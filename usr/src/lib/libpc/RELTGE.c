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
literal|"@(#)RELTGE.c 1.1 10/29/80"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_macro
name|RELTGE
argument_list|(
argument|bytecnt
argument_list|,
argument|left
argument_list|,
argument|right
argument_list|)
end_macro

begin_decl_stmt
name|int
name|bytecnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|long
modifier|*
name|left
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|long
modifier|*
name|right
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|longcnt
decl_stmt|;
name|longcnt
operator|=
name|bytecnt
operator|>>
literal|2
expr_stmt|;
do|do
block|{
if|if
condition|(
operator|(
operator|*
name|right
operator|++
operator|&
operator|~
operator|*
name|left
operator|++
operator|)
operator|!=
literal|0
condition|)
return|return
name|FALSE
return|;
block|}
do|while
condition|(
operator|--
name|longcnt
condition|)
do|;
return|return
name|TRUE
return|;
block|}
end_block

end_unit

