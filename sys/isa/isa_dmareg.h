begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2005 TAKAHASHI Yoshihiro. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISA_ISA_DMAREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ISA_ISA_DMAREG_H_
end_define

begin_include
include|#
directive|include
file|<dev/ic/i8237.h>
end_include

begin_define
define|#
directive|define
name|IO_DMA1
value|0x00
end_define

begin_comment
comment|/* 8237A DMA Controller #1 */
end_comment

begin_define
define|#
directive|define
name|IO_DMA2
value|0xC0
end_define

begin_comment
comment|/* 8237A DMA Controller #2 */
end_comment

begin_comment
comment|/*  * Register definitions for DMA controller 1 (channels 0..3):  */
end_comment

begin_define
define|#
directive|define
name|DMA1_CHN
parameter_list|(
name|c
parameter_list|)
value|(IO_DMA1 + 1*(2*(c)))
end_define

begin_comment
comment|/* addr reg for channel c */
end_comment

begin_define
define|#
directive|define
name|DMA1_STATUS
value|(IO_DMA1 + 1*8)
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|DMA1_SMSK
value|(IO_DMA1 + 1*10)
end_define

begin_comment
comment|/* single mask register */
end_comment

begin_define
define|#
directive|define
name|DMA1_MODE
value|(IO_DMA1 + 1*11)
end_define

begin_comment
comment|/* mode register */
end_comment

begin_define
define|#
directive|define
name|DMA1_FFC
value|(IO_DMA1 + 1*12)
end_define

begin_comment
comment|/* clear first/last FF */
end_comment

begin_define
define|#
directive|define
name|DMA1_RESET
value|(IO_DMA1 + 1*13)
end_define

begin_comment
comment|/* reset */
end_comment

begin_comment
comment|/*  * Register definitions for DMA controller 2 (channels 4..7):  */
end_comment

begin_define
define|#
directive|define
name|DMA2_CHN
parameter_list|(
name|c
parameter_list|)
value|(IO_DMA2 + 2*(2*(c)))
end_define

begin_comment
comment|/* addr reg for channel c */
end_comment

begin_define
define|#
directive|define
name|DMA2_STATUS
value|(IO_DMA2 + 2*8)
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|DMA2_SMSK
value|(IO_DMA2 + 2*10)
end_define

begin_comment
comment|/* single mask register */
end_comment

begin_define
define|#
directive|define
name|DMA2_MODE
value|(IO_DMA2 + 2*11)
end_define

begin_comment
comment|/* mode register */
end_comment

begin_define
define|#
directive|define
name|DMA2_FFC
value|(IO_DMA2 + 2*12)
end_define

begin_comment
comment|/* clear first/last FF */
end_comment

begin_define
define|#
directive|define
name|DMA2_RESET
value|(IO_DMA2 + 2*13)
end_define

begin_comment
comment|/* reset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISA_ISA_DMAREG_H_ */
end_comment

end_unit

