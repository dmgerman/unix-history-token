begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_dagfuncs.h,v 1.4 2000/03/30 13:39:07 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland, William V. Courtright II, Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*****************************************************************************************  *  * dagfuncs.h -- header file for DAG node execution routines  *  ****************************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_DAGFUNCS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_DAGFUNCS_H_
end_define

begin_function_decl
name|int
name|rf_ConfigureDAGFuncs
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_TerminateFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_TerminateUndoFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_DiskReadMirrorIdleFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_DiskReadMirrorPartitionFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_DiskReadMirrorUndoFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ParityLogUpdateFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ParityLogOverwriteFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ParityLogUpdateUndoFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ParityLogOverwriteUndoFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_NullNodeFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_NullNodeUndoFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_DiskReadFuncForThreads
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_DiskWriteFuncForThreads
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_DiskUndoFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_DiskUnlockFuncForThreads
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_GenericWakeupFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RegularXorFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_SimpleXorFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RecoveryXorFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_XorIntoBuffer
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_PhysDiskAddr_t
modifier|*
name|pda
parameter_list|,
name|char
modifier|*
name|srcbuf
parameter_list|,
name|char
modifier|*
name|targbuf
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_bxor
parameter_list|(
name|char
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
name|int
name|len
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_longword_bxor
parameter_list|(
name|unsigned
name|long
modifier|*
name|src
parameter_list|,
name|unsigned
name|long
modifier|*
name|dest
parameter_list|,
name|int
name|len
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_longword_bxor3
parameter_list|(
name|unsigned
name|long
modifier|*
name|dest
parameter_list|,
name|unsigned
name|long
modifier|*
name|a
parameter_list|,
name|unsigned
name|long
modifier|*
name|b
parameter_list|,
name|unsigned
name|long
modifier|*
name|c
parameter_list|,
name|int
name|len
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_bxor3
parameter_list|(
name|unsigned
name|char
modifier|*
name|dst
parameter_list|,
name|unsigned
name|char
modifier|*
name|a
parameter_list|,
name|unsigned
name|char
modifier|*
name|b
parameter_list|,
name|unsigned
name|char
modifier|*
name|c
parameter_list|,
name|unsigned
name|long
name|len
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* function ptrs defined in ConfigureDAGFuncs() */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|rf_DiskReadFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|rf_DiskWriteFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|rf_DiskReadUndoFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|rf_DiskWriteUndoFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|rf_DiskUnlockFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|rf_DiskUnlockUndoFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|rf_SimpleXorUndoFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|rf_RegularXorUndoFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|rf_RecoveryXorUndoFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* macros for manipulating the param[3] in a read or write node */
end_comment

begin_define
define|#
directive|define
name|RF_CREATE_PARAM3
parameter_list|(
name|pri
parameter_list|,
name|lk
parameter_list|,
name|unlk
parameter_list|,
name|wru
parameter_list|)
value|(((RF_uint64)(((wru&0xFFFFFF)<<8)|((lk)?0x10:0)|((unlk)?0x20:0)|((pri)&0xF)) ))
end_define

begin_define
define|#
directive|define
name|RF_EXTRACT_PRIORITY
parameter_list|(
name|_x_
parameter_list|)
value|((((unsigned) ((unsigned long)(_x_)))>> 0)& 0x0F)
end_define

begin_define
define|#
directive|define
name|RF_EXTRACT_LOCK_FLAG
parameter_list|(
name|_x_
parameter_list|)
value|((((unsigned) ((unsigned long)(_x_)))>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|RF_EXTRACT_UNLOCK_FLAG
parameter_list|(
name|_x_
parameter_list|)
value|((((unsigned) ((unsigned long)(_x_)))>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|RF_EXTRACT_RU
parameter_list|(
name|_x_
parameter_list|)
value|((((unsigned) ((unsigned long)(_x_)))>> 8)& 0xFFFFFF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_DAGFUNCS_H_ */
end_comment

end_unit

