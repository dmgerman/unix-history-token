begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_alloclist.h,v 1.3 1999/02/05 00:06:06 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/****************************************************************************  *  * alloclist.h -- header file for alloclist.c  *  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_ALLOCLIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_ALLOCLIST_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_define
define|#
directive|define
name|RF_POINTERS_PER_ALLOC_LIST_ELEMENT
value|20
end_define

begin_struct
struct|struct
name|RF_AllocListElem_s
block|{
name|void
modifier|*
name|pointers
index|[
name|RF_POINTERS_PER_ALLOC_LIST_ELEMENT
index|]
decl_stmt|;
name|int
name|sizes
index|[
name|RF_POINTERS_PER_ALLOC_LIST_ELEMENT
index|]
decl_stmt|;
name|int
name|numPointers
decl_stmt|;
name|RF_AllocListElem_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rf_MakeAllocList
parameter_list|(
name|_ptr_
parameter_list|)
value|_ptr_ = rf_real_MakeAllocList(1);
end_define

begin_define
define|#
directive|define
name|rf_AddToAllocList
parameter_list|(
name|_l_
parameter_list|,
name|_ptr_
parameter_list|,
name|_sz_
parameter_list|)
value|rf_real_AddToAllocList((_l_), (_ptr_), (_sz_), 1)
end_define

begin_function_decl
name|int
name|rf_ConfigureAllocList
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|RF_UTILITY
operator|==
literal|0
end_if

begin_function_decl
name|void
name|rf_real_AddToAllocList
parameter_list|(
name|RF_AllocListElem_t
modifier|*
name|l
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|lockflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeAllocList
parameter_list|(
name|RF_AllocListElem_t
modifier|*
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_AllocListElem_t
modifier|*
name|rf_real_MakeAllocList
parameter_list|(
name|int
name|lockflag
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RF_UTILITY == 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_ALLOCLIST_H_ */
end_comment

end_unit

