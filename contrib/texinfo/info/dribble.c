begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dribble.c -- dribble files for Info.     Copyright (C) 1993, 98 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_include
include|#
directive|include
file|"dribble.h"
end_include

begin_comment
comment|/* When non-zero, it is a stream to write all input characters to for the    duration of this info session. */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|info_dribble_file
init|=
operator|(
name|FILE
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open a dribble file named NAME, perhaps closing an already open one.    This sets the global variable INFO_DRIBBLE_FILE to the open stream. */
end_comment

begin_function
name|void
name|open_dribble_file
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
comment|/* Perhaps close existing dribble file. */
name|close_dribble_file
argument_list|()
expr_stmt|;
comment|/* Keystrokes can be non-printable characters, so we need binary I/O.  */
name|info_dribble_file
operator|=
name|fopen
argument_list|(
name|name
argument_list|,
name|FOPEN_WBIN
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SETVBUF
argument_list|)
if|if
condition|(
name|info_dribble_file
condition|)
if|#
directive|if
name|defined
argument_list|(
name|SETVBUF_REVERSED
argument_list|)
name|setvbuf
argument_list|(
name|info_dribble_file
argument_list|,
name|_IONBF
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
name|setvbuf
argument_list|(
name|info_dribble_file
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|_IONBF
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !SETVBUF_REVERSED */
endif|#
directive|endif
comment|/* HAVE_SETVBUF */
block|}
end_function

begin_comment
comment|/* If there is a dribble file already open, close it. */
end_comment

begin_function
name|void
name|close_dribble_file
parameter_list|()
block|{
if|if
condition|(
name|info_dribble_file
condition|)
block|{
name|fflush
argument_list|(
name|info_dribble_file
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|info_dribble_file
argument_list|)
expr_stmt|;
name|info_dribble_file
operator|=
operator|(
name|FILE
operator|*
operator|)
name|NULL
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Write some output to our existing dribble file. */
end_comment

begin_function
name|void
name|dribble
parameter_list|(
name|byte
parameter_list|)
name|unsigned
name|char
name|byte
decl_stmt|;
block|{
if|if
condition|(
name|info_dribble_file
condition|)
name|fwrite
argument_list|(
operator|&
name|byte
argument_list|,
expr|sizeof
operator|(
name|unsigned
name|char
operator|)
argument_list|,
literal|1
argument_list|,
name|info_dribble_file
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

