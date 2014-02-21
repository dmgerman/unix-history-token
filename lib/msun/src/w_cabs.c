begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * cabs() wrapper for hypot().  *  * Written by J.T. Conklin,<jtc@wimsey.com>  * Placed into the Public Domain, 1994.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<complex.h>
end_include

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function
name|double
name|cabs
parameter_list|(
name|double
name|complex
name|z
parameter_list|)
block|{
return|return
name|hypot
argument_list|(
name|creal
argument_list|(
name|z
argument_list|)
argument_list|,
name|cimag
argument_list|(
name|z
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|LDBL_MANT_DIG
operator|==
literal|53
end_if

begin_expr_stmt
name|__weak_reference
argument_list|(
name|cabs
argument_list|,
name|cabsl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

