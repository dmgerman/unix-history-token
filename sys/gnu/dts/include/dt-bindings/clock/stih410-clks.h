begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants clk index STMicroelectronics  * STiH410 SoC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_STIH410
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_STIH410
end_define

begin_include
include|#
directive|include
file|"stih407-clks.h"
end_include

begin_comment
comment|/* STiH410 introduces new clock outputs compared to STiH407 */
end_comment

begin_comment
comment|/* CLOCKGEN C0 */
end_comment

begin_define
define|#
directive|define
name|CLK_TX_ICN_HADES
value|32
end_define

begin_define
define|#
directive|define
name|CLK_RX_ICN_HADES
value|33
end_define

begin_define
define|#
directive|define
name|CLK_ICN_REG_16
value|34
end_define

begin_define
define|#
directive|define
name|CLK_PP_HADES
value|35
end_define

begin_define
define|#
directive|define
name|CLK_CLUST_HADES
value|36
end_define

begin_define
define|#
directive|define
name|CLK_HWPE_HADES
value|37
end_define

begin_define
define|#
directive|define
name|CLK_FC_HADES
value|38
end_define

begin_comment
comment|/* CLOCKGEN D0 */
end_comment

begin_define
define|#
directive|define
name|CLK_PCMR10_MASTER
value|4
end_define

begin_define
define|#
directive|define
name|CLK_USB2_PHY
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

