begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Intel 80386 running Solaris 2    Copyright (C) 1993, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.    Contributed by Fred Fish (fnf@cygnus.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/sysv4.h"
end_include

begin_comment
comment|/* We use stabs-in-elf for debugging, because that is what the native    toolchain uses.  */
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

begin_if
if|#
directive|if
operator|!
name|GAS_REJECTS_MINUS_S
end_if

begin_comment
comment|/*   Changed from config/svr4.h in the following ways:    - Removed -Yd (neither the sun bundled assembler nor gas accept it).   - Added "-s" so that stabs are not discarded. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Wa,*:%*} -s"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* GAS_REJECTS_MINUS_S */
end_comment

begin_comment
comment|/* Same as above, except for -s, unsupported by GNU as.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Wa,*:%*}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GAS_REJECTS_MINUS_S */
end_comment

begin_comment
comment|/* The Solaris 2.0 x86 linker botches alignment of code sections.    It tries to align to a 16 byte boundary by padding with 0x00000090    ints, rather than 0x90 bytes (nop).  This generates trash in the    ".init" section since the contribution from crtbegin.o is only 7    bytes.  The linker pads it to 16 bytes with a single 0x90 byte, and    two 0x00000090 ints, which generates a segmentation violation when    executed.  This macro forces the assembler to do the padding, since    it knows what it is doing. */
end_comment

begin_define
define|#
directive|define
name|FORCE_INIT_SECTION_ALIGN
value|asm (ALIGN_ASM_OP ## " 16")
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
value|"-Dunix -D__svr4__ -D__SVR4 -Dsun -Asystem(svr4)"
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
value|"%(cpp_cpu) \    %{compat-bsd:-iwithprefixbefore ucbinclude -I/usr/ucbinclude}"
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

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{!shared: \ 			 %{!symbolic: \ 			  %{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}}}\ 			%{pg:gmon.o%s} crti.o%s \ 			%{ansi:values-Xc.o%s} \ 			%{!ansi: \ 			 %{traditional:values-Xt.o%s} \ 			 %{!traditional:values-Xa.o%s}} \  			crtbegin.o%s"
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
value|"%{h*} %{v:-V} \    %{b} %{Wl,*:%*} \    %{static:-dn -Bstatic} \    %{shared:-G -dy -z text} \    %{symbolic:-Bsymbolic -G -dy -z text} \    %{G:-G} \    %{YP,*} \    %{R*} \    %{compat-bsd: \      %{!YP,*:%{pg:-Y P,/usr/ucblib:/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \      %{!pg:%{p:-Y P,/usr/ucblib:/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{!p:-Y P,/usr/ucblib:/usr/ccs/lib:/usr/lib}}} \      -R /usr/ucblib} \    %{!compat-bsd: \      %{!YP,*:%{pg:-Y P,/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \      %{!pg:%{p:-Y P,/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{!p:-Y P,/usr/ccs/lib:/usr/lib}}}} \    %{Qy:} %{!Qn:-Qy}"
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
value|(DEFAULT_SWITCH_TAKES_ARG(CHAR) \    || (CHAR) == 'R' \    || (CHAR) == 'h' \    || (CHAR) == 'z')
end_define

begin_define
define|#
directive|define
name|STDC_0_IN_SYSTEM_HEADERS
end_define

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

end_unit

