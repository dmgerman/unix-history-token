begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tailor.c -- target dependent functions  * Copyright (C) 1992-1993 Jean-loup Gailly  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  */
end_comment

begin_comment
comment|/* tailor.c is a bunch of non portable routines.  * It should be kept to a minimum.  */
end_comment

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_include
include|#
directive|include
file|"gzip.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: tailor.c,v 0.8 1993/02/24 18:24:54 jloup Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_comment
comment|/************************/
end_comment

begin_comment
comment|/*  Function fcalloc()  */
end_comment

begin_comment
comment|/************************/
end_comment

begin_comment
comment|/* Turbo C malloc() does not allow dynamic allocation of 64K bytes  * and farmalloc(64K) returns a pointer with an offset of 8, so we  * must fix the pointer. Warning: the pointer must be put back to its  * original form in order to free it, use fcfree().  * For MSC, use halloc instead of this function (see tailor.h).  */
end_comment

begin_decl_stmt
specifier|static
name|ush
name|ptr_offset
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|fcalloc
parameter_list|(
name|items
parameter_list|,
name|size
parameter_list|)
name|unsigned
name|items
decl_stmt|;
comment|/* number of items */
name|unsigned
name|size
decl_stmt|;
comment|/* item size */
block|{
name|void
modifier|*
name|buf
init|=
name|farmalloc
argument_list|(
operator|(
name|ulg
operator|)
name|items
operator|*
name|size
operator|+
literal|16L
argument_list|)
decl_stmt|;
if|if
condition|(
name|buf
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
comment|/* Normalize the pointer to seg:0 */
if|if
condition|(
name|ptr_offset
operator|==
literal|0
condition|)
block|{
name|ptr_offset
operator|=
call|(
name|ush
call|)
argument_list|(
operator|(
name|uch
operator|*
operator|)
name|buf
operator|-
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ptr_offset
operator|!=
call|(
name|ush
call|)
argument_list|(
operator|(
name|uch
operator|*
operator|)
name|buf
operator|-
literal|0
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"inconsistent ptr_offset"
argument_list|)
expr_stmt|;
block|}
operator|*
operator|(
operator|(
name|ush
operator|*
operator|)
operator|&
name|buf
operator|+
literal|1
operator|)
operator|+=
operator|(
name|ptr_offset
operator|+
literal|15
operator|)
operator|>>
literal|4
expr_stmt|;
operator|*
operator|(
name|ush
operator|*
operator|)
operator|&
name|buf
operator|=
literal|0
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

begin_function
name|void
name|fcfree
parameter_list|(
name|ptr
parameter_list|)
name|void
modifier|*
name|ptr
decl_stmt|;
comment|/* region allocated with fcalloc() */
block|{
comment|/* Put the pointer back to its original form: */
operator|*
operator|(
operator|(
name|ush
operator|*
operator|)
operator|&
name|ptr
operator|+
literal|1
operator|)
operator|-=
operator|(
name|ptr_offset
operator|+
literal|15
operator|)
operator|>>
literal|4
expr_stmt|;
operator|*
operator|(
name|ush
operator|*
operator|)
operator|&
name|ptr
operator|=
name|ptr_offset
expr_stmt|;
name|farfree
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TURBOC__ */
end_comment

end_unit

