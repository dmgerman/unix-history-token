begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)sleep_.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * sleep for awhile  *  * calling sequence:  *	call sleep(seconds)  * where:  *	seconds is an integer number of seconds to sleep (see sleep(3))  */
end_comment

begin_macro
name|sleep_
argument_list|(
argument|sec
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|sec
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sleep
argument_list|(
operator|(
name|unsigned
name|int
operator|)
operator|*
name|sec
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

