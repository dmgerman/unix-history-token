begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Iris version.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|SGI_TARGET
value|1
end_define

begin_comment
comment|/* inform other mips files this is SGI */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dmips -Dsgi -DSVR3 -Dhost_mips -DMIPSEB -DSYSTYPE_SYSV"
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}"
end_define

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{!ansi:-D__EXTENSIONS__} -D_MIPSEB -D_SYSTYPE_SYSV \ %{.S:	-D_LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY}} \ %{.cc:	-D_LANGUAGE_C_PLUS_PLUS} \ %{.cxx:	-D_LANGUAGE_C_PLUS_PLUS} \ %{.C:	-D_LANGUAGE_C_PLUS_PLUS} \ %{.m:	-D_LANGUAGE_OBJECTIVE_C} \ %{!.S: %{!.cc: %{!.cxx: %{!.C: %{!.m: -D_LANGUAGE_C %{!ansi:-DLANGUAGE_C}}}}}}"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} crtn.o%s"
end_define

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"Silicon Graphics Mips"
end_define

begin_comment
comment|/* SGI Iris doesn't support -EB/-EL like other MIPS processors.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{!mgas: \ 	%{!mrnames: %{!.s:-nocpp} %{.s: %{cpp} %{nocpp}}} \ 	%{pipe: %e-pipe is not supported.} \ 	%{mips1} %{mips2} %{mips3} \ 	%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3} \ 	%{g} %{g0} %{g1} %{g2} %{g3} %{v} %{K}} \ %{G*}"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ %{G*} \ %{!mgas: %{mips1} %{mips2} %{mips3} \ 	 %{bestGnum} %{shared} %{non_shared}}"
end_define

begin_comment
comment|/* Always use 1 for .file number.  I [meissner@osf.org] wonder why    IRIS needs this.  */
end_comment

begin_define
define|#
directive|define
name|SET_FILE_NUMBER
parameter_list|()
value|num_source_filenames = 1
end_define

begin_comment
comment|/* Put out a label after a .loc.  I [meissner@osf.org] wonder why    IRIS needs this.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_AFTER_LOC
parameter_list|(
name|STREAM
parameter_list|)
value|fprintf (STREAM, "LM%d:\n", ++sym_lineno)
end_define

begin_define
define|#
directive|define
name|STACK_ARGS_ADJUST
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|{                                                                       \   SIZE.constant += 4;                                                   \   if (SIZE.constant< 32)						\     SIZE.constant = 32;                                                 \ }
end_define

begin_comment
comment|/* Define this macro to control use of the character `$' in    identifier names.  The value should be 0, 1, or 2.  0 means `$'    is not allowed by default; 1 means it is allowed by default if    `-traditional' is used; 2 means it is allowed by default provided    `-ansi' is not used.  1 is the default; there is no need to    define this macro in that case. */
end_comment

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|0
end_define

begin_comment
comment|/* Tell G++ not to create constructors or destructors with $'s in them.  */
end_comment

begin_define
define|#
directive|define
name|NO_DOLLAR_IN_LABEL
value|1
end_define

begin_comment
comment|/* Specify size_t, ptrdiff_t, and wchar_t types.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"unsigned char"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_UNIT
end_define

begin_comment
comment|/* Generate calls to memcpy, etc., not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Plain char is unsigned in the SGI compiler.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|0
end_define

begin_include
include|#
directive|include
file|"mips.h"
end_include

end_unit

