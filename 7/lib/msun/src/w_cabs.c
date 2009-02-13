begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * cabs() wrapper for hypot().  *  * Written by J.T. Conklin,<jtc@wimsey.com>  * Placed into the Public Domain, 1994.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<complex.h>
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
name|z
parameter_list|)
name|double
name|complex
name|z
decl_stmt|;
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

begin_function
name|double
name|z_abs
parameter_list|(
name|z
parameter_list|)
name|double
name|complex
modifier|*
name|z
decl_stmt|;
block|{
return|return
name|hypot
argument_list|(
name|creal
argument_list|(
operator|*
name|z
argument_list|)
argument_list|,
name|cimag
argument_list|(
operator|*
name|z
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

