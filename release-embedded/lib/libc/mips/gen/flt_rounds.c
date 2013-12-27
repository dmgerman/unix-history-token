begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: flt_rounds.c,v 1.5 2005/12/24 23:10:08 perry Exp $	*/
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
literal|"$NetBSD: flt_rounds.c,v 1.5 2005/12/24 23:10:08 perry Exp $"
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
literal|2
block|,
comment|/* round to positive infinity */
literal|3
comment|/* round to negative infinity */
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
asm|__asm("cfc1 %0,$31" : "=r" (x));
return|return
name|map
index|[
name|x
operator|&
literal|0x03
index|]
return|;
block|}
end_function

end_unit

