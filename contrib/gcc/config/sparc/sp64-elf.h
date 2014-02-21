begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC, for SPARC64, ELF.    Copyright (C) 1994, 1995, 1996, 1997, 1998, 2000, 2004, 2005    Free Software Foundation, Inc.    Contributed by Doug Evans, dje@cygnus.com.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
value|fprintf (stderr, " (sparc64-elf)")
end_define

begin_comment
comment|/* A 64 bit v9 compiler in a Medium/Anywhere code model environment.  */
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
value|(MASK_V9 + MASK_PTR64 + MASK_64BIT + MASK_HARD_QUAD \  + MASK_APP_REGS + MASK_FPU + MASK_STACK_BIAS + MASK_LONG_DOUBLE_128)
end_define

begin_undef
undef|#
directive|undef
name|SPARC_DEFAULT_CMODEL
end_undef

begin_define
define|#
directive|define
name|SPARC_DEFAULT_CMODEL
value|CM_EMBMEDANY
end_define

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* __svr4__ is used by the C library (FIXME) */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|"-D__svr4__"
end_define

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{v:-V} -s %{fpic|fPIC|fpie|fPIE:-K PIC} \ %{mlittle-endian:-EL} \ %(asm_cpu) %(asm_arch) \ "
end_define

begin_comment
comment|/* This is taken from sol2.h.  */
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
value|"\ %{v:-V} \ %{mlittle-endian:-EL} \ "
end_define

begin_comment
comment|/* We need something a little simpler for the embedded environment.    Profiling doesn't really work yet so we just copy the default.  */
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
value|"\ %{!shared:%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}} \ crtbegin.o%s \ "
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
value|"%{ffast-math|funsafe-math-optimizations:crtfastmath.o%s} \    crtend.o%s"
end_define

begin_comment
comment|/* Use the default (for now).  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

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

begin_undef
undef|#
directive|undef
name|BYTES_BIG_ENDIAN
end_undef

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|(! TARGET_LITTLE_ENDIAN)
end_define

begin_undef
undef|#
directive|undef
name|WORDS_BIG_ENDIAN
end_undef

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|(! TARGET_LITTLE_ENDIAN)
end_define

begin_escape
end_escape

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
comment|/* ??? This should be 32 bits for v9 but what can we do?  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
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
value|16
end_define

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_comment
comment|/* The medium/anywhere code model practically requires us to put jump tables    in the text section as gcc is unable to distinguish LABEL_REF's of jump    tables from other label refs (when we need to).  */
end_comment

begin_comment
comment|/* But we now defer the tables to the end of the function, so we make    this 0 to not confuse the branch shortening code.  */
end_comment

begin_undef
undef|#
directive|undef
name|JUMP_TABLES_IN_TEXT_SECTION
end_undef

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|0
end_define

end_unit

