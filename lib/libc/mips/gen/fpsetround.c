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
name|fpsetround
parameter_list|(
name|rnd_dir
parameter_list|)
name|fp_rnd
name|rnd_dir
decl_stmt|;
block|{
name|fp_rnd
name|old
decl_stmt|;
name|fp_rnd
name|new
decl_stmt|;
asm|__asm__("cfc1 %0,$31" : "=r" (old));
name|new
operator|=
name|old
expr_stmt|;
name|new
operator|&=
operator|~
literal|0x03
expr_stmt|;
name|new
operator||=
operator|(
name|rnd_dir
operator|&
literal|0x03
operator|)
expr_stmt|;
asm|__asm__("ctc1 %0,$31" : : "r" (new));
return|return
name|old
operator|&
literal|0x03
return|;
block|}
end_function

end_unit

