begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)putchar.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * A subroutine version of the macro putchar  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_expr_stmt
name|putchar
argument_list|(
name|c
argument_list|)
specifier|register
name|c
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|putc
argument_list|(
name|c
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

