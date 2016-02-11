begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the reset controller  * based peripheral powerdown requests on the STMicroelectronics  * STiH415 SoC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_CONTROLLER_STIH415
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_CONTROLLER_STIH415
end_define

begin_define
define|#
directive|define
name|STIH415_EMISS_POWERDOWN
value|0
end_define

begin_define
define|#
directive|define
name|STIH415_NAND_POWERDOWN
value|1
end_define

begin_define
define|#
directive|define
name|STIH415_KEYSCAN_POWERDOWN
value|2
end_define

begin_define
define|#
directive|define
name|STIH415_USB0_POWERDOWN
value|3
end_define

begin_define
define|#
directive|define
name|STIH415_USB1_POWERDOWN
value|4
end_define

begin_define
define|#
directive|define
name|STIH415_USB2_POWERDOWN
value|5
end_define

begin_define
define|#
directive|define
name|STIH415_SATA0_POWERDOWN
value|6
end_define

begin_define
define|#
directive|define
name|STIH415_SATA1_POWERDOWN
value|7
end_define

begin_define
define|#
directive|define
name|STIH415_PCIE_POWERDOWN
value|8
end_define

begin_define
define|#
directive|define
name|STIH415_ETH0_SOFTRESET
value|0
end_define

begin_define
define|#
directive|define
name|STIH415_ETH1_SOFTRESET
value|1
end_define

begin_define
define|#
directive|define
name|STIH415_IRB_SOFTRESET
value|2
end_define

begin_define
define|#
directive|define
name|STIH415_USB0_SOFTRESET
value|3
end_define

begin_define
define|#
directive|define
name|STIH415_USB1_SOFTRESET
value|4
end_define

begin_define
define|#
directive|define
name|STIH415_USB2_SOFTRESET
value|5
end_define

begin_define
define|#
directive|define
name|STIH415_KEYSCAN_SOFTRESET
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_RESET_CONTROLLER_STIH415 */
end_comment

end_unit

