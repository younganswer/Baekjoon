import sys
from submit import submit
from result import result

if __name__ == "__main__":
	if len(sys.argv) != 2:
		print(f"Usage: {sys.argv[0]} <problem_id>", file=sys.stderr)
		sys.exit(1)

	submit(sys.argv[1])
	result()