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
literal|"@(#)space.c	4.1 (Berkeley) 6/27/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"con.h"
end_include

begin_decl_stmt
name|float
name|deltx
init|=
literal|4095.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|delty
init|=
literal|4095.
decl_stmt|;
end_decl_stmt

begin_macro
name|space
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
name|botx
operator|=
operator|-
literal|2047.
expr_stmt|;
name|boty
operator|=
operator|-
literal|2047.
expr_stmt|;
name|obotx
operator|=
name|x0
expr_stmt|;
name|oboty
operator|=
name|y0
expr_stmt|;
name|scalex
operator|=
name|deltx
operator|/
operator|(
name|x1
operator|-
name|x0
operator|)
expr_stmt|;
name|scaley
operator|=
name|delty
operator|/
operator|(
name|y1
operator|-
name|y0
operator|)
expr_stmt|;
block|}
end_block

end_unit

