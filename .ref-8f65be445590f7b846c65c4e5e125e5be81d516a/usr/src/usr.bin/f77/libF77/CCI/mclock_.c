begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.proprietary.c%  */
end_comment

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
literal|"@(#)mclock_.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_function
name|long
name|int
name|mclock_
parameter_list|()
block|{
name|int
name|buf
index|[
literal|6
index|]
decl_stmt|;
name|times
argument_list|(
name|buf
argument_list|)
expr_stmt|;
return|return
operator|(
name|buf
index|[
literal|0
index|]
operator|+
name|buf
index|[
literal|2
index|]
operator|+
name|buf
index|[
literal|3
index|]
operator|)
return|;
block|}
end_function

end_unit

