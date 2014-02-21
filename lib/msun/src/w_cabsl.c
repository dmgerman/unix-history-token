begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * cabs() wrapper for hypot().  *  * Written by J.T. Conklin,<jtc@wimsey.com>  * Placed into the Public Domain, 1994.  *  * Modified by Steven G. Kargl for the long double type.  */
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
file|<math.h>
end_include

begin_function
name|long
name|double
name|cabsl
parameter_list|(
name|long
name|double
name|complex
name|z
parameter_list|)
block|{
return|return
name|hypotl
argument_list|(
name|creall
argument_list|(
name|z
argument_list|)
argument_list|,
name|cimagl
argument_list|(
name|z
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

