begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  DECstation (OSF/1) version.    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|DEC_OSF1
end_define

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__ANSI_COMPAT \ -DMIPSEL -DR3000 -DSYSTYPE_BSD -D_SYSTYPE_BSD -Dbsd4_2 -Dhost_mips -Dmips -Dosf -Dunix"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ %{G*} \ %{!mgas: \ 	%{EL} %{!EL: -EL} \ 	%{EB: %e-EB not supported} \ 	%{mips1} %{mips2} %{mips3} %{bestGnum} \ 	%{shared} %{non_shared} %{call_shared} %{no_archive} %{exact_version} \ 	%{!shared: %{!non_shared: %{!call_shared: -non_shared}}}}"
end_define

begin_include
include|#
directive|include
file|"decstatn.h"
end_include

begin_comment
comment|/* Specify size_t, ptrdiff_t, and wchar_t types.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
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

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
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
value|"short unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|SHORT_TYPE_SIZE
end_define

begin_comment
comment|/* turn off collect2 COFF support, since ldfcn now has elf declaration */
end_comment

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_COFF
end_undef

begin_undef
undef|#
directive|undef
name|MACHINE_TYPE
end_undef

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"DECstation running DEC OSF/1"
end_define

end_unit

