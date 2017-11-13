begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the STM32H7 RCC IP  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_MFD_STM32H7_RCC_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_MFD_STM32H7_RCC_H
end_define

begin_comment
comment|/* AHB3 */
end_comment

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB3_MDMA
value|0
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB3_DMA2D
value|4
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB3_JPGDEC
value|5
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB3_FMC
value|12
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB3_QUADSPI
value|14
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB3_SDMMC1
value|16
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB3_CPU
value|31
end_define

begin_define
define|#
directive|define
name|STM32H7_AHB3_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32H7_RCC_AHB3_##bit + (0x7C * 8))
end_define

begin_comment
comment|/* AHB1 */
end_comment

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB1_DMA1
value|0
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB1_DMA2
value|1
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB1_ADC12
value|5
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB1_ART
value|14
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB1_ETH1MAC
value|15
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB1_USB1OTG
value|25
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB1_USB2OTG
value|27
end_define

begin_define
define|#
directive|define
name|STM32H7_AHB1_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32H7_RCC_AHB1_##bit + (0x80 * 8))
end_define

begin_comment
comment|/* AHB2 */
end_comment

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB2_CAMITF
value|0
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB2_CRYPT
value|4
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB2_HASH
value|5
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB2_RNG
value|6
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB2_SDMMC2
value|9
end_define

begin_define
define|#
directive|define
name|STM32H7_AHB2_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32H7_RCC_AHB2_##bit + (0x84 * 8))
end_define

begin_comment
comment|/* AHB4 */
end_comment

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOA
value|0
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOB
value|1
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOC
value|2
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOD
value|3
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOE
value|4
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOF
value|5
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOG
value|6
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOH
value|7
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOI
value|8
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOJ
value|9
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_GPIOK
value|10
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_CRC
value|19
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_BDMA
value|21
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_ADC3
value|24
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_AHB4_HSEM
value|25
end_define

begin_define
define|#
directive|define
name|STM32H7_AHB4_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32H7_RCC_AHB4_##bit + (0x88 * 8))
end_define

begin_comment
comment|/* APB3 */
end_comment

begin_define
define|#
directive|define
name|STM32H7_RCC_APB3_LTDC
value|3
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB3_DSI
value|4
end_define

begin_define
define|#
directive|define
name|STM32H7_APB3_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32H7_RCC_APB3_##bit + (0x8C * 8))
end_define

begin_comment
comment|/* APB1L */
end_comment

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_TIM2
value|0
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_TIM3
value|1
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_TIM4
value|2
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_TIM5
value|3
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_TIM6
value|4
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_TIM7
value|5
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_TIM12
value|6
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_TIM13
value|7
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_TIM14
value|8
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_LPTIM1
value|9
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_SPI2
value|14
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_SPI3
value|15
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_SPDIF_RX
value|16
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_USART2
value|17
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_USART3
value|18
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_UART4
value|19
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_UART5
value|20
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_I2C1
value|21
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_I2C2
value|22
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_I2C3
value|23
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_HDMICEC
value|27
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_DAC12
value|29
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_USART7
value|30
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1L_USART8
value|31
end_define

begin_define
define|#
directive|define
name|STM32H7_APB1L_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32H7_RCC_APB1L_##bit + (0x90 * 8))
end_define

begin_comment
comment|/* APB1H */
end_comment

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1H_CRS
value|1
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1H_SWP
value|2
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1H_OPAMP
value|4
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1H_MDIOS
value|5
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB1H_FDCAN
value|8
end_define

begin_define
define|#
directive|define
name|STM32H7_APB1H_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32H7_RCC_APB1H_##bit + (0x94 * 8))
end_define

begin_comment
comment|/* APB2 */
end_comment

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_TIM1
value|0
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_TIM8
value|1
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_USART1
value|4
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_USART6
value|5
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_SPI1
value|12
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_SPI4
value|13
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_TIM15
value|16
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_TIM16
value|17
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_TIM17
value|18
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_SPI5
value|20
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_SAI1
value|22
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_SAI2
value|23
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_SAI3
value|24
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_DFSDM1
value|28
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB2_HRTIM
value|29
end_define

begin_define
define|#
directive|define
name|STM32H7_APB2_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32H7_RCC_APB2_##bit + (0x98 * 8))
end_define

begin_comment
comment|/* APB4 */
end_comment

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_SYSCFG
value|1
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_LPUART1
value|3
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_SPI6
value|5
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_I2C4
value|7
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_LPTIM2
value|9
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_LPTIM3
value|10
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_LPTIM4
value|11
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_LPTIM5
value|12
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_COMP12
value|14
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_VREF
value|15
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_SAI4
value|21
end_define

begin_define
define|#
directive|define
name|STM32H7_RCC_APB4_TMPSENS
value|26
end_define

begin_define
define|#
directive|define
name|STM32H7_APB4_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32H7_RCC_APB4_##bit + (0x9C * 8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_MFD_STM32H7_RCC_H */
end_comment

end_unit

