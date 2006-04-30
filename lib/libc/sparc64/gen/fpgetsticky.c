begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fpgetsticky.c,v 1.2 2002/01/13 21:45:50 thorpej Exp $	*/
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
name|fpgetsticky
parameter_list|()
block|{
name|unsigned
name|int
name|x
decl_stmt|;
asm|__asm__("st %%fsr,%0" : "=m" (x));
return|return
operator|(
name|FSR_GET_AEXC
argument_list|(
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

