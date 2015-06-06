begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants clk index STMicroelectronics  * STiH407 SoC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_STIH407
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_STIH407
end_define

begin_comment
comment|/* CLOCKGEN C0 */
end_comment

begin_define
define|#
directive|define
name|CLK_ICN_GPU
value|0
end_define

begin_define
define|#
directive|define
name|CLK_FDMA
value|1
end_define

begin_define
define|#
directive|define
name|CLK_NAND
value|2
end_define

begin_define
define|#
directive|define
name|CLK_HVA
value|3
end_define

begin_define
define|#
directive|define
name|CLK_PROC_STFE
value|4
end_define

begin_define
define|#
directive|define
name|CLK_PROC_TP
value|5
end_define

begin_define
define|#
directive|define
name|CLK_RX_ICN_DMU
value|6
end_define

begin_define
define|#
directive|define
name|CLK_RX_ICN_DISP_0
value|6
end_define

begin_define
define|#
directive|define
name|CLK_RX_ICN_DISP_1
value|6
end_define

begin_define
define|#
directive|define
name|CLK_RX_ICN_HVA
value|7
end_define

begin_define
define|#
directive|define
name|CLK_RX_ICN_TS
value|7
end_define

begin_define
define|#
directive|define
name|CLK_ICN_CPU
value|8
end_define

begin_define
define|#
directive|define
name|CLK_TX_ICN_DMU
value|9
end_define

begin_define
define|#
directive|define
name|CLK_TX_ICN_HVA
value|9
end_define

begin_define
define|#
directive|define
name|CLK_TX_ICN_TS
value|9
end_define

begin_define
define|#
directive|define
name|CLK_ICN_COMPO
value|9
end_define

begin_define
define|#
directive|define
name|CLK_MMC_0
value|10
end_define

begin_define
define|#
directive|define
name|CLK_MMC_1
value|11
end_define

begin_define
define|#
directive|define
name|CLK_JPEGDEC
value|12
end_define

begin_define
define|#
directive|define
name|CLK_ICN_REG
value|13
end_define

begin_define
define|#
directive|define
name|CLK_TRACE_A9
value|13
end_define

begin_define
define|#
directive|define
name|CLK_PTI_STM
value|13
end_define

begin_define
define|#
directive|define
name|CLK_EXT2F_A9
value|13
end_define

begin_define
define|#
directive|define
name|CLK_IC_BDISP_0
value|14
end_define

begin_define
define|#
directive|define
name|CLK_IC_BDISP_1
value|15
end_define

begin_define
define|#
directive|define
name|CLK_PP_DMU
value|16
end_define

begin_define
define|#
directive|define
name|CLK_VID_DMU
value|17
end_define

begin_define
define|#
directive|define
name|CLK_DSS_LPC
value|18
end_define

begin_define
define|#
directive|define
name|CLK_ST231_AUD_0
value|19
end_define

begin_define
define|#
directive|define
name|CLK_ST231_GP_0
value|19
end_define

begin_define
define|#
directive|define
name|CLK_ST231_GP_1
value|20
end_define

begin_define
define|#
directive|define
name|CLK_ST231_DMU
value|21
end_define

begin_define
define|#
directive|define
name|CLK_ICN_LMI
value|22
end_define

begin_define
define|#
directive|define
name|CLK_TX_ICN_DISP_0
value|23
end_define

begin_define
define|#
directive|define
name|CLK_TX_ICN_DISP_1
value|23
end_define

begin_define
define|#
directive|define
name|CLK_ICN_SBC
value|24
end_define

begin_define
define|#
directive|define
name|CLK_STFE_FRC2
value|25
end_define

begin_define
define|#
directive|define
name|CLK_ETH_PHY
value|26
end_define

begin_define
define|#
directive|define
name|CLK_ETH_REF_PHYCLK
value|27
end_define

begin_define
define|#
directive|define
name|CLK_FLASH_PROMIP
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MAIN_DISP
value|29
end_define

begin_define
define|#
directive|define
name|CLK_AUX_DISP
value|30
end_define

begin_define
define|#
directive|define
name|CLK_COMPO_DVP
value|31
end_define

begin_comment
comment|/* CLOCKGEN D0 */
end_comment

begin_define
define|#
directive|define
name|CLK_PCM_0
value|0
end_define

begin_define
define|#
directive|define
name|CLK_PCM_1
value|1
end_define

begin_define
define|#
directive|define
name|CLK_PCM_2
value|2
end_define

begin_define
define|#
directive|define
name|CLK_SPDIFF
value|3
end_define

begin_comment
comment|/* CLOCKGEN D2 */
end_comment

begin_define
define|#
directive|define
name|CLK_PIX_MAIN_DISP
value|0
end_define

begin_define
define|#
directive|define
name|CLK_PIX_PIP
value|1
end_define

begin_define
define|#
directive|define
name|CLK_PIX_GDP1
value|2
end_define

begin_define
define|#
directive|define
name|CLK_PIX_GDP2
value|3
end_define

begin_define
define|#
directive|define
name|CLK_PIX_GDP3
value|4
end_define

begin_define
define|#
directive|define
name|CLK_PIX_GDP4
value|5
end_define

begin_define
define|#
directive|define
name|CLK_PIX_AUX_DISP
value|6
end_define

begin_define
define|#
directive|define
name|CLK_DENC
value|7
end_define

begin_define
define|#
directive|define
name|CLK_PIX_HDDAC
value|8
end_define

begin_define
define|#
directive|define
name|CLK_HDDAC
value|9
end_define

begin_define
define|#
directive|define
name|CLK_SDDAC
value|10
end_define

begin_define
define|#
directive|define
name|CLK_PIX_DVO
value|11
end_define

begin_define
define|#
directive|define
name|CLK_DVO
value|12
end_define

begin_define
define|#
directive|define
name|CLK_PIX_HDMI
value|13
end_define

begin_define
define|#
directive|define
name|CLK_TMDS_HDMI
value|14
end_define

begin_define
define|#
directive|define
name|CLK_REF_HDMIPHY
value|15
end_define

begin_comment
comment|/* CLOCKGEN D3 */
end_comment

begin_define
define|#
directive|define
name|CLK_STFE_FRC1
value|0
end_define

begin_define
define|#
directive|define
name|CLK_TSOUT_0
value|1
end_define

begin_define
define|#
directive|define
name|CLK_TSOUT_1
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MCHI
value|3
end_define

begin_define
define|#
directive|define
name|CLK_VSENS_COMPO
value|4
end_define

begin_define
define|#
directive|define
name|CLK_FRC1_REMOTE
value|5
end_define

begin_define
define|#
directive|define
name|CLK_LPC_0
value|6
end_define

begin_define
define|#
directive|define
name|CLK_LPC_1
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

