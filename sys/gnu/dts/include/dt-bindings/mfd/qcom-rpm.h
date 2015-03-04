begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the Qualcomm RPM bindings.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_MFD_QCOM_RPM_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_MFD_QCOM_RPM_H
end_define

begin_comment
comment|/*  * Constants use to identify individual resources in the RPM.  */
end_comment

begin_define
define|#
directive|define
name|QCOM_RPM_APPS_FABRIC_ARB
value|1
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_APPS_FABRIC_CLK
value|2
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_APPS_FABRIC_HALT
value|3
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_APPS_FABRIC_IOCTL
value|4
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_APPS_FABRIC_MODE
value|5
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_APPS_L2_CACHE_CTL
value|6
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_CFPB_CLK
value|7
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_CXO_BUFFERS
value|8
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_CXO_CLK
value|9
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_DAYTONA_FABRIC_CLK
value|10
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_DDR_DMM
value|11
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_EBI1_CLK
value|12
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_HDMI_SWITCH
value|13
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_MMFPB_CLK
value|14
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_MM_FABRIC_ARB
value|15
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_MM_FABRIC_CLK
value|16
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_MM_FABRIC_HALT
value|17
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_MM_FABRIC_IOCTL
value|18
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_MM_FABRIC_MODE
value|19
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PLL_4
value|20
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO0
value|21
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO1
value|22
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO2
value|23
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO3
value|24
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO4
value|25
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO5
value|26
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO6
value|27
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO7
value|28
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO8
value|29
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO9
value|30
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO10
value|31
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO11
value|32
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO12
value|33
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO13
value|34
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO14
value|35
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO15
value|36
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO16
value|37
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO17
value|38
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO18
value|39
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO19
value|40
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO20
value|41
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO21
value|42
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO22
value|43
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO23
value|44
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO24
value|45
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LDO25
value|46
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LVS0
value|47
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_LVS1
value|48
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_NCP
value|49
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_SMPS0
value|50
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_SMPS1
value|51
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_SMPS2
value|52
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_SMPS3
value|53
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8058_SMPS4
value|54
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8821_LDO1
value|55
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8821_SMPS1
value|56
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8821_SMPS2
value|57
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LDO0
value|58
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LDO1
value|59
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LDO2
value|60
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LDO3
value|61
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LDO4
value|62
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LDO5
value|63
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LDO6
value|64
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LVS0
value|65
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LVS1
value|66
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LVS2
value|67
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_LVS3
value|68
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_MVS
value|69
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_SMPS0
value|70
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_SMPS1
value|71
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_SMPS2
value|72
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_SMPS3
value|73
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8901_SMPS4
value|74
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_CLK1
value|75
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_CLK2
value|76
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO1
value|77
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO2
value|78
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO3
value|79
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO4
value|80
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO5
value|81
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO6
value|82
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO7
value|83
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO8
value|84
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO9
value|85
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO10
value|86
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO11
value|87
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO12
value|88
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO13
value|89
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO14
value|90
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO15
value|91
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO16
value|92
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO17
value|93
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO18
value|94
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO19
value|95
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO20
value|96
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO21
value|97
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO22
value|98
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO23
value|99
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO24
value|100
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO25
value|101
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO26
value|102
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO27
value|103
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO28
value|104
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LDO29
value|105
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LVS1
value|106
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LVS2
value|107
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LVS3
value|108
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LVS4
value|109
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LVS5
value|110
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LVS6
value|111
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_LVS7
value|112
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_MVS
value|113
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_NCP
value|114
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_SMPS1
value|115
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_SMPS2
value|116
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_SMPS3
value|117
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_SMPS4
value|118
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_SMPS5
value|119
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_SMPS6
value|120
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_SMPS7
value|121
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PM8921_SMPS8
value|122
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_PXO_CLK
value|123
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_QDSS_CLK
value|124
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_SFPB_CLK
value|125
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_SMI_CLK
value|126
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_SYS_FABRIC_ARB
value|127
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_SYS_FABRIC_CLK
value|128
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_SYS_FABRIC_HALT
value|129
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_SYS_FABRIC_IOCTL
value|130
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_SYS_FABRIC_MODE
value|131
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_USB_OTG_SWITCH
value|132
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_VDDMIN_GPIO
value|133
end_define

begin_comment
comment|/*  * Constants used to select force mode for regulators.  */
end_comment

begin_define
define|#
directive|define
name|QCOM_RPM_FORCE_MODE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_FORCE_MODE_LPM
value|1
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_FORCE_MODE_HPM
value|2
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_FORCE_MODE_AUTO
value|3
end_define

begin_define
define|#
directive|define
name|QCOM_RPM_FORCE_MODE_BYPASS
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

