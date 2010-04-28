begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_DCR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_DCR_H_
end_define

begin_comment
comment|/*  * Definitions for the UltraSPARC-III Depatch Control Register (ASR 18).  */
end_comment

begin_define
define|#
directive|define
name|DCR_MS
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|DCR_IFPOE
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|DCR_SI
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|DCR_RPE
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|DCR_BPE
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|DCR_OBSDATA_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|DCR_OBSDATA_CT_BITS
value|8
end_define

begin_define
define|#
directive|define
name|DCR_OBSDATA_CT_MASK
define|\
value|(((1UL<< DCR_OBSDATA_CT_BITS) - 1)<< DCR_OBSDATA_SHIFT)
end_define

begin_comment
comment|/* The following bits are valid for the UltraSPARC-III++/IV+ only. */
end_comment

begin_define
define|#
directive|define
name|DCR_IPE
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|DCR_OBSDATA_CTP_BITS
value|6
end_define

begin_define
define|#
directive|define
name|DCR_OBSDATA_CTP_MASK
define|\
value|(((1UL<< DCR_OBSDATA_CTP_BITS) - 1)<< DCR_OBSDATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCR_DPE
value|(1UL<< 12)
end_define

begin_comment
comment|/* The following bits are valid for the UltraSPARC-IV+ only. */
end_comment

begin_define
define|#
directive|define
name|DCR_BPM_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|DCR_BPM_BITS
value|2
end_define

begin_define
define|#
directive|define
name|DCR_BPM_MASK
define|\
value|(((1UL<< DCR_BPM_BITS) - 1)<< DCR_BPM_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCR_BPM_1HIST_GSHARE
value|(0UL<< DCR_BPM_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCR_BPM_2HIST_GSHARE
value|(1UL<< DCR_BPM_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCR_BPM_PC
value|(2UL<< DCR_BPM_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCR_BPM_2HIST_MIXED
value|(3UL<< DCR_BPM_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCR_JPE
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|DCR_ITPE
value|(1UL<< 16)
end_define

begin_define
define|#
directive|define
name|DCR_DTPE
value|(1UL<< 17)
end_define

begin_define
define|#
directive|define
name|DCR_PPE
value|(1UL<< 18)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_DCR_H_ */
end_comment

end_unit

