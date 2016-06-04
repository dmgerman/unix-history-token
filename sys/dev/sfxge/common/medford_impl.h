begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Solarflare Communications Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright notice,  *    this list of conditions and the following disclaimer in the documentation  *    and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * The views and conclusions contained in the software and documentation are  * those of the authors and should not be interpreted as representing official  * policies, either expressed or implied, of the FreeBSD Project.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MEDFORD_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MEDFORD_IMPL_H
end_define

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
comment|/* Alignment requirement for value written to RX WPTR:  *  the WPTR must be aligned to an 8 descriptor boundary  *  * FIXME: Is this the same on Medford as Huntington?  */
define|#
directive|define
name|MEDFORD_RX_WPTR_ALIGN
value|8
ifndef|#
directive|ifndef
name|ER_EZ_TX_PIOBUF_SIZE
define|#
directive|define
name|ER_EZ_TX_PIOBUF_SIZE
value|4096
endif|#
directive|endif
define|#
directive|define
name|MEDFORD_PIOBUF_NBUFS
value|(16)
define|#
directive|define
name|MEDFORD_PIOBUF_SIZE
value|(ER_EZ_TX_PIOBUF_SIZE)
define|#
directive|define
name|MEDFORD_MIN_PIO_ALLOC_SIZE
value|(MEDFORD_PIOBUF_SIZE / 32)
specifier|extern
name|__checkReturn
name|efx_rc_t
name|medford_board_cfg
parameter_list|(
name|__in
name|efx_nic_t
modifier|*
name|enp
parameter_list|)
function_decl|;
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
comment|/* _SYS_MEDFORD_IMPL_H */
end_comment

end_unit

