begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)signal.h	8.4 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__SIGSET_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__SIGSET_H_
end_define

begin_comment
comment|/*  * sigset_t macros.  */
end_comment

begin_define
define|#
directive|define
name|_SIG_WORDS
value|4
end_define

begin_define
define|#
directive|define
name|_SIG_MAXSIG
value|128
end_define

begin_define
define|#
directive|define
name|_SIG_IDX
parameter_list|(
name|sig
parameter_list|)
value|((sig) - 1)
end_define

begin_define
define|#
directive|define
name|_SIG_WORD
parameter_list|(
name|sig
parameter_list|)
value|(_SIG_IDX(sig)>> 5)
end_define

begin_define
define|#
directive|define
name|_SIG_BIT
parameter_list|(
name|sig
parameter_list|)
value|(1<< (_SIG_IDX(sig)& 31))
end_define

begin_define
define|#
directive|define
name|_SIG_VALID
parameter_list|(
name|sig
parameter_list|)
value|((sig)<= _SIG_MAXSIG&& (sig)> 0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|__sigset
block|{
name|__uint32_t
name|__bits
index|[
name|_SIG_WORDS
index|]
decl_stmt|;
block|}
name|__sigset_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|osigset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__SIGSET_H_ */
end_comment

end_unit

