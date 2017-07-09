begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for binding nvidia,tegra30-car.  *  * The first 130 clocks are numbered to match the bits in the CAR's CLK_OUT_ENB  * registers. These IDs often match those in the CAR's RST_DEVICES registers,  * but not in all cases. Some bits in CLK_OUT_ENB affect multiple clocks. In  * this case, those clocks are assigned IDs above 160 in order to highlight  * this issue. Implementations that interpret these clock IDs as bit values  * within the CLK_OUT_ENB or RST_DEVICES registers should be careful to  * explicitly handle these special cases.  *  * The balance of the clocks controlled by the CAR are assigned IDs of 160 and  * above.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_TEGRA30_CAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_TEGRA30_CAR_H
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CPU
value|0
end_define

begin_comment
comment|/* 1 */
end_comment

begin_comment
comment|/* 2 */
end_comment

begin_comment
comment|/* 3 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_RTC
value|4
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_TIMER
value|5
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_UARTA
value|6
end_define

begin_comment
comment|/* 7 (register bit affects uartb and vfir) */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_GPIO
value|8
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SDMMC2
value|9
end_define

begin_comment
comment|/* 10 (register bit affects spdif_in and spdif_out) */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2S1
value|11
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2C1
value|12
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_NDFLASH
value|13
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SDMMC1
value|14
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SDMMC4
value|15
end_define

begin_comment
comment|/* 16 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_PWM
value|17
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2S2
value|18
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_EPP
value|19
end_define

begin_comment
comment|/* 20 (register bit affects vi and vi_sensor) */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_GR2D
value|21
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_USBD
value|22
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_ISP
value|23
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_GR3D
value|24
end_define

begin_comment
comment|/* 25 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_DISP2
value|26
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_DISP1
value|27
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_HOST1X
value|28
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_VCP
value|29
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2S0
value|30
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_COP_CACHE
value|31
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_MC
value|32
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AHBDMA
value|33
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_APBDMA
value|34
end_define

begin_comment
comment|/* 35 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_KBC
value|36
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_STATMON
value|37
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PMC
value|38
end_define

begin_comment
comment|/* 39 (register bit affects fuse and fuse_burn) */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_KFUSE
value|40
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SBC1
value|41
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_NOR
value|42
end_define

begin_comment
comment|/* 43 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_SBC2
value|44
end_define

begin_comment
comment|/* 45 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_SBC3
value|46
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2C5
value|47
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_DSIA
value|48
end_define

begin_comment
comment|/* 49 (register bit affects cve and tvo) */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_MIPI
value|50
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_HDMI
value|51
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CSI
value|52
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_TVDAC
value|53
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2C2
value|54
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_UARTC
value|55
end_define

begin_comment
comment|/* 56 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_EMC
value|57
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_USB2
value|58
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_USB3
value|59
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_MPE
value|60
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_VDE
value|61
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_BSEA
value|62
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_BSEV
value|63
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SPEEDO
value|64
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_UARTD
value|65
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_UARTE
value|66
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2C3
value|67
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SBC4
value|68
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SDMMC3
value|69
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PCIE
value|70
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_OWR
value|71
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AFI
value|72
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CSITE
value|73
end_define

begin_comment
comment|/* 74 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_AVPUCQ
value|75
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_LA
value|76
end_define

begin_comment
comment|/* 77 */
end_comment

begin_comment
comment|/* 78 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_DTV
value|79
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_NDSPEED
value|80
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2CSLOW
value|81
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_DSIB
value|82
end_define

begin_comment
comment|/* 83 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_IRAMA
value|84
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_IRAMB
value|85
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_IRAMC
value|86
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_IRAMD
value|87
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CRAM2
value|88
end_define

begin_comment
comment|/* 89 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO_2X
value|90
end_define

begin_comment
comment|/* a/k/a audio_2x_sync_clk */
end_comment

begin_comment
comment|/* 91 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_CSUS
value|92
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CDEV2
value|93
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CDEV1
value|94
end_define

begin_comment
comment|/* 95 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_CPU_G
value|96
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CPU_LP
value|97
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_GR3D2
value|98
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_MSELECT
value|99
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_TSENSOR
value|100
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2S3
value|101
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2S4
value|102
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2C4
value|103
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SBC5
value|104
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SBC6
value|105
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_D_AUDIO
value|106
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_APBIF
value|107
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_DAM0
value|108
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_DAM1
value|109
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_DAM2
value|110
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_HDA2CODEC_2X
value|111
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_ATOMICS
value|112
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO0_2X
value|113
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO1_2X
value|114
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO2_2X
value|115
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO3_2X
value|116
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO4_2X
value|117
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SPDIF_2X
value|118
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_ACTMON
value|119
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_EXTERN1
value|120
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_EXTERN2
value|121
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_EXTERN3
value|122
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SATA_OOB
value|123
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SATA
value|124
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_HDA
value|125
end_define

begin_comment
comment|/* 126 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_SE
value|127
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_HDA2HDMI
value|128
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SATA_COLD
value|129
end_define

begin_comment
comment|/* 130 */
end_comment

begin_comment
comment|/* 131 */
end_comment

begin_comment
comment|/* 132 */
end_comment

begin_comment
comment|/* 133 */
end_comment

begin_comment
comment|/* 134 */
end_comment

begin_comment
comment|/* 135 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_CEC
value|136
end_define

begin_comment
comment|/* 137 */
end_comment

begin_comment
comment|/* 138 */
end_comment

begin_comment
comment|/* 139 */
end_comment

begin_comment
comment|/* 140 */
end_comment

begin_comment
comment|/* 141 */
end_comment

begin_comment
comment|/* 142 */
end_comment

begin_comment
comment|/* 143 */
end_comment

begin_comment
comment|/* 144 */
end_comment

begin_comment
comment|/* 145 */
end_comment

begin_comment
comment|/* 146 */
end_comment

begin_comment
comment|/* 147 */
end_comment

begin_comment
comment|/* 148 */
end_comment

begin_comment
comment|/* 149 */
end_comment

begin_comment
comment|/* 150 */
end_comment

begin_comment
comment|/* 151 */
end_comment

begin_comment
comment|/* 152 */
end_comment

begin_comment
comment|/* 153 */
end_comment

begin_comment
comment|/* 154 */
end_comment

begin_comment
comment|/* 155 */
end_comment

begin_comment
comment|/* 156 */
end_comment

begin_comment
comment|/* 157 */
end_comment

begin_comment
comment|/* 158 */
end_comment

begin_comment
comment|/* 159 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_UARTB
value|160
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_VFIR
value|161
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SPDIF_IN
value|162
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SPDIF_OUT
value|163
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_VI
value|164
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_VI_SENSOR
value|165
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_FUSE
value|166
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_FUSE_BURN
value|167
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CVE
value|168
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_TVO
value|169
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_32K
value|170
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_M
value|171
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_M_DIV2
value|172
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_M_DIV4
value|173
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_REF
value|174
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_C
value|175
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_C_OUT1
value|176
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_M
value|177
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_M_OUT1
value|178
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_P
value|179
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_P_OUT1
value|180
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_P_OUT2
value|181
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_P_OUT3
value|182
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_P_OUT4
value|183
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_A
value|184
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_A_OUT0
value|185
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_D
value|186
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_D_OUT0
value|187
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_D2
value|188
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_D2_OUT0
value|189
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_U
value|190
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_X
value|191
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_X_OUT0
value|192
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PLL_E
value|193
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SPDIF_IN_SYNC
value|194
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2S0_SYNC
value|195
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2S1_SYNC
value|196
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2S2_SYNC
value|197
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2S3_SYNC
value|198
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_I2S4_SYNC
value|199
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_VIMCLK_SYNC
value|200
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO0
value|201
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO1
value|202
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO2
value|203
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO3
value|204
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO4
value|205
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SPDIF
value|206
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_OUT_1
value|207
end_define

begin_comment
comment|/* (extern1) */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_OUT_2
value|208
end_define

begin_comment
comment|/* (extern2) */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_OUT_3
value|209
end_define

begin_comment
comment|/* (extern3) */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_SCLK
value|210
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_BLINK
value|211
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CCLK_G
value|212
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CCLK_LP
value|213
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_TWD
value|214
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CML0
value|215
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CML1
value|216
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_HCLK
value|217
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_PCLK
value|218
end_define

begin_comment
comment|/* 219 */
end_comment

begin_comment
comment|/* 220 */
end_comment

begin_comment
comment|/* 221 */
end_comment

begin_comment
comment|/* 222 */
end_comment

begin_comment
comment|/* 223 */
end_comment

begin_comment
comment|/* 288 */
end_comment

begin_comment
comment|/* 289 */
end_comment

begin_comment
comment|/* 290 */
end_comment

begin_comment
comment|/* 291 */
end_comment

begin_comment
comment|/* 292 */
end_comment

begin_comment
comment|/* 293 */
end_comment

begin_comment
comment|/* 294 */
end_comment

begin_comment
comment|/* 295 */
end_comment

begin_comment
comment|/* 296 */
end_comment

begin_comment
comment|/* 297 */
end_comment

begin_comment
comment|/* 298 */
end_comment

begin_comment
comment|/* 299 */
end_comment

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_OUT_1_MUX
value|300
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_OUT_2_MUX
value|301
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_OUT_3_MUX
value|302
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO0_MUX
value|303
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO1_MUX
value|304
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO2_MUX
value|305
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO3_MUX
value|306
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_AUDIO4_MUX
value|307
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_SPDIF_MUX
value|308
end_define

begin_define
define|#
directive|define
name|TEGRA30_CLK_CLK_MAX
value|309
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_TEGRA30_CAR_H */
end_comment

end_unit

