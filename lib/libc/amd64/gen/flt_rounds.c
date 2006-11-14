begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by J.T. Conklin, Apr 10, 1995  * Public domain.  */
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
file|<float.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|int
name|map
index|[]
init|=
block|{
literal|1
block|,
comment|/* round to nearest */
literal|3
block|,
comment|/* round to zero */
literal|2
block|,
comment|/* round to negative infinity */
literal|0
comment|/* round to positive infinity */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|__flt_rounds
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
comment|/* Assume that the x87 and the SSE unit agree on the rounding mode. */
asm|__asm("fnstcw %0" : "=m" (x));
return|return
operator|(
name|map
index|[
operator|(
name|x
operator|>>
literal|10
operator|)
operator|&
literal|0x03
index|]
operator|)
return|;
block|}
end_function

end_unit

