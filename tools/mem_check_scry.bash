#!/bin/bash

make && valgrind --leak-check=full --suppressions=tools/valgrind.supp --gen-suppressions=all ./build/linux_x86/riptide_client
