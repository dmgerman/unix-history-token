begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)mscpvar.h	7.2 (Berkeley) 7/9/88  */
end_comment

begin_comment
comment|/*  * MSCP generic driver configuration  */
end_comment

begin_comment
comment|/*  * Enabling MSCP_PARANOIA makes the response code perform various checks  * on the hardware.  (Right now it verifies only the buffer pointer in  * mscp_cmdref.)  *  * Enabling AVOID_EMULEX_BUG selects an alternative method of identifying  * transfers in progress, which gets around a rather peculiar bug in the  * SC41/MS.  Enabling MSCP_PARANOIA instead should work, but will cause  * `extra' Unibus resets.  *  * Either of these flags can simply be included as an `options' line in  * your configuration file.  */
end_comment

begin_comment
comment|/* #define MSCP_PARANOIA */
end_comment

begin_comment
comment|/* #define AVOID_EMULEX_BUG */
end_comment

begin_comment
comment|/*  * Per driver information.  *  * md_ndpc sets the maximum unit number allowed in response packets.  * md_nunits is the number of drives attached to all controllers.  * md_unitshift is the divisor for converting a minor device number  * to a unit index for the device queues in md_utab.  *  * The routines are called from the generic response dispatcher.  * THE FOLLOWING IS OUT OF DATE  * The first three (dgram, ctlrdone, and unconf) get passed a pointer  * to the uba_ctlr and to the packet; the rest get a pointer to the  * uba_device and to the packet (`um, mp' and `ui, mp' respectively).  * The routines unconf, online, gotstatus, and ioerr are functions  * and should return one of the values given below.  In addition,  * the ioerr and bb routines get a third argument, `bp': a pointer  * to the buffer describing the transfer in error.  * END OUT OF DATE  */
end_comment

begin_struct
struct|struct
name|mscp_driver
block|{
name|int
name|md_ndpc
decl_stmt|;
comment|/* number of drives per ctlr */
name|int
name|md_nunits
decl_stmt|;
comment|/* total number drives (all ctlrs) */
name|int
name|md_unitshift
decl_stmt|;
comment|/* device number to unit:>> count */
name|struct
name|buf
modifier|*
name|md_utab
decl_stmt|;
comment|/* pointer to device queues */
name|struct
name|disklabel
modifier|*
name|md_lab
decl_stmt|;
comment|/* pointer to devicee disklabels */
name|struct
name|uba_device
modifier|*
modifier|*
name|md_dinfo
decl_stmt|;
comment|/* pointer to device info */
name|int
function_decl|(
modifier|*
name|md_dgram
function_decl|)
parameter_list|()
function_decl|;
comment|/* error datagram */
name|int
function_decl|(
modifier|*
name|md_ctlrdone
function_decl|)
parameter_list|()
function_decl|;
comment|/* controller operation complete */
name|int
function_decl|(
modifier|*
name|md_unconf
function_decl|)
parameter_list|()
function_decl|;
comment|/* response from unconfigured drive */
name|int
function_decl|(
modifier|*
name|md_iodone
function_decl|)
parameter_list|()
function_decl|;
comment|/* normal I/O is done */
name|int
function_decl|(
modifier|*
name|md_online
function_decl|)
parameter_list|()
function_decl|;
comment|/* drive on line */
name|int
function_decl|(
modifier|*
name|md_gotstatus
function_decl|)
parameter_list|()
function_decl|;
comment|/* got unit status */
name|int
function_decl|(
modifier|*
name|md_replace
function_decl|)
parameter_list|()
function_decl|;
comment|/* replace done */
name|int
function_decl|(
modifier|*
name|md_ioerr
function_decl|)
parameter_list|()
function_decl|;
comment|/* read or write failed */
name|int
function_decl|(
modifier|*
name|md_bb
function_decl|)
parameter_list|()
function_decl|;
comment|/* B_BAD io done */
name|char
modifier|*
name|md_mname
decl_stmt|;
comment|/* name of controllers */
name|char
modifier|*
name|md_dname
decl_stmt|;
comment|/* name of drives */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Return values from functions.  * MSCP_RESTARTED is peculiar to I/O errors.  */
end_comment

begin_define
define|#
directive|define
name|MSCP_DONE
value|0
end_define

begin_comment
comment|/* all ok */
end_comment

begin_define
define|#
directive|define
name|MSCP_FAILED
value|1
end_define

begin_comment
comment|/* no go */
end_comment

begin_define
define|#
directive|define
name|MSCP_RESTARTED
value|2
end_define

begin_comment
comment|/* transfer restarted */
end_comment

begin_comment
comment|/*  * Ring information, per ring (one each for commands and responses).  */
end_comment

begin_struct
struct|struct
name|mscp_ri
block|{
name|int
name|mri_size
decl_stmt|;
comment|/* ring size */
name|int
name|mri_next
decl_stmt|;
comment|/* next (expected|free) */
name|long
modifier|*
name|mri_desc
decl_stmt|;
comment|/* base address of descriptors */
name|struct
name|mscp
modifier|*
name|mri_ring
decl_stmt|;
comment|/* base address of packets */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per device information.  *  * mi_ip is a pointer to the inverting pointers (things that get `ui's  * given unit numbers) FOR THIS CONTROLLER (NOT the whole set!).  *  * mi_wtab holds a queue of those transfers that were started but have  * not yet finished.  Other Unibus drivers do not need this as they hand  * out requests one at a time.  MSCP devices, however, take a slew of  * requests and pick their own order to execute them.  This means that  * we have to have a place to move transfers that were given to the  * controller, so we can tell those apart from those that have not yet  * been handed out; mi_wtab is that place.  */
end_comment

begin_struct
struct|struct
name|mscp_info
block|{
name|struct
name|mscp_driver
modifier|*
name|mi_md
decl_stmt|;
comment|/* pointer to driver info */
name|int
name|mi_ctlr
decl_stmt|;
comment|/* controller index */
name|struct
name|buf
modifier|*
name|mi_tab
decl_stmt|;
comment|/* pointer to ctlr's drive queue */
name|struct
name|uba_device
modifier|*
modifier|*
name|mi_ip
decl_stmt|;
comment|/* pointer to inverting pointers */
name|struct
name|mscp_ri
name|mi_cmd
decl_stmt|;
comment|/* MSCP command ring info */
name|struct
name|mscp_ri
name|mi_rsp
decl_stmt|;
comment|/* MSCP response ring info */
name|short
name|mi_credits
decl_stmt|;
comment|/* transfer credits */
name|char
name|mi_wantcmd
decl_stmt|;
comment|/* waiting for command packet */
name|char
name|mi_wantcredits
decl_stmt|;
comment|/* waiting for transfer credits */
name|struct
name|buf
name|mi_wtab
decl_stmt|;
comment|/* transfer wait queue */
ifdef|#
directive|ifdef
name|AVOID_EMULEX_BUG
define|#
directive|define
name|AEB_MAX_BP
value|32
comment|/* max pend xfers (power of 2) XXX */
name|struct
name|buf
modifier|*
name|mi_bp
index|[
name|AEB_MAX_BP
index|]
decl_stmt|;
comment|/* xfer no. to buffer */
name|u_int
name|mi_nextbp
decl_stmt|;
comment|/* generates unique xfer no's */
name|int
name|mi_ok
decl_stmt|;
comment|/* for error rate statistics */
endif|#
directive|endif
endif|AVOID_EMULEX_BUG
block|}
struct|;
end_struct

begin_comment
comment|/*  * We have run out of credits when mi_credits is<= MSCP_MINCREDITS.  * It is still possible to issue one command in this case, but it must  * not be a data transfer.  E.g., `get command status' or `abort command'  * is legal, while `read' is not.  */
end_comment

begin_define
define|#
directive|define
name|MSCP_MINCREDITS
value|1
end_define

begin_comment
comment|/*  * Flags for mscp_getcp().  */
end_comment

begin_define
define|#
directive|define
name|MSCP_WAIT
value|1
end_define

begin_define
define|#
directive|define
name|MSCP_DONTWAIT
value|0
end_define

begin_function_decl
name|struct
name|mscp
modifier|*
name|mscp_getcp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get a command packet */
end_comment

begin_comment
comment|/*  * Unit flags  */
end_comment

begin_define
define|#
directive|define
name|UNIT_ONLINE
value|0x01
end_define

begin_comment
comment|/* drive is on line */
end_comment

begin_define
define|#
directive|define
name|UNIT_HAVESTATUS
value|0x02
end_define

begin_comment
comment|/* got unit status */
end_comment

begin_define
define|#
directive|define
name|UNIT_REQUEUE
value|0x04
end_define

begin_comment
comment|/* requeue after response */
end_comment

begin_comment
comment|/*  * Handle a command ring transition: wake up sleepers for command packets.  * This is too simple to bother with a function call.  */
end_comment

begin_define
define|#
directive|define
name|MSCP_DOCMD
parameter_list|(
name|mi
parameter_list|)
value|{ \ 	if ((mi)->mi_wantcmd) { \ 		(mi)->mi_wantcmd = 0; \ 		wakeup((caddr_t)&(mi)->mi_wantcmd); \ 	} \ }
end_define

begin_comment
comment|/*  * The following macro appends a buffer to a drive queue or a drive to  * a controller queue, given the name of the forward link.  Use as  * `APPEND(dp,&um->um_tab, b_forw)' or `APPEND(bp, dp, av_forw)',  * where `bp' is a transfer request, `dp' is a drive queue, and `um_tab'  * is a controller queue.  (That is, the forward link for controller  * queues is `b_forw'; for drive queues, it is `av_forw'.)  */
end_comment

begin_define
define|#
directive|define
name|APPEND
parameter_list|(
name|bp
parameter_list|,
name|queue
parameter_list|,
name|link
parameter_list|)
value|{ \ 	(bp)->link = NULL; \ 	if ((queue)->b_actf == NULL) \ 		(queue)->b_actf = (bp); \ 	else \ 		(queue)->b_actl->link = (bp); \ 	(queue)->b_actl = (bp); \ }
end_define

end_unit

