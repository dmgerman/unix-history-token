begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fpsetround.c,v 1.2 2002/01/13 21:45:51 thorpej Exp $	*/
end_comment

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
file|<machine/fsr.h>
end_include

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_function
name|fp_rnd_t
name|fpsetround
parameter_list|(
name|rnd_dir
parameter_list|)
name|fp_rnd_t
name|rnd_dir
decl_stmt|;
block|{
name|unsigned
name|int
name|old
decl_stmt|;
name|unsigned
name|int
name|new
decl_stmt|;
asm|__asm__("st %%fsr,%0" : "=m" (old));
name|new
operator|=
name|old
expr_stmt|;
name|new
operator|&=
operator|~
name|FSR_RD_MASK
expr_stmt|;
name|new
operator||=
name|FSR_RD
argument_list|(
operator|(
name|unsigned
name|int
operator|)
name|rnd_dir
operator|&
literal|0x03
argument_list|)
expr_stmt|;
asm|__asm__("ld %0,%%fsr" : : "m" (new));
return|return
operator|(
operator|(
name|fp_rnd_t
operator|)
name|FSR_GET_RD
argument_list|(
name|old
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

