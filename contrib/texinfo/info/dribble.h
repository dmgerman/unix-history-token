begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dribble.h -- Functions and vars declared in dribble.c. */
end_comment

begin_comment
comment|/* This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_DRIBBLE_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DRIBBLE_H_
end_define

begin_comment
comment|/* When non-zero, it is a stream to write all input characters to for the    duration of this info session. */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|info_dribble_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open a dribble file named NAME, perhaps closing an already open one.    This sets the global variable INFO_DRIBBLE_FILE to the open stream. */
end_comment

begin_function_decl
specifier|extern
name|void
name|open_dribble_file
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* If there is a dribble file already open, close it. */
end_comment

begin_function_decl
specifier|extern
name|void
name|close_dribble_file
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Write some output to our existing dribble file. */
end_comment

begin_function_decl
specifier|extern
name|void
name|dribble
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DRIBBLE_H_ */
end_comment

end_unit

