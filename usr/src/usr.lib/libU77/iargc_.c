begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)iargc_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * return the number of args on the command line following the command name  *  * calling sequence:  *	nargs = iargc()  * where:  *	nargs will be set to the number of args  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xargc
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|iargc_
parameter_list|()
block|{
return|return
operator|(
call|(
name|long
call|)
argument_list|(
name|xargc
operator|-
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

