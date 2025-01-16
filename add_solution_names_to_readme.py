#!/bin/env python3
import os
import hashlib
from concurrent.futures import ThreadPoolExecutor

LANG_BY_CORE_SOURCE = {"c": "main.c", "cpp": "main.cpp", "csharp": "Program.cs"}
INITIAL_README_FILE = "./readme_core.md"
RESULT_README_FILE = "./readme.md"


def search_core_source(core_source: str) -> list[str]:
    result_list = []
    for root, dir, files in os.walk(os.path.dirname(__file__)):
        for file in files:
            if file.endswith(core_source):
                result_list.append(root.split("/")[-2:])
    return result_list


def get_initial_readme() -> str:
    with open(INITIAL_README_FILE, "r") as int_readme_f:
        return str(int_readme_f.read())


def check_hash_readme(new_readme_content: str) -> bool:
    with open(RESULT_README_FILE, "rb") as result_readme:
        return hashlib.sha256(result_readme.read()) == hashlib.sha256(
            new_readme_content.encode("utf-8")
        )


def main():
    total_res = dict()
    with ThreadPoolExecutor() as executor:
        futures = {
            executor.submit(search_core_source, LANG_BY_CORE_SOURCE[lang]): lang
            for lang in LANG_BY_CORE_SOURCE
        }
        for future in futures:
            lang = futures[future]
            total_res[lang] = future.result()
    print(total_res)
    init_data = get_initial_readme()
    new_readme_data_str = init_data
    for lang in total_res:
        existed_heads = set()
        new_readme_data_str += f"## {lang}\n\n"
        for problem in total_res[lang]:
            problem_head, problem_sub = problem
            if problem_head not in existed_heads:
                new_readme_data_str += f"### {problem_head}\n\n"
                existed_heads.add(problem_head)
            new_readme_data_str += (
                f" * [{problem_sub}](./{lang}/{problem_head}/{problem_sub})\n"
            )
        new_readme_data_str += "\n"
    new_readme_data_str.removesuffix("\n")
    if not check_hash_readme(new_readme_data_str):
        with open(RESULT_README_FILE, "w", encoding="utf-8") as result_readme:
            result_readme.writelines(new_readme_data_str)


if __name__ == "__main__":
    main()
