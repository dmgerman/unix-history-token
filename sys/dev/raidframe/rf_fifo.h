begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_fifo.h,v 1.3 1999/02/05 00:06:11 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * rf_fifo.h --  prioritized FIFO queue code.  *  * 4-9-93 Created (MCH)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_FIFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_FIFO_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_archs.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_diskqueue.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|RF_FifoHeader_s
block|{
name|RF_DiskQueueData_t
modifier|*
name|hq_head
decl_stmt|,
modifier|*
name|hq_tail
decl_stmt|;
comment|/* high priority requests */
name|RF_DiskQueueData_t
modifier|*
name|lq_head
decl_stmt|,
modifier|*
name|lq_tail
decl_stmt|;
comment|/* low priority requests */
name|int
name|hq_count
decl_stmt|,
name|lq_count
decl_stmt|;
comment|/* debug only */
block|}
name|RF_FifoHeader_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
modifier|*
name|rf_FifoCreate
parameter_list|(
name|RF_SectorCount_t
name|sectPerDisk
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|clList
parameter_list|,
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rf_FifoEnqueue
parameter_list|(
name|void
modifier|*
name|q_in
parameter_list|,
name|RF_DiskQueueData_t
modifier|*
name|elem
parameter_list|,
name|int
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RF_DiskQueueData_t
modifier|*
name|rf_FifoDequeue
parameter_list|(
name|void
modifier|*
name|q_in
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RF_DiskQueueData_t
modifier|*
name|rf_FifoPeek
parameter_list|(
name|void
modifier|*
name|q_in
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rf_FifoPromote
parameter_list|(
name|void
modifier|*
name|q_in
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
comment|/* !_RF__RF_FIFO_H_ */
end_comment

end_unit

