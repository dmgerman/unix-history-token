begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2009 Ariff Abdullah<ariff@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SND_INTPCM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SND_INTPCM_H_
end_define

begin_typedef
typedef|typedef
name|intpcm_t
name|intpcm_read_t
parameter_list|(
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|intpcm_write_t
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|intpcm_t
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|intpcm_read_t
modifier|*
name|feeder_format_read_op
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|intpcm_write_t
modifier|*
name|feeder_format_write_op
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|INTPCM_DECLARE_OP_WRITE
parameter_list|(
name|SIGN
parameter_list|,
name|BIT
parameter_list|,
name|ENDIAN
parameter_list|,
name|SHIFT
parameter_list|)
define|\
value|static __inline void							\ intpcm_write_##SIGN##BIT##ENDIAN(uint8_t *dst, intpcm_t v)		\ {									\ 									\ 	_PCM_WRITE_##SIGN##BIT##_##ENDIAN(dst, v>> SHIFT);		\ }
end_define

begin_define
define|#
directive|define
name|INTPCM_DECLARE_OP_8
parameter_list|(
name|SIGN
parameter_list|,
name|ENDIAN
parameter_list|)
define|\
value|static __inline intpcm_t						\ intpcm_read_##SIGN##8##ENDIAN(uint8_t *src)				\ {									\ 									\ 	return (_PCM_READ_##SIGN##8##_##ENDIAN(src)<< 24);		\ }									\ INTPCM_DECLARE_OP_WRITE(SIGN, 8, ENDIAN, 24)
end_define

begin_define
define|#
directive|define
name|INTPCM_DECLARE_OP_16
parameter_list|(
name|SIGN
parameter_list|,
name|ENDIAN
parameter_list|)
define|\
value|static __inline intpcm_t						\ intpcm_read_##SIGN##16##ENDIAN(uint8_t *src)				\ {									\ 									\ 	return (_PCM_READ_##SIGN##16##_##ENDIAN(src)<< 16);		\ }									\ INTPCM_DECLARE_OP_WRITE(SIGN, 16, ENDIAN, 16)
end_define

begin_define
define|#
directive|define
name|INTPCM_DECLARE_OP_24
parameter_list|(
name|SIGN
parameter_list|,
name|ENDIAN
parameter_list|)
define|\
value|static __inline intpcm_t						\ intpcm_read_##SIGN##24##ENDIAN(uint8_t *src)				\ {									\ 									\ 	return (_PCM_READ_##SIGN##24##_##ENDIAN(src)<< 8);		\ }									\ INTPCM_DECLARE_OP_WRITE(SIGN, 24, ENDIAN, 8)
end_define

begin_define
define|#
directive|define
name|INTPCM_DECLARE_OP_32
parameter_list|(
name|SIGN
parameter_list|,
name|ENDIAN
parameter_list|)
define|\
value|static __inline intpcm_t						\ intpcm_read_##SIGN##32##ENDIAN(uint8_t *src)				\ {									\ 									\ 	return (_PCM_READ_##SIGN##32##_##ENDIAN(src));			\ }									\ 									\ static __inline void							\ intpcm_write_##SIGN##32##ENDIAN(uint8_t *dst, intpcm_t v)		\ {									\ 									\ 	_PCM_WRITE_##SIGN##32##_##ENDIAN(dst, v);			\ }
end_define

begin_define
define|#
directive|define
name|INTPCM_DECLARE
parameter_list|(
name|t
parameter_list|)
define|\ 									\
value|G711_DECLARE_TABLE(t);							\ 									\ static __inline intpcm_t						\ intpcm_read_ulaw(uint8_t *src)						\ {									\ 									\ 	return (_G711_TO_INTPCM((t).ulaw_to_u8, *src)<< 24);		\ }									\ 									\ static __inline intpcm_t						\ intpcm_read_alaw(uint8_t *src)						\ {									\ 									\ 	return (_G711_TO_INTPCM((t).alaw_to_u8, *src)<< 24);		\ }									\ 									\ static __inline void							\ intpcm_write_ulaw(uint8_t *dst, intpcm_t v)				\ {									\ 									\ 	*dst = _INTPCM_TO_G711((t).u8_to_ulaw, v>> 24);		\ }									\ 									\ static __inline void							\ intpcm_write_alaw(uint8_t *dst, intpcm_t v)				\ {									\ 									\ 	*dst = _INTPCM_TO_G711((t).u8_to_alaw, v>> 24);		\ }									\ 									\ INTPCM_DECLARE_OP_8(S, NE)						\ INTPCM_DECLARE_OP_16(S, LE)						\ INTPCM_DECLARE_OP_16(S, BE)						\ INTPCM_DECLARE_OP_24(S, LE)						\ INTPCM_DECLARE_OP_24(S, BE)						\ INTPCM_DECLARE_OP_32(S, LE)						\ INTPCM_DECLARE_OP_32(S, BE)						\ INTPCM_DECLARE_OP_8(U,  NE)						\ INTPCM_DECLARE_OP_16(U, LE)						\ INTPCM_DECLARE_OP_16(U, BE)						\ INTPCM_DECLARE_OP_24(U, LE)						\ INTPCM_DECLARE_OP_24(U, BE)						\ INTPCM_DECLARE_OP_32(U, LE)						\ INTPCM_DECLARE_OP_32(U, BE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SND_INTPCM_H_ */
end_comment

end_unit

