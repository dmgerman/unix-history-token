begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_sstf.h,v 1.3 1999/02/05 00:06:17 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_SSTF_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_SSTF_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_diskqueue.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|RF_SstfQ_s
block|{
name|RF_DiskQueueData_t
modifier|*
name|queue
decl_stmt|;
name|RF_DiskQueueData_t
modifier|*
name|qtail
decl_stmt|;
name|int
name|qlen
decl_stmt|;
block|}
name|RF_SstfQ_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RF_Sstf_s
block|{
name|RF_SstfQ_t
name|left
decl_stmt|;
name|RF_SstfQ_t
name|right
decl_stmt|;
name|RF_SstfQ_t
name|lopri
decl_stmt|;
name|RF_SectorNum_t
name|last_sector
decl_stmt|;
name|int
name|dir
decl_stmt|;
name|int
name|allow_reverse
decl_stmt|;
block|}
name|RF_Sstf_t
typedef|;
end_typedef

begin_function_decl
name|void
modifier|*
name|rf_SstfCreate
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
modifier|*
name|rf_ScanCreate
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
modifier|*
name|rf_CscanCreate
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
name|rf_SstfEnqueue
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
name|rf_SstfDequeue
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
name|rf_SstfPeek
parameter_list|(
name|void
modifier|*
name|qptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_SstfPromote
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

begin_function_decl
name|RF_DiskQueueData_t
modifier|*
name|rf_ScanDequeue
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
name|rf_ScanPeek
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
name|rf_CscanDequeue
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
name|rf_CscanPeek
parameter_list|(
name|void
modifier|*
name|qptr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_SSTF_H_ */
end_comment

end_unit

