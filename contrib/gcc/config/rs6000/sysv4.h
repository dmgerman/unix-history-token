begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for PowerPC running System V.4    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.    Contributed by Cygnus Support.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
comment|/* Override rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_DEFAULT_SPEC
value|"-D_ARCH_PPC"
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

begin_comment
comment|/* V.4/eabi switches.  */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_BITFIELD_TYPE
value|0x40000000
end_define

begin_comment
comment|/* Set PCC_BITFIELD_TYPE_MATTERS to 0.  */
end_comment

begin_define
define|#
directive|define
name|MASK_STRICT_ALIGN
value|0x20000000
end_define

begin_comment
comment|/* Set STRICT_ALIGNMENT to 1.  */
end_comment

begin_define
define|#
directive|define
name|MASK_RELOCATABLE
value|0x10000000
end_define

begin_comment
comment|/* GOT pointers are PC relative.  */
end_comment

begin_define
define|#
directive|define
name|MASK_EABI
value|0x08000000
end_define

begin_comment
comment|/* Adhere to eabi, not System V spec.  */
end_comment

begin_define
define|#
directive|define
name|MASK_LITTLE_ENDIAN
value|0x04000000
end_define

begin_comment
comment|/* Target is little endian.  */
end_comment

begin_define
define|#
directive|define
name|MASK_REGNAMES
value|0x02000000
end_define

begin_comment
comment|/* Use alternate register names.  */
end_comment

begin_define
define|#
directive|define
name|MASK_PROTOTYPE
value|0x01000000
end_define

begin_comment
comment|/* Only prototyped fcns pass variable args.  */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_BITFIELD_WORD
value|0x00800000
end_define

begin_comment
comment|/* Bitfields cannot cross word boundaries */
end_comment

begin_define
define|#
directive|define
name|TARGET_NO_BITFIELD_TYPE
value|(target_flags& MASK_NO_BITFIELD_TYPE)
end_define

begin_define
define|#
directive|define
name|TARGET_STRICT_ALIGN
value|(target_flags& MASK_STRICT_ALIGN)
end_define

begin_define
define|#
directive|define
name|TARGET_RELOCATABLE
value|(target_flags& MASK_RELOCATABLE)
end_define

begin_define
define|#
directive|define
name|TARGET_EABI
value|(target_flags& MASK_EABI)
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_ENDIAN
value|(target_flags& MASK_LITTLE_ENDIAN)
end_define

begin_define
define|#
directive|define
name|TARGET_REGNAMES
value|(target_flags& MASK_REGNAMES)
end_define

begin_define
define|#
directive|define
name|TARGET_PROTOTYPE
value|(target_flags& MASK_PROTOTYPE)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_BITFIELD_WORD
value|(target_flags& MASK_NO_BITFIELD_WORD)
end_define

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

begin_comment
comment|/* Strings provided by SUBTARGET_OPTIONS */
end_comment

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

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_OPTIONS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_OPTIONS
define|\
value|{ "call-",&rs6000_abi_name, N_("Select ABI calling convention") },	\   { "sdata=",&rs6000_sdata_name, N_("Select method for sdata handling") }
end_define

begin_comment
comment|/* Max # of bytes for variables to automatically be put into the .sdata    or .sdata2 sections.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g_switch_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Value of the -G xx switch.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g_switch_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether -G xx was passed.  */
end_comment

begin_define
define|#
directive|define
name|SDATA_DEFAULT_SIZE
value|8
end_define

begin_comment
comment|/* Note, V.4 no longer uses a normal TOC, so make -mfull-toc, be just    the same as -mminimal-toc.  */
end_comment

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

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
value|{ "bit-align",	-MASK_NO_BITFIELD_TYPE,				\     N_("Align to the base type of the bit-field") },			\   { "no-bit-align",	 MASK_NO_BITFIELD_TYPE,				\     N_("Don't align to the base type of the bit-field") },		\   { "strict-align",	 MASK_STRICT_ALIGN,				\     N_("Don't assume that unaligned accesses are handled by the system") }, \   { "no-strict-align",	-MASK_STRICT_ALIGN,				\     N_("Assume that unaligned accesses are handled by the system") },	\   { "relocatable",	 MASK_RELOCATABLE | MASK_MINIMAL_TOC | MASK_NO_FP_IN_TOC, \     N_("Produce code relocatable at runtime") },			\   { "no-relocatable",	-MASK_RELOCATABLE,				\     N_("Don't produce code relocatable at runtime") },			\   { "relocatable-lib",	 MASK_RELOCATABLE | MASK_MINIMAL_TOC | MASK_NO_FP_IN_TOC, \     N_("Produce code relocatable at runtime") },			\   { "no-relocatable-lib", -MASK_RELOCATABLE,				\     N_("Don't produce code relocatable at runtime") },			\   { "little-endian",	 MASK_LITTLE_ENDIAN,				\     N_("Produce little endian code") },					\   { "little",		 MASK_LITTLE_ENDIAN,				\     N_("Produce little endian code") },					\   { "big-endian",	-MASK_LITTLE_ENDIAN,				\     N_("Produce big endian code") },					\   { "big",		-MASK_LITTLE_ENDIAN,				\     N_("Produce big endian code") },					\   { "no-toc",		 0, N_("no description yet") },			\   { "toc",		 MASK_MINIMAL_TOC, N_("no description yet") },	\   { "full-toc",		 MASK_MINIMAL_TOC, N_("no description yet") },	\   { "prototype",	 MASK_PROTOTYPE, N_("no description yet") },	\   { "no-prototype",	-MASK_PROTOTYPE, N_("no description yet") },	\   { "no-traceback",	 0, N_("no description yet") },			\   { "eabi",		 MASK_EABI, N_("Use EABI") },			\   { "no-eabi",		-MASK_EABI, N_("Don't use EABI") },		\   { "bit-word",		-MASK_NO_BITFIELD_WORD, "" },			\   { "no-bit-word",	 MASK_NO_BITFIELD_WORD,				\     N_("Do not allow bit-fields to cross word boundaries") },		\   { "regnames",		  MASK_REGNAMES,				\     N_("Use alternate register names") },				\   { "no-regnames",	 -MASK_REGNAMES,				\     N_("Don't use alternate register names") },				\   { "sdata",		 0, N_("no description yet") },			\   { "no-sdata",		 0, N_("no description yet") },			\   { "sim",		 0,						\     N_("Link with libsim.a, libc.a and sim-crt0.o") },			\   { "ads",		 0,						\     N_("Link with libads.a, libc.a and crt0.o") },			\   { "yellowknife",	 0,						\     N_("Link with libyk.a, libc.a and crt0.o") },			\   { "mvme",		 0,						\     N_("Link with libmvme.a, libc.a and crt0.o") },			\   { "emb",		 0,						\     N_("Set the PPC_EMB bit in the ELF flags header") },		\   { "vxworks",		 0, N_("no description yet") },			\   { "shlib",		 0, N_("no description yet") },			\   EXTRA_SUBTARGET_SWITCHES						\   { "newlib",		 0, N_("no description yet") },
end_define

begin_comment
comment|/* This is meant to be redefined in the host dependent files.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SUBTARGET_SWITCHES
end_define

begin_comment
comment|/* Sometimes certain combinations of command options do not make sense    on a particular target machine.  You can define a macro    `OVERRIDE_OPTIONS' to take account of this.  This macro, if    defined, is executed once just after all the command options have    been parsed.     The macro SUBTARGET_OVERRIDE_OPTIONS is provided for subtargets, to    get control.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|do {									\   if (!g_switch_set)							\     g_switch_value = SDATA_DEFAULT_SIZE;				\ 									\   if (!strcmp (rs6000_abi_name, "sysv"))				\     rs6000_current_abi = ABI_V4;					\   else if (!strcmp (rs6000_abi_name, "sysv-noeabi"))			\     {									\       rs6000_current_abi = ABI_V4;					\       target_flags&= ~ MASK_EABI;					\     }									\   else if (!strcmp (rs6000_abi_name, "sysv-eabi")			\ 	   || !strcmp (rs6000_abi_name, "eabi"))			\     {									\       rs6000_current_abi = ABI_V4;					\       target_flags |= MASK_EABI;					\     }									\   else if (!strcmp (rs6000_abi_name, "aix"))				\     {									\       rs6000_current_abi = ABI_AIX_NODESC;				\       target_flags |= MASK_EABI;					\     }									\   else if (!strcmp (rs6000_abi_name, "aixdesc"))			\     rs6000_current_abi = ABI_AIX;					\   else if (!strcmp (rs6000_abi_name, "freebsd"))			\     rs6000_current_abi = ABI_V4;					\   else if (!strcmp (rs6000_abi_name, "linux"))				\     rs6000_current_abi = ABI_V4;					\   else if (!strcmp (rs6000_abi_name, "netbsd"))				\     rs6000_current_abi = ABI_V4;					\   else if (!strcmp (rs6000_abi_name, "i960-old"))			\     {									\       rs6000_current_abi = ABI_V4;					\       target_flags |= (MASK_LITTLE_ENDIAN | MASK_EABI			\ 		       | MASK_NO_BITFIELD_WORD);			\       target_flags&= ~MASK_STRICT_ALIGN;				\     }									\   else									\     {									\       rs6000_current_abi = ABI_V4;					\       error ("bad value for -mcall-%s", rs6000_abi_name);		\     }									\ 									\   if (rs6000_sdata_name)						\     {									\       if (!strcmp (rs6000_sdata_name, "none"))				\ 	rs6000_sdata = SDATA_NONE;					\       else if (!strcmp (rs6000_sdata_name, "data"))			\ 	rs6000_sdata = SDATA_DATA;					\       else if (!strcmp (rs6000_sdata_name, "default"))			\ 	rs6000_sdata = (TARGET_EABI) ? SDATA_EABI : SDATA_SYSV;		\       else if (!strcmp (rs6000_sdata_name, "sysv"))			\ 	rs6000_sdata = SDATA_SYSV;					\       else if (!strcmp (rs6000_sdata_name, "eabi"))			\ 	rs6000_sdata = SDATA_EABI;					\       else								\ 	error ("bad value for -msdata=%s", rs6000_sdata_name);		\     }									\   else if (DEFAULT_ABI == ABI_V4)					\     {									\       rs6000_sdata = SDATA_DATA;					\       rs6000_sdata_name = "data";					\     }									\   else									\     {									\       rs6000_sdata = SDATA_NONE;					\       rs6000_sdata_name = "none";					\     }									\ 									\   if (TARGET_RELOCATABLE&&						\       (rs6000_sdata == SDATA_EABI || rs6000_sdata == SDATA_SYSV))	\     {									\       rs6000_sdata = SDATA_DATA;					\       error ("-mrelocatable and -msdata=%s are incompatible",		\ 	     rs6000_sdata_name);					\     }									\ 									\   else if (flag_pic&&							\ 	   (rs6000_sdata == SDATA_EABI || rs6000_sdata == SDATA_SYSV))	\     {									\       rs6000_sdata = SDATA_DATA;					\       error ("-f%s and -msdata=%s are incompatible",			\ 	     (flag_pic> 1) ? "PIC" : "pic",				\ 	     rs6000_sdata_name);					\     }									\ 									\   if (rs6000_sdata != SDATA_NONE&& DEFAULT_ABI != ABI_V4)		\     {									\       rs6000_sdata = SDATA_NONE;					\       error ("-msdata=%s and -mcall-%s are incompatible",		\ 	     rs6000_sdata_name, rs6000_abi_name);			\     }									\ 									\   if (TARGET_RELOCATABLE&& !TARGET_MINIMAL_TOC)			\     {									\       target_flags |= MASK_MINIMAL_TOC;					\       error ("-mrelocatable and -mno-minimal-toc are incompatible");	\     }									\ 									\   if (TARGET_RELOCATABLE&& rs6000_current_abi == ABI_AIX)		\     {									\       target_flags&= ~MASK_RELOCATABLE;				\       error ("-mrelocatable and -mcall-%s are incompatible",		\ 	     rs6000_abi_name);						\     }									\ 									\   if (flag_pic> 1&& rs6000_current_abi == ABI_AIX)			\     {									\       flag_pic = 0;							\       error ("-fPIC and -mcall-%s are incompatible",			\ 	     rs6000_abi_name);						\     }									\ 									\   if (rs6000_current_abi == ABI_AIX&& TARGET_LITTLE_ENDIAN)		\     {									\       target_flags&= ~MASK_LITTLE_ENDIAN;				\       error ("-mcall-aixdesc must be big endian");			\     }									\ 									\
comment|/* Treat -fPIC the same as -mrelocatable.  */
value|\   if (flag_pic> 1)							\     target_flags |= MASK_RELOCATABLE | MASK_MINIMAL_TOC | MASK_NO_FP_IN_TOC; \ 									\   else if (TARGET_RELOCATABLE)						\     flag_pic = 2;							\ 									\ } while (0)
end_define

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
comment|/* Size of the V.4 varargs area if needed.  */
end_comment

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|RS6000_VARARGS_AREA
end_undef

begin_define
define|#
directive|define
name|RS6000_VARARGS_AREA
value|((cfun->machine->sysv_varargs_p) ? RS6000_VARARGS_SIZE : 0)
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
name|_LITTLE_ENDIAN
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
comment|/* Alignment in bits of the stack boundary.  Note, in order to allow building    one set of libraries with -mno-eabi instead of eabi libraries and non-eabi    versions, just use 64 as the stack boundary.  */
end_comment

begin_undef
undef|#
directive|undef
name|STACK_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|(TARGET_ALTIVEC_ABI ? 128 : 64)
end_define

begin_comment
comment|/* Real stack boundary as mandated by the appropriate ABI.  */
end_comment

begin_define
define|#
directive|define
name|ABI_STACK_BOUNDARY
value|((TARGET_EABI&& !TARGET_ALTIVEC_ABI) ? 64 : 128)
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_undef
undef|#
directive|undef
name|BIGGEST_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|(TARGET_EABI ? 64 : 128)
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

begin_comment
comment|/* Define this macro as an expression for the alignment of a type    (given by TYPE as a tree node) if the alignment computed in the    usual way is COMPUTED and the alignment explicitly specified was    SPECIFIED.  */
end_comment

begin_define
define|#
directive|define
name|ROUND_TYPE_ALIGN
parameter_list|(
name|TYPE
parameter_list|,
name|COMPUTED
parameter_list|,
name|SPECIFIED
parameter_list|)
define|\
value|((TARGET_ALTIVEC&& TREE_CODE (TYPE) == VECTOR_TYPE)	        \ 	 ? 128 : MAX (COMPUTED, SPECIFIED))
end_define

begin_undef
undef|#
directive|undef
name|BIGGEST_FIELD_ALIGNMENT
end_undef

begin_undef
undef|#
directive|undef
name|ADJUST_FIELD_ALIGN
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
value|((TARGET_RELOCATABLE || flag_pic) ? "\t.section\t\".got2\",\"aw\"" : "\t.section\t\".got1\",\"aw\"")
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
comment|/* Besides the usual ELF sections, we need a toc section.  */
end_comment

begin_comment
comment|/* Override elfos.h definition.  */
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
value|in_const, in_toc, in_sdata, in_sdata2, in_sbss, in_init, in_fini
end_define

begin_comment
comment|/* Override elfos.h definition.  */
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
value|CONST_SECTION_FUNCTION						\   TOC_SECTION_FUNCTION							\   SDATA_SECTION_FUNCTION						\   SDATA2_SECTION_FUNCTION						\   SBSS_SECTION_FUNCTION							\   INIT_SECTION_FUNCTION							\   FINI_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|TOC_SECTION_FUNCTION
define|\
value|void									\ toc_section ()								\ {									\   if (in_section != in_toc)						\     {									\       in_section = in_toc;						\       if (DEFAULT_ABI == ABI_AIX					\&& TARGET_MINIMAL_TOC						\&& !TARGET_RELOCATABLE)					\ 	{								\ 	  if (! toc_initialized)					\ 	    {								\ 	      toc_initialized = 1;					\ 	      fprintf (asm_out_file, "%s\n", TOC_SECTION_ASM_OP);	\ 	      ASM_OUTPUT_INTERNAL_LABEL (asm_out_file, "LCTOC", 0);	\ 	      fprintf (asm_out_file, "\t.tc ");				\ 	      ASM_OUTPUT_INTERNAL_LABEL_PREFIX (asm_out_file, "LCTOC1[TC],"); \ 	      ASM_OUTPUT_INTERNAL_LABEL_PREFIX (asm_out_file, "LCTOC1"); \ 	      fprintf (asm_out_file, "\n");				\ 									\ 	      fprintf (asm_out_file, "%s\n", MINIMAL_TOC_SECTION_ASM_OP); \ 	      ASM_OUTPUT_INTERNAL_LABEL_PREFIX (asm_out_file, "LCTOC1"); \ 	      fprintf (asm_out_file, " = .+32768\n");			\ 	    }								\ 	  else								\ 	    fprintf (asm_out_file, "%s\n", MINIMAL_TOC_SECTION_ASM_OP);	\ 	}								\       else if (DEFAULT_ABI == ABI_AIX&& !TARGET_RELOCATABLE)		\ 	fprintf (asm_out_file, "%s\n", TOC_SECTION_ASM_OP);		\       else								\ 	{								\ 	  fprintf (asm_out_file, "%s\n", MINIMAL_TOC_SECTION_ASM_OP);	\ 	  if (! toc_initialized)					\ 	    {								\ 	      ASM_OUTPUT_INTERNAL_LABEL_PREFIX (asm_out_file, "LCTOC1"); \ 	      fprintf (asm_out_file, " = .+32768\n");			\ 	      toc_initialized = 1;					\ 	    }								\ 	}								\     }									\ }									\ 									\ extern int in_toc_section PARAMS ((void));				\ int in_toc_section ()							\ {									\   return in_section == in_toc;						\ }
end_define

begin_define
define|#
directive|define
name|SDATA_SECTION_FUNCTION
define|\
value|void									\ sdata_section ()							\ {									\   if (in_section != in_sdata)						\     {									\       in_section = in_sdata;						\       fprintf (asm_out_file, "%s\n", SDATA_SECTION_ASM_OP);		\     }									\ }
end_define

begin_define
define|#
directive|define
name|SDATA2_SECTION_FUNCTION
define|\
value|void									\ sdata2_section ()							\ {									\   if (in_section != in_sdata2)						\     {									\       in_section = in_sdata2;						\       fprintf (asm_out_file, "%s\n", SDATA2_SECTION_ASM_OP);		\     }									\ }
end_define

begin_define
define|#
directive|define
name|SBSS_SECTION_FUNCTION
define|\
value|void									\ sbss_section ()								\ {									\   if (in_section != in_sbss)						\     {									\       in_section = in_sbss;						\       fprintf (asm_out_file, "%s\n", SBSS_SECTION_ASM_OP);		\     }									\ }
end_define

begin_define
define|#
directive|define
name|INIT_SECTION_FUNCTION
define|\
value|void									\ init_section ()								\ {									\   if (in_section != in_init)						\     {									\       in_section = in_init;						\       fprintf (asm_out_file, "%s\n", INIT_SECTION_ASM_OP);		\     }									\ }
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_FUNCTION
define|\
value|void									\ fini_section ()								\ {									\   if (in_section != in_fini)						\     {									\       in_section = in_fini;						\       fprintf (asm_out_file, "%s\n", FINI_SECTION_ASM_OP);		\     }									\ }
end_define

begin_comment
comment|/* A C statement or statements to switch to the appropriate section    for output of RTX in mode MODE.  You can assume that RTX is some    kind of constant in RTL.  The argument MODE is redundant except in    the case of a `const_int' rtx.  Select the section by calling    `text_section' or one of the alternatives for other sections.     Do not define this macro if you put all constants in the read-only    data section.  */
end_comment

begin_comment
comment|/* Override elfos.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|ALIGN
parameter_list|)
value|rs6000_select_rtx_section (MODE, X)
end_define

begin_comment
comment|/* A C statement or statements to switch to the appropriate    section for output of DECL.  DECL is either a `VAR_DECL' node    or a constant of some sort.  RELOC indicates whether forming    the initial value of DECL requires link-time relocations.  */
end_comment

begin_comment
comment|/* Override elfos.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|SELECT_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|,
name|ALIGN
parameter_list|)
value|rs6000_select_section (DECL, RELOC)
end_define

begin_comment
comment|/* A C statement to build up a unique section name, expressed as a    STRING_CST node, and assign it to DECL_SECTION_NAME (decl).    RELOC indicates whether the initial value of EXP requires    link-time relocations.  If you do not define this macro, GCC will use    the symbol name prefixed by `.' as the section name.  Note - this    macro can now be called for uninitialized data items as well as    initialised data and functions.  */
end_comment

begin_comment
comment|/* Override elfos.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|UNIQUE_SECTION
end_undef

begin_define
define|#
directive|define
name|UNIQUE_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
value|rs6000_unique_section (DECL, RELOC)
end_define

begin_comment
comment|/* Return non-zero if this entry is to be written into the constant pool    in a special way.  We do so if this is a SYMBOL_REF, LABEL_REF or a CONST    containing one of them.  If -mfp-in-toc (the default), we also do    this for floating-point constants.  We actually can only do this    if the FP formats of the target and host machines are the same, but    we can't check that since not every file that uses    GO_IF_LEGITIMATE_ADDRESS_P includes real.h.     Unlike AIX, we don't key off of -mminimal-toc, but instead do not    allow floating point constants in the TOC if -mrelocatable.  */
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
value|(TARGET_TOC								\&& (GET_CODE (X) == SYMBOL_REF					\        || (GET_CODE (X) == CONST&& GET_CODE (XEXP (X, 0)) == PLUS	\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == SYMBOL_REF)		\        || GET_CODE (X) == LABEL_REF					\        || (GET_CODE (X) == CONST_INT 					\&& GET_MODE_BITSIZE (MODE)<= GET_MODE_BITSIZE (Pmode))	\        || (!TARGET_NO_FP_IN_TOC						\&& !TARGET_RELOCATABLE					\&& GET_CODE (X) == CONST_DOUBLE				\&& GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT		\&& BITS_PER_WORD == HOST_BITS_PER_INT)))
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
value|do {									\     const char *const init_ptr = (TARGET_64BIT) ? ".quad" : ".long";	\ 									\     if (TARGET_RELOCATABLE 						\&& (get_pool_size () != 0 || current_function_profile)		\&& uses_TOC())							\       {									\ 	char buf[256];							\ 									\ 	ASM_OUTPUT_INTERNAL_LABEL (FILE, "LCL", rs6000_pic_labelno);	\ 									\ 	ASM_GENERATE_INTERNAL_LABEL (buf, "LCTOC", 1);			\ 	fprintf (FILE, "\t%s ", init_ptr);				\ 	assemble_name (FILE, buf);					\ 	putc ('-', FILE);						\ 	ASM_GENERATE_INTERNAL_LABEL (buf, "LCF", rs6000_pic_labelno);	\ 	assemble_name (FILE, buf);					\ 	putc ('\n', FILE);						\       }									\ 									\     fprintf (FILE, "%s", TYPE_ASM_OP);					\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "function");			\     putc ('\n', FILE);							\     ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\ 									\     if (DEFAULT_ABI == ABI_AIX)						\       {									\ 	const char *desc_name, *orig_name;				\ 									\         STRIP_NAME_ENCODING (orig_name, NAME);				\         desc_name = orig_name;						\ 	while (*desc_name == '.')					\ 	  desc_name++;							\ 									\ 	if (TREE_PUBLIC (DECL))						\ 	  fprintf (FILE, "\t.globl %s\n", desc_name);			\ 									\ 	fprintf (FILE, "%s\n", MINIMAL_TOC_SECTION_ASM_OP);		\ 	fprintf (FILE, "%s:\n", desc_name);				\ 	fprintf (FILE, "\t%s %s\n", init_ptr, orig_name);		\ 	fprintf (FILE, "\t%s _GLOBAL_OFFSET_TABLE_\n", init_ptr);	\ 	if (DEFAULT_ABI == ABI_AIX)					\ 	  fprintf (FILE, "\t%s 0\n", init_ptr);				\ 	fprintf (FILE, "\t.previous\n");				\       }									\     ASM_OUTPUT_LABEL (FILE, NAME);					\   } while (0)
end_define

begin_comment
comment|/* A C compound statement that outputs the assembler code for a thunk function,     used to implement C++ virtual function calls with multiple inheritance.  The     thunk acts as a wrapper around a virtual function, adjusting the implicit     object parameter before handing control off to the real function.      First, emit code to add the integer DELTA to the location that contains the     incoming first argument.  Assume that this argument contains a pointer, and     is the one used to pass the this' pointer in C++.  This is the incoming     argument *before* the function prologue, e.g. %o0' on a sparc.  The     addition must preserve the values of all other incoming arguments.      After the addition, emit code to jump to FUNCTION, which is a     FUNCTION_DECL'.  This is a direct pure jump, not a call, and does not touch     the return address.  Hence returning from FUNCTION will return to whoever     called the current thunk'.      The effect must be as if FUNCTION had been called directly with the adjusted     first argument.  This macro is responsible for emitting all of the code for     a thunk function; FUNCTION_PROLOGUE' and FUNCTION_EPILOGUE' are not     invoked.      The THUNK_FNDECL is redundant.  (DELTA and FUNCTION have already been     extracted from it.)  It might possibly be useful on some targets, but     probably not.      If you do not define this macro, the target-independent code in the C++     frontend will generate a less efficient heavyweight thunk that calls     FUNCTION instead of jumping to it.  The generic approach does not support     varargs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_MI_THUNK
parameter_list|(
name|FILE
parameter_list|,
name|THUNK_FNDECL
parameter_list|,
name|DELTA
parameter_list|,
name|FUNCTION
parameter_list|)
define|\
value|output_mi_thunk (FILE, THUNK_FNDECL, DELTA, FUNCTION)
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
comment|/* svr4.h overrides ASM_OUTPUT_INTERNAL_LABEL.  */
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

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|(assemble_name (FILE, NAME), fputs (":\n", FILE))
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { fputs ("\t.globl ", FILE);	\        assemble_name (FILE, NAME); putc ('\n', FILE);} while (0)
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
comment|/* Override elfos.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {									\   if (rs6000_sdata != SDATA_NONE&& (SIZE)> 0				\&& (SIZE)<= g_switch_value)					\     {									\       sbss_section ();							\       ASM_OUTPUT_ALIGN (FILE, exact_log2 (ALIGN / BITS_PER_UNIT));	\       ASM_OUTPUT_LABEL (FILE, NAME);					\       ASM_OUTPUT_SKIP (FILE, SIZE);					\       if (!flag_inhibit_size_directive&& (SIZE)> 0)			\ 	{								\ 	  fprintf (FILE, "%s", SIZE_ASM_OP);				\ 	  assemble_name (FILE, NAME);					\ 	  fprintf (FILE, ",%d\n",  SIZE);				\ 	}								\     }									\   else									\     {									\       fprintf (FILE, "%s", LCOMM_ASM_OP);				\       assemble_name ((FILE), (NAME));					\       fprintf ((FILE), ",%u,%u\n", (SIZE), (ALIGN) / BITS_PER_UNIT);	\     }									\ } while (0)
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
value|do {									\   ASM_GLOBALIZE_LABEL (FILE, NAME);					\   ASM_OUTPUT_ALIGNED_LOCAL (FILE, NAME, SIZE, ALIGN);			\ } while (0)
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

begin_comment
comment|/* Output .file.  */
end_comment

begin_comment
comment|/* Override elfos.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {									\   output_file_directive ((FILE), main_input_filename);			\   rs6000_file_start (FILE, TARGET_CPU_DEFAULT);				\ } while (0)
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
end_define

begin_comment
comment|/* If we are referencing a function that is static or is known to be    in this file, make the SYMBOL_REF special.  We can use this to indicate    that we can branch to this function without emitting a no-op after the    call.  For real AIX calling sequences, we also replace the    function name with the real name (1 or 2 leading .'s), rather than    the function descriptor name.  This saves a lot of overriding code    to read the prefixes.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENCODE_SECTION_INFO
end_undef

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
value|rs6000_encode_section_info (DECL)
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
comment|/* This macro gets just the user-specified name    out of the string in a SYMBOL_REF.  Discard    a leading * or @.  */
end_comment

begin_define
define|#
directive|define
name|STRIP_NAME_ENCODING
parameter_list|(
name|VAR
parameter_list|,
name|SYMBOL_NAME
parameter_list|)
define|\
value|do {									\   const char *_name = SYMBOL_NAME;					\   while (*_name == '*' || *_name == '@')				\     _name++;								\   (VAR) = _name;							\ } while (0)
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.    `assemble_name' uses this.  */
end_comment

begin_comment
comment|/* Override elfos.h definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {						\   const char *_name = NAME;			\   if (*_name == '@')				\     _name++;					\  						\   if (*_name == '*')				\     fprintf (FILE, "%s", _name + 1);		\   else						\     asm_fprintf (FILE, "%U%s", _name);		\ } while (0)
end_define

begin_comment
comment|/* But, to make this work, we have to output the stabs for the function    name *first*...  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_PREDEFINES
end_ifndef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-DPPC -Dunix -D__svr4__ -Asystem=unix -Asystem=svr4 -Acpu=powerpc -Amachine=powerpc"
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
value|"%(asm_cpu) \ %{.s: %{mregnames} %{mno-regnames}} %{.S: %{mregnames} %{mno-regnames}} \ %{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*} \ %{mrelocatable} %{mrelocatable-lib} %{fpic:-K PIC} %{fPIC:-K PIC} \ %{memb} %{!memb: %{msdata: -memb} %{msdata=eabi: -memb}} \ %{mlittle} %{mlittle-endian} %{mbig} %{mbig-endian} \ %{!mlittle: %{!mlittle-endian: %{!mbig: %{!mbig-endian: \     %{mcall-freebsd: -mbig} \     %{mcall-i960-old: -mlittle} \     %{mcall-linux: -mbig} \     %{mcall-netbsd: -mbig} \ }}}}"
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
value|"%(cc1_endian_big_spec)"
end_define

begin_comment
comment|/* Pass -G xxx to the compiler and set correct endian mode.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{G*} \ %{mlittle: %(cc1_endian_little)} %{!mlittle: %{mlittle-endian: %(cc1_endian_little)}} \ %{mbig: %(cc1_endian_big)} %{!mbig: %{mbig-endian: %(cc1_endian_big)}} \ %{!mlittle: %{!mlittle-endian: %{!mbig: %{!mbig-endian: \     %{mcall-aixdesc: -mbig %(cc1_endian_big) } \     %{mcall-freebsd: -mbig %(cc1_endian_big) } \     %{mcall-i960-old: -mlittle %(cc1_endian_little) } \     %{mcall-linux: -mbig %(cc1_endian_big) } \     %{mcall-netbsd: -mbig %(cc1_endian_big) } \     %{!mcall-aixdesc: %{!mcall-freebsd: %{!mcall-i960-old: %{!mcall-linux: %{!mcall-netbsd: \ 	    %(cc1_endian_default) \     }}}}} \ }}}} \ %{mno-sdata: -msdata=none } \ %{meabi: %{!mcall-*: -mcall-sysv }} \ %{!meabi: %{!mno-eabi: \     %{mrelocatable: -meabi } \     %{mcall-freebsd: -mno-eabi } \     %{mcall-i960-old: -meabi } \     %{mcall-linux: -mno-eabi } \     %{mcall-netbsd: -mno-eabi }}} \ %{msdata: -msdata=default} \ %{mno-sdata: -msdata=none} \ %{profile: -p}"
end_define

begin_comment
comment|/* Don't put -Y P,<path> for cross compilers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
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
value|"\ %{mads: %(link_start_ads) } \ %{myellowknife: %(link_start_yellowknife) } \ %{mmvme: %(link_start_mvme) } \ %{msim: %(link_start_sim) } \ %{mcall-freebsd: %(link_start_freebsd) } \ %{mcall-linux: %(link_start_linux) } \ %{mcall-netbsd: %(link_start_netbsd) } \ %{!mads: %{!myellowknife: %{!mmvme: %{!msim: %{!mcall-linux: \ 	%{!mcall-netbsd: %{!mcall-freebsd: %(link_start_default) }}}}}}}"
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
value|"\ %{mads: %(link_os_ads) } \ %{myellowknife: %(link_os_yellowknife) } \ %{mmvme: %(link_os_mvme) } \ %{msim: %(link_os_sim) } \ %{mcall-freebsd: %(link_os_freebsd) } \ %{mcall-linux: %(link_os_linux) } \ %{mcall-netbsd: %(link_os_netbsd) } \ %{!mads: %{!myellowknife: %{!mmvme: %{!msim: %{!mcall-freebsd: %{!mcall-linux: %{!mcall-netbsd: %(link_os_default) }}}}}}}"
end_define

begin_define
define|#
directive|define
name|LINK_OS_DEFAULT_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|CPP_SYSV_SPEC
define|\
value|"%{mrelocatable*: -D_RELOCATABLE} \ %{fpic: -D__PIC__=1 -D__pic__=1} \ %{!fpic: %{fPIC: -D__PIC__=2 -D__pic__=2}} \ %{mlong-double-128: -D__LONG_DOUBLE_128__=1} \ %{!mlong-double-64: %(cpp_longdouble_default)} \ %{mcall-sysv: -D_CALL_SYSV} \ %{mcall-aix: -D_CALL_AIX} %{mcall-aixdesc: -D_CALL_AIX -D_CALL_AIXDESC} \ %{!mcall-sysv: %{!mcall-aix: %{!mcall-aixdesc: %(cpp_sysv_default) }}} \ %{msoft-float: -D_SOFT_FLOAT} \ %{!msoft-float: %{!mhard-float: \     %{mcpu=401: -D_SOFT_FLOAT} \     %{mcpu=403: -D_SOFT_FLOAT} \     %{mcpu=405: -D_SOFT_FLOAT} \     %{mcpu=ec603e: -D_SOFT_FLOAT} \     %{mcpu=801: -D_SOFT_FLOAT} \     %{mcpu=821: -D_SOFT_FLOAT} \     %{mcpu=823: -D_SOFT_FLOAT} \     %{mcpu=860: -D_SOFT_FLOAT} \     %{!mcpu*: %(cpp_float_default) }}}"
end_define

begin_comment
comment|/* Whether floating point is disabled by default.  */
end_comment

begin_define
define|#
directive|define
name|CPP_FLOAT_DEFAULT_SPEC
value|""
end_define

begin_comment
comment|/* Whether 'long double' is 128 bits by default.  */
end_comment

begin_define
define|#
directive|define
name|CPP_LONGDOUBLE_DEFAULT_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|CPP_SYSV_DEFAULT_SPEC
value|"-D_CALL_SYSV"
end_define

begin_define
define|#
directive|define
name|CPP_ENDIAN_BIG_SPEC
value|"-D_BIG_ENDIAN -D__BIG_ENDIAN__ -Amachine=bigendian"
end_define

begin_define
define|#
directive|define
name|CPP_ENDIAN_LITTLE_SPEC
value|"-D_LITTLE_ENDIAN -D__LITTLE_ENDIAN__ -Amachine=littleendian"
end_define

begin_define
define|#
directive|define
name|CPP_ENDIAN_SPEC
define|\
value|"%{mlittle: %(cpp_endian_little) } \ %{mlittle-endian: %(cpp_endian_little) } \ %{mbig: %(cpp_endian_big) } \ %{mbig-endian: %(cpp_endian_big) } \ %{!mlittle: %{!mlittle-endian: %{!mbig: %{!mbig-endian: \     %{mcall-freebsd: %(cpp_endian_big) } \     %{mcall-linux: %(cpp_endian_big) } \     %{mcall-netbsd: %(cpp_endian_big) } \     %{mcall-i960-old: %(cpp_endian_little) } \     %{mcall-aixdesc:  %(cpp_endian_big) } \     %{!mcall-linux: %{!mcall-freebsd: %{!mcall-netbsd: %{!mcall-aixdesc: %(cpp_endian_default) }}}}}}}}"
end_define

begin_define
define|#
directive|define
name|CPP_ENDIAN_DEFAULT_SPEC
value|"%(cpp_endian_big)"
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
value|"%{posix: -D_POSIX_SOURCE} %(cpp_sysv) %(cpp_endian) %(cpp_cpu) \ %{mads: %(cpp_os_ads) } \ %{myellowknife: %(cpp_os_yellowknife) } \ %{mmvme: %(cpp_os_mvme) } \ %{msim: %(cpp_os_sim) } \ %{mcall-freebsd: %(cpp_os_freebsd) } \ %{mcall-linux: %(cpp_os_linux) } \ %{mcall-netbsd: %(cpp_os_netbsd) } \ %{!mads: %{!myellowknife: %{!mmvme: %{!msim: %{!mcall-freebsd: %{!mcall-linux: %{!mcall-netbsd: %(cpp_os_default) }}}}}}}"
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
value|"\ %{mads: %(startfile_ads) } \ %{myellowknife: %(startfile_yellowknife) } \ %{mmvme: %(startfile_mvme) } \ %{msim: %(startfile_sim) } \ %{mcall-freebsd: %(startfile_freebsd) } \ %{mcall-linux: %(startfile_linux) } \ %{mcall-netbsd: %(startfile_netbsd) } \ %{!mads: %{!myellowknife: %{!mmvme: %{!msim: %{!mcall-freebsd: %{!mcall-linux: %{!mcall-netbsd: %(startfile_default) }}}}}}}"
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
value|"\ %{mads: %(lib_ads) } \ %{myellowknife: %(lib_yellowknife) } \ %{mmvme: %(lib_mvme) } \ %{msim: %(lib_sim) } \ %{mcall-freebsd: %(lib_freebsd) } \ %{mcall-linux: %(lib_linux) } \ %{mcall-netbsd: %(lib_netbsd) } \ %{!mads: %{!myellowknife: %{!mmvme: %{!msim: %{!mcall-freebsd: %{!mcall-linux: %{!mcall-netbsd: %(lib_default) }}}}}}}"
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
value|"\ %{mads: %(endfile_ads)} \ %{myellowknife: %(endfile_yellowknife)} \ %{mmvme: %(endfile_mvme)} \ %{msim: %(endfile_sim)} \ %{mcall-freebsd: %(endfile_freebsd) } \ %{mcall-linux: %(endfile_linux) } \ %{mcall-netbsd: %(endfile_netbsd) } \ %{mvxworks: %(endfile_vxworks) } \ %{!mads: %{!myellowknife: %{!mmvme: %{!msim: %{!mcall-freebsd: %{!mcall-linux: %{!mcall-netbsd: %{!mvxworks: %(endfile_default) }}}}}}}}"
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
value|"\   %{symbolic:-Bsymbolic}"
end_define

begin_comment
comment|/* GNU/Linux support.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GNULIBC_1
end_ifdef

begin_define
define|#
directive|define
name|LIB_LINUX_SPEC
value|"%{mnewlib: --start-group -llinux -lc --end-group } \ %{!mnewlib: -lc }"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIB_LINUX_SPEC
value|"%{mnewlib: --start-group -llinux -lc --end-group } \ %{!mnewlib: %{shared:-lc} %{!shared: %{pthread:-lpthread } \ %{profile:-lc_p} %{!profile:-lc}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STARTFILE_LINUX_SPEC
value|"\ %{!shared: %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}} \ %{mnewlib: ecrti.o%s} %{!mnewlib: crti.o%s} \ %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_define
define|#
directive|define
name|ENDFILE_LINUX_SPEC
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} \ %{mnewlib: ecrtn.o%s} %{!mnewlib: crtn.o%s}"
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
name|LINK_OS_LINUX_SPEC
value|"-m elf32ppclinux %{!shared: %{!static: \   %{rdynamic:-export-dynamic} \   %{!dynamic-linker:-dynamic-linker /lib/ld.so.1}}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GNULIBC_1
end_ifdef

begin_define
define|#
directive|define
name|CPP_OS_LINUX_SPEC
value|"-D__unix__ -D__linux__		\ %{!undef:							\   %{!ansi:							\     %{!std=*:-Dunix -D__unix -Dlinux -D__linux}			\     %{std=gnu*:-Dunix -D__unix -Dlinux -D__linux}}}		\ -Asystem=unix -Asystem=posix"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_OS_LINUX_SPEC
value|"-D__unix__ -D__linux__		\ %{!undef:							\   %{!ansi:							\     %{!std=*:-Dunix -D__unix -Dlinux -D__linux}			\     %{std=gnu*:-Dunix -D__unix -Dlinux -D__linux}}}		\ -Asystem=unix -Asystem=posix %{pthread:-D_REENTRANT}"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|"\ -D__powerpc__ -D__NetBSD__ -D__ELF__ -D__KPRINTF_ATTRIBUTE__"
end_define

begin_comment
comment|/* VxWorks support.  */
end_comment

begin_comment
comment|/* VxWorks does all the library stuff itself.  */
end_comment

begin_define
define|#
directive|define
name|LIB_VXWORKS_SPEC
value|""
end_define

begin_comment
comment|/* VxWorks provides the functionality of crt0.o and friends itself.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_VXWORKS_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|ENDFILE_VXWORKS_SPEC
value|""
end_define

begin_comment
comment|/* Because it uses ld -r, vxworks has no start/end files, nor starting    address.  */
end_comment

begin_define
define|#
directive|define
name|LINK_START_VXWORKS_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|LINK_OS_VXWORKS_SPEC
value|"-r"
end_define

begin_define
define|#
directive|define
name|CPP_OS_VXWORKS_SPEC
value|"\ -DCPU_FAMILY=PPC \ %{!mcpu*: \   %{mpowerpc*: -DCPU=PPC603} \   %{!mno-powerpc: -DCPU=PPC603}} \ %{mcpu=powerpc: -DCPU=PPC603} \ %{mcpu=401: -DCPU=PPC403} \ %{mcpu=403: -DCPU=PPC403} \ %{mcpu=405: -DCPU=PPC405} \ %{mcpu=601: -DCPU=PPC601} \ %{mcpu=602: -DCPU=PPC603} \ %{mcpu=603: -DCPU=PPC603} \ %{mcpu=603e: -DCPU=PPC603} \ %{mcpu=ec603e: -DCPU=PPC603} \ %{mcpu=604: -DCPU=PPC604} \ %{mcpu=604e: -DCPU=PPC604} \ %{mcpu=620: -DCPU=PPC604} \ %{mcpu=740: -DCPU=PPC603} \ %{mcpu=7450: -DCPU=PPC603} \ %{mcpu=750: -DCPU=PPC603} \ %{mcpu=801: -DCPU=PPC603} \ %{mcpu=821: -DCPU=PPC603} \ %{mcpu=823: -DCPU=PPC603} \ %{mcpu=860: -DCPU=PPC603}"
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
value|{ "cpp_sysv",			CPP_SYSV_SPEC },			\   { "cpp_sysv_default",		CPP_SYSV_DEFAULT_SPEC },		\   { "cpp_endian_default",	CPP_ENDIAN_DEFAULT_SPEC },		\   { "cpp_endian",		CPP_ENDIAN_SPEC },			\   { "lib_ads",			LIB_ADS_SPEC },				\   { "lib_yellowknife",		LIB_YELLOWKNIFE_SPEC },			\   { "lib_mvme",			LIB_MVME_SPEC },			\   { "lib_sim",			LIB_SIM_SPEC },				\   { "lib_freebsd",		LIB_FREEBSD_SPEC },			\   { "lib_linux",		LIB_LINUX_SPEC },			\   { "lib_netbsd",		LIB_NETBSD_SPEC },			\   { "lib_vxworks",		LIB_VXWORKS_SPEC },			\   { "lib_default",		LIB_DEFAULT_SPEC },			\   { "startfile_ads",		STARTFILE_ADS_SPEC },			\   { "startfile_yellowknife",	STARTFILE_YELLOWKNIFE_SPEC },		\   { "startfile_mvme",		STARTFILE_MVME_SPEC },			\   { "startfile_sim",		STARTFILE_SIM_SPEC },			\   { "startfile_freebsd",	STARTFILE_FREEBSD_SPEC },		\   { "startfile_linux",		STARTFILE_LINUX_SPEC },			\   { "startfile_netbsd",		STARTFILE_NETBSD_SPEC },		\   { "startfile_vxworks",	STARTFILE_VXWORKS_SPEC },		\   { "startfile_default",	STARTFILE_DEFAULT_SPEC },		\   { "endfile_ads",		ENDFILE_ADS_SPEC },			\   { "endfile_yellowknife",	ENDFILE_YELLOWKNIFE_SPEC },		\   { "endfile_mvme",		ENDFILE_MVME_SPEC },			\   { "endfile_sim",		ENDFILE_SIM_SPEC },			\   { "endfile_freebsd",		ENDFILE_FREEBSD_SPEC },			\   { "endfile_linux",		ENDFILE_LINUX_SPEC },			\   { "endfile_netbsd",		ENDFILE_NETBSD_SPEC },			\   { "endfile_vxworks",		ENDFILE_VXWORKS_SPEC },			\   { "endfile_default",		ENDFILE_DEFAULT_SPEC },			\   { "link_path",		LINK_PATH_SPEC },			\   { "link_shlib",		LINK_SHLIB_SPEC },			\   { "link_target",		LINK_TARGET_SPEC },			\   { "link_start",		LINK_START_SPEC },			\   { "link_start_ads",		LINK_START_ADS_SPEC },			\   { "link_start_yellowknife",	LINK_START_YELLOWKNIFE_SPEC },		\   { "link_start_mvme",		LINK_START_MVME_SPEC },			\   { "link_start_sim",		LINK_START_SIM_SPEC },			\   { "link_start_freebsd",	LINK_START_FREEBSD_SPEC },		\   { "link_start_linux",		LINK_START_LINUX_SPEC },		\   { "link_start_netbsd",	LINK_START_NETBSD_SPEC },		\   { "link_start_vxworks",	LINK_START_VXWORKS_SPEC },		\   { "link_start_default",	LINK_START_DEFAULT_SPEC },		\   { "link_os",			LINK_OS_SPEC },				\   { "link_os_ads",		LINK_OS_ADS_SPEC },			\   { "link_os_yellowknife",	LINK_OS_YELLOWKNIFE_SPEC },		\   { "link_os_mvme",		LINK_OS_MVME_SPEC },			\   { "link_os_sim",		LINK_OS_SIM_SPEC },			\   { "link_os_freebsd",		LINK_OS_FREEBSD_SPEC },			\   { "link_os_linux",		LINK_OS_LINUX_SPEC },			\   { "link_os_netbsd",		LINK_OS_NETBSD_SPEC },			\   { "link_os_vxworks",		LINK_OS_VXWORKS_SPEC },			\   { "link_os_default",		LINK_OS_DEFAULT_SPEC },			\   { "cc1_endian_big",		CC1_ENDIAN_BIG_SPEC },			\   { "cc1_endian_little",	CC1_ENDIAN_LITTLE_SPEC },		\   { "cc1_endian_default",	CC1_ENDIAN_DEFAULT_SPEC },		\   { "cpp_endian_big",		CPP_ENDIAN_BIG_SPEC },			\   { "cpp_endian_little",	CPP_ENDIAN_LITTLE_SPEC },		\   { "cpp_float_default",	CPP_FLOAT_DEFAULT_SPEC },		\   { "cpp_longdouble_default",	CPP_LONGDOUBLE_DEFAULT_SPEC },		\   { "cpp_os_ads",		CPP_OS_ADS_SPEC },			\   { "cpp_os_yellowknife",	CPP_OS_YELLOWKNIFE_SPEC },		\   { "cpp_os_mvme",		CPP_OS_MVME_SPEC },			\   { "cpp_os_sim",		CPP_OS_SIM_SPEC },			\   { "cpp_os_freebsd",		CPP_OS_FREEBSD_SPEC },			\   { "cpp_os_linux",		CPP_OS_LINUX_SPEC },			\   { "cpp_os_netbsd",		CPP_OS_NETBSD_SPEC },			\   { "cpp_os_vxworks",		CPP_OS_VXWORKS_SPEC },			\   { "cpp_os_default",		CPP_OS_DEFAULT_SPEC },
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
comment|/* Define this macro (to a value of 1) if you want to support the    Win32 style pragmas #pragma pack(push,<n>)' and #pragma    pack(pop)'.  The pack(push,<n>) pragma specifies the maximum    alignment (in bytes) of fields within a structure, in much the    same way as the __aligned__' and __packed__' __attribute__'s    do.  A pack value of zero resets the behaviour to the default.    Successive invocations of this pragma cause the previous values to    be stacked, so that invocations of #pragma pack(pop)' will return    to the previous value.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK_PUSH_POP
value|1
end_define

begin_comment
comment|/* Define library calls for quad FP operations.  These are all part of the    PowerPC 32bit ABI.  */
end_comment

begin_define
define|#
directive|define
name|ADDTF3_LIBCALL
value|"_q_add"
end_define

begin_define
define|#
directive|define
name|DIVTF3_LIBCALL
value|"_q_div"
end_define

begin_define
define|#
directive|define
name|EXTENDDFTF2_LIBCALL
value|"_q_dtoq"
end_define

begin_define
define|#
directive|define
name|EQTF2_LIBCALL
value|"_q_feq"
end_define

begin_define
define|#
directive|define
name|GETF2_LIBCALL
value|"_q_fge"
end_define

begin_define
define|#
directive|define
name|GTTF2_LIBCALL
value|"_q_fgt"
end_define

begin_define
define|#
directive|define
name|LETF2_LIBCALL
value|"_q_fle"
end_define

begin_define
define|#
directive|define
name|LTTF2_LIBCALL
value|"_q_flt"
end_define

begin_define
define|#
directive|define
name|NETF2_LIBCALL
value|"_q_fne"
end_define

begin_define
define|#
directive|define
name|FLOATSITF2_LIBCALL
value|"_q_itoq"
end_define

begin_define
define|#
directive|define
name|MULTF3_LIBCALL
value|"_q_mul"
end_define

begin_define
define|#
directive|define
name|NEGTF2_LIBCALL
value|"_q_neg"
end_define

begin_define
define|#
directive|define
name|TRUNCTFDF2_LIBCALL
value|"_q_qtod"
end_define

begin_define
define|#
directive|define
name|FIX_TRUNCTFSI2_LIBCALL
value|"_q_qtoi"
end_define

begin_define
define|#
directive|define
name|TRUNCTFSF2_LIBCALL
value|"_q_qtos"
end_define

begin_define
define|#
directive|define
name|FIXUNS_TRUNCTFSI2_LIBCALL
value|"_q_qtou"
end_define

begin_define
define|#
directive|define
name|SQRTTF_LIBCALL
value|"_q_sqrt"
end_define

begin_define
define|#
directive|define
name|EXTENDSFTF2_LIBCALL
value|"_q_stoq"
end_define

begin_define
define|#
directive|define
name|SUBTF3_LIBCALL
value|"_q_sub"
end_define

begin_define
define|#
directive|define
name|FLOATUNSSITF2_LIBCALL
value|"_q_utoq"
end_define

begin_define
define|#
directive|define
name|INIT_TARGET_OPTABS
define|\
value|do {									\     if (TARGET_HARD_FLOAT)						\       {									\ 	add_optab->handlers[(int) TFmode].libfunc			\ 	  = init_one_libfunc (ADDTF3_LIBCALL);				\ 	sub_optab->handlers[(int) TFmode].libfunc			\ 	  = init_one_libfunc (SUBTF3_LIBCALL);				\ 	neg_optab->handlers[(int) TFmode].libfunc			\ 	  = init_one_libfunc (NEGTF2_LIBCALL);				\ 	smul_optab->handlers[(int) TFmode].libfunc			\ 	  = init_one_libfunc (MULTF3_LIBCALL);				\ 	sdiv_optab->handlers[(int) TFmode].libfunc			\ 	  = init_one_libfunc (DIVTF3_LIBCALL);				\ 	eqtf2_libfunc = init_one_libfunc (EQTF2_LIBCALL);		\ 	netf2_libfunc = init_one_libfunc (NETF2_LIBCALL);		\ 	gttf2_libfunc = init_one_libfunc (GTTF2_LIBCALL);		\ 	getf2_libfunc = init_one_libfunc (GETF2_LIBCALL);		\ 	lttf2_libfunc = init_one_libfunc (LTTF2_LIBCALL);		\ 	letf2_libfunc = init_one_libfunc (LETF2_LIBCALL);		\ 	trunctfsf2_libfunc = init_one_libfunc (TRUNCTFSF2_LIBCALL);	\ 	trunctfdf2_libfunc = init_one_libfunc (TRUNCTFDF2_LIBCALL);	\ 	extendsftf2_libfunc = init_one_libfunc (EXTENDSFTF2_LIBCALL);	\ 	extenddftf2_libfunc = init_one_libfunc (EXTENDDFTF2_LIBCALL);	\ 	floatsitf_libfunc = init_one_libfunc (FLOATSITF2_LIBCALL);	\ 	fixtfsi_libfunc = init_one_libfunc (FIX_TRUNCTFSI2_LIBCALL);	\ 	fixunstfsi_libfunc						\ 	  = init_one_libfunc (FIXUNS_TRUNCTFSI2_LIBCALL);		\ 	if (TARGET_PPC_GPOPT || TARGET_POWER2) 				\ 	  sqrt_optab->handlers[(int) TFmode].libfunc			\ 	    = init_one_libfunc (SQRTTF_LIBCALL);			\       }									\   } while (0)
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
name|TARGET_ASM_EXCEPTION_SECTION
value|readonly_data_section
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
end_define

end_unit

