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
literal|"@(#)i_dnnt.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_function
name|long
name|int
name|i_dnnt
parameter_list|(
name|x
parameter_list|)
name|double
modifier|*
name|x
decl_stmt|;
block|{
name|double
name|floor
parameter_list|()
function_decl|;
return|return
operator|(
operator|(
operator|*
name|x
operator|)
operator|>=
literal|0
condition|?
name|floor
argument_list|(
operator|*
name|x
operator|+
literal|.5
argument_list|)
else|:
operator|-
name|floor
argument_list|(
literal|.5
operator|-
operator|*
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

