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
literal|"@(#)TEOLN.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_include
include|#
directive|include
file|"h01errs.h"
end_include

begin_expr_stmt
name|TEOLN
argument_list|(
name|filep
argument_list|)
specifier|register
expr|struct
name|iorec
operator|*
name|filep
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|filep
operator|->
name|fblk
operator|>=
name|MAXFILES
operator|||
name|_actfile
index|[
name|filep
operator|->
name|fblk
index|]
operator|!=
name|filep
condition|)
block|{
name|ERROR
argument_list|(
name|ENOFILE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
name|IOSYNC
argument_list|(
name|filep
argument_list|)
expr_stmt|;
if|if
condition|(
name|filep
operator|->
name|funit
operator|&
name|EOLN
condition|)
return|return
name|TRUE
return|;
return|return
name|FALSE
return|;
block|}
end_block

end_unit

