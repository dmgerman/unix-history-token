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
literal|"@(#)point.c	4.1 (Berkeley) 6/27/83"
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

begin_macro
name|point
argument_list|(
argument|xi
argument_list|,
argument|yi
argument_list|)
end_macro

begin_block
block|{
name|move
argument_list|(
name|xi
argument_list|,
name|yi
argument_list|)
expr_stmt|;
name|label
argument_list|(
literal|"."
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

