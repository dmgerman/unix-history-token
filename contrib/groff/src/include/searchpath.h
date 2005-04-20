begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992, 2000 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_decl_stmt
name|class
name|search_path
block|{
name|char
modifier|*
name|dirs
decl_stmt|;
name|unsigned
name|init_len
decl_stmt|;
name|public
label|:
name|search_path
argument_list|(
argument|const char *envvar
argument_list|,
argument|const char *standard
argument_list|,
argument|int add_home
argument_list|,
argument|int add_current
argument_list|)
empty_stmt|;
operator|~
name|search_path
argument_list|()
expr_stmt|;
name|void
name|command_line_dir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|FILE
modifier|*
name|open_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

