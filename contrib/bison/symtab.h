begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for symtab.c and callers, part of bison,    Copyright (C) 1984, 1989, 1992 Free Software Foundation, Inc.  This file is part of Bison, the GNU Compiler Compiler.  Bison is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  Bison is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bison; see the file COPYING.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TABSIZE
value|1009
end_define

begin_comment
comment|/*  symbol classes  */
end_comment

begin_define
define|#
directive|define
name|SUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|STOKEN
value|1
end_define

begin_comment
comment|/* terminal symbol */
end_comment

begin_define
define|#
directive|define
name|SNTERM
value|2
end_define

begin_comment
comment|/* non-terminal */
end_comment

begin_define
define|#
directive|define
name|SALIAS
value|-9991
end_define

begin_comment
comment|/* for symbol generated with an alias */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bucket
block|{
name|struct
name|bucket
modifier|*
name|link
decl_stmt|;
name|struct
name|bucket
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|tag
decl_stmt|;
name|char
modifier|*
name|type_name
decl_stmt|;
name|short
name|value
decl_stmt|;
name|short
name|prec
decl_stmt|;
name|short
name|assoc
decl_stmt|;
name|short
name|user_token_number
decl_stmt|;
comment|/* special value SALIAS in the identifier 			 half of the identifier-symbol pair for an alias */
name|struct
name|bucket
modifier|*
name|alias
decl_stmt|;
comment|/* points to the other in the identifier-symbol 			 pair for an alias */
name|char
name|class
decl_stmt|;
block|}
name|bucket
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|bucket
modifier|*
modifier|*
name|symtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bucket
modifier|*
name|firstsymbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bucket
modifier|*
name|getsym
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

