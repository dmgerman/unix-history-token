begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ttoutput.c	3.3 %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California,  * All rights reserved.  Redistribution permitted subject to  * the terms of the Berkeley Software License Agreement.  */
end_comment

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|"tt.h"
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_comment
comment|/*  * Buffered output package.  * We need this because stdio fails on non-blocking writes.  */
end_comment

begin_macro
name|ttflush
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|n
expr_stmt|;
extern|extern errno;
name|wwnflush
operator|++
expr_stmt|;
for|for
control|(
name|p
operator|=
name|tt_ob
init|;
name|p
operator|<
name|tt_obp
condition|;
control|)
block|{
name|wwnwr
operator|++
expr_stmt|;
name|n
operator|=
name|write
argument_list|(
literal|1
argument_list|,
name|p
argument_list|,
name|tt_obp
operator|-
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
name|wwnwre
operator|++
expr_stmt|;
if|if
condition|(
name|errno
operator|!=
name|EWOULDBLOCK
condition|)
block|{
comment|/* can't deal with this */
name|p
operator|=
name|tt_obp
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|n
operator|==
literal|0
condition|)
block|{
comment|/* what to do? */
name|wwnwrz
operator|++
expr_stmt|;
block|}
else|else
block|{
name|wwnwrc
operator|+=
name|n
expr_stmt|;
name|p
operator|+=
name|n
expr_stmt|;
block|}
block|}
name|tt_obp
operator|=
name|tt_ob
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ttputs
argument_list|(
name|s
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_block
block|{
while|while
condition|(
operator|*
name|s
condition|)
name|ttputc
argument_list|(
operator|*
name|s
operator|++
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

