begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Allocate input grammar variables for bison,    Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.  This file is part of Bison, the GNU Compiler Compiler.  Bison is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  Bison is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bison; see the file COPYING.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* comments for these variables are in gram.h  */
end_comment

begin_decl_stmt
name|int
name|nitems
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nrules
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nsyms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ntokens
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nvars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|ritem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|rlhs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|rrhs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|rprec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|rprecsym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|sprec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|rassoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|sassoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|token_translations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|rline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|start_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|translations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|max_user_token_number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|semantic_parser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pure_parser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|error_token_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is to avoid linker problems which occur on VMS when using GCC,    when the file in question contains data definitions only.  */
end_comment

begin_function
name|void
name|dummy
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

