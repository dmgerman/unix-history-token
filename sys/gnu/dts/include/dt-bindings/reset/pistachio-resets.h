begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * This header provides constants for the reset controller  * present in the Pistachio SoC  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PISTACHIO_RESETS_H
end_ifndef

begin_define
define|#
directive|define
name|_PISTACHIO_RESETS_H
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_I2C0
value|0
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_I2C1
value|1
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_I2C2
value|2
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_I2C3
value|3
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_I2S_IN
value|4
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_PRL_OUT
value|5
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_SPDIF_OUT
value|6
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_SPI
value|7
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_PWM_PDM
value|8
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_UART0
value|9
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_UART1
value|10
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_QSPI
value|11
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_MDC
value|12
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_SDHOST
value|13
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_ETHERNET
value|14
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_IR
value|15
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_HASH
value|16
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_TIMER
value|17
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_I2S_OUT
value|18
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_SPDIF_IN
value|19
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_EVT
value|20
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_USB_H
value|21
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_USB_PR
value|22
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_USB_PHY_PR
value|23
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_USB_PHY_PON
value|24
end_define

begin_define
define|#
directive|define
name|PISTACHIO_RESET_MAX
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

