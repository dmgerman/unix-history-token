begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"cset.h"
end_include

begin_include
include|#
directive|include
file|"errarg.h"
end_include

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_include
include|#
directive|include
file|"box.h"
end_include

begin_decl_stmt
specifier|extern
name|char
name|start_delim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|end_delim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|non_empty_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inline_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|draw_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|one_size_reduction_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|compatible_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nroff
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|init_lex
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|lineno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lex_error
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|,
specifier|const
name|errarg
modifier|&
name|arg1
init|=
name|empty_errarg
parameter_list|,
specifier|const
name|errarg
modifier|&
name|arg2
init|=
name|empty_errarg
parameter_list|,
specifier|const
name|errarg
modifier|&
name|arg3
init|=
name|empty_errarg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_table
parameter_list|(
specifier|const
name|char
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// prefix for all registers, strings, macros
end_comment

begin_define
define|#
directive|define
name|PREFIX
value|"0"
end_define

end_unit

