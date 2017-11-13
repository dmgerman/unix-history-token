begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

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

begin_comment
comment|/* Digital Input/Output: level [PM8058] */
end_comment

begin_define
define|#
directive|define
name|PM8058_MPP_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PM8058_MPP_S3
value|1
end_define

begin_define
define|#
directive|define
name|PM8058_MPP_L2
value|2
end_define

begin_define
define|#
directive|define
name|PM8058_MPP_L3
value|3
end_define

begin_comment
comment|/* Digital Input/Output: level [PM8901] */
end_comment

begin_define
define|#
directive|define
name|PM8901_MPP_MSMIO
value|0
end_define

begin_define
define|#
directive|define
name|PM8901_MPP_DIG
value|1
end_define

begin_define
define|#
directive|define
name|PM8901_MPP_L5
value|2
end_define

begin_define
define|#
directive|define
name|PM8901_MPP_S4
value|3
end_define

begin_define
define|#
directive|define
name|PM8901_MPP_VPH
value|4
end_define

begin_comment
comment|/* Digital Input/Output: level [PM8921] */
end_comment

begin_define
define|#
directive|define
name|PM8921_MPP_S4
value|1
end_define

begin_define
define|#
directive|define
name|PM8921_MPP_L15
value|3
end_define

begin_define
define|#
directive|define
name|PM8921_MPP_L17
value|4
end_define

begin_define
define|#
directive|define
name|PM8921_MPP_VPH
value|7
end_define

begin_comment
comment|/* Digital Input/Output: level [PM8821] */
end_comment

begin_define
define|#
directive|define
name|PM8821_MPP_1P8
value|0
end_define

begin_define
define|#
directive|define
name|PM8821_MPP_VPH
value|7
end_define

begin_comment
comment|/* Digital Input/Output: level [PM8018] */
end_comment

begin_define
define|#
directive|define
name|PM8018_MPP_L4
value|0
end_define

begin_define
define|#
directive|define
name|PM8018_MPP_L14
value|1
end_define

begin_define
define|#
directive|define
name|PM8018_MPP_S3
value|2
end_define

begin_define
define|#
directive|define
name|PM8018_MPP_L6
value|3
end_define

begin_define
define|#
directive|define
name|PM8018_MPP_L2
value|4
end_define

begin_define
define|#
directive|define
name|PM8018_MPP_L5
value|5
end_define

begin_define
define|#
directive|define
name|PM8018_MPP_VPH
value|7
end_define

begin_comment
comment|/* Digital Input/Output: level [PM8038] */
end_comment

begin_define
define|#
directive|define
name|PM8038_MPP_L20
value|0
end_define

begin_define
define|#
directive|define
name|PM8038_MPP_L11
value|1
end_define

begin_define
define|#
directive|define
name|PM8038_MPP_L5
value|2
end_define

begin_define
define|#
directive|define
name|PM8038_MPP_L15
value|3
end_define

begin_define
define|#
directive|define
name|PM8038_MPP_L17
value|4
end_define

begin_define
define|#
directive|define
name|PM8038_MPP_VPH
value|7
end_define

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
name|PM8916_MPP_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PM8916_MPP_L2
value|2
end_define

begin_define
define|#
directive|define
name|PM8916_MPP_L5
value|3
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

begin_define
define|#
directive|define
name|PM8994_MPP_VPH
value|0
end_define

begin_comment
comment|/* Only supported for MPP_05-MPP_08 */
end_comment

begin_define
define|#
directive|define
name|PM8994_MPP_L19
value|1
end_define

begin_define
define|#
directive|define
name|PM8994_MPP_S4
value|2
end_define

begin_define
define|#
directive|define
name|PM8994_MPP_L12
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
comment|/* Analog Output: level */
end_comment

begin_define
define|#
directive|define
name|PMIC_MPP_AOUT_LVL_1V25
value|0
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AOUT_LVL_1V25_2
value|1
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AOUT_LVL_0V625
value|2
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AOUT_LVL_0V3125
value|3
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AOUT_LVL_MPP
value|4
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AOUT_LVL_ABUS1
value|5
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AOUT_LVL_ABUS2
value|6
end_define

begin_define
define|#
directive|define
name|PMIC_MPP_AOUT_LVL_ABUS3
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

