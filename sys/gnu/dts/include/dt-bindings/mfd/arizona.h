begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Device Tree defines for Arizona devices  *  * Copyright 2015 Cirrus Logic Inc.  *  * Author: Charles Keepax<ckeepax@opensource.wolfsonmicro.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_MFD_ARIZONA_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_MFD_ARIZONA_H
end_define

begin_comment
comment|/* GPIO Function Definitions */
end_comment

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_TXLRCLK
value|0x00
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_GPIO
value|0x01
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_IRQ1
value|0x02
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_IRQ2
value|0x03
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_OPCLK
value|0x04
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_FLL1_OUT
value|0x05
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_FLL2_OUT
value|0x06
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_PWM1
value|0x08
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_PWM2
value|0x09
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_SYSCLK_UNDERCLOCKED
value|0x0A
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_ASYNCCLK_UNDERCLOCKED
value|0x0B
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_FLL1_LOCK
value|0x0C
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_FLL2_LOCK
value|0x0D
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_FLL1_CLOCK_OK
value|0x0F
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_FLL2_CLOCK_OK
value|0x10
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_HEADPHONE_DET
value|0x12
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_MIC_DET
value|0x13
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_WSEQ_STATUS
value|0x15
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_CIF_ADDRESS_ERROR
value|0x16
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_ASRC1_LOCK
value|0x1A
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_ASRC2_LOCK
value|0x1B
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_ASRC_CONFIG_ERROR
value|0x1C
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DRC1_SIGNAL_DETECT
value|0x1D
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DRC1_ANTICLIP
value|0x1E
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DRC1_DECAY
value|0x1F
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DRC1_NOISE
value|0x20
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DRC1_QUICK_RELEASE
value|0x21
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DRC2_SIGNAL_DETECT
value|0x22
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DRC2_ANTICLIP
value|0x23
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DRC2_DECAY
value|0x24
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DRC2_NOISE
value|0x25
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DRC2_QUICK_RELEASE
value|0x26
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_MIXER_DROPPED_SAMPLE
value|0x27
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_AIF1_CONFIG_ERROR
value|0x28
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_AIF2_CONFIG_ERROR
value|0x29
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_AIF3_CONFIG_ERROR
value|0x2A
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_SPK_TEMP_SHUTDOWN
value|0x2B
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_SPK_TEMP_WARNING
value|0x2C
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_UNDERCLOCKED
value|0x2D
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_OVERCLOCKED
value|0x2E
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DSP_IRQ1
value|0x35
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DSP_IRQ2
value|0x36
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_ASYNC_OPCLK
value|0x3D
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_BOOT_DONE
value|0x44
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_DSP1_RAM_READY
value|0x45
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_SYSCLK_ENA_STATUS
value|0x4B
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_FN_ASYNCCLK_ENA_STATUS
value|0x4C
end_define

begin_comment
comment|/* GPIO Configuration Bits */
end_comment

begin_define
define|#
directive|define
name|ARIZONA_GPN_DIR
value|0x8000
end_define

begin_define
define|#
directive|define
name|ARIZONA_GPN_PU
value|0x4000
end_define

begin_define
define|#
directive|define
name|ARIZONA_GPN_PD
value|0x2000
end_define

begin_define
define|#
directive|define
name|ARIZONA_GPN_LVL
value|0x0800
end_define

begin_define
define|#
directive|define
name|ARIZONA_GPN_POL
value|0x0400
end_define

begin_define
define|#
directive|define
name|ARIZONA_GPN_OP_CFG
value|0x0200
end_define

begin_define
define|#
directive|define
name|ARIZONA_GPN_DB
value|0x0100
end_define

begin_comment
comment|/* Provide some defines for the most common configs */
end_comment

begin_define
define|#
directive|define
name|ARIZONA_GP_DEFAULT
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_OUTPUT
value|(ARIZONA_GP_FN_GPIO)
end_define

begin_define
define|#
directive|define
name|ARIZONA_GP_INPUT
value|(ARIZONA_GP_FN_GPIO | \ 					ARIZONA_GPN_DIR)
end_define

begin_define
define|#
directive|define
name|ARIZONA_32KZ_MCLK1
value|1
end_define

begin_define
define|#
directive|define
name|ARIZONA_32KZ_MCLK2
value|2
end_define

begin_define
define|#
directive|define
name|ARIZONA_32KZ_NONE
value|3
end_define

begin_define
define|#
directive|define
name|ARIZONA_DMIC_MICVDD
value|0
end_define

begin_define
define|#
directive|define
name|ARIZONA_DMIC_MICBIAS1
value|1
end_define

begin_define
define|#
directive|define
name|ARIZONA_DMIC_MICBIAS2
value|2
end_define

begin_define
define|#
directive|define
name|ARIZONA_DMIC_MICBIAS3
value|3
end_define

begin_define
define|#
directive|define
name|ARIZONA_INMODE_DIFF
value|0
end_define

begin_define
define|#
directive|define
name|ARIZONA_INMODE_SE
value|1
end_define

begin_define
define|#
directive|define
name|ARIZONA_INMODE_DMIC
value|2
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_CONTINUOUS
value|0
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_250US
value|1
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_500US
value|2
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_1MS
value|3
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_2MS
value|4
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_4MS
value|5
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_8MS
value|6
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_16MS
value|7
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_32MS
value|8
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_64MS
value|9
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_128MS
value|10
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_256MS
value|11
end_define

begin_define
define|#
directive|define
name|ARIZONA_MICD_TIME_512MS
value|12
end_define

begin_define
define|#
directive|define
name|ARIZONA_ACCDET_MODE_MIC
value|0
end_define

begin_define
define|#
directive|define
name|ARIZONA_ACCDET_MODE_HPL
value|1
end_define

begin_define
define|#
directive|define
name|ARIZONA_ACCDET_MODE_HPR
value|2
end_define

begin_define
define|#
directive|define
name|ARIZONA_ACCDET_MODE_HPM
value|4
end_define

begin_define
define|#
directive|define
name|ARIZONA_ACCDET_MODE_ADC
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

