begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* libgloss.h -- operating system specific defines to be used when    targeting GCC for Libgloss supported targets.    Copyright (C) 1996 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file should not be used for ELF targets, as this definition of    STARTFILE_SPEC is all wrong.  */
end_comment

begin_comment
comment|/* The libgloss standard for crt0.s has the name based on the command line    option. */
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
value|"%{!shared:%{pg:pgcrt0%O%s}%{!pg:%{p:pcrt0%O%s}%{!p:crt0%O%s}}}"
end_define

begin_comment
comment|/* This file used to force LINK_SPEC to be the null string, but that is not    correct.  LINK_SPEC is used to pass machine specific arguments to the    linker and hence can not be redefined here.  LINK_SPEC is never used to    specify startup files or libraries, so it should never conflict with    libgloss.  */
end_comment

begin_comment
comment|/* Don't set the target flags, this is done by the linker script */
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

end_unit

