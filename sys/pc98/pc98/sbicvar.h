begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: sbicvar.h,v 1.5 1995/02/12 19:19:21 chopps Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Van Jacobson of Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)scsivar.h	7.1 (Berkeley) 5/8/90  */
end_comment

begin_comment
comment|/*  * Ported to PC-9801 by Yoshio Kimura, 1994  *	last update 09/23/1994  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SBICVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SBICVAR_H_
end_define

begin_comment
comment|/*  * The largest single request will be MAXPHYS bytes which will require  * at most MAXPHYS/PAGE_SIZE+1 chain elements to describe, i.e. if none of  * the buffer pages are physically contiguous (MAXPHYS/PAGE_SIZE) and the  * buffer is not page aligned (+1).  */
end_comment

begin_define
define|#
directive|define
name|SBIC_NSEG
value|17
end_define

begin_struct
struct|struct
name|dma_chain
block|{
name|int
name|dc_count
decl_stmt|;
name|int
name|dc_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sbic_pending
block|{
name|TAILQ_ENTRY
argument_list|(
argument|sbic_pending
argument_list|)
name|link
expr_stmt|;
name|struct
name|scsi_xfer
modifier|*
name|xs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sbic_softc
block|{
ifndef|#
directive|ifndef
name|__FreeBSD__
name|struct
name|device
name|sc_dev
decl_stmt|;
name|struct
name|pc98dev
name|sc_id
decl_stmt|;
name|struct
name|intrhand
name|sc_ih
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FreeBSD__
name|int
name|unit
decl_stmt|;
comment|/* unit number */
endif|#
directive|endif
name|u_short
name|sc_base
decl_stmt|;
name|u_short
name|sc_int
decl_stmt|;
name|u_short
name|sc_dma
decl_stmt|;
name|int
name|sc_scsi_dev
decl_stmt|;
name|u_long
name|sc_clkfreq
decl_stmt|;
struct|struct
name|target_sync
block|{
name|u_char
name|state
decl_stmt|;
name|u_char
name|period
decl_stmt|;
name|u_char
name|offset
decl_stmt|;
block|}
name|sc_sync
index|[
literal|8
index|]
struct|;
name|struct
name|scsi_link
name|sc_link
decl_stmt|;
comment|/* proto for sub devices */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|sbic_pending
argument_list|)
name|sc_xslist
expr_stmt|;
comment|/* LIFO */
name|struct
name|sbic_pending
name|sc_xsstore
index|[
literal|8
index|]
index|[
literal|8
index|]
decl_stmt|;
comment|/* one for every unit */
name|struct
name|scsi_xfer
modifier|*
name|sc_xs
decl_stmt|;
comment|/* transfer from high level code */
name|u_char
name|sc_flags
decl_stmt|;
name|u_char
name|sc_stat
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|sc_msg
index|[
literal|7
index|]
decl_stmt|;
name|struct
name|dma_chain
name|sc_chain
index|[
name|SBIC_NSEG
index|]
decl_stmt|;
name|struct
name|dma_chain
modifier|*
name|sc_cur
decl_stmt|;
name|struct
name|dma_chain
modifier|*
name|sc_last
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sc_flags */
end_comment

begin_define
define|#
directive|define
name|SBICF_ALIVE
value|0x01
end_define

begin_comment
comment|/* controller initialized */
end_comment

begin_define
define|#
directive|define
name|SBICF_DCFLUSH
value|0x02
end_define

begin_comment
comment|/* need flush for overlap after dma finishes */
end_comment

begin_define
define|#
directive|define
name|SBICF_SELECTED
value|0x04
end_define

begin_comment
comment|/* bus is in selected state. */
end_comment

begin_define
define|#
directive|define
name|SBICF_BADDMA
value|0x10
end_define

begin_comment
comment|/* controller can only DMA to ztwobus space */
end_comment

begin_define
define|#
directive|define
name|SBICF_BBUF
value|0x20
end_define

begin_comment
comment|/* DMA input needs to be copied from bounce */
end_comment

begin_define
define|#
directive|define
name|SBICF_INTR
value|0x40
end_define

begin_comment
comment|/* SBICF interrupt expected */
end_comment

begin_define
define|#
directive|define
name|SBICF_INDMA
value|0x80
end_define

begin_comment
comment|/* not used yet, DMA I/O in progress */
end_comment

begin_comment
comment|/* sync states */
end_comment

begin_define
define|#
directive|define
name|SYNC_START
value|0
end_define

begin_comment
comment|/* no sync handshake started */
end_comment

begin_define
define|#
directive|define
name|SYNC_SENT
value|1
end_define

begin_comment
comment|/* we sent sync request, no answer yet */
end_comment

begin_define
define|#
directive|define
name|SYNC_DONE
value|2
end_define

begin_comment
comment|/* target accepted our (or inferior) settings, 				   or it rejected the request and we stay async */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DDB_FOLLOW
value|0x04
end_define

begin_define
define|#
directive|define
name|DDB_IO
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PHASE
value|0x07
end_define

begin_comment
comment|/* mask for psns/pctl phase */
end_comment

begin_define
define|#
directive|define
name|DATA_OUT_PHASE
value|0x00
end_define

begin_define
define|#
directive|define
name|DATA_IN_PHASE
value|0x01
end_define

begin_define
define|#
directive|define
name|CMD_PHASE
value|0x02
end_define

begin_define
define|#
directive|define
name|STATUS_PHASE
value|0x03
end_define

begin_define
define|#
directive|define
name|BUS_FREE_PHASE
value|0x04
end_define

begin_define
define|#
directive|define
name|ARB_SEL_PHASE
value|0x05
end_define

begin_comment
comment|/* Fuji chip combines arbitration with sel. */
end_comment

begin_define
define|#
directive|define
name|MESG_OUT_PHASE
value|0x06
end_define

begin_define
define|#
directive|define
name|MESG_IN_PHASE
value|0x07
end_define

begin_define
define|#
directive|define
name|MSG_CMD_COMPLETE
value|0x00
end_define

begin_define
define|#
directive|define
name|MSG_EXT_MESSAGE
value|0x01
end_define

begin_define
define|#
directive|define
name|MSG_SAVE_DATA_PTR
value|0x02
end_define

begin_define
define|#
directive|define
name|MSG_RESTORE_PTR
value|0x03
end_define

begin_define
define|#
directive|define
name|MSG_DISCONNECT
value|0x04
end_define

begin_define
define|#
directive|define
name|MSG_INIT_DETECT_ERROR
value|0x05
end_define

begin_define
define|#
directive|define
name|MSG_ABORT
value|0x06
end_define

begin_define
define|#
directive|define
name|MSG_REJECT
value|0x07
end_define

begin_define
define|#
directive|define
name|MSG_NOOP
value|0x08
end_define

begin_define
define|#
directive|define
name|MSG_PARITY_ERROR
value|0x09
end_define

begin_define
define|#
directive|define
name|MSG_BUS_DEVICE_RESET
value|0x0C
end_define

begin_define
define|#
directive|define
name|MSG_IDENTIFY
value|0x80
end_define

begin_define
define|#
directive|define
name|MSG_IDENTIFY_DR
value|0xc0
end_define

begin_comment
comment|/* (disconnect/reconnect allowed) */
end_comment

begin_define
define|#
directive|define
name|MSG_SYNC_REQ
value|0x01
end_define

begin_define
define|#
directive|define
name|STS_CHECKCOND
value|0x02
end_define

begin_comment
comment|/* Check Condition (ie., read sense) */
end_comment

begin_define
define|#
directive|define
name|STS_CONDMET
value|0x04
end_define

begin_comment
comment|/* Condition Met (ie., search worked) */
end_comment

begin_define
define|#
directive|define
name|STS_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|STS_INTERMED
value|0x10
end_define

begin_comment
comment|/* Intermediate status sent */
end_comment

begin_define
define|#
directive|define
name|STS_EXT
value|0x80
end_define

begin_comment
comment|/* Extended status valid */
end_comment

begin_comment
comment|/*  * XXXX   */
end_comment

begin_struct
struct|struct
name|scsi_fmt_cdb
block|{
name|int
name|len
decl_stmt|;
comment|/* cdb length (in bytes) */
name|u_char
name|cdb
index|[
literal|28
index|]
decl_stmt|;
comment|/* cdb to use on next read/write */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SBICVAR_H_ */
end_comment

end_unit

