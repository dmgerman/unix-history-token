begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2006,2007  *	Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|WPI_TX_RING_COUNT
value|256
end_define

begin_define
define|#
directive|define
name|WPI_TX_RING_LOMARK
value|192
end_define

begin_define
define|#
directive|define
name|WPI_TX_RING_HIMARK
value|224
end_define

begin_define
define|#
directive|define
name|WPI_RX_RING_COUNT_LOG
value|6
end_define

begin_define
define|#
directive|define
name|WPI_RX_RING_COUNT
value|(1<< WPI_RX_RING_COUNT_LOG)
end_define

begin_define
define|#
directive|define
name|WPI_NTXQUEUES
value|8
end_define

begin_define
define|#
directive|define
name|WPI_NDMACHNLS
value|6
end_define

begin_comment
comment|/* Maximum scatter/gather. */
end_comment

begin_define
define|#
directive|define
name|WPI_MAX_SCATTER
value|4
end_define

begin_comment
comment|/*  * Rings must be aligned on a 16K boundary.  */
end_comment

begin_define
define|#
directive|define
name|WPI_RING_DMA_ALIGN
value|0x4000
end_define

begin_comment
comment|/* Maximum Rx buffer size. */
end_comment

begin_define
define|#
directive|define
name|WPI_RBUF_SIZE
value|( 3 * 1024 )
end_define

begin_comment
comment|/* XXX 3000 but must be aligned */
end_comment

begin_comment
comment|/*  * Control and status registers.  */
end_comment

begin_define
define|#
directive|define
name|WPI_HW_IF_CONFIG
value|0x000
end_define

begin_define
define|#
directive|define
name|WPI_INT
value|0x008
end_define

begin_define
define|#
directive|define
name|WPI_INT_MASK
value|0x00c
end_define

begin_define
define|#
directive|define
name|WPI_FH_INT
value|0x010
end_define

begin_define
define|#
directive|define
name|WPI_GPIO_IN
value|0x018
end_define

begin_define
define|#
directive|define
name|WPI_RESET
value|0x020
end_define

begin_define
define|#
directive|define
name|WPI_GP_CNTRL
value|0x024
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM
value|0x02c
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_GP
value|0x030
end_define

begin_define
define|#
directive|define
name|WPI_GIO
value|0x03c
end_define

begin_define
define|#
directive|define
name|WPI_UCODE_GP1
value|0x054
end_define

begin_define
define|#
directive|define
name|WPI_UCODE_GP1_SET
value|0x058
end_define

begin_define
define|#
directive|define
name|WPI_UCODE_GP1_CLR
value|0x05c
end_define

begin_define
define|#
directive|define
name|WPI_UCODE_GP2
value|0x060
end_define

begin_define
define|#
directive|define
name|WPI_GIO_CHICKEN
value|0x100
end_define

begin_define
define|#
directive|define
name|WPI_ANA_PLL
value|0x20c
end_define

begin_define
define|#
directive|define
name|WPI_DBG_HPET_MEM
value|0x240
end_define

begin_define
define|#
directive|define
name|WPI_MEM_RADDR
value|0x40c
end_define

begin_define
define|#
directive|define
name|WPI_MEM_WADDR
value|0x410
end_define

begin_define
define|#
directive|define
name|WPI_MEM_WDATA
value|0x418
end_define

begin_define
define|#
directive|define
name|WPI_MEM_RDATA
value|0x41c
end_define

begin_define
define|#
directive|define
name|WPI_PRPH_WADDR
value|0x444
end_define

begin_define
define|#
directive|define
name|WPI_PRPH_RADDR
value|0x448
end_define

begin_define
define|#
directive|define
name|WPI_PRPH_WDATA
value|0x44c
end_define

begin_define
define|#
directive|define
name|WPI_PRPH_RDATA
value|0x450
end_define

begin_define
define|#
directive|define
name|WPI_HBUS_TARG_WRPTR
value|0x460
end_define

begin_comment
comment|/*  * Flow-Handler registers.  */
end_comment

begin_define
define|#
directive|define
name|WPI_FH_CBBC_CTRL
parameter_list|(
name|qid
parameter_list|)
value|(0x940 + (qid) * 8)
end_define

begin_define
define|#
directive|define
name|WPI_FH_CBBC_BASE
parameter_list|(
name|qid
parameter_list|)
value|(0x944 + (qid) * 8)
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_CONFIG
value|0xc00
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_BASE
value|0xc04
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_WPTR
value|0xc20
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_RPTR_ADDR
value|0xc24
end_define

begin_define
define|#
directive|define
name|WPI_FH_RSSR_TBL
value|0xcc0
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_STATUS
value|0xcc4
end_define

begin_define
define|#
directive|define
name|WPI_FH_TX_CONFIG
parameter_list|(
name|qid
parameter_list|)
value|(0xd00 + (qid) * 32)
end_define

begin_define
define|#
directive|define
name|WPI_FH_TX_BASE
value|0xe80
end_define

begin_define
define|#
directive|define
name|WPI_FH_MSG_CONFIG
value|0xe88
end_define

begin_define
define|#
directive|define
name|WPI_FH_TX_STATUS
value|0xe90
end_define

begin_comment
comment|/*  * NIC internal memory offsets.  */
end_comment

begin_define
define|#
directive|define
name|WPI_ALM_SCHED_MODE
value|0x2e00
end_define

begin_define
define|#
directive|define
name|WPI_ALM_SCHED_ARASTAT
value|0x2e04
end_define

begin_define
define|#
directive|define
name|WPI_ALM_SCHED_TXFACT
value|0x2e10
end_define

begin_define
define|#
directive|define
name|WPI_ALM_SCHED_TXF4MF
value|0x2e14
end_define

begin_define
define|#
directive|define
name|WPI_ALM_SCHED_TXF5MF
value|0x2e20
end_define

begin_define
define|#
directive|define
name|WPI_ALM_SCHED_SBYPASS_MODE1
value|0x2e2c
end_define

begin_define
define|#
directive|define
name|WPI_ALM_SCHED_SBYPASS_MODE2
value|0x2e30
end_define

begin_define
define|#
directive|define
name|WPI_APMG_CLK_EN
value|0x3004
end_define

begin_define
define|#
directive|define
name|WPI_APMG_CLK_DIS
value|0x3008
end_define

begin_define
define|#
directive|define
name|WPI_APMG_PS
value|0x300c
end_define

begin_define
define|#
directive|define
name|WPI_APMG_PCI_STT
value|0x3010
end_define

begin_define
define|#
directive|define
name|WPI_APMG_RFKILL
value|0x3014
end_define

begin_define
define|#
directive|define
name|WPI_BSM_WR_CTRL
value|0x3400
end_define

begin_define
define|#
directive|define
name|WPI_BSM_WR_MEM_SRC
value|0x3404
end_define

begin_define
define|#
directive|define
name|WPI_BSM_WR_MEM_DST
value|0x3408
end_define

begin_define
define|#
directive|define
name|WPI_BSM_WR_DWCOUNT
value|0x340c
end_define

begin_define
define|#
directive|define
name|WPI_BSM_DRAM_TEXT_ADDR
value|0x3490
end_define

begin_define
define|#
directive|define
name|WPI_BSM_DRAM_TEXT_SIZE
value|0x3494
end_define

begin_define
define|#
directive|define
name|WPI_BSM_DRAM_DATA_ADDR
value|0x3498
end_define

begin_define
define|#
directive|define
name|WPI_BSM_DRAM_DATA_SIZE
value|0x349c
end_define

begin_define
define|#
directive|define
name|WPI_BSM_SRAM_BASE
value|0x3800
end_define

begin_comment
comment|/* Possible flags for register WPI_HW_IF_CONFIG. */
end_comment

begin_define
define|#
directive|define
name|WPI_HW_IF_CONFIG_ALM_MB
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|WPI_HW_IF_CONFIG_ALM_MM
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|WPI_HW_IF_CONFIG_SKU_MRC
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|WPI_HW_IF_CONFIG_REV_D
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|WPI_HW_IF_CONFIG_TYPE_B
value|(1<< 12)
end_define

begin_comment
comment|/* Possible flags for registers WPI_PRPH_RADDR/WPI_PRPH_WADDR. */
end_comment

begin_define
define|#
directive|define
name|WPI_PRPH_DWORD
value|((sizeof (uint32_t) - 1)<< 24)
end_define

begin_comment
comment|/* Possible values for WPI_BSM_WR_MEM_DST. */
end_comment

begin_define
define|#
directive|define
name|WPI_FW_TEXT_BASE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|WPI_FW_DATA_BASE
value|0x00800000
end_define

begin_comment
comment|/* Possible flags for WPI_GPIO_IN. */
end_comment

begin_define
define|#
directive|define
name|WPI_GPIO_IN_VMAIN
value|(1<< 9)
end_define

begin_comment
comment|/* Possible flags for register WPI_RESET. */
end_comment

begin_define
define|#
directive|define
name|WPI_RESET_NEVO
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|WPI_RESET_SW
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|WPI_RESET_MASTER_DISABLED
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|WPI_RESET_STOP_MASTER
value|(1<< 9)
end_define

begin_comment
comment|/* Possible flags for register WPI_GP_CNTRL. */
end_comment

begin_define
define|#
directive|define
name|WPI_GP_CNTRL_MAC_ACCESS_ENA
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|WPI_GP_CNTRL_MAC_CLOCK_READY
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|WPI_GP_CNTRL_INIT_DONE
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|WPI_GP_CNTRL_MAC_ACCESS_REQ
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|WPI_GP_CNTRL_SLEEP
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|WPI_GP_CNTRL_PS_MASK
value|(7<< 24)
end_define

begin_define
define|#
directive|define
name|WPI_GP_CNTRL_MAC_PS
value|(4<< 24)
end_define

begin_define
define|#
directive|define
name|WPI_GP_CNTRL_RFKILL
value|(1<< 27)
end_define

begin_comment
comment|/* Possible flags for register WPI_GIO_CHICKEN. */
end_comment

begin_define
define|#
directive|define
name|WPI_GIO_CHICKEN_L1A_NO_L0S_RX
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|WPI_GIO_CHICKEN_DIS_L0S_TIMER
value|(1<< 29)
end_define

begin_comment
comment|/* Possible flags for register WPI_GIO. */
end_comment

begin_define
define|#
directive|define
name|WPI_GIO_L0S_ENA
value|(1<< 1)
end_define

begin_comment
comment|/* Possible flags for register WPI_FH_RX_CONFIG. */
end_comment

begin_define
define|#
directive|define
name|WPI_FH_RX_CONFIG_DMA_ENA
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_CONFIG_RDRBD_ENA
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_CONFIG_WRSTATUS_ENA
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_CONFIG_MAXFRAG
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_CONFIG_NRBD
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_CONFIG_IRQ_DST_HOST
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|WPI_FH_RX_CONFIG_IRQ_TIMEOUT
parameter_list|(
name|x
parameter_list|)
value|((x)<<  4)
end_define

begin_comment
comment|/* Possible flags for register WPI_ANA_PLL. */
end_comment

begin_define
define|#
directive|define
name|WPI_ANA_PLL_INIT
value|(1<< 24)
end_define

begin_comment
comment|/* Possible flags for register WPI_UCODE_GP1*. */
end_comment

begin_define
define|#
directive|define
name|WPI_UCODE_GP1_MAC_SLEEP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|WPI_UCODE_GP1_RFKILL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|WPI_UCODE_GP1_CMD_BLOCKED
value|(1<< 2)
end_define

begin_comment
comment|/* Possible flags for register WPI_FH_RX_STATUS. */
end_comment

begin_define
define|#
directive|define
name|WPI_FH_RX_STATUS_IDLE
value|(1<< 24)
end_define

begin_comment
comment|/* Possible flags for register WPI_BSM_WR_CTRL. */
end_comment

begin_define
define|#
directive|define
name|WPI_BSM_WR_CTRL_START_EN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|WPI_BSM_WR_CTRL_START
value|(1U<< 31)
end_define

begin_comment
comment|/* Possible flags for register WPI_INT. */
end_comment

begin_define
define|#
directive|define
name|WPI_INT_ALIVE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|WPI_INT_WAKEUP
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|WPI_INT_SW_RX
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|WPI_INT_SW_ERR
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|WPI_INT_FH_TX
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|WPI_INT_HW_ERR
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|WPI_INT_FH_RX
value|(1U<< 31)
end_define

begin_comment
comment|/* Shortcut. */
end_comment

begin_define
define|#
directive|define
name|WPI_INT_MASK_DEF
define|\
value|(WPI_INT_SW_ERR | WPI_INT_HW_ERR | WPI_INT_FH_TX  |	\ 	 WPI_INT_FH_RX  | WPI_INT_ALIVE  | WPI_INT_WAKEUP |	\ 	 WPI_INT_SW_RX)
end_define

begin_comment
comment|/* Possible flags for register WPI_FH_INT. */
end_comment

begin_define
define|#
directive|define
name|WPI_FH_INT_RX_CHNL
parameter_list|(
name|x
parameter_list|)
value|(1<< ((x) + 16))
end_define

begin_define
define|#
directive|define
name|WPI_FH_INT_HI_PRIOR
value|(1<< 30)
end_define

begin_comment
comment|/* Shortcuts for the above. */
end_comment

begin_define
define|#
directive|define
name|WPI_FH_INT_RX
define|\
value|(WPI_FH_INT_RX_CHNL(0) |	\ 	 WPI_FH_INT_RX_CHNL(1) |	\ 	 WPI_FH_INT_RX_CHNL(2) |	\ 	 WPI_FH_INT_HI_PRIOR)
end_define

begin_comment
comment|/* Possible flags for register WPI_FH_TX_STATUS. */
end_comment

begin_define
define|#
directive|define
name|WPI_FH_TX_STATUS_IDLE
parameter_list|(
name|qid
parameter_list|)
define|\
value|(1<< ((qid) + 24) | 1<< ((qid) + 16))
end_define

begin_comment
comment|/* Possible flags for register WPI_EEPROM. */
end_comment

begin_define
define|#
directive|define
name|WPI_EEPROM_READ_VALID
value|(1<< 0)
end_define

begin_comment
comment|/* Possible flags for register WPI_EEPROM_GP. */
end_comment

begin_define
define|#
directive|define
name|WPI_EEPROM_VERSION
value|0x00000007
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_GP_IF_OWNER
value|0x00000180
end_define

begin_comment
comment|/* Possible flags for register WPI_APMG_PS. */
end_comment

begin_define
define|#
directive|define
name|WPI_APMG_PS_PWR_SRC_MASK
value|(3<< 24)
end_define

begin_comment
comment|/* Possible flags for registers WPI_APMG_CLK_*. */
end_comment

begin_define
define|#
directive|define
name|WPI_APMG_CLK_CTRL_DMA_CLK_RQT
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|WPI_APMG_CLK_CTRL_BSM_CLK_RQT
value|(1<< 11)
end_define

begin_comment
comment|/* Possible flags for register WPI_APMG_PCI_STT. */
end_comment

begin_define
define|#
directive|define
name|WPI_APMG_PCI_STT_L1A_DIS
value|(1<< 11)
end_define

begin_struct
struct|struct
name|wpi_shared
block|{
name|uint32_t
name|txbase
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|next
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|WPI_MAX_SEG_LEN
value|65520
end_define

begin_struct
struct|struct
name|wpi_tx_desc
block|{
name|uint8_t
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|nsegs
decl_stmt|;
define|#
directive|define
name|WPI_PAD32
parameter_list|(
name|x
parameter_list|)
value|(roundup2(x, 4) - (x))
struct|struct
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
block|}
name|__packed
name|segs
index|[
name|WPI_MAX_SCATTER
index|]
struct|;
name|uint8_t
name|reserved2
index|[
literal|28
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_tx_stat
block|{
name|uint8_t
name|rtsfailcnt
decl_stmt|;
name|uint8_t
name|ackfailcnt
decl_stmt|;
name|uint8_t
name|btkillcnt
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint32_t
name|duration
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_rx_desc
block|{
name|uint32_t
name|len
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|WPI_UC_READY
value|1
define|#
directive|define
name|WPI_RX_DONE
value|27
define|#
directive|define
name|WPI_TX_DONE
value|28
define|#
directive|define
name|WPI_START_SCAN
value|130
define|#
directive|define
name|WPI_SCAN_RESULTS
value|131
define|#
directive|define
name|WPI_STOP_SCAN
value|132
define|#
directive|define
name|WPI_BEACON_SENT
value|144
define|#
directive|define
name|WPI_RX_STATISTICS
value|156
define|#
directive|define
name|WPI_BEACON_STATISTICS
value|157
define|#
directive|define
name|WPI_STATE_CHANGED
value|161
define|#
directive|define
name|WPI_BEACON_MISSED
value|162
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|idx
decl_stmt|;
name|uint8_t
name|qid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_rx_stat
block|{
name|uint8_t
name|len
decl_stmt|;
define|#
directive|define
name|WPI_STAT_MAXLEN
value|20
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|rssi
decl_stmt|;
comment|/* received signal strength */
define|#
directive|define
name|WPI_RSSI_OFFSET
value|95
name|uint8_t
name|agc
decl_stmt|;
comment|/* access gain control */
name|uint16_t
name|signal
decl_stmt|;
name|uint16_t
name|noise
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_rx_head
block|{
name|uint16_t
name|chan
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|WPI_STAT_FLAG_SHPREAMBLE
value|(1<< 2)
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|plcp
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_rx_tail
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|WPI_RX_NO_CRC_ERR
value|(1<< 0)
define|#
directive|define
name|WPI_RX_NO_OVFL_ERR
value|(1<< 1)
comment|/* shortcut for the above */
define|#
directive|define
name|WPI_RX_NOERROR
value|(WPI_RX_NO_CRC_ERR | WPI_RX_NO_OVFL_ERR)
define|#
directive|define
name|WPI_RX_CIPHER_MASK
value|(7<<  8)
define|#
directive|define
name|WPI_RX_CIPHER_CCMP
value|(2<<  8)
define|#
directive|define
name|WPI_RX_DECRYPT_MASK
value|(3<< 11)
define|#
directive|define
name|WPI_RX_DECRYPT_OK
value|(3<< 11)
name|uint64_t
name|tstamp
decl_stmt|;
name|uint32_t
name|tbeacon
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_tx_cmd
block|{
name|uint8_t
name|code
decl_stmt|;
define|#
directive|define
name|WPI_CMD_RXON
value|16
define|#
directive|define
name|WPI_CMD_RXON_ASSOC
value|17
define|#
directive|define
name|WPI_CMD_EDCA_PARAMS
value|19
define|#
directive|define
name|WPI_CMD_TIMING
value|20
define|#
directive|define
name|WPI_CMD_ADD_NODE
value|24
define|#
directive|define
name|WPI_CMD_DEL_NODE
value|25
define|#
directive|define
name|WPI_CMD_TX_DATA
value|28
define|#
directive|define
name|WPI_CMD_MRR_SETUP
value|71
define|#
directive|define
name|WPI_CMD_SET_LED
value|72
define|#
directive|define
name|WPI_CMD_SET_POWER_MODE
value|119
define|#
directive|define
name|WPI_CMD_SCAN
value|128
define|#
directive|define
name|WPI_CMD_SET_BEACON
value|145
define|#
directive|define
name|WPI_CMD_TXPOWER
value|151
define|#
directive|define
name|WPI_CMD_BT_COEX
value|155
define|#
directive|define
name|WPI_CMD_GET_STATISTICS
value|156
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|idx
decl_stmt|;
name|uint8_t
name|qid
decl_stmt|;
name|uint8_t
name|data
index|[
literal|124
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_RXON. */
end_comment

begin_struct
struct|struct
name|wpi_rxon
block|{
name|uint8_t
name|myaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint8_t
name|wlap
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|reserved3
decl_stmt|;
name|uint8_t
name|mode
decl_stmt|;
define|#
directive|define
name|WPI_MODE_HOSTAP
value|1
define|#
directive|define
name|WPI_MODE_STA
value|3
define|#
directive|define
name|WPI_MODE_IBSS
value|4
define|#
directive|define
name|WPI_MODE_MONITOR
value|6
name|uint8_t
name|air
decl_stmt|;
name|uint16_t
name|reserved4
decl_stmt|;
name|uint8_t
name|ofdm_mask
decl_stmt|;
name|uint8_t
name|cck_mask
decl_stmt|;
name|uint16_t
name|associd
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|WPI_RXON_24GHZ
value|(1<<  0)
define|#
directive|define
name|WPI_RXON_CCK
value|(1<<  1)
define|#
directive|define
name|WPI_RXON_AUTO
value|(1<<  2)
define|#
directive|define
name|WPI_RXON_SHSLOT
value|(1<<  4)
define|#
directive|define
name|WPI_RXON_SHPREAMBLE
value|(1<<  5)
define|#
directive|define
name|WPI_RXON_NODIVERSITY
value|(1<<  7)
define|#
directive|define
name|WPI_RXON_ANTENNA_A
value|(1<<  8)
define|#
directive|define
name|WPI_RXON_ANTENNA_B
value|(1<<  9)
define|#
directive|define
name|WPI_RXON_TSF
value|(1<< 15)
define|#
directive|define
name|WPI_RXON_CTS_TO_SELF
value|(1<< 30)
name|uint32_t
name|filter
decl_stmt|;
define|#
directive|define
name|WPI_FILTER_PROMISC
value|(1<< 0)
define|#
directive|define
name|WPI_FILTER_CTL
value|(1<< 1)
define|#
directive|define
name|WPI_FILTER_MULTICAST
value|(1<< 2)
define|#
directive|define
name|WPI_FILTER_NODECRYPT
value|(1<< 3)
define|#
directive|define
name|WPI_FILTER_BSS
value|(1<< 5)
define|#
directive|define
name|WPI_FILTER_BEACON
value|(1<< 6)
name|uint8_t
name|chan
decl_stmt|;
name|uint16_t
name|reserved5
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_RXON_ASSOC. */
end_comment

begin_struct
struct|struct
name|wpi_assoc
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|filter
decl_stmt|;
name|uint8_t
name|ofdm_mask
decl_stmt|;
name|uint8_t
name|cck_mask
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_EDCA_PARAMS. */
end_comment

begin_struct
struct|struct
name|wpi_edca_params
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|WPI_EDCA_UPDATE
value|(1<< 0)
struct|struct
block|{
name|uint16_t
name|cwmin
decl_stmt|;
name|uint16_t
name|cwmax
decl_stmt|;
name|uint8_t
name|aifsn
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|txoplimit
decl_stmt|;
block|}
name|__packed
name|ac
index|[
name|WME_NUM_AC
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_TIMING. */
end_comment

begin_struct
struct|struct
name|wpi_cmd_timing
block|{
name|uint64_t
name|tstamp
decl_stmt|;
name|uint16_t
name|bintval
decl_stmt|;
name|uint16_t
name|atim
decl_stmt|;
name|uint32_t
name|binitval
decl_stmt|;
name|uint16_t
name|lintval
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_ADD_NODE. */
end_comment

begin_struct
struct|struct
name|wpi_node_info
block|{
name|uint8_t
name|control
decl_stmt|;
define|#
directive|define
name|WPI_NODE_UPDATE
value|(1<< 0)
name|uint8_t
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
define|#
directive|define
name|WPI_ID_BSS
value|0
define|#
directive|define
name|WPI_ID_IBSS_MIN
value|2
define|#
directive|define
name|WPI_ID_IBSS_MAX
value|23
define|#
directive|define
name|WPI_ID_BROADCAST
value|24
define|#
directive|define
name|WPI_ID_UNDEFINED
value|(uint8_t)-1
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|WPI_FLAG_KEY_SET
value|(1<< 0)
name|uint16_t
name|reserved3
decl_stmt|;
name|uint16_t
name|kflags
decl_stmt|;
define|#
directive|define
name|WPI_KFLAG_CCMP
value|(1<<  1)
define|#
directive|define
name|WPI_KFLAG_KID
parameter_list|(
name|kid
parameter_list|)
value|((kid)<< 8)
define|#
directive|define
name|WPI_KFLAG_MULTICAST
value|(1<< 14)
name|uint8_t
name|tsc2
decl_stmt|;
name|uint8_t
name|reserved4
decl_stmt|;
name|uint16_t
name|ttak
index|[
literal|5
index|]
decl_stmt|;
name|uint16_t
name|reserved5
decl_stmt|;
name|uint8_t
name|key
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
name|uint32_t
name|action
decl_stmt|;
define|#
directive|define
name|WPI_ACTION_SET_RATE
value|(1<< 2)
name|uint32_t
name|mask
decl_stmt|;
name|uint16_t
name|tid
decl_stmt|;
name|uint8_t
name|plcp
decl_stmt|;
name|uint8_t
name|antenna
decl_stmt|;
define|#
directive|define
name|WPI_ANTENNA_A
value|(1<< 6)
define|#
directive|define
name|WPI_ANTENNA_B
value|(1<< 7)
define|#
directive|define
name|WPI_ANTENNA_BOTH
value|(WPI_ANTENNA_A | WPI_ANTENNA_B)
name|uint8_t
name|add_imm
decl_stmt|;
name|uint8_t
name|del_imm
decl_stmt|;
name|uint16_t
name|add_imm_start
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_DEL_NODE. */
end_comment

begin_struct
struct|struct
name|wpi_cmd_del_node
block|{
name|uint8_t
name|count
decl_stmt|;
name|uint8_t
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_TX_DATA. */
end_comment

begin_struct
struct|struct
name|wpi_cmd_data
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|lnext
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|WPI_TX_NEED_RTS
value|(1<<  1)
define|#
directive|define
name|WPI_TX_NEED_CTS
value|(1<<  2)
define|#
directive|define
name|WPI_TX_NEED_ACK
value|(1<<  3)
define|#
directive|define
name|WPI_TX_FULL_TXOP
value|(1<<  7)
define|#
directive|define
name|WPI_TX_BT_DISABLE
value|(1<< 12)
comment|/* bluetooth coexistence */
define|#
directive|define
name|WPI_TX_AUTO_SEQ
value|(1<< 13)
define|#
directive|define
name|WPI_TX_MORE_FRAG
value|(1<< 14)
define|#
directive|define
name|WPI_TX_INSERT_TSTAMP
value|(1<< 16)
name|uint8_t
name|plcp
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|tid
decl_stmt|;
name|uint8_t
name|security
decl_stmt|;
define|#
directive|define
name|WPI_CIPHER_WEP
value|1
define|#
directive|define
name|WPI_CIPHER_CCMP
value|2
define|#
directive|define
name|WPI_CIPHER_TKIP
value|3
define|#
directive|define
name|WPI_CIPHER_WEP104
value|9
name|uint8_t
name|key
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
name|uint8_t
name|tkip
index|[
name|IEEE80211_WEP_MICLEN
index|]
decl_stmt|;
name|uint32_t
name|fnext
decl_stmt|;
name|uint32_t
name|lifetime
decl_stmt|;
define|#
directive|define
name|WPI_LIFETIME_INFINITE
value|0xffffffff
name|uint8_t
name|ofdm_mask
decl_stmt|;
name|uint8_t
name|cck_mask
decl_stmt|;
name|uint8_t
name|rts_ntries
decl_stmt|;
name|uint8_t
name|data_ntries
decl_stmt|;
name|uint16_t
name|timeout
decl_stmt|;
name|uint16_t
name|txop
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_SET_BEACON. */
end_comment

begin_struct
struct|struct
name|wpi_cmd_beacon
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* same as wpi_cmd_data */
name|uint8_t
name|plcp
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|30
index|]
decl_stmt|;
name|uint32_t
name|lifetime
decl_stmt|;
name|uint8_t
name|ofdm_mask
decl_stmt|;
name|uint8_t
name|cck_mask
decl_stmt|;
name|uint16_t
name|reserved3
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|tim
decl_stmt|;
name|uint8_t
name|timsz
decl_stmt|;
name|uint8_t
name|reserved4
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for notification WPI_BEACON_MISSED. */
end_comment

begin_struct
struct|struct
name|wpi_beacon_missed
block|{
name|uint32_t
name|consecutive
decl_stmt|;
name|uint32_t
name|total
decl_stmt|;
name|uint32_t
name|expected
decl_stmt|;
name|uint32_t
name|received
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_MRR_SETUP. */
end_comment

begin_define
define|#
directive|define
name|WPI_RIDX_MAX
value|11
end_define

begin_struct
struct|struct
name|wpi_mrr_setup
block|{
name|uint32_t
name|which
decl_stmt|;
define|#
directive|define
name|WPI_MRR_CTL
value|0
define|#
directive|define
name|WPI_MRR_DATA
value|1
struct|struct
block|{
name|uint8_t
name|plcp
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|ntries
decl_stmt|;
name|uint8_t
name|next
decl_stmt|;
block|}
name|__packed
name|rates
index|[
name|WPI_RIDX_MAX
operator|+
literal|1
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_SET_LED. */
end_comment

begin_struct
struct|struct
name|wpi_cmd_led
block|{
name|uint32_t
name|unit
decl_stmt|;
comment|/* multiplier (in usecs) */
name|uint8_t
name|which
decl_stmt|;
define|#
directive|define
name|WPI_LED_ACTIVITY
value|1
define|#
directive|define
name|WPI_LED_LINK
value|2
name|uint8_t
name|off
decl_stmt|;
name|uint8_t
name|on
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_SET_POWER_MODE. */
end_comment

begin_struct
struct|struct
name|wpi_pmgt_cmd
block|{
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|WPI_PS_ALLOW_SLEEP
value|(1<< 0)
define|#
directive|define
name|WPI_PS_NOTIFY
value|(1<< 1)
define|#
directive|define
name|WPI_PS_SLEEP_OVER_DTIM
value|(1<< 2)
define|#
directive|define
name|WPI_PS_PCI_PMGT
value|(1<< 3)
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|rxtimeout
decl_stmt|;
name|uint32_t
name|txtimeout
decl_stmt|;
name|uint32_t
name|intval
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structures for command WPI_CMD_SCAN. */
end_comment

begin_define
define|#
directive|define
name|WPI_SCAN_MAX_ESSIDS
value|4
end_define

begin_struct
struct|struct
name|wpi_scan_essid
block|{
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
name|uint8_t
name|data
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_scan_hdr
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint8_t
name|nchan
decl_stmt|;
name|uint16_t
name|quiet_time
decl_stmt|;
name|uint16_t
name|quiet_threshold
decl_stmt|;
name|uint16_t
name|crc_threshold
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint32_t
name|max_svc
decl_stmt|;
comment|/* background scans */
name|uint32_t
name|pause_svc
decl_stmt|;
comment|/* background scans */
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|filter
decl_stmt|;
comment|/* Followed by a struct wpi_cmd_data. */
comment|/* Followed by an array of 4 structs wpi_scan_essid. */
comment|/* Followed by probe request body. */
comment|/* Followed by an array of ``nchan'' structs wpi_scan_chan. */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_scan_chan
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|WPI_CHAN_ACTIVE
value|(1<< 0)
define|#
directive|define
name|WPI_CHAN_NPBREQS
parameter_list|(
name|x
parameter_list|)
value|(((1<< (x)) - 1)<< 1)
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|rf_gain
decl_stmt|;
name|uint8_t
name|dsp_gain
decl_stmt|;
name|uint16_t
name|active
decl_stmt|;
comment|/* msecs */
name|uint16_t
name|passive
decl_stmt|;
comment|/* msecs */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|WPI_SCAN_CRC_TH_DEFAULT
value|htole16(1)
end_define

begin_define
define|#
directive|define
name|WPI_SCAN_CRC_TH_NEVER
value|htole16(0xffff)
end_define

begin_comment
comment|/* Maximum size of a scan command. */
end_comment

begin_define
define|#
directive|define
name|WPI_SCAN_MAXSZ
value|(MCLBYTES - 4)
end_define

begin_define
define|#
directive|define
name|WPI_ACTIVE_DWELL_TIME_2GHZ
value|(30)
end_define

begin_comment
comment|/* all times in msec */
end_comment

begin_define
define|#
directive|define
name|WPI_ACTIVE_DWELL_TIME_5GHZ
value|(20)
end_define

begin_define
define|#
directive|define
name|WPI_ACTIVE_DWELL_FACTOR_2GHZ
value|( 3)
end_define

begin_define
define|#
directive|define
name|WPI_ACTIVE_DWELL_FACTOR_5GHZ
value|( 2)
end_define

begin_define
define|#
directive|define
name|WPI_PASSIVE_DWELL_TIME_2GHZ
value|( 20)
end_define

begin_define
define|#
directive|define
name|WPI_PASSIVE_DWELL_TIME_5GHZ
value|( 10)
end_define

begin_define
define|#
directive|define
name|WPI_PASSIVE_DWELL_BASE
value|(100)
end_define

begin_comment
comment|/* Structure for command WPI_CMD_TXPOWER. */
end_comment

begin_struct
struct|struct
name|wpi_cmd_txpower
block|{
name|uint8_t
name|band
decl_stmt|;
define|#
directive|define
name|WPI_BAND_5GHZ
value|0
define|#
directive|define
name|WPI_BAND_2GHZ
value|1
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|chan
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|plcp
decl_stmt|;
name|uint8_t
name|rf_gain
decl_stmt|;
name|uint8_t
name|dsp_gain
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
name|rates
index|[
name|WPI_RIDX_MAX
operator|+
literal|1
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command WPI_CMD_BT_COEX. */
end_comment

begin_struct
struct|struct
name|wpi_bluetooth
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|WPI_BT_COEX_DISABLE
value|0
define|#
directive|define
name|WPI_BT_COEX_MODE_2WIRE
value|1
define|#
directive|define
name|WPI_BT_COEX_MODE_3WIRE
value|2
define|#
directive|define
name|WPI_BT_COEX_MODE_4WIRE
value|3
name|uint8_t
name|lead_time
decl_stmt|;
define|#
directive|define
name|WPI_BT_LEAD_TIME_DEF
value|30
name|uint8_t
name|max_kill
decl_stmt|;
define|#
directive|define
name|WPI_BT_MAX_KILL_DEF
value|5
name|uint8_t
name|reserved
decl_stmt|;
name|uint32_t
name|kill_ack
decl_stmt|;
name|uint32_t
name|kill_cts
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for WPI_UC_READY notification. */
end_comment

begin_struct
struct|struct
name|wpi_ucode_info
block|{
name|uint8_t
name|minor
decl_stmt|;
name|uint8_t
name|major
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|revision
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|subtype
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint32_t
name|logptr
decl_stmt|;
name|uint32_t
name|errptr
decl_stmt|;
name|uint32_t
name|tstamp
decl_stmt|;
name|uint32_t
name|valid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for WPI_START_SCAN notification. */
end_comment

begin_struct
struct|struct
name|wpi_start_scan
block|{
name|uint64_t
name|tstamp
decl_stmt|;
name|uint32_t
name|tbeacon
decl_stmt|;
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|band
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for WPI_STOP_SCAN notification. */
end_comment

begin_struct
struct|struct
name|wpi_stop_scan
block|{
name|uint8_t
name|nchan
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|chan
decl_stmt|;
name|uint64_t
name|tsf
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structures for WPI_{RX,BEACON}_STATISTICS notification. */
end_comment

begin_struct
struct|struct
name|wpi_rx_phy_stats
block|{
name|uint32_t
name|ina
decl_stmt|;
name|uint32_t
name|fina
decl_stmt|;
name|uint32_t
name|bad_plcp
decl_stmt|;
name|uint32_t
name|bad_crc32
decl_stmt|;
name|uint32_t
name|overrun
decl_stmt|;
name|uint32_t
name|eoverrun
decl_stmt|;
name|uint32_t
name|good_crc32
decl_stmt|;
name|uint32_t
name|fa
decl_stmt|;
name|uint32_t
name|bad_fina_sync
decl_stmt|;
name|uint32_t
name|sfd_timeout
decl_stmt|;
name|uint32_t
name|fina_timeout
decl_stmt|;
name|uint32_t
name|no_rts_ack
decl_stmt|;
name|uint32_t
name|rxe_limit
decl_stmt|;
name|uint32_t
name|ack
decl_stmt|;
name|uint32_t
name|cts
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_rx_general_stats
block|{
name|uint32_t
name|bad_cts
decl_stmt|;
name|uint32_t
name|bad_ack
decl_stmt|;
name|uint32_t
name|not_bss
decl_stmt|;
name|uint32_t
name|filtered
decl_stmt|;
name|uint32_t
name|bad_chan
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_rx_stats
block|{
name|struct
name|wpi_rx_phy_stats
name|ofdm
decl_stmt|;
name|struct
name|wpi_rx_phy_stats
name|cck
decl_stmt|;
name|struct
name|wpi_rx_general_stats
name|general
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_tx_stats
block|{
name|uint32_t
name|preamble
decl_stmt|;
name|uint32_t
name|rx_detected
decl_stmt|;
name|uint32_t
name|bt_defer
decl_stmt|;
name|uint32_t
name|bt_kill
decl_stmt|;
name|uint32_t
name|short_len
decl_stmt|;
name|uint32_t
name|cts_timeout
decl_stmt|;
name|uint32_t
name|ack_timeout
decl_stmt|;
name|uint32_t
name|exp_ack
decl_stmt|;
name|uint32_t
name|ack
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_general_stats
block|{
name|uint32_t
name|temp
decl_stmt|;
name|uint32_t
name|burst_check
decl_stmt|;
name|uint32_t
name|burst
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|sleep
decl_stmt|;
name|uint32_t
name|slot_out
decl_stmt|;
name|uint32_t
name|slot_idle
decl_stmt|;
name|uint32_t
name|ttl_tstamp
decl_stmt|;
name|uint32_t
name|tx_ant_a
decl_stmt|;
name|uint32_t
name|tx_ant_b
decl_stmt|;
name|uint32_t
name|exec
decl_stmt|;
name|uint32_t
name|probe
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_stats
block|{
name|uint32_t
name|flags
decl_stmt|;
name|struct
name|wpi_rx_stats
name|rx
decl_stmt|;
name|struct
name|wpi_tx_stats
name|tx
decl_stmt|;
name|struct
name|wpi_general_stats
name|general
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Possible flags for command WPI_CMD_GET_STATISTICS. */
end_comment

begin_define
define|#
directive|define
name|WPI_STATISTICS_BEACON_DISABLE
value|(1<< 1)
end_define

begin_comment
comment|/* Firmware error dump entry. */
end_comment

begin_struct
struct|struct
name|wpi_fw_dump
block|{
name|uint32_t
name|desc
decl_stmt|;
name|uint32_t
name|time
decl_stmt|;
name|uint32_t
name|blink
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|ilink
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|data
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Firmware image file header. */
end_comment

begin_struct
struct|struct
name|wpi_firmware_hdr
block|{
define|#
directive|define
name|WPI_FW_MINVERSION
value|2144
define|#
directive|define
name|WPI_FW_NAME
value|"wpifw"
name|uint16_t
name|driver
decl_stmt|;
name|uint8_t
name|minor
decl_stmt|;
name|uint8_t
name|major
decl_stmt|;
name|uint32_t
name|rtextsz
decl_stmt|;
name|uint32_t
name|rdatasz
decl_stmt|;
name|uint32_t
name|itextsz
decl_stmt|;
name|uint32_t
name|idatasz
decl_stmt|;
name|uint32_t
name|btextsz
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|WPI_FW_TEXT_MAXSZ
value|( 80 * 1024 )
end_define

begin_define
define|#
directive|define
name|WPI_FW_DATA_MAXSZ
value|( 32 * 1024 )
end_define

begin_define
define|#
directive|define
name|WPI_FW_BOOT_TEXT_MAXSZ
value|1024
end_define

begin_define
define|#
directive|define
name|WPI_FW_UPDATED
value|(1U<< 31 )
end_define

begin_comment
comment|/*  * Offsets into EEPROM.  */
end_comment

begin_define
define|#
directive|define
name|WPI_EEPROM_MAC
value|0x015
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_REVISION
value|0x035
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_SKU_CAP
value|0x045
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_TYPE
value|0x04a
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_DOMAIN
value|0x060
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_BAND1
value|0x063
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_BAND2
value|0x072
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_BAND3
value|0x080
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_BAND4
value|0x08d
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_BAND5
value|0x099
end_define

begin_define
define|#
directive|define
name|WPI_EEPROM_POWER_GRP
value|0x100
end_define

begin_struct
struct|struct
name|wpi_eeprom_chan
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|WPI_EEPROM_CHAN_VALID
value|(1<< 0)
define|#
directive|define
name|WPI_EEPROM_CHAN_IBSS
value|(1<< 1)
define|#
directive|define
name|WPI_EEPROM_CHAN_ACTIVE
value|(1<< 3)
define|#
directive|define
name|WPI_EEPROM_CHAN_RADAR
value|(1<< 4)
name|int8_t
name|maxpwr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|wpi_eeprom_sample
block|{
name|uint8_t
name|index
decl_stmt|;
name|int8_t
name|power
decl_stmt|;
name|uint16_t
name|volt
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|WPI_POWER_GROUPS_COUNT
value|5
end_define

begin_struct
struct|struct
name|wpi_eeprom_group
block|{
name|struct
name|wpi_eeprom_sample
name|samples
index|[
literal|5
index|]
decl_stmt|;
name|int32_t
name|coef
index|[
literal|5
index|]
decl_stmt|;
name|int32_t
name|corr
index|[
literal|5
index|]
decl_stmt|;
name|int8_t
name|maxpwr
decl_stmt|;
name|uint8_t
name|chan
decl_stmt|;
name|int16_t
name|temp
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|WPI_CHAN_BANDS_COUNT
value|5
end_define

begin_define
define|#
directive|define
name|WPI_MAX_CHAN_PER_BAND
value|14
end_define

begin_struct
specifier|static
specifier|const
struct|struct
name|wpi_chan_band
block|{
name|uint32_t
name|addr
decl_stmt|;
comment|/* offset in EEPROM */
name|uint8_t
name|nchan
decl_stmt|;
name|uint8_t
name|chan
index|[
name|WPI_MAX_CHAN_PER_BAND
index|]
decl_stmt|;
block|}
name|wpi_bands
index|[]
init|=
block|{
comment|/* 20MHz channels, 2GHz band. */
block|{
name|WPI_EEPROM_BAND1
block|,
literal|14
block|,
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|}
block|}
block|,
comment|/* 20MHz channels, 5GHz band. */
block|{
name|WPI_EEPROM_BAND2
block|,
literal|13
block|,
block|{
literal|183
block|,
literal|184
block|,
literal|185
block|,
literal|187
block|,
literal|188
block|,
literal|189
block|,
literal|192
block|,
literal|196
block|,
literal|7
block|,
literal|8
block|,
literal|11
block|,
literal|12
block|,
literal|16
block|}
block|}
block|,
block|{
name|WPI_EEPROM_BAND3
block|,
literal|12
block|,
block|{
literal|34
block|,
literal|36
block|,
literal|38
block|,
literal|40
block|,
literal|42
block|,
literal|44
block|,
literal|46
block|,
literal|48
block|,
literal|52
block|,
literal|56
block|,
literal|60
block|,
literal|64
block|}
block|}
block|,
block|{
name|WPI_EEPROM_BAND4
block|,
literal|11
block|,
block|{
literal|100
block|,
literal|104
block|,
literal|108
block|,
literal|112
block|,
literal|116
block|,
literal|120
block|,
literal|124
block|,
literal|128
block|,
literal|132
block|,
literal|136
block|,
literal|140
block|}
block|}
block|,
block|{
name|WPI_EEPROM_BAND5
block|,
literal|6
block|,
block|{
literal|145
block|,
literal|149
block|,
literal|153
block|,
literal|157
block|,
literal|161
block|,
literal|165
block|}
block|}
block|}
struct|;
end_struct

begin_comment
comment|/* HW rate indices. */
end_comment

begin_define
define|#
directive|define
name|WPI_RIDX_OFDM6
value|0
end_define

begin_define
define|#
directive|define
name|WPI_RIDX_OFDM36
value|5
end_define

begin_define
define|#
directive|define
name|WPI_RIDX_OFDM48
value|6
end_define

begin_define
define|#
directive|define
name|WPI_RIDX_OFDM54
value|7
end_define

begin_define
define|#
directive|define
name|WPI_RIDX_CCK1
value|8
end_define

begin_define
define|#
directive|define
name|WPI_RIDX_CCK2
value|9
end_define

begin_define
define|#
directive|define
name|WPI_RIDX_CCK11
value|11
end_define

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|wpi_ridx_to_plcp
index|[]
init|=
block|{
comment|/* OFDM: IEEE Std 802.11a-1999, pp. 14 Table 80 */
comment|/* R1-R4 (ral/ural is R4-R1) */
literal|0xd
block|,
literal|0xf
block|,
literal|0x5
block|,
literal|0x7
block|,
literal|0x9
block|,
literal|0xb
block|,
literal|0x1
block|,
literal|0x3
block|,
comment|/* CCK: device-dependent */
literal|10
block|,
literal|20
block|,
literal|55
block|,
literal|110
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|WPI_MAX_PWR_INDEX
value|77
end_define

begin_comment
comment|/*  * RF Tx gain values from highest to lowest power (values obtained from  * the reference driver.)  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|wpi_rf_gain_2ghz
index|[
name|WPI_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0xfb
block|,
literal|0xfb
block|,
literal|0xfb
block|,
literal|0xfb
block|,
literal|0xfb
block|,
literal|0xfb
block|,
literal|0xfb
block|,
literal|0xfb
block|,
literal|0xbb
block|,
literal|0xbb
block|,
literal|0xbb
block|,
literal|0xbb
block|,
literal|0xf3
block|,
literal|0xf3
block|,
literal|0xf3
block|,
literal|0xf3
block|,
literal|0xf3
block|,
literal|0xd3
block|,
literal|0xd3
block|,
literal|0xb3
block|,
literal|0xb3
block|,
literal|0xb3
block|,
literal|0x93
block|,
literal|0x93
block|,
literal|0x93
block|,
literal|0x93
block|,
literal|0x93
block|,
literal|0x93
block|,
literal|0x93
block|,
literal|0x73
block|,
literal|0xeb
block|,
literal|0xeb
block|,
literal|0xeb
block|,
literal|0xcb
block|,
literal|0xcb
block|,
literal|0xcb
block|,
literal|0xcb
block|,
literal|0xcb
block|,
literal|0xcb
block|,
literal|0xcb
block|,
literal|0xab
block|,
literal|0xab
block|,
literal|0xab
block|,
literal|0x8b
block|,
literal|0xe3
block|,
literal|0xe3
block|,
literal|0xe3
block|,
literal|0xe3
block|,
literal|0xe3
block|,
literal|0xe3
block|,
literal|0xc3
block|,
literal|0xc3
block|,
literal|0xc3
block|,
literal|0xc3
block|,
literal|0xa3
block|,
literal|0xa3
block|,
literal|0xa3
block|,
literal|0xa3
block|,
literal|0x83
block|,
literal|0x83
block|,
literal|0x83
block|,
literal|0x83
block|,
literal|0x63
block|,
literal|0x63
block|,
literal|0x63
block|,
literal|0x63
block|,
literal|0x43
block|,
literal|0x43
block|,
literal|0x43
block|,
literal|0x43
block|,
literal|0x23
block|,
literal|0x23
block|,
literal|0x23
block|,
literal|0x23
block|,
literal|0x03
block|,
literal|0x03
block|,
literal|0x03
block|,
literal|0x03
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|wpi_rf_gain_5ghz
index|[
name|WPI_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0xfb
block|,
literal|0xfb
block|,
literal|0xfb
block|,
literal|0xdb
block|,
literal|0xdb
block|,
literal|0xbb
block|,
literal|0xbb
block|,
literal|0x9b
block|,
literal|0x9b
block|,
literal|0x7b
block|,
literal|0x7b
block|,
literal|0x7b
block|,
literal|0x7b
block|,
literal|0x5b
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x1b
block|,
literal|0x1b
block|,
literal|0x1b
block|,
literal|0x73
block|,
literal|0x73
block|,
literal|0x73
block|,
literal|0x53
block|,
literal|0x53
block|,
literal|0x53
block|,
literal|0x53
block|,
literal|0x53
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x13
block|,
literal|0x13
block|,
literal|0x13
block|,
literal|0x13
block|,
literal|0x13
block|,
literal|0xab
block|,
literal|0xab
block|,
literal|0xab
block|,
literal|0x8b
block|,
literal|0x8b
block|,
literal|0x8b
block|,
literal|0x8b
block|,
literal|0x6b
block|,
literal|0x6b
block|,
literal|0x6b
block|,
literal|0x6b
block|,
literal|0x4b
block|,
literal|0x4b
block|,
literal|0x4b
block|,
literal|0x4b
block|,
literal|0x2b
block|,
literal|0x2b
block|,
literal|0x2b
block|,
literal|0x2b
block|,
literal|0x0b
block|,
literal|0x0b
block|,
literal|0x0b
block|,
literal|0x0b
block|,
literal|0x83
block|,
literal|0x83
block|,
literal|0x63
block|,
literal|0x63
block|,
literal|0x63
block|,
literal|0x63
block|,
literal|0x43
block|,
literal|0x43
block|,
literal|0x43
block|,
literal|0x43
block|,
literal|0x23
block|,
literal|0x23
block|,
literal|0x23
block|,
literal|0x23
block|,
literal|0x03
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * DSP pre-DAC gain values from highest to lowest power (values obtained  * from the reference driver.)  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|wpi_dsp_gain_2ghz
index|[
name|WPI_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0x7f
block|,
literal|0x7f
block|,
literal|0x7f
block|,
literal|0x7f
block|,
literal|0x7d
block|,
literal|0x6e
block|,
literal|0x69
block|,
literal|0x62
block|,
literal|0x7d
block|,
literal|0x73
block|,
literal|0x6c
block|,
literal|0x63
block|,
literal|0x77
block|,
literal|0x6f
block|,
literal|0x69
block|,
literal|0x61
block|,
literal|0x5c
block|,
literal|0x6a
block|,
literal|0x64
block|,
literal|0x78
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x7d
block|,
literal|0x77
block|,
literal|0x70
block|,
literal|0x6a
block|,
literal|0x65
block|,
literal|0x61
block|,
literal|0x5b
block|,
literal|0x6b
block|,
literal|0x79
block|,
literal|0x73
block|,
literal|0x6d
block|,
literal|0x7f
block|,
literal|0x79
block|,
literal|0x73
block|,
literal|0x6c
block|,
literal|0x66
block|,
literal|0x60
block|,
literal|0x5c
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x74
block|,
literal|0x7d
block|,
literal|0x77
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x65
block|,
literal|0x60
block|,
literal|0x71
block|,
literal|0x6a
block|,
literal|0x66
block|,
literal|0x5f
block|,
literal|0x71
block|,
literal|0x6a
block|,
literal|0x66
block|,
literal|0x5f
block|,
literal|0x71
block|,
literal|0x6a
block|,
literal|0x66
block|,
literal|0x5f
block|,
literal|0x71
block|,
literal|0x6a
block|,
literal|0x66
block|,
literal|0x5f
block|,
literal|0x71
block|,
literal|0x6a
block|,
literal|0x66
block|,
literal|0x5f
block|,
literal|0x71
block|,
literal|0x6a
block|,
literal|0x66
block|,
literal|0x5f
block|,
literal|0x71
block|,
literal|0x6a
block|,
literal|0x66
block|,
literal|0x5f
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|wpi_dsp_gain_5ghz
index|[
name|WPI_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0x7f
block|,
literal|0x78
block|,
literal|0x72
block|,
literal|0x77
block|,
literal|0x65
block|,
literal|0x71
block|,
literal|0x66
block|,
literal|0x72
block|,
literal|0x67
block|,
literal|0x75
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x5c
block|,
literal|0x6c
block|,
literal|0x7d
block|,
literal|0x76
block|,
literal|0x6d
block|,
literal|0x66
block|,
literal|0x60
block|,
literal|0x5a
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x5c
block|,
literal|0x76
block|,
literal|0x6f
block|,
literal|0x68
block|,
literal|0x7e
block|,
literal|0x79
block|,
literal|0x71
block|,
literal|0x69
block|,
literal|0x63
block|,
literal|0x76
block|,
literal|0x6f
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x74
block|,
literal|0x6d
block|,
literal|0x66
block|,
literal|0x62
block|,
literal|0x5d
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x78
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x78
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x78
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x78
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x78
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x78
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x78
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x78
block|,
literal|0x71
block|,
literal|0x6b
block|,
literal|0x63
block|,
literal|0x78
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Power saving settings (values obtained from the reference driver.)  */
end_comment

begin_define
define|#
directive|define
name|WPI_NDTIMRANGES
value|2
end_define

begin_define
define|#
directive|define
name|WPI_NPOWERLEVELS
value|6
end_define

begin_struct
specifier|static
specifier|const
struct|struct
name|wpi_pmgt
block|{
name|uint32_t
name|rxtimeout
decl_stmt|;
name|uint32_t
name|txtimeout
decl_stmt|;
name|uint32_t
name|intval
index|[
literal|5
index|]
decl_stmt|;
name|int
name|skip_dtim
decl_stmt|;
block|}
name|wpi_pmgt
index|[
name|WPI_NDTIMRANGES
index|]
index|[
name|WPI_NPOWERLEVELS
index|]
init|=
block|{
comment|/* DTIM<= 10 */
block|{
block|{
literal|0
block|,
literal|0
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
literal|0
block|}
block|,
comment|/* CAM */
block|{
literal|200
block|,
literal|500
block|,
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|4
block|}
block|,
literal|0
block|}
block|,
comment|/* PS level 1 */
block|{
literal|200
block|,
literal|300
block|,
block|{
literal|2
block|,
literal|4
block|,
literal|6
block|,
literal|7
block|,
literal|7
block|}
block|,
literal|0
block|}
block|,
comment|/* PS level 2 */
block|{
literal|50
block|,
literal|100
block|,
block|{
literal|2
block|,
literal|6
block|,
literal|9
block|,
literal|9
block|,
literal|10
block|}
block|,
literal|0
block|}
block|,
comment|/* PS level 3 */
block|{
literal|50
block|,
literal|25
block|,
block|{
literal|2
block|,
literal|7
block|,
literal|9
block|,
literal|9
block|,
literal|10
block|}
block|,
literal|1
block|}
block|,
comment|/* PS level 4 */
block|{
literal|25
block|,
literal|25
block|,
block|{
literal|4
block|,
literal|7
block|,
literal|10
block|,
literal|10
block|,
literal|10
block|}
block|,
literal|1
block|}
comment|/* PS level 5 */
block|}
block|,
comment|/* DTIM>= 11 */
block|{
block|{
literal|0
block|,
literal|0
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
literal|0
block|}
block|,
comment|/* CAM */
block|{
literal|200
block|,
literal|500
block|,
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
operator|-
literal|1
block|}
block|,
literal|0
block|}
block|,
comment|/* PS level 1 */
block|{
literal|200
block|,
literal|300
block|,
block|{
literal|2
block|,
literal|4
block|,
literal|6
block|,
literal|7
block|,
operator|-
literal|1
block|}
block|,
literal|0
block|}
block|,
comment|/* PS level 2 */
block|{
literal|50
block|,
literal|100
block|,
block|{
literal|2
block|,
literal|6
block|,
literal|9
block|,
literal|9
block|,
operator|-
literal|1
block|}
block|,
literal|0
block|}
block|,
comment|/* PS level 3 */
block|{
literal|50
block|,
literal|25
block|,
block|{
literal|2
block|,
literal|7
block|,
literal|9
block|,
literal|9
block|,
operator|-
literal|1
block|}
block|,
literal|0
block|}
block|,
comment|/* PS level 4 */
block|{
literal|25
block|,
literal|25
block|,
block|{
literal|4
block|,
literal|7
block|,
literal|10
block|,
literal|10
block|,
operator|-
literal|1
block|}
block|,
literal|0
block|}
comment|/* PS level 5 */
block|}
block|}
struct|;
end_struct

begin_comment
comment|/* Firmware errors. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|wpi_fw_errmsg
index|[]
init|=
block|{
literal|"OK"
block|,
literal|"FAIL"
block|,
literal|"BAD_PARAM"
block|,
literal|"BAD_CHECKSUM"
block|,
literal|"NMI_INTERRUPT"
block|,
literal|"SYSASSERT"
block|,
literal|"FATAL_ERROR"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|WPI_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_st, (sc)->sc_sh, (reg))
end_define

begin_define
define|#
directive|define
name|WPI_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|WPI_WRITE_REGION_4
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|datap
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_region_4((sc)->sc_st, (sc)->sc_sh, (offset),	\ 	    (datap), (count))
end_define

begin_define
define|#
directive|define
name|WPI_SETBITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|mask
parameter_list|)
define|\
value|WPI_WRITE(sc, reg, WPI_READ(sc, reg) | (mask))
end_define

begin_define
define|#
directive|define
name|WPI_CLRBITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|mask
parameter_list|)
define|\
value|WPI_WRITE(sc, reg, WPI_READ(sc, reg)& ~(mask))
end_define

begin_define
define|#
directive|define
name|WPI_BARRIER_WRITE
parameter_list|(
name|sc
parameter_list|)
define|\
value|bus_space_barrier((sc)->sc_st, (sc)->sc_sh, 0, (sc)->sc_sz,	\ 	    BUS_SPACE_BARRIER_WRITE)
end_define

begin_define
define|#
directive|define
name|WPI_BARRIER_READ_WRITE
parameter_list|(
name|sc
parameter_list|)
define|\
value|bus_space_barrier((sc)->sc_st, (sc)->sc_sh, 0, (sc)->sc_sz,	\ 	    BUS_SPACE_BARRIER_READ | BUS_SPACE_BARRIER_WRITE)
end_define

end_unit

