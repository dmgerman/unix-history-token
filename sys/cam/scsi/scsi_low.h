begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: scsi_low.h,v 1.24 1999/07/23 21:00:05 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_LOW_DIAGNOSTIC
end_define

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1995, 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1995, 1996, 1997, 1998  *	Naofumi HONDA. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_LOW_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_LOW_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<i386/Cbus/dev/scsi_dvcfg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/device_port.h>
end_include

begin_define
define|#
directive|define
name|CAM
end_define

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_dvcfg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* user configuration flags defs */
end_comment

begin_define
define|#
directive|define
name|SCSI_LOW_SYNC
value|DVF_SCSI_SYNC
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_DISC
value|DVF_SCSI_DISC
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_WAIT
value|DVF_SCSI_WAIT
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_LINK
value|DVF_SCSI_LINK
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_QTAG
value|DVF_SCSI_QTAG
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_NOPARITY
value|DVF_SCSI_NOPARITY
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_SAVESP
value|DVF_SCSI_SAVESP
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_DEFCFG
value|DVF_SCSI_DEFCFG
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_BITS
value|DVF_SCSI_BITS
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_PERIOD
parameter_list|(
name|n
parameter_list|)
value|DVF_SCSI_PERIOD(n)
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_OFFSET
parameter_list|(
name|n
parameter_list|)
value|DVF_SCSI_OFFSET(n)
end_define

begin_comment
comment|/* host scsi id and targets macro */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_LOW_NTARGETS
end_ifndef

begin_define
define|#
directive|define
name|SCSI_LOW_NTARGETS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCSI_LOW_NTARGETS */
end_comment

begin_define
define|#
directive|define
name|SCSI_LOW_NCCB
value|32
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_MAX_MSGLEN
value|16
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_MAX_RETRY
value|3
end_define

begin_comment
comment|/* timeout control macro */
end_comment

begin_define
define|#
directive|define
name|SCSI_LOW_MIN_TOUT
value|24
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_TIMEOUT_CHECK_INTERVAL
value|4
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_POWDOWN_TC
value|15
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_MAX_PHCHANGES
value|256
end_define

begin_comment
comment|/* max synch period */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_LOW_MAX_SYNCH_SPEED
end_ifndef

begin_define
define|#
directive|define
name|SCSI_LOW_MAX_SYNCH_SPEED
value|(100)
end_define

begin_comment
comment|/* 10.0M */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SCSI_LOW_MAX_SYNCH_SPEED */
end_comment

begin_comment
comment|/*************************************************  * Scsi Data Pointer  *************************************************/
end_comment

begin_comment
comment|/* scsi pointer */
end_comment

begin_struct
struct|struct
name|sc_p
block|{
name|u_int8_t
modifier|*
name|scp_data
decl_stmt|;
name|int
name|scp_datalen
decl_stmt|;
name|u_int8_t
modifier|*
name|scp_cmd
decl_stmt|;
name|int
name|scp_cmdlen
decl_stmt|;
name|u_int
name|scp_direction
decl_stmt|;
define|#
directive|define
name|SCSI_LOW_RWUNK
value|(-1)
define|#
directive|define
name|SCSI_LOW_WRITE
value|0
define|#
directive|define
name|SCSI_LOW_READ
value|1
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSI_LOW_SETUP_PHASE
parameter_list|(
name|ti
parameter_list|,
name|phase
parameter_list|)
define|\
value|{							\ 	if ((ti)->ti_phase != (phase))			\ 	{						\ 		(ti)->ti_ophase = ti->ti_phase;		\ 		(ti)->ti_phase = (phase);		\ 	}						\ }
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_SETUP_MSGPHASE
parameter_list|(
name|slp
parameter_list|,
name|PHASE
parameter_list|)
define|\
value|{							\ 	(slp)->sl_msgphase = (PHASE);			\ }
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_TARGET_ASSERT_ATN
parameter_list|(
name|slp
parameter_list|)
define|\
value|{							\ 	(ti)->ti_tflags |= TARG_ASSERT_ATN;		\ }
end_define

begin_comment
comment|/*************************************************  * Command Control Block Structure  *************************************************/
end_comment

begin_typedef
typedef|typedef
name|int
name|scsi_low_tag_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|targ_info
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|SCSI_LOW_UNKLUN
value|((u_int) -1)
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_UNKTAG
value|((scsi_low_tag_t) -1)
end_define

begin_struct
struct|struct
name|slccb
block|{
name|TAILQ_ENTRY
argument_list|(
argument|slccb
argument_list|)
name|ccb_chain
expr_stmt|;
ifdef|#
directive|ifdef
name|CAM
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
else|#
directive|else
name|struct
name|scsipi_xfer
modifier|*
name|xs
decl_stmt|;
comment|/* scsi upper */
endif|#
directive|endif
name|struct
name|targ_info
modifier|*
name|ti
decl_stmt|;
comment|/* targ_info */
name|struct
name|lun_info
modifier|*
name|li
decl_stmt|;
comment|/* lun info */
name|scsi_low_tag_t
name|ccb_tag
decl_stmt|;
comment|/* tag */
comment|/***************************************** 	 * Scsi data pointers (original and saved) 	 *****************************************/
name|struct
name|sc_p
name|ccb_scp
decl_stmt|;
comment|/* given */
name|struct
name|sc_p
name|ccb_sscp
decl_stmt|;
comment|/* saved scsi data pointer */
ifdef|#
directive|ifdef
name|SCSI_LOW_SUPPORT_USER_MSGOUT
name|u_int8_t
name|msgout
index|[
name|SCSI_LOW_MAX_MSGLEN
index|]
decl_stmt|;
comment|/* scsi msgout */
name|u_int
name|msgoutlen
decl_stmt|;
endif|#
directive|endif
comment|/* SCSI_LOW_SUPPORT_USER_MSGOUT */
comment|/***************************************** 	 * Error or Timeout counters 	 *****************************************/
name|u_int
name|ccb_flags
decl_stmt|;
define|#
directive|define
name|CCB_SENSE
value|0x01
name|u_int
name|ccb_error
decl_stmt|;
name|int
name|ccb_rcnt
decl_stmt|;
comment|/* retry counter */
name|int
name|ccb_tc
decl_stmt|;
comment|/* timer counter */
name|int
name|ccb_tcmax
decl_stmt|;
comment|/* max timeout */
comment|/***************************************** 	 * Sense data buffer 	 *****************************************/
ifdef|#
directive|ifdef
name|__NetBSD__
name|struct
name|scsipi_sense
name|ccb_sense_cmd
decl_stmt|;
name|struct
name|scsipi_sense_data
name|ccb_sense
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|scsi_sense
name|ccb_sense_cmd
decl_stmt|;
name|struct
name|scsi_sense_data
name|ccb_sense
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* ccb assert */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<dev/isa/ccbque.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<i386/isa/ccbque.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|GENERIC_CCB_ASSERT
argument_list|(
argument|scsi_low
argument_list|,
argument|slccb
argument_list|)
end_macro

begin_comment
comment|/*************************************************  * Target structures  *************************************************/
end_comment

begin_struct_decl
struct_decl|struct
name|scsi_low_softc
struct_decl|;
end_struct_decl

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|targ_info_tab
argument_list|,
name|targ_info
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|lun_info_tab
argument_list|,
name|lun_info
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|lun_info
block|{
name|int
name|li_lun
decl_stmt|;
name|struct
name|targ_info
modifier|*
name|li_ti
decl_stmt|;
comment|/* my target */
name|LIST_ENTRY
argument_list|(
argument|lun_info
argument_list|)
name|lun_chain
expr_stmt|;
comment|/* targ_info link */
name|int
name|li_disc
decl_stmt|;
comment|/* num disconnects */
name|int
name|li_maxnexus
decl_stmt|;
comment|/* 	 * lun state 	 */
define|#
directive|define
name|UNIT_SLEEP
value|0x00
define|#
directive|define
name|UNIT_START
value|0x01
define|#
directive|define
name|UNIT_SYNCH
value|0x02
define|#
directive|define
name|UNIT_WIDE
value|0x03
define|#
directive|define
name|UNIT_OK
value|0x04
define|#
directive|define
name|UNIT_NEGSTART
value|UNIT_SYNCH
name|u_int
name|li_state
decl_stmt|;
comment|/* target lun state */
name|u_int
name|li_maxstate
decl_stmt|;
comment|/* max state */
comment|/* 	 * lun control flags  	 */
name|u_int
name|li_flags
decl_stmt|;
comment|/* real control flags */
name|u_int
name|li_cfgflags
decl_stmt|;
comment|/* given target cfgflags */
name|u_int
name|li_quirks
decl_stmt|;
comment|/* given target quirk */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|targ_info
block|{
name|TAILQ_ENTRY
argument_list|(
argument|targ_info
argument_list|)
name|ti_chain
expr_stmt|;
comment|/* targ_info link */
name|struct
name|scsi_low_softc
modifier|*
name|ti_sc
decl_stmt|;
comment|/* our softc */
name|u_int
name|ti_id
decl_stmt|;
comment|/* scsi id */
comment|/* 	 * Lun chain 	 */
name|struct
name|lun_info_tab
name|ti_litab
decl_stmt|;
comment|/* lun chain */
comment|/* 	 * Nexus 	 */
name|struct
name|slccb
modifier|*
name|ti_nexus
decl_stmt|;
comment|/* current nexus */
name|struct
name|lun_info
modifier|*
name|ti_li
decl_stmt|;
comment|/* current nexus lun_info */
comment|/* 	 * Target status  	 */
define|#
directive|define
name|TARG_ASSERT_ATN
value|0x01
name|u_int
name|ti_tflags
decl_stmt|;
comment|/* target state I */
comment|/* 	 * Scsi phase control  	 */
name|struct
name|slccbtab
name|ti_discq
decl_stmt|;
comment|/* disconnect queue */
define|#
directive|define
name|PH_NULL
value|0x00
define|#
directive|define
name|PH_ARBSTART
value|0x01
define|#
directive|define
name|PH_SELSTART
value|0x02
define|#
directive|define
name|PH_SELECTED
value|0x03
define|#
directive|define
name|PH_CMD
value|0x04
define|#
directive|define
name|PH_DATA
value|0x05
define|#
directive|define
name|PH_MSGIN
value|0x06
define|#
directive|define
name|PH_MSGOUT
value|0x07
define|#
directive|define
name|PH_STAT
value|0x08
define|#
directive|define
name|PH_DISC
value|0x09
define|#
directive|define
name|PH_RESEL
value|0x0a
name|u_int
name|ti_phase
decl_stmt|;
comment|/* scsi phase */
name|u_int
name|ti_ophase
decl_stmt|;
comment|/* old scsi phase */
comment|/* 	 * Status in  	 */
name|u_int8_t
name|ti_status
decl_stmt|;
comment|/* status in */
comment|/* 	 * Msg in  	 */
name|u_int
name|ti_msginptr
decl_stmt|;
comment|/* msgin ptr */
name|u_int
name|ti_msginlen
decl_stmt|;
comment|/* expected msg length */
name|u_int8_t
name|ti_msgin
index|[
name|SCSI_LOW_MAX_MSGLEN
index|]
decl_stmt|;
comment|/* msgin buffer */
name|u_int
name|ti_sphase
decl_stmt|;
ifdef|#
directive|ifdef
name|SCSI_LOW_DIAGNOSTIC
define|#
directive|define
name|MSGIN_HISTORY_LEN
value|5
name|u_int8_t
name|ti_msgin_history
index|[
name|MSGIN_HISTORY_LEN
index|]
decl_stmt|;
name|int
name|ti_msgin_hist_pointer
decl_stmt|;
endif|#
directive|endif
comment|/* SCSI_LOW_DIAGNOSTIC */
comment|/* 	 * Msg out  	 */
name|u_int
name|ti_msgflags
decl_stmt|;
comment|/* msgs to be asserted */
name|u_int
name|ti_omsgflags
decl_stmt|;
comment|/* msgs asserted */
name|u_int
name|ti_emsgflags
decl_stmt|;
comment|/* a msg currently asserted */
define|#
directive|define
name|SCSI_LOW_MSG_RESET
value|0x00000001
define|#
directive|define
name|SCSI_LOW_MSG_ABORT
value|0x00000002
define|#
directive|define
name|SCSI_LOW_MSG_REJECT
value|0x00000004
define|#
directive|define
name|SCSI_LOW_MSG_PARITY
value|0x00000008
define|#
directive|define
name|SCSI_LOW_MSG_ERROR
value|0x00000010
define|#
directive|define
name|SCSI_LOW_MSG_IDENTIFY
value|0x00000020
define|#
directive|define
name|SCSI_LOW_MSG_SYNCH
value|0x00000040
define|#
directive|define
name|SCSI_LOW_MSG_WIDE
value|0x00000080
define|#
directive|define
name|SCSI_LOW_MSG_USER
value|0x00000100
define|#
directive|define
name|SCSI_LOW_MSG_NOOP
value|0x00000200
define|#
directive|define
name|SCSI_LOW_MSG_ALL
value|0xffffffff
comment|/* msgout buffer */
name|u_int8_t
name|ti_msgoutstr
index|[
name|SCSI_LOW_MAX_MSGLEN
index|]
decl_stmt|;
comment|/* scsi msgout */
name|u_int
name|ti_msgoutlen
decl_stmt|;
comment|/* msgout strlen */
comment|/* 	 * synch and wide data  	 */
struct|struct
name|synch
block|{
name|u_int8_t
name|offset
decl_stmt|;
name|u_int8_t
name|period
decl_stmt|;
block|}
name|ti_maxsynch
struct|;
comment|/* synch data */
name|u_int
name|ti_width
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************  * COMMON HEADER STRUCTURE  *************************************************/
end_comment

begin_struct_decl
struct_decl|struct
name|scsi_low_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|scsi_low_softc
modifier|*
name|sc_low_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCSI_LOW_START_OK
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_START_FAIL
value|1
end_define

begin_define
define|#
directive|define
name|SC_LOW_INIT_T
value|(int (*) __P((sc_low_t, int)))
end_define

begin_define
define|#
directive|define
name|SC_LOW_BUSRST_T
value|(void (*) __P((sc_low_t)))
end_define

begin_define
define|#
directive|define
name|SC_LOW_TARG_INIT_T
value|(int (*) __P((sc_low_t, struct targ_info *)))
end_define

begin_define
define|#
directive|define
name|SC_LOW_SELECT_T
value|(int (*) __P((sc_low_t, struct slccb *)))
end_define

begin_define
define|#
directive|define
name|SC_LOW_ATTEN_T
value|(void (*) __P((sc_low_t)))
end_define

begin_define
define|#
directive|define
name|SC_LOW_NEXUS_T
value|(int (*) __P((sc_low_t, struct targ_info *)))
end_define

begin_define
define|#
directive|define
name|SC_LOW_MSG_T
value|(int (*) __P((sc_low_t, struct targ_info *, u_int)))
end_define

begin_define
define|#
directive|define
name|SC_LOW_POLL_T
value|(int (*) __P((void *)))
end_define

begin_define
define|#
directive|define
name|SC_LOW_POWER_T
value|(int (*) __P((sc_low_t, u_int)))
end_define

begin_struct
struct|struct
name|scsi_low_funcs
block|{
name|int
argument_list|(
argument|*scsi_low_init
argument_list|)
name|__P
argument_list|(
operator|(
name|sc_low_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*scsi_low_bus_reset
argument_list|)
name|__P
argument_list|(
operator|(
name|sc_low_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scsi_low_targ_init
argument_list|)
name|__P
argument_list|(
operator|(
name|sc_low_t
operator|,
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scsi_low_start_bus
argument_list|)
name|__P
argument_list|(
operator|(
name|sc_low_t
operator|,
expr|struct
name|slccb
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scsi_low_establish_nexus
argument_list|)
name|__P
argument_list|(
operator|(
name|sc_low_t
operator|,
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*scsi_low_attention
argument_list|)
name|__P
argument_list|(
operator|(
name|sc_low_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scsi_low_msg
argument_list|)
name|__P
argument_list|(
operator|(
name|sc_low_t
operator|,
expr|struct
name|targ_info
operator|*
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scsi_low_poll
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|SCSI_LOW_POWDOWN
value|1
define|#
directive|define
name|SCSI_LOW_ENGAGE
value|2
name|int
argument_list|(
argument|*scsi_low_power
argument_list|)
name|__P
argument_list|(
operator|(
name|sc_low_t
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************  * SCSI LOW SOFTC  *************************************************/
end_comment

begin_struct
struct|struct
name|scsi_low_softc
block|{
name|DEVPORT_DEVICE
name|sl_dev
decl_stmt|;
name|u_char
name|sl_xname
index|[
literal|16
index|]
decl_stmt|;
comment|/* upper interface */
ifdef|#
directive|ifdef
name|CAM
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
else|#
directive|else
name|struct
name|scsipi_link
name|sl_link
decl_stmt|;
endif|#
directive|endif
comment|/* my targets */
name|struct
name|targ_info
modifier|*
name|sl_ti
index|[
name|SCSI_LOW_NTARGETS
index|]
decl_stmt|;
name|struct
name|targ_info_tab
name|sl_titab
decl_stmt|;
comment|/* current active nexus */
name|int
name|sl_nexus_call
decl_stmt|;
name|struct
name|targ_info
modifier|*
name|sl_nexus
decl_stmt|;
comment|/* ccb start queue */
name|struct
name|slccbtab
name|sl_start
decl_stmt|;
comment|/* retry limit and phase change counter */
name|int
name|sl_max_retry
decl_stmt|;
name|int
name|sl_ph_count
decl_stmt|;
comment|/* selection& total num disconnect targets */
name|int
name|sl_disc
decl_stmt|;
name|struct
name|targ_info
modifier|*
name|sl_selid
decl_stmt|;
comment|/* scsi phased suggested by scsi msg */
name|u_int
name|sl_msgphase
decl_stmt|;
define|#
directive|define
name|MSGPH_NULL
value|0x00
comment|/* no msg */
define|#
directive|define
name|MSGPH_DISC
value|0x01
comment|/* disconnect msg */
define|#
directive|define
name|MSGPH_CMDC
value|0x02
comment|/* cmd complete msg */
comment|/* error */
define|#
directive|define
name|FATALIO
value|0x01
comment|/* generic io error& retry io */
define|#
directive|define
name|ABORTIO
value|0x02
comment|/* generic io error& terminate io */
define|#
directive|define
name|TIMEOUTIO
value|0x04
comment|/* watch dog timeout */
define|#
directive|define
name|SELTIMEOUTIO
value|0x08
comment|/* selection timeout */
define|#
directive|define
name|PDMAERR
value|0x10
comment|/* dma xfer error */
define|#
directive|define
name|MSGERR
value|0x20
comment|/* msgsys error */
define|#
directive|define
name|PARITYERR
value|0x40
comment|/* parity error */
define|#
directive|define
name|BUSYERR
value|0x80
comment|/* target busy error */
define|#
directive|define
name|CMDREJECT
value|0x100
comment|/* cmd reject error */
define|#
directive|define
name|SCSI_LOW_ERRORBITS
value|"\020\009cmdrej\008busy\007parity\006msgerr\005pdmaerr\004seltimeout\003timeout\002abort\001fatal"
name|u_int
name|sl_error
decl_stmt|;
comment|/* error flags */
comment|/* current scsi data pointer */
name|struct
name|sc_p
name|sl_scp
decl_stmt|;
comment|/* power control */
name|u_int
name|sl_active
decl_stmt|;
comment|/* host is busy state */
name|int
name|sl_powc
decl_stmt|;
comment|/* power down timer counter */
name|u_int
name|sl_rstep
decl_stmt|;
comment|/* resume step */
comment|/* configuration flags */
name|u_int
name|sl_flags
decl_stmt|;
define|#
directive|define
name|HW_POWDOWN
value|0x01
define|#
directive|define
name|HW_RESUME
value|0x02
define|#
directive|define
name|HW_PDMASTART
value|0x04
define|#
directive|define
name|HW_INACTIVE
value|0x08
define|#
directive|define
name|HW_POWERCTRL
value|0x10
name|u_int
name|sl_cfgflags
decl_stmt|;
define|#
directive|define
name|CFG_NODISC
value|0x01
define|#
directive|define
name|CFG_NOPARITY
value|0x02
define|#
directive|define
name|CFG_NOATTEN
value|0x04
define|#
directive|define
name|CFG_ASYNC
value|0x08
define|#
directive|define
name|CFG_MSGUNIFY
value|0x10
comment|/* host informations */
name|u_int
name|sl_hostid
decl_stmt|;
name|int
name|sl_nluns
decl_stmt|;
name|int
name|sl_ntargs
decl_stmt|;
name|int
name|sl_openings
decl_stmt|;
comment|/* interface functions */
name|struct
name|scsi_low_funcs
modifier|*
name|sl_funcs
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
name|u_int
name|sl_irq
decl_stmt|;
comment|/* XXX */
endif|#
directive|endif
comment|/* i386 */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|callout_handle
name|engage_ch
decl_stmt|;
name|struct
name|callout_handle
name|timeout_ch
decl_stmt|;
ifdef|#
directive|ifdef
name|SCSI_LOW_POWFUNC
name|struct
name|callout_handle
name|recover_ch
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* __FreeBSD__ */
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************  * SCSI LOW service functions  *************************************************/
end_comment

begin_comment
comment|/*   * Scsi low attachment function.  */
end_comment

begin_decl_stmt
name|int
name|scsi_low_attach
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scsi_low_dettach
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Scsi phase "bus service" functions.  * These functions are corresponding to each scsi bus phaeses.  */
end_comment

begin_comment
comment|/* nexus abort (selection failed) */
end_comment

begin_decl_stmt
name|void
name|scsi_low_clear_nexus
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* msgout phase */
end_comment

begin_decl_stmt
name|int
name|scsi_low_msgout
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* msgin phase */
end_comment

begin_decl_stmt
name|void
name|scsi_low_msgin
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|,
name|u_int8_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data phase */
end_comment

begin_decl_stmt
name|int
name|scsi_low_data
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cmd phase */
end_comment

begin_decl_stmt
name|int
name|scsi_low_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reselection phase */
end_comment

begin_decl_stmt
name|struct
name|targ_info
modifier|*
name|scsi_low_reselected
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* disconnection phase */
end_comment

begin_decl_stmt
name|int
name|scsi_low_disconnected
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Scsi bus restart function.  * Canncel all established nexuses => scsi system initialized => restart jobs.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_LOW_RESTART_HARD
value|1
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_RESTART_SOFT
value|0
end_define

begin_decl_stmt
name|int
name|scsi_low_restart
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
name|int
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Scsi utility fucntions  */
end_comment

begin_comment
comment|/* print current status */
end_comment

begin_decl_stmt
name|void
name|scsi_low_print
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* timeout utility (only in used scsi_low_pisa) */
end_comment

begin_decl_stmt
name|void
name|scsi_low_timeout
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SCSI2_RESET_DELAY
value|5000000
end_define

begin_define
define|#
directive|define
name|TWIDDLEWAIT
value|10000
end_define

begin_comment
comment|/* bus reset utility */
end_comment

begin_decl_stmt
name|void
name|scsi_low_bus_reset
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************************************************  * Inline utility  *************************************************/
end_comment

begin_decl_stmt
specifier|static
name|__inline
name|u_int8_t
name|scsi_low_identify
name|__P
argument_list|(
operator|(
expr|struct
name|targ_info
operator|*
name|ti
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|void
name|scsi_low_attention
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|int
name|scsi_low_is_msgout_continue
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
specifier|static
name|__inline
name|int
name|scsi_low_assert_msg
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|,
name|u_int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|void
name|scsi_low_arbit_win
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|int
name|scsi_low_is_msgout_continue
parameter_list|(
name|ti
parameter_list|)
name|struct
name|targ_info
modifier|*
name|ti
decl_stmt|;
block|{
return|return
operator|(
name|ti
operator|->
name|ti_msgflags
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int8_t
name|scsi_low_identify
parameter_list|(
name|ti
parameter_list|)
name|struct
name|targ_info
modifier|*
name|ti
decl_stmt|;
block|{
name|u_int8_t
name|msg
decl_stmt|;
name|struct
name|lun_info
modifier|*
name|li
init|=
name|ti
operator|->
name|ti_li
decl_stmt|;
name|msg
operator|=
operator|(
name|li
operator|->
name|li_flags
operator|&
name|SCSI_LOW_DISC
operator|)
condition|?
literal|0xc0
else|:
literal|0x80
expr_stmt|;
name|msg
operator||=
name|li
operator|->
name|li_lun
expr_stmt|;
return|return
name|msg
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ID_MSG_SETUP
parameter_list|(
name|ti
parameter_list|)
value|(scsi_low_identify(ti))
end_define

begin_function
specifier|static
name|__inline
name|void
name|scsi_low_attention
parameter_list|(
name|slp
parameter_list|,
name|ti
parameter_list|)
name|struct
name|scsi_low_softc
modifier|*
name|slp
decl_stmt|;
name|struct
name|targ_info
modifier|*
name|ti
decl_stmt|;
block|{
call|(
modifier|*
name|slp
operator|->
name|sl_funcs
operator|->
name|scsi_low_attention
call|)
argument_list|(
name|slp
argument_list|)
expr_stmt|;
name|SCSI_LOW_TARGET_ASSERT_ATN
argument_list|(
name|slp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|scsi_low_assert_msg
parameter_list|(
name|slp
parameter_list|,
name|ti
parameter_list|,
name|msg
parameter_list|,
name|now
parameter_list|)
name|struct
name|scsi_low_softc
modifier|*
name|slp
decl_stmt|;
name|struct
name|targ_info
modifier|*
name|ti
decl_stmt|;
name|u_int
name|msg
decl_stmt|;
name|int
name|now
decl_stmt|;
block|{
name|ti
operator|->
name|ti_msgflags
operator||=
name|msg
expr_stmt|;
if|if
condition|(
name|now
operator|!=
literal|0
condition|)
name|scsi_low_attention
argument_list|(
name|slp
argument_list|,
name|ti
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|scsi_low_arbit_win
parameter_list|(
name|slp
parameter_list|,
name|ti
parameter_list|)
name|struct
name|scsi_low_softc
modifier|*
name|slp
decl_stmt|;
name|struct
name|targ_info
modifier|*
name|ti
decl_stmt|;
block|{
name|slp
operator|->
name|sl_selid
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/*************************************************  * Message out defs  *************************************************/
end_comment

begin_comment
comment|/* XXX: use scsi_message.h */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_undef
undef|#
directive|undef
name|MSG_IDENTIFY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MSG_IDENTIFY
value|0x80
end_define

begin_define
define|#
directive|define
name|OS_DEPEND
parameter_list|(
name|s
parameter_list|)
value|(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SCSI_LOW_H_ */
end_comment

end_unit

