begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for IBM PS2 running AIX/386.    Copyright (C) 1988, 1996, 1998 Free Software Foundation, Inc.    Contributed by Minh Tran-Le<TRANLE@intellicorp.com>.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/i386.h"
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
comment|/* Use the ATT assembler syntax.    This overrides at least one macro (USER_LABEL_PREFIX) from svr3.h.  */
end_comment

begin_include
include|#
directive|include
file|"i386/att.h"
end_include

begin_comment
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}"
end_define

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtn.o%s"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{shlib:-lc_s} -lc"
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
value|"-Dps2 -Dunix -Asystem(aix)"
end_define

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) \   %{posix:-D_POSIX_SOURCE}%{!posix:-DAIX} -D_I386 -D_AIX -D_MBCS"
end_define

begin_comment
comment|/* special flags for the aix assembler to generate the short form for all    qualifying forward reference */
end_comment

begin_comment
comment|/* The buggy /bin/as of aix ps/2 1.2.x cannot always handle it.	*/
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-s2"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

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
value|do { output_file_directive (FILE, main_input_filename);	\        if (optimize)						\           ASM_FILE_START_1 (FILE); 				\        else							\           fprintf (FILE, "\t.noopt\n");				\      } while (0)
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

begin_ifndef
ifndef|#
directive|ifndef
name|USE_GAS
end_ifndef

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
value|fprintf (FILE, "\t.noopt\n")
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

begin_comment
comment|/* Undef all the .init and .fini section stuff if we are not using gas and  * gnu ld so that we can use collect because the standard /bin/as and /bin/ld  * cannot handle those.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_GAS
end_ifndef

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CONSTRUCTOR
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DESTRUCTOR
end_undef

begin_undef
undef|#
directive|undef
name|DO_GLOBAL_CTORS_BODY
end_undef

begin_undef
undef|#
directive|undef
name|CTOR_LIST_BEGIN
end_undef

begin_define
define|#
directive|define
name|CTOR_LIST_BEGIN
end_define

begin_undef
undef|#
directive|undef
name|CTOR_LIST_END
end_undef

begin_define
define|#
directive|define
name|CTOR_LIST_END
end_define

begin_undef
undef|#
directive|undef
name|DTOR_LIST_BEGIN
end_undef

begin_define
define|#
directive|define
name|DTOR_LIST_BEGIN
end_define

begin_undef
undef|#
directive|undef
name|DTOR_LIST_END
end_undef

begin_define
define|#
directive|define
name|DTOR_LIST_END
end_define

begin_undef
undef|#
directive|undef
name|CONST_SECTION_FUNCTION
end_undef

begin_define
define|#
directive|define
name|CONST_SECTION_FUNCTION
define|\
value|void									\ const_section ()							\ {									\   extern void text_section();						\   text_section();							\ }
end_define

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|CONST_SECTION_FUNCTION
end_define

begin_comment
comment|/* for collect2 */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_COFF
end_define

begin_define
define|#
directive|define
name|MY_ISCOFF
parameter_list|(
name|magic
parameter_list|)
define|\
value|((magic) == I386MAGIC || (magic) == I386SVMAGIC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_GAS */
end_comment

end_unit

