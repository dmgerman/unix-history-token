begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_raidframe.h,v 1.11 2000/05/28 00:48:31 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*****************************************************  *  * rf_raidframe.h  *  * main header file for using raidframe in the kernel.  *  *****************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_RAIDFRAME_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_RAIDFRAME_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_configure.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_disks.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_raid.h>
end_include

begin_typedef
typedef|typedef
name|RF_uint32
name|RF_ReconReqFlags_t
typedef|;
end_typedef

begin_struct
struct|struct
name|rf_recon_req
block|{
comment|/* used to tell the kernel to fail a disk */
name|RF_RowCol_t
name|row
decl_stmt|,
name|col
decl_stmt|;
name|RF_ReconReqFlags_t
name|flags
decl_stmt|;
name|void
modifier|*
name|raidPtr
decl_stmt|;
comment|/* used internally; need not be set at ioctl 				 * time */
name|struct
name|rf_recon_req
modifier|*
name|next
decl_stmt|;
comment|/* used internally; need not be set at 					 * ioctl time */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_SparetWait_s
block|{
name|int
name|C
decl_stmt|,
name|G
decl_stmt|,
name|fcol
decl_stmt|;
comment|/* C = # disks in row, G = # units in stripe, 				 * fcol = which disk has failed */
name|RF_StripeCount_t
name|SUsPerPU
decl_stmt|;
comment|/* this stuff is the info required to 					 * create a spare table */
name|int
name|TablesPerSpareRegion
decl_stmt|;
name|int
name|BlocksPerTable
decl_stmt|;
name|RF_StripeCount_t
name|TableDepthInPUs
decl_stmt|;
name|RF_StripeCount_t
name|SpareSpaceDepthPerRegionInSUs
decl_stmt|;
name|RF_SparetWait_t
modifier|*
name|next
decl_stmt|;
comment|/* used internally; need not be set at ioctl 				 * time */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|RF_DeviceConfig_s
block|{
name|u_int
name|rows
decl_stmt|;
name|u_int
name|cols
decl_stmt|;
name|u_int
name|maxqdepth
decl_stmt|;
name|int
name|ndevs
decl_stmt|;
name|RF_RaidDisk_t
name|devs
index|[
name|RF_MAX_DISKS
index|]
decl_stmt|;
name|int
name|nspares
decl_stmt|;
name|RF_RaidDisk_t
name|spares
index|[
name|RF_MAX_DISKS
index|]
decl_stmt|;
block|}
name|RF_DeviceConfig_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RF_ProgressInfo_s
block|{
name|RF_uint64
name|remaining
decl_stmt|;
name|RF_uint64
name|completed
decl_stmt|;
name|RF_uint64
name|total
decl_stmt|;
block|}
name|RF_ProgressInfo_t
typedef|;
end_typedef

begin_comment
comment|/* flags that can be put in the rf_recon_req structure */
end_comment

begin_define
define|#
directive|define
name|RF_FDFLAGS_NONE
value|0x0
end_define

begin_comment
comment|/* just fail the disk */
end_comment

begin_define
define|#
directive|define
name|RF_FDFLAGS_RECON
value|0x1
end_define

begin_comment
comment|/* fail and initiate recon */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_CONFIGURE
value|_IOW ('r',  1, void *)
end_define

begin_comment
comment|/* config an array */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|RAIDFRAME_SHUTDOWN
value|_IO  ('r',  2)
end_define

begin_comment
comment|/* shutdown the array */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RAIDFRAME_SHUTDOWN
value|_IOW ('r',  2, int)
end_define

begin_comment
comment|/* shutdown the array */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RAIDFRAME_TUR
value|_IOW ('r',  3, dev_t)
end_define

begin_comment
comment|/* debug only: test 							 * ready */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_TEST_ACC
value|_IOWR('r',  4, struct rf_test_acc)
end_define

begin_comment
comment|/* run a test access */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_FAIL_DISK
value|_IOW ('r',  5, struct rf_recon_req)
end_define

begin_comment
comment|/* fail a disk& 							 * optionally start 							 * recon */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_CHECK_RECON_STATUS
value|_IOR('r',  6, int)
end_define

begin_comment
comment|/* get reconstruction % 							 * complete on indicated 							 * row */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_REWRITEPARITY
value|_IO  ('r',  7)
end_define

begin_comment
comment|/* rewrite (initialize) 							 * all parity */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_COPYBACK
value|_IO  ('r',  8)
end_define

begin_comment
comment|/* copy reconstructed 							 * data back to replaced 							 * disk */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_SPARET_WAIT
value|_IOR ('r',  9, RF_SparetWait_t)
end_define

begin_comment
comment|/* does not return until 							 * kernel needs a spare 							 * table */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_SEND_SPARET
value|_IOW ('r', 10, void *)
end_define

begin_comment
comment|/* used to send a spare 							 * table down into the 							 * kernel */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_ABORT_SPARET_WAIT
value|_IO  ('r', 11)
end_define

begin_comment
comment|/* used to wake up the 							 * sparemap daemon& 							 * tell it to exit */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_START_ATRACE
value|_IO  ('r', 12)
end_define

begin_comment
comment|/* start tracing 							 * accesses */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_STOP_ATRACE
value|_IO  ('r', 13)
end_define

begin_comment
comment|/* stop tracing 							 * accesses */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_GET_SIZE
value|_IOR ('r', 14, int)
end_define

begin_comment
comment|/* get size (# sectors) 							 * in raid device */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_GET_INFO
value|_IOWR ('r', 15, RF_DeviceConfig_t *)
end_define

begin_comment
comment|/* get configuration */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_RESET_ACCTOTALS
value|_IO  ('r', 16)
end_define

begin_comment
comment|/* reset AccTotals for 							 * device */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_GET_ACCTOTALS
value|_IOR ('r', 17, RF_AccTotals_t)
end_define

begin_comment
comment|/* retrieve AccTotals 							 * for device */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_KEEP_ACCTOTALS
value|_IOW ('r', 18, int)
end_define

begin_comment
comment|/* turn AccTotals on or 							 * off for device */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_GET_COMPONENT_LABEL
value|_IOWR ('r', 19, RF_ComponentLabel_t)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_SET_COMPONENT_LABEL
value|_IOW  ('r', 20, RF_ComponentLabel_t)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_INIT_LABELS
value|_IOW ('r', 21, RF_ComponentLabel_t)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_ADD_HOT_SPARE
value|_IOW ('r', 22, RF_SingleComponent_t)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_REMOVE_HOT_SPARE
value|_IOW ('r', 23, RF_SingleComponent_t)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_REBUILD_IN_PLACE
value|_IOW ('r', 24, RF_SingleComponent_t)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_CHECK_PARITY
value|_IOWR ('r', 25, int)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_CHECK_PARITYREWRITE_STATUS
value|_IOR ('r', 26, int)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_CHECK_COPYBACK_STATUS
value|_IOR ('r', 27, int)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_SET_AUTOCONFIG
value|_IOWR ('r', 28, int)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_SET_ROOT
value|_IOWR ('r', 29, int)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_DELETE_COMPONENT
value|_IOW  ('r', 30, RF_SingleComponent_t)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_INCORPORATE_HOT_SPARE
value|_IOW ('r', 31, RF_SingleComponent_t)
end_define

begin_comment
comment|/* 'Extended' status versions */
end_comment

begin_define
define|#
directive|define
name|RAIDFRAME_CHECK_RECON_STATUS_EXT
value|_IOR('r',  32, RF_ProgressInfo_t)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_CHECK_PARITYREWRITE_STATUS_EXT
value|_IOR ('r', 33, \ 							RF_ProgressInfo_t)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_CHECK_COPYBACK_STATUS_EXT
value|_IOR ('r', 34, RF_ProgressInfo_t)
end_define

begin_define
define|#
directive|define
name|RAIDFRAME_GET_UNIT
value|_IOWR ('r', 35, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_RAIDFRAME_H_ */
end_comment

end_unit

