begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)short_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * convert long ints to short.  *  * used as follows:  *	integer*2 short  *	...  *	call mysub(short(ivar))  * where:  *	mysub expects to receive an integer*2 arg and ivar is integer*4  */
end_comment

begin_function
name|short
name|short_
parameter_list|(
name|i
parameter_list|)
name|long
modifier|*
name|i
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|short
operator|)
operator|*
name|i
operator|)
return|;
block|}
end_function

end_unit

