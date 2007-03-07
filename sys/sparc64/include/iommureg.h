begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)sbusreg.h	8.1 (Berkeley) 6/11/93  *	from: NetBSD: iommureg.h,v 1.6 2001/07/20 00:07:13 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IOMMUREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IOMMUREG_H_
end_define

begin_comment
comment|/*  * UltraSPARC IOMMU registers, common to both the PCI and SBus  * controllers.  */
end_comment

begin_comment
comment|/* iommmu registers */
end_comment

begin_define
define|#
directive|define
name|IMR_CTL
value|0x0000
end_define

begin_comment
comment|/* IOMMU control register */
end_comment

begin_define
define|#
directive|define
name|IMR_TSB
value|0x0008
end_define

begin_comment
comment|/* IOMMU TSB base register */
end_comment

begin_define
define|#
directive|define
name|IMR_FLUSH
value|0x0010
end_define

begin_comment
comment|/* IOMMU flush register */
end_comment

begin_comment
comment|/* streaming buffer registers */
end_comment

begin_define
define|#
directive|define
name|ISR_CTL
value|0x0000
end_define

begin_comment
comment|/* streaming buffer control reg */
end_comment

begin_define
define|#
directive|define
name|ISR_PGFLUSH
value|0x0008
end_define

begin_comment
comment|/* streaming buffer page flush */
end_comment

begin_define
define|#
directive|define
name|ISR_FLUSHSYNC
value|0x0010
end_define

begin_comment
comment|/* streaming buffer flush sync */
end_comment

begin_comment
comment|/* streaming buffer diagnostics registers. */
end_comment

begin_define
define|#
directive|define
name|ISD_DATA_DIAG
value|0x0000
end_define

begin_comment
comment|/* streaming buffer data RAM diag 0..127 */
end_comment

begin_define
define|#
directive|define
name|ISD_ERROR_DIAG
value|0x0400
end_define

begin_comment
comment|/* streaming buffer error status diag 0..127 */
end_comment

begin_define
define|#
directive|define
name|ISD_PG_TAG_DIAG
value|0x0800
end_define

begin_comment
comment|/* streaming buffer page tag diag 0..15 */
end_comment

begin_define
define|#
directive|define
name|ISD_LN_TAG_DIAG
value|0x0900
end_define

begin_comment
comment|/* streaming buffer line tag diag 0..15 */
end_comment

begin_comment
comment|/* streaming buffer control register */
end_comment

begin_define
define|#
directive|define
name|STRBUF_EN
value|0x0000000000000001UL
end_define

begin_define
define|#
directive|define
name|STRBUF_D
value|0x0000000000000002UL
end_define

begin_define
define|#
directive|define
name|IOMMU_BITS
value|34
end_define

begin_define
define|#
directive|define
name|IOMMU_MAXADDR
value|((1UL<< IOMMU_BITS) - 1)
end_define

begin_comment
comment|/*  * control register bits  */
end_comment

begin_comment
comment|/* Nummber of entries in IOTSB */
end_comment

begin_define
define|#
directive|define
name|IOMMUCR_TSBSZ_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IOMMUCR_TSB1K
value|0x0000000000000000UL
end_define

begin_define
define|#
directive|define
name|IOMMUCR_TSB2K
value|0x0000000000010000UL
end_define

begin_define
define|#
directive|define
name|IOMMUCR_TSB4K
value|0x0000000000020000UL
end_define

begin_define
define|#
directive|define
name|IOMMUCR_TSB8K
value|0x0000000000030000UL
end_define

begin_define
define|#
directive|define
name|IOMMUCR_TSB16K
value|0x0000000000040000UL
end_define

begin_define
define|#
directive|define
name|IOMMUCR_TSB32K
value|0x0000000000050000UL
end_define

begin_define
define|#
directive|define
name|IOMMUCR_TSB64K
value|0x0000000000060000UL
end_define

begin_define
define|#
directive|define
name|IOMMUCR_TSB128K
value|0x0000000000070000UL
end_define

begin_comment
comment|/* Mask for above */
end_comment

begin_define
define|#
directive|define
name|IOMMUCR_TSBMASK
value|0xfffffffffff8ffffUL
end_define

begin_comment
comment|/* 8K iommu page size */
end_comment

begin_define
define|#
directive|define
name|IOMMUCR_8KPG
value|0x0000000000000000UL
end_define

begin_comment
comment|/* 64K iommu page size */
end_comment

begin_define
define|#
directive|define
name|IOMMUCR_64KPG
value|0x0000000000000004UL
end_define

begin_comment
comment|/* Diag enable */
end_comment

begin_define
define|#
directive|define
name|IOMMUCR_DE
value|0x0000000000000002UL
end_define

begin_comment
comment|/* Enable IOMMU */
end_comment

begin_define
define|#
directive|define
name|IOMMUCR_EN
value|0x0000000000000001UL
end_define

begin_comment
comment|/*  * Diagnostic register definitions.  */
end_comment

begin_define
define|#
directive|define
name|IOMMU_DTAG_VPNBITS
value|19
end_define

begin_define
define|#
directive|define
name|IOMMU_DTAG_VPNMASK
value|((1<< IOMMU_DTAG_VPNBITS) - 1)
end_define

begin_define
define|#
directive|define
name|IOMMU_DTAG_VPNSHIFT
value|13
end_define

begin_define
define|#
directive|define
name|IOMMU_DTAG_ERRBITS
value|3
end_define

begin_define
define|#
directive|define
name|IOMMU_DTAG_ERRSHIFT
value|22
end_define

begin_define
define|#
directive|define
name|IOMMU_DTAG_ERRMASK
define|\
value|(((1<< IOMMU_DTAG_ERRBITS) - 1)<< IOMMU_DTAG_ERRSHIFT)
end_define

begin_define
define|#
directive|define
name|IOMMU_DDATA_PGBITS
value|21
end_define

begin_define
define|#
directive|define
name|IOMMU_DDATA_PGMASK
value|((1<< IOMMU_DDATA_PGBITS) - 1)
end_define

begin_define
define|#
directive|define
name|IOMMU_DDATA_PGSHIFT
value|13
end_define

begin_define
define|#
directive|define
name|IOMMU_DDATA_C
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|IOMMU_DDATA_V
value|(1<< 30)
end_define

begin_comment
comment|/*  * IOMMU stuff  */
end_comment

begin_comment
comment|/* Entry valid */
end_comment

begin_define
define|#
directive|define
name|IOTTE_V
value|0x8000000000000000UL
end_define

begin_comment
comment|/* 8K or 64K page? */
end_comment

begin_define
define|#
directive|define
name|IOTTE_64K
value|0x2000000000000000UL
end_define

begin_define
define|#
directive|define
name|IOTTE_8K
value|0x0000000000000000UL
end_define

begin_comment
comment|/* Is page streamable? */
end_comment

begin_define
define|#
directive|define
name|IOTTE_STREAM
value|0x1000000000000000UL
end_define

begin_comment
comment|/* Accesses to same bus segment? */
end_comment

begin_define
define|#
directive|define
name|IOTTE_LOCAL
value|0x0800000000000000UL
end_define

begin_comment
comment|/* Let's assume this is correct */
end_comment

begin_define
define|#
directive|define
name|IOTTE_PAMASK
value|0x000001ffffffe000UL
end_define

begin_comment
comment|/* Accesses to cacheable space */
end_comment

begin_define
define|#
directive|define
name|IOTTE_C
value|0x0000000000000010UL
end_define

begin_comment
comment|/* Writeable */
end_comment

begin_define
define|#
directive|define
name|IOTTE_W
value|0x0000000000000002UL
end_define

begin_comment
comment|/* log2 of the IOMMU TTE size. */
end_comment

begin_define
define|#
directive|define
name|IOTTE_SHIFT
value|3
end_define

begin_comment
comment|/* Streaming buffer line size. */
end_comment

begin_define
define|#
directive|define
name|STRBUF_LINESZ
value|64
end_define

begin_comment
comment|/*  * Number of bytes written by a stream buffer flushsync operation to indicate  * completion.  */
end_comment

begin_define
define|#
directive|define
name|STRBUF_FLUSHSYNC_NBYTES
value|STRBUF_LINESZ
end_define

begin_comment
comment|/*  * On sun4u each bus controller has a separate IOMMU.  The IOMMU has  * a TSB which must be page aligned and physically contiguous.  Mappings  * can be of 8K IOMMU pages or 64K IOMMU pages.  We use 8K for compatibility  * with the CPU's MMU.  *  * On sysio, psycho, and psycho+, IOMMU TSBs using 8K pages can map the  * following size segments:  *  *	VA size		VA base		TSB size	tsbsize  *	--------	--------	---------	-------  *	8MB		ff800000	8K		0  *	16MB		ff000000	16K		1  *	32MB		fe000000	32K		2  *	64MB		fc000000	64K		3  *	128MB		f8000000	128K		4  *	256MB		f0000000	256K		5  *	512MB		e0000000	512K		6  *	1GB		c0000000	1MB		7  *  * Unfortunately, sabres on UltraSPARC IIi and IIe processors does not use  * this scheme to determine the IOVA base address.  Instead, bits 31-29 are  * used to check against the Target Address Space register in the IIi and  * the the IOMMU is used if they hit.  God knows what goes on in the IIe.  *  */
end_comment

begin_define
define|#
directive|define
name|IOTSB_BASESZ
value|(1024<< IOTTE_SHIFT)
end_define

begin_define
define|#
directive|define
name|IOTSB_VEND
value|(~IO_PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|IOTSB_VSTART
parameter_list|(
name|sz
parameter_list|)
value|(u_int)(IOTSB_VEND<< ((sz) + 10))
end_define

begin_define
define|#
directive|define
name|MAKEIOTTE
parameter_list|(
name|pa
parameter_list|,
name|w
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|(((pa)& IOTTE_PAMASK) | ((w) ? IOTTE_W : 0) |			\ 	((c) ? IOTTE_C : 0) | ((s) ? IOTTE_STREAM : 0) |		\ 	(IOTTE_V | IOTTE_8K))
end_define

begin_define
define|#
directive|define
name|IOTSBSLOT
parameter_list|(
name|va
parameter_list|)
define|\
value|((u_int)(((vm_offset_t)(va)) - (is->is_dvmabase))>> IO_PAGE_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IOMMUREG_H_ */
end_comment

end_unit

