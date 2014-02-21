begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Topspin Communications.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERN_ABI_H
end_ifndef

begin_define
define|#
directive|define
name|KERN_ABI_H
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_comment
comment|/*  * Increment this value if any changes that break userspace ABI  * compatibility are made.  */
end_comment

begin_define
define|#
directive|define
name|IB_USER_VERBS_ABI_VERSION
value|1
end_define

begin_enum
enum|enum
block|{
name|IB_USER_VERBS_CMD_GET_CONTEXT
block|,
name|IB_USER_VERBS_CMD_GET_EVENT_FDS
block|,
name|IB_USER_VERBS_CMD_ALLOC_PD
block|,
name|IB_USER_VERBS_CMD_DEALLOC_PD
block|,
name|IB_USER_VERBS_CMD_REG_MR
block|,
name|IB_USER_VERBS_CMD_DEREG_MR
block|}
enum|;
end_enum

begin_comment
comment|/*  * Make sure that all structs defined in this file remain laid out so  * that they pack the same way on 32-bit and 64-bit architectures (to  * avoid incompatibility between 32-bit userspace and 64-bit kernels).  * In particular do not use pointer types -- pass pointers in __u64  * instead.  */
end_comment

begin_struct
struct|struct
name|ibv_kern_async_event
block|{
name|__u32
name|event_type
decl_stmt|;
name|__u32
name|element
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ibv_comp_event
block|{
name|__u32
name|cq_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * All commands from userspace should start with a __u32 command field  * followed by __u16 in_words and out_words fields (which give the  * length of the command block and response buffer if any in 32-bit  * words).  The kernel driver will read these fields first and read  * the rest of the command struct based on these value.  */
end_comment

begin_struct
struct|struct
name|ibv_get_context
block|{
name|__u32
name|command
decl_stmt|;
name|__u16
name|in_words
decl_stmt|;
name|__u16
name|out_words
decl_stmt|;
name|__u64
name|response
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ibv_get_context_resp
block|{
name|__u32
name|num_cq_events
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ibv_get_event_fds
block|{
name|__u32
name|command
decl_stmt|;
name|__u16
name|in_words
decl_stmt|;
name|__u16
name|out_words
decl_stmt|;
name|__u64
name|response
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ibv_get_event_fds_resp
block|{
name|__u32
name|async_fd
decl_stmt|;
name|__u32
name|cq_fd
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERN_ABI_H */
end_comment

end_unit

