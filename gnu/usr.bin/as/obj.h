begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* obj.h - defines the object dependent hooks for all object    format backends.     Copyright (C) 1987, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

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
name|obj_default_output_file_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_crawl_symbol_chain
parameter_list|(
name|object_headers
modifier|*
name|headers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_emit_relocations
parameter_list|(
name|char
modifier|*
modifier|*
name|where
parameter_list|,
name|fixS
modifier|*
name|fixP
parameter_list|,
name|relax_addressT
name|segment_address_in_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_emit_strings
parameter_list|(
name|char
modifier|*
modifier|*
name|where
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_emit_symbols
parameter_list|(
name|char
modifier|*
modifier|*
name|where
parameter_list|,
name|symbolS
modifier|*
name|symbol_rootP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_header_append
parameter_list|(
name|char
modifier|*
modifier|*
name|where
parameter_list|,
name|object_headers
modifier|*
name|headers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_read_begin_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|obj_symbol_new_hook
end_ifndef

begin_function_decl
name|void
name|obj_symbol_new_hook
parameter_list|(
name|symbolS
modifier|*
name|symbolP
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* obj_symbol_new_hook */
end_comment

begin_function_decl
name|void
name|obj_symbol_to_chars
parameter_list|(
name|char
modifier|*
modifier|*
name|where
parameter_list|,
name|symbolS
modifier|*
name|symbolP
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|obj_pre_write_hook
end_ifndef

begin_function_decl
name|void
name|obj_pre_write_hook
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
comment|/* obj_pre_write_hook */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|char
modifier|*
name|obj_default_output_file_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_crawl_symbol_chain
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_emit_relocations
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_emit_strings
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_emit_symbols
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_header_append
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|obj_read_begin_hook
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|obj_symbol_new_hook
end_ifndef

begin_function_decl
name|void
name|obj_symbol_new_hook
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* obj_symbol_new_hook */
end_comment

begin_function_decl
name|void
name|obj_symbol_to_chars
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|obj_pre_write_hook
end_ifndef

begin_function_decl
name|void
name|obj_pre_write_hook
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* obj_pre_write_hook */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|pseudo_typeS
name|obj_pseudo_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of obj.h */
end_comment

end_unit

