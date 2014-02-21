begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 KISA(Korea Information Security Agency). All rights reserved.    *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Neither the name of author nor the names of its contributors may  *    be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_SEED_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_SEED_LOCL_H
end_define

begin_include
include|#
directive|include
file|"openssl/e_os2.h"
end_include

begin_include
include|#
directive|include
file|<openssl/seed.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SEED_LONG
end_ifdef

begin_comment
comment|/* need 32-bit type */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|seed_word
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|int
name|seed_word
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|G_FUNC
parameter_list|(
name|v
parameter_list|)
define|\
value|SS[0][(unsigned char)      (v)& 0xff] ^ SS[1][(unsigned char) ((v)>>8)& 0xff] ^ \         SS[2][(unsigned char)((v)>>16)& 0xff] ^ SS[3][(unsigned char)((v)>>24)& 0xff]
define|#
directive|define
name|char2word
parameter_list|(
name|c
parameter_list|,
name|i
parameter_list|)
define|\
value|(i) = ((((seed_word)(c)[0])<< 24) | (((seed_word)(c)[1])<< 16) | (((seed_word)(c)[2])<< 8) | ((seed_word)(c)[3]))
define|#
directive|define
name|word2char
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
define|\
value|*((c)+0) = (unsigned char)((l)>>24)& 0xff; \         *((c)+1) = (unsigned char)((l)>>16)& 0xff; \         *((c)+2) = (unsigned char)((l)>> 8)& 0xff; \         *((c)+3) = (unsigned char)((l))& 0xff
define|#
directive|define
name|KEYSCHEDULE_UPDATE0
parameter_list|(
name|T0
parameter_list|,
name|T1
parameter_list|,
name|X1
parameter_list|,
name|X2
parameter_list|,
name|X3
parameter_list|,
name|X4
parameter_list|,
name|KC
parameter_list|)
define|\
value|(T0) = (X3);                                     \         (X3) = (((X3)<<8) ^ ((X4)>>24))& 0xffffffff;    \         (X4) = (((X4)<<8) ^ ((T0)>>24))& 0xffffffff;    \         (T0) = ((X1) + (X3) - (KC))& 0xffffffff;    \         (T1) = ((X2) + (KC) - (X4))& 0xffffffff
define|#
directive|define
name|KEYSCHEDULE_UPDATE1
parameter_list|(
name|T0
parameter_list|,
name|T1
parameter_list|,
name|X1
parameter_list|,
name|X2
parameter_list|,
name|X3
parameter_list|,
name|X4
parameter_list|,
name|KC
parameter_list|)
define|\
value|(T0) = (X1);                                     \         (X1) = (((X1)>>8) ^ ((X2)<<24))& 0xffffffff;    \         (X2) = (((X2)>>8) ^ ((T0)<<24))& 0xffffffff;    \         (T0) = ((X1) + (X3) - (KC))& 0xffffffff;     \         (T1) = ((X2) + (KC) - (X4))& 0xffffffff
define|#
directive|define
name|KEYUPDATE_TEMP
parameter_list|(
name|T0
parameter_list|,
name|T1
parameter_list|,
name|K
parameter_list|)
define|\
value|(K)[0] = G_FUNC((T0));      \         (K)[1] = G_FUNC((T1))
define|#
directive|define
name|XOR_SEEDBLOCK
parameter_list|(
name|DST
parameter_list|,
name|SRC
parameter_list|)
define|\
value|((DST))[0] ^= ((SRC))[0];    \         ((DST))[1] ^= ((SRC))[1];    \         ((DST))[2] ^= ((SRC))[2];    \         ((DST))[3] ^= ((SRC))[3]
define|#
directive|define
name|MOV_SEEDBLOCK
parameter_list|(
name|DST
parameter_list|,
name|SRC
parameter_list|)
define|\
value|((DST))[0] = ((SRC))[0];     \         ((DST))[1] = ((SRC))[1];     \         ((DST))[2] = ((SRC))[2];     \         ((DST))[3] = ((SRC))[3]
define|#
directive|define
name|CHAR2WORD
parameter_list|(
name|C
parameter_list|,
name|I
parameter_list|)
define|\
value|char2word((C),    (I)[0]);    \         char2word((C+4),  (I)[1]);    \         char2word((C+8),  (I)[2]);    \         char2word((C+12), (I)[3])
define|#
directive|define
name|WORD2CHAR
parameter_list|(
name|I
parameter_list|,
name|C
parameter_list|)
define|\
value|word2char((I)[0], (C));       \         word2char((I)[1], (C+4));     \         word2char((I)[2], (C+8));     \         word2char((I)[3], (C+12))
define|#
directive|define
name|E_SEED
parameter_list|(
name|T0
parameter_list|,
name|T1
parameter_list|,
name|X1
parameter_list|,
name|X2
parameter_list|,
name|X3
parameter_list|,
name|X4
parameter_list|,
name|rbase
parameter_list|)
define|\
value|(T0) = (X3) ^ (ks->data)[(rbase)];       \         (T1) = (X4) ^ (ks->data)[(rbase)+1];     \         (T1) ^= (T0);                            \         (T1) = G_FUNC((T1));                     \         (T0) = ((T0) + (T1))& 0xffffffff;       \         (T0) = G_FUNC((T0));                     \         (T1) = ((T1) + (T0))& 0xffffffff;       \         (T1) = G_FUNC((T1));                     \         (T0) = ((T0) + (T1))& 0xffffffff;       \         (X1) ^= (T0);                            \         (X2) ^= (T1)
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEADER_SEED_LOCL_H */
end_comment

end_unit

