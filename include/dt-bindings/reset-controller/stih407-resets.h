begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the reset controller  * based peripheral powerdown requests on the STMicroelectronics  * STiH407 SoC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_CONTROLLER_STIH407
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_CONTROLLER_STIH407
end_define

begin_comment
comment|/* Powerdown requests control 0 */
end_comment

begin_define
define|#
directive|define
name|STIH407_EMISS_POWERDOWN
value|0
end_define

begin_define
define|#
directive|define
name|STIH407_NAND_POWERDOWN
value|1
end_define

begin_comment
comment|/* Synp GMAC PowerDown */
end_comment

begin_define
define|#
directive|define
name|STIH407_ETH1_POWERDOWN
value|2
end_define

begin_comment
comment|/* Powerdown requests control 1 */
end_comment

begin_define
define|#
directive|define
name|STIH407_USB3_POWERDOWN
value|3
end_define

begin_define
define|#
directive|define
name|STIH407_USB2_PORT1_POWERDOWN
value|4
end_define

begin_define
define|#
directive|define
name|STIH407_USB2_PORT0_POWERDOWN
value|5
end_define

begin_define
define|#
directive|define
name|STIH407_PCIE1_POWERDOWN
value|6
end_define

begin_define
define|#
directive|define
name|STIH407_PCIE0_POWERDOWN
value|7
end_define

begin_define
define|#
directive|define
name|STIH407_SATA1_POWERDOWN
value|8
end_define

begin_define
define|#
directive|define
name|STIH407_SATA0_POWERDOWN
value|9
end_define

begin_comment
comment|/* Reset defines */
end_comment

begin_define
define|#
directive|define
name|STIH407_ETH1_SOFTRESET
value|0
end_define

begin_define
define|#
directive|define
name|STIH407_MMC1_SOFTRESET
value|1
end_define

begin_define
define|#
directive|define
name|STIH407_PICOPHY_SOFTRESET
value|2
end_define

begin_define
define|#
directive|define
name|STIH407_IRB_SOFTRESET
value|3
end_define

begin_define
define|#
directive|define
name|STIH407_PCIE0_SOFTRESET
value|4
end_define

begin_define
define|#
directive|define
name|STIH407_PCIE1_SOFTRESET
value|5
end_define

begin_define
define|#
directive|define
name|STIH407_SATA0_SOFTRESET
value|6
end_define

begin_define
define|#
directive|define
name|STIH407_SATA1_SOFTRESET
value|7
end_define

begin_define
define|#
directive|define
name|STIH407_MIPHY0_SOFTRESET
value|8
end_define

begin_define
define|#
directive|define
name|STIH407_MIPHY1_SOFTRESET
value|9
end_define

begin_define
define|#
directive|define
name|STIH407_MIPHY2_SOFTRESET
value|10
end_define

begin_define
define|#
directive|define
name|STIH407_SATA0_PWR_SOFTRESET
value|11
end_define

begin_define
define|#
directive|define
name|STIH407_SATA1_PWR_SOFTRESET
value|12
end_define

begin_define
define|#
directive|define
name|STIH407_DELTA_SOFTRESET
value|13
end_define

begin_define
define|#
directive|define
name|STIH407_BLITTER_SOFTRESET
value|14
end_define

begin_define
define|#
directive|define
name|STIH407_HDTVOUT_SOFTRESET
value|15
end_define

begin_define
define|#
directive|define
name|STIH407_HDQVDP_SOFTRESET
value|16
end_define

begin_define
define|#
directive|define
name|STIH407_VDP_AUX_SOFTRESET
value|17
end_define

begin_define
define|#
directive|define
name|STIH407_COMPO_SOFTRESET
value|18
end_define

begin_define
define|#
directive|define
name|STIH407_HDMI_TX_PHY_SOFTRESET
value|19
end_define

begin_define
define|#
directive|define
name|STIH407_JPEG_DEC_SOFTRESET
value|20
end_define

begin_define
define|#
directive|define
name|STIH407_VP8_DEC_SOFTRESET
value|21
end_define

begin_define
define|#
directive|define
name|STIH407_GPU_SOFTRESET
value|22
end_define

begin_define
define|#
directive|define
name|STIH407_HVA_SOFTRESET
value|23
end_define

begin_define
define|#
directive|define
name|STIH407_ERAM_HVA_SOFTRESET
value|24
end_define

begin_define
define|#
directive|define
name|STIH407_LPM_SOFTRESET
value|25
end_define

begin_define
define|#
directive|define
name|STIH407_KEYSCAN_SOFTRESET
value|26
end_define

begin_define
define|#
directive|define
name|STIH407_USB2_PORT0_SOFTRESET
value|27
end_define

begin_define
define|#
directive|define
name|STIH407_USB2_PORT1_SOFTRESET
value|28
end_define

begin_comment
comment|/* Picophy reset defines */
end_comment

begin_define
define|#
directive|define
name|STIH407_PICOPHY0_RESET
value|0
end_define

begin_define
define|#
directive|define
name|STIH407_PICOPHY1_RESET
value|1
end_define

begin_define
define|#
directive|define
name|STIH407_PICOPHY2_RESET
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_RESET_CONTROLLER_STIH407 */
end_comment

end_unit

