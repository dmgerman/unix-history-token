begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992, 2000, 2001    Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
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
file|"lib.h"
end_include

begin_include
include|#
directive|include
file|"assert.h"
end_include

begin_include
include|#
directive|include
file|"device.h"
end_include

begin_include
include|#
directive|include
file|"searchpath.h"
end_include

begin_function_decl
name|void
name|cleanup_and_exit
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
name|units
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|units
name|scale
parameter_list|(
name|units
name|n
parameter_list|,
name|units
name|x
parameter_list|,
name|units
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// scale n by x/y
end_comment

begin_decl_stmt
specifier|extern
name|units
name|units_per_inch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ascii_output_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|suppress_output_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_html
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcommand_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vresolution
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hresolution
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sizescale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|search_path
modifier|*
name|mac_path
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"cset.h"
end_include

begin_include
include|#
directive|include
file|"cmap.h"
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

begin_enum
enum|enum
name|warning_type
block|{
name|WARN_CHAR
init|=
literal|01
block|,
name|WARN_NUMBER
init|=
literal|02
block|,
name|WARN_BREAK
init|=
literal|04
block|,
name|WARN_DELIM
init|=
literal|010
block|,
name|WARN_EL
init|=
literal|020
block|,
name|WARN_SCALE
init|=
literal|040
block|,
name|WARN_RANGE
init|=
literal|0100
block|,
name|WARN_SYNTAX
init|=
literal|0200
block|,
name|WARN_DI
init|=
literal|0400
block|,
name|WARN_MAC
init|=
literal|01000
block|,
name|WARN_REG
init|=
literal|02000
block|,
name|WARN_TAB
init|=
literal|04000
block|,
name|WARN_RIGHT_BRACE
init|=
literal|010000
block|,
name|WARN_MISSING
init|=
literal|020000
block|,
name|WARN_INPUT
init|=
literal|040000
block|,
name|WARN_ESCAPE
init|=
literal|0100000
block|,
name|WARN_SPACE
init|=
literal|0200000
block|,
name|WARN_FONT
init|=
literal|0400000
block|,
name|WARN_IG
init|=
literal|01000000
comment|// change WARN_TOTAL if you add more warning types
block|}
enum|;
end_enum

begin_decl_stmt
specifier|const
name|int
name|WARN_TOTAL
init|=
literal|01777777
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|warning
parameter_list|(
name|warning_type
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|errarg
modifier|&
init|=
name|empty_errarg
parameter_list|,
specifier|const
name|errarg
modifier|&
init|=
name|empty_errarg
parameter_list|,
specifier|const
name|errarg
modifier|&
init|=
name|empty_errarg
parameter_list|)
function_decl|;
end_function_decl

end_unit

