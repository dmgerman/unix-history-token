begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for SPARC running Solaris 2    Copyright 1992, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@netcom.com).    Additional changes by David V. Henkel-Wallace (gumby@cygnus.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Supposedly the same as vanilla sparc svr4, except for the stuff below: */
end_comment

begin_include
include|#
directive|include
file|"sparc/sysv4.h"
end_include

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
value|"-Dsparc -Dsun -Dunix -D__svr4__ -D__SVR4 \ -Asystem(unix) -Asystem(svr4)"
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
value|"\ %{pthreads:-D_REENTRANT -D_PTHREADS} \ %{!pthreads:%{threads:-D_REENTRANT -D_SOLARIS_THREADS}} \ %{compat-bsd:-iwithprefixbefore ucbinclude -I/usr/ucbinclude} \ "
end_define

begin_comment
comment|/* The sun bundled assembler doesn't accept -Yd, (and neither does gas).    It's safe to pass -s always, even if -g is not used. */
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
value|"\ %{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Wa,*:%*} -s \ %{fpic:-K PIC} %{fPIC:-K PIC} \ %(asm_cpu) \ "
end_define

begin_comment
comment|/* This is here rather than in sparc.h because it's not known what    other assemblers will accept.  */
end_comment

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_v9
end_if

begin_undef
undef|#
directive|undef
name|ASM_CPU_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_DEFAULT_SPEC
value|"-xarch=v8plus"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_ultrasparc
end_if

begin_undef
undef|#
directive|undef
name|ASM_CPU_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_DEFAULT_SPEC
value|"-xarch=v8plusa"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ASM_CPU_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_SPEC
value|"\ %{mcpu=v8plus:-xarch=v8plus} \ %{mcpu=ultrasparc:-xarch=v8plusa} \ %{!mcpu*:%(asm_cpu_default)} \ "
end_define

begin_comment
comment|/* However it appears that Solaris 2.0 uses the same reg numbering as    the old BSD-style system did. */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_comment
comment|/* Same as sparc.h */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(TARGET_FLAT&& REGNO == FRAME_POINTER_REGNUM ? 31 : REGNO)
end_define

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

begin_comment
comment|/* The Solaris 2 assembler uses .skip, not .zero, so put this back. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SKIP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|fprintf (FILE, "\t.skip %u\n", (SIZE))
end_define

begin_comment
comment|/* Use .uahalf/.uaword so packed structure members don't generate    assembler errors when using the native assembler.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SHORT
end_undef

begin_define
define|#
directive|define
name|ASM_SHORT
value|".uahalf"
end_define

begin_undef
undef|#
directive|undef
name|ASM_LONG
end_undef

begin_define
define|#
directive|define
name|ASM_LONG
value|".uaword"
end_define

begin_comment
comment|/* This is how to output a definition of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, ".L%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output a reference to an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, ".L%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf ((LABEL), "*.L%s%ld", (PREFIX), (long)(NUM))
end_define

begin_escape
end_escape

begin_comment
comment|/* We don't use the standard svr4 STARTFILE_SPEC because it's wrong for us.    We don't use the standard LIB_SPEC only because we don't yet support c++ */
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
value|"%{!shared: \ 			 %{!symbolic: \ 			  %{p:mcrt1.o%s} \                           %{!p: \ 	                    %{pg:gcrt1.o%s gmon.o%s} \                             %{!pg:crt1.o%s}}}} \ 			crti.o%s \ 			%{ansi:values-Xc.o%s} \ 			%{!ansi: \ 			 %{traditional:values-Xt.o%s} \ 			 %{!traditional:values-Xa.o%s}} \ 			crtbegin.o%s"
end_define

begin_comment
comment|/* ??? Note: in order for -compat-bsd to work fully,    we must somehow arrange to fixincludes /usr/ucbinclude    and put the result in $(libsubdir)/ucbinclude.  */
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
value|"%{compat-bsd:-lucb -lsocket -lnsl -lelf -laio} \    %{!shared:\      %{!symbolic:\        %{pthreads:-lpthread} \        %{!pthreads:%{threads:-lthread}} \        -lc}}"
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
value|"crtend.o%s crtn.o%s"
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
value|"%{h*} %{v:-V} \    %{b} %{Wl,*:%*} \    %{static:-dn -Bstatic} \    %{shared:-G -dy %{!mimpure-text:-z text}} \    %{symbolic:-Bsymbolic -G -dy -z text} \    %{G:-G} \    %{YP,*} \    %{R*} \    %{compat-bsd: \      %{!YP,*:%{p:-Y P,/usr/ucblib:/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{pg:-Y P,/usr/ucblib:/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{!p:%{!pg:-Y P,/usr/ucblib:/usr/ccs/lib:/usr/lib}}} \      -R /usr/ucblib} \    %{!compat-bsd: \      %{!YP,*:%{p:-Y P,/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{pg:-Y P,/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{!p:%{!pg:-Y P,/usr/ccs/lib:/usr/lib}}}} \    %{Qy:} %{!Qn:-Qy}"
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
value|(DEFAULT_SWITCH_TAKES_ARG(CHAR) \    || (CHAR) == 'R' \    || (CHAR) == 'h' \    || (CHAR) == 'x' \    || (CHAR) == 'z')
end_define

begin_escape
end_escape

begin_comment
comment|/* ??? This does not work in SunOS 4.x, so it is not enabled in sparc.h.    Instead, it is enabled here, because it does work under Solaris.  */
end_comment

begin_comment
comment|/* Define for support of TFmode long double and REAL_ARITHMETIC.    Sparc ABI says that long double is 4 words.  */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_comment
comment|/* But indicate that it isn't supported by the hardware.  */
end_comment

begin_define
define|#
directive|define
name|WIDEST_HARDWARE_FP_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|STDC_0_IN_SYSTEM_HEADERS
end_define

begin_define
define|#
directive|define
name|MULDI3_LIBCALL
value|"__mul64"
end_define

begin_define
define|#
directive|define
name|DIVDI3_LIBCALL
value|"__div64"
end_define

begin_define
define|#
directive|define
name|UDIVDI3_LIBCALL
value|"__udiv64"
end_define

begin_define
define|#
directive|define
name|MODDI3_LIBCALL
value|"__rem64"
end_define

begin_define
define|#
directive|define
name|UMODDI3_LIBCALL
value|"__urem64"
end_define

begin_undef
undef|#
directive|undef
name|INIT_SUBTARGET_OPTABS
end_undef

begin_define
define|#
directive|define
name|INIT_SUBTARGET_OPTABS
define|\
value|fixsfdi_libfunc = gen_rtx_SYMBOL_REF (Pmode, \ 	TARGET_ARCH64 ? "__ftol" : "__ftoll");	\   fixunssfdi_libfunc = gen_rtx_SYMBOL_REF (Pmode, \ 	TARGET_ARCH64 ? "__ftoul" : "__ftoull");	\   fixdfdi_libfunc = gen_rtx_SYMBOL_REF (Pmode, \ 	TARGET_ARCH64 ? "__dtol" : "__dtoll");	\   fixunsdfdi_libfunc = gen_rtx_SYMBOL_REF (Pmode, \ 	TARGET_ARCH64 ? "__dtoul" : "__dtoull")
end_define

begin_comment
comment|/* No weird SPARC variants on Solaris */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_LIVE_G0
end_undef

begin_define
define|#
directive|define
name|TARGET_LIVE_G0
value|0
end_define

begin_undef
undef|#
directive|undef
name|TARGET_BROKEN_SAVERESTORE
end_undef

begin_define
define|#
directive|define
name|TARGET_BROKEN_SAVERESTORE
value|0
end_define

begin_comment
comment|/* Solaris allows 64 bit out and global registers in 32 bit mode.    sparc_override_options will disable V8+ if not generating V9 code.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_APP_REGS + MASK_EPILOGUE + MASK_FPU + MASK_V8PLUS)
end_define

begin_escape
end_escape

begin_comment
comment|/* Override MACHINE_STATE_{SAVE,RESTORE} because we have special    traps available which can get and set the condition codes    reliably.  */
end_comment

begin_undef
undef|#
directive|undef
name|MACHINE_STATE_SAVE
end_undef

begin_define
define|#
directive|define
name|MACHINE_STATE_SAVE
parameter_list|(
name|ID
parameter_list|)
define|\
value|unsigned long int ms_flags, ms_saveret;		\   asm volatile("ta	0x20\n\t"			\ 	       "mov	%%g1, %0\n\t"			\ 	       "mov	%%g2, %1\n\t"			\ 	       : "=r" (ms_flags), "=r" (ms_saveret));
end_define

begin_undef
undef|#
directive|undef
name|MACHINE_STATE_RESTORE
end_undef

begin_define
define|#
directive|define
name|MACHINE_STATE_RESTORE
parameter_list|(
name|ID
parameter_list|)
define|\
value|asm volatile("mov	%0, %%g1\n\t"			\ 	       "mov	%1, %%g2\n\t"			\ 	       "ta	0x21\n\t"			\ 	       :
comment|/* no outputs */
value|\ 	       : "r" (ms_flags), "r" (ms_saveret));
end_define

end_unit

