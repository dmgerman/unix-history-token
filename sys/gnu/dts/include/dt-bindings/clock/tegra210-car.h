begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for binding nvidia,tegra210-car.  *  * The first 224 clocks are numbered to match the bits in the CAR's CLK_OUT_ENB  * registers. These IDs often match those in the CAR's RST_DEVICES registers,  * but not in all cases. Some bits in CLK_OUT_ENB affect multiple clocks. In  * this case, those clocks are assigned IDs above 224 in order to highlight  * this issue. Implementations that interpret these clock IDs as bit values  * within the CLK_OUT_ENB or RST_DEVICES registers should be careful to  * explicitly handle these special cases.  *  * The balance of the clocks controlled by the CAR are assigned IDs of 224 and  * above.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_TEGRA210_CAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_TEGRA210_CAR_H
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
name|TEGRA210_CLK_ISPB
value|3
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_RTC
value|4
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_TIMER
value|5
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_UARTA
value|6
end_define

begin_comment
comment|/* 7 (register bit affects uartb and vfir) */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_GPIO
value|8
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SDMMC2
value|9
end_define

begin_comment
comment|/* 10 (register bit affects spdif_in and spdif_out) */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2S1
value|11
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2C1
value|12
end_define

begin_comment
comment|/* 13 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_SDMMC1
value|14
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SDMMC4
value|15
end_define

begin_comment
comment|/* 16 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_PWM
value|17
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2S2
value|18
end_define

begin_comment
comment|/* 19 */
end_comment

begin_comment
comment|/* 20 (register bit affects vi and vi_sensor) */
end_comment

begin_comment
comment|/* 21 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_USBD
value|22
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_ISPA
value|23
end_define

begin_comment
comment|/* 24 */
end_comment

begin_comment
comment|/* 25 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_DISP2
value|26
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DISP1
value|27
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_HOST1X
value|28
end_define

begin_comment
comment|/* 29 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2S0
value|30
end_define

begin_comment
comment|/* 31 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_MC
value|32
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AHBDMA
value|33
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_APBDMA
value|34
end_define

begin_comment
comment|/* 35 */
end_comment

begin_comment
comment|/* 36 */
end_comment

begin_comment
comment|/* 37 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_PMC
value|38
end_define

begin_comment
comment|/* 39 (register bit affects fuse and fuse_burn) */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_KFUSE
value|40
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SBC1
value|41
end_define

begin_comment
comment|/* 42 */
end_comment

begin_comment
comment|/* 43 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_SBC2
value|44
end_define

begin_comment
comment|/* 45 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_SBC3
value|46
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2C5
value|47
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DSIA
value|48
end_define

begin_comment
comment|/* 49 */
end_comment

begin_comment
comment|/* 50 */
end_comment

begin_comment
comment|/* 51 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_CSI
value|52
end_define

begin_comment
comment|/* 53 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2C2
value|54
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_UARTC
value|55
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_MIPI_CAL
value|56
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_EMC
value|57
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_USB2
value|58
end_define

begin_comment
comment|/* 59 */
end_comment

begin_comment
comment|/* 60 */
end_comment

begin_comment
comment|/* 61 */
end_comment

begin_comment
comment|/* 62 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_BSEV
value|63
end_define

begin_comment
comment|/* 64 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_UARTD
value|65
end_define

begin_comment
comment|/* 66 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2C3
value|67
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SBC4
value|68
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SDMMC3
value|69
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PCIE
value|70
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_OWR
value|71
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AFI
value|72
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CSITE
value|73
end_define

begin_comment
comment|/* 74 */
end_comment

begin_comment
comment|/* 75 */
end_comment

begin_comment
comment|/* 76 */
end_comment

begin_comment
comment|/* 77 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_SOC_THERM
value|78
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DTV
value|79
end_define

begin_comment
comment|/* 80 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2CSLOW
value|81
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DSIB
value|82
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_TSEC
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
name|TEGRA210_CLK_XUSB_HOST
value|89
end_define

begin_comment
comment|/* 90 */
end_comment

begin_comment
comment|/* 91 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_CSUS
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
name|TEGRA210_CLK_MSELECT
value|99
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_TSENSOR
value|100
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2S3
value|101
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2S4
value|102
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2C4
value|103
end_define

begin_comment
comment|/* 104 */
end_comment

begin_comment
comment|/* 105 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_D_AUDIO
value|106
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_APB2APE
value|107
end_define

begin_comment
comment|/* 108 */
end_comment

begin_comment
comment|/* 109 */
end_comment

begin_comment
comment|/* 110 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_HDA2CODEC_2X
value|111
end_define

begin_comment
comment|/* 112 */
end_comment

begin_comment
comment|/* 113 */
end_comment

begin_comment
comment|/* 114 */
end_comment

begin_comment
comment|/* 115 */
end_comment

begin_comment
comment|/* 116 */
end_comment

begin_comment
comment|/* 117 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_SPDIF_2X
value|118
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_ACTMON
value|119
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_EXTERN1
value|120
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_EXTERN2
value|121
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_EXTERN3
value|122
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SATA_OOB
value|123
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SATA
value|124
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_HDA
value|125
end_define

begin_comment
comment|/* 126 */
end_comment

begin_comment
comment|/* 127 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_HDA2HDMI
value|128
end_define

begin_comment
comment|/* 129 */
end_comment

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
name|TEGRA210_CLK_CEC
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
comment|/* (bit affects xusb_falcon_src, xusb_fs_src, xusb_host_src and xusb_ss_src) */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_GATE
value|143
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CILAB
value|144
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CILCD
value|145
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CILE
value|146
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DSIALP
value|147
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DSIBLP
value|148
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_ENTROPY
value|149
end_define

begin_comment
comment|/* 150 */
end_comment

begin_comment
comment|/* 151 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_DP2
value|152
end_define

begin_comment
comment|/* 153 */
end_comment

begin_comment
comment|/* 154 */
end_comment

begin_comment
comment|/* 155 (bit affects dfll_ref and dfll_soc) */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_SS
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

begin_define
define|#
directive|define
name|TEGRA210_CLK_DMIC1
value|161
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DMIC2
value|162
end_define

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
name|TEGRA210_CLK_I2C6
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
name|TEGRA210_CLK_VIM2_CLK
value|171
end_define

begin_comment
comment|/* 172 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_MIPIBIF
value|173
end_define

begin_comment
comment|/* 174 */
end_comment

begin_comment
comment|/* 175 */
end_comment

begin_comment
comment|/* 176 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK72MHZ
value|177
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_VIC03
value|178
end_define

begin_comment
comment|/* 179 */
end_comment

begin_comment
comment|/* 180 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_DPAUX
value|181
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SOR0
value|182
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SOR1
value|183
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_GPU
value|184
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DBGAPB
value|185
end_define

begin_comment
comment|/* 186 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_P_OUT_ADSP
value|187
end_define

begin_comment
comment|/* 188 ((bit affects pll_a_out_adsp and pll_a_out0_out_adsp)*/
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_G_REF
value|189
end_define

begin_comment
comment|/* 190 */
end_comment

begin_comment
comment|/* 191 */
end_comment

begin_comment
comment|/* 192 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_SDMMC_LEGACY
value|193
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_NVDEC
value|194
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_NVJPG
value|195
end_define

begin_comment
comment|/* 196 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_DMIC3
value|197
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_APE
value|198
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_ADSP
value|199
end_define

begin_comment
comment|/* 200 */
end_comment

begin_comment
comment|/* 201 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_MAUD
value|202
end_define

begin_comment
comment|/* 203 */
end_comment

begin_comment
comment|/* 204 */
end_comment

begin_comment
comment|/* 205 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_TSECB
value|206
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DPAUX1
value|207
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_VI_I2C
value|208
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_HSIC_TRK
value|209
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_USB2_TRK
value|210
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_QSPI
value|211
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_UARTAPE
value|212
end_define

begin_comment
comment|/* 213 */
end_comment

begin_comment
comment|/* 214 */
end_comment

begin_comment
comment|/* 215 */
end_comment

begin_comment
comment|/* 216 */
end_comment

begin_comment
comment|/* 217 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_ADSP_NEON
value|218
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_NVENC
value|219
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_IQC2
value|220
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_IQC1
value|221
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SOR_SAFE
value|222
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_P_OUT_CPU
value|223
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_UARTB
value|224
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_VFIR
value|225
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SPDIF_IN
value|226
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SPDIF_OUT
value|227
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_VI
value|228
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_VI_SENSOR
value|229
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_FUSE
value|230
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_FUSE_BURN
value|231
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_32K
value|232
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_M
value|233
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_M_DIV2
value|234
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_M_DIV4
value|235
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_REF
value|236
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_C
value|237
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_C_OUT1
value|238
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_C2
value|239
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_C3
value|240
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_M
value|241
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_M_OUT1
value|242
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_P
value|243
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_P_OUT1
value|244
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_P_OUT2
value|245
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_P_OUT3
value|246
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_P_OUT4
value|247
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_A
value|248
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_A_OUT0
value|249
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_D
value|250
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_D_OUT0
value|251
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_D2
value|252
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_D2_OUT0
value|253
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_U
value|254
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_U_480M
value|255
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_U_60M
value|256
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_U_48M
value|257
end_define

begin_comment
comment|/* 258 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_X
value|259
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_X_OUT0
value|260
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_RE_VCO
value|261
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_RE_OUT
value|262
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_E
value|263
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SPDIF_IN_SYNC
value|264
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2S0_SYNC
value|265
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2S1_SYNC
value|266
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2S2_SYNC
value|267
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2S3_SYNC
value|268
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_I2S4_SYNC
value|269
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_VIMCLK_SYNC
value|270
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AUDIO0
value|271
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AUDIO1
value|272
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AUDIO2
value|273
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AUDIO3
value|274
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AUDIO4
value|275
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SPDIF
value|276
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_OUT_1
value|277
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_OUT_2
value|278
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_OUT_3
value|279
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_BLINK
value|280
end_define

begin_comment
comment|/* 281 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_SOR1_SRC
value|282
end_define

begin_comment
comment|/* 283 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_HOST_SRC
value|284
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_FALCON_SRC
value|285
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_FS_SRC
value|286
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_SS_SRC
value|287
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_DEV_SRC
value|288
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_DEV
value|289
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_HS_SRC
value|290
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SCLK
value|291
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_HCLK
value|292
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PCLK
value|293
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CCLK_G
value|294
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CCLK_LP
value|295
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DFLL_REF
value|296
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DFLL_SOC
value|297
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_VI_SENSOR2
value|298
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_P_OUT5
value|299
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CML0
value|300
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CML1
value|301
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_C4
value|302
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_DP
value|303
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_E_MUX
value|304
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_MB
value|305
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_A1
value|306
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_D_DSI_OUT
value|307
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_C4_OUT0
value|308
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_C4_OUT1
value|309
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_C4_OUT2
value|310
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_C4_OUT3
value|311
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_U_OUT
value|312
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_U_OUT1
value|313
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_U_OUT2
value|314
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_USB2_HSIC_TRK
value|315
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_P_OUT_HSIO
value|316
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_P_OUT_XUSB
value|317
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_SSP_SRC
value|318
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_RE_OUT1
value|319
end_define

begin_comment
comment|/* 320 */
end_comment

begin_comment
comment|/* 321 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_ISP
value|322
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_A_OUT_ADSP
value|323
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_A_OUT0_OUT_ADSP
value|324
end_define

begin_comment
comment|/* 325 */
end_comment

begin_comment
comment|/* 326 */
end_comment

begin_comment
comment|/* 327 */
end_comment

begin_comment
comment|/* 328 */
end_comment

begin_comment
comment|/* 329 */
end_comment

begin_comment
comment|/* 330 */
end_comment

begin_comment
comment|/* 331 */
end_comment

begin_comment
comment|/* 332 */
end_comment

begin_comment
comment|/* 333 */
end_comment

begin_comment
comment|/* 334 */
end_comment

begin_comment
comment|/* 335 */
end_comment

begin_comment
comment|/* 336 */
end_comment

begin_comment
comment|/* 337 */
end_comment

begin_comment
comment|/* 338 */
end_comment

begin_comment
comment|/* 339 */
end_comment

begin_comment
comment|/* 340 */
end_comment

begin_comment
comment|/* 341 */
end_comment

begin_comment
comment|/* 342 */
end_comment

begin_comment
comment|/* 343 */
end_comment

begin_comment
comment|/* 344 */
end_comment

begin_comment
comment|/* 345 */
end_comment

begin_comment
comment|/* 346 */
end_comment

begin_comment
comment|/* 347 */
end_comment

begin_comment
comment|/* 348 */
end_comment

begin_comment
comment|/* 349 */
end_comment

begin_define
define|#
directive|define
name|TEGRA210_CLK_AUDIO0_MUX
value|350
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AUDIO1_MUX
value|351
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AUDIO2_MUX
value|352
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AUDIO3_MUX
value|353
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_AUDIO4_MUX
value|354
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SPDIF_MUX
value|355
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_OUT_1_MUX
value|356
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_OUT_2_MUX
value|357
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_OUT_3_MUX
value|358
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DSIA_MUX
value|359
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DSIB_MUX
value|360
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SOR0_LVDS
value|361
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_XUSB_SS_DIV2
value|362
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_M_UD
value|363
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_PLL_C_UD
value|364
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_SCLK_MUX
value|365
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_ACLK
value|370
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DMIC1_SYNC_CLK
value|388
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DMIC1_SYNC_CLK_MUX
value|389
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DMIC2_SYNC_CLK
value|390
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DMIC2_SYNC_CLK_MUX
value|391
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DMIC3_SYNC_CLK
value|392
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_DMIC3_SYNC_CLK_MUX
value|393
end_define

begin_define
define|#
directive|define
name|TEGRA210_CLK_CLK_MAX
value|394
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_TEGRA210_CAR_H */
end_comment

end_unit

