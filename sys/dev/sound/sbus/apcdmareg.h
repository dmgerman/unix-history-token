begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: apcdmareg.h,v 1.2 2003/06/02 18:53:18 jason Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Jason L. Wright (jason@thought.net)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Definitions for Sun APC DMA controller.  */
end_comment

begin_comment
comment|/* APC DMA registers */
end_comment

begin_define
define|#
directive|define
name|APC_CSR
value|0x0010
end_define

begin_comment
comment|/* control/status */
end_comment

begin_define
define|#
directive|define
name|APC_CVA
value|0x0020
end_define

begin_comment
comment|/* capture virtual address */
end_comment

begin_define
define|#
directive|define
name|APC_CC
value|0x0024
end_define

begin_comment
comment|/* capture count */
end_comment

begin_define
define|#
directive|define
name|APC_CNVA
value|0x0028
end_define

begin_comment
comment|/* capture next virtual address */
end_comment

begin_define
define|#
directive|define
name|APC_CNC
value|0x002c
end_define

begin_comment
comment|/* capture next count */
end_comment

begin_define
define|#
directive|define
name|APC_PVA
value|0x0030
end_define

begin_comment
comment|/* playback virtual address */
end_comment

begin_define
define|#
directive|define
name|APC_PC
value|0x0034
end_define

begin_comment
comment|/* playback count */
end_comment

begin_define
define|#
directive|define
name|APC_PNVA
value|0x0038
end_define

begin_comment
comment|/* playback next virtual address */
end_comment

begin_define
define|#
directive|define
name|APC_PNC
value|0x003c
end_define

begin_comment
comment|/* playback next count */
end_comment

begin_comment
comment|/*  * APC DMA Register definitions  */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_RESET
value|0x00000001
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_CDMA_GO
value|0x00000004
end_define

begin_comment
comment|/* capture dma go */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_PDMA_GO
value|0x00000008
end_define

begin_comment
comment|/* playback dma go */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_CODEC_RESET
value|0x00000020
end_define

begin_comment
comment|/* codec reset */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_CPAUSE
value|0x00000040
end_define

begin_comment
comment|/* capture dma pause */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_PPAUSE
value|0x00000080
end_define

begin_comment
comment|/* playback dma pause */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_CMIE
value|0x00000100
end_define

begin_comment
comment|/* capture pipe empty enb */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_CMI
value|0x00000200
end_define

begin_comment
comment|/* capture pipe empty intr */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_CD
value|0x00000400
end_define

begin_comment
comment|/* capture nva dirty */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_CM
value|0x00000800
end_define

begin_comment
comment|/* capture data lost */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_PMIE
value|0x00001000
end_define

begin_comment
comment|/* pb pipe empty intr enable */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_PD
value|0x00002000
end_define

begin_comment
comment|/* pb nva dirty */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_PM
value|0x00004000
end_define

begin_comment
comment|/* pb pipe empty */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_PMI
value|0x00008000
end_define

begin_comment
comment|/* pb pipe empty interrupt */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_EIE
value|0x00010000
end_define

begin_comment
comment|/* error interrupt enable */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_CIE
value|0x00020000
end_define

begin_comment
comment|/* capture intr enable */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_PIE
value|0x00040000
end_define

begin_comment
comment|/* playback intr enable */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_GIE
value|0x00080000
end_define

begin_comment
comment|/* general intr enable */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_EI
value|0x00100000
end_define

begin_comment
comment|/* error interrupt */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_CI
value|0x00200000
end_define

begin_comment
comment|/* capture interrupt */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_PI
value|0x00400000
end_define

begin_comment
comment|/* playback interrupt */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_GI
value|0x00800000
end_define

begin_comment
comment|/* general interrupt */
end_comment

begin_define
define|#
directive|define
name|APC_CSR_PLAY
value|( \ 		APC_CSR_EI		| \ 	 	APC_CSR_GIE		| \ 		APC_CSR_PIE		| \ 		APC_CSR_EIE		| \ 		APC_CSR_PDMA_GO		| \ 		APC_CSR_PMIE		)
end_define

begin_define
define|#
directive|define
name|APC_CSR_CAPTURE
value|( \ 		APC_CSR_EI		| \ 	 	APC_CSR_GIE		| \ 		APC_CSR_CIE		| \ 		APC_CSR_EIE		| \ 		APC_CSR_CDMA_GO	)
end_define

begin_define
define|#
directive|define
name|APC_CSR_PLAY_PAUSE
value|(~( \ 		APC_CSR_PPAUSE		| \ 		APC_CSR_GI		| \ 		APC_CSR_PI		| \ 		APC_CSR_CI		| \ 		APC_CSR_EI		| \ 		APC_CSR_PMI		| \ 		APC_CSR_PMIE		| \ 		APC_CSR_CMI		| \ 		APC_CSR_CMIE		) )
end_define

begin_define
define|#
directive|define
name|APC_CSR_CAPTURE_PAUSE
value|(~( \ 		APC_CSR_PPAUSE		| \ 		APC_CSR_GI		| \ 		APC_CSR_PI		| \ 		APC_CSR_CI		| \ 		APC_CSR_EI		| \ 		APC_CSR_PMI		| \ 		APC_CSR_PMIE		| \ 		APC_CSR_CMI		| \ 		APC_CSR_CMIE		) )
end_define

begin_define
define|#
directive|define
name|APC_CSR_INTR_MASK
value|( \ 		APC_CSR_GI		| \ 		APC_CSR_PI		| \ 		APC_CSR_CI		| \ 		APC_CSR_EI		| \ 		APC_CSR_PMI		| \ 		APC_CSR_CMI		)
end_define

end_unit

