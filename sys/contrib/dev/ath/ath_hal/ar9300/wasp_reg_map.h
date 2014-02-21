begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__REG_WASP_REG_MAP_H__
end_ifndef

begin_struct
struct|struct
name|host_intf_reg_ar9340
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x4000
index|]
decl_stmt|;
comment|/*        0x0 - 0x4000     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_RESET_CONTROL
decl_stmt|;
comment|/*     0x4000 - 0x4004     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_PM_CTRL
decl_stmt|;
comment|/*     0x4004 - 0x4008     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_TIMEOUT
decl_stmt|;
comment|/*     0x4008 - 0x400c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_SREV
decl_stmt|;
comment|/*     0x400c - 0x4010     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_SYNC_CAUSE
decl_stmt|;
comment|/*     0x4010 - 0x4014     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_SYNC_ENABLE
decl_stmt|;
comment|/*     0x4014 - 0x4018     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_ASYNC_MASK
decl_stmt|;
comment|/*     0x4018 - 0x401c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_SYNC_MASK
decl_stmt|;
comment|/*     0x401c - 0x4020     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_ASYNC_CAUSE
decl_stmt|;
comment|/*     0x4020 - 0x4024     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_ASYNC_ENABLE
decl_stmt|;
comment|/*     0x4024 - 0x4028     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OUT
decl_stmt|;
comment|/*     0x4028 - 0x402c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_IN
decl_stmt|;
comment|/*     0x402c - 0x4030     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OE
decl_stmt|;
comment|/*     0x4030 - 0x4034     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OE1
decl_stmt|;
comment|/*     0x4034 - 0x4038     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_INTR_POLAR
decl_stmt|;
comment|/*     0x4038 - 0x403c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_INPUT_VALUE
decl_stmt|;
comment|/*     0x403c - 0x4040     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_INPUT_MUX1
decl_stmt|;
comment|/*     0x4040 - 0x4044     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_INPUT_MUX2
decl_stmt|;
comment|/*     0x4044 - 0x4048     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OUTPUT_MUX1
decl_stmt|;
comment|/*     0x4048 - 0x404c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OUTPUT_MUX2
decl_stmt|;
comment|/*     0x404c - 0x4050     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OUTPUT_MUX3
decl_stmt|;
comment|/*     0x4050 - 0x4054     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_INPUT_STATE
decl_stmt|;
comment|/*     0x4054 - 0x4058     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_CLKRUN
decl_stmt|;
comment|/*     0x4058 - 0x405c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_OBS_CTRL
decl_stmt|;
comment|/*     0x405c - 0x4060     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_RFSILENT
decl_stmt|;
comment|/*     0x4060 - 0x4064     */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*     0x4064 - 0x4074     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_MISC
decl_stmt|;
comment|/*     0x4074 - 0x4078     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_MAC_TDMA_CCA_CNTL
decl_stmt|;
comment|/*     0x4078 - 0x407c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_MAC_TXAPSYNC
decl_stmt|;
comment|/*     0x407c - 0x4080     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_MAC_TXSYNC_INITIAL_SYNC_TMR
decl_stmt|;
comment|/*     0x4080 - 0x4084     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_SYNC_CAUSE
decl_stmt|;
comment|/*     0x4084 - 0x4088     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_SYNC_ENABLE
decl_stmt|;
comment|/*     0x4088 - 0x408c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_ASYNC_MASK
decl_stmt|;
comment|/*     0x408c - 0x4090     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_SYNC_MASK
decl_stmt|;
comment|/*     0x4090 - 0x4094     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_ASYNC_CAUSE
decl_stmt|;
comment|/*     0x4094 - 0x4098     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_ASYNC_ENABLE
decl_stmt|;
comment|/*     0x4098 - 0x409c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_AXI_BYTE_SWAP
decl_stmt|;
comment|/*     0x409c - 0x40a0     */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x20
index|]
decl_stmt|;
comment|/*     0x40a4 - 0x40c4     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_WORK_AROUND
decl_stmt|;
comment|/*     0x40c4 - 0x40c8     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_EEPROM_STS
decl_stmt|;
comment|/*     0x40c8 - 0x40cc     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_PCIE_MSI
decl_stmt|;
comment|/*     0x40d8 - 0x40dc     */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __REG_WASP_REG_MAP_H__ */
end_comment

end_unit

