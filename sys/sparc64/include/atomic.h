begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson.  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/i386/include/atomic.h,v 1.20 2001/02/11  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_comment
comment|/* Userland needs different ASI's. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|__ASI_ATOMIC
value|ASI_N
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__ASI_ATOMIC
value|ASI_P
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Various simple arithmetic on memory which is atomic in the presence  * of interrupts and multiple processors.  See atomic(9) for details.  * Note that efficient hardware support exists only for the 32 and 64  * bit variants; the 8 and 16 bit versions are not provided and should  * not be used in MI code.  *  * This implementation takes advantage of the fact that the sparc64  * cas instruction is both a load and a store.  The loop is often coded  * as follows:  *  *	do {  *		expect = *p;  *		new = expect + 1;  *	} while (cas(p, expect, new) != expect);  *  * which performs an unnnecessary load on each iteration that the cas  * operation fails.  Modified as follows:  *  *	expect = *p;  *	for (;;) {  *		new = expect + 1;  *		result = cas(p, expect, new);  *		if (result == expect)  *			break;  *		expect = result;  *	}  *  * the return value of cas is used to avoid the extra reload.  At the  * time of writing, with gcc version 2.95.3, the branch for the if  * statement is predicted incorrectly as not taken, rather than taken.  * It is expected that the branch prediction hints available in gcc 3.0,  * __builtin_expect, will allow better code to be generated.  *  * The memory barriers provided by the acq and rel variants are intended  * to be sufficient for use of relaxed memory ordering.  Due to the  * suggested assembly syntax of the membar operands containing a #  * character, they cannot be used in macros.  The cmask and mmask bits  * are hard coded in machine/cpufunc.h and used here through macros.  * Hopefully sun will choose not to change the bit numbers.  */
end_comment

begin_define
define|#
directive|define
name|itype
parameter_list|(
name|sz
parameter_list|)
value|u_int ## sz ## _t
end_define

begin_define
define|#
directive|define
name|atomic_cas_32
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|casa(p, e, s, __ASI_ATOMIC)
end_define

begin_define
define|#
directive|define
name|atomic_cas_64
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|)
value|casxa(p, e, s, __ASI_ATOMIC)
end_define

begin_define
define|#
directive|define
name|atomic_cas
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|,
name|sz
parameter_list|)
define|\
value|atomic_cas_ ## sz(p, e, s)
end_define

begin_define
define|#
directive|define
name|atomic_cas_acq
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|,
name|sz
parameter_list|)
value|({					\ 	itype(sz) v;							\ 	v = atomic_cas(p, e, s, sz);					\ 	membar(LoadLoad | LoadStore);					\ 	v;								\ })
end_define

begin_define
define|#
directive|define
name|atomic_cas_rel
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|,
name|sz
parameter_list|)
value|({					\ 	itype(sz) v;							\ 	membar(LoadStore | StoreStore);					\ 	v = atomic_cas(p, e, s, sz);					\ 	v;								\ })
end_define

begin_define
define|#
directive|define
name|atomic_op
parameter_list|(
name|p
parameter_list|,
name|op
parameter_list|,
name|v
parameter_list|,
name|sz
parameter_list|)
value|do {					\ 	itype(sz) e, r, s;						\ 	for (e = *(volatile itype(sz) *)p;; e = r) {			\ 		s = e op v;						\ 		r = atomic_cas_ ## sz(p, e, s);				\ 		if (r == e)						\ 			break;						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|atomic_op_acq
parameter_list|(
name|p
parameter_list|,
name|op
parameter_list|,
name|v
parameter_list|,
name|sz
parameter_list|)
value|do {				\ 	atomic_op(p, op, v, sz);					\ 	membar(LoadLoad | LoadStore);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|atomic_op_rel
parameter_list|(
name|p
parameter_list|,
name|op
parameter_list|,
name|v
parameter_list|,
name|sz
parameter_list|)
value|do {				\ 	membar(LoadStore | StoreStore);					\ 	atomic_op(p, op, v, sz);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|atomic_load
parameter_list|(
name|p
parameter_list|,
name|sz
parameter_list|)
define|\
value|atomic_cas(p, 0, 0, sz)
end_define

begin_define
define|#
directive|define
name|atomic_load_acq
parameter_list|(
name|p
parameter_list|,
name|sz
parameter_list|)
value|({					\ 	itype(sz) v;							\ 	v = atomic_load(p, sz);						\ 	membar(LoadLoad | LoadStore);					\ 	v;								\ })
end_define

begin_define
define|#
directive|define
name|atomic_load_clear
parameter_list|(
name|p
parameter_list|,
name|sz
parameter_list|)
value|({					\ 	itype(sz) e, r;							\ 	for (e = *(volatile itype(sz) *)p;; e = r) {			\ 		r = atomic_cas(p, e, 0, sz);				\ 		if (r == e)						\ 			break;						\ 	}								\ 	e;								\ })
end_define

begin_define
define|#
directive|define
name|atomic_store
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|sz
parameter_list|)
value|do {					\ 	itype(sz) e, r;							\ 	for (e = *(volatile itype(sz) *)p;; e = r) {			\ 		r = atomic_cas(p, e, v, sz);				\ 		if (r == e)						\ 			break;						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|atomic_store_rel
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|sz
parameter_list|)
value|do {					\ 	membar(LoadStore | StoreStore);					\ 	atomic_store(p, v, sz);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|ATOMIC_GEN
parameter_list|(
name|name
parameter_list|,
name|ptype
parameter_list|,
name|vtype
parameter_list|,
name|atype
parameter_list|,
name|sz
parameter_list|)
define|\ 									\
value|static __inline void							\ atomic_add_ ## name(volatile ptype p, atype v)				\ {									\ 	atomic_op(p, +, v, sz);						\ }									\ static __inline void							\ atomic_add_acq_ ## name(volatile ptype p, atype v)			\ {									\ 	atomic_op_acq(p, +, v, sz);					\ }									\ static __inline void							\ atomic_add_rel_ ## name(volatile ptype p, atype v)			\ {									\ 	atomic_op_rel(p, +, v, sz);					\ }									\ 									\ static __inline void							\ atomic_clear_ ## name(volatile ptype p, atype v)			\ {									\ 	atomic_op(p,&, ~v, sz);					\ }									\ static __inline void							\ atomic_clear_acq_ ## name(volatile ptype p, atype v)			\ {									\ 	atomic_op_acq(p,&, ~v, sz);					\ }									\ static __inline void							\ atomic_clear_rel_ ## name(volatile ptype p, atype v)			\ {									\ 	atomic_op_rel(p,&, ~v, sz);					\ }									\ 									\ static __inline int							\ atomic_cmpset_ ## name(volatile ptype p, vtype e, vtype s)		\ {									\ 	return (((vtype)atomic_cas(p, e, s, sz)) == e);			\ }									\ static __inline int							\ atomic_cmpset_acq_ ## name(volatile ptype p, vtype e, vtype s)		\ {									\ 	return (((vtype)atomic_cas_acq(p, e, s, sz)) == e);		\ }									\ static __inline int							\ atomic_cmpset_rel_ ## name(volatile ptype p, vtype e, vtype s)		\ {									\ 	return (((vtype)atomic_cas_rel(p, e, s, sz)) == e);		\ }									\ 									\ static __inline vtype							\ atomic_load_ ## name(volatile ptype p)					\ {									\ 	return ((vtype)atomic_cas(p, 0, 0, sz));			\ }									\ static __inline vtype							\ atomic_load_acq_ ## name(volatile ptype p)				\ {									\ 	return ((vtype)atomic_cas_acq(p, 0, 0, sz));			\ }									\ 									\ static __inline vtype							\ atomic_readandclear_ ## name(volatile ptype p)				\ {									\ 	return ((vtype)atomic_load_clear(p, sz));			\ }									\ 									\ static __inline void							\ atomic_set_ ## name(volatile ptype p, atype v)				\ {									\ 	atomic_op(p, |, v, sz);						\ }									\ static __inline void							\ atomic_set_acq_ ## name(volatile ptype p, atype v)			\ {									\ 	atomic_op_acq(p, |, v, sz);					\ }									\ static __inline void							\ atomic_set_rel_ ## name(volatile ptype p, atype v)			\ {									\ 	atomic_op_rel(p, |, v, sz);					\ }									\ 									\ static __inline void							\ atomic_subtract_ ## name(volatile ptype p, atype v)			\ {									\ 	atomic_op(p, -, v, sz);						\ }									\ static __inline void							\ atomic_subtract_acq_ ## name(volatile ptype p, atype v)			\ {									\ 	atomic_op_acq(p, -, v, sz);					\ }									\ static __inline void							\ atomic_subtract_rel_ ## name(volatile ptype p, atype v)			\ {									\ 	atomic_op_rel(p, -, v, sz);					\ }									\ 									\ static __inline void							\ atomic_store_ ## name(volatile ptype p, vtype v)			\ {									\ 	atomic_store(p, v, sz);						\ }									\ static __inline void							\ atomic_store_rel_ ## name(volatile ptype p, vtype v)			\ {									\ 	atomic_store_rel(p, v, sz);					\ }
end_define

begin_expr_stmt
name|ATOMIC_GEN
argument_list|(
name|int
argument_list|,
name|int
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_GEN
argument_list|(
literal|32
argument_list|,
name|int
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_GEN
argument_list|(
name|long
argument_list|,
name|long
operator|*
argument_list|,
name|long
argument_list|,
name|long
argument_list|,
literal|64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_GEN
argument_list|(
literal|64
argument_list|,
name|long
operator|*
argument_list|,
name|long
argument_list|,
name|long
argument_list|,
literal|64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_GEN
argument_list|(
name|ptr
argument_list|,
name|void
operator|*
argument_list|,
name|void
operator|*
argument_list|,
name|uintptr_t
argument_list|,
literal|64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|__ASI_ATOMIC
end_undef

begin_undef
undef|#
directive|undef
name|ATOMIC_GEN
end_undef

begin_undef
undef|#
directive|undef
name|atomic_cas_32
end_undef

begin_undef
undef|#
directive|undef
name|atomic_cas_64
end_undef

begin_undef
undef|#
directive|undef
name|atomic_cas
end_undef

begin_undef
undef|#
directive|undef
name|atomic_cas_acq
end_undef

begin_undef
undef|#
directive|undef
name|atomic_cas_rel
end_undef

begin_undef
undef|#
directive|undef
name|atomic_op
end_undef

begin_undef
undef|#
directive|undef
name|atomic_op_acq
end_undef

begin_undef
undef|#
directive|undef
name|atomic_op_rel
end_undef

begin_undef
undef|#
directive|undef
name|atomic_load_acq
end_undef

begin_undef
undef|#
directive|undef
name|atomic_store_rel
end_undef

begin_undef
undef|#
directive|undef
name|atomic_load_clear
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ATOMIC_H_ */
end_comment

end_unit

