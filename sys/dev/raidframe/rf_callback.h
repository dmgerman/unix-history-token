begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_callback.h,v 1.3 1999/02/05 00:06:06 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*****************************************************************************************  *  * callback.h -- header file for callback.c  *  * the reconstruction code must manage concurrent I/Os on multiple drives.  * it sometimes needs to suspend operation on a particular drive until some  * condition occurs.  we can't block the thread, of course, or we wouldn't  * be able to manage our other outstanding I/Os.  Instead we just suspend  * new activity on the indicated disk, and create a callback descriptor and  * put it someplace where it will get invoked when the condition that's  * stalling us has cleared.  When the descriptor is invoked, it will call  * a function that will restart operation on the indicated disk.  *  ****************************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_CALLBACK_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_CALLBACK_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_struct
struct|struct
name|RF_CallbackDesc_s
block|{
name|void
function_decl|(
modifier|*
name|callbackFunc
function_decl|)
parameter_list|(
name|RF_CBParam_t
parameter_list|)
function_decl|;
comment|/* function to call */
name|RF_CBParam_t
name|callbackArg
decl_stmt|;
comment|/* args to give to function, or just 					 * info about this callback  */
name|RF_CBParam_t
name|callbackArg2
decl_stmt|;
name|RF_RowCol_t
name|row
decl_stmt|;
comment|/* disk row and column IDs to give to the 				 * callback func */
name|RF_RowCol_t
name|col
decl_stmt|;
name|RF_CallbackDesc_t
modifier|*
name|next
decl_stmt|;
comment|/* next entry in list */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|rf_ConfigureCallback
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_CallbackDesc_t
modifier|*
name|rf_AllocCallbackDesc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeCallbackDesc
parameter_list|(
name|RF_CallbackDesc_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_CALLBACK_H_ */
end_comment

end_unit

