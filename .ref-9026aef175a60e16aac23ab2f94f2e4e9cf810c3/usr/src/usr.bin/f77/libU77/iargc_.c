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
literal|"@(#)iargc_.c	5.2 (Berkeley) %G%"
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

