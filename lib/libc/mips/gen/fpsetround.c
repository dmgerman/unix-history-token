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

