begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * This header provides macros for MAXIM MAX77620 device bindings.  *  * Copyright (c) 2016, NVIDIA Corporation.  * Author: Laxman Dewangan<ldewangan@nvidia.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_MFD_MAX77620_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_MFD_MAX77620_H
end_define

begin_comment
comment|/* MAX77620 interrupts */
end_comment

begin_define
define|#
directive|define
name|MAX77620_IRQ_TOP_GLBL
value|0
end_define

begin_comment
comment|/* Low-Battery */
end_comment

begin_define
define|#
directive|define
name|MAX77620_IRQ_TOP_SD
value|1
end_define

begin_comment
comment|/* SD power fail */
end_comment

begin_define
define|#
directive|define
name|MAX77620_IRQ_TOP_LDO
value|2
end_define

begin_comment
comment|/* LDO power fail */
end_comment

begin_define
define|#
directive|define
name|MAX77620_IRQ_TOP_GPIO
value|3
end_define

begin_comment
comment|/* GPIO internal int to MAX77620 */
end_comment

begin_define
define|#
directive|define
name|MAX77620_IRQ_TOP_RTC
value|4
end_define

begin_comment
comment|/* RTC */
end_comment

begin_define
define|#
directive|define
name|MAX77620_IRQ_TOP_32K
value|5
end_define

begin_comment
comment|/* 32kHz oscillator */
end_comment

begin_define
define|#
directive|define
name|MAX77620_IRQ_TOP_ONOFF
value|6
end_define

begin_comment
comment|/* ON/OFF oscillator */
end_comment

begin_define
define|#
directive|define
name|MAX77620_IRQ_LBT_MBATLOW
value|7
end_define

begin_comment
comment|/* Thermal alarm status,> 120C */
end_comment

begin_define
define|#
directive|define
name|MAX77620_IRQ_LBT_TJALRM1
value|8
end_define

begin_comment
comment|/* Thermal alarm status,> 120C */
end_comment

begin_define
define|#
directive|define
name|MAX77620_IRQ_LBT_TJALRM2
value|9
end_define

begin_comment
comment|/* Thermal alarm status,> 140C */
end_comment

begin_comment
comment|/* FPS event source */
end_comment

begin_define
define|#
directive|define
name|MAX77620_FPS_EVENT_SRC_EN0
value|0
end_define

begin_define
define|#
directive|define
name|MAX77620_FPS_EVENT_SRC_EN1
value|1
end_define

begin_define
define|#
directive|define
name|MAX77620_FPS_EVENT_SRC_SW
value|2
end_define

begin_comment
comment|/* Device state when FPS event LOW  */
end_comment

begin_define
define|#
directive|define
name|MAX77620_FPS_INACTIVE_STATE_SLEEP
value|0
end_define

begin_define
define|#
directive|define
name|MAX77620_FPS_INACTIVE_STATE_LOW_POWER
value|1
end_define

begin_comment
comment|/* FPS source */
end_comment

begin_define
define|#
directive|define
name|MAX77620_FPS_SRC_0
value|0
end_define

begin_define
define|#
directive|define
name|MAX77620_FPS_SRC_1
value|1
end_define

begin_define
define|#
directive|define
name|MAX77620_FPS_SRC_2
value|2
end_define

begin_define
define|#
directive|define
name|MAX77620_FPS_SRC_NONE
value|3
end_define

begin_define
define|#
directive|define
name|MAX77620_FPS_SRC_DEF
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

