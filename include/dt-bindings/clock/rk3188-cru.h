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
name|SRST_PTM_CORE2
value|0
end_define

begin_define
define|#
directive|define
name|SRST_PTM_CORE3
value|1
end_define

begin_define
define|#
directive|define
name|SRST_CORE2
value|5
end_define

begin_define
define|#
directive|define
name|SRST_CORE3
value|6
end_define

begin_define
define|#
directive|define
name|SRST_CORE2_DBG
value|10
end_define

begin_define
define|#
directive|define
name|SRST_CORE3_DBG
value|11
end_define

begin_define
define|#
directive|define
name|SRST_TIMER2
value|16
end_define

begin_define
define|#
directive|define
name|SRST_TIMER4
value|23
end_define

begin_define
define|#
directive|define
name|SRST_I2S0
value|24
end_define

begin_define
define|#
directive|define
name|SRST_TIMER5
value|25
end_define

begin_define
define|#
directive|define
name|SRST_TIMER3
value|29
end_define

begin_define
define|#
directive|define
name|SRST_TIMER6
value|31
end_define

begin_define
define|#
directive|define
name|SRST_PTM3
value|36
end_define

begin_define
define|#
directive|define
name|SRST_PTM3_ATB
value|37
end_define

begin_define
define|#
directive|define
name|SRST_GPS
value|67
end_define

begin_define
define|#
directive|define
name|SRST_HSICPHY
value|75
end_define

begin_define
define|#
directive|define
name|SRST_TIMER
value|78
end_define

begin_define
define|#
directive|define
name|SRST_PTM2
value|92
end_define

begin_define
define|#
directive|define
name|SRST_CORE2_WDT
value|94
end_define

begin_define
define|#
directive|define
name|SRST_CORE3_WDT
value|95
end_define

begin_define
define|#
directive|define
name|SRST_PTM2_ATB
value|111
end_define

begin_define
define|#
directive|define
name|SRST_HSIC
value|117
end_define

begin_define
define|#
directive|define
name|SRST_CTI2
value|118
end_define

begin_define
define|#
directive|define
name|SRST_CTI2_APB
value|119
end_define

begin_define
define|#
directive|define
name|SRST_GPU_BRIDGE
value|121
end_define

begin_define
define|#
directive|define
name|SRST_CTI3
value|123
end_define

begin_define
define|#
directive|define
name|SRST_CTI3_APB
value|124
end_define

end_unit

