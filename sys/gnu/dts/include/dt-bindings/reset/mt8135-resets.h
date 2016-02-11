begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 MediaTek Inc.  * Author: Flora Fu, MediaTek  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_CONTROLLER_MT8135
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_CONTROLLER_MT8135
end_define

begin_comment
comment|/* INFRACFG resets */
end_comment

begin_define
define|#
directive|define
name|MT8135_INFRA_EMI_REG_RST
value|0
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_DRAMC0_A0_RST
value|1
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_CCIF0_RST
value|2
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_APCIRQ_EINT_RST
value|3
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_APXGPT_RST
value|4
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_SCPSYS_RST
value|5
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_CCIF1_RST
value|6
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_PMIC_WRAP_RST
value|7
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_KP_RST
value|8
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_EMI_RST
value|32
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_DRAMC0_RST
value|34
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_SMI_RST
value|35
end_define

begin_define
define|#
directive|define
name|MT8135_INFRA_M4U_RST
value|36
end_define

begin_comment
comment|/*  PERICFG resets */
end_comment

begin_define
define|#
directive|define
name|MT8135_PERI_UART0_SW_RST
value|0
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_UART1_SW_RST
value|1
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_UART2_SW_RST
value|2
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_UART3_SW_RST
value|3
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_IRDA_SW_RST
value|4
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_PTP_SW_RST
value|5
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_AP_HIF_SW_RST
value|6
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_GPCU_SW_RST
value|7
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_MD_HIF_SW_RST
value|8
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_NLI_SW_RST
value|9
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_AUXADC_SW_RST
value|10
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_DMA_SW_RST
value|11
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_NFI_SW_RST
value|14
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_PWM_SW_RST
value|15
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_THERM_SW_RST
value|16
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_MSDC0_SW_RST
value|17
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_MSDC1_SW_RST
value|18
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_MSDC2_SW_RST
value|19
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_MSDC3_SW_RST
value|20
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_I2C0_SW_RST
value|22
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_I2C1_SW_RST
value|23
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_I2C2_SW_RST
value|24
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_I2C3_SW_RST
value|25
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_I2C4_SW_RST
value|26
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_I2C5_SW_RST
value|27
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_I2C6_SW_RST
value|28
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_USB_SW_RST
value|29
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_SPI1_SW_RST
value|33
end_define

begin_define
define|#
directive|define
name|MT8135_PERI_PWRAP_BRIDGE_SW_RST
value|34
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_RESET_CONTROLLER_MT8135 */
end_comment

end_unit

