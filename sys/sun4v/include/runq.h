begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder<jake@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_RUNQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_RUNQ_H_
end_define

begin_define
define|#
directive|define
name|RQB_LEN
value|(1UL)
end_define

begin_comment
comment|/* Number of priority status words. */
end_comment

begin_define
define|#
directive|define
name|RQB_L2BPW
value|(6UL)
end_define

begin_comment
comment|/* Log2(sizeof(rqb_word_t) * NBBY)). */
end_comment

begin_define
define|#
directive|define
name|RQB_BPW
value|(1UL<<RQB_L2BPW)
end_define

begin_comment
comment|/* Bits in an rqb_word_t. */
end_comment

begin_define
define|#
directive|define
name|RQB_BIT
parameter_list|(
name|pri
parameter_list|)
value|(1UL<< ((pri)& (RQB_BPW - 1)))
end_define

begin_define
define|#
directive|define
name|RQB_WORD
parameter_list|(
name|pri
parameter_list|)
value|((pri)>> RQB_L2BPW)
end_define

begin_define
define|#
directive|define
name|RQB_FFS
parameter_list|(
name|word
parameter_list|)
value|(ffs64(word) - 1)
end_define

begin_comment
comment|/*  * Type of run queue status word.  */
end_comment

begin_typedef
typedef|typedef
name|u_int64_t
name|rqb_word_t
typedef|;
end_typedef

begin_function
specifier|static
name|__inline
name|u_long
name|ffs64
parameter_list|(
name|u_long
name|mask
parameter_list|)
block|{
name|u_long
name|bit
decl_stmt|;
if|if
condition|(
name|mask
operator|==
literal|0
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
operator|(
name|mask
operator|&
literal|1UL
operator|)
operator|==
literal|0
condition|;
name|bit
operator|++
control|)
name|mask
operator|>>=
literal|1UL
expr_stmt|;
return|return
operator|(
name|bit
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

