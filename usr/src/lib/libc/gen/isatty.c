begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|sccsid
index|[]
init|=
literal|"@(#)isatty.c	5.2 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * Returns 1 iff file is a tty  */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_macro
name|isatty
argument_list|(
argument|f
argument_list|)
end_macro

begin_block
block|{
name|struct
name|sgttyb
name|ttyb
decl_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|f
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|ttyb
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

end_unit

