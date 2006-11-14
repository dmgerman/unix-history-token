begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common VxWorks target definitions for GCC.    Copyright (C) 1999, 2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Wind River Systems.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Specify what to link with.  */
end_comment

begin_comment
comment|/* VxWorks does all the library stuff itself.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-r"
end_define

begin_comment
comment|/* VxWorks provides the functionality of crt0.o and friends itself.  */
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
value|""
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|""
end_define

begin_comment
comment|/* VxWorks cannot have dots in constructor labels, because it uses a    mutant variation of collect2 that generates C code instead of    assembly.  Thus each constructor label must be a legitimate C    symbol.  FIXME: Have VxWorks use real collect2 instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_define
define|#
directive|define
name|NO_DOT_IN_LABEL
end_define

begin_comment
comment|/* enable #pragma pack(n) */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_comment
comment|/* No underscore is prepended to any C symbol name.  */
end_comment

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_comment
comment|/* VxWorks uses wchar_t == unsigned short (UCS2) on all architectures.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
end_define

begin_comment
comment|/* Dwarf2 unwind info is not supported.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_comment
comment|/* Weak symbols and link-once sections are not enabled by default.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_USE_WEAK
value|0
end_define

begin_comment
comment|/* Only supported debug format is Dwarf2.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

end_unit

