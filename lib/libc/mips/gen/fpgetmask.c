begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by J.T. Conklin, Apr 11, 1995  * Public domain.  */
end_comment

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

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$OpenBSD$"
decl_stmt|;
end_decl_stmt

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
file|<ieeefp.h>
end_include

begin_function
name|fp_except
name|fpgetmask
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
asm|__asm__("cfc1 %0,$31" : "=r" (x));
return|return
operator|(
name|x
operator|>>
literal|7
operator|)
operator|&
literal|0x1f
return|;
block|}
end_function

end_unit

