begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function
name|double
name|fmod
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|double
name|x
decl_stmt|,
name|y
decl_stmt|;
block|{
name|double
name|quot
init|=
name|x
operator|/
name|y
decl_stmt|;
return|return
name|x
operator|-
operator|(
name|quot
operator|<
literal|0.0
condition|?
name|ceil
argument_list|(
name|quot
argument_list|)
else|:
name|floor
argument_list|(
name|quot
argument_list|)
operator|)
operator|*
name|y
return|;
block|}
end_function

end_unit

