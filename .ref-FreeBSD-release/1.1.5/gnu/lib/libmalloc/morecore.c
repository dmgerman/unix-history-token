begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Free Software Foundation, Inc. This file is part of the GNU C Library.  The GNU C Library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  The GNU C Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with the GNU C Library; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|__GNU_LIBRARY__
end_ifndef

begin_define
define|#
directive|define
name|__sbrk
value|sbrk
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|__ptr_t
name|__sbrk
name|__P
argument_list|(
operator|(
name|int
name|increment
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allocate INCREMENT more bytes of data space,    and return the start of data space, or NULL on errors.    If INCREMENT is negative, shrink data space.  */
end_comment

begin_function
name|__ptr_t
name|__default_morecore
parameter_list|(
name|increment
parameter_list|)
name|ptrdiff_t
name|increment
decl_stmt|;
block|{
name|__ptr_t
name|result
init|=
name|__sbrk
argument_list|(
operator|(
name|int
operator|)
name|increment
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|==
operator|(
name|__ptr_t
operator|)
operator|-
literal|1
condition|)
return|return
name|NULL
return|;
return|return
name|result
return|;
block|}
end_function

end_unit

