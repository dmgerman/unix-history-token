begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Intel Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFINIBAND_SA_KERN_ABI_H
end_ifndef

begin_define
define|#
directive|define
name|INFINIBAND_SA_KERN_ABI_H
end_define

begin_include
include|#
directive|include
file|<infiniband/types.h>
end_include

begin_comment
comment|/*  * Obsolete, deprecated names.  Will be removed in libibverbs 1.1.  */
end_comment

begin_define
define|#
directive|define
name|ib_kern_path_rec
value|ibv_kern_path_rec
end_define

begin_struct
struct|struct
name|ibv_kern_path_rec
block|{
name|__u8
name|dgid
index|[
literal|16
index|]
decl_stmt|;
name|__u8
name|sgid
index|[
literal|16
index|]
decl_stmt|;
name|__u16
name|dlid
decl_stmt|;
name|__u16
name|slid
decl_stmt|;
name|__u32
name|raw_traffic
decl_stmt|;
name|__u32
name|flow_label
decl_stmt|;
name|__u32
name|reversible
decl_stmt|;
name|__u32
name|mtu
decl_stmt|;
name|__u16
name|pkey
decl_stmt|;
name|__u8
name|hop_limit
decl_stmt|;
name|__u8
name|traffic_class
decl_stmt|;
name|__u8
name|numb_path
decl_stmt|;
name|__u8
name|sl
decl_stmt|;
name|__u8
name|mtu_selector
decl_stmt|;
name|__u8
name|rate_selector
decl_stmt|;
name|__u8
name|rate
decl_stmt|;
name|__u8
name|packet_life_time_selector
decl_stmt|;
name|__u8
name|packet_life_time
decl_stmt|;
name|__u8
name|preference
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INFINIBAND_SA_KERN_ABI_H */
end_comment

end_unit

