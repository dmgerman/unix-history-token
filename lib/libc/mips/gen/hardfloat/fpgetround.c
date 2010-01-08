begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fpgetround.c,v 1.5 2005/12/24 23:10:08 perry Exp $	*/
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: fpgetround.c,v 1.5 2005/12/24 23:10:08 perry Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__weak_alias
end_ifdef

begin_macro
name|__weak_alias
argument_list|(
argument|fpgetround
argument_list|,
argument|_fpgetround
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|fp_rnd_t
name|fpgetround
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
asm|__asm("cfc1 %0,$31" : "=r" (x));
return|return
name|x
operator|&
literal|0x03
return|;
block|}
end_function

end_unit

