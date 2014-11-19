begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Tomasz Figa<tomasz.figa@gmail.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This header provides constants for Samsung audio subsystem  * clock controller.  *  * The constants defined in this header are being used in dts  * and s5pv210 audss driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_S5PV210_AUDSS_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_S5PV210_AUDSS_H
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_AUDSS
value|0
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_I2S_A
value|1
end_define

begin_define
define|#
directive|define
name|CLK_DOUT_AUD_BUS
value|2
end_define

begin_define
define|#
directive|define
name|CLK_DOUT_I2S_A
value|3
end_define

begin_define
define|#
directive|define
name|CLK_I2S
value|4
end_define

begin_define
define|#
directive|define
name|CLK_HCLK_I2S
value|5
end_define

begin_define
define|#
directive|define
name|CLK_HCLK_UART
value|6
end_define

begin_define
define|#
directive|define
name|CLK_HCLK_HWA
value|7
end_define

begin_define
define|#
directive|define
name|CLK_HCLK_DMA
value|8
end_define

begin_define
define|#
directive|define
name|CLK_HCLK_BUF
value|9
end_define

begin_define
define|#
directive|define
name|CLK_HCLK_RP
value|10
end_define

begin_define
define|#
directive|define
name|AUDSS_MAX_CLKS
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

