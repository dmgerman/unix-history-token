begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 by Matthew Jacob  * NASA AMES Research Center.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|DWLPX_NONE
value|0
end_define

begin_define
define|#
directive|define
name|DWLPX_SG32K
value|1
end_define

begin_define
define|#
directive|define
name|DWLPX_SG64K
value|2
end_define

begin_define
define|#
directive|define
name|DWLPX_SG128K
value|3
end_define

begin_comment
comment|/*  * Each DWLPX supports up to 15 devices, 12 of which are PCI slots.  *  * Since the STD I/O modules in slots 12-14 are really a PCI-EISA  * bridge, we'll punt on those for the moment.  */
end_comment

begin_define
define|#
directive|define
name|DWLPX_MAXDEV
value|12
end_define

begin_comment
comment|/*  * There are 5 possible slots that can have I/O boards, and for each  * one there are 4 possible hoses. To cover them all, we'd have to  * reserve 5 bits of selector out our current 32 bit cookie we use  * for primary PCI address spaces. It turns out that we *just* have  * enough bits for this (see drawing in dwlpxreg.h)  */
end_comment

begin_define
define|#
directive|define
name|DWLPX_NIONODE
value|5
end_define

begin_define
define|#
directive|define
name|DWLPX_NHOSE
value|4
end_define

begin_comment
comment|/*  * Interrupt Cookie for DWLPX vectors.  *  * Bits 0..3	PCI Slot (0..11)  * Bits 4..7	I/O Hose (0..3)  * Bits 8..11	I/O Node (0..4)  * Bit	15	Constant 1  */
end_comment

begin_define
define|#
directive|define
name|DWLPX_VEC_MARK
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|DWLPX_MVEC
parameter_list|(
name|ionode
parameter_list|,
name|hose
parameter_list|,
name|pcislot
parameter_list|)
define|\
value|(DWLPX_VEC_MARK | (ionode<< 8) | (hose<< 4) | (pcislot))
end_define

begin_define
define|#
directive|define
name|DWLPX_MVEC_IONODE
parameter_list|(
name|cookie
parameter_list|)
define|\
value|((((u_int64_t)(cookie))>> 8)& 0xf)
end_define

begin_define
define|#
directive|define
name|DWLPX_MVEC_HOSE
parameter_list|(
name|cookie
parameter_list|)
define|\
value|((((u_int64_t)(cookie))>> 4)& 0xf)
end_define

begin_define
define|#
directive|define
name|DWLPX_MVEC_PCISLOT
parameter_list|(
name|cookie
parameter_list|)
define|\
value|(((u_int64_t)(cookie))& 0xf)
end_define

begin_comment
comment|/*  * DWLPX Error Interrupt  */
end_comment

begin_define
define|#
directive|define
name|DWLPX_VEC_EMARK
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|DWLPX_ERRVEC
parameter_list|(
name|ionode
parameter_list|,
name|hose
parameter_list|)
define|\
value|(DWLPX_VEC_EMARK | (ionode<< 8) | (hose<< 4))
end_define

begin_comment
comment|/*  * Default values to put into DWLPX IMASK register(s)  */
end_comment

begin_define
define|#
directive|define
name|DWLPX_IMASK_DFLT
define|\
value|(1<< 24) |
comment|/* IPL 17 for error interrupts */
value|\ 	(1<< 17) |
comment|/* IPL 14 for device interrupts */
value|\ 	(1<< 16)
end_define

begin_comment
comment|/* Enable Error Interrupts */
end_comment

begin_define
define|#
directive|define
name|DWLPX_BASE
parameter_list|(
name|node
parameter_list|,
name|hose
parameter_list|)
define|\
value|((((unsigned long)(node - 4))<< 36) |	\ 	     (((unsigned long)(hose))<< 34) |	\ 	     (1LL<< 39))
end_define

end_unit

