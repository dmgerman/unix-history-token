begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)setbps.c 1.1 1/18/82"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * set all breakpoints in object code  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_include
include|#
directive|include
file|"bp.rep"
end_include

begin_macro
name|setallbps
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|BPINFO
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
name|bphead
init|;
name|p
operator|!=
name|NIL
condition|;
name|p
operator|=
name|p
operator|->
name|bpnext
control|)
block|{
name|setbp
argument_list|(
name|p
operator|->
name|bpaddr
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * undo damage done by "setallbps"  */
end_comment

begin_macro
name|unsetallbps
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|BPINFO
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
name|bphead
init|;
name|p
operator|!=
name|NIL
condition|;
name|p
operator|=
name|p
operator|->
name|bpnext
control|)
block|{
name|unsetbp
argument_list|(
name|p
operator|->
name|bpaddr
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

