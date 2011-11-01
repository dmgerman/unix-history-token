begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pcscpreg.h,v 1.2 2008/04/28 20:23:55 martin Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Izumi Tsutsui.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AM53C974_H_
end_ifndef

begin_define
define|#
directive|define
name|_AM53C974_H_
end_define

begin_comment
comment|/*  * Am53c974 DMA engine registers  */
end_comment

begin_define
define|#
directive|define
name|DMA_CMD
value|0x40
end_define

begin_comment
comment|/* Command */
end_comment

begin_define
define|#
directive|define
name|DMACMD_RSVD
value|0xFFFFFF28
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|DMACMD_DIR
value|0x00000080
end_define

begin_comment
comment|/* Transfer Direction (read:1) */
end_comment

begin_define
define|#
directive|define
name|DMACMD_INTE
value|0x00000040
end_define

begin_comment
comment|/* DMA Interrupt Enable	*/
end_comment

begin_define
define|#
directive|define
name|DMACMD_MDL
value|0x00000010
end_define

begin_comment
comment|/* Map to Memory Description List */
end_comment

begin_define
define|#
directive|define
name|DMACMD_DIAG
value|0x00000004
end_define

begin_comment
comment|/* Diagnostic */
end_comment

begin_define
define|#
directive|define
name|DMACMD_CMD
value|0x00000003
end_define

begin_comment
comment|/* Command Code Bit */
end_comment

begin_define
define|#
directive|define
name|DMACMD_IDLE
value|0x00000000
end_define

begin_comment
comment|/*  Idle */
end_comment

begin_define
define|#
directive|define
name|DMACMD_BLAST
value|0x00000001
end_define

begin_comment
comment|/*  Blast */
end_comment

begin_define
define|#
directive|define
name|DMACMD_ABORT
value|0x00000002
end_define

begin_comment
comment|/*  Abort */
end_comment

begin_define
define|#
directive|define
name|DMACMD_START
value|0x00000003
end_define

begin_comment
comment|/*  Start */
end_comment

begin_define
define|#
directive|define
name|DMA_STC
value|0x44
end_define

begin_comment
comment|/* Start Transfer Count */
end_comment

begin_define
define|#
directive|define
name|DMA_SPA
value|0x48
end_define

begin_comment
comment|/* Start Physical Address */
end_comment

begin_define
define|#
directive|define
name|DMA_WBC
value|0x4C
end_define

begin_comment
comment|/* Working Byte Counter */
end_comment

begin_define
define|#
directive|define
name|DMA_WAC
value|0x50
end_define

begin_comment
comment|/* Working Address Counter */
end_comment

begin_define
define|#
directive|define
name|DMA_STAT
value|0x54
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|DMASTAT_RSVD
value|0xFFFFFF80
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|DMASTAT_PABT
value|0x00000040
end_define

begin_comment
comment|/* PCI master/target Abort */
end_comment

begin_define
define|#
directive|define
name|DMASTAT_BCMP
value|0x00000020
end_define

begin_comment
comment|/* BLAST Complete */
end_comment

begin_define
define|#
directive|define
name|DMASTAT_SINT
value|0x00000010
end_define

begin_comment
comment|/* SCSI Interrupt */
end_comment

begin_define
define|#
directive|define
name|DMASTAT_DONE
value|0x00000008
end_define

begin_comment
comment|/* DMA Transfer Terminated */
end_comment

begin_define
define|#
directive|define
name|DMASTAT_ABT
value|0x00000004
end_define

begin_comment
comment|/* DMA Transfer Aborted */
end_comment

begin_define
define|#
directive|define
name|DMASTAT_ERR
value|0x00000002
end_define

begin_comment
comment|/* DMA Transfer Error */
end_comment

begin_define
define|#
directive|define
name|DMASTAT_PWDN
value|0x00000001
end_define

begin_comment
comment|/* Power Down Indicator */
end_comment

begin_define
define|#
directive|define
name|DMA_SMDLA
value|0x58
end_define

begin_comment
comment|/* Starting Memory Descpritor List Address */
end_comment

begin_define
define|#
directive|define
name|DMA_WMAC
value|0x5C
end_define

begin_comment
comment|/* Working MDL Counter */
end_comment

begin_define
define|#
directive|define
name|DMA_SBAC
value|0x70
end_define

begin_comment
comment|/* SCSI Bus and Control */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AM53C974_H_ */
end_comment

end_unit

