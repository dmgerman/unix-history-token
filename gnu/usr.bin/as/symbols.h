begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* symbols.h -     Copyright (C) 1987, 1990, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|obstack
name|notes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* eg FixS live here. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|obstack
name|cond_obstack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this is where we track .ifdef/.endif 				       (if we do that at all).  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|local_bss_counter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Zeroed before a pass. */
end_comment

begin_comment
comment|/* Only used by .lcomm directive. */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|symbol_rootP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all the symbol nodes */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|symbol_lastP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last struct symbol we made, or NULL */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
name|abs_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|dot_text_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|dot_data_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|dot_bss_symbol
decl_stmt|;
end_decl_stmt

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
name|decode_local_label_name
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|local_label_name
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|augend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find_base
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|strip_underscore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find_or_make
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_make
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_new
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|segT
name|segment
parameter_list|,
name|long
name|value
parameter_list|,
name|fragS
modifier|*
name|frag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|colon
parameter_list|(
name|char
modifier|*
name|sym_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|local_colon
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_begin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_table_insert
parameter_list|(
name|symbolS
modifier|*
name|symbolP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|verify_symbol_chain
parameter_list|(
name|symbolS
modifier|*
name|rootP
parameter_list|,
name|symbolS
modifier|*
name|lastP
parameter_list|)
function_decl|;
end_function_decl

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
name|decode_local_label_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|local_label_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find_base
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find_or_make
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_make
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|colon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|local_colon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_table_insert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|verify_symbol_chain
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of symbols.h */
end_comment

end_unit

