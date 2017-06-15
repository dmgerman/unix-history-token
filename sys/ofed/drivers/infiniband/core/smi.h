begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Mellanox Technologies Ltd.  All rights reserved.  * Copyright (c) 2004 Infinicon Corporation.  All rights reserved.  * Copyright (c) 2004 Intel Corporation.  All rights reserved.  * Copyright (c) 2004 Topspin Corporation.  All rights reserved.  * Copyright (c) 2004-2007 Voltaire Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMI_H_
end_ifndef

begin_define
define|#
directive|define
name|__SMI_H_
end_define

begin_include
include|#
directive|include
file|<rdma/ib_smi.h>
end_include

begin_enum
enum|enum
name|smi_action
block|{
name|IB_SMI_DISCARD
block|,
name|IB_SMI_HANDLE
block|}
enum|;
end_enum

begin_enum
enum|enum
name|smi_forward_action
block|{
name|IB_SMI_LOCAL
block|,
comment|/* SMP should be completed up the stack */
name|IB_SMI_SEND
block|,
comment|/* received DR SMP should be forwarded to the send queue */
name|IB_SMI_FORWARD
comment|/* SMP should be forwarded (for switches only) */
block|}
enum|;
end_enum

begin_function_decl
name|enum
name|smi_action
name|smi_handle_dr_smp_recv
parameter_list|(
name|struct
name|ib_smp
modifier|*
name|smp
parameter_list|,
name|bool
name|is_switch
parameter_list|,
name|int
name|port_num
parameter_list|,
name|int
name|phys_port_cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smi_get_fwd_port
parameter_list|(
name|struct
name|ib_smp
modifier|*
name|smp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|smi_forward_action
name|smi_check_forward_dr_smp
parameter_list|(
name|struct
name|ib_smp
modifier|*
name|smp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|smi_action
name|smi_handle_dr_smp_send
parameter_list|(
name|struct
name|ib_smp
modifier|*
name|smp
parameter_list|,
name|bool
name|is_switch
parameter_list|,
name|int
name|port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return IB_SMI_HANDLE if the SMP should be handled by the local SMA/SM  * via process_mad  */
end_comment

begin_function
specifier|static
specifier|inline
name|enum
name|smi_action
name|smi_check_local_smp
parameter_list|(
name|struct
name|ib_smp
modifier|*
name|smp
parameter_list|,
name|struct
name|ib_device
modifier|*
name|device
parameter_list|)
block|{
comment|/* C14-9:3 -- We're at the end of the DR segment of path */
comment|/* C14-9:4 -- Hop Pointer = Hop Count + 1 -> give to SMA/SM */
return|return
operator|(
operator|(
name|device
operator|->
name|process_mad
operator|&&
operator|!
name|ib_get_smp_direction
argument_list|(
name|smp
argument_list|)
operator|&&
operator|(
name|smp
operator|->
name|hop_ptr
operator|==
name|smp
operator|->
name|hop_cnt
operator|+
literal|1
operator|)
operator|)
condition|?
name|IB_SMI_HANDLE
else|:
name|IB_SMI_DISCARD
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return IB_SMI_HANDLE if the SMP should be handled by the local SMA/SM  * via process_mad  */
end_comment

begin_function
specifier|static
specifier|inline
name|enum
name|smi_action
name|smi_check_local_returning_smp
parameter_list|(
name|struct
name|ib_smp
modifier|*
name|smp
parameter_list|,
name|struct
name|ib_device
modifier|*
name|device
parameter_list|)
block|{
comment|/* C14-13:3 -- We're at the end of the DR segment of path */
comment|/* C14-13:4 -- Hop Pointer == 0 -> give to SM */
return|return
operator|(
operator|(
name|device
operator|->
name|process_mad
operator|&&
name|ib_get_smp_direction
argument_list|(
name|smp
argument_list|)
operator|&&
operator|!
name|smp
operator|->
name|hop_ptr
operator|)
condition|?
name|IB_SMI_HANDLE
else|:
name|IB_SMI_DISCARD
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SMI_H_ */
end_comment

end_unit

