begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides Tegra210-specific constants for binding  * nvidia,tegra210-car.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_TEGRA210_CAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_TEGRA210_CAR_H
end_define

begin_define
define|#
directive|define
name|TEGRA210_RESET
parameter_list|(
name|x
parameter_list|)
value|(7 * 32 + (x))
end_define

begin_define
define|#
directive|define
name|TEGRA210_RST_DFLL_DVCO
value|TEGRA210_RESET(0)
end_define

begin_define
define|#
directive|define
name|TEGRA210_RST_ADSP
value|TEGRA210_RESET(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_RESET_TEGRA210_CAR_H */
end_comment

end_unit

