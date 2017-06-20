begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_STM32H7_PINFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_STM32H7_PINFUNC_H
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_GPIO
value|0x0
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_TIM2_CH1_TIM2_ETR
value|0x2
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_TIM5_CH1
value|0x3
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_TIM8_ETR
value|0x4
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_TIM15_BKIN
value|0x5
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_USART2_CTS_NSS
value|0x8
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_UART4_TX
value|0x9
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_SDMMC2_CMD
value|0xa
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_SAI2_SD_B
value|0xb
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_ETH_MII_CRS
value|0xc
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_EVENTOUT
value|0x10
end_define

begin_define
define|#
directive|define
name|STM32H7_PA0_FUNC_ANALOG
value|0x11
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_GPIO
value|0x100
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_TIM2_CH2
value|0x102
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_TIM5_CH2
value|0x103
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_LPTIM3_OUT
value|0x104
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_TIM15_CH1N
value|0x105
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_USART2_RTS
value|0x108
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_UART4_RX
value|0x109
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_QUADSPI_BK1_IO3
value|0x10a
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_SAI2_MCK_B
value|0x10b
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_ETH_MII_RX_CLK_ETH_RMII_REF_CLK
value|0x10c
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_LCD_R2
value|0x10f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_EVENTOUT
value|0x110
end_define

begin_define
define|#
directive|define
name|STM32H7_PA1_FUNC_ANALOG
value|0x111
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_GPIO
value|0x200
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_TIM2_CH3
value|0x202
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_TIM5_CH3
value|0x203
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_LPTIM4_OUT
value|0x204
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_TIM15_CH1
value|0x205
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_USART2_TX
value|0x208
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_SAI2_SCK_B
value|0x209
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_ETH_MDIO
value|0x20c
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_MDIOS_MDIO
value|0x20d
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_LCD_R1
value|0x20f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_EVENTOUT
value|0x210
end_define

begin_define
define|#
directive|define
name|STM32H7_PA2_FUNC_ANALOG
value|0x211
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_GPIO
value|0x300
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_TIM2_CH4
value|0x302
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_TIM5_CH4
value|0x303
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_LPTIM5_OUT
value|0x304
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_TIM15_CH2
value|0x305
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_USART2_RX
value|0x308
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_LCD_B2
value|0x30a
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_OTG_HS_ULPI_D0
value|0x30b
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_ETH_MII_COL
value|0x30c
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_LCD_B5
value|0x30f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_EVENTOUT
value|0x310
end_define

begin_define
define|#
directive|define
name|STM32H7_PA3_FUNC_ANALOG
value|0x311
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_GPIO
value|0x400
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_TIM5_ETR
value|0x403
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_SPI1_NSS_I2S1_WS
value|0x406
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_SPI3_NSS_I2S3_WS
value|0x407
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_USART2_CK
value|0x408
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_SPI6_NSS
value|0x409
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_OTG_HS_SOF
value|0x40d
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_DCMI_HSYNC
value|0x40e
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_LCD_VSYNC
value|0x40f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_EVENTOUT
value|0x410
end_define

begin_define
define|#
directive|define
name|STM32H7_PA4_FUNC_ANALOG
value|0x411
end_define

begin_define
define|#
directive|define
name|STM32H7_PA5_FUNC_GPIO
value|0x500
end_define

begin_define
define|#
directive|define
name|STM32H7_PA5_FUNC_TIM2_CH1_TIM2_ETR
value|0x502
end_define

begin_define
define|#
directive|define
name|STM32H7_PA5_FUNC_TIM8_CH1N
value|0x504
end_define

begin_define
define|#
directive|define
name|STM32H7_PA5_FUNC_SPI1_SCK_I2S1_CK
value|0x506
end_define

begin_define
define|#
directive|define
name|STM32H7_PA5_FUNC_SPI6_SCK
value|0x509
end_define

begin_define
define|#
directive|define
name|STM32H7_PA5_FUNC_OTG_HS_ULPI_CK
value|0x50b
end_define

begin_define
define|#
directive|define
name|STM32H7_PA5_FUNC_LCD_R4
value|0x50f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA5_FUNC_EVENTOUT
value|0x510
end_define

begin_define
define|#
directive|define
name|STM32H7_PA5_FUNC_ANALOG
value|0x511
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_GPIO
value|0x600
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_TIM1_BKIN
value|0x602
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_TIM3_CH1
value|0x603
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_TIM8_BKIN
value|0x604
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_SPI1_MISO_I2S1_SDI
value|0x606
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_SPI6_MISO
value|0x609
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_TIM13_CH1
value|0x60a
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_TIM8_BKIN_COMP12
value|0x60b
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_MDIOS_MDC
value|0x60c
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_TIM1_BKIN_COMP12
value|0x60d
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_DCMI_PIXCLK
value|0x60e
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_LCD_G2
value|0x60f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_EVENTOUT
value|0x610
end_define

begin_define
define|#
directive|define
name|STM32H7_PA6_FUNC_ANALOG
value|0x611
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_GPIO
value|0x700
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_TIM1_CH1N
value|0x702
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_TIM3_CH2
value|0x703
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_TIM8_CH1N
value|0x704
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_SPI1_MOSI_I2S1_SDO
value|0x706
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_SPI6_MOSI
value|0x709
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_TIM14_CH1
value|0x70a
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_ETH_MII_RX_DV_ETH_RMII_CRS_DV
value|0x70c
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_FMC_SDNWE
value|0x70d
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_EVENTOUT
value|0x710
end_define

begin_define
define|#
directive|define
name|STM32H7_PA7_FUNC_ANALOG
value|0x711
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_GPIO
value|0x800
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_MCO1
value|0x801
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_TIM1_CH1
value|0x802
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_HRTIM_CHB2
value|0x803
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_TIM8_BKIN2
value|0x804
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_I2C3_SCL
value|0x805
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_USART1_CK
value|0x808
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_OTG_FS_SOF
value|0x80b
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_UART7_RX
value|0x80c
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_TIM8_BKIN2_COMP12
value|0x80d
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_LCD_B3
value|0x80e
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_LCD_R6
value|0x80f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_EVENTOUT
value|0x810
end_define

begin_define
define|#
directive|define
name|STM32H7_PA8_FUNC_ANALOG
value|0x811
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_GPIO
value|0x900
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_TIM1_CH2
value|0x902
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_HRTIM_CHC1
value|0x903
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_LPUART1_TX
value|0x904
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_I2C3_SMBA
value|0x905
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_SPI2_SCK_I2S2_CK
value|0x906
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_USART1_TX
value|0x908
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_CAN1_RXFD
value|0x90a
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_ETH_TX_ER
value|0x90c
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_DCMI_D0
value|0x90e
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_LCD_R5
value|0x90f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_EVENTOUT
value|0x910
end_define

begin_define
define|#
directive|define
name|STM32H7_PA9_FUNC_ANALOG
value|0x911
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_GPIO
value|0xa00
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_TIM1_CH3
value|0xa02
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_HRTIM_CHC2
value|0xa03
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_LPUART1_RX
value|0xa04
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_USART1_RX
value|0xa08
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_CAN1_TXFD
value|0xa0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_OTG_FS_ID
value|0xa0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_MDIOS_MDIO
value|0xa0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_LCD_B4
value|0xa0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_DCMI_D1
value|0xa0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_LCD_B1
value|0xa0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_EVENTOUT
value|0xa10
end_define

begin_define
define|#
directive|define
name|STM32H7_PA10_FUNC_ANALOG
value|0xa11
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_GPIO
value|0xb00
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_TIM1_CH4
value|0xb02
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_HRTIM_CHD1
value|0xb03
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_LPUART1_CTS
value|0xb04
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_SPI2_NSS_I2S2_WS
value|0xb06
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_UART4_RX
value|0xb07
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_USART1_CTS_NSS
value|0xb08
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_CAN1_RX
value|0xb0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_OTG_FS_DM
value|0xb0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_LCD_R4
value|0xb0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_EVENTOUT
value|0xb10
end_define

begin_define
define|#
directive|define
name|STM32H7_PA11_FUNC_ANALOG
value|0xb11
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_GPIO
value|0xc00
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_TIM1_ETR
value|0xc02
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_HRTIM_CHD2
value|0xc03
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_LPUART1_RTS
value|0xc04
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_SPI2_SCK_I2S2_CK
value|0xc06
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_UART4_TX
value|0xc07
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_USART1_RTS
value|0xc08
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_SAI2_FS_B
value|0xc09
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_CAN1_TX
value|0xc0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_OTG_FS_DP
value|0xc0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_LCD_R5
value|0xc0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_EVENTOUT
value|0xc10
end_define

begin_define
define|#
directive|define
name|STM32H7_PA12_FUNC_ANALOG
value|0xc11
end_define

begin_define
define|#
directive|define
name|STM32H7_PA13_FUNC_GPIO
value|0xd00
end_define

begin_define
define|#
directive|define
name|STM32H7_PA13_FUNC_JTMS_SWDIO
value|0xd01
end_define

begin_define
define|#
directive|define
name|STM32H7_PA13_FUNC_EVENTOUT
value|0xd10
end_define

begin_define
define|#
directive|define
name|STM32H7_PA13_FUNC_ANALOG
value|0xd11
end_define

begin_define
define|#
directive|define
name|STM32H7_PA14_FUNC_GPIO
value|0xe00
end_define

begin_define
define|#
directive|define
name|STM32H7_PA14_FUNC_JTCK_SWCLK
value|0xe01
end_define

begin_define
define|#
directive|define
name|STM32H7_PA14_FUNC_EVENTOUT
value|0xe10
end_define

begin_define
define|#
directive|define
name|STM32H7_PA14_FUNC_ANALOG
value|0xe11
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_GPIO
value|0xf00
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_JTDI
value|0xf01
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_TIM2_CH1_TIM2_ETR
value|0xf02
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_HRTIM_FLT1
value|0xf03
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_HDMI_CEC
value|0xf05
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_SPI1_NSS_I2S1_WS
value|0xf06
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_SPI3_NSS_I2S3_WS
value|0xf07
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_SPI6_NSS
value|0xf08
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_UART4_RTS
value|0xf09
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_UART7_TX
value|0xf0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_DSI_TE
value|0xf0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_EVENTOUT
value|0xf10
end_define

begin_define
define|#
directive|define
name|STM32H7_PA15_FUNC_ANALOG
value|0xf11
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_GPIO
value|0x1000
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_TIM1_CH2N
value|0x1002
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_TIM3_CH3
value|0x1003
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_TIM8_CH2N
value|0x1004
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_DFSDM_CKOUT
value|0x1007
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_UART4_CTS
value|0x1009
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_LCD_R3
value|0x100a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_OTG_HS_ULPI_D1
value|0x100b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_ETH_MII_RXD2
value|0x100c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_LCD_G1
value|0x100f
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_EVENTOUT
value|0x1010
end_define

begin_define
define|#
directive|define
name|STM32H7_PB0_FUNC_ANALOG
value|0x1011
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_GPIO
value|0x1100
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_TIM1_CH3N
value|0x1102
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_TIM3_CH4
value|0x1103
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_TIM8_CH3N
value|0x1104
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_DFSDM_DATIN1
value|0x1107
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_LCD_R6
value|0x110a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_OTG_HS_ULPI_D2
value|0x110b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_ETH_MII_RXD3
value|0x110c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_LCD_G0
value|0x110f
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_EVENTOUT
value|0x1110
end_define

begin_define
define|#
directive|define
name|STM32H7_PB1_FUNC_ANALOG
value|0x1111
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_GPIO
value|0x1200
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_SAI1_D1
value|0x1203
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_DFSDM_CKIN1
value|0x1205
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_SAI1_SD_A
value|0x1207
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_SPI3_MOSI_I2S3_SDO
value|0x1208
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_SAI4_SD_A
value|0x1209
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_QUADSPI_CLK
value|0x120a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_SAI4_D1
value|0x120b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_ETH_TX_ER
value|0x120c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_EVENTOUT
value|0x1210
end_define

begin_define
define|#
directive|define
name|STM32H7_PB2_FUNC_ANALOG
value|0x1211
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_GPIO
value|0x1300
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_JTDO_TRACESWO
value|0x1301
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_TIM2_CH2
value|0x1302
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_HRTIM_FLT4
value|0x1303
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_SPI1_SCK_I2S1_CK
value|0x1306
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_SPI3_SCK_I2S3_CK
value|0x1307
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_SPI6_SCK
value|0x1309
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_SDMMC2_D2
value|0x130a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_UART7_RX
value|0x130c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_EVENTOUT
value|0x1310
end_define

begin_define
define|#
directive|define
name|STM32H7_PB3_FUNC_ANALOG
value|0x1311
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_GPIO
value|0x1400
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_NJTRST
value|0x1401
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_TIM16_BKIN
value|0x1402
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_TIM3_CH1
value|0x1403
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_HRTIM_EEV6
value|0x1404
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_SPI1_MISO_I2S1_SDI
value|0x1406
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_SPI3_MISO_I2S3_SDI
value|0x1407
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_SPI2_NSS_I2S2_WS
value|0x1408
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_SPI6_MISO
value|0x1409
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_SDMMC2_D3
value|0x140a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_UART7_TX
value|0x140c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_EVENTOUT
value|0x1410
end_define

begin_define
define|#
directive|define
name|STM32H7_PB4_FUNC_ANALOG
value|0x1411
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_GPIO
value|0x1500
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_TIM17_BKIN
value|0x1502
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_TIM3_CH2
value|0x1503
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_HRTIM_EEV7
value|0x1504
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_I2C1_SMBA
value|0x1505
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_SPI1_MOSI_I2S1_SDO
value|0x1506
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_I2C4_SMBA
value|0x1507
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_SPI3_MOSI_I2S3_SDO
value|0x1508
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_SPI6_MOSI
value|0x1509
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_CAN2_RX
value|0x150a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_OTG_HS_ULPI_D7
value|0x150b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_ETH_PPS_OUT
value|0x150c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_FMC_SDCKE1
value|0x150d
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_DCMI_D10
value|0x150e
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_UART5_RX
value|0x150f
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_EVENTOUT
value|0x1510
end_define

begin_define
define|#
directive|define
name|STM32H7_PB5_FUNC_ANALOG
value|0x1511
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_GPIO
value|0x1600
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_TIM16_CH1N
value|0x1602
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_TIM4_CH1
value|0x1603
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_HRTIM_EEV8
value|0x1604
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_I2C1_SCL
value|0x1605
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_HDMI_CEC
value|0x1606
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_I2C4_SCL
value|0x1607
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_USART1_TX
value|0x1608
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_LPUART1_TX
value|0x1609
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_CAN2_TX
value|0x160a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_QUADSPI_BK1_NCS
value|0x160b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_DFSDM_DATIN5
value|0x160c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_FMC_SDNE1
value|0x160d
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_DCMI_D5
value|0x160e
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_UART5_TX
value|0x160f
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_EVENTOUT
value|0x1610
end_define

begin_define
define|#
directive|define
name|STM32H7_PB6_FUNC_ANALOG
value|0x1611
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_GPIO
value|0x1700
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_TIM17_CH1N
value|0x1702
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_TIM4_CH2
value|0x1703
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_HRTIM_EEV9
value|0x1704
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_I2C1_SDA
value|0x1705
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_I2C4_SDA
value|0x1707
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_USART1_RX
value|0x1708
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_LPUART1_RX
value|0x1709
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_CAN2_TXFD
value|0x170a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_DFSDM_CKIN5
value|0x170c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_FMC_NL
value|0x170d
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_DCMI_VSYNC
value|0x170e
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_EVENTOUT
value|0x1710
end_define

begin_define
define|#
directive|define
name|STM32H7_PB7_FUNC_ANALOG
value|0x1711
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_GPIO
value|0x1800
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_TIM16_CH1
value|0x1802
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_TIM4_CH3
value|0x1803
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_DFSDM_CKIN7
value|0x1804
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_I2C1_SCL
value|0x1805
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_I2C4_SCL
value|0x1807
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_SDMMC1_CKIN
value|0x1808
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_UART4_RX
value|0x1809
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_CAN1_RX
value|0x180a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_SDMMC2_D4
value|0x180b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_ETH_MII_TXD3
value|0x180c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_SDMMC1_D4
value|0x180d
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_DCMI_D6
value|0x180e
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_LCD_B6
value|0x180f
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_EVENTOUT
value|0x1810
end_define

begin_define
define|#
directive|define
name|STM32H7_PB8_FUNC_ANALOG
value|0x1811
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_GPIO
value|0x1900
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_TIM17_CH1
value|0x1902
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_TIM4_CH4
value|0x1903
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_DFSDM_DATIN7
value|0x1904
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_I2C1_SDA
value|0x1905
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_SPI2_NSS_I2S2_WS
value|0x1906
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_I2C4_SDA
value|0x1907
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_SDMMC1_CDIR
value|0x1908
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_UART4_TX
value|0x1909
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_CAN1_TX
value|0x190a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_SDMMC2_D5
value|0x190b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_I2C4_SMBA
value|0x190c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_SDMMC1_D5
value|0x190d
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_DCMI_D7
value|0x190e
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_LCD_B7
value|0x190f
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_EVENTOUT
value|0x1910
end_define

begin_define
define|#
directive|define
name|STM32H7_PB9_FUNC_ANALOG
value|0x1911
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_GPIO
value|0x1a00
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_TIM2_CH3
value|0x1a02
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_HRTIM_SCOUT
value|0x1a03
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_LPTIM2_IN1
value|0x1a04
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_I2C2_SCL
value|0x1a05
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_SPI2_SCK_I2S2_CK
value|0x1a06
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_DFSDM_DATIN7
value|0x1a07
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_USART3_TX
value|0x1a08
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_QUADSPI_BK1_NCS
value|0x1a0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_OTG_HS_ULPI_D3
value|0x1a0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_ETH_MII_RX_ER
value|0x1a0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_LCD_G4
value|0x1a0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_EVENTOUT
value|0x1a10
end_define

begin_define
define|#
directive|define
name|STM32H7_PB10_FUNC_ANALOG
value|0x1a11
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_GPIO
value|0x1b00
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_TIM2_CH4
value|0x1b02
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_HRTIM_SCIN
value|0x1b03
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_LPTIM2_ETR
value|0x1b04
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_I2C2_SDA
value|0x1b05
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_DFSDM_CKIN7
value|0x1b07
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_USART3_RX
value|0x1b08
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_OTG_HS_ULPI_D4
value|0x1b0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_ETH_MII_TX_EN_ETH_RMII_TX_EN
value|0x1b0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_DSI_TE
value|0x1b0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_LCD_G5
value|0x1b0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_EVENTOUT
value|0x1b10
end_define

begin_define
define|#
directive|define
name|STM32H7_PB11_FUNC_ANALOG
value|0x1b11
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_GPIO
value|0x1c00
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_TIM1_BKIN
value|0x1c02
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_I2C2_SMBA
value|0x1c05
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_SPI2_NSS_I2S2_WS
value|0x1c06
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_DFSDM_DATIN1
value|0x1c07
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_USART3_CK
value|0x1c08
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_CAN2_RX
value|0x1c0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_OTG_HS_ULPI_D5
value|0x1c0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_ETH_MII_TXD0_ETH_RMII_TXD0
value|0x1c0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_OTG_HS_ID
value|0x1c0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_TIM1_BKIN_COMP12
value|0x1c0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_UART5_RX
value|0x1c0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_EVENTOUT
value|0x1c10
end_define

begin_define
define|#
directive|define
name|STM32H7_PB12_FUNC_ANALOG
value|0x1c11
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_GPIO
value|0x1d00
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_TIM1_CH1N
value|0x1d02
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_LPTIM2_OUT
value|0x1d04
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_SPI2_SCK_I2S2_CK
value|0x1d06
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_DFSDM_CKIN1
value|0x1d07
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_USART3_CTS_NSS
value|0x1d08
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_CAN2_TX
value|0x1d0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_OTG_HS_ULPI_D6
value|0x1d0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_ETH_MII_TXD1_ETH_RMII_TXD1
value|0x1d0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_UART5_TX
value|0x1d0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_EVENTOUT
value|0x1d10
end_define

begin_define
define|#
directive|define
name|STM32H7_PB13_FUNC_ANALOG
value|0x1d11
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_GPIO
value|0x1e00
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_TIM1_CH2N
value|0x1e02
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_TIM8_CH2N
value|0x1e04
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_USART1_TX
value|0x1e05
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_SPI2_MISO_I2S2_SDI
value|0x1e06
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_DFSDM_DATIN2
value|0x1e07
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_USART3_RTS
value|0x1e08
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_UART4_RTS
value|0x1e09
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_SDMMC2_D0
value|0x1e0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_OTG_HS_DM
value|0x1e0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_EVENTOUT
value|0x1e10
end_define

begin_define
define|#
directive|define
name|STM32H7_PB14_FUNC_ANALOG
value|0x1e11
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_GPIO
value|0x1f00
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_RTC_REFIN
value|0x1f01
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_TIM1_CH3N
value|0x1f02
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_TIM8_CH3N
value|0x1f04
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_USART1_RX
value|0x1f05
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_SPI2_MOSI_I2S2_SDO
value|0x1f06
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_DFSDM_CKIN2
value|0x1f07
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_UART4_CTS
value|0x1f09
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_SDMMC2_D1
value|0x1f0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_OTG_HS_DP
value|0x1f0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_EVENTOUT
value|0x1f10
end_define

begin_define
define|#
directive|define
name|STM32H7_PB15_FUNC_ANALOG
value|0x1f11
end_define

begin_define
define|#
directive|define
name|STM32H7_PC0_FUNC_GPIO
value|0x2000
end_define

begin_define
define|#
directive|define
name|STM32H7_PC0_FUNC_DFSDM_CKIN0
value|0x2004
end_define

begin_define
define|#
directive|define
name|STM32H7_PC0_FUNC_DFSDM_DATIN4
value|0x2007
end_define

begin_define
define|#
directive|define
name|STM32H7_PC0_FUNC_SAI2_FS_B
value|0x2009
end_define

begin_define
define|#
directive|define
name|STM32H7_PC0_FUNC_OTG_HS_ULPI_STP
value|0x200b
end_define

begin_define
define|#
directive|define
name|STM32H7_PC0_FUNC_FMC_SDNWE
value|0x200d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC0_FUNC_LCD_R5
value|0x200f
end_define

begin_define
define|#
directive|define
name|STM32H7_PC0_FUNC_EVENTOUT
value|0x2010
end_define

begin_define
define|#
directive|define
name|STM32H7_PC0_FUNC_ANALOG
value|0x2011
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_GPIO
value|0x2100
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_TRACED0
value|0x2101
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_SAI1_D1
value|0x2103
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_DFSDM_DATIN0
value|0x2104
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_DFSDM_CKIN4
value|0x2105
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_SPI2_MOSI_I2S2_SDO
value|0x2106
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_SAI1_SD_A
value|0x2107
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_SAI4_SD_A
value|0x2109
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_SDMMC2_CK
value|0x210a
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_SAI4_D1
value|0x210b
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_ETH_MDC
value|0x210c
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_MDIOS_MDC
value|0x210d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_EVENTOUT
value|0x2110
end_define

begin_define
define|#
directive|define
name|STM32H7_PC1_FUNC_ANALOG
value|0x2111
end_define

begin_define
define|#
directive|define
name|STM32H7_PC2_FUNC_GPIO
value|0x2200
end_define

begin_define
define|#
directive|define
name|STM32H7_PC2_FUNC_DFSDM_CKIN1
value|0x2204
end_define

begin_define
define|#
directive|define
name|STM32H7_PC2_FUNC_SPI2_MISO_I2S2_SDI
value|0x2206
end_define

begin_define
define|#
directive|define
name|STM32H7_PC2_FUNC_DFSDM_CKOUT
value|0x2207
end_define

begin_define
define|#
directive|define
name|STM32H7_PC2_FUNC_OTG_HS_ULPI_DIR
value|0x220b
end_define

begin_define
define|#
directive|define
name|STM32H7_PC2_FUNC_ETH_MII_TXD2
value|0x220c
end_define

begin_define
define|#
directive|define
name|STM32H7_PC2_FUNC_FMC_SDNE0
value|0x220d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC2_FUNC_EVENTOUT
value|0x2210
end_define

begin_define
define|#
directive|define
name|STM32H7_PC2_FUNC_ANALOG
value|0x2211
end_define

begin_define
define|#
directive|define
name|STM32H7_PC3_FUNC_GPIO
value|0x2300
end_define

begin_define
define|#
directive|define
name|STM32H7_PC3_FUNC_DFSDM_DATIN1
value|0x2304
end_define

begin_define
define|#
directive|define
name|STM32H7_PC3_FUNC_SPI2_MOSI_I2S2_SDO
value|0x2306
end_define

begin_define
define|#
directive|define
name|STM32H7_PC3_FUNC_OTG_HS_ULPI_NXT
value|0x230b
end_define

begin_define
define|#
directive|define
name|STM32H7_PC3_FUNC_ETH_MII_TX_CLK
value|0x230c
end_define

begin_define
define|#
directive|define
name|STM32H7_PC3_FUNC_FMC_SDCKE0
value|0x230d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC3_FUNC_EVENTOUT
value|0x2310
end_define

begin_define
define|#
directive|define
name|STM32H7_PC3_FUNC_ANALOG
value|0x2311
end_define

begin_define
define|#
directive|define
name|STM32H7_PC4_FUNC_GPIO
value|0x2400
end_define

begin_define
define|#
directive|define
name|STM32H7_PC4_FUNC_DFSDM_CKIN2
value|0x2404
end_define

begin_define
define|#
directive|define
name|STM32H7_PC4_FUNC_I2S1_MCK
value|0x2406
end_define

begin_define
define|#
directive|define
name|STM32H7_PC4_FUNC_SPDIFRX_IN2
value|0x240a
end_define

begin_define
define|#
directive|define
name|STM32H7_PC4_FUNC_ETH_MII_RXD0_ETH_RMII_RXD0
value|0x240c
end_define

begin_define
define|#
directive|define
name|STM32H7_PC4_FUNC_FMC_SDNE0
value|0x240d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC4_FUNC_EVENTOUT
value|0x2410
end_define

begin_define
define|#
directive|define
name|STM32H7_PC4_FUNC_ANALOG
value|0x2411
end_define

begin_define
define|#
directive|define
name|STM32H7_PC5_FUNC_GPIO
value|0x2500
end_define

begin_define
define|#
directive|define
name|STM32H7_PC5_FUNC_SAI1_D3
value|0x2503
end_define

begin_define
define|#
directive|define
name|STM32H7_PC5_FUNC_DFSDM_DATIN2
value|0x2504
end_define

begin_define
define|#
directive|define
name|STM32H7_PC5_FUNC_SPDIFRX_IN3
value|0x250a
end_define

begin_define
define|#
directive|define
name|STM32H7_PC5_FUNC_SAI4_D3
value|0x250b
end_define

begin_define
define|#
directive|define
name|STM32H7_PC5_FUNC_ETH_MII_RXD1_ETH_RMII_RXD1
value|0x250c
end_define

begin_define
define|#
directive|define
name|STM32H7_PC5_FUNC_FMC_SDCKE0
value|0x250d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC5_FUNC_COMP_1_OUT
value|0x250e
end_define

begin_define
define|#
directive|define
name|STM32H7_PC5_FUNC_EVENTOUT
value|0x2510
end_define

begin_define
define|#
directive|define
name|STM32H7_PC5_FUNC_ANALOG
value|0x2511
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_GPIO
value|0x2600
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_HRTIM_CHA1
value|0x2602
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_TIM3_CH1
value|0x2603
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_TIM8_CH1
value|0x2604
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_DFSDM_CKIN3
value|0x2605
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_I2S2_MCK
value|0x2606
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_USART6_TX
value|0x2608
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_SDMMC1_D0DIR
value|0x2609
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_FMC_NWAIT
value|0x260a
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_SDMMC2_D6
value|0x260b
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_SDMMC1_D6
value|0x260d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_DCMI_D0
value|0x260e
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_LCD_HSYNC
value|0x260f
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_EVENTOUT
value|0x2610
end_define

begin_define
define|#
directive|define
name|STM32H7_PC6_FUNC_ANALOG
value|0x2611
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_GPIO
value|0x2700
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_TRGIO
value|0x2701
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_HRTIM_CHA2
value|0x2702
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_TIM3_CH2
value|0x2703
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_TIM8_CH2
value|0x2704
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_DFSDM_DATIN3
value|0x2705
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_I2S3_MCK
value|0x2707
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_USART6_RX
value|0x2708
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_SDMMC1_D123DIR
value|0x2709
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_FMC_NE1
value|0x270a
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_SDMMC2_D7
value|0x270b
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_SWPMI_TX
value|0x270c
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_SDMMC1_D7
value|0x270d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_DCMI_D1
value|0x270e
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_LCD_G6
value|0x270f
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_EVENTOUT
value|0x2710
end_define

begin_define
define|#
directive|define
name|STM32H7_PC7_FUNC_ANALOG
value|0x2711
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_GPIO
value|0x2800
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_TRACED1
value|0x2801
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_HRTIM_CHB1
value|0x2802
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_TIM3_CH3
value|0x2803
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_TIM8_CH3
value|0x2804
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_USART6_CK
value|0x2808
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_UART5_RTS
value|0x2809
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_FMC_NE2_FMC_NCE
value|0x280a
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_SWPMI_RX
value|0x280c
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_SDMMC1_D0
value|0x280d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_DCMI_D2
value|0x280e
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_EVENTOUT
value|0x2810
end_define

begin_define
define|#
directive|define
name|STM32H7_PC8_FUNC_ANALOG
value|0x2811
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_GPIO
value|0x2900
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_MCO2
value|0x2901
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_TIM3_CH4
value|0x2903
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_TIM8_CH4
value|0x2904
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_I2C3_SDA
value|0x2905
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_I2S_CKIN
value|0x2906
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_UART5_CTS
value|0x2909
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_QUADSPI_BK1_IO0
value|0x290a
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_LCD_G3
value|0x290b
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_SWPMI_SUSPEND
value|0x290c
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_SDMMC1_D1
value|0x290d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_DCMI_D3
value|0x290e
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_LCD_B2
value|0x290f
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_EVENTOUT
value|0x2910
end_define

begin_define
define|#
directive|define
name|STM32H7_PC9_FUNC_ANALOG
value|0x2911
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_GPIO
value|0x2a00
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_HRTIM_EEV1
value|0x2a03
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_DFSDM_CKIN5
value|0x2a04
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_SPI3_SCK_I2S3_CK
value|0x2a07
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_USART3_TX
value|0x2a08
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_UART4_TX
value|0x2a09
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_QUADSPI_BK1_IO1
value|0x2a0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_SDMMC1_D2
value|0x2a0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_DCMI_D8
value|0x2a0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_LCD_R2
value|0x2a0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_EVENTOUT
value|0x2a10
end_define

begin_define
define|#
directive|define
name|STM32H7_PC10_FUNC_ANALOG
value|0x2a11
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_GPIO
value|0x2b00
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_HRTIM_FLT2
value|0x2b03
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_DFSDM_DATIN5
value|0x2b04
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_SPI3_MISO_I2S3_SDI
value|0x2b07
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_USART3_RX
value|0x2b08
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_UART4_RX
value|0x2b09
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_QUADSPI_BK2_NCS
value|0x2b0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_SDMMC1_D3
value|0x2b0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_DCMI_D4
value|0x2b0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_EVENTOUT
value|0x2b10
end_define

begin_define
define|#
directive|define
name|STM32H7_PC11_FUNC_ANALOG
value|0x2b11
end_define

begin_define
define|#
directive|define
name|STM32H7_PC12_FUNC_GPIO
value|0x2c00
end_define

begin_define
define|#
directive|define
name|STM32H7_PC12_FUNC_TRACED3
value|0x2c01
end_define

begin_define
define|#
directive|define
name|STM32H7_PC12_FUNC_HRTIM_EEV2
value|0x2c03
end_define

begin_define
define|#
directive|define
name|STM32H7_PC12_FUNC_SPI3_MOSI_I2S3_SDO
value|0x2c07
end_define

begin_define
define|#
directive|define
name|STM32H7_PC12_FUNC_USART3_CK
value|0x2c08
end_define

begin_define
define|#
directive|define
name|STM32H7_PC12_FUNC_UART5_TX
value|0x2c09
end_define

begin_define
define|#
directive|define
name|STM32H7_PC12_FUNC_SDMMC1_CK
value|0x2c0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PC12_FUNC_DCMI_D9
value|0x2c0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PC12_FUNC_EVENTOUT
value|0x2c10
end_define

begin_define
define|#
directive|define
name|STM32H7_PC12_FUNC_ANALOG
value|0x2c11
end_define

begin_define
define|#
directive|define
name|STM32H7_PC13_FUNC_GPIO
value|0x2d00
end_define

begin_define
define|#
directive|define
name|STM32H7_PC13_FUNC_EVENTOUT
value|0x2d10
end_define

begin_define
define|#
directive|define
name|STM32H7_PC13_FUNC_ANALOG
value|0x2d11
end_define

begin_define
define|#
directive|define
name|STM32H7_PC14_FUNC_GPIO
value|0x2e00
end_define

begin_define
define|#
directive|define
name|STM32H7_PC14_FUNC_EVENTOUT
value|0x2e10
end_define

begin_define
define|#
directive|define
name|STM32H7_PC14_FUNC_ANALOG
value|0x2e11
end_define

begin_define
define|#
directive|define
name|STM32H7_PC15_FUNC_GPIO
value|0x2f00
end_define

begin_define
define|#
directive|define
name|STM32H7_PC15_FUNC_EVENTOUT
value|0x2f10
end_define

begin_define
define|#
directive|define
name|STM32H7_PC15_FUNC_ANALOG
value|0x2f11
end_define

begin_define
define|#
directive|define
name|STM32H7_PD0_FUNC_GPIO
value|0x3000
end_define

begin_define
define|#
directive|define
name|STM32H7_PD0_FUNC_DFSDM_CKIN6
value|0x3004
end_define

begin_define
define|#
directive|define
name|STM32H7_PD0_FUNC_SAI3_SCK_A
value|0x3007
end_define

begin_define
define|#
directive|define
name|STM32H7_PD0_FUNC_UART4_RX
value|0x3009
end_define

begin_define
define|#
directive|define
name|STM32H7_PD0_FUNC_CAN1_RX
value|0x300a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD0_FUNC_FMC_D2_FMC_DA2
value|0x300d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD0_FUNC_EVENTOUT
value|0x3010
end_define

begin_define
define|#
directive|define
name|STM32H7_PD0_FUNC_ANALOG
value|0x3011
end_define

begin_define
define|#
directive|define
name|STM32H7_PD1_FUNC_GPIO
value|0x3100
end_define

begin_define
define|#
directive|define
name|STM32H7_PD1_FUNC_DFSDM_DATIN6
value|0x3104
end_define

begin_define
define|#
directive|define
name|STM32H7_PD1_FUNC_SAI3_SD_A
value|0x3107
end_define

begin_define
define|#
directive|define
name|STM32H7_PD1_FUNC_UART4_TX
value|0x3109
end_define

begin_define
define|#
directive|define
name|STM32H7_PD1_FUNC_CAN1_TX
value|0x310a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD1_FUNC_FMC_D3_FMC_DA3
value|0x310d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD1_FUNC_EVENTOUT
value|0x3110
end_define

begin_define
define|#
directive|define
name|STM32H7_PD1_FUNC_ANALOG
value|0x3111
end_define

begin_define
define|#
directive|define
name|STM32H7_PD2_FUNC_GPIO
value|0x3200
end_define

begin_define
define|#
directive|define
name|STM32H7_PD2_FUNC_TRACED2
value|0x3201
end_define

begin_define
define|#
directive|define
name|STM32H7_PD2_FUNC_TIM3_ETR
value|0x3203
end_define

begin_define
define|#
directive|define
name|STM32H7_PD2_FUNC_UART5_RX
value|0x3209
end_define

begin_define
define|#
directive|define
name|STM32H7_PD2_FUNC_SDMMC1_CMD
value|0x320d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD2_FUNC_DCMI_D11
value|0x320e
end_define

begin_define
define|#
directive|define
name|STM32H7_PD2_FUNC_EVENTOUT
value|0x3210
end_define

begin_define
define|#
directive|define
name|STM32H7_PD2_FUNC_ANALOG
value|0x3211
end_define

begin_define
define|#
directive|define
name|STM32H7_PD3_FUNC_GPIO
value|0x3300
end_define

begin_define
define|#
directive|define
name|STM32H7_PD3_FUNC_DFSDM_CKOUT
value|0x3304
end_define

begin_define
define|#
directive|define
name|STM32H7_PD3_FUNC_SPI2_SCK_I2S2_CK
value|0x3306
end_define

begin_define
define|#
directive|define
name|STM32H7_PD3_FUNC_USART2_CTS_NSS
value|0x3308
end_define

begin_define
define|#
directive|define
name|STM32H7_PD3_FUNC_FMC_CLK
value|0x330d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD3_FUNC_DCMI_D5
value|0x330e
end_define

begin_define
define|#
directive|define
name|STM32H7_PD3_FUNC_LCD_G7
value|0x330f
end_define

begin_define
define|#
directive|define
name|STM32H7_PD3_FUNC_EVENTOUT
value|0x3310
end_define

begin_define
define|#
directive|define
name|STM32H7_PD3_FUNC_ANALOG
value|0x3311
end_define

begin_define
define|#
directive|define
name|STM32H7_PD4_FUNC_GPIO
value|0x3400
end_define

begin_define
define|#
directive|define
name|STM32H7_PD4_FUNC_HRTIM_FLT3
value|0x3403
end_define

begin_define
define|#
directive|define
name|STM32H7_PD4_FUNC_SAI3_FS_A
value|0x3407
end_define

begin_define
define|#
directive|define
name|STM32H7_PD4_FUNC_USART2_RTS
value|0x3408
end_define

begin_define
define|#
directive|define
name|STM32H7_PD4_FUNC_CAN1_RXFD
value|0x340a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD4_FUNC_FMC_NOE
value|0x340d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD4_FUNC_EVENTOUT
value|0x3410
end_define

begin_define
define|#
directive|define
name|STM32H7_PD4_FUNC_ANALOG
value|0x3411
end_define

begin_define
define|#
directive|define
name|STM32H7_PD5_FUNC_GPIO
value|0x3500
end_define

begin_define
define|#
directive|define
name|STM32H7_PD5_FUNC_HRTIM_EEV3
value|0x3503
end_define

begin_define
define|#
directive|define
name|STM32H7_PD5_FUNC_USART2_TX
value|0x3508
end_define

begin_define
define|#
directive|define
name|STM32H7_PD5_FUNC_CAN1_TXFD
value|0x350a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD5_FUNC_FMC_NWE
value|0x350d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD5_FUNC_EVENTOUT
value|0x3510
end_define

begin_define
define|#
directive|define
name|STM32H7_PD5_FUNC_ANALOG
value|0x3511
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_GPIO
value|0x3600
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_SAI1_D1
value|0x3603
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_DFSDM_CKIN4
value|0x3604
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_DFSDM_DATIN1
value|0x3605
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_SPI3_MOSI_I2S3_SDO
value|0x3606
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_SAI1_SD_A
value|0x3607
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_USART2_RX
value|0x3608
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_SAI4_SD_A
value|0x3609
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_CAN2_RXFD
value|0x360a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_SAI4_D1
value|0x360b
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_SDMMC2_CK
value|0x360c
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_FMC_NWAIT
value|0x360d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_DCMI_D10
value|0x360e
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_LCD_B2
value|0x360f
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_EVENTOUT
value|0x3610
end_define

begin_define
define|#
directive|define
name|STM32H7_PD6_FUNC_ANALOG
value|0x3611
end_define

begin_define
define|#
directive|define
name|STM32H7_PD7_FUNC_GPIO
value|0x3700
end_define

begin_define
define|#
directive|define
name|STM32H7_PD7_FUNC_DFSDM_DATIN4
value|0x3704
end_define

begin_define
define|#
directive|define
name|STM32H7_PD7_FUNC_SPI1_MOSI_I2S1_SDO
value|0x3706
end_define

begin_define
define|#
directive|define
name|STM32H7_PD7_FUNC_DFSDM_CKIN1
value|0x3707
end_define

begin_define
define|#
directive|define
name|STM32H7_PD7_FUNC_USART2_CK
value|0x3708
end_define

begin_define
define|#
directive|define
name|STM32H7_PD7_FUNC_SPDIFRX_IN0
value|0x370a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD7_FUNC_SDMMC2_CMD
value|0x370c
end_define

begin_define
define|#
directive|define
name|STM32H7_PD7_FUNC_FMC_NE1
value|0x370d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD7_FUNC_EVENTOUT
value|0x3710
end_define

begin_define
define|#
directive|define
name|STM32H7_PD7_FUNC_ANALOG
value|0x3711
end_define

begin_define
define|#
directive|define
name|STM32H7_PD8_FUNC_GPIO
value|0x3800
end_define

begin_define
define|#
directive|define
name|STM32H7_PD8_FUNC_DFSDM_CKIN3
value|0x3804
end_define

begin_define
define|#
directive|define
name|STM32H7_PD8_FUNC_SAI3_SCK_B
value|0x3807
end_define

begin_define
define|#
directive|define
name|STM32H7_PD8_FUNC_USART3_TX
value|0x3808
end_define

begin_define
define|#
directive|define
name|STM32H7_PD8_FUNC_SPDIFRX_IN1
value|0x380a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD8_FUNC_FMC_D13_FMC_DA13
value|0x380d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD8_FUNC_EVENTOUT
value|0x3810
end_define

begin_define
define|#
directive|define
name|STM32H7_PD8_FUNC_ANALOG
value|0x3811
end_define

begin_define
define|#
directive|define
name|STM32H7_PD9_FUNC_GPIO
value|0x3900
end_define

begin_define
define|#
directive|define
name|STM32H7_PD9_FUNC_DFSDM_DATIN3
value|0x3904
end_define

begin_define
define|#
directive|define
name|STM32H7_PD9_FUNC_SAI3_SD_B
value|0x3907
end_define

begin_define
define|#
directive|define
name|STM32H7_PD9_FUNC_USART3_RX
value|0x3908
end_define

begin_define
define|#
directive|define
name|STM32H7_PD9_FUNC_CAN2_RXFD
value|0x390a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD9_FUNC_FMC_D14_FMC_DA14
value|0x390d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD9_FUNC_EVENTOUT
value|0x3910
end_define

begin_define
define|#
directive|define
name|STM32H7_PD9_FUNC_ANALOG
value|0x3911
end_define

begin_define
define|#
directive|define
name|STM32H7_PD10_FUNC_GPIO
value|0x3a00
end_define

begin_define
define|#
directive|define
name|STM32H7_PD10_FUNC_DFSDM_CKOUT
value|0x3a04
end_define

begin_define
define|#
directive|define
name|STM32H7_PD10_FUNC_SAI3_FS_B
value|0x3a07
end_define

begin_define
define|#
directive|define
name|STM32H7_PD10_FUNC_USART3_CK
value|0x3a08
end_define

begin_define
define|#
directive|define
name|STM32H7_PD10_FUNC_CAN2_TXFD
value|0x3a0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD10_FUNC_FMC_D15_FMC_DA15
value|0x3a0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD10_FUNC_LCD_B3
value|0x3a0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PD10_FUNC_EVENTOUT
value|0x3a10
end_define

begin_define
define|#
directive|define
name|STM32H7_PD10_FUNC_ANALOG
value|0x3a11
end_define

begin_define
define|#
directive|define
name|STM32H7_PD11_FUNC_GPIO
value|0x3b00
end_define

begin_define
define|#
directive|define
name|STM32H7_PD11_FUNC_LPTIM2_IN2
value|0x3b04
end_define

begin_define
define|#
directive|define
name|STM32H7_PD11_FUNC_I2C4_SMBA
value|0x3b05
end_define

begin_define
define|#
directive|define
name|STM32H7_PD11_FUNC_USART3_CTS_NSS
value|0x3b08
end_define

begin_define
define|#
directive|define
name|STM32H7_PD11_FUNC_QUADSPI_BK1_IO0
value|0x3b0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD11_FUNC_SAI2_SD_A
value|0x3b0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PD11_FUNC_FMC_A16
value|0x3b0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD11_FUNC_EVENTOUT
value|0x3b10
end_define

begin_define
define|#
directive|define
name|STM32H7_PD11_FUNC_ANALOG
value|0x3b11
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_GPIO
value|0x3c00
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_LPTIM1_IN1
value|0x3c02
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_TIM4_CH1
value|0x3c03
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_LPTIM2_IN1
value|0x3c04
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_I2C4_SCL
value|0x3c05
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_USART3_RTS
value|0x3c08
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_QUADSPI_BK1_IO1
value|0x3c0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_SAI2_FS_A
value|0x3c0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_FMC_A17
value|0x3c0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_EVENTOUT
value|0x3c10
end_define

begin_define
define|#
directive|define
name|STM32H7_PD12_FUNC_ANALOG
value|0x3c11
end_define

begin_define
define|#
directive|define
name|STM32H7_PD13_FUNC_GPIO
value|0x3d00
end_define

begin_define
define|#
directive|define
name|STM32H7_PD13_FUNC_LPTIM1_OUT
value|0x3d02
end_define

begin_define
define|#
directive|define
name|STM32H7_PD13_FUNC_TIM4_CH2
value|0x3d03
end_define

begin_define
define|#
directive|define
name|STM32H7_PD13_FUNC_I2C4_SDA
value|0x3d05
end_define

begin_define
define|#
directive|define
name|STM32H7_PD13_FUNC_QUADSPI_BK1_IO3
value|0x3d0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PD13_FUNC_SAI2_SCK_A
value|0x3d0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PD13_FUNC_FMC_A18
value|0x3d0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD13_FUNC_EVENTOUT
value|0x3d10
end_define

begin_define
define|#
directive|define
name|STM32H7_PD13_FUNC_ANALOG
value|0x3d11
end_define

begin_define
define|#
directive|define
name|STM32H7_PD14_FUNC_GPIO
value|0x3e00
end_define

begin_define
define|#
directive|define
name|STM32H7_PD14_FUNC_TIM4_CH3
value|0x3e03
end_define

begin_define
define|#
directive|define
name|STM32H7_PD14_FUNC_SAI3_MCLK_B
value|0x3e07
end_define

begin_define
define|#
directive|define
name|STM32H7_PD14_FUNC_UART8_CTS
value|0x3e09
end_define

begin_define
define|#
directive|define
name|STM32H7_PD14_FUNC_FMC_D0_FMC_DA0
value|0x3e0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD14_FUNC_EVENTOUT
value|0x3e10
end_define

begin_define
define|#
directive|define
name|STM32H7_PD14_FUNC_ANALOG
value|0x3e11
end_define

begin_define
define|#
directive|define
name|STM32H7_PD15_FUNC_GPIO
value|0x3f00
end_define

begin_define
define|#
directive|define
name|STM32H7_PD15_FUNC_TIM4_CH4
value|0x3f03
end_define

begin_define
define|#
directive|define
name|STM32H7_PD15_FUNC_SAI3_MCLK_A
value|0x3f07
end_define

begin_define
define|#
directive|define
name|STM32H7_PD15_FUNC_UART8_RTS
value|0x3f09
end_define

begin_define
define|#
directive|define
name|STM32H7_PD15_FUNC_FMC_D1_FMC_DA1
value|0x3f0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PD15_FUNC_EVENTOUT
value|0x3f10
end_define

begin_define
define|#
directive|define
name|STM32H7_PD15_FUNC_ANALOG
value|0x3f11
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_GPIO
value|0x4000
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_LPTIM1_ETR
value|0x4002
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_TIM4_ETR
value|0x4003
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_HRTIM_SCIN
value|0x4004
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_LPTIM2_ETR
value|0x4005
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_UART8_RX
value|0x4009
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_CAN1_RXFD
value|0x400a
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_SAI2_MCK_A
value|0x400b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_FMC_NBL0
value|0x400d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_DCMI_D2
value|0x400e
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_EVENTOUT
value|0x4010
end_define

begin_define
define|#
directive|define
name|STM32H7_PE0_FUNC_ANALOG
value|0x4011
end_define

begin_define
define|#
directive|define
name|STM32H7_PE1_FUNC_GPIO
value|0x4100
end_define

begin_define
define|#
directive|define
name|STM32H7_PE1_FUNC_LPTIM1_IN2
value|0x4102
end_define

begin_define
define|#
directive|define
name|STM32H7_PE1_FUNC_HRTIM_SCOUT
value|0x4104
end_define

begin_define
define|#
directive|define
name|STM32H7_PE1_FUNC_UART8_TX
value|0x4109
end_define

begin_define
define|#
directive|define
name|STM32H7_PE1_FUNC_CAN1_TXFD
value|0x410a
end_define

begin_define
define|#
directive|define
name|STM32H7_PE1_FUNC_FMC_NBL1
value|0x410d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE1_FUNC_DCMI_D3
value|0x410e
end_define

begin_define
define|#
directive|define
name|STM32H7_PE1_FUNC_EVENTOUT
value|0x4110
end_define

begin_define
define|#
directive|define
name|STM32H7_PE1_FUNC_ANALOG
value|0x4111
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_GPIO
value|0x4200
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_TRACECLK
value|0x4201
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_SAI1_CK1
value|0x4203
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_SPI4_SCK
value|0x4206
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_SAI1_MCLK_A
value|0x4207
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_SAI4_MCLK_A
value|0x4209
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_QUADSPI_BK1_IO2
value|0x420a
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_SAI4_CK1
value|0x420b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_ETH_MII_TXD3
value|0x420c
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_FMC_A23
value|0x420d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_EVENTOUT
value|0x4210
end_define

begin_define
define|#
directive|define
name|STM32H7_PE2_FUNC_ANALOG
value|0x4211
end_define

begin_define
define|#
directive|define
name|STM32H7_PE3_FUNC_GPIO
value|0x4300
end_define

begin_define
define|#
directive|define
name|STM32H7_PE3_FUNC_TRACED0
value|0x4301
end_define

begin_define
define|#
directive|define
name|STM32H7_PE3_FUNC_TIM15_BKIN
value|0x4305
end_define

begin_define
define|#
directive|define
name|STM32H7_PE3_FUNC_SAI1_SD_B
value|0x4307
end_define

begin_define
define|#
directive|define
name|STM32H7_PE3_FUNC_SAI4_SD_B
value|0x4309
end_define

begin_define
define|#
directive|define
name|STM32H7_PE3_FUNC_FMC_A19
value|0x430d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE3_FUNC_EVENTOUT
value|0x4310
end_define

begin_define
define|#
directive|define
name|STM32H7_PE3_FUNC_ANALOG
value|0x4311
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_GPIO
value|0x4400
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_TRACED1
value|0x4401
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_SAI1_D2
value|0x4403
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_DFSDM_DATIN3
value|0x4404
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_TIM15_CH1N
value|0x4405
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_SPI4_NSS
value|0x4406
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_SAI1_FS_A
value|0x4407
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_SAI4_FS_A
value|0x4409
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_SAI4_D2
value|0x440b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_FMC_A20
value|0x440d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_DCMI_D4
value|0x440e
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_LCD_B0
value|0x440f
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_EVENTOUT
value|0x4410
end_define

begin_define
define|#
directive|define
name|STM32H7_PE4_FUNC_ANALOG
value|0x4411
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_GPIO
value|0x4500
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_TRACED2
value|0x4501
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_SAI1_CK2
value|0x4503
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_DFSDM_CKIN3
value|0x4504
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_TIM15_CH1
value|0x4505
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_SPI4_MISO
value|0x4506
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_SAI1_SCK_A
value|0x4507
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_SAI4_SCK_A
value|0x4509
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_SAI4_CK2
value|0x450b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_FMC_A21
value|0x450d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_DCMI_D6
value|0x450e
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_LCD_G0
value|0x450f
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_EVENTOUT
value|0x4510
end_define

begin_define
define|#
directive|define
name|STM32H7_PE5_FUNC_ANALOG
value|0x4511
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_GPIO
value|0x4600
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_TRACED3
value|0x4601
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_TIM1_BKIN2
value|0x4602
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_SAI1_D1
value|0x4603
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_TIM15_CH2
value|0x4605
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_SPI4_MOSI
value|0x4606
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_SAI1_SD_A
value|0x4607
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_SAI4_SD_A
value|0x4609
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_SAI4_D1
value|0x460a
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_SAI2_MCK_B
value|0x460b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_TIM1_BKIN2_COMP12
value|0x460c
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_FMC_A22
value|0x460d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_DCMI_D7
value|0x460e
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_LCD_G1
value|0x460f
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_EVENTOUT
value|0x4610
end_define

begin_define
define|#
directive|define
name|STM32H7_PE6_FUNC_ANALOG
value|0x4611
end_define

begin_define
define|#
directive|define
name|STM32H7_PE7_FUNC_GPIO
value|0x4700
end_define

begin_define
define|#
directive|define
name|STM32H7_PE7_FUNC_TIM1_ETR
value|0x4702
end_define

begin_define
define|#
directive|define
name|STM32H7_PE7_FUNC_DFSDM_DATIN2
value|0x4704
end_define

begin_define
define|#
directive|define
name|STM32H7_PE7_FUNC_UART7_RX
value|0x4708
end_define

begin_define
define|#
directive|define
name|STM32H7_PE7_FUNC_QUADSPI_BK2_IO0
value|0x470b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE7_FUNC_FMC_D4_FMC_DA4
value|0x470d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE7_FUNC_EVENTOUT
value|0x4710
end_define

begin_define
define|#
directive|define
name|STM32H7_PE7_FUNC_ANALOG
value|0x4711
end_define

begin_define
define|#
directive|define
name|STM32H7_PE8_FUNC_GPIO
value|0x4800
end_define

begin_define
define|#
directive|define
name|STM32H7_PE8_FUNC_TIM1_CH1N
value|0x4802
end_define

begin_define
define|#
directive|define
name|STM32H7_PE8_FUNC_DFSDM_CKIN2
value|0x4804
end_define

begin_define
define|#
directive|define
name|STM32H7_PE8_FUNC_UART7_TX
value|0x4808
end_define

begin_define
define|#
directive|define
name|STM32H7_PE8_FUNC_QUADSPI_BK2_IO1
value|0x480b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE8_FUNC_FMC_D5_FMC_DA5
value|0x480d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE8_FUNC_COMP_2_OUT
value|0x480e
end_define

begin_define
define|#
directive|define
name|STM32H7_PE8_FUNC_EVENTOUT
value|0x4810
end_define

begin_define
define|#
directive|define
name|STM32H7_PE8_FUNC_ANALOG
value|0x4811
end_define

begin_define
define|#
directive|define
name|STM32H7_PE9_FUNC_GPIO
value|0x4900
end_define

begin_define
define|#
directive|define
name|STM32H7_PE9_FUNC_TIM1_CH1
value|0x4902
end_define

begin_define
define|#
directive|define
name|STM32H7_PE9_FUNC_DFSDM_CKOUT
value|0x4904
end_define

begin_define
define|#
directive|define
name|STM32H7_PE9_FUNC_UART7_RTS
value|0x4908
end_define

begin_define
define|#
directive|define
name|STM32H7_PE9_FUNC_QUADSPI_BK2_IO2
value|0x490b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE9_FUNC_FMC_D6_FMC_DA6
value|0x490d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE9_FUNC_EVENTOUT
value|0x4910
end_define

begin_define
define|#
directive|define
name|STM32H7_PE9_FUNC_ANALOG
value|0x4911
end_define

begin_define
define|#
directive|define
name|STM32H7_PE10_FUNC_GPIO
value|0x4a00
end_define

begin_define
define|#
directive|define
name|STM32H7_PE10_FUNC_TIM1_CH2N
value|0x4a02
end_define

begin_define
define|#
directive|define
name|STM32H7_PE10_FUNC_DFSDM_DATIN4
value|0x4a04
end_define

begin_define
define|#
directive|define
name|STM32H7_PE10_FUNC_UART7_CTS
value|0x4a08
end_define

begin_define
define|#
directive|define
name|STM32H7_PE10_FUNC_QUADSPI_BK2_IO3
value|0x4a0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE10_FUNC_FMC_D7_FMC_DA7
value|0x4a0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE10_FUNC_EVENTOUT
value|0x4a10
end_define

begin_define
define|#
directive|define
name|STM32H7_PE10_FUNC_ANALOG
value|0x4a11
end_define

begin_define
define|#
directive|define
name|STM32H7_PE11_FUNC_GPIO
value|0x4b00
end_define

begin_define
define|#
directive|define
name|STM32H7_PE11_FUNC_TIM1_CH2
value|0x4b02
end_define

begin_define
define|#
directive|define
name|STM32H7_PE11_FUNC_DFSDM_CKIN4
value|0x4b04
end_define

begin_define
define|#
directive|define
name|STM32H7_PE11_FUNC_SPI4_NSS
value|0x4b06
end_define

begin_define
define|#
directive|define
name|STM32H7_PE11_FUNC_SAI2_SD_B
value|0x4b0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE11_FUNC_FMC_D8_FMC_DA8
value|0x4b0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE11_FUNC_LCD_G3
value|0x4b0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PE11_FUNC_EVENTOUT
value|0x4b10
end_define

begin_define
define|#
directive|define
name|STM32H7_PE11_FUNC_ANALOG
value|0x4b11
end_define

begin_define
define|#
directive|define
name|STM32H7_PE12_FUNC_GPIO
value|0x4c00
end_define

begin_define
define|#
directive|define
name|STM32H7_PE12_FUNC_TIM1_CH3N
value|0x4c02
end_define

begin_define
define|#
directive|define
name|STM32H7_PE12_FUNC_DFSDM_DATIN5
value|0x4c04
end_define

begin_define
define|#
directive|define
name|STM32H7_PE12_FUNC_SPI4_SCK
value|0x4c06
end_define

begin_define
define|#
directive|define
name|STM32H7_PE12_FUNC_SAI2_SCK_B
value|0x4c0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE12_FUNC_FMC_D9_FMC_DA9
value|0x4c0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE12_FUNC_COMP_1_OUT
value|0x4c0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PE12_FUNC_LCD_B4
value|0x4c0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PE12_FUNC_EVENTOUT
value|0x4c10
end_define

begin_define
define|#
directive|define
name|STM32H7_PE12_FUNC_ANALOG
value|0x4c11
end_define

begin_define
define|#
directive|define
name|STM32H7_PE13_FUNC_GPIO
value|0x4d00
end_define

begin_define
define|#
directive|define
name|STM32H7_PE13_FUNC_TIM1_CH3
value|0x4d02
end_define

begin_define
define|#
directive|define
name|STM32H7_PE13_FUNC_DFSDM_CKIN5
value|0x4d04
end_define

begin_define
define|#
directive|define
name|STM32H7_PE13_FUNC_SPI4_MISO
value|0x4d06
end_define

begin_define
define|#
directive|define
name|STM32H7_PE13_FUNC_SAI2_FS_B
value|0x4d0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE13_FUNC_FMC_D10_FMC_DA10
value|0x4d0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE13_FUNC_COMP_2_OUT
value|0x4d0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PE13_FUNC_LCD_DE
value|0x4d0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PE13_FUNC_EVENTOUT
value|0x4d10
end_define

begin_define
define|#
directive|define
name|STM32H7_PE13_FUNC_ANALOG
value|0x4d11
end_define

begin_define
define|#
directive|define
name|STM32H7_PE14_FUNC_GPIO
value|0x4e00
end_define

begin_define
define|#
directive|define
name|STM32H7_PE14_FUNC_TIM1_CH4
value|0x4e02
end_define

begin_define
define|#
directive|define
name|STM32H7_PE14_FUNC_SPI4_MOSI
value|0x4e06
end_define

begin_define
define|#
directive|define
name|STM32H7_PE14_FUNC_SAI2_MCK_B
value|0x4e0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PE14_FUNC_FMC_D11_FMC_DA11
value|0x4e0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE14_FUNC_LCD_CLK
value|0x4e0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PE14_FUNC_EVENTOUT
value|0x4e10
end_define

begin_define
define|#
directive|define
name|STM32H7_PE14_FUNC_ANALOG
value|0x4e11
end_define

begin_define
define|#
directive|define
name|STM32H7_PE15_FUNC_GPIO
value|0x4f00
end_define

begin_define
define|#
directive|define
name|STM32H7_PE15_FUNC_TIM1_BKIN
value|0x4f02
end_define

begin_define
define|#
directive|define
name|STM32H7_PE15_FUNC_HDMI__TIM1_BKIN
value|0x4f06
end_define

begin_define
define|#
directive|define
name|STM32H7_PE15_FUNC_FMC_D12_FMC_DA12
value|0x4f0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PE15_FUNC_TIM1_BKIN_COMP12
value|0x4f0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PE15_FUNC_LCD_R7
value|0x4f0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PE15_FUNC_EVENTOUT
value|0x4f10
end_define

begin_define
define|#
directive|define
name|STM32H7_PE15_FUNC_ANALOG
value|0x4f11
end_define

begin_define
define|#
directive|define
name|STM32H7_PF0_FUNC_GPIO
value|0x5000
end_define

begin_define
define|#
directive|define
name|STM32H7_PF0_FUNC_I2C2_SDA
value|0x5005
end_define

begin_define
define|#
directive|define
name|STM32H7_PF0_FUNC_FMC_A0
value|0x500d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF0_FUNC_EVENTOUT
value|0x5010
end_define

begin_define
define|#
directive|define
name|STM32H7_PF0_FUNC_ANALOG
value|0x5011
end_define

begin_define
define|#
directive|define
name|STM32H7_PF1_FUNC_GPIO
value|0x5100
end_define

begin_define
define|#
directive|define
name|STM32H7_PF1_FUNC_I2C2_SCL
value|0x5105
end_define

begin_define
define|#
directive|define
name|STM32H7_PF1_FUNC_FMC_A1
value|0x510d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF1_FUNC_EVENTOUT
value|0x5110
end_define

begin_define
define|#
directive|define
name|STM32H7_PF1_FUNC_ANALOG
value|0x5111
end_define

begin_define
define|#
directive|define
name|STM32H7_PF2_FUNC_GPIO
value|0x5200
end_define

begin_define
define|#
directive|define
name|STM32H7_PF2_FUNC_I2C2_SMBA
value|0x5205
end_define

begin_define
define|#
directive|define
name|STM32H7_PF2_FUNC_FMC_A2
value|0x520d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF2_FUNC_EVENTOUT
value|0x5210
end_define

begin_define
define|#
directive|define
name|STM32H7_PF2_FUNC_ANALOG
value|0x5211
end_define

begin_define
define|#
directive|define
name|STM32H7_PF3_FUNC_GPIO
value|0x5300
end_define

begin_define
define|#
directive|define
name|STM32H7_PF3_FUNC_FMC_A3
value|0x530d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF3_FUNC_EVENTOUT
value|0x5310
end_define

begin_define
define|#
directive|define
name|STM32H7_PF3_FUNC_ANALOG
value|0x5311
end_define

begin_define
define|#
directive|define
name|STM32H7_PF4_FUNC_GPIO
value|0x5400
end_define

begin_define
define|#
directive|define
name|STM32H7_PF4_FUNC_FMC_A4
value|0x540d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF4_FUNC_EVENTOUT
value|0x5410
end_define

begin_define
define|#
directive|define
name|STM32H7_PF4_FUNC_ANALOG
value|0x5411
end_define

begin_define
define|#
directive|define
name|STM32H7_PF5_FUNC_GPIO
value|0x5500
end_define

begin_define
define|#
directive|define
name|STM32H7_PF5_FUNC_FMC_A5
value|0x550d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF5_FUNC_EVENTOUT
value|0x5510
end_define

begin_define
define|#
directive|define
name|STM32H7_PF5_FUNC_ANALOG
value|0x5511
end_define

begin_define
define|#
directive|define
name|STM32H7_PF6_FUNC_GPIO
value|0x5600
end_define

begin_define
define|#
directive|define
name|STM32H7_PF6_FUNC_TIM16_CH1
value|0x5602
end_define

begin_define
define|#
directive|define
name|STM32H7_PF6_FUNC_SPI5_NSS
value|0x5606
end_define

begin_define
define|#
directive|define
name|STM32H7_PF6_FUNC_SAI1_SD_B
value|0x5607
end_define

begin_define
define|#
directive|define
name|STM32H7_PF6_FUNC_UART7_RX
value|0x5608
end_define

begin_define
define|#
directive|define
name|STM32H7_PF6_FUNC_SAI4_SD_B
value|0x5609
end_define

begin_define
define|#
directive|define
name|STM32H7_PF6_FUNC_QUADSPI_BK1_IO3
value|0x560a
end_define

begin_define
define|#
directive|define
name|STM32H7_PF6_FUNC_EVENTOUT
value|0x5610
end_define

begin_define
define|#
directive|define
name|STM32H7_PF6_FUNC_ANALOG
value|0x5611
end_define

begin_define
define|#
directive|define
name|STM32H7_PF7_FUNC_GPIO
value|0x5700
end_define

begin_define
define|#
directive|define
name|STM32H7_PF7_FUNC_TIM17_CH1
value|0x5702
end_define

begin_define
define|#
directive|define
name|STM32H7_PF7_FUNC_SPI5_SCK
value|0x5706
end_define

begin_define
define|#
directive|define
name|STM32H7_PF7_FUNC_SAI1_MCLK_B
value|0x5707
end_define

begin_define
define|#
directive|define
name|STM32H7_PF7_FUNC_UART7_TX
value|0x5708
end_define

begin_define
define|#
directive|define
name|STM32H7_PF7_FUNC_SAI4_MCLK_B
value|0x5709
end_define

begin_define
define|#
directive|define
name|STM32H7_PF7_FUNC_QUADSPI_BK1_IO2
value|0x570a
end_define

begin_define
define|#
directive|define
name|STM32H7_PF7_FUNC_EVENTOUT
value|0x5710
end_define

begin_define
define|#
directive|define
name|STM32H7_PF7_FUNC_ANALOG
value|0x5711
end_define

begin_define
define|#
directive|define
name|STM32H7_PF8_FUNC_GPIO
value|0x5800
end_define

begin_define
define|#
directive|define
name|STM32H7_PF8_FUNC_TIM16_CH1N
value|0x5802
end_define

begin_define
define|#
directive|define
name|STM32H7_PF8_FUNC_SPI5_MISO
value|0x5806
end_define

begin_define
define|#
directive|define
name|STM32H7_PF8_FUNC_SAI1_SCK_B
value|0x5807
end_define

begin_define
define|#
directive|define
name|STM32H7_PF8_FUNC_UART7_RTS
value|0x5808
end_define

begin_define
define|#
directive|define
name|STM32H7_PF8_FUNC_SAI4_SCK_B
value|0x5809
end_define

begin_define
define|#
directive|define
name|STM32H7_PF8_FUNC_TIM13_CH1
value|0x580a
end_define

begin_define
define|#
directive|define
name|STM32H7_PF8_FUNC_QUADSPI_BK1_IO0
value|0x580b
end_define

begin_define
define|#
directive|define
name|STM32H7_PF8_FUNC_EVENTOUT
value|0x5810
end_define

begin_define
define|#
directive|define
name|STM32H7_PF8_FUNC_ANALOG
value|0x5811
end_define

begin_define
define|#
directive|define
name|STM32H7_PF9_FUNC_GPIO
value|0x5900
end_define

begin_define
define|#
directive|define
name|STM32H7_PF9_FUNC_TIM17_CH1N
value|0x5902
end_define

begin_define
define|#
directive|define
name|STM32H7_PF9_FUNC_SPI5_MOSI
value|0x5906
end_define

begin_define
define|#
directive|define
name|STM32H7_PF9_FUNC_SAI1_FS_B
value|0x5907
end_define

begin_define
define|#
directive|define
name|STM32H7_PF9_FUNC_UART7_CTS
value|0x5908
end_define

begin_define
define|#
directive|define
name|STM32H7_PF9_FUNC_SAI4_FS_B
value|0x5909
end_define

begin_define
define|#
directive|define
name|STM32H7_PF9_FUNC_TIM14_CH1
value|0x590a
end_define

begin_define
define|#
directive|define
name|STM32H7_PF9_FUNC_QUADSPI_BK1_IO1
value|0x590b
end_define

begin_define
define|#
directive|define
name|STM32H7_PF9_FUNC_EVENTOUT
value|0x5910
end_define

begin_define
define|#
directive|define
name|STM32H7_PF9_FUNC_ANALOG
value|0x5911
end_define

begin_define
define|#
directive|define
name|STM32H7_PF10_FUNC_GPIO
value|0x5a00
end_define

begin_define
define|#
directive|define
name|STM32H7_PF10_FUNC_TIM16_BKIN
value|0x5a02
end_define

begin_define
define|#
directive|define
name|STM32H7_PF10_FUNC_SAI1_D3
value|0x5a03
end_define

begin_define
define|#
directive|define
name|STM32H7_PF10_FUNC_QUADSPI_CLK
value|0x5a0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PF10_FUNC_SAI4_D3
value|0x5a0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PF10_FUNC_DCMI_D11
value|0x5a0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PF10_FUNC_LCD_DE
value|0x5a0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PF10_FUNC_EVENTOUT
value|0x5a10
end_define

begin_define
define|#
directive|define
name|STM32H7_PF10_FUNC_ANALOG
value|0x5a11
end_define

begin_define
define|#
directive|define
name|STM32H7_PF11_FUNC_GPIO
value|0x5b00
end_define

begin_define
define|#
directive|define
name|STM32H7_PF11_FUNC_SPI5_MOSI
value|0x5b06
end_define

begin_define
define|#
directive|define
name|STM32H7_PF11_FUNC_SAI2_SD_B
value|0x5b0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PF11_FUNC_FMC_SDNRAS
value|0x5b0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF11_FUNC_DCMI_D12
value|0x5b0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PF11_FUNC_EVENTOUT
value|0x5b10
end_define

begin_define
define|#
directive|define
name|STM32H7_PF11_FUNC_ANALOG
value|0x5b11
end_define

begin_define
define|#
directive|define
name|STM32H7_PF12_FUNC_GPIO
value|0x5c00
end_define

begin_define
define|#
directive|define
name|STM32H7_PF12_FUNC_FMC_A6
value|0x5c0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF12_FUNC_EVENTOUT
value|0x5c10
end_define

begin_define
define|#
directive|define
name|STM32H7_PF12_FUNC_ANALOG
value|0x5c11
end_define

begin_define
define|#
directive|define
name|STM32H7_PF13_FUNC_GPIO
value|0x5d00
end_define

begin_define
define|#
directive|define
name|STM32H7_PF13_FUNC_DFSDM_DATIN6
value|0x5d04
end_define

begin_define
define|#
directive|define
name|STM32H7_PF13_FUNC_I2C4_SMBA
value|0x5d05
end_define

begin_define
define|#
directive|define
name|STM32H7_PF13_FUNC_FMC_A7
value|0x5d0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF13_FUNC_EVENTOUT
value|0x5d10
end_define

begin_define
define|#
directive|define
name|STM32H7_PF13_FUNC_ANALOG
value|0x5d11
end_define

begin_define
define|#
directive|define
name|STM32H7_PF14_FUNC_GPIO
value|0x5e00
end_define

begin_define
define|#
directive|define
name|STM32H7_PF14_FUNC_DFSDM_CKIN6
value|0x5e04
end_define

begin_define
define|#
directive|define
name|STM32H7_PF14_FUNC_I2C4_SCL
value|0x5e05
end_define

begin_define
define|#
directive|define
name|STM32H7_PF14_FUNC_FMC_A8
value|0x5e0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF14_FUNC_EVENTOUT
value|0x5e10
end_define

begin_define
define|#
directive|define
name|STM32H7_PF14_FUNC_ANALOG
value|0x5e11
end_define

begin_define
define|#
directive|define
name|STM32H7_PF15_FUNC_GPIO
value|0x5f00
end_define

begin_define
define|#
directive|define
name|STM32H7_PF15_FUNC_I2C4_SDA
value|0x5f05
end_define

begin_define
define|#
directive|define
name|STM32H7_PF15_FUNC_FMC_A9
value|0x5f0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PF15_FUNC_EVENTOUT
value|0x5f10
end_define

begin_define
define|#
directive|define
name|STM32H7_PF15_FUNC_ANALOG
value|0x5f11
end_define

begin_define
define|#
directive|define
name|STM32H7_PG0_FUNC_GPIO
value|0x6000
end_define

begin_define
define|#
directive|define
name|STM32H7_PG0_FUNC_FMC_A10
value|0x600d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG0_FUNC_EVENTOUT
value|0x6010
end_define

begin_define
define|#
directive|define
name|STM32H7_PG0_FUNC_ANALOG
value|0x6011
end_define

begin_define
define|#
directive|define
name|STM32H7_PG1_FUNC_GPIO
value|0x6100
end_define

begin_define
define|#
directive|define
name|STM32H7_PG1_FUNC_FMC_A11
value|0x610d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG1_FUNC_EVENTOUT
value|0x6110
end_define

begin_define
define|#
directive|define
name|STM32H7_PG1_FUNC_ANALOG
value|0x6111
end_define

begin_define
define|#
directive|define
name|STM32H7_PG2_FUNC_GPIO
value|0x6200
end_define

begin_define
define|#
directive|define
name|STM32H7_PG2_FUNC_TIM8_BKIN
value|0x6204
end_define

begin_define
define|#
directive|define
name|STM32H7_PG2_FUNC_TIM8_BKIN_COMP12
value|0x620c
end_define

begin_define
define|#
directive|define
name|STM32H7_PG2_FUNC_FMC_A12
value|0x620d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG2_FUNC_EVENTOUT
value|0x6210
end_define

begin_define
define|#
directive|define
name|STM32H7_PG2_FUNC_ANALOG
value|0x6211
end_define

begin_define
define|#
directive|define
name|STM32H7_PG3_FUNC_GPIO
value|0x6300
end_define

begin_define
define|#
directive|define
name|STM32H7_PG3_FUNC_TIM8_BKIN2
value|0x6304
end_define

begin_define
define|#
directive|define
name|STM32H7_PG3_FUNC_TIM8_BKIN2_COMP12
value|0x630c
end_define

begin_define
define|#
directive|define
name|STM32H7_PG3_FUNC_FMC_A13
value|0x630d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG3_FUNC_EVENTOUT
value|0x6310
end_define

begin_define
define|#
directive|define
name|STM32H7_PG3_FUNC_ANALOG
value|0x6311
end_define

begin_define
define|#
directive|define
name|STM32H7_PG4_FUNC_GPIO
value|0x6400
end_define

begin_define
define|#
directive|define
name|STM32H7_PG4_FUNC_TIM1_BKIN2
value|0x6402
end_define

begin_define
define|#
directive|define
name|STM32H7_PG4_FUNC_TIM1_BKIN2_COMP12
value|0x640c
end_define

begin_define
define|#
directive|define
name|STM32H7_PG4_FUNC_FMC_A14_FMC_BA0
value|0x640d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG4_FUNC_EVENTOUT
value|0x6410
end_define

begin_define
define|#
directive|define
name|STM32H7_PG4_FUNC_ANALOG
value|0x6411
end_define

begin_define
define|#
directive|define
name|STM32H7_PG5_FUNC_GPIO
value|0x6500
end_define

begin_define
define|#
directive|define
name|STM32H7_PG5_FUNC_TIM1_ETR
value|0x6502
end_define

begin_define
define|#
directive|define
name|STM32H7_PG5_FUNC_FMC_A15_FMC_BA1
value|0x650d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG5_FUNC_EVENTOUT
value|0x6510
end_define

begin_define
define|#
directive|define
name|STM32H7_PG5_FUNC_ANALOG
value|0x6511
end_define

begin_define
define|#
directive|define
name|STM32H7_PG6_FUNC_GPIO
value|0x6600
end_define

begin_define
define|#
directive|define
name|STM32H7_PG6_FUNC_TIM17_BKIN
value|0x6602
end_define

begin_define
define|#
directive|define
name|STM32H7_PG6_FUNC_HRTIM_CHE1
value|0x6603
end_define

begin_define
define|#
directive|define
name|STM32H7_PG6_FUNC_QUADSPI_BK1_NCS
value|0x660b
end_define

begin_define
define|#
directive|define
name|STM32H7_PG6_FUNC_FMC_NE3
value|0x660d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG6_FUNC_DCMI_D12
value|0x660e
end_define

begin_define
define|#
directive|define
name|STM32H7_PG6_FUNC_LCD_R7
value|0x660f
end_define

begin_define
define|#
directive|define
name|STM32H7_PG6_FUNC_EVENTOUT
value|0x6610
end_define

begin_define
define|#
directive|define
name|STM32H7_PG6_FUNC_ANALOG
value|0x6611
end_define

begin_define
define|#
directive|define
name|STM32H7_PG7_FUNC_GPIO
value|0x6700
end_define

begin_define
define|#
directive|define
name|STM32H7_PG7_FUNC_HRTIM_CHE2
value|0x6703
end_define

begin_define
define|#
directive|define
name|STM32H7_PG7_FUNC_SAI1_MCLK_A
value|0x6707
end_define

begin_define
define|#
directive|define
name|STM32H7_PG7_FUNC_USART6_CK
value|0x6708
end_define

begin_define
define|#
directive|define
name|STM32H7_PG7_FUNC_FMC_INT
value|0x670d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG7_FUNC_DCMI_D13
value|0x670e
end_define

begin_define
define|#
directive|define
name|STM32H7_PG7_FUNC_LCD_CLK
value|0x670f
end_define

begin_define
define|#
directive|define
name|STM32H7_PG7_FUNC_EVENTOUT
value|0x6710
end_define

begin_define
define|#
directive|define
name|STM32H7_PG7_FUNC_ANALOG
value|0x6711
end_define

begin_define
define|#
directive|define
name|STM32H7_PG8_FUNC_GPIO
value|0x6800
end_define

begin_define
define|#
directive|define
name|STM32H7_PG8_FUNC_TIM8_ETR
value|0x6804
end_define

begin_define
define|#
directive|define
name|STM32H7_PG8_FUNC_SPI6_NSS
value|0x6806
end_define

begin_define
define|#
directive|define
name|STM32H7_PG8_FUNC_USART6_RTS
value|0x6808
end_define

begin_define
define|#
directive|define
name|STM32H7_PG8_FUNC_SPDIFRX_IN2
value|0x6809
end_define

begin_define
define|#
directive|define
name|STM32H7_PG8_FUNC_ETH_PPS_OUT
value|0x680c
end_define

begin_define
define|#
directive|define
name|STM32H7_PG8_FUNC_FMC_SDCLK
value|0x680d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG8_FUNC_LCD_G7
value|0x680f
end_define

begin_define
define|#
directive|define
name|STM32H7_PG8_FUNC_EVENTOUT
value|0x6810
end_define

begin_define
define|#
directive|define
name|STM32H7_PG8_FUNC_ANALOG
value|0x6811
end_define

begin_define
define|#
directive|define
name|STM32H7_PG9_FUNC_GPIO
value|0x6900
end_define

begin_define
define|#
directive|define
name|STM32H7_PG9_FUNC_SPI1_MISO_I2S1_SDI
value|0x6906
end_define

begin_define
define|#
directive|define
name|STM32H7_PG9_FUNC_USART6_RX
value|0x6908
end_define

begin_define
define|#
directive|define
name|STM32H7_PG9_FUNC_SPDIFRX_IN3
value|0x6909
end_define

begin_define
define|#
directive|define
name|STM32H7_PG9_FUNC_QUADSPI_BK2_IO2
value|0x690a
end_define

begin_define
define|#
directive|define
name|STM32H7_PG9_FUNC_SAI2_FS_B
value|0x690b
end_define

begin_define
define|#
directive|define
name|STM32H7_PG9_FUNC_FMC_NE2_FMC_NCE
value|0x690d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG9_FUNC_DCMI_VSYNC
value|0x690e
end_define

begin_define
define|#
directive|define
name|STM32H7_PG9_FUNC_EVENTOUT
value|0x6910
end_define

begin_define
define|#
directive|define
name|STM32H7_PG9_FUNC_ANALOG
value|0x6911
end_define

begin_define
define|#
directive|define
name|STM32H7_PG10_FUNC_GPIO
value|0x6a00
end_define

begin_define
define|#
directive|define
name|STM32H7_PG10_FUNC_HRTIM_FLT5
value|0x6a03
end_define

begin_define
define|#
directive|define
name|STM32H7_PG10_FUNC_SPI1_NSS_I2S1_WS
value|0x6a06
end_define

begin_define
define|#
directive|define
name|STM32H7_PG10_FUNC_LCD_G3
value|0x6a0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PG10_FUNC_SAI2_SD_B
value|0x6a0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PG10_FUNC_FMC_NE3
value|0x6a0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG10_FUNC_DCMI_D2
value|0x6a0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PG10_FUNC_LCD_B2
value|0x6a0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PG10_FUNC_EVENTOUT
value|0x6a10
end_define

begin_define
define|#
directive|define
name|STM32H7_PG10_FUNC_ANALOG
value|0x6a11
end_define

begin_define
define|#
directive|define
name|STM32H7_PG11_FUNC_GPIO
value|0x6b00
end_define

begin_define
define|#
directive|define
name|STM32H7_PG11_FUNC_HRTIM_EEV4
value|0x6b03
end_define

begin_define
define|#
directive|define
name|STM32H7_PG11_FUNC_SPI1_SCK_I2S1_CK
value|0x6b06
end_define

begin_define
define|#
directive|define
name|STM32H7_PG11_FUNC_SPDIFRX_IN0
value|0x6b09
end_define

begin_define
define|#
directive|define
name|STM32H7_PG11_FUNC_SDMMC2_D2
value|0x6b0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PG11_FUNC_ETH_MII_TX_EN_ETH_RMII_TX_EN
value|0x6b0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PG11_FUNC_DCMI_D3
value|0x6b0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PG11_FUNC_LCD_B3
value|0x6b0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PG11_FUNC_EVENTOUT
value|0x6b10
end_define

begin_define
define|#
directive|define
name|STM32H7_PG11_FUNC_ANALOG
value|0x6b11
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_GPIO
value|0x6c00
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_LPTIM1_IN1
value|0x6c02
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_HRTIM_EEV5
value|0x6c03
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_SPI6_MISO
value|0x6c06
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_USART6_RTS
value|0x6c08
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_SPDIFRX_IN1
value|0x6c09
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_LCD_B4
value|0x6c0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_ETH_MII_TXD1_ETH_RMII_TXD1
value|0x6c0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_FMC_NE4
value|0x6c0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_LCD_B1
value|0x6c0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_EVENTOUT
value|0x6c10
end_define

begin_define
define|#
directive|define
name|STM32H7_PG12_FUNC_ANALOG
value|0x6c11
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_GPIO
value|0x6d00
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_TRACED0
value|0x6d01
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_LPTIM1_OUT
value|0x6d02
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_HRTIM_EEV10
value|0x6d03
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_SPI6_SCK
value|0x6d06
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_USART6_CTS_NSS
value|0x6d08
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_ETH_MII_TXD0_ETH_RMII_TXD0
value|0x6d0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_FMC_A24
value|0x6d0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_LCD_R0
value|0x6d0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_EVENTOUT
value|0x6d10
end_define

begin_define
define|#
directive|define
name|STM32H7_PG13_FUNC_ANALOG
value|0x6d11
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_GPIO
value|0x6e00
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_TRACED1
value|0x6e01
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_LPTIM1_ETR
value|0x6e02
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_SPI6_MOSI
value|0x6e06
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_USART6_TX
value|0x6e08
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_QUADSPI_BK2_IO3
value|0x6e0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_ETH_MII_TXD1_ETH_RMII_TXD1
value|0x6e0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_FMC_A25
value|0x6e0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_LCD_B0
value|0x6e0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_EVENTOUT
value|0x6e10
end_define

begin_define
define|#
directive|define
name|STM32H7_PG14_FUNC_ANALOG
value|0x6e11
end_define

begin_define
define|#
directive|define
name|STM32H7_PG15_FUNC_GPIO
value|0x6f00
end_define

begin_define
define|#
directive|define
name|STM32H7_PG15_FUNC_USART6_CTS_NSS
value|0x6f08
end_define

begin_define
define|#
directive|define
name|STM32H7_PG15_FUNC_FMC_SDNCAS
value|0x6f0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PG15_FUNC_DCMI_D13
value|0x6f0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PG15_FUNC_EVENTOUT
value|0x6f10
end_define

begin_define
define|#
directive|define
name|STM32H7_PG15_FUNC_ANALOG
value|0x6f11
end_define

begin_define
define|#
directive|define
name|STM32H7_PH0_FUNC_GPIO
value|0x7000
end_define

begin_define
define|#
directive|define
name|STM32H7_PH0_FUNC_EVENTOUT
value|0x7010
end_define

begin_define
define|#
directive|define
name|STM32H7_PH0_FUNC_ANALOG
value|0x7011
end_define

begin_define
define|#
directive|define
name|STM32H7_PH1_FUNC_GPIO
value|0x7100
end_define

begin_define
define|#
directive|define
name|STM32H7_PH1_FUNC_EVENTOUT
value|0x7110
end_define

begin_define
define|#
directive|define
name|STM32H7_PH1_FUNC_ANALOG
value|0x7111
end_define

begin_define
define|#
directive|define
name|STM32H7_PH2_FUNC_GPIO
value|0x7200
end_define

begin_define
define|#
directive|define
name|STM32H7_PH2_FUNC_LPTIM1_IN2
value|0x7202
end_define

begin_define
define|#
directive|define
name|STM32H7_PH2_FUNC_QUADSPI_BK2_IO0
value|0x720a
end_define

begin_define
define|#
directive|define
name|STM32H7_PH2_FUNC_SAI2_SCK_B
value|0x720b
end_define

begin_define
define|#
directive|define
name|STM32H7_PH2_FUNC_ETH_MII_CRS
value|0x720c
end_define

begin_define
define|#
directive|define
name|STM32H7_PH2_FUNC_FMC_SDCKE0
value|0x720d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH2_FUNC_LCD_R0
value|0x720f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH2_FUNC_EVENTOUT
value|0x7210
end_define

begin_define
define|#
directive|define
name|STM32H7_PH2_FUNC_ANALOG
value|0x7211
end_define

begin_define
define|#
directive|define
name|STM32H7_PH3_FUNC_GPIO
value|0x7300
end_define

begin_define
define|#
directive|define
name|STM32H7_PH3_FUNC_QUADSPI_BK2_IO1
value|0x730a
end_define

begin_define
define|#
directive|define
name|STM32H7_PH3_FUNC_SAI2_MCK_B
value|0x730b
end_define

begin_define
define|#
directive|define
name|STM32H7_PH3_FUNC_ETH_MII_COL
value|0x730c
end_define

begin_define
define|#
directive|define
name|STM32H7_PH3_FUNC_FMC_SDNE0
value|0x730d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH3_FUNC_LCD_R1
value|0x730f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH3_FUNC_EVENTOUT
value|0x7310
end_define

begin_define
define|#
directive|define
name|STM32H7_PH3_FUNC_ANALOG
value|0x7311
end_define

begin_define
define|#
directive|define
name|STM32H7_PH4_FUNC_GPIO
value|0x7400
end_define

begin_define
define|#
directive|define
name|STM32H7_PH4_FUNC_I2C2_SCL
value|0x7405
end_define

begin_define
define|#
directive|define
name|STM32H7_PH4_FUNC_LCD_G5
value|0x740a
end_define

begin_define
define|#
directive|define
name|STM32H7_PH4_FUNC_OTG_HS_ULPI_NXT
value|0x740b
end_define

begin_define
define|#
directive|define
name|STM32H7_PH4_FUNC_LCD_G4
value|0x740f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH4_FUNC_EVENTOUT
value|0x7410
end_define

begin_define
define|#
directive|define
name|STM32H7_PH4_FUNC_ANALOG
value|0x7411
end_define

begin_define
define|#
directive|define
name|STM32H7_PH5_FUNC_GPIO
value|0x7500
end_define

begin_define
define|#
directive|define
name|STM32H7_PH5_FUNC_I2C2_SDA
value|0x7505
end_define

begin_define
define|#
directive|define
name|STM32H7_PH5_FUNC_SPI5_NSS
value|0x7506
end_define

begin_define
define|#
directive|define
name|STM32H7_PH5_FUNC_FMC_SDNWE
value|0x750d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH5_FUNC_EVENTOUT
value|0x7510
end_define

begin_define
define|#
directive|define
name|STM32H7_PH5_FUNC_ANALOG
value|0x7511
end_define

begin_define
define|#
directive|define
name|STM32H7_PH6_FUNC_GPIO
value|0x7600
end_define

begin_define
define|#
directive|define
name|STM32H7_PH6_FUNC_I2C2_SMBA
value|0x7605
end_define

begin_define
define|#
directive|define
name|STM32H7_PH6_FUNC_SPI5_SCK
value|0x7606
end_define

begin_define
define|#
directive|define
name|STM32H7_PH6_FUNC_ETH_MII_RXD2
value|0x760c
end_define

begin_define
define|#
directive|define
name|STM32H7_PH6_FUNC_FMC_SDNE1
value|0x760d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH6_FUNC_DCMI_D8
value|0x760e
end_define

begin_define
define|#
directive|define
name|STM32H7_PH6_FUNC_EVENTOUT
value|0x7610
end_define

begin_define
define|#
directive|define
name|STM32H7_PH6_FUNC_ANALOG
value|0x7611
end_define

begin_define
define|#
directive|define
name|STM32H7_PH7_FUNC_GPIO
value|0x7700
end_define

begin_define
define|#
directive|define
name|STM32H7_PH7_FUNC_I2C3_SCL
value|0x7705
end_define

begin_define
define|#
directive|define
name|STM32H7_PH7_FUNC_SPI5_MISO
value|0x7706
end_define

begin_define
define|#
directive|define
name|STM32H7_PH7_FUNC_ETH_MII_RXD3
value|0x770c
end_define

begin_define
define|#
directive|define
name|STM32H7_PH7_FUNC_FMC_SDCKE1
value|0x770d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH7_FUNC_DCMI_D9
value|0x770e
end_define

begin_define
define|#
directive|define
name|STM32H7_PH7_FUNC_EVENTOUT
value|0x7710
end_define

begin_define
define|#
directive|define
name|STM32H7_PH7_FUNC_ANALOG
value|0x7711
end_define

begin_define
define|#
directive|define
name|STM32H7_PH8_FUNC_GPIO
value|0x7800
end_define

begin_define
define|#
directive|define
name|STM32H7_PH8_FUNC_TIM5_ETR
value|0x7803
end_define

begin_define
define|#
directive|define
name|STM32H7_PH8_FUNC_I2C3_SDA
value|0x7805
end_define

begin_define
define|#
directive|define
name|STM32H7_PH8_FUNC_FMC_D16
value|0x780d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH8_FUNC_DCMI_HSYNC
value|0x780e
end_define

begin_define
define|#
directive|define
name|STM32H7_PH8_FUNC_LCD_R2
value|0x780f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH8_FUNC_EVENTOUT
value|0x7810
end_define

begin_define
define|#
directive|define
name|STM32H7_PH8_FUNC_ANALOG
value|0x7811
end_define

begin_define
define|#
directive|define
name|STM32H7_PH9_FUNC_GPIO
value|0x7900
end_define

begin_define
define|#
directive|define
name|STM32H7_PH9_FUNC_I2C3_SMBA
value|0x7905
end_define

begin_define
define|#
directive|define
name|STM32H7_PH9_FUNC_FMC_D17
value|0x790d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH9_FUNC_DCMI_D0
value|0x790e
end_define

begin_define
define|#
directive|define
name|STM32H7_PH9_FUNC_LCD_R3
value|0x790f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH9_FUNC_EVENTOUT
value|0x7910
end_define

begin_define
define|#
directive|define
name|STM32H7_PH9_FUNC_ANALOG
value|0x7911
end_define

begin_define
define|#
directive|define
name|STM32H7_PH10_FUNC_GPIO
value|0x7a00
end_define

begin_define
define|#
directive|define
name|STM32H7_PH10_FUNC_TIM5_CH1
value|0x7a03
end_define

begin_define
define|#
directive|define
name|STM32H7_PH10_FUNC_I2C4_SMBA
value|0x7a05
end_define

begin_define
define|#
directive|define
name|STM32H7_PH10_FUNC_FMC_D18
value|0x7a0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH10_FUNC_DCMI_D1
value|0x7a0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PH10_FUNC_LCD_R4
value|0x7a0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH10_FUNC_EVENTOUT
value|0x7a10
end_define

begin_define
define|#
directive|define
name|STM32H7_PH10_FUNC_ANALOG
value|0x7a11
end_define

begin_define
define|#
directive|define
name|STM32H7_PH11_FUNC_GPIO
value|0x7b00
end_define

begin_define
define|#
directive|define
name|STM32H7_PH11_FUNC_TIM5_CH2
value|0x7b03
end_define

begin_define
define|#
directive|define
name|STM32H7_PH11_FUNC_I2C4_SCL
value|0x7b05
end_define

begin_define
define|#
directive|define
name|STM32H7_PH11_FUNC_FMC_D19
value|0x7b0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH11_FUNC_DCMI_D2
value|0x7b0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PH11_FUNC_LCD_R5
value|0x7b0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH11_FUNC_EVENTOUT
value|0x7b10
end_define

begin_define
define|#
directive|define
name|STM32H7_PH11_FUNC_ANALOG
value|0x7b11
end_define

begin_define
define|#
directive|define
name|STM32H7_PH12_FUNC_GPIO
value|0x7c00
end_define

begin_define
define|#
directive|define
name|STM32H7_PH12_FUNC_TIM5_CH3
value|0x7c03
end_define

begin_define
define|#
directive|define
name|STM32H7_PH12_FUNC_I2C4_SDA
value|0x7c05
end_define

begin_define
define|#
directive|define
name|STM32H7_PH12_FUNC_FMC_D20
value|0x7c0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH12_FUNC_DCMI_D3
value|0x7c0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PH12_FUNC_LCD_R6
value|0x7c0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH12_FUNC_EVENTOUT
value|0x7c10
end_define

begin_define
define|#
directive|define
name|STM32H7_PH12_FUNC_ANALOG
value|0x7c11
end_define

begin_define
define|#
directive|define
name|STM32H7_PH13_FUNC_GPIO
value|0x7d00
end_define

begin_define
define|#
directive|define
name|STM32H7_PH13_FUNC_TIM8_CH1N
value|0x7d04
end_define

begin_define
define|#
directive|define
name|STM32H7_PH13_FUNC_UART4_TX
value|0x7d09
end_define

begin_define
define|#
directive|define
name|STM32H7_PH13_FUNC_CAN1_TX
value|0x7d0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PH13_FUNC_FMC_D21
value|0x7d0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH13_FUNC_LCD_G2
value|0x7d0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH13_FUNC_EVENTOUT
value|0x7d10
end_define

begin_define
define|#
directive|define
name|STM32H7_PH13_FUNC_ANALOG
value|0x7d11
end_define

begin_define
define|#
directive|define
name|STM32H7_PH14_FUNC_GPIO
value|0x7e00
end_define

begin_define
define|#
directive|define
name|STM32H7_PH14_FUNC_TIM8_CH2N
value|0x7e04
end_define

begin_define
define|#
directive|define
name|STM32H7_PH14_FUNC_UART4_RX
value|0x7e09
end_define

begin_define
define|#
directive|define
name|STM32H7_PH14_FUNC_CAN1_RX
value|0x7e0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PH14_FUNC_FMC_D22
value|0x7e0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH14_FUNC_DCMI_D4
value|0x7e0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PH14_FUNC_LCD_G3
value|0x7e0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH14_FUNC_EVENTOUT
value|0x7e10
end_define

begin_define
define|#
directive|define
name|STM32H7_PH14_FUNC_ANALOG
value|0x7e11
end_define

begin_define
define|#
directive|define
name|STM32H7_PH15_FUNC_GPIO
value|0x7f00
end_define

begin_define
define|#
directive|define
name|STM32H7_PH15_FUNC_TIM8_CH3N
value|0x7f04
end_define

begin_define
define|#
directive|define
name|STM32H7_PH15_FUNC_CAN1_TXFD
value|0x7f0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PH15_FUNC_FMC_D23
value|0x7f0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PH15_FUNC_DCMI_D11
value|0x7f0e
end_define

begin_define
define|#
directive|define
name|STM32H7_PH15_FUNC_LCD_G4
value|0x7f0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PH15_FUNC_EVENTOUT
value|0x7f10
end_define

begin_define
define|#
directive|define
name|STM32H7_PH15_FUNC_ANALOG
value|0x7f11
end_define

begin_define
define|#
directive|define
name|STM32H7_PI0_FUNC_GPIO
value|0x8000
end_define

begin_define
define|#
directive|define
name|STM32H7_PI0_FUNC_TIM5_CH4
value|0x8003
end_define

begin_define
define|#
directive|define
name|STM32H7_PI0_FUNC_SPI2_NSS_I2S2_WS
value|0x8006
end_define

begin_define
define|#
directive|define
name|STM32H7_PI0_FUNC_CAN1_RXFD
value|0x800a
end_define

begin_define
define|#
directive|define
name|STM32H7_PI0_FUNC_FMC_D24
value|0x800d
end_define

begin_define
define|#
directive|define
name|STM32H7_PI0_FUNC_DCMI_D13
value|0x800e
end_define

begin_define
define|#
directive|define
name|STM32H7_PI0_FUNC_LCD_G5
value|0x800f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI0_FUNC_EVENTOUT
value|0x8010
end_define

begin_define
define|#
directive|define
name|STM32H7_PI0_FUNC_ANALOG
value|0x8011
end_define

begin_define
define|#
directive|define
name|STM32H7_PI1_FUNC_GPIO
value|0x8100
end_define

begin_define
define|#
directive|define
name|STM32H7_PI1_FUNC_TIM8_BKIN2
value|0x8104
end_define

begin_define
define|#
directive|define
name|STM32H7_PI1_FUNC_SPI2_SCK_I2S2_CK
value|0x8106
end_define

begin_define
define|#
directive|define
name|STM32H7_PI1_FUNC_TIM8_BKIN2_COMP12
value|0x810c
end_define

begin_define
define|#
directive|define
name|STM32H7_PI1_FUNC_FMC_D25
value|0x810d
end_define

begin_define
define|#
directive|define
name|STM32H7_PI1_FUNC_DCMI_D8
value|0x810e
end_define

begin_define
define|#
directive|define
name|STM32H7_PI1_FUNC_LCD_G6
value|0x810f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI1_FUNC_EVENTOUT
value|0x8110
end_define

begin_define
define|#
directive|define
name|STM32H7_PI1_FUNC_ANALOG
value|0x8111
end_define

begin_define
define|#
directive|define
name|STM32H7_PI2_FUNC_GPIO
value|0x8200
end_define

begin_define
define|#
directive|define
name|STM32H7_PI2_FUNC_TIM8_CH4
value|0x8204
end_define

begin_define
define|#
directive|define
name|STM32H7_PI2_FUNC_SPI2_MISO_I2S2_SDI
value|0x8206
end_define

begin_define
define|#
directive|define
name|STM32H7_PI2_FUNC_FMC_D26
value|0x820d
end_define

begin_define
define|#
directive|define
name|STM32H7_PI2_FUNC_DCMI_D9
value|0x820e
end_define

begin_define
define|#
directive|define
name|STM32H7_PI2_FUNC_LCD_G7
value|0x820f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI2_FUNC_EVENTOUT
value|0x8210
end_define

begin_define
define|#
directive|define
name|STM32H7_PI2_FUNC_ANALOG
value|0x8211
end_define

begin_define
define|#
directive|define
name|STM32H7_PI3_FUNC_GPIO
value|0x8300
end_define

begin_define
define|#
directive|define
name|STM32H7_PI3_FUNC_TIM8_ETR
value|0x8304
end_define

begin_define
define|#
directive|define
name|STM32H7_PI3_FUNC_SPI2_MOSI_I2S2_SDO
value|0x8306
end_define

begin_define
define|#
directive|define
name|STM32H7_PI3_FUNC_FMC_D27
value|0x830d
end_define

begin_define
define|#
directive|define
name|STM32H7_PI3_FUNC_DCMI_D10
value|0x830e
end_define

begin_define
define|#
directive|define
name|STM32H7_PI3_FUNC_EVENTOUT
value|0x8310
end_define

begin_define
define|#
directive|define
name|STM32H7_PI3_FUNC_ANALOG
value|0x8311
end_define

begin_define
define|#
directive|define
name|STM32H7_PI4_FUNC_GPIO
value|0x8400
end_define

begin_define
define|#
directive|define
name|STM32H7_PI4_FUNC_TIM8_BKIN
value|0x8404
end_define

begin_define
define|#
directive|define
name|STM32H7_PI4_FUNC_SAI2_MCK_A
value|0x840b
end_define

begin_define
define|#
directive|define
name|STM32H7_PI4_FUNC_TIM8_BKIN_COMP12
value|0x840c
end_define

begin_define
define|#
directive|define
name|STM32H7_PI4_FUNC_FMC_NBL2
value|0x840d
end_define

begin_define
define|#
directive|define
name|STM32H7_PI4_FUNC_DCMI_D5
value|0x840e
end_define

begin_define
define|#
directive|define
name|STM32H7_PI4_FUNC_LCD_B4
value|0x840f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI4_FUNC_EVENTOUT
value|0x8410
end_define

begin_define
define|#
directive|define
name|STM32H7_PI4_FUNC_ANALOG
value|0x8411
end_define

begin_define
define|#
directive|define
name|STM32H7_PI5_FUNC_GPIO
value|0x8500
end_define

begin_define
define|#
directive|define
name|STM32H7_PI5_FUNC_TIM8_CH1
value|0x8504
end_define

begin_define
define|#
directive|define
name|STM32H7_PI5_FUNC_SAI2_SCK_A
value|0x850b
end_define

begin_define
define|#
directive|define
name|STM32H7_PI5_FUNC_FMC_NBL3
value|0x850d
end_define

begin_define
define|#
directive|define
name|STM32H7_PI5_FUNC_DCMI_VSYNC
value|0x850e
end_define

begin_define
define|#
directive|define
name|STM32H7_PI5_FUNC_LCD_B5
value|0x850f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI5_FUNC_EVENTOUT
value|0x8510
end_define

begin_define
define|#
directive|define
name|STM32H7_PI5_FUNC_ANALOG
value|0x8511
end_define

begin_define
define|#
directive|define
name|STM32H7_PI6_FUNC_GPIO
value|0x8600
end_define

begin_define
define|#
directive|define
name|STM32H7_PI6_FUNC_TIM8_CH2
value|0x8604
end_define

begin_define
define|#
directive|define
name|STM32H7_PI6_FUNC_SAI2_SD_A
value|0x860b
end_define

begin_define
define|#
directive|define
name|STM32H7_PI6_FUNC_FMC_D28
value|0x860d
end_define

begin_define
define|#
directive|define
name|STM32H7_PI6_FUNC_DCMI_D6
value|0x860e
end_define

begin_define
define|#
directive|define
name|STM32H7_PI6_FUNC_LCD_B6
value|0x860f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI6_FUNC_EVENTOUT
value|0x8610
end_define

begin_define
define|#
directive|define
name|STM32H7_PI6_FUNC_ANALOG
value|0x8611
end_define

begin_define
define|#
directive|define
name|STM32H7_PI7_FUNC_GPIO
value|0x8700
end_define

begin_define
define|#
directive|define
name|STM32H7_PI7_FUNC_TIM8_CH3
value|0x8704
end_define

begin_define
define|#
directive|define
name|STM32H7_PI7_FUNC_SAI2_FS_A
value|0x870b
end_define

begin_define
define|#
directive|define
name|STM32H7_PI7_FUNC_FMC_D29
value|0x870d
end_define

begin_define
define|#
directive|define
name|STM32H7_PI7_FUNC_DCMI_D7
value|0x870e
end_define

begin_define
define|#
directive|define
name|STM32H7_PI7_FUNC_LCD_B7
value|0x870f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI7_FUNC_EVENTOUT
value|0x8710
end_define

begin_define
define|#
directive|define
name|STM32H7_PI7_FUNC_ANALOG
value|0x8711
end_define

begin_define
define|#
directive|define
name|STM32H7_PI8_FUNC_GPIO
value|0x8800
end_define

begin_define
define|#
directive|define
name|STM32H7_PI8_FUNC_EVENTOUT
value|0x8810
end_define

begin_define
define|#
directive|define
name|STM32H7_PI8_FUNC_ANALOG
value|0x8811
end_define

begin_define
define|#
directive|define
name|STM32H7_PI9_FUNC_GPIO
value|0x8900
end_define

begin_define
define|#
directive|define
name|STM32H7_PI9_FUNC_UART4_RX
value|0x8909
end_define

begin_define
define|#
directive|define
name|STM32H7_PI9_FUNC_CAN1_RX
value|0x890a
end_define

begin_define
define|#
directive|define
name|STM32H7_PI9_FUNC_FMC_D30
value|0x890d
end_define

begin_define
define|#
directive|define
name|STM32H7_PI9_FUNC_LCD_VSYNC
value|0x890f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI9_FUNC_EVENTOUT
value|0x8910
end_define

begin_define
define|#
directive|define
name|STM32H7_PI9_FUNC_ANALOG
value|0x8911
end_define

begin_define
define|#
directive|define
name|STM32H7_PI10_FUNC_GPIO
value|0x8a00
end_define

begin_define
define|#
directive|define
name|STM32H7_PI10_FUNC_CAN1_RXFD
value|0x8a0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PI10_FUNC_ETH_MII_RX_ER
value|0x8a0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PI10_FUNC_FMC_D31
value|0x8a0d
end_define

begin_define
define|#
directive|define
name|STM32H7_PI10_FUNC_LCD_HSYNC
value|0x8a0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI10_FUNC_EVENTOUT
value|0x8a10
end_define

begin_define
define|#
directive|define
name|STM32H7_PI10_FUNC_ANALOG
value|0x8a11
end_define

begin_define
define|#
directive|define
name|STM32H7_PI11_FUNC_GPIO
value|0x8b00
end_define

begin_define
define|#
directive|define
name|STM32H7_PI11_FUNC_LCD_G6
value|0x8b0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PI11_FUNC_OTG_HS_ULPI_DIR
value|0x8b0b
end_define

begin_define
define|#
directive|define
name|STM32H7_PI11_FUNC_EVENTOUT
value|0x8b10
end_define

begin_define
define|#
directive|define
name|STM32H7_PI11_FUNC_ANALOG
value|0x8b11
end_define

begin_define
define|#
directive|define
name|STM32H7_PI12_FUNC_GPIO
value|0x8c00
end_define

begin_define
define|#
directive|define
name|STM32H7_PI12_FUNC_ETH_TX_ER
value|0x8c0c
end_define

begin_define
define|#
directive|define
name|STM32H7_PI12_FUNC_LCD_HSYNC
value|0x8c0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI12_FUNC_EVENTOUT
value|0x8c10
end_define

begin_define
define|#
directive|define
name|STM32H7_PI12_FUNC_ANALOG
value|0x8c11
end_define

begin_define
define|#
directive|define
name|STM32H7_PI13_FUNC_GPIO
value|0x8d00
end_define

begin_define
define|#
directive|define
name|STM32H7_PI13_FUNC_LCD_VSYNC
value|0x8d0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI13_FUNC_EVENTOUT
value|0x8d10
end_define

begin_define
define|#
directive|define
name|STM32H7_PI13_FUNC_ANALOG
value|0x8d11
end_define

begin_define
define|#
directive|define
name|STM32H7_PI14_FUNC_GPIO
value|0x8e00
end_define

begin_define
define|#
directive|define
name|STM32H7_PI14_FUNC_LCD_CLK
value|0x8e0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI14_FUNC_EVENTOUT
value|0x8e10
end_define

begin_define
define|#
directive|define
name|STM32H7_PI14_FUNC_ANALOG
value|0x8e11
end_define

begin_define
define|#
directive|define
name|STM32H7_PI15_FUNC_GPIO
value|0x8f00
end_define

begin_define
define|#
directive|define
name|STM32H7_PI15_FUNC_LCD_G2
value|0x8f0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PI15_FUNC_LCD_R0
value|0x8f0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PI15_FUNC_EVENTOUT
value|0x8f10
end_define

begin_define
define|#
directive|define
name|STM32H7_PI15_FUNC_ANALOG
value|0x8f11
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ0_FUNC_GPIO
value|0x9000
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ0_FUNC_LCD_R7
value|0x900a
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ0_FUNC_LCD_R1
value|0x900f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ0_FUNC_EVENTOUT
value|0x9010
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ0_FUNC_ANALOG
value|0x9011
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ1_FUNC_GPIO
value|0x9100
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ1_FUNC_LCD_R2
value|0x910f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ1_FUNC_EVENTOUT
value|0x9110
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ1_FUNC_ANALOG
value|0x9111
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ2_FUNC_GPIO
value|0x9200
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ2_FUNC_DSI_TE
value|0x920e
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ2_FUNC_LCD_R3
value|0x920f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ2_FUNC_EVENTOUT
value|0x9210
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ2_FUNC_ANALOG
value|0x9211
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ3_FUNC_GPIO
value|0x9300
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ3_FUNC_LCD_R4
value|0x930f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ3_FUNC_EVENTOUT
value|0x9310
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ3_FUNC_ANALOG
value|0x9311
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ4_FUNC_GPIO
value|0x9400
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ4_FUNC_LCD_R5
value|0x940f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ4_FUNC_EVENTOUT
value|0x9410
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ4_FUNC_ANALOG
value|0x9411
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ5_FUNC_GPIO
value|0x9500
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ5_FUNC_LCD_R6
value|0x950f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ5_FUNC_EVENTOUT
value|0x9510
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ5_FUNC_ANALOG
value|0x9511
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ6_FUNC_GPIO
value|0x9600
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ6_FUNC_TIM8_CH2
value|0x9604
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ6_FUNC_LCD_R7
value|0x960f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ6_FUNC_EVENTOUT
value|0x9610
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ6_FUNC_ANALOG
value|0x9611
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ7_FUNC_GPIO
value|0x9700
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ7_FUNC_TRGIN
value|0x9701
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ7_FUNC_TIM8_CH2N
value|0x9704
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ7_FUNC_LCD_G0
value|0x970f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ7_FUNC_EVENTOUT
value|0x9710
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ7_FUNC_ANALOG
value|0x9711
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ8_FUNC_GPIO
value|0x9800
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ8_FUNC_TIM1_CH3N
value|0x9802
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ8_FUNC_TIM8_CH1
value|0x9804
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ8_FUNC_UART8_TX
value|0x9809
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ8_FUNC_LCD_G1
value|0x980f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ8_FUNC_EVENTOUT
value|0x9810
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ8_FUNC_ANALOG
value|0x9811
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ9_FUNC_GPIO
value|0x9900
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ9_FUNC_TIM1_CH3
value|0x9902
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ9_FUNC_TIM8_CH1N
value|0x9904
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ9_FUNC_UART8_RX
value|0x9909
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ9_FUNC_LCD_G2
value|0x990f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ9_FUNC_EVENTOUT
value|0x9910
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ9_FUNC_ANALOG
value|0x9911
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ10_FUNC_GPIO
value|0x9a00
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ10_FUNC_TIM1_CH2N
value|0x9a02
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ10_FUNC_TIM8_CH2
value|0x9a04
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ10_FUNC_SPI5_MOSI
value|0x9a06
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ10_FUNC_LCD_G3
value|0x9a0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ10_FUNC_EVENTOUT
value|0x9a10
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ10_FUNC_ANALOG
value|0x9a11
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ11_FUNC_GPIO
value|0x9b00
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ11_FUNC_TIM1_CH2
value|0x9b02
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ11_FUNC_TIM8_CH2N
value|0x9b04
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ11_FUNC_SPI5_MISO
value|0x9b06
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ11_FUNC_LCD_G4
value|0x9b0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ11_FUNC_EVENTOUT
value|0x9b10
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ11_FUNC_ANALOG
value|0x9b11
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ12_FUNC_GPIO
value|0x9c00
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ12_FUNC_TRGOUT
value|0x9c01
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ12_FUNC_LCD_G3
value|0x9c0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ12_FUNC_LCD_B0
value|0x9c0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ12_FUNC_EVENTOUT
value|0x9c10
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ12_FUNC_ANALOG
value|0x9c11
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ13_FUNC_GPIO
value|0x9d00
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ13_FUNC_LCD_B4
value|0x9d0a
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ13_FUNC_LCD_B1
value|0x9d0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ13_FUNC_EVENTOUT
value|0x9d10
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ13_FUNC_ANALOG
value|0x9d11
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ14_FUNC_GPIO
value|0x9e00
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ14_FUNC_LCD_B2
value|0x9e0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ14_FUNC_EVENTOUT
value|0x9e10
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ14_FUNC_ANALOG
value|0x9e11
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ15_FUNC_GPIO
value|0x9f00
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ15_FUNC_LCD_B3
value|0x9f0f
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ15_FUNC_EVENTOUT
value|0x9f10
end_define

begin_define
define|#
directive|define
name|STM32H7_PJ15_FUNC_ANALOG
value|0x9f11
end_define

begin_define
define|#
directive|define
name|STM32H7_PK0_FUNC_GPIO
value|0xa000
end_define

begin_define
define|#
directive|define
name|STM32H7_PK0_FUNC_TIM1_CH1N
value|0xa002
end_define

begin_define
define|#
directive|define
name|STM32H7_PK0_FUNC_TIM8_CH3
value|0xa004
end_define

begin_define
define|#
directive|define
name|STM32H7_PK0_FUNC_SPI5_SCK
value|0xa006
end_define

begin_define
define|#
directive|define
name|STM32H7_PK0_FUNC_LCD_G5
value|0xa00f
end_define

begin_define
define|#
directive|define
name|STM32H7_PK0_FUNC_EVENTOUT
value|0xa010
end_define

begin_define
define|#
directive|define
name|STM32H7_PK0_FUNC_ANALOG
value|0xa011
end_define

begin_define
define|#
directive|define
name|STM32H7_PK1_FUNC_GPIO
value|0xa100
end_define

begin_define
define|#
directive|define
name|STM32H7_PK1_FUNC_TIM1_CH1
value|0xa102
end_define

begin_define
define|#
directive|define
name|STM32H7_PK1_FUNC_TIM8_CH3N
value|0xa104
end_define

begin_define
define|#
directive|define
name|STM32H7_PK1_FUNC_SPI5_NSS
value|0xa106
end_define

begin_define
define|#
directive|define
name|STM32H7_PK1_FUNC_LCD_G6
value|0xa10f
end_define

begin_define
define|#
directive|define
name|STM32H7_PK1_FUNC_EVENTOUT
value|0xa110
end_define

begin_define
define|#
directive|define
name|STM32H7_PK1_FUNC_ANALOG
value|0xa111
end_define

begin_define
define|#
directive|define
name|STM32H7_PK2_FUNC_GPIO
value|0xa200
end_define

begin_define
define|#
directive|define
name|STM32H7_PK2_FUNC_TIM1_BKIN
value|0xa202
end_define

begin_define
define|#
directive|define
name|STM32H7_PK2_FUNC_TIM8_BKIN
value|0xa204
end_define

begin_define
define|#
directive|define
name|STM32H7_PK2_FUNC_TIM8_BKIN_COMP12
value|0xa20b
end_define

begin_define
define|#
directive|define
name|STM32H7_PK2_FUNC_TIM1_BKIN_COMP12
value|0xa20c
end_define

begin_define
define|#
directive|define
name|STM32H7_PK2_FUNC_LCD_G7
value|0xa20f
end_define

begin_define
define|#
directive|define
name|STM32H7_PK2_FUNC_EVENTOUT
value|0xa210
end_define

begin_define
define|#
directive|define
name|STM32H7_PK2_FUNC_ANALOG
value|0xa211
end_define

begin_define
define|#
directive|define
name|STM32H7_PK3_FUNC_GPIO
value|0xa300
end_define

begin_define
define|#
directive|define
name|STM32H7_PK3_FUNC_LCD_B4
value|0xa30f
end_define

begin_define
define|#
directive|define
name|STM32H7_PK3_FUNC_EVENTOUT
value|0xa310
end_define

begin_define
define|#
directive|define
name|STM32H7_PK3_FUNC_ANALOG
value|0xa311
end_define

begin_define
define|#
directive|define
name|STM32H7_PK4_FUNC_GPIO
value|0xa400
end_define

begin_define
define|#
directive|define
name|STM32H7_PK4_FUNC_LCD_B5
value|0xa40f
end_define

begin_define
define|#
directive|define
name|STM32H7_PK4_FUNC_EVENTOUT
value|0xa410
end_define

begin_define
define|#
directive|define
name|STM32H7_PK4_FUNC_ANALOG
value|0xa411
end_define

begin_define
define|#
directive|define
name|STM32H7_PK5_FUNC_GPIO
value|0xa500
end_define

begin_define
define|#
directive|define
name|STM32H7_PK5_FUNC_LCD_B6
value|0xa50f
end_define

begin_define
define|#
directive|define
name|STM32H7_PK5_FUNC_EVENTOUT
value|0xa510
end_define

begin_define
define|#
directive|define
name|STM32H7_PK5_FUNC_ANALOG
value|0xa511
end_define

begin_define
define|#
directive|define
name|STM32H7_PK6_FUNC_GPIO
value|0xa600
end_define

begin_define
define|#
directive|define
name|STM32H7_PK6_FUNC_LCD_B7
value|0xa60f
end_define

begin_define
define|#
directive|define
name|STM32H7_PK6_FUNC_EVENTOUT
value|0xa610
end_define

begin_define
define|#
directive|define
name|STM32H7_PK6_FUNC_ANALOG
value|0xa611
end_define

begin_define
define|#
directive|define
name|STM32H7_PK7_FUNC_GPIO
value|0xa700
end_define

begin_define
define|#
directive|define
name|STM32H7_PK7_FUNC_LCD_DE
value|0xa70f
end_define

begin_define
define|#
directive|define
name|STM32H7_PK7_FUNC_EVENTOUT
value|0xa710
end_define

begin_define
define|#
directive|define
name|STM32H7_PK7_FUNC_ANALOG
value|0xa711
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_STM32H7_PINFUNC_H */
end_comment

end_unit

