begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_kintf.h,v 1.15 2000/10/20 02:24:45 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_kintf.h  *  * RAIDframe exported kernel interface  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_KINTF_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_KINTF_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

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
name|RF_LTSLEEP
parameter_list|(
name|cond
parameter_list|,
name|pri
parameter_list|,
name|text
parameter_list|,
name|time
parameter_list|,
name|mutex
parameter_list|)
define|\
value|ltsleep(cond, pri, text, time, mutex)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|500005
end_if

begin_define
define|#
directive|define
name|RF_LTSLEEP
parameter_list|(
name|cond
parameter_list|,
name|pri
parameter_list|,
name|text
parameter_list|,
name|time
parameter_list|,
name|mutex
parameter_list|)
define|\
value|msleep(cond, mutex, pri, text, time);
end_define

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|int
name|RF_LTSLEEP
parameter_list|(
name|void
modifier|*
name|cond
parameter_list|,
name|int
name|pri
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|,
name|int
name|time
parameter_list|,
name|struct
name|simplelock
modifier|*
name|mutex
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
if|if
condition|(
name|mutex
operator|!=
name|NULL
condition|)
name|simple_unlock
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
name|ret
operator|=
name|tsleep
argument_list|(
name|cond
argument_list|,
name|pri
argument_list|,
name|text
argument_list|,
name|time
argument_list|)
expr_stmt|;
if|if
condition|(
name|mutex
operator|!=
name|NULL
condition|)
name|simple_lock
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|rf_GetSpareTableFromDaemon
parameter_list|(
name|RF_SparetWait_t
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|raidstart
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_DispatchKernelIO
parameter_list|(
name|RF_DiskQueue_t
modifier|*
name|queue
parameter_list|,
name|RF_DiskQueueData_t
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|raidwrite_component_label
parameter_list|(
name|dev_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|RF_ComponentLabel_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|raidread_component_label
parameter_list|(
name|dev_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|RF_ComponentLabel_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RF_NORMAL_COMPONENT_UPDATE
value|0
end_define

begin_define
define|#
directive|define
name|RF_FINAL_COMPONENT_UPDATE
value|1
end_define

begin_function_decl
name|void
name|rf_update_component_labels
parameter_list|(
name|RF_Raid_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|raidlookup
parameter_list|(
name|char
modifier|*
parameter_list|,
name|RF_Thread_t
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|raidmarkclean
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|vnode
modifier|*
name|b_vp
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|raidmarkdirty
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|vnode
modifier|*
name|b_vp
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|raid_init_component_label
parameter_list|(
name|RF_Raid_t
modifier|*
parameter_list|,
name|RF_ComponentLabel_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_print_component_label
parameter_list|(
name|RF_ComponentLabel_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_UnconfigureVnodes
parameter_list|(
name|RF_Raid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_close_component
parameter_list|(
name|RF_Raid_t
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_disk_unbusy
parameter_list|(
name|RF_RaidAccessDesc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|raid_getcomponentsize
parameter_list|(
name|RF_Raid_t
modifier|*
parameter_list|,
name|RF_RowCol_t
parameter_list|,
name|RF_RowCol_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RF__RF_KINTF_H_ */
end_comment

end_unit

