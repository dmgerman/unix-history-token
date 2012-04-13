begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010-2011 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File: qla_glbl.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  * Content: Contains prototypes of the exported functions from each file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QLA_GLBL_H_
end_ifndef

begin_define
define|#
directive|define
name|_QLA_GLBL_H_
end_define

begin_comment
comment|/*  * from qla_isr.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|qla_isr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_rcv
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|int
name|pending
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * from qla_os.c  */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|std_replenish
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|jumbo_replenish
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|rcv_pkt_thres
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|rcv_pkt_thres_d
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|snd_pkt_thres
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|free_pkt_thres
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|qla_alloc_dmabuf
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|qla_dma_t
modifier|*
name|dma_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_free_dmabuf
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|qla_dma_t
modifier|*
name|dma_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_start
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_get_mbuf
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|qla_rx_buf_t
modifier|*
name|rxb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|nmp
parameter_list|,
name|uint32_t
name|jumbo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * from qla_flash.c  */
end_comment

begin_function_decl
specifier|extern
name|int
name|qla_flash_rd32_words
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|,
name|uint32_t
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_flash_rd32
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * from qla_hw.c  */
end_comment

begin_function_decl
specifier|extern
name|int
name|qla_get_msix_count
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_alloc_dma
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_free_dma
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_hw_add_sysctls
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_hw_send
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
name|nsegs
parameter_list|,
name|uint32_t
modifier|*
name|tx_idx
parameter_list|,
name|struct
name|mbuf
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_init_hw_if
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_get_hw_caps
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_hw_set_multi
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|uint8_t
modifier|*
name|mta
parameter_list|,
name|uint32_t
name|mcnt
parameter_list|,
name|uint32_t
name|add_multi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_del_hw_if
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_set_promisc
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_set_allmulti
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_reset_promisc_allmulti
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_config_ipv4_addr
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|uint32_t
name|ipv4_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_hw_tx_compl
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_update_link_state
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_hw_tx_done
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_config_lro
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_free_lro
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_set_max_mtu
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|uint32_t
name|mtu
parameter_list|,
name|uint16_t
name|cntxt_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_hw_stop_rcv
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * from qla_misc.c  */
end_comment

begin_function_decl
specifier|extern
name|int
name|qla_init_hw
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_rdwr_indreg32
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|,
name|uint32_t
name|rd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_rd_flash32
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|uint32_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * from qla_ioctl.c  */
end_comment

begin_function_decl
specifier|extern
name|int
name|qla_make_cdev
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qla_del_cdev
parameter_list|(
name|qla_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qla_eioctl
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef_QLA_GLBL_H_ */
end_comment

end_unit

