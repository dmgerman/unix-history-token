begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_define
define|#
directive|define
name|INDEX_MAGIC
value|0x23021964
end_define

begin_define
define|#
directive|define
name|INDEX_VERSION
value|1
end_define

begin_struct
struct|struct
name|index_header
block|{
name|int
name|magic
decl_stmt|;
name|int
name|version
decl_stmt|;
name|int
name|tags_size
decl_stmt|;
name|int
name|table_size
decl_stmt|;
name|int
name|lists_size
decl_stmt|;
name|int
name|strings_size
decl_stmt|;
name|int
name|truncate
decl_stmt|;
name|int
name|shortest
decl_stmt|;
name|int
name|common
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tag
block|{
name|int
name|filename_index
decl_stmt|;
name|int
name|start
decl_stmt|;
name|int
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|unsigned
name|hash
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

end_unit

