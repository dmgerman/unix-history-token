begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)zabs.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_comment
comment|/* THIS IS BASED ON TAHOE FP REPRESENTATION */
end_comment

begin_include
include|#
directive|include
file|<tahoemath/FP.h>
end_include

begin_function
name|double
name|zabs
parameter_list|(
name|real
parameter_list|,
name|imag
parameter_list|)
name|double
name|real
decl_stmt|,
name|imag
decl_stmt|;
block|{
name|double
name|temp
decl_stmt|,
name|sqrt
argument_list|()
decl_stmt|;
if|if
condition|(
name|real
operator|<
literal|0
condition|)
operator|*
operator|(
name|long
name|int
operator|*
operator|)
operator|&
name|real
operator|^=
name|SIGN_BIT
expr_stmt|;
if|if
condition|(
name|imag
operator|<
literal|0
condition|)
operator|*
operator|(
name|long
name|int
operator|*
operator|)
operator|&
name|imag
operator|^=
name|SIGN_BIT
expr_stmt|;
if|if
condition|(
name|imag
operator|>
name|real
condition|)
block|{
name|temp
operator|=
name|real
expr_stmt|;
name|real
operator|=
name|imag
expr_stmt|;
name|imag
operator|=
name|temp
expr_stmt|;
block|}
if|if
condition|(
name|imag
operator|==
literal|0.
condition|)
comment|/* if((real+imag) == real) */
return|return
operator|(
name|real
operator|)
return|;
name|temp
operator|=
name|imag
operator|/
name|real
expr_stmt|;
name|temp
operator|=
name|real
operator|*
name|sqrt
argument_list|(
literal|1.0
operator|+
name|temp
operator|*
name|temp
argument_list|)
expr_stmt|;
comment|/*overflow!!*/
return|return
operator|(
name|temp
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

end_unit

