begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running Interactive Unix System V,    using dbx-in-coff encapsulation.    Specifically, this is for recent versions that support POSIX.    Copyright (C) 1992, 1995 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Mostly it's like AT&T Unix System V with dbx-in-coff.  */
end_comment

begin_include
include|#
directive|include
file|"i386/svr3dbx.h"
end_include

begin_comment
comment|/* But with a few changes.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_include
include|#
directive|include
file|"i386/isc.h"
end_include

begin_comment
comment|/* Overridden defines for ifile usage.  */
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
value|"%{!r:%{!z:svr3.ifile%s}%{z:svr3z.ifile%s}}\    %{!shlib:%{posix:%{pg:mcrtp1.o%s}%{!pg:%{p:mcrtp1.o%s}%{!p:crtp1.o%s}}}\    %{Xp:%{pg:mcrtp1.o%s}%{!pg:%{p:mcrtp1.o%s}%{!p:crtp1.o%s}}}\    %{!posix:%{!Xp:%{pg:mcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}}}\    %{p:-L/usr/lib/libp} %{pg:-L/usr/lib/libp}}\    %{shlib:%{posix:crtp1.o%s}%{Xp:crtp1.o%s}%{!posix:%{!Xp:crt1.o%s}}}"
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
value|"crtn.o%s"
end_define

end_unit

