begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPP Library.    Copyright (C) 1986, 87, 89, 92-98, 1999 Free Software Foundation, Inc.    Contributed by Per Bothner, 1994-95.    Based on CCCP program by Paul Rubin, June 1986    Adapted to ANSI C, Richard Stallman, Jan 1987  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"output.h"
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
name|user_label_prefix
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

