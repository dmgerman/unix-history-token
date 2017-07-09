begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for binding nvidia,tegra124-car or  * nvidia,tegra132-car.  *  * The first 192 clocks are numbered to match the bits in the CAR's CLK_OUT_ENB  * registers. These IDs often match those in the CAR's RST_DEVICES registers,  * but not in all cases. Some bits in CLK_OUT_ENB affect multiple clocks. In  * this case, those clocks are assigned IDs above 185 in order to highlight  * this issue. Implementations that interpret these clock IDs as bit values  * within the CLK_OUT_ENB or RST_DEVICES registers should be careful to  * explicitly handle these special cases.  *  * The balance of the clocks controlled by the CAR are assigned IDs of 185 and  * above.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_TEGRA124_CAR_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_TEGRA124_CAR_COMMON_H
end_define

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* 1 */
end_comment

begin_comment
comment|/* 2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_ISPB
value|3
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_RTC
value|4
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_TIMER
value|5
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_UARTA
value|6
end_define

begin_comment
comment|/* 7 (register bit affects uartb and vfir) */
end_comment

begin_comment
comment|/* 8 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_SDMMC2
value|9
end_define

begin_comment
comment|/* 10 (register bit affects spdif_in and spdif_out) */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2S1
value|11
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2C1
value|12
end_define

begin_comment
comment|/* 13 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_SDMMC1
value|14
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SDMMC4
value|15
end_define

begin_comment
comment|/* 16 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_PWM
value|17
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2S2
value|18
end_define

begin_comment
comment|/* 20 (register bit affects vi and vi_sensor) */
end_comment

begin_comment
comment|/* 21 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_USBD
value|22
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_ISP
value|23
end_define

begin_comment
comment|/* 26 */
end_comment

begin_comment
comment|/* 25 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_DISP2
value|26
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DISP1
value|27
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_HOST1X
value|28
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_VCP
value|29
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2S0
value|30
end_define

begin_comment
comment|/* 31 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_MC
value|32
end_define

begin_comment
comment|/* 33 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_APBDMA
value|34
end_define

begin_comment
comment|/* 35 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_KBC
value|36
end_define

begin_comment
comment|/* 37 */
end_comment

begin_comment
comment|/* 38 */
end_comment

begin_comment
comment|/* 39 (register bit affects fuse and fuse_burn) */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_KFUSE
value|40
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SBC1
value|41
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_NOR
value|42
end_define

begin_comment
comment|/* 43 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_SBC2
value|44
end_define

begin_comment
comment|/* 45 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_SBC3
value|46
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2C5
value|47
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DSIA
value|48
end_define

begin_comment
comment|/* 49 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_MIPI
value|50
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_HDMI
value|51
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CSI
value|52
end_define

begin_comment
comment|/* 53 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2C2
value|54
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_UARTC
value|55
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_MIPI_CAL
value|56
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_EMC
value|57
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_USB2
value|58
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_USB3
value|59
end_define

begin_comment
comment|/* 60 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_VDE
value|61
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_BSEA
value|62
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_BSEV
value|63
end_define

begin_comment
comment|/* 64 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_UARTD
value|65
end_define

begin_comment
comment|/* 66 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2C3
value|67
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SBC4
value|68
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SDMMC3
value|69
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PCIE
value|70
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_OWR
value|71
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AFI
value|72
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CSITE
value|73
end_define

begin_comment
comment|/* 74 */
end_comment

begin_comment
comment|/* 75 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_LA
value|76
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_TRACE
value|77
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SOC_THERM
value|78
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DTV
value|79
end_define

begin_comment
comment|/* 80 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2CSLOW
value|81
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DSIB
value|82
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_TSEC
value|83
end_define

begin_comment
comment|/* 84 */
end_comment

begin_comment
comment|/* 85 */
end_comment

begin_comment
comment|/* 86 */
end_comment

begin_comment
comment|/* 87 */
end_comment

begin_comment
comment|/* 88 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_XUSB_HOST
value|89
end_define

begin_comment
comment|/* 90 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_MSENC
value|91
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CSUS
value|92
end_define

begin_comment
comment|/* 93 */
end_comment

begin_comment
comment|/* 94 */
end_comment

begin_comment
comment|/* 95 (bit affects xusb_dev and xusb_dev_src) */
end_comment

begin_comment
comment|/* 96 */
end_comment

begin_comment
comment|/* 97 */
end_comment

begin_comment
comment|/* 98 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_MSELECT
value|99
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_TSENSOR
value|100
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2S3
value|101
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2S4
value|102
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2C4
value|103
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SBC5
value|104
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SBC6
value|105
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_D_AUDIO
value|106
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_APBIF
value|107
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DAM0
value|108
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DAM1
value|109
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DAM2
value|110
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_HDA2CODEC_2X
value|111
end_define

begin_comment
comment|/* 112 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO0_2X
value|113
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO1_2X
value|114
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO2_2X
value|115
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO3_2X
value|116
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO4_2X
value|117
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SPDIF_2X
value|118
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_ACTMON
value|119
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_EXTERN1
value|120
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_EXTERN2
value|121
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_EXTERN3
value|122
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SATA_OOB
value|123
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SATA
value|124
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_HDA
value|125
end_define

begin_comment
comment|/* 126 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_SE
value|127
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_HDA2HDMI
value|128
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SATA_COLD
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
name|TEGRA124_CLK_CEC
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
comment|/* 143 (bit affects xusb_falcon_src, xusb_fs_src, */
end_comment

begin_comment
comment|/*      xusb_host_src and xusb_ss_src) */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_CILAB
value|144
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CILCD
value|145
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CILE
value|146
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DSIALP
value|147
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DSIBLP
value|148
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_ENTROPY
value|149
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DDS
value|150
end_define

begin_comment
comment|/* 151 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_DP2
value|152
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AMX
value|153
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_ADX
value|154
end_define

begin_comment
comment|/* 155 (bit affects dfll_ref and dfll_soc) */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_XUSB_SS
value|156
end_define

begin_comment
comment|/* 157 */
end_comment

begin_comment
comment|/* 158 */
end_comment

begin_comment
comment|/* 159 */
end_comment

begin_comment
comment|/* 160 */
end_comment

begin_comment
comment|/* 161 */
end_comment

begin_comment
comment|/* 162 */
end_comment

begin_comment
comment|/* 163 */
end_comment

begin_comment
comment|/* 164 */
end_comment

begin_comment
comment|/* 165 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2C6
value|166
end_define

begin_comment
comment|/* 167 */
end_comment

begin_comment
comment|/* 168 */
end_comment

begin_comment
comment|/* 169 */
end_comment

begin_comment
comment|/* 170 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_VIM2_CLK
value|171
end_define

begin_comment
comment|/* 172 */
end_comment

begin_comment
comment|/* 173 */
end_comment

begin_comment
comment|/* 174 */
end_comment

begin_comment
comment|/* 175 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_HDMI_AUDIO
value|176
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK72MHZ
value|177
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_VIC03
value|178
end_define

begin_comment
comment|/* 179 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_ADX1
value|180
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DPAUX
value|181
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SOR0
value|182
end_define

begin_comment
comment|/* 183 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_GPU
value|184
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AMX1
value|185
end_define

begin_comment
comment|/* 186 */
end_comment

begin_comment
comment|/* 187 */
end_comment

begin_comment
comment|/* 188 */
end_comment

begin_comment
comment|/* 189 */
end_comment

begin_comment
comment|/* 190 */
end_comment

begin_comment
comment|/* 191 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_UARTB
value|192
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_VFIR
value|193
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SPDIF_IN
value|194
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SPDIF_OUT
value|195
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_VI
value|196
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_VI_SENSOR
value|197
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_FUSE
value|198
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_FUSE_BURN
value|199
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_32K
value|200
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_M
value|201
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_M_DIV2
value|202
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_M_DIV4
value|203
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_REF
value|204
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_C
value|205
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_C_OUT1
value|206
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_C2
value|207
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_C3
value|208
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_M
value|209
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_M_OUT1
value|210
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_P
value|211
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_P_OUT1
value|212
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_P_OUT2
value|213
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_P_OUT3
value|214
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_P_OUT4
value|215
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_A
value|216
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_A_OUT0
value|217
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_D
value|218
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_D_OUT0
value|219
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_D2
value|220
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_D2_OUT0
value|221
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_U
value|222
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_U_480M
value|223
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_U_60M
value|224
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_U_48M
value|225
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_U_12M
value|226
end_define

begin_comment
comment|/* 227 */
end_comment

begin_comment
comment|/* 228 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_RE_VCO
value|229
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_RE_OUT
value|230
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_E
value|231
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SPDIF_IN_SYNC
value|232
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2S0_SYNC
value|233
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2S1_SYNC
value|234
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2S2_SYNC
value|235
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2S3_SYNC
value|236
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_I2S4_SYNC
value|237
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_VIMCLK_SYNC
value|238
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO0
value|239
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO1
value|240
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO2
value|241
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO3
value|242
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO4
value|243
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SPDIF
value|244
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_OUT_1
value|245
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_OUT_2
value|246
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_OUT_3
value|247
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_BLINK
value|248
end_define

begin_comment
comment|/* 249 */
end_comment

begin_comment
comment|/* 250 */
end_comment

begin_comment
comment|/* 251 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_XUSB_HOST_SRC
value|252
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_XUSB_FALCON_SRC
value|253
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_XUSB_FS_SRC
value|254
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_XUSB_SS_SRC
value|255
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_XUSB_DEV_SRC
value|256
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_XUSB_DEV
value|257
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_XUSB_HS_SRC
value|258
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SCLK
value|259
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_HCLK
value|260
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PCLK
value|261
end_define

begin_comment
comment|/* 262 */
end_comment

begin_comment
comment|/* 263 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_DFLL_REF
value|264
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_DFLL_SOC
value|265
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_VI_SENSOR2
value|266
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_P_OUT5
value|267
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CML0
value|268
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CML1
value|269
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_C4
value|270
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_DP
value|271
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_E_MUX
value|272
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_D_DSI_OUT
value|273
end_define

begin_comment
comment|/* 274 */
end_comment

begin_comment
comment|/* 275 */
end_comment

begin_comment
comment|/* 276 */
end_comment

begin_comment
comment|/* 277 */
end_comment

begin_comment
comment|/* 278 */
end_comment

begin_comment
comment|/* 279 */
end_comment

begin_comment
comment|/* 280 */
end_comment

begin_comment
comment|/* 281 */
end_comment

begin_comment
comment|/* 282 */
end_comment

begin_comment
comment|/* 283 */
end_comment

begin_comment
comment|/* 284 */
end_comment

begin_comment
comment|/* 285 */
end_comment

begin_comment
comment|/* 286 */
end_comment

begin_comment
comment|/* 287 */
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
name|TEGRA124_CLK_AUDIO0_MUX
value|300
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO1_MUX
value|301
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO2_MUX
value|302
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO3_MUX
value|303
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_AUDIO4_MUX
value|304
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_SPDIF_MUX
value|305
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_OUT_1_MUX
value|306
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_OUT_2_MUX
value|307
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_OUT_3_MUX
value|308
end_define

begin_comment
comment|/* 309 */
end_comment

begin_comment
comment|/* 310 */
end_comment

begin_define
define|#
directive|define
name|TEGRA124_CLK_SOR0_LVDS
value|311
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_XUSB_SS_DIV2
value|312
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_M_UD
value|313
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_C_UD
value|314
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_TEGRA124_CAR_COMMON_H */
end_comment

end_unit

