begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (c) 2007, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CXGB3_OFFLOAD_CTL_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|_CXGB3_OFFLOAD_CTL_DEFS_H
end_define

begin_enum
enum|enum
block|{
name|GET_MAX_OUTSTANDING_WR
block|,
name|GET_TX_MAX_CHUNK
block|,
name|GET_TID_RANGE
block|,
name|GET_STID_RANGE
block|,
name|GET_RTBL_RANGE
block|,
name|GET_L2T_CAPACITY
block|,
name|GET_MTUS
block|,
name|GET_WR_LEN
block|,
name|GET_IFF_FROM_MAC
block|,
name|GET_DDP_PARAMS
block|,
name|GET_PORTS
block|,
name|ULP_ISCSI_GET_PARAMS
block|,
name|ULP_ISCSI_SET_PARAMS
block|,
name|RDMA_GET_PARAMS
block|,
name|RDMA_CQ_OP
block|,
name|RDMA_CQ_SETUP
block|,
name|RDMA_CQ_DISABLE
block|,
name|RDMA_CTRL_QP_SETUP
block|,
name|RDMA_GET_MEM
block|,
name|FAILOVER
init|=
literal|30
block|,
name|FAILOVER_DONE
init|=
literal|31
block|,
name|FAILOVER_CLEAR
init|=
literal|32
block|,
name|GET_CPUIDX_OF_QSET
init|=
literal|40
block|,
name|GET_RX_PAGE_INFO
init|=
literal|50
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Structure used to describe a TID range.  Valid TIDs are [base, base+num).  */
end_comment

begin_struct
struct|struct
name|tid_range
block|{
name|unsigned
name|int
name|base
decl_stmt|;
comment|/* first TID */
name|unsigned
name|int
name|num
decl_stmt|;
comment|/* number of TIDs in range */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to request the size and contents of the MTU table.  */
end_comment

begin_struct
struct|struct
name|mtutab
block|{
name|unsigned
name|int
name|size
decl_stmt|;
comment|/* # of entries in the MTU table */
specifier|const
name|unsigned
name|short
modifier|*
name|mtus
decl_stmt|;
comment|/* the MTU table values */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|net_device
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Structure used to request the adapter net_device owning a given MAC address.  */
end_comment

begin_struct
struct|struct
name|iff_mac
block|{
name|struct
name|net_device
modifier|*
name|dev
decl_stmt|;
comment|/* the net_device */
specifier|const
name|unsigned
name|char
modifier|*
name|mac_addr
decl_stmt|;
comment|/* MAC address to lookup */
name|u16
name|vlan_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|pci_dev
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Structure used to request the TCP DDP parameters.  */
end_comment

begin_struct
struct|struct
name|ddp_params
block|{
name|unsigned
name|int
name|llimit
decl_stmt|;
comment|/* TDDP region start address */
name|unsigned
name|int
name|ulimit
decl_stmt|;
comment|/* TDDP region end address */
name|unsigned
name|int
name|tag_mask
decl_stmt|;
comment|/* TDDP tag mask */
name|struct
name|pci_dev
modifier|*
name|pdev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adap_ports
block|{
name|unsigned
name|int
name|nports
decl_stmt|;
comment|/* number of ports on this adapter */
name|struct
name|net_device
modifier|*
name|lldevs
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to return information to the iscsi layer.  */
end_comment

begin_struct
struct|struct
name|ulp_iscsi_info
block|{
name|unsigned
name|int
name|offset
decl_stmt|;
name|unsigned
name|int
name|llimit
decl_stmt|;
name|unsigned
name|int
name|ulimit
decl_stmt|;
name|unsigned
name|int
name|tagmask
decl_stmt|;
name|unsigned
name|int
name|pgsz3
decl_stmt|;
name|unsigned
name|int
name|pgsz2
decl_stmt|;
name|unsigned
name|int
name|pgsz1
decl_stmt|;
name|unsigned
name|int
name|pgsz0
decl_stmt|;
name|unsigned
name|int
name|max_rxsz
decl_stmt|;
name|unsigned
name|int
name|max_txsz
decl_stmt|;
name|struct
name|pci_dev
modifier|*
name|pdev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Offload TX/RX page information.  */
end_comment

begin_struct
struct|struct
name|ofld_page_info
block|{
name|unsigned
name|int
name|page_size
decl_stmt|;
comment|/* Page size, should be a power of 2 */
name|unsigned
name|int
name|num
decl_stmt|;
comment|/* Number of pages */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to return information to the RDMA layer.  */
end_comment

begin_struct
struct|struct
name|rdma_info
block|{
name|unsigned
name|int
name|tpt_base
decl_stmt|;
comment|/* TPT base address */
name|unsigned
name|int
name|tpt_top
decl_stmt|;
comment|/* TPT last entry address */
name|unsigned
name|int
name|pbl_base
decl_stmt|;
comment|/* PBL base address */
name|unsigned
name|int
name|pbl_top
decl_stmt|;
comment|/* PBL last entry address */
name|unsigned
name|int
name|rqt_base
decl_stmt|;
comment|/* RQT base address */
name|unsigned
name|int
name|rqt_top
decl_stmt|;
comment|/* RQT last entry address */
name|unsigned
name|int
name|udbell_len
decl_stmt|;
comment|/* user doorbell region length */
name|unsigned
name|long
name|udbell_physbase
decl_stmt|;
comment|/* user doorbell physical start addr */
name|void
specifier|volatile
modifier|*
name|kdb_addr
decl_stmt|;
comment|/* kernel doorbell register address */
name|struct
name|pci_dev
modifier|*
name|pdev
decl_stmt|;
comment|/* associated PCI device */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to request an operation on an RDMA completion queue.  */
end_comment

begin_struct
struct|struct
name|rdma_cq_op
block|{
name|unsigned
name|int
name|id
decl_stmt|;
name|unsigned
name|int
name|op
decl_stmt|;
name|unsigned
name|int
name|credits
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to setup RDMA completion queues.  */
end_comment

begin_struct
struct|struct
name|rdma_cq_setup
block|{
name|unsigned
name|int
name|id
decl_stmt|;
name|unsigned
name|long
name|long
name|base_addr
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
name|unsigned
name|int
name|credits
decl_stmt|;
name|unsigned
name|int
name|credit_thres
decl_stmt|;
name|unsigned
name|int
name|ovfl_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to setup the RDMA control egress context.  */
end_comment

begin_struct
struct|struct
name|rdma_ctrlqp_setup
block|{
name|unsigned
name|long
name|long
name|base_addr
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CXGB3_OFFLOAD_CTL_DEFS_H */
end_comment

end_unit

