begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)gmtime_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * return broken down time  *  * calling sequence:  *	integer time, t[9]  *	call gmtime(time, t)  * where:  *	time is a system time. (see time(3F))  *	t will receive the broken down time assuming GMT.  *	(see ctime(3))  */
end_comment

begin_function_decl
name|int
modifier|*
name|gmtime
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|gmtime_
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
name|g
decl_stmt|;
name|g
operator|=
name|gmtime
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
name|g
operator|++
expr_stmt|;
block|}
end_block

end_unit

