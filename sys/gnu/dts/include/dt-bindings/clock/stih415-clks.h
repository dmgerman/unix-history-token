begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants clk index STMicroelectronics  * STiH415 SoC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CLK_STIH415
end_ifndef

begin_define
define|#
directive|define
name|_CLK_STIH415
end_define

begin_comment
comment|/* CLOCKGEN A0 */
end_comment

begin_define
define|#
directive|define
name|CLK_ICN_REG
value|0
end_define

begin_define
define|#
directive|define
name|CLK_ETH1_PHY
value|4
end_define

begin_comment
comment|/* CLOCKGEN A1 */
end_comment

begin_define
define|#
directive|define
name|CLK_ICN_IF_2
value|0
end_define

begin_define
define|#
directive|define
name|CLK_GMAC0_PHY
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

