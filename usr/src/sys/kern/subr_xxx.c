begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)subr_xxx.c	8.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Miscellaneous trivial functions, including many  * that are often inline-expanded or done in assembler.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_comment
comment|/*  * Unsupported device function (e.g. writing to read-only device).  */
end_comment

begin_function
name|int
name|enodev
parameter_list|()
block|{
return|return
operator|(
name|ENODEV
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Unconfigured device function; driver not configured.  */
end_comment

begin_function
name|int
name|enxio
parameter_list|()
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Unsupported ioctl function.  */
end_comment

begin_function
name|int
name|enoioctl
parameter_list|()
block|{
return|return
operator|(
name|ENOTTY
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Unsupported system function.  * This is used for an otherwise-reasonable operation  * that is not supported by the current system binary.  */
end_comment

begin_function
name|int
name|enosys
parameter_list|()
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return error for operation not supported  * on a specific object or file type.  */
end_comment

begin_function
name|int
name|eopnotsupp
parameter_list|()
block|{
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return error for an inval operation  * on a specific object or file type.  */
end_comment

begin_function
name|int
name|einval
parameter_list|()
block|{
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Generic null operation, always returns success.  */
end_comment

begin_function
name|int
name|nullop
parameter_list|()
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

