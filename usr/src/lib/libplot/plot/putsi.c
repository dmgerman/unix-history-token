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
literal|"@(#)putsi.c	4.1 (Berkeley) 6/27/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|putsi
argument_list|(
argument|a
argument_list|)
end_macro

begin_block
block|{
name|putc
argument_list|(
operator|(
name|char
operator|)
name|a
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|putc
argument_list|(
call|(
name|char
call|)
argument_list|(
name|a
operator|>>
literal|8
argument_list|)
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

