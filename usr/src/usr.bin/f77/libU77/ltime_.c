begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)ltime_.c	5.2 (Berkeley) 4/12/91"
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
comment|/*  * return broken down time  *  * calling sequence:  *	integer time, t[9]  *	call ltime(time, t)  * where:  *	time is a  system time. (see time(3F))  *	t will receive the broken down time corrected for local timezone.  *	(see ctime(3))  */
end_comment

begin_function_decl
name|int
modifier|*
name|localtime
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|ltime_
argument_list|(
argument|clock
argument_list|,
argument|t
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|clock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
modifier|*
name|t
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
name|int
modifier|*
name|l
decl_stmt|;
name|l
operator|=
name|localtime
argument_list|(
name|clock
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|9
condition|;
name|i
operator|++
control|)
operator|*
name|t
operator|++
operator|=
operator|*
name|l
operator|++
expr_stmt|;
block|}
end_block

end_unit

