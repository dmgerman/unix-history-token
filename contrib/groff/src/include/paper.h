begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 2002 Free Software Foundation, Inc.      Written by Werner Lemberg (wl@gnu.org)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin St - Fifth Floor, Boston, MA 02110-1301, USA. */
end_comment

begin_struct
struct|struct
name|paper
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|double
name|length
decl_stmt|;
comment|// in PS points
name|double
name|width
decl_stmt|;
comment|// in PS points
block|}
struct|;
end_struct

begin_comment
comment|// global constructor
end_comment

begin_decl_stmt
specifier|static
name|class
name|papersize_init
block|{
specifier|static
name|int
name|initialised
decl_stmt|;
name|public
label|:
name|papersize_init
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|_papersize_init
expr_stmt|;
end_expr_stmt

begin_comment
comment|// A0-A7, B0-B7, C0-C7, D0-D7, 8 American paper sizes, 1 special size */
end_comment

begin_define
define|#
directive|define
name|NUM_PAPERSIZES
value|4*8 + 8 + 1
end_define

begin_decl_stmt
specifier|extern
name|paper
name|papersizes
index|[]
decl_stmt|;
end_decl_stmt

end_unit

