begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SYS, CORE AND BUS CLOCKS */
end_comment

begin_define
define|#
directive|define
name|SYS_D1CPRE
value|0
end_define

begin_define
define|#
directive|define
name|HCLK
value|1
end_define

begin_define
define|#
directive|define
name|PCLK1
value|2
end_define

begin_define
define|#
directive|define
name|PCLK2
value|3
end_define

begin_define
define|#
directive|define
name|PCLK3
value|4
end_define

begin_define
define|#
directive|define
name|PCLK4
value|5
end_define

begin_define
define|#
directive|define
name|HSI_DIV
value|6
end_define

begin_define
define|#
directive|define
name|HSE_1M
value|7
end_define

begin_define
define|#
directive|define
name|I2S_CKIN
value|8
end_define

begin_define
define|#
directive|define
name|CK_DSI_PHY
value|9
end_define

begin_define
define|#
directive|define
name|HSE_CK
value|10
end_define

begin_define
define|#
directive|define
name|LSE_CK
value|11
end_define

begin_define
define|#
directive|define
name|CSI_KER_DIV122
value|12
end_define

begin_define
define|#
directive|define
name|RTC_CK
value|13
end_define

begin_define
define|#
directive|define
name|CPU_SYSTICK
value|14
end_define

begin_comment
comment|/* OSCILLATOR BANK */
end_comment

begin_define
define|#
directive|define
name|OSC_BANK
value|18
end_define

begin_define
define|#
directive|define
name|HSI_CK
value|18
end_define

begin_define
define|#
directive|define
name|HSI_KER_CK
value|19
end_define

begin_define
define|#
directive|define
name|CSI_CK
value|20
end_define

begin_define
define|#
directive|define
name|CSI_KER_CK
value|21
end_define

begin_define
define|#
directive|define
name|RC48_CK
value|22
end_define

begin_define
define|#
directive|define
name|LSI_CK
value|23
end_define

begin_comment
comment|/* MCLOCK BANK */
end_comment

begin_define
define|#
directive|define
name|MCLK_BANK
value|28
end_define

begin_define
define|#
directive|define
name|PER_CK
value|28
end_define

begin_define
define|#
directive|define
name|PLLSRC
value|29
end_define

begin_define
define|#
directive|define
name|SYS_CK
value|30
end_define

begin_define
define|#
directive|define
name|TRACEIN_CK
value|31
end_define

begin_comment
comment|/* ODF BANK */
end_comment

begin_define
define|#
directive|define
name|ODF_BANK
value|32
end_define

begin_define
define|#
directive|define
name|PLL1_P
value|32
end_define

begin_define
define|#
directive|define
name|PLL1_Q
value|33
end_define

begin_define
define|#
directive|define
name|PLL1_R
value|34
end_define

begin_define
define|#
directive|define
name|PLL2_P
value|35
end_define

begin_define
define|#
directive|define
name|PLL2_Q
value|36
end_define

begin_define
define|#
directive|define
name|PLL2_R
value|37
end_define

begin_define
define|#
directive|define
name|PLL3_P
value|38
end_define

begin_define
define|#
directive|define
name|PLL3_Q
value|39
end_define

begin_define
define|#
directive|define
name|PLL3_R
value|40
end_define

begin_comment
comment|/* MCO BANK */
end_comment

begin_define
define|#
directive|define
name|MCO_BANK
value|41
end_define

begin_define
define|#
directive|define
name|MCO1
value|41
end_define

begin_define
define|#
directive|define
name|MCO2
value|42
end_define

begin_comment
comment|/* PERIF BANK */
end_comment

begin_define
define|#
directive|define
name|PERIF_BANK
value|50
end_define

begin_define
define|#
directive|define
name|D1SRAM1_CK
value|50
end_define

begin_define
define|#
directive|define
name|ITCM_CK
value|51
end_define

begin_define
define|#
directive|define
name|DTCM2_CK
value|52
end_define

begin_define
define|#
directive|define
name|DTCM1_CK
value|53
end_define

begin_define
define|#
directive|define
name|FLITF_CK
value|54
end_define

begin_define
define|#
directive|define
name|JPGDEC_CK
value|55
end_define

begin_define
define|#
directive|define
name|DMA2D_CK
value|56
end_define

begin_define
define|#
directive|define
name|MDMA_CK
value|57
end_define

begin_define
define|#
directive|define
name|USB2ULPI_CK
value|58
end_define

begin_define
define|#
directive|define
name|USB1ULPI_CK
value|59
end_define

begin_define
define|#
directive|define
name|ETH1RX_CK
value|60
end_define

begin_define
define|#
directive|define
name|ETH1TX_CK
value|61
end_define

begin_define
define|#
directive|define
name|ETH1MAC_CK
value|62
end_define

begin_define
define|#
directive|define
name|ART_CK
value|63
end_define

begin_define
define|#
directive|define
name|DMA2_CK
value|64
end_define

begin_define
define|#
directive|define
name|DMA1_CK
value|65
end_define

begin_define
define|#
directive|define
name|D2SRAM3_CK
value|66
end_define

begin_define
define|#
directive|define
name|D2SRAM2_CK
value|67
end_define

begin_define
define|#
directive|define
name|D2SRAM1_CK
value|68
end_define

begin_define
define|#
directive|define
name|HASH_CK
value|69
end_define

begin_define
define|#
directive|define
name|CRYPT_CK
value|70
end_define

begin_define
define|#
directive|define
name|CAMITF_CK
value|71
end_define

begin_define
define|#
directive|define
name|BKPRAM_CK
value|72
end_define

begin_define
define|#
directive|define
name|HSEM_CK
value|73
end_define

begin_define
define|#
directive|define
name|BDMA_CK
value|74
end_define

begin_define
define|#
directive|define
name|CRC_CK
value|75
end_define

begin_define
define|#
directive|define
name|GPIOK_CK
value|76
end_define

begin_define
define|#
directive|define
name|GPIOJ_CK
value|77
end_define

begin_define
define|#
directive|define
name|GPIOI_CK
value|78
end_define

begin_define
define|#
directive|define
name|GPIOH_CK
value|79
end_define

begin_define
define|#
directive|define
name|GPIOG_CK
value|80
end_define

begin_define
define|#
directive|define
name|GPIOF_CK
value|81
end_define

begin_define
define|#
directive|define
name|GPIOE_CK
value|82
end_define

begin_define
define|#
directive|define
name|GPIOD_CK
value|83
end_define

begin_define
define|#
directive|define
name|GPIOC_CK
value|84
end_define

begin_define
define|#
directive|define
name|GPIOB_CK
value|85
end_define

begin_define
define|#
directive|define
name|GPIOA_CK
value|86
end_define

begin_define
define|#
directive|define
name|WWDG1_CK
value|87
end_define

begin_define
define|#
directive|define
name|DAC12_CK
value|88
end_define

begin_define
define|#
directive|define
name|WWDG2_CK
value|89
end_define

begin_define
define|#
directive|define
name|TIM14_CK
value|90
end_define

begin_define
define|#
directive|define
name|TIM13_CK
value|91
end_define

begin_define
define|#
directive|define
name|TIM12_CK
value|92
end_define

begin_define
define|#
directive|define
name|TIM7_CK
value|93
end_define

begin_define
define|#
directive|define
name|TIM6_CK
value|94
end_define

begin_define
define|#
directive|define
name|TIM5_CK
value|95
end_define

begin_define
define|#
directive|define
name|TIM4_CK
value|96
end_define

begin_define
define|#
directive|define
name|TIM3_CK
value|97
end_define

begin_define
define|#
directive|define
name|TIM2_CK
value|98
end_define

begin_define
define|#
directive|define
name|MDIOS_CK
value|99
end_define

begin_define
define|#
directive|define
name|OPAMP_CK
value|100
end_define

begin_define
define|#
directive|define
name|CRS_CK
value|101
end_define

begin_define
define|#
directive|define
name|TIM17_CK
value|102
end_define

begin_define
define|#
directive|define
name|TIM16_CK
value|103
end_define

begin_define
define|#
directive|define
name|TIM15_CK
value|104
end_define

begin_define
define|#
directive|define
name|TIM8_CK
value|105
end_define

begin_define
define|#
directive|define
name|TIM1_CK
value|106
end_define

begin_define
define|#
directive|define
name|TMPSENS_CK
value|107
end_define

begin_define
define|#
directive|define
name|RTCAPB_CK
value|108
end_define

begin_define
define|#
directive|define
name|VREF_CK
value|109
end_define

begin_define
define|#
directive|define
name|COMP12_CK
value|110
end_define

begin_define
define|#
directive|define
name|SYSCFG_CK
value|111
end_define

begin_comment
comment|/* KERNEL BANK */
end_comment

begin_define
define|#
directive|define
name|KERN_BANK
value|120
end_define

begin_define
define|#
directive|define
name|SDMMC1_CK
value|120
end_define

begin_define
define|#
directive|define
name|QUADSPI_CK
value|121
end_define

begin_define
define|#
directive|define
name|FMC_CK
value|122
end_define

begin_define
define|#
directive|define
name|USB2OTG_CK
value|123
end_define

begin_define
define|#
directive|define
name|USB1OTG_CK
value|124
end_define

begin_define
define|#
directive|define
name|ADC12_CK
value|125
end_define

begin_define
define|#
directive|define
name|SDMMC2_CK
value|126
end_define

begin_define
define|#
directive|define
name|RNG_CK
value|127
end_define

begin_define
define|#
directive|define
name|ADC3_CK
value|128
end_define

begin_define
define|#
directive|define
name|DSI_CK
value|129
end_define

begin_define
define|#
directive|define
name|LTDC_CK
value|130
end_define

begin_define
define|#
directive|define
name|USART8_CK
value|131
end_define

begin_define
define|#
directive|define
name|USART7_CK
value|132
end_define

begin_define
define|#
directive|define
name|HDMICEC_CK
value|133
end_define

begin_define
define|#
directive|define
name|I2C3_CK
value|134
end_define

begin_define
define|#
directive|define
name|I2C2_CK
value|135
end_define

begin_define
define|#
directive|define
name|I2C1_CK
value|136
end_define

begin_define
define|#
directive|define
name|UART5_CK
value|137
end_define

begin_define
define|#
directive|define
name|UART4_CK
value|138
end_define

begin_define
define|#
directive|define
name|USART3_CK
value|139
end_define

begin_define
define|#
directive|define
name|USART2_CK
value|140
end_define

begin_define
define|#
directive|define
name|SPDIFRX_CK
value|141
end_define

begin_define
define|#
directive|define
name|SPI3_CK
value|142
end_define

begin_define
define|#
directive|define
name|SPI2_CK
value|143
end_define

begin_define
define|#
directive|define
name|LPTIM1_CK
value|144
end_define

begin_define
define|#
directive|define
name|FDCAN_CK
value|145
end_define

begin_define
define|#
directive|define
name|SWP_CK
value|146
end_define

begin_define
define|#
directive|define
name|HRTIM_CK
value|147
end_define

begin_define
define|#
directive|define
name|DFSDM1_CK
value|148
end_define

begin_define
define|#
directive|define
name|SAI3_CK
value|149
end_define

begin_define
define|#
directive|define
name|SAI2_CK
value|150
end_define

begin_define
define|#
directive|define
name|SAI1_CK
value|151
end_define

begin_define
define|#
directive|define
name|SPI5_CK
value|152
end_define

begin_define
define|#
directive|define
name|SPI4_CK
value|153
end_define

begin_define
define|#
directive|define
name|SPI1_CK
value|154
end_define

begin_define
define|#
directive|define
name|USART6_CK
value|155
end_define

begin_define
define|#
directive|define
name|USART1_CK
value|156
end_define

begin_define
define|#
directive|define
name|SAI4B_CK
value|157
end_define

begin_define
define|#
directive|define
name|SAI4A_CK
value|158
end_define

begin_define
define|#
directive|define
name|LPTIM5_CK
value|159
end_define

begin_define
define|#
directive|define
name|LPTIM4_CK
value|160
end_define

begin_define
define|#
directive|define
name|LPTIM3_CK
value|161
end_define

begin_define
define|#
directive|define
name|LPTIM2_CK
value|162
end_define

begin_define
define|#
directive|define
name|I2C4_CK
value|163
end_define

begin_define
define|#
directive|define
name|SPI6_CK
value|164
end_define

begin_define
define|#
directive|define
name|LPUART1_CK
value|165
end_define

begin_define
define|#
directive|define
name|STM32H7_MAX_CLKS
value|166
end_define

end_unit

