import subprocess
import os

BUILD_DIR = "cmake-build-debug"
binary_name = os.path.join(BUILD_DIR, "assigment5.exe" if os.name == 'nt' else "assigment5")
def run_session(input_lines):
    process = subprocess.Popen(
        [binary_name],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    input_data = "\n".join(input_lines) + "\nexit\n"
    stdout, stderr = process.communicate(input_data)
    return [line for line in stdout.strip().split("\n") if line], stderr


def run_test(name, input_lines, expected_outputs):
    actual_outputs, stderr = run_session(input_lines)
    if actual_outputs == expected_outputs:
        print(f"[PASS] {name}")
    else:
        print(f"[FAIL] {name}")
        print(f"  input:    {input_lines}")
        print(f"  expected: {expected_outputs}")
        print(f"  actual:   {actual_outputs}")
        if stderr:
            print(f"  stderr:   {stderr}")


def main():
    run_test(
        "basic arithmetic with priority",
        ["5 + 3 * 2"],
        ["11"]
    )

    run_test(
        "built-in functions",
        ["max(5, 2)", "min(3, 4)"],
        ["5", "3"]
    )

    run_test(
        "nested function calls",
        ["max(min(3 * 2, 2), 2)"],
        ["2"]
    )

    run_test(
        "variable declaration and reuse",
        ["var a = max(min(3 * 2, 2), 2)", "a + 3"],
        ["5"]  # var-рядок нічого не друкує
    )

    run_test(
        "immutability: reassignment must fail",
        ["var a = 5", "var b = 10", "var b = 20"],
        ["Error: Variable 'b' is already defined and cannot be reassigned."]
    )


if __name__ == "__main__":
    main()