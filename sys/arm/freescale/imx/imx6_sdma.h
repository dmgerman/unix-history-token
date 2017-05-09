begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_MC0PTR
value|0x00
end_define

begin_comment
comment|/* ARM platform Channel 0 Pointer */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_INTR
value|0x04
end_define

begin_comment
comment|/* Channel Interrupts */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_STOP_STAT
value|0x08
end_define

begin_comment
comment|/* Channel Stop/Channel Status */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_HSTART
value|0x0C
end_define

begin_comment
comment|/* Channel Start */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_EVTOVR
value|0x10
end_define

begin_comment
comment|/* Channel Event Override */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_DSPOVR
value|0x14
end_define

begin_comment
comment|/* Channel BP Override */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_HOSTOVR
value|0x18
end_define

begin_comment
comment|/* Channel ARM platform Override */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_EVTPEND
value|0x1C
end_define

begin_comment
comment|/* Channel Event Pending */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_RESET
value|0x24
end_define

begin_comment
comment|/* Reset Register */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_EVTERR
value|0x28
end_define

begin_comment
comment|/* DMA Request Error Register */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_INTRMASK
value|0x2C
end_define

begin_comment
comment|/* Channel ARM platform Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_PSW
value|0x30
end_define

begin_comment
comment|/* Schedule Status */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_EVTERRDBG
value|0x34
end_define

begin_comment
comment|/* DMA Request Error Register */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_CONFIG
value|0x38
end_define

begin_comment
comment|/* Configuration Register */
end_comment

begin_define
define|#
directive|define
name|CONFIG_CSM
value|0x3
end_define

begin_define
define|#
directive|define
name|SDMAARM_SDMA_LOCK
value|0x3C
end_define

begin_comment
comment|/* SDMA LOCK */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_ONCE_ENB
value|0x40
end_define

begin_comment
comment|/* OnCE Enable */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_ONCE_DATA
value|0x44
end_define

begin_comment
comment|/* OnCE Data Register */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_ONCE_INSTR
value|0x48
end_define

begin_comment
comment|/* OnCE Instruction Register */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_ONCE_STAT
value|0x4C
end_define

begin_comment
comment|/* OnCE Status Register */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_ONCE_CMD
value|0x50
end_define

begin_comment
comment|/* OnCE Command Register */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_ILLINSTADDR
value|0x58
end_define

begin_comment
comment|/* Illegal Instruction Trap Address */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_CHN0ADDR
value|0x5C
end_define

begin_comment
comment|/* Channel 0 Boot Address */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_EVT_MIRROR
value|0x60
end_define

begin_comment
comment|/* DMA Requests */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_EVT_MIRROR2
value|0x64
end_define

begin_comment
comment|/* DMA Requests 2 */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_XTRIG_CONF1
value|0x70
end_define

begin_comment
comment|/* Cross-Trigger Events Configuration Register 1 */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_XTRIG_CONF2
value|0x74
end_define

begin_comment
comment|/* Cross-Trigger Events Configuration Register 2 */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_SDMA_CHNPRI
parameter_list|(
name|n
parameter_list|)
value|(0x100 + 0x4 * n)
end_define

begin_comment
comment|/* Channel Priority Registers */
end_comment

begin_define
define|#
directive|define
name|SDMAARM_CHNENBL
parameter_list|(
name|n
parameter_list|)
value|(0x200 + 0x4 * n)
end_define

begin_comment
comment|/* Channel Enable RAM */
end_comment

begin_comment
comment|/* SDMA Event Mappings */
end_comment

begin_define
define|#
directive|define
name|SSI1_RX_1
value|35
end_define

begin_define
define|#
directive|define
name|SSI1_TX_1
value|36
end_define

begin_define
define|#
directive|define
name|SSI1_RX_0
value|37
end_define

begin_define
define|#
directive|define
name|SSI1_TX_0
value|38
end_define

begin_define
define|#
directive|define
name|SSI2_RX_1
value|39
end_define

begin_define
define|#
directive|define
name|SSI2_TX_1
value|40
end_define

begin_define
define|#
directive|define
name|SSI2_RX_0
value|41
end_define

begin_define
define|#
directive|define
name|SSI2_TX_0
value|42
end_define

begin_define
define|#
directive|define
name|SSI3_RX_1
value|43
end_define

begin_define
define|#
directive|define
name|SSI3_TX_1
value|44
end_define

begin_define
define|#
directive|define
name|SSI3_RX_0
value|45
end_define

begin_define
define|#
directive|define
name|SSI3_TX_0
value|46
end_define

begin_define
define|#
directive|define
name|C0_ADDR
value|0x01
end_define

begin_define
define|#
directive|define
name|C0_LOAD
value|0x02
end_define

begin_define
define|#
directive|define
name|C0_DUMP
value|0x03
end_define

begin_define
define|#
directive|define
name|C0_SETCTX
value|0x07
end_define

begin_define
define|#
directive|define
name|C0_GETCTX
value|0x03
end_define

begin_define
define|#
directive|define
name|C0_SETDM
value|0x01
end_define

begin_define
define|#
directive|define
name|C0_SETPM
value|0x04
end_define

begin_define
define|#
directive|define
name|C0_GETDM
value|0x02
end_define

begin_define
define|#
directive|define
name|C0_GETPM
value|0x08
end_define

begin_define
define|#
directive|define
name|BD_DONE
value|0x01
end_define

begin_define
define|#
directive|define
name|BD_WRAP
value|0x02
end_define

begin_define
define|#
directive|define
name|BD_CONT
value|0x04
end_define

begin_define
define|#
directive|define
name|BD_INTR
value|0x08
end_define

begin_define
define|#
directive|define
name|BD_RROR
value|0x10
end_define

begin_define
define|#
directive|define
name|BD_LAST
value|0x20
end_define

begin_define
define|#
directive|define
name|BD_EXTD
value|0x80
end_define

begin_comment
comment|/* sDMA data transfer length */
end_comment

begin_define
define|#
directive|define
name|CMD_4BYTES
value|0
end_define

begin_define
define|#
directive|define
name|CMD_3BYTES
value|3
end_define

begin_define
define|#
directive|define
name|CMD_2BYTES
value|2
end_define

begin_define
define|#
directive|define
name|CMD_1BYTES
value|1
end_define

begin_struct
struct|struct
name|sdma_firmware_header
block|{
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|version_major
decl_stmt|;
name|uint32_t
name|version_minor
decl_stmt|;
name|uint32_t
name|script_addrs_start
decl_stmt|;
name|uint32_t
name|num_script_addrs
decl_stmt|;
name|uint32_t
name|ram_code_start
decl_stmt|;
name|uint32_t
name|ram_code_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdma_mode_count
block|{
name|uint16_t
name|count
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|command
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdma_buffer_descriptor
block|{
name|struct
name|sdma_mode_count
name|mode
decl_stmt|;
name|uint32_t
name|buffer_addr
decl_stmt|;
name|uint32_t
name|ext_buffer_addr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|sdma_channel_control
block|{
name|uint32_t
name|current_bd_ptr
decl_stmt|;
name|uint32_t
name|base_bd_ptr
decl_stmt|;
name|uint32_t
name|unused
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|sdma_state_registers
block|{
name|uint32_t
name|pc
range|:
literal|14
decl_stmt|;
name|uint32_t
name|unused1
range|:
literal|1
decl_stmt|;
name|uint32_t
name|t
range|:
literal|1
decl_stmt|;
name|uint32_t
name|rpc
range|:
literal|14
decl_stmt|;
name|uint32_t
name|unused0
range|:
literal|1
decl_stmt|;
name|uint32_t
name|sf
range|:
literal|1
decl_stmt|;
name|uint32_t
name|spc
range|:
literal|14
decl_stmt|;
name|uint32_t
name|unused2
range|:
literal|1
decl_stmt|;
name|uint32_t
name|df
range|:
literal|1
decl_stmt|;
name|uint32_t
name|epc
range|:
literal|14
decl_stmt|;
name|uint32_t
name|lm
range|:
literal|2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|sdma_context_data
block|{
name|struct
name|sdma_state_registers
name|channel_state
decl_stmt|;
name|uint32_t
name|gReg
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|mda
decl_stmt|;
name|uint32_t
name|msa
decl_stmt|;
name|uint32_t
name|ms
decl_stmt|;
name|uint32_t
name|md
decl_stmt|;
name|uint32_t
name|pda
decl_stmt|;
name|uint32_t
name|psa
decl_stmt|;
name|uint32_t
name|ps
decl_stmt|;
name|uint32_t
name|pd
decl_stmt|;
name|uint32_t
name|ca
decl_stmt|;
name|uint32_t
name|cs
decl_stmt|;
name|uint32_t
name|dda
decl_stmt|;
name|uint32_t
name|dsa
decl_stmt|;
name|uint32_t
name|ds
decl_stmt|;
name|uint32_t
name|dd
decl_stmt|;
name|uint32_t
name|unused
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SDMA firmware script pointers */
end_comment

begin_struct
struct|struct
name|sdma_script_start_addrs
block|{
name|int32_t
name|ap_2_ap_addr
decl_stmt|;
name|int32_t
name|ap_2_bp_addr
decl_stmt|;
name|int32_t
name|ap_2_ap_fixed_addr
decl_stmt|;
name|int32_t
name|bp_2_ap_addr
decl_stmt|;
name|int32_t
name|loopback_on_dsp_side_addr
decl_stmt|;
name|int32_t
name|mcu_interrupt_only_addr
decl_stmt|;
name|int32_t
name|firi_2_per_addr
decl_stmt|;
name|int32_t
name|firi_2_mcu_addr
decl_stmt|;
name|int32_t
name|per_2_firi_addr
decl_stmt|;
name|int32_t
name|mcu_2_firi_addr
decl_stmt|;
name|int32_t
name|uart_2_per_addr
decl_stmt|;
name|int32_t
name|uart_2_mcu_addr
decl_stmt|;
name|int32_t
name|per_2_app_addr
decl_stmt|;
name|int32_t
name|mcu_2_app_addr
decl_stmt|;
name|int32_t
name|per_2_per_addr
decl_stmt|;
name|int32_t
name|uartsh_2_per_addr
decl_stmt|;
name|int32_t
name|uartsh_2_mcu_addr
decl_stmt|;
name|int32_t
name|per_2_shp_addr
decl_stmt|;
name|int32_t
name|mcu_2_shp_addr
decl_stmt|;
name|int32_t
name|ata_2_mcu_addr
decl_stmt|;
name|int32_t
name|mcu_2_ata_addr
decl_stmt|;
name|int32_t
name|app_2_per_addr
decl_stmt|;
name|int32_t
name|app_2_mcu_addr
decl_stmt|;
name|int32_t
name|shp_2_per_addr
decl_stmt|;
name|int32_t
name|shp_2_mcu_addr
decl_stmt|;
name|int32_t
name|mshc_2_mcu_addr
decl_stmt|;
name|int32_t
name|mcu_2_mshc_addr
decl_stmt|;
name|int32_t
name|spdif_2_mcu_addr
decl_stmt|;
name|int32_t
name|mcu_2_spdif_addr
decl_stmt|;
name|int32_t
name|asrc_2_mcu_addr
decl_stmt|;
name|int32_t
name|ext_mem_2_ipu_addr
decl_stmt|;
name|int32_t
name|descrambler_addr
decl_stmt|;
name|int32_t
name|dptc_dvfs_addr
decl_stmt|;
name|int32_t
name|utra_addr
decl_stmt|;
name|int32_t
name|ram_code_start_addr
decl_stmt|;
name|int32_t
name|mcu_2_ssish_addr
decl_stmt|;
name|int32_t
name|ssish_2_mcu_addr
decl_stmt|;
name|int32_t
name|hdmi_dma_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SDMA_N_CHANNELS
value|32
end_define

begin_define
define|#
directive|define
name|SDMA_N_EVENTS
value|48
end_define

begin_define
define|#
directive|define
name|FW_HEADER_MAGIC
value|0x414d4453
end_define

begin_struct
struct|struct
name|sdma_channel
block|{
name|struct
name|sdma_conf
modifier|*
name|conf
decl_stmt|;
name|struct
name|sdma_buffer_descriptor
modifier|*
name|bd
decl_stmt|;
name|uint8_t
name|in_use
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdma_softc
block|{
name|struct
name|resource
modifier|*
name|res
index|[
literal|2
index|]
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
name|struct
name|sdma_channel_control
modifier|*
name|ccb
decl_stmt|;
name|struct
name|sdma_buffer_descriptor
modifier|*
name|bd0
decl_stmt|;
name|struct
name|sdma_context_data
modifier|*
name|context
decl_stmt|;
name|struct
name|sdma_channel
name|channel
index|[
name|SDMA_N_CHANNELS
index|]
decl_stmt|;
name|uint32_t
name|num_bd
decl_stmt|;
name|uint32_t
name|ccb_phys
decl_stmt|;
name|uint32_t
name|context_phys
decl_stmt|;
specifier|const
name|struct
name|sdma_firmware_header
modifier|*
name|fw_header
decl_stmt|;
specifier|const
name|struct
name|sdma_script_start_addrs
modifier|*
name|fw_scripts
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdma_conf
block|{
name|bus_addr_t
name|saddr
decl_stmt|;
name|bus_addr_t
name|daddr
decl_stmt|;
name|uint32_t
name|word_length
decl_stmt|;
name|uint32_t
name|nbits
decl_stmt|;
name|uint32_t
name|command
decl_stmt|;
name|uint32_t
name|num_bd
decl_stmt|;
name|uint32_t
name|event
decl_stmt|;
name|uint32_t
name|period
decl_stmt|;
name|uint32_t
function_decl|(
modifier|*
name|ih
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
modifier|*
name|ih_user
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|sdma_configure
parameter_list|(
name|int
parameter_list|,
name|struct
name|sdma_conf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdma_start
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdma_stop
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdma_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdma_free
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

