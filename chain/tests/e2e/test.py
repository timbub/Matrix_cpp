import subprocess
import os

EXE_PATH = "../../../build/chain/chain"

TESTS = [
    ("5\n30 35 15 5 10", "1 0 2"),
    ("3\n10 20 30", "0"),
    ("4\n10 100 5 50", "0 1"),
    ("4\n50 5 100 10", "1 0"),
    ("5\n10 10 10 10 10", "0 1 2"),
    ("6\n100 1 100 1 100 1", "1 3 2 0"),
    ("7\n30 35 15 10 5 10 20", "2 1 0 4 3"),
    ("5\n1000 2000 3000 4000 5000", "0 1 2"),
    ("6\n2 2 2 2 2 2", "0 1 2 3"),
    ("5\n100 1 100 1 100", "1 0 2")
]

def start_tests():
    if not os.path.exists(EXE_PATH):
        print(f"File {EXE_PATH} is not found")
        return

    passed = 0

    for i, (input_, expected_) in enumerate(TESTS, 1):

        result = subprocess.run([EXE_PATH], input=input_, capture_output=True, text=True)

        answer = result.stdout.strip()
        expected = expected_.strip()

        if answer == expected:
            print(f"Test #{i}: [ OK ]")
            passed += 1
        else:
            print(f"Test #{i}: [ FAIL ]")
            print(f"   Input: input.replace")
            print(f"   Expect: '{expected}'")
            print(f"   Get: '{answer}'")

    print(f"Passed {passed} / {len(TESTS)}")

if __name__ == "__main__":
    start_tests()
