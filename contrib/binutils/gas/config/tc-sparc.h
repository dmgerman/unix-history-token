begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-sparc.h - Macros and type defines for the sparc.    Copyright 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2005 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public    License along with GAS; see the file COPYING.  If not, write    to the Free Software Foundation, 51 Franklin Street - Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_SPARC
end_ifndef

begin_define
define|#
directive|define
name|TC_SPARC
value|1
end_define

begin_struct_decl
struct_decl|struct
name|frag
struct_decl|;
end_struct_decl

begin_comment
comment|/* This is used to set the default value for `target_big_endian'.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_sparc
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|sparc_target_format
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
name|TARGET_FORMAT
value|sparc_target_format ()
end_define

begin_define
define|#
directive|define
name|RELOC_EXPANSION_POSSIBLE
end_define

begin_define
define|#
directive|define
name|MAX_RELOC_EXPANSION
value|2
end_define

begin_comment
comment|/* Make it unconditional and check if -EL is valid after option parsing */
end_comment

begin_define
define|#
directive|define
name|SPARC_BIENDIAN
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|md_convert_frag
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
define|\
value|as_fatal (_("sparc convert_frag\n"))
end_define

begin_define
define|#
directive|define
name|md_estimate_size_before_relax
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|(as_fatal (_("estimate_size_before_relax called")), 1)
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"SPARC GAS "
end_define

begin_decl_stmt
specifier|extern
name|int
name|sparc_pic_code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We require .word, et. al., to be aligned correctly.  */
end_comment

begin_define
define|#
directive|define
name|md_cons_align
parameter_list|(
name|nbytes
parameter_list|)
value|sparc_cons_align (nbytes)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_cons_align
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
name|HANDLE_ALIGN
parameter_list|(
name|fragp
parameter_list|)
value|sparc_handle_align (fragp)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_handle_align
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

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(3 + 4 + 4)
end_define

begin_comment
comment|/* I know that "call 0" fails in sparc-coff if this doesn't return 1.  I    don't know about other relocation types, or other formats, yet.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF
end_ifdef

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_ABS
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type == BFD_RELOC_32_PCREL_S2	\    || TC_FORCE_RELOCATION (FIX))
end_define

begin_define
define|#
directive|define
name|RELOC_REQUIRES_SYMBOL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_AOUT
end_ifdef

begin_comment
comment|/* This expression evaluates to true if the relocation is for a local    object for which we still want to do the relocation at runtime.    False if we are willing to perform this relocation while building    the .o file.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_LOCAL
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(!(FIX)->fx_pcrel				\    || (FIX)->fx_plt				\    || (sparc_pic_code				\&& S_IS_EXTERNAL ((FIX)->fx_addsy))	\    || TC_FORCE_RELOCATION (FIX))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_comment
comment|/* Don't turn certain relocs into relocations against sections.  This    is required for the dynamic linker to operate properly.  When    generating PIC, we need to keep any non PC relative reloc.  The PIC    part of this test must be parallel to the code in tc_gen_reloc which    converts relocations to GOT relocations.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type != BFD_RELOC_VTABLE_INHERIT				\&& (FIX)->fx_r_type != BFD_RELOC_VTABLE_ENTRY			\&& ((FIX)->fx_r_type< BFD_RELOC_SPARC_TLS_GD_HI22			\        || (FIX)->fx_r_type> BFD_RELOC_SPARC_TLS_TPOFF64)		\&& (! sparc_pic_code							\        || ((FIX)->fx_r_type != BFD_RELOC_HI22				\&& (FIX)->fx_r_type != BFD_RELOC_LO10			\&& (FIX)->fx_r_type != BFD_RELOC_SPARC13			\&& ((FIX)->fx_r_type != BFD_RELOC_32_PCREL_S2		\ 	       || !generic_force_reloc (FIX))				\&& ((FIX)->fx_pcrel						\ 	       || ((FIX)->fx_subsy != NULL				\&& (S_GET_SEGMENT ((FIX)->fx_subsy)			\ 		       == S_GET_SEGMENT ((FIX)->fx_addsy)))		\ 	       || S_IS_LOCAL ((FIX)->fx_addsy)))))
end_define

begin_comment
comment|/* Values passed to md_apply_fix don't include the symbol value.  */
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

begin_comment
comment|/* Finish up the entire symtab.  */
end_comment

begin_define
define|#
directive|define
name|tc_adjust_symtab
parameter_list|()
value|sparc_adjust_symtab ()
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_adjust_symtab
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

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_AOUT
end_ifdef

begin_comment
comment|/* When generating PIC code, we must not adjust any reloc which will    turn into a reloc against the global offset table, nor any reloc    which we will need if a symbol is overridden.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(! sparc_pic_code							\    || ((FIX)->fx_pcrel							\&& ((FIX)->fx_addsy == NULL					\ 	   || (! S_IS_EXTERNAL ((FIX)->fx_addsy)			\&& ! S_IS_WEAK ((FIX)->fx_addsy))))			\    || (FIX)->fx_r_type == BFD_RELOC_16					\    || (FIX)->fx_r_type == BFD_RELOC_32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|elf_tc_final_processing
value|sparc_elf_final_processing
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_elf_final_processing
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
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_md_end
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
name|md_end
parameter_list|()
value|sparc_md_end ()
end_define

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
name|TC_PARSE_CONS_EXPRESSION
parameter_list|(
name|EXP
parameter_list|,
name|NBYTES
parameter_list|)
value|sparc_cons (EXP, NBYTES)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_cons
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
value|cons_fix_new_sparc
end_define

begin_decl_stmt
specifier|extern
name|void
name|cons_fix_new_sparc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frag
operator|*
operator|,
name|int
operator|,
name|unsigned
name|int
operator|,
expr|struct
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_FIX_TYPE
value|valueT
end_define

begin_define
define|#
directive|define
name|TC_INIT_FIX_DATA
parameter_list|(
name|X
parameter_list|)
define|\
value|do						\      {						\        (X)->tc_fix_data = 0;			\      }						\   while (0)
end_define

begin_define
define|#
directive|define
name|TC_FIX_DATA_PRINT
parameter_list|(
name|FILE
parameter_list|,
name|FIX
parameter_list|)
define|\
value|do									\     {									\       fprintf ((FILE), "addend2=%ld\n",   				\ 	      (unsigned long) (FIX)->tc_fix_data);			\     }									\   while (0)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_CFIPOP
value|1
end_define

begin_define
define|#
directive|define
name|tc_cfi_frame_initial_instructions
value|sparc_cfi_frame_initial_instructions
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_cfi_frame_initial_instructions
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
name|tc_regname_to_dw2regnum
value|sparc_regname_to_dw2regnum
end_define

begin_decl_stmt
specifier|extern
name|int
name|sparc_regname_to_dw2regnum
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|regname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_cfi_emit_pcrel_expr
value|sparc_cfi_emit_pcrel_expr
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_cfi_emit_pcrel_expr
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sparc_cie_data_alignment
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|4
end_define

begin_define
define|#
directive|define
name|DWARF2_DEFAULT_RETURN_COLUMN
value|15
end_define

begin_define
define|#
directive|define
name|DWARF2_CIE_DATA_ALIGNMENT
value|sparc_cie_data_alignment
end_define

begin_comment
comment|/* end of tc-sparc.h */
end_comment

end_unit

