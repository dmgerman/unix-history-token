begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target macros for the FRV port of GCC.    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.    Contributed by Red Hat Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FRV_H__
end_ifndef

begin_define
define|#
directive|define
name|__FRV_H__
end_define

begin_comment
comment|/* Frv general purpose macros.  */
end_comment

begin_comment
comment|/* Align an address.  */
end_comment

begin_define
define|#
directive|define
name|ADDR_ALIGN
parameter_list|(
name|addr
parameter_list|,
name|align
parameter_list|)
value|(((addr) + (align) - 1)& ~((align) - 1))
end_define

begin_comment
comment|/* Return true if a value is inside a range.  */
end_comment

begin_define
define|#
directive|define
name|IN_RANGE_P
parameter_list|(
name|VALUE
parameter_list|,
name|LOW
parameter_list|,
name|HIGH
parameter_list|)
define|\
value|(   (((HOST_WIDE_INT)(VALUE))>= (HOST_WIDE_INT)(LOW))	\&& (((HOST_WIDE_INT)(VALUE))<= ((HOST_WIDE_INT)(HIGH))))
end_define

begin_escape
end_escape

begin_comment
comment|/* Driver configuration.  */
end_comment

begin_comment
comment|/* A C expression which determines whether the option `-CHAR' takes arguments.    The value should be the number of arguments that option takes-zero, for many    options.     By default, this macro is defined to handle the standard options properly.    You need not define it unless you wish to add additional options which take    arguments.     Defined in svr4.h.  */
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
value|(DEFAULT_SWITCH_TAKES_ARG (CHAR) || (CHAR) == 'G')
end_define

begin_comment
comment|/* A C expression which determines whether the option `-NAME' takes arguments.    The value should be the number of arguments that option takes-zero, for many    options.  This macro rather than `SWITCH_TAKES_ARG' is used for    multi-character option names.     By default, this macro is defined as `DEFAULT_WORD_SWITCH_TAKES_ARG', which    handles the standard options properly.  You need not define    `WORD_SWITCH_TAKES_ARG' unless you wish to add additional options which take    arguments.  Any redefinition should call `DEFAULT_WORD_SWITCH_TAKES_ARG' and    then check for additional options.     Defined in svr4.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|WORD_SWITCH_TAKES_ARG
end_undef

begin_comment
comment|/* A C string constant that tells the GCC driver program options to pass to    the assembler.  It can also specify how to translate options you give to GNU    CC into options for GCC to pass to the assembler.  See the file `sun3.h'    for an example of this.     Do not define this macro if it does not need to do anything.     Defined in svr4.h.  */
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
value|"\ %{G*} %{v} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*} \ %{mtomcat-stats} \ %{!mno-eflags: \     %{mcpu=*} \     %{mgpr-*} %{mfpr-*} \     %{msoft-float} %{mhard-float} \     %{mdword} %{mno-dword} \     %{mdouble} %{mno-double} \     %{mmedia} %{mno-media} \     %{mmuladd} %{mno-muladd} \     %{mpack} %{mno-pack} \     %{fpic|fpie: -mpic} %{fPIC|fPIE: -mPIC} %{mlibrary-pic}}"
end_define

begin_comment
comment|/* Another C string constant used much like `LINK_SPEC'.  The difference    between the two is that `STARTFILE_SPEC' is used at the very beginning of    the command given to the linker.     If this macro is not defined, a default is provided that loads the standard    C startup file from the usual place.  See `gcc.c'.     Defined in svr4.h.  */
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
value|"crt0%O%s frvbegin%O%s"
end_define

begin_comment
comment|/* Another C string constant used much like `LINK_SPEC'.  The difference    between the two is that `ENDFILE_SPEC' is used at the very end of the    command given to the linker.     Do not define this macro if it does not need to do anything.     Defined in svr4.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"frvend%O%s"
end_define

begin_comment
comment|/* A C string constant that tells the GCC driver program options to pass to    CPP.  It can also specify how to translate options you give to GCC into    options for GCC to pass to the CPP.     Do not define this macro if it does not need to do anything.  */
end_comment

begin_comment
comment|/* The idea here is to use the -mcpu option to define macros based on the    processor's features, using the features of the default processor if    no -mcpu option is given.  These macros can then be overridden by    other -m options.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{mcpu=frv: %(cpp_frv)} \ %{mcpu=fr500: %(cpp_fr500)} \ %{mcpu=fr400: %(cpp_fr400)} \ %{mcpu=fr300: %(cpp_simple)} \ %{mcpu=tomcat: %(cpp_fr500)} \ %{mcpu=simple: %(cpp_simple)} \ %{!mcpu*: %(cpp_cpu_default)} \ %{mno-media: -D__FRV_ACC__=0 %{msoft-float: -D__FRV_FPR__=0}} \ %{mhard-float: -D__FRV_HARD_FLOAT__} \ %{msoft-float: -U__FRV_HARD_FLOAT__} \ %{mgpr-32: -U__FRV_GPR__ -D__FRV_GPR__=32} \ %{mgpr-64: -U__FRV_GPR__ -D__FRV_GPR__=64} \ %{mfpr-32: -U__FRV_FPR__ -D__FRV_FPR__=32} \ %{mfpr-64: -U__FRV_FPR__ -D__FRV_FPR__=64} \ %{macc-4: -U__FRV_ACC__ -D__FRV_ACC__=4} \ %{macc-8: -U__FRV_ACC__ -D__FRV_ACC__=8} \ %{mdword: -D__FRV_DWORD__} \ %{mno-dword: -U__FRV_DWORD__} \ %{mno-pack: -U__FRV_VLIW__} \ %{fleading-underscore: -D__FRV_UNDERSCORE__}"
end_define

begin_comment
comment|/* CPU defaults.  Each CPU has its own CPP spec that defines the default    macros for that CPU.  Each CPU also has its own default target mask.     CPU		GPRs	FPRs	ACCs	FPU	MulAdd  ldd/std  Issue rate    ---		----    ----    ----    ---	------  -------  ----------    FRV		64	64	8	double	yes	yes      4    FR500	64	64	8	single	no	yes      4    FR400	32	32	4	none	no	yes      2    Simple	32	0	0	none	no	no       1 */
end_comment

begin_define
define|#
directive|define
name|CPP_FRV_SPEC
value|"\ -D__FRV_GPR__=64 \ -D__FRV_FPR__=64 \ -D__FRV_ACC__=8 \ -D__FRV_HARD_FLOAT__ \ -D__FRV_DWORD__ \ -D__FRV_VLIW__=4"
end_define

begin_define
define|#
directive|define
name|CPP_FR500_SPEC
value|"\ -D__FRV_GPR__=64 \ -D__FRV_FPR__=64 \ -D__FRV_ACC__=8 \ -D__FRV_HARD_FLOAT__ \ -D__FRV_DWORD__ \ -D__FRV_VLIW__=4"
end_define

begin_define
define|#
directive|define
name|CPP_FR400_SPEC
value|"\ -D__FRV_GPR__=32 \ -D__FRV_FPR__=32 \ -D__FRV_ACC__=4 \ -D__FRV_DWORD__ \ -D__FRV_VLIW__=2"
end_define

begin_define
define|#
directive|define
name|CPP_SIMPLE_SPEC
value|"\ -D__FRV_GPR__=32 \ -D__FRV_FPR__=0 \ -D__FRV_ACC__=0 \ %{mmedia: -D__FRV_ACC__=8} \ %{mhard-float|mmedia: -D__FRV_FPR__=64}"
end_define

begin_define
define|#
directive|define
name|MASK_DEFAULT_FRV
define|\
value|(MASK_MEDIA			\    | MASK_DOUBLE		\    | MASK_MULADD		\    | MASK_DWORD			\    | MASK_PACK)
end_define

begin_define
define|#
directive|define
name|MASK_DEFAULT_FR500
define|\
value|(MASK_MEDIA | MASK_DWORD | MASK_PACK)
end_define

begin_define
define|#
directive|define
name|MASK_DEFAULT_FR400
define|\
value|(MASK_GPR_32			\    | MASK_FPR_32		\    | MASK_MEDIA			\    | MASK_ACC_4			\    | MASK_SOFT_FLOAT		\    | MASK_DWORD			\    | MASK_PACK)
end_define

begin_define
define|#
directive|define
name|MASK_DEFAULT_SIMPLE
define|\
value|(MASK_GPR_32 | MASK_SOFT_FLOAT)
end_define

begin_comment
comment|/* A C string constant that tells the GCC driver program options to pass to    `cc1'.  It can also specify how to translate options you give to GCC into    options for GCC to pass to the `cc1'.     Do not define this macro if it does not need to do anything.  */
end_comment

begin_comment
comment|/* For ABI compliance, we need to put bss data into the normal data section.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{G*}"
end_define

begin_comment
comment|/* A C string constant that tells the GCC driver program options to pass to    the linker.  It can also specify how to translate options you give to GCC    into options for GCC to pass to the linker.     Do not define this macro if it does not need to do anything.     Defined in svr4.h.  */
end_comment

begin_comment
comment|/* Override the svr4.h version with one that dispenses without the svr4    shared library options, notably -G.  */
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
value|"\ %{h*} %{v:-V} \ %{b} %{Wl,*:%*} \ %{static:-dn -Bstatic} \ %{shared:-Bdynamic} \ %{symbolic:-Bsymbolic} \ %{G*} \ %{YP,*} \ %{Qy:} %{!Qn:-Qy}"
end_define

begin_comment
comment|/* Another C string constant used much like `LINK_SPEC'.  The difference    between the two is that `LIB_SPEC' is used at the end of the command given    to the linker.     If this macro is not defined, a default is provided that loads the standard    C library from the usual place.  See `gcc.c'.     Defined in svr4.h.  */
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
value|"--start-group -lc -lsim --end-group"
end_define

begin_comment
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GCC driver    program.     Do not define this macro if it does not need to do anything.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_EXTRA_SPECS
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXTRA_SPECS
define|\
value|{ "cpp_frv",		CPP_FRV_SPEC },					\   { "cpp_fr500",	CPP_FR500_SPEC },				\   { "cpp_fr400",	CPP_FR400_SPEC },				\   { "cpp_simple",	CPP_SIMPLE_SPEC },				\   { "cpp_cpu_default",	CPP_CPU_DEFAULT_SPEC },				\   SUBTARGET_EXTRA_SPECS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_CPU_DEFAULT_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|CPP_FR500_SPEC
end_define

begin_define
define|#
directive|define
name|CPU_TYPE
value|FRV_CPU_FR500
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allow us to easily change the default for -malloc-cc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_NO_ALLOC_CC
end_ifndef

begin_define
define|#
directive|define
name|MASK_DEFAULT_ALLOC_CC
value|MASK_ALLOC_CC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MASK_DEFAULT_ALLOC_CC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Run-time target specifications */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       builtin_define ("__frv__");		\       builtin_assert ("machine=frv");		\     }						\   while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* This declaration should be present.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This series of macros is to allow compiler command arguments to enable or    disable the use of optional features of the target machine.  For example,    one machine description serves both the 68000 and the 68020; a command    argument tells the compiler whether it should use 68020-only instructions or    not.  This command argument works by means of a macro `TARGET_68020' that    tests a bit in `target_flags'.     Define a macro `TARGET_FEATURENAME' for each such option.  Its definition    should test a bit in `target_flags'; for example:          #define TARGET_68020 (target_flags& 1)     One place where these macros are used is in the condition-expressions of    instruction patterns.  Note how `TARGET_68020' appears frequently in the    68000 machine description file, `m68k.md'.  Another place they are used is    in the definitions of the other macros in the `MACHINE.h' file.  */
end_comment

begin_define
define|#
directive|define
name|MASK_GPR_32
value|0x00000001
end_define

begin_comment
comment|/* Limit gprs to 32 registers */
end_comment

begin_define
define|#
directive|define
name|MASK_FPR_32
value|0x00000002
end_define

begin_comment
comment|/* Limit fprs to 32 registers */
end_comment

begin_define
define|#
directive|define
name|MASK_SOFT_FLOAT
value|0x00000004
end_define

begin_comment
comment|/* Use software floating point */
end_comment

begin_define
define|#
directive|define
name|MASK_ALLOC_CC
value|0x00000008
end_define

begin_comment
comment|/* Dynamically allocate icc/fcc's */
end_comment

begin_define
define|#
directive|define
name|MASK_DWORD
value|0x00000010
end_define

begin_comment
comment|/* Change ABi to allow dbl word insns*/
end_comment

begin_define
define|#
directive|define
name|MASK_DOUBLE
value|0x00000020
end_define

begin_comment
comment|/* Use double precision instructions */
end_comment

begin_define
define|#
directive|define
name|MASK_MEDIA
value|0x00000040
end_define

begin_comment
comment|/* Use media instructions */
end_comment

begin_define
define|#
directive|define
name|MASK_MULADD
value|0x00000080
end_define

begin_comment
comment|/* Use multiply add/subtract insns */
end_comment

begin_define
define|#
directive|define
name|MASK_LIBPIC
value|0x00000100
end_define

begin_comment
comment|/* -fpic that can be linked w/o pic */
end_comment

begin_define
define|#
directive|define
name|MASK_ACC_4
value|0x00000200
end_define

begin_comment
comment|/* Only use four media accumulators */
end_comment

begin_define
define|#
directive|define
name|MASK_PACK
value|0x00000400
end_define

begin_comment
comment|/* Set to enable packed output */
end_comment

begin_comment
comment|/* put debug masks up high */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_ARG
value|0x40000000
end_define

begin_comment
comment|/* debug argument handling */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_ADDR
value|0x20000000
end_define

begin_comment
comment|/* debug go_if_legitimate_address */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_STACK
value|0x10000000
end_define

begin_comment
comment|/* debug stack frame */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG
value|0x08000000
end_define

begin_comment
comment|/* general debugging switch */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_LOC
value|0x04000000
end_define

begin_comment
comment|/* optimize line # table */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_COND_EXEC
value|0x02000000
end_define

begin_comment
comment|/* debug cond exec code */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_COND_MOVE
value|0x01000000
end_define

begin_comment
comment|/* disable conditional moves */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_SCC
value|0x00800000
end_define

begin_comment
comment|/* disable set conditional codes */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_COND_EXEC
value|0x00400000
end_define

begin_comment
comment|/* disable conditional execution */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_VLIW_BRANCH
value|0x00200000
end_define

begin_comment
comment|/* disable repacking branches */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_MULTI_CE
value|0x00100000
end_define

begin_comment
comment|/* disable multi-level cond exec */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_NESTED_CE
value|0x00080000
end_define

begin_comment
comment|/* disable nested cond exec */
end_comment

begin_define
define|#
directive|define
name|MASK_DEFAULT
value|MASK_DEFAULT_ALLOC_CC
end_define

begin_define
define|#
directive|define
name|TARGET_GPR_32
value|((target_flags& MASK_GPR_32) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_FPR_32
value|((target_flags& MASK_FPR_32) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_SOFT_FLOAT
value|((target_flags& MASK_SOFT_FLOAT) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_ALLOC_CC
value|((target_flags& MASK_ALLOC_CC) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_DWORD
value|((target_flags& MASK_DWORD) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_DOUBLE
value|((target_flags& MASK_DOUBLE) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_MEDIA
value|((target_flags& MASK_MEDIA) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_MULADD
value|((target_flags& MASK_MULADD) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_LIBPIC
value|((target_flags& MASK_LIBPIC) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_ACC_4
value|((target_flags& MASK_ACC_4) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_ARG
value|((target_flags& MASK_DEBUG_ARG) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_ADDR
value|((target_flags& MASK_DEBUG_ADDR) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_STACK
value|((target_flags& MASK_DEBUG_STACK) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG
value|((target_flags& MASK_DEBUG) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_LOC
value|((target_flags& MASK_DEBUG_LOC) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_COND_EXEC
value|((target_flags& MASK_DEBUG_COND_EXEC) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_COND_MOVE
value|((target_flags& MASK_NO_COND_MOVE) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_SCC
value|((target_flags& MASK_NO_SCC) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_COND_EXEC
value|((target_flags& MASK_NO_COND_EXEC) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_VLIW_BRANCH
value|((target_flags& MASK_NO_VLIW_BRANCH) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_MULTI_CE
value|((target_flags& MASK_NO_MULTI_CE) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_NESTED_CE
value|((target_flags& MASK_NO_NESTED_CE) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_PACK
value|((target_flags& MASK_PACK) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_GPR_64
value|(! TARGET_GPR_32)
end_define

begin_define
define|#
directive|define
name|TARGET_FPR_64
value|(! TARGET_FPR_32)
end_define

begin_define
define|#
directive|define
name|TARGET_HARD_FLOAT
value|(! TARGET_SOFT_FLOAT)
end_define

begin_define
define|#
directive|define
name|TARGET_FIXED_CC
value|(! TARGET_ALLOC_CC)
end_define

begin_define
define|#
directive|define
name|TARGET_COND_MOVE
value|(! TARGET_NO_COND_MOVE)
end_define

begin_define
define|#
directive|define
name|TARGET_SCC
value|(! TARGET_NO_SCC)
end_define

begin_define
define|#
directive|define
name|TARGET_COND_EXEC
value|(! TARGET_NO_COND_EXEC)
end_define

begin_define
define|#
directive|define
name|TARGET_VLIW_BRANCH
value|(! TARGET_NO_VLIW_BRANCH)
end_define

begin_define
define|#
directive|define
name|TARGET_MULTI_CE
value|(! TARGET_NO_MULTI_CE)
end_define

begin_define
define|#
directive|define
name|TARGET_NESTED_CE
value|(! TARGET_NO_NESTED_CE)
end_define

begin_define
define|#
directive|define
name|TARGET_ACC_8
value|(! TARGET_ACC_4)
end_define

begin_define
define|#
directive|define
name|TARGET_HAS_FPRS
value|(TARGET_HARD_FLOAT || TARGET_MEDIA)
end_define

begin_define
define|#
directive|define
name|NUM_GPRS
value|(TARGET_GPR_32? 32 : 64)
end_define

begin_define
define|#
directive|define
name|NUM_FPRS
value|(!TARGET_HAS_FPRS? 0 : TARGET_FPR_32? 32 : 64)
end_define

begin_define
define|#
directive|define
name|NUM_ACCS
value|(!TARGET_MEDIA? 0 : TARGET_ACC_4? 4 : 8)
end_define

begin_comment
comment|/* Macros to identify the blend of media instructions available.  Revision 1    is the one found on the FR500.  Revision 2 includes the changes made for    the FR400.     Treat the generic processor as a revision 1 machine for now, for    compatibility with earlier releases.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEDIA_REV1
define|\
value|(TARGET_MEDIA							\&& (frv_cpu_type == FRV_CPU_GENERIC				\        || frv_cpu_type == FRV_CPU_FR500))
end_define

begin_define
define|#
directive|define
name|TARGET_MEDIA_REV2
define|\
value|(TARGET_MEDIA&& frv_cpu_type == FRV_CPU_FR400)
end_define

begin_comment
comment|/* This macro defines names of command options to set and clear bits in    `target_flags'.  Its definition is an initializer with a subgrouping for    each command option.     Each subgrouping contains a string constant, that defines the option name,    a number, which contains the bits to set in `target_flags', and an optional    second string which is the textual description that will be displayed when    the user passes --help on the command line.  If the number entry is negative    then the specified bits will be cleared instead of being set.  If the second    string entry is present but empty, then no help information will be displayed    for that option, but it will not count as an undocumented option.  The actual    option name, asseen on the command line is made by appending `-m' to the    specified name.     One of the subgroupings should have a null string.  The number in this    grouping is the default value for `target_flags'.  Any target options act    starting with that value.     Here is an example which defines `-m68000' and `-m68020' with opposite    meanings, and picks the latter as the default:          #define TARGET_SWITCHES \           { { "68020",  1, ""},      \             { "68000", -1, "Compile for the m68000"},     \             { "",       1, }}     This declaration must be present.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{{ "gpr-32",		  MASK_GPR_32,		"Only use 32 gprs"},	    \  { "gpr-64",		 -MASK_GPR_32,		"Use 64 gprs"},		    \  { "fpr-32",		  MASK_FPR_32,		"Only use 32 fprs"},	    \  { "fpr-64",		 -MASK_FPR_32,		"Use 64 fprs"},		    \  { "hard-float",	 -MASK_SOFT_FLOAT,	"Use hardware floating point" },\  { "soft-float",	  MASK_SOFT_FLOAT,	"Use software floating point" },\  { "alloc-cc",		  MASK_ALLOC_CC,	"Dynamically allocate cc's" }, \  { "fixed-cc",		 -MASK_ALLOC_CC,	"Just use icc0/fcc0" },	    \  { "dword",		  MASK_DWORD,		"Change ABI to allow double word insns" }, \  { "no-dword",		 -MASK_DWORD,		"Do not use double word insns" }, \  { "double",		  MASK_DOUBLE,		"Use fp double instructions" }, \  { "no-double",		 -MASK_DOUBLE,		"Do not use fp double insns" }, \  { "media",		  MASK_MEDIA,		"Use media instructions" }, \  { "no-media",		 -MASK_MEDIA,		"Do not use media insns" }, \  { "muladd",		  MASK_MULADD,		"Use multiply add/subtract instructions" }, \  { "no-muladd",		 -MASK_MULADD,		"Do not use multiply add/subtract insns" }, \  { "library-pic",	  MASK_LIBPIC,		"PIC support for building libraries" }, \  { "acc-4",		  MASK_ACC_4,		"Use 4 media accumulators" }, \  { "acc-8",		 -MASK_ACC_4,		"Use 8 media accumulators" }, \  { "pack",		  MASK_PACK,		"Pack VLIW instructions" }, \  { "no-pack",		 -MASK_PACK,		"Do not pack VLIW instructions" }, \  { "no-eflags",		  0,			"Do not mark ABI switches in e_flags" }, \  { "debug-arg",		  MASK_DEBUG_ARG,	"Internal debug switch" },  \  { "debug-addr",	  MASK_DEBUG_ADDR,	"Internal debug switch" },  \  { "debug-stack",	  MASK_DEBUG_STACK,	"Internal debug switch" },  \  { "debug",		  MASK_DEBUG,		"Internal debug switch" },  \  { "debug-cond-exec",	  MASK_DEBUG_COND_EXEC,	"Internal debug switch" },  \  { "debug-loc",		  MASK_DEBUG_LOC,	"Internal debug switch" },  \  { "cond-move",		 -MASK_NO_COND_MOVE,	"Enable conditional moves" },  \  { "no-cond-move",	  MASK_NO_COND_MOVE,	"Disable conditional moves" },  \  { "scc",		 -MASK_NO_SCC,		"Enable setting gprs to the result of comparisons" },  \  { "no-scc",		  MASK_NO_SCC,		"Disable setting gprs to the result of comparisons" },  \  { "cond-exec",		 -MASK_NO_COND_EXEC,	"Enable conditional execution other than moves/scc" }, \  { "no-cond-exec",	  MASK_NO_COND_EXEC,	"Disable conditional execution other than moves/scc" }, \  { "vliw-branch",	 -MASK_NO_VLIW_BRANCH,	"Run pass to pack branches into VLIW insns" }, \  { "no-vliw-branch",	  MASK_NO_VLIW_BRANCH,	"Do not run pass to pack branches into VLIW insns" }, \  { "multi-cond-exec",	 -MASK_NO_MULTI_CE,	"Disable optimizing&&/|| in conditional execution" }, \  { "no-multi-cond-exec",  MASK_NO_MULTI_CE,	"Enable optimizing&&/|| in conditional execution" }, \  { "nested-cond-exec",	 -MASK_NO_NESTED_CE,	"Enable nested conditional execution optimizations" }, \  { "no-nested-cond-exec" ,MASK_NO_NESTED_CE,	"Disable nested conditional execution optimizations" }, \  { "tomcat-stats",	  0, 			"Cause gas to print tomcat statistics" }, \  { "",			  MASK_DEFAULT,		"" }}
end_define

begin_comment
unit|\
comment|/* This macro is similar to `TARGET_SWITCHES' but defines names of command    options that have values.  Its definition is an initializer with a    subgrouping for each command option.     Each subgrouping contains a string constant, that defines the fixed part of    the option name, the address of a variable, and an optional description string.    The variable, of type `char *', is set to the text following the fixed part of    the option as it is specified on the command line.  The actual option name is    made by appending `-m' to the specified name.     Here is an example which defines `-mshort-data-NUMBER'.  If the given option    is `-mshort-data-512', the variable `m88k_short_data' will be set to the    string `"512"'.          extern char *m88k_short_data;         #define TARGET_OPTIONS \          { { "short-data-",& m88k_short_data, \ 	 "Specify the size of the short data section"  } }     This declaration is optional.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OPTIONS
define|\
value|{									      \   { "cpu=",&frv_cpu_string,	 "Set cpu type", 0},	      \   { "branch-cost=",&frv_branch_cost_string, "Internal debug switch", 0}, \   { "cond-exec-insns=",&frv_condexec_insns_str, "Internal debug switch", 0}, \   { "cond-exec-temps=",&frv_condexec_temps_str, "Internal debug switch", 0}, \   { "sched-lookahead=",&frv_sched_lookahead_str,"Internal debug switch", 0}, \ }
end_define

begin_comment
comment|/* This macro is a C statement to print on `stderr' a string describing the    particular machine description choice.  Every machine description should    define `TARGET_VERSION'.  For example:          #ifdef MOTOROLA         #define TARGET_VERSION \           fprintf (stderr, " (68k, Motorola syntax)");         #else         #define TARGET_VERSION \           fprintf (stderr, " (68k, MIT syntax)");         #endif  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, _(" (frv)"))
end_define

begin_comment
comment|/* Sometimes certain combinations of command options do not make sense on a    particular target machine.  You can define a macro `OVERRIDE_OPTIONS' to    take account of this.  This macro, if defined, is executed once just after    all the command options have been parsed.     Don't use this macro to turn on various extra optimizations for `-O'.  That    is what `OPTIMIZATION_OPTIONS' is for.  */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
value|frv_override_options ()
end_define

begin_comment
comment|/* Some machines may desire to change what optimizations are performed for    various optimization levels.  This macro, if defined, is executed once just    after the optimization level is determined and before the remainder of the    command options have been parsed.  Values set in this macro are used as the    default values for the other command line options.     LEVEL is the optimization level specified; 2 if `-O2' is specified, 1 if    `-O' is specified, and 0 if neither is specified.     SIZE is nonzero if `-Os' is specified, 0 otherwise.     You should not use this macro to change options that are not    machine-specific.  These should uniformly selected by the same optimization    level on all supported machines.  Use this macro to enable machbine-specific    optimizations.     *Do not examine `write_symbols' in this macro!* The debugging options are    *not supposed to alter the generated code.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|LEVEL
parameter_list|,
name|SIZE
parameter_list|)
value|frv_optimization_options (LEVEL, SIZE)
end_define

begin_comment
comment|/* Define this macro if debugging can be performed even without a frame    pointer.  If this macro is defined, GCC will turn on the    `-fomit-frame-pointer' option whenever `-O' is specified.  */
end_comment

begin_comment
comment|/* Frv needs a specific frame layout that includes the frame pointer.  */
end_comment

begin_define
define|#
directive|define
name|CAN_DEBUG_WITHOUT_FP
end_define

begin_escape
end_escape

begin_comment
comment|/* Small Data Area Support.  */
end_comment

begin_comment
comment|/* Maximum size of variables that go in .sdata/.sbss.    The -msdata=foo switch also controls how small variables are handled.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SDATA_DEFAULT_SIZE
end_ifndef

begin_define
define|#
directive|define
name|SDATA_DEFAULT_SIZE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Storage Layout */
end_comment

begin_comment
comment|/* Define this macro to have the value 1 if the most significant bit in a byte    has the lowest number; otherwise define it to have the value zero.  This    means that bit-field instructions count from the most significant bit.  If    the machine has no bit-field instructions, then this must still be defined,    but it doesn't matter which value it is defined to.  This macro need not be    a constant.     This macro does not affect the way structure fields are packed into bytes or    words; that is controlled by `BYTES_BIG_ENDIAN'.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this macro to have the value 1 if the most significant byte in a word    has the lowest number.  This macro need not be a constant.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this macro to have the value 1 if, in a multiword object, the most    significant word has the lowest number.  This applies to both memory    locations and registers; GCC fundamentally assumes that the order of    words in memory is the same as the order in registers.  This macro need not    be a constant.  */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Number of storage units in a word; normally 4.  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|4
end_define

begin_comment
comment|/* A macro to update MODE and UNSIGNEDP when an object whose type is TYPE and    which has the specified mode and signedness is to be stored in a register.    This macro is only called when TYPE is a scalar type.     On most RISC machines, which only have operations that operate on a full    register, define this macro to set M to `word_mode' if M is an integer mode    narrower than `BITS_PER_WORD'.  In most cases, only integer modes should be    widened because wider-precision floating-point operations are usually more    expensive than their narrower counterparts.     For most machines, the macro definition does not change UNSIGNEDP.  However,    some machines, have instructions that preferentially handle either signed or    unsigned quantities of certain modes.  For example, on the DEC Alpha, 32-bit    loads from memory and 32-bit add instructions sign-extend the result to 64    bits.  On such machines, set UNSIGNEDP according to which kind of extension    is more efficient.     Do not define this macro if it would never modify MODE.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_MODE
parameter_list|(
name|MODE
parameter_list|,
name|UNSIGNEDP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|do						\     {						\       if (GET_MODE_CLASS (MODE) == MODE_INT	\&& GET_MODE_SIZE (MODE)< 4)		\ 	(MODE) = SImode;			\     }						\   while (0)
end_define

begin_comment
comment|/* Normal alignment required for function parameters on the stack, in bits.    All stack parameters receive at least this much alignment regardless of data    type.  On most machines, this is the same as the size of an integer.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|32
end_define

begin_comment
comment|/* Define this macro if you wish to preserve a certain alignment for the stack    pointer.  The definition is a C expression for the desired alignment    (measured in bits).     If `PUSH_ROUNDING' is not defined, the stack will always be aligned to the    specified boundary.  If `PUSH_ROUNDING' is defined and specifies a less    strict alignment than `STACK_BOUNDARY', the stack may be momentarily    unaligned while pushing arguments.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|64
end_define

begin_comment
comment|/* Alignment required for a function entry point, in bits.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|128
end_define

begin_comment
comment|/* Biggest alignment that any data type can require on this machine,    in bits.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|64
end_define

begin_comment
comment|/* @@@ A hack, needed because libobjc wants to use ADJUST_FIELD_ALIGN for    some reason.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_TARGET_LIBS
end_ifdef

begin_define
define|#
directive|define
name|BIGGEST_FIELD_ALIGNMENT
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* An expression for the alignment of a structure field FIELD if the    alignment computed in the usual way is COMPUTED.  GCC uses this    value instead of the value in `BIGGEST_ALIGNMENT' or    `BIGGEST_FIELD_ALIGNMENT', if defined, for structure fields only.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_FIELD_ALIGN
parameter_list|(
name|FIELD
parameter_list|,
name|COMPUTED
parameter_list|)
define|\
value|frv_adjust_field_align (FIELD, COMPUTED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If defined, a C expression to compute the alignment for a static variable.    TYPE is the data type, and ALIGN is the alignment that the object    would ordinarily have.  The value of this macro is used instead of that    alignment to align the object.     If this macro is not defined, then ALIGN is used.     One use of this macro is to increase alignment of medium-size data to make    it all fit in fewer cache lines.  Another is to cause character arrays to be    word-aligned so that `strcpy' calls that copy constants to character arrays    can be done inline.  */
end_comment

begin_define
define|#
directive|define
name|DATA_ALIGNMENT
parameter_list|(
name|TYPE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == ARRAY_TYPE		\&& TYPE_MODE (TREE_TYPE (TYPE)) == QImode	\&& (ALIGN)< BITS_PER_WORD ? BITS_PER_WORD : (ALIGN))
end_define

begin_comment
comment|/* If defined, a C expression to compute the alignment given to a constant that    is being placed in memory.  CONSTANT is the constant and ALIGN is the    alignment that the object would ordinarily have.  The value of this macro is    used instead of that alignment to align the object.     If this macro is not defined, then ALIGN is used.     The typical use of this macro is to increase alignment for string constants    to be word aligned so that `strcpy' calls that copy constants can be done    inline.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ALIGNMENT
parameter_list|(
name|EXP
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|(TREE_CODE (EXP) == STRING_CST	\&& (ALIGN)< BITS_PER_WORD ? BITS_PER_WORD : (ALIGN))
end_define

begin_comment
comment|/* Define this macro to be the value 1 if instructions will fail to work if    given data not on the nominal alignment.  If instructions will merely go    slower in that case, define this macro as 0.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_comment
comment|/* Define this if you wish to imitate the way many other C compilers handle    alignment of bitfields and the structures that contain them.     The behavior is that the type written for a bit-field (`int', `short', or    other integer type) imposes an alignment for the entire structure, as if the    structure really did contain an ordinary field of that type.  In addition,    the bit-field is placed within the structure so that it would fit within such    a field, not crossing a boundary for it.     Thus, on most machines, a bit-field whose type is written as `int' would not    cross a four-byte boundary, and would force four-byte alignment for the    whole structure.  (The alignment used may not be four bytes; it is    controlled by the other alignment parameters.)     If the macro is defined, its definition should be a C expression; a nonzero    value for the expression enables this behavior.     Note that if this macro is not defined, or its value is zero, some bitfields    may cross more than one alignment boundary.  The compiler can support such    references if there are `insv', `extv', and `extzv' insns that can directly    reference memory.     The other known way of making bitfields work is to define    `STRUCTURE_SIZE_BOUNDARY' as large as `BIGGEST_ALIGNMENT'.  Then every    structure can be accessed with fullwords.     Unless the machine has bit-field instructions or you define    `STRUCTURE_SIZE_BOUNDARY' that way, you must define    `PCC_BITFIELD_TYPE_MATTERS' to have a nonzero value.     If your aim is to make GCC use the same conventions for laying out    bitfields as are used by another compiler, here is how to investigate what    the other compiler does.  Compile and run this program:          struct foo1         {           char x;           char :0;           char y;         };          struct foo2         {           char x;           int :0;           char y;         };          main ()         {           printf ("Size of foo1 is %d\n",                   sizeof (struct foo1));           printf ("Size of foo2 is %d\n",                   sizeof (struct foo2));           exit (0);         }     If this prints 2 and 5, then the compiler's behavior is what you would get    from `PCC_BITFIELD_TYPE_MATTERS'.     Defined in svr4.h.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Layout of Source Language Data Types.  */
end_comment

begin_define
define|#
directive|define
name|CHAR_TYPE_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|SHORT_TYPE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|LONG_LONG_TYPE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|FLOAT_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|DOUBLE_TYPE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* An expression whose value is 1 or 0, according to whether the type `char'    should be signed or unsigned by default.  The user can always override this    default with the options `-fsigned-char' and `-funsigned-char'.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* General purpose registers.  */
end_comment

begin_define
define|#
directive|define
name|GPR_FIRST
value|0
end_define

begin_comment
comment|/* First gpr */
end_comment

begin_define
define|#
directive|define
name|GPR_LAST
value|(GPR_FIRST + 63)
end_define

begin_comment
comment|/* Last gpr */
end_comment

begin_define
define|#
directive|define
name|GPR_R0
value|GPR_FIRST
end_define

begin_comment
comment|/* R0, constant 0 */
end_comment

begin_define
define|#
directive|define
name|GPR_FP
value|(GPR_FIRST + 2)
end_define

begin_comment
comment|/* Frame pointer */
end_comment

begin_define
define|#
directive|define
name|GPR_SP
value|(GPR_FIRST + 1)
end_define

begin_comment
comment|/* Stack pointer */
end_comment

begin_comment
comment|/* small data register */
end_comment

begin_define
define|#
directive|define
name|SDA_BASE_REG
value|((unsigned)(flag_pic ? PIC_REGNO : (GPR_FIRST+16)))
end_define

begin_define
define|#
directive|define
name|PIC_REGNO
value|(GPR_FIRST + 17)
end_define

begin_comment
comment|/* PIC register */
end_comment

begin_define
define|#
directive|define
name|FPR_FIRST
value|64
end_define

begin_comment
comment|/* First FP reg */
end_comment

begin_define
define|#
directive|define
name|FPR_LAST
value|127
end_define

begin_comment
comment|/* Last  FP reg */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CONDEXEC_TEMPS
value|4
end_define

begin_comment
comment|/* reserve 4 regs by default */
end_comment

begin_define
define|#
directive|define
name|GPR_TEMP_NUM
value|frv_condexec_temps
end_define

begin_comment
comment|/* # gprs to reserve for temps */
end_comment

begin_comment
comment|/* We reserve the last CR and CCR in each category to be used as a reload    register to reload the CR/CCR registers.  This is a kludge.  */
end_comment

begin_define
define|#
directive|define
name|CC_FIRST
value|128
end_define

begin_comment
comment|/* First ICC/FCC reg */
end_comment

begin_define
define|#
directive|define
name|CC_LAST
value|135
end_define

begin_comment
comment|/* Last  ICC/FCC reg */
end_comment

begin_define
define|#
directive|define
name|ICC_FIRST
value|(CC_FIRST + 4)
end_define

begin_comment
comment|/* First ICC reg */
end_comment

begin_define
define|#
directive|define
name|ICC_LAST
value|(CC_FIRST + 7)
end_define

begin_comment
comment|/* Last  ICC reg */
end_comment

begin_define
define|#
directive|define
name|ICC_TEMP
value|(CC_FIRST + 7)
end_define

begin_comment
comment|/* Temporary ICC reg */
end_comment

begin_define
define|#
directive|define
name|FCC_FIRST
value|(CC_FIRST)
end_define

begin_comment
comment|/* First FCC reg */
end_comment

begin_define
define|#
directive|define
name|FCC_LAST
value|(CC_FIRST + 3)
end_define

begin_comment
comment|/* Last  FCC reg */
end_comment

begin_comment
comment|/* Amount to shift a value to locate a ICC or FCC register in the CCR    register and shift it to the bottom 4 bits.  */
end_comment

begin_define
define|#
directive|define
name|CC_SHIFT_RIGHT
parameter_list|(
name|REGNO
parameter_list|)
value|(((REGNO) - CC_FIRST)<< 2)
end_define

begin_comment
comment|/* Mask to isolate a single ICC/FCC value.  */
end_comment

begin_define
define|#
directive|define
name|CC_MASK
value|0xf
end_define

begin_comment
comment|/* Masks to isolate the various bits in an ICC field.  */
end_comment

begin_define
define|#
directive|define
name|ICC_MASK_N
value|0x8
end_define

begin_comment
comment|/* negative */
end_comment

begin_define
define|#
directive|define
name|ICC_MASK_Z
value|0x4
end_define

begin_comment
comment|/* zero */
end_comment

begin_define
define|#
directive|define
name|ICC_MASK_V
value|0x2
end_define

begin_comment
comment|/* overflow */
end_comment

begin_define
define|#
directive|define
name|ICC_MASK_C
value|0x1
end_define

begin_comment
comment|/* carry */
end_comment

begin_comment
comment|/* Mask to isolate the N/Z flags in an ICC.  */
end_comment

begin_define
define|#
directive|define
name|ICC_MASK_NZ
value|(ICC_MASK_N | ICC_MASK_Z)
end_define

begin_comment
comment|/* Mask to isolate the Z/C flags in an ICC.  */
end_comment

begin_define
define|#
directive|define
name|ICC_MASK_ZC
value|(ICC_MASK_Z | ICC_MASK_C)
end_define

begin_comment
comment|/* Masks to isolate the various bits in a FCC field.  */
end_comment

begin_define
define|#
directive|define
name|FCC_MASK_E
value|0x8
end_define

begin_comment
comment|/* equal */
end_comment

begin_define
define|#
directive|define
name|FCC_MASK_L
value|0x4
end_define

begin_comment
comment|/* less than */
end_comment

begin_define
define|#
directive|define
name|FCC_MASK_G
value|0x2
end_define

begin_comment
comment|/* greater than */
end_comment

begin_define
define|#
directive|define
name|FCC_MASK_U
value|0x1
end_define

begin_comment
comment|/* unordered */
end_comment

begin_comment
comment|/* For CCR registers, the machine wants CR4..CR7 to be used for integer    code and CR0..CR3 to be used for floating point.  */
end_comment

begin_define
define|#
directive|define
name|CR_FIRST
value|136
end_define

begin_comment
comment|/* First CCR */
end_comment

begin_define
define|#
directive|define
name|CR_LAST
value|143
end_define

begin_comment
comment|/* Last  CCR */
end_comment

begin_define
define|#
directive|define
name|CR_NUM
value|(CR_LAST-CR_FIRST+1)
end_define

begin_comment
comment|/* # of CCRs (8) */
end_comment

begin_define
define|#
directive|define
name|ICR_FIRST
value|(CR_FIRST + 4)
end_define

begin_comment
comment|/* First integer CCR */
end_comment

begin_define
define|#
directive|define
name|ICR_LAST
value|(CR_FIRST + 7)
end_define

begin_comment
comment|/* Last  integer CCR */
end_comment

begin_define
define|#
directive|define
name|ICR_TEMP
value|ICR_LAST
end_define

begin_comment
comment|/* Temp  integer CCR */
end_comment

begin_define
define|#
directive|define
name|FCR_FIRST
value|(CR_FIRST + 0)
end_define

begin_comment
comment|/* First float CCR */
end_comment

begin_define
define|#
directive|define
name|FCR_LAST
value|(CR_FIRST + 3)
end_define

begin_comment
comment|/* Last  float CCR */
end_comment

begin_comment
comment|/* Amount to shift a value to locate a CR register in the CCCR special purpose    register and shift it to the bottom 2 bits.  */
end_comment

begin_define
define|#
directive|define
name|CR_SHIFT_RIGHT
parameter_list|(
name|REGNO
parameter_list|)
value|(((REGNO) - CR_FIRST)<< 1)
end_define

begin_comment
comment|/* Mask to isolate a single CR value.  */
end_comment

begin_define
define|#
directive|define
name|CR_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|ACC_FIRST
value|144
end_define

begin_comment
comment|/* First acc register */
end_comment

begin_define
define|#
directive|define
name|ACC_LAST
value|151
end_define

begin_comment
comment|/* Last  acc register */
end_comment

begin_define
define|#
directive|define
name|ACCG_FIRST
value|152
end_define

begin_comment
comment|/* First accg register */
end_comment

begin_define
define|#
directive|define
name|ACCG_LAST
value|159
end_define

begin_comment
comment|/* Last  accg register */
end_comment

begin_define
define|#
directive|define
name|AP_FIRST
value|160
end_define

begin_comment
comment|/* fake argument pointer */
end_comment

begin_define
define|#
directive|define
name|SPR_FIRST
value|161
end_define

begin_define
define|#
directive|define
name|SPR_LAST
value|162
end_define

begin_define
define|#
directive|define
name|LR_REGNO
value|(SPR_FIRST)
end_define

begin_define
define|#
directive|define
name|LCR_REGNO
value|(SPR_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|GPR_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, GPR_FIRST, GPR_LAST)
end_define

begin_define
define|#
directive|define
name|GPR_OR_AP_P
parameter_list|(
name|R
parameter_list|)
value|(GPR_P (R) || (R) == ARG_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|FPR_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, FPR_FIRST, FPR_LAST)
end_define

begin_define
define|#
directive|define
name|CC_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, CC_FIRST, CC_LAST)
end_define

begin_define
define|#
directive|define
name|ICC_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, ICC_FIRST, ICC_LAST)
end_define

begin_define
define|#
directive|define
name|FCC_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, FCC_FIRST, FCC_LAST)
end_define

begin_define
define|#
directive|define
name|CR_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, CR_FIRST, CR_LAST)
end_define

begin_define
define|#
directive|define
name|ICR_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, ICR_FIRST, ICR_LAST)
end_define

begin_define
define|#
directive|define
name|FCR_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, FCR_FIRST, FCR_LAST)
end_define

begin_define
define|#
directive|define
name|ACC_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, ACC_FIRST, ACC_LAST)
end_define

begin_define
define|#
directive|define
name|ACCG_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, ACCG_FIRST, ACCG_LAST)
end_define

begin_define
define|#
directive|define
name|SPR_P
parameter_list|(
name|R
parameter_list|)
value|IN_RANGE_P (R, SPR_FIRST, SPR_LAST)
end_define

begin_define
define|#
directive|define
name|GPR_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(GPR_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|FPR_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(FPR_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|GPR_AP_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(GPR_OR_AP_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|CC_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(CC_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|ICC_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(ICC_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|FCC_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(FCC_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|CR_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(CR_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|ICR_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(ICR_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|FCR_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(FCR_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|ACC_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(ACC_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|ACCG_OR_PSEUDO_P
parameter_list|(
name|R
parameter_list|)
value|(ACCG_P (R) || (R)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|MAX_STACK_IMMEDIATE_OFFSET
value|2047
end_define

begin_escape
end_escape

begin_comment
comment|/* Register Basics.  */
end_comment

begin_comment
comment|/* Number of hardware registers known to the compiler.  They receive numbers 0    through `FIRST_PSEUDO_REGISTER-1'; thus, the first pseudo register's number    really is assigned the number `FIRST_PSEUDO_REGISTER'.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|(SPR_LAST + 1)
end_define

begin_comment
comment|/* The first/last register that can contain the arguments to a function.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_ARG_REGNUM
value|(GPR_FIRST + 8)
end_define

begin_define
define|#
directive|define
name|LAST_ARG_REGNUM
value|(FIRST_ARG_REGNUM + FRV_NUM_ARG_REGS - 1)
end_define

begin_comment
comment|/* Registers used by the exception handling functions.  These should be    registers that are not otherwised used by the calling sequence.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_EH_REGNUM
value|14
end_define

begin_define
define|#
directive|define
name|LAST_EH_REGNUM
value|15
end_define

begin_comment
comment|/* Scratch registers used in the prologue, epilogue and thunks.    OFFSET_REGNO is for loading constant addends that are too big for a    single instruction.  TEMP_REGNO is used for transferring SPRs to and from    the stack, and various other activities.  */
end_comment

begin_define
define|#
directive|define
name|OFFSET_REGNO
value|4
end_define

begin_define
define|#
directive|define
name|TEMP_REGNO
value|5
end_define

begin_comment
comment|/* Registers used in the prologue.  OLD_SP_REGNO is the old stack pointer,    which is sometimes used to set up the frame pointer.  */
end_comment

begin_define
define|#
directive|define
name|OLD_SP_REGNO
value|6
end_define

begin_comment
comment|/* Registers used in the epilogue.  STACKADJ_REGNO stores the exception    handler's stack adjustment.  */
end_comment

begin_define
define|#
directive|define
name|STACKADJ_REGNO
value|6
end_define

begin_comment
comment|/* Registers used in thunks.  JMP_REGNO is used for loading the target    address.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_REGNO
value|6
end_define

begin_define
define|#
directive|define
name|EH_RETURN_DATA_REGNO
parameter_list|(
name|N
parameter_list|)
value|((N)<= (LAST_EH_REGNUM - FIRST_EH_REGNUM)? \ 				 (N) + FIRST_EH_REGNUM : INVALID_REGNUM)
end_define

begin_define
define|#
directive|define
name|EH_RETURN_STACKADJ_RTX
value|gen_rtx_REG (SImode, STACKADJ_REGNO)
end_define

begin_define
define|#
directive|define
name|EH_RETURN_HANDLER_RTX
value|RETURN_ADDR_RTX (0, frame_pointer_rtx)
end_define

begin_comment
comment|/* An initializer that says which registers are used for fixed purposes all    throughout the compiled code and are therefore not available for general    allocation.  These would include the stack pointer, the frame pointer    (except on machines where that can be used as a general register when no    frame pointer is needed), the program counter on machines where that is    considered one of the addressable registers, and any other numbered register    with a standard use.     This information is expressed as a sequence of numbers, separated by commas    and surrounded by braces.  The Nth number is 1 if register N is fixed, 0    otherwise.     The table initialized from this macro, and the table initialized by the    following one, may be overridden at run time either automatically, by the    actions of the macro `CONDITIONAL_REGISTER_USAGE', or by the user with the    command options `-ffixed-REG', `-fcall-used-REG' and `-fcall-saved-REG'.  */
end_comment

begin_comment
comment|/* gr0  -- Hard Zero    gr1  -- Stack Pointer    gr2  -- Frame Pointer    gr3  -- Hidden Parameter    gr16 -- Small Data reserved    gr17 -- Pic reserved    gr28 -- OS reserved    gr29 -- OS reserved    gr30 -- OS reserved    gr31 -- OS reserved    cr3  -- reserved to reload FCC registers.    cr7  -- reserved to reload ICC registers.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{
comment|/* Integer Registers */
value|\ 	1, 1, 1, 1, 0, 0, 0, 0,
comment|/* 000-007, gr0  - gr7  */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 008-015, gr8  - gr15 */
value|\ 	1, 1, 0, 0, 0, 0, 0, 0,
comment|/* 016-023, gr16 - gr23 */
value|\ 	0, 0, 0, 0, 1, 1, 1, 1,
comment|/* 024-031, gr24 - gr31 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 032-039, gr32 - gr39 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 040-040, gr48 - gr47 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 048-055, gr48 - gr55 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 056-063, gr56 - gr63 */
value|\
comment|/* Float Registers */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 064-071, fr0  - fr7  */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 072-079, fr8  - fr15 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 080-087, fr16 - fr23 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 088-095, fr24 - fr31 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 096-103, fr32 - fr39 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 104-111, fr48 - fr47 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 112-119, fr48 - fr55 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 120-127, fr56 - fr63 */
value|\
comment|/* Condition Code Registers */
value|\ 	0, 0, 0, 0,
comment|/* 128-131, fcc0 - fcc3  */
value|\ 	0, 0, 0, 1,
comment|/* 132-135, icc0 - icc3 */
value|\
comment|/* Conditional execution Registers (CCR) */
value|\ 	0, 0, 0, 0, 0, 0, 0, 1,
comment|/* 136-143, cr0 - cr7 */
value|\
comment|/* Accumulators */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 144-151, acc0  - acc7 */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 152-159, accg0 - accg7 */
value|\
comment|/* Other registers */
value|\ 	1,
comment|/* 160, AP   - fake arg ptr */
value|\ 	0,
comment|/* 161, LR   - Link register*/
value|\ 	0,
comment|/* 162, LCR  - Loop count reg*/
value|\ }
end_define

begin_comment
comment|/* Like `FIXED_REGISTERS' but has 1 for each register that is clobbered (in    general) by function calls as well as for fixed registers.  This macro    therefore identifies the registers that are not available for general    allocation of values that must live across function calls.     If a register has 0 in `CALL_USED_REGISTERS', the compiler automatically    saves it on function entry and restores it on function exit, if the register    is used within the function.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{
comment|/* Integer Registers */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 000-007, gr0  - gr7  */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 008-015, gr8  - gr15 */
value|\ 	1, 1, 0, 0, 0, 0, 0, 0,
comment|/* 016-023, gr16 - gr23 */
value|\ 	0, 0, 0, 0, 1, 1, 1, 1,
comment|/* 024-031, gr24 - gr31 */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 032-039, gr32 - gr39 */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 040-040, gr48 - gr47 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 048-055, gr48 - gr55 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 056-063, gr56 - gr63 */
value|\
comment|/* Float Registers */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 064-071, fr0  - fr7  */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 072-079, fr8  - fr15 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 080-087, fr16 - fr23 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 088-095, fr24 - fr31 */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 096-103, fr32 - fr39 */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 104-111, fr48 - fr47 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 112-119, fr48 - fr55 */
value|\ 	0, 0, 0, 0, 0, 0, 0, 0,
comment|/* 120-127, fr56 - fr63 */
value|\
comment|/* Condition Code Registers */
value|\ 	1, 1, 1, 1,
comment|/* 128-131, fcc0 - fcc3 */
value|\ 	1, 1, 1, 1,
comment|/* 132-135, icc0 - icc3  */
value|\
comment|/* Conditional execution Registers (CCR) */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 136-143, cr0 - cr7 */
value|\
comment|/* Accumulators */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 144-151, acc0 - acc7 */
value|\ 	1, 1, 1, 1, 1, 1, 1, 1,
comment|/* 152-159, accg0 - accg7 */
value|\
comment|/* Other registers */
value|\ 	1,
comment|/* 160, AP  - fake arg ptr */
value|\ 	1,
comment|/* 161, LR  - Link register*/
value|\ 	1,
comment|/* 162, LCR - Loop count reg */
value|\ }
end_define

begin_comment
comment|/* Zero or more C statements that may conditionally modify two variables    `fixed_regs' and `call_used_regs' (both of type `char []') after they have    been initialized from the two preceding macros.     This is necessary in case the fixed or call-clobbered registers depend on    target flags.     You need not define this macro if it has no work to do.     If the usage of an entire class of registers depends on the target flags,    you may indicate this to GCC by using this macro to modify `fixed_regs' and    `call_used_regs' to 1 for each of the registers in the classes which should    not be used by GCC.  Also define the macro `REG_CLASS_FROM_LETTER' to return    `NO_REGS' if it is called with a letter for a class that shouldn't be used.     (However, if this class is not included in `GENERAL_REGS' and all of the    insn patterns whose constraints permit this class are controlled by target    switches, then GCC will automatically avoid using these registers when the    target switches are opposed to them.)  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
value|frv_conditional_register_usage ()
end_define

begin_escape
end_escape

begin_comment
comment|/* Order of allocation of registers.  */
end_comment

begin_comment
comment|/* If defined, an initializer for a vector of integers, containing the numbers    of hard registers in the order in which GCC should prefer to use them    (from most preferred to least).     If this macro is not defined, registers are used lowest numbered first (all    else being equal).     One use of this macro is on machines where the highest numbered registers    must always be saved and the save-multiple-registers instruction supports    only sequences of consecutive registers.  On such machines, define    `REG_ALLOC_ORDER' to be an initializer that lists the highest numbered    allocatable register first.  */
end_comment

begin_comment
comment|/* On the FRV, allocate GR16 and GR17 after other saved registers so that we    have a better chance of allocating 2 registers at a time and can use the    double word load/store instructions in the prologue.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{									\
comment|/* volatile registers */
value|\   GPR_FIRST  +  4, GPR_FIRST  +  5, GPR_FIRST  +  6, GPR_FIRST 	+  7,	\   GPR_FIRST  +  8, GPR_FIRST  +  9, GPR_FIRST  + 10, GPR_FIRST 	+ 11,	\   GPR_FIRST  + 12, GPR_FIRST  + 13, GPR_FIRST  + 14, GPR_FIRST 	+ 15,	\   GPR_FIRST  + 32, GPR_FIRST  + 33, GPR_FIRST  + 34, GPR_FIRST 	+ 35,	\   GPR_FIRST  + 36, GPR_FIRST  + 37, GPR_FIRST  + 38, GPR_FIRST 	+ 39,	\   GPR_FIRST  + 40, GPR_FIRST  + 41, GPR_FIRST  + 42, GPR_FIRST 	+ 43,	\   GPR_FIRST  + 44, GPR_FIRST  + 45, GPR_FIRST  + 46, GPR_FIRST 	+ 47,	\ 									\   FPR_FIRST  +  0, FPR_FIRST  +  1, FPR_FIRST  +  2, FPR_FIRST 	+  3,	\   FPR_FIRST  +  4, FPR_FIRST  +  5, FPR_FIRST  +  6, FPR_FIRST 	+  7,	\   FPR_FIRST  +  8, FPR_FIRST  +  9, FPR_FIRST  + 10, FPR_FIRST 	+ 11,	\   FPR_FIRST  + 12, FPR_FIRST  + 13, FPR_FIRST  + 14, FPR_FIRST 	+ 15,	\   FPR_FIRST  + 32, FPR_FIRST  + 33, FPR_FIRST  + 34, FPR_FIRST 	+ 35,	\   FPR_FIRST  + 36, FPR_FIRST  + 37, FPR_FIRST  + 38, FPR_FIRST 	+ 39,	\   FPR_FIRST  + 40, FPR_FIRST  + 41, FPR_FIRST  + 42, FPR_FIRST 	+ 43,	\   FPR_FIRST  + 44, FPR_FIRST  + 45, FPR_FIRST  + 46, FPR_FIRST 	+ 47,	\ 									\   ICC_FIRST  +  0, ICC_FIRST  +  1, ICC_FIRST  +  2, ICC_FIRST 	+  3,	\   FCC_FIRST  +  0, FCC_FIRST  +  1, FCC_FIRST  +  2, FCC_FIRST 	+  3,	\   CR_FIRST   +  0, CR_FIRST   +  1, CR_FIRST   +  2, CR_FIRST  	+  3,	\   CR_FIRST   +  4, CR_FIRST   +  5, CR_FIRST   +  6, CR_FIRST  	+  7,	\ 									\
comment|/* saved registers */
value|\   GPR_FIRST  + 18, GPR_FIRST  + 19,					\   GPR_FIRST  + 20, GPR_FIRST  + 21, GPR_FIRST  + 22, GPR_FIRST 	+ 23,	\   GPR_FIRST  + 24, GPR_FIRST  + 25, GPR_FIRST  + 26, GPR_FIRST 	+ 27,	\   GPR_FIRST  + 48, GPR_FIRST  + 49, GPR_FIRST  + 50, GPR_FIRST 	+ 51,	\   GPR_FIRST  + 52, GPR_FIRST  + 53, GPR_FIRST  + 54, GPR_FIRST 	+ 55,	\   GPR_FIRST  + 56, GPR_FIRST  + 57, GPR_FIRST  + 58, GPR_FIRST 	+ 59,	\   GPR_FIRST  + 60, GPR_FIRST  + 61, GPR_FIRST  + 62, GPR_FIRST 	+ 63,	\   GPR_FIRST  + 16, GPR_FIRST  + 17,					\ 									\   FPR_FIRST  + 16, FPR_FIRST  + 17, FPR_FIRST  + 18, FPR_FIRST 	+ 19,	\   FPR_FIRST  + 20, FPR_FIRST  + 21, FPR_FIRST  + 22, FPR_FIRST 	+ 23,	\   FPR_FIRST  + 24, FPR_FIRST  + 25, FPR_FIRST  + 26, FPR_FIRST 	+ 27,	\   FPR_FIRST  + 28, FPR_FIRST  + 29, FPR_FIRST  + 30, FPR_FIRST 	+ 31,	\   FPR_FIRST  + 48, FPR_FIRST  + 49, FPR_FIRST  + 50, FPR_FIRST 	+ 51,	\   FPR_FIRST  + 52, FPR_FIRST  + 53, FPR_FIRST  + 54, FPR_FIRST 	+ 55,	\   FPR_FIRST  + 56, FPR_FIRST  + 57, FPR_FIRST  + 58, FPR_FIRST 	+ 59,	\   FPR_FIRST  + 60, FPR_FIRST  + 61, FPR_FIRST  + 62, FPR_FIRST 	+ 63,	\ 									\
comment|/* special or fixed registers */
value|\   GPR_FIRST  +  0, GPR_FIRST  +  1, GPR_FIRST  +  2, GPR_FIRST 	+  3,	\   GPR_FIRST  + 28, GPR_FIRST  + 29, GPR_FIRST  + 30, GPR_FIRST 	+ 31,	\   ACC_FIRST  +  0, ACC_FIRST  +  1, ACC_FIRST  +  2, ACC_FIRST 	+  3,	\   ACC_FIRST  +  4, ACC_FIRST  +  5, ACC_FIRST  +  6, ACC_FIRST 	+  7,	\   ACCG_FIRST +  0, ACCG_FIRST +  1, ACCG_FIRST +  2, ACCG_FIRST	+  3,	\   ACCG_FIRST +  4, ACCG_FIRST +  5, ACCG_FIRST +  6, ACCG_FIRST	+  7,	\   AP_FIRST, 	   LR_REGNO,       LCR_REGNO				\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* How Values Fit in Registers.  */
end_comment

begin_comment
comment|/* A C expression for the number of consecutive hard registers, starting at    register number REGNO, required to hold a value of mode MODE.     On a machine where all registers are exactly one word, a suitable definition    of this macro is          #define HARD_REGNO_NREGS(REGNO, MODE)            \            ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1)  \             / UNITS_PER_WORD))  */
end_comment

begin_comment
comment|/* On the FRV, make the CC modes take 3 words in the integer registers, so that    we can build the appropriate instructions to properly reload the values.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_NREGS
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
value|frv_hard_regno_nregs (REGNO, MODE)
end_define

begin_comment
comment|/* A C expression that is nonzero if it is permissible to store a value of mode    MODE in hard register number REGNO (or in several registers starting with    that one).  For a machine where all registers are equivalent, a suitable    definition is          #define HARD_REGNO_MODE_OK(REGNO, MODE) 1     It is not necessary for this macro to check for the numbers of fixed    registers, because the allocation mechanism considers them to be always    occupied.     On some machines, double-precision values must be kept in even/odd register    pairs.  The way to implement that is to define this macro to reject odd    register numbers for such modes.     The minimum requirement for a mode to be OK in a register is that the    `movMODE' instruction pattern support moves between the register and any    other hard register for which the mode is OK; and that moving a value into    the register and back out not alter it.     Since the same instruction used to move `SImode' will work for all narrower    integer modes, it is not necessary on any machine for `HARD_REGNO_MODE_OK'    to distinguish between these modes, provided you define patterns `movhi',    etc., to take advantage of this.  This is useful because of the interaction    between `HARD_REGNO_MODE_OK' and `MODES_TIEABLE_P'; it is very desirable for    all integer modes to be tieable.     Many machines have special registers for floating point arithmetic.  Often    people assume that floating point machine modes are allowed only in floating    point registers.  This is not true.  Any registers that can hold integers    can safely *hold* a floating point machine mode, whether or not floating    arithmetic can be done on it in those registers.  Integer move instructions    can be used to move the values.     On some machines, though, the converse is true: fixed-point machine modes    may not go in floating registers.  This is true if the floating registers    normalize any value stored in them, because storing a non-floating value    there would garble it.  In this case, `HARD_REGNO_MODE_OK' should reject    fixed-point machine modes in floating registers.  But if the floating    registers do not automatically normalize, if you can store any bit pattern    in one and retrieve it unchanged without a trap, then any machine mode may    go in a floating register, so you can define this macro to say so.     The primary significance of special floating registers is rather that they    are the registers acceptable in floating point arithmetic instructions.    However, this is of no concern to `HARD_REGNO_MODE_OK'.  You handle it by    writing the proper constraints for those instructions.     On some machines, the floating registers are especially slow to access, so    that it is better to store a value in a stack frame than in such a register    if floating point arithmetic is not being done.  As long as the floating    registers are not in class `GENERAL_REGS', they will not be used unless some    pattern's constraint asks for one.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_MODE_OK
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
value|frv_hard_regno_mode_ok (REGNO, MODE)
end_define

begin_comment
comment|/* A C expression that is nonzero if it is desirable to choose register    allocation so as to avoid move instructions between a value of mode MODE1    and a value of mode MODE2.     If `HARD_REGNO_MODE_OK (R, MODE1)' and `HARD_REGNO_MODE_OK (R, MODE2)' are    ever different for any R, then `MODES_TIEABLE_P (MODE1, MODE2)' must be    zero.  */
end_comment

begin_define
define|#
directive|define
name|MODES_TIEABLE_P
parameter_list|(
name|MODE1
parameter_list|,
name|MODE2
parameter_list|)
value|(MODE1 == MODE2)
end_define

begin_comment
comment|/* Define this macro if the compiler should avoid copies to/from CCmode    registers.  You should only define this macro if support fo copying to/from    CCmode is incomplete.  */
end_comment

begin_define
define|#
directive|define
name|AVOID_CCMODE_COPIES
end_define

begin_escape
end_escape

begin_comment
comment|/* Register Classes.  */
end_comment

begin_comment
comment|/* An enumeral type that must be defined with all the register class names as    enumeral values.  `NO_REGS' must be first.  `ALL_REGS' must be the last    register class, followed by one more enumeral value, `LIM_REG_CLASSES',    which is not a register class but rather tells how many classes there are.     Each register class has a number, which is the value of casting the class    name to type `int'.  The number serves as an index in many of the tables    described below.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|ICC_REGS
block|,
name|FCC_REGS
block|,
name|CC_REGS
block|,
name|ICR_REGS
block|,
name|FCR_REGS
block|,
name|CR_REGS
block|,
name|LCR_REG
block|,
name|LR_REG
block|,
name|SPR_REGS
block|,
name|QUAD_ACC_REGS
block|,
name|EVEN_ACC_REGS
block|,
name|ACC_REGS
block|,
name|ACCG_REGS
block|,
name|QUAD_FPR_REGS
block|,
name|FEVEN_REGS
block|,
name|FPR_REGS
block|,
name|QUAD_REGS
block|,
name|EVEN_REGS
block|,
name|GPR_REGS
block|,
name|ALL_REGS
block|,
name|LIM_REG_CLASSES
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|GENERAL_REGS
value|GPR_REGS
end_define

begin_comment
comment|/* The number of distinct register classes, defined as follows:          #define N_REG_CLASSES (int) LIM_REG_CLASSES  */
end_comment

begin_define
define|#
directive|define
name|N_REG_CLASSES
value|((int) LIM_REG_CLASSES)
end_define

begin_comment
comment|/* An initializer containing the names of the register classes as C string    constants.  These names are used in writing some of the debugging dumps.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
value|{						\    "NO_REGS",								\    "ICC_REGS",								\    "FCC_REGS",								\    "CC_REGS",								\    "ICR_REGS",								\    "FCR_REGS",								\    "CR_REGS",								\    "LCR_REG",								\    "LR_REG",								\    "SPR_REGS",								\    "QUAD_ACC_REGS",							\    "EVEN_ACC_REGS",							\    "ACC_REGS",								\    "ACCG_REGS",								\    "QUAD_FPR_REGS",							\    "FEVEN_REGS",							\    "FPR_REGS",								\    "QUAD_REGS",								\    "EVEN_REGS",								\    "GPR_REGS",								\    "ALL_REGS"								\ }
end_define

begin_comment
comment|/* An initializer containing the contents of the register classes, as integers    which are bit masks.  The Nth integer specifies the contents of class N.    The way the integer MASK is interpreted is that register R is in the class    if `MASK& (1<< R)' is 1.     When the machine has more than 32 registers, an integer does not suffice.    Then the integers are replaced by sub-initializers, braced groupings    containing several integers.  Each sub-initializer must be suitable as an    initializer for the type `HARD_REG_SET' which is defined in    `hard-reg-set.h'.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{
comment|/* gr0-gr31 gr32-gr63  fr0-fr31   fr32-fr-63 cc/ccr/acc ap/spr */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0},
comment|/* NO_REGS  */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x000000f0,0x0},
comment|/* ICC_REGS */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x0000000f,0x0},
comment|/* FCC_REGS */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x000000ff,0x0},
comment|/* CC_REGS  */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x0000f000,0x0},
comment|/* ICR_REGS */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x00000f00,0x0},
comment|/* FCR_REGS */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x0000ff00,0x0},
comment|/* CR_REGS  */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x4},
comment|/* LCR_REGS */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x2},
comment|/* LR_REGS  */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x6},
comment|/* SPR_REGS */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x00ff0000,0x0},
comment|/* QUAD_ACC */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x00ff0000,0x0},
comment|/* EVEN_ACC */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0x00ff0000,0x0},
comment|/* ACC_REGS */
value|\   { 0x00000000,0x00000000,0x00000000,0x00000000,0xff000000,0x0},
comment|/* ACCG_REGS*/
value|\   { 0x00000000,0x00000000,0xffffffff,0xffffffff,0x00000000,0x0},
comment|/* QUAD_FPR */
value|\   { 0x00000000,0x00000000,0xffffffff,0xffffffff,0x00000000,0x0},
comment|/* FEVEN_REG*/
value|\   { 0x00000000,0x00000000,0xffffffff,0xffffffff,0x00000000,0x0},
comment|/* FPR_REGS */
value|\   { 0x0ffffffc,0xffffffff,0x00000000,0x00000000,0x00000000,0x0},
comment|/* QUAD_REGS*/
value|\   { 0xfffffffc,0xffffffff,0x00000000,0x00000000,0x00000000,0x0},
comment|/* EVEN_REGS*/
value|\   { 0xffffffff,0xffffffff,0x00000000,0x00000000,0x00000000,0x1},
comment|/* GPR_REGS */
value|\   { 0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x7},
comment|/* ALL_REGS */
value|\ }
end_define

begin_comment
comment|/* A C expression whose value is a register class containing hard register    REGNO.  In general there is more than one such class; choose a class which    is "minimal", meaning that no smaller class also contains the register.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|regno_reg_class
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
value|regno_reg_class [REGNO]
end_define

begin_comment
comment|/* A macro whose definition is the name of the class to which a valid base    register must belong.  A base register is one used in an address which is    the register value plus a displacement.  */
end_comment

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|GPR_REGS
end_define

begin_comment
comment|/* A macro whose definition is the name of the class to which a valid index    register must belong.  An index register is one used in an address where its    value is either multiplied by a scale factor or added to another register    (as well as added to a displacement).  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|GPR_REGS
end_define

begin_comment
comment|/* A C expression which defines the machine-dependent operand constraint    letters for register classes.  If CHAR is such a letter, the value should be    the register class corresponding to it.  Otherwise, the value should be    `NO_REGS'.  The register letter `r', corresponding to class `GENERAL_REGS',    will not be passed to this macro; you do not need to handle it.     The following letters are unavailable, due to being used as    constraints: 	'0'..'9' 	'<', '>' 	'E', 'F', 'G', 'H' 	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' 	'Q', 'R', 'S', 'T', 'U' 	'V', 'X' 	'g', 'i', 'm', 'n', 'o', 'p', 'r', 's' */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|reg_class_from_letter
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|CHAR
parameter_list|)
value|reg_class_from_letter [(unsigned char)(CHAR)]
end_define

begin_comment
comment|/* A C expression which is nonzero if register number NUM is suitable for use    as a base register in operand addresses.  It may be either a suitable hard    register or a pseudo register that has been allocated such a hard register.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|NUM
parameter_list|)
define|\
value|((NUM)< FIRST_PSEUDO_REGISTER           \    ? GPR_P (NUM)                           \    : (reg_renumber [NUM]>= 0&& GPR_P (reg_renumber [NUM])))
end_define

begin_comment
comment|/* A C expression which is nonzero if register number NUM is suitable for use    as an index register in operand addresses.  It may be either a suitable hard    register or a pseudo register that has been allocated such a hard register.     The difference between an index register and a base register is that the    index register may be scaled.  If an address involves the sum of two    registers, neither one of them scaled, then either one may be labeled the    "base" and the other the "index"; but whichever labeling is used must fit    the machine's constraints of which registers may serve in each capacity.    The compiler will try both labelings, looking for one that is valid, and    will reload one or both registers only if neither labeling works.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|NUM
parameter_list|)
define|\
value|((NUM)< FIRST_PSEUDO_REGISTER                                        \    ? GPR_P (NUM)                                                        \    : (reg_renumber [NUM]>= 0&& GPR_P (reg_renumber [NUM])))
end_define

begin_comment
comment|/* A C expression that places additional restrictions on the register class to    use when it is necessary to copy value X into a register in class CLASS.    The value is a register class; perhaps CLASS, or perhaps another, smaller    class.  On many machines, the following definition is safe:          #define PREFERRED_RELOAD_CLASS(X,CLASS) CLASS     Sometimes returning a more restrictive class makes better code.  For    example, on the 68000, when X is an integer constant that is in range for a    `moveq' instruction, the value of this macro is always `DATA_REGS' as long    as CLASS includes the data registers.  Requiring a data register guarantees    that a `moveq' will be used.     If X is a `const_double', by returning `NO_REGS' you can force X into a    memory constant.  This is useful on certain machines where immediate    floating values cannot be loaded into certain kinds of registers.     This declaration must be present.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_RELOAD_CLASS
parameter_list|(
name|X
parameter_list|,
name|CLASS
parameter_list|)
value|CLASS
end_define

begin_define
define|#
directive|define
name|SECONDARY_INPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|X
parameter_list|)
define|\
value|frv_secondary_reload_class (CLASS, MODE, X, TRUE)
end_define

begin_define
define|#
directive|define
name|SECONDARY_OUTPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|X
parameter_list|)
define|\
value|frv_secondary_reload_class (CLASS, MODE, X, FALSE)
end_define

begin_comment
comment|/* A C expression whose value is nonzero if pseudos that have been assigned to    registers of class CLASS would likely be spilled because registers of CLASS    are needed for spill registers.     The default value of this macro returns 1 if CLASS has exactly one register    and zero otherwise.  On most machines, this default should be used.  Only    define this macro to some other expression if pseudo allocated by    `local-alloc.c' end up in memory because their hard registers were needed    for spill registers.  If this macro returns nonzero for those classes, those    pseudos will only be allocated by `global.c', which knows how to reallocate    the pseudo to another register.  If there would not be another register    available for reallocation, you should not change the definition of this    macro since the only effect of such a definition would be to slow down    register allocation.  */
end_comment

begin_define
define|#
directive|define
name|CLASS_LIKELY_SPILLED_P
parameter_list|(
name|CLASS
parameter_list|)
value|frv_class_likely_spilled_p (CLASS)
end_define

begin_comment
comment|/* A C expression for the maximum number of consecutive registers of    class CLASS needed to hold a value of mode MODE.     This is closely related to the macro `HARD_REGNO_NREGS'.  In fact, the value    of the macro `CLASS_MAX_NREGS (CLASS, MODE)' should be the maximum value of    `HARD_REGNO_NREGS (REGNO, MODE)' for all REGNO values in the class CLASS.     This macro helps control the handling of multiple-word values in    the reload pass.     This declaration is required.  */
end_comment

begin_define
define|#
directive|define
name|CLASS_MAX_NREGS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|)
value|frv_class_max_nregs (CLASS, MODE)
end_define

begin_define
define|#
directive|define
name|ZERO_P
parameter_list|(
name|x
parameter_list|)
value|(x == CONST0_RTX (GET_MODE (x)))
end_define

begin_comment
comment|/* 6 bit signed immediate.  */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_I
parameter_list|(
name|VALUE
parameter_list|)
value|IN_RANGE_P(VALUE, -32, 31)
end_define

begin_comment
comment|/* 10 bit signed immediate.  */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_J
parameter_list|(
name|VALUE
parameter_list|)
value|IN_RANGE_P(VALUE, -512, 511)
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_K
parameter_list|(
name|VALUE
parameter_list|)
value|0
end_define

begin_comment
comment|/* 16 bit signed immediate.  */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_L
parameter_list|(
name|VALUE
parameter_list|)
value|IN_RANGE_P(VALUE, -32768, 32767)
end_define

begin_comment
comment|/* 16 bit unsigned immediate.  */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_M
parameter_list|(
name|VALUE
parameter_list|)
value|IN_RANGE_P (VALUE, 0, 65535)
end_define

begin_comment
comment|/* 12 bit signed immediate that is negative.  */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_N
parameter_list|(
name|VALUE
parameter_list|)
value|IN_RANGE_P(VALUE, -2048, -1)
end_define

begin_comment
comment|/* Zero */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_O
parameter_list|(
name|VALUE
parameter_list|)
value|((VALUE) == 0)
end_define

begin_comment
comment|/* 12 bit signed immediate that is negative.  */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_P
parameter_list|(
name|VALUE
parameter_list|)
value|IN_RANGE_P(VALUE, 1, 2047)
end_define

begin_comment
comment|/* A C expression that defines the machine-dependent operand constraint letters    (`I', `J', `K', .. 'P') that specify particular ranges of integer values.    If C is one of those letters, the expression should check that VALUE, an    integer, is in the appropriate range and return 1 if so, 0 otherwise.  If C    is not one of those letters, the value should be 0 regardless of VALUE.  */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|(  (C) == 'I' ? CONST_OK_FOR_I (VALUE)        \    : (C) == 'J' ? CONST_OK_FOR_J (VALUE)        \    : (C) == 'K' ? CONST_OK_FOR_K (VALUE)        \    : (C) == 'L' ? CONST_OK_FOR_L (VALUE)        \    : (C) == 'M' ? CONST_OK_FOR_M (VALUE)        \    : (C) == 'N' ? CONST_OK_FOR_N (VALUE)        \    : (C) == 'O' ? CONST_OK_FOR_O (VALUE)        \    : (C) == 'P' ? CONST_OK_FOR_P (VALUE)        \    : 0)
end_define

begin_comment
comment|/* A C expression that defines the machine-dependent operand constraint letters    (`G', `H') that specify particular ranges of `const_double' values.     If C is one of those letters, the expression should check that VALUE, an RTX    of code `const_double', is in the appropriate range and return 1 if so, 0    otherwise.  If C is not one of those letters, the value should be 0    regardless of VALUE.     `const_double' is used for all floating-point constants and for `DImode'    fixed-point constants.  A given letter can accept either or both kinds of    values.  It can use `GET_MODE' to distinguish between these kinds.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_G
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|((GET_MODE (VALUE) == VOIDmode 					\&& CONST_DOUBLE_LOW (VALUE) == 0					\&& CONST_DOUBLE_HIGH (VALUE) == 0)					\    || ((GET_MODE (VALUE) == SFmode					\         || GET_MODE (VALUE) == DFmode)					\&& (VALUE) == CONST0_RTX (GET_MODE (VALUE))))
end_define

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_H
parameter_list|(
name|VALUE
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|(  (C) == 'G' ? CONST_DOUBLE_OK_FOR_G (VALUE)				\    : (C) == 'H' ? CONST_DOUBLE_OK_FOR_H (VALUE)				\    : 0)
end_define

begin_comment
comment|/* A C expression that defines the optional machine-dependent constraint    letters (`Q', `R', `S', `T', `U') that can be used to segregate specific    types of operands, usually memory references, for the target machine.    Normally this macro will not be defined.  If it is required for a particular    target machine, it should return 1 if VALUE corresponds to the operand type    represented by the constraint letter C.  If C is not defined as an extra    constraint, the value returned should be 0 regardless of VALUE.     For example, on the ROMP, load instructions cannot have their output in r0    if the memory reference contains a symbolic address.  Constraint letter `Q'    is defined as representing a memory address that does *not* contain a    symbolic address.  An alternative is specified with a `Q' constraint on the    input and `r' on the output.  The next alternative specifies `m' on the    input and a register class that does not include r0 on the output.  */
end_comment

begin_comment
comment|/* Small data references */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT_FOR_Q
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|(small_data_symbolic_operand (VALUE, GET_MODE (VALUE)))
end_define

begin_comment
comment|/* Double word memory ops that take one instruction.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT_FOR_R
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|(dbl_memory_one_insn_operand (VALUE, GET_MODE (VALUE)))
end_define

begin_comment
comment|/* SYMBOL_REF */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT_FOR_S
parameter_list|(
name|VALUE
parameter_list|)
value|(GET_CODE (VALUE) == SYMBOL_REF)
end_define

begin_comment
comment|/* Double word memory ops that take two instructions.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT_FOR_T
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|(dbl_memory_two_insn_operand (VALUE, GET_MODE (VALUE)))
end_define

begin_comment
comment|/* Memory operand for conditional execution.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT_FOR_U
parameter_list|(
name|VALUE
parameter_list|)
define|\
value|(condexec_memory_operand (VALUE, GET_MODE (VALUE)))
end_define

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|(  (C) == 'Q'   ? EXTRA_CONSTRAINT_FOR_Q (VALUE)			\    : (C) == 'R' ? EXTRA_CONSTRAINT_FOR_R (VALUE)			\    : (C) == 'S' ? EXTRA_CONSTRAINT_FOR_S (VALUE)			\    : (C) == 'T' ? EXTRA_CONSTRAINT_FOR_T (VALUE)			\    : (C) == 'U' ? EXTRA_CONSTRAINT_FOR_U (VALUE)			\    : 0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Basic Stack Layout.  */
end_comment

begin_comment
comment|/* Structure to describe information about a saved range of registers */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|frv_stack_regs
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of the register ranges */
name|int
name|first
decl_stmt|;
comment|/* first register in the range */
name|int
name|last
decl_stmt|;
comment|/* last register in the range */
name|int
name|size_1word
decl_stmt|;
comment|/* # of bytes to be stored via 1 word stores */
name|int
name|size_2words
decl_stmt|;
comment|/* # of bytes to be stored via 2 word stores */
name|unsigned
name|char
name|field_p
decl_stmt|;
comment|/* true if the registers are a single SPR */
name|unsigned
name|char
name|dword_p
decl_stmt|;
comment|/* true if we can do dword stores */
name|unsigned
name|char
name|special_p
decl_stmt|;
comment|/* true if the regs have a fixed save loc.  */
block|}
name|frv_stack_regs_t
typedef|;
end_typedef

begin_comment
comment|/* Register ranges to look into saving.  */
end_comment

begin_define
define|#
directive|define
name|STACK_REGS_GPR
value|0
end_define

begin_comment
comment|/* Gprs (normally gr16..gr31, gr48..gr63) */
end_comment

begin_define
define|#
directive|define
name|STACK_REGS_FPR
value|1
end_define

begin_comment
comment|/* Fprs (normally fr16..fr31, fr48..fr63) */
end_comment

begin_define
define|#
directive|define
name|STACK_REGS_LR
value|2
end_define

begin_comment
comment|/* LR register */
end_comment

begin_define
define|#
directive|define
name|STACK_REGS_CC
value|3
end_define

begin_comment
comment|/* CCrs (normally not saved) */
end_comment

begin_define
define|#
directive|define
name|STACK_REGS_LCR
value|5
end_define

begin_comment
comment|/* lcr register */
end_comment

begin_define
define|#
directive|define
name|STACK_REGS_STDARG
value|6
end_define

begin_comment
comment|/* stdarg registers */
end_comment

begin_define
define|#
directive|define
name|STACK_REGS_STRUCT
value|7
end_define

begin_comment
comment|/* structure return (gr3) */
end_comment

begin_define
define|#
directive|define
name|STACK_REGS_FP
value|8
end_define

begin_comment
comment|/* FP register */
end_comment

begin_define
define|#
directive|define
name|STACK_REGS_MAX
value|9
end_define

begin_comment
comment|/* # of register ranges */
end_comment

begin_comment
comment|/* Values for save_p field.  */
end_comment

begin_define
define|#
directive|define
name|REG_SAVE_NO_SAVE
value|0
end_define

begin_comment
comment|/* register not saved */
end_comment

begin_define
define|#
directive|define
name|REG_SAVE_1WORD
value|1
end_define

begin_comment
comment|/* save the register */
end_comment

begin_define
define|#
directive|define
name|REG_SAVE_2WORDS
value|2
end_define

begin_comment
comment|/* save register and register+1 */
end_comment

begin_comment
comment|/* Structure used to define the frv stack.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|frv_stack
block|{
name|int
name|total_size
decl_stmt|;
comment|/* total bytes allocated for stack */
name|int
name|vars_size
decl_stmt|;
comment|/* variable save area size */
name|int
name|parameter_size
decl_stmt|;
comment|/* outgoing parameter size */
name|int
name|stdarg_size
decl_stmt|;
comment|/* size of regs needed to be saved for stdarg */
name|int
name|regs_size
decl_stmt|;
comment|/* size of the saved registers */
name|int
name|regs_size_1word
decl_stmt|;
comment|/* # of bytes to be stored via 1 word stores */
name|int
name|regs_size_2words
decl_stmt|;
comment|/* # of bytes to be stored via 2 word stores */
name|int
name|header_size
decl_stmt|;
comment|/* size of the old FP, struct ret., LR save */
name|int
name|pretend_size
decl_stmt|;
comment|/* size of pretend args */
name|int
name|vars_offset
decl_stmt|;
comment|/* offset to save local variables from new SP*/
name|int
name|regs_offset
decl_stmt|;
comment|/* offset to save registers from new SP */
comment|/* register range information */
name|frv_stack_regs_t
name|regs
index|[
name|STACK_REGS_MAX
index|]
decl_stmt|;
comment|/* offset to store each register */
name|int
name|reg_offset
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
comment|/* whether to save register (& reg+1) */
name|unsigned
name|char
name|save_p
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
block|}
name|frv_stack_t
typedef|;
end_typedef

begin_comment
comment|/* Define this macro if pushing a word onto the stack moves the stack pointer    to a smaller address.  */
end_comment

begin_define
define|#
directive|define
name|STACK_GROWS_DOWNWARD
value|1
end_define

begin_comment
comment|/* Define this macro if the addresses of local variable slots are at negative    offsets from the frame pointer.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Offset from the frame pointer to the first local variable slot to be    allocated.     If `FRAME_GROWS_DOWNWARD', find the next slot's offset by subtracting the    first slot's length from `STARTING_FRAME_OFFSET'.  Otherwise, it is found by    adding the length of the first slot to the value `STARTING_FRAME_OFFSET'.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|0
end_define

begin_comment
comment|/* Offset from the stack pointer register to the first location at which    outgoing arguments are placed.  If not specified, the default value of zero    is used.  This is the proper value for most machines.     If `ARGS_GROW_DOWNWARD', this is the offset to the location above the first    location at which outgoing arguments are placed.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|0
end_define

begin_comment
comment|/* Offset from the argument pointer register to the first argument's address.    On some machines it may depend on the data type of the function.     If `ARGS_GROW_DOWNWARD', this is the offset to the location above the first    argument's address.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FUNDECL
parameter_list|)
value|0
end_define

begin_comment
comment|/* A C expression whose value is RTL representing the address in a stack frame    where the pointer to the caller's frame is stored.  Assume that FRAMEADDR is    an RTL expression for the address of the stack frame itself.     If you don't define this macro, the default is to return the value of    FRAMEADDR--that is, the stack frame address is also the address of the stack    word that points to the previous frame.  */
end_comment

begin_define
define|#
directive|define
name|DYNAMIC_CHAIN_ADDRESS
parameter_list|(
name|FRAMEADDR
parameter_list|)
value|frv_dynamic_chain_address (FRAMEADDR)
end_define

begin_comment
comment|/* A C expression whose value is RTL representing the value of the return    address for the frame COUNT steps up from the current frame, after the    prologue.  FRAMEADDR is the frame pointer of the COUNT frame, or the frame    pointer of the COUNT - 1 frame if `RETURN_ADDR_IN_PREVIOUS_FRAME' is    defined.     The value of the expression must always be the correct address when COUNT is    zero, but may be `NULL_RTX' if there is not way to determine the return    address of other frames.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDR_RTX
parameter_list|(
name|COUNT
parameter_list|,
name|FRAMEADDR
parameter_list|)
value|frv_return_addr_rtx (COUNT, FRAMEADDR)
end_define

begin_comment
comment|/* This function contains machine specific function data.  */
end_comment

begin_decl_stmt
name|struct
name|machine_function
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* True if we have created an rtx that relies on the stack frame.  */
name|int
name|frame_needed
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|RETURN_POINTER_REGNUM
value|LR_REGNO
end_define

begin_comment
comment|/* A C expression whose value is RTL representing the location of the incoming    return address at the beginning of any function, before the prologue.  This    RTL is either a `REG', indicating that the return value is saved in `REG',    or a `MEM' representing a location in the stack.     You only need to define this macro if you want to support call frame    debugging information like that provided by DWARF 2.  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_RETURN_ADDR_RTX
value|gen_rtx_REG (SImode, RETURN_POINTER_REGNUM)
end_define

begin_escape
end_escape

begin_comment
comment|/* Register That Address the Stack Frame.  */
end_comment

begin_comment
comment|/* The register number of the stack pointer register, which must also be a    fixed register according to `FIXED_REGISTERS'.  On most machines, the    hardware determines which register this is.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|(GPR_FIRST + 1)
end_define

begin_comment
comment|/* The register number of the frame pointer register, which is used to access    automatic variables in the stack frame.  On some machines, the hardware    determines which register this is.  On other machines, you can choose any    register you wish for this purpose.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|(GPR_FIRST + 2)
end_define

begin_comment
comment|/* The register number of the arg pointer register, which is used to access the    function's argument list.  On some machines, this is the same as the frame    pointer register.  On some machines, the hardware determines which register    this is.  On other machines, you can choose any register you wish for this    purpose.  If this is not the same register as the frame pointer register,    then you must mark it as a fixed register according to `FIXED_REGISTERS', or    arrange to be able to eliminate it.  */
end_comment

begin_comment
comment|/* On frv this is a fake register that is eliminated in    terms of either the frame pointer or stack pointer.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|AP_FIRST
end_define

begin_comment
comment|/* Register numbers used for passing a function's static chain pointer.  If    register windows are used, the register number as seen by the called    function is `STATIC_CHAIN_INCOMING_REGNUM', while the register number as    seen by the calling function is `STATIC_CHAIN_REGNUM'.  If these registers    are the same, `STATIC_CHAIN_INCOMING_REGNUM' need not be defined.     The static chain register need not be a fixed register.     If the static chain is passed in memory, these macros should not be defined;    instead, the next two macros should be defined.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|(GPR_FIRST + 7)
end_define

begin_define
define|#
directive|define
name|STATIC_CHAIN_INCOMING_REGNUM
value|(GPR_FIRST + 7)
end_define

begin_escape
end_escape

begin_comment
comment|/* Eliminating the Frame Pointer and the Arg Pointer.  */
end_comment

begin_comment
comment|/* A C expression which is nonzero if a function must have and use a frame    pointer.  This expression is evaluated in the reload pass.  If its value is    nonzero the function will have a frame pointer.     The expression can in principle examine the current function and decide    according to the facts, but on most machines the constant 0 or the constant    1 suffices.  Use 0 when the machine allows code to be generated with no    frame pointer, and doing so saves some time or space.  Use 1 when there is    no possible advantage to avoiding a frame pointer.     In certain cases, the compiler does not know how to produce valid code    without a frame pointer.  The compiler recognizes those cases and    automatically gives the function a frame pointer regardless of what    `FRAME_POINTER_REQUIRED' says.  You don't need to worry about them.     In a function that does not require a frame pointer, the frame pointer    register can be allocated for ordinary usage, unless you mark it as a fixed    register.  See `FIXED_REGISTERS' for more information.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|frv_frame_pointer_required ()
end_define

begin_comment
comment|/* If defined, this macro specifies a table of register pairs used to eliminate    unneeded registers that point into the stack frame.  If it is not defined,    the only elimination attempted by the compiler is to replace references to    the frame pointer with references to the stack pointer.     The definition of this macro is a list of structure initializations, each of    which specifies an original and replacement register.     On some machines, the position of the argument pointer is not known until    the compilation is completed.  In such a case, a separate hard register must    be used for the argument pointer.  This register can be eliminated by    replacing it with either the frame pointer or the argument pointer,    depending on whether or not the frame pointer has been eliminated.     In this case, you might specify:         #define ELIMINABLE_REGS  \         {{ARG_POINTER_REGNUM, STACK_POINTER_REGNUM}, \          {ARG_POINTER_REGNUM, FRAME_POINTER_REGNUM}, \          {FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM}}     Note that the elimination of the argument pointer with the stack pointer is    specified first since that is the preferred elimination.  */
end_comment

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{									\   {ARG_POINTER_REGNUM,	 STACK_POINTER_REGNUM},				\   {ARG_POINTER_REGNUM,	 FRAME_POINTER_REGNUM},				\   {FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM}				\ }
end_define

begin_comment
comment|/* A C expression that returns nonzero if the compiler is allowed to try to    replace register number FROM with register number TO.  This macro need only    be defined if `ELIMINABLE_REGS' is defined, and will usually be the constant    1, since most of the cases preventing register elimination are things that    the compiler already knows about.  */
end_comment

begin_define
define|#
directive|define
name|CAN_ELIMINATE
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|((FROM) == ARG_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM		\    ? ! frame_pointer_needed						\    : 1)
end_define

begin_comment
comment|/* This macro is similar to `INITIAL_FRAME_POINTER_OFFSET'.  It specifies the    initial difference between the specified pair of registers.  This macro must    be defined if `ELIMINABLE_REGS' is defined.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_ELIMINATION_OFFSET
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(OFFSET) = frv_initial_elimination_offset (FROM, TO)
end_define

begin_escape
end_escape

begin_comment
comment|/* Passing Function Arguments on the Stack.  */
end_comment

begin_comment
comment|/* If defined, the maximum amount of space required for outgoing arguments will    be computed and placed into the variable    `current_function_outgoing_args_size'.  No space will be pushed onto the    stack for each call; instead, the function prologue should increase the    stack frame size by this amount.     Defining both `PUSH_ROUNDING' and `ACCUMULATE_OUTGOING_ARGS' is not    proper.  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
value|1
end_define

begin_comment
comment|/* A C expression that should indicate the number of bytes of its own arguments    that a function pops on returning, or 0 if the function pops no arguments    and the caller must therefore pop them all after the function returns.     FUNDECL is a C variable whose value is a tree node that describes the    function in question.  Normally it is a node of type `FUNCTION_DECL' that    describes the declaration of the function.  From this it is possible to    obtain the DECL_ATTRIBUTES of the function.     FUNTYPE is a C variable whose value is a tree node that describes the    function in question.  Normally it is a node of type `FUNCTION_TYPE' that    describes the data type of the function.  From this it is possible to obtain    the data types of the value and arguments (if known).     When a call to a library function is being considered, FUNTYPE will contain    an identifier node for the library function.  Thus, if you need to    distinguish among various library functions, you can do so by their names.    Note that "library function" in this context means a function used to    perform arithmetic, whose name is known specially in the compiler and was    not mentioned in the C code being compiled.     STACK-SIZE is the number of bytes of arguments passed on the stack.  If a    variable number of bytes is passed, it is zero, and argument popping will    always be the responsibility of the calling function.     On the VAX, all functions always pop their arguments, so the definition of    this macro is STACK-SIZE.  On the 68000, using the standard calling    convention, no functions pop their arguments, so the value of the macro is    always 0 in this case.  But an alternative calling convention is available    in which functions that take a fixed number of arguments pop them but other    functions (such as `printf') pop nothing (the caller pops all).  When this    convention is in use, FUNTYPE is examined to determine whether a function    takes a fixed number of arguments.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNDECL
parameter_list|,
name|FUNTYPE
parameter_list|,
name|STACK_SIZE
parameter_list|)
value|0
end_define

begin_escape
end_escape

begin_comment
comment|/* Function Arguments in Registers.  */
end_comment

begin_comment
comment|/* Nonzero if we do not know how to pass TYPE solely in registers.    We cannot do so in the following cases:     - if the type has variable size    - if the type is marked as addressable (it is required to be constructed      into the stack)    - if the type is a structure or union.  */
end_comment

begin_define
define|#
directive|define
name|MUST_PASS_IN_STACK
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(((MODE) == BLKmode)                                         \     || ((TYPE) != 0                                             \&& (TREE_CODE (TYPE_SIZE (TYPE)) != INTEGER_CST        \              || TREE_CODE (TYPE) == RECORD_TYPE                 \              || TREE_CODE (TYPE) == UNION_TYPE                  \              || TREE_CODE (TYPE) == QUAL_UNION_TYPE             \              || TREE_ADDRESSABLE (TYPE))))
end_define

begin_comment
comment|/* The number of register assigned to holding function arguments.  */
end_comment

begin_define
define|#
directive|define
name|FRV_NUM_ARG_REGS
value|6
end_define

begin_comment
comment|/* A C expression that controls whether a function argument is passed in a    register, and which register.     The arguments are CUM, of type CUMULATIVE_ARGS, which summarizes (in a way    defined by INIT_CUMULATIVE_ARGS and FUNCTION_ARG_ADVANCE) all of the previous    arguments so far passed in registers; MODE, the machine mode of the argument;    TYPE, the data type of the argument as a tree node or 0 if that is not known    (which happens for C support library functions); and NAMED, which is 1 for an    ordinary argument and 0 for nameless arguments that correspond to `...' in the    called function's prototype.     The value of the expression should either be a `reg' RTX for the hard    register in which to pass the argument, or zero to pass the argument on the    stack.     For machines like the VAX and 68000, where normally all arguments are    pushed, zero suffices as a definition.     The usual way to make the ANSI library `stdarg.h' work on a machine where    some arguments are usually passed in registers, is to cause nameless    arguments to be passed on the stack instead.  This is done by making    `FUNCTION_ARG' return 0 whenever NAMED is 0.     You may use the macro `MUST_PASS_IN_STACK (MODE, TYPE)' in the definition of    this macro to determine if this argument is of a type that must be passed in    the stack.  If `REG_PARM_STACK_SPACE' is not defined and `FUNCTION_ARG'    returns nonzero for such an argument, the compiler will abort.  If    `REG_PARM_STACK_SPACE' is defined, the argument will be computed in the    stack and then loaded into a register.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|frv_function_arg (&CUM, MODE, TYPE, NAMED, FALSE)
end_define

begin_comment
comment|/* Define this macro if the target machine has "register windows", so that the    register in which a function sees an arguments is not necessarily the same    as the one in which the caller passed the argument.     For such machines, `FUNCTION_ARG' computes the register in which the caller    passes the value, and `FUNCTION_INCOMING_ARG' should be defined in a similar    fashion to tell the function being called where the arguments will arrive.     If `FUNCTION_INCOMING_ARG' is not defined, `FUNCTION_ARG' serves both    purposes.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_INCOMING_ARG
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|frv_function_arg (&CUM, MODE, TYPE, NAMED, TRUE)
end_define

begin_comment
comment|/* A C expression for the number of words, at the beginning of an argument,    must be put in registers.  The value must be zero for arguments that are    passed entirely in registers or that are entirely pushed on the stack.     On some machines, certain arguments must be passed partially in registers    and partially in memory.  On these machines, typically the first N words of    arguments are passed in registers, and the rest on the stack.  If a    multi-word argument (a `double' or a structure) crosses that boundary, its    first few words must be passed in registers and the rest must be pushed.    This macro tells the compiler when this occurs, and how many of the words    should go in registers.     `FUNCTION_ARG' for these arguments should return the first register to be    used by the caller for this argument; likewise `FUNCTION_INCOMING_ARG', for    the called function.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PARTIAL_NREGS
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|frv_function_arg_partial_nregs (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* extern int frv_function_arg_partial_nregs (CUMULATIVE_ARGS, int, Tree, int);  */
end_comment

begin_comment
comment|/* A C expression that indicates when an argument must be passed by reference.    If nonzero for an argument, a copy of that argument is made in memory and a    pointer to the argument is passed instead of the argument itself.  The    pointer is passed in whatever way is appropriate for passing a pointer to    that type.     On machines where `REG_PARM_STACK_SPACE' is not defined, a suitable    definition of this macro might be         #define FUNCTION_ARG_PASS_BY_REFERENCE(CUM, MODE, TYPE, NAMED)  \           MUST_PASS_IN_STACK (MODE, TYPE)  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PASS_BY_REFERENCE
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|frv_function_arg_pass_by_reference (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* If defined, a C expression that indicates when it is the called function's    responsibility to make a copy of arguments passed by invisible reference.    Normally, the caller makes a copy and passes the address of the copy to the    routine being called.  When FUNCTION_ARG_CALLEE_COPIES is defined and is    nonzero, the caller does not make a copy.  Instead, it passes a pointer to    the "live" value.  The called function must not modify this value.  If it    can be determined that the value won't be modified, it need not make a copy;    otherwise a copy must be made.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_CALLEE_COPIES
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|frv_function_arg_callee_copies (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* If defined, a C expression that indicates when it is more desirable to keep    an argument passed by invisible reference as a reference, rather than    copying it to a pseudo register.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_KEEP_AS_REFERENCE
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|frv_function_arg_keep_as_reference (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* A C type for declaring a variable that is used as the first argument of    `FUNCTION_ARG' and other related values.  For some target machines, the type    `int' suffices and can hold the number of bytes of argument so far.     There is no need to record in `CUMULATIVE_ARGS' anything about the arguments    that have been passed on the stack.  The compiler has other variables to    keep track of that.  For target machines on which all arguments are passed    on the stack, there is no need to store anything in `CUMULATIVE_ARGS';    however, the data structure must exist and should not be empty, so use    `int'.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* A C statement (sans semicolon) for initializing the variable CUM for the    state at the beginning of the argument list.  The variable has type    `CUMULATIVE_ARGS'.  The value of FNTYPE is the tree node for the data type    of the function which will receive the args, or 0 if the args are to a    compiler support library function.  The value of INDIRECT is nonzero when    processing an indirect call, for example a call through a function pointer.    The value of INDIRECT is zero for a call to an explicitly named function, a    library function call, or when `INIT_CUMULATIVE_ARGS' is used to find    arguments for the function being compiled.     When processing a call to a compiler support library function, LIBNAME    identifies which one.  It is a `symbol_ref' rtx which contains the name of    the function, as a string.  LIBNAME is 0 when an ordinary C function call is    being processed.  Thus, each time this macro is called, either LIBNAME or    FNTYPE is nonzero, but never both of them at once.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
parameter_list|,
name|LIBNAME
parameter_list|,
name|FNDECL
parameter_list|,
name|N_NAMED_ARGS
parameter_list|)
define|\
value|frv_init_cumulative_args (&CUM, FNTYPE, LIBNAME, FNDECL, FALSE)
end_define

begin_comment
comment|/* Like `INIT_CUMULATIVE_ARGS' but overrides it for the purposes of finding the    arguments for the function being compiled.  If this macro is undefined,    `INIT_CUMULATIVE_ARGS' is used instead.     The value passed for LIBNAME is always 0, since library routines with    special calling conventions are never compiled with GCC.  The argument    LIBNAME exists for symmetry with `INIT_CUMULATIVE_ARGS'.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_INCOMING_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
parameter_list|,
name|LIBNAME
parameter_list|)
define|\
value|frv_init_cumulative_args (&CUM, FNTYPE, LIBNAME, NULL, TRUE)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to update the summarizer variable CUM to    advance past an argument in the argument list.  The values MODE, TYPE and    NAMED describe that argument.  Once this is done, the variable CUM is    suitable for analyzing the *following* argument with `FUNCTION_ARG', etc.     This macro need not do anything if the argument in question was passed on    the stack.  The compiler knows how to track the amount of stack space used    for arguments without any special help.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_ADVANCE
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|frv_function_arg_advance (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* If defined, a C expression that gives the alignment boundary, in bits, of an    argument with the specified mode and type.  If it is not defined,    `PARM_BOUNDARY' is used for all arguments.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_BOUNDARY
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|frv_function_arg_boundary (MODE, TYPE)
end_define

begin_comment
comment|/* A C expression that is nonzero if REGNO is the number of a hard register in    which function arguments are sometimes passed.  This does *not* include    implicit arguments such as the static chain and the structure-value address.    On many machines, no registers can be used for this purpose since all    function arguments are pushed on the stack.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)>= FIRST_ARG_REGNUM&& ((REGNO)<= LAST_ARG_REGNUM))
end_define

begin_escape
end_escape

begin_comment
comment|/* How Scalar Function Values are Returned.  */
end_comment

begin_comment
comment|/* The number of the hard register that is used to return a scalar value from a    function call.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_VALUE_REGNUM
value|(GPR_FIRST + 8)
end_define

begin_comment
comment|/* A C expression to create an RTX representing the place where a function    returns a value of data type VALTYPE.  VALTYPE is a tree node representing a    data type.  Write `TYPE_MODE (VALTYPE)' to get the machine mode used to    represent that type.  On many machines, only the mode is relevant.    (Actually, on most machines, scalar values are returned in the same place    regardless of mode).     If `PROMOTE_FUNCTION_RETURN' is defined, you must apply the same promotion    rules specified in `PROMOTE_MODE' if VALTYPE is a scalar type.     If the precise function being called is known, FUNC is a tree node    (`FUNCTION_DECL') for it; otherwise, FUNC is a null pointer.  This makes it    possible to use a different value-returning convention for specific    functions when all their calls are known.     `FUNCTION_VALUE' is not used for return vales with aggregate data types,    because these are returned in another way.  See `STRUCT_VALUE_REGNUM' and    related macros, below.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|gen_rtx (REG, TYPE_MODE (VALTYPE), RETURN_VALUE_REGNUM)
end_define

begin_comment
comment|/* A C expression to create an RTX representing the place where a library    function returns a value of mode MODE.     Note that "library function" in this context means a compiler support    routine, used to perform arithmetic, whose name is known specially by the    compiler and was not mentioned in the C code being compiled.     The definition of `LIBRARY_VALUE' need not be concerned aggregate data    types, because none of the library functions returns such types.  */
end_comment

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
value|gen_rtx (REG, MODE, RETURN_VALUE_REGNUM)
end_define

begin_comment
comment|/* A C expression that is nonzero if REGNO is the number of a hard register in    which the values of called function may come back.     A register whose use for returning values is limited to serving as the    second of a pair (for a value of type `double', say) need not be recognized    by this macro.  So for most machines, this definition suffices:          #define FUNCTION_VALUE_REGNO_P(N) ((N) == RETURN)     If the machine has register windows, so that the caller and the called    function use different registers for the return value, this macro should    recognize only the caller's register numbers.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO) == RETURN_VALUE_REGNUM)
end_define

begin_escape
end_escape

begin_comment
comment|/* How Large Values are Returned.  */
end_comment

begin_comment
comment|/* If the structure value address is passed in a register, then    `STRUCT_VALUE_REGNUM' should be the number of that register.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|(GPR_FIRST + 3)
end_define

begin_escape
end_escape

begin_comment
comment|/* Function Entry and Exit.  */
end_comment

begin_comment
comment|/* Define this macro as a C expression that is nonzero if the return    instruction or the function epilogue ignores the value of the stack pointer;    in other words, if it is safe to delete an instruction to adjust the stack    pointer before a return from the function.     Note that this macro's value is relevant only for functions for which frame    pointers are maintained.  It is never safe to delete a final stack    adjustment in a function that has no frame pointer, and the compiler knows    this regardless of `EXIT_IGNORE_STACK'.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Generating Code for Profiling.  */
end_comment

begin_comment
comment|/* A C statement or compound statement to output to FILE some assembler code to    call the profiling subroutine `mcount'.  Before calling, the assembler code    must load the address of a counter variable into a register where `mcount'    expects to find the address.  The name of this variable is `LP' followed by    the number LABELNO, so you would generate the name using `LP%d' in a    `fprintf'.     The details of how the address should be passed to `mcount' are determined    by your operating system environment, not by GCC.  To figure them out,    compile a small program for profiling using the system's installed C    compiler and look at the assembler code that results.     This declaration must be present, but it can be an abort if profiling is    not implemented.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
end_define

begin_escape
end_escape

begin_comment
comment|/* Implementing the Varargs Macros.  */
end_comment

begin_comment
comment|/* If defined, is a C expression that produces the machine-specific code for a    call to `__builtin_saveregs'.  This code will be moved to the very beginning    of the function, before any parameter access are made.  The return value of    this function should be an RTX that contains the value to use as the return    of `__builtin_saveregs'.     If this macro is not defined, the compiler will output an ordinary call to    the library function `__builtin_saveregs'.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_SAVEREGS
parameter_list|()
value|frv_expand_builtin_saveregs ()
end_define

begin_comment
comment|/* This macro offers an alternative to using `__builtin_saveregs' and defining    the macro `EXPAND_BUILTIN_SAVEREGS'.  Use it to store the anonymous register    arguments into the stack so that all the arguments appear to have been    passed consecutively on the stack.  Once this is done, you can use the    standard implementation of varargs that works for machines that pass all    their arguments on the stack.     The argument ARGS_SO_FAR is the `CUMULATIVE_ARGS' data structure, containing    the values that obtain after processing of the named arguments.  The    arguments MODE and TYPE describe the last named argument--its machine mode    and its data type as a tree node.     The macro implementation should do two things: first, push onto the stack    all the argument registers *not* used for the named arguments, and second,    store the size of the data thus pushed into the `int'-valued variable whose    name is supplied as the argument PRETEND_ARGS_SIZE.  The value that you    store here will serve as additional offset for setting up the stack frame.     Because you must generate code to push the anonymous arguments at compile    time without knowing their data types, `SETUP_INCOMING_VARARGS' is only    useful on machines that have just a single category of argument register and    use it uniformly for all data types.     If the argument SECOND_TIME is nonzero, it means that the arguments of the    function are being analyzed for the second time.  This happens for an inline    function, which is not actually compiled until the end of the source file.    The macro `SETUP_INCOMING_VARARGS' should not generate any instructions in    this case.  */
end_comment

begin_define
define|#
directive|define
name|SETUP_INCOMING_VARARGS
parameter_list|(
name|ARGS_SO_FAR
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|PRETEND_ARGS_SIZE
parameter_list|,
name|SECOND_TIME
parameter_list|)
define|\
value|frv_setup_incoming_varargs (& ARGS_SO_FAR, (int) MODE, TYPE, 	\& PRETEND_ARGS_SIZE, SECOND_TIME)
end_define

begin_comment
comment|/* Implement the stdarg/varargs va_start macro.  STDARG_P is nonzero if this    is stdarg.h instead of varargs.h.  VALIST is the tree of the va_list    variable to initialize.  NEXTARG is the machine independent notion of the    'next' argument after the variable arguments.  If not defined, a standard    implementation will be defined that works for arguments passed on the stack.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_START
parameter_list|(
name|VALIST
parameter_list|,
name|NEXTARG
parameter_list|)
define|\
value|(frv_expand_builtin_va_start(VALIST, NEXTARG))
end_define

begin_comment
comment|/* Implement the stdarg/varargs va_arg macro.  VALIST is the variable of type    va_list as a tree, TYPE is the type passed to va_arg.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_ARG
parameter_list|(
name|VALIST
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(frv_expand_builtin_va_arg (VALIST, TYPE))
end_define

begin_escape
end_escape

begin_comment
comment|/* Trampolines for Nested Functions.  */
end_comment

begin_comment
comment|/* A C expression for the size in bytes of the trampoline, as an integer.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|frv_trampoline_size ()
end_define

begin_comment
comment|/* Alignment required for trampolines, in bits.     If you don't define this macro, the value of `BIGGEST_ALIGNMENT' is used for    aligning trampolines.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_ALIGNMENT
value|32
end_define

begin_comment
comment|/* A C statement to initialize the variable parts of a trampoline.  ADDR is an    RTX for the address of the trampoline; FNADDR is an RTX for the address of    the nested function; STATIC_CHAIN is an RTX for the static chain value that    should be passed to the function when it is called.  */
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE
parameter_list|(
name|ADDR
parameter_list|,
name|FNADDR
parameter_list|,
name|STATIC_CHAIN
parameter_list|)
define|\
value|frv_initialize_trampoline (ADDR, FNADDR, STATIC_CHAIN)
end_define

begin_comment
comment|/* Define this macro if trampolines need a special subroutine to do their work.    The macro should expand to a series of `asm' statements which will be    compiled with GCC.  They go in a library function named    `__transfer_from_trampoline'.     If you need to avoid executing the ordinary prologue code of a compiled C    function when you jump to the subroutine, you can do so by placing a special    label of your own in the assembler code.  Use one `asm' statement to    generate an assembler label, and another to make the label global.  Then    trampolines can use that label to jump directly to your special assembler    code.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FRV_UNDERSCORE__
end_ifdef

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE_NAME
value|"___trampoline_template"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE_NAME
value|"__trampoline_template"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRANSFER_FROM_TRAMPOLINE
define|\
value|extern int _write (int, const void *, unsigned);			\ 									\ void									\ __trampoline_setup (short * addr, int size, int fnaddr, int sc)		\ {									\   extern short __trampoline_template[];					\   short * to = addr;							\   short * from =&__trampoline_template[0];				\   int i;								\ 									\   if (size< 20)							\     {									\       _write (2, "__trampoline_setup bad size\n",			\ 	      sizeof ("__trampoline_setup bad size\n") - 1);		\       exit (-1);							\     }									\ 									\   to[0] = from[0];							\   to[1] = (short)(fnaddr);						\   to[2] = from[2];							\   to[3] = (short)(sc);							\   to[4] = from[4];							\   to[5] = (short)(fnaddr>> 16);					\   to[6] = from[6];							\   to[7] = (short)(sc>> 16);						\   to[8] = from[8];							\   to[9] = from[9];							\ 									\   for (i = 0; i< 20; i++)						\     __asm__ volatile ("dcf @(%0,%1)\n\tici @(%0,%1)" :: "r" (to), "r" (i)); \ }									\ 									\ __asm__("\n"								\ 	"\t.globl " TRAMPOLINE_TEMPLATE_NAME "\n"			\ 	"\t.text\n"							\ 	TRAMPOLINE_TEMPLATE_NAME ":\n"					\ 	"\tsetlos #0, gr6\n"
comment|/* jump register */
value|\ 	"\tsetlos #0, gr7\n"
comment|/* static chain */
value|\ 	"\tsethi #0, gr6\n"						\ 	"\tsethi #0, gr7\n"						\ 	"\tjmpl @(gr0,gr6)\n");
end_define

begin_escape
end_escape

begin_comment
comment|/* Addressing Modes.  */
end_comment

begin_comment
comment|/* A C expression that is 1 if the RTX X is a constant which is a valid    address.  On most machines, this can be defined as `CONSTANT_P (X)', but a    few machines are more restrictive in which constant addresses are supported.     `CONSTANT_P' accepts integer-values expressions whose values are not    explicitly known, such as `symbol_ref', `label_ref', and `high' expressions    and `const' arithmetic expressions, in addition to `const_int' and    `const_double' expressions.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
value|CONSTANT_P (X)
end_define

begin_comment
comment|/* A number, the maximum number of registers that can appear in a valid memory    address.  Note that it is up to you to specify a value equal to the maximum    number that `GO_IF_LEGITIMATE_ADDRESS' would ever accept.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|2
end_define

begin_comment
comment|/* A C compound statement with a conditional `goto LABEL;' executed if X (an    RTX) is a legitimate memory address on the target machine for a memory    operand of mode MODE.     It usually pays to define several simpler macros to serve as subroutines for    this one.  Otherwise it may be too complicated to understand.     This macro must exist in two variants: a strict variant and a non-strict    one.  The strict variant is used in the reload pass.  It must be defined so    that any pseudo-register that has not been allocated a hard register is    considered a memory reference.  In contexts where some kind of register is    required, a pseudo-register with no hard register must be rejected.     The non-strict variant is used in other passes.  It must be defined to    accept all pseudo-registers in every context where some kind of register is    required.     Compiler source files that want to use the strict variant of this macro    define the macro `REG_OK_STRICT'.  You should use an `#ifdef REG_OK_STRICT'    conditional to define the strict variant in that case and the non-strict    variant otherwise.     Subroutines to check for acceptable registers for various purposes (one for    base registers, one for index registers, and so on) are typically among the    subroutines used to define `GO_IF_LEGITIMATE_ADDRESS'.  Then only these    subroutine macros need have two variants; the higher levels of macros may be    the same whether strict or not.     Normally, constant addresses which are the sum of a `symbol_ref' and an    integer are stored inside a `const' RTX to mark them as constant.    Therefore, there is no need to recognize such sums specifically as    legitimate addresses.  Normally you would simply recognize any `const' as    legitimate.     Usually `PRINT_OPERAND_ADDRESS' is not prepared to handle constant sums that    are not marked with `const'.  It assumes that a naked `plus' indicates    indexing.  If so, then you *must* reject such naked constant sums as    illegitimate addresses, so that none of them will be given to    `PRINT_OPERAND_ADDRESS'.     On some machines, whether a symbolic address is legitimate depends on the    section that the address refers to.  On these machines, define the macro    `ENCODE_SECTION_INFO' to store the information into the `symbol_ref', and    then check for it here.  When you see a `const', you will have to look    inside it to find the `symbol_ref' in order to determine the section.     The best way to modify the name string is by adding text to the beginning,    with suitable punctuation to prevent any ambiguity.  Allocate the new name    in `saveable_obstack'.  You will have to modify `ASM_OUTPUT_LABELREF' to    remove and decode the added text and output the name accordingly, and define    `(* targetm.strip_name_encoding)' to access the original name string.     You can check the information stored here into the `symbol_ref' in the    definitions of the macros `GO_IF_LEGITIMATE_ADDRESS' and    `PRINT_OPERAND_ADDRESS'.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REG_OK_STRICT
end_ifdef

begin_define
define|#
directive|define
name|REG_OK_STRICT_P
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_OK_STRICT_P
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GO_IF_LEGITIMATE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|LABEL
parameter_list|)
define|\
value|do									\     {									\       if (frv_legitimate_address_p (MODE, X, REG_OK_STRICT_P, FALSE))	\ 	goto LABEL;							\     }									\   while (0)
end_define

begin_comment
comment|/* A C expression that is nonzero if X (assumed to be a `reg' RTX) is valid for    use as a base register.  For hard registers, it should always accept those    which the hardware permits and reject the others.  Whether the macro accepts    or rejects pseudo registers must be controlled by `REG_OK_STRICT' as    described above.  This usually requires two variant definitions, of which    `REG_OK_STRICT' controls the one actually used.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REG_OK_STRICT
end_ifdef

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|GPR_P (REGNO (X))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|GPR_AP_OR_PSEUDO_P (REGNO (X))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A C expression that is nonzero if X (assumed to be a `reg' RTX) is valid for    use as an index register.     The difference between an index register and a base register is that the    index register may be scaled.  If an address involves the sum of two    registers, neither one of them scaled, then either one may be labeled the    "base" and the other the "index"; but whichever labeling is used must fit    the machine's constraints of which registers may serve in each capacity.    The compiler will try both labelings, looking for one that is valid, and    will reload one or both registers only if neither labeling works.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_BASE_P (X)
end_define

begin_comment
comment|/* A C compound statement that attempts to replace X with a valid memory    address for an operand of mode MODE.  WIN will be a C statement label    elsewhere in the code; the macro definition may use          GO_IF_LEGITIMATE_ADDRESS (MODE, X, WIN);     to avoid further processing if the address has become legitimate.     X will always be the result of a call to `break_out_memory_refs', and OLDX    will be the operand that was given to that function to produce X.     The code generated by this macro should not alter the substructure of X.  If    it transforms X into a more legitimate form, it should assign X (which will    always be a C variable) a new value.     It is not necessary for this macro to come up with a legitimate address.    The compiler has standard ways of doing so in all cases.  In fact, it is    safe for this macro to do nothing.  But often a machine-dependent strategy    can generate better code.  */
end_comment

begin_comment
comment|/* On the FRV, we use it to convert small data and pic references into using    the appropriate pointer in the address.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMIZE_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|OLDX
parameter_list|,
name|MODE
parameter_list|,
name|WIN
parameter_list|)
define|\
value|do								\     {								\       rtx newx = frv_legitimize_address (X, OLDX, MODE);	\ 								\       if (newx)							\ 	{							\ 	  (X) = newx;						\ 	  goto WIN;						\ 	}							\     }								\   while (0)
end_define

begin_comment
comment|/* A C statement or compound statement with a conditional `goto LABEL;'    executed if memory address X (an RTX) can have different meanings depending    on the machine mode of the memory reference it is used for or if the address    is valid for some modes but not others.     Autoincrement and autodecrement addresses typically have mode-dependent    effects because the amount of the increment or decrement is the size of the    operand being addressed.  Some machines have other mode-dependent addresses.    Many RISC machines have no mode-dependent addresses.     You may assume that ADDR is a valid address for the machine.  */
end_comment

begin_define
define|#
directive|define
name|GO_IF_MODE_DEPENDENT_ADDRESS
parameter_list|(
name|ADDR
parameter_list|,
name|LABEL
parameter_list|)
end_define

begin_comment
comment|/* A C expression that is nonzero if X is a legitimate constant for an    immediate operand on the target machine.  You can assume that X satisfies    `CONSTANT_P', so you need not check this.  In fact, `1' is a suitable    definition for this macro on machines where anything `CONSTANT_P' is valid.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
value|frv_legitimate_constant_p (X)
end_define

begin_comment
comment|/* The load-and-update commands allow pre-modification in addresses.    The index has to be in a register.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRE_MODIFY_REG
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Returns a mode from class `MODE_CC' to be used when comparison operation    code OP is applied to rtx X and Y.  For example, on the SPARC,    `SELECT_CC_MODE' is defined as (see *note Jump Patterns::.  for a    description of the reason for this definition)          #define SELECT_CC_MODE(OP,X,Y) \           (GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT          \            ? ((OP == EQ || OP == NE) ? CCFPmode : CCFPEmode)    \            : ((GET_CODE (X) == PLUS || GET_CODE (X) == MINUS    \                || GET_CODE (X) == NEG) \               ? CC_NOOVmode : CCmode))     You need not define this macro if `EXTRA_CC_MODES' is not defined.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_CC_MODE
parameter_list|(
name|OP
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|(GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT				\    ? CC_FPmode								\    : (((OP) == LEU || (OP) == GTU || (OP) == LTU || (OP) == GEU)	\       ? CC_UNSmode							\       : CCmode))
end_define

begin_comment
comment|/* A C expression whose value is one if it is always safe to reverse a    comparison whose mode is MODE.  If `SELECT_CC_MODE' can ever return MODE for    a floating-point inequality comparison, then `REVERSIBLE_CC_MODE (MODE)'    must be zero.     You need not define this macro if it would always returns zero or if the    floating-point format is anything other than `IEEE_FLOAT_FORMAT'.  For    example, here is the definition used on the SPARC, where floating-point    inequality comparisons are always given `CCFPEmode':          #define REVERSIBLE_CC_MODE(MODE)  ((MODE) != CCFPEmode)  */
end_comment

begin_comment
comment|/* On frv, don't consider floating point comparisons to be reversible.  In    theory, fp equality comparisons can be reversible.  */
end_comment

begin_define
define|#
directive|define
name|REVERSIBLE_CC_MODE
parameter_list|(
name|MODE
parameter_list|)
value|((MODE) == CCmode || (MODE) == CC_UNSmode)
end_define

begin_comment
comment|/* Frv CCR_MODE's are not reversible.  */
end_comment

begin_define
define|#
directive|define
name|REVERSE_CONDEXEC_PREDICATES_P
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|0
end_define

begin_escape
end_escape

begin_comment
comment|/* Describing Relative Costs of Operations.  */
end_comment

begin_comment
comment|/* A C expression for the cost of moving data from a register in class FROM to    one in class TO.  The classes are expressed using the enumeration values    such as `GENERAL_REGS'.  A value of 4 is the default; other values are    interpreted relative to that.     It is not required that the cost always equal 2 when FROM is the same as TO;    on some machines it is expensive to move between registers if they are not    general registers.     If reload sees an insn consisting of a single `set' between two hard    registers, and if `REGISTER_MOVE_COST' applied to their classes returns a    value of 2, reload does not check to ensure that the constraints of the insn    are met.  Setting a cost of other than 2 will allow reload to verify that    the constraints are met.  You should do this if the `movM' pattern's    constraints do not allow such copying.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
parameter_list|(
name|MODE
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
value|frv_register_move_cost (FROM, TO)
end_define

begin_comment
comment|/* A C expression for the cost of moving data of mode M between a register and    memory.  A value of 2 is the default; this cost is relative to those in    `REGISTER_MOVE_COST'.     If moving between registers and memory is more expensive than between two    registers, you should define this macro to express the relative cost.  */
end_comment

begin_define
define|#
directive|define
name|MEMORY_MOVE_COST
parameter_list|(
name|M
parameter_list|,
name|C
parameter_list|,
name|I
parameter_list|)
value|4
end_define

begin_comment
comment|/* A C expression for the cost of a branch instruction.  A value of 1 is the    default; other values are interpreted relative to that.  */
end_comment

begin_comment
comment|/* Here are additional macros which do not specify precise relative costs, but    only that certain actions are more expensive than GCC would ordinarily    expect.  */
end_comment

begin_comment
comment|/* We used to default the branch cost to 2, but I changed it to 1, to avoid    generating SCC instructions and or/and-ing them together, and then doing the    branch on the result, which collectively generate much worse code.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_BRANCH_COST
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_BRANCH_COST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BRANCH_COST
value|frv_branch_cost_int
end_define

begin_comment
comment|/* Define this macro as a C expression which is nonzero if accessing less than    a word of memory (i.e. a `char' or a `short') is no faster than accessing a    word of memory, i.e., if such access require more than one instruction or if    there is no difference in cost between byte and (aligned) word loads.     When this macro is not defined, the compiler will access a field by finding    the smallest containing object; when it is defined, a fullword load will be    used if alignment permits.  Unless bytes accesses are faster than word    accesses, using word accesses is preferable since it may eliminate    subsequent memory access if subsequent accesses occur to other fields in the    same word of the structure, but to different bytes.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|1
end_define

begin_comment
comment|/* Define this macro if it is as good or better to call a constant function    address than to call an address kept in a register.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
end_define

begin_comment
comment|/* Define this macro if it is as good or better for a function to call itself    with an explicit address than to call an address kept in a register.  */
end_comment

begin_define
define|#
directive|define
name|NO_RECURSIVE_FUNCTION_CSE
end_define

begin_escape
end_escape

begin_comment
comment|/* Dividing the output into sections.  */
end_comment

begin_comment
comment|/* A C expression whose value is a string containing the assembler operation    that should precede instructions and read-only data.  Normally `".text"' is    right.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.text"
end_define

begin_comment
comment|/* A C expression whose value is a string containing the assembler operation to    identify the following data as writable initialized data.  Normally    `".data"' is right.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.data"
end_define

begin_comment
comment|/* If defined, a C expression whose value is a string containing the    assembler operation to identify the following data as    uninitialized global data.  If not defined, and neither    `ASM_OUTPUT_BSS' nor `ASM_OUTPUT_ALIGNED_BSS' are defined,    uninitialized global data will be output in the data section if    `-fno-common' is passed, otherwise `ASM_OUTPUT_COMMON' will be    used.  */
end_comment

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section .bss,\"aw\""
end_define

begin_comment
comment|/* Short Data Support */
end_comment

begin_define
define|#
directive|define
name|SDATA_SECTION_ASM_OP
value|"\t.section .sdata,\"aw\""
end_define

begin_comment
comment|/* On svr4, we *do* have support for the .init and .fini sections, and we    can put stuff in there to be executed before and after `main'.  We let    crtstuff.c and other files know this by defining the following symbols.    The definitions say how to change sections to the .init and .fini    sections.  This is the same for all known svr4 assemblers.     The standard System V.4 macros will work, but they look ugly in the    assembly output, so redefine them.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"\t.section .init,\"ax\""
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
value|"\t.section .fini,\"ax\""
end_define

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"\t.section\t.ctors,\"a\""
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"\t.section\t.dtors,\"a\""
end_define

begin_comment
comment|/* A C expression whose value is a string containing the assembler operation to    switch to the fixup section that records all initialized pointers in a -fpic    program so they can be changed program startup time if the program is loaded    at a different address than linked for.  */
end_comment

begin_define
define|#
directive|define
name|FIXUP_SECTION_ASM_OP
value|"\t.section .rofixup,\"a\""
end_define

begin_comment
comment|/* A list of names for sections other than the standard two, which are    `in_text' and `in_data'.  You need not define this macro    on a system with no other sections (that GCC needs to use).  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_sdata, in_const, in_fixup
end_define

begin_comment
comment|/* One or more functions to be defined in "varasm.c".  These    functions should do jobs analogous to those of `text_section' and    `data_section', for your additional sections.  Do not define this    macro if you do not define `EXTRA_SECTIONS'.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|SDATA_SECTION_FUNCTION						\ 	FIXUP_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|SDATA_SECTION_FUNCTION
define|\
value|void									\ sdata_section (void)							\ {									\   if (in_section != in_sdata)						\     {									\       fprintf (asm_out_file, "%s\n", SDATA_SECTION_ASM_OP);		\       in_section = in_sdata;						\     }									\ }
end_define

begin_define
define|#
directive|define
name|FIXUP_SECTION_FUNCTION
define|\
value|void									\ fixup_section (void)							\ {									\   if (in_section != in_fixup)						\     {									\       fprintf (asm_out_file, "%s\n", FIXUP_SECTION_ASM_OP);		\       in_section = in_fixup;						\     }									\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Position Independent Code.  */
end_comment

begin_comment
comment|/* A C expression that is nonzero if X is a legitimate immediate operand on the    target machine when generating position independent code.  You can assume    that X satisfies `CONSTANT_P', so you need not check this.  You can also    assume FLAG_PIC is true, so you need not check it either.  You need not    define this macro if all constants (including `SYMBOL_REF') can be immediate    operands when generating position independent code.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_PIC_OPERAND_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(   GET_CODE (X) == CONST_INT						\    || GET_CODE (X) == CONST_DOUBLE					\    || (GET_CODE (X) == HIGH&& GET_CODE (XEXP (X, 0)) == CONST_INT)	\    || GET_CODE (X) == CONSTANT_P_RTX)
end_define

begin_escape
end_escape

begin_comment
comment|/* The Overall Framework of an Assembler File.  */
end_comment

begin_comment
comment|/* A C string constant describing how to begin a comment in the target    assembler language.  The compiler assumes that the comment will end at the    end of the line.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|";"
end_define

begin_comment
comment|/* A C string constant for text to be output before each `asm' statement or    group of consecutive ones.  Normally this is `"#APP"', which is a comment    that has no effect on most assemblers but tells the GNU assembler that it    must check the lines that follow for all valid assembler constructs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_comment
comment|/* A C string constant for text to be output after each `asm' statement or    group of consecutive ones.  Normally this is `"#NO_APP"', which tells the    GNU assembler to resume making the time-saving assumptions that are valid    for ordinary compiler output.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_escape
end_escape

begin_comment
comment|/* Output of Data.  */
end_comment

begin_comment
comment|/* This is how to output a label to dwarf/dwarf2.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DWARF_ADDR
parameter_list|(
name|STREAM
parameter_list|,
name|LABEL
parameter_list|)
define|\
value|do {									\   fprintf (STREAM, "\t.picptr\t");					\   assemble_name (STREAM, LABEL);					\ } while (0)
end_define

begin_comment
comment|/* Whether to emit the gas specific dwarf2 line number support.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_ASM_LINE_DEBUG_INFO
value|(TARGET_DEBUG_LOC)
end_define

begin_escape
end_escape

begin_comment
comment|/* Output of Uninitialized Variables.  */
end_comment

begin_comment
comment|/* A C statement (sans semicolon) to output to the stdio stream STREAM the    assembler definition of a local-common-label named NAME whose size is SIZE    bytes.  The variable ROUNDED is the size rounded up to whatever alignment    the caller wants.     Use the expression `assemble_name (STREAM, NAME)' to output the name itself;    before and after that, output the additional assembler syntax for defining    the name, and a newline.     This macro controls how the assembler definitions of uninitialized static    variables are output.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_comment
comment|/* Like `ASM_OUTPUT_LOCAL' except takes the required alignment as a separate,    explicit argument.  If you define this macro, it is used in place of    `ASM_OUTPUT_LOCAL', and gives you more flexibility in handling the required    alignment of the variable.  The alignment is specified as the number of    bits.     Defined in svr4.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_undef

begin_comment
comment|/* This is for final.c, because it is used by ASM_DECLARE_OBJECT_NAME.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|size_directive_output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like `ASM_OUTPUT_ALIGNED_LOCAL' except that it takes an additional    parameter - the DECL of variable to be output, if there is one.    This macro can be called with DECL == NULL_TREE.  If you define    this macro, it is used in place of `ASM_OUTPUT_LOCAL' and    `ASM_OUTPUT_ALIGNED_LOCAL', and gives you more flexibility in    handling the destination of the variable.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_DECL_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_DECL_LOCAL
parameter_list|(
name|STREAM
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {                                                                   	\   if ((SIZE)> 0&& (SIZE)<= g_switch_value)				\     named_section (0, ".sbss", 0);                                    	\   else                                                                 	\     bss_section ();                                                  	\   ASM_OUTPUT_ALIGN (STREAM, floor_log2 ((ALIGN) / BITS_PER_UNIT));     	\   ASM_DECLARE_OBJECT_NAME (STREAM, NAME, DECL);                        	\   ASM_OUTPUT_SKIP (STREAM, (SIZE) ? (SIZE) : 1);                       	\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Output and Generation of Labels.  */
end_comment

begin_comment
comment|/* A C statement (sans semicolon) to output to the stdio stream STREAM the    assembler definition of a label named NAME.  Use the expression    `assemble_name (STREAM, NAME)' to output the name itself; before and after    that, output the additional assembler syntax for defining the name, and a    newline.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   assemble_name (STREAM, NAME);						\   fputs (":\n", STREAM);						\ } while (0)
end_define

begin_comment
comment|/* Globalizing directive for a label.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|"\t.globl "
end_define

begin_comment
comment|/* A C statement to store into the string STRING a label whose name is made    from the string PREFIX and the number NUM.     This string, when output subsequently by `assemble_name', should produce the    output that `(*targetm.asm_out.internal_label)' would produce with the same PREFIX    and NUM.     If the string begins with `*', then `assemble_name' will output the rest of    the string unchanged.  It is often convenient for    `ASM_GENERATE_INTERNAL_LABEL' to use `*' in this way.  If the string doesn't    start with `*', then `ASM_OUTPUT_LABELREF' gets to output the string, and    may change it.  (Of course, `ASM_OUTPUT_LABELREF' is also part of your    machine description, so you should know what it does on your machine.)     Defined in svr4.h.  */
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
value|do {									\   sprintf (LABEL, "*.%s%ld", PREFIX, (long)NUM);			\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Macros Controlling Initialization Routines.  */
end_comment

begin_comment
comment|/* If defined, a C string constant for the assembler operation to identify the    following data as initialization code.  If not defined, GCC will assume    such a section does not exist.  When you are using special sections for    initialization and termination functions, this macro also controls how    `crtstuff.c' and `libgcc2.c' arrange to run the initialization functions.     Defined in svr4.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_comment
comment|/* If defined, `main' will call `__main' despite the presence of    `INIT_SECTION_ASM_OP'.  This macro should be defined for systems where the    init section is not actually run automatically, but is still useful for    collecting the lists of constructors and destructors.  */
end_comment

begin_define
define|#
directive|define
name|INVOKE__main
end_define

begin_escape
end_escape

begin_comment
comment|/* Output of Assembler Instructions.  */
end_comment

begin_comment
comment|/* A C initializer containing the assembler's names for the machine registers,    each one as a C string constant.  This is what translates register numbers    in the compiler into assembler language.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{									\  "gr0",  "sp",   "fp",   "gr3",  "gr4",  "gr5",  "gr6",  "gr7",		\   "gr8",  "gr9",  "gr10", "gr11", "gr12", "gr13", "gr14", "gr15",	\   "gr16", "gr17", "gr18", "gr19", "gr20", "gr21", "gr22", "gr23",	\   "gr24", "gr25", "gr26", "gr27", "gr28", "gr29", "gr30", "gr31",	\   "gr32", "gr33", "gr34", "gr35", "gr36", "gr37", "gr38", "gr39",	\   "gr40", "gr41", "gr42", "gr43", "gr44", "gr45", "gr46", "gr47",	\   "gr48", "gr49", "gr50", "gr51", "gr52", "gr53", "gr54", "gr55",	\   "gr56", "gr57", "gr58", "gr59", "gr60", "gr61", "gr62", "gr63",	\ 									\   "fr0",  "fr1",  "fr2",  "fr3",  "fr4",  "fr5",  "fr6",  "fr7",	\   "fr8",  "fr9",  "fr10", "fr11", "fr12", "fr13", "fr14", "fr15",	\   "fr16", "fr17", "fr18", "fr19", "fr20", "fr21", "fr22", "fr23",	\   "fr24", "fr25", "fr26", "fr27", "fr28", "fr29", "fr30", "fr31",	\   "fr32", "fr33", "fr34", "fr35", "fr36", "fr37", "fr38", "fr39",	\   "fr40", "fr41", "fr42", "fr43", "fr44", "fr45", "fr46", "fr47",	\   "fr48", "fr49", "fr50", "fr51", "fr52", "fr53", "fr54", "fr55",	\   "fr56", "fr57", "fr58", "fr59", "fr60", "fr61", "fr62", "fr63",	\ 									\   "fcc0", "fcc1", "fcc2", "fcc3", "icc0", "icc1", "icc2", "icc3",	\   "cc0",  "cc1",  "cc2",  "cc3",  "cc4",  "cc5",  "cc6",  "cc7",	\   "acc0", "acc1", "acc2", "acc3", "acc4", "acc5", "acc6", "acc7",	\   "accg0","accg1","accg2","accg3","accg4","accg5","accg6","accg7",	\   "ap",   "lr",   "lcr"							\ }
end_define

begin_comment
comment|/* Define this macro if you are using an unusual assembler that    requires different names for the machine instructions.     The definition is a C statement or statements which output an    assembler instruction opcode to the stdio stream STREAM.  The    macro-operand PTR is a variable of type `char *' which points to    the opcode name in its "internal" form--the form that is written    in the machine description.  The definition should output the    opcode name to STREAM, performing any translation you desire, and    increment the variable PTR to point at the end of the opcode so    that it will not be output twice.     In fact, your macro definition may process less than the entire    opcode name, or more than the opcode name; but if you want to    process text that includes `%'-sequences to substitute operands,    you must take care of the substitution yourself.  Just be sure to    increment PTR over whatever text should not be output normally.     If you need to look at the operand values, they can be found as the    elements of `recog_operand'.     If the macro definition does nothing, the instruction is output in    the usual way.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_OPCODE
parameter_list|(
name|STREAM
parameter_list|,
name|PTR
parameter_list|)
define|\
value|(PTR) = frv_asm_output_opcode (STREAM, PTR)
end_define

begin_comment
comment|/* If defined, a C statement to be executed just prior to the output    of assembler code for INSN, to modify the extracted operands so    they will be output differently.     Here the argument OPVEC is the vector containing the operands    extracted from INSN, and NOPERANDS is the number of elements of    the vector which contain meaningful data for this insn.  The    contents of this vector are what will be used to convert the insn    template into assembler code, so you can change the assembler    output by changing the contents of the vector.     This macro is useful when various assembler syntaxes share a single    file of instruction patterns; by defining this macro differently,    you can cause a large class of instructions to be output    differently (such as with rearranged operands).  Naturally,    variations in assembler syntax affecting individual insn patterns    ought to be handled by writing conditional output routines in    those patterns.     If this macro is not defined, it is equivalent to a null statement.  */
end_comment

begin_define
define|#
directive|define
name|FINAL_PRESCAN_INSN
parameter_list|(
name|INSN
parameter_list|,
name|OPVEC
parameter_list|,
name|NOPERANDS
parameter_list|)
define|\
value|frv_final_prescan_insn (INSN, OPVEC, NOPERANDS)
end_define

begin_comment
comment|/* A C compound statement to output to stdio stream STREAM the assembler syntax    for an instruction operand X.  X is an RTL expression.     CODE is a value that can be used to specify one of several ways of printing    the operand.  It is used when identical operands must be printed differently    depending on the context.  CODE comes from the `%' specification that was    used to request printing of the operand.  If the specification was just    `%DIGIT' then CODE is 0; if the specification was `%LTR DIGIT' then CODE is    the ASCII code for LTR.     If X is a register, this macro should print the register's name.  The names    can be found in an array `reg_names' whose type is `char *[]'.  `reg_names'    is initialized from `REGISTER_NAMES'.     When the machine description has a specification `%PUNCT' (a `%' followed by    a punctuation character), this macro is called with a null pointer for X and    the punctuation character for CODE.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND
parameter_list|(
name|STREAM
parameter_list|,
name|X
parameter_list|,
name|CODE
parameter_list|)
value|frv_print_operand (STREAM, X, CODE)
end_define

begin_comment
comment|/* A C expression which evaluates to true if CODE is a valid punctuation    character for use in the `PRINT_OPERAND' macro.  If    `PRINT_OPERAND_PUNCT_VALID_P' is not defined, it means that no punctuation    characters (except for the standard one, `%') are used in this way.  */
end_comment

begin_comment
comment|/* . == gr0    # == hint operand -- always zero for now    @ == small data base register (gr16)    ~ == pic register (gr17)    * == temporary integer CCR register (cr3)& == temporary integer ICC register (icc3)  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '.' || (CODE) == '#' || (CODE) == '@' || (CODE) == '~'	\  || (CODE) == '*' || (CODE) == '&')
end_define

begin_comment
comment|/* A C compound statement to output to stdio stream STREAM the assembler syntax    for an instruction operand that is a memory reference whose address is X.  X    is an RTL expression.     On some machines, the syntax for a symbolic address depends on the section    that the address refers to.  On these machines, define the macro    `ENCODE_SECTION_INFO' to store the information into the `symbol_ref', and    then check for it here.     This declaration must be present.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|STREAM
parameter_list|,
name|X
parameter_list|)
value|frv_print_operand_address (STREAM, X)
end_define

begin_comment
comment|/* If defined, C string expressions to be used for the `%R', `%L', `%U', and    `%I' options of `asm_fprintf' (see `final.c').  These are useful when a    single `md' file must support multiple assembler formats.  In that case, the    various `tm.h' files can define these macros differently.     USER_LABEL_PREFIX is defined in svr4.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|""
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_define
define|#
directive|define
name|IMMEDIATE_PREFIX
value|"#"
end_define

begin_escape
end_escape

begin_comment
comment|/* Output of dispatch tables.  */
end_comment

begin_comment
comment|/* This macro should be provided on machines where the addresses in a dispatch    table are relative to the table's own address.     The definition should be a C statement to output to the stdio stream STREAM    an assembler pseudo-instruction to generate a difference between two labels.    VALUE and REL are the numbers of two internal labels.  The definitions of    these labels are output using `(*targetm.asm_out.internal_label)', and they must be    printed in the same way here.  For example,          fprintf (STREAM, "\t.word L%d-L%d\n", VALUE, REL)  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|BODY
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fprintf (STREAM, "\t.word .L%d-.L%d\n", VALUE, REL)
end_define

begin_comment
comment|/* This macro should be provided on machines where the addresses in a dispatch    table are absolute.     The definition should be a C statement to output to the stdio stream STREAM    an assembler pseudo-instruction to generate a reference to a label.  VALUE    is the number of an internal label whose definition is output using    `(*targetm.asm_out.internal_label)'.  For example,          fprintf (STREAM, "\t.word L%d\n", VALUE)  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (STREAM, "\t.word .L%d\n", VALUE)
end_define

begin_comment
comment|/* Define this if the label before a jump-table needs to be output specially.    The first three arguments are the same as for `(*targetm.asm_out.internal_label)';    the fourth argument is the jump-table which follows (a `jump_insn'    containing an `addr_vec' or `addr_diff_vec').     This feature is used on system V to output a `swbeg' statement for the    table.     If this macro is not defined, these labels are output with    `(*targetm.asm_out.internal_label)'.     Defined in svr4.h.  */
end_comment

begin_comment
comment|/* When generating embedded PIC or mips16 code we want to put the jump    table in the .text section.  In all other cases, we want to put the    jump table in the .rdata section.  Unfortunately, we can't use    JUMP_TABLES_IN_TEXT_SECTION, because it is not conditional.    Instead, we use ASM_OUTPUT_CASE_LABEL to switch back to the .text    section if appropriate.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CASE_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|TABLE
parameter_list|)
define|\
value|do {                                                                    \   if (flag_pic)                                                         \     function_section (current_function_decl);                           \   (*targetm.asm_out.internal_label) (STREAM, PREFIX, NUM);                      \ } while (0)
end_define

begin_comment
comment|/* Define this to determine whether case statement labels are relative to    the start of the case statement or not.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_PC_RELATIVE
value|(flag_pic)
end_define

begin_escape
end_escape

begin_comment
comment|/* Assembler Commands for Exception Regions.  */
end_comment

begin_comment
comment|/* Define this macro to 0 if your target supports DWARF 2 frame unwind    information, but it does not yet work with exception handling.  Otherwise,    if your target supports this information (if it defines    `INCOMING_RETURN_ADDR_RTX' and either `UNALIGNED_INT_ASM_OP' or    `OBJECT_FORMAT_ELF'), GCC will provide a default definition of 1.     If this macro is defined to 1, the DWARF 2 unwinder will be the default    exception handling mechanism; otherwise, setjmp/longjmp will be used by    default.     If this macro is defined to anything, the DWARF 2 unwinder will be used    instead of inline unwinders and __unwind_function in the non-setjmp case.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|1
end_define

begin_define
define|#
directive|define
name|DWARF_FRAME_RETURN_COLUMN
value|DWARF_FRAME_REGNUM (LR_REGNO)
end_define

begin_escape
end_escape

begin_comment
comment|/* Assembler Commands for Alignment.  */
end_comment

begin_comment
comment|/* A C statement to output to the stdio stream STREAM an assembler instruction    to advance the location counter by NBYTES bytes.  Those bytes should be zero    when loaded.  NBYTES will be a C expression of type `int'.     Defined in svr4.h.  */
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
name|STREAM
parameter_list|,
name|NBYTES
parameter_list|)
define|\
value|fprintf (STREAM, "\t.zero\t%u\n", (int)(NBYTES))
end_define

begin_comment
comment|/* A C statement to output to the stdio stream STREAM an assembler command to    advance the location counter to a multiple of 2 to the POWER bytes.  POWER    will be a C expression of type `int'.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|STREAM
parameter_list|,
name|POWER
parameter_list|)
define|\
value|fprintf ((STREAM), "\t.p2align %d\n", (POWER))
end_define

begin_comment
comment|/* Inside the text section, align with unpacked nops rather than zeros.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN_WITH_NOP
parameter_list|(
name|STREAM
parameter_list|,
name|POWER
parameter_list|)
define|\
value|fprintf ((STREAM), "\t.p2alignl %d,0x80880000\n", (POWER))
end_define

begin_escape
end_escape

begin_comment
comment|/* Macros Affecting all Debug Formats.  */
end_comment

begin_comment
comment|/* A C expression that returns the DBX register number for the compiler    register number REGNO.  In simple cases, the value of this expression may be    REGNO itself.  But sometimes there are some registers that the compiler    knows about and DBX does not, or vice versa.  In such cases, some register    may need to have one number in the compiler and another for DBX.     If two registers have consecutive numbers inside GCC, and they can be    used as a pair to hold a multiword value, then they *must* have consecutive    numbers after renumbering with `DBX_REGISTER_NUMBER'.  Otherwise, debuggers    will be unable to access such a pair, because they expect register pairs to    be consecutive in their own numbering scheme.     If you find yourself defining `DBX_REGISTER_NUMBER' in way that does not    preserve register pairs, then what you must do instead is redefine the    actual register numbering scheme.     This declaration is required.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|(REGNO)
end_define

begin_comment
comment|/* A C expression that returns the type of debugging output GCC produces    when the user specifies `-g' or `-ggdb'.  Define this if you have arranged    for GCC to support more than one format of debugging output.  Currently,    the allowable values are `DBX_DEBUG', `SDB_DEBUG', `DWARF_DEBUG',    `DWARF2_DEBUG', and `XCOFF_DEBUG'.     The value of this macro only affects the default debugging output; the user    can always get a specific type of output by using `-gstabs', `-gcoff',    `-gdwarf-1', `-gdwarf-2', or `-gxcoff'.     Defined in svr4.h.  */
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
value|DWARF2_DEBUG
end_define

begin_escape
end_escape

begin_comment
comment|/* Miscellaneous Parameters.  */
end_comment

begin_comment
comment|/* Define this if you have defined special-purpose predicates in the file    `MACHINE.c'.  This macro is called within an initializer of an array of    structures.  The first field in the structure is the name of a predicate and    the second field is an array of rtl codes.  For each predicate, list all rtl    codes that can be in expressions matched by the predicate.  The list should    have a trailing comma.  Here is an example of two entries in the list for a    typical RISC machine:          #define PREDICATE_CODES \           {"gen_reg_rtx_operand", {SUBREG, REG}},  \           {"reg_or_short_cint_operand", {SUBREG, REG, CONST_INT}},     Defining this macro does not affect the generated code (however, incorrect    definitions that omit an rtl code that may be matched by the predicate can    cause the compiler to malfunction).  Instead, it allows the table built by    `genrecog' to be more compact and efficient, thus speeding up the compiler.    The most important predicates to include in the list specified by this macro    are thoses used in the most insn patterns.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{ "integer_register_operand",		{ REG, SUBREG }},		\   { "frv_load_operand",			{ REG, SUBREG, MEM }},		\   { "gpr_no_subreg_operand",		{ REG }},			\   { "gpr_or_fpr_operand",		{ REG, SUBREG }},		\   { "gpr_or_int12_operand",		{ REG, SUBREG, CONST_INT }},	\   { "gpr_fpr_or_int12_operand",		{ REG, SUBREG, CONST_INT }},	\   { "gpr_or_int10_operand",		{ REG, SUBREG, CONST_INT }},	\   { "gpr_or_int_operand",		{ REG, SUBREG, CONST_INT }},	\   { "move_source_operand",		{ REG, SUBREG, CONST_INT, MEM,	\ 					  CONST_DOUBLE, CONST,		\ 					  SYMBOL_REF, LABEL_REF }},	\   { "move_destination_operand",		{ REG, SUBREG, MEM }},		\   { "condexec_source_operand",		{ REG, SUBREG, CONST_INT, MEM,	\ 					  CONST_DOUBLE }},		\   { "condexec_dest_operand",		{ REG, SUBREG, MEM }},		\   { "reg_or_0_operand",			{ REG, SUBREG, CONST_INT }},	\   { "lr_operand",			{ REG }},			\   { "gpr_or_memory_operand",		{ REG, SUBREG, MEM }},		\   { "fpr_or_memory_operand",		{ REG, SUBREG, MEM }},		\   { "int12_operand",			{ CONST_INT }},			\   { "int_2word_operand",		{ CONST_INT, CONST_DOUBLE,	\ 					  SYMBOL_REF, LABEL_REF, CONST }}, \   { "pic_register_operand",		{ REG }},			\   { "pic_symbolic_operand",		{ SYMBOL_REF, LABEL_REF, CONST }}, \   { "small_data_register_operand",	{ REG }},			\   { "small_data_symbolic_operand",	{ SYMBOL_REF, CONST }},		\   { "icc_operand",			{ REG }},			\   { "fcc_operand",			{ REG }},			\   { "cc_operand",			{ REG }},			\   { "icr_operand",			{ REG }},			\   { "fcr_operand",			{ REG }},			\   { "cr_operand",			{ REG }},			\   { "fpr_operand",			{ REG, SUBREG }},		\   { "even_reg_operand",			{ REG, SUBREG }},		\   { "odd_reg_operand",			{ REG, SUBREG }},		\   { "even_gpr_operand",			{ REG, SUBREG }},		\   { "odd_gpr_operand",			{ REG, SUBREG }},		\   { "quad_fpr_operand",			{ REG, SUBREG }},		\   { "even_fpr_operand",			{ REG, SUBREG }},		\   { "odd_fpr_operand",			{ REG, SUBREG }},		\   { "dbl_memory_one_insn_operand",	{ MEM }},			\   { "dbl_memory_two_insn_operand",	{ MEM }},			\   { "call_operand",			{ REG, SUBREG, PLUS, CONST_INT,	\ 					  SYMBOL_REF, LABEL_REF, CONST }}, \   { "upper_int16_operand",		{ CONST_INT }},			\   { "uint16_operand",			{ CONST_INT }},			\   { "relational_operator",		{ EQ, NE, LE, LT, GE, GT,	\ 					  LEU, LTU, GEU, GTU }},	\   { "signed_relational_operator",	{ EQ, NE, LE, LT, GE, GT }},	\   { "unsigned_relational_operator",	{ LEU, LTU, GEU, GTU }},	\   { "float_relational_operator",	{ EQ, NE, LE, LT, GE, GT }},	\   { "ccr_eqne_operator",		{ EQ, NE }},			\   { "minmax_operator",			{ SMIN, SMAX, UMIN, UMAX }},	\   { "condexec_si_binary_operator",	{ PLUS, MINUS, AND, IOR, XOR,	\ 					  ASHIFT, ASHIFTRT, LSHIFTRT }}, \   { "condexec_si_media_operator",	{ AND, IOR, XOR }},		\   { "condexec_si_divide_operator",	{ DIV, UDIV }},			\   { "condexec_si_unary_operator",	{ NOT, NEG }},			\   { "condexec_sf_add_operator",		{ PLUS, MINUS }},		\   { "condexec_sf_conv_operator",	{ ABS, NEG }},			\   { "intop_compare_operator",		{ PLUS, MINUS, AND, IOR, XOR,	\ 					  ASHIFT, ASHIFTRT, LSHIFTRT }}, \   { "condexec_intop_cmp_operator",	{ PLUS, MINUS, AND, IOR, XOR,	\ 					  ASHIFT, ASHIFTRT, LSHIFTRT }}, \   { "fpr_or_int6_operand",		{ REG, SUBREG, CONST_INT }},	\   { "int6_operand",			{ CONST_INT }},			\   { "int5_operand",			{ CONST_INT }},			\   { "uint5_operand",			{ CONST_INT }},			\   { "uint4_operand",			{ CONST_INT }},			\   { "uint1_operand",			{ CONST_INT }},			\   { "acc_operand",			{ REG, SUBREG }},		\   { "even_acc_operand",			{ REG, SUBREG }},		\   { "quad_acc_operand",			{ REG, SUBREG }},		\   { "accg_operand",			{ REG, SUBREG }},
end_define

begin_comment
comment|/* An alias for a machine mode name.  This is the machine mode that elements of    a jump-table should have.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
value|SImode
end_define

begin_comment
comment|/* Define this macro if operations between registers with integral mode smaller    than a word are always performed on the entire register.  Most RISC machines    have this property and most CISC machines do not.  */
end_comment

begin_define
define|#
directive|define
name|WORD_REGISTER_OPERATIONS
end_define

begin_comment
comment|/* Define this macro to be a C expression indicating when insns that read    memory in MODE, an integral mode narrower than a word, set the bits outside    of MODE to be either the sign-extension or the zero-extension of the data    read.  Return `SIGN_EXTEND' for values of MODE for which the insn    sign-extends, `ZERO_EXTEND' for which it zero-extends, and `NIL' for other    modes.     This macro is not called with MODE non-integral or with a width greater than    or equal to `BITS_PER_WORD', so you may return any value in this case.  Do    not define this macro if it would always return `NIL'.  On machines where    this macro is defined, you will normally define it as the constant    `SIGN_EXTEND' or `ZERO_EXTEND'.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_EXTEND_OP
parameter_list|(
name|MODE
parameter_list|)
value|SIGN_EXTEND
end_define

begin_comment
comment|/* Define if loading short immediate values into registers sign extends.  */
end_comment

begin_define
define|#
directive|define
name|SHORT_IMMEDIATES_SIGN_EXTEND
end_define

begin_comment
comment|/* The maximum number of bytes that a single instruction can move quickly from    memory to memory.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|8
end_define

begin_comment
comment|/* A C expression which is nonzero if on this machine it is safe to "convert"    an integer of INPREC bits to one of OUTPREC bits (where OUTPREC is smaller    than INPREC) by merely operating on it as if it had only OUTPREC bits.     On many machines, this expression can be 1.     When `TRULY_NOOP_TRUNCATION' returns 1 for a pair of sizes for modes for    which `MODES_TIEABLE_P' is 0, suboptimal code can result.  If this is the    case, making `TRULY_NOOP_TRUNCATION' return 0 in such cases may improve    things.  */
end_comment

begin_define
define|#
directive|define
name|TRULY_NOOP_TRUNCATION
parameter_list|(
name|OUTPREC
parameter_list|,
name|INPREC
parameter_list|)
value|1
end_define

begin_comment
comment|/* An alias for the machine mode for pointers.  On most machines, define this    to be the integer mode corresponding to the width of a hardware pointer;    `SImode' on 32-bit machine or `DImode' on 64-bit machines.  On some machines    you must define this to be one of the partial integer modes, such as    `PSImode'.     The width of `Pmode' must be at least as large as the value of    `POINTER_SIZE'.  If it is not equal, you must define the macro    `POINTERS_EXTEND_UNSIGNED' to specify how pointers are extended to `Pmode'.  */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|SImode
end_define

begin_comment
comment|/* An alias for the machine mode used for memory references to functions being    called, in `call' RTL expressions.  On most machines this should be    `QImode'.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|QImode
end_define

begin_comment
comment|/* Define this macro to handle System V style pragmas: #pragma pack and    #pragma weak.  Note, #pragma weak will only be supported if SUPPORT_WEAK is    defined.     Defined in svr4.h.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
value|1
end_define

begin_comment
comment|/* A C expression for the maximum number of instructions to execute via    conditional execution instructions instead of a branch.  A value of    BRANCH_COST+1 is the default if the machine does not use    cc0, and 1 if it does use cc0.  */
end_comment

begin_define
define|#
directive|define
name|MAX_CONDITIONAL_EXECUTE
value|frv_condexec_insns
end_define

begin_comment
comment|/* Default value of MAX_CONDITIONAL_EXECUTE if no -mcond-exec-insns= */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CONDEXEC_INSNS
value|8
end_define

begin_comment
comment|/* A C expression to modify the code described by the conditional if    information CE_INFO, possibly updating the tests in TRUE_EXPR, and    FALSE_EXPR for converting if-then and if-then-else code to conditional    instructions.  Set either TRUE_EXPR or FALSE_EXPR to a null pointer if the    tests cannot be converted.  */
end_comment

begin_define
define|#
directive|define
name|IFCVT_MODIFY_TESTS
parameter_list|(
name|CE_INFO
parameter_list|,
name|TRUE_EXPR
parameter_list|,
name|FALSE_EXPR
parameter_list|)
define|\
value|frv_ifcvt_modify_tests (CE_INFO,&TRUE_EXPR,&FALSE_EXPR)
end_define

begin_comment
comment|/* A C expression to modify the code described by the conditional if    information CE_INFO, for the basic block BB, possibly updating the tests in    TRUE_EXPR, and FALSE_EXPR for converting the&& and || parts of if-then or    if-then-else code to conditional instructions.  OLD_TRUE and OLD_FALSE are    the previous tests.  Set either TRUE_EXPR or FALSE_EXPR to a null pointer if    the tests cannot be converted.  */
end_comment

begin_define
define|#
directive|define
name|IFCVT_MODIFY_MULTIPLE_TESTS
parameter_list|(
name|CE_INFO
parameter_list|,
name|BB
parameter_list|,
name|TRUE_EXPR
parameter_list|,
name|FALSE_EXPR
parameter_list|)
define|\
value|frv_ifcvt_modify_multiple_tests (CE_INFO, BB,&TRUE_EXPR,&FALSE_EXPR)
end_define

begin_comment
comment|/* A C expression to modify the code described by the conditional if    information CE_INFO with the new PATTERN in INSN.  If PATTERN is a null    pointer after the IFCVT_MODIFY_INSN macro executes, it is assumed that that    insn cannot be converted to be executed conditionally.  */
end_comment

begin_define
define|#
directive|define
name|IFCVT_MODIFY_INSN
parameter_list|(
name|CE_INFO
parameter_list|,
name|PATTERN
parameter_list|,
name|INSN
parameter_list|)
define|\
value|(PATTERN) = frv_ifcvt_modify_insn (CE_INFO, PATTERN, INSN)
end_define

begin_comment
comment|/* A C expression to perform any final machine dependent modifications in    converting code to conditional execution in the code described by the    conditional if information CE_INFO.  */
end_comment

begin_define
define|#
directive|define
name|IFCVT_MODIFY_FINAL
parameter_list|(
name|CE_INFO
parameter_list|)
value|frv_ifcvt_modify_final (CE_INFO)
end_define

begin_comment
comment|/* A C expression to cancel any machine dependent modifications in converting    code to conditional execution in the code described by the conditional if    information CE_INFO.  */
end_comment

begin_define
define|#
directive|define
name|IFCVT_MODIFY_CANCEL
parameter_list|(
name|CE_INFO
parameter_list|)
value|frv_ifcvt_modify_cancel (CE_INFO)
end_define

begin_comment
comment|/* Initialize the extra fields provided by IFCVT_EXTRA_FIELDS.  */
end_comment

begin_define
define|#
directive|define
name|IFCVT_INIT_EXTRA_FIELDS
parameter_list|(
name|CE_INFO
parameter_list|)
value|frv_ifcvt_init_extra_fields (CE_INFO)
end_define

begin_comment
comment|/* Indicate how many instructions can be issued at the same time.  */
end_comment

begin_define
define|#
directive|define
name|ISSUE_RATE
define|\
value|(! TARGET_PACK ? 1							\  : (frv_cpu_type == FRV_CPU_GENERIC					\     || frv_cpu_type == FRV_CPU_FR500					\     || frv_cpu_type == FRV_CPU_TOMCAT) ? 4				\  : frv_cpu_type == FRV_CPU_FR400 ? 2 : 1)
end_define

begin_comment
comment|/* Set and clear whether this insn begins a VLIW insn.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_VLIW_START
parameter_list|(
name|INSN
parameter_list|)
value|PUT_MODE (INSN, VOIDmode)
end_define

begin_define
define|#
directive|define
name|SET_VLIW_START
parameter_list|(
name|INSN
parameter_list|)
value|PUT_MODE (INSN, TImode)
end_define

begin_comment
comment|/* The definition of the following macro results in that the 2nd jump    optimization (after the 2nd insn scheduling) is minimal.  It is    necessary to define when start cycle marks of insns (TImode is used    for this) is used for VLIW insn packing.  Some jump optimizations    make such marks invalid.  These marks are corrected for some    (minimal) optimizations.  ??? Probably the macro is temporary.    Final solution could making the 2nd jump optimizations before the    2nd instruction scheduling or corrections of the marks for all jump    optimizations.  Although some jump optimizations are actually    deoptimizations for VLIW (super-scalar) processors.  */
end_comment

begin_define
define|#
directive|define
name|MINIMAL_SECOND_JUMP_OPTIMIZATION
end_define

begin_comment
comment|/* Return true if parallel operations are expected to be emitted via the    packing flag.  */
end_comment

begin_define
define|#
directive|define
name|PACKING_FLAG_USED_P
parameter_list|()
define|\
value|(optimize&& flag_schedule_insns_after_reload&& ISSUE_RATE> 1)
end_define

begin_comment
comment|/* If the following macro is defined and nonzero and deterministic    finite state automata are used for pipeline hazard recognition, the    code making resource-constrained software pipelining is on.  */
end_comment

begin_define
define|#
directive|define
name|RCSP_SOFTWARE_PIPELINING
value|1
end_define

begin_comment
comment|/* If the following macro is defined and nonzero and deterministic    finite state automata are used for pipeline hazard recognition, we    will try to exchange insns in queue ready to improve the schedule.    The more macro value, the more tries will be made.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_CYCLE_MULTIPASS_SCHEDULING
value|1
end_define

begin_comment
comment|/* The following macro is used only when value of    FIRST_CYCLE_MULTIPASS_SCHEDULING is nonzero.  The more macro value,    the more tries will be made to choose better schedule.  If the    macro value is zero or negative there will be no multi-pass    scheduling.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_CYCLE_MULTIPASS_SCHEDULING_LOOKAHEAD
value|frv_sched_lookahead
end_define

begin_enum
enum|enum
name|frv_builtins
block|{
name|FRV_BUILTIN_MAND
block|,
name|FRV_BUILTIN_MOR
block|,
name|FRV_BUILTIN_MXOR
block|,
name|FRV_BUILTIN_MNOT
block|,
name|FRV_BUILTIN_MAVEH
block|,
name|FRV_BUILTIN_MSATHS
block|,
name|FRV_BUILTIN_MSATHU
block|,
name|FRV_BUILTIN_MADDHSS
block|,
name|FRV_BUILTIN_MADDHUS
block|,
name|FRV_BUILTIN_MSUBHSS
block|,
name|FRV_BUILTIN_MSUBHUS
block|,
name|FRV_BUILTIN_MPACKH
block|,
name|FRV_BUILTIN_MQADDHSS
block|,
name|FRV_BUILTIN_MQADDHUS
block|,
name|FRV_BUILTIN_MQSUBHSS
block|,
name|FRV_BUILTIN_MQSUBHUS
block|,
name|FRV_BUILTIN_MUNPACKH
block|,
name|FRV_BUILTIN_MDPACKH
block|,
name|FRV_BUILTIN_MBTOH
block|,
name|FRV_BUILTIN_MHTOB
block|,
name|FRV_BUILTIN_MCOP1
block|,
name|FRV_BUILTIN_MCOP2
block|,
name|FRV_BUILTIN_MROTLI
block|,
name|FRV_BUILTIN_MROTRI
block|,
name|FRV_BUILTIN_MWCUT
block|,
name|FRV_BUILTIN_MSLLHI
block|,
name|FRV_BUILTIN_MSRLHI
block|,
name|FRV_BUILTIN_MSRAHI
block|,
name|FRV_BUILTIN_MEXPDHW
block|,
name|FRV_BUILTIN_MEXPDHD
block|,
name|FRV_BUILTIN_MMULHS
block|,
name|FRV_BUILTIN_MMULHU
block|,
name|FRV_BUILTIN_MMULXHS
block|,
name|FRV_BUILTIN_MMULXHU
block|,
name|FRV_BUILTIN_MMACHS
block|,
name|FRV_BUILTIN_MMACHU
block|,
name|FRV_BUILTIN_MMRDHS
block|,
name|FRV_BUILTIN_MMRDHU
block|,
name|FRV_BUILTIN_MQMULHS
block|,
name|FRV_BUILTIN_MQMULHU
block|,
name|FRV_BUILTIN_MQMULXHU
block|,
name|FRV_BUILTIN_MQMULXHS
block|,
name|FRV_BUILTIN_MQMACHS
block|,
name|FRV_BUILTIN_MQMACHU
block|,
name|FRV_BUILTIN_MCPXRS
block|,
name|FRV_BUILTIN_MCPXRU
block|,
name|FRV_BUILTIN_MCPXIS
block|,
name|FRV_BUILTIN_MCPXIU
block|,
name|FRV_BUILTIN_MQCPXRS
block|,
name|FRV_BUILTIN_MQCPXRU
block|,
name|FRV_BUILTIN_MQCPXIS
block|,
name|FRV_BUILTIN_MQCPXIU
block|,
name|FRV_BUILTIN_MCUT
block|,
name|FRV_BUILTIN_MCUTSS
block|,
name|FRV_BUILTIN_MWTACC
block|,
name|FRV_BUILTIN_MWTACCG
block|,
name|FRV_BUILTIN_MRDACC
block|,
name|FRV_BUILTIN_MRDACCG
block|,
name|FRV_BUILTIN_MTRAP
block|,
name|FRV_BUILTIN_MCLRACC
block|,
name|FRV_BUILTIN_MCLRACCA
block|,
name|FRV_BUILTIN_MDUNPACKH
block|,
name|FRV_BUILTIN_MBTOHE
block|,
name|FRV_BUILTIN_MQXMACHS
block|,
name|FRV_BUILTIN_MQXMACXHS
block|,
name|FRV_BUILTIN_MQMACXHS
block|,
name|FRV_BUILTIN_MADDACCS
block|,
name|FRV_BUILTIN_MSUBACCS
block|,
name|FRV_BUILTIN_MASACCS
block|,
name|FRV_BUILTIN_MDADDACCS
block|,
name|FRV_BUILTIN_MDSUBACCS
block|,
name|FRV_BUILTIN_MDASACCS
block|,
name|FRV_BUILTIN_MABSHS
block|,
name|FRV_BUILTIN_MDROTLI
block|,
name|FRV_BUILTIN_MCPLHI
block|,
name|FRV_BUILTIN_MCPLI
block|,
name|FRV_BUILTIN_MDCUTSSI
block|,
name|FRV_BUILTIN_MQSATHS
block|,
name|FRV_BUILTIN_MHSETLOS
block|,
name|FRV_BUILTIN_MHSETLOH
block|,
name|FRV_BUILTIN_MHSETHIS
block|,
name|FRV_BUILTIN_MHSETHIH
block|,
name|FRV_BUILTIN_MHDSETS
block|,
name|FRV_BUILTIN_MHDSETH
block|}
enum|;
end_enum

begin_comment
comment|/* Enable prototypes on the call rtl functions.  */
end_comment

begin_define
define|#
directive|define
name|MD_CALL_PROTOTYPES
value|1
end_define

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|frv_compare_op0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operand save for */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|frv_compare_op1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* comparison generation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FRV_H__ */
end_comment

end_unit

