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
literal|"@(#)INCT.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_expr_stmt
name|INCT
argument_list|(
name|element
argument_list|,
name|paircnt
argument_list|,
name|singcnt
argument_list|,
name|data
argument_list|)
specifier|register
name|int
name|element
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* element to find */
end_comment

begin_decl_stmt
name|int
name|paircnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of pairs to check */
end_comment

begin_decl_stmt
name|int
name|singcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of singles to check */
end_comment

begin_decl_stmt
name|int
name|data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* paircnt plus singcnt bounds */
end_comment

begin_block
block|{
specifier|register
name|int
modifier|*
name|dataptr
decl_stmt|;
specifier|register
name|int
name|cnt
decl_stmt|;
name|dataptr
operator|=
operator|&
name|data
expr_stmt|;
for|for
control|(
name|cnt
operator|=
literal|0
init|;
name|cnt
operator|<
name|paircnt
condition|;
name|cnt
operator|++
control|)
block|{
if|if
condition|(
name|element
operator|>
operator|*
name|dataptr
operator|++
condition|)
block|{
name|dataptr
operator|++
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|element
operator|>=
operator|*
name|dataptr
operator|++
condition|)
block|{
return|return
name|TRUE
return|;
block|}
block|}
for|for
control|(
name|cnt
operator|=
literal|0
init|;
name|cnt
operator|<
name|singcnt
condition|;
name|cnt
operator|++
control|)
block|{
if|if
condition|(
name|element
operator|==
operator|*
name|dataptr
operator|++
condition|)
block|{
return|return
name|TRUE
return|;
block|}
block|}
return|return
name|FALSE
return|;
block|}
end_block

end_unit

