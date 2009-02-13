begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an OpenBSD i386 target.        Copyright (C) 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This gets defined in tm.h->linux.h->svr4.h, and keeps us from using    libraries compiled with the native cc, so undef it. */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_comment
comment|/* Override the default comment-starter of "/".  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"#"
end_define

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
value|svr4_dbx_register_map[n]
end_define

begin_comment
comment|/* This goes away when the math-emulator is fixed */
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
define|\
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS | MASK_NO_FANCY_MATH_387)
end_define

begin_comment
comment|/* Run-time target specifications */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\     	OPENBSD_OS_CPP_BUILTINS();		\     }						\   while (0)
end_define

begin_comment
comment|/* As an elf system, we need crtbegin/crtend stuff.  */
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
value|"\ 	%{!shared: %{pg:gcrt0%O%s} %{!pg:%{p:gcrt0%O%s} %{!p:crt0%O%s}} \ 	crtbegin%O%s} %{shared:crtbeginS%O%s}"
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
value|"%{!shared:crtend%O%s} %{shared:crtendS%O%s}"
end_define

begin_comment
comment|/* Layout of source language data types.  */
end_comment

begin_comment
comment|/* This must agree with<machine/ansi.h> */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Assembler format: overall framework.  */
end_comment

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

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set\t"
end_define

begin_comment
comment|/* The following macros were originally stolen from i386v4.h.    These have to be defined to get PIC code correct.  */
end_comment

begin_comment
comment|/* Assembler format: dispatch tables.  */
end_comment

begin_comment
comment|/* Assembler format: sections.  */
end_comment

begin_comment
comment|/* Stack& calling: aggregate returns.  */
end_comment

begin_comment
comment|/* Don't default to pcc-struct-return, because gcc is the only compiler, and    we want to retain compatibility with older gcc versions.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/* Assembler format: alignment output.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifdef

begin_define
define|#
directive|define
name|ASM_OUTPUT_MAX_SKIP_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|,
name|MAX_SKIP
parameter_list|)
define|\
value|if ((LOG) != 0) {\     if ((MAX_SKIP) == 0) fprintf ((FILE), "\t.p2align %d\n", (LOG)); \     else fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP)); \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Stack& calling: profiling.  */
end_comment

begin_comment
comment|/* OpenBSD's profiler recovers all information from the stack pointer.    The icky part is not here, but in machine/profile.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|fputs (flag_pic ? "\tcall __mcount@PLT\n": "\tcall __mcount\n", FILE);
end_define

begin_comment
comment|/* Assembler format: exception region output.  */
end_comment

begin_comment
comment|/* our configuration still doesn't handle dwarf2 correctly */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_comment
comment|/* Assembler format: alignment output.  */
end_comment

begin_comment
comment|/* Note that we pick up ASM_OUTPUT_MAX_SKIP_ALIGN from i386/gas.h */
end_comment

begin_comment
comment|/* Note that we pick up ASM_OUTPUT_MI_THUNK from unix.h.  */
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
value|"%{!shared:%{!nostdlib:%{!r*:%{!e*:-e __start}}}} \    %{shared:-shared} %{R*} \    %{static:-Bstatic} \    %{!static:-Bdynamic} \    %{assert*} \    %{!dynamic-linker:-dynamic-linker /usr/libexec/ld.so}"
end_define

begin_define
define|#
directive|define
name|OBSD_HAS_CORRECT_SPECS
end_define

end_unit

