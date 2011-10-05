begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HEIM_BN_H
end_ifndef

begin_define
define|#
directive|define
name|_HEIM_BN_H
value|1
end_define

begin_comment
comment|/* symbol renaming */
end_comment

begin_define
define|#
directive|define
name|BN_GENCB_call
value|hc_BN_GENCB_call
end_define

begin_define
define|#
directive|define
name|BN_GENCB_set
value|hc_BN_GENCB_set
end_define

begin_define
define|#
directive|define
name|BN_bin2bn
value|hc_BN_bin2bn
end_define

begin_define
define|#
directive|define
name|BN_bn2bin
value|hc_BN_bn2bin
end_define

begin_define
define|#
directive|define
name|BN_bn2hex
value|hc_BN_bn2hex
end_define

begin_define
define|#
directive|define
name|BN_clear
value|hc_BN_clear
end_define

begin_define
define|#
directive|define
name|BN_clear_bit
value|hc_BN_clear_bit
end_define

begin_define
define|#
directive|define
name|BN_clear_free
value|hc_BN_clear_free
end_define

begin_define
define|#
directive|define
name|BN_cmp
value|hc_BN_cmp
end_define

begin_define
define|#
directive|define
name|BN_dup
value|hc_BN_dup
end_define

begin_define
define|#
directive|define
name|BN_free
value|hc_BN_free
end_define

begin_define
define|#
directive|define
name|BN_is_negative
value|hc_BN_is_negative
end_define

begin_define
define|#
directive|define
name|BN_get_word
value|hc_BN_get_word
end_define

begin_define
define|#
directive|define
name|BN_hex2bn
value|hc_BN_hex2bn
end_define

begin_define
define|#
directive|define
name|BN_is_bit_set
value|hc_BN_is_bit_set
end_define

begin_define
define|#
directive|define
name|BN_new
value|hc_BN_new
end_define

begin_define
define|#
directive|define
name|BN_num_bits
value|hc_BN_num_bits
end_define

begin_define
define|#
directive|define
name|BN_num_bytes
value|hc_BN_num_bytes
end_define

begin_define
define|#
directive|define
name|BN_rand
value|hc_BN_rand
end_define

begin_define
define|#
directive|define
name|BN_set_bit
value|hc_BN_set_bit
end_define

begin_define
define|#
directive|define
name|BN_set_negative
value|hc_BN_set_negative
end_define

begin_define
define|#
directive|define
name|BN_set_word
value|hc_BN_set_word
end_define

begin_define
define|#
directive|define
name|BN_uadd
value|hc_BN_uadd
end_define

begin_define
define|#
directive|define
name|BN_CTX_new
value|hc_BN_CTX_new
end_define

begin_define
define|#
directive|define
name|BN_CTX_free
value|hc_BN_CTX_free
end_define

begin_define
define|#
directive|define
name|BN_CTX_get
value|hc_BN_CTX_get
end_define

begin_define
define|#
directive|define
name|BN_CTX_start
value|hc_BN_CTX_start
end_define

begin_define
define|#
directive|define
name|BN_CTX_end
value|hc_BN_CTX_end
end_define

begin_comment
comment|/*  *  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|BIGNUM
name|BIGNUM
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|BN_GENCB
name|BN_GENCB
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|BN_CTX
name|BN_CTX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|BN_MONT_CTX
name|BN_MONT_CTX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|BN_BLINDING
name|BN_BLINDING
typedef|;
end_typedef

begin_struct
struct|struct
name|BN_GENCB
block|{
name|unsigned
name|int
name|ver
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
union|union
block|{
name|int
function_decl|(
modifier|*
name|cb_2
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|BN_GENCB
modifier|*
parameter_list|)
function_decl|;
block|}
name|cb
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  */
end_comment

begin_function_decl
name|BIGNUM
modifier|*
name|BN_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BN_free
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BN_clear_free
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BN_clear
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BIGNUM
modifier|*
name|BN_dup
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_num_bits
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_num_bytes
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_cmp
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BN_set_negative
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_is_negative
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_is_bit_set
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_set_bit
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_clear_bit
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_set_word
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|BN_get_word
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BIGNUM
modifier|*
name|BN_bin2bn
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
name|len
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_bn2bin
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_hex2bn
parameter_list|(
name|BIGNUM
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|BN_bn2hex
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_uadd
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_rand
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BN_GENCB_set
parameter_list|(
name|BN_GENCB
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|BN_GENCB
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|BN_GENCB_call
parameter_list|(
name|BN_GENCB
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BN_CTX
modifier|*
name|BN_CTX_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BN_CTX_free
parameter_list|(
name|BN_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BIGNUM
modifier|*
name|BN_CTX_get
parameter_list|(
name|BN_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BN_CTX_start
parameter_list|(
name|BN_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BN_CTX_end
parameter_list|(
name|BN_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

