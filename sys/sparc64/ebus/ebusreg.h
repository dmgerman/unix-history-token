begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: ebusreg.h,v 1.4 2001/10/01 18:08:04 jason Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: ebusreg.h,v 1.1 1999/06/04 13:29:13 mrg Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * UltraSPARC `ebus'  *  * The `ebus' bus is designed to plug traditional PC-ISA devices into  * an SPARC system with as few costs as possible, without sacrificing  * to performance.  Typically, it is implemented in the PCIO IC from  * SME, which also implements a `hme-compatible' PCI network device  * (`network').  The ebus has 4 DMA channels, similar to the DMA seen  * in the ESP SCSI DMA.  *  * Typical UltraSPARC systems have a NatSemi SuperIO IC to provide  * serial ports for the keyboard and mouse (`se'), floppy disk  * controller (`fdthree'), parallel port controller (`bpp') connected  * to the ebus, and a PCI-IDE controller (connected directly to the  * PCI bus, of course), as well as a Siemens Nixdorf SAB82532 dual  * channel serial controller (`su' providing ttya and ttyb), an MK48T59  * EEPROM/clock controller (also where the idprom, including the  * ethernet address, is located), the audio system (`SUNW,CS4231', same  * as other UltraSPARC and some SPARC systems), and other various  * internal devices found on traditional SPARC systems such as the  * `power', `flashprom', etc., devices.  *  * The ebus uses an interrupt mapping scheme similar to PCI, though  * the actual structures are different.  */
end_comment

begin_comment
comment|/* EBUS dma registers */
end_comment

begin_define
define|#
directive|define
name|EBDMA_DCSR
value|0x0
end_define

begin_comment
comment|/* control/status */
end_comment

begin_define
define|#
directive|define
name|EBDMA_DADDR
value|0x4
end_define

begin_comment
comment|/* DMA address */
end_comment

begin_define
define|#
directive|define
name|EBDMA_DCNT
value|0x8
end_define

begin_comment
comment|/* DMA count */
end_comment

begin_comment
comment|/* EBUS DMA control/status (EBDMA_DCSR) */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_INT
value|0x00000001
end_define

begin_comment
comment|/* interrupt pending */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_ERR
value|0x00000002
end_define

begin_comment
comment|/* error pending */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_DRAIN
value|0x00000004
end_define

begin_comment
comment|/* drain */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_INTEN
value|0x00000010
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_RESET
value|0x00000080
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_WRITE
value|0x00000100
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_DMAEN
value|0x00000200
end_define

begin_comment
comment|/* dma enable */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_CYC
value|0x00000400
end_define

begin_comment
comment|/* cyc pending */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_DIAGRD
value|0x00000800
end_define

begin_comment
comment|/* diagnostic read done */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_DIAGWR
value|0x00001000
end_define

begin_comment
comment|/* diagnostic write done */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_CNTEN
value|0x00002000
end_define

begin_comment
comment|/* count enable */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_TC
value|0x00004000
end_define

begin_comment
comment|/* terminal count */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_CSRDRNDIS
value|0x00010000
end_define

begin_comment
comment|/* disable csr drain */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_BURSTMASK
value|0x000c0000
end_define

begin_comment
comment|/* burst size mask */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_BURST_1
value|0x00080000
end_define

begin_comment
comment|/* burst 1 */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_BURST_4
value|0x00000000
end_define

begin_comment
comment|/* burst 4 */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_BURST_8
value|0x00040000
end_define

begin_comment
comment|/* burst 8 */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_BURST_16
value|0x000c0000
end_define

begin_comment
comment|/* burst 16 */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_DIAGEN
value|0x00100000
end_define

begin_comment
comment|/* enable diagnostics */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_ERRDIS
value|0x00400000
end_define

begin_comment
comment|/* disable error pending */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_TCIDIS
value|0x00800000
end_define

begin_comment
comment|/* disable TCI */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_NEXTEN
value|0x01000000
end_define

begin_comment
comment|/* enable next */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_DMAON
value|0x02000000
end_define

begin_comment
comment|/* dma on */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_A_LOADED
value|0x04000000
end_define

begin_comment
comment|/* address loaded */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_NA_LOADED
value|0x08000000
end_define

begin_comment
comment|/* next address loaded */
end_comment

begin_define
define|#
directive|define
name|EBDCSR_DEVMASK
value|0xf0000000
end_define

begin_comment
comment|/* device id mask */
end_comment

end_unit

