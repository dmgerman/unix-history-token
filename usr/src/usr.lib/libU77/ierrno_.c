begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ierrno_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * return the current value of the system error register  *  * calling sequence:  *	ier = ierrno()  * where:  *	ier will receive the current value of errno  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|ierrno_
parameter_list|()
block|{
return|return
operator|(
operator|(
name|long
operator|)
name|errno
operator|)
return|;
block|}
end_function

end_unit

