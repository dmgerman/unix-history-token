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
literal|"@(#)line.c	4.1 (Berkeley) 6/27/83"
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
name|line
argument_list|(
argument|x0
argument_list|,
argument|y0
argument_list|,
argument|x1
argument_list|,
argument|y1
argument_list|)
end_macro

begin_block
block|{
name|putc
argument_list|(
literal|'l'
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|putsi
argument_list|(
name|x0
argument_list|)
expr_stmt|;
name|putsi
argument_list|(
name|y0
argument_list|)
expr_stmt|;
name|putsi
argument_list|(
name|x1
argument_list|)
expr_stmt|;
name|putsi
argument_list|(
name|y1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

