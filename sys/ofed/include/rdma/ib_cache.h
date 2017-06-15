begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Topspin Communications.  All rights reserved.  * Copyright (c) 2005 Intel Corporation. All rights reserved.  * Copyright (c) 2005 Sun Microsystems, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IB_CACHE_H
end_ifndef

begin_define
define|#
directive|define
name|_IB_CACHE_H
end_define

begin_include
include|#
directive|include
file|<rdma/ib_verbs.h>
end_include

begin_comment
comment|/**  * ib_get_cached_gid - Returns a cached GID table entry  * @device: The device to query.  * @port_num: The port number of the device to query.  * @index: The index into the cached GID table to query.  * @gid: The GID value found at the specified index.  * @attr: The GID attribute found at the specified index (only in RoCE).  *   NULL means ignore (output parameter).  *  * ib_get_cached_gid() fetches the specified GID table entry stored in  * the local software cache.  */
end_comment

begin_function_decl
name|int
name|ib_get_cached_gid
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|int
name|index
parameter_list|,
name|union
name|ib_gid
modifier|*
name|gid
parameter_list|,
name|struct
name|ib_gid_attr
modifier|*
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_find_cached_gid - Returns the port number and GID table index where  *   a specified GID value occurs.  * @device: The device to query.  * @gid: The GID value to search for.  * @gid_type: The GID type to search for.  * @ndev: In RoCE, the net device of the device. NULL means ignore.  * @port_num: The port number of the device where the GID value was found.  * @index: The index into the cached GID table where the GID was found.  This  *   parameter may be NULL.  *  * ib_find_cached_gid() searches for the specified GID value in  * the local software cache.  */
end_comment

begin_function_decl
name|int
name|ib_find_cached_gid
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
specifier|const
name|union
name|ib_gid
modifier|*
name|gid
parameter_list|,
name|enum
name|ib_gid_type
name|gid_type
parameter_list|,
name|struct
name|net_device
modifier|*
name|ndev
parameter_list|,
name|u8
modifier|*
name|port_num
parameter_list|,
name|u16
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_find_cached_gid_by_port - Returns the GID table index where a specified  * GID value occurs  * @device: The device to query.  * @gid: The GID value to search for.  * @gid_type: The GID type to search for.  * @port_num: The port number of the device where the GID value sould be  *   searched.  * @ndev: In RoCE, the net device of the device. Null means ignore.  * @index: The index into the cached GID table where the GID was found.  This  *   parameter may be NULL.  *  * ib_find_cached_gid() searches for the specified GID value in  * the local software cache.  */
end_comment

begin_function_decl
name|int
name|ib_find_cached_gid_by_port
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
specifier|const
name|union
name|ib_gid
modifier|*
name|gid
parameter_list|,
name|enum
name|ib_gid_type
name|gid_type
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|struct
name|net_device
modifier|*
name|ndev
parameter_list|,
name|u16
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ib_find_gid_by_filter
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
specifier|const
name|union
name|ib_gid
modifier|*
name|gid
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|bool
function_decl|(
modifier|*
name|filter
function_decl|)
parameter_list|(
specifier|const
name|union
name|ib_gid
modifier|*
name|gid
parameter_list|,
specifier|const
name|struct
name|ib_gid_attr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|u16
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_get_cached_pkey - Returns a cached PKey table entry  * @device: The device to query.  * @port_num: The port number of the device to query.  * @index: The index into the cached PKey table to query.  * @pkey: The PKey value found at the specified index.  *  * ib_get_cached_pkey() fetches the specified PKey table entry stored in  * the local software cache.  */
end_comment

begin_function_decl
name|int
name|ib_get_cached_pkey
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device_handle
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|int
name|index
parameter_list|,
name|u16
modifier|*
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_find_cached_pkey - Returns the PKey table index where a specified  *   PKey value occurs.  * @device: The device to query.  * @port_num: The port number of the device to search for the PKey.  * @pkey: The PKey value to search for.  * @index: The index into the cached PKey table where the PKey was found.  *  * ib_find_cached_pkey() searches the specified PKey table in  * the local software cache.  */
end_comment

begin_function_decl
name|int
name|ib_find_cached_pkey
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|u16
name|pkey
parameter_list|,
name|u16
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_find_exact_cached_pkey - Returns the PKey table index where a specified  *   PKey value occurs. Comparison uses the FULL 16 bits (incl membership bit)  * @device: The device to query.  * @port_num: The port number of the device to search for the PKey.  * @pkey: The PKey value to search for.  * @index: The index into the cached PKey table where the PKey was found.  *  * ib_find_exact_cached_pkey() searches the specified PKey table in  * the local software cache.  */
end_comment

begin_function_decl
name|int
name|ib_find_exact_cached_pkey
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|u16
name|pkey
parameter_list|,
name|u16
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_get_cached_lmc - Returns a cached lmc table entry  * @device: The device to query.  * @port_num: The port number of the device to query.  * @lmc: The lmc value for the specified port for that device.  *  * ib_get_cached_lmc() fetches the specified lmc table entry stored in  * the local software cache.  */
end_comment

begin_function_decl
name|int
name|ib_get_cached_lmc
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|u8
modifier|*
name|lmc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IB_CACHE_H */
end_comment

end_unit

