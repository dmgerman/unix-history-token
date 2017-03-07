begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for Keystone pinctrl bindings.  *  * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed "as is" WITHOUT ANY WARRANTY of any  * kind, whether express or implied; without even the implied warranty  * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_KEYSTONE_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_KEYSTONE_H
end_define

begin_define
define|#
directive|define
name|MUX_MODE0
value|0
end_define

begin_define
define|#
directive|define
name|MUX_MODE1
value|1
end_define

begin_define
define|#
directive|define
name|MUX_MODE2
value|2
end_define

begin_define
define|#
directive|define
name|MUX_MODE3
value|3
end_define

begin_define
define|#
directive|define
name|MUX_MODE4
value|4
end_define

begin_define
define|#
directive|define
name|MUX_MODE5
value|5
end_define

begin_define
define|#
directive|define
name|BUFFER_CLASS_B
value|(0<< 19)
end_define

begin_define
define|#
directive|define
name|BUFFER_CLASS_C
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|BUFFER_CLASS_D
value|(2<< 19)
end_define

begin_define
define|#
directive|define
name|BUFFER_CLASS_E
value|(3<< 19)
end_define

begin_define
define|#
directive|define
name|PULL_DISABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PIN_PULLUP
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|PIN_PULLDOWN
value|(0<< 17)
end_define

begin_define
define|#
directive|define
name|KEYSTONE_IOPAD_OFFSET
parameter_list|(
name|pa
parameter_list|,
name|offset
parameter_list|)
value|(((pa)& 0xffff) - (offset))
end_define

begin_define
define|#
directive|define
name|K2G_CORE_IOPAD
parameter_list|(
name|pa
parameter_list|)
value|KEYSTONE_IOPAD_OFFSET((pa), 0x1000)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

