begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for binding nvidia,tegra20-car.  *  * The first 96 clocks are numbered to match the bits in the CAR's CLK_OUT_ENB  * registers. These IDs often match those in the CAR's RST_DEVICES registers,  * but not in all cases. Some bits in CLK_OUT_ENB affect multiple clocks. In  * this case, those clocks are assigned IDs above 95 in order to highlight  * this issue. Implementations that interpret these clock IDs as bit values  * within the CLK_OUT_ENB or RST_DEVICES registers should be careful to  * explicitly handle these special cases.  *  * The balance of the clocks controlled by the CAR are assigned IDs of 96 and  * above.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_TEGRA20_CAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_TEGRA20_CAR_H
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_CPU
value|0
end_define

begin_comment
comment|/* 1 */
end_comment

begin_comment
comment|/* 2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_AC97
value|3
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_RTC
value|4
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_TIMER
value|5
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_UARTA
value|6
end_define

begin_comment
comment|/* 7 (register bit affects uart2 and vfir) */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_GPIO
value|8
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SDMMC2
value|9
end_define

begin_comment
comment|/* 10 (register bit affects spdif_in and spdif_out) */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_I2S1
value|11
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_I2C1
value|12
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_NDFLASH
value|13
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SDMMC1
value|14
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SDMMC4
value|15
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_TWC
value|16
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PWM
value|17
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_I2S2
value|18
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_EPP
value|19
end_define

begin_comment
comment|/* 20 (register bit affects vi and vi_sensor) */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_GR2D
value|21
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_USBD
value|22
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_ISP
value|23
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_GR3D
value|24
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_IDE
value|25
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_DISP2
value|26
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_DISP1
value|27
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_HOST1X
value|28
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_VCP
value|29
end_define

begin_comment
comment|/* 30 */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_CACHE2
value|31
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_MEM
value|32
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_AHBDMA
value|33
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_APBDMA
value|34
end_define

begin_comment
comment|/* 35 */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_KBC
value|36
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_STAT_MON
value|37
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PMC
value|38
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_FUSE
value|39
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_KFUSE
value|40
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SBC1
value|41
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_NOR
value|42
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SPI
value|43
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SBC2
value|44
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_XIO
value|45
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SBC3
value|46
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_DVC
value|47
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_DSI
value|48
end_define

begin_comment
comment|/* 49 (register bit affects tvo and cve) */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_MIPI
value|50
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_HDMI
value|51
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_CSI
value|52
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_TVDAC
value|53
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_I2C2
value|54
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_UARTC
value|55
end_define

begin_comment
comment|/* 56 */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_EMC
value|57
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_USB2
value|58
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_USB3
value|59
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_MPE
value|60
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_VDE
value|61
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_BSEA
value|62
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_BSEV
value|63
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SPEEDO
value|64
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_UARTD
value|65
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_UARTE
value|66
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_I2C3
value|67
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SBC4
value|68
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SDMMC3
value|69
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PEX
value|70
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_OWR
value|71
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_AFI
value|72
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_CSITE
value|73
end_define

begin_comment
comment|/* 74 */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_AVPUCQ
value|75
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_LA
value|76
end_define

begin_comment
comment|/* 77 */
end_comment

begin_comment
comment|/* 78 */
end_comment

begin_comment
comment|/* 79 */
end_comment

begin_comment
comment|/* 80 */
end_comment

begin_comment
comment|/* 81 */
end_comment

begin_comment
comment|/* 82 */
end_comment

begin_comment
comment|/* 83 */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_IRAMA
value|84
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_IRAMB
value|85
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_IRAMC
value|86
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_IRAMD
value|87
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_CRAM2
value|88
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_AUDIO_2X
value|89
end_define

begin_comment
comment|/* a/k/a audio_2x_sync_clk */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_CLK_D
value|90
end_define

begin_comment
comment|/* 91 */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_CSUS
value|92
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_CDEV2
value|93
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_CDEV1
value|94
end_define

begin_comment
comment|/* 95 */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_UARTB
value|96
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_VFIR
value|97
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SPDIF_IN
value|98
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SPDIF_OUT
value|99
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_VI
value|100
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_VI_SENSOR
value|101
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_TVO
value|102
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_CVE
value|103
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_OSC
value|104
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_CLK_32K
value|105
end_define

begin_comment
comment|/* a/k/a clk_s */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_CLK_M
value|106
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_SCLK
value|107
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_CCLK
value|108
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_HCLK
value|109
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PCLK
value|110
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_BLINK
value|111
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_A
value|112
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_A_OUT0
value|113
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_C
value|114
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_C_OUT1
value|115
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_D
value|116
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_D_OUT0
value|117
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_E
value|118
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_M
value|119
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_M_OUT1
value|120
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_P
value|121
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_P_OUT1
value|122
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_P_OUT2
value|123
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_P_OUT3
value|124
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_P_OUT4
value|125
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_S
value|126
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_U
value|127
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_X
value|128
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_COP
value|129
end_define

begin_comment
comment|/* a/k/a avp */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_AUDIO
value|130
end_define

begin_comment
comment|/* a/k/a audio_sync_clk */
end_comment

begin_define
define|#
directive|define
name|TEGRA20_CLK_PLL_REF
value|131
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_TWD
value|132
end_define

begin_define
define|#
directive|define
name|TEGRA20_CLK_CLK_MAX
value|133
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_TEGRA20_CAR_H */
end_comment

end_unit

