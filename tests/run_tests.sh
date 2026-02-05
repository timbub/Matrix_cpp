#!/bin/bash
PROGRAM="../build/matrix"

TESTS_DIR="."

echo "running E2E tests"
for INPUT_FILE in ${TESTS_DIR}/input/*.in; do

    BASENAME=$(basename "${INPUT_FILE}" .in)
    EXPECTED_FILE=${TESTS_DIR}/output/${BASENAME}.out
    ACTUAL_FILE="${BASENAME}.act"

${PROGRAM} < ${INPUT_FILE} > ${ACTUAL_FILE}

diff -q -w "${ACTUAL_FILE}" "${EXPECTED_FILE}"
if [ $? -eq 0 ]; then
    echo "TEST ${INPUT_FILE} PASSED"
else
    echo "TEST ${INPUT_FILE} FAILED"
fi
    
rm ${ACTUAL_FILE}
done
