begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_cvscan.h,v 1.3 1999/02/05 00:06:07 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/* **	Disk scheduling by CVSCAN( N, r ) ** **	Given a set of requests, partition them into one set on each **	side of the current arm position.  The trick is to pick which **	side you are going to service next; once a side is picked you will **	service the closest request. **	Let there be n1 requests on one side and n2 requests on the other **	side.  If one of n1 or n2 is zero, select the other side. **	If both n1 and n2 are nonzero, select a "range" for examination **	that is N' = min( n1, n2, N ).  Average the distance from the **	current position to the nearest N' requests on each side giving **	d1 and d2. **	Suppose the last decision was to move toward set 2, then the **	current direction is toward set 2, and you will only switch to set **	1 if d1+R< d2 where R is r*(total number of cylinders), r in [0,1]. ** **	I extend this by applying only to the set of requests that all **	share the same, highest priority level. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_CVSCAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_CVSCAN_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_diskqueue.h>
end_include

begin_typedef
typedef|typedef
enum|enum
name|RF_CvscanArmDir_e
block|{
name|rf_cvscan_LEFT
block|,
name|rf_cvscan_RIGHT
block|}
name|RF_CvscanArmDir_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RF_CvscanHeader_s
block|{
name|long
name|range_for_avg
decl_stmt|;
comment|/* CVSCAN param N */
name|long
name|change_penalty
decl_stmt|;
comment|/* CVSCAN param R */
name|RF_CvscanArmDir_t
name|direction
decl_stmt|;
name|RF_SectorNum_t
name|cur_block
decl_stmt|;
name|int
name|nxt_priority
decl_stmt|;
name|RF_DiskQueueData_t
modifier|*
name|left
decl_stmt|;
name|int
name|left_cnt
decl_stmt|;
name|RF_DiskQueueData_t
modifier|*
name|right
decl_stmt|;
name|int
name|right_cnt
decl_stmt|;
name|RF_DiskQueueData_t
modifier|*
name|burner
decl_stmt|;
block|}
name|RF_CvscanHeader_t
typedef|;
end_typedef

begin_function_decl
name|int
name|rf_CvscanConfigure
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rf_CvscanCreate
parameter_list|(
name|RF_SectorCount_t
name|sect_per_disk
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|cl_list
parameter_list|,
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_CvscanEnqueue
parameter_list|(
name|void
modifier|*
name|qptr
parameter_list|,
name|RF_DiskQueueData_t
modifier|*
name|req
parameter_list|,
name|int
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_DiskQueueData_t
modifier|*
name|rf_CvscanDequeue
parameter_list|(
name|void
modifier|*
name|qptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_DiskQueueData_t
modifier|*
name|rf_CvscanPeek
parameter_list|(
name|void
modifier|*
name|qptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_CvscanPromote
parameter_list|(
name|void
modifier|*
name|qptr
parameter_list|,
name|RF_StripeNum_t
name|parityStripeID
parameter_list|,
name|RF_ReconUnitNum_t
name|which_ru
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_CVSCAN_H_ */
end_comment

end_unit

