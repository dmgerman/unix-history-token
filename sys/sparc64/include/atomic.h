begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This is not atomic.  It is just a stub to make things compile.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_define
define|#
directive|define
name|__atomic_op
parameter_list|(
name|p
parameter_list|,
name|op
parameter_list|,
name|v
parameter_list|)
value|({					\ 	__typeof(*p) __v = (__typeof(*p))v;				\ 	*p op __v;							\ })
end_define

begin_define
define|#
directive|define
name|__atomic_load
parameter_list|(
name|p
parameter_list|)
value|({						\ 	__typeof(*p) __v;						\ 	__v = *p;							\ 	__v;								\ })
end_define

begin_define
define|#
directive|define
name|__atomic_load_clear
parameter_list|(
name|p
parameter_list|)
value|({					\ 	__typeof(*p) __v;						\ 	__v = *p;							\ 	*p = 0;								\ 	__v;								\ })
end_define

begin_define
define|#
directive|define
name|__atomic_cas
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|({					\ 	u_int __v;							\ 	if (*p == (__typeof(*p))e) {					\ 		*p = (__typeof(*p))s;					\ 		__v = 1;						\ 	} else {							\ 		__v = 0;						\ 	}								\ 	__v;								\ })
end_define

begin_define
define|#
directive|define
name|__atomic_op_8
parameter_list|(
name|p
parameter_list|,
name|op
parameter_list|,
name|v
parameter_list|)
value|__atomic_op(p, op, v)
end_define

begin_define
define|#
directive|define
name|__atomic_op_16
parameter_list|(
name|p
parameter_list|,
name|op
parameter_list|,
name|v
parameter_list|)
value|__atomic_op(p, op, v)
end_define

begin_define
define|#
directive|define
name|__atomic_op_32
parameter_list|(
name|p
parameter_list|,
name|op
parameter_list|,
name|v
parameter_list|)
value|__atomic_op(p, op, v)
end_define

begin_define
define|#
directive|define
name|__atomic_load_32
parameter_list|(
name|p
parameter_list|)
value|__atomic_load(p)
end_define

begin_define
define|#
directive|define
name|__atomic_load_clear_32
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_clear(p)
end_define

begin_define
define|#
directive|define
name|__atomic_cas_32
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas(p, e, s)
end_define

begin_define
define|#
directive|define
name|__atomic_op_64
parameter_list|(
name|p
parameter_list|,
name|op
parameter_list|,
name|v
parameter_list|)
value|__atomic_op(p, op, v)
end_define

begin_define
define|#
directive|define
name|__atomic_load_64
parameter_list|(
name|p
parameter_list|)
value|__atomic_load(p)
end_define

begin_define
define|#
directive|define
name|__atomic_load_clear_64
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_clear(p)
end_define

begin_define
define|#
directive|define
name|__atomic_cas_64
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_32
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_32(p)
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_32
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_clear_32(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_32
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_32(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_64
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_64
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_clear_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_64
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_32
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_32(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_32
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_32(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_64
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_64
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_32
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_32(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_64
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_int
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_32(p)
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_int
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_clear_32(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_int
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_32(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_long
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_clear_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_long
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_int
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_32(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_int
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_32(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_long
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_long
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_int
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_32(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_long
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_int
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_32(p)
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_int
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_clear_32(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_int
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_32(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_long
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_clear_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_long
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_ptr
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_clear_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_int
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_32(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_int
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_32(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_long
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_long
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_ptr
parameter_list|(
name|p
parameter_list|)
value|__atomic_load_64(p)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_char
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_8(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_16(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_32(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_int
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_32(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_long
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, +=, v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, -=, v)
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, |=, v)
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p,&=, ~v)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|__atomic_op_64(p, =, v)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|__atomic_cas_64(p, e, s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ATOMIC_H_ */
end_comment

end_unit

