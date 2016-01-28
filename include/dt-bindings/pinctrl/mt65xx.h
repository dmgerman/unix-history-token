begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 MediaTek Inc.  * Author: Hongzhou.Yang<hongzhou.yang@mediatek.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_MT65XX_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_MT65XX_H
end_define

begin_define
define|#
directive|define
name|MTK_PIN_NO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|MTK_GET_PIN_NO
parameter_list|(
name|x
parameter_list|)
value|((x)>> 8)
end_define

begin_define
define|#
directive|define
name|MTK_GET_PIN_FUNC
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xf)
end_define

begin_define
define|#
directive|define
name|MTK_PUPD_SET_R1R0_00
value|100
end_define

begin_define
define|#
directive|define
name|MTK_PUPD_SET_R1R0_01
value|101
end_define

begin_define
define|#
directive|define
name|MTK_PUPD_SET_R1R0_10
value|102
end_define

begin_define
define|#
directive|define
name|MTK_PUPD_SET_R1R0_11
value|103
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_2mA
value|2
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_4mA
value|4
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_6mA
value|6
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_8mA
value|8
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_10mA
value|10
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_12mA
value|12
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_14mA
value|14
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_16mA
value|16
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_20mA
value|20
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_24mA
value|24
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_28mA
value|28
end_define

begin_define
define|#
directive|define
name|MTK_DRIVE_32mA
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_PINCTRL_MT65XX_H */
end_comment

end_unit

