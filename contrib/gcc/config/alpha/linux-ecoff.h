begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler    for Alpha Linux-based GNU systems using ECOFF.    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    Contributed by Bob Manson.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (Alpha GNU/Linux for ECOFF)");
end_define

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|"-D__ECOFF__"
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
value|"-G 8 %{O*:-O3} %{!O*:-O1}"
end_define

begin_comment
comment|/* stabs get slurped by the assembler into a queer ecoff format.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_comment
comment|/* We support #pragma.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

end_unit

