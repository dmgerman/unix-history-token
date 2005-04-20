begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fpsetsticky.c,v 1.2 2002/01/13 21:45:51 thorpej Exp $	*/
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
name|fp_except_t
name|fpsetsticky
parameter_list|(
name|sticky
parameter_list|)
name|fp_except_t
name|sticky
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
name|FSR_AEXC_MASK
expr_stmt|;
name|new
operator||=
name|FSR_AEXC
argument_list|(
name|sticky
operator|&
name|FSR_EXC_MASK
argument_list|)
expr_stmt|;
asm|__asm__("ld %0,%%fsr" : : "m" (new));
return|return
operator|(
name|FSR_GET_AEXC
argument_list|(
name|old
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

