begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stime -- set the system clock    Copyright (C) 1989, 1991 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* David MacKenzie<djm@ai.mit.edu> */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* Set the system time to *WHEN seconds past the start of 1970 GMT. */
end_comment

begin_function
name|int
name|stime
parameter_list|(
name|when
parameter_list|)
name|time_t
modifier|*
name|when
decl_stmt|;
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
name|tv
operator|.
name|tv_sec
operator|=
operator|*
name|when
expr_stmt|;
name|tv
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
return|return
name|settimeofday
argument_list|(
operator|&
name|tv
argument_list|,
operator|(
expr|struct
name|timezone
operator|*
operator|)
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

