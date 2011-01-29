begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_ATH_MISC_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_ATH_MISC_H__
end_define

begin_comment
comment|/*  * This is where definitions for "public things" in if_ath.c  * will go for the time being.  *  * Anything in here should eventually be moved out of if_ath.c  * and into something else.  */
end_comment

begin_comment
comment|/* unaligned little endian access */
end_comment

begin_define
define|#
directive|define
name|LE_READ_2
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int16_t)							\ 	 ((((u_int8_t *)(p))[0]      ) | (((u_int8_t *)(p))[1]<<  8)))
end_define

begin_define
define|#
directive|define
name|LE_READ_4
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int32_t)							\ 	 ((((u_int8_t *)(p))[0]      ) | (((u_int8_t *)(p))[1]<<  8) |	\ 	  (((u_int8_t *)(p))[2]<< 16) | (((u_int8_t *)(p))[3]<< 24)))
end_define

begin_function_decl
specifier|extern
name|int
name|ath_tx_findrix
parameter_list|(
specifier|const
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ath_buf
modifier|*
name|ath_getbuf
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ath_buf
modifier|*
name|_ath_getbuf_locked
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

