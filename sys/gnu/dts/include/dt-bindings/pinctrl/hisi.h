begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for hisilicon pinctrl bindings.  *  * Copyright (c) 2015 Hisilicon Limited.  * Copyright (c) 2015 Linaro Limited.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed "as is" WITHOUT ANY WARRANTY of any  * kind, whether express or implied; without even the implied warranty  * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_HISI_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_HISI_H
end_define

begin_comment
comment|/* iomg bit definition */
end_comment

begin_define
define|#
directive|define
name|MUX_M0
value|0
end_define

begin_define
define|#
directive|define
name|MUX_M1
value|1
end_define

begin_define
define|#
directive|define
name|MUX_M2
value|2
end_define

begin_define
define|#
directive|define
name|MUX_M3
value|3
end_define

begin_define
define|#
directive|define
name|MUX_M4
value|4
end_define

begin_define
define|#
directive|define
name|MUX_M5
value|5
end_define

begin_define
define|#
directive|define
name|MUX_M6
value|6
end_define

begin_define
define|#
directive|define
name|MUX_M7
value|7
end_define

begin_comment
comment|/* iocg bit definition */
end_comment

begin_define
define|#
directive|define
name|PULL_MASK
value|(3)
end_define

begin_define
define|#
directive|define
name|PULL_DIS
value|(0)
end_define

begin_define
define|#
directive|define
name|PULL_UP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PULL_DOWN
value|(1<< 1)
end_define

begin_comment
comment|/* drive strength definition */
end_comment

begin_define
define|#
directive|define
name|DRIVE_MASK
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE1_02MA
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE1_04MA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE1_08MA
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE1_10MA
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE2_02MA
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE2_04MA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE2_08MA
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE2_10MA
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE3_04MA
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE3_08MA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE3_12MA
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE3_16MA
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE3_20MA
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE3_24MA
value|(5<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE3_32MA
value|(6<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE3_40MA
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE4_02MA
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE4_04MA
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE4_08MA
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE4_10MA
value|(6<< 4)
end_define

begin_comment
comment|/* drive strength definition for hi3660 */
end_comment

begin_define
define|#
directive|define
name|DRIVE6_MASK
value|(15<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE6_04MA
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE6_12MA
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE6_19MA
value|(8<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE6_27MA
value|(10<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE6_32MA
value|(15<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE7_02MA
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE7_04MA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE7_06MA
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE7_08MA
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE7_10MA
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE7_12MA
value|(5<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE7_14MA
value|(6<< 4)
end_define

begin_define
define|#
directive|define
name|DRIVE7_16MA
value|(7<< 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

