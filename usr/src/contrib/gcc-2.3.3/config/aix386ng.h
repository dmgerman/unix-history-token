begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for IBM PS2 running AIX/386.    From: Minh Tran-Le<TRANLE@intellicorp.com>    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386.h"
end_include

begin_comment
comment|/* Get the generic definitions for system V.3.  */
end_comment

begin_include
include|#
directive|include
file|"svr3.h"
end_include

begin_comment
comment|/* Use the ATT assembler syntax.    This overrides at least one macro (ASM_OUTPUT_LABELREF) from svr3.h.  */
end_comment

begin_include
include|#
directive|include
file|"att386.h"
end_include

begin_comment
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}} crtbegin.o%s"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-L/usr/lib/libp}%{pg:-L/usr/lib/libp} -lc \   crtend.o%s crtn.o%s"
end_define

begin_comment
comment|/* Special flags for the linker.  I don't know what they do.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{K} %{!K:-K} %{T*} %{z:-lm}"
end_define

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D_I386 -Di386 -DAIX -D_AIX"
end_define

begin_comment
comment|/* special flags for the aix assembler to generate the short form for all    qualifying forward reference */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-s2"
end_define

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do { fprintf (FILE, "\t.file\t\"%s\"\n", dump_base_name);	\        if (optimize)						\           ASM_FILE_START_1 (FILE); 				\        else							\           fprintf (FILE, "\t.noopt\n");				\      } while (0)
end_define

begin_comment
comment|/* This was suggested, but it shouldn't be right for DBX output. -- RMS    #define ASM_OUTPUT_SOURCE_FILENAME(FILE, NAME) */
end_comment

begin_comment
comment|/* Writing `int' for a bitfield forces int alignment for the structure.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Don't write a `.optim' pseudo; this assembler    is said to have a bug when .optim is used.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START_1
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START_1
parameter_list|(
name|FILE
parameter_list|)
value|fprintf (FILE, "\t.noopt\n");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|fprintf (FILE, "\tleal %sP%d,%%eax\n\tcall mcount\n", LPREFIX, (LABELNO));
end_define

begin_comment
comment|/* Note that using bss_section here caused errors    in building shared libraries on system V.3.    but AIX 1.2 does not have yet shareable libraries on PS2 */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|(bss_section (),					\    ASM_OUTPUT_LABEL ((FILE), (NAME)),			\    fprintf ((FILE), "\t.set .,.+%u\n", (ROUNDED)))
end_define

end_unit

