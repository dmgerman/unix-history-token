begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000 Jonathan Lemon  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * software structures for the Compaq RAID controller  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IDAVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IDAVAR_H
end_define

begin_define
define|#
directive|define
name|ida_inb
parameter_list|(
name|ida
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((ida)->tag, (ida)->bsh, port)
end_define

begin_define
define|#
directive|define
name|ida_inw
parameter_list|(
name|ida
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_2((ida)->tag, (ida)->bsh, port)
end_define

begin_define
define|#
directive|define
name|ida_inl
parameter_list|(
name|ida
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_4((ida)->tag, (ida)->bsh, port)
end_define

begin_define
define|#
directive|define
name|ida_outb
parameter_list|(
name|ida
parameter_list|,
name|port
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((ida)->tag, (ida)->bsh, port, val)
end_define

begin_define
define|#
directive|define
name|ida_outw
parameter_list|(
name|ida
parameter_list|,
name|port
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2((ida)->tag, (ida)->bsh, port, val)
end_define

begin_define
define|#
directive|define
name|ida_outl
parameter_list|(
name|ida
parameter_list|,
name|port
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((ida)->tag, (ida)->bsh, port, val)
end_define

begin_struct
struct|struct
name|ida_hdr
block|{
name|u_int8_t
name|drive
decl_stmt|;
comment|/* logical drive */
name|u_int8_t
name|priority
decl_stmt|;
comment|/* block priority */
name|u_int16_t
name|size
decl_stmt|;
comment|/* size of request, in words */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ida_req
block|{
name|u_int16_t
name|next
decl_stmt|;
comment|/* offset of next request */
name|u_int8_t
name|command
decl_stmt|;
comment|/* command */
name|u_int8_t
name|error
decl_stmt|;
comment|/* return error code */
name|u_int32_t
name|blkno
decl_stmt|;
comment|/* block number */
name|u_int16_t
name|bcount
decl_stmt|;
comment|/* block count */
name|u_int8_t
name|sgcount
decl_stmt|;
comment|/* number of scatter/gather entries */
name|u_int8_t
name|spare
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ida_sgb
block|{
name|u_int32_t
name|length
decl_stmt|;
comment|/* length of S/G segment */
name|u_int32_t
name|addr
decl_stmt|;
comment|/* physical address of block */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDA_NSEG
value|32
end_define

begin_comment
comment|/* maximum number of segments */
end_comment

begin_comment
comment|/*  * right now, this structure totals 276 bytes.  */
end_comment

begin_struct
struct|struct
name|ida_hardware_qcb
block|{
name|struct
name|ida_hdr
name|hdr
decl_stmt|;
comment|/*   4 */
name|struct
name|ida_req
name|req
decl_stmt|;
comment|/*  12 */
name|struct
name|ida_sgb
name|seg
index|[
name|IDA_NSEG
index|]
decl_stmt|;
comment|/* 256 */
name|struct
name|ida_qcb
modifier|*
name|qcb
decl_stmt|;
comment|/*   4 - qcb backpointer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|QCB_FREE
init|=
literal|0x0000
block|,
name|QCB_ACTIVE
init|=
literal|0x0001
block|,
comment|/* waiting for completion */
block|}
name|qcb_state
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DMA_DATA_IN
value|0x0001
end_define

begin_define
define|#
directive|define
name|DMA_DATA_OUT
value|0x0002
end_define

begin_define
define|#
directive|define
name|IDA_COMMAND
value|0x0004
end_define

begin_define
define|#
directive|define
name|DMA_DATA_TRANSFER
value|(DMA_DATA_IN | DMA_DATA_OUT)
end_define

begin_define
define|#
directive|define
name|IDA_QCB_MAX
value|256
end_define

begin_define
define|#
directive|define
name|IDA_CONTROLLER
value|0
end_define

begin_comment
comment|/* drive "number" for controller */
end_comment

begin_struct
struct|struct
name|ida_qcb
block|{
name|struct
name|ida_hardware_qcb
modifier|*
name|hwqcb
decl_stmt|;
name|qcb_state
name|state
decl_stmt|;
name|short
name|flags
decl_stmt|;
union|union
block|{
name|STAILQ_ENTRY
argument_list|(
argument|ida_qcb
argument_list|)
name|stqe
expr_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|ida_qcb
argument_list|)
name|sle
expr_stmt|;
block|}
name|link
union|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
name|bus_addr_t
name|hwqcb_busaddr
decl_stmt|;
name|struct
name|buf
modifier|*
name|buf
decl_stmt|;
comment|/* buf associated with qcb */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ida_softc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ida_access
block|{
name|int
function_decl|(
modifier|*
name|fifo_full
function_decl|)
parameter_list|(
name|struct
name|ida_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|submit
function_decl|)
parameter_list|(
name|struct
name|ida_softc
modifier|*
parameter_list|,
name|struct
name|ida_qcb
modifier|*
parameter_list|)
function_decl|;
name|bus_addr_t
function_decl|(
modifier|*
name|done
function_decl|)
parameter_list|(
name|struct
name|ida_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|int_pending
function_decl|)
parameter_list|(
name|struct
name|ida_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|int_enable
function_decl|)
parameter_list|(
name|struct
name|ida_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * flags for the controller   */
end_comment

begin_define
define|#
directive|define
name|IDA_ATTACHED
value|0x01
end_define

begin_comment
comment|/* attached */
end_comment

begin_define
define|#
directive|define
name|IDA_FIRMWARE
value|0x02
end_define

begin_comment
comment|/* firmware must be started */
end_comment

begin_define
define|#
directive|define
name|IDA_INTERRUPTS
value|0x04
end_define

begin_comment
comment|/* interrupts enabled */
end_comment

begin_struct
struct|struct
name|ida_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|int
name|regs_res_type
decl_stmt|;
name|int
name|regs_res_id
decl_stmt|;
name|struct
name|resource
modifier|*
name|regs
decl_stmt|;
name|int
name|irq_res_type
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
name|bus_space_tag_t
name|tag
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
comment|/* various DMA tags */
name|bus_dma_tag_t
name|parent_dmat
decl_stmt|;
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
name|bus_dma_tag_t
name|hwqcb_dmat
decl_stmt|;
name|bus_dmamap_t
name|hwqcb_dmamap
decl_stmt|;
name|bus_addr_t
name|hwqcb_busaddr
decl_stmt|;
name|bus_dma_tag_t
name|sg_dmat
decl_stmt|;
name|int
name|num_drives
decl_stmt|;
name|int
name|num_qcbs
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|struct
name|ida_hardware_qcb
modifier|*
name|hwqcbs
decl_stmt|;
comment|/* HW QCB array */
name|struct
name|ida_qcb
modifier|*
name|qcbs
decl_stmt|;
comment|/* kernel QCB array */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|ida_qcb
argument_list|)
name|free_qcbs
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ida_qcb
argument_list|)
name|qcb_queue
expr_stmt|;
name|struct
name|buf_queue_head
name|buf_queue
decl_stmt|;
name|struct
name|ida_access
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * drive flags  */
end_comment

begin_define
define|#
directive|define
name|DRV_WRITEPROT
value|0x0001
end_define

begin_struct
struct|struct
name|idad_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|ida_softc
modifier|*
name|controller
decl_stmt|;
name|struct
name|disk
name|disk
decl_stmt|;
name|struct
name|devstat
name|stats
decl_stmt|;
name|int
name|drive
decl_stmt|;
comment|/* per controller */
name|int
name|unit
decl_stmt|;
comment|/* global */
name|int
name|cylinders
decl_stmt|;
name|int
name|heads
decl_stmt|;
name|int
name|sectors
decl_stmt|;
name|int
name|secsize
decl_stmt|;
name|int
name|secperunit
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ida_board
block|{
name|u_int32_t
name|board
decl_stmt|;
name|char
modifier|*
name|desc
decl_stmt|;
name|struct
name|ida_access
modifier|*
name|accessor
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|ida_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ida_softc
modifier|*
name|ida_alloc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|resource
modifier|*
name|regs
parameter_list|,
name|int
name|regs_type
parameter_list|,
name|int
name|regs_id
parameter_list|,
name|bus_dma_tag_t
name|parent_dmat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ida_free
parameter_list|(
name|struct
name|ida_softc
modifier|*
name|ida
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ida_init
parameter_list|(
name|struct
name|ida_softc
modifier|*
name|ida
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ida_attach
parameter_list|(
name|struct
name|ida_softc
modifier|*
name|ida
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ida_command
parameter_list|(
name|struct
name|ida_softc
modifier|*
name|ida
parameter_list|,
name|int
name|command
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|datasize
parameter_list|,
name|int
name|drive
parameter_list|,
name|u_int32_t
name|pblkno
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ida_submit_buf
parameter_list|(
name|struct
name|ida_softc
modifier|*
name|ida
parameter_list|,
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ida_intr
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idad_intr
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IDAVAR_H */
end_comment

end_unit

