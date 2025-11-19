-include .env
export
SHELL := /bin/bash
PWD := $(shell pwd)

CURRENT_DATE := $(shell date '+%Y_%m_%d_%H_%M_%S')

# colors
GREEN = $(shell tput -Txterm setaf 2)
YELLOW = $(shell tput -Txterm setaf 3)
WHITE = $(shell tput -Txterm setaf 7)
RESET = $(shell tput -Txterm sgr0)
GRAY = $(shell tput -Txterm setaf 6)
TARGET_MAX_CHAR_NUM = 30

.EXPORT_ALL_VARIABLES:

.PHONY: all
## Default target
all: help

.PHONY: env clean build


#IGNORE := $(shell bash -c source "/home/redacid/Projects/ESP32/setup-env.sh; env | sed 's/=/:=/' | sed 's/^/export /' > makeenv")

.ONESHELL:
clean:
	cd $(PWD)
	rm -rf build

.ONESHELL:
build: clean
	cd $(PWD)
	mkdir build
	cd build
	cmake ..
	make

.ONESHELL:
test: build
	cd $(PWD)/build/test/
	./rfm69_test