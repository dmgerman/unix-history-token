begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for Samsung audio subsystem  * clock controller.  *  * The constants defined in this header are being used in dts  * and exynos audss driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_EXYNOS_AUDSS_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_EXYNOS_AUDSS_H
end_define

begin_define
define|#
directive|define
name|EXYNOS_MOUT_AUDSS
value|0
end_define

begin_define
define|#
directive|define
name|EXYNOS_MOUT_I2S
value|1
end_define

begin_define
define|#
directive|define
name|EXYNOS_DOUT_SRP
value|2
end_define

begin_define
define|#
directive|define
name|EXYNOS_DOUT_AUD_BUS
value|3
end_define

begin_define
define|#
directive|define
name|EXYNOS_DOUT_I2S
value|4
end_define

begin_define
define|#
directive|define
name|EXYNOS_SRP_CLK
value|5
end_define

begin_define
define|#
directive|define
name|EXYNOS_I2S_BUS
value|6
end_define

begin_define
define|#
directive|define
name|EXYNOS_SCLK_I2S
value|7
end_define

begin_define
define|#
directive|define
name|EXYNOS_PCM_BUS
value|8
end_define

begin_define
define|#
directive|define
name|EXYNOS_SCLK_PCM
value|9
end_define

begin_define
define|#
directive|define
name|EXYNOS_ADMA
value|10
end_define

begin_define
define|#
directive|define
name|EXYNOS_AUDSS_MAX_CLKS
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

