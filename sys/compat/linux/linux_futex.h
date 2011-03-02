begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: linux_futex.h,v 1.2 2005/12/11 12:20:19 christos Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005 Emmanuel Dreyfus, all rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Emmanuel Dreyfus  * 4. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE THE AUTHOR AND CONTRIBUTORS ``AS IS''  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_FUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_FUTEX_H
end_define

begin_extern
extern|extern LIST_HEAD(futex_list
operator|,
extern|futex
end_extern

begin_expr_stmt
unit|)
name|futex_list
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|futex_mtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LINUX_FUTEX_WAIT
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_WAKE
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_FD
value|2
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|LINUX_FUTEX_REQUEUE
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_CMP_REQUEUE
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_WAKE_OP
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_LOCK_PI
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_UNLOCK_PI
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_TRYLOCK_PI
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_WAIT_BITSET
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_WAKE_BITSET
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_WAIT_REQUEUE_PI
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_PRIVATE_FLAG
value|128
end_define

begin_define
define|#
directive|define
name|LINUX_FUTEX_CLOCK_REALTIME
value|256
end_define

begin_define
define|#
directive|define
name|FUTEX_OP_SET
value|0
end_define

begin_comment
comment|/* *(int *)UADDR2 = OPARG; */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_ADD
value|1
end_define

begin_comment
comment|/* *(int *)UADDR2 += OPARG; */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_OR
value|2
end_define

begin_comment
comment|/* *(int *)UADDR2 |= OPARG; */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_ANDN
value|3
end_define

begin_comment
comment|/* *(int *)UADDR2&= ~OPARG; */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_XOR
value|4
end_define

begin_comment
comment|/* *(int *)UADDR2 ^= OPARG; */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_OPARG_SHIFT
value|8
end_define

begin_comment
comment|/* Use (1<< OPARG) instead of OPARG.  */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_CMP_EQ
value|0
end_define

begin_comment
comment|/* if (oldval == CMPARG) wake */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_CMP_NE
value|1
end_define

begin_comment
comment|/* if (oldval != CMPARG) wake */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_CMP_LT
value|2
end_define

begin_comment
comment|/* if (oldval< CMPARG) wake */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_CMP_LE
value|3
end_define

begin_comment
comment|/* if (oldval<= CMPARG) wake */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_CMP_GT
value|4
end_define

begin_comment
comment|/* if (oldval> CMPARG) wake */
end_comment

begin_define
define|#
directive|define
name|FUTEX_OP_CMP_GE
value|5
end_define

begin_comment
comment|/* if (oldval>= CMPARG) wake */
end_comment

begin_define
define|#
directive|define
name|FUTEX_WAITERS
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FUTEX_OWNER_DIED
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FUTEX_TID_MASK
value|0x3fffffff
end_define

begin_define
define|#
directive|define
name|FUTEX_BITSET_MATCH_ANY
value|0xffffffff
end_define

begin_function_decl
name|void
name|release_futexes
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LINUX_FUTEX_H */
end_comment

end_unit

