begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-10-C-0237  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_EXTRES_XDMA_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_EXTRES_XDMA_H_
end_define

begin_enum
enum|enum
name|xdma_direction
block|{
name|XDMA_MEM_TO_MEM
block|,
name|XDMA_MEM_TO_DEV
block|,
name|XDMA_DEV_TO_MEM
block|,
name|XDMA_DEV_TO_DEV
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|xdma_operation_type
block|{
name|XDMA_MEMCPY
block|,
name|XDMA_SG
block|,
name|XDMA_CYCLIC
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|xdma_command
block|{
name|XDMA_CMD_BEGIN
block|,
name|XDMA_CMD_PAUSE
block|,
name|XDMA_CMD_TERMINATE
block|,
name|XDMA_CMD_TERMINATE_ALL
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|xdma_controller
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* DMA consumer device_t. */
name|device_t
name|dma_dev
decl_stmt|;
comment|/* A real DMA device_t. */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* OFW MD part. */
comment|/* List of virtual channels allocated. */
name|TAILQ_HEAD
argument_list|(
argument|xdma_channel_list
argument_list|,
argument|xdma_channel
argument_list|)
name|channels
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xdma_controller
name|xdma_controller_t
typedef|;
end_typedef

begin_struct
struct|struct
name|xdma_channel_config
block|{
name|enum
name|xdma_direction
name|direction
decl_stmt|;
name|uintptr_t
name|src_addr
decl_stmt|;
comment|/* Physical address. */
name|uintptr_t
name|dst_addr
decl_stmt|;
comment|/* Physical address. */
name|int
name|block_len
decl_stmt|;
comment|/* In bytes. */
name|int
name|block_num
decl_stmt|;
comment|/* Count of blocks. */
name|int
name|src_width
decl_stmt|;
comment|/* In bytes. */
name|int
name|dst_width
decl_stmt|;
comment|/* In bytes. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xdma_channel_config
name|xdma_config_t
typedef|;
end_typedef

begin_struct
struct|struct
name|xdma_descriptor
block|{
name|bus_addr_t
name|ds_addr
decl_stmt|;
name|bus_size_t
name|ds_len
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xdma_descriptor
name|xdma_descriptor_t
typedef|;
end_typedef

begin_struct
struct|struct
name|xdma_channel
block|{
name|xdma_controller_t
modifier|*
name|xdma
decl_stmt|;
name|xdma_config_t
name|conf
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|XCHAN_DESC_ALLOCATED
value|(1<< 0)
define|#
directive|define
name|XCHAN_CONFIGURED
value|(1<< 1)
define|#
directive|define
name|XCHAN_TYPE_CYCLIC
value|(1<< 2)
define|#
directive|define
name|XCHAN_TYPE_MEMCPY
value|(1<< 3)
comment|/* A real hardware driver channel. */
name|void
modifier|*
name|chan
decl_stmt|;
comment|/* Interrupt handlers. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|xdma_intr_handler
argument_list|)
name|ie_handlers
expr_stmt|;
comment|/* Descriptors. */
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|void
modifier|*
name|descs
decl_stmt|;
name|xdma_descriptor_t
modifier|*
name|descs_phys
decl_stmt|;
name|uint8_t
name|map_err
decl_stmt|;
name|struct
name|mtx
name|mtx_lock
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|xdma_channel
argument_list|)
name|xchan_next
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xdma_channel
name|xdma_channel_t
typedef|;
end_typedef

begin_comment
comment|/* xDMA controller alloc/free */
end_comment

begin_function_decl
name|xdma_controller_t
modifier|*
name|xdma_ofw_get
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|prop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_put
parameter_list|(
name|xdma_controller_t
modifier|*
name|xdma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xdma_channel_t
modifier|*
name|xdma_channel_alloc
parameter_list|(
name|xdma_controller_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_channel_free
parameter_list|(
name|xdma_channel_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_prep_cyclic
parameter_list|(
name|xdma_channel_t
modifier|*
parameter_list|,
name|enum
name|xdma_direction
parameter_list|,
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_prep_memcpy
parameter_list|(
name|xdma_channel_t
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_desc_alloc
parameter_list|(
name|xdma_channel_t
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_desc_free
parameter_list|(
name|xdma_channel_t
modifier|*
name|xchan
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Channel Control */
end_comment

begin_function_decl
name|int
name|xdma_begin
parameter_list|(
name|xdma_channel_t
modifier|*
name|xchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_pause
parameter_list|(
name|xdma_channel_t
modifier|*
name|xchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_terminate
parameter_list|(
name|xdma_channel_t
modifier|*
name|xchan
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Interrupt callback */
end_comment

begin_function_decl
name|int
name|xdma_setup_intr
parameter_list|(
name|xdma_channel_t
modifier|*
name|xchan
parameter_list|,
name|int
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_teardown_intr
parameter_list|(
name|xdma_channel_t
modifier|*
name|xchan
parameter_list|,
name|struct
name|xdma_intr_handler
modifier|*
name|ih
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_teardown_all_intr
parameter_list|(
name|xdma_channel_t
modifier|*
name|xchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xdma_callback
parameter_list|(
name|struct
name|xdma_channel
modifier|*
name|xchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xdma_assert_locked
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|xdma_intr_handler
block|{
name|int
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|cb_user
decl_stmt|;
name|struct
name|mtx
name|ih_lock
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|xdma_intr_handler
argument_list|)
name|ih_next
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_EXTRES_XDMA_H_ */
end_comment

end_unit

