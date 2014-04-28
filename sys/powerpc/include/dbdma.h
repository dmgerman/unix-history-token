begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Nathan Whitehorn  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_DBDMA_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_DBDMA_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/*   * Apple's DBDMA (Descriptor-based DMA) interface is a common DMA engine  * used by a variety of custom Apple ASICs. It is described in the CHRP  * specification and in the book Macintosh Technology in the Common  * Hardware Reference Platform, copyright 1995 Apple Computer.  */
end_comment

begin_comment
comment|/* DBDMA Command Values */
end_comment

begin_enum
enum|enum
block|{
name|DBDMA_OUTPUT_MORE
init|=
literal|0
block|,
name|DBDMA_OUTPUT_LAST
init|=
literal|1
block|,
name|DBDMA_INPUT_MORE
init|=
literal|2
block|,
name|DBDMA_INPUT_LAST
init|=
literal|3
block|,
name|DBDMA_STORE_QUAD
init|=
literal|4
block|,
name|DBDMA_LOAD_QUAD
init|=
literal|5
block|,
name|DBDMA_NOP
init|=
literal|6
block|,
name|DBDMA_STOP
init|=
literal|7
block|}
enum|;
end_enum

begin_comment
comment|/* These codes are for the interrupt, branch, and wait flags */
end_comment

begin_enum
enum|enum
block|{
name|DBDMA_NEVER
init|=
literal|0
block|,
name|DBDMA_COND_TRUE
init|=
literal|1
block|,
name|DBDMA_COND_FALSE
init|=
literal|2
block|,
name|DBDMA_ALWAYS
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* Channel status bits */
end_comment

begin_define
define|#
directive|define
name|DBDMA_STATUS_RUN
value|(0x01<< 15)
end_define

begin_define
define|#
directive|define
name|DBDMA_STATUS_PAUSE
value|(0x01<< 14)
end_define

begin_define
define|#
directive|define
name|DBDMA_STATUS_FLUSH
value|(0x01<< 13)
end_define

begin_define
define|#
directive|define
name|DBDMA_STATUS_WAKE
value|(0x01<< 12)
end_define

begin_define
define|#
directive|define
name|DBDMA_STATUS_DEAD
value|(0x01<< 11)
end_define

begin_define
define|#
directive|define
name|DBDMA_STATUS_ACTIVE
value|(0x01<< 10)
end_define

begin_comment
comment|/* Set by hardware if a branch was taken */
end_comment

begin_define
define|#
directive|define
name|DBDMA_STATUS_BRANCH
value|8
end_define

begin_struct_decl
struct_decl|struct
name|dbdma_command
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|dbdma_command
name|dbdma_command_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|dbdma_channel
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|dbdma_channel
name|dbdma_channel_t
typedef|;
end_typedef

begin_function_decl
name|int
name|dbdma_allocate_channel
parameter_list|(
name|struct
name|resource
modifier|*
name|dbdma_regs
parameter_list|,
name|u_int
name|offset
parameter_list|,
name|bus_dma_tag_t
name|parent_dma
parameter_list|,
name|int
name|slots
parameter_list|,
name|dbdma_channel_t
modifier|*
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbdma_resize_channel
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|newslots
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbdma_free_channel
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_run
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_stop
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_reset
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_set_current_cmd
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_pause
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_wake
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * DBDMA uses a 16 bit channel control register to describe the current  * state of DMA on the channel. The high-order bits (8-15) contain information  * on the run state and are listed in the DBDMA_STATUS_* constants above. These  * are manipulated with the dbdma_run/stop/reset() routines above.  *  * The low order bits (0-7) are device dependent status bits. These can be set  * and read by both hardware and software. The mask is the set of bits to   * modify; if mask is 0x03 and value is 0, the lowest order 2 bits will be  * zeroed.  */
end_comment

begin_function_decl
name|uint16_t
name|dbdma_get_chan_status
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|dbdma_get_device_status
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_set_device_status
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|uint8_t
name|mask
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Each DBDMA command word has the current channel status register and the  * number of residual bytes (requested - actually transferred) written to it  * at time of command completion.  */
end_comment

begin_function_decl
name|uint16_t
name|dbdma_get_cmd_status
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|dbdma_get_residuals
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_clear_cmd_status
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The interrupt/branch/wait selector let you specify a set of values  * of the device dependent status bits that will cause intterupt/branch/wait  * conditions to be taken if the flags for these are set to one of the   * DBDMA_COND_* values.  *   * The condition is considered true if (status& mask) == value.  */
end_comment

begin_function_decl
name|void
name|dbdma_set_interrupt_selector
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|uint8_t
name|mask
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_set_branch_selector
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|uint8_t
name|mask
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_set_wait_selector
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|uint8_t
name|mask
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_insert_command
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|slot
parameter_list|,
name|int
name|command
parameter_list|,
name|int
name|stream
parameter_list|,
name|bus_addr_t
name|data
parameter_list|,
name|size_t
name|count
parameter_list|,
name|uint8_t
name|interrupt
parameter_list|,
name|uint8_t
name|branch
parameter_list|,
name|uint8_t
name|wait
parameter_list|,
name|uint32_t
name|branch_slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_insert_stop
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_insert_nop
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_insert_branch
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|slot
parameter_list|,
name|int
name|to_slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_sync_commands
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|,
name|bus_dmasync_op_t
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_save_state
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbdma_restore_state
parameter_list|(
name|dbdma_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_DBDMA_H_ */
end_comment

end_unit

