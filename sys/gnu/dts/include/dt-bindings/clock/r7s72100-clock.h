begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2014 Renesas Solutions Corp.  * Copyright (C) 2014 Wolfram Sang, Sang Engineering<wsa@sang-engineering.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; version 2 of the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_R7S72100_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_R7S72100_H__
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_PLL
value|0
end_define

begin_comment
comment|/* MSTP2 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_CORESIGHT
value|0
end_define

begin_comment
comment|/* MSTP3 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_IEBUS
value|7
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_IRDA
value|6
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_LIN0
value|5
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_LIN1
value|4
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_MTU2
value|3
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_CAN
value|2
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_ADCPWR
value|1
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_PWM
value|0
end_define

begin_comment
comment|/* MSTP4 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_SCIF0
value|7
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SCIF1
value|6
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SCIF2
value|5
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SCIF3
value|4
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SCIF4
value|3
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SCIF5
value|2
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SCIF6
value|1
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SCIF7
value|0
end_define

begin_comment
comment|/* MSTP5 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_SCI0
value|7
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SCI1
value|6
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SG0
value|5
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SG1
value|4
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SG2
value|3
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SG3
value|2
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_OSTM0
value|1
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_OSTM1
value|0
end_define

begin_comment
comment|/* MSTP6 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_ADC
value|7
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_CEU
value|6
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_DOC0
value|5
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_DOC1
value|4
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_DRC0
value|3
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_DRC1
value|2
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_JCU
value|1
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_RTC
value|0
end_define

begin_comment
comment|/* MSTP7 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_VDEC0
value|7
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_VDEC1
value|6
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_ETHER
value|4
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_NAND
value|3
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_USB0
value|1
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_USB1
value|0
end_define

begin_comment
comment|/* MSTP8 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_IMR0
value|7
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_IMR1
value|6
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_IMRDISP
value|5
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_MMCIF
value|4
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_MLB
value|3
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_ETHAVB
value|2
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SCUX
value|1
end_define

begin_comment
comment|/* MSTP9 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_I2C0
value|7
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_I2C1
value|6
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_I2C2
value|5
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_I2C3
value|4
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SPIBSC0
value|3
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SPIBSC1
value|2
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_VDC50
value|1
end_define

begin_comment
comment|/* and LVDS */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_VDC51
value|0
end_define

begin_comment
comment|/* MSTP10 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_SPI0
value|7
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SPI1
value|6
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SPI2
value|5
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SPI3
value|4
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SPI4
value|3
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_CDROM
value|2
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SPDIF
value|1
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_RGPVG2
value|0
end_define

begin_comment
comment|/* MSTP11 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_SSI0
value|5
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SSI1
value|4
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SSI2
value|3
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SSI3
value|2
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SSI4
value|1
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SSI5
value|0
end_define

begin_comment
comment|/* MSTP12 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_SDHI00
value|3
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SDHI01
value|2
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SDHI10
value|1
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_SDHI11
value|0
end_define

begin_comment
comment|/* MSTP13 */
end_comment

begin_define
define|#
directive|define
name|R7S72100_CLK_PIX1
value|2
end_define

begin_define
define|#
directive|define
name|R7S72100_CLK_PIX0
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_R7S72100_H__ */
end_comment

end_unit

