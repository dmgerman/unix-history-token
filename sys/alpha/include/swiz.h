begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SWIZ_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SWIZ_H_
end_define

begin_comment
comment|/*  * Macros for accessing device ports or memory in a sparse address space.  */
end_comment

begin_define
define|#
directive|define
name|SPARSE_READ
parameter_list|(
name|o
parameter_list|)
value|(*(u_int32_t*) (o))
end_define

begin_define
define|#
directive|define
name|SPARSE_WRITE
parameter_list|(
name|o
parameter_list|,
name|d
parameter_list|)
value|(*(u_int32_t*) (o) = (d))
end_define

begin_define
define|#
directive|define
name|SPARSE_BYTE_OFFSET
parameter_list|(
name|o
parameter_list|)
value|(((o)<< 5) | (0<< 3))
end_define

begin_define
define|#
directive|define
name|SPARSE_WORD_OFFSET
parameter_list|(
name|o
parameter_list|)
value|(((o)<< 5) | (1<< 3))
end_define

begin_define
define|#
directive|define
name|SPARSE_LONG_OFFSET
parameter_list|(
name|o
parameter_list|)
value|(((o)<< 5) | (3<< 3))
end_define

begin_define
define|#
directive|define
name|SPARSE_BYTE_ADDRESS
parameter_list|(
name|base
parameter_list|,
name|o
parameter_list|)
value|((base) + SPARSE_BYTE_OFFSET(o))
end_define

begin_define
define|#
directive|define
name|SPARSE_WORD_ADDRESS
parameter_list|(
name|base
parameter_list|,
name|o
parameter_list|)
value|((base) + SPARSE_WORD_OFFSET(o))
end_define

begin_define
define|#
directive|define
name|SPARSE_LONG_ADDRESS
parameter_list|(
name|base
parameter_list|,
name|o
parameter_list|)
value|((base) + SPARSE_LONG_OFFSET(o))
end_define

begin_define
define|#
directive|define
name|SPARSE_BYTE_EXTRACT
parameter_list|(
name|o
parameter_list|,
name|d
parameter_list|)
value|((d)>> (8*((o)& 3)))
end_define

begin_define
define|#
directive|define
name|SPARSE_WORD_EXTRACT
parameter_list|(
name|o
parameter_list|,
name|d
parameter_list|)
value|((d)>> (8*((o)& 2)))
end_define

begin_define
define|#
directive|define
name|SPARSE_LONG_EXTRACT
parameter_list|(
name|o
parameter_list|,
name|d
parameter_list|)
value|(d)
end_define

begin_define
define|#
directive|define
name|SPARSE_BYTE_INSERT
parameter_list|(
name|o
parameter_list|,
name|d
parameter_list|)
value|((d)<< (8*((o)& 3)))
end_define

begin_define
define|#
directive|define
name|SPARSE_WORD_INSERT
parameter_list|(
name|o
parameter_list|,
name|d
parameter_list|)
value|((d)<< (8*((o)& 2)))
end_define

begin_define
define|#
directive|define
name|SPARSE_LONG_INSERT
parameter_list|(
name|o
parameter_list|,
name|d
parameter_list|)
value|(d)
end_define

begin_define
define|#
directive|define
name|SPARSE_READ_BYTE
parameter_list|(
name|base
parameter_list|,
name|o
parameter_list|)
define|\
value|SPARSE_BYTE_EXTRACT(o, SPARSE_READ(base + SPARSE_BYTE_OFFSET(o)))
end_define

begin_define
define|#
directive|define
name|SPARSE_READ_WORD
parameter_list|(
name|base
parameter_list|,
name|o
parameter_list|)
define|\
value|SPARSE_WORD_EXTRACT(o, SPARSE_READ(base + SPARSE_WORD_OFFSET(o)))
end_define

begin_define
define|#
directive|define
name|SPARSE_READ_LONG
parameter_list|(
name|base
parameter_list|,
name|o
parameter_list|)
define|\
value|SPARSE_READ(base + SPARSE_LONG_OFFSET(o))
end_define

begin_define
define|#
directive|define
name|SPARSE_WRITE_BYTE
parameter_list|(
name|base
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|)
define|\
value|SPARSE_WRITE(base + SPARSE_BYTE_OFFSET(o), SPARSE_BYTE_INSERT(o, d))
end_define

begin_define
define|#
directive|define
name|SPARSE_WRITE_WORD
parameter_list|(
name|base
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|)
define|\
value|SPARSE_WRITE(base + SPARSE_WORD_OFFSET(o), SPARSE_WORD_INSERT(o, d))
end_define

begin_define
define|#
directive|define
name|SPARSE_WRITE_LONG
parameter_list|(
name|base
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|)
define|\
value|SPARSE_WRITE(base + SPARSE_LONG_OFFSET(o), d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SWIZ_H_ */
end_comment

end_unit

