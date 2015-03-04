begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the Qualcomm PMIC's  * Multi-Purpose Pin binding.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_QCOM_PMIC_MPP_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_QCOM_PMIC_MPP_H
end_define

begin_comment
comment|/* power-source */
end_comment

begin_define
define|#
directive|define
name|PM8841_MPP_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PM8841_MPP_S3
value|2
end_define

begin_define
define|#
directive|define
name|PM8941_MPP_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PM8941_MPP_L1
value|1
end_define

begin_define
define|#
directive|define
name|PM8941_MPP_S3
value|2
end_define

begin_define
define|#
directive|define
name|PM8941_MPP_L6
value|3
end_define

begin_define
define|#
directive|define
name|PMA8084_MPP_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PMA8084_MPP_L1
value|1
end_define

begin_define
define|#
directive|define
name|PMA8084_MPP_S4
value|2
end_define

begin_define
define|#
directive|define
name|PMA8084_MPP_L6
value|3
end_define

begin_comment
comment|/*  * Analog Input - Set the source for analog input.  * To be used with "qcom,amux-route" property  */
end_comment

begin_define
define|#
directive|define
name|PMIC_MPP_AMUX_ROUTE_CH5
value|0
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AMUX_ROUTE_CH6
value|1
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AMUX_ROUTE_CH7
value|2
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AMUX_ROUTE_CH8
value|3
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AMUX_ROUTE_ABUS1
value|4
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AMUX_ROUTE_ABUS2
value|5
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AMUX_ROUTE_ABUS3
value|6
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AMUX_ROUTE_ABUS4
value|7
end_define

begin_comment
comment|/* To be used with "function" */
end_comment

begin_define
define|#
directive|define
name|PMIC_MPP_FUNC_NORMAL
value|"normal"
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_FUNC_PAIRED
value|"paired"
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_FUNC_DTEST1
value|"dtest1"
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_FUNC_DTEST2
value|"dtest2"
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_FUNC_DTEST3
value|"dtest3"
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_FUNC_DTEST4
value|"dtest4"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

