begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Buffer primitives for comparison operations.    Copyright (C) 1993 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     */
end_comment

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"cmpbuf.h"
end_include

begin_comment
comment|/* Least common multiple of two buffer sizes A and B.  */
end_comment

begin_function
name|size_t
name|buffer_lcm
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|size_t
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
name|size_t
name|m
decl_stmt|,
name|n
decl_stmt|,
name|r
decl_stmt|;
comment|/* Yield reasonable values if buffer sizes are zero.  */
if|if
condition|(
operator|!
name|a
condition|)
return|return
name|b
condition|?
name|b
else|:
literal|8
operator|*
literal|1024
return|;
if|if
condition|(
operator|!
name|b
condition|)
return|return
name|a
return|;
comment|/* n = gcd (a, b) */
for|for
control|(
name|m
operator|=
name|a
operator|,
name|n
operator|=
name|b
init|;
operator|(
name|r
operator|=
name|m
operator|%
name|n
operator|)
operator|!=
literal|0
condition|;
name|m
operator|=
name|n
operator|,
name|n
operator|=
name|r
control|)
continue|continue;
return|return
name|a
operator|/
name|n
operator|*
name|b
return|;
block|}
end_function

end_unit

