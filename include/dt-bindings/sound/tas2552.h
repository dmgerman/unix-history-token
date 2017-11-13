begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_TAS2552_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_TAS2552_H
end_define

begin_define
define|#
directive|define
name|TAS2552_PLL_CLKIN
value|(0)
end_define

begin_define
define|#
directive|define
name|TAS2552_PDM_CLK
value|(1)
end_define

begin_define
define|#
directive|define
name|TAS2552_CLK_TARGET_MASK
value|(1)
end_define

begin_define
define|#
directive|define
name|TAS2552_PLL_CLKIN_MCLK
value|((0<< 1) | TAS2552_PLL_CLKIN)
end_define

begin_define
define|#
directive|define
name|TAS2552_PLL_CLKIN_BCLK
value|((1<< 1) | TAS2552_PLL_CLKIN)
end_define

begin_define
define|#
directive|define
name|TAS2552_PLL_CLKIN_IVCLKIN
value|((2<< 1) | TAS2552_PLL_CLKIN)
end_define

begin_define
define|#
directive|define
name|TAS2552_PLL_CLKIN_1_8_FIXED
value|((3<< 1) | TAS2552_PLL_CLKIN)
end_define

begin_define
define|#
directive|define
name|TAS2552_PDM_CLK_PLL
value|((0<< 1) | TAS2552_PDM_CLK)
end_define

begin_define
define|#
directive|define
name|TAS2552_PDM_CLK_IVCLKIN
value|((1<< 1) | TAS2552_PDM_CLK)
end_define

begin_define
define|#
directive|define
name|TAS2552_PDM_CLK_BCLK
value|((2<< 1) | TAS2552_PDM_CLK)
end_define

begin_define
define|#
directive|define
name|TAS2552_PDM_CLK_MCLK
value|((3<< 1) | TAS2552_PDM_CLK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_TAS2552_H */
end_comment

end_unit

