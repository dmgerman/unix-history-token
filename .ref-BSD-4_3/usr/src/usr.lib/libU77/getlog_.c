begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)getlog_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * get login name of user  *  * calling sequence:  *	character*8 getlog, name  *	name = getlog()  * or  *	call getlog (name)  * where:  *	name will receive the login name of the user, or all blanks if  *	this is a detached process.  */
end_comment

begin_function_decl
name|char
modifier|*
name|getlogin
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|getlog_
argument_list|(
argument|name
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|l
init|=
name|getlogin
argument_list|()
decl_stmt|;
name|b_char
argument_list|(
name|l
condition|?
name|l
else|:
literal|" "
argument_list|,
name|name
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

