begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xwrite.c -- write with error checking    Copyright (C) 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|STDC_HEADERS
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Write plus error check. */
end_comment

begin_function
name|void
name|xwrite
parameter_list|(
name|fd
parameter_list|,
name|buffer
parameter_list|,
name|count
parameter_list|)
name|int
name|fd
decl_stmt|;
name|int
name|count
decl_stmt|;
name|char
modifier|*
name|buffer
decl_stmt|;
block|{
name|fd
operator|=
name|write
argument_list|(
name|fd
argument_list|,
name|buffer
argument_list|,
name|count
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|!=
name|count
condition|)
name|error
argument_list|(
literal|1
argument_list|,
name|errno
argument_list|,
literal|"write error"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

