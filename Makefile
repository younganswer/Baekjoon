MAKEFLAGS += -s

build: check_args
	@bash util/build.sh $(word 2, $(MAKECMDGOALS))

submit: check_args
	@python util/submit/__init__.py $(word 2, $(MAKECMDGOALS))

test: check_args
	@bash util/test.sh $(word 2, $(MAKECMDGOALS))

check_args:
	@if [ $(words $(MAKECMDGOALS)) -ne 2 ]; then \
		printf "Usage: make $(word 1, $(MAKECMDGOALS)) <number>\n"; \
		exit 1; \
	fi

clean:
	@bash util/clean.sh

.NOTPARALLEL: build submit test check_args clean

.PHONY: build submit test check_args clean

.DEFAULT:
	@: