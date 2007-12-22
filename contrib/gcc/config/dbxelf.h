begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions needed when using stabs embedded in ELF sections.    Copyright (C) 1999, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This file may be included by any ELF target which wishes to    support -gstabs generating stabs in sections, as produced by gas    and understood by gdb.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_DBX_ELF_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_DBX_ELF_H
end_define

begin_comment
comment|/* Output DBX (stabs) debugging information if doing -gstabs.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
value|1
end_define

begin_comment
comment|/* Make LBRAC and RBRAC addresses relative to the start of the    function.  The native Solaris stabs debugging format works this    way, gdb expects it, and it reduces the number of relocation    entries...  */
end_comment

begin_define
define|#
directive|define
name|DBX_BLOCKS_FUNCTION_RELATIVE
value|1
end_define

begin_comment
comment|/* ... but, to make this work, functions must appear prior to line info.  */
end_comment

begin_define
define|#
directive|define
name|DBX_FUNCTION_FIRST
end_define

begin_comment
comment|/* When generating stabs debugging, use N_BINCL entries.  */
end_comment

begin_define
define|#
directive|define
name|DBX_USE_BINCL
end_define

begin_comment
comment|/* There is no limit to the length of stabs strings.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DBX_CONTIN_LENGTH
end_ifndef

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Like block addresses, stabs line numbers are relative to the    current function.  */
end_comment

begin_define
define|#
directive|define
name|DBX_LINES_FUNCTION_RELATIVE
value|1
end_define

begin_comment
comment|/* Generate a blank trailing N_SO to mark the end of the .o file, since    we can't depend upon the linker to mark .o file boundaries with    embedded stabs.  */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_NULL_N_SO_AT_MAIN_SOURCE_FILE_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_DBX_ELF_H */
end_comment

end_unit

