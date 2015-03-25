begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * DRV260X haptics driver family  *  * Author: Dan Murphy<dmurphy@ti.com>  *  * Copyright:   (C) 2014 Texas Instruments, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_TI_DRV260X_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_TI_DRV260X_H
end_define

begin_comment
comment|/* Calibration Types */
end_comment

begin_define
define|#
directive|define
name|DRV260X_LRA_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|DRV260X_LRA_NO_CAL_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|DRV260X_ERM_MODE
value|0x02
end_define

begin_comment
comment|/* Library Selection */
end_comment

begin_define
define|#
directive|define
name|DRV260X_LIB_EMPTY
value|0x00
end_define

begin_define
define|#
directive|define
name|DRV260X_ERM_LIB_A
value|0x01
end_define

begin_define
define|#
directive|define
name|DRV260X_ERM_LIB_B
value|0x02
end_define

begin_define
define|#
directive|define
name|DRV260X_ERM_LIB_C
value|0x03
end_define

begin_define
define|#
directive|define
name|DRV260X_ERM_LIB_D
value|0x04
end_define

begin_define
define|#
directive|define
name|DRV260X_ERM_LIB_E
value|0x05
end_define

begin_define
define|#
directive|define
name|DRV260X_LIB_LRA
value|0x06
end_define

begin_define
define|#
directive|define
name|DRV260X_ERM_LIB_F
value|0x07
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

