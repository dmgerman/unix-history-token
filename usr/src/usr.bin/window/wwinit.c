begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)wwinit.c	1.1 83/07/12"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_decl_stmt
name|int
name|_wwiflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_macro
name|wwinit
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|_wwiflag
condition|)
return|return;
name|_wwiflag
operator|++
expr_stmt|;
name|initscr
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

