begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (c) 1986, 1987 by Hewlett-Packard Company Copyright (c) 1986, 1987 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  HEWLETT-PACKARD MAKES NO WARRANTY OF ANY KIND WITH REGARD TO THIS SOFWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE.  Hewlett-Packard shall not be liable for errors  contained herein or direct, indirect, special, incidental or  consequential damages in connection with the furnishing,  performance, or use of this material.  This software is not subject to any license of the American Telephone and Telegraph Company or of the Regents of the University of California.  */
end_comment

begin_comment
comment|/***********************************************************************  *  file: hpbuf.h  *  *  *  ******************************************************************  *  *  (c) Copyright Hewlett-Packard Company, 1986.  All rights are  *  *  *  reserved.  Copying or other reproduction of this program      *  *  *  except for archival purposes is prohibited without prior      *  *  *  written consent of Hewlett-Packard Company.		     *  *  ******************************************************************  *  *  Program purpose -- include file for off-screen memory allocator  *  *		Hewlett Packard -- Corvallis Workstation Operation  *		Project -- port of X to HP9000S300  *		Dan Garfinkel -- MTS  *              Bob Leichner -- MTS - port of allocator to X11  *  */
end_comment

begin_include
include|#
directive|include
file|"X.h"
end_include

begin_comment
comment|/*  * Type definitions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HPBUF_DEF
end_ifndef

begin_define
define|#
directive|define
name|_HPBUF_DEF
end_define

begin_typedef
typedef|typedef
struct|struct
name|_cnode
block|{
name|struct
name|_cnode
modifier|*
name|parent
decl_stmt|;
comment|/* parent node */
name|struct
name|_cnode
modifier|*
name|c0
decl_stmt|,
modifier|*
name|c1
decl_stmt|,
modifier|*
name|c2
decl_stmt|;
comment|/* pointers to either cnodes or XHPchunks */
name|short
name|t0
decl_stmt|,
name|t1
decl_stmt|,
name|t2
decl_stmt|;
comment|/* types of c0, c1, and c2 */
comment|/*   One of -- USED, UNUSED, CNODE */
block|}
name|hpCnode
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_chunk
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* x, y position in the frame buffer */
name|short
name|h
decl_stmt|,
name|w
decl_stmt|;
comment|/* height and width of chunk */
name|struct
name|_chunk
modifier|*
name|prev
decl_stmt|;
comment|/* previous chunk in the linked list */
name|struct
name|_chunk
modifier|*
name|next
decl_stmt|;
comment|/* next chunk in the linked list */
name|hpCnode
modifier|*
name|parent
decl_stmt|;
comment|/* parent of this chunk */
block|}
name|hpChunk
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hpChunk
modifier|*
name|used
decl_stmt|;
name|hpChunk
modifier|*
name|unused
decl_stmt|;
name|int
name|initialized
decl_stmt|;
name|int
name|firstcol
decl_stmt|;
block|}
name|hpBufAllocInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|hpBufAllocInfo
modifier|*
name|hpBufAllocInfoPtr
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|hpChunk
modifier|*
name|hpBufAlloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hpBufFree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hpBufAllocInit
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|_HPBUF_DEF
end_endif

end_unit

