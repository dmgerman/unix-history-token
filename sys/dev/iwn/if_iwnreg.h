begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: if_iwnreg.h,v 1.26 2009/05/29 08:25:45 damien Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007, 2008  *	Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|EDCA_NUM_AC
value|4
end_define

begin_define
define|#
directive|define
name|IWN_TX_RING_COUNT
value|256
end_define

begin_define
define|#
directive|define
name|IWN_TX_RING_LOMARK
value|192
end_define

begin_define
define|#
directive|define
name|IWN_TX_RING_HIMARK
value|224
end_define

begin_define
define|#
directive|define
name|IWN_RX_RING_COUNT_LOG
value|6
end_define

begin_define
define|#
directive|define
name|IWN_RX_RING_COUNT
value|(1<< IWN_RX_RING_COUNT_LOG)
end_define

begin_define
define|#
directive|define
name|IWN4965_NTXQUEUES
value|16
end_define

begin_define
define|#
directive|define
name|IWN5000_NTXQUEUES
value|20
end_define

begin_define
define|#
directive|define
name|IWN4965_NDMACHNLS
value|7
end_define

begin_define
define|#
directive|define
name|IWN5000_NDMACHNLS
value|8
end_define

begin_define
define|#
directive|define
name|IWN_SRVC_DMACHNL
value|9
end_define

begin_comment
comment|/* Maximum number of DMA segments for TX. */
end_comment

begin_define
define|#
directive|define
name|IWN_MAX_SCATTER
value|20
end_define

begin_comment
comment|/* RX buffers must be large enough to hold a full 4K A-MPDU. */
end_comment

begin_define
define|#
directive|define
name|IWN_RBUF_SIZE
value|(4 * 1024)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__LP64__
argument_list|)
end_if

begin_comment
comment|/* HW supports 36-bit DMA addresses. */
end_comment

begin_define
define|#
directive|define
name|IWN_LOADDR
parameter_list|(
name|paddr
parameter_list|)
value|((uint32_t)(paddr))
end_define

begin_define
define|#
directive|define
name|IWN_HIADDR
parameter_list|(
name|paddr
parameter_list|)
value|(((paddr)>> 32)& 0xf)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IWN_LOADDR
parameter_list|(
name|paddr
parameter_list|)
value|(paddr)
end_define

begin_define
define|#
directive|define
name|IWN_HIADDR
parameter_list|(
name|paddr
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Base Address Register. */
end_comment

begin_define
define|#
directive|define
name|IWN_PCI_BAR0
value|PCI_MAPREG_START
end_define

begin_comment
comment|/*  * Control and status registers.  */
end_comment

begin_define
define|#
directive|define
name|IWN_HW_IF_CONFIG
value|0x000
end_define

begin_define
define|#
directive|define
name|IWN_INT_COALESCING
value|0x004
end_define

begin_define
define|#
directive|define
name|IWN_INT
value|0x008
end_define

begin_define
define|#
directive|define
name|IWN_MASK
value|0x00c
end_define

begin_define
define|#
directive|define
name|IWN_FH_INT
value|0x010
end_define

begin_define
define|#
directive|define
name|IWN_RESET
value|0x020
end_define

begin_define
define|#
directive|define
name|IWN_GP_CNTRL
value|0x024
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV
value|0x028
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM
value|0x02c
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_GP
value|0x030
end_define

begin_define
define|#
directive|define
name|IWN_OTP_GP
value|0x034
end_define

begin_define
define|#
directive|define
name|IWN_GIO
value|0x03c
end_define

begin_define
define|#
directive|define
name|IWN_UCODE_GP1_CLR
value|0x05c
end_define

begin_define
define|#
directive|define
name|IWN_LED
value|0x094
end_define

begin_define
define|#
directive|define
name|IWN_GIO_CHICKEN
value|0x100
end_define

begin_define
define|#
directive|define
name|IWN_ANA_PLL
value|0x20c
end_define

begin_define
define|#
directive|define
name|IWN_DBG_HPET_MEM
value|0x240
end_define

begin_define
define|#
directive|define
name|IWN_MEM_RADDR
value|0x40c
end_define

begin_define
define|#
directive|define
name|IWN_MEM_WADDR
value|0x410
end_define

begin_define
define|#
directive|define
name|IWN_MEM_WDATA
value|0x418
end_define

begin_define
define|#
directive|define
name|IWN_MEM_RDATA
value|0x41c
end_define

begin_define
define|#
directive|define
name|IWN_PRPH_WADDR
value|0x444
end_define

begin_define
define|#
directive|define
name|IWN_PRPH_RADDR
value|0x448
end_define

begin_define
define|#
directive|define
name|IWN_PRPH_WDATA
value|0x44c
end_define

begin_define
define|#
directive|define
name|IWN_PRPH_RDATA
value|0x450
end_define

begin_define
define|#
directive|define
name|IWN_HBUS_TARG_WRPTR
value|0x460
end_define

begin_comment
comment|/*  * Flow-Handler registers.  */
end_comment

begin_define
define|#
directive|define
name|IWN_FH_TFBD_CTRL0
parameter_list|(
name|qid
parameter_list|)
value|(0x1900 + (qid) * 8)
end_define

begin_define
define|#
directive|define
name|IWN_FH_TFBD_CTRL1
parameter_list|(
name|qid
parameter_list|)
value|(0x1904 + (qid) * 8)
end_define

begin_define
define|#
directive|define
name|IWN_FH_KW_ADDR
value|0x197c
end_define

begin_define
define|#
directive|define
name|IWN_FH_SRAM_ADDR
parameter_list|(
name|qid
parameter_list|)
value|(0x19a4 + (qid) * 4)
end_define

begin_define
define|#
directive|define
name|IWN_FH_CBBC_QUEUE
parameter_list|(
name|qid
parameter_list|)
value|(0x19d0 + (qid) * 4)
end_define

begin_define
define|#
directive|define
name|IWN_FH_STATUS_WPTR
value|0x1bc0
end_define

begin_define
define|#
directive|define
name|IWN_FH_RX_BASE
value|0x1bc4
end_define

begin_define
define|#
directive|define
name|IWN_FH_RX_WPTR
value|0x1bc8
end_define

begin_define
define|#
directive|define
name|IWN_FH_RX_CONFIG
value|0x1c00
end_define

begin_define
define|#
directive|define
name|IWN_FH_RX_STATUS
value|0x1c44
end_define

begin_define
define|#
directive|define
name|IWN_FH_TX_CONFIG
parameter_list|(
name|qid
parameter_list|)
value|(0x1d00 + (qid) * 32)
end_define

begin_define
define|#
directive|define
name|IWN_FH_TXBUF_STATUS
parameter_list|(
name|qid
parameter_list|)
value|(0x1d08 + (qid) * 32)
end_define

begin_define
define|#
directive|define
name|IWN_FH_TX_CHICKEN
value|0x1e98
end_define

begin_define
define|#
directive|define
name|IWN_FH_TX_STATUS
value|0x1eb0
end_define

begin_comment
comment|/*  * TX scheduler registers.  */
end_comment

begin_define
define|#
directive|define
name|IWN_SCHED_BASE
value|0xa02c00
end_define

begin_define
define|#
directive|define
name|IWN_SCHED_SRAM_ADDR
value|(IWN_SCHED_BASE + 0x000)
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_DRAM_ADDR
value|(IWN_SCHED_BASE + 0x008)
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHED_DRAM_ADDR
value|(IWN_SCHED_BASE + 0x010)
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_TXFACT
value|(IWN_SCHED_BASE + 0x010)
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHED_TXFACT
value|(IWN_SCHED_BASE + 0x01c)
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHED_QUEUE_RDPTR
parameter_list|(
name|qid
parameter_list|)
value|(IWN_SCHED_BASE + 0x064 + (qid) * 4)
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_QUEUE_RDPTR
parameter_list|(
name|qid
parameter_list|)
value|(IWN_SCHED_BASE + 0x068 + (qid) * 4)
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHED_QCHAIN_SEL
value|(IWN_SCHED_BASE + 0x0d0)
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHED_INTR_MASK
value|(IWN_SCHED_BASE + 0x0e4)
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_QCHAIN_SEL
value|(IWN_SCHED_BASE + 0x0e8)
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHED_QUEUE_STATUS
parameter_list|(
name|qid
parameter_list|)
value|(IWN_SCHED_BASE + 0x104 + (qid) * 4)
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_INTR_MASK
value|(IWN_SCHED_BASE + 0x108)
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_QUEUE_STATUS
parameter_list|(
name|qid
parameter_list|)
value|(IWN_SCHED_BASE + 0x10c + (qid) * 4)
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_AGGR_SEL
value|(IWN_SCHED_BASE + 0x248)
end_define

begin_comment
comment|/*  * Offsets in TX scheduler's SRAM.  */
end_comment

begin_define
define|#
directive|define
name|IWN4965_SCHED_CTX_OFF
value|0x380
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHED_CTX_LEN
value|416
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHED_QUEUE_OFFSET
parameter_list|(
name|qid
parameter_list|)
value|(0x380 + (qid) * 8)
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHED_TRANS_TBL
parameter_list|(
name|qid
parameter_list|)
value|(0x500 + (qid) * 2)
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_CTX_OFF
value|0x600
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_CTX_LEN
value|520
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_QUEUE_OFFSET
parameter_list|(
name|qid
parameter_list|)
value|(0x600 + (qid) * 8)
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_TRANS_TBL
parameter_list|(
name|qid
parameter_list|)
value|(0x7e0 + (qid) * 2)
end_define

begin_comment
comment|/*  * NIC internal memory offsets.  */
end_comment

begin_define
define|#
directive|define
name|IWN_CLOCK_CTL
value|0x3000
end_define

begin_define
define|#
directive|define
name|IWN_APMG_CLK_CTRL
value|0x3004
end_define

begin_define
define|#
directive|define
name|IWN_APMG_CLK_DIS
value|0x3008
end_define

begin_define
define|#
directive|define
name|IWN_APMG_PS
value|0x300c
end_define

begin_define
define|#
directive|define
name|IWN_APMG_PCI_STT
value|0x3010
end_define

begin_define
define|#
directive|define
name|IWN_BSM_WR_CTRL
value|0x3400
end_define

begin_define
define|#
directive|define
name|IWN_BSM_WR_MEM_SRC
value|0x3404
end_define

begin_define
define|#
directive|define
name|IWN_BSM_WR_MEM_DST
value|0x3408
end_define

begin_define
define|#
directive|define
name|IWN_BSM_WR_DWCOUNT
value|0x340c
end_define

begin_define
define|#
directive|define
name|IWN_BSM_DRAM_TEXT_ADDR
value|0x3490
end_define

begin_define
define|#
directive|define
name|IWN_BSM_DRAM_TEXT_SIZE
value|0x3494
end_define

begin_define
define|#
directive|define
name|IWN_BSM_DRAM_DATA_ADDR
value|0x3498
end_define

begin_define
define|#
directive|define
name|IWN_BSM_DRAM_DATA_SIZE
value|0x349c
end_define

begin_define
define|#
directive|define
name|IWN_BSM_SRAM_BASE
value|0x3800
end_define

begin_comment
comment|/* Possible values for IWN_APMG_CLK_DIS. */
end_comment

begin_define
define|#
directive|define
name|IWN_APMG_CLK_DMA_RQT
value|(1<< 9)
end_define

begin_comment
comment|/* Possible flags for register IWN_HW_IF_CONFIG. */
end_comment

begin_define
define|#
directive|define
name|IWN_HW_IF_CONFIG_4965_R
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|IWN_HW_IF_CONFIG_MAC_SI
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|IWN_HW_IF_CONFIG_RADIO_SI
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|IWN_HW_IF_CONFIG_EEPROM_LOCKED
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|IWN_HW_IF_CONFIG_NIC_READY
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|IWN_HW_IF_CONFIG_HAP_WAKE_L1A
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|IWN_HW_IF_CONFIG_PREPARE_DONE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|IWN_HW_IF_CONFIG_PREPARE
value|(1<< 27)
end_define

begin_comment
comment|/* Possible flags for registers IWN_PRPH_RADDR/IWN_PRPH_WADDR. */
end_comment

begin_define
define|#
directive|define
name|IWN_PRPH_DWORD
value|((sizeof (uint32_t) - 1)<< 24)
end_define

begin_comment
comment|/* Possible values for IWN_BSM_WR_MEM_DST. */
end_comment

begin_define
define|#
directive|define
name|IWN_FW_TEXT_BASE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IWN_FW_DATA_BASE
value|0x00800000
end_define

begin_comment
comment|/* Possible flags for register IWN_RESET. */
end_comment

begin_define
define|#
directive|define
name|IWN_RESET_NEVO
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWN_RESET_SW
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IWN_RESET_MASTER_DISABLED
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IWN_RESET_STOP_MASTER
value|(1<< 9)
end_define

begin_comment
comment|/* Possible flags for register IWN_GP_CNTRL. */
end_comment

begin_define
define|#
directive|define
name|IWN_GP_CNTRL_MAC_ACCESS_ENA
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWN_GP_CNTRL_MAC_CLOCK_READY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWN_GP_CNTRL_INIT_DONE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IWN_GP_CNTRL_MAC_ACCESS_REQ
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IWN_GP_CNTRL_SLEEP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IWN_GP_CNTRL_RFKILL
value|(1<< 27)
end_define

begin_comment
comment|/* Possible flags for register IWN_HW_REV. */
end_comment

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_4965
value|0
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_5300
value|2
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_5350
value|3
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_5150
value|4
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_5100
value|5
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_1000
value|6
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_6000
value|7
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_6050
value|8
end_define

begin_comment
comment|/* Possible flags for register IWN_GIO_CHICKEN. */
end_comment

begin_define
define|#
directive|define
name|IWN_GIO_CHICKEN_L1A_NO_L0S_RX
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|IWN_GIO_CHICKEN_DIS_L0S_TIMER
value|(1<< 29)
end_define

begin_comment
comment|/* Possible flags for register IWN_GIO. */
end_comment

begin_define
define|#
directive|define
name|IWN_GIO_L0S_ENA
value|(1<< 1)
end_define

begin_comment
comment|/* Possible flags for register IWN_UCODE_GP1_CLR. */
end_comment

begin_define
define|#
directive|define
name|IWN_UCODE_GP1_RFKILL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IWN_UCODE_GP1_CMD_BLOCKED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IWN_UCODE_GP1_CTEMP_STOP_RF
value|(1<< 3)
end_define

begin_comment
comment|/* Possible flags/values for register IWN_LED. */
end_comment

begin_define
define|#
directive|define
name|IWN_LED_BSM_CTRL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IWN_LED_OFF
value|0x00000038
end_define

begin_define
define|#
directive|define
name|IWN_LED_ON
value|0x00000078
end_define

begin_comment
comment|/* Possible values for register IWN_ANA_PLL. */
end_comment

begin_define
define|#
directive|define
name|IWN_ANA_PLL_INIT
value|0x00880300
end_define

begin_comment
comment|/* Possible flags for register IWN_FH_RX_STATUS. */
end_comment

begin_define
define|#
directive|define
name|IWN_FH_RX_STATUS_IDLE
value|(1<< 24)
end_define

begin_comment
comment|/* Possible flags for register IWN_BSM_WR_CTRL. */
end_comment

begin_define
define|#
directive|define
name|IWN_BSM_WR_CTRL_START_EN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|IWN_BSM_WR_CTRL_START
value|(1<< 31)
end_define

begin_comment
comment|/* Possible flags for register IWN_INT. */
end_comment

begin_define
define|#
directive|define
name|IWN_INT_ALIVE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|IWN_INT_WAKEUP
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|IWN_INT_SW_RX
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|IWN_INT_CT_REACHED
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|IWN_INT_RF_TOGGLED
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|IWN_INT_SW_ERR
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|IWN_INT_FH_TX
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|IWN_INT_HW_ERR
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|IWN_INT_FH_RX
value|(1<< 31)
end_define

begin_comment
comment|/* Shortcut. */
end_comment

begin_define
define|#
directive|define
name|IWN_INT_MASK
define|\
value|(IWN_INT_SW_ERR | IWN_INT_HW_ERR | IWN_INT_FH_TX |		\ 	 IWN_INT_FH_RX | IWN_INT_ALIVE | IWN_INT_WAKEUP |		\ 	 IWN_INT_SW_RX | IWN_INT_CT_REACHED | IWN_INT_RF_TOGGLED)
end_define

begin_comment
comment|/* Possible flags for register IWN_FH_INT. */
end_comment

begin_define
define|#
directive|define
name|IWN_FH_INT_TX_CHNL
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_define
define|#
directive|define
name|IWN_FH_INT_RX_CHNL
parameter_list|(
name|x
parameter_list|)
value|(1<< ((x) + 16))
end_define

begin_define
define|#
directive|define
name|IWN_FH_INT_HI_PRIOR
value|(1<< 30)
end_define

begin_comment
comment|/* Shortcuts for the above. */
end_comment

begin_define
define|#
directive|define
name|IWN_FH_INT_TX
define|\
value|(IWN_FH_INT_TX_CHNL(0) | IWN_FH_INT_TX_CHNL(1))
end_define

begin_define
define|#
directive|define
name|IWN_FH_INT_RX
define|\
value|(IWN_FH_INT_RX_CHNL(0) | IWN_FH_INT_RX_CHNL(1) | IWN_FH_INT_HI_PRIOR)
end_define

begin_comment
comment|/* Possible flags/values for register IWN_FH_TX_CONFIG. */
end_comment

begin_define
define|#
directive|define
name|IWN_FH_TX_CONFIG_DMA_PAUSE
value|0
end_define

begin_define
define|#
directive|define
name|IWN_FH_TX_CONFIG_DMA_ENA
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|IWN_FH_TX_CONFIG_CIRQ_HOST_ENDTFD
value|(1<< 20)
end_define

begin_comment
comment|/* Possible flags/values for register IWN_FH_TXBUF_STATUS. */
end_comment

begin_define
define|#
directive|define
name|IWN_FH_TXBUF_STATUS_TBNUM
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|IWN_FH_TXBUF_STATUS_TBIDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|IWN_FH_TXBUF_STATUS_TFBD_VALID
value|3
end_define

begin_comment
comment|/* Possible flags for register IWN_FH_TX_CHICKEN. */
end_comment

begin_define
define|#
directive|define
name|IWN_FH_TX_CHICKEN_SCHED_RETRY
value|(1<< 1)
end_define

begin_comment
comment|/* Possible flags for register IWN_FH_TX_STATUS. */
end_comment

begin_define
define|#
directive|define
name|IWN_FH_TX_STATUS_IDLE
parameter_list|(
name|chnl
parameter_list|)
define|\
value|(1<< ((chnl) + 24) | 1<< ((chnl) + 16))
end_define

begin_comment
comment|/* Possible flags for register IWN_FH_RX_CONFIG. */
end_comment

begin_define
define|#
directive|define
name|IWN_FH_RX_CONFIG_ENA
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|IWN_FH_RX_CONFIG_NRBD
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|IWN_FH_RX_CONFIG_RB_SIZE_8K
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IWN_FH_RX_CONFIG_SINGLE_FRAME
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|IWN_FH_RX_CONFIG_IRQ_DST_HOST
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IWN_FH_RX_CONFIG_RB_TIMEOUT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|IWN_FH_RX_CONFIG_IGN_RXF_EMPTY
value|(1<<  2)
end_define

begin_comment
comment|/* Possible flags for register IWN_FH_TX_CONFIG. */
end_comment

begin_define
define|#
directive|define
name|IWN_FH_TX_CONFIG_DMA_ENA
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|IWN_FH_TX_CONFIG_DMA_CREDIT_ENA
value|(1<<  3)
end_define

begin_comment
comment|/* Possible flags for register IWN_EEPROM. */
end_comment

begin_define
define|#
directive|define
name|IWN_EEPROM_READ_VALID
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_CMD
value|(1<< 1)
end_define

begin_comment
comment|/* Possible flags for register IWN_EEPROM_GP. */
end_comment

begin_define
define|#
directive|define
name|IWN_EEPROM_GP_IF_OWNER
value|0x00000180
end_define

begin_comment
comment|/* Possible flags for register IWN_OTP_GP. */
end_comment

begin_define
define|#
directive|define
name|IWN_OTP_GP_DEV_SEL_OTP
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IWN_OTP_GP_RELATIVE_ACCESS
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|IWN_OTP_GP_ECC_CORR_STTS
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|IWN_OTP_GP_ECC_UNCORR_STTS
value|(1<< 21)
end_define

begin_comment
comment|/* Possible flags for register IWN_SCHED_QUEUE_STATUS. */
end_comment

begin_define
define|#
directive|define
name|IWN4965_TXQ_STATUS_ACTIVE
value|0x0007fc01
end_define

begin_define
define|#
directive|define
name|IWN4965_TXQ_STATUS_INACTIVE
value|0x0007fc00
end_define

begin_define
define|#
directive|define
name|IWN4965_TXQ_STATUS_AGGR_ENA
value|(1<< 5 | 1<< 8)
end_define

begin_define
define|#
directive|define
name|IWN4965_TXQ_STATUS_CHGACT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IWN5000_TXQ_STATUS_ACTIVE
value|0x00ff0018
end_define

begin_define
define|#
directive|define
name|IWN5000_TXQ_STATUS_INACTIVE
value|0x00ff0010
end_define

begin_define
define|#
directive|define
name|IWN5000_TXQ_STATUS_CHGACT
value|(1<< 19)
end_define

begin_comment
comment|/* Possible flags for register IWN_APMG_CLK_CTRL. */
end_comment

begin_define
define|#
directive|define
name|IWN_APMG_CLK_CTRL_DMA_CLK_RQT
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|IWN_APMG_CLK_CTRL_BSM_CLK_RQT
value|(1<< 11)
end_define

begin_comment
comment|/* Possible flags for register IWN_APMG_PS. */
end_comment

begin_define
define|#
directive|define
name|IWN_APMG_PS_EARLY_PWROFF_DIS
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|IWN_APMG_PS_PWR_SRC
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|IWN_APMG_PS_PWR_SRC_VMAIN
value|0
end_define

begin_define
define|#
directive|define
name|IWN_APMG_PS_PWR_SRC_VAUX
value|2
end_define

begin_define
define|#
directive|define
name|IWN_APMG_PS_PWR_SRC_MASK
value|IWN_APMG_PS_PWR_SRC(3)
end_define

begin_define
define|#
directive|define
name|IWN_APMG_PS_RESET_REQ
value|(1<< 26)
end_define

begin_comment
comment|/* Possible flags for IWN_APMG_PCI_STT. */
end_comment

begin_define
define|#
directive|define
name|IWN_APMG_PCI_STT_L1A_DIS
value|(1<< 11)
end_define

begin_comment
comment|/* Possible flags for register IWN_BSM_DRAM_TEXT_SIZE. */
end_comment

begin_define
define|#
directive|define
name|IWN_FW_UPDATED
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|IWN_SCHED_WINSZ
value|64
end_define

begin_define
define|#
directive|define
name|IWN_SCHED_LIMIT
value|64
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHED_COUNT
value|512
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHED_COUNT
value|(IWN_TX_RING_COUNT + IWN_SCHED_WINSZ)
end_define

begin_define
define|#
directive|define
name|IWN4965_SCHEDSZ
value|(IWN4965_NTXQUEUES * IWN4965_SCHED_COUNT * 2)
end_define

begin_define
define|#
directive|define
name|IWN5000_SCHEDSZ
value|(IWN5000_NTXQUEUES * IWN5000_SCHED_COUNT * 2)
end_define

begin_struct
struct|struct
name|iwn_tx_desc
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
struct|struct
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
block|}
name|__packed
name|segs
index|[
name|IWN_MAX_SCATTER
index|]
struct|;
comment|/* Pad to 128 bytes. */
name|uint32_t
name|reserved2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_rx_status
block|{
name|uint16_t
name|closed_count
decl_stmt|;
name|uint16_t
name|closed_rx_count
decl_stmt|;
name|uint16_t
name|finished_count
decl_stmt|;
name|uint16_t
name|finished_rx_count
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

begin_struct
struct|struct
name|iwn_rx_desc
block|{
name|uint32_t
name|len
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|IWN_UC_READY
value|1
define|#
directive|define
name|IWN_ADD_NODE_DONE
value|24
define|#
directive|define
name|IWN_TX_DONE
value|28
define|#
directive|define
name|IWN5000_CALIBRATION_RESULT
value|102
define|#
directive|define
name|IWN5000_CALIBRATION_DONE
value|103
define|#
directive|define
name|IWN_START_SCAN
value|130
define|#
directive|define
name|IWN_STOP_SCAN
value|132
define|#
directive|define
name|IWN_RX_STATISTICS
value|156
define|#
directive|define
name|IWN_BEACON_STATISTICS
value|157
define|#
directive|define
name|IWN_STATE_CHANGED
value|161
define|#
directive|define
name|IWN_BEACON_MISSED
value|162
define|#
directive|define
name|IWN_RX_PHY
value|192
define|#
directive|define
name|IWN_MPDU_RX_DONE
value|193
define|#
directive|define
name|IWN_RX_DONE
value|195
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

begin_comment
comment|/* Possible RX status flags. */
end_comment

begin_define
define|#
directive|define
name|IWN_RX_NO_CRC_ERR
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|IWN_RX_NO_OVFL_ERR
value|(1<<  1)
end_define

begin_comment
comment|/* Shortcut for the above. */
end_comment

begin_define
define|#
directive|define
name|IWN_RX_NOERROR
value|(IWN_RX_NO_CRC_ERR | IWN_RX_NO_OVFL_ERR)
end_define

begin_define
define|#
directive|define
name|IWN_RX_MPDU_MIC_OK
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|IWN_RX_CIPHER_MASK
value|(7<<  8)
end_define

begin_define
define|#
directive|define
name|IWN_RX_CIPHER_CCMP
value|(2<<  8)
end_define

begin_define
define|#
directive|define
name|IWN_RX_MPDU_DEC
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IWN_RX_DECRYPT_MASK
value|(3<< 11)
end_define

begin_define
define|#
directive|define
name|IWN_RX_DECRYPT_OK
value|(3<< 11)
end_define

begin_struct
struct|struct
name|iwn_tx_cmd
block|{
name|uint8_t
name|code
decl_stmt|;
define|#
directive|define
name|IWN_CMD_CONFIGURE
value|16
define|#
directive|define
name|IWN_CMD_ASSOCIATE
value|17
define|#
directive|define
name|IWN_CMD_EDCA_PARAMS
value|19
define|#
directive|define
name|IWN_CMD_TIMING
value|20
define|#
directive|define
name|IWN_CMD_ADD_NODE
value|24
define|#
directive|define
name|IWN_CMD_TX_DATA
value|28
define|#
directive|define
name|IWN_CMD_LINK_QUALITY
value|78
define|#
directive|define
name|IWN_CMD_SET_LED
value|72
define|#
directive|define
name|IWN5000_CMD_WIMAX_COEX
value|90
define|#
directive|define
name|IWN5000_CMD_CALIB_CONFIG
value|101
define|#
directive|define
name|IWN_CMD_SET_POWER_MODE
value|119
define|#
directive|define
name|IWN_CMD_SCAN
value|128
define|#
directive|define
name|IWN_CMD_TXPOWER
value|151
define|#
directive|define
name|IWN_CMD_TXPOWER_DBM
value|152
define|#
directive|define
name|IWN_CMD_BT_COEX
value|155
define|#
directive|define
name|IWN_CMD_GET_STATISTICS
value|156
define|#
directive|define
name|IWN_CMD_SET_CRITICAL_TEMP
value|164
define|#
directive|define
name|IWN_CMD_SET_SENSITIVITY
value|168
define|#
directive|define
name|IWN_CMD_PHY_CALIB
value|176
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
literal|136
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Antenna flags, used in various commands. */
end_comment

begin_define
define|#
directive|define
name|IWN_ANT_A
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWN_ANT_B
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IWN_ANT_C
value|(1<< 2)
end_define

begin_comment
comment|/* Shortcut. */
end_comment

begin_define
define|#
directive|define
name|IWN_ANT_ABC
value|(IWN_ANT_A | IWN_ANT_B | IWN_ANT_C)
end_define

begin_comment
comment|/* Structure for command IWN_CMD_CONFIGURE. */
end_comment

begin_struct
struct|struct
name|iwn_rxon
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
name|IWN_MODE_HOSTAP
value|1
define|#
directive|define
name|IWN_MODE_STA
value|3
define|#
directive|define
name|IWN_MODE_IBSS
value|4
define|#
directive|define
name|IWN_MODE_MONITOR
value|6
name|uint8_t
name|air
decl_stmt|;
name|uint16_t
name|rxchain
decl_stmt|;
define|#
directive|define
name|IWN_RXCHAIN_FORCE
value|(1<< 0)
define|#
directive|define
name|IWN_RXCHAIN_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<<  1)
define|#
directive|define
name|IWN_RXCHAIN_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<<  4)
define|#
directive|define
name|IWN_RXCHAIN_MIMO
parameter_list|(
name|x
parameter_list|)
value|((x)<<  7)
define|#
directive|define
name|IWN_RXCHAIN_IDLE_COUNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
define|#
directive|define
name|IWN_RXCHAIN_MIMO_COUNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
define|#
directive|define
name|IWN_RXCHAIN_MIMO_FORCE
value|(1<< 14)
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
name|IWN_RXON_24GHZ
value|0x00000001
comment|/* band */
define|#
directive|define
name|IWN_RXON_CCK
value|0x00000002
comment|/* modulation */
define|#
directive|define
name|IWN_RXON_AUTO
value|0x00000004
comment|/* 2.4-only auto-detect */
define|#
directive|define
name|IWN_RXON_HTPROT
value|0x00000008
comment|/* xmit with HT protection */
define|#
directive|define
name|IWN_RXON_SHSLOT
value|0x00000010
comment|/* short slot time */
define|#
directive|define
name|IWN_RXON_SHPREAMBLE
value|0x00000020
comment|/* short premable */
define|#
directive|define
name|IWN_RXON_NODIVERSITY
value|0x00000080
comment|/* disable antenna diversity */
define|#
directive|define
name|IWN_RXON_ANTENNA_A
value|0x00000100
define|#
directive|define
name|IWN_RXON_ANTENNA_B
value|0x00000200
define|#
directive|define
name|IWN_RXON_RADAR
value|0x00001000
comment|/* enable radar detect */
define|#
directive|define
name|IWN_RXON_NARROW
value|0x00002000
comment|/* MKK narrow band select */
define|#
directive|define
name|IWN_RXON_TSF
value|0x00008000
define|#
directive|define
name|IWN_RXON_HT
value|0x06400000
define|#
directive|define
name|IWN_RXON_HT20
value|0x02000000
define|#
directive|define
name|IWN_RXON_HT40U
value|0x04000000
define|#
directive|define
name|IWN_RXON_HT40D
value|0x04400000
define|#
directive|define
name|IWN_RXON_CTS_TO_SELF
value|0x40000000
name|uint32_t
name|filter
decl_stmt|;
define|#
directive|define
name|IWN_FILTER_PROMISC
value|(1<< 0)
define|#
directive|define
name|IWN_FILTER_CTL
value|(1<< 1)
define|#
directive|define
name|IWN_FILTER_MULTICAST
value|(1<< 2)
define|#
directive|define
name|IWN_FILTER_NODECRYPT
value|(1<< 3)
define|#
directive|define
name|IWN_FILTER_BSS
value|(1<< 5)
define|#
directive|define
name|IWN_FILTER_BEACON
value|(1<< 6)
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|reserved4
decl_stmt|;
name|uint8_t
name|ht_single_mask
decl_stmt|;
name|uint8_t
name|ht_dual_mask
decl_stmt|;
comment|/* The following fields are for 5000 Series only. */
name|uint8_t
name|ht_triple_mask
decl_stmt|;
name|uint8_t
name|reserved5
decl_stmt|;
name|uint16_t
name|acquisition
decl_stmt|;
name|uint16_t
name|reserved6
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN4965_RXONSZ
value|(sizeof (struct iwn_rxon) - 6)
end_define

begin_define
define|#
directive|define
name|IWN5000_RXONSZ
value|(sizeof (struct iwn_rxon))
end_define

begin_comment
comment|/* Structure for command IWN_CMD_ASSOCIATE. */
end_comment

begin_struct
struct|struct
name|iwn_assoc
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
comment|/* Structure for command IWN_CMD_EDCA_PARAMS. */
end_comment

begin_struct
struct|struct
name|iwn_edca_params
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_EDCA_UPDATE
value|(1<< 0)
define|#
directive|define
name|IWN_EDCA_TXOP
value|(1<< 4)
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
name|EDCA_NUM_AC
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command IWN_CMD_TIMING. */
end_comment

begin_struct
struct|struct
name|iwn_cmd_timing
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
comment|/* Structure for command IWN_CMD_ADD_NODE. */
end_comment

begin_struct
struct|struct
name|iwn_node_info
block|{
name|uint8_t
name|control
decl_stmt|;
define|#
directive|define
name|IWN_NODE_UPDATE
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
name|IWN_ID_BSS
value|0
define|#
directive|define
name|IWN5000_ID_BROADCAST
value|15
define|#
directive|define
name|IWN4965_ID_BROADCAST
value|31
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_FLAG_SET_KEY
value|(1<< 0)
define|#
directive|define
name|IWN_FLAG_SET_DISABLE_TID
value|(1<< 1)
define|#
directive|define
name|IWN_FLAG_SET_TXRATE
value|(1<< 2)
define|#
directive|define
name|IWN_FLAG_SET_ADDBA
value|(1<< 3)
define|#
directive|define
name|IWN_FLAG_SET_DELBA
value|(1<< 4)
name|uint16_t
name|reserved3
decl_stmt|;
name|uint16_t
name|kflags
decl_stmt|;
define|#
directive|define
name|IWN_KFLAG_CCMP
value|(1<<  1)
define|#
directive|define
name|IWN_KFLAG_MAP
value|(1<<  3)
define|#
directive|define
name|IWN_KFLAG_KID
parameter_list|(
name|kid
parameter_list|)
value|((kid)<< 8)
define|#
directive|define
name|IWN_KFLAG_INVALID
value|(1<< 11)
define|#
directive|define
name|IWN_KFLAG_GROUP
value|(1<< 14)
name|uint8_t
name|tsc2
decl_stmt|;
comment|/* TKIP TSC2 */
name|uint8_t
name|reserved4
decl_stmt|;
name|uint16_t
name|ttak
index|[
literal|5
index|]
decl_stmt|;
name|uint8_t
name|kid
decl_stmt|;
name|uint8_t
name|reserved5
decl_stmt|;
name|uint8_t
name|key
index|[
literal|16
index|]
decl_stmt|;
comment|/* The following 3 fields are for 5000 Series only. */
name|uint64_t
name|tsc
decl_stmt|;
name|uint8_t
name|rxmic
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|txmic
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|htflags
decl_stmt|;
define|#
directive|define
name|IWN_AMDPU_SIZE_FACTOR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 19)
define|#
directive|define
name|IWN_AMDPU_DENSITY
parameter_list|(
name|x
parameter_list|)
value|((x)<< 23)
name|uint32_t
name|mask
decl_stmt|;
name|uint16_t
name|disable_tid
decl_stmt|;
name|uint16_t
name|reserved6
decl_stmt|;
name|uint8_t
name|addba_tid
decl_stmt|;
name|uint8_t
name|delba_tid
decl_stmt|;
name|uint16_t
name|addba_ssn
decl_stmt|;
name|uint32_t
name|reserved7
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn4965_node_info
block|{
name|uint8_t
name|control
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
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint16_t
name|reserved3
decl_stmt|;
name|uint16_t
name|kflags
decl_stmt|;
name|uint8_t
name|tsc2
decl_stmt|;
comment|/* TKIP TSC2 */
name|uint8_t
name|reserved4
decl_stmt|;
name|uint16_t
name|ttak
index|[
literal|5
index|]
decl_stmt|;
name|uint8_t
name|kid
decl_stmt|;
name|uint8_t
name|reserved5
decl_stmt|;
name|uint8_t
name|key
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|htflags
decl_stmt|;
name|uint32_t
name|mask
decl_stmt|;
name|uint16_t
name|disable_tid
decl_stmt|;
name|uint16_t
name|reserved6
decl_stmt|;
name|uint8_t
name|addba_tid
decl_stmt|;
name|uint8_t
name|delba_tid
decl_stmt|;
name|uint16_t
name|addba_ssn
decl_stmt|;
name|uint32_t
name|reserved7
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN_RFLAG_HT
value|(1<< 0)
end_define

begin_comment
comment|/* use HT modulation */
end_comment

begin_define
define|#
directive|define
name|IWN_RFLAG_CCK
value|(1<< 1)
end_define

begin_comment
comment|/* use CCK modulation */
end_comment

begin_define
define|#
directive|define
name|IWN_RFLAG_HT40
value|(1<< 3)
end_define

begin_comment
comment|/* use dual-stream */
end_comment

begin_define
define|#
directive|define
name|IWN_RFLAG_SGI
value|(1<< 5)
end_define

begin_comment
comment|/* use short GI */
end_comment

begin_define
define|#
directive|define
name|IWN_RFLAG_ANT_A
value|(1<< 6)
end_define

begin_comment
comment|/* start on antenna port A */
end_comment

begin_define
define|#
directive|define
name|IWN_RFLAG_ANT_B
value|(1<< 7)
end_define

begin_comment
comment|/* start on antenna port B */
end_comment

begin_define
define|#
directive|define
name|IWN_RFLAG_ANT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_comment
comment|/* Structure for command IWN_CMD_TX_DATA. */
end_comment

begin_struct
struct|struct
name|iwn_cmd_data
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
name|IWN_TX_NEED_PROTECTION
value|(1<<  0)
comment|/* 5000 only */
define|#
directive|define
name|IWN_TX_NEED_RTS
value|(1<<  1)
define|#
directive|define
name|IWN_TX_NEED_CTS
value|(1<<  2)
define|#
directive|define
name|IWN_TX_NEED_ACK
value|(1<<  3)
define|#
directive|define
name|IWN_TX_LINKQ
value|(1<<  4)
define|#
directive|define
name|IWN_TX_IMM_BA
value|(1<<  6)
define|#
directive|define
name|IWN_TX_FULL_TXOP
value|(1<<  7)
define|#
directive|define
name|IWN_TX_BT_DISABLE
value|(1<< 12)
comment|/* bluetooth coexistence */
define|#
directive|define
name|IWN_TX_AUTO_SEQ
value|(1<< 13)
define|#
directive|define
name|IWN_TX_MORE_FRAG
value|(1<< 14)
define|#
directive|define
name|IWN_TX_INSERT_TSTAMP
value|(1<< 16)
define|#
directive|define
name|IWN_TX_NEED_PADDING
value|(1<< 20)
name|uint32_t
name|scratch
decl_stmt|;
name|uint8_t
name|plcp
decl_stmt|;
name|uint8_t
name|rflags
decl_stmt|;
name|uint16_t
name|xrflags
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|security
decl_stmt|;
define|#
directive|define
name|IWN_CIPHER_WEP40
value|1
define|#
directive|define
name|IWN_CIPHER_CCMP
value|2
define|#
directive|define
name|IWN_CIPHER_TKIP
value|3
define|#
directive|define
name|IWN_CIPHER_WEP104
value|9
name|uint8_t
name|linkq
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint8_t
name|key
index|[
literal|16
index|]
decl_stmt|;
name|uint16_t
name|fnext
decl_stmt|;
name|uint16_t
name|reserved3
decl_stmt|;
name|uint32_t
name|lifetime
decl_stmt|;
define|#
directive|define
name|IWN_LIFETIME_INFINITE
value|0xffffffff
name|uint32_t
name|loaddr
decl_stmt|;
name|uint8_t
name|hiaddr
decl_stmt|;
name|uint8_t
name|rts_ntries
decl_stmt|;
name|uint8_t
name|data_ntries
decl_stmt|;
name|uint8_t
name|tid
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
comment|/* Structure for command IWN_CMD_LINK_QUALITY. */
end_comment

begin_define
define|#
directive|define
name|IWN_MAX_TX_RETRIES
value|16
end_define

begin_struct
struct|struct
name|iwn_cmd_link_quality
block|{
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint16_t
name|ctl
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|mimo
decl_stmt|;
name|uint8_t
name|antmsk_1stream
decl_stmt|;
name|uint8_t
name|antmsk_2stream
decl_stmt|;
name|uint8_t
name|ridx
index|[
name|EDCA_NUM_AC
index|]
decl_stmt|;
name|uint16_t
name|ampdu_limit
decl_stmt|;
name|uint8_t
name|ampdu_threshold
decl_stmt|;
name|uint8_t
name|ampdu_max
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|plcp
decl_stmt|;
name|uint8_t
name|rflags
decl_stmt|;
name|uint16_t
name|xrflags
decl_stmt|;
block|}
name|__packed
name|retry
index|[
name|IWN_MAX_TX_RETRIES
index|]
struct|;
name|uint32_t
name|reserved3
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command IWN_CMD_SET_LED. */
end_comment

begin_struct
struct|struct
name|iwn_cmd_led
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
name|IWN_LED_ACTIVITY
value|1
define|#
directive|define
name|IWN_LED_LINK
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
comment|/* Structure for command IWN5000_CMD_WIMAX_COEX. */
end_comment

begin_struct
struct|struct
name|iwn5000_wimax_coex
block|{
name|uint32_t
name|flags
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|request
decl_stmt|;
name|uint8_t
name|window
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
block|}
name|__packed
name|events
index|[
literal|16
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structures for command IWN5000_CMD_CALIB_CONFIG. */
end_comment

begin_struct
struct|struct
name|iwn5000_calib_elem
block|{
name|uint32_t
name|enable
decl_stmt|;
name|uint32_t
name|start
decl_stmt|;
name|uint32_t
name|send
decl_stmt|;
name|uint32_t
name|apply
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn5000_calib_status
block|{
name|struct
name|iwn5000_calib_elem
name|once
decl_stmt|;
name|struct
name|iwn5000_calib_elem
name|perd
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn5000_calib_config
block|{
name|struct
name|iwn5000_calib_status
name|ucode
decl_stmt|;
name|struct
name|iwn5000_calib_status
name|driver
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command IWN_CMD_SET_POWER_MODE. */
end_comment

begin_struct
struct|struct
name|iwn_pmgt_cmd
block|{
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_PS_ALLOW_SLEEP
value|(1<< 0)
define|#
directive|define
name|IWN_PS_NOTIFY
value|(1<< 1)
define|#
directive|define
name|IWN_PS_SLEEP_OVER_DTIM
value|(1<< 2)
define|#
directive|define
name|IWN_PS_PCI_PMGT
value|(1<< 3)
define|#
directive|define
name|IWN_PS_FAST_PD
value|(1<< 4)
name|uint8_t
name|keepalive
decl_stmt|;
name|uint8_t
name|debug
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
name|uint32_t
name|beacons
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structures for command IWN_CMD_SCAN. */
end_comment

begin_struct
struct|struct
name|iwn_scan_essid
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
name|iwn_scan_hdr
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
name|rxchain
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
comment|/* Followed by a struct iwn_cmd_data. */
comment|/* Followed by an array of 20 structs iwn_scan_essid. */
comment|/* Followed by probe request body. */
comment|/* Followed by an array of ``nchan'' structs iwn_scan_chan. */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_scan_chan
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_CHAN_ACTIVE
value|(1<< 0)
define|#
directive|define
name|IWN_CHAN_NPBREQS
parameter_list|(
name|x
parameter_list|)
value|(((1<< (x)) - 1)<< 1)
name|uint16_t
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

begin_comment
comment|/* Maximum size of a scan command. */
end_comment

begin_define
define|#
directive|define
name|IWN_SCAN_MAXSZ
value|(MCLBYTES - 4)
end_define

begin_comment
comment|/* Structure for command IWN_CMD_TXPOWER (4965AGN only.) */
end_comment

begin_define
define|#
directive|define
name|IWN_RIDX_MAX
value|32
end_define

begin_struct
struct|struct
name|iwn4965_cmd_txpower
block|{
name|uint8_t
name|band
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|rf_gain
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|dsp_gain
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
name|power
index|[
name|IWN_RIDX_MAX
operator|+
literal|1
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command IWN_CMD_TXPOWER_DBM (5000 Series only.) */
end_comment

begin_struct
struct|struct
name|iwn5000_cmd_txpower
block|{
name|int8_t
name|global_limit
decl_stmt|;
comment|/* in half-dBm */
define|#
directive|define
name|IWN5000_TXPOWER_AUTO
value|0x7f
define|#
directive|define
name|IWN5000_TXPOWER_MAX_DBM
value|16
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN5000_TXPOWER_NO_CLOSED
value|(1<< 6)
name|int8_t
name|srv_limit
decl_stmt|;
comment|/* in half-dBm */
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command IWN_CMD_BLUETOOTH. */
end_comment

begin_struct
struct|struct
name|iwn_bluetooth
block|{
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|lead
decl_stmt|;
name|uint8_t
name|kill
decl_stmt|;
name|uint8_t
name|reserved
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

begin_comment
comment|/* Structure for command IWN_CMD_SET_CRITICAL_TEMP. */
end_comment

begin_struct
struct|struct
name|iwn_critical_temp
block|{
name|uint32_t
name|reserved
decl_stmt|;
name|uint32_t
name|tempM
decl_stmt|;
name|uint32_t
name|tempR
decl_stmt|;
comment|/* degK<-> degC conversion macros. */
define|#
directive|define
name|IWN_CTOK
parameter_list|(
name|c
parameter_list|)
value|((c) + 273)
define|#
directive|define
name|IWN_KTOC
parameter_list|(
name|k
parameter_list|)
value|((k) - 273)
define|#
directive|define
name|IWN_CTOMUK
parameter_list|(
name|c
parameter_list|)
value|(((c) * 1000000) + 273150000)
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command IWN_CMD_SET_SENSITIVITY. */
end_comment

begin_struct
struct|struct
name|iwn_sensitivity_cmd
block|{
name|uint16_t
name|which
decl_stmt|;
define|#
directive|define
name|IWN_SENSITIVITY_DEFAULTTBL
value|0
define|#
directive|define
name|IWN_SENSITIVITY_WORKTBL
value|1
name|uint16_t
name|energy_cck
decl_stmt|;
name|uint16_t
name|energy_ofdm
decl_stmt|;
name|uint16_t
name|corr_ofdm_x1
decl_stmt|;
name|uint16_t
name|corr_ofdm_mrc_x1
decl_stmt|;
name|uint16_t
name|corr_cck_mrc_x4
decl_stmt|;
name|uint16_t
name|corr_ofdm_x4
decl_stmt|;
name|uint16_t
name|corr_ofdm_mrc_x4
decl_stmt|;
name|uint16_t
name|corr_barker
decl_stmt|;
name|uint16_t
name|corr_barker_mrc
decl_stmt|;
name|uint16_t
name|corr_cck_x4
decl_stmt|;
name|uint16_t
name|energy_ofdm_th
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structures for command IWN_CMD_PHY_CALIB. */
end_comment

begin_struct
struct|struct
name|iwn_phy_calib
block|{
name|uint8_t
name|code
decl_stmt|;
define|#
directive|define
name|IWN4965_PHY_CALIB_DIFF_GAIN
value|7
define|#
directive|define
name|IWN5000_PHY_CALIB_DC
value|8
define|#
directive|define
name|IWN5000_PHY_CALIB_LO
value|9
define|#
directive|define
name|IWN5000_PHY_CALIB_TX_IQ
value|11
define|#
directive|define
name|IWN5000_PHY_CALIB_CRYSTAL
value|15
define|#
directive|define
name|IWN5000_PHY_CALIB_BASE_BAND
value|16
define|#
directive|define
name|IWN5000_PHY_CALIB_TX_IQ_PERD
value|17
define|#
directive|define
name|IWN5000_PHY_CALIB_RESET_NOISE_GAIN
value|18
define|#
directive|define
name|IWN5000_PHY_CALIB_NOISE_GAIN
value|19
name|uint8_t
name|group
decl_stmt|;
name|uint8_t
name|ngroups
decl_stmt|;
name|uint8_t
name|isvalid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn5000_phy_calib_crystal
block|{
name|uint8_t
name|code
decl_stmt|;
name|uint8_t
name|group
decl_stmt|;
name|uint8_t
name|ngroups
decl_stmt|;
name|uint8_t
name|isvalid
decl_stmt|;
name|uint8_t
name|cap_pin
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|reserved
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
name|iwn_phy_calib_gain
block|{
name|uint8_t
name|code
decl_stmt|;
name|uint8_t
name|group
decl_stmt|;
name|uint8_t
name|ngroups
decl_stmt|;
name|uint8_t
name|isvalid
decl_stmt|;
name|int8_t
name|gain
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for command IWN_CMD_SPECTRUM_MEASUREMENT. */
end_comment

begin_struct
struct|struct
name|iwn_spectrum_cmd
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint8_t
name|token
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|origin
decl_stmt|;
name|uint8_t
name|periodic
decl_stmt|;
name|uint16_t
name|timeout
decl_stmt|;
name|uint32_t
name|start
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|filter
decl_stmt|;
name|uint16_t
name|nchan
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|duration
decl_stmt|;
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|IWN_MEASUREMENT_BASIC
value|(1<< 0)
define|#
directive|define
name|IWN_MEASUREMENT_CCA
value|(1<< 1)
define|#
directive|define
name|IWN_MEASUREMENT_RPI_HISTOGRAM
value|(1<< 2)
define|#
directive|define
name|IWN_MEASUREMENT_NOISE_HISTOGRAM
value|(1<< 3)
define|#
directive|define
name|IWN_MEASUREMENT_FRAME
value|(1<< 4)
define|#
directive|define
name|IWN_MEASUREMENT_IDLE
value|(1<< 7)
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
name|chan
index|[
literal|10
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for IWN_UC_READY notification. */
end_comment

begin_define
define|#
directive|define
name|IWN_NATTEN_GROUPS
value|5
end_define

begin_struct
struct|struct
name|iwn_ucode_info
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
define|#
directive|define
name|IWN_UCODE_RUNTIME
value|0
define|#
directive|define
name|IWN_UCODE_INIT
value|9
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
comment|/* The following fields are for UCODE_INIT only. */
name|int32_t
name|volt
decl_stmt|;
struct|struct
block|{
name|int32_t
name|chan20MHz
decl_stmt|;
name|int32_t
name|chan40MHz
decl_stmt|;
block|}
name|__packed
name|temp
index|[
literal|4
index|]
struct|;
name|int32_t
name|atten
index|[
name|IWN_NATTEN_GROUPS
index|]
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structures for IWN_TX_DONE notification. */
end_comment

begin_define
define|#
directive|define
name|IWN_TX_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|IWN_TX_FAIL
value|0x80
end_define

begin_comment
comment|/* all failures have 0x80 set */
end_comment

begin_define
define|#
directive|define
name|IWN_TX_FAIL_SHORT_LIMIT
value|0x82
end_define

begin_comment
comment|/* too many RTS retries */
end_comment

begin_define
define|#
directive|define
name|IWN_TX_FAIL_LONG_LIMIT
value|0x83
end_define

begin_comment
comment|/* too many retries */
end_comment

begin_define
define|#
directive|define
name|IWN_TX_FAIL_FIFO_UNDERRRUN
value|0x84
end_define

begin_comment
comment|/* tx fifo not kept running */
end_comment

begin_define
define|#
directive|define
name|IWN_TX_FAIL_DEST_IN_PS
value|0x88
end_define

begin_comment
comment|/* sta found in power save */
end_comment

begin_define
define|#
directive|define
name|IWN_TX_FAIL_TX_LOCKED
value|0x90
end_define

begin_comment
comment|/* waiting to see traffic */
end_comment

begin_struct
struct|struct
name|iwn4965_tx_stat
block|{
name|uint8_t
name|nframes
decl_stmt|;
name|uint8_t
name|killcnt
decl_stmt|;
name|uint8_t
name|rtscnt
decl_stmt|;
name|uint8_t
name|retrycnt
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rflags
decl_stmt|;
name|uint16_t
name|xrflags
decl_stmt|;
name|uint16_t
name|duration
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint32_t
name|power
index|[
literal|2
index|]
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
name|iwn5000_tx_stat
block|{
name|uint8_t
name|nframes
decl_stmt|;
name|uint8_t
name|killcnt
decl_stmt|;
name|uint8_t
name|rtscnt
decl_stmt|;
name|uint8_t
name|retrycnt
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rflags
decl_stmt|;
name|uint16_t
name|xrflags
decl_stmt|;
name|uint16_t
name|duration
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint32_t
name|power
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|info
decl_stmt|;
name|uint16_t
name|seq
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
name|uint32_t
name|tlc
decl_stmt|;
name|uint16_t
name|status
decl_stmt|;
name|uint16_t
name|sequence
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for IWN_BEACON_MISSED notification. */
end_comment

begin_struct
struct|struct
name|iwn_beacon_missed
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
comment|/* Structure for IWN_MPDU_RX_DONE notification. */
end_comment

begin_struct
struct|struct
name|iwn_rx_mpdu
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structures for IWN_RX_DONE and IWN_MPDU_RX_DONE notifications. */
end_comment

begin_struct
struct|struct
name|iwn4965_rx_phystat
block|{
name|uint16_t
name|antenna
decl_stmt|;
name|uint16_t
name|agc
decl_stmt|;
name|uint8_t
name|rssi
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn5000_rx_phystat
block|{
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|agc
decl_stmt|;
name|uint16_t
name|rssi
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_rx_stat
block|{
name|uint8_t
name|phy_len
decl_stmt|;
name|uint8_t
name|cfg_phy_len
decl_stmt|;
define|#
directive|define
name|IWN_STAT_MAXLEN
value|20
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint64_t
name|tstamp
decl_stmt|;
name|uint32_t
name|beacon
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_STAT_FLAG_SHPREAMBLE
value|(1<< 2)
name|uint16_t
name|chan
decl_stmt|;
name|uint8_t
name|phybuf
index|[
literal|32
index|]
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rflags
decl_stmt|;
name|uint16_t
name|xrflags
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|reserve3
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN_RSSI_TO_DBM
value|44
end_define

begin_comment
comment|/* Structure for IWN_START_SCAN notification. */
end_comment

begin_struct
struct|struct
name|iwn_start_scan
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
comment|/* Structure for IWN_STOP_SCAN notification. */
end_comment

begin_struct
struct|struct
name|iwn_stop_scan
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
comment|/* Structure for IWN_SPECTRUM_MEASUREMENT notification. */
end_comment

begin_struct
struct|struct
name|iwn_spectrum_notif
block|{
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|token
decl_stmt|;
name|uint8_t
name|idx
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
define|#
directive|define
name|IWN_MEASUREMENT_START
value|0
define|#
directive|define
name|IWN_MEASUREMENT_STOP
value|1
name|uint32_t
name|start
decl_stmt|;
name|uint8_t
name|band
decl_stmt|;
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint32_t
name|cca_ofdm
decl_stmt|;
name|uint32_t
name|cca_cck
decl_stmt|;
name|uint32_t
name|cca_time
decl_stmt|;
name|uint8_t
name|basic
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|ofdm
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|cck
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|stop
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
define|#
directive|define
name|IWN_MEASUREMENT_OK
value|0
define|#
directive|define
name|IWN_MEASUREMENT_CONCURRENT
value|1
define|#
directive|define
name|IWN_MEASUREMENT_CSA_CONFLICT
value|2
define|#
directive|define
name|IWN_MEASUREMENT_TGH_CONFLICT
value|3
define|#
directive|define
name|IWN_MEASUREMENT_STOPPED
value|6
define|#
directive|define
name|IWN_MEASUREMENT_TIMEOUT
value|7
define|#
directive|define
name|IWN_MEASUREMENT_FAILED
value|8
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for IWN_{RX,BEACON}_STATISTICS notification. */
end_comment

begin_struct
struct|struct
name|iwn_rx_phy_stats
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
name|uint32_t
name|ba_resp
decl_stmt|;
name|uint32_t
name|dsp_kill
decl_stmt|;
name|uint32_t
name|bad_mh
decl_stmt|;
name|uint32_t
name|rssi_sum
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_rx_general_stats
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
name|uint32_t
name|beacons
decl_stmt|;
name|uint32_t
name|missed_beacons
decl_stmt|;
name|uint32_t
name|adc_saturated
decl_stmt|;
comment|/* time in 0.8us */
name|uint32_t
name|ina_searched
decl_stmt|;
comment|/* time in 0.8us */
name|uint32_t
name|noise
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|load
decl_stmt|;
name|uint32_t
name|fa
decl_stmt|;
name|uint32_t
name|rssi
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|energy
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_rx_ht_phy_stats
block|{
name|uint32_t
name|bad_plcp
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
name|bad_crc32
decl_stmt|;
name|uint32_t
name|bad_mh
decl_stmt|;
name|uint32_t
name|good_ampdu_crc32
decl_stmt|;
name|uint32_t
name|ampdu
decl_stmt|;
name|uint32_t
name|fragment
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_rx_stats
block|{
name|struct
name|iwn_rx_phy_stats
name|ofdm
decl_stmt|;
name|struct
name|iwn_rx_phy_stats
name|cck
decl_stmt|;
name|struct
name|iwn_rx_general_stats
name|general
decl_stmt|;
name|struct
name|iwn_rx_ht_phy_stats
name|ht
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_tx_stats
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
name|uint32_t
name|msdu
decl_stmt|;
name|uint32_t
name|busrt_err1
decl_stmt|;
name|uint32_t
name|burst_err2
decl_stmt|;
name|uint32_t
name|cts_collision
decl_stmt|;
name|uint32_t
name|ack_collision
decl_stmt|;
name|uint32_t
name|ba_timeout
decl_stmt|;
name|uint32_t
name|ba_resched
decl_stmt|;
name|uint32_t
name|query_ampdu
decl_stmt|;
name|uint32_t
name|query
decl_stmt|;
name|uint32_t
name|query_ampdu_frag
decl_stmt|;
name|uint32_t
name|query_mismatch
decl_stmt|;
name|uint32_t
name|not_ready
decl_stmt|;
name|uint32_t
name|underrun
decl_stmt|;
name|uint32_t
name|bt_ht_kill
decl_stmt|;
name|uint32_t
name|rx_ba_resp
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

begin_struct
struct|struct
name|iwn_general_stats
block|{
name|uint32_t
name|temp
decl_stmt|;
name|uint32_t
name|temp_m
decl_stmt|;
name|uint32_t
name|burst_check
decl_stmt|;
name|uint32_t
name|burst
decl_stmt|;
name|uint32_t
name|reserved1
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
name|uint32_t
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|rx_enabled
decl_stmt|;
name|uint32_t
name|reserved3
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_stats
block|{
name|uint32_t
name|flags
decl_stmt|;
name|struct
name|iwn_rx_stats
name|rx
decl_stmt|;
name|struct
name|iwn_tx_stats
name|tx
decl_stmt|;
name|struct
name|iwn_general_stats
name|general
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Firmware error dump. */
end_comment

begin_struct
struct|struct
name|iwn_fw_dump
block|{
name|uint32_t
name|valid
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
name|uint32_t
name|pc
decl_stmt|;
name|uint32_t
name|branch_link
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|interrupt_link
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|error_data
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|src_line
decl_stmt|;
name|uint32_t
name|tsf
decl_stmt|;
name|uint32_t
name|time
index|[
literal|2
index|]
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
name|iwn_firmware_hdr
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|main_textsz
decl_stmt|;
name|uint32_t
name|main_datasz
decl_stmt|;
name|uint32_t
name|init_textsz
decl_stmt|;
name|uint32_t
name|init_datasz
decl_stmt|;
name|uint32_t
name|boot_textsz
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN4965_FW_TEXT_MAXSZ
value|( 96 * 1024)
end_define

begin_define
define|#
directive|define
name|IWN4965_FW_DATA_MAXSZ
value|( 40 * 1024)
end_define

begin_define
define|#
directive|define
name|IWN5000_FW_TEXT_MAXSZ
value|(256 * 1024)
end_define

begin_define
define|#
directive|define
name|IWN5000_FW_DATA_MAXSZ
value|( 80 * 1024)
end_define

begin_define
define|#
directive|define
name|IWN_FW_BOOT_TEXT_MAXSZ
value|1024
end_define

begin_define
define|#
directive|define
name|IWN4965_FWSZ
value|(IWN4965_FW_TEXT_MAXSZ + IWN4965_FW_DATA_MAXSZ)
end_define

begin_define
define|#
directive|define
name|IWN5000_FWSZ
value|IWN5000_FW_TEXT_MAXSZ
end_define

begin_comment
comment|/*  * Offsets into EEPROM.  */
end_comment

begin_define
define|#
directive|define
name|IWN_EEPROM_MAC
value|0x015
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_RFCFG
value|0x048
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_DOMAIN
value|0x060
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_BAND1
value|0x063
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_REG
value|0x066
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_CAL
value|0x067
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_BAND2
value|0x072
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_BAND3
value|0x080
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_BAND4
value|0x08d
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_BAND5
value|0x099
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_BAND6
value|0x0a0
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_BAND7
value|0x0a8
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_MAXPOW
value|0x0e8
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_VOLTAGE
value|0x0e9
end_define

begin_define
define|#
directive|define
name|IWN4965_EEPROM_BANDS
value|0x0ea
end_define

begin_comment
comment|/* Indirect offsets. */
end_comment

begin_define
define|#
directive|define
name|IWN5000_EEPROM_DOMAIN
value|0x001
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_BAND1
value|0x004
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_BAND2
value|0x013
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_BAND3
value|0x021
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_BAND4
value|0x02e
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_BAND5
value|0x03a
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_BAND6
value|0x041
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_BAND7
value|0x049
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_CRYSTAL
value|0x128
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_TEMP
value|0x12a
end_define

begin_define
define|#
directive|define
name|IWN5000_EEPROM_VOLT
value|0x12b
end_define

begin_comment
comment|/* Possible flags for IWN_EEPROM_RFCFG. */
end_comment

begin_define
define|#
directive|define
name|IWN_RFCFG_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  0)& 0x3)
end_define

begin_define
define|#
directive|define
name|IWN_RFCFG_STEP
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  2)& 0x3)
end_define

begin_define
define|#
directive|define
name|IWN_RFCFG_DASH
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  4)& 0x3)
end_define

begin_define
define|#
directive|define
name|IWN_RFCFG_TXANTMSK
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  8)& 0xf)
end_define

begin_define
define|#
directive|define
name|IWN_RFCFG_RXANTMSK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xf)
end_define

begin_struct
struct|struct
name|iwn_eeprom_chan
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_EEPROM_CHAN_VALID
value|(1<< 0)
define|#
directive|define
name|IWN_EEPROM_CHAN_IBSS
value|(1<< 1)
define|#
directive|define
name|IWN_EEPROM_CHAN_ACTIVE
value|(1<< 3)
define|#
directive|define
name|IWN_EEPROM_CHAN_RADAR
value|(1<< 4)
define|#
directive|define
name|IWN_EEPROM_CHAN_WIDE
value|(1<< 5)
comment|/* HT40 */
define|#
directive|define
name|IWN_EEPROM_CHAN_NARROW
value|(1<< 6)
comment|/* HT20 */
name|int8_t
name|maxpwr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN_NSAMPLES
value|3
end_define

begin_struct
struct|struct
name|iwn4965_eeprom_chan_samples
block|{
name|uint8_t
name|num
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|temp
decl_stmt|;
name|uint8_t
name|gain
decl_stmt|;
name|uint8_t
name|power
decl_stmt|;
name|int8_t
name|pa_det
decl_stmt|;
block|}
name|samples
index|[
literal|2
index|]
index|[
name|IWN_NSAMPLES
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN_NBANDS
value|8
end_define

begin_struct
struct|struct
name|iwn4965_eeprom_band
block|{
name|uint8_t
name|lo
decl_stmt|;
comment|/* low channel number */
name|uint8_t
name|hi
decl_stmt|;
comment|/* high channel number */
name|struct
name|iwn4965_eeprom_chan_samples
name|chans
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Offsets of channels descriptions in EEPROM.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|iwn4965_regulatory_bands
index|[
name|IWN_NBANDS
index|]
init|=
block|{
name|IWN4965_EEPROM_BAND1
block|,
name|IWN4965_EEPROM_BAND2
block|,
name|IWN4965_EEPROM_BAND3
block|,
name|IWN4965_EEPROM_BAND4
block|,
name|IWN4965_EEPROM_BAND5
block|,
name|IWN4965_EEPROM_BAND6
block|,
name|IWN4965_EEPROM_BAND7
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|iwn5000_regulatory_bands
index|[
name|IWN_NBANDS
index|]
init|=
block|{
name|IWN5000_EEPROM_BAND1
block|,
name|IWN5000_EEPROM_BAND2
block|,
name|IWN5000_EEPROM_BAND3
block|,
name|IWN5000_EEPROM_BAND4
block|,
name|IWN5000_EEPROM_BAND5
block|,
name|IWN5000_EEPROM_BAND6
block|,
name|IWN5000_EEPROM_BAND7
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IWN_CHAN_BANDS_COUNT
value|7
end_define

begin_define
define|#
directive|define
name|IWN_MAX_CHAN_PER_BAND
value|14
end_define

begin_struct
specifier|static
specifier|const
struct|struct
name|iwn_chan_band
block|{
name|uint8_t
name|nchan
decl_stmt|;
name|uint8_t
name|chan
index|[
name|IWN_MAX_CHAN_PER_BAND
index|]
decl_stmt|;
block|}
name|iwn_bands
index|[]
init|=
block|{
comment|/* 20MHz channels, 2GHz band. */
block|{
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
block|,
comment|/* 40MHz channels (primary channels), 2GHz band. */
block|{
literal|7
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
block|}
block|}
block|,
comment|/* 40MHz channels (primary channels), 5GHz band. */
block|{
literal|11
block|,
block|{
literal|36
block|,
literal|44
block|,
literal|52
block|,
literal|60
block|,
literal|100
block|,
literal|108
block|,
literal|116
block|,
literal|124
block|,
literal|132
block|,
literal|149
block|,
literal|157
block|}
block|}
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN_RIDX_MCS
value|0x08
end_define

begin_comment
comment|/* or'd to indicate MCS */
end_comment

begin_comment
comment|/* HW rate indices. */
end_comment

begin_define
define|#
directive|define
name|IWN_RIDX_CCK1
value|0
end_define

begin_define
define|#
directive|define
name|IWN_RIDX_CCK11
value|3
end_define

begin_define
define|#
directive|define
name|IWN_RIDX_OFDM6
value|4
end_define

begin_define
define|#
directive|define
name|IWN_RIDX_OFDM54
value|11
end_define

begin_struct
specifier|static
specifier|const
struct|struct
name|iwn_rate
block|{
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|plcp
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
block|}
name|iwn_rates
index|[
name|IWN_RIDX_MAX
operator|+
literal|1
index|]
init|=
block|{
block|{
literal|2
block|,
literal|10
block|,
name|IWN_RFLAG_CCK
block|}
block|,
block|{
literal|4
block|,
literal|20
block|,
name|IWN_RFLAG_CCK
block|}
block|,
block|{
literal|11
block|,
literal|55
block|,
name|IWN_RFLAG_CCK
block|}
block|,
block|{
literal|22
block|,
literal|110
block|,
name|IWN_RFLAG_CCK
block|}
block|,
block|{
literal|12
block|,
literal|0xd
block|,
literal|0
block|}
block|,
block|{
literal|18
block|,
literal|0xf
block|,
literal|0
block|}
block|,
block|{
literal|24
block|,
literal|0x5
block|,
literal|0
block|}
block|,
block|{
literal|36
block|,
literal|0x7
block|,
literal|0
block|}
block|,
block|{
literal|48
block|,
literal|0x9
block|,
literal|0
block|}
block|,
block|{
literal|72
block|,
literal|0xb
block|,
literal|0
block|}
block|,
block|{
literal|96
block|,
literal|0x1
block|,
literal|0
block|}
block|,
block|{
literal|108
block|,
literal|0x3
block|,
literal|0
block|}
block|,
block|{
literal|120
block|,
literal|0x3
block|,
literal|0
block|}
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN4965_MAX_PWR_INDEX
value|107
end_define

begin_comment
comment|/*  * RF Tx gain values from highest to lowest power (values obtained from  * the reference driver.)  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|iwn4965_rf_gain_2ghz
index|[
name|IWN4965_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3e
block|,
literal|0x3e
block|,
literal|0x3e
block|,
literal|0x3d
block|,
literal|0x3d
block|,
literal|0x3d
block|,
literal|0x3c
block|,
literal|0x3c
block|,
literal|0x3c
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3a
block|,
literal|0x3a
block|,
literal|0x3a
block|,
literal|0x39
block|,
literal|0x39
block|,
literal|0x39
block|,
literal|0x38
block|,
literal|0x38
block|,
literal|0x38
block|,
literal|0x37
block|,
literal|0x37
block|,
literal|0x37
block|,
literal|0x36
block|,
literal|0x36
block|,
literal|0x36
block|,
literal|0x35
block|,
literal|0x35
block|,
literal|0x35
block|,
literal|0x34
block|,
literal|0x34
block|,
literal|0x34
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x32
block|,
literal|0x32
block|,
literal|0x32
block|,
literal|0x31
block|,
literal|0x31
block|,
literal|0x31
block|,
literal|0x30
block|,
literal|0x30
block|,
literal|0x30
block|,
literal|0x06
block|,
literal|0x06
block|,
literal|0x06
block|,
literal|0x05
block|,
literal|0x05
block|,
literal|0x05
block|,
literal|0x04
block|,
literal|0x04
block|,
literal|0x04
block|,
literal|0x03
block|,
literal|0x03
block|,
literal|0x03
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|iwn4965_rf_gain_5ghz
index|[
name|IWN4965_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3e
block|,
literal|0x3e
block|,
literal|0x3e
block|,
literal|0x3d
block|,
literal|0x3d
block|,
literal|0x3d
block|,
literal|0x3c
block|,
literal|0x3c
block|,
literal|0x3c
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3a
block|,
literal|0x3a
block|,
literal|0x3a
block|,
literal|0x39
block|,
literal|0x39
block|,
literal|0x39
block|,
literal|0x38
block|,
literal|0x38
block|,
literal|0x38
block|,
literal|0x37
block|,
literal|0x37
block|,
literal|0x37
block|,
literal|0x36
block|,
literal|0x36
block|,
literal|0x36
block|,
literal|0x35
block|,
literal|0x35
block|,
literal|0x35
block|,
literal|0x34
block|,
literal|0x34
block|,
literal|0x34
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x32
block|,
literal|0x32
block|,
literal|0x32
block|,
literal|0x31
block|,
literal|0x31
block|,
literal|0x31
block|,
literal|0x30
block|,
literal|0x30
block|,
literal|0x30
block|,
literal|0x25
block|,
literal|0x25
block|,
literal|0x25
block|,
literal|0x24
block|,
literal|0x24
block|,
literal|0x24
block|,
literal|0x23
block|,
literal|0x23
block|,
literal|0x23
block|,
literal|0x22
block|,
literal|0x18
block|,
literal|0x18
block|,
literal|0x17
block|,
literal|0x17
block|,
literal|0x17
block|,
literal|0x16
block|,
literal|0x16
block|,
literal|0x16
block|,
literal|0x15
block|,
literal|0x15
block|,
literal|0x15
block|,
literal|0x14
block|,
literal|0x14
block|,
literal|0x14
block|,
literal|0x13
block|,
literal|0x13
block|,
literal|0x13
block|,
literal|0x12
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x07
block|,
literal|0x07
block|,
literal|0x07
block|,
literal|0x06
block|,
literal|0x06
block|,
literal|0x06
block|,
literal|0x05
block|,
literal|0x05
block|,
literal|0x05
block|,
literal|0x04
block|,
literal|0x04
block|,
literal|0x04
block|,
literal|0x03
block|,
literal|0x03
block|,
literal|0x03
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
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
name|iwn4965_dsp_gain_2ghz
index|[
name|IWN4965_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x61
block|,
literal|0x60
block|,
literal|0x5f
block|,
literal|0x5e
block|,
literal|0x5d
block|,
literal|0x5c
block|,
literal|0x5b
block|,
literal|0x5a
block|,
literal|0x59
block|,
literal|0x58
block|,
literal|0x57
block|,
literal|0x56
block|,
literal|0x55
block|,
literal|0x54
block|,
literal|0x53
block|,
literal|0x52
block|,
literal|0x51
block|,
literal|0x50
block|,
literal|0x4f
block|,
literal|0x4e
block|,
literal|0x4d
block|,
literal|0x4c
block|,
literal|0x4b
block|,
literal|0x4a
block|,
literal|0x49
block|,
literal|0x48
block|,
literal|0x47
block|,
literal|0x46
block|,
literal|0x45
block|,
literal|0x44
block|,
literal|0x43
block|,
literal|0x42
block|,
literal|0x41
block|,
literal|0x40
block|,
literal|0x3f
block|,
literal|0x3e
block|,
literal|0x3d
block|,
literal|0x3c
block|,
literal|0x3b
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|iwn4965_dsp_gain_5ghz
index|[
name|IWN4965_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0x7b
block|,
literal|0x75
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x5d
block|,
literal|0x58
block|,
literal|0x53
block|,
literal|0x4e
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Power saving settings (values obtained from the reference driver.)  */
end_comment

begin_define
define|#
directive|define
name|IWN_NDTIMRANGES
value|3
end_define

begin_define
define|#
directive|define
name|IWN_NPOWERLEVELS
value|6
end_define

begin_struct
specifier|static
specifier|const
struct|struct
name|iwn_pmgt
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
name|iwn_pmgt
index|[
name|IWN_NDTIMRANGES
index|]
index|[
name|IWN_NPOWERLEVELS
index|]
init|=
block|{
comment|/* DTIM<= 2 */
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
literal|2
block|,
literal|2
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
literal|1
block|,
literal|2
block|,
literal|2
block|,
literal|2
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
literal|2
block|,
literal|2
block|,
literal|2
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
literal|2
block|,
literal|4
block|,
literal|4
block|,
operator|-
literal|1
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
literal|2
block|,
literal|2
block|,
literal|4
block|,
literal|6
block|,
operator|-
literal|1
block|}
block|,
literal|2
block|}
comment|/* PS level 5 */
block|}
block|,
comment|/* 3<= DTIM<= 10 */
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
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
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
literal|4
block|,
literal|6
block|,
literal|7
block|,
literal|9
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
literal|4
block|,
literal|6
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
literal|2
block|,
literal|4
block|,
literal|7
block|,
literal|10
block|,
literal|10
block|}
block|,
literal|2
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

begin_struct
struct|struct
name|iwn_sensitivity_limits
block|{
name|uint32_t
name|min_ofdm_x1
decl_stmt|;
name|uint32_t
name|max_ofdm_x1
decl_stmt|;
name|uint32_t
name|min_ofdm_mrc_x1
decl_stmt|;
name|uint32_t
name|max_ofdm_mrc_x1
decl_stmt|;
name|uint32_t
name|min_ofdm_x4
decl_stmt|;
name|uint32_t
name|max_ofdm_x4
decl_stmt|;
name|uint32_t
name|min_ofdm_mrc_x4
decl_stmt|;
name|uint32_t
name|max_ofdm_mrc_x4
decl_stmt|;
name|uint32_t
name|min_cck_x4
decl_stmt|;
name|uint32_t
name|max_cck_x4
decl_stmt|;
name|uint32_t
name|min_cck_mrc_x4
decl_stmt|;
name|uint32_t
name|max_cck_mrc_x4
decl_stmt|;
name|uint32_t
name|min_energy_cck
decl_stmt|;
name|uint32_t
name|energy_cck
decl_stmt|;
name|uint32_t
name|energy_ofdm
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RX sensitivity limits (values obtained from the reference driver.)  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|iwn_sensitivity_limits
name|iwn4965_sensitivity_limits
init|=
block|{
literal|105
block|,
literal|140
block|,
literal|170
block|,
literal|210
block|,
literal|85
block|,
literal|120
block|,
literal|170
block|,
literal|210
block|,
literal|125
block|,
literal|200
block|,
literal|200
block|,
literal|400
block|,
literal|97
block|,
literal|100
block|,
literal|100
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|iwn_sensitivity_limits
name|iwn5000_sensitivity_limits
init|=
block|{
literal|120
block|,
literal|155
block|,
literal|240
block|,
literal|290
block|,
literal|90
block|,
literal|120
block|,
literal|170
block|,
literal|210
block|,
literal|125
block|,
literal|200
block|,
literal|170
block|,
literal|400
block|,
literal|95
block|,
literal|95
block|,
literal|95
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map TID to TX scheduler's FIFO. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|iwn_tid2fifo
index|[]
init|=
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|2
block|,
literal|3
block|,
literal|3
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Firmware errors. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|iwn_fw_errmsg
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
literal|"NMI_INTERRUPT_WDG"
block|,
literal|"SYSASSERT"
block|,
literal|"FATAL_ERROR"
block|,
literal|"BAD_COMMAND"
block|,
literal|"HW_ERROR_TUNE_LOCK"
block|,
literal|"HW_ERROR_TEMPERATURE"
block|,
literal|"ILLEGAL_CHAN_FREQ"
block|,
literal|"VCC_NOT_STABLE"
block|,
literal|"FH_ERROR"
block|,
literal|"NMI_INTERRUPT_HOST"
block|,
literal|"NMI_INTERRUPT_ACTION_PT"
block|,
literal|"NMI_INTERRUPT_UNKNOWN"
block|,
literal|"UCODE_VERSION_MISMATCH"
block|,
literal|"HW_ERROR_ABS_LOCK"
block|,
literal|"HW_ERROR_CAL_LOCK_FAIL"
block|,
literal|"NMI_INTERRUPT_INST_ACTION_PT"
block|,
literal|"NMI_INTERRUPT_DATA_ACTION_PT"
block|,
literal|"NMI_TRM_HW_ER"
block|,
literal|"NMI_INTERRUPT_TRM"
block|,
literal|"NMI_INTERRUPT_BREAKPOINT"
literal|"DEBUG_0"
block|,
literal|"DEBUG_1"
block|,
literal|"DEBUG_2"
block|,
literal|"DEBUG_3"
block|,
literal|"UNKNOWN"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find least significant bit that is set. */
end_comment

begin_define
define|#
directive|define
name|IWN_LSB
parameter_list|(
name|x
parameter_list|)
value|((((x) - 1)& (x)) ^ (x))
end_define

begin_define
define|#
directive|define
name|IWN_READ
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
name|IWN_WRITE
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
name|IWN_SETBITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|mask
parameter_list|)
define|\
value|IWN_WRITE(sc, reg, IWN_READ(sc, reg) | (mask))
end_define

begin_define
define|#
directive|define
name|IWN_CLRBITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|mask
parameter_list|)
define|\
value|IWN_WRITE(sc, reg, IWN_READ(sc, reg)& ~(mask))
end_define

end_unit

