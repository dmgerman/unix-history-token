begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB2_ENDIAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_ENDIAN_H_
end_define

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_comment
comment|/*  * Declare the basic USB record types. USB records have an alignment  * of 1 byte and are always packed.  */
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|uByte
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|uWord
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|uDWord
index|[
literal|4
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|uQWord
index|[
literal|8
index|]
typedef|;
end_typedef

begin_comment
comment|/*  * Define a set of macros that can get and set data independent of  * CPU endianness and CPU alignment requirements:  */
end_comment

begin_define
define|#
directive|define
name|UGETB
parameter_list|(
name|w
parameter_list|)
define|\
value|((w)[0])
end_define

begin_define
define|#
directive|define
name|UGETW
parameter_list|(
name|w
parameter_list|)
define|\
value|((w)[0] |				\   (((uint16_t)((w)[1]))<< 8))
end_define

begin_define
define|#
directive|define
name|UGETDW
parameter_list|(
name|w
parameter_list|)
define|\
value|((w)[0] |				\   (((uint16_t)((w)[1]))<< 8) |		\   (((uint32_t)((w)[2]))<< 16) |	\   (((uint32_t)((w)[3]))<< 24))
end_define

begin_define
define|#
directive|define
name|UGETQW
parameter_list|(
name|w
parameter_list|)
define|\
value|((w)[0] |				\   (((uint16_t)((w)[1]))<< 8) |		\   (((uint32_t)((w)[2]))<< 16) |	\   (((uint32_t)((w)[3]))<< 24) |	\   (((uint64_t)((w)[4]))<< 32) |	\   (((uint64_t)((w)[5]))<< 40) |	\   (((uint64_t)((w)[6]))<< 48) |	\   (((uint64_t)((w)[7]))<< 56))
end_define

begin_define
define|#
directive|define
name|USETB
parameter_list|(
name|w
parameter_list|,
name|v
parameter_list|)
value|do {			\   (w)[0] = (uint8_t)(v);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|USETW
parameter_list|(
name|w
parameter_list|,
name|v
parameter_list|)
value|do {			\   (w)[0] = (uint8_t)(v);		\   (w)[1] = (uint8_t)((v)>> 8);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|USETDW
parameter_list|(
name|w
parameter_list|,
name|v
parameter_list|)
value|do {		\   (w)[0] = (uint8_t)(v);		\   (w)[1] = (uint8_t)((v)>> 8);		\   (w)[2] = (uint8_t)((v)>> 16);	\   (w)[3] = (uint8_t)((v)>> 24);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|USETQW
parameter_list|(
name|w
parameter_list|,
name|v
parameter_list|)
value|do {		\   (w)[0] = (uint8_t)(v);		\   (w)[1] = (uint8_t)((v)>> 8);		\   (w)[2] = (uint8_t)((v)>> 16);	\   (w)[3] = (uint8_t)((v)>> 24);	\   (w)[4] = (uint8_t)((v)>> 32);	\   (w)[5] = (uint8_t)((v)>> 40);	\   (w)[6] = (uint8_t)((v)>> 48);	\   (w)[7] = (uint8_t)((v)>> 56);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|USETW2
parameter_list|(
name|w
parameter_list|,
name|b1
parameter_list|,
name|b0
parameter_list|)
value|do {		\   (w)[0] = (uint8_t)(b0);		\   (w)[1] = (uint8_t)(b1);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|USETW4
parameter_list|(
name|w
parameter_list|,
name|b3
parameter_list|,
name|b2
parameter_list|,
name|b1
parameter_list|,
name|b0
parameter_list|)
value|do {	\   (w)[0] = (uint8_t)(b0);		\   (w)[1] = (uint8_t)(b1);		\   (w)[2] = (uint8_t)(b2);		\   (w)[3] = (uint8_t)(b3);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|USETW8
parameter_list|(
name|w
parameter_list|,
name|b7
parameter_list|,
name|b6
parameter_list|,
name|b5
parameter_list|,
name|b4
parameter_list|,
name|b3
parameter_list|,
name|b2
parameter_list|,
name|b1
parameter_list|,
name|b0
parameter_list|)
value|do {	\   (w)[0] = (uint8_t)(b0);		\   (w)[1] = (uint8_t)(b1);		\   (w)[2] = (uint8_t)(b2);		\   (w)[3] = (uint8_t)(b3);		\   (w)[4] = (uint8_t)(b4);		\   (w)[5] = (uint8_t)(b5);		\   (w)[6] = (uint8_t)(b6);		\   (w)[7] = (uint8_t)(b7);		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_ENDIAN_H_ */
end_comment

end_unit

