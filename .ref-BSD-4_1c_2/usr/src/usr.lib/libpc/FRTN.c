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
literal|"@(#)FRTN.c 1.5 11/12/82"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_expr_stmt
name|FRTN
argument_list|(
name|frtn
argument_list|,
name|save
argument_list|)
specifier|register
expr|struct
name|formalrtn
operator|*
name|frtn
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|save
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|blkcpy
argument_list|(
name|save
argument_list|,
operator|&
name|_disply
index|[
literal|1
index|]
argument_list|,
name|frtn
operator|->
name|fbn
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|display
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

