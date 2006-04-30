begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xsize.h -- Checked size_t computations.     Copyright (C) 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XSIZE_H
end_ifndef

begin_define
define|#
directive|define
name|_XSIZE_H
end_define

begin_comment
comment|/* Get size_t.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* Get SIZE_MAX.  */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STDINT_H
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The size of memory objects is often computed through expressions of    type size_t. Example:       void* p = malloc (header_size + n * element_size).    These computations can lead to overflow.  When this happens, malloc()    returns a piece of memory that is way too small, and the program then    crashes while attempting to fill the memory.    To avoid this, the functions and macros in this file check for overflow.    The convention is that SIZE_MAX represents overflow.    malloc (SIZE_MAX) is not guaranteed to fail -- think of a malloc    implementation that uses mmap --, it's recommended to use size_overflow_p()    or size_in_bounds_p() before invoking malloc().    The example thus becomes:       size_t size = xsum (header_size, xtimes (n, element_size));       void *p = (size_in_bounds_p (size) ? malloc (size) : NULL); */
end_comment

begin_comment
comment|/* Convert an arbitrary value>= 0 to type size_t.  */
end_comment

begin_define
define|#
directive|define
name|xcast_size_t
parameter_list|(
name|N
parameter_list|)
define|\
value|((N)<= SIZE_MAX ? (size_t) (N) : SIZE_MAX)
end_define

begin_comment
comment|/* Sum of two sizes, with overflow check.  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|size_t
if|#
directive|if
name|__GNUC__
operator|>=
literal|3
name|__attribute__
argument_list|(
operator|(
name|__pure__
operator|)
argument_list|)
endif|#
directive|endif
name|xsum
argument_list|(
name|size_t
name|size1
argument_list|,
name|size_t
name|size2
argument_list|)
block|{
name|size_t
name|sum
init|=
name|size1
operator|+
name|size2
decl_stmt|;
return|return
operator|(
name|sum
operator|>=
name|size1
condition|?
name|sum
else|:
name|SIZE_MAX
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* Sum of three sizes, with overflow check.  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|size_t
if|#
directive|if
name|__GNUC__
operator|>=
literal|3
name|__attribute__
argument_list|(
operator|(
name|__pure__
operator|)
argument_list|)
endif|#
directive|endif
name|xsum3
argument_list|(
name|size_t
name|size1
argument_list|,
name|size_t
name|size2
argument_list|,
name|size_t
name|size3
argument_list|)
block|{
return|return
name|xsum
argument_list|(
name|xsum
argument_list|(
name|size1
argument_list|,
name|size2
argument_list|)
argument_list|,
name|size3
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* Sum of four sizes, with overflow check.  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|size_t
if|#
directive|if
name|__GNUC__
operator|>=
literal|3
name|__attribute__
argument_list|(
operator|(
name|__pure__
operator|)
argument_list|)
endif|#
directive|endif
name|xsum4
argument_list|(
name|size_t
name|size1
argument_list|,
name|size_t
name|size2
argument_list|,
name|size_t
name|size3
argument_list|,
name|size_t
name|size4
argument_list|)
block|{
return|return
name|xsum
argument_list|(
name|xsum
argument_list|(
name|xsum
argument_list|(
name|size1
argument_list|,
name|size2
argument_list|)
argument_list|,
name|size3
argument_list|)
argument_list|,
name|size4
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* Maximum of two sizes, with overflow check.  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|size_t
if|#
directive|if
name|__GNUC__
operator|>=
literal|3
name|__attribute__
argument_list|(
operator|(
name|__pure__
operator|)
argument_list|)
endif|#
directive|endif
name|xmax
argument_list|(
name|size_t
name|size1
argument_list|,
name|size_t
name|size2
argument_list|)
block|{
comment|/* No explicit check is needed here, because for any n:      max (SIZE_MAX, n) == SIZE_MAX and max (n, SIZE_MAX) == SIZE_MAX.  */
return|return
operator|(
name|size1
operator|>=
name|size2
condition|?
name|size1
else|:
name|size2
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* Multiplication of a count with an element size, with overflow check.    The count must be>= 0 and the element size must be> 0.    This is a macro, not an inline function, so that it works correctly even    when N is of a wider tupe and N> SIZE_MAX.  */
end_comment

begin_define
define|#
directive|define
name|xtimes
parameter_list|(
name|N
parameter_list|,
name|ELSIZE
parameter_list|)
define|\
value|((N)<= SIZE_MAX / (ELSIZE) ? (size_t) (N) * (ELSIZE) : SIZE_MAX)
end_define

begin_comment
comment|/* Check for overflow.  */
end_comment

begin_define
define|#
directive|define
name|size_overflow_p
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|((SIZE) == SIZE_MAX)
end_define

begin_comment
comment|/* Check against overflow.  */
end_comment

begin_define
define|#
directive|define
name|size_in_bounds_p
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|((SIZE) != SIZE_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XSIZE_H */
end_comment

end_unit

