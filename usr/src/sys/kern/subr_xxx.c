begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1991 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)subr_xxx.c	7.10 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Miscellaneous trivial functions, including many  * that are often inline-expanded or done in assembler.  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"machine/cpu.h"
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

begin_comment
comment|/*  * Definitions of various trivial functions;  * usually expanded inline rather than being defined here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_MINMAX
end_ifdef

begin_macro
name|imin
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_block

begin_macro
name|imax
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_block

begin_function
name|unsigned
name|int
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|unsigned
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|unsigned
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
name|long
name|lmin
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|long
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
name|long
name|lmax
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|long
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|ulmin
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|unsigned
name|long
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|ulmax
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|unsigned
name|long
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_MINMAX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_FFS
end_ifdef

begin_expr_stmt
name|ffs
argument_list|(
name|mask
argument_list|)
specifier|register
name|long
name|mask
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|bit
decl_stmt|;
if|if
condition|(
operator|!
name|mask
condition|)
return|return
operator|(
literal|0
operator|)
return|;
for|for
control|(
name|bit
operator|=
literal|1
init|;
condition|;
operator|++
name|bit
control|)
block|{
if|if
condition|(
name|mask
operator|&
literal|0x01
condition|)
return|return
operator|(
name|bit
operator|)
return|;
name|mask
operator|>>=
literal|1
expr_stmt|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_FFS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_BCMP
end_ifdef

begin_macro
name|bcmp
argument_list|(
argument|v1
argument_list|,
argument|v2
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|void
modifier|*
name|v1
decl_stmt|,
modifier|*
name|v2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|unsigned
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|u_char
modifier|*
name|s1
init|=
name|v1
decl_stmt|,
modifier|*
name|s2
init|=
name|v2
decl_stmt|;
while|while
condition|(
name|len
operator|--
condition|)
if|if
condition|(
operator|*
name|s1
operator|++
operator|!=
operator|*
name|s2
operator|++
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_BCMP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_STRLEN
end_ifdef

begin_expr_stmt
name|strlen
argument_list|(
name|s1
argument_list|)
specifier|register
name|char
operator|*
name|s1
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|len
decl_stmt|;
for|for
control|(
name|len
operator|=
literal|0
init|;
operator|*
name|s1
operator|++
operator|!=
literal|'\0'
condition|;
name|len
operator|++
control|)
empty_stmt|;
return|return
operator|(
name|len
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_STRLEN */
end_comment

end_unit

