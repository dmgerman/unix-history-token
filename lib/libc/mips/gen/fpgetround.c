begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by J.T. Conklin, Apr 11, 1995  * Public domain.  */
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
file|<ieeefp.h>
end_include

begin_function
name|fp_rnd
name|fpgetround
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
asm|__asm__("cfc1 %0,$31" : "=r" (x));
return|return
name|x
operator|&
literal|0x03
return|;
block|}
end_function

end_unit

