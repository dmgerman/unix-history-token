begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1991 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)subr_xxx.c	7.10 (Berkeley) 4/20/91  *	$Id: subr_xxx.c,v 1.2 1993/10/16 15:24:45 rgrimes Exp $  */
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

begin_function
name|size_t
name|strlen
parameter_list|(
name|s1
parameter_list|)
specifier|register
specifier|const
name|char
modifier|*
name|s1
decl_stmt|;
block|{
specifier|register
name|size_t
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
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_STRLEN */
end_comment

end_unit

