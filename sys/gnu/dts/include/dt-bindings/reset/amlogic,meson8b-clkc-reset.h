begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017 Martin Blumenstingl<martin.blumenstingl@googlemail.com>.  *  * SPDX-License-Identifier: (GPL-2.0+ OR MIT)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_AMLOGIC_MESON8B_CLKC_RESET_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_AMLOGIC_MESON8B_CLKC_RESET_H
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_L2_CACHE_SOFT_RESET
value|0
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_AXI_64_TO_128_BRIDGE_A5_SOFT_RESET
value|1
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_SCU_SOFT_RESET
value|2
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_CPU0_SOFT_RESET
value|3
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_CPU1_SOFT_RESET
value|4
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_CPU2_SOFT_RESET
value|5
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_CPU3_SOFT_RESET
value|6
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_A5_GLOBAL_RESET
value|7
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_A5_AXI_SOFT_RESET
value|8
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_A5_ABP_SOFT_RESET
value|9
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_AXI_64_TO_128_BRIDGE_MMC_SOFT_RESET
value|10
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_VID_CLK_CNTL_SOFT_RESET
value|11
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_VID_DIVIDER_CNTL_SOFT_RESET_POST
value|12
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_VID_DIVIDER_CNTL_SOFT_RESET_PRE
value|13
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_VID_DIVIDER_CNTL_RESET_N_POST
value|14
end_define

begin_define
define|#
directive|define
name|CLKC_RESET_VID_DIVIDER_CNTL_RESET_N_PRE
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_AMLOGIC_MESON8B_CLKC_RESET_H */
end_comment

end_unit

