begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD */
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
file|<mips/xlr/xlrconfig.h>
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
name|value
parameter_list|)
value|write_c2_register32(MSGRNG_MSG_CONFIG_REG, 0, value)
end_define

begin_define
define|#
directive|define
name|msgrng_read_bucksize
parameter_list|(
name|bucket
parameter_list|)
value|read_c2_register32(MSGRNG_MSG_BUCKSIZE_REG, bucket)
end_define

begin_define
define|#
directive|define
name|msgrng_write_bucksize
parameter_list|(
name|bucket
parameter_list|,
name|value
parameter_list|)
value|write_c2_register32(MSGRNG_MSG_BUCKSIZE_REG, bucket, value)
end_define

begin_define
define|#
directive|define
name|msgrng_read_cc
parameter_list|(
name|reg
parameter_list|,
name|pri
parameter_list|)
value|read_c2_register32(reg, pri)
end_define

begin_define
define|#
directive|define
name|msgrng_write_cc
parameter_list|(
name|reg
parameter_list|,
name|value
parameter_list|,
name|pri
parameter_list|)
value|write_c2_register32(reg, pri, value)
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
name|value
parameter_list|)
value|write_c2_register64(MSGRNG_TX_BUF_REG, 0, value)
end_define

begin_define
define|#
directive|define
name|msgrng_load_tx_msg1
parameter_list|(
name|value
parameter_list|)
value|write_c2_register64(MSGRNG_TX_BUF_REG, 1, value)
end_define

begin_define
define|#
directive|define
name|msgrng_load_tx_msg2
parameter_list|(
name|value
parameter_list|)
value|write_c2_register64(MSGRNG_TX_BUF_REG, 2, value)
end_define

begin_define
define|#
directive|define
name|msgrng_load_tx_msg3
parameter_list|(
name|value
parameter_list|)
value|write_c2_register64(MSGRNG_TX_BUF_REG, 3, value)
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

begin_function
specifier|static
specifier|inline
name|int
name|msgrng_xgmac_stid_rfr
parameter_list|(
name|int
name|id
parameter_list|)
block|{
return|return
operator|!
name|id
condition|?
name|MSGRNG_STNID_XMAC0RFR
else|:
name|MSGRNG_STNID_XMAC1RFR
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|msgrng_xgmac_stid_jfr
parameter_list|(
name|int
name|id
parameter_list|)
block|{
return|return
operator|!
name|id
condition|?
name|MSGRNG_STNID_XMAC0JFR
else|:
name|MSGRNG_STNID_XMAC1JFR
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|msgrng_xgmac_stid_tx
parameter_list|(
name|int
name|id
parameter_list|)
block|{
return|return
operator|!
name|id
condition|?
name|MSGRNG_STNID_XMAC0_00_TX
else|:
name|MSGRNG_STNID_XMAC1_00_TX
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|msgrng_gmac_stid_rfr
parameter_list|(
name|int
name|id
parameter_list|)
block|{
return|return
operator|(
name|MSGRNG_STNID_GMACRFR_0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|msgrng_gmac_stid_rfr_split_mode
parameter_list|(
name|int
name|id
parameter_list|)
block|{
return|return
operator|(
operator|(
name|id
operator|>>
literal|1
operator|)
condition|?
name|MSGRNG_STNID_GMACRFR_1
else|:
name|MSGRNG_STNID_GMACRFR_0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|msgrng_gmac_stid_jfr
parameter_list|(
name|int
name|id
parameter_list|)
block|{
return|return
name|MSGRNG_STNID_GMACJFR_0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|msgrng_gmac_stid_jfr_split_mode
parameter_list|(
name|int
name|id
parameter_list|)
block|{
return|return
operator|(
operator|(
name|id
operator|>>
literal|1
operator|)
condition|?
name|MSGRNG_STNID_GMACJFR_1
else|:
name|MSGRNG_STNID_GMACJFR_0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|msgrng_gmac_stid_tx
parameter_list|(
name|int
name|id
parameter_list|)
block|{
return|return
operator|(
name|MSGRNG_STNID_GMACTX0
operator|+
name|id
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
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
asm|( 		    ".set push\n" 		    ".set noreorder\n" 		    "sync\n"
comment|//		    "msgsnd %0\n"
asm|"move  $8, %0\n" 		    "c2    0x80001\n" 		    ".set pop\n" 		    : : "r" (stid) : "$8" 		    );
block|}
end_function

begin_function
specifier|static
specifier|inline
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
asm|( 		    ".set push\n" 		    ".set noreorder\n"
comment|//		    "msgld %0\n"
asm|"move $8, %0\n" 		    "c2   0x80002\n" 		    ".set pop\n" 		    : : "r" (pri) : "$8" 		    );
block|}
end_function

begin_function
specifier|static
specifier|inline
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
asm|( 		    ".set push\n" 		    ".set noreorder\n"
comment|//		    "msgwait %0\n"
asm|"move $8, %0\n" 		    "c2   0x80003\n" 		    ".set pop\n" 		    : :"r" (mask) : "$8" 		    );
block|}
end_function

begin_define
define|#
directive|define
name|msgrng_enable
parameter_list|(
name|flags
parameter_list|)
define|\
value|do {                                                \   __asm__ volatile (                                \ 		    ".set push\n\t"                 \ 		    ".set reorder\n\t"              \ 		    ".set noat\n\t"                 \ 		    "mfc0 %0, $12\n\t"              \ 		    "li  $8, 0x40000001\n\t"        \ 		    "or  $1, %0, $8\n\t"            \ 		    "xori $1, 1\n\t"                \ 		    ".set noreorder\n\t"            \ 		    "mtc0 $1, $12\n\t"              \ 		    ".set\tpop\n\t"                 \ 		    : "=r" (flags)                  \ 		    :                               \ 		    : "$8"                          \ 		    );                              \ } while (0)
end_define

begin_define
define|#
directive|define
name|msgrng_disable
parameter_list|(
name|flags
parameter_list|)
value|__asm__ volatile (    \                  "mtc0 %0, $12" : : "r" (flags))
end_define

begin_define
define|#
directive|define
name|msgrng_flags_save
parameter_list|(
name|flags
parameter_list|)
value|msgrng_enable(flags)
end_define

begin_define
define|#
directive|define
name|msgrng_flags_restore
parameter_list|(
name|flags
parameter_list|)
value|msgrng_disable(flags)
end_define

begin_struct
struct|struct
name|msgrng_msg
block|{
name|__uint64_t
name|msg0
decl_stmt|;
name|__uint64_t
name|msg1
decl_stmt|;
name|__uint64_t
name|msg2
decl_stmt|;
name|__uint64_t
name|msg3
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|void
name|message_send_block_fast
parameter_list|(
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
name|unsigned
name|long
name|long
name|msg0
parameter_list|,
name|unsigned
name|long
name|long
name|msg1
parameter_list|,
name|unsigned
name|long
name|long
name|msg2
parameter_list|,
name|unsigned
name|long
name|long
name|msg3
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(".set push\n"                         ".set noreorder\n"                         ".set mips64\n"                         "dmtc2 %1, $0, 0\n"                         "dmtc2 %2, $0, 1\n"                         "dmtc2 %3, $0, 2\n"                         "dmtc2 %4, $0, 3\n"                         "move $8, %0\n"                         "1: c2 0x80001\n"                         "mfc2 $8, $2\n"                         "andi $8, $8, 0x6\n"                         "bnez $8, 1b\n"                         "move $8, %0\n"                         ".set pop\n"                         :                         : "r"(((size-1)<<16)|(code<<8)|stid), "r" (msg0), "r" (msg1), "r"(msg2), "r"(msg3)                         : "$8"                         );
block|}
end_function

begin_define
define|#
directive|define
name|message_receive_fast
parameter_list|(
name|bucket
parameter_list|,
name|size
parameter_list|,
name|code
parameter_list|,
name|stid
parameter_list|,
name|msg0
parameter_list|,
name|msg1
parameter_list|,
name|msg2
parameter_list|,
name|msg3
parameter_list|)
define|\
value|( { unsigned int _status=0, _tmp=0;                     \            msgrng_receive(bucket);                              \            while ( (_status=msgrng_read_status())& 0x08) ;     \            _tmp = _status& 0x30;                               \            if (__builtin_expect((!_tmp), 1)) {                  \                  (size)=((_status& 0xc0)>>6)+1;                \                  (code)=(_status& 0xff00)>>8;                  \                  (stid)=(_status& 0x7f0000)>>16;               \                  (msg0)=msgrng_load_rx_msg0();                  \                  (msg1)=msgrng_load_rx_msg1();                  \                  (msg2)=msgrng_load_rx_msg2();                  \                  (msg3)=msgrng_load_rx_msg3();                  \                  _tmp=0;                                        \                 }                                               \            _tmp;                                                \         } )
end_define

begin_function
specifier|static
name|__inline__
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
operator|(
name|stid
operator|)
expr_stmt|;
comment|//dbg_msg("Sending msg<%Lx,%Lx,%Lx,%Lx> to dest = %x\n",
comment|//msg->msg0, msg->msg1, msg->msg2, msg->msg3, dest);
name|msgrng_send
argument_list|(
name|dest
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|++
control|)
block|{
name|status
operator|=
name|msgrng_read_status
argument_list|()
expr_stmt|;
comment|//	dbg_msg("status = %Lx\n", status);
if|if
condition|(
name|status
operator|&
literal|0x6
condition|)
block|{
continue|continue;
block|}
else|else
break|break;
block|}
if|if
condition|(
name|i
operator|==
literal|16
condition|)
block|{
if|if
condition|(
name|dest
operator|==
literal|0x61
condition|)
comment|//dbg_msg("Processor %x: Unable to send msg to %llx\n", processor_id(), dest);
return|return
name|status
operator|&
literal|0x6
return|;
block|}
return|return
name|msgrng_read_status
argument_list|()
operator|&
literal|0x06
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|message_send_retry
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
name|int
name|res
init|=
literal|0
decl_stmt|;
name|int
name|retry
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|res
operator|=
name|message_send
argument_list|(
name|size
argument_list|,
name|code
argument_list|,
name|stid
argument_list|,
name|msg
argument_list|)
expr_stmt|;
comment|/* retry a pending fail */
if|if
condition|(
name|res
operator|&
literal|0x02
condition|)
continue|continue;
comment|/* credit fail */
if|if
condition|(
name|res
operator|&
literal|0x04
condition|)
name|retry
operator|++
expr_stmt|;
else|else
break|break;
if|if
condition|(
name|retry
operator|==
literal|4
condition|)
return|return
name|res
operator|&
literal|0x06
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|message_receive
parameter_list|(
name|int
name|pri
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
name|src_id
parameter_list|,
name|struct
name|msgrng_msg
modifier|*
name|msg
parameter_list|)
block|{
name|int
name|res
init|=
name|message_receive_fast
argument_list|(
name|pri
argument_list|,
operator|*
name|size
argument_list|,
operator|*
name|code
argument_list|,
operator|*
name|src_id
argument_list|,
name|msg
operator|->
name|msg0
argument_list|,
name|msg
operator|->
name|msg1
argument_list|,
name|msg
operator|->
name|msg2
argument_list|,
name|msg
operator|->
name|msg3
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|MSGRING_DUMP_MESSAGES
if|if
condition|(
operator|!
name|res
condition|)
block|{
name|dbg_msg
argument_list|(
literal|"Received msg<%llx, %llx, %llx, %llx><%d,%d,%d>\n"
argument_list|,
name|msg
operator|->
name|msg0
argument_list|,
name|msg
operator|->
name|msg1
argument_list|,
name|msg
operator|->
name|msg2
argument_list|,
name|msg
operator|->
name|msg3
argument_list|,
operator|*
name|size
argument_list|,
operator|*
name|code
argument_list|,
operator|*
name|src_id
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|res
return|;
block|}
end_function

begin_define
define|#
directive|define
name|MSGRNG_STN_RX_QSIZE
value|256
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
literal|128
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

begin_define
define|#
directive|define
name|msgrng_access_save
parameter_list|(
name|lock
parameter_list|,
name|mflags
parameter_list|)
value|do {                \   mtx_lock_spin(lock);                                       \   msgrng_flags_save(mflags);                                 \  }while(0)
end_define

begin_define
define|#
directive|define
name|msgrng_access_restore
parameter_list|(
name|lock
parameter_list|,
name|mflags
parameter_list|)
value|do {             \   msgrng_flags_restore(mflags);                              \   mtx_unlock_spin(lock);                                     \  }while(0)
end_define

begin_define
define|#
directive|define
name|msgrng_access_enable
parameter_list|(
name|mflags
parameter_list|)
value|do {   \   critical_enter();                         \   msgrng_flags_save(mflags);                \ } while(0)
end_define

begin_define
define|#
directive|define
name|msgrng_access_disable
parameter_list|(
name|mflags
parameter_list|)
value|do {   \   msgrng_flags_restore(mflags);              \   critical_exit();                           \ } while(0)
end_define

begin_comment
comment|/*  * NOTE: this is not stationid/8, ie the station numbers below are just  * for internal use  */
end_comment

begin_enum
enum|enum
block|{
name|TX_STN_CPU_0
block|,
name|TX_STN_CPU_1
block|,
name|TX_STN_CPU_2
block|,
name|TX_STN_CPU_3
block|,
name|TX_STN_CPU_4
block|,
name|TX_STN_CPU_5
block|,
name|TX_STN_CPU_6
block|,
name|TX_STN_CPU_7
block|,
name|TX_STN_GMAC
block|,
name|TX_STN_DMA
block|,
name|TX_STN_XGS_0
block|,
name|TX_STN_XGS_1
block|,
name|TX_STN_SAE
block|,
name|TX_STN_GMAC0
block|,
name|TX_STN_GMAC1
block|,
name|TX_STN_CDE
block|,
name|TX_STN_PCIE
block|,
name|TX_STN_INVALID
block|,
name|MAX_TX_STNS
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|int
name|register_msgring_handler
parameter_list|(
name|int
name|major
parameter_list|,
name|void
function_decl|(
modifier|*
name|action
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
parameter_list|,
name|void
modifier|*
name|dev_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xlr_msgring_cpu_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xlr_msgring_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cpu_to_msgring_bucket
parameter_list|(
name|cpu
parameter_list|)
value|((((cpu)>> 2)<<3)|((cpu)& 0x03))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

