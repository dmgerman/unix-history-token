begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an OpenBSD i386 target.    Copyright (C) 1999, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is tested by i386gas.h.  */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_include
include|#
directive|include
file|<i386/gstabs.h>
end_include

begin_comment
comment|/* Get generic OpenBSD definitions.  */
end_comment

begin_define
define|#
directive|define
name|OBSD_OLD_GAS
end_define

begin_include
include|#
directive|include
file|<openbsd.h>
end_include

begin_comment
comment|/* This goes away when the math-emulator is fixed */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_SUBTARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_SUBTARGET_DEFAULT
define|\
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS | MASK_NO_FANCY_MATH_387)
end_define

begin_comment
comment|/* Run-time target specifications */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__unix__ -D__OpenBSD__ \  -Asystem=unix -Asystem=bsd -Asystem=OpenBSD"
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
value|32
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

begin_comment
comment|/* Kludgy test: when gas is upgraded, it will have p2align, and no problems    with nops.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifndef

begin_comment
comment|/* i386 OpenBSD still uses an older gas that doesn't insert nops by default    when the .align directive demands to insert extra space in the text    segment.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG)!=0) fprintf ((FILE), "\t.align %d,0x90\n", (LOG))
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
value|fputs (flag_pic ? "\tcall mcount@PLT\n": "\tcall mcount\n", FILE);
end_define

begin_comment
comment|/* Assembler format: exception region output.  */
end_comment

begin_comment
comment|/* All configurations that don't use elf must be explicit about not using    dwarf unwind information. egcs doesn't try too hard to check internal    configuration files...  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_undef
undef|#
directive|undef
name|ASM_PREFERRED_EH_DATA_FORMAT
end_undef

begin_comment
comment|/* Assembler format: alignment output.  */
end_comment

begin_comment
comment|/* A C statement to output to the stdio stream FILE an assembler    command to advance the location counter to a multiple of 1<<LOG    bytes if it is within MAX_SKIP bytes.     This will be used to align code labels according to Intel     recommendations, in prevision of binutils upgrade.  */
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
value|do {									\     if ((LOG) != 0) {							\       if ((MAX_SKIP) == 0) fprintf ((FILE), "\t.p2align %d\n", (LOG));	\       else fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP));	\     }									\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Note that we pick up ASM_OUTPUT_MI_THUNK from unix.h.  */
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
value|";#"
end_define

end_unit

