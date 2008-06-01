begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  IRIX version 5.    Copyright (C) 1993, 1995, 1996, 1998, 2000,    2001, 2002, 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX_USING_GNU_LD
end_ifdef

begin_define
define|#
directive|define
name|IRIX_SUBTARGET_LINK_SPEC
value|"-melf32bsmip"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IRIX_SUBTARGET_LINK_SPEC
value|"-_SYSTYPE_SVR4"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"\ %{!static: \   %{!shared:%{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s libprof1.a%s}%{!p:crt1.o%s}}}} \ %{static: \   %{pg:gcrt1.o%s} \   %{!pg:%{p:/usr/lib/nonshared/mcrt1.o%s libprof1.a%s} \   %{!p:/usr/lib/nonshared/crt1.o%s}}} \ irix-crti.o%s crtbegin.o%s"
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
value|"%{!shared:%{p:-lprof1} %{pg:-lprof1} -lc}"
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
value|"crtend.o%s irix-crtn.o%s %{!shared:crtn.o%s}"
end_define

begin_undef
undef|#
directive|undef
name|MACHINE_TYPE
end_undef

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"SGI running IRIX 5.x"
end_define

end_unit

