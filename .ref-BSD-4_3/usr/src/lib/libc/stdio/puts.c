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
literal|"@(#)puts.c	5.2 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_expr_stmt
name|puts
argument_list|(
name|s
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|c
expr_stmt|;
while|while
condition|(
name|c
operator|=
operator|*
name|s
operator|++
condition|)
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
return|return
operator|(
name|putchar
argument_list|(
literal|'\n'
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

