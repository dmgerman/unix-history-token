begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1991 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)subr_xxx.c	7.14 (Berkeley) %G%  */
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

begin_macro
name|enodev
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|ENODEV
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Unconfigured device function; driver not configured.  */
end_comment

begin_macro
name|enxio
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Unsupported ioctl function.  */
end_comment

begin_macro
name|enoioctl
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|ENOTTY
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Unsupported system function.  * This is used for an otherwise-reasonable operation  * that is not supported by the current system binary.  */
end_comment

begin_macro
name|enosys
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Return error for operation not supported  * on a specific object or file type.  */
end_comment

begin_macro
name|eopnotsupp
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Generic null operation, always returns success.  */
end_comment

begin_macro
name|nullop
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

