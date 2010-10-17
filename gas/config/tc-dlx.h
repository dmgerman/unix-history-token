begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-dlx.h -- Assemble for the DLX    Copyright 2002, 2003 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_comment
comment|/* Initially created by Kuang Hwa Lin, 3/20/2002.  */
end_comment

begin_define
define|#
directive|define
name|TC_DLX
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_error
error|#
directive|error
error|DLX support requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__BFD_H_SEEN__
end_ifndef

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_dlx
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-dlx"
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|LEX_DOLLAR
value|1
end_define

begin_comment
comment|/* #define md_operand(x) */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dlx_pop_insert
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
name|int
name|set_dlx_skip_hi16_flag
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
name|md_pop_insert
parameter_list|()
value|dlx_pop_insert ()
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
value|as_fatal ("convert_frag called\n")
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
value|(as_fatal ("estimate_size_before_relax called"),1)
end_define

begin_define
define|#
directive|define
name|tc_unrecognized_line
parameter_list|(
name|c
parameter_list|)
value|dlx_unrecognized_line (c)
end_define

begin_decl_stmt
specifier|extern
name|int
name|dlx_unrecognized_line
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
name|tc_headers_hook
parameter_list|(
name|a
parameter_list|)
value|;
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
value|;
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_crawl_symbol_chain
parameter_list|(
name|a
parameter_list|)
value|;
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_coff_symbol_emit_hook
parameter_list|(
name|a
parameter_list|)
value|;
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|101
end_define

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fix_ptr
parameter_list|)
value|tc_coff_fix2rtype (fix_ptr)
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_dlx
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|DLXMAGIC
end_define

begin_comment
comment|/* Should the reloc be output ? 	on the 29k, this is true only if there is a symbol attached. 	on the h8, this is always true, since no fixup is done         on dlx, I have no idea!! but lets keep it here just for fun. */
end_comment

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|(x->fx_addsy)
end_define

begin_define
define|#
directive|define
name|TC_CONS_RELOC
value|BFD_RELOC_32_PCREL
end_define

begin_comment
comment|/* No shared lib support, so we don't need to ensure externally    visible symbols can be overridden.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|0
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|md_dlx_fix_adjustable (FIX)
end_define

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|md_dlx_fix_adjustable
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
comment|/* Values passed to md_apply_fix3 don't include the symbol value.  */
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
name|NEED_FX_R_TYPE
end_define

begin_comment
comment|/* Zero Based Segment?? sound very dangerous to me!     */
end_comment

begin_define
define|#
directive|define
name|ZERO_BASED_SEGMENTS
end_define

begin_comment
comment|/* Permit temporary numeric labels.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_undef
undef|#
directive|undef
name|LOCAL_LABELS_DOLLAR
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABELS_DOLLAR
value|0
end_define

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* .-foo gets turned into PC relative relocs */
end_comment

end_unit

