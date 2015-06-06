begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides Tegra124-specific constants for binding  * nvidia,tegra124-car.  */
end_comment

begin_include
include|#
directive|include
file|<dt-bindings/clock/tegra124-car-common.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_TEGRA124_CAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_TEGRA124_CAR_H
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_X
value|227
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_PLL_X_OUT0
value|228
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CCLK_G
value|262
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CCLK_LP
value|263
end_define

begin_define
define|#
directive|define
name|TEGRA124_CLK_CLK_MAX
value|315
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_TEGRA124_CAR_H */
end_comment

end_unit

