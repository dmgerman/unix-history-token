begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)proc.c	1.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_empty
empty|#
end_empty

begin_comment
comment|/*  * pxp - Pascal execution profiler  *  * Bill Joy UCB  * Version 1.2 January 1979  */
end_comment

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_macro
name|proc
argument_list|(
argument|r
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|r
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|call
argument_list|(
name|r
index|[
literal|2
index|]
argument_list|,
name|r
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

