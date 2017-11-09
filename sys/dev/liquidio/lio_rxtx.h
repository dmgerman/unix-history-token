begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIO_RXTX_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIO_RXTX_H_
end_define

begin_comment
comment|/* Bit mask values for lio->ifstate */
end_comment

begin_define
define|#
directive|define
name|LIO_IFSTATE_DROQ_OPS
value|0x01
end_define

begin_define
define|#
directive|define
name|LIO_IFSTATE_REGISTERED
value|0x02
end_define

begin_define
define|#
directive|define
name|LIO_IFSTATE_RUNNING
value|0x04
end_define

begin_define
define|#
directive|define
name|LIO_IFSTATE_DETACH
value|0x08
end_define

begin_define
define|#
directive|define
name|LIO_IFSTATE_RESETTING
value|0x10
end_define

begin_comment
comment|/*  * Structure of a node in list of gather components maintained by  * NIC driver for each network device.  */
end_comment

begin_struct
struct|struct
name|lio_gather
block|{
comment|/* List manipulation. Next and prev pointers. */
name|struct
name|lio_stailq_node
name|node
decl_stmt|;
comment|/* Size of the gather component at sg in bytes. */
name|int
name|sg_size
decl_stmt|;
comment|/* 	 * Gather component that can accommodate max sized fragment list 	 * received from the IP layer. 	 */
name|struct
name|lio_sg_entry
modifier|*
name|sg
decl_stmt|;
name|uint64_t
name|sg_dma_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|lio_tx_info
block|{
name|uint64_t
name|tx_info64
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
name|uint16_t
name|gso_size
decl_stmt|;
name|uint16_t
name|gso_segs
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
else|#
directive|else
comment|/* _BYTE_ORDER == _LITTLE_ENDIAN */
name|uint32_t
name|reserved
decl_stmt|;
name|uint16_t
name|gso_segs
decl_stmt|;
name|uint16_t
name|gso_size
decl_stmt|;
endif|#
directive|endif
block|}
name|s
struct|;
block|}
union|;
end_union

begin_function_decl
name|int
name|lio_xmit
parameter_list|(
name|struct
name|lio
modifier|*
name|lio
parameter_list|,
name|struct
name|lio_instr_queue
modifier|*
name|iq
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|m_headp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_mq_start_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|lio_instr_queue
modifier|*
name|iq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_mq_start
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lio_qflush
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIO_RXTX_H_ */
end_comment

end_unit

