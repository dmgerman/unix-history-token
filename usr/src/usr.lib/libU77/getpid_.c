begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)getpid_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * get process id  *  * calling sequence:  *	integer getpid, pid  *	pid = getpid()  * where:  *	pid will be the current process id  */
end_comment

begin_function
name|long
name|getpid_
parameter_list|()
block|{
return|return
operator|(
operator|(
name|long
operator|)
name|getpid
argument_list|()
operator|)
return|;
block|}
end_function

end_unit

