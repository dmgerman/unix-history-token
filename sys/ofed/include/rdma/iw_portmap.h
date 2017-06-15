begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Intel Corporation. All rights reserved.  * Copyright (c) 2014 Chelsio, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *	  copyright notice, this list of conditions and the following  *	  disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *	  copyright notice, this list of conditions and the following  *	  disclaimer in the documentation and/or other materials  *	  provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IW_PORTMAP_H
end_ifndef

begin_define
define|#
directive|define
name|_IW_PORTMAP_H
end_define

begin_define
define|#
directive|define
name|IWPM_ULIBNAME_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|IWPM_DEVNAME_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|IWPM_IFNAME_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|IWPM_IPADDR_SIZE
value|16
end_define

begin_enum
enum|enum
block|{
name|IWPM_INVALID_NLMSG_ERR
init|=
literal|10
block|,
name|IWPM_CREATE_MAPPING_ERR
block|,
name|IWPM_DUPLICATE_MAPPING_ERR
block|,
name|IWPM_UNKNOWN_MAPPING_ERR
block|,
name|IWPM_CLIENT_DEV_INFO_ERR
block|,
name|IWPM_USER_LIB_INFO_ERR
block|,
name|IWPM_REMOTE_QUERY_REJECT
block|}
enum|;
end_enum

begin_struct
struct|struct
name|iwpm_dev_data
block|{
name|char
name|dev_name
index|[
name|IWPM_DEVNAME_SIZE
index|]
decl_stmt|;
name|char
name|if_name
index|[
name|IWPM_IFNAME_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwpm_sa_data
block|{
name|struct
name|sockaddr_storage
name|loc_addr
decl_stmt|;
name|struct
name|sockaddr_storage
name|mapped_loc_addr
decl_stmt|;
name|struct
name|sockaddr_storage
name|rem_addr
decl_stmt|;
name|struct
name|sockaddr_storage
name|mapped_rem_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * iwpm_valid_pid - Check if the userspace iwarp port mapper pid is valid  *  * Returns true if the pid is greater than zero, otherwise returns false  */
end_comment

begin_function_decl
name|int
name|iwpm_valid_pid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IW_PORTMAP_H */
end_comment

end_unit

