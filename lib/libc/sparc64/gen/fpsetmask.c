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
file|<ieeefp.h>
end_include

begin_function
name|fp_except_t
name|fpsetmask
parameter_list|(
name|mask
parameter_list|)
name|fp_except_t
name|mask
decl_stmt|;
block|{
name|fp_except_t
name|old
decl_stmt|;
name|fp_except_t
name|new
decl_stmt|;
asm|__asm__("st %%fsr,%0" : "=m" (*&old));
name|new
operator|=
name|old
expr_stmt|;
name|new
operator|&=
operator|~
operator|(
literal|0x1f
operator|<<
literal|23
operator|)
expr_stmt|;
name|new
operator||=
operator|(
operator|(
name|mask
operator|&
literal|0x1f
operator|)
operator|<<
literal|23
operator|)
expr_stmt|;
asm|__asm__("ld %0,%%fsr" : : "m" (*&new));
return|return
operator|(
name|old
operator|>>
literal|23
operator|)
operator|&
literal|0x1f
return|;
block|}
end_function

end_unit

