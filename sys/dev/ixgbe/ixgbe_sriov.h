begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2017, Intel Corporation   All rights reserved.    Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions are met:     1. Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.     2. Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.     3. Neither the name of the Intel Corporation nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGBE_SRIOV_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_SRIOV_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PCI_IOV
end_ifdef

begin_include
include|#
directive|include
file|<sys/nv.h>
end_include

begin_include
include|#
directive|include
file|<sys/iov_schema.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pci_iov.h>
end_include

begin_include
include|#
directive|include
file|"ixgbe_mbx.h"
end_include

begin_define
define|#
directive|define
name|IXGBE_VF_CTS
value|(1<< 0)
end_define

begin_comment
comment|/* VF is clear to send. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_CAP_MAC
value|(1<< 1)
end_define

begin_comment
comment|/* VF is permitted to change MAC. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_CAP_VLAN
value|(1<< 2)
end_define

begin_comment
comment|/* VF is permitted to join vlans. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_ACTIVE
value|(1<< 3)
end_define

begin_comment
comment|/* VF is active. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_INDEX
parameter_list|(
name|vmdq
parameter_list|)
value|((vmdq) / 32)
end_define

begin_define
define|#
directive|define
name|IXGBE_VF_BIT
parameter_list|(
name|vmdq
parameter_list|)
value|(1<< ((vmdq) % 32))
end_define

begin_define
define|#
directive|define
name|IXGBE_VT_MSG_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|IXGBE_VT_MSGINFO
parameter_list|(
name|msg
parameter_list|)
define|\
value|(((msg)& IXGBE_VT_MSGINFO_MASK)>> IXGBE_VT_MSGINFO_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_VF_GET_QUEUES_RESP_LEN
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_API_VER_1_0
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_API_VER_2_0
value|1
end_define

begin_comment
comment|/* Solaris API.  Not supported. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_API_VER_1_1
value|2
end_define

begin_define
define|#
directive|define
name|IXGBE_API_VER_UNKNOWN
value|UINT16_MAX
end_define

begin_define
define|#
directive|define
name|IXGBE_NO_VM
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_32_VM
value|32
end_define

begin_define
define|#
directive|define
name|IXGBE_64_VM
value|64
end_define

begin_function_decl
name|int
name|ixgbe_add_vf
parameter_list|(
name|device_t
parameter_list|,
name|u16
parameter_list|,
specifier|const
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixgbe_init_iov
parameter_list|(
name|device_t
parameter_list|,
name|u16
parameter_list|,
specifier|const
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_uninit_iov
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_initialize_iov
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_recalculate_max_frame
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_ping_all_vfs
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixgbe_pci_iov_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_define_iov_schemas
parameter_list|(
name|device_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_align_all_queue_indices
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u32
name|ixgbe_get_mtqc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u32
name|ixgbe_get_mrqc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************/
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PCI_IOV */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ixgbe_add_vf
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ixgbe_init_iov
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ixgbe_uninit_iov
parameter_list|(
name|_a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ixgbe_initialize_iov
parameter_list|(
name|_a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ixgbe_recalculate_max_frame
parameter_list|(
name|_a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ixgbe_ping_all_vfs
parameter_list|(
name|_a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ixgbe_pci_iov_detach
parameter_list|(
name|_a
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|ixgbe_define_iov_schemas
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ixgbe_align_all_queue_indices
parameter_list|(
name|_a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ixgbe_get_mtqc
parameter_list|(
name|_a
parameter_list|)
value|IXGBE_MTQC_64Q_1PB
end_define

begin_define
define|#
directive|define
name|ixgbe_get_mrqc
parameter_list|(
name|_a
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCI_IOV */
end_comment

begin_function_decl
name|void
name|ixgbe_handle_mbx
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixgbe_vf_que_index
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

