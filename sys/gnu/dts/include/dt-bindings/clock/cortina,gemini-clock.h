begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DT_BINDINGS_CORTINA_GEMINI_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|DT_BINDINGS_CORTINA_GEMINI_CLOCK_H
end_define

begin_comment
comment|/* RTC, AHB, APB, CPU, PCI, TVC, UART clocks and 13 gates */
end_comment

begin_define
define|#
directive|define
name|GEMINI_NUM_CLKS
value|20
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_RTC
value|0
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_AHB
value|1
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_APB
value|2
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_CPU
value|3
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_PCI
value|4
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_TVC
value|5
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_UART
value|6
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATES
value|7
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_SECURITY
value|7
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_GMAC0
value|8
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_GMAC1
value|9
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_SATA0
value|10
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_SATA1
value|11
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_USB0
value|12
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_USB1
value|13
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_IDE
value|14
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_PCI
value|15
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_DDR
value|16
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_FLASH
value|17
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_TVC
value|18
end_define

begin_define
define|#
directive|define
name|GEMINI_CLK_GATE_BOOT
value|19
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DT_BINDINGS_CORTINA_GEMINI_CLOCK_H */
end_comment

end_unit

