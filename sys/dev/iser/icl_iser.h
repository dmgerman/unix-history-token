begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2015, Mellanox Technologies, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ICL_ISER_H
end_ifndef

begin_define
define|#
directive|define
name|ICL_ISER_H
end_define

begin_comment
comment|/*  * iSCSI Common Layer for RDMA.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/capsicum.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<dev/iscsi/icl.h>
end_include

begin_include
include|#
directive|include
file|<dev/iscsi/iscsi_proto.h>
end_include

begin_include
include|#
directive|include
file|<icl_conn_if.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_verbs.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_fmr_pool.h>
end_include

begin_include
include|#
directive|include
file|<rdma/rdma_cm.h>
end_include

begin_define
define|#
directive|define
name|ISER_DBG
parameter_list|(
name|X
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {								\ 		if (unlikely(iser_debug> 2))				\ 			printf("DEBUG: %s: " X "\n",			\ 				__func__, ## __VA_ARGS__);		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISER_INFO
parameter_list|(
name|X
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {								\ 		if (unlikely(iser_debug> 1))				\ 			printf("INFO: %s: " X "\n",			\ 				__func__, ## __VA_ARGS__);		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISER_WARN
parameter_list|(
name|X
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {								\ 		if (unlikely(iser_debug> 0)) {				\ 			printf("WARNING: %s: " X "\n",			\ 				__func__, ## __VA_ARGS__);		\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISER_ERR
parameter_list|(
name|X
parameter_list|,
modifier|...
parameter_list|)
define|\
value|printf("ERROR: %s: " X "\n", __func__, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|ISER_VER
value|0x10
end_define

begin_define
define|#
directive|define
name|ISER_WSV
value|0x08
end_define

begin_define
define|#
directive|define
name|ISER_RSV
value|0x04
end_define

begin_define
define|#
directive|define
name|ISER_FASTREG_LI_WRID
value|0xffffffffffffffffULL
end_define

begin_define
define|#
directive|define
name|ISER_BEACON_WRID
value|0xfffffffffffffffeULL
end_define

begin_define
define|#
directive|define
name|SHIFT_4K
value|12
end_define

begin_define
define|#
directive|define
name|SIZE_4K
value|(1ULL<< SHIFT_4K)
end_define

begin_define
define|#
directive|define
name|MASK_4K
value|(~(SIZE_4K-1))
end_define

begin_comment
comment|/* support up to 512KB in one RDMA */
end_comment

begin_define
define|#
directive|define
name|ISCSI_ISER_SG_TABLESIZE
value|(0x80000>> SHIFT_4K)
end_define

begin_define
define|#
directive|define
name|ISER_DEF_XMIT_CMDS_MAX
value|256
end_define

begin_comment
comment|/* the max RX (recv) WR supported by the iSER QP is defined by                 *  * max_recv_wr = commands_max + recv_beacon                                    */
end_comment

begin_define
define|#
directive|define
name|ISER_QP_MAX_RECV_DTOS
value|(ISER_DEF_XMIT_CMDS_MAX + 1)
end_define

begin_define
define|#
directive|define
name|ISER_MIN_POSTED_RX
value|(ISER_DEF_XMIT_CMDS_MAX>> 2)
end_define

begin_comment
comment|/* QP settings */
end_comment

begin_comment
comment|/* Maximal bounds on received asynchronous PDUs */
end_comment

begin_define
define|#
directive|define
name|ISER_MAX_RX_MISC_PDUS
value|4
end_define

begin_comment
comment|/* NOOP_IN(2) , ASYNC_EVENT(2)   */
end_comment

begin_define
define|#
directive|define
name|ISER_MAX_TX_MISC_PDUS
value|6
end_define

begin_comment
comment|/* NOOP_OUT(2), TEXT(1), SCSI_TMFUNC(2), LOGOUT(1) */
end_comment

begin_comment
comment|/* the max TX (send) WR supported by the iSER QP is defined by                 *  * max_send_wr = T * (1 + D) + C ; D is how many inflight dataouts we expect   *  * to have at max for SCSI command. The tx posting& completion handling code  *  * supports -EAGAIN scheme where tx is suspended till the QP has room for more *  * send WR. D=8 comes from 64K/8K                                              */
end_comment

begin_define
define|#
directive|define
name|ISER_INFLIGHT_DATAOUTS
value|8
end_define

begin_comment
comment|/* the send_beacon increase the max_send_wr by 1  */
end_comment

begin_define
define|#
directive|define
name|ISER_QP_MAX_REQ_DTOS
value|(ISER_DEF_XMIT_CMDS_MAX *    \ 					(1 + ISER_INFLIGHT_DATAOUTS) + \ 					ISER_MAX_TX_MISC_PDUS        + \ 					ISER_MAX_RX_MISC_PDUS + 1)
end_define

begin_define
define|#
directive|define
name|ISER_GET_MAX_XMIT_CMDS
parameter_list|(
name|send_wr
parameter_list|)
value|((send_wr			\ 					 - ISER_MAX_TX_MISC_PDUS	\ 					 - ISER_MAX_RX_MISC_PDUS - 1) /	\ 					 (1 + ISER_INFLIGHT_DATAOUTS))
end_define

begin_define
define|#
directive|define
name|ISER_WC_BATCH_COUNT
value|16
end_define

begin_define
define|#
directive|define
name|ISER_SIGNAL_CMD_COUNT
value|32
end_define

begin_comment
comment|/* Maximal QP's recommended per CQ. In case we use more QP's per CQ we might   *  * encounter a CQ overrun state.                                               */
end_comment

begin_define
define|#
directive|define
name|ISCSI_ISER_MAX_CONN
value|8
end_define

begin_define
define|#
directive|define
name|ISER_MAX_RX_LEN
value|(ISER_QP_MAX_RECV_DTOS * ISCSI_ISER_MAX_CONN)
end_define

begin_define
define|#
directive|define
name|ISER_MAX_TX_LEN
value|(ISER_QP_MAX_REQ_DTOS  * ISCSI_ISER_MAX_CONN)
end_define

begin_define
define|#
directive|define
name|ISER_MAX_CQ_LEN
value|(ISER_MAX_RX_LEN + ISER_MAX_TX_LEN + \ 				 ISCSI_ISER_MAX_CONN)
end_define

begin_define
define|#
directive|define
name|ISER_ZBVA_NOT_SUPPORTED
value|0x80
end_define

begin_define
define|#
directive|define
name|ISER_SEND_W_INV_NOT_SUPPORTED
value|0x40
end_define

begin_define
define|#
directive|define
name|ISCSI_DEF_MAX_RECV_SEG_LEN
value|8192
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|icl_to_iser_conn
parameter_list|(
name|ic
parameter_list|)
define|\
value|container_of(ic, struct iser_conn, icl_conn)
end_define

begin_define
define|#
directive|define
name|icl_to_iser_pdu
parameter_list|(
name|ip
parameter_list|)
define|\
value|container_of(ip, struct icl_iser_pdu, icl_pdu)
end_define

begin_comment
comment|/**  * struct iser_hdr - iSER header  *  * @flags:        flags support (zbva, remote_inv)  * @rsvd:         reserved  * @write_stag:   write rkey  * @write_va:     write virtual address  * @reaf_stag:    read rkey  * @read_va:      read virtual address  */
end_comment

begin_struct
struct|struct
name|iser_hdr
block|{
name|u8
name|flags
decl_stmt|;
name|u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|write_stag
decl_stmt|;
name|__be64
name|write_va
decl_stmt|;
name|__be32
name|read_stag
decl_stmt|;
name|__be64
name|read_va
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|iser_cm_hdr
block|{
name|u8
name|flags
decl_stmt|;
name|u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Constant PDU lengths calculations */
end_comment

begin_define
define|#
directive|define
name|ISER_HEADERS_LEN
value|(sizeof(struct iser_hdr) + ISCSI_BHS_SIZE)
end_define

begin_define
define|#
directive|define
name|ISER_RECV_DATA_SEG_LEN
value|128
end_define

begin_define
define|#
directive|define
name|ISER_RX_PAYLOAD_SIZE
value|(ISER_HEADERS_LEN + ISER_RECV_DATA_SEG_LEN)
end_define

begin_define
define|#
directive|define
name|ISER_RX_LOGIN_SIZE
value|(ISER_HEADERS_LEN + ISCSI_DEF_MAX_RECV_SEG_LEN)
end_define

begin_enum
enum|enum
name|iser_conn_state
block|{
name|ISER_CONN_INIT
block|,
comment|/* descriptor allocd, no conn          */
name|ISER_CONN_PENDING
block|,
comment|/* in the process of being established */
name|ISER_CONN_UP
block|,
comment|/* up and running                      */
name|ISER_CONN_TERMINATING
block|,
comment|/* in the process of being terminated  */
name|ISER_CONN_DOWN
block|,
comment|/* shut down                           */
name|ISER_CONN_STATES_NUM
block|}
enum|;
end_enum

begin_enum
enum|enum
name|iser_task_status
block|{
name|ISER_TASK_STATUS_INIT
init|=
literal|0
block|,
name|ISER_TASK_STATUS_STARTED
block|,
name|ISER_TASK_STATUS_COMPLETED
block|}
enum|;
end_enum

begin_enum
enum|enum
name|iser_data_dir
block|{
name|ISER_DIR_IN
init|=
literal|0
block|,
comment|/* to initiator */
name|ISER_DIR_OUT
block|,
comment|/* from initiator */
name|ISER_DIRS_NUM
block|}
enum|;
end_enum

begin_comment
comment|/**  * struct iser_mem_reg - iSER memory registration info  *  * @sge:          memory region sg element  * @rkey:         memory region remote key  * @mem_h:        pointer to registration context (FMR/Fastreg)  */
end_comment

begin_struct
struct|struct
name|iser_mem_reg
block|{
name|struct
name|ib_sge
name|sge
decl_stmt|;
name|u32
name|rkey
decl_stmt|;
name|void
modifier|*
name|mem_h
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|iser_desc_type
block|{
name|ISCSI_TX_CONTROL
block|,
name|ISCSI_TX_SCSI_COMMAND
block|,
name|ISCSI_TX_DATAOUT
block|}
enum|;
end_enum

begin_comment
comment|/**  * struct iser_data_buf - iSER data buffer  *  * @sg:           pointer to the sg list  * @size:         num entries of this sg  * @data_len:     total beffer byte len  * @dma_nents:    returned by dma_map_sg  * @copy_buf:     allocated copy buf for SGs unaligned  *                for rdma which are copied  * @orig_sg:      pointer to the original sg list (in case  *                we used a copy)  * @sg_single:    SG-ified clone of a non SG SC or  *                unaligned SG  */
end_comment

begin_struct
struct|struct
name|iser_data_buf
block|{
name|struct
name|scatterlist
name|sgl
index|[
name|ISCSI_ISER_SG_TABLESIZE
index|]
decl_stmt|;
name|void
modifier|*
name|sg
decl_stmt|;
name|int
name|size
decl_stmt|;
name|unsigned
name|long
name|data_len
decl_stmt|;
name|unsigned
name|int
name|dma_nents
decl_stmt|;
name|char
modifier|*
name|copy_buf
decl_stmt|;
name|struct
name|scatterlist
modifier|*
name|orig_sg
decl_stmt|;
name|struct
name|scatterlist
name|sg_single
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* fwd declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|iser_conn
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ib_conn
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iser_device
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct iser_tx_desc - iSER TX descriptor (for send wr_id)  *  * @iser_header:   iser header  * @iscsi_header:  iscsi header (bhs)  * @type:          command/control/dataout  * @dma_addr:      header buffer dma_address  * @tx_sg:         sg[0] points to iser/iscsi headers  *                 sg[1] optionally points to either of immediate data  *                 unsolicited data-out or control  * @num_sge:       number sges used on this TX task  * @mapped:        indicates if the descriptor is dma mapped  */
end_comment

begin_struct
struct|struct
name|iser_tx_desc
block|{
name|struct
name|iser_hdr
name|iser_header
decl_stmt|;
name|struct
name|iscsi_bhs
name|iscsi_header
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|enum
name|iser_desc_type
name|type
decl_stmt|;
name|u64
name|dma_addr
decl_stmt|;
name|struct
name|ib_sge
name|tx_sg
index|[
literal|2
index|]
decl_stmt|;
name|int
name|num_sge
decl_stmt|;
name|bool
name|mapped
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISER_RX_PAD_SIZE
value|(256 - (ISER_RX_PAYLOAD_SIZE + \ 					sizeof(u64) + sizeof(struct ib_sge)))
end_define

begin_comment
comment|/**  * struct iser_rx_desc - iSER RX descriptor (for recv wr_id)  *  * @iser_header:   iser header  * @iscsi_header:  iscsi header  * @data:          received data segment  * @dma_addr:      receive buffer dma address  * @rx_sg:         ib_sge of receive buffer  * @pad:           for sense data TODO: Modify to maximum sense length supported  */
end_comment

begin_struct
struct|struct
name|iser_rx_desc
block|{
name|struct
name|iser_hdr
name|iser_header
decl_stmt|;
name|struct
name|iscsi_bhs
name|iscsi_header
decl_stmt|;
name|char
name|data
index|[
name|ISER_RECV_DATA_SEG_LEN
index|]
decl_stmt|;
name|u64
name|dma_addr
decl_stmt|;
name|struct
name|ib_sge
name|rx_sg
decl_stmt|;
name|char
name|pad
index|[
name|ISER_RX_PAD_SIZE
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|icl_iser_pdu
block|{
name|struct
name|icl_pdu
name|icl_pdu
decl_stmt|;
name|struct
name|iser_tx_desc
name|desc
decl_stmt|;
name|struct
name|iser_conn
modifier|*
name|iser_conn
decl_stmt|;
name|enum
name|iser_task_status
name|status
decl_stmt|;
name|struct
name|ccb_scsiio
modifier|*
name|csio
decl_stmt|;
name|int
name|command_sent
decl_stmt|;
name|int
name|dir
index|[
name|ISER_DIRS_NUM
index|]
decl_stmt|;
name|struct
name|iser_mem_reg
name|rdma_reg
index|[
name|ISER_DIRS_NUM
index|]
decl_stmt|;
name|struct
name|iser_data_buf
name|data
index|[
name|ISER_DIRS_NUM
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct iser_comp - iSER completion context  *  * @device:     pointer to device handle  * @cq:         completion queue  * @wcs:        work completion array  * @tq:    	taskqueue handle  * @task:    	task to run task_fn  * @active_qps: Number of active QPs attached  *              to completion context  */
end_comment

begin_struct
struct|struct
name|iser_comp
block|{
name|struct
name|iser_device
modifier|*
name|device
decl_stmt|;
name|struct
name|ib_cq
modifier|*
name|cq
decl_stmt|;
name|struct
name|ib_wc
name|wcs
index|[
name|ISER_WC_BATCH_COUNT
index|]
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
name|struct
name|task
name|task
decl_stmt|;
name|int
name|active_qps
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct iser_device - iSER device handle  *  * @ib_device:     RDMA device  * @pd:            Protection Domain for this device  * @dev_attr:      Device attributes container  * @mr:            Global DMA memory region  * @event_handler: IB events handle routine  * @ig_list:	   entry in devices list  * @refcount:      Reference counter, dominated by open iser connections  * @comps_used:    Number of completion contexts used, Min between online  *                 cpus and device max completion vectors  * @comps:         Dinamically allocated array of completion handlers  */
end_comment

begin_struct
struct|struct
name|iser_device
block|{
name|struct
name|ib_device
modifier|*
name|ib_device
decl_stmt|;
name|struct
name|ib_pd
modifier|*
name|pd
decl_stmt|;
name|struct
name|ib_device_attr
name|dev_attr
decl_stmt|;
name|struct
name|ib_mr
modifier|*
name|mr
decl_stmt|;
name|struct
name|ib_event_handler
name|event_handler
decl_stmt|;
name|struct
name|list_head
name|ig_list
decl_stmt|;
name|int
name|refcount
decl_stmt|;
name|int
name|comps_used
decl_stmt|;
name|struct
name|iser_comp
modifier|*
name|comps
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct iser_reg_resources - Fast registration recources  *  * @mr:         memory region  * @mr_valid:   is mr valid indicator  */
end_comment

begin_struct
struct|struct
name|iser_reg_resources
block|{
name|struct
name|ib_mr
modifier|*
name|mr
decl_stmt|;
name|u8
name|mr_valid
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct fast_reg_descriptor - Fast registration descriptor  *  * @list:           entry in connection fastreg pool  * @rsc:            data buffer registration resources  */
end_comment

begin_struct
struct|struct
name|fast_reg_descriptor
block|{
name|struct
name|list_head
name|list
decl_stmt|;
name|struct
name|iser_reg_resources
name|rsc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct iser_beacon - beacon to signal all flush errors were drained  *  * @send:           send wr  * @recv:           recv wr  * @flush_lock:     protects flush_cv  * @flush_cv:       condition variable for beacon flush  */
end_comment

begin_struct
struct|struct
name|iser_beacon
block|{
union|union
block|{
name|struct
name|ib_send_wr
name|send
decl_stmt|;
name|struct
name|ib_recv_wr
name|recv
decl_stmt|;
block|}
union|;
name|struct
name|mtx
name|flush_lock
decl_stmt|;
name|struct
name|cv
name|flush_cv
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct ib_conn - Infiniband related objects  *  * @cma_id:              rdma_cm connection maneger handle  * @qp:                  Connection Queue-pair  * @device:              reference to iser device  * @comp:                iser completion context   */
end_comment

begin_struct
struct|struct
name|ib_conn
block|{
name|struct
name|rdma_cm_id
modifier|*
name|cma_id
decl_stmt|;
name|struct
name|ib_qp
modifier|*
name|qp
decl_stmt|;
name|int
name|post_recv_buf_count
decl_stmt|;
name|u8
name|sig_count
decl_stmt|;
name|struct
name|ib_recv_wr
name|rx_wr
index|[
name|ISER_MIN_POSTED_RX
index|]
decl_stmt|;
name|struct
name|iser_device
modifier|*
name|device
decl_stmt|;
name|struct
name|iser_comp
modifier|*
name|comp
decl_stmt|;
name|struct
name|iser_beacon
name|beacon
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|struct
name|ib_fmr_pool
modifier|*
name|pool
decl_stmt|;
name|struct
name|iser_page_vec
modifier|*
name|page_vec
decl_stmt|;
block|}
name|fmr
struct|;
struct|struct
block|{
name|struct
name|list_head
name|pool
decl_stmt|;
name|int
name|pool_size
decl_stmt|;
block|}
name|fastreg
struct|;
block|}
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iser_conn
block|{
name|struct
name|icl_conn
name|icl_conn
decl_stmt|;
name|struct
name|ib_conn
name|ib_conn
decl_stmt|;
name|struct
name|cv
name|up_cv
decl_stmt|;
name|struct
name|list_head
name|conn_list
decl_stmt|;
name|struct
name|sx
name|state_mutex
decl_stmt|;
name|enum
name|iser_conn_state
name|state
decl_stmt|;
name|int
name|qp_max_recv_dtos
decl_stmt|;
name|int
name|min_posted_rx
decl_stmt|;
name|u16
name|max_cmds
decl_stmt|;
name|char
modifier|*
name|login_buf
decl_stmt|;
name|char
modifier|*
name|login_req_buf
decl_stmt|,
modifier|*
name|login_resp_buf
decl_stmt|;
name|u64
name|login_req_dma
decl_stmt|,
name|login_resp_dma
decl_stmt|;
name|unsigned
name|int
name|rx_desc_head
decl_stmt|;
name|struct
name|iser_rx_desc
modifier|*
name|rx_descs
decl_stmt|;
name|u32
name|num_rx_descs
decl_stmt|;
name|bool
name|handoff_done
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct iser_global: iSER global context  *  * @device_list_mutex:    protects device_list  * @device_list:          iser devices global list  * @connlist_mutex:       protects connlist  * @connlist:             iser connections global list  * @desc_cache:           kmem cache for tx dataout  * @close_conns_mutex:    serializes conns closure  */
end_comment

begin_struct
struct|struct
name|iser_global
block|{
name|struct
name|sx
name|device_list_mutex
decl_stmt|;
name|struct
name|list_head
name|device_list
decl_stmt|;
name|struct
name|mtx
name|connlist_mutex
decl_stmt|;
name|struct
name|list_head
name|connlist
decl_stmt|;
name|struct
name|sx
name|close_conns_mutex
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|iser_global
name|ig
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iser_debug
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|iser_create_send_desc
parameter_list|(
name|struct
name|iser_conn
modifier|*
parameter_list|,
name|struct
name|iser_tx_desc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_post_recvl
parameter_list|(
name|struct
name|iser_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_post_recvm
parameter_list|(
name|struct
name|iser_conn
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_alloc_login_buf
parameter_list|(
name|struct
name|iser_conn
modifier|*
name|iser_conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iser_free_login_buf
parameter_list|(
name|struct
name|iser_conn
modifier|*
name|iser_conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_post_send
parameter_list|(
name|struct
name|ib_conn
modifier|*
parameter_list|,
name|struct
name|iser_tx_desc
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iser_snd_completion
parameter_list|(
name|struct
name|iser_tx_desc
modifier|*
parameter_list|,
name|struct
name|ib_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iser_rcv_completion
parameter_list|(
name|struct
name|iser_rx_desc
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|struct
name|ib_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iser_pdu_free
parameter_list|(
name|struct
name|icl_conn
modifier|*
parameter_list|,
name|struct
name|icl_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|icl_pdu
modifier|*
name|iser_new_pdu
parameter_list|(
name|struct
name|icl_conn
modifier|*
name|ic
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_alloc_rx_descriptors
parameter_list|(
name|struct
name|iser_conn
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iser_free_rx_descriptors
parameter_list|(
name|struct
name|iser_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_initialize_headers
parameter_list|(
name|struct
name|icl_iser_pdu
modifier|*
parameter_list|,
name|struct
name|iser_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_send_control
parameter_list|(
name|struct
name|iser_conn
modifier|*
parameter_list|,
name|struct
name|icl_iser_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_send_command
parameter_list|(
name|struct
name|iser_conn
modifier|*
parameter_list|,
name|struct
name|icl_iser_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_reg_rdma_mem
parameter_list|(
name|struct
name|icl_iser_pdu
modifier|*
parameter_list|,
name|enum
name|iser_data_dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iser_unreg_rdma_mem
parameter_list|(
name|struct
name|icl_iser_pdu
modifier|*
parameter_list|,
name|enum
name|iser_data_dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_create_fastreg_pool
parameter_list|(
name|struct
name|ib_conn
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iser_free_fastreg_pool
parameter_list|(
name|struct
name|ib_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_dma_map_task_data
parameter_list|(
name|struct
name|icl_iser_pdu
modifier|*
parameter_list|,
name|struct
name|iser_data_buf
modifier|*
parameter_list|,
name|enum
name|iser_data_dir
parameter_list|,
name|enum
name|dma_data_direction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_conn_terminate
parameter_list|(
name|struct
name|iser_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iser_free_ib_conn_res
parameter_list|(
name|struct
name|iser_conn
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iser_dma_unmap_task_data
parameter_list|(
name|struct
name|icl_iser_pdu
modifier|*
parameter_list|,
name|struct
name|iser_data_buf
modifier|*
parameter_list|,
name|enum
name|dma_data_direction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iser_cma_handler
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
parameter_list|,
name|struct
name|rdma_cm_event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ICL_ISER_H */
end_comment

end_unit

