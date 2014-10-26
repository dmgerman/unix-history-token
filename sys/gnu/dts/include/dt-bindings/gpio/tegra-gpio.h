begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for binding nvidia,tegra*-gpio.  *  * The first cell in Tegra's GPIO specifier is the GPIO ID. The macros below  * provide names for this.  *  * The second cell contains standard flag values specified in gpio.h.  */
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

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_A
value|0
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_B
value|1
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_C
value|2
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_D
value|3
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_E
value|4
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_F
value|5
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_G
value|6
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_H
value|7
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_I
value|8
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_J
value|9
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_K
value|10
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_L
value|11
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_M
value|12
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_N
value|13
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_O
value|14
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_P
value|15
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_Q
value|16
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_R
value|17
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_S
value|18
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_T
value|19
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_U
value|20
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_V
value|21
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_W
value|22
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_X
value|23
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_Y
value|24
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_Z
value|25
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_AA
value|26
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_BB
value|27
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_CC
value|28
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_DD
value|29
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_EE
value|30
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO_BANK_ID_FF
value|31
end_define

begin_define
define|#
directive|define
name|TEGRA_GPIO
parameter_list|(
name|bank
parameter_list|,
name|offset
parameter_list|)
define|\
value|((TEGRA_GPIO_BANK_ID_##bank * 8) + offset)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

