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
literal|"@(#)random_.c	5.5 (Berkeley) %G%"
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
comment|/*   * Routines to return random values  *  * calling sequence:  *	double precision d, drandm  *	i = irandm(iflag)  *	x = random(iflag)  *	d = drandm(iflag)  * where:  *	If arg is nonzero, generator is restarted and value is returned.  *	If arg is 0, next value is returned.  *	Integer values will range from 0 thru 2147483647 (see random(3)).  *	Real values will range from 0.0 thru 1.0 .  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|||
name|defined
argument_list|(
name|hp300
argument_list|)
end_if

begin_define
define|#
directive|define
name|RANDMAX
value|2147483647
end_define

begin_else
else|#
directive|else
else|vax || tahoe
end_else

begin_expr_stmt
name|UNKNOWN
name|MACHINE
operator|!
endif|#
directive|endif
endif|vax || tahoe
name|long
name|irandm_
argument_list|(
argument|iarg
argument_list|)
name|long
operator|*
name|iarg
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
operator|*
name|iarg
condition|)
name|srandom
argument_list|(
operator|(
name|int
operator|)
operator|*
name|iarg
argument_list|)
expr_stmt|;
return|return
operator|(
name|random
argument_list|()
operator|)
return|;
block|}
end_block

begin_function
name|float
name|random_
parameter_list|(
name|iarg
parameter_list|)
name|long
modifier|*
name|iarg
decl_stmt|;
block|{
if|if
condition|(
operator|*
name|iarg
condition|)
name|srandom
argument_list|(
operator|(
name|int
operator|)
operator|*
name|iarg
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|float
call|)
argument_list|(
name|random
argument_list|()
argument_list|)
operator|/
operator|(
name|float
operator|)
name|RANDMAX
operator|)
return|;
block|}
end_function

begin_function
name|double
name|drandm_
parameter_list|(
name|iarg
parameter_list|)
name|long
modifier|*
name|iarg
decl_stmt|;
block|{
if|if
condition|(
operator|*
name|iarg
condition|)
name|srandom
argument_list|(
operator|(
name|int
operator|)
operator|*
name|iarg
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|double
call|)
argument_list|(
name|random
argument_list|()
argument_list|)
operator|/
operator|(
name|double
operator|)
name|RANDMAX
operator|)
return|;
block|}
end_function

end_unit

