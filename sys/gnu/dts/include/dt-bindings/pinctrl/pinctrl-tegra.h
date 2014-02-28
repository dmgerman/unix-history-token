begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for Tegra pinctrl bindings.  *  * Copyright (c) 2013, NVIDIA CORPORATION.  All rights reserved.  *  * Author: Laxman Dewangan<ldewangan@nvidia.com>  *  * This program is free software; you can redistribute it and/or modify it  * under the terms and conditions of the GNU General Public License,  * version 2, as published by the Free Software Foundation.  *  * This program is distributed in the hope it will be useful, but WITHOUT  * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for  * more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_TEGRA_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_TEGRA_H
end_define

begin_comment
comment|/*  * Enable/disable for diffeent dt properties. This is applicable for  * properties nvidia,enable-input, nvidia,tristate, nvidia,open-drain,  * nvidia,lock, nvidia,rcv-sel, nvidia,high-speed-mode, nvidia,schmitt.  */
end_comment

begin_define
define|#
directive|define
name|TEGRA_PIN_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|TEGRA_PIN_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|TEGRA_PIN_PULL_NONE
value|0
end_define

begin_define
define|#
directive|define
name|TEGRA_PIN_PULL_DOWN
value|1
end_define

begin_define
define|#
directive|define
name|TEGRA_PIN_PULL_UP
value|2
end_define

begin_comment
comment|/* Low power mode driver */
end_comment

begin_define
define|#
directive|define
name|TEGRA_PIN_LP_DRIVE_DIV_8
value|0
end_define

begin_define
define|#
directive|define
name|TEGRA_PIN_LP_DRIVE_DIV_4
value|1
end_define

begin_define
define|#
directive|define
name|TEGRA_PIN_LP_DRIVE_DIV_2
value|2
end_define

begin_define
define|#
directive|define
name|TEGRA_PIN_LP_DRIVE_DIV_1
value|3
end_define

begin_comment
comment|/* Rising/Falling slew rate */
end_comment

begin_define
define|#
directive|define
name|TEGRA_PIN_SLEW_RATE_FASTEST
value|0
end_define

begin_define
define|#
directive|define
name|TEGRA_PIN_SLEW_RATE_FAST
value|1
end_define

begin_define
define|#
directive|define
name|TEGRA_PIN_SLEW_RATE_SLOW
value|2
end_define

begin_define
define|#
directive|define
name|TEGRA_PIN_SLEW_RATE_SLOWEST
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

