begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2013 Broadcom Corporation  * Copyright 2013 Linaro Limited  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation version 2.  *  * This program is distributed "as is" WITHOUT ANY WARRANTY of any  * kind, whether express or implied; without even the implied warranty  * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOCK_BCM281XX_H
end_ifndef

begin_define
define|#
directive|define
name|_CLOCK_BCM281XX_H
end_define

begin_comment
comment|/*  * This file defines the values used to specify clocks provided by  * the clock control units (CCUs) on Broadcom BCM281XX family SoCs.  */
end_comment

begin_comment
comment|/*  * These are the bcm281xx CCU device tree "compatible" strings.  * We're stuck with using "bcm11351" in the string because wild  * cards aren't allowed, and that name was the first one defined  * in this family of devices.  */
end_comment

begin_define
define|#
directive|define
name|BCM281XX_DT_ROOT_CCU_COMPAT
value|"brcm,bcm11351-root-ccu"
end_define

begin_define
define|#
directive|define
name|BCM281XX_DT_AON_CCU_COMPAT
value|"brcm,bcm11351-aon-ccu"
end_define

begin_define
define|#
directive|define
name|BCM281XX_DT_HUB_CCU_COMPAT
value|"brcm,bcm11351-hub-ccu"
end_define

begin_define
define|#
directive|define
name|BCM281XX_DT_MASTER_CCU_COMPAT
value|"brcm,bcm11351-master-ccu"
end_define

begin_define
define|#
directive|define
name|BCM281XX_DT_SLAVE_CCU_COMPAT
value|"brcm,bcm11351-slave-ccu"
end_define

begin_comment
comment|/* root CCU clock ids */
end_comment

begin_define
define|#
directive|define
name|BCM281XX_ROOT_CCU_FRAC_1M
value|0
end_define

begin_define
define|#
directive|define
name|BCM281XX_ROOT_CCU_CLOCK_COUNT
value|1
end_define

begin_comment
comment|/* aon CCU clock ids */
end_comment

begin_define
define|#
directive|define
name|BCM281XX_AON_CCU_HUB_TIMER
value|0
end_define

begin_define
define|#
directive|define
name|BCM281XX_AON_CCU_PMU_BSC
value|1
end_define

begin_define
define|#
directive|define
name|BCM281XX_AON_CCU_PMU_BSC_VAR
value|2
end_define

begin_define
define|#
directive|define
name|BCM281XX_AON_CCU_CLOCK_COUNT
value|3
end_define

begin_comment
comment|/* hub CCU clock ids */
end_comment

begin_define
define|#
directive|define
name|BCM281XX_HUB_CCU_TMON_1M
value|0
end_define

begin_define
define|#
directive|define
name|BCM281XX_HUB_CCU_CLOCK_COUNT
value|1
end_define

begin_comment
comment|/* master CCU clock ids */
end_comment

begin_define
define|#
directive|define
name|BCM281XX_MASTER_CCU_SDIO1
value|0
end_define

begin_define
define|#
directive|define
name|BCM281XX_MASTER_CCU_SDIO2
value|1
end_define

begin_define
define|#
directive|define
name|BCM281XX_MASTER_CCU_SDIO3
value|2
end_define

begin_define
define|#
directive|define
name|BCM281XX_MASTER_CCU_SDIO4
value|3
end_define

begin_define
define|#
directive|define
name|BCM281XX_MASTER_CCU_USB_IC
value|4
end_define

begin_define
define|#
directive|define
name|BCM281XX_MASTER_CCU_HSIC2_48M
value|5
end_define

begin_define
define|#
directive|define
name|BCM281XX_MASTER_CCU_HSIC2_12M
value|6
end_define

begin_define
define|#
directive|define
name|BCM281XX_MASTER_CCU_CLOCK_COUNT
value|7
end_define

begin_comment
comment|/* slave CCU clock ids */
end_comment

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_UARTB
value|0
end_define

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_UARTB2
value|1
end_define

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_UARTB3
value|2
end_define

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_UARTB4
value|3
end_define

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_SSP0
value|4
end_define

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_SSP2
value|5
end_define

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_BSC1
value|6
end_define

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_BSC2
value|7
end_define

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_BSC3
value|8
end_define

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_PWM
value|9
end_define

begin_define
define|#
directive|define
name|BCM281XX_SLAVE_CCU_CLOCK_COUNT
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CLOCK_BCM281XX_H */
end_comment

end_unit

