begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Free Software Foundation, Inc.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with this library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author may be reached (Email) at the address mike@ai.mit.edu,    or (US mail) as Mike Haertel c/o Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MALLOC_INTERNAL
end_ifndef

begin_define
define|#
directive|define
name|_MALLOC_INTERNAL
end_define

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allocate an array of NMEMB elements each SIZE bytes long.    The entire array is initialized to zeros.  */
end_comment

begin_function
name|__ptr_t
name|calloc
parameter_list|(
name|nmemb
parameter_list|,
name|size
parameter_list|)
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
name|__ptr_t
name|result
init|=
name|malloc
argument_list|(
name|nmemb
operator|*
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
name|NULL
condition|)
operator|(
name|void
operator|)
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
return|return
name|result
return|;
block|}
end_function

end_unit

