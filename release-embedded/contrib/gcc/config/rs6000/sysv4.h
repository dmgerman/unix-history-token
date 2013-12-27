begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for PowerPC running System V.4    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003,    2004, 2005, 2006, 2007 Free Software Foundation, Inc.    Contributed by Cygnus Support.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Header files should be C++ aware in general.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_IMPLICIT_EXTERN_C
end_undef

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* Yes!  We are ELF.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OBJECT_FORMAT
value|OBJECT_ELF
end_define

begin_comment
comment|/* Default ABI to compile code for.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_ABI
value|rs6000_current_abi
end_define

begin_comment
comment|/* Default ABI to use.  */
end_comment

begin_define
define|#
directive|define
name|RS6000_ABI_NAME
value|"sysv"
end_define

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_DEFAULT_SPEC
value|"-mppc"
end_define

begin_comment
comment|/* Small data support types.  */
end_comment

begin_enum
enum|enum
name|rs6000_sdata_type
block|{
name|SDATA_NONE
block|,
comment|/* No small data support.  */
name|SDATA_DATA
block|,
comment|/* Just put data in .sbss/.sdata, don't use relocs.  */
name|SDATA_SYSV
block|,
comment|/* Use r13 to point to .sdata/.sbss.  */
name|SDATA_EABI
comment|/* Use r13 like above, r2 points to .sdata2/.sbss2.  */
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|rs6000_sdata_type
name|rs6000_sdata
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_TOC
value|((target_flags& MASK_64BIT)		\ 				 || ((target_flags& (MASK_RELOCATABLE	\ 						      | MASK_MINIMAL_TOC)) \&& flag_pic> 1)			\ 				 || DEFAULT_ABI == ABI_AIX)
end_define

begin_define
define|#
directive|define
name|TARGET_BITFIELD_TYPE
value|(! TARGET_NO_BITFIELD_TYPE)
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_ENDIAN
value|(! TARGET_LITTLE_ENDIAN)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_PROTOTYPE
value|(! TARGET_PROTOTYPE)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_TOC
value|(! TARGET_TOC)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_EABI
value|(! TARGET_EABI)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AS_REL16
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_SECURE_PLT
end_undef

begin_define
define|#
directive|define
name|TARGET_SECURE_PLT
value|secure_plt
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_abi_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_sdata_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_tls_size_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For -mtls-size= */
end_comment

begin_define
define|#
directive|define
name|SDATA_DEFAULT_SIZE
value|8
end_define

begin_comment
comment|/* Sometimes certain combinations of command options do not make sense    on a particular target machine.  You can define a macro    `OVERRIDE_OPTIONS' to take account of this.  This macro, if    defined, is executed once just after all the command options have    been parsed.     The macro SUBTARGET_OVERRIDE_OPTIONS is provided for subtargets, to    get control.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|do {									\   if (!g_switch_set)							\     g_switch_value = SDATA_DEFAULT_SIZE;				\ 									\   if (rs6000_abi_name == NULL)						\     rs6000_abi_name = RS6000_ABI_NAME;					\ 									\   if (!strcmp (rs6000_abi_name, "sysv"))				\     rs6000_current_abi = ABI_V4;					\   else if (!strcmp (rs6000_abi_name, "sysv-noeabi"))			\     {									\       rs6000_current_abi = ABI_V4;					\       target_flags&= ~ MASK_EABI;					\     }									\   else if (!strcmp (rs6000_abi_name, "sysv-eabi")			\ 	   || !strcmp (rs6000_abi_name, "eabi"))			\     {									\       rs6000_current_abi = ABI_V4;					\       target_flags |= MASK_EABI;					\     }									\   else if (!strcmp (rs6000_abi_name, "aixdesc"))			\     rs6000_current_abi = ABI_AIX;					\   else if (!strcmp (rs6000_abi_name, "freebsd"))			\     rs6000_current_abi = ABI_V4;					\   else if (!strcmp (rs6000_abi_name, "linux"))				\     {									\       if (TARGET_64BIT)							\ 	rs6000_current_abi = ABI_AIX;					\       else								\ 	rs6000_current_abi = ABI_V4;					\     }									\   else if (!strcmp (rs6000_abi_name, "gnu"))				\     rs6000_current_abi = ABI_V4;					\   else if (!strcmp (rs6000_abi_name, "netbsd"))				\     rs6000_current_abi = ABI_V4;					\   else if (!strcmp (rs6000_abi_name, "openbsd"))			\     rs6000_current_abi = ABI_V4;					\   else if (!strcmp (rs6000_abi_name, "i960-old"))			\     {									\       rs6000_current_abi = ABI_V4;					\       target_flags |= (MASK_LITTLE_ENDIAN | MASK_EABI			\ 		       | MASK_NO_BITFIELD_WORD);			\       target_flags&= ~MASK_STRICT_ALIGN;				\     }									\   else									\     {									\       rs6000_current_abi = ABI_V4;					\       error ("bad value for -mcall-%s", rs6000_abi_name);		\     }									\ 									\   if (rs6000_sdata_name)						\     {									\       if (!strcmp (rs6000_sdata_name, "none"))				\ 	rs6000_sdata = SDATA_NONE;					\       else if (!strcmp (rs6000_sdata_name, "data"))			\ 	rs6000_sdata = SDATA_DATA;					\       else if (!strcmp (rs6000_sdata_name, "default"))			\ 	rs6000_sdata = (TARGET_EABI) ? SDATA_EABI : SDATA_SYSV;		\       else if (!strcmp (rs6000_sdata_name, "sysv"))			\ 	rs6000_sdata = SDATA_SYSV;					\       else if (!strcmp (rs6000_sdata_name, "eabi"))			\ 	rs6000_sdata = SDATA_EABI;					\       else								\ 	error ("bad value for -msdata=%s", rs6000_sdata_name);		\     }									\   else if (DEFAULT_ABI == ABI_V4)					\     {									\       rs6000_sdata = SDATA_DATA;					\       rs6000_sdata_name = "data";					\     }									\   else									\     {									\       rs6000_sdata = SDATA_NONE;					\       rs6000_sdata_name = "none";					\     }									\ 									\   if (TARGET_RELOCATABLE&&						\       (rs6000_sdata == SDATA_EABI || rs6000_sdata == SDATA_SYSV))	\     {									\       rs6000_sdata = SDATA_DATA;					\       error ("-mrelocatable and -msdata=%s are incompatible",		\ 	     rs6000_sdata_name);					\     }									\ 									\   else if (flag_pic&& DEFAULT_ABI != ABI_AIX				\&& (rs6000_sdata == SDATA_EABI				\ 	       || rs6000_sdata == SDATA_SYSV))				\     {									\       rs6000_sdata = SDATA_DATA;					\       error ("-f%s and -msdata=%s are incompatible",			\ 	     (flag_pic> 1) ? "PIC" : "pic",				\ 	     rs6000_sdata_name);					\     }									\ 									\   if ((rs6000_sdata != SDATA_NONE&& DEFAULT_ABI != ABI_V4)		\       || (rs6000_sdata == SDATA_EABI&& !TARGET_EABI))			\     {									\       rs6000_sdata = SDATA_NONE;					\       error ("-msdata=%s and -mcall-%s are incompatible",		\ 	     rs6000_sdata_name, rs6000_abi_name);			\     }									\ 									\   targetm.have_srodata_section = rs6000_sdata == SDATA_EABI;		\ 									\   if (TARGET_RELOCATABLE&& !TARGET_MINIMAL_TOC)			\     {									\       target_flags |= MASK_MINIMAL_TOC;					\       error ("-mrelocatable and -mno-minimal-toc are incompatible");	\     }									\ 									\   if (TARGET_RELOCATABLE&& rs6000_current_abi == ABI_AIX)		\     {									\       target_flags&= ~MASK_RELOCATABLE;				\       error ("-mrelocatable and -mcall-%s are incompatible",		\ 	     rs6000_abi_name);						\     }									\ 									\   if (!TARGET_64BIT&& flag_pic> 1&& rs6000_current_abi == ABI_AIX)	\     {									\       flag_pic = 0;							\       error ("-fPIC and -mcall-%s are incompatible",			\ 	     rs6000_abi_name);						\     }									\ 									\   if (rs6000_current_abi == ABI_AIX&& TARGET_LITTLE_ENDIAN)		\     {									\       target_flags&= ~MASK_LITTLE_ENDIAN;				\       error ("-mcall-aixdesc must be big endian");			\     }									\ 									\   if (TARGET_SECURE_PLT != secure_plt)					\     {									\       error ("-msecure-plt not supported by your assembler");		\     }									\ 									\
comment|/* Treat -fPIC the same as -mrelocatable.  */
value|\   if (flag_pic> 1&& DEFAULT_ABI != ABI_AIX)				\     {									\       target_flags |= MASK_RELOCATABLE | MASK_MINIMAL_TOC;		\       TARGET_NO_FP_IN_TOC = 1;						\     }									\ 									\   else if (TARGET_RELOCATABLE)						\     flag_pic = 2;							\ } while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|RS6000_BI_ARCH
end_ifndef

begin_define
define|#
directive|define
name|SUBSUBTARGET_OVERRIDE_OPTIONS
define|\
value|do {									\   if ((TARGET_DEFAULT ^ target_flags)& MASK_64BIT)			\     error ("-m%s not supported in this configuration",			\ 	   (target_flags& MASK_64BIT) ? "64" : "32");			\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Override rs6000.h definition.  */
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
value|(MASK_POWERPC | MASK_NEW_MNEMONICS)
end_define

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|PROCESSOR_DEFAULT
end_undef

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT
value|PROCESSOR_PPC750
end_define

begin_comment
comment|/* SVR4 only defined for PowerPC, so short-circuit POWER patterns.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_POWER
end_undef

begin_define
define|#
directive|define
name|TARGET_POWER
value|0
end_define

begin_define
define|#
directive|define
name|FIXED_R2
value|1
end_define

begin_comment
comment|/* System V.4 uses register 13 as a pointer to the small data area,    so it is not available to the normal user.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_R13
value|1
end_define

begin_comment
comment|/* Override default big endianism definitions in rs6000.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|BYTES_BIG_ENDIAN
end_undef

begin_undef
undef|#
directive|undef
name|WORDS_BIG_ENDIAN
end_undef

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|(TARGET_BIG_ENDIAN)
end_define

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|(TARGET_BIG_ENDIAN)
end_define

begin_comment
comment|/* Define this to set the endianness to use in libgcc2.c, which can    not depend on target_flags.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LITTLE_ENDIAN__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sun__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define cutoff for using external functions to save floating point.    Currently on V.4, always use inline stores.  */
end_comment

begin_define
define|#
directive|define
name|FP_SAVE_INLINE
parameter_list|(
name|FIRST_REG
parameter_list|)
value|((FIRST_REG)< 64)
end_define

begin_comment
comment|/* Put jump tables in read-only memory, rather than in .text.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|0
end_define

begin_comment
comment|/* Prefix and suffix to use to saving floating point.  */
end_comment

begin_define
define|#
directive|define
name|SAVE_FP_PREFIX
value|"_savefpr_"
end_define

begin_define
define|#
directive|define
name|SAVE_FP_SUFFIX
value|"_l"
end_define

begin_comment
comment|/* Prefix and suffix to use to restoring floating point.  */
end_comment

begin_define
define|#
directive|define
name|RESTORE_FP_PREFIX
value|"_restfpr_"
end_define

begin_define
define|#
directive|define
name|RESTORE_FP_SUFFIX
value|"_l"
end_define

begin_comment
comment|/* Type used for ptrdiff_t, as a string used in a declaration.  */
end_comment

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_comment
comment|/* Type used for wchar_t, as a string used in a declaration.  */
end_comment

begin_comment
comment|/* Override svr4.h definition.  */
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
value|"long int"
end_define

begin_comment
comment|/* Width of wchar_t in bits.  */
end_comment

begin_comment
comment|/* Override svr4.h definition.  */
end_comment

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
comment|/* Make int foo : 8 not cause structures to be aligned to an int boundary.  */
end_comment

begin_comment
comment|/* Override elfos.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|PCC_BITFIELD_TYPE_MATTERS
end_undef

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|(TARGET_BITFIELD_TYPE)
end_define

begin_undef
undef|#
directive|undef
name|BITFIELD_NBYTES_LIMITED
end_undef

begin_define
define|#
directive|define
name|BITFIELD_NBYTES_LIMITED
value|(TARGET_NO_BITFIELD_WORD)
end_define

begin_comment
comment|/* Define this macro to be the value 1 if instructions will fail to    work if given data not on the nominal alignment.  If instructions    will merely go slower in that case, define this macro as 0.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRICT_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|(TARGET_STRICT_ALIGN)
end_define

begin_comment
comment|/* Define this macro if you wish to preserve a certain alignment for    the stack pointer, greater than what the hardware enforces.  The    definition is a C expression for the desired alignment (measured    in bits).  This macro must evaluate to a value equal to or larger    than STACK_BOUNDARY.    For the SYSV ABI and variants the alignment of the stack pointer    is usually controlled manually in rs6000.c. However, to maintain    alignment across alloca () in all circumstances,    PREFERRED_STACK_BOUNDARY needs to be set as well.    This has the additional advantage of allowing a bigger maximum    alignment of user objects on the stack.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_STACK_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|PREFERRED_STACK_BOUNDARY
value|128
end_define

begin_comment
comment|/* Real stack boundary as mandated by the appropriate ABI.  */
end_comment

begin_define
define|#
directive|define
name|ABI_STACK_BOUNDARY
define|\
value|((TARGET_EABI&& !TARGET_ALTIVEC&& !TARGET_ALTIVEC_ABI) ? 64 : 128)
end_define

begin_comment
comment|/* An expression for the alignment of a structure field FIELD if the    alignment computed in the usual way is COMPUTED.  */
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
value|((TARGET_ALTIVEC&& TREE_CODE (TREE_TYPE (FIELD)) == VECTOR_TYPE)     \ 	 ? 128 : COMPUTED)
end_define

begin_undef
undef|#
directive|undef
name|BIGGEST_FIELD_ALIGNMENT
end_undef

begin_comment
comment|/* Use ELF style section commands.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.section\t\".text\""
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.section\t\".data\""
end_define

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section\t\".bss\""
end_define

begin_comment
comment|/* Override elfos.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"\t.section\t\".init\",\"ax\""
end_define

begin_comment
comment|/* Override elfos.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
value|"\t.section\t\".fini\",\"ax\""
end_define

begin_define
define|#
directive|define
name|TOC_SECTION_ASM_OP
value|"\t.section\t\".got\",\"aw\""
end_define

begin_comment
comment|/* Put PC relative got entries in .got2.  */
end_comment

begin_define
define|#
directive|define
name|MINIMAL_TOC_SECTION_ASM_OP
define|\
value|(TARGET_RELOCATABLE || (flag_pic&& DEFAULT_ABI != ABI_AIX)		\    ? "\t.section\t\".got2\",\"aw\"" : "\t.section\t\".got1\",\"aw\"")
end_define

begin_define
define|#
directive|define
name|SDATA_SECTION_ASM_OP
value|"\t.section\t\".sdata\",\"aw\""
end_define

begin_define
define|#
directive|define
name|SDATA2_SECTION_ASM_OP
value|"\t.section\t\".sdata2\",\"a\""
end_define

begin_define
define|#
directive|define
name|SBSS_SECTION_ASM_OP
value|"\t.section\t\".sbss\",\"aw\",@nobits"
end_define

begin_comment
comment|/* Override default elf definitions.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_INIT_SECTIONS
value|rs6000_elf_asm_init_sections
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_RELOC_RW_MASK
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_RELOC_RW_MASK
value|rs6000_elf_reloc_rw_mask
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_RTX_SECTION
value|rs6000_elf_select_rtx_section
end_define

begin_comment
comment|/* Return nonzero if this entry is to be written into the constant pool    in a special way.  We do so if this is a SYMBOL_REF, LABEL_REF or a CONST    containing one of them.  If -mfp-in-toc (the default), we also do    this for floating-point constants.  We actually can only do this    if the FP formats of the target and host machines are the same, but    we can't check that since not every file that uses    GO_IF_LEGITIMATE_ADDRESS_P includes real.h.     Unlike AIX, we don't key off of -mminimal-toc, but instead do not    allow floating point constants in the TOC if -mrelocatable.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SPECIAL_POOL_ENTRY_P
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SPECIAL_POOL_ENTRY_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(TARGET_TOC								\&& (GET_CODE (X) == SYMBOL_REF					\        || (GET_CODE (X) == CONST&& GET_CODE (XEXP (X, 0)) == PLUS	\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == SYMBOL_REF)		\        || GET_CODE (X) == LABEL_REF					\        || (GET_CODE (X) == CONST_INT 					\&& GET_MODE_BITSIZE (MODE)<= GET_MODE_BITSIZE (Pmode))	\        || (!TARGET_NO_FP_IN_TOC						\&& !TARGET_RELOCATABLE					\&& GET_CODE (X) == CONST_DOUBLE				\&& SCALAR_FLOAT_MODE_P (GET_MODE (X))			\&& BITS_PER_WORD == HOST_BITS_PER_INT)))
end_define

begin_comment
comment|/* These macros generate the special .type and .size directives which    are used to set the corresponding fields of the linker symbol table    entries in an ELF object file under SVR4.  These macros also output    the starting labels for the relevant functions/objects.  */
end_comment

begin_comment
comment|/* Write the extra assembler code needed to declare a function properly.    Some svr4 assemblers need to also have something extra said about the    function's return value.  We allow for that here.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rs6000_pic_labelno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Override elfos.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|rs6000_elf_declare_function_name ((FILE), (NAME), (DECL))
end_define

begin_comment
comment|/* The USER_LABEL_PREFIX stuff is affected by the -fleading-underscore    flag.  The LOCAL_LABEL_PREFIX variable is used by dbxelf.h.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_comment
comment|/* svr4.h overrides (*targetm.asm_out.internal_label).  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL_PREFIX
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|)
define|\
value|asm_fprintf (FILE, "%L%s", PREFIX)
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
comment|/* This says how to output assembler code to declare an    uninitialized internal linkage data object.  Under SVR4,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_ASM_OP
value|"\t.local\t"
end_define

begin_define
define|#
directive|define
name|LCOMM_ASM_OP
value|"\t.lcomm\t"
end_define

begin_comment
comment|/* Describe how to emit uninitialized local items.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_DECL_LOCAL
parameter_list|(
name|FILE
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
value|do {									\   if ((DECL)&& rs6000_elf_in_small_data_p (DECL))			\     {									\       switch_to_section (sbss_section);					\       ASM_OUTPUT_ALIGN (FILE, exact_log2 (ALIGN / BITS_PER_UNIT));	\       ASM_OUTPUT_LABEL (FILE, NAME);					\       ASM_OUTPUT_SKIP (FILE, SIZE);					\       if (!flag_inhibit_size_directive&& (SIZE)> 0)			\ 	ASM_OUTPUT_SIZE_DIRECTIVE (FILE, NAME, SIZE);			\     }									\   else									\     {									\       fprintf (FILE, "%s", LCOMM_ASM_OP);				\       assemble_name ((FILE), (NAME));					\       fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\ 	       (SIZE), (ALIGN) / BITS_PER_UNIT);			\     }									\   ASM_OUTPUT_TYPE_DIRECTIVE (FILE, NAME, "object");			\ } while (0)
end_define

begin_comment
comment|/* Describe how to emit uninitialized external linkage items.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
parameter_list|(
name|FILE
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
value|do {									\   ASM_OUTPUT_ALIGNED_DECL_LOCAL (FILE, DECL, NAME, SIZE, ALIGN);	\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifdef

begin_comment
comment|/* To support -falign-* switches we need to use .p2align so    that alignment directives in code sections will be padded    with no-op instructions, rather than zeroes.  */
end_comment

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
value|if ((LOG) != 0)							\     {									\       if ((MAX_SKIP) == 0)						\ 	fprintf ((FILE), "\t.p2align %d\n", (LOG));			\       else								\ 	fprintf ((FILE), "\t.p2align %d,,%d\n",	(LOG), (MAX_SKIP));	\     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output code to push a register on the stack.    It need not be very fast code.     On the rs6000, we must keep the backchain up to date.  In order    to simplify things, always allocate 16 bytes for a push (System V    wants to keep stack aligned to a 16 byte boundary).  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|do {									\   if (DEFAULT_ABI == ABI_V4)						\     asm_fprintf (FILE,							\ 		 "\t{stu|stwu} %s,-16(%s)\n\t{st|stw} %s,12(%s)\n",	\ 		 reg_names[1], reg_names[1], reg_names[REGNO],		\ 		 reg_names[1]);						\ } while (0)
end_define

begin_comment
comment|/* This is how to output an insn to pop a register from the stack.    It need not be very fast code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|do {									\   if (DEFAULT_ABI == ABI_V4)						\     asm_fprintf (FILE,							\ 		 "\t{l|lwz} %s,12(%s)\n\t{ai|addic} %s,%s,16\n",	\ 		 reg_names[REGNO], reg_names[1], reg_names[1],		\ 		 reg_names[1]);						\ } while (0)
end_define

begin_comment
comment|/* Switch  Recognition by gcc.c.  Add -G xx support.  */
end_comment

begin_comment
comment|/* Override svr4.h definition.  */
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
value|((CHAR) == 'D' || (CHAR) == 'U' || (CHAR) == 'o'			\    || (CHAR) == 'e' || (CHAR) == 'T' || (CHAR) == 'u'			\    || (CHAR) == 'I' || (CHAR) == 'm' || (CHAR) == 'x'			\    || (CHAR) == 'L' || (CHAR) == 'A' || (CHAR) == 'V'			\    || (CHAR) == 'B' || (CHAR) == 'b' || (CHAR) == 'G')
end_define

begin_decl_stmt
specifier|extern
name|int
name|fixuplabelno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Handle constructors specially for -mrelocatable.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|rs6000_elf_asm_out_constructor
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_DESTRUCTOR
value|rs6000_elf_asm_out_destructor
end_define

begin_comment
comment|/* This is the end of what might become sysv4.h.  */
end_comment

begin_comment
comment|/* Use DWARF 2 debugging information by default.  */
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

begin_comment
comment|/* Historically we have also supported stabs debugging.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_ENCODE_SECTION_INFO
value|rs6000_elf_encode_section_info
end_define

begin_define
define|#
directive|define
name|TARGET_IN_SMALL_DATA_P
value|rs6000_elf_in_small_data_p
end_define

begin_comment
comment|/* The ELF version doesn't encode [DS] or whatever at the end of symbols.  */
end_comment

begin_define
define|#
directive|define
name|RS6000_OUTPUT_BASENAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|assemble_name (FILE, NAME)
end_define

begin_comment
comment|/* We have to output the stabs for the function name *first*, before    outputting its label.  */
end_comment

begin_define
define|#
directive|define
name|DBX_FUNCTION_FIRST
end_define

begin_comment
comment|/* This is the end of what might become sysv4dbx.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VERSION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (PowerPC System V.4)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_define
define|#
directive|define
name|TARGET_OS_SYSV_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       if (target_flags_explicit			\& MASK_RELOCATABLE)			\ 	builtin_define ("_RELOCATABLE");	\     }						\   while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_OS_CPP_BUILTINS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       builtin_define_std ("PPC");		\       builtin_define_std ("unix");		\       builtin_define ("__svr4__");		\       builtin_assert ("system=unix");		\       builtin_assert ("system=svr4");		\       builtin_assert ("cpu=powerpc");		\       builtin_assert ("machine=powerpc");	\       TARGET_OS_SYSV_CPP_BUILTINS ();		\     }						\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Pass various options to the assembler.  */
end_comment

begin_comment
comment|/* Override svr4.h definition.  */
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
value|"%(asm_cpu) \ %{.s: %{mregnames} %{mno-regnames}} %{.S: %{mregnames} %{mno-regnames}} \ %{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*} \ %{mrelocatable} %{mrelocatable-lib} %{fpic|fpie|fPIC|fPIE:-K PIC} \ %{memb|msdata|msdata=eabi: -memb} \ %{mlittle|mlittle-endian:-mlittle; \   mbig|mbig-endian      :-mbig;    \   mcall-aixdesc |		   \   mcall-freebsd |		   \   mcall-netbsd  |		   \   mcall-openbsd |		   \   mcall-linux   |		   \   mcall-gnu             :-mbig;    \   mcall-i960-old        :-mlittle}"
end_define

begin_define
define|#
directive|define
name|CC1_ENDIAN_BIG_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|CC1_ENDIAN_LITTLE_SPEC
value|"\ %{!mstrict-align: %{!mno-strict-align: \     %{!mcall-i960-old: \ 	-mstrict-align \     } \ }}"
end_define

begin_define
define|#
directive|define
name|CC1_ENDIAN_DEFAULT_SPEC
value|"%(cc1_endian_big)"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CC1_SECURE_PLT_DEFAULT_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CC1_SECURE_PLT_DEFAULT_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Pass -G xxx to the compiler and set correct endian mode.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{G*} \ %{mlittle|mlittle-endian: %(cc1_endian_little);           \   mbig   |mbig-endian   : %(cc1_endian_big);              \   mcall-aixdesc |					  \   mcall-freebsd |					  \   mcall-netbsd  |					  \   mcall-openbsd |					  \   mcall-linux   |					  \   mcall-gnu             : -mbig %(cc1_endian_big);        \   mcall-i960-old        : -mlittle %(cc1_endian_little);  \                         : %(cc1_endian_default)}          \ %{meabi: %{!mcall-*: -mcall-sysv }} \ %{!meabi: %{!mno-eabi: \     %{mrelocatable: -meabi } \     %{mcall-freebsd: -mno-eabi } \     %{mcall-i960-old: -meabi } \     %{mcall-linux: -mno-eabi } \     %{mcall-gnu: -mno-eabi } \     %{mcall-netbsd: -mno-eabi } \     %{mcall-openbsd: -mno-eabi }}} \ %{msdata: -msdata=default} \ %{mno-sdata: -msdata=none} \ %{!mbss-plt: %{!msecure-plt: %(cc1_secure_plt_default)}} \ %{profile: -p}"
end_define

begin_comment
comment|/* Don't put -Y P,<path> for cross compilers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_DIRECTORY_STRUCTURE
end_ifndef

begin_define
define|#
directive|define
name|LINK_PATH_SPEC
value|"\ %{!R*:%{L*:-R %*}} \ %{!nostdlib: %{!YP,*: \     %{compat-bsd: \ 	%{p:-Y P,/usr/ucblib:/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \ 	%{!p:-Y P,/usr/ucblib:/usr/ccs/lib:/usr/lib}} \ 	%{!R*: %{!L*: -R /usr/ucblib}} \     %{!compat-bsd: \ 	%{p:-Y P,/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \ 	%{!p:-Y P,/usr/ccs/lib:/usr/lib}}}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_PATH_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default starting address if specified.  */
end_comment

begin_define
define|#
directive|define
name|LINK_START_SPEC
value|"\ %{mads         : %(link_start_ads)         ; \   myellowknife : %(link_start_yellowknife) ; \   mmvme        : %(link_start_mvme)        ; \   msim         : %(link_start_sim)         ; \   mwindiss     : %(link_start_windiss)     ; \   mcall-freebsd: %(link_start_freebsd)     ; \   mcall-linux  : %(link_start_linux)       ; \   mcall-gnu    : %(link_start_gnu)         ; \   mcall-netbsd : %(link_start_netbsd)      ; \   mcall-openbsd: %(link_start_openbsd)     ; \                : %(link_start_default)     }"
end_define

begin_define
define|#
directive|define
name|LINK_START_DEFAULT_SPEC
value|""
end_define

begin_comment
comment|/* Override svr4.h definition.  */
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
value|"\ %{h*} %{v:-V} %{!msdata=none:%{G*}} %{msdata=none:-G0} \ %{YP,*} %{R*} \ %{Qy:} %{!Qn:-Qy} \ %(link_shlib) \ %{!Wl,-T*: %{!T*: %(link_start) }} \ %(link_target) \ %(link_os)"
end_define

begin_comment
comment|/* For now, turn off shared libraries by default.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHARED_LIB_SUPPORT
end_ifndef

begin_define
define|#
directive|define
name|NO_SHARED_LIB_SUPPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SHARED_LIB_SUPPORT
end_ifndef

begin_comment
comment|/* Shared libraries are default.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SHLIB_SPEC
value|"\ %{!static: %(link_path) %{!R*:%{L*:-R %*}}} \ %{mshlib: } \ %{static:-dn -Bstatic} \ %{shared:-G -dy -z text} \ %{symbolic:-Bsymbolic -G -dy -z text}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Shared libraries are not default.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SHLIB_SPEC
value|"\ %{mshlib: %(link_path) } \ %{!mshlib: %{!shared: %{!symbolic: -dn -Bstatic}}} \ %{static: } \ %{shared:-G -dy -z text %(link_path) } \ %{symbolic:-Bsymbolic -G -dy -z text %(link_path) }"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Override the default target of the linker.  */
end_comment

begin_define
define|#
directive|define
name|LINK_TARGET_SPEC
value|"\ %{mlittle: --oformat elf32-powerpcle } %{mlittle-endian: --oformat elf32-powerpcle } \ %{!mlittle: %{!mlittle-endian: %{!mbig: %{!mbig-endian: \     %{mcall-i960-old: --oformat elf32-powerpcle} \   }}}}"
end_define

begin_comment
comment|/* Any specific OS flags.  */
end_comment

begin_define
define|#
directive|define
name|LINK_OS_SPEC
value|"\ %{mads         : %(link_os_ads)         ; \   myellowknife : %(link_os_yellowknife) ; \   mmvme        : %(link_os_mvme)        ; \   msim         : %(link_os_sim)         ; \   mwindiss     : %(link_os_windiss)     ; \   mcall-freebsd: %(link_os_freebsd)     ; \   mcall-linux  : %(link_os_linux)       ; \   mcall-gnu    : %(link_os_gnu)         ; \   mcall-netbsd : %(link_os_netbsd)      ; \   mcall-openbsd: %(link_os_openbsd)     ; \                : %(link_os_default)     }"
end_define

begin_define
define|#
directive|define
name|LINK_OS_DEFAULT_SPEC
value|""
end_define

begin_comment
comment|/* Override rs6000.h definition.  */
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
value|"%{posix: -D_POSIX_SOURCE} \ %{mads         : %(cpp_os_ads)         ; \   myellowknife : %(cpp_os_yellowknife) ; \   mmvme        : %(cpp_os_mvme)        ; \   msim         : %(cpp_os_sim)         ; \   mwindiss     : %(cpp_os_windiss)     ; \   mcall-freebsd: %(cpp_os_freebsd)     ; \   mcall-linux  : %(cpp_os_linux)       ; \   mcall-gnu    : %(cpp_os_gnu)         ; \   mcall-netbsd : %(cpp_os_netbsd)      ; \   mcall-openbsd: %(cpp_os_openbsd)     ; \                : %(cpp_os_default)     }"
end_define

begin_define
define|#
directive|define
name|CPP_OS_DEFAULT_SPEC
value|""
end_define

begin_comment
comment|/* Override svr4.h definition.  */
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
value|"\ %{mads         : %(startfile_ads)         ; \   myellowknife : %(startfile_yellowknife) ; \   mmvme        : %(startfile_mvme)        ; \   msim         : %(startfile_sim)         ; \   mwindiss     : %(startfile_windiss)     ; \   mcall-freebsd: %(startfile_freebsd)     ; \   mcall-linux  : %(startfile_linux)       ; \   mcall-gnu    : %(startfile_gnu)         ; \   mcall-netbsd : %(startfile_netbsd)      ; \   mcall-openbsd: %(startfile_openbsd)     ; \                : %(startfile_default)     }"
end_define

begin_define
define|#
directive|define
name|STARTFILE_DEFAULT_SPEC
value|""
end_define

begin_comment
comment|/* Override svr4.h definition.  */
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
value|"\ %{mads         : %(lib_ads)         ; \   myellowknife : %(lib_yellowknife) ; \   mmvme        : %(lib_mvme)        ; \   msim         : %(lib_sim)         ; \   mwindiss     : %(lib_windiss)     ; \   mcall-freebsd: %(lib_freebsd)     ; \   mcall-linux  : %(lib_linux)       ; \   mcall-gnu    : %(lib_gnu)         ; \   mcall-netbsd : %(lib_netbsd)      ; \   mcall-openbsd: %(lib_openbsd)     ; \                : %(lib_default)     }"
end_define

begin_define
define|#
directive|define
name|LIB_DEFAULT_SPEC
value|""
end_define

begin_comment
comment|/* Override svr4.h definition.  */
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
value|"\ %{mads         : crtsavres.o%s        %(endfile_ads)         ; \   myellowknife : crtsavres.o%s        %(endfile_yellowknife) ; \   mmvme        : crtsavres.o%s        %(endfile_mvme)        ; \   msim         : crtsavres.o%s        %(endfile_sim)         ; \   mwindiss     :                      %(endfile_windiss)     ; \   mcall-freebsd: crtsavres.o%s        %(endfile_freebsd)     ; \   mcall-linux  : crtsavres.o%s        %(endfile_linux)       ; \   mcall-gnu    : crtsavres.o%s        %(endfile_gnu)         ; \   mcall-netbsd : crtsavres.o%s        %(endfile_netbsd)      ; \   mcall-openbsd: crtsavres.o%s        %(endfile_openbsd)     ; \                : %(crtsavres_default) %(endfile_default)     }"
end_define

begin_define
define|#
directive|define
name|CRTSAVRES_DEFAULT_SPEC
value|"crtsavres.o%s"
end_define

begin_define
define|#
directive|define
name|ENDFILE_DEFAULT_SPEC
value|""
end_define

begin_comment
comment|/* Motorola ADS support.  */
end_comment

begin_define
define|#
directive|define
name|LIB_ADS_SPEC
value|"--start-group -lads -lc --end-group"
end_define

begin_define
define|#
directive|define
name|STARTFILE_ADS_SPEC
value|"ecrti.o%s crt0.o%s crtbegin.o%s"
end_define

begin_define
define|#
directive|define
name|ENDFILE_ADS_SPEC
value|"crtend.o%s ecrtn.o%s"
end_define

begin_define
define|#
directive|define
name|LINK_START_ADS_SPEC
value|"-T ads.ld%s"
end_define

begin_define
define|#
directive|define
name|LINK_OS_ADS_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|CPP_OS_ADS_SPEC
value|""
end_define

begin_comment
comment|/* Motorola Yellowknife support.  */
end_comment

begin_define
define|#
directive|define
name|LIB_YELLOWKNIFE_SPEC
value|"--start-group -lyk -lc --end-group"
end_define

begin_define
define|#
directive|define
name|STARTFILE_YELLOWKNIFE_SPEC
value|"ecrti.o%s crt0.o%s crtbegin.o%s"
end_define

begin_define
define|#
directive|define
name|ENDFILE_YELLOWKNIFE_SPEC
value|"crtend.o%s ecrtn.o%s"
end_define

begin_define
define|#
directive|define
name|LINK_START_YELLOWKNIFE_SPEC
value|"-T yellowknife.ld%s"
end_define

begin_define
define|#
directive|define
name|LINK_OS_YELLOWKNIFE_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|CPP_OS_YELLOWKNIFE_SPEC
value|""
end_define

begin_comment
comment|/* Motorola MVME support.  */
end_comment

begin_define
define|#
directive|define
name|LIB_MVME_SPEC
value|"--start-group -lmvme -lc --end-group"
end_define

begin_define
define|#
directive|define
name|STARTFILE_MVME_SPEC
value|"ecrti.o%s crt0.o%s crtbegin.o%s"
end_define

begin_define
define|#
directive|define
name|ENDFILE_MVME_SPEC
value|"crtend.o%s ecrtn.o%s"
end_define

begin_define
define|#
directive|define
name|LINK_START_MVME_SPEC
value|"-Ttext 0x40000"
end_define

begin_define
define|#
directive|define
name|LINK_OS_MVME_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|CPP_OS_MVME_SPEC
value|""
end_define

begin_comment
comment|/* PowerPC simulator based on netbsd system calls support.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SIM_SPEC
value|"--start-group -lsim -lc --end-group"
end_define

begin_define
define|#
directive|define
name|STARTFILE_SIM_SPEC
value|"ecrti.o%s sim-crt0.o%s crtbegin.o%s"
end_define

begin_define
define|#
directive|define
name|ENDFILE_SIM_SPEC
value|"crtend.o%s ecrtn.o%s"
end_define

begin_define
define|#
directive|define
name|LINK_START_SIM_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|LINK_OS_SIM_SPEC
value|"-m elf32ppcsim"
end_define

begin_define
define|#
directive|define
name|CPP_OS_SIM_SPEC
value|""
end_define

begin_comment
comment|/* FreeBSD support.  */
end_comment

begin_define
define|#
directive|define
name|CPP_OS_FREEBSD_SPEC
value|"\   -D__PPC__ -D__ppc__ -D__PowerPC__ -D__powerpc__ \   -Acpu=powerpc -Amachine=powerpc"
end_define

begin_define
define|#
directive|define
name|STARTFILE_FREEBSD_SPEC
value|FBSD_STARTFILE_SPEC
end_define

begin_define
define|#
directive|define
name|ENDFILE_FREEBSD_SPEC
value|FBSD_ENDFILE_SPEC
end_define

begin_define
define|#
directive|define
name|LIB_FREEBSD_SPEC
value|FBSD_LIB_SPEC
end_define

begin_define
define|#
directive|define
name|LINK_START_FREEBSD_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|LINK_OS_FREEBSD_SPEC
value|"\   %{p:%nconsider using `-pg' instead of `-p' with gprof(1)} \   %{v:-V} \   %{assert*} %{R*} %{rpath*} %{defsym*} \   %{shared:-Bshareable %{h*} %{soname*}} \   %{!shared: \     %{!static: \       %{rdynamic: -export-dynamic} \       %{!dynamic-linker:-dynamic-linker %(fbsd_dynamic_linker) }} \     %{static:-Bstatic}} \   %{symbolic:-Bsymbolic}"
end_define

begin_comment
comment|/* GNU/Linux support.  */
end_comment

begin_define
define|#
directive|define
name|LIB_LINUX_SPEC
value|"%{mnewlib: --start-group -llinux -lc --end-group } \ %{!mnewlib: %{pthread:-lpthread} %{shared:-lc} \ %{!shared: %{profile:-lc_p} %{!profile:-lc}}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LD_PIE
end_ifdef

begin_define
define|#
directive|define
name|STARTFILE_LINUX_SPEC
value|"\ %{!shared: %{pg|p|profile:gcrt1.o%s;pie:Scrt1.o%s;:crt1.o%s}} \ %{mnewlib:ecrti.o%s;:crti.o%s} \ %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STARTFILE_LINUX_SPEC
value|"\ %{!shared: %{pg|p|profile:gcrt1.o%s;:crt1.o%s}} \ %{mnewlib:ecrti.o%s;:crti.o%s} \ %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ENDFILE_LINUX_SPEC
value|"\ %{shared|pie:crtendS.o%s;:crtend.o%s} \ %{mnewlib:ecrtn.o%s;:crtn.o%s}"
end_define

begin_define
define|#
directive|define
name|LINK_START_LINUX_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER
value|"/lib/ld.so.1"
end_define

begin_define
define|#
directive|define
name|UCLIBC_DYNAMIC_LINKER
value|"/lib/ld-uClibc.so.0"
end_define

begin_if
if|#
directive|if
name|UCLIBC_DEFAULT
end_if

begin_define
define|#
directive|define
name|CHOOSE_DYNAMIC_LINKER
parameter_list|(
name|G
parameter_list|,
name|U
parameter_list|)
value|"%{mglibc:%{muclibc:%e-mglibc and -muclibc used together}" G ";:" U "}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHOOSE_DYNAMIC_LINKER
parameter_list|(
name|G
parameter_list|,
name|U
parameter_list|)
value|"%{muclibc:%{mglibc:%e-mglibc and -muclibc used together}" U ";:" G "}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINUX_DYNAMIC_LINKER
define|\
value|CHOOSE_DYNAMIC_LINKER (GLIBC_DYNAMIC_LINKER, UCLIBC_DYNAMIC_LINKER)
end_define

begin_define
define|#
directive|define
name|LINK_OS_LINUX_SPEC
value|"-m elf32ppclinux %{!shared: %{!static: \   %{rdynamic:-export-dynamic} \   %{!dynamic-linker:-dynamic-linker " LINUX_DYNAMIC_LINKER "}}}"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_LD_EH_FRAME_HDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|LINK_EH_SPEC
value|"%{!static:--eh-frame-hdr} "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPP_OS_LINUX_SPEC
value|"-D__unix__ -D__gnu_linux__ -D__linux__ \ %{!undef:							  \   %{!ansi:							  \     %{!std=*:-Dunix -D__unix -Dlinux -D__linux}			  \     %{std=gnu*:-Dunix -D__unix -Dlinux -D__linux}}}		  \ -Asystem=linux -Asystem=unix -Asystem=posix %{pthread:-D_REENTRANT}"
end_define

begin_comment
comment|/* GNU/Hurd support.  */
end_comment

begin_define
define|#
directive|define
name|LIB_GNU_SPEC
value|"%{mnewlib: --start-group -lgnu -lc --end-group } \ %{!mnewlib: %{shared:-lc} %{!shared: %{pthread:-lpthread } \ %{profile:-lc_p} %{!profile:-lc}}}"
end_define

begin_define
define|#
directive|define
name|STARTFILE_GNU_SPEC
value|"\ %{!shared: %{!static: %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}}} \ %{static: %{pg:gcrt0.o%s} %{!pg:%{p:gcrt0.o%s} %{!p:crt0.o%s}}} \ %{mnewlib: ecrti.o%s} %{!mnewlib: crti.o%s} \ %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_define
define|#
directive|define
name|ENDFILE_GNU_SPEC
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} \ %{mnewlib: ecrtn.o%s} %{!mnewlib: crtn.o%s}"
end_define

begin_define
define|#
directive|define
name|LINK_START_GNU_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|LINK_OS_GNU_SPEC
value|"-m elf32ppclinux %{!shared: %{!static: \   %{rdynamic:-export-dynamic} \   %{!dynamic-linker:-dynamic-linker /lib/ld.so.1}}}"
end_define

begin_define
define|#
directive|define
name|CPP_OS_GNU_SPEC
value|"-D__unix__ -D__gnu_hurd__ -D__GNU__	\ %{!undef:					                \   %{!ansi: -Dunix -D__unix}}			                \ -Asystem=gnu -Asystem=unix -Asystem=posix %{pthread:-D_REENTRANT}"
end_define

begin_comment
comment|/* NetBSD support.  */
end_comment

begin_define
define|#
directive|define
name|LIB_NETBSD_SPEC
value|"\ %{profile:-lgmon -lc_p} %{!profile:-lc}"
end_define

begin_define
define|#
directive|define
name|STARTFILE_NETBSD_SPEC
value|"\ ncrti.o%s crt0.o%s \ %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_define
define|#
directive|define
name|ENDFILE_NETBSD_SPEC
value|"\ %{!shared:crtend.o%s} %{shared:crtendS.o%s} \ ncrtn.o%s"
end_define

begin_define
define|#
directive|define
name|LINK_START_NETBSD_SPEC
value|"\ "
end_define

begin_define
define|#
directive|define
name|LINK_OS_NETBSD_SPEC
value|"\ %{!shared: %{!static: \   %{rdynamic:-export-dynamic} \   %{!dynamic-linker:-dynamic-linker /usr/libexec/ld.elf_so}}}"
end_define

begin_define
define|#
directive|define
name|CPP_OS_NETBSD_SPEC
value|"\ -D__powerpc__ -D__NetBSD__ -D__KPRINTF_ATTRIBUTE__"
end_define

begin_comment
comment|/* OpenBSD support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_OPENBSD_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LIB_OPENBSD_SPEC
value|"%{!shared:%{pthread:-lpthread%{p:_p}%{!p:%{pg:_p}}}} %{!shared:-lc%{p:_p}%{!p:%{pg:_p}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STARTFILE_OPENBSD_SPEC
end_ifndef

begin_define
define|#
directive|define
name|STARTFILE_OPENBSD_SPEC
value|"\ %{!shared: %{pg:gcrt0.o%s} %{!pg:%{p:gcrt0.o%s} %{!p:crt0.o%s}}} \ %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENDFILE_OPENBSD_SPEC
end_ifndef

begin_define
define|#
directive|define
name|ENDFILE_OPENBSD_SPEC
value|"\ %{!shared:crtend.o%s} %{shared:crtendS.o%s}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_START_OPENBSD_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_START_OPENBSD_SPEC
value|"-Ttext 0x400074"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_OS_OPENBSD_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_OS_OPENBSD_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_OS_OPENBSD_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPP_OS_OPENBSD_SPEC
value|"%{posix:-D_POSIX_SOURCE} %{pthread:-D_POSIX_THREADS}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WindISS support.  */
end_comment

begin_define
define|#
directive|define
name|LIB_WINDISS_SPEC
value|"--start-group -li -lcfp -lwindiss -lram -limpl -limpfp --end-group"
end_define

begin_define
define|#
directive|define
name|CPP_OS_WINDISS_SPEC
value|"\ -D__rtasim \ -D__EABI__ \ -D__ppc \ %{!msoft-float: -D__hardfp} \ "
end_define

begin_define
define|#
directive|define
name|STARTFILE_WINDISS_SPEC
value|"crt0.o%s crtbegin.o%s"
end_define

begin_define
define|#
directive|define
name|ENDFILE_WINDISS_SPEC
value|"crtend.o%s"
end_define

begin_define
define|#
directive|define
name|LINK_START_WINDISS_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|LINK_OS_WINDISS_SPEC
value|""
end_define

begin_comment
comment|/* Define any extra SPECS that the compiler needs to generate.  */
end_comment

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "crtsavres_default",	CRTSAVRES_DEFAULT_SPEC },		\   { "lib_ads",			LIB_ADS_SPEC },				\   { "lib_yellowknife",		LIB_YELLOWKNIFE_SPEC },			\   { "lib_mvme",			LIB_MVME_SPEC },			\   { "lib_sim",			LIB_SIM_SPEC },				\   { "lib_freebsd",		LIB_FREEBSD_SPEC },			\   { "lib_gnu",			LIB_GNU_SPEC },				\   { "lib_linux",		LIB_LINUX_SPEC },			\   { "lib_netbsd",		LIB_NETBSD_SPEC },			\   { "lib_openbsd",		LIB_OPENBSD_SPEC },			\   { "lib_windiss",		LIB_WINDISS_SPEC },			\   { "lib_default",		LIB_DEFAULT_SPEC },			\   { "startfile_ads",		STARTFILE_ADS_SPEC },			\   { "startfile_yellowknife",	STARTFILE_YELLOWKNIFE_SPEC },		\   { "startfile_mvme",		STARTFILE_MVME_SPEC },			\   { "startfile_sim",		STARTFILE_SIM_SPEC },			\   { "startfile_freebsd",	STARTFILE_FREEBSD_SPEC },		\   { "startfile_gnu",		STARTFILE_GNU_SPEC },			\   { "startfile_linux",		STARTFILE_LINUX_SPEC },			\   { "startfile_netbsd",		STARTFILE_NETBSD_SPEC },		\   { "startfile_openbsd",	STARTFILE_OPENBSD_SPEC },		\   { "startfile_windiss",	STARTFILE_WINDISS_SPEC },		\   { "startfile_default",	STARTFILE_DEFAULT_SPEC },		\   { "endfile_ads",		ENDFILE_ADS_SPEC },			\   { "endfile_yellowknife",	ENDFILE_YELLOWKNIFE_SPEC },		\   { "endfile_mvme",		ENDFILE_MVME_SPEC },			\   { "endfile_sim",		ENDFILE_SIM_SPEC },			\   { "endfile_freebsd",		ENDFILE_FREEBSD_SPEC },			\   { "endfile_gnu",		ENDFILE_GNU_SPEC },			\   { "endfile_linux",		ENDFILE_LINUX_SPEC },			\   { "endfile_netbsd",		ENDFILE_NETBSD_SPEC },			\   { "endfile_openbsd",		ENDFILE_OPENBSD_SPEC },			\   { "endfile_windiss",		ENDFILE_WINDISS_SPEC },			\   { "endfile_default",		ENDFILE_DEFAULT_SPEC },			\   { "link_path",		LINK_PATH_SPEC },			\   { "link_shlib",		LINK_SHLIB_SPEC },			\   { "link_target",		LINK_TARGET_SPEC },			\   { "link_start",		LINK_START_SPEC },			\   { "link_start_ads",		LINK_START_ADS_SPEC },			\   { "link_start_yellowknife",	LINK_START_YELLOWKNIFE_SPEC },		\   { "link_start_mvme",		LINK_START_MVME_SPEC },			\   { "link_start_sim",		LINK_START_SIM_SPEC },			\   { "link_start_freebsd",	LINK_START_FREEBSD_SPEC },		\   { "link_start_gnu",		LINK_START_GNU_SPEC },			\   { "link_start_linux",		LINK_START_LINUX_SPEC },		\   { "link_start_netbsd",	LINK_START_NETBSD_SPEC },		\   { "link_start_openbsd",	LINK_START_OPENBSD_SPEC },		\   { "link_start_windiss",	LINK_START_WINDISS_SPEC },		\   { "link_start_default",	LINK_START_DEFAULT_SPEC },		\   { "link_os",			LINK_OS_SPEC },				\   { "link_os_ads",		LINK_OS_ADS_SPEC },			\   { "link_os_yellowknife",	LINK_OS_YELLOWKNIFE_SPEC },		\   { "link_os_mvme",		LINK_OS_MVME_SPEC },			\   { "link_os_sim",		LINK_OS_SIM_SPEC },			\   { "link_os_freebsd",		LINK_OS_FREEBSD_SPEC },			\   { "link_os_linux",		LINK_OS_LINUX_SPEC },			\   { "link_os_gnu",		LINK_OS_GNU_SPEC },			\   { "link_os_netbsd",		LINK_OS_NETBSD_SPEC },			\   { "link_os_openbsd",		LINK_OS_OPENBSD_SPEC },			\   { "link_os_windiss",		LINK_OS_WINDISS_SPEC },			\   { "link_os_default",		LINK_OS_DEFAULT_SPEC },			\   { "cc1_endian_big",		CC1_ENDIAN_BIG_SPEC },			\   { "cc1_endian_little",	CC1_ENDIAN_LITTLE_SPEC },		\   { "cc1_endian_default",	CC1_ENDIAN_DEFAULT_SPEC },		\   { "cc1_secure_plt_default",	CC1_SECURE_PLT_DEFAULT_SPEC },		\   { "cpp_os_ads",		CPP_OS_ADS_SPEC },			\   { "cpp_os_yellowknife",	CPP_OS_YELLOWKNIFE_SPEC },		\   { "cpp_os_mvme",		CPP_OS_MVME_SPEC },			\   { "cpp_os_sim",		CPP_OS_SIM_SPEC },			\   { "cpp_os_freebsd",		CPP_OS_FREEBSD_SPEC },			\   { "cpp_os_gnu",		CPP_OS_GNU_SPEC },			\   { "cpp_os_linux",		CPP_OS_LINUX_SPEC },			\   { "cpp_os_netbsd",		CPP_OS_NETBSD_SPEC },			\   { "cpp_os_openbsd",		CPP_OS_OPENBSD_SPEC },			\   { "cpp_os_windiss",		CPP_OS_WINDISS_SPEC },			\   { "cpp_os_default",		CPP_OS_DEFAULT_SPEC },			\   { "fbsd_dynamic_linker",	FBSD_DYNAMIC_LINKER },			\   SUBSUBTARGET_EXTRA_SPECS
end_define

begin_define
define|#
directive|define
name|SUBSUBTARGET_EXTRA_SPECS
end_define

begin_comment
comment|/* Define this macro as a C expression for the initializer of an    array of string to tell the driver program which options are    defaults for this target and thus do not need to be handled    specially when using `MULTILIB_OPTIONS'.     Do not define this macro if `MULTILIB_OPTIONS' is not defined in    the target makefile fragment or if none of the options listed in    `MULTILIB_OPTIONS' are set by default.  *Note Target Fragment::.  */
end_comment

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "mbig", "mcall-sysv" }
end_define

begin_comment
comment|/* Define this macro if the code for function profiling should come    before the function prologue.  Normally, the profiling code comes    after.  */
end_comment

begin_define
define|#
directive|define
name|PROFILE_BEFORE_PROLOGUE
value|1
end_define

begin_comment
comment|/* Function name to call to do profiling.  */
end_comment

begin_define
define|#
directive|define
name|RS6000_MCOUNT
value|"_mcount"
end_define

begin_comment
comment|/* Define this macro (to a value of 1) if you want to support the    Win32 style pragmas #pragma pack(push,<n>)' and #pragma    pack(pop)'.  The pack(push,<n>) pragma specifies the maximum    alignment (in bytes) of fields within a structure, in much the    same way as the __aligned__' and __packed__' __attribute__'s    do.  A pack value of zero resets the behavior to the default.    Successive invocations of this pragma cause the previous values to    be stacked, so that invocations of #pragma pack(pop)' will return    to the previous value.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK_PUSH_POP
value|1
end_define

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  CODE    is 0 for data, 1 for code labels, 2 for function pointers.  GLOBAL is    true if the symbol may be affected by dynamic relocations.  */
end_comment

begin_define
define|#
directive|define
name|ASM_PREFERRED_EH_DATA_FORMAT
parameter_list|(
name|CODE
parameter_list|,
name|GLOBAL
parameter_list|)
define|\
value|((flag_pic || TARGET_RELOCATABLE)					     \    ? (((GLOBAL) ? DW_EH_PE_indirect : 0) | DW_EH_PE_pcrel | DW_EH_PE_sdata4) \    : DW_EH_PE_absptr)
end_define

begin_define
define|#
directive|define
name|DOUBLE_INT_ASM_OP
value|"\t.quad\t"
end_define

begin_comment
comment|/* Generate entries in .fixup for relocatable addresses.  */
end_comment

begin_define
define|#
directive|define
name|RELOCATABLE_NEEDS_FIXUP
value|1
end_define

begin_comment
comment|/* This target uses the sysv4.opt file.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_USES_SYSV4_OPT
value|1
end_define

end_unit

