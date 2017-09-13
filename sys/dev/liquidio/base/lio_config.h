begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/*  \file  lio_config.h  *  \brief Host Driver: Configuration data structures for the host driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIO_CONFIG_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIO_CONFIG_H__
end_define

begin_comment
comment|/*--------------------------CONFIG VALUES------------------------*/
end_comment

begin_comment
comment|/*  * The following macros affect the way the driver data structures  * are generated for Octeon devices.  * They can be modified.  */
end_comment

begin_comment
comment|/*  * Maximum octeon devices defined as LIO_MAX_IF to support  * multiple(<= LIO_MAX_IF) Miniports  */
end_comment

begin_define
define|#
directive|define
name|LIO_MAX_IF
value|128
end_define

begin_define
define|#
directive|define
name|LIO_MAX_DEVICES
value|LIO_MAX_IF
end_define

begin_define
define|#
directive|define
name|LIO_MAX_MULTICAST_ADDR
value|32
end_define

begin_comment
comment|/* CN23xx IQ configuration macros */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PF_MAX_RINGS
value|64
end_define

begin_define
define|#
directive|define
name|LIO_BR_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PF_MAX_INPUT_QUEUES
value|LIO_CN23XX_PF_MAX_RINGS
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_MAX_IQ_DESCRIPTORS
value|2048
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_DEFAULT_IQ_DESCRIPTORS
value|512
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_MIN_IQ_DESCRIPTORS
value|128
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_DB_MIN
value|1
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_DB_TIMEOUT
value|1
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PF_MAX_OUTPUT_QUEUES
value|LIO_CN23XX_PF_MAX_RINGS
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_MAX_OQ_DESCRIPTORS
value|2048
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_DEFAULT_OQ_DESCRIPTORS
value|512
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_MIN_OQ_DESCRIPTORS
value|128
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_OQ_BUF_SIZE
value|MCLBYTES
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_OQ_PKTS_PER_INTR
value|128
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_OQ_REFIL_THRESHOLD
value|16
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_OQ_INTR_PKT
value|64
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_OQ_INTR_TIME
value|100
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_DEFAULT_NUM_PORTS
value|1
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_CFG_IO_QUEUES
value|LIO_CN23XX_PF_MAX_RINGS
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_DEF_IQ_INTR_THRESHOLD
value|32
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKI_MAX_FRAME_SIZE
value|65535
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_RAW_FRONT_SIZE
value|48
end_define

begin_comment
comment|/*  * this is the max jabber value.Any packets greater than this size sent over  * DPI will be truncated.  */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_MAX_INPUT_JABBER
value|(LIO_CN23XX_PKI_MAX_FRAME_SIZE - \ 				      LIO_CN23XX_RAW_FRONT_SIZE)
end_define

begin_comment
comment|/* common OCTEON configuration macros */
end_comment

begin_define
define|#
directive|define
name|LIO_64BYTE_INSTR
value|64
end_define

begin_define
define|#
directive|define
name|LIO_MAX_TXQS_PER_INTF
value|8
end_define

begin_define
define|#
directive|define
name|LIO_MAX_RXQS_PER_INTF
value|8
end_define

begin_define
define|#
directive|define
name|LIO_DEF_TXQS_PER_INTF
value|4
end_define

begin_define
define|#
directive|define
name|LIO_DEF_RXQS_PER_INTF
value|4
end_define

begin_comment
comment|/* Macros to get octeon config params */
end_comment

begin_define
define|#
directive|define
name|LIO_GET_IQ_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->iq)
end_define

begin_define
define|#
directive|define
name|LIO_GET_IQ_MAX_Q_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->iq.max_iqs)
end_define

begin_define
define|#
directive|define
name|LIO_GET_IQ_INSTR_TYPE_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->iq.instr_type)
end_define

begin_define
define|#
directive|define
name|LIO_GET_IQ_INTR_PKT_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->iq.iq_intr_pkt)
end_define

begin_define
define|#
directive|define
name|LIO_GET_OQ_MAX_Q_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->oq.max_oqs)
end_define

begin_define
define|#
directive|define
name|LIO_GET_OQ_PKTS_PER_INTR_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->oq.pkts_per_intr)
end_define

begin_define
define|#
directive|define
name|LIO_GET_OQ_REFILL_THRESHOLD_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->oq.refill_threshold)
end_define

begin_define
define|#
directive|define
name|LIO_GET_OQ_INTR_PKT_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->oq.oq_intr_pkt)
end_define

begin_define
define|#
directive|define
name|LIO_GET_OQ_INTR_TIME_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->oq.oq_intr_time)
end_define

begin_define
define|#
directive|define
name|LIO_GET_NUM_NIC_PORTS_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->num_nic_ports)
end_define

begin_define
define|#
directive|define
name|LIO_GET_NUM_DEF_TX_DESCS_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->num_def_tx_descs)
end_define

begin_define
define|#
directive|define
name|LIO_GET_NUM_DEF_RX_DESCS_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->num_def_rx_descs)
end_define

begin_define
define|#
directive|define
name|LIO_GET_DEF_RX_BUF_SIZE_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->def_rx_buf_size)
end_define

begin_define
define|#
directive|define
name|LIO_GET_NUM_RX_DESCS_NIC_IF_CFG
parameter_list|(
name|cfg
parameter_list|,
name|idx
parameter_list|)
define|\
value|((cfg)->nic_if_cfg[idx].num_rx_descs)
end_define

begin_define
define|#
directive|define
name|LIO_GET_NUM_TX_DESCS_NIC_IF_CFG
parameter_list|(
name|cfg
parameter_list|,
name|idx
parameter_list|)
define|\
value|((cfg)->nic_if_cfg[idx].num_tx_descs)
end_define

begin_define
define|#
directive|define
name|LIO_GET_NUM_RX_BUF_SIZE_NIC_IF_CFG
parameter_list|(
name|cfg
parameter_list|,
name|idx
parameter_list|)
define|\
value|((cfg)->nic_if_cfg[idx].rx_buf_size)
end_define

begin_define
define|#
directive|define
name|LIO_GET_IS_SLI_BP_ON_CFG
parameter_list|(
name|cfg
parameter_list|)
value|((cfg)->misc.enable_sli_oq_bp)
end_define

begin_comment
comment|/* Max IOQs per OCTEON Link */
end_comment

begin_define
define|#
directive|define
name|LIO_MAX_IOQS_PER_NICIF
value|64
end_define

begin_define
define|#
directive|define
name|LIO_SET_NUM_RX_DESCS_NIC_IF
parameter_list|(
name|cfg
parameter_list|,
name|idx
parameter_list|,
name|value
parameter_list|)
define|\
value|((cfg)->nic_if_cfg[idx].num_rx_descs = value)
end_define

begin_define
define|#
directive|define
name|LIO_SET_NUM_TX_DESCS_NIC_IF
parameter_list|(
name|cfg
parameter_list|,
name|idx
parameter_list|,
name|value
parameter_list|)
define|\
value|((cfg)->nic_if_cfg[idx].num_tx_descs = value)
end_define

begin_comment
comment|/* TX/RX process pkt budget */
end_comment

begin_define
define|#
directive|define
name|LIO_DEFAULT_TX_PKTS_PROCESS_BUDGET
value|64
end_define

begin_define
define|#
directive|define
name|LIO_DEFAULT_RX_PKTS_PROCESS_BUDGET
value|64
end_define

begin_enum
enum|enum
name|lio_card_type
block|{
name|LIO_23XX
comment|/* 23xx */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|LIO_23XX_NAME
value|"23xx"
end_define

begin_comment
comment|/*  *  Structure to define the configuration attributes for each Input queue.  *  Applicable to all Octeon processors  */
end_comment

begin_struct
struct|struct
name|lio_iq_config
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|reserved
range|:
literal|16
decl_stmt|;
comment|/* Tx interrupt packets. Applicable to 23xx only */
name|uint64_t
name|iq_intr_pkt
range|:
literal|16
decl_stmt|;
comment|/* Minimum ticks to wait before checking for pending instructions. */
name|uint64_t
name|db_timeout
range|:
literal|16
decl_stmt|;
comment|/* 	 *  Minimum number of commands pending to be posted to Octeon 	 *  before driver hits the Input queue doorbell. 	 */
name|uint64_t
name|db_min
range|:
literal|8
decl_stmt|;
comment|/* Command size - 32 or 64 bytes */
name|uint64_t
name|instr_type
range|:
literal|32
decl_stmt|;
comment|/* 	 *  Pending list size (usually set to the sum of the size of all Input 	 *  queues) 	 */
name|uint64_t
name|pending_list_size
range|:
literal|32
decl_stmt|;
comment|/* Max number of IQs available */
name|uint64_t
name|max_iqs
range|:
literal|8
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
comment|/* Max number of IQs available */
name|uint64_t
name|max_iqs
range|:
literal|8
decl_stmt|;
comment|/* 	 *  Pending list size (usually set to the sum of the size of all Input 	 *  queues) 	 */
name|uint64_t
name|pending_list_size
range|:
literal|32
decl_stmt|;
comment|/* Command size - 32 or 64 bytes */
name|uint64_t
name|instr_type
range|:
literal|32
decl_stmt|;
comment|/* 	 *  Minimum number of commands pending to be posted to Octeon 	 *  before driver hits the Input queue doorbell. 	 */
name|uint64_t
name|db_min
range|:
literal|8
decl_stmt|;
comment|/* Minimum ticks to wait before checking for pending instructions. */
name|uint64_t
name|db_timeout
range|:
literal|16
decl_stmt|;
comment|/* Tx interrupt packets. Applicable to 23xx only */
name|uint64_t
name|iq_intr_pkt
range|:
literal|16
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|16
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
struct|;
end_struct

begin_comment
comment|/*  *  Structure to define the configuration attributes for each Output queue.  *  Applicable to all Octeon processors  */
end_comment

begin_struct
struct|struct
name|lio_oq_config
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|reserved
range|:
literal|16
decl_stmt|;
name|uint64_t
name|pkts_per_intr
range|:
literal|16
decl_stmt|;
comment|/* 	 *  Interrupt Coalescing (Time Interval). Octeon will interrupt the 	 *  host if atleast one packet was sent in the time interval specified 	 *  by this field. The driver uses time interval interrupt coalescing 	 *  by default. The time is specified in microseconds. 	 */
name|uint64_t
name|oq_intr_time
range|:
literal|16
decl_stmt|;
comment|/* 	 *  Interrupt Coalescing (Packet Count). Octeon will interrupt the host 	 *  only if it sent as many packets as specified by this field. 	 *  The driver 	 *  usually does not use packet count interrupt coalescing. 	 */
name|uint64_t
name|oq_intr_pkt
range|:
literal|16
decl_stmt|;
comment|/* 	 *   The number of buffers that were consumed during packet processing by 	 *   the driver on this Output queue before the driver attempts to 	 *   replenish 	 *   the descriptor ring with new buffers. 	 */
name|uint64_t
name|refill_threshold
range|:
literal|16
decl_stmt|;
comment|/* Max number of OQs available */
name|uint64_t
name|max_oqs
range|:
literal|8
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
comment|/* Max number of OQs available */
name|uint64_t
name|max_oqs
range|:
literal|8
decl_stmt|;
comment|/* 	 *   The number of buffers that were consumed during packet processing by 	 *   the driver on this Output queue before the driver attempts to 	 *   replenish 	 *   the descriptor ring with new buffers. 	 */
name|uint64_t
name|refill_threshold
range|:
literal|16
decl_stmt|;
comment|/* 	 *  Interrupt Coalescing (Packet Count). Octeon will interrupt the host 	 *  only if it sent as many packets as specified by this field. 	 *  The driver 	 *  usually does not use packet count interrupt coalescing. 	 */
name|uint64_t
name|oq_intr_pkt
range|:
literal|16
decl_stmt|;
comment|/* 	 *  Interrupt Coalescing (Time Interval). Octeon will interrupt the 	 *  host if atleast one packet was sent in the time interval specified 	 *  by this field. The driver uses time interval interrupt coalescing 	 *  by default.  The time is specified in microseconds. 	 */
name|uint64_t
name|oq_intr_time
range|:
literal|16
decl_stmt|;
name|uint64_t
name|pkts_per_intr
range|:
literal|16
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|16
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
struct|;
end_struct

begin_comment
comment|/*  *  This structure conatins the NIC link configuration attributes,  *  common for all the OCTEON Modles.  */
end_comment

begin_struct
struct|struct
name|lio_nic_if_config
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint64_t
name|reserved
range|:
literal|56
decl_stmt|;
name|uint64_t
name|base_queue
range|:
literal|16
decl_stmt|;
name|uint64_t
name|gmx_port_id
range|:
literal|8
decl_stmt|;
comment|/* 	 * mbuf size, We need not change buf size even for Jumbo frames. 	 * Octeon can send jumbo frames in 4 consecutive descriptors, 	 */
name|uint64_t
name|rx_buf_size
range|:
literal|16
decl_stmt|;
comment|/* Num of desc for tx rings */
name|uint64_t
name|num_tx_descs
range|:
literal|16
decl_stmt|;
comment|/* Num of desc for rx rings */
name|uint64_t
name|num_rx_descs
range|:
literal|16
decl_stmt|;
comment|/* Actual configured value. Range could be: 1...max_rxqs */
name|uint64_t
name|num_rxqs
range|:
literal|16
decl_stmt|;
comment|/* Max Rxqs: Half for each of the two ports :max_oq/2  */
name|uint64_t
name|max_rxqs
range|:
literal|16
decl_stmt|;
comment|/* Actual configured value. Range could be: 1...max_txqs */
name|uint64_t
name|num_txqs
range|:
literal|16
decl_stmt|;
comment|/* Max Txqs: Half for each of the two ports :max_iq/2 */
name|uint64_t
name|max_txqs
range|:
literal|16
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
comment|/* Max Txqs: Half for each of the two ports :max_iq/2 */
name|uint64_t
name|max_txqs
range|:
literal|16
decl_stmt|;
comment|/* Actual configured value. Range could be: 1...max_txqs */
name|uint64_t
name|num_txqs
range|:
literal|16
decl_stmt|;
comment|/* Max Rxqs: Half for each of the two ports :max_oq/2  */
name|uint64_t
name|max_rxqs
range|:
literal|16
decl_stmt|;
comment|/* Actual configured value. Range could be: 1...max_rxqs */
name|uint64_t
name|num_rxqs
range|:
literal|16
decl_stmt|;
comment|/* Num of desc for rx rings */
name|uint64_t
name|num_rx_descs
range|:
literal|16
decl_stmt|;
comment|/* Num of desc for tx rings */
name|uint64_t
name|num_tx_descs
range|:
literal|16
decl_stmt|;
comment|/* 	 * mbuf size, We need not change buf size even for Jumbo frames. 	 * Octeon can send jumbo frames in 4 consecutive descriptors, 	 */
name|uint64_t
name|rx_buf_size
range|:
literal|16
decl_stmt|;
name|uint64_t
name|gmx_port_id
range|:
literal|8
decl_stmt|;
name|uint64_t
name|base_queue
range|:
literal|16
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|56
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
struct|;
end_struct

begin_comment
comment|/*  *  Structure to define the configuration attributes for meta data.  *  Applicable to all Octeon processors.  */
end_comment

begin_struct
struct|struct
name|lio_misc_config
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
comment|/* Host link status polling period */
name|uint64_t
name|host_link_query_interval
range|:
literal|32
decl_stmt|;
comment|/* Oct link status polling period */
name|uint64_t
name|oct_link_query_interval
range|:
literal|32
decl_stmt|;
name|uint64_t
name|enable_sli_oq_bp
range|:
literal|1
decl_stmt|;
comment|/* Control IQ Group */
name|uint64_t
name|ctrlq_grp
range|:
literal|4
decl_stmt|;
else|#
directive|else
comment|/* BYTE_ORDER != BIG_ENDIAN */
comment|/* Control IQ Group */
name|uint64_t
name|ctrlq_grp
range|:
literal|4
decl_stmt|;
comment|/* BP for SLI OQ */
name|uint64_t
name|enable_sli_oq_bp
range|:
literal|1
decl_stmt|;
comment|/* Host link status polling period */
name|uint64_t
name|oct_link_query_interval
range|:
literal|32
decl_stmt|;
comment|/* Oct link status polling period */
name|uint64_t
name|host_link_query_interval
range|:
literal|32
decl_stmt|;
endif|#
directive|endif
comment|/* BYTE_ORDER == BIG_ENDIAN */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure to define the configuration for all OCTEON processors. */
end_comment

begin_struct
struct|struct
name|lio_config
block|{
name|uint16_t
name|card_type
decl_stmt|;
name|char
modifier|*
name|card_name
decl_stmt|;
comment|/* Input Queue attributes. */
name|struct
name|lio_iq_config
name|iq
decl_stmt|;
comment|/* Output Queue attributes. */
name|struct
name|lio_oq_config
name|oq
decl_stmt|;
comment|/* NIC Port Configuration */
name|struct
name|lio_nic_if_config
name|nic_if_cfg
index|[
name|LIO_MAX_IF
index|]
decl_stmt|;
comment|/* Miscellaneous attributes */
name|struct
name|lio_misc_config
name|misc
decl_stmt|;
name|int
name|num_nic_ports
decl_stmt|;
name|int
name|num_def_tx_descs
decl_stmt|;
comment|/* Num of desc for rx rings */
name|int
name|num_def_rx_descs
decl_stmt|;
name|int
name|def_rx_buf_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The following config values are fixed and should not be modified. */
end_comment

begin_comment
comment|/* Maximum address space to be mapped for Octeon's BAR1 index-based access. */
end_comment

begin_define
define|#
directive|define
name|LIO_MAX_BAR1_MAP_INDEX
value|2
end_define

begin_comment
comment|/*  * Response lists - 1 ordered, 1 unordered-blocking, 1 unordered-nonblocking  * NoResponse Lists are now maintained with each IQ. (Dec' 2007).  */
end_comment

begin_define
define|#
directive|define
name|LIO_MAX_RESPONSE_LISTS
value|4
end_define

begin_comment
comment|/*  * Opcode hash bits. The opcode is hashed on the lower 6-bits to lookup the  * dispatch table.  */
end_comment

begin_define
define|#
directive|define
name|LIO_OPCODE_MASK_BITS
value|6
end_define

begin_comment
comment|/* Mask for the 6-bit lookup hash */
end_comment

begin_define
define|#
directive|define
name|LIO_OPCODE_MASK
value|0x3f
end_define

begin_comment
comment|/* Size of the dispatch table. The 6-bit hash can index into 2^6 entries */
end_comment

begin_define
define|#
directive|define
name|LIO_DISPATCH_LIST_SIZE
value|BIT(LIO_OPCODE_MASK_BITS)
end_define

begin_define
define|#
directive|define
name|LIO_MAX_INSTR_QUEUES
parameter_list|(
name|oct
parameter_list|)
value|LIO_CN23XX_PF_MAX_INPUT_QUEUES
end_define

begin_define
define|#
directive|define
name|LIO_MAX_OUTPUT_QUEUES
parameter_list|(
name|oct
parameter_list|)
value|LIO_CN23XX_PF_MAX_OUTPUT_QUEUES
end_define

begin_define
define|#
directive|define
name|LIO_MAX_POSSIBLE_INSTR_QUEUES
value|LIO_CN23XX_PF_MAX_INPUT_QUEUES
end_define

begin_define
define|#
directive|define
name|LIO_MAX_POSSIBLE_OUTPUT_QUEUES
value|LIO_CN23XX_PF_MAX_OUTPUT_QUEUES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIO_CONFIG_H__  */
end_comment

end_unit

