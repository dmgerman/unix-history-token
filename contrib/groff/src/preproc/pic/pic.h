begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992, 2000 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
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
file|<math.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_HYPOT
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
name|double
name|hypot
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_DECLARATION_HYPOT */
end_comment

begin_include
include|#
directive|include
file|"assert.h"
end_include

begin_include
include|#
directive|include
file|"cset.h"
end_include

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_include
include|#
directive|include
file|"stringclass.h"
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
file|"position.h"
end_include

begin_include
include|#
directive|include
file|"text.h"
end_include

begin_include
include|#
directive|include
file|"output.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|M_SQRT2
end_ifndef

begin_define
define|#
directive|define
name|M_SQRT2
value|1.41421356237309504880
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|M_PI
end_ifndef

begin_define
define|#
directive|define
name|M_PI
value|3.14159265358979323846
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|input
block|{
name|input
modifier|*
name|next
decl_stmt|;
name|public
label|:
name|input
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|input
argument_list|()
expr_stmt|;
name|virtual
name|int
name|get
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|int
name|peek
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|int
name|get_location
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|friend
name|class
name|input_stack
decl_stmt|;
name|friend
name|class
name|copy_rest_thru_input
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|file_input
range|:
name|public
name|input
block|{
name|FILE
operator|*
name|fp
block|;
specifier|const
name|char
operator|*
name|filename
block|;
name|int
name|lineno
block|;
name|string
name|line
block|;
specifier|const
name|char
operator|*
name|ptr
block|;
name|int
name|read_line
argument_list|()
block|;
name|public
operator|:
name|file_input
argument_list|(
name|FILE
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
block|;
operator|~
name|file_input
argument_list|()
block|;
name|int
name|get
argument_list|()
block|;
name|int
name|peek
argument_list|()
block|;
name|int
name|get_location
argument_list|(
specifier|const
name|char
operator|*
operator|*
argument_list|,
name|int
operator|*
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|lex_init
parameter_list|(
name|input
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_location
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_copy
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse_cleanup
parameter_list|()
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
name|lex_warning
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
name|lex_cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|flyback_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|command_char
decl_stmt|;
end_decl_stmt

begin_comment
comment|// zero_length_line_flag is non-zero if zero-length lines are drawn
end_comment

begin_comment
comment|// as dots by the output device
end_comment

begin_decl_stmt
specifier|extern
name|int
name|zero_length_line_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|driver_extension_flag
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
name|safer_flag
decl_stmt|;
end_decl_stmt

end_unit

