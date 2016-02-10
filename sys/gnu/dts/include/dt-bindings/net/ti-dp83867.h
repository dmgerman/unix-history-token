begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Device Tree constants for the Texas Instruments DP83867 PHY  *  * Author: Dan Murphy<dmurphy@ti.com>  *  * Copyright:   (C) 2015 Texas Instruments, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_TI_DP83867_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_TI_DP83867_H
end_define

begin_comment
comment|/* PHY CTRL bits */
end_comment

begin_define
define|#
directive|define
name|DP83867_PHYCR_FIFO_DEPTH_3_B_NIB
value|0x00
end_define

begin_define
define|#
directive|define
name|DP83867_PHYCR_FIFO_DEPTH_4_B_NIB
value|0x01
end_define

begin_define
define|#
directive|define
name|DP83867_PHYCR_FIFO_DEPTH_6_B_NIB
value|0x02
end_define

begin_define
define|#
directive|define
name|DP83867_PHYCR_FIFO_DEPTH_8_B_NIB
value|0x03
end_define

begin_comment
comment|/* RGMIIDCTL internal delay for rx and tx */
end_comment

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_250_PS
value|0x0
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_500_PS
value|0x1
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_750_PS
value|0x2
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_1_NS
value|0x3
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_1_25_NS
value|0x4
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_1_50_NS
value|0x5
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_1_75_NS
value|0x6
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_2_00_NS
value|0x7
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_2_25_NS
value|0x8
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_2_50_NS
value|0x9
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_2_75_NS
value|0xa
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_3_00_NS
value|0xb
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_3_25_NS
value|0xc
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_3_50_NS
value|0xd
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_3_75_NS
value|0xe
end_define

begin_define
define|#
directive|define
name|DP83867_RGMIIDCTL_4_00_NS
value|0xf
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

