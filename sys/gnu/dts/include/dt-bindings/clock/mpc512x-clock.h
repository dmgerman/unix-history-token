begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for MPC512x clock specs in DT bindings.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_MPC512x_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_MPC512x_CLOCK_H
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_DUMMY
value|0
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_REF
value|1
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_SYS
value|2
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_DIU
value|3
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_VIU
value|4
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_CSB
value|5
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_E300
value|6
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_IPS
value|7
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_FEC
value|8
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_SATA
value|9
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PATA
value|10
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_NFC
value|11
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_LPC
value|12
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_MBX_BUS
value|13
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_MBX
value|14
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_MBX_3D
value|15
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_AXE
value|16
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_USB1
value|17
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_USB2
value|18
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_I2C
value|19
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_MSCAN0_MCLK
value|20
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_MSCAN1_MCLK
value|21
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_MSCAN2_MCLK
value|22
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_MSCAN3_MCLK
value|23
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_BDLC
value|24
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_SDHC
value|25
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PCI
value|26
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC_MCLK_IN
value|27
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_SPDIF_TX
value|28
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_SPDIF_RX
value|29
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_SPDIF_MCLK
value|30
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_SPDIF
value|31
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_AC97
value|32
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC0_MCLK
value|33
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC1_MCLK
value|34
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC2_MCLK
value|35
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC3_MCLK
value|36
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC4_MCLK
value|37
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC5_MCLK
value|38
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC6_MCLK
value|39
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC7_MCLK
value|40
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC8_MCLK
value|41
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC9_MCLK
value|42
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC10_MCLK
value|43
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC11_MCLK
value|44
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC_FIFO
value|45
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC0
value|46
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC1
value|47
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC2
value|48
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC3
value|49
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC4
value|50
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC5
value|51
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC6
value|52
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC7
value|53
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC8
value|54
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC9
value|55
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC10
value|56
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_PSC11
value|57
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_SDHC2
value|58
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_FEC2
value|59
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_OUT0_CLK
value|60
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_OUT1_CLK
value|61
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_OUT2_CLK
value|62
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_OUT3_CLK
value|63
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_CAN_CLK_IN
value|64
end_define

begin_define
define|#
directive|define
name|MPC512x_CLK_LAST_PUBLIC
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

