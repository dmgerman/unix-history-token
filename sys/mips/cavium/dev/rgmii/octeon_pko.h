begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  *  Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  *  reserved.  *  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are  *  met:  *  *      * Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  *  *      * Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials provided  *        with the distribution.  *  *      * Neither the name of Cavium Networks nor the names of  *        its contributors may be used to endorse or promote products  *        derived from this software without specific prior written  *        permission.  *  *  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  *  AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  *  OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  *  RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  *  REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  *  DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  *  OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  *  PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  *  POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  *  OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  *  For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*------------------------------------------------------------------  * octeon_pko.h      Packet Output Block  *  *------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|___OCTEON_PKO__H___
end_ifndef

begin_define
define|#
directive|define
name|___OCTEON_PKO__H___
end_define

begin_comment
comment|/*  * PKO Command Buffer Register.  * Specify Pool-# and Size of each entry in Pool. For Output Cmd Buffers.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|unused_mbz
range|:
literal|41
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|pool
range|:
literal|3
decl_stmt|;
comment|/* FPA Pool to use */
name|uint64_t
name|unused_mbz2
range|:
literal|7
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|size
range|:
literal|13
decl_stmt|;
comment|/* Size of the pool blocks */
block|}
name|bits
struct|;
block|}
name|octeon_pko_pool_cfg_t
typedef|;
end_typedef

begin_comment
comment|/*  * PKO GMX Mode Register  * Specify the # of GMX1 ports and GMX0 ports  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|unused_mbz
range|:
literal|58
decl_stmt|;
comment|/* MBZ */
name|uint64_t
name|mode1
range|:
literal|3
decl_stmt|;
comment|/* # GMX1 ports; */
comment|/*  16>> MODE1, 0<= MODE1<=4 */
name|uint64_t
name|mode0
range|:
literal|3
decl_stmt|;
comment|/* # GMX0 ports; */
comment|/*  16>> MODE0, 0<= MODE0<=4 */
block|}
name|bits
struct|;
block|}
name|octeon_pko_reg_gmx_port_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|unused_mbz
range|:
literal|62
decl_stmt|;
comment|/* MBZ */
name|uint64_t
name|mode
range|:
literal|2
decl_stmt|;
comment|/* Queues Mode */
block|}
name|bits
struct|;
block|}
name|octeon_pko_queue_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|unused_mbz
range|:
literal|32
decl_stmt|;
comment|/* MBZ */
name|uint64_t
name|crc_ports_mask
range|:
literal|32
decl_stmt|;
comment|/* CRC Ports Enable mask */
block|}
name|bits
struct|;
block|}
name|octeon_pko_crc_ports_enable_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OCTEON_PKO_QUEUES_MAX
value|128
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_PORTS_MAX
value|36
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_PORT_ILLEGAL
value|63
end_define

begin_comment
comment|/* Defines how the PKO command buffer FAU register is used */
end_comment

begin_define
define|#
directive|define
name|OCTEON_PKO_INDEX_BITS
value|12
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_INDEX_MASK
value|((1ull<< OCTEON_PKO_INDEX_BITS) - 1)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|OCTEON_PKO_SUCCESS
block|,
name|OCTEON_PKO_INVALID_PORT
block|,
name|OCTEON_PKO_INVALID_QUEUE
block|,
name|OCTEON_PKO_INVALID_PRIORITY
block|,
name|OCTEON_PKO_NO_MEMORY
block|}
name|octeon_pko_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|packets
decl_stmt|;
name|uint64_t
name|octets
decl_stmt|;
name|uint64_t
name|doorbell
decl_stmt|;
block|}
name|octeon_pko_port_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|octeon_mips_space_t
name|mem_space
range|:
literal|2
decl_stmt|;
comment|/* Octeon IO_SEG */
name|uint64_t
name|unused_mbz
range|:
literal|13
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|is_io
range|:
literal|1
decl_stmt|;
comment|/* Must be one */
name|uint64_t
name|did
range|:
literal|8
decl_stmt|;
comment|/* device-ID on non-coherent bus*/
name|uint64_t
name|unused_mbz2
range|:
literal|4
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|unused_mbz3
range|:
literal|18
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|port
range|:
literal|6
decl_stmt|;
comment|/* output port */
name|uint64_t
name|queue
range|:
literal|9
decl_stmt|;
comment|/* output queue to send */
name|uint64_t
name|unused_mbz4
range|:
literal|3
decl_stmt|;
comment|/* Must be zero */
block|}
name|bits
struct|;
block|}
name|octeon_pko_doorbell_address_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure of the first packet output command word.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|octeon_fau_op_size_t
name|size1
range|:
literal|2
decl_stmt|;
comment|/* The size of reg1 operation */
comment|/* - could be 8, 16, 32, or 64 bits */
name|octeon_fau_op_size_t
name|size0
range|:
literal|2
decl_stmt|;
comment|/* The size of the reg0 operation  */
comment|/* - could be 8, 16, 32, or 64 bits */
name|uint64_t
name|subone1
range|:
literal|1
decl_stmt|;
comment|/* Subtract 1, else sub pkt size */
name|uint64_t
name|reg1
range|:
literal|11
decl_stmt|;
comment|/* The register, subtract will be */
comment|/*       done if reg1 is non-zero */
name|uint64_t
name|subone0
range|:
literal|1
decl_stmt|;
comment|/* Subtract 1, else sub pkt size */
name|uint64_t
name|reg0
range|:
literal|11
decl_stmt|;
comment|/* The register, subtract will be */
comment|/*       done if reg0 is non-zero */
name|uint64_t
name|unused
range|:
literal|2
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|wqp
range|:
literal|1
decl_stmt|;
comment|/* If rsp, then word3 contains a */
comment|/*     ptr to a work queue entry */
name|uint64_t
name|rsp
range|:
literal|1
decl_stmt|;
comment|/* HW will  respond when done */
name|uint64_t
name|gather
range|:
literal|1
decl_stmt|;
comment|/* If set, the supplied pkt_ptr is */
comment|/*    a ptr to a list of pkt_ptr's */
name|uint64_t
name|ipoffp1
range|:
literal|7
decl_stmt|;
comment|/* Off to IP hdr.  For HW checksum */
name|uint64_t
name|ignore_i
range|:
literal|1
decl_stmt|;
comment|/* Ignore  I bit in all pointers */
name|uint64_t
name|dontfree
range|:
literal|1
decl_stmt|;
comment|/* Don't free buffs containing pkt */
name|uint64_t
name|segs
range|:
literal|6
decl_stmt|;
comment|/* Number of segs. If gather set, */
comment|/*        also gather list length */
name|uint64_t
name|total_bytes
range|:
literal|16
decl_stmt|;
comment|/* Includes L2, w/o trailing CRC */
block|}
name|bits
struct|;
block|}
name|octeon_pko_command_word0_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|i
range|:
literal|1
decl_stmt|;
comment|/* Invert the "free" pick of the overall pkt. */
comment|/* For inbound pkts, HW always sets this to 0 */
name|uint64_t
name|back
range|:
literal|4
decl_stmt|;
comment|/* Amount to back up to get to buffer start */
comment|/* in cache lines. This is mostly less than 1 */
comment|/* complete cache line; so the value is zero */
name|uint64_t
name|pool
range|:
literal|3
decl_stmt|;
comment|/* FPA pool that the buffer belongs to */
name|uint64_t
name|size
range|:
literal|16
decl_stmt|;
comment|/* segment size (bytes) pointed at by addr */
name|uint64_t
name|addr
range|:
literal|40
decl_stmt|;
comment|/* Ptr to 1st data byte. NOT buffer */
block|}
name|bits
struct|;
block|}
name|octeon_pko_packet_ptr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Definition of the hardware structure used to configure an  * output queue.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|unused_mbz
range|:
literal|3
decl_stmt|;
comment|/* Must be zero */
name|uint64_t
name|qos_mask
range|:
literal|8
decl_stmt|;
comment|/* Control Mask priority */
comment|/*      across 8 QOS levels */
name|uint64_t
name|buf_ptr
range|:
literal|36
decl_stmt|;
comment|/* Command buffer pointer, */
comment|/*          8 byte-aligned */
name|uint64_t
name|tail
range|:
literal|1
decl_stmt|;
comment|/* Set if this queue is the tail */
comment|/*       of the port queue array */
name|uint64_t
name|index
range|:
literal|3
decl_stmt|;
comment|/* Index (distance from head) in */
comment|/*          the port queue array */
name|uint64_t
name|port
range|:
literal|6
decl_stmt|;
comment|/* Port ID for this queue  mapping */
name|uint64_t
name|queue
range|:
literal|7
decl_stmt|;
comment|/* Hardware queue number */
block|}
name|bits
struct|;
block|}
name|octeon_pko_queue_cfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|word64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|unused_mbz
range|:
literal|48
decl_stmt|;
name|uint64_t
name|inc
range|:
literal|8
decl_stmt|;
name|uint64_t
name|idx
range|:
literal|8
decl_stmt|;
block|}
name|bits
struct|;
block|}
name|octeon_pko_read_idx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|octeon_pko_sw_queue_info_t_
block|{
name|uint64_t
name|xmit_command_state
decl_stmt|;
name|octeon_spinlock_t
name|lock
decl_stmt|;
name|uint32_t
name|pad
index|[
literal|29
index|]
decl_stmt|;
block|}
name|octeon_pko_sw_queue_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OCTEON_DID_PKT
value|10ULL
end_define

begin_define
define|#
directive|define
name|OCTEON_DID_PKT_SEND
value|OCTEON_ADDR_FULL_DID(OCTEON_DID_PKT,2ULL)
end_define

begin_comment
comment|/*  * Ring the packet output doorbell. This tells the packet  * output hardware that "len" command words have been added  * to its pending list.  This command includes the required  * SYNCW before the doorbell ring.  *  * @param port   Port the packet is for  * @param queue  Queue the packet is for  * @param len    Length of the command in 64 bit words  */
end_comment

begin_function_decl
specifier|extern
name|void
name|octeon_pko_doorbell_data
parameter_list|(
name|u_int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//#define CORE_0_ONLY 1
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|octeon_pko_ring_doorbell
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_int
name|queue
parameter_list|,
name|u_int
name|len
parameter_list|)
block|{
name|octeon_pko_doorbell_address_t
name|ptr
decl_stmt|;
name|ptr
operator|.
name|word64
operator|=
literal|0
expr_stmt|;
name|ptr
operator|.
name|bits
operator|.
name|mem_space
operator|=
name|OCTEON_IO_SEG
expr_stmt|;
name|ptr
operator|.
name|bits
operator|.
name|did
operator|=
name|OCTEON_DID_PKT_SEND
expr_stmt|;
name|ptr
operator|.
name|bits
operator|.
name|is_io
operator|=
literal|1
expr_stmt|;
name|ptr
operator|.
name|bits
operator|.
name|port
operator|=
name|port
expr_stmt|;
name|ptr
operator|.
name|bits
operator|.
name|queue
operator|=
name|queue
expr_stmt|;
name|OCTEON_SYNCWS
expr_stmt|;
name|oct_write64
argument_list|(
name|ptr
operator|.
name|word64
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|OCTEON_PKO_QUEUES_PER_PORT_INTERFACE0
value|1
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_QUEUES_PER_PORT_INTERFACE1
value|1
end_define

begin_define
define|#
directive|define
name|OCTEON_PKO_QUEUES_PER_PORT_PCI
value|1
end_define

begin_comment
comment|/*  * octeon_pko_get_base_queue  *  * For a given port number, return the base pko output queue  * for the port.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u_int
name|octeon_pko_get_base_queue
parameter_list|(
name|u_int
name|port
parameter_list|)
block|{
if|if
condition|(
name|port
operator|<
literal|16
condition|)
block|{
return|return
operator|(
name|port
operator|*
name|OCTEON_PKO_QUEUES_PER_PORT_INTERFACE0
operator|)
return|;
block|}
if|if
condition|(
name|port
operator|<
literal|32
condition|)
block|{
return|return
operator|(
literal|16
operator|*
name|OCTEON_PKO_QUEUES_PER_PORT_INTERFACE0
operator|+
operator|(
name|port
operator|-
literal|16
operator|)
operator|*
name|OCTEON_PKO_QUEUES_PER_PORT_INTERFACE1
operator|)
return|;
block|}
return|return
operator|(
literal|16
operator|*
name|OCTEON_PKO_QUEUES_PER_PORT_INTERFACE0
operator|+
literal|16
operator|*
name|OCTEON_PKO_QUEUES_PER_PORT_INTERFACE1
operator|+
operator|(
name|port
operator|-
literal|32
operator|)
operator|*
name|OCTEON_PKO_QUEUES_PER_PORT_PCI
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * For a given port number, return the number of pko output queues.  *  * @param port   Port number  * @return Number of output queues  */
end_comment

begin_function
specifier|static
specifier|inline
name|u_int
name|octeon_pko_get_num_queues
parameter_list|(
name|u_int
name|port
parameter_list|)
block|{
if|if
condition|(
name|port
operator|<
literal|16
condition|)
block|{
return|return
operator|(
name|OCTEON_PKO_QUEUES_PER_PORT_INTERFACE0
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|port
operator|<
literal|32
condition|)
block|{
return|return
operator|(
name|OCTEON_PKO_QUEUES_PER_PORT_INTERFACE1
operator|)
return|;
block|}
return|return
operator|(
name|OCTEON_PKO_QUEUES_PER_PORT_PCI
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Externs  */
end_comment

begin_function_decl
specifier|extern
name|void
name|octeon_pko_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_pko_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_pko_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_pko_show
parameter_list|(
name|u_int
name|start_port
parameter_list|,
name|u_int
name|end_port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_pko_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_pko_config_cmdbuf_global_defaults
parameter_list|(
name|u_int
name|cmdbuf_pool
parameter_list|,
name|u_int
name|elem_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_pko_config_rgmx_ports
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|octeon_pko_get_port_status
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|octeon_pko_port_status_t
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|octeon_pko_status_t
name|octeon_pko_config_port
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_int
name|base_queue
parameter_list|,
name|u_int
name|num_queues
parameter_list|,
specifier|const
name|u_int
name|priority
index|[]
parameter_list|,
name|u_int
name|pko_output_cmdbuf_fpa_pool
parameter_list|,
name|octeon_pko_sw_queue_info_t
name|sw_queues
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  ___OCTEON_PKO__H___ */
end_comment

end_unit

