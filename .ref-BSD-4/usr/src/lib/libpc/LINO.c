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
literal|"@(#)LINO.c 1.1 10/29/80"
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

begin_macro
name|LINO
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|++
name|_stcnt
operator|>=
name|_stlim
condition|)
block|{
name|ERROR
argument_list|(
name|ESTLIM
argument_list|,
name|_stcnt
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_block

end_unit

