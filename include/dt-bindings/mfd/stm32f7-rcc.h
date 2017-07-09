begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the STM32F7 RCC IP  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_MFD_STM32F7_RCC_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_MFD_STM32F7_RCC_H
end_define

begin_comment
comment|/* AHB1 */
end_comment

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOA
value|0
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOB
value|1
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOC
value|2
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOD
value|3
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOE
value|4
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOF
value|5
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOG
value|6
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOH
value|7
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOI
value|8
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOJ
value|9
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_GPIOK
value|10
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_CRC
value|12
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_BKPSRAM
value|18
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_DTCMRAM
value|20
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_DMA1
value|21
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_DMA2
value|22
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_DMA2D
value|23
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_ETHMAC
value|25
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_ETHMACTX
value|26
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_ETHMACRX
value|27
end_define

begin_define
define|#
directive|define
name|STM32FF_RCC_AHB1_ETHMACPTP
value|28
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_OTGHS
value|29
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB1_OTGHSULPI
value|30
end_define

begin_define
define|#
directive|define
name|STM32F7_AHB1_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32F7_RCC_AHB1_##bit + (0x10 * 8))
end_define

begin_define
define|#
directive|define
name|STM32F7_AHB1_CLOCK
parameter_list|(
name|bit
parameter_list|)
value|(STM32F7_RCC_AHB1_##bit)
end_define

begin_comment
comment|/* AHB2 */
end_comment

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB2_DCMI
value|0
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB2_CRYP
value|4
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB2_HASH
value|5
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB2_RNG
value|6
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB2_OTGFS
value|7
end_define

begin_define
define|#
directive|define
name|STM32F7_AHB2_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32F7_RCC_AHB2_##bit + (0x14 * 8))
end_define

begin_define
define|#
directive|define
name|STM32F7_AHB2_CLOCK
parameter_list|(
name|bit
parameter_list|)
value|(STM32F7_RCC_AHB2_##bit + 0x20)
end_define

begin_comment
comment|/* AHB3 */
end_comment

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB3_FMC
value|0
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_AHB3_QSPI
value|1
end_define

begin_define
define|#
directive|define
name|STM32F7_AHB3_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32F7_RCC_AHB3_##bit + (0x18 * 8))
end_define

begin_define
define|#
directive|define
name|STM32F7_AHB3_CLOCK
parameter_list|(
name|bit
parameter_list|)
value|(STM32F7_RCC_AHB3_##bit + 0x40)
end_define

begin_comment
comment|/* APB1 */
end_comment

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_TIM2
value|0
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_TIM3
value|1
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_TIM4
value|2
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_TIM5
value|3
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_TIM6
value|4
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_TIM7
value|5
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_TIM12
value|6
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_TIM13
value|7
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_TIM14
value|8
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_LPTIM1
value|9
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_WWDG
value|11
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_SPI2
value|14
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_SPI3
value|15
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_SPDIFRX
value|16
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_UART2
value|17
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_UART3
value|18
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_UART4
value|19
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_UART5
value|20
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_I2C1
value|21
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_I2C2
value|22
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_I2C3
value|23
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_I2C4
value|24
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_CAN1
value|25
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_CAN2
value|26
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_CEC
value|27
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_PWR
value|28
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_DAC
value|29
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_UART7
value|30
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB1_UART8
value|31
end_define

begin_define
define|#
directive|define
name|STM32F7_APB1_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32F7_RCC_APB1_##bit + (0x20 * 8))
end_define

begin_define
define|#
directive|define
name|STM32F7_APB1_CLOCK
parameter_list|(
name|bit
parameter_list|)
value|(STM32F7_RCC_APB1_##bit + 0x80)
end_define

begin_comment
comment|/* APB2 */
end_comment

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_TIM1
value|0
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_TIM8
value|1
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_USART1
value|4
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_USART6
value|5
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_ADC1
value|8
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_ADC2
value|9
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_ADC3
value|10
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_SDMMC1
value|11
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_SPI1
value|12
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_SPI4
value|13
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_SYSCFG
value|14
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_TIM9
value|16
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_TIM10
value|17
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_TIM11
value|18
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_SPI5
value|20
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_SPI6
value|21
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_SAI1
value|22
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_SAI2
value|23
end_define

begin_define
define|#
directive|define
name|STM32F7_RCC_APB2_LTDC
value|26
end_define

begin_define
define|#
directive|define
name|STM32F7_APB2_RESET
parameter_list|(
name|bit
parameter_list|)
value|(STM32F7_RCC_APB2_##bit + (0x24 * 8))
end_define

begin_define
define|#
directive|define
name|STM32F7_APB2_CLOCK
parameter_list|(
name|bit
parameter_list|)
value|(STM32F7_RCC_APB2_##bit + 0xA0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_MFD_STM32F7_RCC_H */
end_comment

end_unit

