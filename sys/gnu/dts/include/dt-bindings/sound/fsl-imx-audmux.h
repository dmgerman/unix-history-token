begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__DT_FSL_IMX_AUDMUX_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_FSL_IMX_AUDMUX_H
end_define

begin_define
define|#
directive|define
name|MX27_AUDMUX_HPCR1_SSI0
value|0
end_define

begin_define
define|#
directive|define
name|MX27_AUDMUX_HPCR2_SSI1
value|1
end_define

begin_define
define|#
directive|define
name|MX27_AUDMUX_HPCR3_SSI_PINS_4
value|2
end_define

begin_define
define|#
directive|define
name|MX27_AUDMUX_PPCR1_SSI_PINS_1
value|3
end_define

begin_define
define|#
directive|define
name|MX27_AUDMUX_PPCR2_SSI_PINS_2
value|4
end_define

begin_define
define|#
directive|define
name|MX27_AUDMUX_PPCR3_SSI_PINS_3
value|5
end_define

begin_define
define|#
directive|define
name|MX31_AUDMUX_PORT1_SSI0
value|0
end_define

begin_define
define|#
directive|define
name|MX31_AUDMUX_PORT2_SSI1
value|1
end_define

begin_define
define|#
directive|define
name|MX31_AUDMUX_PORT3_SSI_PINS_3
value|2
end_define

begin_define
define|#
directive|define
name|MX31_AUDMUX_PORT4_SSI_PINS_4
value|3
end_define

begin_define
define|#
directive|define
name|MX31_AUDMUX_PORT5_SSI_PINS_5
value|4
end_define

begin_define
define|#
directive|define
name|MX31_AUDMUX_PORT6_SSI_PINS_6
value|5
end_define

begin_define
define|#
directive|define
name|MX31_AUDMUX_PORT7_SSI_PINS_7
value|6
end_define

begin_define
define|#
directive|define
name|MX51_AUDMUX_PORT1_SSI0
value|0
end_define

begin_define
define|#
directive|define
name|MX51_AUDMUX_PORT2_SSI1
value|1
end_define

begin_define
define|#
directive|define
name|MX51_AUDMUX_PORT3
value|2
end_define

begin_define
define|#
directive|define
name|MX51_AUDMUX_PORT4
value|3
end_define

begin_define
define|#
directive|define
name|MX51_AUDMUX_PORT5
value|4
end_define

begin_define
define|#
directive|define
name|MX51_AUDMUX_PORT6
value|5
end_define

begin_define
define|#
directive|define
name|MX51_AUDMUX_PORT7
value|6
end_define

begin_comment
comment|/* Register definitions for the i.MX21/27 Digital Audio Multiplexer */
end_comment

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_INMMASK
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_INMEN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_TXRXEN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_SYN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_RXDSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 13)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_RFCSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 20)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_RCLKDIR
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_RFSDIR
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_TFCSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 26)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_TCLKDIR
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V1_PCR_TFSDIR
value|(1<< 31)
end_define

begin_comment
comment|/* Register definitions for the i.MX25/31/35/51 Digital Audio Multiplexer */
end_comment

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PTCR_TFSDIR
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PTCR_TFSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 27)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PTCR_TCLKDIR
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PTCR_TCSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 22)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PTCR_RFSDIR
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PTCR_RFSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 17)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PTCR_RCLKDIR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PTCR_RCSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 12)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PTCR_SYN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PDCR_RXDSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 13)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PDCR_TXRXEN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PDCR_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|IMX_AUDMUX_V2_PDCR_INMMASK
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_FSL_IMX_AUDMUX_H */
end_comment

end_unit

