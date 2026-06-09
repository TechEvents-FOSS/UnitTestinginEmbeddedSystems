coverage:
	ceedling gcov:all

mock_test:
	ceedling test:all

coverage_summary: coverage
	@python3 -m gcovr build/gcov/out --json-summary-pretty -o build/coverage.json
	@python3 scripts/coverage_summary.py

clean:
	rm -rf build