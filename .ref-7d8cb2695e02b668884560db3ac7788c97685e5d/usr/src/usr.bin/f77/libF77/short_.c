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
literal|"@(#)short_.c	5.2 (Berkeley) %G%"
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

