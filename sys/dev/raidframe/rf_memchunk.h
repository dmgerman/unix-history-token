begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_memchunk.h,v 1.3 1999/02/05 00:06:13 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/* header file for rf_memchunk.c.  See comments there */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_MEMCHUNK_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_MEMCHUNK_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_struct
struct|struct
name|RF_ChunkDesc_s
block|{
name|int
name|size
decl_stmt|;
name|int
name|reuse_count
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|RF_ChunkDesc_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|rf_ConfigureMemChunk
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_ChunkDesc_t
modifier|*
name|rf_GetMemChunk
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_ReleaseMemChunk
parameter_list|(
name|RF_ChunkDesc_t
modifier|*
name|chunk
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_MEMCHUNK_H_ */
end_comment

end_unit

