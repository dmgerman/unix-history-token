begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/pqueue/pqueue_compat.h */
end_comment

begin_comment
comment|/*   * DTLS implementation written by Nagendra Modadugu  * (nagendra@cs.stanford.edu) for the OpenSSL project 2005.    */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1999-2005 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|"opensslconf.h"
end_include

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_comment
comment|/*   * The purpose of this header file is for supporting 64-bit integer  * manipulation on 32-bit (and lower) machines.  Currently the only  * such environment is VMS, Utrix and those with smaller default integer  * sizes than 32 bits.  For all such environment, we fall back to using  * BIGNUM.  We may need to fine tune the conditions for systems that  * are incorrectly configured.  *  * The only clients of this code are (1) pqueue for priority, and  * (2) DTLS, for sequence number manipulation.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|THIRTY_TWO_BIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BN_LLONG
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|SIXTEEN_BIT
argument_list|)
operator|||
name|defined
argument_list|(
name|EIGHT_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|PQ_64BIT_IS_INTEGER
value|0
end_define

begin_define
define|#
directive|define
name|PQ_64BIT_IS_BIGNUM
value|1
end_define

begin_define
define|#
directive|define
name|PQ_64BIT
value|BIGNUM
end_define

begin_define
define|#
directive|define
name|PQ_64BIT_CTX
value|BN_CTX
end_define

begin_define
define|#
directive|define
name|pq_64bit_init
parameter_list|(
name|x
parameter_list|)
value|BN_init(x)
end_define

begin_define
define|#
directive|define
name|pq_64bit_free
parameter_list|(
name|x
parameter_list|)
value|BN_free(x)
end_define

begin_define
define|#
directive|define
name|pq_64bit_ctx_new
parameter_list|(
name|ctx
parameter_list|)
value|BN_CTX_new()
end_define

begin_define
define|#
directive|define
name|pq_64bit_ctx_free
parameter_list|(
name|x
parameter_list|)
value|BN_CTX_free(x)
end_define

begin_define
define|#
directive|define
name|pq_64bit_assign
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|BN_copy(x, y)
end_define

begin_define
define|#
directive|define
name|pq_64bit_assign_word
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|BN_set_word(x, y)
end_define

begin_define
define|#
directive|define
name|pq_64bit_gt
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|BN_ucmp(x, y)>= 1 ? 1 : 0
end_define

begin_define
define|#
directive|define
name|pq_64bit_eq
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|BN_ucmp(x, y) == 0 ? 1 : 0
end_define

begin_define
define|#
directive|define
name|pq_64bit_add_word
parameter_list|(
name|x
parameter_list|,
name|w
parameter_list|)
value|BN_add_word(x, w)
end_define

begin_define
define|#
directive|define
name|pq_64bit_sub
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|BN_sub(r, x, y)
end_define

begin_define
define|#
directive|define
name|pq_64bit_sub_word
parameter_list|(
name|x
parameter_list|,
name|w
parameter_list|)
value|BN_sub_word(x, w)
end_define

begin_define
define|#
directive|define
name|pq_64bit_mod
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|n
parameter_list|,
name|ctx
parameter_list|)
value|BN_mod(r, x, n, ctx)
end_define

begin_define
define|#
directive|define
name|pq_64bit_bin2num
parameter_list|(
name|bn
parameter_list|,
name|bytes
parameter_list|,
name|len
parameter_list|)
value|BN_bin2bn(bytes, len, bn)
end_define

begin_define
define|#
directive|define
name|pq_64bit_num2bin
parameter_list|(
name|bn
parameter_list|,
name|bytes
parameter_list|)
value|BN_bn2bin(bn, bytes)
end_define

begin_define
define|#
directive|define
name|pq_64bit_get_word
parameter_list|(
name|x
parameter_list|)
value|BN_get_word(x)
end_define

begin_define
define|#
directive|define
name|pq_64bit_is_bit_set
parameter_list|(
name|x
parameter_list|,
name|offset
parameter_list|)
value|BN_is_bit_set(x, offset)
end_define

begin_define
define|#
directive|define
name|pq_64bit_lshift
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|shift
parameter_list|)
value|BN_lshift(r, x, shift)
end_define

begin_define
define|#
directive|define
name|pq_64bit_set_bit
parameter_list|(
name|x
parameter_list|,
name|num
parameter_list|)
value|BN_set_bit(x, num)
end_define

begin_define
define|#
directive|define
name|pq_64bit_get_length
parameter_list|(
name|x
parameter_list|)
value|BN_num_bits((x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PQ_64BIT_IS_INTEGER
value|1
end_define

begin_define
define|#
directive|define
name|PQ_64BIT_IS_BIGNUM
value|0
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIXTY_FOUR_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|PQ_64BIT
value|BN_ULONG
end_define

begin_define
define|#
directive|define
name|PQ_64BIT_PRINT
value|"%lld"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SIXTY_FOUR_BIT_LONG
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PQ_64BIT
value|BN_ULONG
end_define

begin_define
define|#
directive|define
name|PQ_64BIT_PRINT
value|"%ld"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|THIRTY_TWO_BIT
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PQ_64BIT
value|BN_ULLONG
end_define

begin_define
define|#
directive|define
name|PQ_64BIT_PRINT
value|"%lld"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PQ_64BIT_CTX
value|void
end_define

begin_define
define|#
directive|define
name|pq_64bit_init
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|pq_64bit_free
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|pq_64bit_ctx_new
parameter_list|(
name|ctx
parameter_list|)
value|(ctx)
end_define

begin_define
define|#
directive|define
name|pq_64bit_ctx_free
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|pq_64bit_assign
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(*(x) = *(y))
end_define

begin_define
define|#
directive|define
name|pq_64bit_assign_word
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(*(x) = y)
end_define

begin_define
define|#
directive|define
name|pq_64bit_gt
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(*(x)> *(y))
end_define

begin_define
define|#
directive|define
name|pq_64bit_eq
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(*(x) == *(y))
end_define

begin_define
define|#
directive|define
name|pq_64bit_add_word
parameter_list|(
name|x
parameter_list|,
name|w
parameter_list|)
value|(*(x) = (*(x) + (w)))
end_define

begin_define
define|#
directive|define
name|pq_64bit_sub
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|(*(r) = (*(x) - *(y)))
end_define

begin_define
define|#
directive|define
name|pq_64bit_sub_word
parameter_list|(
name|x
parameter_list|,
name|w
parameter_list|)
value|(*(x) = (*(x) - (w)))
end_define

begin_define
define|#
directive|define
name|pq_64bit_mod
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|n
parameter_list|,
name|ctx
parameter_list|)
end_define

begin_define
define|#
directive|define
name|pq_64bit_bin2num
parameter_list|(
name|num
parameter_list|,
name|bytes
parameter_list|,
name|len
parameter_list|)
value|bytes_to_long_long(bytes, num)
end_define

begin_define
define|#
directive|define
name|pq_64bit_num2bin
parameter_list|(
name|num
parameter_list|,
name|bytes
parameter_list|)
value|long_long_to_bytes(num, bytes)
end_define

begin_define
define|#
directive|define
name|pq_64bit_get_word
parameter_list|(
name|x
parameter_list|)
value|*(x)
end_define

begin_define
define|#
directive|define
name|pq_64bit_lshift
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|shift
parameter_list|)
value|(*(r) = (*(x)<< (shift)))
end_define

begin_define
define|#
directive|define
name|pq_64bit_set_bit
parameter_list|(
name|x
parameter_list|,
name|num
parameter_list|)
value|do { \                                               PQ_64BIT mask = 1; \                                               mask = mask<< (num); \                                               *(x) |= mask; \                                           } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL_SYS_VMS */
end_comment

end_unit

