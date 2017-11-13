begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_POWER_RK3288_POWER_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_POWER_RK3288_POWER_H__
end_define

begin_comment
comment|/**  * RK3288 Power Domain and Voltage Domain Summary.  */
end_comment

begin_comment
comment|/* VD_CORE */
end_comment

begin_define
define|#
directive|define
name|RK3288_PD_A17_0
value|0
end_define

begin_define
define|#
directive|define
name|RK3288_PD_A17_1
value|1
end_define

begin_define
define|#
directive|define
name|RK3288_PD_A17_2
value|2
end_define

begin_define
define|#
directive|define
name|RK3288_PD_A17_3
value|3
end_define

begin_define
define|#
directive|define
name|RK3288_PD_SCU
value|4
end_define

begin_define
define|#
directive|define
name|RK3288_PD_DEBUG
value|5
end_define

begin_define
define|#
directive|define
name|RK3288_PD_MEM
value|6
end_define

begin_comment
comment|/* VD_LOGIC */
end_comment

begin_define
define|#
directive|define
name|RK3288_PD_BUS
value|7
end_define

begin_define
define|#
directive|define
name|RK3288_PD_PERI
value|8
end_define

begin_define
define|#
directive|define
name|RK3288_PD_VIO
value|9
end_define

begin_define
define|#
directive|define
name|RK3288_PD_ALIVE
value|10
end_define

begin_define
define|#
directive|define
name|RK3288_PD_HEVC
value|11
end_define

begin_define
define|#
directive|define
name|RK3288_PD_VIDEO
value|12
end_define

begin_comment
comment|/* VD_GPU */
end_comment

begin_define
define|#
directive|define
name|RK3288_PD_GPU
value|13
end_define

begin_comment
comment|/* VD_PMU */
end_comment

begin_define
define|#
directive|define
name|RK3288_PD_PMU
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

