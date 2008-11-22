begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Rs6000 running LynxOS.    Copyright (C) 2003 Free Software Foundation, Inc.    Contributed by David Henkel-Wallace, Cygnus Support (gumby@cygnus.com)     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Definitions we want to override with those from rs6000.h:  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION
end_undef

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_ASM_SELECT_RTX_SECTION
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_ASM_SELECT_SECTION
end_undef

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_COMMON
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

end_unit

