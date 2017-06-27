begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Samsung's Exynos pinctrl bindings  *  * Copyright (c) 2016 Samsung Electronics Co., Ltd.  *		http://www.samsung.com  * Author: Krzysztof Kozlowski<krzk@kernel.org>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_PINCTRL_SAMSUNG_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_PINCTRL_SAMSUNG_H__
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_PULL_NONE
value|0
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_PULL_DOWN
value|1
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_PULL_UP
value|3
end_define

begin_define
define|#
directive|define
name|S3C64XX_PIN_PULL_NONE
value|0
end_define

begin_define
define|#
directive|define
name|S3C64XX_PIN_PULL_DOWN
value|1
end_define

begin_define
define|#
directive|define
name|S3C64XX_PIN_PULL_UP
value|2
end_define

begin_comment
comment|/* Pin function in power down mode */
end_comment

begin_define
define|#
directive|define
name|EXYNOS_PIN_PDN_OUT0
value|0
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_PDN_OUT1
value|1
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_PDN_INPUT
value|2
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_PDN_PREV
value|3
end_define

begin_comment
comment|/* Drive strengths for Exynos3250, Exynos4 (all) and Exynos5250 */
end_comment

begin_define
define|#
directive|define
name|EXYNOS4_PIN_DRV_LV1
value|0
end_define

begin_define
define|#
directive|define
name|EXYNOS4_PIN_DRV_LV2
value|2
end_define

begin_define
define|#
directive|define
name|EXYNOS4_PIN_DRV_LV3
value|1
end_define

begin_define
define|#
directive|define
name|EXYNOS4_PIN_DRV_LV4
value|3
end_define

begin_comment
comment|/* Drive strengths for Exynos5260 */
end_comment

begin_define
define|#
directive|define
name|EXYNOS5260_PIN_DRV_LV1
value|0
end_define

begin_define
define|#
directive|define
name|EXYNOS5260_PIN_DRV_LV2
value|1
end_define

begin_define
define|#
directive|define
name|EXYNOS5260_PIN_DRV_LV4
value|2
end_define

begin_define
define|#
directive|define
name|EXYNOS5260_PIN_DRV_LV6
value|3
end_define

begin_comment
comment|/* Drive strengths for Exynos5410, Exynos542x and Exynos5800 */
end_comment

begin_define
define|#
directive|define
name|EXYNOS5420_PIN_DRV_LV1
value|0
end_define

begin_define
define|#
directive|define
name|EXYNOS5420_PIN_DRV_LV2
value|1
end_define

begin_define
define|#
directive|define
name|EXYNOS5420_PIN_DRV_LV3
value|2
end_define

begin_define
define|#
directive|define
name|EXYNOS5420_PIN_DRV_LV4
value|3
end_define

begin_comment
comment|/* Drive strengths for Exynos5433 */
end_comment

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_FAST_SR1
value|0
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_FAST_SR2
value|1
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_FAST_SR3
value|2
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_FAST_SR4
value|3
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_FAST_SR5
value|4
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_FAST_SR6
value|5
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_SLOW_SR1
value|8
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_SLOW_SR2
value|9
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_SLOW_SR3
value|0xa
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_SLOW_SR4
value|0xb
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_SLOW_SR5
value|0xc
end_define

begin_define
define|#
directive|define
name|EXYNOS5433_PIN_DRV_SLOW_SR6
value|0xf
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_FUNC_INPUT
value|0
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_FUNC_OUTPUT
value|1
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_FUNC_2
value|2
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_FUNC_3
value|3
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_FUNC_4
value|4
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_FUNC_5
value|5
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_FUNC_6
value|6
end_define

begin_define
define|#
directive|define
name|EXYNOS_PIN_FUNC_F
value|0xf
end_define

begin_comment
comment|/* Drive strengths for Exynos7 FSYS1 block */
end_comment

begin_define
define|#
directive|define
name|EXYNOS7_FSYS1_PIN_DRV_LV1
value|0
end_define

begin_define
define|#
directive|define
name|EXYNOS7_FSYS1_PIN_DRV_LV2
value|4
end_define

begin_define
define|#
directive|define
name|EXYNOS7_FSYS1_PIN_DRV_LV3
value|2
end_define

begin_define
define|#
directive|define
name|EXYNOS7_FSYS1_PIN_DRV_LV4
value|6
end_define

begin_define
define|#
directive|define
name|EXYNOS7_FSYS1_PIN_DRV_LV5
value|1
end_define

begin_define
define|#
directive|define
name|EXYNOS7_FSYS1_PIN_DRV_LV6
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_PINCTRL_SAMSUNG_H__ */
end_comment

end_unit

