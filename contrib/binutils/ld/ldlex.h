begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ldlex.h -    Copyright 1991, 1992, 1993, 1994, 1995, 1997, 2000, 2003    Free Software Foundation, Inc.     This file is part of GLD, the Gnu Linker.     GLD is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     GLD is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GLD; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDLEX_H
end_ifndef

begin_define
define|#
directive|define
name|LDLEX_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* The initial parser states.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|input_enum
block|{
name|input_selected
block|,
comment|/* We've set the initial state.  */
name|input_script
block|,
name|input_mri_script
block|,
name|input_version_script
block|,
name|input_defsym
block|}
name|input_type
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|input_type
name|parser_input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|lex_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In ldlex.l.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lex_push_file
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lex_redirect
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldlex_script
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldlex_mri_script
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldlex_version_script
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldlex_version_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldlex_defsym
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldlex_expression
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldlex_both
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldlex_command
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldlex_popstate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In lexsup.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|lex_input
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lex_unput
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|yywrap
end_ifndef

begin_function_decl
specifier|extern
name|int
name|yywrap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|parse_args
parameter_list|(
name|unsigned
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

