begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_MARVELL_MMP2_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_MARVELL_MMP2_CLOCK_H
end_define

begin_comment
comment|/* fixed clocks and plls */
end_comment

begin_define
define|#
directive|define
name|MMP2_CLK_CLK32
value|1
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_VCTCXO
value|2
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL1
value|3
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL1_2
value|8
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL1_4
value|9
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL1_8
value|10
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL1_16
value|11
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL1_3
value|12
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL1_6
value|13
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL1_12
value|14
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL1_20
value|15
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL2
value|16
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL2_2
value|17
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL2_4
value|18
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL2_8
value|19
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL2_16
value|20
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL2_3
value|21
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL2_6
value|22
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PLL2_12
value|23
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_VCTCXO_2
value|24
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_VCTCXO_4
value|25
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_UART_PLL
value|26
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_USB_PLL
value|27
end_define

begin_comment
comment|/* apb periphrals */
end_comment

begin_define
define|#
directive|define
name|MMP2_CLK_TWSI0
value|60
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_TWSI1
value|61
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_TWSI2
value|62
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_TWSI3
value|63
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_TWSI4
value|64
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_TWSI5
value|65
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_GPIO
value|66
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_KPC
value|67
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_RTC
value|68
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PWM0
value|69
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PWM1
value|70
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PWM2
value|71
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_PWM3
value|72
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_UART0
value|73
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_UART1
value|74
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_UART2
value|75
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_UART3
value|76
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_SSP0
value|77
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_SSP1
value|78
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_SSP2
value|79
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_SSP3
value|80
end_define

begin_comment
comment|/* axi periphrals */
end_comment

begin_define
define|#
directive|define
name|MMP2_CLK_SDH0
value|101
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_SDH1
value|102
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_SDH2
value|103
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_SDH3
value|104
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_USB
value|105
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_DISP0
value|106
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_DISP0_MUX
value|107
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_DISP0_SPHY
value|108
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_DISP1
value|109
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_DISP1_MUX
value|110
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_CCIC_ARBITER
value|111
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_CCIC0
value|112
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_CCIC0_MIX
value|113
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_CCIC0_PHY
value|114
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_CCIC0_SPHY
value|115
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_CCIC1
value|116
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_CCIC1_MIX
value|117
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_CCIC1_PHY
value|118
end_define

begin_define
define|#
directive|define
name|MMP2_CLK_CCIC1_SPHY
value|119
end_define

begin_define
define|#
directive|define
name|MMP2_NR_CLKS
value|200
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

