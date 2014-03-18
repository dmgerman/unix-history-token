begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ncr53c9xvar.h,v 1.55 2011/07/31 18:39:00 jakllsch Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994 Peter Galbavy.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Peter Galbavy.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NCR53C9XVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NCR53C9XVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_comment
comment|/* Set this to 1 for normal debug, or 2 for per-target tracing. */
end_comment

begin_comment
comment|/* #define	NCR53C9X_DEBUG		2 */
end_comment

begin_comment
comment|/* Wide or differential can have 16 targets */
end_comment

begin_define
define|#
directive|define
name|NCR_NLUN
value|8
end_define

begin_define
define|#
directive|define
name|NCR_ABORT_TIMEOUT
value|2000
end_define

begin_comment
comment|/* time to wait for abort */
end_comment

begin_define
define|#
directive|define
name|NCR_SENSE_TIMEOUT
value|1000
end_define

begin_comment
comment|/* time to wait for sense */
end_comment

begin_define
define|#
directive|define
name|FREQTOCCF
parameter_list|(
name|freq
parameter_list|)
value|(((freq + 4) / 5))
end_define

begin_comment
comment|/*  * NCR 53c9x variants.  Note these values are used as indexes into  * a table; do not modify them unless you know what you are doing.  */
end_comment

begin_define
define|#
directive|define
name|NCR_VARIANT_ESP100
value|0
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_ESP100A
value|1
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_ESP200
value|2
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_NCR53C94
value|3
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_NCR53C96
value|4
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_ESP406
value|5
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_FAS408
value|6
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_FAS216
value|7
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_AM53C974
value|8
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_FAS366
value|9
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_NCR53C90_86C01
value|10
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_FAS100A
value|11
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_FAS236
value|12
end_define

begin_define
define|#
directive|define
name|NCR_VARIANT_MAX
value|13
end_define

begin_comment
comment|/* XXX Max tag depth.  Should this be defined in the register header? */
end_comment

begin_define
define|#
directive|define
name|NCR_TAG_DEPTH
value|256
end_define

begin_comment
comment|/*  * ECB. Holds additional information for each SCSI command Comments: We  * need a separate scsi command block because we may need to overwrite it  * with a request sense command.  Basicly, we refrain from fiddling with  * the ccb union (except do the expected updating of return values).  * We'll generally update: ccb->ccb_h.status and ccb->csio.{resid,  * scsi_status,sense_data}.  */
end_comment

begin_struct
struct|struct
name|ncr53c9x_ecb
block|{
comment|/* These fields are preserved between alloc and free. */
name|struct
name|callout
name|ch
decl_stmt|;
name|struct
name|ncr53c9x_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|tag_id
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
comment|/* SCSI xfer ctrl block from above */
name|TAILQ_ENTRY
argument_list|(
argument|ncr53c9x_ecb
argument_list|)
name|free_links
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ncr53c9x_ecb
argument_list|)
name|chain
expr_stmt|;
define|#
directive|define
name|ECB_ALLOC
value|0x01
define|#
directive|define
name|ECB_READY
value|0x02
define|#
directive|define
name|ECB_SENSE
value|0x04
define|#
directive|define
name|ECB_ABORT
value|0x40
define|#
directive|define
name|ECB_RESET
value|0x80
define|#
directive|define
name|ECB_TENTATIVE_DONE
value|0x100
name|int
name|timeout
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|msg
index|[
literal|3
index|]
decl_stmt|;
comment|/* Selection Id msg and tags */
name|struct
name|scsi_generic
name|cmd
decl_stmt|;
comment|/* SCSI command block */
block|}
name|cmd
struct|;
name|uint8_t
modifier|*
name|daddr
decl_stmt|;
comment|/* Saved data pointer */
name|int
name|clen
decl_stmt|;
comment|/* Size of command in cmd.cmd */
name|int
name|dleft
decl_stmt|;
comment|/* Residue */
name|uint8_t
name|stat
decl_stmt|;
comment|/* SCSI status byte */
name|uint8_t
name|tag
index|[
literal|2
index|]
decl_stmt|;
comment|/* TAG bytes */
name|uint8_t
name|pad
index|[
literal|1
index|]
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|NCR53C9X_DEBUG
argument_list|)
operator|&&
name|NCR53C9X_DEBUG
operator|>
literal|1
name|char
name|trace
index|[
literal|1000
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCR53C9X_DEBUG
argument_list|)
operator|&&
name|NCR53C9X_DEBUG
operator|>
literal|1
end_if

begin_define
define|#
directive|define
name|ECB_TRACE
parameter_list|(
name|ecb
parameter_list|,
name|msg
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|do {					\ 	const char *f = "[" msg "]";					\ 	int n = strlen((ecb)->trace);					\ 	if (n< (sizeof((ecb)->trace)-100))				\ 		sprintf((ecb)->trace + n, f, a, b);			\ } while (
comment|/* CONSTCOND */
value|0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ECB_TRACE
parameter_list|(
name|ecb
parameter_list|,
name|msg
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Some info about each (possible) target and LUN on the SCSI bus.  *  * SCSI I and II devices can have up to 8 LUNs, each with up to 256  * outstanding tags.  SCSI III devices have 64-bit LUN identifiers  * that can be sparsely allocated.  *  * Since SCSI II devices can have up to 8 LUNs, we use an array  * of 8 pointers to ncr53c9x_linfo structures for fast lookup.  * Longer LUNs need to traverse the linked list.  */
end_comment

begin_struct
struct|struct
name|ncr53c9x_linfo
block|{
name|int64_t
name|lun
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|ncr53c9x_linfo
argument_list|)
name|link
expr_stmt|;
name|time_t
name|last_used
decl_stmt|;
name|uint8_t
name|used
decl_stmt|;
comment|/* # slots in use */
name|uint8_t
name|avail
decl_stmt|;
comment|/* where to start scanning */
name|uint8_t
name|busy
decl_stmt|;
name|struct
name|ncr53c9x_ecb
modifier|*
name|untagged
decl_stmt|;
name|struct
name|ncr53c9x_ecb
modifier|*
name|queued
index|[
name|NCR_TAG_DEPTH
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ncr53c9x_xinfo
block|{
name|uint8_t
name|period
decl_stmt|;
name|uint8_t
name|offset
decl_stmt|;
name|uint8_t
name|width
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ncr53c9x_tinfo
block|{
name|int
name|cmds
decl_stmt|;
comment|/* # of commands processed */
name|int
name|dconns
decl_stmt|;
comment|/* # of disconnects */
name|int
name|touts
decl_stmt|;
comment|/* # of timeouts */
name|int
name|perrs
decl_stmt|;
comment|/* # of parity errors */
name|int
name|senses
decl_stmt|;
comment|/* # of request sense commands sent */
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|T_SYNCHOFF
value|0x01
comment|/* SYNC mode is permanently off */
define|#
directive|define
name|T_RSELECTOFF
value|0x02
comment|/* RE-SELECT mode is off */
define|#
directive|define
name|T_TAG
value|0x04
comment|/* Turn on TAG QUEUEs */
define|#
directive|define
name|T_SDTRSENT
value|0x08
comment|/* SDTR message has been sent to */
define|#
directive|define
name|T_WDTRSENT
value|0x10
comment|/* WDTR message has been sent to */
name|struct
name|ncr53c9x_xinfo
name|curr
decl_stmt|;
name|struct
name|ncr53c9x_xinfo
name|goal
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument|lun_list
argument_list|,
argument|ncr53c9x_linfo
argument_list|)
name|luns
expr_stmt|;
name|struct
name|ncr53c9x_linfo
modifier|*
name|lun
index|[
name|NCR_NLUN
index|]
decl_stmt|;
comment|/* For speedy lookups */
block|}
struct|;
end_struct

begin_comment
comment|/* Look up a lun in a tinfo */
end_comment

begin_define
define|#
directive|define
name|TINFO_LUN
parameter_list|(
name|t
parameter_list|,
name|l
parameter_list|)
value|(						\ 	(((l)< NCR_NLUN)&& (((t)->lun[(l)]) != NULL))			\ 		? ((t)->lun[(l)])					\ 		: ncr53c9x_lunsearch((t), (int64_t)(l))			\ )
end_define

begin_comment
comment|/* Register a linenumber (for debugging). */
end_comment

begin_define
define|#
directive|define
name|LOGLINE
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NCR_SHOWECBS
value|0x01
end_define

begin_define
define|#
directive|define
name|NCR_SHOWINTS
value|0x02
end_define

begin_define
define|#
directive|define
name|NCR_SHOWCMDS
value|0x04
end_define

begin_define
define|#
directive|define
name|NCR_SHOWMISC
value|0x08
end_define

begin_define
define|#
directive|define
name|NCR_SHOWTRAC
value|0x10
end_define

begin_define
define|#
directive|define
name|NCR_SHOWSTART
value|0x20
end_define

begin_define
define|#
directive|define
name|NCR_SHOWPHASE
value|0x40
end_define

begin_define
define|#
directive|define
name|NCR_SHOWDMA
value|0x80
end_define

begin_define
define|#
directive|define
name|NCR_SHOWCCMDS
value|0x100
end_define

begin_define
define|#
directive|define
name|NCR_SHOWMSGS
value|0x200
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NCR53C9X_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ncr53c9x_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NCR_ECBS
parameter_list|(
name|str
parameter_list|)
define|\
value|do {								\ 		if ((ncr53c9x_debug& NCR_SHOWECBS) != 0)		\ 			printf str;					\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|NCR_MISC
parameter_list|(
name|str
parameter_list|)
define|\
value|do {								\ 		if ((ncr53c9x_debug& NCR_SHOWMISC) != 0)		\ 			printf str;					\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|NCR_INTS
parameter_list|(
name|str
parameter_list|)
define|\
value|do {								\ 		if ((ncr53c9x_debug& NCR_SHOWINTS) != 0)		\ 			printf str;					\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|NCR_TRACE
parameter_list|(
name|str
parameter_list|)
define|\
value|do {								\ 		if ((ncr53c9x_debug& NCR_SHOWTRAC) != 0)		\ 			printf str;					\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|NCR_CMDS
parameter_list|(
name|str
parameter_list|)
define|\
value|do {								\ 		if ((ncr53c9x_debug& NCR_SHOWCMDS) != 0)		\ 			printf str;					\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|NCR_START
parameter_list|(
name|str
parameter_list|)
define|\
value|do {								\ 		if ((ncr53c9x_debug& NCR_SHOWSTART) != 0)		\ 			printf str;					\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|NCR_PHASE
parameter_list|(
name|str
parameter_list|)
define|\
value|do {								\ 		if ((ncr53c9x_debug& NCR_SHOWPHASE) != 0)		\ 			printf str;					\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|NCR_DMA
parameter_list|(
name|str
parameter_list|)
define|\
value|do {								\ 		if ((ncr53c9x_debug& NCR_SHOWDMA) != 0)		\ 			printf str;					\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|NCR_MSGS
parameter_list|(
name|str
parameter_list|)
define|\
value|do {								\ 		if ((ncr53c9x_debug& NCR_SHOWMSGS) != 0)		\ 			printf str;					\ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCR_ECBS
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NCR_MISC
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NCR_INTS
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NCR_TRACE
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NCR_CMDS
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NCR_START
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NCR_PHASE
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NCR_DMA
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NCR_MSGS
parameter_list|(
name|str
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NCR_MAX_MSG_LEN
value|8
end_define

begin_struct_decl
struct_decl|struct
name|ncr53c9x_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Function switch used as glue to MD code  */
end_comment

begin_struct
struct|struct
name|ncr53c9x_glue
block|{
comment|/* Mandatory entry points. */
name|uint8_t
function_decl|(
modifier|*
name|gl_read_reg
function_decl|)
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|gl_write_reg
function_decl|)
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|gl_dma_isintr
function_decl|)
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|gl_dma_reset
function_decl|)
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|gl_dma_intr
function_decl|)
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|gl_dma_setup
function_decl|)
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|gl_dma_go
function_decl|)
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|gl_dma_stop
function_decl|)
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|gl_dma_isactive
function_decl|)
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ncr53c9x_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* us as a device */
name|struct
name|cam_sim
modifier|*
name|sc_sim
decl_stmt|;
comment|/* our scsi adapter */
name|struct
name|cam_path
modifier|*
name|sc_path
decl_stmt|;
comment|/* our scsi channel */
name|struct
name|callout
name|sc_watchdog
decl_stmt|;
comment|/* periodic timer */
specifier|const
name|struct
name|ncr53c9x_glue
modifier|*
name|sc_glue
decl_stmt|;
comment|/* glue to MD code */
name|int
name|sc_cfflags
decl_stmt|;
comment|/* Copy of config flags */
comment|/* register defaults */
name|uint8_t
name|sc_cfg1
decl_stmt|;
comment|/* Config 1 */
name|uint8_t
name|sc_cfg2
decl_stmt|;
comment|/* Config 2, not ESP100 */
name|uint8_t
name|sc_cfg3
decl_stmt|;
comment|/* Config 3, ESP200,FAS */
name|uint8_t
name|sc_cfg3_fscsi
decl_stmt|;
comment|/* Chip-specific FSCSI bit */
name|uint8_t
name|sc_cfg4
decl_stmt|;
comment|/* Config 4, only ESP200 */
name|uint8_t
name|sc_cfg5
decl_stmt|;
comment|/* Config 5, only ESP200 */
name|uint8_t
name|sc_ccf
decl_stmt|;
comment|/* Clock Conversion */
name|uint8_t
name|sc_timeout
decl_stmt|;
comment|/* register copies, see ncr53c9x_readregs() */
name|uint8_t
name|sc_espintr
decl_stmt|;
name|uint8_t
name|sc_espstat
decl_stmt|;
name|uint8_t
name|sc_espstep
decl_stmt|;
name|uint8_t
name|sc_espstat2
decl_stmt|;
name|uint8_t
name|sc_espfflags
decl_stmt|;
comment|/* Lists of command blocks */
name|TAILQ_HEAD
argument_list|(
argument|ecb_list
argument_list|,
argument|ncr53c9x_ecb
argument_list|)
name|ready_list
expr_stmt|;
name|struct
name|ncr53c9x_ecb
modifier|*
name|sc_nexus
decl_stmt|;
comment|/* Current command */
name|int
name|sc_ntarg
decl_stmt|;
name|struct
name|ncr53c9x_tinfo
modifier|*
name|sc_tinfo
decl_stmt|;
comment|/* Data about the current nexus (updated for every cmd switch) */
name|void
modifier|*
name|sc_dp
decl_stmt|;
comment|/* Current data pointer */
name|ssize_t
name|sc_dleft
decl_stmt|;
comment|/* Data left to transfer */
comment|/* Adapter state */
name|int
name|sc_phase
decl_stmt|;
comment|/* Copy of what bus phase we are in */
name|int
name|sc_prevphase
decl_stmt|;
comment|/* Copy of what bus phase we were in */
name|uint8_t
name|sc_state
decl_stmt|;
comment|/* State applicable to the adapter */
name|uint8_t
name|sc_flags
decl_stmt|;
comment|/* See below */
name|uint8_t
name|sc_selid
decl_stmt|;
name|uint8_t
name|sc_lastcmd
decl_stmt|;
comment|/* Message stuff */
name|uint16_t
name|sc_msgify
decl_stmt|;
comment|/* IDENTIFY message associated with nexus */
name|uint16_t
name|sc_msgout
decl_stmt|;
comment|/* What message is on its way out? */
name|uint16_t
name|sc_msgpriq
decl_stmt|;
comment|/* One or more messages to send (encoded) */
name|uint16_t
name|sc_msgoutq
decl_stmt|;
comment|/* What messages have been sent so far? */
name|uint8_t
modifier|*
name|sc_omess
decl_stmt|;
comment|/* MSGOUT buffer */
name|int
name|sc_omess_self
decl_stmt|;
comment|/* MSGOUT buffer is self-allocated */
name|void
modifier|*
name|sc_omp
decl_stmt|;
comment|/* Message pointer (for multibyte messages) */
name|size_t
name|sc_omlen
decl_stmt|;
name|uint8_t
modifier|*
name|sc_imess
decl_stmt|;
comment|/* MSGIN buffer */
name|int
name|sc_imess_self
decl_stmt|;
comment|/* MSGIN buffer is self-allocated */
name|void
modifier|*
name|sc_imp
decl_stmt|;
comment|/* Message pointer (for multibyte messages) */
name|size_t
name|sc_imlen
decl_stmt|;
name|void
modifier|*
name|sc_cmdp
decl_stmt|;
comment|/* Command pointer (for DMAed commands) */
name|size_t
name|sc_cmdlen
decl_stmt|;
comment|/* Size of command in transit */
comment|/* Hardware attributes */
name|int
name|sc_freq
decl_stmt|;
comment|/* SCSI bus frequency in MHz */
name|int
name|sc_id
decl_stmt|;
comment|/* Our SCSI id */
name|int
name|sc_rev
decl_stmt|;
comment|/* Chip revision */
name|int
name|sc_features
decl_stmt|;
comment|/* Chip features */
name|int
name|sc_minsync
decl_stmt|;
comment|/* Minimum sync period / 4 */
name|int
name|sc_maxxfer
decl_stmt|;
comment|/* Maximum transfer size */
name|int
name|sc_maxoffset
decl_stmt|;
comment|/* Maximum offset */
name|int
name|sc_maxwidth
decl_stmt|;
comment|/* Maximum width */
name|int
name|sc_extended_geom
decl_stmt|;
comment|/* Should we return extended geometry */
name|struct
name|mtx
name|sc_lock
decl_stmt|;
comment|/* driver mutex */
name|struct
name|ncr53c9x_ecb
modifier|*
name|ecb_array
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ncr53c9x_ecb
argument_list|)
name|free_list
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* values for sc_state */
end_comment

begin_define
define|#
directive|define
name|NCR_IDLE
value|1
end_define

begin_comment
comment|/* Waiting for something to do */
end_comment

begin_define
define|#
directive|define
name|NCR_SELECTING
value|2
end_define

begin_comment
comment|/* SCSI command is arbiting */
end_comment

begin_define
define|#
directive|define
name|NCR_RESELECTED
value|3
end_define

begin_comment
comment|/* Has been reselected */
end_comment

begin_define
define|#
directive|define
name|NCR_IDENTIFIED
value|4
end_define

begin_comment
comment|/* Has gotten IFY but not TAG */
end_comment

begin_define
define|#
directive|define
name|NCR_CONNECTED
value|5
end_define

begin_comment
comment|/* Actively using the SCSI bus */
end_comment

begin_define
define|#
directive|define
name|NCR_DISCONNECT
value|6
end_define

begin_comment
comment|/* MSG_DISCONNECT received */
end_comment

begin_define
define|#
directive|define
name|NCR_CMDCOMPLETE
value|7
end_define

begin_comment
comment|/* MSG_CMDCOMPLETE received */
end_comment

begin_define
define|#
directive|define
name|NCR_CLEANING
value|8
end_define

begin_define
define|#
directive|define
name|NCR_SBR
value|9
end_define

begin_comment
comment|/* Expect a SCSI RST because we commanded it */
end_comment

begin_comment
comment|/* values for sc_flags */
end_comment

begin_define
define|#
directive|define
name|NCR_DROP_MSGI
value|0x01
end_define

begin_comment
comment|/* Discard all msgs (parity err detected) */
end_comment

begin_define
define|#
directive|define
name|NCR_ABORTING
value|0x02
end_define

begin_comment
comment|/* Bailing out */
end_comment

begin_define
define|#
directive|define
name|NCR_ICCS
value|0x04
end_define

begin_comment
comment|/* Expect status phase results */
end_comment

begin_define
define|#
directive|define
name|NCR_WAITI
value|0x08
end_define

begin_comment
comment|/* Waiting for non-DMA data to arrive */
end_comment

begin_define
define|#
directive|define
name|NCR_ATN
value|0x10
end_define

begin_comment
comment|/* ATN asserted */
end_comment

begin_define
define|#
directive|define
name|NCR_EXPECT_ILLCMD
value|0x20
end_define

begin_comment
comment|/* Expect Illegal Command Interrupt */
end_comment

begin_comment
comment|/* values for sc_features */
end_comment

begin_define
define|#
directive|define
name|NCR_F_HASCFG3
value|0x01
end_define

begin_comment
comment|/* chip has CFG3 register */
end_comment

begin_define
define|#
directive|define
name|NCR_F_FASTSCSI
value|0x02
end_define

begin_comment
comment|/* chip supports Fast mode */
end_comment

begin_define
define|#
directive|define
name|NCR_F_DMASELECT
value|0x04
end_define

begin_comment
comment|/* can do dmaselect */
end_comment

begin_define
define|#
directive|define
name|NCR_F_SELATN3
value|0x08
end_define

begin_comment
comment|/* chip supports SELATN3 command */
end_comment

begin_define
define|#
directive|define
name|NCR_F_LARGEXFER
value|0x10
end_define

begin_comment
comment|/* chip supports transfers> 64k */
end_comment

begin_comment
comment|/* values for sc_msgout */
end_comment

begin_define
define|#
directive|define
name|SEND_DEV_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|SEND_PARITY_ERROR
value|0x0002
end_define

begin_define
define|#
directive|define
name|SEND_INIT_DET_ERR
value|0x0004
end_define

begin_define
define|#
directive|define
name|SEND_REJECT
value|0x0008
end_define

begin_define
define|#
directive|define
name|SEND_IDENTIFY
value|0x0010
end_define

begin_define
define|#
directive|define
name|SEND_ABORT
value|0x0020
end_define

begin_define
define|#
directive|define
name|SEND_TAG
value|0x0040
end_define

begin_define
define|#
directive|define
name|SEND_WDTR
value|0x0080
end_define

begin_define
define|#
directive|define
name|SEND_SDTR
value|0x0100
end_define

begin_comment
comment|/* SCSI Status codes */
end_comment

begin_define
define|#
directive|define
name|ST_MASK
value|0x3e
end_define

begin_comment
comment|/* bit 0,6,7 is reserved */
end_comment

begin_comment
comment|/* phase bits */
end_comment

begin_define
define|#
directive|define
name|IOI
value|0x01
end_define

begin_define
define|#
directive|define
name|CDI
value|0x02
end_define

begin_define
define|#
directive|define
name|MSGI
value|0x04
end_define

begin_comment
comment|/* Information transfer phases */
end_comment

begin_define
define|#
directive|define
name|DATA_OUT_PHASE
value|(0)
end_define

begin_define
define|#
directive|define
name|DATA_IN_PHASE
value|(IOI)
end_define

begin_define
define|#
directive|define
name|COMMAND_PHASE
value|(CDI)
end_define

begin_define
define|#
directive|define
name|STATUS_PHASE
value|(CDI | IOI)
end_define

begin_define
define|#
directive|define
name|MESSAGE_OUT_PHASE
value|(MSGI | CDI)
end_define

begin_define
define|#
directive|define
name|MESSAGE_IN_PHASE
value|(MSGI | CDI | IOI)
end_define

begin_define
define|#
directive|define
name|PHASE_MASK
value|(MSGI | CDI | IOI)
end_define

begin_comment
comment|/* Some pseudo phases for getphase()*/
end_comment

begin_define
define|#
directive|define
name|BUSFREE_PHASE
value|0x100
end_define

begin_comment
comment|/* Re/Selection no longer valid */
end_comment

begin_define
define|#
directive|define
name|INVALID_PHASE
value|0x101
end_define

begin_comment
comment|/* Re/Selection valid, but no REQ yet */
end_comment

begin_define
define|#
directive|define
name|PSEUDO_PHASE
value|0x100
end_define

begin_comment
comment|/* "pseudo" bit */
end_comment

begin_comment
comment|/*  * Macros to read and write the chip's registers.  */
end_comment

begin_define
define|#
directive|define
name|NCR_READ_REG
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|(*(sc)->sc_glue->gl_read_reg)((sc), (reg))
end_define

begin_define
define|#
directive|define
name|NCR_WRITE_REG
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|(*(sc)->sc_glue->gl_write_reg)((sc), (reg), (val))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NCR53C9X_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|NCRCMD
parameter_list|(
name|sc
parameter_list|,
name|cmd
parameter_list|)
value|do {						\ 	if ((ncr53c9x_debug& NCR_SHOWCCMDS) != 0)			\ 		printf("<CMD:0x%x %d>", (unsigned int)cmd, __LINE__);	\ 	sc->sc_lastcmd = cmd;						\ 	NCR_WRITE_REG(sc, NCR_CMD, cmd);				\ } while (
comment|/* CONSTCOND */
value|0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCRCMD
parameter_list|(
name|sc
parameter_list|,
name|cmd
parameter_list|)
value|NCR_WRITE_REG(sc, NCR_CMD, cmd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros for locking  */
end_comment

begin_define
define|#
directive|define
name|NCR_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&(_sc)->sc_lock, "ncr", "ncr53c9x lock", MTX_DEF);
end_define

begin_define
define|#
directive|define
name|NCR_LOCK_INITIALIZED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_initialized(&(_sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|NCR_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|NCR_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|NCR_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|_what
parameter_list|)
value|mtx_assert(&(_sc)->sc_lock, (_what))
end_define

begin_define
define|#
directive|define
name|NCR_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_lock)
end_define

begin_comment
comment|/*  * DMA macros for NCR53c9x  */
end_comment

begin_define
define|#
directive|define
name|NCRDMA_ISINTR
parameter_list|(
name|sc
parameter_list|)
value|(*(sc)->sc_glue->gl_dma_isintr)((sc))
end_define

begin_define
define|#
directive|define
name|NCRDMA_RESET
parameter_list|(
name|sc
parameter_list|)
value|(*(sc)->sc_glue->gl_dma_reset)((sc))
end_define

begin_define
define|#
directive|define
name|NCRDMA_INTR
parameter_list|(
name|sc
parameter_list|)
value|(*(sc)->sc_glue->gl_dma_intr)((sc))
end_define

begin_define
define|#
directive|define
name|NCRDMA_SETUP
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|len
parameter_list|,
name|datain
parameter_list|,
name|dmasize
parameter_list|)
define|\
value|(*(sc)->sc_glue->gl_dma_setup)((sc), (addr), (len), (datain), (dmasize))
end_define

begin_define
define|#
directive|define
name|NCRDMA_GO
parameter_list|(
name|sc
parameter_list|)
value|(*(sc)->sc_glue->gl_dma_go)((sc))
end_define

begin_define
define|#
directive|define
name|NCRDMA_STOP
parameter_list|(
name|sc
parameter_list|)
value|(*(sc)->sc_glue->gl_dma_stop)((sc))
end_define

begin_define
define|#
directive|define
name|NCRDMA_ISACTIVE
parameter_list|(
name|sc
parameter_list|)
value|(*(sc)->sc_glue->gl_dma_isactive)((sc))
end_define

begin_comment
comment|/*  * Macro to convert the chip register Clock Per Byte value to  * Synchronous Transfer Period.  */
end_comment

begin_define
define|#
directive|define
name|ncr53c9x_cpb2stp
parameter_list|(
name|sc
parameter_list|,
name|cpb
parameter_list|)
define|\
value|((250 * (cpb)) / (sc)->sc_freq)
end_define

begin_decl_stmt
specifier|extern
name|devclass_t
name|esp_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ncr53c9x_attach
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncr53c9x_detach
parameter_list|(
name|struct
name|ncr53c9x_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncr53c9x_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NCR53C9XVAR_H_ */
end_comment

end_unit

