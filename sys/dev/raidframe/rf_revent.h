begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_revent.h,v 1.3 1999/02/05 00:06:17 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author:  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*******************************************************************  *  * rf_revent.h -- header file for reconstruction event handling code  *  *******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_REVENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_REVENT_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_function_decl
name|int
name|rf_ConfigureReconEvent
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_ReconEvent_t
modifier|*
name|rf_GetNextReconEvent
parameter_list|(
name|RF_RaidReconDesc_t
modifier|*
name|reconDesc
parameter_list|,
name|RF_RowCol_t
name|row
parameter_list|,
name|void
function_decl|(
modifier|*
name|continueFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|continueArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_CauseReconEvent
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RowCol_t
name|row
parameter_list|,
name|RF_RowCol_t
name|col
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|RF_Revent_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeReconEventDesc
parameter_list|(
name|RF_ReconEvent_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_REVENT_H_ */
end_comment

end_unit

