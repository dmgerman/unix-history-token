begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Meson8b clock tree IDs  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MESON8B_CLKC_H
end_ifndef

begin_define
define|#
directive|define
name|__MESON8B_CLKC_H
end_define

begin_define
define|#
directive|define
name|CLKID_UNUSED
value|0
end_define

begin_define
define|#
directive|define
name|CLKID_XTAL
value|1
end_define

begin_define
define|#
directive|define
name|CLKID_PLL_FIXED
value|2
end_define

begin_define
define|#
directive|define
name|CLKID_PLL_VID
value|3
end_define

begin_define
define|#
directive|define
name|CLKID_PLL_SYS
value|4
end_define

begin_define
define|#
directive|define
name|CLKID_FCLK_DIV2
value|5
end_define

begin_define
define|#
directive|define
name|CLKID_FCLK_DIV3
value|6
end_define

begin_define
define|#
directive|define
name|CLKID_FCLK_DIV4
value|7
end_define

begin_define
define|#
directive|define
name|CLKID_FCLK_DIV5
value|8
end_define

begin_define
define|#
directive|define
name|CLKID_FCLK_DIV7
value|9
end_define

begin_define
define|#
directive|define
name|CLKID_CLK81
value|10
end_define

begin_define
define|#
directive|define
name|CLKID_MALI
value|11
end_define

begin_define
define|#
directive|define
name|CLKID_CPUCLK
value|12
end_define

begin_define
define|#
directive|define
name|CLKID_ZERO
value|13
end_define

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|(CLKID_ZERO + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MESON8B_CLKC_H */
end_comment

end_unit

