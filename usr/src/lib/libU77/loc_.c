begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)loc_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * Return the address of the argument.  *  * calling sequence:  *	iloc = loc (arg)  * where:  *	iloc will receive the address of arg  */
end_comment

begin_function
name|long
name|loc_
parameter_list|(
name|arg
parameter_list|)
name|long
modifier|*
name|arg
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|long
operator|)
name|arg
operator|)
return|;
block|}
end_function

end_unit

