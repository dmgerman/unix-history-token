begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) KATO Takenori, 1996.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * PC-9801 specific definitions for DP8390/SMC8216 NICs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PC98
end_ifndef

begin_error
error|#
directive|error
error|Why you include if_ed98.h?
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Vendor types  */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_MISC
value|0xf0
end_define

begin_comment
comment|/* others */
end_comment

begin_comment
comment|/*  * Card types.  *  * Type  Card  * 0x00  Allied Telesis CenterCom LA-98-T / SMC EtherEZ98.  * 0x10  ** RESERVED **  * 0x20  PLANET SMART COM 98 EN-2298 / ELECOM LANEED LD-BDN[123]A.  * 0x30  MELCO EGY-98 / Contec C-NET(98)E-A/L-A.  * 0x40  MELCO LGY-98, IND-SP, IND-SS / MACNICA NE2098(XXX).  * 0x50  ICM DT-ET-25, DT-ET-T5, IF-2766ET, IF-2771ET /  *       D-Link DE-298P{T,CAT}, DE-298{T,TP,CAT}.  * 0x60  Allied Telesis SIC-98.  * 0x70  ** RESERVED **  * 0x80  NEC PC-9801-108.  * 0x90  IO-DATA LA-98 / NEC PC-9801-77.  * 0xa0  Contec C-NET(98).  * 0xb0  Contec C-NET(98)E/L.  * 0xc0  ** RESERVED **  * 0xd0  Networld EC/EP-98X.  * 0xe0  Soliton SB-9801 / Fujikura FN-9801 / Networld EC/EP-98S.  * 0xf0  NextCom NC5098.  */
end_comment

begin_define
define|#
directive|define
name|ED_TYPE98_BASE
value|0x80
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_GENERIC
value|0x80
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_BDN
value|0x82
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_EGY
value|0x83
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_LGY
value|0x84
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_ICM
value|0x85
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_SIC
value|0x86
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_108
value|0x88
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_LA98
value|0x89
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_CNET98
value|0x8a
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_CNET98EL
value|0x8b
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_NW98X
value|0x8d
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_SB98
value|0x8e
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_NC5098
value|0x8f
end_define

begin_define
define|#
directive|define
name|ED_TYPE98
parameter_list|(
name|x
parameter_list|)
value|(((x& 0xffff0000)>> 20) | ED_TYPE98_BASE)
end_define

begin_define
define|#
directive|define
name|ED_TYPE98SUB
parameter_list|(
name|x
parameter_list|)
value|((x& 0xf0000)>> 16)
end_define

begin_comment
comment|/*  * 		Definitions for C-NET(98) serise  */
end_comment

begin_comment
comment|/*  * Initial Register(on board JP1)  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_INIT
value|0xaaed
end_define

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_INIT2
value|0x55ed
end_define

begin_comment
comment|/* another setting */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98EL_PAGE_OFFSET
value|0x0000
end_define

begin_comment
comment|/* Page offset for NIC access to mem */
end_comment

begin_comment
comment|/*  *		Definitions for Soliton SB-9801  */
end_comment

begin_comment
comment|/*  * I/O port select register  */
end_comment

begin_define
define|#
directive|define
name|ED_SB98_IO_INHIBIT
value|0x0040
end_define

begin_comment
comment|/* XXX - shares printer port! */
end_comment

begin_comment
comment|/*  *		Definitions for SMC EtherEZ98(SMC8498BTA)  */
end_comment

begin_define
define|#
directive|define
name|ED_EZ98_NIC_OFFSET
value|0x100
end_define

begin_comment
comment|/* I/O base offset to NIC */
end_comment

begin_define
define|#
directive|define
name|ED_EZ98_ASIC_OFFSET
value|0
end_define

begin_comment
comment|/* I/O base offset to ASIC */
end_comment

begin_comment
comment|/*  * XXX - The I/O address range is fragmented in the EtherEZ98;  *      it occupies 16*2 I/O addresses, by the way.  */
end_comment

begin_define
define|#
directive|define
name|ED_EZ98_IO_PORTS
value|16
end_define

begin_comment
comment|/* # of i/o addresses used */
end_comment

end_unit

