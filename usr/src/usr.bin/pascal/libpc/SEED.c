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
literal|"@(#)SEED.c 1.4 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_macro
name|SEED
argument_list|(
argument|value
argument_list|)
end_macro

begin_decl_stmt
name|long
name|value
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|tmp
decl_stmt|;
name|tmp
operator|=
name|_seed
expr_stmt|;
name|_seed
operator|=
name|value
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_block

end_unit

