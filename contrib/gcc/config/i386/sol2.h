begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Intel 80386 running Solaris 2    Copyright (C) 1993, 1995 Free Software Foundation, Inc.     Written by Fred Fish (fnf@cygnus.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/sysv4.h"
end_include

begin_comment
comment|/* The Solaris 2.0 x86 linker botches alignment of code sections.    It tries to align to a 16 byte boundary by padding with 0x00000090    ints, rather than 0x90 bytes (nop).  This generates trash in the    ".init" section since the contribution from crtbegin.o is only 7    bytes.  The linker pads it to 16 bytes with a single 0x90 byte, and    two 0x00000090 ints, which generates a segmentation violation when    executed.  This macro forces the assembler to do the padding, since    it knows what it is doing. */
end_comment

begin_define
define|#
directive|define
name|FORCE_INIT_SECTION_ALIGN
value|do { asm (ALIGN_ASM_OP ## " 16"); } while (0)
end_define

begin_define
define|#
directive|define
name|FORCE_FINI_SECTION_ALIGN
value|FORCE_INIT_SECTION_ALIGN
end_define

begin_comment
comment|/* Add "sun" to the list of symbols defined for SVR4.  */
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
value|"-Di386 -Dunix -D__svr4__ -D__SVR4 -Dsun \    -Asystem(unix) -Asystem(svr4) -Acpu(i386) -Amachine(i386)"
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
value|"\    %{compat-bsd:-iwithprefixbefore ucbinclude -I/usr/ucbinclude}"
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
define|\
value|"%{compat-bsd:-lucb -lsocket -lnsl -lelf -laio} %{!shared:%{!symbolic:-lc}}"
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
value|"crtend.o%s %{pg:crtn.o%s}%{!pg:crtn.o%s}"
end_define

begin_comment
comment|/* This should be the same as in svr4.h, except with -R added.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{h*} %{V} %{v:%{!V:-V}} \    %{b} %{Wl,*:%*} \    %{static:-dn -Bstatic} \    %{shared:-G -dy -z text} \    %{symbolic:-Bsymbolic -G -dy -z text} \    %{G:-G} \    %{YP,*} \    %{R*} \    %{compat-bsd: \      %{!YP,*:%{p:-Y P,/usr/ucblib:/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{!p:-Y P,/usr/ucblib:/usr/ccs/lib:/usr/lib}} \      -R /usr/ucblib} \    %{!compat-bsd: \      %{!YP,*:%{p:-Y P,/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{!p:-Y P,/usr/ccs/lib:/usr/lib}}} \    %{Qy:} %{!Qn:-Qy}"
end_define

begin_comment
comment|/* This defines which switch letters take arguments.    It is as in svr4.h but with -R added.  */
end_comment

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(   (CHAR) == 'D' \    || (CHAR) == 'U' \    || (CHAR) == 'o' \    || (CHAR) == 'e' \    || (CHAR) == 'u' \    || (CHAR) == 'I' \    || (CHAR) == 'm' \    || (CHAR) == 'L' \    || (CHAR) == 'R' \    || (CHAR) == 'A' \    || (CHAR) == 'h' \    || (CHAR) == 'z')
end_define

end_unit

