begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc.h - target cpu dependent     Copyright 1987, 1990, 1991, 1992, 1993, 1994, 1995, 2000    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* In theory (mine, at least!) the machine dependent part of the assembler    should only have to include one file.  This one.  -- JF */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|pseudo_typeS
name|md_pseudo_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* JF moved this here from as.h under the theory that nobody except MACHINE.c    and write.c care about it anyway.  */
end_comment

begin_struct
struct|struct
name|relax_type
block|{
comment|/* Forward reach. Signed number.> 0.  */
name|long
name|rlx_forward
decl_stmt|;
comment|/* Backward reach. Signed number.< 0.  */
name|long
name|rlx_backward
decl_stmt|;
comment|/* Bytes length of this address.  */
name|unsigned
name|char
name|rlx_length
decl_stmt|;
comment|/* Next longer relax-state.  0 means there is no 'next' relax-state.  */
name|relax_substateT
name|rlx_more
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|relax_type
name|relax_typeS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|md_reloc_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of a relocation record */
end_comment

begin_decl_stmt
name|char
modifier|*
name|md_atof
name|PARAMS
argument_list|(
operator|(
name|int
name|what_statement_type
operator|,
name|char
operator|*
name|literalP
operator|,
name|int
operator|*
name|sizeP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|md_estimate_size_before_relax
end_ifndef

begin_decl_stmt
name|int
name|md_estimate_size_before_relax
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
name|fragP
operator|,
name|segT
name|segment
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|md_parse_option
name|PARAMS
argument_list|(
operator|(
name|int
name|c
operator|,
name|char
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_show_usage
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|md_pcrel_from
name|PARAMS
argument_list|(
operator|(
name|fixS
operator|*
name|fixP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|tc_coff_fix2rtype
name|PARAMS
argument_list|(
operator|(
name|fixS
operator|*
name|fixP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_assemble
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_begin
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|md_create_long_jump
end_ifndef

begin_decl_stmt
name|void
name|md_create_long_jump
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|ptr
operator|,
name|addressT
name|from_addr
operator|,
name|addressT
name|to_addr
operator|,
name|fragS
operator|*
name|frag
operator|,
name|symbolS
operator|*
name|to_symbol
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|md_create_short_jump
end_ifndef

begin_decl_stmt
name|void
name|md_create_short_jump
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|ptr
operator|,
name|addressT
name|from_addr
operator|,
name|addressT
name|to_addr
operator|,
name|fragS
operator|*
name|frag
operator|,
name|symbolS
operator|*
name|to_symbol
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|md_number_to_chars
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|valueT
name|val
operator|,
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|md_operand
end_ifndef

begin_decl_stmt
name|void
name|md_operand
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
name|expressionP
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
name|MD_APPLY_FIX3
end_ifdef

begin_decl_stmt
name|int
name|md_apply_fix3
name|PARAMS
argument_list|(
operator|(
name|fixS
operator|*
name|fixP
operator|,
name|valueT
operator|*
name|val
operator|,
name|segT
name|seg
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
name|BFD_ASSEMBLER
end_ifdef

begin_decl_stmt
name|int
name|md_apply_fix
name|PARAMS
argument_list|(
operator|(
name|fixS
operator|*
name|fixP
operator|,
name|valueT
operator|*
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|md_convert_frag
end_ifndef

begin_decl_stmt
name|void
name|md_convert_frag
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|headers
operator|,
name|segT
name|sec
operator|,
name|fragS
operator|*
name|fragP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tc_headers_hook
end_ifndef

begin_decl_stmt
name|void
name|tc_headers_hook
name|PARAMS
argument_list|(
operator|(
name|segT
operator|*
operator|,
name|fixS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_EXPANSION_POSSIBLE
end_ifndef

begin_decl_stmt
specifier|extern
name|arelent
modifier|*
name|tc_gen_reloc
name|PARAMS
argument_list|(
operator|(
name|asection
operator|*
operator|,
name|fixS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|arelent
modifier|*
modifier|*
name|tc_gen_reloc
name|PARAMS
argument_list|(
operator|(
name|asection
operator|*
operator|,
name|fixS
operator|*
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
comment|/* not BFD_ASSEMBLER */
end_comment

begin_decl_stmt
name|void
name|md_apply_fix
name|PARAMS
argument_list|(
operator|(
name|fixS
operator|*
name|fixP
operator|,
name|long
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|md_convert_frag
end_ifndef

begin_decl_stmt
name|void
name|md_convert_frag
name|PARAMS
argument_list|(
operator|(
name|object_headers
operator|*
name|headers
operator|,
name|segT
operator|,
name|fragS
operator|*
name|fragP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tc_crawl_symbol_chain
end_ifndef

begin_decl_stmt
name|void
name|tc_crawl_symbol_chain
name|PARAMS
argument_list|(
operator|(
name|object_headers
operator|*
name|headers
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tc_crawl_symbol_chain */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tc_headers_hook
end_ifndef

begin_decl_stmt
name|void
name|tc_headers_hook
name|PARAMS
argument_list|(
operator|(
name|object_headers
operator|*
name|headers
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tc_headers_hook */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BFD_ASSEMBLER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|md_section_align
end_ifndef

begin_decl_stmt
name|valueT
name|md_section_align
name|PARAMS
argument_list|(
operator|(
name|segT
name|seg
operator|,
name|valueT
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|md_undefined_symbol
end_ifndef

begin_decl_stmt
name|symbolS
modifier|*
name|md_undefined_symbol
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of tc.h */
end_comment

end_unit

