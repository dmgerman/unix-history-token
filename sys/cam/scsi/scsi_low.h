begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: scsi_low.h,v 1.24.10.5 2001/06/26 07:31:46 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_LOW_DIAGNOSTIC
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_ALT_QTAG_ALLOCATE
end_define

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1995, 1996, 1997, 1998, 1999, 2000, 2001  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1995, 1996, 1997, 1998, 1999, 2000, 2001  *	Naofumi HONDA. All rights reserved.  *  * [Ported for FreeBSD CAM]  *  Copyright (c) 2000, 2001  *      MITSUNAGA Noriaki, NOKUBI Hirotaka and TAKAHASHI Yoshihiro.  *      All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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

begin_comment
comment|/*================================================  * Scsi low OSDEP   * (All os depend structures should be here!)  ================================================*/
end_comment

begin_comment
comment|/******** interface ******************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|SCSI_LOW_INTERFACE_XS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|SCSI_LOW_INTERFACE_CAM
end_define

begin_define
define|#
directive|define
name|CAM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/******** includes *******************************/
end_comment

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

begin_include
include|#
directive|include
file|<dev/isa/ccbque.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

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

begin_include
include|#
directive|include
file|<i386/isa/ccbque.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/******** functions macro ************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|SCSI_LOW_DEBUGGER
parameter_list|(
name|dev
parameter_list|)
value|Debugger()
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_DELAY
parameter_list|(
name|mu
parameter_list|)
value|delay((mu))
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_SPLSCSI
value|splbio
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_BZERO
parameter_list|(
name|pt
parameter_list|,
name|size
parameter_list|)
value|memset((pt), 0, (size))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

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

begin_define
define|#
directive|define
name|SCSI_LOW_DEBUGGER
parameter_list|(
name|dev
parameter_list|)
value|Debugger((dev))
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_DELAY
parameter_list|(
name|mu
parameter_list|)
value|DELAY((mu))
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_SPLSCSI
value|splcam
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_BZERO
parameter_list|(
name|pt
parameter_list|,
name|size
parameter_list|)
value|bzero((pt), (size))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/******** os depend interface structures **********/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|scsipi_sense_data
name|scsi_low_osdep_sense_data_t
typedef|;
end_typedef

begin_struct
struct|struct
name|scsi_low_osdep_interface
block|{
name|struct
name|device
name|si_dev
decl_stmt|;
name|struct
name|scsipi_link
modifier|*
name|si_splp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_low_osdep_targ_interface
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|scsi_low_osdep_lun_interface
block|{
name|u_int
name|sloi_quirks
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|scsi_sense_data
name|scsi_low_osdep_sense_data_t
typedef|;
end_typedef

begin_struct
struct|struct
name|scsi_low_osdep_interface
block|{
name|DEVPORT_DEVICE
name|si_dev
decl_stmt|;
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
name|int
name|si_poll_count
decl_stmt|;
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_low_osdep_targ_interface
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|scsi_low_osdep_lun_interface
block|{ }
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/******** os depend interface functions *************/
end_comment

begin_struct_decl
struct_decl|struct
name|slccb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|scsi_low_softc
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|SCSI_LOW_TIMEOUT_STOP
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_TIMEOUT_START
value|1
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_TIMEOUT_CH_IO
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_TIMEOUT_CH_ENGAGE
value|1
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_TIMEOUT_CH_RECOVER
value|2
end_define

begin_struct
struct|struct
name|scsi_low_osdep_funcs
block|{
name|int
argument_list|(
argument|*scsi_low_osdep_attach
argument_list|)
block|\
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scsi_low_osdep_world_start
argument_list|)
block|\
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scsi_low_osdep_dettach
argument_list|)
block|\
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scsi_low_osdep_ccb_setup
argument_list|)
block|\
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|slccb
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scsi_low_osdep_done
argument_list|)
block|\
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|slccb
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*scsi_low_osdep_timeout
argument_list|)
block|\
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
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*================================================  * Generic Scsi Low header file   * (All os depend structures should be above!)  ================================================*/
end_comment

begin_comment
comment|/*************************************************  * Scsi low definitions  *************************************************/
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
value|128
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_MAX_RETRY
value|3
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_MAX_SELECTION_RETRY
value|10
end_define

begin_comment
comment|/* timeout control macro */
end_comment

begin_define
define|#
directive|define
name|SCSI_LOW_TIMEOUT_HZ
value|10
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_MIN_TOUT
value|12
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_TIMEOUT_CHECK_INTERVAL
value|1
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

begin_define
define|#
directive|define
name|SCSI2_RESET_DELAY
value|5000000
end_define

begin_comment
comment|/* msg */
end_comment

begin_define
define|#
directive|define
name|SCSI_LOW_MAX_MSGLEN
value|32
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_MSG_LOG_DATALEN
value|8
end_define

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
name|u_int8_t
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
name|u_int8_t
name|scp_status
decl_stmt|;
name|u_int8_t
name|scp_spare
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

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
name|void
modifier|*
name|osdep
decl_stmt|;
comment|/* os depend structure */
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
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* io bufs */
name|scsi_low_tag_t
name|ccb_tag
decl_stmt|;
comment|/* effective qtag */
name|scsi_low_tag_t
name|ccb_otag
decl_stmt|;
comment|/* allocated qtag */
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
name|int
name|ccb_datalen
decl_stmt|;
comment|/* transfered data counter */
comment|/***************************************** 	 * Msgout  	 *****************************************/
name|u_int
name|ccb_msgoutflag
decl_stmt|;
name|u_int
name|ccb_omsgoutflag
decl_stmt|;
comment|/***************************************** 	 * Error or Timeout counters 	 *****************************************/
name|u_int
name|ccb_flags
decl_stmt|;
define|#
directive|define
name|CCB_INTERNAL
value|0x0001
define|#
directive|define
name|CCB_SENSE
value|0x0002
define|#
directive|define
name|CCB_CLEARQ
value|0x0004
define|#
directive|define
name|CCB_DISCQ
value|0x0008
define|#
directive|define
name|CCB_STARTQ
value|0x0010
define|#
directive|define
name|CCB_POLLED
value|0x0100
comment|/* polling ccb */
define|#
directive|define
name|CCB_NORETRY
value|0x0200
comment|/* do NOT retry */
define|#
directive|define
name|CCB_AUTOSENSE
value|0x0400
comment|/* do a sence after CA */
define|#
directive|define
name|CCB_URGENT
value|0x0800
comment|/* an urgent ccb */
define|#
directive|define
name|CCB_NOSDONE
value|0x1000
comment|/* do not call an os done routine */
define|#
directive|define
name|CCB_SCSIIO
value|0x2000
comment|/* a normal scsi io coming from upper layer */
define|#
directive|define
name|CCB_SILENT
value|0x4000
comment|/* no terminate messages */
name|u_int
name|ccb_error
decl_stmt|;
name|int
name|ccb_rcnt
decl_stmt|;
comment|/* retry counter */
name|int
name|ccb_selrcnt
decl_stmt|;
comment|/* selection retry counter */
name|int
name|ccb_tc
decl_stmt|;
comment|/* timer counter */
name|int
name|ccb_tcmax
decl_stmt|;
comment|/* max timeout */
comment|/***************************************** 	 * Sense data buffer 	 *****************************************/
name|u_int8_t
name|ccb_scsi_cmd
index|[
literal|12
index|]
decl_stmt|;
name|scsi_low_osdep_sense_data_t
name|ccb_sense
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************  * Slccb functions  *************************************************/
end_comment

begin_macro
name|GENERIC_CCB_ASSERT
argument_list|(
argument|scsi_low
argument_list|,
argument|slccb
argument_list|)
end_macro

begin_comment
comment|/*************************************************  * Target and Lun structures  *************************************************/
end_comment

begin_struct_decl
struct_decl|struct
name|scsi_low_softc
struct_decl|;
end_struct_decl

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|scsi_low_softc_tab
argument_list|,
name|scsi_low_softc
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|struct
name|scsi_low_osdep_lun_interface
name|li_sloi
decl_stmt|;
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
name|struct
name|slccbtab
name|li_discq
decl_stmt|;
comment|/* disconnect queue */
comment|/* 	 * qtag control 	 */
name|int
name|li_maxnexus
decl_stmt|;
name|int
name|li_maxnqio
decl_stmt|;
name|int
name|li_nqio
decl_stmt|;
name|int
name|li_disc
decl_stmt|;
define|#
directive|define
name|SCSI_LOW_MAXNEXUS
value|(sizeof(u_int) * NBBY)
name|u_int
name|li_qtagbits
decl_stmt|;
ifdef|#
directive|ifdef
name|SCSI_LOW_ALT_QTAG_ALLOCATE
name|u_int8_t
name|li_qtagarray
index|[
name|SCSI_LOW_MAXNEXUS
index|]
decl_stmt|;
name|u_int
name|li_qd
decl_stmt|;
endif|#
directive|endif
comment|/* SCSI_LOW_ALT_QTAG_ALLOCATE */
define|#
directive|define
name|SCSI_LOW_QFLAG_CA_QCLEAR
value|0x01
name|u_int
name|li_qflags
decl_stmt|;
comment|/* 	 * lun state 	 */
define|#
directive|define
name|SCSI_LOW_LUN_SLEEP
value|0x00
define|#
directive|define
name|SCSI_LOW_LUN_START
value|0x01
define|#
directive|define
name|SCSI_LOW_LUN_INQ
value|0x02
define|#
directive|define
name|SCSI_LOW_LUN_MODEQ
value|0x03
define|#
directive|define
name|SCSI_LOW_LUN_OK
value|0x04
name|u_int
name|li_state
decl_stmt|;
comment|/* target lun state */
comment|/* 	 * lun control flags  	 */
name|u_int
name|li_flags_valid
decl_stmt|;
comment|/* valid flags */
define|#
directive|define
name|SCSI_LOW_LUN_FLAGS_USER_VALID
value|0x0001
define|#
directive|define
name|SCSI_LOW_LUN_FLAGS_DISK_VALID
value|0x0002
define|#
directive|define
name|SCSI_LOW_LUN_FLAGS_QUIRKS_VALID
value|0x0004
define|#
directive|define
name|SCSI_LOW_LUN_FLAGS_ALL_VALID
define|\
value|(SCSI_LOW_LUN_FLAGS_USER_VALID | \ 	 SCSI_LOW_LUN_FLAGS_DISK_VALID | SCSI_LOW_LUN_FLAGS_QUIRKS_VALID)
name|u_int
name|li_flags
decl_stmt|;
comment|/* real lun control flags */
name|u_int
name|li_cfgflags
decl_stmt|;
comment|/* lun control flags given by user */
name|u_int
name|li_diskflags
decl_stmt|;
comment|/* lun control flags given by hardware info */
name|u_int
name|li_quirks
decl_stmt|;
comment|/* lun control flags given by upper layer */
comment|/* inq buffer */
struct|struct
name|scsi_low_inq_data
block|{
name|u_int8_t
name|sd_type
decl_stmt|;
name|u_int8_t
name|sd_sp1
decl_stmt|;
name|u_int8_t
name|sd_version
decl_stmt|;
name|u_int8_t
name|sd_resp
decl_stmt|;
name|u_int8_t
name|sd_len
decl_stmt|;
name|u_int8_t
name|sd_sp2
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|sd_support
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|li_inq
struct|;
comment|/* modeq buffer */
struct|struct
name|scsi_low_mode_sense_data
block|{
name|u_int8_t
name|sms_header
index|[
literal|4
index|]
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|cmp_page
decl_stmt|;
name|u_int8_t
name|cmp_length
decl_stmt|;
name|u_int8_t
name|cmp_rlec
decl_stmt|;
name|u_int8_t
name|cmp_qc
decl_stmt|;
name|u_int8_t
name|cmp_eca
decl_stmt|;
name|u_int8_t
name|cmp_spare
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|sms_cmp
struct|;
block|}
name|li_sms
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_low_msg_log
block|{
name|int
name|slml_ptr
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|msg
index|[
literal|2
index|]
decl_stmt|;
block|}
name|slml_msg
index|[
name|SCSI_LOW_MSG_LOG_DATALEN
index|]
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|targ_info
block|{
name|struct
name|scsi_low_osdep_targ_interface
name|ti_slti
decl_stmt|;
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
comment|/* 	 * total disconnected nexus 	 */
name|int
name|ti_disc
decl_stmt|;
comment|/* 	 * Scsi phase control  	 */
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
comment|/* 	 * Msg in  	 */
name|u_int
name|ti_msginptr
decl_stmt|;
comment|/* msgin ptr */
name|u_int
name|ti_msginlen
decl_stmt|;
comment|/* expected msg length */
name|int
name|ti_msgin_parity_error
decl_stmt|;
comment|/* parity error detected */
name|u_int8_t
name|ti_msgin
index|[
name|SCSI_LOW_MAX_MSGLEN
index|]
decl_stmt|;
comment|/* msgin buffer */
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
name|SCSI_LOW_MSG_REJECT
value|0x00000002
define|#
directive|define
name|SCSI_LOW_MSG_PARITY
value|0x00000004
define|#
directive|define
name|SCSI_LOW_MSG_ERROR
value|0x00000008
define|#
directive|define
name|SCSI_LOW_MSG_IDENTIFY
value|0x00000010
define|#
directive|define
name|SCSI_LOW_MSG_ABORT
value|0x00000020
define|#
directive|define
name|SCSI_LOW_MSG_TERMIO
value|0x00000040
define|#
directive|define
name|SCSI_LOW_MSG_SIMPLE_QTAG
value|0x00000080
define|#
directive|define
name|SCSI_LOW_MSG_ORDERED_QTAG
value|0x00000100
define|#
directive|define
name|SCSI_LOW_MSG_HEAD_QTAG
value|0x00000200
define|#
directive|define
name|SCSI_LOW_MSG_ABORT_QTAG
value|0x00000400
define|#
directive|define
name|SCSI_LOW_MSG_CLEAR_QTAG
value|0x00000800
define|#
directive|define
name|SCSI_LOW_MSG_WIDE
value|0x00001000
define|#
directive|define
name|SCSI_LOW_MSG_SYNCH
value|0x00002000
define|#
directive|define
name|SCSI_LOW_MSG_NOOP
value|0x00004000
define|#
directive|define
name|SCSI_LOW_MSG_LAST
value|0x00008000
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
comment|/* 	 * target initialize msgout   	 */
name|u_int
name|ti_setup_msg
decl_stmt|;
comment|/* setup msgout requests */
name|u_int
name|ti_setup_msg_done
decl_stmt|;
comment|/* 	 * synch and wide data info  	 */
name|u_int
name|ti_flags_valid
decl_stmt|;
comment|/* valid flags */
define|#
directive|define
name|SCSI_LOW_TARG_FLAGS_USER_VALID
value|0x0001
define|#
directive|define
name|SCSI_LOW_TARG_FLAGS_DISK_VALID
value|0x0002
define|#
directive|define
name|SCSI_LOW_TARG_FLAGS_QUIRKS_VALID
value|0x0004
define|#
directive|define
name|SCSI_LOW_TARG_FLAGS_ALL_VALID
define|\
value|(SCSI_LOW_TARG_FLAGS_USER_VALID | \ 	 SCSI_LOW_TARG_FLAGS_DISK_VALID | SCSI_LOW_TARG_FLAGS_QUIRKS_VALID)
name|u_int
name|ti_diskflags
decl_stmt|;
comment|/* given target disk flags */
name|u_int
name|ti_quirks
decl_stmt|;
comment|/* given target quirk */
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
name|ti_osynch
struct|,
name|ti_maxsynch
struct|;
comment|/* synch data */
define|#
directive|define
name|SCSI_LOW_BUS_WIDTH_8
value|0
define|#
directive|define
name|SCSI_LOW_BUS_WIDTH_16
value|1
define|#
directive|define
name|SCSI_LOW_BUS_WIDTH_32
value|2
name|u_int
name|ti_owidth
decl_stmt|,
name|ti_width
decl_stmt|;
comment|/* 	 * lun info size.  	 */
name|int
name|ti_lunsize
decl_stmt|;
ifdef|#
directive|ifdef
name|SCSI_LOW_DIAGNOSTIC
name|struct
name|scsi_low_msg_log
name|ti_log_msgout
decl_stmt|;
name|struct
name|scsi_low_msg_log
name|ti_log_msgin
decl_stmt|;
endif|#
directive|endif
comment|/* SCSI_LOW_DIAGNOSTIC */
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

begin_struct_decl
struct_decl|struct
name|proc
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
name|SCSI_LOW_INFO_ALLOC
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_INFO_REVOKE
value|1
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_INFO_DEALLOC
value|2
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_POWDOWN
value|1
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_ENGAGE
value|2
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
value|(int (*) __P((sc_low_t, struct targ_info *, int)))
end_define

begin_define
define|#
directive|define
name|SC_LOW_LUN_INIT_T
value|(int (*) __P((sc_low_t, struct targ_info *, struct lun_info *, int)))
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
value|(int (*) __P((sc_low_t)))
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

begin_define
define|#
directive|define
name|SC_LOW_TIMEOUT_T
value|(int (*) __P((sc_low_t)))
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
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scsi_low_lun_init
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
expr|struct
name|lun_info
operator|*
operator|,
name|int
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
argument|*scsi_low_establish_lun_nexus
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
argument|*scsi_low_establish_ccb_nexus
argument_list|)
name|__P
argument_list|(
operator|(
name|sc_low_t
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
argument|*scsi_low_timeout
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
name|int
argument_list|(
argument|*scsi_low_ioctl
argument_list|)
name|__P
argument_list|(
operator|(
name|sc_low_t
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_low_softc
block|{
comment|/* os depend structure */
name|struct
name|scsi_low_osdep_interface
name|sl_si
decl_stmt|;
define|#
directive|define
name|sl_dev
value|sl_si.si_dev
name|struct
name|scsi_low_osdep_funcs
modifier|*
name|sl_osdep_fp
decl_stmt|;
name|u_char
name|sl_xname
index|[
literal|16
index|]
decl_stmt|;
comment|/* our chain */
name|LIST_ENTRY
argument_list|(
argument|scsi_low_softc
argument_list|)
name|sl_chain
expr_stmt|;
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
comment|/* current active T_L_Q nexus */
name|struct
name|targ_info
modifier|*
name|sl_Tnexus
decl_stmt|;
comment|/* Target nexus */
name|struct
name|lun_info
modifier|*
name|sl_Lnexus
decl_stmt|;
comment|/* Lun nexus */
name|struct
name|slccb
modifier|*
name|sl_Qnexus
decl_stmt|;
comment|/* Qtag nexus */
name|int
name|sl_nexus_call
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
name|int
name|sl_timeout_count
decl_stmt|;
comment|/* selection& total num disconnect targets */
name|int
name|sl_nio
decl_stmt|;
name|int
name|sl_disc
decl_stmt|;
name|int
name|sl_retry_sel
decl_stmt|;
name|struct
name|slccb
modifier|*
name|sl_selid
decl_stmt|;
comment|/* attention */
name|int
name|sl_atten
decl_stmt|;
comment|/* ATN asserted */
name|int
name|sl_clear_atten
decl_stmt|;
comment|/* negate ATN required */
comment|/* scsi phase suggested by scsi msg */
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
define|#
directive|define
name|MSGPH_ABORT
value|0x03
comment|/* abort seq */
define|#
directive|define
name|MSGPH_TERM
value|0x04
comment|/* current io terminate */
define|#
directive|define
name|MSGPH_LCTERM
value|0x05
comment|/* cmd link terminated */
define|#
directive|define
name|MSGPH_RESET
value|0x06
comment|/* reset target */
comment|/* error */
name|u_int
name|sl_error
decl_stmt|;
comment|/* error flags */
define|#
directive|define
name|FATALIO
value|0x0001
comment|/* generic io error& retry io */
define|#
directive|define
name|ABORTIO
value|0x0002
comment|/* generic io error& terminate io */
define|#
directive|define
name|TIMEOUTIO
value|0x0004
comment|/* watch dog timeout */
define|#
directive|define
name|SELTIMEOUTIO
value|0x0008
comment|/* selection timeout */
define|#
directive|define
name|PDMAERR
value|0x0010
comment|/* dma xfer error */
define|#
directive|define
name|MSGERR
value|0x0020
comment|/* msgsys error */
define|#
directive|define
name|PARITYERR
value|0x0040
comment|/* parity error */
define|#
directive|define
name|BUSYERR
value|0x0080
comment|/* target busy error */
define|#
directive|define
name|STATERR
value|0x0100
comment|/* status error */
define|#
directive|define
name|UACAERR
value|0x0200
comment|/* target CA state, no sense check */
define|#
directive|define
name|SENSEIO
value|0x1000
comment|/* cmd not excuted but sense data ok */
define|#
directive|define
name|SENSEERR
value|0x2000
comment|/* cmd not excuted and sense data bad */
define|#
directive|define
name|UBFERR
value|0x4000
comment|/* unexpected bus free */
define|#
directive|define
name|PENDINGIO
value|0x8000
comment|/* ccb start not yet */
define|#
directive|define
name|SCSI_LOW_ERRORBITS
value|"\020\017ubferr\016senseerr\015senseio\012uacaerr\011staterr\010busy\007parity\006msgerr\005pdmaerr\004seltimeout\003timeout\002abort\001fatal"
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
value|0x0001
define|#
directive|define
name|HW_RESUME
value|0x0002
define|#
directive|define
name|HW_PDMASTART
value|0x0004
define|#
directive|define
name|HW_INACTIVE
value|0x0008
define|#
directive|define
name|HW_POWERCTRL
value|0x0010
define|#
directive|define
name|HW_INITIALIZING
value|0x0020
define|#
directive|define
name|HW_READ_PADDING
value|0x1000
define|#
directive|define
name|HW_WRITE_PADDING
value|0x2000
name|u_int
name|sl_cfgflags
decl_stmt|;
define|#
directive|define
name|CFG_NODISC
value|0x0001
define|#
directive|define
name|CFG_NOPARITY
value|0x0002
define|#
directive|define
name|CFG_NOATTEN
value|0x0004
define|#
directive|define
name|CFG_ASYNC
value|0x0008
define|#
directive|define
name|CFG_NOQTAG
value|0x0010
name|int
name|sl_show_result
decl_stmt|;
define|#
directive|define
name|SHOW_SYNCH_NEG
value|0x0001
define|#
directive|define
name|SHOW_WIDE_NEG
value|0x0002
define|#
directive|define
name|SHOW_CALCF_RES
value|0x0010
define|#
directive|define
name|SHOW_PROBE_RES
value|0x0020
define|#
directive|define
name|SHOW_ALL_NEG
value|-1
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
comment|/* targinfo size */
name|int
name|sl_targsize
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|i386
argument_list|)
operator|||
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
comment|/*   * Scsi low interface activate or deactivate functions  */
end_comment

begin_decl_stmt
name|int
name|scsi_low_is_busy
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

begin_decl_stmt
name|int
name|scsi_low_activate
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

begin_decl_stmt
name|int
name|scsi_low_deactivate
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
comment|/* bus idle phase (other initiators or targets release bus) */
end_comment

begin_decl_stmt
name|void
name|scsi_low_bus_idle
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
comment|/* arbitration and selection phase */
end_comment

begin_decl_stmt
name|void
name|scsi_low_arbit_fail
name|__P
argument_list|(
operator|(
expr|struct
name|scsi_low_softc
operator|*
operator|,
expr|struct
name|slccb
operator|*
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* msgout phase */
end_comment

begin_define
define|#
directive|define
name|SCSI_LOW_MSGOUT_INIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_MSGOUT_UNIFY
value|0x00000002
end_define

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
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* msgin phase */
end_comment

begin_define
define|#
directive|define
name|SCSI_LOW_DATA_PE
value|0x80000000
end_define

begin_decl_stmt
name|int
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
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statusin phase */
end_comment

begin_decl_stmt
specifier|static
name|__inline
name|int
name|scsi_low_statusin
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

begin_decl_stmt
specifier|static
name|__inline
name|void
name|scsi_low_data_finish
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
comment|/*************************************************  * Message macro defs  *************************************************/
end_comment

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
value|{							\ 	(ti)->ti_ophase = ti->ti_phase;			\ 	(ti)->ti_phase = (phase);			\ }
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
name|SCSI_LOW_ASSERT_ATN
parameter_list|(
name|slp
parameter_list|)
define|\
value|{							\ 	(slp)->sl_atten = 1;				\ }
end_define

begin_define
define|#
directive|define
name|SCSI_LOW_DEASSERT_ATN
parameter_list|(
name|slp
parameter_list|)
define|\
value|{							\ 	(slp)->sl_atten = 0;				\ }
end_define

begin_comment
comment|/*************************************************  * Inline functions  *************************************************/
end_comment

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
operator|,
name|u_int
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
name|int
name|scsi_low_is_disconnect_ok
name|__P
argument_list|(
operator|(
expr|struct
name|slccb
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
parameter_list|,
name|mask
parameter_list|)
name|struct
name|targ_info
modifier|*
name|ti
decl_stmt|;
name|u_int
name|mask
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|ti
operator|->
name|ti_msgflags
operator|&
operator|(
operator|~
name|mask
operator|)
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|scsi_low_is_disconnect_ok
parameter_list|(
name|cb
parameter_list|)
name|struct
name|slccb
modifier|*
name|cb
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|cb
operator|->
name|li
operator|->
name|li_flags
operator|&
name|SCSI_LOW_DISC
operator|)
operator|!=
literal|0
operator|&&
operator|(
name|cb
operator|->
name|ccb_flags
operator|&
operator|(
name|CCB_SENSE
operator||
name|CCB_CLEARQ
operator|)
operator|)
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|scsi_low_attention
parameter_list|(
name|slp
parameter_list|)
name|struct
name|scsi_low_softc
modifier|*
name|slp
decl_stmt|;
block|{
if|if
condition|(
name|slp
operator|->
name|sl_atten
operator|!=
literal|0
condition|)
return|return;
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
name|SCSI_LOW_ASSERT_ATN
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
parameter_list|)
name|struct
name|scsi_low_softc
modifier|*
name|slp
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

begin_function
specifier|static
name|__inline
name|void
name|scsi_low_data_finish
parameter_list|(
name|slp
parameter_list|)
name|struct
name|scsi_low_softc
modifier|*
name|slp
decl_stmt|;
block|{
if|if
condition|(
name|slp
operator|->
name|sl_Qnexus
operator|!=
name|NULL
condition|)
block|{
name|slp
operator|->
name|sl_Qnexus
operator|->
name|ccb_datalen
operator|=
name|slp
operator|->
name|sl_scp
operator|.
name|scp_datalen
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|scsi_low_statusin
parameter_list|(
name|slp
parameter_list|,
name|ti
parameter_list|,
name|c
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
name|c
decl_stmt|;
block|{
name|slp
operator|->
name|sl_ph_count
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|c
operator|&
name|SCSI_LOW_DATA_PE
operator|)
operator|!=
literal|0
condition|)
block|{
name|scsi_low_assert_msg
argument_list|(
name|slp
argument_list|,
name|ti
argument_list|,
name|SCSI_LOW_MSG_ERROR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|EIO
return|;
block|}
name|slp
operator|->
name|sl_scp
operator|.
name|scp_status
operator|=
operator|(
name|u_int8_t
operator|)
name|c
expr_stmt|;
return|return
literal|0
return|;
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
name|ST_CMDTERM
value|0x22
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
name|ST_UNKNOWN
value|0xff
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

begin_define
define|#
directive|define
name|MSG_ABORT_QTAG
value|0x0d
end_define

begin_define
define|#
directive|define
name|MSG_CLEAR_QTAG
value|0x0e
end_define

begin_define
define|#
directive|define
name|MSG_TERM_IO
value|0x11
end_define

begin_define
define|#
directive|define
name|MSG_SIMPLE_QTAG
value|0x20
end_define

begin_define
define|#
directive|define
name|MSG_HEAD_QTAG
value|0x21
end_define

begin_define
define|#
directive|define
name|MSG_ORDERED_QTAG
value|0x22
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
name|MSG_IDENTIFY_DISCPRIV
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SCSI_LOW_H_ */
end_comment

end_unit

