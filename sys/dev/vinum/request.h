begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $Id: request.h,v 1.19 2000/11/24 03:41:51 grog Exp grog $  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Information needed to set up a transfer */
end_comment

begin_enum
enum|enum
name|xferinfo
block|{
name|XFR_NORMAL_READ
init|=
literal|1
block|,
name|XFR_NORMAL_WRITE
init|=
literal|2
block|,
comment|/* write request in normal mode */
name|XFR_RECOVERY_READ
init|=
literal|4
block|,
name|XFR_DEGRADED_WRITE
init|=
literal|8
block|,
name|XFR_PARITYLESS_WRITE
init|=
literal|0x10
block|,
name|XFR_NO_PARITY_STRIPE
init|=
literal|0x20
block|,
comment|/* parity stripe is not available */
name|XFR_DATA_BLOCK
init|=
literal|0x40
block|,
comment|/* data block in request */
name|XFR_PARITY_BLOCK
init|=
literal|0x80
block|,
comment|/* parity block in request */
name|XFR_BAD_SUBDISK
init|=
literal|0x100
block|,
comment|/* this subdisk is dead */
name|XFR_MALLOCED
init|=
literal|0x200
block|,
comment|/* this buffer is malloced */
if|#
directive|if
name|VINUMDEBUG
name|XFR_PHASE2
init|=
literal|0x800
block|,
comment|/* documentation only: 2nd phase write */
endif|#
directive|endif
name|XFR_REVIVECONFLICT
init|=
literal|0x1000
block|,
comment|/* possible conflict with a revive operation */
name|XFR_BUFLOCKED
init|=
literal|0x2000
block|,
comment|/* BUF_LOCK performed on this buffer */
comment|/* operations that need a parity block */
name|XFR_PARITYOP
init|=
operator|(
name|XFR_NORMAL_WRITE
operator||
name|XFR_RECOVERY_READ
operator||
name|XFR_DEGRADED_WRITE
operator|)
block|,
comment|/* operations that use the group parameters */
name|XFR_GROUPOP
init|=
operator|(
name|XFR_DEGRADED_WRITE
operator||
name|XFR_RECOVERY_READ
operator|)
block|,
comment|/* operations that that use the data parameters */
name|XFR_DATAOP
init|=
operator|(
name|XFR_NORMAL_READ
operator||
name|XFR_NORMAL_WRITE
operator||
name|XFR_PARITYLESS_WRITE
operator|)
block|,
comment|/* operations requiring read before write */
name|XFR_RBW
init|=
operator|(
name|XFR_NORMAL_WRITE
operator||
name|XFR_DEGRADED_WRITE
operator|)
block|,
comment|/* operations that need a malloced buffer */
name|XFR_NEEDS_MALLOC
init|=
operator|(
name|XFR_NORMAL_WRITE
operator||
name|XFR_RECOVERY_READ
operator||
name|XFR_DEGRADED_WRITE
operator|)
block|}
enum|;
end_enum

begin_comment
comment|/*  * Describe one low-level request, part of a  * high-level request.  This is an extended  * struct buf buffer, and the first element  * *must* be a struct buf.  We pass this  * structure to the I/O routines instead of a  * struct buf in order to be able to locate the  * high-level request when it completes.  *  * All offsets and lengths are in sectors.  */
end_comment

begin_struct
struct|struct
name|rqelement
block|{
name|struct
name|buf
name|b
decl_stmt|;
comment|/* buf structure */
name|struct
name|rqgroup
modifier|*
name|rqg
decl_stmt|;
comment|/* pointer to our group */
comment|/* Information about the transfer */
name|daddr_t
name|sdoffset
decl_stmt|;
comment|/* offset in subdisk */
name|int
name|useroffset
decl_stmt|;
comment|/* offset in user buffer of normal data */
comment|/*      * dataoffset and datalen refer to "individual" data      * transfers which involve only this drive (normal read,      * parityless write) and also degraded write.      *      * groupoffset and grouplen refer to the other "group"      * operations (normal write, recovery read) which involve      * more than one drive.  Both the offsets are relative to      * the start of the local buffer.      */
name|int
name|dataoffset
decl_stmt|;
comment|/* offset in buffer of the normal data */
name|int
name|groupoffset
decl_stmt|;
comment|/* offset in buffer of group data */
name|short
name|datalen
decl_stmt|;
comment|/* length of normal data (sectors) */
name|short
name|grouplen
decl_stmt|;
comment|/* length of group data (sectors) */
name|short
name|buflen
decl_stmt|;
comment|/* total buffer length to allocate */
name|short
name|flags
decl_stmt|;
comment|/* really enum xferinfo (see above) */
comment|/* Ways to find other components */
name|short
name|sdno
decl_stmt|;
comment|/* subdisk number */
name|short
name|driveno
decl_stmt|;
comment|/* drive number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A group of requests built to satisfy an I/O  * transfer on a single plex.  */
end_comment

begin_struct
struct|struct
name|rqgroup
block|{
name|struct
name|rqgroup
modifier|*
name|next
decl_stmt|;
comment|/* pointer to next group */
name|struct
name|request
modifier|*
name|rq
decl_stmt|;
comment|/* pointer to the request */
name|short
name|count
decl_stmt|;
comment|/* number of requests in this group */
name|short
name|active
decl_stmt|;
comment|/* and number active */
name|short
name|plexno
decl_stmt|;
comment|/* index of plex */
name|int
name|badsdno
decl_stmt|;
comment|/* index of bad subdisk or -1 */
name|enum
name|xferinfo
name|flags
decl_stmt|;
comment|/* description of transfer */
name|struct
name|rangelock
modifier|*
name|lock
decl_stmt|;
comment|/* lock for this transfer */
name|daddr_t
name|lockbase
decl_stmt|;
comment|/* and lock address */
name|struct
name|rqelement
name|rqe
index|[
literal|0
index|]
decl_stmt|;
comment|/* and the elements of this request */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Describe one high-level request and the  * work we have to do to satisfy it.  */
end_comment

begin_struct
struct|struct
name|request
block|{
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* pointer to the high-level request */
name|enum
name|xferinfo
name|flags
decl_stmt|;
union|union
block|{
name|int
name|volno
decl_stmt|;
comment|/* volume index */
name|int
name|plexno
decl_stmt|;
comment|/* or plex index */
block|}
name|volplex
union|;
name|int
name|error
decl_stmt|;
comment|/* current error indication */
name|int
name|sdno
decl_stmt|;
comment|/* reviving subdisk (XFR_REVIVECONFLICT) */
name|short
name|isplex
decl_stmt|;
comment|/* set if this is a plex request */
name|short
name|active
decl_stmt|;
comment|/* number of subrequests still active */
name|struct
name|rqgroup
modifier|*
name|rqg
decl_stmt|;
comment|/* pointer to the first group of requests */
name|struct
name|rqgroup
modifier|*
name|lrqg
decl_stmt|;
comment|/* and to the last group of requests */
name|struct
name|request
modifier|*
name|next
decl_stmt|;
comment|/* link of waiting requests */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Extended buffer header for subdisk I/O.  Includes  * a pointer to the user I/O request.  */
end_comment

begin_struct
struct|struct
name|sdbuf
block|{
name|struct
name|buf
name|b
decl_stmt|;
comment|/* our buffer */
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* and pointer to parent */
name|short
name|driveno
decl_stmt|;
comment|/* drive index */
name|short
name|sdno
decl_stmt|;
comment|/* and subdisk index */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Values returned by rqe and friends.  Be careful  * with these: they are in order of increasing  * seriousness.  Some routines check for  *> REQUEST_RECOVERED to indicate a failed request. XXX  */
end_comment

begin_enum
enum|enum
name|requeststatus
block|{
name|REQUEST_OK
block|,
comment|/* request built OK */
name|REQUEST_RECOVERED
block|,
comment|/* request OK, but involves RAID5 recovery */
name|REQUEST_DEGRADED
block|,
comment|/* parts of request failed */
name|REQUEST_EOF
block|,
comment|/* parts of request failed: outside plex */
name|REQUEST_DOWN
block|,
comment|/* all of request failed: subdisk(s) down */
name|REQUEST_ENOMEM
comment|/* all of request failed: ran out of memory */
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_comment
comment|/* Trace entry for request info (DEBUG_LASTREQS) */
end_comment

begin_enum
enum|enum
name|rqinfo_type
block|{
name|loginfo_unused
block|,
comment|/* never been used */
name|loginfo_user_bp
block|,
comment|/* this is the bp when strategy is called */
name|loginfo_user_bpl
block|,
comment|/* and this is the bp at launch time */
name|loginfo_rqe
block|,
comment|/* user RQE */
name|loginfo_iodone
block|,
comment|/* iodone */
name|loginfo_raid5_data
block|,
comment|/* write RAID-5 data block */
name|loginfo_raid5_parity
block|,
comment|/* write RAID-5 parity block */
name|loginfo_sdio
block|,
comment|/* subdisk I/O */
name|loginfo_sdiol
block|,
comment|/* subdisk I/O launch */
name|loginfo_sdiodone
block|,
comment|/* subdisk iodone */
name|loginfo_lockwait
block|,
comment|/* wait for range lock */
name|loginfo_lock
block|,
comment|/* lock range */
name|loginfo_unlock
block|,
comment|/* unlock range */
block|}
enum|;
end_enum

begin_union
union|union
name|rqinfou
block|{
comment|/* info to pass to logrq */
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
name|struct
name|rqelement
modifier|*
name|rqe
decl_stmt|;
comment|/* address of request, for correlation */
name|struct
name|rangelock
modifier|*
name|lockinfo
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|rqinfo
block|{
name|enum
name|rqinfo_type
name|type
decl_stmt|;
comment|/* kind of event */
name|struct
name|timeval
name|timestamp
decl_stmt|;
comment|/* time it happened */
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* point to user buffer */
name|int
name|devmajor
decl_stmt|;
comment|/* major and minor device info */
name|int
name|devminor
decl_stmt|;
union|union
block|{
name|struct
name|buf
name|b
decl_stmt|;
comment|/* yup, the *whole* buffer header */
name|struct
name|rqelement
name|rqe
decl_stmt|;
comment|/* and the whole rqe */
name|struct
name|rangelock
name|lockinfo
decl_stmt|;
block|}
name|info
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RQINFO_SIZE
value|128
end_define

begin_comment
comment|/* number of info slots in buffer */
end_comment

begin_function_decl
name|void
name|logrq
parameter_list|(
name|enum
name|rqinfo_type
name|type
parameter_list|,
name|union
name|rqinfou
name|info
parameter_list|,
name|struct
name|buf
modifier|*
name|ubp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Structures for the daemon */
end_comment

begin_comment
comment|/* types of request to the daemon */
end_comment

begin_enum
enum|enum
name|daemonrq
block|{
name|daemonrq_none
block|,
comment|/* dummy to catch bugs */
name|daemonrq_ioerror
block|,
comment|/* error occurred on I/O */
name|daemonrq_saveconfig
block|,
comment|/* save configuration */
name|daemonrq_return
block|,
comment|/* return to userland */
name|daemonrq_ping
block|,
comment|/* show sign of life */
name|daemonrq_init
block|,
comment|/* initialize a plex */
name|daemonrq_revive
block|,
comment|/* revive a subdisk */
name|daemonrq_closedrive
block|,
comment|/* close a drive */
block|}
enum|;
end_enum

begin_comment
comment|/* info field for daemon requests */
end_comment

begin_union
union|union
name|daemoninfo
block|{
comment|/* and the request information */
name|struct
name|request
modifier|*
name|rq
decl_stmt|;
comment|/* for daemonrq_ioerror */
name|struct
name|sd
modifier|*
name|sd
decl_stmt|;
comment|/* for daemonrq_revive */
name|struct
name|plex
modifier|*
name|plex
decl_stmt|;
comment|/* for daemonrq_init */
name|struct
name|drive
modifier|*
name|drive
decl_stmt|;
comment|/* for daemonrq_closedrive */
name|int
name|nothing
decl_stmt|;
comment|/* for passing NULL */
block|}
union|;
end_union

begin_struct
struct|struct
name|daemonq
block|{
name|struct
name|daemonq
modifier|*
name|next
decl_stmt|;
comment|/* pointer to next element in queue */
name|enum
name|daemonrq
name|type
decl_stmt|;
comment|/* type of request */
name|int
name|privateinuse
decl_stmt|;
comment|/* private element, being used */
name|union
name|daemoninfo
name|info
decl_stmt|;
comment|/* and the request information */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|queue_daemon_request
parameter_list|(
name|enum
name|daemonrq
name|type
parameter_list|,
name|union
name|daemoninfo
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|daemon_options
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|daemon_option
block|{
name|daemon_verbose
init|=
literal|1
block|,
comment|/* talk about what we're doing */
name|daemon_stopped
init|=
literal|2
block|,
name|daemon_noupdate
init|=
literal|4
block|,
comment|/* don't update the disk config, for recovery */
block|}
enum|;
end_enum

begin_function_decl
name|void
name|freerq
parameter_list|(
name|struct
name|request
modifier|*
name|rq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unlockrange
parameter_list|(
name|int
name|plexno
parameter_list|,
name|struct
name|rangelock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Local Variables: */
end_comment

begin_comment
comment|/* fill-column: 50 */
end_comment

begin_comment
comment|/* End: */
end_comment

end_unit

