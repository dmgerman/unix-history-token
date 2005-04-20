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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/float.h>
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
literal|0
block|,
comment|/* round to zero */
literal|3
block|,
comment|/* round to negative infinity */
literal|2
comment|/* round to positive infinity */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|__flt_rounds
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
asm|__asm("st %%fsr,%0" : "=m" (*&x));
return|return
name|map
index|[
operator|(
name|x
operator|>>
literal|30
operator|)
operator|&
literal|0x03
index|]
return|;
block|}
end_function

end_unit

