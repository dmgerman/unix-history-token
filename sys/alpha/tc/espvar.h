begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: espvar.h,v 1.3.4.1 1996/09/10 17:28:18 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Peter Galbavy.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Peter Galbavy.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*#define ESP_DEBUG 0*/
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
comment|/* esp revisions */
end_comment

begin_define
define|#
directive|define
name|ESP100
value|0x01
end_define

begin_define
define|#
directive|define
name|ESP100A
value|0x02
end_define

begin_define
define|#
directive|define
name|ESP200
value|0x03
end_define

begin_define
define|#
directive|define
name|NCR53C94
value|0x04
end_define

begin_comment
comment|/*  * ECB. Holds additional information for each SCSI command Comments: We  * need a separate scsi command block because we may need to overwrite it  * with a request sense command.  Basicly, we refrain from fiddling with  * the scsi_xfer struct (except do the expected updating of return values).  * We'll generally update: xs->{flags,resid,error,sense,status} and  * occasionally xs->retries.  */
end_comment

begin_struct
struct|struct
name|ecb
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ecb
argument_list|)
name|chain
expr_stmt|;
name|struct
name|scsi_xfer
modifier|*
name|xs
decl_stmt|;
comment|/* SCSI xfer ctrl block from above */
name|int
name|flags
decl_stmt|;
comment|/* Status */
define|#
directive|define
name|ECB_QNONE
value|0
define|#
directive|define
name|ECB_QFREE
value|1
define|#
directive|define
name|ECB_QREADY
value|2
define|#
directive|define
name|ECB_QNEXUS
value|3
define|#
directive|define
name|ECB_QBITS
value|0x07
define|#
directive|define
name|ECB_CHKSENSE
value|0x08
define|#
directive|define
name|ECB_ABORTED
value|0x10
define|#
directive|define
name|ECB_SETQ
parameter_list|(
name|e
parameter_list|,
name|q
parameter_list|)
value|do (e)->flags = ((e)->flags&~ECB_QBITS)|(q); while(0)
name|struct
name|scsi_generic
name|cmd
decl_stmt|;
comment|/* SCSI command block */
name|int
name|clen
decl_stmt|;
name|char
modifier|*
name|daddr
decl_stmt|;
comment|/* Saved data pointer */
name|int
name|dleft
decl_stmt|;
comment|/* Residue */
name|struct
name|callout_handle
name|timeout_ch
decl_stmt|;
name|u_char
name|stat
decl_stmt|;
comment|/* SCSI status byte */
if|#
directive|if
name|ESP_DEBUG
operator|>
literal|0
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
name|ESP_DEBUG
operator|>
literal|0
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
value|do { \ 	const char *f = "[" msg "]"; \ 	int n = strlen((ecb)->trace); \ 	snprintf((ecb)->trace + n, sizeof((ecb)->trace) - n, f, a, b); \ } while(0)
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
comment|/*  * Some info about each (possible) target on the SCSI bus.  This should  * probably have been a "per target+lunit" structure, but we'll leave it at  * this for now.  Is there a way to reliably hook it up to sc->fordriver??  */
end_comment

begin_struct
struct|struct
name|esp_tinfo
block|{
name|int
name|cmds
decl_stmt|;
comment|/* #commands processed */
name|int
name|dconns
decl_stmt|;
comment|/* #disconnects */
name|int
name|touts
decl_stmt|;
comment|/* #timeouts */
name|int
name|perrs
decl_stmt|;
comment|/* #parity errors */
name|int
name|senses
decl_stmt|;
comment|/* #request sense commands sent */
name|ushort
name|lubusy
decl_stmt|;
comment|/* What local units/subr. are busy? */
name|u_char
name|flags
decl_stmt|;
define|#
directive|define
name|T_NEED_TO_RESET
value|0x01
comment|/* Should send a BUS_DEV_RESET */
define|#
directive|define
name|T_NEGOTIATE
value|0x02
comment|/* (Re)Negotiate synchronous options */
define|#
directive|define
name|T_BUSY
value|0x04
comment|/* Target is busy, i.e. cmd in progress */
define|#
directive|define
name|T_SYNCMODE
value|0x08
comment|/* sync mode has been negotiated */
define|#
directive|define
name|T_SYNCHOFF
value|0x10
comment|/* .. */
define|#
directive|define
name|T_RSELECTOFF
value|0x20
comment|/* .. */
name|u_char
name|period
decl_stmt|;
comment|/* Period suggestion */
name|u_char
name|offset
decl_stmt|;
comment|/* Offset suggestion */
block|}
name|tinfo_t
struct|;
end_struct

begin_comment
comment|/* Register a linenumber (for debugging) */
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
name|ESP_SHOWECBS
value|0x01
end_define

begin_define
define|#
directive|define
name|ESP_SHOWINTS
value|0x02
end_define

begin_define
define|#
directive|define
name|ESP_SHOWCMDS
value|0x04
end_define

begin_define
define|#
directive|define
name|ESP_SHOWMISC
value|0x08
end_define

begin_define
define|#
directive|define
name|ESP_SHOWTRAC
value|0x10
end_define

begin_define
define|#
directive|define
name|ESP_SHOWSTART
value|0x20
end_define

begin_define
define|#
directive|define
name|ESP_SHOWPHASE
value|0x40
end_define

begin_define
define|#
directive|define
name|ESP_SHOWDMA
value|0x80
end_define

begin_define
define|#
directive|define
name|ESP_SHOWCCMDS
value|0x100
end_define

begin_define
define|#
directive|define
name|ESP_SHOWMSGS
value|0x200
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ESP_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|esp_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ESP_ECBS
parameter_list|(
name|str
parameter_list|)
value|do {if (esp_debug& ESP_SHOWECBS) printf str;} while (0)
end_define

begin_define
define|#
directive|define
name|ESP_MISC
parameter_list|(
name|str
parameter_list|)
value|do {if (esp_debug& ESP_SHOWMISC) printf str;} while (0)
end_define

begin_define
define|#
directive|define
name|ESP_INTS
parameter_list|(
name|str
parameter_list|)
value|do {if (esp_debug& ESP_SHOWINTS) printf str;} while (0)
end_define

begin_define
define|#
directive|define
name|ESP_TRACE
parameter_list|(
name|str
parameter_list|)
value|do {if (esp_debug& ESP_SHOWTRAC) printf str;} while (0)
end_define

begin_define
define|#
directive|define
name|ESP_CMDS
parameter_list|(
name|str
parameter_list|)
value|do {if (esp_debug& ESP_SHOWCMDS) printf str;} while (0)
end_define

begin_define
define|#
directive|define
name|ESP_START
parameter_list|(
name|str
parameter_list|)
value|do {if (esp_debug& ESP_SHOWSTART) printf str;}while (0)
end_define

begin_define
define|#
directive|define
name|ESP_PHASE
parameter_list|(
name|str
parameter_list|)
value|do {if (esp_debug& ESP_SHOWPHASE) printf str;}while (0)
end_define

begin_define
define|#
directive|define
name|ESP_DMA
parameter_list|(
name|str
parameter_list|)
value|do {if (esp_debug& ESP_SHOWDMA) printf str;}while (0)
end_define

begin_define
define|#
directive|define
name|ESP_MSGS
parameter_list|(
name|str
parameter_list|)
value|do {if (esp_debug& ESP_SHOWMSGS) printf str;}while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ESP_ECBS
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ESP_MISC
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ESP_INTS
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ESP_TRACE
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ESP_CMDS
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ESP_START
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ESP_PHASE
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ESP_DMA
parameter_list|(
name|str
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ESP_MSGS
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
name|ESP_MAX_MSG_LEN
value|8
end_define

begin_struct
struct|struct
name|esp_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* us as a device */
ifdef|#
directive|ifdef
name|SPARC_DRIVER
name|struct
name|sbusdev
name|sc_sd
decl_stmt|;
comment|/* sbus device */
name|struct
name|intrhand
name|sc_ih
decl_stmt|;
comment|/* intr handler */
endif|#
directive|endif
name|struct
name|evcnt
name|sc_intrcnt
decl_stmt|;
comment|/* intr count */
name|struct
name|scsi_link
name|sc_link
decl_stmt|;
comment|/* scsi lint struct */
ifdef|#
directive|ifdef
name|SPARC_DRIVER
specifier|volatile
name|u_char
modifier|*
name|sc_reg
decl_stmt|;
comment|/* the registers */
name|struct
name|dma_softc
modifier|*
name|sc_dma
decl_stmt|;
comment|/* pointer to my dma */
else|#
directive|else
specifier|volatile
name|u_int32_t
modifier|*
name|sc_reg
decl_stmt|;
comment|/* the registers */
name|struct
name|tcds_slotconfig
modifier|*
name|sc_dma
decl_stmt|;
comment|/* DMA/slot info lives here. */
name|void
modifier|*
name|sc_cookie
decl_stmt|;
comment|/* intr. handling cookie */
endif|#
directive|endif
comment|/* register defaults */
name|u_char
name|sc_cfg1
decl_stmt|;
comment|/* Config 1 */
name|u_char
name|sc_cfg2
decl_stmt|;
comment|/* Config 2, not ESP100 */
name|u_char
name|sc_cfg3
decl_stmt|;
comment|/* Config 3, only ESP200 */
name|u_char
name|sc_ccf
decl_stmt|;
comment|/* Clock Conversion */
name|u_char
name|sc_timeout
decl_stmt|;
comment|/* register copies, see espreadregs() */
name|u_char
name|sc_espintr
decl_stmt|;
name|u_char
name|sc_espstat
decl_stmt|;
name|u_char
name|sc_espstep
decl_stmt|;
name|u_char
name|sc_espfflags
decl_stmt|;
comment|/* Lists of command blocks */
name|TAILQ_HEAD
argument_list|(
argument|ecb_list
argument_list|,
argument|ecb
argument_list|)
name|free_list
operator|,
name|ready_list
operator|,
name|nexus_list
expr_stmt|;
name|struct
name|ecb
modifier|*
name|sc_nexus
decl_stmt|;
comment|/* current command */
name|struct
name|ecb
name|sc_ecb
index|[
literal|8
index|]
decl_stmt|;
comment|/* one per target */
name|struct
name|esp_tinfo
name|sc_tinfo
index|[
literal|8
index|]
decl_stmt|;
comment|/* Data about the current nexus (updated for every cmd switch) */
name|caddr_t
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
name|u_char
name|sc_state
decl_stmt|;
comment|/* State applicable to the adapter */
name|u_char
name|sc_flags
decl_stmt|;
name|u_char
name|sc_selid
decl_stmt|;
name|u_char
name|sc_lastcmd
decl_stmt|;
comment|/* Message stuff */
name|u_char
name|sc_msgpriq
decl_stmt|;
comment|/* One or more messages to send (encoded) */
name|u_char
name|sc_msgout
decl_stmt|;
comment|/* What message is on its way out? */
name|u_char
name|sc_omess
index|[
name|ESP_MAX_MSG_LEN
index|]
decl_stmt|;
name|caddr_t
name|sc_omp
decl_stmt|;
comment|/* Message pointer (for multibyte messages) */
name|size_t
name|sc_omlen
decl_stmt|;
name|u_char
name|sc_imess
index|[
name|ESP_MAX_MSG_LEN
operator|+
literal|1
index|]
decl_stmt|;
name|caddr_t
name|sc_imp
decl_stmt|;
comment|/* Message pointer (for multibyte messages) */
name|size_t
name|sc_imlen
decl_stmt|;
comment|/* hardware/openprom stuff */
name|int
name|sc_node
decl_stmt|;
comment|/* PROM node ID */
name|int
name|sc_freq
decl_stmt|;
comment|/* Freq in HZ */
ifdef|#
directive|ifdef
name|SPARC_DRIVER
name|int
name|sc_pri
decl_stmt|;
comment|/* SBUS priority */
endif|#
directive|endif
name|int
name|sc_id
decl_stmt|;
comment|/* our scsi id */
name|int
name|sc_rev
decl_stmt|;
comment|/* esp revision */
name|int
name|sc_minsync
decl_stmt|;
comment|/* minimum sync period / 4 */
name|int
name|sc_maxxfer
decl_stmt|;
comment|/* maximum transfer size */
block|}
struct|;
end_struct

begin_comment
comment|/* values for sc_state */
end_comment

begin_define
define|#
directive|define
name|ESP_IDLE
value|0x01
end_define

begin_comment
comment|/* waiting for something to do */
end_comment

begin_define
define|#
directive|define
name|ESP_TMP_UNAVAIL
value|0x02
end_define

begin_comment
comment|/* Don't accept SCSI commands */
end_comment

begin_define
define|#
directive|define
name|ESP_SELECTING
value|0x03
end_define

begin_comment
comment|/* SCSI command is arbiting  */
end_comment

begin_define
define|#
directive|define
name|ESP_RESELECTED
value|0x04
end_define

begin_comment
comment|/* Has been reselected */
end_comment

begin_define
define|#
directive|define
name|ESP_HASNEXUS
value|0x05
end_define

begin_comment
comment|/* Actively using the SCSI bus */
end_comment

begin_define
define|#
directive|define
name|ESP_CLEANING
value|0x06
end_define

begin_define
define|#
directive|define
name|ESP_SBR
value|0x07
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
name|ESP_DROP_MSGI
value|0x01
end_define

begin_comment
comment|/* Discard all msgs (parity err detected) */
end_comment

begin_define
define|#
directive|define
name|ESP_DOINGDMA
value|0x02
end_define

begin_comment
comment|/* The FIFO data path is active! */
end_comment

begin_define
define|#
directive|define
name|ESP_BUSFREE_OK
value|0x04
end_define

begin_comment
comment|/* Bus free phase is OK. */
end_comment

begin_define
define|#
directive|define
name|ESP_SYNCHNEGO
value|0x08
end_define

begin_comment
comment|/* Synch negotiation in progress. */
end_comment

begin_comment
comment|/*#define ESP_BLOCKED	0x10	* Don't schedule new scsi bus operations */
end_comment

begin_define
define|#
directive|define
name|ESP_DISCON
value|0x10
end_define

begin_comment
comment|/* Target sent DISCONNECT msg */
end_comment

begin_define
define|#
directive|define
name|ESP_ABORTING
value|0x20
end_define

begin_comment
comment|/* Bailing out */
end_comment

begin_define
define|#
directive|define
name|ESP_ICCS
value|0x40
end_define

begin_comment
comment|/* Expect status phase results */
end_comment

begin_define
define|#
directive|define
name|ESP_WAITI
value|0x80
end_define

begin_comment
comment|/* Waiting for non-DMA data to arrive */
end_comment

begin_comment
comment|/* values for sc_msgout */
end_comment

begin_define
define|#
directive|define
name|SEND_DEV_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|SEND_PARITY_ERROR
value|0x02
end_define

begin_define
define|#
directive|define
name|SEND_ABORT
value|0x04
end_define

begin_define
define|#
directive|define
name|SEND_REJECT
value|0x08
end_define

begin_define
define|#
directive|define
name|SEND_INIT_DET_ERR
value|0x10
end_define

begin_define
define|#
directive|define
name|SEND_IDENTIFY
value|0x20
end_define

begin_define
define|#
directive|define
name|SEND_SDTR
value|0x40
end_define

begin_comment
comment|/* SCSI Status codes */
end_comment

begin_define
define|#
directive|define
name|ST_GOOD
value|0x00
end_define

begin_define
define|#
directive|define
name|ST_CHKCOND
value|0x02
end_define

begin_define
define|#
directive|define
name|ST_CONDMET
value|0x04
end_define

begin_define
define|#
directive|define
name|ST_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|ST_INTERMED
value|0x10
end_define

begin_define
define|#
directive|define
name|ST_INTERMED_CONDMET
value|0x14
end_define

begin_define
define|#
directive|define
name|ST_RESERVATION_CONFLICT
value|0x18
end_define

begin_define
define|#
directive|define
name|ST_CMD_TERM
value|0x22
end_define

begin_define
define|#
directive|define
name|ST_QUEUE_FULL
value|0x28
end_define

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
value|(CDI|IOI)
end_define

begin_define
define|#
directive|define
name|MESSAGE_OUT_PHASE
value|(MSGI|CDI)
end_define

begin_define
define|#
directive|define
name|MESSAGE_IN_PHASE
value|(MSGI|CDI|IOI)
end_define

begin_define
define|#
directive|define
name|PHASE_MASK
value|(MSGI|CDI|IOI)
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

begin_function_decl
specifier|static
name|u_char
name|ESP_READ_REG
parameter_list|(
name|struct
name|esp_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|1
end_if

begin_function
specifier|static
name|__inline
name|u_char
name|ESP_READ_REG
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
name|struct
name|esp_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|reg
decl_stmt|;
block|{
name|u_char
name|v
decl_stmt|;
name|v
operator|=
name|sc
operator|->
name|sc_reg
index|[
name|reg
operator|*
literal|2
index|]
operator|&
literal|0xff
expr_stmt|;
name|alpha_mb
argument_list|()
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ESP_READ_REG
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|((u_char)((sc)->sc_reg[(reg) * 2]& 0xff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ESP_WRITE_REG
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|do {					\ 		u_char v = (val);		\ 		(sc)->sc_reg[(reg) * 2] = v;	\ 		alpha_mb();			\ 	} while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ESP_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ESPCMD
parameter_list|(
name|sc
parameter_list|,
name|cmd
parameter_list|)
value|do {				\ 	if (esp_debug& ESP_SHOWCCMDS)			\ 		printf("<cmd:0x%x>", (unsigned)cmd);	\ 	sc->sc_lastcmd = cmd;				\ 	ESP_WRITE_REG(sc, ESP_CMD, cmd);		\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ESPCMD
parameter_list|(
name|sc
parameter_list|,
name|cmd
parameter_list|)
value|ESP_WRITE_REG(sc, ESP_CMD, cmd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SAME_ESP
parameter_list|(
name|unit
parameter_list|,
name|bp
parameter_list|,
name|ca
parameter_list|)
define|\
value|((bp->val[0] == ca->ca_slot&& bp->val[1] == ca->ca_offset) || \ 	 (bp->val[0] == -1&& bp->val[1] == unit))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SPARC_DRIVER
end_ifndef

begin_comment
comment|/* DMA macros for ESP */
end_comment

begin_define
define|#
directive|define
name|DMA_ISINTR
parameter_list|(
name|sc
parameter_list|)
value|tcds_dma_isintr(sc)
end_define

begin_define
define|#
directive|define
name|DMA_RESET
parameter_list|(
name|sc
parameter_list|)
value|tcds_dma_reset(sc)
end_define

begin_define
define|#
directive|define
name|DMA_INTR
parameter_list|(
name|sc
parameter_list|)
value|tcds_dma_intr(sc)
end_define

begin_define
define|#
directive|define
name|DMA_SETUP
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
value|tcds_dma_setup(sc, addr, len, datain, dmasize)
end_define

begin_define
define|#
directive|define
name|DMA_GO
parameter_list|(
name|sc
parameter_list|)
value|tcds_dma_go(sc)
end_define

begin_define
define|#
directive|define
name|DMA_ISACTIVE
parameter_list|(
name|sc
parameter_list|)
value|tcds_dma_isactive(sc)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

