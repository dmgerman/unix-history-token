begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright Â© 2015 Broadcom  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_ARM_BCM2835_RPI_POWER_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_ARM_BCM2835_RPI_POWER_H
end_define

begin_comment
comment|/* These power domain indices are the firmware interface's indices  * minus one.  */
end_comment

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_I2C0
value|0
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_I2C1
value|1
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_I2C2
value|2
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_VIDEO_SCALER
value|3
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_VPU1
value|4
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_HDMI
value|5
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_USB
value|6
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_VEC
value|7
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_JPEG
value|8
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_H264
value|9
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_V3D
value|10
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_ISP
value|11
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_UNICAM0
value|12
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_UNICAM1
value|13
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_CCP2RX
value|14
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_CSI2
value|15
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_CPI
value|16
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_DSI0
value|17
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_DSI1
value|18
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_TRANSPOSER
value|19
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_CCP2TX
value|20
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_CDP
value|21
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_ARM
value|22
end_define

begin_define
define|#
directive|define
name|RPI_POWER_DOMAIN_COUNT
value|23
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_ARM_BCM2835_RPI_POWER_H */
end_comment

end_unit

