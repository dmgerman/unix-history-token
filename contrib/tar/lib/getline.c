begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getline.c -- Replacement for GNU C library function getline  Copyright (C) 1993, 1996, 1997, 1998, 2000 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/* Written by Jan Brittenson, bson@gnu.ai.mit.edu.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The `getdelim' function is only declared if the following symbol    is defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|defined
name|__GNU_LIBRARY__
operator|&&
name|HAVE_GETDELIM
end_if

begin_function
name|int
name|getline
parameter_list|(
name|char
modifier|*
modifier|*
name|lineptr
parameter_list|,
name|size_t
modifier|*
name|n
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
block|{
return|return
name|getdelim
argument_list|(
name|lineptr
argument_list|,
name|n
argument_list|,
literal|'\n'
argument_list|,
name|stream
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! have getdelim */
end_comment

begin_include
include|#
directive|include
file|"getstr.h"
end_include

begin_function
name|int
name|getline
parameter_list|(
name|char
modifier|*
modifier|*
name|lineptr
parameter_list|,
name|size_t
modifier|*
name|n
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
block|{
return|return
name|getstr
argument_list|(
name|lineptr
argument_list|,
name|n
argument_list|,
name|stream
argument_list|,
literal|'\n'
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|getdelim
parameter_list|(
name|char
modifier|*
modifier|*
name|lineptr
parameter_list|,
name|size_t
modifier|*
name|n
parameter_list|,
name|int
name|delimiter
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
block|{
return|return
name|getstr
argument_list|(
name|lineptr
argument_list|,
name|n
argument_list|,
name|stream
argument_list|,
name|delimiter
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

