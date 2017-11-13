begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * This header provides constants for binding nvidia,tegra186-gpio*.  *  * The first cell in Tegra's GPIO specifier is the GPIO ID. The macros below  * provide names for this.  *  * The second cell contains standard flag values specified in gpio.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_GPIO_TEGRA_GPIO_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_GPIO_TEGRA_GPIO_H
end_define

begin_include
include|#
directive|include
file|<dt-bindings/gpio/gpio.h>
end_include

begin_comment
comment|/* GPIOs implemented by main GPIO controller */
end_comment

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_A
value|0
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_B
value|1
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_C
value|2
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_D
value|3
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_E
value|4
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_F
value|5
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_G
value|6
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_H
value|7
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_I
value|8
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_J
value|9
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_K
value|10
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_L
value|11
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_M
value|12
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_N
value|13
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_O
value|14
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_P
value|15
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_Q
value|16
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_R
value|17
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_T
value|18
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_X
value|19
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_Y
value|20
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_BB
value|21
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO_PORT_CC
value|22
end_define

begin_define
define|#
directive|define
name|TEGRA_MAIN_GPIO
parameter_list|(
name|port
parameter_list|,
name|offset
parameter_list|)
define|\
value|((TEGRA_MAIN_GPIO_PORT_##port * 8) + offset)
end_define

begin_comment
comment|/* GPIOs implemented by AON GPIO controller */
end_comment

begin_define
define|#
directive|define
name|TEGRA_AON_GPIO_PORT_S
value|0
end_define

begin_define
define|#
directive|define
name|TEGRA_AON_GPIO_PORT_U
value|1
end_define

begin_define
define|#
directive|define
name|TEGRA_AON_GPIO_PORT_V
value|2
end_define

begin_define
define|#
directive|define
name|TEGRA_AON_GPIO_PORT_W
value|3
end_define

begin_define
define|#
directive|define
name|TEGRA_AON_GPIO_PORT_Z
value|4
end_define

begin_define
define|#
directive|define
name|TEGRA_AON_GPIO_PORT_AA
value|5
end_define

begin_define
define|#
directive|define
name|TEGRA_AON_GPIO_PORT_EE
value|6
end_define

begin_define
define|#
directive|define
name|TEGRA_AON_GPIO_PORT_FF
value|7
end_define

begin_define
define|#
directive|define
name|TEGRA_AON_GPIO
parameter_list|(
name|port
parameter_list|,
name|offset
parameter_list|)
define|\
value|((TEGRA_AON_GPIO_PORT_##port * 8) + offset)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

