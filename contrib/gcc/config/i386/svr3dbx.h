begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running system V, using dbx-in-coff encapsulation.    Copyright (C) 1992, 1995 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/svr3gas.h"
end_include

begin_comment
comment|/* We do not want to output SDB debugging information.  */
end_comment

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_comment
comment|/* We want to output DBX debugging information.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Compensate for botch in dbxout_init/dbxout_source_file which    unconditionally drops the first character from ltext_label_name */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|BUF
parameter_list|,
name|PREFIX
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|sprintf ((BUF), "*.%s%d", (PREFIX), (NUMBER))
end_define

begin_comment
comment|/* With the current gas, .align N aligns to an N-byte boundary.    This is done to be compatible with the system assembler.    You must specify -DOTHER_ALIGN when building gas-1.38.1.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG)!=0) fprintf ((FILE), "\t.align %d\n", 1<<(LOG))
end_define

begin_comment
comment|/* Align labels, etc. at 4-byte boundaries.    For the 486, align to 16-byte boundary for sake of cache.  */
end_comment

begin_undef
undef|#
directive|undef
name|LABEL_ALIGN_AFTER_BARRIER
end_undef

begin_define
define|#
directive|define
name|LABEL_ALIGN_AFTER_BARRIER
parameter_list|(
name|LABEL
parameter_list|)
value|(i386_align_jumps)
end_define

begin_comment
comment|/* Align start of loop at 4-byte boundary.  */
end_comment

begin_undef
undef|#
directive|undef
name|LOOP_ALIGN
end_undef

begin_define
define|#
directive|define
name|LOOP_ALIGN
parameter_list|(
name|LABEL
parameter_list|)
value|(i386_align_loops)
end_define

begin_comment
comment|/* Additional overrides needed for dbx-in-coff gas, mostly taken from pbb.h */
end_comment

begin_comment
comment|/* Although the gas we use can create .ctor and .dtor sections from N_SETT    stabs, it does not support section directives, so we need to have the loader    define the lists.  */
end_comment

begin_define
define|#
directive|define
name|CTOR_LISTS_DEFINED_EXTERNALLY
end_define

begin_comment
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.  */
end_comment

begin_comment
comment|/*  * The loader directive file svr3.ifile defines how to merge the constructor   * sections into the data section.  Also, since gas only puts out those   * sections in response to N_SETT stabs, and does not (yet) have a   * ".sections" directive, svr3.ifile also defines the list symbols   * __DTOR_LIST__ and __CTOR_LIST__.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!r:%{!z:svr3.ifile%s}%{z:svr3z.ifile%s}}\    %{pg:gcrt1.o%s}%{!pg:%{posix:%{p:mcrtp1.o%s}%{!p:crtp1.o%s}}%{!posix:%{p:mcrt1.o%s}%{!p:crt1.o%s}}} \    %{p:-L/usr/lib/libp}%{pg:-L/usr/lib/libp}"
end_define

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtn.o%s"
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{posix:-lcposix} %{shlib:-lc_s} -lc -lg"
end_define

end_unit

