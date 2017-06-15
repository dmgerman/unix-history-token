begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Intel Corporation. All rights reserved.  * Copyright (c) 2014 Chelsio, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *	  copyright notice, this list of conditions and the following  *	  disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *	  copyright notice, this list of conditions and the following  *	  disclaimer in the documentation and/or other materials  *	  provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IWPM_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_IWPM_UTIL_H
end_define

begin_include
include|#
directive|include
file|<linux/module.h>
end_include

begin_include
include|#
directive|include
file|<linux/io.h>
end_include

begin_include
include|#
directive|include
file|<linux/in.h>
end_include

begin_include
include|#
directive|include
file|<linux/in6.h>
end_include

begin_include
include|#
directive|include
file|<linux/spinlock.h>
end_include

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<linux/netdevice.h>
end_include

begin_include
include|#
directive|include
file|<linux/delay.h>
end_include

begin_include
include|#
directive|include
file|<linux/workqueue.h>
end_include

begin_include
include|#
directive|include
file|<linux/mutex.h>
end_include

begin_include
include|#
directive|include
file|<linux/jhash.h>
end_include

begin_include
include|#
directive|include
file|<linux/kref.h>
end_include

begin_include
include|#
directive|include
file|<linux/errno.h>
end_include

begin_include
include|#
directive|include
file|<linux/rwsem.h>
end_include

begin_include
include|#
directive|include
file|<rdma/iw_portmap.h>
end_include

begin_define
define|#
directive|define
name|IWPM_PID_UNDEFINED
value|-1
end_define

begin_define
define|#
directive|define
name|IWPM_PID_UNAVAILABLE
value|-2
end_define

begin_define
define|#
directive|define
name|IWPM_REG_UNDEF
value|0x01
end_define

begin_define
define|#
directive|define
name|IWPM_REG_VALID
value|0x02
end_define

begin_define
define|#
directive|define
name|IWPM_REG_INCOMPL
value|0x04
end_define

begin_comment
comment|/**  * iwpm_compare_sockaddr - Compare two sockaddr storage structs  *  * Returns 0 if they are holding the same ip/tcp address info,  * otherwise returns 1  */
end_comment

begin_function_decl
name|int
name|iwpm_compare_sockaddr
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|a_sockaddr
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|b_sockaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * iwpm_print_sockaddr - Print IPv4/IPv6 address and TCP port  * @sockaddr: Socket address to print  * @msg: Message to print  */
end_comment

begin_function_decl
name|void
name|iwpm_print_sockaddr
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|sockaddr
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

