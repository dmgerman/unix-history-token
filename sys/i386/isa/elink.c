begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 Charles Hannum.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Charles Hannum.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Common code for dealing with 3COM ethernet cards.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/elink.h>
end_include

begin_comment
comment|/*  * Issue a `global reset' to all cards.  We have to be careful to do this only  * once during autoconfig, to prevent resetting boards that have already been  * configured.  */
end_comment

begin_function
name|void
name|elink_reset
parameter_list|()
block|{
specifier|static
name|int
name|x
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{
name|x
operator|=
literal|1
expr_stmt|;
name|outb
argument_list|(
name|ELINK_ID_PORT
argument_list|,
name|ELINK_RESET
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * The `ID sequence' is really just snapshots of an 8-bit CRC register as 0  * bits are shifted in.  Different board types use different polynomials.  */
end_comment

begin_function
name|void
name|elink_idseq
parameter_list|(
name|u_char
name|p
parameter_list|)
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|u_char
name|c
decl_stmt|;
name|c
operator|=
literal|0xff
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|255
init|;
name|i
condition|;
name|i
operator|--
control|)
block|{
name|outb
argument_list|(
name|ELINK_ID_PORT
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|&
literal|0x80
condition|)
block|{
name|c
operator|<<=
literal|1
expr_stmt|;
name|c
operator|^=
name|p
expr_stmt|;
block|}
else|else
name|c
operator|<<=
literal|1
expr_stmt|;
block|}
block|}
end_function

end_unit

