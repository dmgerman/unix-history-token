begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NecBSD: bsvar.h,v 1.2 1997/10/31 17:43:41 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC98 series]  *  Copyright (c) 1994, 1995, 1996 NetBSD/pc98 porting staff.  *  All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Naofumi HONDA.  All rights reserved.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|BS_INLINE
value|__inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BS_INLINE
value|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**************************************************  *	CONTROL FLAGS  (cf_flags)  *************************************************/
end_comment

begin_define
define|#
directive|define
name|BSC_FASTACK
value|0x01
end_define

begin_define
define|#
directive|define
name|BSC_SMITSAT_DISEN
value|0x02
end_define

begin_define
define|#
directive|define
name|BSC_CHIP_CLOCK
parameter_list|(
name|dvcfg
parameter_list|)
value|(((dvcfg)>> 4)& 0x03)
end_define

begin_define
define|#
directive|define
name|BS_SCSI_SYNC
value|DVF_SCSI_SYNC
end_define

begin_define
define|#
directive|define
name|BS_SCSI_DISC
value|DVF_SCSI_DISC
end_define

begin_define
define|#
directive|define
name|BS_SCSI_WAIT
value|DVF_SCSI_WAIT
end_define

begin_define
define|#
directive|define
name|BS_SCSI_LINK
value|DVF_SCSI_LINK
end_define

begin_define
define|#
directive|define
name|BS_SCSI_QTAG
value|DVF_SCSI_QTAG
end_define

begin_define
define|#
directive|define
name|BS_SCSI_NOSAT
value|DVF_SCSI_SP0
end_define

begin_define
define|#
directive|define
name|BS_SCSI_NOPARITY
value|DVF_SCSI_NOPARITY
end_define

begin_define
define|#
directive|define
name|BS_SCSI_SAVESP
value|DVF_SCSI_SAVESP
end_define

begin_define
define|#
directive|define
name|BS_SCSI_NOSMIT
value|DVF_SCSI_SP1
end_define

begin_define
define|#
directive|define
name|BS_SCSI_PERIOD
parameter_list|(
name|XXX
parameter_list|)
value|DVF_SCSI_PERIOD(XXX)
end_define

begin_define
define|#
directive|define
name|BS_SCSI_OFFSET
parameter_list|(
name|XXX
parameter_list|)
value|DVF_SCSI_OFFSET(XXX)
end_define

begin_define
define|#
directive|define
name|BS_SCSI_SYNCMASK
value|DVF_SCSI_SYNCMASK
end_define

begin_define
define|#
directive|define
name|BS_SCSI_BITS
value|DVF_SCSI_BITS
end_define

begin_define
define|#
directive|define
name|BS_SCSI_DEFCFG
value|(BS_SCSI_NOSAT | DVF_SCSI_DEFCFG)
end_define

begin_define
define|#
directive|define
name|BS_SCSI_POSITIVE
value|(BS_SCSI_SYNC | BS_SCSI_DISC | BS_SCSI_LINK)
end_define

begin_define
define|#
directive|define
name|BS_SCSI_NEGATIVE
value|(BS_SCSI_WAIT | BS_SCSI_NOSAT | BS_SCSI_NOPARITY |\ 			  BS_SCSI_SAVESP | BS_SCSI_NOSMIT)
end_define

begin_comment
comment|/*******************************************  * CONFIG SECTION  ******************************************/
end_comment

begin_comment
comment|/* Enable timeout watch dog */
end_comment

begin_define
define|#
directive|define
name|BS_DEFAULT_TIMEOUT_SECOND
value|16
end_define

begin_comment
comment|/* default 16 sec */
end_comment

begin_define
define|#
directive|define
name|BS_SYNC_TIMEOUT
value|16
end_define

begin_define
define|#
directive|define
name|BS_STARTUP_TIMEOUT
value|60
end_define

begin_define
define|#
directive|define
name|BS_MOTOR_TIMEOUT
value|120
end_define

begin_define
define|#
directive|define
name|BS_TIMEOUT_CHECK_INTERVAL
value|4
end_define

begin_comment
comment|/* check each 4 sec */
end_comment

begin_comment
comment|/* If you use memory over 16M */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCSI_BOUNCE_SIZE
end_ifdef

begin_define
define|#
directive|define
name|BS_BOUNCE_SIZE
value|SCSI_BOUNCE_SIZE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SCSI_BOUNCE_SIZE */
end_comment

begin_define
define|#
directive|define
name|BS_BOUNCE_SIZE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SCSI_BOUNCE_SIZE */
end_comment

begin_comment
comment|/* debug */
end_comment

begin_define
define|#
directive|define
name|BS_STATICS
value|1
end_define

begin_define
define|#
directive|define
name|BS_DIAG
value|1
end_define

begin_define
define|#
directive|define
name|BS_DEBUG_ROUTINE
value|1
end_define

begin_define
define|#
directive|define
name|BS_DEBUG
value|1
end_define

begin_comment
comment|/* #define	SHOW_PORT	1 */
end_comment

begin_comment
comment|/**************************************************  *	PARAMETER  **************************************************/
end_comment

begin_define
define|#
directive|define
name|NTARGETS
value|8
end_define

begin_define
define|#
directive|define
name|RETRIES
value|1
end_define

begin_comment
comment|/* number of retries before giving up */
end_comment

begin_define
define|#
directive|define
name|HARDRETRIES
value|3
end_define

begin_define
define|#
directive|define
name|XSMAX
value|4
end_define

begin_define
define|#
directive|define
name|BSDMABUFSIZ
value|0x10000
end_define

begin_define
define|#
directive|define
name|BS_MAX_CCB
value|(XSMAX * (NTARGETS - 1))
end_define

begin_define
define|#
directive|define
name|BSCMDSTART
value|0
end_define

begin_define
define|#
directive|define
name|BSCMDRESTART
value|0x01
end_define

begin_define
define|#
directive|define
name|BSCMDFORCE
value|0x02
end_define

begin_define
define|#
directive|define
name|BS_TIMEOUT_INTERVAL
value|(hz * BS_TIMEOUT_CHECK_INTERVAL)
end_define

begin_comment
comment|/**************************************************  *	SCSI PHASE  **************************************************/
end_comment

begin_enum
enum|enum
name|scsi_phase
block|{
name|FREE
init|=
literal|0
block|,
name|HOSTQUEUE
block|,
name|DISCONNECTED
block|,
name|IOCOMPLETED
block|,
name|ATTENTIONASSERT
block|,
name|DISCONNECTASSERT
block|,
name|SELECTASSERT
block|,
name|SELECTED
block|,
name|RESELECTED
block|,
name|MSGIN
block|,
name|MSGOUT
block|,
name|STATUSIN
block|,
name|CMDPHASE
block|,
name|DATAPHASE
block|,
name|SATSEL
block|,
name|SATRESEL
block|,
name|SATSDP
block|,
name|SATCOMPSEQ
block|,
name|UNDEF
block|, }
enum|;
end_enum

begin_comment
comment|/**************************************************  *	SCSI PHASE CONTROL MACRO  **************************************************/
end_comment

begin_define
define|#
directive|define
name|BS_HOST_START
define|\
value|{							\ 	bsc->sc_nexus = ti;				\ }
end_define

begin_define
define|#
directive|define
name|BS_HOST_TERMINATE
define|\
value|{							\ 	bsc->sc_selwait = NULL;				\ 	bsc->sc_nexus = NULL;				\ }
end_define

begin_define
define|#
directive|define
name|BS_SELECTION_START
define|\
value|{							\ 	bsc->sc_selwait = ti;				\ }
end_define

begin_define
define|#
directive|define
name|BS_SELECTION_TERMINATE
define|\
value|{							\ 	bsc->sc_selwait = NULL;				\ }
end_define

begin_define
define|#
directive|define
name|BS_SETUP_PHASE
parameter_list|(
name|PHASE
parameter_list|)
define|\
value|{							\ 	ti->ti_ophase = ti->ti_phase;			\ 	ti->ti_phase = (PHASE);				\ }
end_define

begin_define
define|#
directive|define
name|BS_SETUP_MSGPHASE
parameter_list|(
name|PHASE
parameter_list|)
define|\
value|{							\ 	bsc->sc_msgphase = (PHASE);			\ }
end_define

begin_define
define|#
directive|define
name|BS_SETUP_SYNCSTATE
parameter_list|(
name|STATE
parameter_list|)
define|\
value|{							\ 	ti->ti_syncnow.state = (STATE);			\ }
end_define

begin_define
define|#
directive|define
name|BS_SETUP_TARGSTATE
parameter_list|(
name|STATE
parameter_list|)
define|\
value|{							\ 	ti->ti_state = (STATE);				\ }
end_define

begin_define
define|#
directive|define
name|BS_LOAD_SDP
define|\
value|{							\ 	bsc->sc_p.data = ti->ti_scsp.data;		\ 	bsc->sc_p.datalen = ti->ti_scsp.datalen;	\ 	bsc->sc_p.seglen = ti->ti_scsp.seglen;		\ }
end_define

begin_define
define|#
directive|define
name|BS_RESTORE_SDP
define|\
value|{							\ 	bsc->sc_p = ti->ti_scsp;			\ }
end_define

begin_define
define|#
directive|define
name|BS_SAVE_SDP
define|\
value|{							\ 	ti->ti_scsp = bsc->sc_p;			\ }
end_define

begin_comment
comment|/**************************************************  * STRUCTURES  **************************************************/
end_comment

begin_struct
struct|struct
name|msgbase
block|{
define|#
directive|define
name|MAXMSGLEN
value|8
name|u_int8_t
name|msg
index|[
name|MAXMSGLEN
index|]
decl_stmt|;
name|u_int
name|msglen
decl_stmt|;
name|u_int
name|flag
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|syncdata
block|{
name|u_int8_t
name|period
decl_stmt|;
name|u_int8_t
name|offset
decl_stmt|;
define|#
directive|define
name|BS_SYNCMSG_NULL
value|0x00
define|#
directive|define
name|BS_SYNCMSG_ASSERT
value|0x01
define|#
directive|define
name|BS_SYNCMSG_REJECT
value|0x02
define|#
directive|define
name|BS_SYNCMSG_ACCEPT
value|0x03
define|#
directive|define
name|BS_SYNCMSG_REQUESTED
value|0x04
name|u_int
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sc_p
block|{
name|u_int8_t
modifier|*
name|data
decl_stmt|;
name|int
name|datalen
decl_stmt|;
name|u_int8_t
modifier|*
name|segaddr
decl_stmt|;
name|int
name|seglen
decl_stmt|;
name|u_int8_t
modifier|*
name|bufp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* targ_info error flags */
end_comment

begin_define
define|#
directive|define
name|BSDMAABNORMAL
value|0x01
end_define

begin_define
define|#
directive|define
name|BSCMDABNORMAL
value|0x02
end_define

begin_define
define|#
directive|define
name|BSPARITY
value|0x04
end_define

begin_define
define|#
directive|define
name|BSSTATUSERROR
value|0x08
end_define

begin_define
define|#
directive|define
name|BSTIMEOUT
value|0x10
end_define

begin_define
define|#
directive|define
name|BSREQSENSE
value|0x20
end_define

begin_define
define|#
directive|define
name|BSSELTIMEOUT
value|0x40
end_define

begin_define
define|#
directive|define
name|BSFATALIO
value|0x80
end_define

begin_define
define|#
directive|define
name|BSMSGERROR
value|0x100
end_define

begin_define
define|#
directive|define
name|BSTRYRECOV
value|0x200
end_define

begin_define
define|#
directive|define
name|BSABNORMAL
value|0x400
end_define

begin_define
define|#
directive|define
name|BSTARGETBUSY
value|0x800
end_define

begin_define
define|#
directive|define
name|BSERRORBITS
value|"\020\014busy\013abnormal\012retry\011msgerr\010fatal\007seltimeout\006sense\005timeout\004statuserr\003parity\002cmderr\001dmaerr"
end_define

begin_comment
comment|/* bsccb bsccb_flags& targ_info flags& cmd flags*/
end_comment

begin_define
define|#
directive|define
name|BSREAD
value|0x0001
end_define

begin_define
define|#
directive|define
name|BSSAT
value|0x0002
end_define

begin_define
define|#
directive|define
name|BSLINK
value|0x0004
end_define

begin_define
define|#
directive|define
name|BSERROROK
value|0x0008
end_define

begin_define
define|#
directive|define
name|BSSMIT
value|0x0010
end_define

begin_define
define|#
directive|define
name|BSDISC
value|0x1000
end_define

begin_define
define|#
directive|define
name|BSFORCEIOPOLL
value|0x2000
end_define

begin_define
define|#
directive|define
name|BSCASTAT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BSSENSECCB
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BSQUEUED
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BSALTBUF
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BSITSDONE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BSNEXUS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BSCFLAGSMASK
value|(0xffff)
end_define

begin_struct
struct|struct
name|bsccb
block|{
name|TAILQ_ENTRY
argument_list|(
argument|bsccb
argument_list|)
name|ccb_chain
expr_stmt|;
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
comment|/* upper drivers info */
name|u_int
name|lun
decl_stmt|;
comment|/* lun */
name|u_int
name|bsccb_flags
decl_stmt|;
comment|/* control flags */
name|int
name|rcnt
decl_stmt|;
comment|/* retry counter of this ccb */
name|u_int
name|error
decl_stmt|;
comment|/* recorded error */
comment|/***************************************** 	 * scsi cmd& data 	 *****************************************/
name|u_int8_t
modifier|*
name|cmd
decl_stmt|;
comment|/* scsi cmd */
name|int
name|cmdlen
decl_stmt|;
name|u_int8_t
modifier|*
name|data
decl_stmt|;
comment|/* scsi data */
name|int
name|datalen
decl_stmt|;
name|u_int8_t
name|msgout
index|[
name|MAXMSGLEN
index|]
decl_stmt|;
comment|/* scsi msgout */
name|u_int
name|msgoutlen
decl_stmt|;
comment|/***************************************** 	 * timeout counter 	 *****************************************/
name|int
name|tc
decl_stmt|;
name|int
name|tcmax
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|GENERIC_CCB_ASSERT
argument_list|(
argument|bs
argument_list|,
argument|bsccb
argument_list|)
end_macro

begin_comment
comment|/* target info */
end_comment

begin_struct
struct|struct
name|targ_info
block|{
comment|/*0*/
name|TAILQ_ENTRY
argument_list|(
argument|targ_info
argument_list|)
name|ti_tchain
expr_stmt|;
comment|/* targ_info link */
comment|/*4*/
name|TAILQ_ENTRY
argument_list|(
argument|targ_info
argument_list|)
name|ti_wchain
expr_stmt|;
comment|/* wait link */
comment|/*8*/
name|struct
name|bs_softc
modifier|*
name|ti_bsc
decl_stmt|;
comment|/* our controller */
comment|/*c*/
name|u_int
name|ti_id
decl_stmt|;
comment|/* scsi id */
comment|/*10*/
name|u_int
name|ti_lun
decl_stmt|;
comment|/* current lun */
comment|/*14*/
name|struct
name|bsccbtab
name|ti_ctab
decl_stmt|,
name|ti_bctab
decl_stmt|;
comment|/* ccb */
define|#
directive|define
name|BS_TARG_NULL
value|0
define|#
directive|define
name|BS_TARG_CTRL
value|1
define|#
directive|define
name|BS_TARG_START
value|2
define|#
directive|define
name|BS_TARG_SYNCH
value|3
define|#
directive|define
name|BS_TARG_RDY
value|4
comment|/*24*/
name|int
name|ti_state
decl_stmt|;
comment|/* target state */
comment|/*28*/
name|u_int
name|ti_cfgflags
decl_stmt|;
comment|/* target cfg flags */
comment|/*2c*/
name|u_int
name|ti_flags
decl_stmt|;
comment|/* flags */
comment|/*30*/
name|u_int
name|ti_mflags
decl_stmt|;
comment|/* flags masks */
comment|/*34*/
name|u_int
name|ti_error
decl_stmt|;
comment|/* error flags */
comment|/*38*/
name|u_int
name|ti_herrcnt
decl_stmt|;
comment|/* hardware err retry counter */
comment|/***************************************** 	 * scsi phase data 	 *****************************************/
comment|/*3c*/
name|struct
name|sc_p
name|ti_scsp
decl_stmt|;
comment|/* saved scsi data pointer */
comment|/*50*/
name|enum
name|scsi_phase
name|ti_phase
decl_stmt|;
comment|/* scsi phase */
comment|/*54*/
name|enum
name|scsi_phase
name|ti_ophase
decl_stmt|;
comment|/* previous scsi phase */
comment|/*58*/
name|u_int8_t
name|ti_status
decl_stmt|;
comment|/* status in */
comment|/*59*/
name|u_int8_t
name|ti_msgin
index|[
name|MAXMSGLEN
index|]
decl_stmt|;
comment|/* msgin buffer */
comment|/*64*/
name|int
name|ti_msginptr
decl_stmt|;
comment|/*68*/
name|u_int8_t
name|ti_msgout
decl_stmt|;
comment|/* last msgout byte */
comment|/*69*/
name|u_int8_t
name|ti_emsgout
decl_stmt|;
comment|/* last msgout byte */
comment|/*6c*/
name|u_int
name|ti_omsgoutlen
decl_stmt|;
comment|/* for retry msgout */
comment|/*70*/
name|struct
name|syncdata
name|ti_syncmax
decl_stmt|;
comment|/* synch data (scsi) */
comment|/*72*/
name|struct
name|syncdata
name|ti_syncnow
decl_stmt|;
comment|/*74*/
name|u_int8_t
name|ti_sync
decl_stmt|;
comment|/* synch val (chip) */
comment|/***************************************** 	 * bounce buffer& smit data pointer 	 *****************************************/
comment|/*75*/
name|u_int8_t
modifier|*
name|bounce_phys
decl_stmt|;
comment|/*76*/
name|u_int8_t
modifier|*
name|bounce_addr
decl_stmt|;
comment|/*78*/
name|u_int
name|bounce_size
decl_stmt|;
comment|/*7c*/
name|u_long
name|sm_offset
decl_stmt|;
comment|/***************************************** 	 * target inq data 	 *****************************************/
comment|/*79*/
name|u_int8_t
name|targ_type
decl_stmt|;
comment|/*7a*/
name|u_int8_t
name|targ_support
decl_stmt|;
comment|/***************************************** 	 * generic scsi cmd buffer for this target 	 *****************************************/
comment|/*7b*/
name|u_int8_t
name|scsi_cmd
index|[
literal|12
index|]
decl_stmt|;
name|struct
name|scsi_sense_data
name|sense
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|titab
argument_list|,
name|targ_info
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|bshw
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bs_softc
block|{
comment|/***************************************** 	 * OS depend header 	 *****************************************/
name|OS_DEPEND_DEVICE_HEADER
name|OS_DEPEND_MISC_HEADER
comment|/***************************************** 	 * target link 	 *****************************************/
expr|struct
name|targ_info
operator|*
name|sc_ti
index|[
name|NTARGETS
index|]
expr_stmt|;
name|u_int
name|sc_openf
decl_stmt|;
name|struct
name|titab
name|sc_sttab
decl_stmt|;
name|struct
name|titab
name|sc_titab
decl_stmt|;
comment|/***************************************** 	 * current scsi phase 	 *****************************************/
name|struct
name|targ_info
modifier|*
name|sc_nexus
decl_stmt|;
comment|/* current active nexus */
name|enum
name|scsi_phase
name|sc_msgphase
decl_stmt|;
comment|/* scsi phase pointed by msg */
name|struct
name|targ_info
modifier|*
name|sc_selwait
decl_stmt|;
comment|/* selection assert */
name|u_int
name|sc_dtgnum
decl_stmt|;
comment|/* disconnected target */
comment|/***************************************** 	 * current scsi data pointer 	 *****************************************/
name|struct
name|sc_p
name|sc_p
decl_stmt|;
comment|/* scsi data pointer */
name|int
name|sc_dmadir
decl_stmt|;
comment|/* dma direction */
name|int
name|sm_tdatalen
decl_stmt|;
comment|/* smit data transfer bytes */
comment|/***************************************** 	 * parameter 	 *****************************************/
name|u_int
name|sc_retry
decl_stmt|;
comment|/* max retry count */
define|#
directive|define
name|BSDMATRANSFER
value|0x01
define|#
directive|define
name|BSDMASTART
value|0x02
define|#
directive|define
name|BSSMITSTART
value|0x04
define|#
directive|define
name|BSUNDERRESET
value|0x08
define|#
directive|define
name|BSRESET
value|0x10
define|#
directive|define
name|BSSTARTTIMEOUT
value|0x20
define|#
directive|define
name|BSPOLLDONE
value|0x100
define|#
directive|define
name|BSJOBDONE
value|0x200
define|#
directive|define
name|BSBSMODE
value|0x400
define|#
directive|define
name|BSINACTIVE
value|0x800
specifier|volatile
name|int
name|sc_flags
decl_stmt|;
comment|/* host flags */
define|#
directive|define
name|BSC_NULL
value|0
define|#
directive|define
name|BSC_BOOTUP
value|1
define|#
directive|define
name|BSC_TARG_CHECK
value|2
define|#
directive|define
name|BSC_RDY
value|3
name|int
name|sc_hstate
decl_stmt|;
comment|/* host state */
comment|/***************************************** 	 * polling misc 	 *****************************************/
name|u_int
name|sc_wc
decl_stmt|;
comment|/* weight count */
name|int
name|sc_poll
decl_stmt|;
name|struct
name|bsccb
modifier|*
name|sc_outccb
decl_stmt|;
comment|/***************************************** 	 * wd33c93 chip depend section 	 *****************************************/
name|u_int
name|sc_cfgflags
decl_stmt|;
comment|/* hardware cfg flags */
name|struct
name|bshw
modifier|*
name|sc_hw
decl_stmt|;
comment|/* hw selection */
name|u_long
name|sm_offset
decl_stmt|;
comment|/* smit buffer offset */
name|u_int
name|sc_RSTdelay
decl_stmt|;
name|int
name|sc_hwlock
decl_stmt|;
comment|/* hardware lock count */
name|int
name|sc_iobase
decl_stmt|;
comment|/* iobase for FreeBSD */
name|u_int32_t
name|sc_irq
decl_stmt|;
comment|/* irq */
name|u_int
name|sc_dmachan
decl_stmt|;
comment|/* dma channel */
name|u_int8_t
name|sc_busstat
decl_stmt|;
comment|/* scsi bus status register */
name|u_int8_t
name|sc_hostid
decl_stmt|;
comment|/* host scsi id */
name|u_int8_t
name|sc_cspeed
decl_stmt|;
comment|/* chip clock rate */
name|u_int8_t
name|sc_membank
decl_stmt|;
comment|/* memory back (NEC) register */
comment|/***************************************** 	 * our name 	 *****************************************/
define|#
directive|define
name|BS_DVNAME_LEN
value|16
name|u_char
name|sc_dvname
index|[
name|BS_DVNAME_LEN
index|]
decl_stmt|;
comment|/***************************************** 	 * CAM support 	 *****************************************/
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************  * debug  *************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BS_STATICS
end_ifdef

begin_struct
struct|struct
name|bs_statics
block|{
name|u_int
name|select
decl_stmt|;
name|u_int
name|select_miss_in_assert
decl_stmt|;
name|u_int
name|select_miss_by_reselect
decl_stmt|;
name|u_int
name|select_miss
decl_stmt|;
name|u_int
name|select_win
decl_stmt|;
name|u_int
name|selected
decl_stmt|;
name|u_int
name|disconnected
decl_stmt|;
name|u_int
name|reselect
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|bs_statics
name|bs_statics
index|[
name|NTARGETS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|bs_linkcmd_count
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|bs_bounce_used
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BS_STATICS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BS_DEBUG_ROUTINE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DDB
end_ifndef

begin_define
define|#
directive|define
name|Debugger
parameter_list|()
value|panic("should call debugger here (bs.c)")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DDB */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BS_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|bs_debug_flag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BS_DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BS_DEBUG_ROUTINE */
end_comment

begin_comment
comment|/*************************************************  * Function declare  *************************************************/
end_comment

begin_decl_stmt
name|int
name|bs_scsi_cmd_internal
name|__P
argument_list|(
operator|(
expr|struct
name|bsccb
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bsccb
modifier|*
name|bscmddone
name|__P
argument_list|(
operator|(
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bscmdstart
name|__P
argument_list|(
operator|(
expr|struct
name|targ_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bs_scsi_cmd_poll
name|__P
argument_list|(
operator|(
expr|struct
name|targ_info
operator|*
operator|,
expr|struct
name|bsccb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bs_sequencer
name|__P
argument_list|(
operator|(
expr|struct
name|bs_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bs_poll_timeout
name|__P
argument_list|(
operator|(
expr|struct
name|bs_softc
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************************************************  * XXX  *************************************************/
end_comment

begin_comment
comment|/* misc error */
end_comment

begin_define
define|#
directive|define
name|COMPLETE
value|2
end_define

begin_define
define|#
directive|define
name|NOTARGET
value|(-2)
end_define

begin_define
define|#
directive|define
name|HASERROR
value|(-1)
end_define

begin_comment
comment|/* XXX: use scsi_message.h */
end_comment

begin_comment
comment|/* status */
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
name|ST_MET
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
name|ST_INTERGOOD
value|0x10
end_define

begin_define
define|#
directive|define
name|ST_INTERMET
value|0x14
end_define

begin_define
define|#
directive|define
name|ST_CONFLICT
value|0x18
end_define

begin_define
define|#
directive|define
name|ST_QUEFULL
value|0x28
end_define

begin_define
define|#
directive|define
name|ST_UNK
value|0xff
end_define

begin_comment
comment|/* message */
end_comment

begin_define
define|#
directive|define
name|MSG_COMP
value|0x00
end_define

begin_define
define|#
directive|define
name|MSG_EXTEND
value|0x01
end_define

begin_define
define|#
directive|define
name|MKMSG_EXTEND
parameter_list|(
name|XLEN
parameter_list|,
name|XCODE
parameter_list|)
value|((((u_int)(XLEN))<< NBBY) | ((u_int)(XCODE)))
end_define

begin_define
define|#
directive|define
name|MSG_EXTEND_MDPCODE
value|0x00
end_define

begin_define
define|#
directive|define
name|MSG_EXTEND_MDPLEN
value|0x05
end_define

begin_define
define|#
directive|define
name|MSG_EXTEND_SYNCHCODE
value|0x01
end_define

begin_define
define|#
directive|define
name|MSG_EXTEND_SYNCHLEN
value|0x03
end_define

begin_define
define|#
directive|define
name|MSG_EXTEND_WIDECODE
value|0x03
end_define

begin_define
define|#
directive|define
name|MSG_EXTEND_WIDELEN
value|0x02
end_define

begin_define
define|#
directive|define
name|MSG_SAVESP
value|0x02
end_define

begin_define
define|#
directive|define
name|MSG_RESTORESP
value|0x03
end_define

begin_define
define|#
directive|define
name|MSG_DISCON
value|0x04
end_define

begin_define
define|#
directive|define
name|MSG_I_ERROR
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
name|MSG_PARITY
value|0x09
end_define

begin_define
define|#
directive|define
name|MSG_LCOMP
value|0x0a
end_define

begin_define
define|#
directive|define
name|MSG_LCOMP_F
value|0x0b
end_define

begin_define
define|#
directive|define
name|MSG_RESET
value|0x0c
end_define

end_unit

