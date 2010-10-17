begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-xtensa.h -- Header file for tc-xtensa.c.    Copyright (C) 2003 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_XTENSA
end_ifndef

begin_define
define|#
directive|define
name|TC_XTENSA
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

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_error
error|#
directive|error
error|Xtensa support requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OBJ_ELF
end_ifndef

begin_error
error|#
directive|error
error|Xtensa support requires ELF object format
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xtensa-config.h"
end_include

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|XCHAL_HAVE_BE
end_define

begin_struct
struct|struct
name|xtensa_frag_type
block|{
name|unsigned
name|is_literal
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_text
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_loop_target
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_branch_target
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_insn
range|:
literal|1
decl_stmt|;
comment|/* Info about the current state of assembly, i.e., density, relax,      generics, freeregs, longcalls.  These need to be passed to the      backend and then to the linking file.  */
name|unsigned
name|is_no_density
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_relax
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_generics
range|:
literal|1
decl_stmt|;
name|unsigned
name|is_longcalls
range|:
literal|1
decl_stmt|;
comment|/* For text fragments that can generate literals at relax time, this      variable points to the frag where the literal will be stored.  For      literal frags, this variable points to the nearest literal pool      location frag.  This literal frag will be moved to after this      location.  */
name|fragS
modifier|*
name|literal_frag
decl_stmt|;
comment|/* The destination segment for literal frags.  (Note that this is only      valid after xtensa_move_literals.  */
name|segT
name|lit_seg
decl_stmt|;
comment|/* For the relaxation scheme, some literal fragments can have their      expansions modified by an instruction that relaxes.  */
name|unsigned
name|text_expansion
decl_stmt|;
name|unsigned
name|literal_expansion
decl_stmt|;
name|unsigned
name|unreported_expansion
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|xtensa_block_info_struct
block|{
name|segT
name|sec
decl_stmt|;
name|bfd_vma
name|offset
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|struct
name|xtensa_block_info_struct
modifier|*
name|next
decl_stmt|;
block|}
name|xtensa_block_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|xt_insn_sec
block|,
name|xt_literal_sec
block|,
name|max_xt_sec
block|}
name|xt_section_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_segment_info_struct
block|{
name|fragS
modifier|*
name|literal_pool_loc
decl_stmt|;
name|xtensa_block_info
modifier|*
name|blocks
index|[
name|max_xt_sec
index|]
decl_stmt|;
block|}
name|xtensa_segment_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xtensa_symfield_type_struct
block|{
name|unsigned
name|int
name|plt
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_loop_target
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_branch_target
range|:
literal|1
decl_stmt|;
block|}
name|xtensa_symfield_type
typedef|;
end_typedef

begin_comment
comment|/* Section renaming is only supported in Tensilica's version of GAS.  */
end_comment

begin_define
define|#
directive|define
name|XTENSA_SECTION_RENAME
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|XTENSA_SECTION_RENAME
end_ifdef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|xtensa_section_rename
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Tensilica's section renaming feature is not included here.  */
end_comment

begin_define
define|#
directive|define
name|xtensa_section_rename
parameter_list|(
name|name
parameter_list|)
value|(name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XTENSA_SECTION_RENAME */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|xtensa_target_format
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xtensa_frag_init
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xtensa_cons_fix_new
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xtensa_frob_label
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xtensa_end
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xtensa_post_relax_hook
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xtensa_file_arch_init
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xtensa_flush_pending_output
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|xtensa_fix_adjustable
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

begin_decl_stmt
specifier|extern
name|void
name|xtensa_symbol_new_hook
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|xtensa_relax_frag
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|long
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|xtensa_target_format ()
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_xtensa
end_define

begin_define
define|#
directive|define
name|TC_SEGMENT_INFO_TYPE
value|xtensa_segment_info
end_define

begin_define
define|#
directive|define
name|TC_SYMFIELD_TYPE
value|xtensa_symfield_type
end_define

begin_define
define|#
directive|define
name|TC_FRAG_TYPE
value|struct xtensa_frag_type
end_define

begin_define
define|#
directive|define
name|TC_FRAG_INIT
parameter_list|(
name|frag
parameter_list|)
value|xtensa_frag_init (frag)
end_define

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
value|xtensa_cons_fix_new
end_define

begin_define
define|#
directive|define
name|tc_canonicalize_symbol_name
parameter_list|(
name|s
parameter_list|)
value|xtensa_section_rename (s)
end_define

begin_define
define|#
directive|define
name|tc_init_after_args
parameter_list|()
value|xtensa_file_arch_init (stdoutput)
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|fix
parameter_list|)
value|xtensa_fix_adjustable (fix)
end_define

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|xtensa_frob_label (sym)
end_define

begin_define
define|#
directive|define
name|tc_symbol_new_hook
parameter_list|(
name|s
parameter_list|)
value|xtensa_symbol_new_hook (s)
end_define

begin_define
define|#
directive|define
name|md_elf_section_rename
parameter_list|(
name|name
parameter_list|)
value|xtensa_section_rename (name)
end_define

begin_define
define|#
directive|define
name|md_end
value|xtensa_end
end_define

begin_define
define|#
directive|define
name|md_flush_pending_output
parameter_list|()
value|xtensa_flush_pending_output ()
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
name|TEXT_SECTION_NAME
value|xtensa_section_rename (".text")
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_NAME
value|xtensa_section_rename (".data")
end_define

begin_define
define|#
directive|define
name|BSS_SECTION_NAME
value|xtensa_section_rename (".bss")
end_define

begin_comment
comment|/* The renumber_section function must be mapped over all the sections    after calling xtensa_post_relax_hook.  That function is static in    write.c so it cannot be called from xtensa_post_relax_hook itself.  */
end_comment

begin_define
define|#
directive|define
name|md_post_relax_hook
define|\
value|do \     { \       int i = 0; \       xtensa_post_relax_hook (); \       bfd_map_over_sections (stdoutput, renumber_sections,&i); \     } \   while (0)
end_define

begin_comment
comment|/* Because xtensa relaxation can insert a new literal into the middle of    fragment and thus require re-running the relaxation pass on the    section, we need an explicit flag here.  We explicitly use the name    "stretched" here to avoid changing the source code in write.c.  */
end_comment

begin_define
define|#
directive|define
name|md_relax_frag
parameter_list|(
name|segment
parameter_list|,
name|fragP
parameter_list|,
name|stretch
parameter_list|)
define|\
value|xtensa_relax_frag (fragP, stretch,&stretched)
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
name|WORKING_DOT_WORD
value|1
end_define

begin_define
define|#
directive|define
name|DOUBLESLASH_LINE_COMMENTS
end_define

begin_define
define|#
directive|define
name|TC_HANDLES_FX_DONE
end_define

begin_define
define|#
directive|define
name|TC_FINALIZE_SYMS_BEFORE_SIZE_SEG
value|0
end_define

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_XTENSA */
end_comment

end_unit

