begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)STLIM.c 1.2 6/10/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_macro
name|STLIM
argument_list|(
argument|limit
argument_list|)
end_macro

begin_decl_stmt
name|long
name|limit
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|_stcnt
operator|>=
name|limit
condition|)
block|{
name|ERROR
argument_list|(
literal|"Statement count limit of %D exceeded\n"
argument_list|,
name|_stcnt
argument_list|)
expr_stmt|;
return|return;
block|}
name|_stlim
operator|=
name|limit
expr_stmt|;
block|}
end_block

end_unit

