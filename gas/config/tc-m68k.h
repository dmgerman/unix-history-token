begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-m68k.h    Copyright 1987, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997,    1998, 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_M68K
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_AOUT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TE_SUN3
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-sunos-big"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_NetBSD
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-m68k-netbsd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_LINUX
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-m68k-linux"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-zero-big"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-m68k"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_APOLLO
end_ifdef

begin_define
define|#
directive|define
name|COFF_MAGIC
value|APOLLOM68KMAGIC
end_define

begin_define
define|#
directive|define
name|COFF_AOUTHDR_MAGIC
value|APOLLO_COFF_VERSION_NUMBER
end_define

begin_undef
undef|#
directive|undef
name|OBJ_COFF_OMIT_OPTIONAL_HEADER
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_LYNX
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-m68k-lynx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_AUX
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-m68k-aux"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TE_DELTA
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-m68k-sysv"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_MAGIC
end_ifndef

begin_define
define|#
directive|define
name|COFF_MAGIC
value|MC68MAGIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_m68k
end_define

begin_comment
comment|/* for non-BFD_ASSEMBLER */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_m68k
end_define

begin_comment
comment|/* BFD_ASSEMBLER */
end_comment

begin_define
define|#
directive|define
name|COFF_FLAGS
value|F_AR32W
end_define

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|((x)->fx_addsy||(x)->fx_subsy)
end_define

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|FIX
parameter_list|)
value|tc_coff_fix2rtype(FIX)
end_define

begin_define
define|#
directive|define
name|TC_COFF_SIZEMACHDEP
parameter_list|(
name|frag
parameter_list|)
value|tc_coff_sizemachdep(frag)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tc_coff_sizemachdep
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frag
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TE_SUN3
end_ifdef

begin_comment
comment|/* This variable contains the value to write out at the beginning of    the a.out file.  The 2<<16 means that this is a 68020 file instead    of an old-style 68000 file */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MAGIC_NUMBER_FOR_OBJECT_FILE
value|(2<<16|OMAGIC);
end_define

begin_comment
comment|/* Magic byte for file header */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TE_SUN3 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AOUT_MACHTYPE
end_ifndef

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|m68k_aout_machtype
end_define

begin_decl_stmt
specifier|extern
name|int
name|m68k_aout_machtype
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tc_comment_chars
value|m68k_comment_chars
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|m68k_comment_chars
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_crawl_symbol_chain
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_headers_hook
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_aout_pre_write_hook
parameter_list|(
name|x
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|LISTING_WORD_SIZE
value|2
end_define

begin_comment
comment|/* A word is 2 bytes */
end_comment

begin_define
define|#
directive|define
name|LISTING_LHS_WIDTH
value|2
end_define

begin_comment
comment|/* One word on the first line */
end_comment

begin_define
define|#
directive|define
name|LISTING_LHS_WIDTH_SECOND
value|2
end_define

begin_comment
comment|/* One word on the second line */
end_comment

begin_define
define|#
directive|define
name|LISTING_LHS_CONT_LINES
value|4
end_define

begin_comment
comment|/* And 4 lines max */
end_comment

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"68K GAS "
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|REGISTER_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|'%'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|REGISTER_PREFIX_OPTIONAL
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|M68KCOFF
argument_list|)
operator|||
name|defined
argument_list|(
name|OBJ_ELF
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|(name[0] == '.' \&& (name[1] == 'L' || name[1] == '.'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BFD_ASSEMBLER */
end_comment

begin_define
define|#
directive|define
name|REGISTER_PREFIX_OPTIONAL
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! (COFF || ELF) */
end_comment

begin_define
define|#
directive|define
name|REGISTER_PREFIX_OPTIONAL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! (COFF || ELF) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not def REGISTER_PREFIX and not def OPTIONAL_REGISTER_PREFIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TE_DELTA
end_ifdef

begin_comment
comment|/* On the Delta, `%' can occur within a label name, but not as the    initial character.  */
end_comment

begin_define
define|#
directive|define
name|LEX_PCT
value|LEX_NAME
end_define

begin_comment
comment|/* On the Delta, `~' can start a label name, but is converted to '.'.  */
end_comment

begin_define
define|#
directive|define
name|LEX_TILDE
value|LEX_BEGIN_NAME
end_define

begin_define
define|#
directive|define
name|tc_canonicalize_symbol_name
parameter_list|(
name|s
parameter_list|)
value|((*(s) == '~' ? *(s) = '.' : '.'), s)
end_define

begin_comment
comment|/* On the Delta, dots are not required before pseudo-ops.  */
end_comment

begin_define
define|#
directive|define
name|NO_PSEUDO_DOT
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
define|\
value|(name[0] == '.' || (name[0] == 'L'&& name[1] == '%'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|m68k_mri_mode_change
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MRI_MODE_CHANGE
parameter_list|(
name|i
parameter_list|)
value|m68k_mri_mode_change (i)
end_define

begin_decl_stmt
specifier|extern
name|int
name|m68k_conditional_pseudoop
name|PARAMS
argument_list|(
operator|(
name|pseudo_typeS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_conditional_pseudoop
parameter_list|(
name|pop
parameter_list|)
value|m68k_conditional_pseudoop (pop)
end_define

begin_decl_stmt
specifier|extern
name|void
name|m68k_frob_label
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|m68k_frob_label (sym)
end_define

begin_decl_stmt
specifier|extern
name|void
name|m68k_flush_pending_output
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_flush_pending_output
parameter_list|()
value|m68k_flush_pending_output ()
end_define

begin_decl_stmt
specifier|extern
name|void
name|m68k_frob_symbol
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_define
define|#
directive|define
name|tc_frob_symbol
parameter_list|(
name|sym
parameter_list|,
name|punt
parameter_list|)
define|\
value|do								\   {								\     if (S_GET_SEGMENT (sym) == reg_section)			\       punt = 1;							\     m68k_frob_symbol (sym);					\   }								\ while (0)
end_define

begin_define
define|#
directive|define
name|NO_RELOC
value|BFD_RELOC_NONE
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_ABS8
value|BFD_RELOC_8
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_ABS16
value|BFD_RELOC_16
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_ABS32
value|BFD_RELOC_32
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_PC8
value|BFD_RELOC_8_PCREL
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_PC16
value|BFD_RELOC_16_PCREL
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_PC32
value|BFD_RELOC_32_PCREL
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|X
parameter_list|)
value|tc_m68k_fix_adjustable(X)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tc_m68k_fix_adjustable
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Target *-*-elf implies an embedded target.  No shared libs.    *-*-uclinux also requires special casing to prevent GAS from    generating unsupported R_68K_PC16 relocs.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
define|\
value|((strcmp (TARGET_OS, "elf") != 0)&& (strcmp (TARGET_OS, "uclinux") != 0))
end_define

begin_comment
comment|/* Values passed to md_apply_fix3 don't include symbol values.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|elf_tc_final_processing
value|m68k_elf_final_processing
end_define

begin_decl_stmt
specifier|extern
name|void
name|m68k_elf_final_processing
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! BFD_ASSEMBLER */
end_comment

begin_define
define|#
directive|define
name|tc_frob_coff_symbol
parameter_list|(
name|sym
parameter_list|)
value|m68k_frob_symbol (sym)
end_define

begin_define
define|#
directive|define
name|NO_RELOC
value|0
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_ABS8
value|0
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_ABS16
value|0
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_ABS32
value|0
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_PC8
value|0
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_PC16
value|0
end_define

begin_define
define|#
directive|define
name|RELAX_RELOC_PC32
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BFD_ASSEMBLER */
end_comment

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_decl_stmt
specifier|extern
name|void
name|m68k_init_after_args
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_init_after_args
value|m68k_init_after_args
end_define

begin_decl_stmt
specifier|extern
name|int
name|m68k_parse_long_option
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_parse_long_option
value|m68k_parse_long_option
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TARGET_WORD_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_m68k
end_define

begin_decl_stmt
specifier|extern
name|struct
name|relax_type
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_relax_table
end_define

begin_comment
comment|/* We can't do a byte jump to the next instruction, so in that case    force word mode by faking AIM.  */
end_comment

begin_define
define|#
directive|define
name|md_prepare_relax_scan
parameter_list|(
name|fragP
parameter_list|,
name|address
parameter_list|,
name|aim
parameter_list|,
name|this_state
parameter_list|,
name|this_type
parameter_list|)
define|\
value|do									  \     {								 	  \       if (aim == 0&& this_type->rlx_forward == 127)			  \         aim = 128;							  \     }									  \   while (0)
end_define

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|2
end_define

begin_comment
comment|/* We want .cfi_* pseudo-ops for generating unwind info.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_USE_CFIPOP
value|1
end_define

begin_define
define|#
directive|define
name|DWARF2_DEFAULT_RETURN_COLUMN
value|24
end_define

begin_define
define|#
directive|define
name|DWARF2_CIE_DATA_ALIGNMENT
value|(-4)
end_define

begin_define
define|#
directive|define
name|tc_regname_to_dw2regnum
value|tc_m68k_regname_to_dw2regnum
end_define

begin_function_decl
specifier|extern
name|int
name|tc_m68k_regname_to_dw2regnum
parameter_list|(
specifier|const
name|char
modifier|*
name|regname
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_cfi_frame_initial_instructions
value|tc_m68k_frame_initial_instructions
end_define

begin_function_decl
specifier|extern
name|void
name|tc_m68k_frame_initial_instructions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

