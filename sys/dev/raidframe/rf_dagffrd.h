begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_dagffrd.h,v 1.3 1999/02/05 00:06:07 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland, Daniel Stodolsky, William V. Courtright II  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_DAGFFRD_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_DAGFFRD_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_comment
comment|/* fault-free read DAG creation routines */
end_comment

begin_function_decl
name|void
name|rf_CreateFaultFreeReadDAG
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|RF_DagHeader_t
modifier|*
name|dag_h
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|allocList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_CreateNonredundantDAG
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|RF_DagHeader_t
modifier|*
name|dag_h
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|allocList
parameter_list|,
name|RF_IoType_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_CreateMirrorIdleReadDAG
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|RF_DagHeader_t
modifier|*
name|dag_h
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|allocList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_CreateMirrorPartitionReadDAG
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|RF_DagHeader_t
modifier|*
name|dag_h
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|allocList
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_DAGFFRD_H_ */
end_comment

end_unit

