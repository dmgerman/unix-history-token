begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)getuid_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * get user id  *  * calling sequence:  *	integer getuid, uid  *	uid = getuid()  * where:  *	uid will be the real user id  */
end_comment

begin_function
name|long
name|getuid_
parameter_list|()
block|{
return|return
operator|(
operator|(
name|long
operator|)
name|getuid
argument_list|()
operator|)
return|;
block|}
end_function

end_unit

