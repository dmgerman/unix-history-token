begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2002 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_l4timer.c - timer and timeout handling for layer 4  *	--------------------------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Sat Mar  9 19:49:13 2002]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|"i4b.h"
end_include

begin_if
if|#
directive|if
name|NI4B
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_debug.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<i4b/include/i4b_global.h>
end_include

begin_include
include|#
directive|include
file|<i4b/include/i4b_l3l4.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer4/i4b_l4.h>
end_include

begin_comment
comment|/*---------------------------------------------------------------------------*  *	timer T400 timeout function  *---------------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
name|void
name|T400_timeout
parameter_list|(
name|call_desc_t
modifier|*
name|cd
parameter_list|)
block|{
name|NDBGL4
argument_list|(
name|L4_ERR
argument_list|,
literal|"cr = %d"
argument_list|,
name|cd
operator|->
name|cr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *	timer T400 start  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|T400_start
parameter_list|(
name|call_desc_t
modifier|*
name|cd
parameter_list|)
block|{
if|if
condition|(
name|cd
operator|->
name|T400
operator|==
name|TIMER_ACTIVE
condition|)
return|return;
name|NDBGL4
argument_list|(
name|L4_MSG
argument_list|,
literal|"cr = %d"
argument_list|,
name|cd
operator|->
name|cr
argument_list|)
expr_stmt|;
name|cd
operator|->
name|T400
operator|=
name|TIMER_ACTIVE
expr_stmt|;
name|START_TIMER
argument_list|(
name|cd
operator|->
name|T400_callout
argument_list|,
name|T400_timeout
argument_list|,
name|cd
argument_list|,
name|T400DEF
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *	timer T400 stop  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|T400_stop
parameter_list|(
name|call_desc_t
modifier|*
name|cd
parameter_list|)
block|{
name|CRIT_VAR
expr_stmt|;
name|CRIT_BEG
expr_stmt|;
if|if
condition|(
name|cd
operator|->
name|T400
operator|==
name|TIMER_ACTIVE
condition|)
block|{
name|STOP_TIMER
argument_list|(
name|cd
operator|->
name|T400_callout
argument_list|,
name|T400_timeout
argument_list|,
name|cd
argument_list|)
expr_stmt|;
name|cd
operator|->
name|T400
operator|=
name|TIMER_IDLE
expr_stmt|;
block|}
name|CRIT_END
expr_stmt|;
name|NDBGL4
argument_list|(
name|L4_MSG
argument_list|,
literal|"cr = %d"
argument_list|,
name|cd
operator|->
name|cr
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NI4B> 0 */
end_comment

end_unit

