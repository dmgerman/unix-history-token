begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the reset controller  * based peripheral powerdown requests on the STMicroelectronics  * STiH416 SoC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_CONTROLLER_STIH416
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_CONTROLLER_STIH416
end_define

begin_define
define|#
directive|define
name|STIH416_EMISS_POWERDOWN
value|0
end_define

begin_define
define|#
directive|define
name|STIH416_NAND_POWERDOWN
value|1
end_define

begin_define
define|#
directive|define
name|STIH416_KEYSCAN_POWERDOWN
value|2
end_define

begin_define
define|#
directive|define
name|STIH416_USB0_POWERDOWN
value|3
end_define

begin_define
define|#
directive|define
name|STIH416_USB1_POWERDOWN
value|4
end_define

begin_define
define|#
directive|define
name|STIH416_USB2_POWERDOWN
value|5
end_define

begin_define
define|#
directive|define
name|STIH416_USB3_POWERDOWN
value|6
end_define

begin_define
define|#
directive|define
name|STIH416_SATA0_POWERDOWN
value|7
end_define

begin_define
define|#
directive|define
name|STIH416_SATA1_POWERDOWN
value|8
end_define

begin_define
define|#
directive|define
name|STIH416_PCIE0_POWERDOWN
value|9
end_define

begin_define
define|#
directive|define
name|STIH416_PCIE1_POWERDOWN
value|10
end_define

begin_define
define|#
directive|define
name|STIH416_ETH0_SOFTRESET
value|0
end_define

begin_define
define|#
directive|define
name|STIH416_ETH1_SOFTRESET
value|1
end_define

begin_define
define|#
directive|define
name|STIH416_IRB_SOFTRESET
value|2
end_define

begin_define
define|#
directive|define
name|STIH416_USB0_SOFTRESET
value|3
end_define

begin_define
define|#
directive|define
name|STIH416_USB1_SOFTRESET
value|4
end_define

begin_define
define|#
directive|define
name|STIH416_USB2_SOFTRESET
value|5
end_define

begin_define
define|#
directive|define
name|STIH416_USB3_SOFTRESET
value|6
end_define

begin_define
define|#
directive|define
name|STIH416_SATA0_SOFTRESET
value|7
end_define

begin_define
define|#
directive|define
name|STIH416_SATA1_SOFTRESET
value|8
end_define

begin_define
define|#
directive|define
name|STIH416_PCIE0_SOFTRESET
value|9
end_define

begin_define
define|#
directive|define
name|STIH416_PCIE1_SOFTRESET
value|10
end_define

begin_define
define|#
directive|define
name|STIH416_AUD_DAC_SOFTRESET
value|11
end_define

begin_define
define|#
directive|define
name|STIH416_HDTVOUT_SOFTRESET
value|12
end_define

begin_define
define|#
directive|define
name|STIH416_VTAC_M_RX_SOFTRESET
value|13
end_define

begin_define
define|#
directive|define
name|STIH416_VTAC_A_RX_SOFTRESET
value|14
end_define

begin_define
define|#
directive|define
name|STIH416_SYNC_HD_SOFTRESET
value|15
end_define

begin_define
define|#
directive|define
name|STIH416_SYNC_SD_SOFTRESET
value|16
end_define

begin_define
define|#
directive|define
name|STIH416_BLITTER_SOFTRESET
value|17
end_define

begin_define
define|#
directive|define
name|STIH416_GPU_SOFTRESET
value|18
end_define

begin_define
define|#
directive|define
name|STIH416_VTAC_M_TX_SOFTRESET
value|19
end_define

begin_define
define|#
directive|define
name|STIH416_VTAC_A_TX_SOFTRESET
value|20
end_define

begin_define
define|#
directive|define
name|STIH416_VTG_AUX_SOFTRESET
value|21
end_define

begin_define
define|#
directive|define
name|STIH416_JPEG_DEC_SOFTRESET
value|22
end_define

begin_define
define|#
directive|define
name|STIH416_HVA_SOFTRESET
value|23
end_define

begin_define
define|#
directive|define
name|STIH416_COMPO_M_SOFTRESET
value|24
end_define

begin_define
define|#
directive|define
name|STIH416_COMPO_A_SOFTRESET
value|25
end_define

begin_define
define|#
directive|define
name|STIH416_VP8_DEC_SOFTRESET
value|26
end_define

begin_define
define|#
directive|define
name|STIH416_VTG_MAIN_SOFTRESET
value|27
end_define

begin_define
define|#
directive|define
name|STIH416_KEYSCAN_SOFTRESET
value|28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_RESET_CONTROLLER_STIH416 */
end_comment

end_unit

