begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Free Software Foundation, Inc. This file is part of the GNU C Library.  The GNU C Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU C Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU C Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* Prototypes for memcpy, memmove, memset, etc */
end_comment

begin_include
include|#
directive|include
file|"mmalloc.h"
end_include

begin_comment
comment|/* Allocate an array of NMEMB elements each SIZE bytes long.    The entire array is initialized to zeros.  */
end_comment

begin_function
name|PTR
name|mcalloc
parameter_list|(
name|md
parameter_list|,
name|nmemb
parameter_list|,
name|size
parameter_list|)
name|PTR
name|md
decl_stmt|;
specifier|register
name|size_t
name|nmemb
decl_stmt|;
specifier|register
name|size_t
name|size
decl_stmt|;
block|{
specifier|register
name|PTR
name|result
decl_stmt|;
if|if
condition|(
operator|(
name|result
operator|=
name|mmalloc
argument_list|(
name|md
argument_list|,
name|nmemb
operator|*
name|size
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|memset
argument_list|(
name|result
argument_list|,
literal|0
argument_list|,
name|nmemb
operator|*
name|size
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_comment
comment|/* When using this package, provide a version of malloc/realloc/free built    on top of it, so that if we use the default sbrk() region we will not    collide with another malloc package trying to do the same thing, if    the application contains any "hidden" calls to malloc/realloc/free (such    as inside a system library). */
end_comment

begin_function
name|PTR
name|calloc
parameter_list|(
name|nmemb
parameter_list|,
name|size
parameter_list|)
name|size_t
name|nmemb
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|{
return|return
operator|(
name|mcalloc
argument_list|(
operator|(
name|PTR
operator|)
name|NULL
argument_list|,
name|nmemb
argument_list|,
name|size
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

