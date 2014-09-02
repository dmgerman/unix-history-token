begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2009 Ariff Abdullah<ariff@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SND_PCM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SND_PCM_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/*  * Macros for reading/writing PCM sample / int values from bytes array.  * Since every process is done using signed integer (and to make our life  * less miserable), unsigned sample will be converted to its signed  * counterpart and restored during writing back. To avoid overflow,  * we truncate 32bit (and only 32bit) samples down to 24bit (see below  * for the reason), unless SND_PCM_64 is defined.  */
end_comment

begin_comment
comment|/*  * Automatically turn on 64bit arithmetic on suitable archs  * (amd64 64bit, etc..) for wider 32bit samples / integer processing.  */
end_comment

begin_if
if|#
directive|if
name|LONG_BIT
operator|>=
literal|64
end_if

begin_undef
undef|#
directive|undef
name|SND_PCM_64
end_undef

begin_define
define|#
directive|define
name|SND_PCM_64
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int32_t
name|intpcm_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|intpcm8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|intpcm16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|intpcm24_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|uintpcm_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|uintpcm8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|uintpcm16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|uintpcm24_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|SND_PCM_64
end_ifdef

begin_typedef
typedef|typedef
name|int64_t
name|intpcm32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|uintpcm32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int32_t
name|intpcm32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|uintpcm32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int64_t
name|intpcm64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|uintpcm64_t
typedef|;
end_typedef

begin_comment
comment|/* 32bit fixed point shift */
end_comment

begin_define
define|#
directive|define
name|PCM_FXSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PCM_S8_MAX
value|0x7f
end_define

begin_define
define|#
directive|define
name|PCM_S8_MIN
value|-0x80
end_define

begin_define
define|#
directive|define
name|PCM_S16_MAX
value|0x7fff
end_define

begin_define
define|#
directive|define
name|PCM_S16_MIN
value|-0x8000
end_define

begin_define
define|#
directive|define
name|PCM_S24_MAX
value|0x7fffff
end_define

begin_define
define|#
directive|define
name|PCM_S24_MIN
value|-0x800000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SND_PCM_64
end_ifdef

begin_if
if|#
directive|if
name|LONG_BIT
operator|>=
literal|64
end_if

begin_define
define|#
directive|define
name|PCM_S32_MAX
value|0x7fffffffL
end_define

begin_define
define|#
directive|define
name|PCM_S32_MIN
value|-0x80000000L
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCM_S32_MAX
value|0x7fffffffLL
end_define

begin_define
define|#
directive|define
name|PCM_S32_MIN
value|-0x80000000LL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCM_S32_MAX
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|PCM_S32_MIN
value|(-0x7fffffff - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Bytes-per-sample definition */
end_comment

begin_define
define|#
directive|define
name|PCM_8_BPS
value|1
end_define

begin_define
define|#
directive|define
name|PCM_16_BPS
value|2
end_define

begin_define
define|#
directive|define
name|PCM_24_BPS
value|3
end_define

begin_define
define|#
directive|define
name|PCM_32_BPS
value|4
end_define

begin_define
define|#
directive|define
name|INTPCM_T
parameter_list|(
name|v
parameter_list|)
value|((intpcm_t)(v))
end_define

begin_define
define|#
directive|define
name|INTPCM8_T
parameter_list|(
name|v
parameter_list|)
value|((intpcm8_t)(v))
end_define

begin_define
define|#
directive|define
name|INTPCM16_T
parameter_list|(
name|v
parameter_list|)
value|((intpcm16_t)(v))
end_define

begin_define
define|#
directive|define
name|INTPCM24_T
parameter_list|(
name|v
parameter_list|)
value|((intpcm24_t)(v))
end_define

begin_define
define|#
directive|define
name|INTPCM32_T
parameter_list|(
name|v
parameter_list|)
value|((intpcm32_t)(v))
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|_PCM_READ_S16_LE
parameter_list|(
name|b8
parameter_list|)
value|INTPCM_T(*((int16_t *)(b8)))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S32_LE
parameter_list|(
name|b8
parameter_list|)
value|INTPCM_T(*((int32_t *)(b8)))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S16_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[1] | (((int8_t)((b8)[0]))<< 8))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S32_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[3] | ((b8)[2]<< 8) | ((b8)[1]<< 16) |		\ 	    (((int8_t)((b8)[0]))<< 24))
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S16_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|do {				\ 	*((int16_t *)(b8)) = (val);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|do {				\ 	*((int32_t *)(b8)) = (val);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S16_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval); 						\ 	uint8_t *b8 = (bb8);						\ 	b8[1] = val;							\ 	b8[0] = val>> 8;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S32_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[3] = val;							\ 	b8[2] = val>> 8;						\ 	b8[1] = val>> 16;						\ 	b8[0] = val>> 24;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U16_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((int16_t)(*((uint16_t *)(b8)) ^ 0x8000))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U32_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((int32_t)(*((uint32_t *)(b8)) ^ 0x80000000))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U16_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[1] | (((int8_t)((b8)[0] ^ 0x80))<< 8))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U32_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[3] | ((b8)[2]<< 8) | ((b8)[1]<< 16) |		\ 	    (((int8_t)((b8)[0] ^ 0x80))<< 24))
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U16_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|do {				\ 	*((uint16_t *)(b8)) = (val) ^ 0x8000;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|do {				\ 	*((uint32_t *)(b8)) = (val) ^ 0x80000000;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U16_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[1] = val;							\ 	b8[0] = (val>> 8) ^ 0x80;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U32_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[3] = val;							\ 	b8[2] = val>> 8;						\ 	b8[1] = val>> 16;						\ 	b8[0] = (val>> 24) ^ 0x80;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S16_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S16_LE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U16_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U16_LE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S32_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S32_LE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U32_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U32_LE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S16_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_S16_LE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U16_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_U16_LE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S32_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_S32_LE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U32_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_U32_LE(b8)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|_PCM_READ_S16_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[0] | (((int8_t)((b8)[1]))<< 8))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S32_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[0] | ((b8)[1]<< 8) | ((b8)[2]<< 16) |		\ 	    (((int8_t)((b8)[3]))<< 24))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S16_BE
parameter_list|(
name|b8
parameter_list|)
value|INTPCM_T(*((int16_t *)(b8)))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S32_BE
parameter_list|(
name|b8
parameter_list|)
value|INTPCM_T(*((int32_t *)(b8)))
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S16_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[0] = val;							\ 	b8[1] = val>> 8;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S32_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[0] = val;							\ 	b8[1] = val>> 8;						\ 	b8[2] = val>> 16;						\ 	b8[3] = val>> 24;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S16_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|do {				\ 	*((int16_t *)(b8)) = (val);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|do {				\ 	*((int32_t *)(b8)) = (val);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U16_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[0] | (((int8_t)((b8)[1] ^ 0x80))<< 8))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U32_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[0] | ((b8)[1]<< 8) | ((b8)[2]<< 16) |		\ 	    (((int8_t)((b8)[3] ^ 0x80))<< 24))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U16_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((int16_t)(*((uint16_t *)(b8)) ^ 0x8000))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U32_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((int32_t)(*((uint32_t *)(b8)) ^ 0x80000000))
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U16_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[0] = val;							\ 	b8[1] = (val>> 8) ^ 0x80;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U32_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[0] = val;							\ 	b8[1] = val>> 8;						\ 	b8[2] = val>> 16;						\ 	b8[3] = (val>> 24) ^ 0x80;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U16_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|do {				\ 	*((uint16_t *)(b8)) = (val) ^ 0x8000;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|do {				\ 	*((uint32_t *)(b8)) = (val) ^ 0x80000000;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S16_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S16_BE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U16_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U16_BE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S32_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S32_BE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U32_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U32_BE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S16_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_S16_BE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U16_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_U16_BE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S32_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_S32_BE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U32_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_U32_BE(b8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|_PCM_READ_S24_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[0] | ((b8)[1]<< 8) | (((int8_t)((b8)[2]))<< 16))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S24_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[2] | ((b8)[1]<< 8) | (((int8_t)((b8)[0]))<< 16))
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S24_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[0] = val;							\ 	b8[1] = val>> 8;						\ 	b8[2] = val>> 16;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S24_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[2] = val;							\ 	b8[1] = val>> 8;						\ 	b8[0] = val>> 16;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U24_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[0] | ((b8)[1]<< 8) |				\ 	    (((int8_t)((b8)[2] ^ 0x80))<< 16))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U24_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((b8)[2] | ((b8)[1]<< 8) |				\ 	    (((int8_t)((b8)[0] ^ 0x80))<< 16))
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U24_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[0] = val;							\ 	b8[1] = val>> 8;						\ 	b8[2] = (val>> 16) ^ 0x80;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U24_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do {				\ 	intpcm_t val = (vval);						\ 	uint8_t *b8 = (bb8);						\ 	b8[2] = val;							\ 	b8[1] = val>> 8;						\ 	b8[0] = (val>> 16) ^ 0x80;					\ } while (0)
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|_PCM_READ_S24_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S24_LE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U24_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U24_LE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S24_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_S24_LE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U24_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_U24_LE(b8)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|_PCM_READ_S24_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S24_BE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U24_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U24_BE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S24_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_S24_BE(b8)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U24_NE
parameter_list|(
name|b6
parameter_list|)
value|_PCM_WRITE_U24_BE(b8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LITTLE_ENDIAN */
end_comment

begin_comment
comment|/*  * 8bit sample is pretty much useless since it doesn't provide  * sufficient dynamic range throughout our filtering process.  * For the sake of completeness, declare it anyway.  */
end_comment

begin_define
define|#
directive|define
name|_PCM_READ_S8_NE
parameter_list|(
name|b8
parameter_list|)
value|INTPCM_T(*((int8_t *)(b8)))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U8_NE
parameter_list|(
name|b8
parameter_list|)
define|\
value|INTPCM_T((int8_t)(*((uint8_t *)(b8)) ^ 0x80))
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S8_NE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|do {				\ 	*((int8_t *)(b8)) = (val);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U8_NE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|do {				\ 	*((uint8_t *)(b8)) = (val) ^ 0x80;				\ } while (0)
end_define

begin_comment
comment|/*  * Common macross. Use this instead of "_", unless we want  * the real sample value.  */
end_comment

begin_comment
comment|/* 8bit */
end_comment

begin_define
define|#
directive|define
name|PCM_READ_S8_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S8_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U8_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U8_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S8_NE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S8_NE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U8_NE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U8_NE(b8, val)
end_define

begin_comment
comment|/* 16bit */
end_comment

begin_define
define|#
directive|define
name|PCM_READ_S16_LE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S16_LE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_S16_BE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S16_BE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U16_LE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U16_LE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U16_BE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U16_BE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S16_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S16_LE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S16_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S16_BE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U16_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U16_LE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U16_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U16_BE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_READ_S16_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S16_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U16_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U16_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S16_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_WRITE_S16_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U16_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_WRITE_U16_NE(b8)
end_define

begin_comment
comment|/* 24bit */
end_comment

begin_define
define|#
directive|define
name|PCM_READ_S24_LE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S24_LE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_S24_BE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S24_BE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U24_LE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U24_LE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U24_BE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U24_BE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S24_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S24_LE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S24_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S24_BE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U24_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U24_LE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U24_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U24_BE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_READ_S24_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S24_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U24_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U24_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S24_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_WRITE_S24_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U24_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_WRITE_U24_NE(b8)
end_define

begin_comment
comment|/* 32bit */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SND_PCM_64
end_ifdef

begin_define
define|#
directive|define
name|PCM_READ_S32_LE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S32_LE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_S32_BE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S32_BE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U32_LE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U32_LE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U32_BE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U32_BE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S32_LE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S32_BE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U32_LE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U32_BE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_READ_S32_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S32_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U32_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U32_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S32_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_WRITE_S32_NE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U32_NE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_WRITE_U32_NE(b8)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SND_PCM_64 */
end_comment

begin_comment
comment|/*  * 24bit integer ?!? This is quite unfortunate, eh? Get the fact straight:  * Dynamic range for:  *	1) Human =~ 140db  *	2) 16bit = 96db (close enough)  *	3) 24bit = 144db (perfect)  *	4) 32bit = 196db (way too much)  *	5) Bugs Bunny = Gazillion!@%$Erbzzztt-EINVAL db  * Since we're not Bugs Bunny ..uh..err.. avoiding 64bit arithmetic, 24bit  * is pretty much sufficient for our signed integer processing.  */
end_comment

begin_define
define|#
directive|define
name|PCM_READ_S32_LE
parameter_list|(
name|b8
parameter_list|)
value|(_PCM_READ_S32_LE(b8)>> PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_READ_S32_BE
parameter_list|(
name|b8
parameter_list|)
value|(_PCM_READ_S32_BE(b8)>> PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U32_LE
parameter_list|(
name|b8
parameter_list|)
value|(_PCM_READ_U32_LE(b8)>> PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U32_BE
parameter_list|(
name|b8
parameter_list|)
value|(_PCM_READ_U32_BE(b8)>> PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_READ_S32_NE
parameter_list|(
name|b8
parameter_list|)
value|(_PCM_READ_S32_NE(b8)>> PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U32_NE
parameter_list|(
name|b8
parameter_list|)
value|(_PCM_READ_U32_NE(b8)>> PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
define|\
value|_PCM_WRITE_S32_LE(b8, (val)<< PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
define|\
value|_PCM_WRITE_S32_BE(b8, (val)<< PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
define|\
value|_PCM_WRITE_U32_LE(b8, (val)<< PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
define|\
value|_PCM_WRITE_U32_BE(b8, (val)<< PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S32_NE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
define|\
value|_PCM_WRITE_S32_NE(b8, (val)<< PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U32_NE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
define|\
value|_PCM_WRITE_U32_NE(b8, (val)<< PCM_FXSHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SND_PCM_64 */
end_comment

begin_define
define|#
directive|define
name|PCM_CLAMP_S8
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)> PCM_S8_MAX) ? PCM_S8_MAX :		\ 			 (((val)< PCM_S8_MIN) ? PCM_S8_MIN : (val)))
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_S16
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)> PCM_S16_MAX) ? PCM_S16_MAX :		\ 			 (((val)< PCM_S16_MIN) ? PCM_S16_MIN : (val)))
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_S24
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)> PCM_S24_MAX) ? PCM_S24_MAX :		\ 			 (((val)< PCM_S24_MIN) ? PCM_S24_MIN : (val)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SND_PCM_64
end_ifdef

begin_define
define|#
directive|define
name|PCM_CLAMP_S32
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)> PCM_S32_MAX) ? PCM_S32_MAX :		\ 			 (((val)< PCM_S32_MIN) ? PCM_S32_MIN : (val)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SND_PCM_64 */
end_comment

begin_define
define|#
directive|define
name|PCM_CLAMP_S32
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)> PCM_S24_MAX) ? PCM_S32_MAX :		\ 			 (((val)< PCM_S24_MIN) ? PCM_S32_MIN :		\ 			 ((val)<< PCM_FXSHIFT)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SND_PCM_64 */
end_comment

begin_define
define|#
directive|define
name|PCM_CLAMP_U8
parameter_list|(
name|val
parameter_list|)
value|PCM_CLAMP_S8(val)
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_U16
parameter_list|(
name|val
parameter_list|)
value|PCM_CLAMP_S16(val)
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_U24
parameter_list|(
name|val
parameter_list|)
value|PCM_CLAMP_S24(val)
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_U32
parameter_list|(
name|val
parameter_list|)
value|PCM_CLAMP_S32(val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SND_PCM_H_ */
end_comment

end_unit

