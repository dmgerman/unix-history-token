begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-s390.h -- Header file for tc-s390.c.    Copyright 2000, 2001, 2002 Free Software Foundation, Inc.    Written by Martin Schwidefsky (schwidefsky@de.ibm.com).     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_S390
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

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_error
error|#
directive|error
error|S390 support requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This expression evaluates to false if the relocation is for a local object    for which we still want to do the relocation at runtime.  True if we    are willing to perform this relocation while building the .o file.    This is only used for pcrel relocations, so GOTOFF does not need to be    checked here.  I am not sure if some of the others are ever used with    pcrel, but it is easier to be safe than sorry.  */
end_comment

begin_define
define|#
directive|define
name|TC_RELOC_RTSYM_LOC_FIXUP
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type != BFD_RELOC_390_GOTENT  \&& ((FIX)->fx_addsy == NULL               \        || (! S_IS_EXTERNAL ((FIX)->fx_addsy)      \&& ! S_IS_WEAK ((FIX)->fx_addsy)  \&& S_IS_DEFINED ((FIX)->fx_addsy)      \&& ! S_IS_COMMON ((FIX)->fx_addsy))))
end_define

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIXP
parameter_list|)
value|tc_s390_force_relocation(FIXP)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tc_s390_force_relocation
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

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|X
parameter_list|)
value|tc_s390_fix_adjustable(X)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tc_s390_fix_adjustable
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

begin_define
define|#
directive|define
name|TC_FIX_ADJUSTABLE
parameter_list|(
name|fixP
parameter_list|)
define|\
value|(! symbol_used_in_reloc_p ((fixP)->fx_addsy)&& tc_fix_adjustable (fixP))
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_s390
end_define

begin_decl_stmt
specifier|extern
name|enum
name|bfd_architecture
name|s390_arch
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The target BFD format.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|s390_target_format()
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|s390_target_format
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the endianness we are using.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Whether or not the target is big endian */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_big_endian
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Permit temporary numeric labels.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_comment
comment|/* $ is used to refer to the current location.  */
end_comment

begin_comment
comment|/* #define DOLLAR_DOT */
end_comment

begin_comment
comment|/* We need to be able to make relocations involving the difference of    two symbols.  This includes the difference of two symbols when    one of them is undefined (this comes up in PIC code generation).  */
end_comment

begin_define
define|#
directive|define
name|UNDEFINED_DIFFERENCE_OK
end_define

begin_comment
comment|/* foo-. gets turned into PC relative relocs */
end_comment

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* We don't need to handle .word strangely.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_bigendian
end_define

begin_define
define|#
directive|define
name|md_do_align
parameter_list|(
name|n
parameter_list|,
name|fill
parameter_list|,
name|len
parameter_list|,
name|max
parameter_list|,
name|around
parameter_list|)
define|\
value|if ((n)&& !need_pass_2&& (fill == 0)&&                               \     (bfd_get_section_flags (stdoutput, now_seg)& SEC_CODE) != 0) {     \   char *p;                                                              \   p = frag_var (rs_align_code, 15, 1, (relax_substateT) max,            \                 (symbolS *) 0, (offsetT) (n), (char *) 0);              \   *p = 0x07;                                                            \   goto around;                                                          \ }
end_define

begin_decl_stmt
specifier|extern
name|void
name|s390_align_code
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
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
name|fragP
parameter_list|)
define|\
value|if (fragP->fr_type == rs_align_code)					\   s390_align_code (fragP, (fragP->fr_next->fr_address			\ 			   - fragP->fr_address				\ 			   - fragP->fr_fix));
end_define

begin_comment
comment|/* call md_pcrel_from_section, not md_pcrel_from */
end_comment

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|FIXP
parameter_list|,
name|SEC
parameter_list|)
value|md_pcrel_from_section(FIXP, SEC)
end_define

begin_decl_stmt
specifier|extern
name|long
name|md_pcrel_from_section
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|,
name|segT
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
name|s390_md_end
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
value|s390_md_end ()
end_define

end_unit

