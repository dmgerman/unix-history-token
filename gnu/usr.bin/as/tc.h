begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc.h - target cpu dependent     Copyright (C) 1987, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
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
comment|/* JF moved this here from as.h under the theory that nobody except MACHINE.c    and write.c care about it anyway. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|rlx_forward
decl_stmt|;
comment|/* Forward  reach. Signed number.> 0. */
name|long
name|rlx_backward
decl_stmt|;
comment|/* Backward reach. Signed number.< 0. */
name|unsigned
name|char
name|rlx_length
decl_stmt|;
comment|/* Bytes length of this address. */
name|relax_substateT
name|rlx_more
decl_stmt|;
comment|/* Next longer relax-state. */
comment|/* 0 means there is no 'next' relax-state. */
block|}
name|relax_typeS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|relax_typeS
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define it in MACHINE.c */
end_comment

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

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|md_emit_relocations
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

begin_function_decl
name|char
modifier|*
name|md_atof
parameter_list|(
name|int
name|what_statement_type
parameter_list|,
name|char
modifier|*
name|literalP
parameter_list|,
name|int
modifier|*
name|sizeP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_estimate_size_before_relax
parameter_list|(
name|fragS
modifier|*
name|fragP
parameter_list|,
name|segT
name|segment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_parse_option
parameter_list|(
name|char
modifier|*
modifier|*
name|argP
parameter_list|,
name|int
modifier|*
name|cntP
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|vecP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|md_pcrel_from
parameter_list|(
name|fixS
modifier|*
name|fixP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|md_section_align
parameter_list|(
name|segT
name|seg
parameter_list|,
name|long
name|align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|short
name|tc_coff_fix2rtype
parameter_list|(
name|fixS
modifier|*
name|fixP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|md_undefined_symbol
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_apply_fix
parameter_list|(
name|fixS
modifier|*
name|fixP
parameter_list|,
name|long
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_assemble
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_begin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_convert_frag
parameter_list|(
name|object_headers
modifier|*
name|headers
parameter_list|,
name|fragS
modifier|*
name|fragP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_create_long_jump
parameter_list|(
name|char
modifier|*
name|ptr
parameter_list|,
name|long
name|from_addr
parameter_list|,
name|long
name|to_addr
parameter_list|,
name|fragS
modifier|*
name|frag
parameter_list|,
name|symbolS
modifier|*
name|to_symbol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_create_short_jump
parameter_list|(
name|char
modifier|*
name|ptr
parameter_list|,
name|long
name|from_addr
parameter_list|,
name|long
name|to_addr
parameter_list|,
name|fragS
modifier|*
name|frag
parameter_list|,
name|symbolS
modifier|*
name|to_symbol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_number_to_chars
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|long
name|val
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_operand
parameter_list|(
name|expressionS
modifier|*
name|expressionP
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|tc_crawl_symbol_chain
end_ifndef

begin_function_decl
name|void
name|tc_crawl_symbol_chain
parameter_list|(
name|object_headers
modifier|*
name|headers
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|tc_headers_hook
parameter_list|(
name|object_headers
modifier|*
name|headers
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tc_headers_hook */
end_comment

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|md_atof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_estimate_size_before_relax
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_parse_option
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|md_pcrel_from
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|md_section_align
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|short
name|tc_coff_fix2rtype
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|md_undefined_symbol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_apply_fix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_assemble
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_convert_frag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_create_long_jump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_create_short_jump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_number_to_chars
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_operand
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|tc_headers_hook
end_ifndef

begin_function_decl
name|void
name|tc_headers_hook
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tc_headers_hook */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tc_crawl_symbol_chain
end_ifndef

begin_function_decl
name|void
name|tc_crawl_symbol_chain
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tc_crawl_symbol_chain */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC_ */
end_comment

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of tc.h */
end_comment

end_unit

