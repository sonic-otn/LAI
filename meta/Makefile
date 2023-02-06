#
# Copyright (c) 2014 Microsoft Open Technologies, Inc.
#
#    Licensed under the Apache License, Version 2.0 (the "License"); you may
#    not use this file except in compliance with the License. You may obtain
#    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
#
#    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
#    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
#    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
#    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
#
#    See the Apache Version 2.0 License for specific language governing
#    permissions and limitations under the License.
#
#    Microsoft would like to thank the following companies for their review and
#    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
#    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
#
# @file    Makefile
#
# @brief   This module defines LAI Metadata Makefile
#

WARNINGS = \
	-ansi \
	-Wall \
	-Wcast-align \
	-Wcast-qual \
	-Wconversion \
	-Wdisabled-optimization \
	-Werror \
	-Wextra \
	-Wextra \
	-Wfloat-equal \
	-Wformat=2 \
	-Wformat-nonliteral \
	-Wformat-security \
	-Wformat-y2k \
	-Wimport \
	-Winit-self \
	-Winline \
	-Winvalid-pch \
	-Wmissing-field-initializers \
	-Wmissing-format-attribute \
	-Wmissing-include-dirs \
	-Wmissing-noreturn \
	-Wno-aggregate-return \
	-Wno-padded \
	-Wno-switch-enum \
	-Wno-unused-parameter \
	-Wpacked \
	-Wpointer-arith \
	-Wredundant-decls \
	-Wshadow \
	-Wstack-protector \
	-Wstrict-aliasing=3 \
	-Wswitch \
	-Wswitch-default \
	-Wunreachable-code \
	-Wunused \
	-Wvariadic-macros \
	-Wwrite-strings

BINS = doxygen perl

$(foreach bin,$(BINS),$(if $(shell which $(bin)),,$(error "Missing $(bin) in PATH")))

CFLAGS += -I../inc $(WARNINGS)

DEPS = $(wildcard ../inc/*.h)
XMLDEPS = $(wildcard xml/*.xml)

OBJ = laimetadata.o laimetadatautils.o laiserialize.o

SYMBOLS = $(OBJ:=.symbols)

all: $(SYMBOLS)
	./checkheaders.pl ../inc ../inc

CONSTHEADERS = laimetadatatypes.h laimetadatalogger.h laimetadatautils.h laiserialize.h

xml: $(DEPS) Doxyfile $(CONSTHEADERS)
	doxygen Doxyfile 2>&1 | perl -npe '$$e=1 if /warning/i; END{exit $$e}'
	touch xml

EXTRA = acronyms.txt aspell.en.pws *.pm *.cap

laimetadata.c laimetadata.h: install_excel_writer xml $(XMLDEPS) parse.pl $(CONSTHEADERS) $(EXTRA)
	perl -I. parse.pl

HEADERS = laimetadata.h $(CONSTHEADERS)

%.o: %.c $(HEADERS)
	gcc -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(HEADERS)
	gcc -c -o $@ $< $(CFLAGS)

%.o.symbols: %.o
	nm $^ | ./checksymbols.pl

install_excel_writer: excel-writer-xlsx-main.tar.gz
	tar -xzf excel-writer-xlsx-main.tar.gz
	cd excel-writer-xlsx-main && perl Makefile.PL
	sudo make -C excel-writer-xlsx-main
	sudo make -C excel-writer-xlsx-main install

.PHONY: clean install_excel_writer

clean:
	rm -f *.o *~ .*~ *.tmp .*.swp .*.swo *.bak lai*.gv lai*.svg *.o.symbols
	rm -f laimetadata.h laimetadata.c
	rm -rf xml html dist
	rm -rf excel-writer-xlsx-main
