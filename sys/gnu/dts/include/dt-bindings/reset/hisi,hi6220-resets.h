begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/**  * This header provides index for the reset controller  * based on hi6220 SoC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_CONTROLLER_HI6220
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_CONTROLLER_HI6220
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTDIS0_MMC0
value|0x000
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTDIS0_MMC1
value|0x001
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTDIS0_MMC2
value|0x002
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTDIS0_NANDC
value|0x003
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTDIS0_USBOTG_BUS
value|0x004
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTDIS0_POR_PICOPHY
value|0x005
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTDIS0_USBOTG
value|0x006
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTDIS0_USBOTG_32K
value|0x007
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTDIS1_HIFI
value|0x100
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTDIS1_DIGACODEC
value|0x105
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN2_IPF
value|0x200
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN2_SOCP
value|0x201
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN2_DMAC
value|0x202
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN2_SECENG
value|0x203
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN2_ABB
value|0x204
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN2_HPM0
value|0x205
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN2_HPM1
value|0x206
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN2_HPM2
value|0x207
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN2_HPM3
value|0x208
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_CSSYS
value|0x300
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_I2C0
value|0x301
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_I2C1
value|0x302
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_I2C2
value|0x303
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_I2C3
value|0x304
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_UART1
value|0x305
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_UART2
value|0x306
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_UART3
value|0x307
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_UART4
value|0x308
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_SSP
value|0x309
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_PWM
value|0x30a
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_BLPWM
value|0x30b
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_TSENSOR
value|0x30c
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_DAPB
value|0x312
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_HKADC
value|0x313
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_CODEC_SSI
value|0x314
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN3_PMUSSI1
value|0x316
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_RS0
value|0x400
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_RS2
value|0x401
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_RS3
value|0x402
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_MS0
value|0x403
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_MS2
value|0x405
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_XG2RAM0
value|0x406
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_X2SRAM_TZMA
value|0x407
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_SRAM
value|0x408
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_HARQ
value|0x40a
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_DDRC
value|0x40c
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_DDRC_APB
value|0x40d
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_DDRPACK_APB
value|0x40e
end_define

begin_define
define|#
directive|define
name|PERIPH_RSTEN8_DDRT
value|0x411
end_define

begin_define
define|#
directive|define
name|PERIPH_RSDIST9_CARM_DAP
value|0x500
end_define

begin_define
define|#
directive|define
name|PERIPH_RSDIST9_CARM_ATB
value|0x501
end_define

begin_define
define|#
directive|define
name|PERIPH_RSDIST9_CARM_LBUS
value|0x502
end_define

begin_define
define|#
directive|define
name|PERIPH_RSDIST9_CARM_POR
value|0x503
end_define

begin_define
define|#
directive|define
name|PERIPH_RSDIST9_CARM_CORE
value|0x504
end_define

begin_define
define|#
directive|define
name|PERIPH_RSDIST9_CARM_DBG
value|0x505
end_define

begin_define
define|#
directive|define
name|PERIPH_RSDIST9_CARM_L2
value|0x506
end_define

begin_define
define|#
directive|define
name|PERIPH_RSDIST9_CARM_SOCDBG
value|0x507
end_define

begin_define
define|#
directive|define
name|PERIPH_RSDIST9_CARM_ETM
value|0x508
end_define

begin_define
define|#
directive|define
name|MEDIA_G3D
value|0
end_define

begin_define
define|#
directive|define
name|MEDIA_CODEC_VPU
value|2
end_define

begin_define
define|#
directive|define
name|MEDIA_CODEC_JPEG
value|3
end_define

begin_define
define|#
directive|define
name|MEDIA_ISP
value|4
end_define

begin_define
define|#
directive|define
name|MEDIA_ADE
value|5
end_define

begin_define
define|#
directive|define
name|MEDIA_MMU
value|6
end_define

begin_define
define|#
directive|define
name|MEDIA_XG2RAM1
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_DT_BINDINGS_RESET_CONTROLLER_HI6220*/
end_comment

end_unit

