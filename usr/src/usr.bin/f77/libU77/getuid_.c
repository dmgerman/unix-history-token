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
literal|"@(#)getuid_.c	5.2 (Berkeley) %G%"
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

