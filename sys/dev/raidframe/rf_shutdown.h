begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_shutdown.h,v 1.2 1999/02/05 00:06:17 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_shutdown.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Maintain lists of cleanup functions. Also, mechanisms for coordinating  * thread startup and shutdown.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_SHUTDOWN_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_SHUTDOWN_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_comment
comment|/*  * Important note: the shutdown list is run like a stack, new  * entries pushed on top. Therefore, the most recently added  * entry (last started) is the first removed (stopped). This  * should handle system-dependencies pretty nicely- if a system  * is there when you start another, it'll be there when you  * shut down another. Hopefully, this subsystem will remove  * more complexity than it introduces.  */
end_comment

begin_struct
struct|struct
name|RF_ShutdownList_s
block|{
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|arg
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
name|RF_ShutdownList_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rf_ShutdownCreate
parameter_list|(
name|_listp_
parameter_list|,
name|_func_
parameter_list|,
name|_arg_
parameter_list|)
define|\
value|_rf_ShutdownCreate(_listp_,_func_,_arg_,__FILE__,__LINE__)
end_define

begin_function_decl
name|int
name|_rf_ShutdownCreate
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|,
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ShutdownList
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_SHUTDOWN_H_ */
end_comment

end_unit

