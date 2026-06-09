import json
import os

with open("build/coverage.json") as f:
    d = json.load(f)

p = d["line_percent"]
h = d["line_covered"]
t = d["line_total"]

status = "✅ Pass" if p == 100 else "⚠️ Partial"

print("\n📊 Coverage Report")
print(f"Status: {status}")
print(f"Percentage: {p:.2f}%")
print(f"Details: {h} out of {t} lines executed\n")

summary = os.getenv("GITHUB_STEP_SUMMARY")
if summary:
    with open(summary, "a") as f:
        f.write(
            f"\n---\n\n"
            f"## Lab4 - Unit Test Coverage\n"
            f"- **Status:** {status}\n"
            f"- **Percentage:** {p:.2f}%\n"
            f"- **Details:** {h} out of {t} lines executed\n"
        )