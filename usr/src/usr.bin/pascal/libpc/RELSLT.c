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
literal|"@(#)RELSLT.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_expr_stmt
name|RELSLT
argument_list|(
name|size
argument_list|,
name|str1
argument_list|,
name|str2
argument_list|)
specifier|register
name|int
name|size
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|str1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|str2
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
operator|*
name|str1
operator|++
operator|==
operator|*
name|str2
operator|++
operator|&&
operator|--
name|size
condition|)
comment|/* void */
empty_stmt|;
if|if
condition|(
operator|(
name|size
operator|==
literal|0
operator|)
operator|||
operator|(
operator|*
operator|--
name|str1
operator|>=
operator|*
operator|--
name|str2
operator|)
condition|)
return|return
name|FALSE
return|;
return|return
name|TRUE
return|;
block|}
end_block

end_unit

