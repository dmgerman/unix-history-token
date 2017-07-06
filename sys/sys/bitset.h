begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, Jeffrey Roberson<jeff@freebsd.org>  * All rights reserved.  *  * Copyright (c) 2008 Nokia Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_BITSET_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_BITSET_H_
end_define

begin_define
define|#
directive|define
name|__bitset_mask
parameter_list|(
name|_s
parameter_list|,
name|n
parameter_list|)
define|\
value|(1L<< ((__bitset_words((_s)) == 1) ?				\ 	    (__size_t)(n) : ((n) % _BITSET_BITS)))
end_define

begin_define
define|#
directive|define
name|__bitset_word
parameter_list|(
name|_s
parameter_list|,
name|n
parameter_list|)
define|\
value|((__bitset_words((_s)) == 1) ? 0 : ((n) / _BITSET_BITS))
end_define

begin_define
define|#
directive|define
name|BIT_CLR
parameter_list|(
name|_s
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|((p)->__bits[__bitset_word(_s, n)]&= ~__bitset_mask((_s), (n)))
end_define

begin_define
define|#
directive|define
name|BIT_COPY
parameter_list|(
name|_s
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|)
value|(void)(*(t) = *(f))
end_define

begin_define
define|#
directive|define
name|BIT_ISSET
parameter_list|(
name|_s
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|((((p)->__bits[__bitset_word(_s, n)]& __bitset_mask((_s), (n))) != 0))
end_define

begin_define
define|#
directive|define
name|BIT_SET
parameter_list|(
name|_s
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|((p)->__bits[__bitset_word(_s, n)] |= __bitset_mask((_s), (n)))
end_define

begin_define
define|#
directive|define
name|BIT_ZERO
parameter_list|(
name|_s
parameter_list|,
name|p
parameter_list|)
value|do {						\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		(p)->__bits[__i] = 0L;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_FILL
parameter_list|(
name|_s
parameter_list|,
name|p
parameter_list|)
value|do {						\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		(p)->__bits[__i] = -1L;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_SETOF
parameter_list|(
name|_s
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
value|do {					\ 	BIT_ZERO(_s, p);						\ 	(p)->__bits[__bitset_word(_s, n)] = __bitset_mask((_s), (n));	\ } while (0)
end_define

begin_comment
comment|/* Is p empty. */
end_comment

begin_define
define|#
directive|define
name|BIT_EMPTY
parameter_list|(
name|_s
parameter_list|,
name|p
parameter_list|)
value|__extension__ ({				\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		if ((p)->__bits[__i])					\ 			break;						\ 	__i == __bitset_words((_s));					\ })
end_define

begin_comment
comment|/* Is p full set. */
end_comment

begin_define
define|#
directive|define
name|BIT_ISFULLSET
parameter_list|(
name|_s
parameter_list|,
name|p
parameter_list|)
value|__extension__ ({				\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		if ((p)->__bits[__i] != (long)-1)			\ 			break;						\ 	__i == __bitset_words((_s));					\ })
end_define

begin_comment
comment|/* Is c a subset of p. */
end_comment

begin_define
define|#
directive|define
name|BIT_SUBSET
parameter_list|(
name|_s
parameter_list|,
name|p
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({				\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		if (((c)->__bits[__i]&					\ 		    (p)->__bits[__i]) !=				\ 		    (c)->__bits[__i])					\ 			break;						\ 	__i == __bitset_words((_s));					\ })
end_define

begin_comment
comment|/* Are there any common bits between b& c? */
end_comment

begin_define
define|#
directive|define
name|BIT_OVERLAP
parameter_list|(
name|_s
parameter_list|,
name|p
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({				\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		if (((c)->__bits[__i]&					\ 		    (p)->__bits[__i]) != 0)				\ 			break;						\ 	__i != __bitset_words((_s));					\ })
end_define

begin_comment
comment|/* Compare two sets, returns 0 if equal 1 otherwise. */
end_comment

begin_define
define|#
directive|define
name|BIT_CMP
parameter_list|(
name|_s
parameter_list|,
name|p
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({				\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		if (((c)->__bits[__i] !=				\ 		    (p)->__bits[__i]))					\ 			break;						\ 	__i != __bitset_words((_s));					\ })
end_define

begin_define
define|#
directive|define
name|BIT_OR
parameter_list|(
name|_s
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|do {						\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		(d)->__bits[__i] |= (s)->__bits[__i];			\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_OR2
parameter_list|(
name|_s
parameter_list|,
name|d
parameter_list|,
name|s1
parameter_list|,
name|s2
parameter_list|)
value|do {					\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		(d)->__bits[__i] = (s1)->__bits[__i] | (s2)->__bits[__i];\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_AND
parameter_list|(
name|_s
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|do {						\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		(d)->__bits[__i]&= (s)->__bits[__i];			\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_AND2
parameter_list|(
name|_s
parameter_list|,
name|d
parameter_list|,
name|s1
parameter_list|,
name|s2
parameter_list|)
value|do {					\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		(d)->__bits[__i] = (s1)->__bits[__i]& (s2)->__bits[__i];\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_NAND
parameter_list|(
name|_s
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|do {						\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		(d)->__bits[__i]&= ~(s)->__bits[__i];			\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_NAND2
parameter_list|(
name|_s
parameter_list|,
name|d
parameter_list|,
name|s1
parameter_list|,
name|s2
parameter_list|)
value|do {					\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		(d)->__bits[__i] = (s1)->__bits[__i]& ~(s2)->__bits[__i];\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_XOR
parameter_list|(
name|_s
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|do {						\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		(d)->__bits[__i] ^= (s)->__bits[__i];			\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_XOR2
parameter_list|(
name|_s
parameter_list|,
name|d
parameter_list|,
name|s1
parameter_list|,
name|s2
parameter_list|)
value|do {					\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		(d)->__bits[__i] = (s1)->__bits[__i] ^ (s2)->__bits[__i];\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_CLR_ATOMIC
parameter_list|(
name|_s
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|atomic_clear_long(&(p)->__bits[__bitset_word(_s, n)],		\ 	    __bitset_mask((_s), n))
end_define

begin_define
define|#
directive|define
name|BIT_SET_ATOMIC
parameter_list|(
name|_s
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|atomic_set_long(&(p)->__bits[__bitset_word(_s, n)],		\ 	    __bitset_mask((_s), n))
end_define

begin_define
define|#
directive|define
name|BIT_SET_ATOMIC_ACQ
parameter_list|(
name|_s
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|atomic_set_acq_long(&(p)->__bits[__bitset_word(_s, n)],		\ 	    __bitset_mask((_s), n))
end_define

begin_comment
comment|/* Convenience functions catering special cases. */
end_comment

begin_define
define|#
directive|define
name|BIT_AND_ATOMIC
parameter_list|(
name|_s
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|do {					\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		atomic_clear_long(&(d)->__bits[__i],			\ 		    ~(s)->__bits[__i]);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_OR_ATOMIC
parameter_list|(
name|_s
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|do {					\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		atomic_set_long(&(d)->__bits[__i],			\ 		    (s)->__bits[__i]);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_COPY_STORE_REL
parameter_list|(
name|_s
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|)
value|do {				\ 	__size_t __i;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		atomic_store_rel_long(&(t)->__bits[__i],		\ 		    (f)->__bits[__i]);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_FFS
parameter_list|(
name|_s
parameter_list|,
name|p
parameter_list|)
value|__extension__ ({					\ 	__size_t __i;							\ 	int __bit;							\ 									\ 	__bit = 0;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++) {		\ 		if ((p)->__bits[__i] != 0) {				\ 			__bit = ffsl((p)->__bits[__i]);			\ 			__bit += __i * _BITSET_BITS;			\ 			break;						\ 		}							\ 	}								\ 	__bit;								\ })
end_define

begin_define
define|#
directive|define
name|BIT_FLS
parameter_list|(
name|_s
parameter_list|,
name|p
parameter_list|)
value|__extension__ ({					\ 	__size_t __i;							\ 	int __bit;							\ 									\ 	__bit = 0;							\ 	for (__i = __bitset_words((_s)) - 1; __i>= 0; __i--) {		\ 		if ((p)->__bits[__i] != 0) {				\ 			__bit = flsl((p)->__bits[__i]);			\ 			__bit += __i * _BITSET_BITS;			\ 			break;						\ 		}							\ 	}								\ 	__bit;								\ })
end_define

begin_define
define|#
directive|define
name|BIT_COUNT
parameter_list|(
name|_s
parameter_list|,
name|p
parameter_list|)
value|__extension__ ({				\ 	__size_t __i;							\ 	int __count;							\ 									\ 	__count = 0;							\ 	for (__i = 0; __i< __bitset_words((_s)); __i++)		\ 		__count += __bitcountl((p)->__bits[__i]);		\ 	__count;							\ })
end_define

begin_define
define|#
directive|define
name|BITSET_T_INITIALIZER
parameter_list|(
name|x
parameter_list|)
define|\
value|{ .__bits = { x } }
end_define

begin_define
define|#
directive|define
name|BITSET_FSET
parameter_list|(
name|n
parameter_list|)
define|\
value|[ 0 ... ((n) - 1) ] = (-1L)
end_define

begin_comment
comment|/*  * Dynamically allocate a bitset.  */
end_comment

begin_define
define|#
directive|define
name|BITSET_ALLOC
parameter_list|(
name|_s
parameter_list|,
name|mt
parameter_list|,
name|mf
parameter_list|)
define|\
value|malloc(__bitset_words(_s) * sizeof(long), mt, (mf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_BITSET_H_ */
end_comment

end_unit

