begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RMI_MSGRING_H_
end_ifndef

begin_define
define|#
directive|define
name|_RMI_MSGRING_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuregs.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<mips/rmi/rmi_mips_exts.h>
end_include

begin_define
define|#
directive|define
name|MSGRNG_TX_BUF_REG
value|0
end_define

begin_define
define|#
directive|define
name|MSGRNG_RX_BUF_REG
value|1
end_define

begin_define
define|#
directive|define
name|MSGRNG_MSG_STATUS_REG
value|2
end_define

begin_define
define|#
directive|define
name|MSGRNG_MSG_CONFIG_REG
value|3
end_define

begin_define
define|#
directive|define
name|MSGRNG_MSG_BUCKSIZE_REG
value|4
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_0_REG
value|16
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_1_REG
value|17
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_2_REG
value|18
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_3_REG
value|19
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_4_REG
value|20
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_5_REG
value|21
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_6_REG
value|22
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_7_REG
value|23
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_8_REG
value|24
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_9_REG
value|25
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_10_REG
value|26
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_11_REG
value|27
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_12_REG
value|28
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_13_REG
value|29
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_14_REG
value|30
end_define

begin_define
define|#
directive|define
name|MSGRNG_CC_15_REG
value|31
end_define

begin_comment
comment|/* Station IDs */
end_comment

begin_define
define|#
directive|define
name|MSGRNG_STNID_CPU0
value|0x00
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CPU1
value|0x08
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CPU2
value|0x10
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CPU3
value|0x18
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CPU4
value|0x20
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CPU5
value|0x28
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CPU6
value|0x30
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CPU7
value|0x38
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XGS0_TX
value|64
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_00_TX
value|64
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_01_TX
value|65
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_02_TX
value|66
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_03_TX
value|67
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_04_TX
value|68
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_05_TX
value|69
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_06_TX
value|70
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_07_TX
value|71
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_08_TX
value|72
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_09_TX
value|73
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_10_TX
value|74
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_11_TX
value|75
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_12_TX
value|76
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_13_TX
value|77
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_14_TX
value|78
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0_15_TX
value|79
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XGS1_TX
value|80
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_00_TX
value|80
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_01_TX
value|81
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_02_TX
value|82
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_03_TX
value|83
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_04_TX
value|84
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_05_TX
value|85
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_06_TX
value|86
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_07_TX
value|87
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_08_TX
value|88
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_09_TX
value|89
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_10_TX
value|90
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_11_TX
value|91
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_12_TX
value|92
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_13_TX
value|93
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_14_TX
value|94
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1_15_TX
value|95
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC
value|96
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMACJFR_0
value|96
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMACRFR_0
value|97
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMACTX0
value|98
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMACTX1
value|99
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMACTX2
value|100
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMACTX3
value|101
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMACJFR_1
value|102
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMACRFR_1
value|103
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_DMA
value|104
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_DMA_0
value|104
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_DMA_1
value|105
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_DMA_2
value|106
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_DMA_3
value|107
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XGS0FR
value|112
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0JFR
value|112
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC0RFR
value|113
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XGS1FR
value|114
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1JFR
value|114
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XMAC1RFR
value|115
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_SEC
value|120
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_SEC0
value|120
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_SEC1
value|121
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_SEC2
value|122
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_SEC3
value|123
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_PK0
value|124
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_SEC_RSA
value|124
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_SEC_RSVD0
value|125
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_SEC_RSVD1
value|126
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_SEC_RSVD2
value|127
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC1
value|80
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC1_FR_0
value|81
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC1_TX0
value|82
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC1_TX1
value|83
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC1_TX2
value|84
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC1_TX3
value|85
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC1_FR_1
value|87
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC0
value|96
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC0_FR_0
value|97
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC0_TX0
value|98
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC0_TX1
value|99
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC0_TX2
value|100
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC0_TX3
value|101
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_GMAC0_FR_1
value|103
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CMP_0
value|108
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CMP_1
value|109
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CMP_2
value|110
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_CMP_3
value|111
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_PCIE_0
value|116
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_PCIE_1
value|117
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_PCIE_2
value|118
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_PCIE_3
value|119
end_define

begin_define
define|#
directive|define
name|MSGRNG_STNID_XLS_PK0
value|121
end_define

begin_define
define|#
directive|define
name|MSGRNG_CODE_MAC
value|0
end_define

begin_define
define|#
directive|define
name|MSGRNG_CODE_XGMAC
value|2
end_define

begin_define
define|#
directive|define
name|MSGRNG_CODE_SEC
value|0
end_define

begin_define
define|#
directive|define
name|MSGRNG_CODE_BOOT_WAKEUP
value|200
end_define

begin_define
define|#
directive|define
name|MSGRNG_CODE_SPI4
value|3
end_define

begin_define
define|#
directive|define
name|msgrng_read_status
parameter_list|()
value|read_c2_register32(MSGRNG_MSG_STATUS_REG, 0)
end_define

begin_define
define|#
directive|define
name|msgrng_read_config
parameter_list|()
value|read_c2_register32(MSGRNG_MSG_CONFIG_REG, 0)
end_define

begin_define
define|#
directive|define
name|msgrng_write_config
parameter_list|(
name|v
parameter_list|)
value|write_c2_register32(MSGRNG_MSG_CONFIG_REG, 0, v)
end_define

begin_define
define|#
directive|define
name|msgrng_read_bucksize
parameter_list|(
name|b
parameter_list|)
value|read_c2_register32(MSGRNG_MSG_BUCKSIZE_REG, b)
end_define

begin_define
define|#
directive|define
name|msgrng_write_bucksize
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|write_c2_register32(MSGRNG_MSG_BUCKSIZE_REG, b, v)
end_define

begin_define
define|#
directive|define
name|msgrng_read_cc
parameter_list|(
name|r
parameter_list|,
name|s
parameter_list|)
value|read_c2_register32(r, s)
end_define

begin_define
define|#
directive|define
name|msgrng_write_cc
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
value|write_c2_register32(r, s, v)
end_define

begin_define
define|#
directive|define
name|msgrng_load_rx_msg0
parameter_list|()
value|read_c2_register64(MSGRNG_RX_BUF_REG, 0)
end_define

begin_define
define|#
directive|define
name|msgrng_load_rx_msg1
parameter_list|()
value|read_c2_register64(MSGRNG_RX_BUF_REG, 1)
end_define

begin_define
define|#
directive|define
name|msgrng_load_rx_msg2
parameter_list|()
value|read_c2_register64(MSGRNG_RX_BUF_REG, 2)
end_define

begin_define
define|#
directive|define
name|msgrng_load_rx_msg3
parameter_list|()
value|read_c2_register64(MSGRNG_RX_BUF_REG, 3)
end_define

begin_define
define|#
directive|define
name|msgrng_load_tx_msg0
parameter_list|(
name|v
parameter_list|)
value|write_c2_register64(MSGRNG_TX_BUF_REG, 0, v)
end_define

begin_define
define|#
directive|define
name|msgrng_load_tx_msg1
parameter_list|(
name|v
parameter_list|)
value|write_c2_register64(MSGRNG_TX_BUF_REG, 1, v)
end_define

begin_define
define|#
directive|define
name|msgrng_load_tx_msg2
parameter_list|(
name|v
parameter_list|)
value|write_c2_register64(MSGRNG_TX_BUF_REG, 2, v)
end_define

begin_define
define|#
directive|define
name|msgrng_load_tx_msg3
parameter_list|(
name|v
parameter_list|)
value|write_c2_register64(MSGRNG_TX_BUF_REG, 3, v)
end_define

begin_function
specifier|static
name|__inline
name|void
name|msgrng_send
parameter_list|(
name|unsigned
name|int
name|stid
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|( 	    ".set	push\n" 	    ".set	noreorder\n" 	    "move	$8, %0\n" 	    "c2		0x80001\n"
comment|/* msgsnd $8 */
asm|".set	pop\n" 	    :: "r" (stid): "$8" 	);
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|msgrng_receive
parameter_list|(
name|unsigned
name|int
name|pri
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|( 	    ".set	push\n" 	    ".set	noreorder\n" 	    "move	$8, %0\n" 	    "c2		0x80002\n"
comment|/* msgld $8 */
asm|".set	pop\n" 	    :: "r" (pri): "$8" 	);
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|msgrng_wait
parameter_list|(
name|unsigned
name|int
name|mask
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|( 	    ".set	push\n" 	    ".set	noreorder\n" 	    "move	$8, %0\n" 	    "c2		0x80003\n"
comment|/* msgwait $8 */
asm|".set	pop\n" 	    :: "r" (mask): "$8" 	);
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|msgrng_access_enable
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|sr
init|=
name|mips_rd_status
argument_list|()
decl_stmt|;
name|mips_wr_status
argument_list|(
operator|(
name|sr
operator|&
operator|~
name|MIPS_SR_INT_IE
operator|)
operator||
name|MIPS_SR_COP_2_BIT
argument_list|)
expr_stmt|;
return|return
operator|(
name|sr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|msgrng_restore
parameter_list|(
name|uint32_t
name|sr
parameter_list|)
block|{
name|mips_wr_status
argument_list|(
name|sr
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|msgrng_msg
block|{
name|uint64_t
name|msg0
decl_stmt|;
name|uint64_t
name|msg1
decl_stmt|;
name|uint64_t
name|msg2
decl_stmt|;
name|uint64_t
name|msg3
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|int
name|message_send
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|,
name|unsigned
name|int
name|code
parameter_list|,
name|unsigned
name|int
name|stid
parameter_list|,
name|struct
name|msgrng_msg
modifier|*
name|msg
parameter_list|)
block|{
name|unsigned
name|int
name|dest
init|=
literal|0
decl_stmt|;
name|unsigned
name|long
name|long
name|status
init|=
literal|0
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|/*  	 * Make sure that all the writes pending at the cpu are flushed. 	 * Any writes pending on CPU will not be see by devices. L1/L2 	 * caches are coherent with IO, so no cache flush needed. 	 */
asm|__asm __volatile ("sync");
comment|/* Load TX message buffers */
name|msgrng_load_tx_msg0
argument_list|(
name|msg
operator|->
name|msg0
argument_list|)
expr_stmt|;
name|msgrng_load_tx_msg1
argument_list|(
name|msg
operator|->
name|msg1
argument_list|)
expr_stmt|;
name|msgrng_load_tx_msg2
argument_list|(
name|msg
operator|->
name|msg2
argument_list|)
expr_stmt|;
name|msgrng_load_tx_msg3
argument_list|(
name|msg
operator|->
name|msg3
argument_list|)
expr_stmt|;
name|dest
operator|=
operator|(
operator|(
name|size
operator|-
literal|1
operator|)
operator|<<
literal|16
operator|)
operator||
operator|(
name|code
operator|<<
literal|8
operator|)
operator||
name|stid
expr_stmt|;
comment|/* 	 * Retry a few times on credit fail, this should be a  	 * transient condition, unless there is a configuration 	 * failure, or the receiver is stuck. 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
name|msgrng_send
argument_list|(
name|dest
argument_list|)
expr_stmt|;
name|status
operator|=
name|msgrng_read_status
argument_list|()
expr_stmt|;
name|KASSERT
argument_list|(
operator|(
name|status
operator|&
literal|0x2
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"Send pending fail!"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|status
operator|&
literal|0x4
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* If there is a credit failure, return error */
return|return
operator|(
name|status
operator|&
literal|0x06
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|message_receive
parameter_list|(
name|int
name|bucket
parameter_list|,
name|int
modifier|*
name|size
parameter_list|,
name|int
modifier|*
name|code
parameter_list|,
name|int
modifier|*
name|stid
parameter_list|,
name|struct
name|msgrng_msg
modifier|*
name|msg
parameter_list|)
block|{
name|uint32_t
name|status
init|=
literal|0
decl_stmt|,
name|tmp
init|=
literal|0
decl_stmt|;
name|msgrng_receive
argument_list|(
name|bucket
argument_list|)
expr_stmt|;
comment|/* wait for load pending to clear */
do|do
block|{
name|status
operator|=
name|msgrng_read_status
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|status
operator|&
literal|0x08
operator|)
operator|!=
literal|0
condition|)
do|;
comment|/* receive error bits */
name|tmp
operator|=
name|status
operator|&
literal|0x30
expr_stmt|;
if|if
condition|(
name|tmp
operator|!=
literal|0
condition|)
return|return
operator|(
name|tmp
operator|)
return|;
operator|*
name|size
operator|=
operator|(
operator|(
name|status
operator|&
literal|0xc0
operator|)
operator|>>
literal|6
operator|)
operator|+
literal|1
expr_stmt|;
operator|*
name|code
operator|=
operator|(
name|status
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
expr_stmt|;
operator|*
name|stid
operator|=
operator|(
name|status
operator|&
literal|0x7f0000
operator|)
operator|>>
literal|16
expr_stmt|;
name|msg
operator|->
name|msg0
operator|=
name|msgrng_load_rx_msg0
argument_list|()
expr_stmt|;
name|msg
operator|->
name|msg1
operator|=
name|msgrng_load_rx_msg1
argument_list|()
expr_stmt|;
name|msg
operator|->
name|msg2
operator|=
name|msgrng_load_rx_msg2
argument_list|()
expr_stmt|;
name|msg
operator|->
name|msg3
operator|=
name|msgrng_load_rx_msg3
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|MSGRNG_STN_RX_QSIZE
value|256
end_define

begin_define
define|#
directive|define
name|MSGRNG_NSTATIONS
value|128
end_define

begin_define
define|#
directive|define
name|MSGRNG_CORE_NBUCKETS
value|8
end_define

begin_struct
struct|struct
name|stn_cc
block|{
name|unsigned
name|short
name|counters
index|[
literal|16
index|]
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bucket_size
block|{
name|unsigned
name|short
name|bucket
index|[
name|MSGRNG_NSTATIONS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|bucket_size
name|bucket_sizes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_cpu_0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_cpu_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_cpu_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_cpu_3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_cpu_4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_cpu_5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_cpu_6
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_cpu_7
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_xgs_0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_xgs_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_gmac
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_dma
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|cc_table_sec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bucket_size
name|xls_bucket_sizes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|xls_cc_table_cpu_0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|xls_cc_table_cpu_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|xls_cc_table_cpu_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|xls_cc_table_cpu_3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|xls_cc_table_gmac0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|xls_cc_table_gmac1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|xls_cc_table_cmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|xls_cc_table_pcie
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|xls_cc_table_dma
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stn_cc
name|xls_cc_table_sec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|msgring_handler
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|msgrng_msg
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|register_msgring_handler
parameter_list|(
name|int
name|startb
parameter_list|,
name|int
name|endb
parameter_list|,
name|msgring_handler
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|xlr_msgring_handler
parameter_list|(
name|uint8_t
name|bucket_mask
parameter_list|,
name|uint32_t
name|max_messages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xlr_msgring_cpu_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xlr_msgring_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

