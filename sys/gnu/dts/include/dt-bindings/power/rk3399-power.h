begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_POWER_RK3399_POWER_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_POWER_RK3399_POWER_H__
end_define

begin_comment
comment|/* VD_CORE_L */
end_comment

begin_define
define|#
directive|define
name|RK3399_PD_A53_L0
value|0
end_define

begin_define
define|#
directive|define
name|RK3399_PD_A53_L1
value|1
end_define

begin_define
define|#
directive|define
name|RK3399_PD_A53_L2
value|2
end_define

begin_define
define|#
directive|define
name|RK3399_PD_A53_L3
value|3
end_define

begin_define
define|#
directive|define
name|RK3399_PD_SCU_L
value|4
end_define

begin_comment
comment|/* VD_CORE_B */
end_comment

begin_define
define|#
directive|define
name|RK3399_PD_A72_B0
value|5
end_define

begin_define
define|#
directive|define
name|RK3399_PD_A72_B1
value|6
end_define

begin_define
define|#
directive|define
name|RK3399_PD_SCU_B
value|7
end_define

begin_comment
comment|/* VD_LOGIC */
end_comment

begin_define
define|#
directive|define
name|RK3399_PD_TCPD0
value|8
end_define

begin_define
define|#
directive|define
name|RK3399_PD_TCPD1
value|9
end_define

begin_define
define|#
directive|define
name|RK3399_PD_CCI
value|10
end_define

begin_define
define|#
directive|define
name|RK3399_PD_CCI0
value|11
end_define

begin_define
define|#
directive|define
name|RK3399_PD_CCI1
value|12
end_define

begin_define
define|#
directive|define
name|RK3399_PD_PERILP
value|13
end_define

begin_define
define|#
directive|define
name|RK3399_PD_PERIHP
value|14
end_define

begin_define
define|#
directive|define
name|RK3399_PD_VIO
value|15
end_define

begin_define
define|#
directive|define
name|RK3399_PD_VO
value|16
end_define

begin_define
define|#
directive|define
name|RK3399_PD_VOPB
value|17
end_define

begin_define
define|#
directive|define
name|RK3399_PD_VOPL
value|18
end_define

begin_define
define|#
directive|define
name|RK3399_PD_ISP0
value|19
end_define

begin_define
define|#
directive|define
name|RK3399_PD_ISP1
value|20
end_define

begin_define
define|#
directive|define
name|RK3399_PD_HDCP
value|21
end_define

begin_define
define|#
directive|define
name|RK3399_PD_GMAC
value|22
end_define

begin_define
define|#
directive|define
name|RK3399_PD_EMMC
value|23
end_define

begin_define
define|#
directive|define
name|RK3399_PD_USB3
value|24
end_define

begin_define
define|#
directive|define
name|RK3399_PD_EDP
value|25
end_define

begin_define
define|#
directive|define
name|RK3399_PD_GIC
value|26
end_define

begin_define
define|#
directive|define
name|RK3399_PD_SD
value|27
end_define

begin_define
define|#
directive|define
name|RK3399_PD_SDIOAUDIO
value|28
end_define

begin_define
define|#
directive|define
name|RK3399_PD_ALIVE
value|29
end_define

begin_comment
comment|/* VD_CENTER */
end_comment

begin_define
define|#
directive|define
name|RK3399_PD_CENTER
value|30
end_define

begin_define
define|#
directive|define
name|RK3399_PD_VCODEC
value|31
end_define

begin_define
define|#
directive|define
name|RK3399_PD_VDU
value|32
end_define

begin_define
define|#
directive|define
name|RK3399_PD_RGA
value|33
end_define

begin_define
define|#
directive|define
name|RK3399_PD_IEP
value|34
end_define

begin_comment
comment|/* VD_GPU */
end_comment

begin_define
define|#
directive|define
name|RK3399_PD_GPU
value|35
end_define

begin_comment
comment|/* VD_PMU */
end_comment

begin_define
define|#
directive|define
name|RK3399_PD_PMU
value|36
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

