begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Based on BSD-licensed source modules in the Linux iwlwifi driver,  * which were used as the reference documentation for this implementation.  *  ******************************************************************************  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2007 - 2014 Intel Corporation. All rights reserved.  * Copyright(c) 2015 Intel Deutschland GmbH  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110,  * USA  *  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * Contact Information:  *  Intel Linux Wireless<linuxwifi@intel.com>  * Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497  *  * BSD LICENSE  *  * Copyright(c) 2005 - 2014 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  * Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * Neither the name Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *****************************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_IWN_NOTIF_WAIT_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_IWN_NOTIF_WAIT_H__
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|IWM_MAX_NOTIF_CMDS
value|5
end_define

begin_struct_decl
struct_decl|struct
name|iwm_rx_packet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iwm_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct iwm_notification_wait - notification wait entry  * @entry: link for global list  * @fn: Function called with the notification. If the function  *      returns true, the wait is over, if it returns false then  *      the waiter stays blocked. If no function is given, any  *      of the listed commands will unblock the waiter.  * @cmds: command IDs  * @n_cmds: number of command IDs  * @triggered: waiter should be woken up  * @aborted: wait was aborted  *  * This structure is not used directly, to wait for a  * notification declare it on the stack, and call  * iwm_init_notification_wait() with appropriate  * parameters. Then do whatever will cause the ucode  * to notify the driver, and to wait for that then  * call iwm_wait_notification().  *  * Each notification is one-shot. If at some point we  * need to support multi-shot notifications (which  * can't be allocated on the stack) we need to modify  * the code for them.  */
end_comment

begin_struct
struct|struct
name|iwm_notification_wait
block|{
name|STAILQ_ENTRY
argument_list|(
argument|iwm_notification_wait
argument_list|)
name|entry
expr_stmt|;
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|struct
name|iwm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|iwm_rx_packet
modifier|*
name|pkt
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
modifier|*
name|fn_data
decl_stmt|;
name|uint16_t
name|cmds
index|[
name|IWM_MAX_NOTIF_CMDS
index|]
decl_stmt|;
name|uint8_t
name|n_cmds
decl_stmt|;
name|int
name|triggered
decl_stmt|,
name|aborted
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* caller functions */
end_comment

begin_function_decl
specifier|extern
name|struct
name|iwm_notif_wait_data
modifier|*
name|iwm_notification_wait_init
parameter_list|(
name|struct
name|iwm_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iwm_notification_wait_free
parameter_list|(
name|struct
name|iwm_notif_wait_data
modifier|*
name|notif_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iwm_notification_wait_notify
parameter_list|(
name|struct
name|iwm_notif_wait_data
modifier|*
name|notif_data
parameter_list|,
name|uint16_t
name|cmd
parameter_list|,
name|struct
name|iwm_rx_packet
modifier|*
name|pkt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iwm_abort_notification_waits
parameter_list|(
name|struct
name|iwm_notif_wait_data
modifier|*
name|notif_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* user functions */
end_comment

begin_function_decl
specifier|extern
name|void
name|iwm_init_notification_wait
parameter_list|(
name|struct
name|iwm_notif_wait_data
modifier|*
name|notif_data
parameter_list|,
name|struct
name|iwm_notification_wait
modifier|*
name|wait_entry
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|cmds
parameter_list|,
name|int
name|n_cmds
parameter_list|,
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|struct
name|iwm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|iwm_rx_packet
modifier|*
name|pkt
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
parameter_list|,
name|void
modifier|*
name|fn_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iwm_wait_notification
parameter_list|(
name|struct
name|iwm_notif_wait_data
modifier|*
name|notif_data
parameter_list|,
name|struct
name|iwm_notification_wait
modifier|*
name|wait_entry
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iwm_remove_notification
parameter_list|(
name|struct
name|iwm_notif_wait_data
modifier|*
name|notif_data
parameter_list|,
name|struct
name|iwm_notification_wait
modifier|*
name|wait_entry
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_IWN_NOTIF_WAIT_H__ */
end_comment

end_unit

