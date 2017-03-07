begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015, NVIDIA CORPORATION.  All rights reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms and conditions of the GNU General Public License,  * version 2, as published by the Free Software Foundation.  *  * This program is distributed in the hope it will be useful, but WITHOUT  * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for  * more details.  *  * You should have received a copy of the GNU General Public License  * along with this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ABI_MACH_T186_RESET_T186_H_
end_ifndef

begin_define
define|#
directive|define
name|_ABI_MACH_T186_RESET_T186_H_
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ACTMON
value|0
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AFI
value|1
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_CEC
value|2
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_CSITE
value|3
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DP2
value|4
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DPAUX
value|5
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DSI
value|6
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DSIB
value|7
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DTV
value|8
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DVFS
value|9
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ENTROPY
value|10
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_EXTPERIPH1
value|11
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_EXTPERIPH2
value|12
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_EXTPERIPH3
value|13
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_GPU
value|14
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_HDA
value|15
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_HDA2CODEC_2X
value|16
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_HDA2HDMICODEC
value|17
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_HOST1X
value|18
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C1
value|19
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C2
value|20
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C3
value|21
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C4
value|22
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C5
value|23
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C6
value|24
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ISP
value|25
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_KFUSE
value|26
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_LA
value|27
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_MIPI_CAL
value|28
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PCIE
value|29
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PCIEXCLK
value|30
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SATA
value|31
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SATACOLD
value|32
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SDMMC1
value|33
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SDMMC2
value|34
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SDMMC3
value|35
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SDMMC4
value|36
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SE
value|37
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SOC_THERM
value|38
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SOR0
value|39
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SPI1
value|40
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SPI2
value|41
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SPI3
value|42
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SPI4
value|43
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TMR
value|44
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TRIG_SYS
value|45
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TSEC
value|46
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UARTA
value|47
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UARTB
value|48
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UARTC
value|49
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UARTD
value|50
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_VI
value|51
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_VIC
value|52
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_XUSB_DEV
value|53
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_XUSB_HOST
value|54
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_XUSB_PADCTL
value|55
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_XUSB_SS
value|56
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_APB
value|57
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AXI_CBB
value|58
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_APB
value|59
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_CAN1
value|60
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_CAN2
value|61
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DMIC5
value|62
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DSIC
value|63
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DSID
value|64
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_EMC_EMC
value|65
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_EMC_MEM
value|66
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_EMCSB_EMC
value|67
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_EMCSB_MEM
value|68
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_EQOS
value|69
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_GPCDMA
value|70
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_GPIO_CTL0
value|71
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_GPIO_CTL1
value|72
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_GPIO_CTL2
value|73
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_GPIO_CTL3
value|74
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_GPIO_CTL4
value|75
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_GPIO_CTL5
value|76
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C10
value|77
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C12
value|78
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C13
value|79
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C14
value|80
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C7
value|81
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C8
value|82
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_I2C9
value|83
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_JTAG2AXI
value|84
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_MPHY_IOBIST
value|85
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_MPHY_L0_RX
value|86
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_MPHY_L0_TX
value|87
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVCSI
value|88
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDISPLAY0_HEAD0
value|89
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDISPLAY0_HEAD1
value|90
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDISPLAY0_HEAD2
value|91
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDISPLAY0_MISC
value|92
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDISPLAY0_WGRP0
value|93
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDISPLAY0_WGRP1
value|94
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDISPLAY0_WGRP2
value|95
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDISPLAY0_WGRP3
value|96
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDISPLAY0_WGRP4
value|97
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDISPLAY0_WGRP5
value|98
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PWM1
value|99
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PWM2
value|100
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PWM3
value|101
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PWM4
value|102
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PWM5
value|103
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PWM6
value|104
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PWM7
value|105
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PWM8
value|106
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_APB
value|107
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SOR1
value|108
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TACH
value|109
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TSC
value|110
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UARTF
value|111
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UARTG
value|112
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UFSHC
value|113
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UFSHC_AXI_M
value|114
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UPHY
value|115
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ADSP
value|116
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ADSPDBG
value|117
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ADSPINTF
value|118
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ADSPNEON
value|119
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ADSPPERIPH
value|120
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ADSPSCU
value|121
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ADSPWDT
value|122
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_APE
value|123
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DPAUX1
value|124
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVDEC
value|125
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVENC
value|126
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_NVJPG
value|127
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PEX_USB_UPHY
value|128
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_QSPI
value|129
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TSECB
value|130
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_VI_I2C
value|131
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UARTE
value|132
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TOP_GTE
value|133
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SHSP
value|134
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PEX_USB_UPHY_L5
value|135
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PEX_USB_UPHY_L4
value|136
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PEX_USB_UPHY_L3
value|137
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PEX_USB_UPHY_L2
value|138
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PEX_USB_UPHY_L1
value|139
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PEX_USB_UPHY_L0
value|140
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PEX_USB_UPHY_PLL1
value|141
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_PEX_USB_UPHY_PLL0
value|142
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TSCTNVI
value|143
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_EXTPERIPH4
value|144
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_DSIPADCTL
value|145
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AUD_MCLK
value|146
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_MPHY_CLK_CTL
value|147
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_MPHY_L1_RX
value|148
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_MPHY_L1_TX
value|149
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_UFSHC_LP
value|150
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_NIC
value|151
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_NSYSPORESET
value|152
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_NRESET
value|153
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_DBGRESETN
value|154
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_PRESETDBGN
value|155
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_PM
value|156
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_CVC
value|157
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_DMA
value|158
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_HSP
value|159
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TSCTNBPMP
value|160
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_TKE
value|161
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_GTE
value|162
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_BPMP_PM_ACTMON
value|163
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_NIC
value|164
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_NSYSPORESET
value|165
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_NRESET
value|166
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_DBGRESETN
value|167
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_PRESETDBGN
value|168
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_ACTMON
value|169
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AOPM
value|170
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AOVC
value|171
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_DMA
value|172
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_GPIO
value|173
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_HSP
value|174
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TSCTNAON
value|175
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_TKE
value|176
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_AON_GTE
value|177
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_NIC
value|178
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_NSYSPORESET
value|179
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_NRESET
value|180
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_DBGRESETN
value|181
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_PRESETDBGN
value|182
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_ACTMON
value|183
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_PM
value|184
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_DMA
value|185
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_HSP
value|186
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_TSCTNSCE
value|187
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_TKE
value|188
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_GTE
value|189
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SCE_CFG
value|190
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_ADSP_ALL
value|191
end_define

begin_comment
comment|/** @brief controls the power up/down sequence of UFSHC PSW partition. Controls LP_PWR_READY, LP_ISOL_EN, and LP_RESET_N signals */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_RESET_UFSHC_LP_SEQ
value|192
end_define

begin_define
define|#
directive|define
name|TEGRA186_RESET_SIZE
value|193
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

