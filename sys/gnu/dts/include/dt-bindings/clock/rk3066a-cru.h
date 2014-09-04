begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 MundoReader S.L.  * Author: Heiko Stuebner<heiko@sntech.de>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_include
include|#
directive|include
file|<dt-bindings/clock/rk3188-cru-common.h>
end_include

begin_comment
comment|/* soft-reset indices */
end_comment

begin_define
define|#
directive|define
name|SRST_SRST1
value|0
end_define

begin_define
define|#
directive|define
name|SRST_SRST2
value|1
end_define

begin_define
define|#
directive|define
name|SRST_L2MEM
value|18
end_define

begin_define
define|#
directive|define
name|SRST_I2S0
value|23
end_define

begin_define
define|#
directive|define
name|SRST_I2S1
value|24
end_define

begin_define
define|#
directive|define
name|SRST_I2S2
value|25
end_define

begin_define
define|#
directive|define
name|SRST_TIMER2
value|29
end_define

begin_define
define|#
directive|define
name|SRST_GPIO4
value|36
end_define

begin_define
define|#
directive|define
name|SRST_GPIO6
value|38
end_define

begin_define
define|#
directive|define
name|SRST_TSADC
value|92
end_define

begin_define
define|#
directive|define
name|SRST_HDMI
value|96
end_define

begin_define
define|#
directive|define
name|SRST_HDMI_APB
value|97
end_define

begin_define
define|#
directive|define
name|SRST_CIF1
value|111
end_define

end_unit

