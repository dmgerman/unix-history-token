begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xmalloc.c -- malloc with out of memory checking     Copyright (C) 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2002, 2003, 2004, 2005, 2006 Free Software Foundation,    Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_INLINE
end_if

begin_define
define|#
directive|define
name|static_inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xalloc.h"
end_include

begin_undef
undef|#
directive|undef
name|static_inline
end_undef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|SIZE_MAX
value|((size_t) -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 1 if calloc is known to be compatible with GNU calloc.  This    matters if we are not also using the calloc module, which defines    HAVE_CALLOC and supports the GNU API even on non-GNU platforms.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|HAVE_CALLOC
operator|||
name|defined
name|__GLIBC__
end_if

begin_enum
enum|enum
block|{
name|HAVE_GNU_CALLOC
init|=
literal|1
block|}
enum|;
end_enum

begin_else
else|#
directive|else
end_else

begin_enum
enum|enum
block|{
name|HAVE_GNU_CALLOC
init|=
literal|0
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allocate N bytes of memory dynamically, with error checking.  */
end_comment

begin_function
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size_t
name|n
parameter_list|)
block|{
name|void
modifier|*
name|p
init|=
name|malloc
argument_list|(
name|n
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|p
operator|&&
name|n
operator|!=
literal|0
condition|)
name|xalloc_die
argument_list|()
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|/* Change the size of an allocated block of memory P to N bytes,    with error checking.  */
end_comment

begin_function
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|p
operator|=
name|realloc
argument_list|(
name|p
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p
operator|&&
name|n
operator|!=
literal|0
condition|)
name|xalloc_die
argument_list|()
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|/* If P is null, allocate a block of at least *PN bytes; otherwise,    reallocate P so that it contains more than *PN bytes.  *PN must be    nonzero unless P is null.  Set *PN to the new block's size, and    return the pointer to the new block.  *PN is never set to zero, and    the returned pointer is never null.  */
end_comment

begin_function
name|void
modifier|*
name|x2realloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
modifier|*
name|pn
parameter_list|)
block|{
return|return
name|x2nrealloc
argument_list|(
name|p
argument_list|,
name|pn
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Allocate S bytes of zeroed memory dynamically, with error checking.    There's no need for xnzalloc (N, S), since it would be equivalent    to xcalloc (N, S).  */
end_comment

begin_function
name|void
modifier|*
name|xzalloc
parameter_list|(
name|size_t
name|s
parameter_list|)
block|{
return|return
name|memset
argument_list|(
name|xmalloc
argument_list|(
name|s
argument_list|)
argument_list|,
literal|0
argument_list|,
name|s
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Allocate zeroed memory for N elements of S bytes, with error    checking.  S must be nonzero.  */
end_comment

begin_function
name|void
modifier|*
name|xcalloc
parameter_list|(
name|size_t
name|n
parameter_list|,
name|size_t
name|s
parameter_list|)
block|{
name|void
modifier|*
name|p
decl_stmt|;
comment|/* Test for overflow, since some calloc implementations don't have      proper overflow checks.  But omit overflow and size-zero tests if      HAVE_GNU_CALLOC, since GNU calloc catches overflow and never      returns NULL if successful.  */
if|if
condition|(
operator|(
operator|!
name|HAVE_GNU_CALLOC
operator|&&
name|xalloc_oversized
argument_list|(
name|n
argument_list|,
name|s
argument_list|)
operator|)
operator|||
operator|(
operator|!
operator|(
name|p
operator|=
name|calloc
argument_list|(
name|n
argument_list|,
name|s
argument_list|)
operator|)
operator|&&
operator|(
name|HAVE_GNU_CALLOC
operator|||
name|n
operator|!=
literal|0
operator|)
operator|)
condition|)
name|xalloc_die
argument_list|()
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|/* Clone an object P of size S, with error checking.  There's no need    for xnmemdup (P, N, S), since xmemdup (P, N * S) works without any    need for an arithmetic overflow check.  */
end_comment

begin_function
name|void
modifier|*
name|xmemdup
parameter_list|(
name|void
specifier|const
modifier|*
name|p
parameter_list|,
name|size_t
name|s
parameter_list|)
block|{
return|return
name|memcpy
argument_list|(
name|xmalloc
argument_list|(
name|s
argument_list|)
argument_list|,
name|p
argument_list|,
name|s
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Clone STRING.  */
end_comment

begin_function
name|char
modifier|*
name|xstrdup
parameter_list|(
name|char
specifier|const
modifier|*
name|string
parameter_list|)
block|{
return|return
name|xmemdup
argument_list|(
name|string
argument_list|,
name|strlen
argument_list|(
name|string
argument_list|)
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

end_unit

