begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* read.h - of read.c    Copyright (C) 1986 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|input_line_pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -> char we are parsing now. */
end_comment

begin_define
define|#
directive|define
name|PERMIT_WHITESPACE
end_define

begin_comment
comment|/* Define to make whitespace be allowed in */
end_comment

begin_comment
comment|/* many syntactically unnecessary places. */
end_comment

begin_comment
comment|/* Normally undefined. For compatibility */
end_comment

begin_comment
comment|/* with ancient GNU cc. */
end_comment

begin_undef
undef|#
directive|undef
name|PERMIT_WHITESPACE
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|PERMIT_WHITESPACE
end_ifdef

begin_define
define|#
directive|define
name|SKIP_WHITESPACE
parameter_list|()
value|{if (* input_line_pointer == ' ') ++ input_line_pointer;}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SKIP_WHITESPACE
parameter_list|()
value|ASSERT( * input_line_pointer != ' ' )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LEX_NAME
value|(1)
end_define

begin_comment
comment|/* may continue a name */
end_comment

begin_define
define|#
directive|define
name|LEX_BEGIN_NAME
value|(2)
end_define

begin_comment
comment|/* may begin a name */
end_comment

begin_define
define|#
directive|define
name|is_name_beginner
parameter_list|(
name|c
parameter_list|)
value|( lex_type[c]& LEX_BEGIN_NAME )
end_define

begin_define
define|#
directive|define
name|is_part_of_name
parameter_list|(
name|c
parameter_list|)
value|( lex_type[c]& LEX_NAME       )
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|lex_type
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|read_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_a_source_file
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* end: read.h */
end_comment

end_unit

