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
literal|"@(#)printf.c	5.2 (Berkeley) %G%"
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

begin_macro
name|printf
argument_list|(
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|_doprnt
argument_list|(
name|fmt
argument_list|,
operator|&
name|args
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
return|return
operator|(
name|ferror
argument_list|(
name|stdout
argument_list|)
condition|?
name|EOF
else|:
literal|0
operator|)
return|;
block|}
end_block

end_unit

