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
literal|"@(#)getlog_.c	5.2 (Berkeley) %G%"
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

