begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running SCO Unix System V 3.2 Version 4.    Written by Chip Salzenberg.    Copyright (C) 1992, 1994 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Mostly it's like earlier SCO UNIX.  */
end_comment

begin_include
include|#
directive|include
file|"i386/sco.h"
end_include

begin_comment
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.  */
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
value|"%{scoxpg3:%{p:mcrt1X.o%s}%{!p:crt1X.o%s}} \   %{!scoxpg3:\    %{posix:%{p:mcrt1P.o%s}%{!p:crt1P.o%s}} \    %{!posix:\     %{ansi:%{p:mcrt1A.o%s}%{!p:crt1A.o%s}} \     %{!ansi:%{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}}}} \   crtbegin.o%s"
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
define|\
value|"crtend.o%s \   %{scoxpg3:crtnX.o%s} \   %{!scoxpg3:\    %{posix:crtnP.o%s} \    %{!posix:\     %{ansi:crtnA.o%s} \     %{!ansi:crtn.o%s}}}"
end_define

begin_comment
comment|/* Library spec.  */
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
define|\
value|"%{p:-L/usr/lib/libp}%{pg:-L/usr/lib/libp} \  %{scoxpg3:-lcX -lcP -lcA} \  %{!scoxpg3:\   %{posix:-lcP -lcA} \   %{!posix:\    %{ansi:-lcA} \    %{!ansi:%{scointl:-lintl} -lc}}}"
end_define

begin_comment
comment|/* Macros, macros everywhere:    Specify predefined symbols in preprocessor.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Asystem(svr3)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) \   -D_i386 -D_M_I386 -D_M_I86 -D_M_I86SM -D_M_SDATA -D_M_STEXT \   -D_unix -D_M_UNIX -D_M_XENIX \   -D_M_SYS5 -D_M_SYSV -D_M_SYS3 -D_M_SYSIII \   -D_M_COFF -D_M_BITFIELDS -D_M_WORDSWAP \   %{scoxpg3:-D_XOPEN_SOURCE -D_STRICT_NAMES} \   %{!scoxpg3:%{posix:-D_POSIX_SOURCE -D_STRICT_NAMES}} \   %{!scoxpg3:%{!posix:\     %{ansi:-D_STRICT_NAMES}%{!ansi:\     -Di386 -DM_I386 -DM_I86 -DM_I86SM -DM_SDATA -DM_STEXT \     -Dunix -DM_UNIX -DM_XENIX \     -DM_SYS5 -DM_SYSV -DM_SYS3 -DM_SYSIII \     -DM_COFF -DM_BITFIELDS -DM_WORDSWAP \     %{scointl:-D_M_INTERNAT -DM_INTERNAT} \     %{traditional:-D_KR -D_SVID -D_NO_PROTOTYPE}}}}"
end_define

begin_comment
comment|/* The system headers are C++-aware.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

end_unit

