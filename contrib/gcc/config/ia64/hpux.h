begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine GNU compiler.  IA-64 version.    Copyright (C) 1999, 2000, 2001 Free Software Foundation, Inc.    Contributed by Steve Ellcey<sje@cup.hp.com> and                   Reva Cuthbertson<reva@cup.hp.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This macro is a C statement to print on `stderr' a string describing the    particular machine description choice.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (IA-64) HP-UX");
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"\   -D__IA64__ -D__ia64 -D__ia64__ -D__hpux -D__hpux__ -Dhpux -Dunix \   -D__BIG_ENDIAN__ -D_LONGLONG -D__ELF__ \   -Asystem=hpux -Asystem=posix -Asystem=unix -Acpu=ia64 -Amachine=ia64 \   -D_UINT128_T"
end_define

begin_comment
comment|/* -D__fpreg=long double is needed to compensate for the lack of __fpreg    which is a primitive type in HP C but does not exist in GNU C.  Same    for __float80 and __float128.  These types appear in HP-UX header    files and so must have some definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\   %{mcpu=itanium:-D__itanium__} \   %{mlp64:-D__LP64__ -D__LONG_MAX__=9223372036854775807L} \   %{!ansi:%{!std=c*:%{!std=i*: -D_HPUX_SOURCE -D__STDC_EXT__}}} \   -D__fpreg=long\\ double \   -D__float80=long\\ double \   -D__float128=long\\ double"
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-x %{mconstant-gp} %{mauto-pic} \   %{milp32:-milp32} %{mlp64:-mlp64}"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{!shared:crt0%O%s}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"/usr/ccs/lib/hpux64/crt0%O"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\   +Accept TypeMismatch \   %{shared:-b} \   %{!shared: \     -u main \     %{!static: \       %{rdynamic:-export-dynamic}} \       %{static:-static}}"
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
value|"%{!shared:%{!symbolic:-lc}}"
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{ "ilp32",    MASK_ILP32,     "Generate ILP32 code" }, \   { "lp64",    -MASK_ILP32,     "Generate LP64 code" },
end_define

begin_comment
comment|/* A C expression whose value is zero if pointers that need to be extended    from being `POINTER_SIZE' bits wide to `Pmode' are sign-extended and    greater then zero if they are zero-extended and less then zero if the    ptr_extend instruction should be used.  */
end_comment

begin_define
define|#
directive|define
name|POINTERS_EXTEND_UNSIGNED
value|-1
end_define

begin_define
define|#
directive|define
name|DONT_USE_BUILTIN_SETJMP
end_define

begin_define
define|#
directive|define
name|JMP_BUF_SIZE
value|(8 * 76)
end_define

begin_undef
undef|#
directive|undef
name|CONST_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CONST_SECTION_ASM_OP
value|"\t.section\t.rodata,\t\"a\",\t\"progbits\""
end_define

begin_undef
undef|#
directive|undef
name|BITS_BIG_ENDIAN
end_undef

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|1
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_DWARF2_ASM | MASK_BIG_ENDIAN)
end_define

begin_comment
comment|/* This needs to be set to force structure arguments with a single    field to be treated as structures and not as the type of their    field.  Without this a structure with a single char will be    returned just like a char variable and that is wrong on HP-UX    IA64.  TARGET_STRUCT_ARG_REG_LITTLE_ENDIAN triggers the special    structure handling, this macro simply ensures that single field    structures are always treated like structures.  */
end_comment

begin_define
define|#
directive|define
name|MEMBER_TYPE_FORCES_BLK
parameter_list|(
name|FIELD
parameter_list|)
value|1
end_define

begin_comment
comment|/* Override the setting of FUNCTION_ARG_REG_LITTLE_ENDIAN in    defaults.h.  Setting this to true means that we are not passing    structures in registers in the "normal" big-endian way.  See    See section 8.5 of the "Itanium Software Conventions and Runtime    Architecture", specifically Table 8-1 and the explanation of Byte 0    alignment and LSB alignment and a description of how structures    are passed.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REG_LITTLE_ENDIAN
value|1
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_ARG_PADDING
end_undef

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|ia64_hpux_function_arg_padding ((MODE), (TYPE))
end_define

begin_undef
undef|#
directive|undef
name|PAD_VARARGS_DOWN
end_undef

begin_define
define|#
directive|define
name|PAD_VARARGS_DOWN
value|(!AGGREGATE_TYPE_P (type))
end_define

end_unit

