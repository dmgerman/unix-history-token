begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1996 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From: wd82371reg.h,v 1.3 1997/02/22 09:44:15 peter Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_IDEPCIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_IDEPCIREG_H_
value|1
end_define

begin_comment
comment|/* Ports are for controller 0.  Add SFF8038_CTLR_1 for controller 1. */
end_comment

begin_define
define|#
directive|define
name|SFF8038_CTLR_1
value|8
end_define

begin_comment
comment|/* Contents of BMICOM register */
end_comment

begin_define
define|#
directive|define
name|BMICOM_PORT
value|0
end_define

begin_define
define|#
directive|define
name|BMICOM_READ_WRITE
value|0x0008
end_define

begin_comment
comment|/* false = read, true = write */
end_comment

begin_define
define|#
directive|define
name|BMICOM_STOP_START
value|0x0001
end_define

begin_comment
comment|/* false = stop, true = start */
end_comment

begin_comment
comment|/* Contents of BMISTA register */
end_comment

begin_define
define|#
directive|define
name|BMISTA_PORT
value|2
end_define

begin_define
define|#
directive|define
name|BMISTA_SIMPLEX
value|0x0080
end_define

begin_comment
comment|/* 1 = controller cannot DMA on both 					  channels simultaneously */
end_comment

begin_define
define|#
directive|define
name|BMISTA_DMA1CAP
value|0x0040
end_define

begin_comment
comment|/* true = drive 1 can DMA */
end_comment

begin_define
define|#
directive|define
name|BMISTA_DMA0CAP
value|0x0020
end_define

begin_comment
comment|/* true = drive 0 can DMA */
end_comment

begin_define
define|#
directive|define
name|BMISTA_INTERRUPT
value|0x0004
end_define

begin_define
define|#
directive|define
name|BMISTA_DMA_ERROR
value|0x0002
end_define

begin_define
define|#
directive|define
name|BMISTA_DMA_ACTIVE
value|0x0001
end_define

begin_define
define|#
directive|define
name|BMIDTP_PORT
value|4
end_define

begin_comment
comment|/* use outl */
end_comment

begin_struct
struct|struct
name|ide_pci_prd
block|{
name|u_int32_t
name|prd_base
decl_stmt|;
name|u_int32_t
name|prd_count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PRD_EOT_BIT
value|0x80000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCI_IDEPCIREG_H_ */
end_comment

end_unit

