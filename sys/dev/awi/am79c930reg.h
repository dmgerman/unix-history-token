begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: am79c930reg.h,v 1.3 2000/03/22 11:22:22 onoe Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Bill Sommerfeld  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Device register definitions gleaned from from the AMD "Am79C930  * PCnet(tm)-Mobile Single Chip Wireless LAN Media Access Controller"  * data sheet, AMD Pub #20183, Rev B, amendment/0, issue date August 1997.  *  * As of 1999/10/23, this was available from AMD's web site in PDF  * form.  */
end_comment

begin_comment
comment|/*  * The 79c930 contains a bus interface unit, a media access  * controller, and a tranceiver attachment interface.  * The MAC contains an 80188 CPU core.  * typical devices built around this chip typically add 32k or 64k of  * memory for buffers.  *  * The 80188 runs firmware which handles most of the 802.11 gorp, and  * communicates with the host using shared data structures in this  * memory; the specifics of the shared memory layout are not covered  * in this source file; see<dev/ic/am80211fw.h> for details of that layer.  */
end_comment

begin_comment
comment|/*  * Device Registers  */
end_comment

begin_define
define|#
directive|define
name|AM79C930_IO_BASE
value|0
end_define

begin_define
define|#
directive|define
name|AM79C930_IO_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|AM79C930_IO_SIZE_BIG
value|40
end_define

begin_define
define|#
directive|define
name|AM79C930_IO_ALIGN
value|0x40
end_define

begin_comment
comment|/* am79c930 decodes lower 6bits */
end_comment

begin_define
define|#
directive|define
name|AM79C930_GCR
value|0
end_define

begin_comment
comment|/* General Config Register */
end_comment

begin_define
define|#
directive|define
name|AM79C930_GCR_SWRESET
value|0x80
end_define

begin_comment
comment|/* software reset */
end_comment

begin_define
define|#
directive|define
name|AM79C930_GCR_CORESET
value|0x40
end_define

begin_comment
comment|/* core reset */
end_comment

begin_define
define|#
directive|define
name|AM79C930_GCR_DISPWDN
value|0x20
end_define

begin_comment
comment|/* disable powerdown */
end_comment

begin_define
define|#
directive|define
name|AM79C930_GCR_ECWAIT
value|0x10
end_define

begin_comment
comment|/* embedded controller wait */
end_comment

begin_define
define|#
directive|define
name|AM79C930_GCR_ECINT
value|0x08
end_define

begin_comment
comment|/* interrupt from embedded ctrlr */
end_comment

begin_define
define|#
directive|define
name|AM79C930_GCR_INT2EC
value|0x04
end_define

begin_comment
comment|/* interrupt to embedded ctrlr */
end_comment

begin_define
define|#
directive|define
name|AM79C930_GCR_ENECINT
value|0x02
end_define

begin_comment
comment|/* enable interrupts from e.c. */
end_comment

begin_define
define|#
directive|define
name|AM79C930_GCR_DAM
value|0x01
end_define

begin_comment
comment|/* direct access mode (read only) */
end_comment

begin_define
define|#
directive|define
name|AM79C930_GCR_BITS
value|"\020\1DAM\2ENECINT\3INT2EC\4ECINT\5ECWAIT\6DISPWDN\7CORESET\010SWRESET"
end_define

begin_define
define|#
directive|define
name|AM79C930_BSS
value|1
end_define

begin_comment
comment|/* Bank Switching Select register */
end_comment

begin_define
define|#
directive|define
name|AM79C930_BSS_ECATR
value|0x80
end_define

begin_comment
comment|/* E.C. ALE test read */
end_comment

begin_define
define|#
directive|define
name|AM79C930_BSS_FS
value|0x20
end_define

begin_comment
comment|/* Flash Select */
end_comment

begin_define
define|#
directive|define
name|AM79C930_BSS_MBS
value|0x18
end_define

begin_comment
comment|/* Memory Bank Select */
end_comment

begin_define
define|#
directive|define
name|AM79C930_BSS_EIOW
value|0x04
end_define

begin_comment
comment|/* Expand I/O Window */
end_comment

begin_define
define|#
directive|define
name|AM79C930_BSS_TBS
value|0x03
end_define

begin_comment
comment|/* TAI Bank Select */
end_comment

begin_define
define|#
directive|define
name|AM79C930_LMA_LO
value|2
end_define

begin_comment
comment|/* Local Memory Address register (low byte) */
end_comment

begin_define
define|#
directive|define
name|AM79C930_LMA_HI
value|3
end_define

begin_comment
comment|/* Local Memory Address register (high byte) */
end_comment

begin_comment
comment|/* set this bit to turn off ISAPnP version */
end_comment

begin_define
define|#
directive|define
name|AM79C930_LMA_HI_ISAPWRDWN
value|0x80
end_define

begin_comment
comment|/*  * mmm, inconsistancy in chip documentation:  * According to page 79--80, all four of the following are equivalent  * and address the single byte pointed at by BSS_{FS,MBS} | LMA_{HI,LO}  * According to tables on p63 and p67, they're the LSB through MSB  * of a 32-bit word.  */
end_comment

begin_define
define|#
directive|define
name|AM79C930_IODPA
value|4
end_define

begin_comment
comment|/* I/O Data port A */
end_comment

begin_define
define|#
directive|define
name|AM79C930_IODPB
value|5
end_define

begin_comment
comment|/* I/O Data port B */
end_comment

begin_define
define|#
directive|define
name|AM79C930_IODPC
value|6
end_define

begin_comment
comment|/* I/O Data port C */
end_comment

begin_define
define|#
directive|define
name|AM79C930_IODPD
value|7
end_define

begin_comment
comment|/* I/O Data port D */
end_comment

begin_comment
comment|/*  * Tranceiver Attachment Interface Registers (TIR space)  * (omitted for now, since host access to them is for diagnostic  * purposes only).  */
end_comment

begin_comment
comment|/*  * memory space goo.  */
end_comment

begin_define
define|#
directive|define
name|AM79C930_MEM_SIZE
value|0x8000
end_define

begin_comment
comment|/* 32k */
end_comment

begin_define
define|#
directive|define
name|AM79C930_MEM_BASE
value|0x0
end_define

begin_comment
comment|/* starting at 0 */
end_comment

end_unit

