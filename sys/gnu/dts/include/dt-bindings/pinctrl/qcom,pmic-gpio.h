begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the Qualcomm PMIC GPIO binding.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_QCOM_PMIC_GPIO_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_QCOM_PMIC_GPIO_H
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_PULL_UP_30
value|0
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_PULL_UP_1P5
value|1
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_PULL_UP_31P5
value|2
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_PULL_UP_1P5_30
value|3
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_STRENGTH_NO
value|0
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_STRENGTH_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_STRENGTH_MED
value|2
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_STRENGTH_LOW
value|3
end_define

begin_comment
comment|/*  * Note: PM8018 GPIO3 and GPIO4 are supporting  * only S3 and L2 options (1.8V)  */
end_comment

begin_define
define|#
directive|define
name|PM8018_GPIO_L6
value|0
end_define

begin_define
define|#
directive|define
name|PM8018_GPIO_L5
value|1
end_define

begin_define
define|#
directive|define
name|PM8018_GPIO_S3
value|2
end_define

begin_define
define|#
directive|define
name|PM8018_GPIO_L14
value|3
end_define

begin_define
define|#
directive|define
name|PM8018_GPIO_L2
value|4
end_define

begin_define
define|#
directive|define
name|PM8018_GPIO_L4
value|5
end_define

begin_define
define|#
directive|define
name|PM8018_GPIO_VDD
value|6
end_define

begin_comment
comment|/*  * Note: PM8038 GPIO7 and GPIO8 are supporting  * only L11 and L4 options (1.8V)  */
end_comment

begin_define
define|#
directive|define
name|PM8038_GPIO_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO_BB
value|1
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO_L11
value|2
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO_L15
value|3
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO_L4
value|4
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO_L3
value|5
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO_L17
value|6
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO_BB
value|1
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO_S3
value|2
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO_L3
value|3
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO_L7
value|4
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO_L6
value|5
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO_L5
value|6
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO_L2
value|7
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO_S4
value|2
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO_L15
value|3
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO_L4
value|4
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO_L3
value|5
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO_L17
value|6
end_define

begin_define
define|#
directive|define
name|PM8921_GPIO_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PM8921_GPIO_BB
value|1
end_define

begin_define
define|#
directive|define
name|PM8921_GPIO_S4
value|2
end_define

begin_define
define|#
directive|define
name|PM8921_GPIO_L15
value|3
end_define

begin_define
define|#
directive|define
name|PM8921_GPIO_L4
value|4
end_define

begin_define
define|#
directive|define
name|PM8921_GPIO_L3
value|5
end_define

begin_define
define|#
directive|define
name|PM8921_GPIO_L17
value|6
end_define

begin_comment
comment|/*  * Note: PM8941 gpios from 15 to 18 are supporting  * only S3 and L6 options (1.8V)  */
end_comment

begin_define
define|#
directive|define
name|PM8941_GPIO_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO_L1
value|1
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO_S3
value|2
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO_L6
value|3
end_define

begin_comment
comment|/*  * Note: PMA8084 gpios from 15 to 18 are supporting  * only S4 and L6 options (1.8V)  */
end_comment

begin_define
define|#
directive|define
name|PMA8084_GPIO_VPH
value|0
end_define

begin_define
define|#
directive|define
name|PMA8084_GPIO_L1
value|1
end_define

begin_define
define|#
directive|define
name|PMA8084_GPIO_S4
value|2
end_define

begin_define
define|#
directive|define
name|PMA8084_GPIO_L6
value|3
end_define

begin_comment
comment|/* To be used with "function" */
end_comment

begin_define
define|#
directive|define
name|PMIC_GPIO_FUNC_NORMAL
value|"normal"
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_FUNC_PAIRED
value|"paired"
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_FUNC_FUNC1
value|"func1"
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_FUNC_FUNC2
value|"func2"
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_FUNC_DTEST1
value|"dtest1"
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_FUNC_DTEST2
value|"dtest2"
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_FUNC_DTEST3
value|"dtest3"
end_define

begin_define
define|#
directive|define
name|PMIC_GPIO_FUNC_DTEST4
value|"dtest4"
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO1_2_LPG_DRV
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO3_5V_BOOST_EN
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO4_SSBI_ALT_CLK
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO5_6_EXT_REG_EN
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO10_11_EXT_REG_EN
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO6_7_CLK
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO9_BAT_ALRM_OUT
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8038_GPIO6_12_KYPD_DRV
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO7_8_MP3_CLK
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO7_8_BCLK_19P2MHZ
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO9_26_KYPD_DRV
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO21_23_UART_TX
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO24_26_LPG_DRV
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO33_BCLK_19P2MHZ
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO34_35_MP3_CLK
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO36_BCLK_19P2MHZ
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO37_UPL_OUT
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO37_UART_M_RX
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO38_XO_SLEEP_CLK
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO38_39_CLK_32KHZ
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO39_MP3_CLK
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8058_GPIO40_EXT_BB_EN
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO9_18_KEYP_DRV
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO20_BAT_ALRM_OUT
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO21_23_UART_TX
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO25_26_EXT_REG_EN
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO37_38_XO_SLEEP_CLK
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8917_GPIO37_38_MP3_CLK
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO9_14_KYPD_DRV
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO15_18_DIV_CLK
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO15_18_SLEEP_CLK
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO23_26_KYPD_DRV
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO23_26_LPG_DRV_HI
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO31_BAT_ALRM_OUT
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO33_36_LPG_DRV_3D
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PM8941_GPIO33_36_LPG_DRV_HI
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PMA8084_GPIO4_5_LPG_DRV
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PMA8084_GPIO7_10_LPG_DRV
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PMA8084_GPIO5_14_KEYP_DRV
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PMA8084_GPIO19_21_KEYP_DRV
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PMA8084_GPIO15_18_DIV_CLK
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_define
define|#
directive|define
name|PMA8084_GPIO15_18_SLEEP_CLK
value|PMIC_GPIO_FUNC_FUNC2
end_define

begin_define
define|#
directive|define
name|PMA8084_GPIO22_BAT_ALRM_OUT
value|PMIC_GPIO_FUNC_FUNC1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

