begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Linux-based GNU systems with a.out binaries.    Copyright (C) 1995, 1997, 1999, 2000 Free Software Foundation, Inc.    Contributed by H.J. Lu (hjl@nynexst.com)  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{pg:gcrt0.o%s} %{!pg:%{p:gcrt0.o%s} %{!p:crt0.o%s}} %{static:-static}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set\t"
end_define

begin_comment
comment|/* We need that too.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
value|1
end_define

end_unit

