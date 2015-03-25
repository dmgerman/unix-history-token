begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants clk index STMicroelectronics  * STiH418 SoC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_STIH418
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_STIH418
end_define

begin_include
include|#
directive|include
file|"stih410-clks.h"
end_include

begin_comment
comment|/* STiH418 introduces new clock outputs compared to STiH410 */
end_comment

begin_comment
comment|/* CLOCKGEN C0 */
end_comment

begin_define
define|#
directive|define
name|CLK_PROC_BDISP_0
value|14
end_define

begin_define
define|#
directive|define
name|CLK_PROC_BDISP_1
value|15
end_define

begin_define
define|#
directive|define
name|CLK_TX_ICN_1
value|23
end_define

begin_define
define|#
directive|define
name|CLK_ETH_PHYREF
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PP_HEVC
value|35
end_define

begin_define
define|#
directive|define
name|CLK_CLUST_HEVC
value|36
end_define

begin_define
define|#
directive|define
name|CLK_HWPE_HEVC
value|37
end_define

begin_define
define|#
directive|define
name|CLK_FC_HEVC
value|38
end_define

begin_define
define|#
directive|define
name|CLK_PROC_MIXER
value|39
end_define

begin_define
define|#
directive|define
name|CLK_PROC_SC
value|40
end_define

begin_define
define|#
directive|define
name|CLK_AVSP_HEVC
value|41
end_define

begin_comment
comment|/* CLOCKGEN D2 */
end_comment

begin_undef
undef|#
directive|undef
name|CLK_PIX_PIP
end_undef

begin_undef
undef|#
directive|undef
name|CLK_PIX_GDP1
end_undef

begin_undef
undef|#
directive|undef
name|CLK_PIX_GDP2
end_undef

begin_undef
undef|#
directive|undef
name|CLK_PIX_GDP3
end_undef

begin_undef
undef|#
directive|undef
name|CLK_PIX_GDP4
end_undef

begin_define
define|#
directive|define
name|CLK_TMDS_HDMI_DIV2
value|5
end_define

begin_define
define|#
directive|define
name|CLK_VP9
value|47
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

