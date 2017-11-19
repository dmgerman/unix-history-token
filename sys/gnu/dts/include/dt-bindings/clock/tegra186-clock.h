begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/** @file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACH_T186_CLK_T186_H
end_ifndef

begin_define
define|#
directive|define
name|_MACH_T186_CLK_T186_H
end_define

begin_comment
comment|/**  * @defgroup clock_ids Clock Identifiers  * @{  *   @defgroup extern_input external input clocks  *   @{  *     @def TEGRA186_CLK_OSC  *     @def TEGRA186_CLK_CLK_32K  *     @def TEGRA186_CLK_DTV_INPUT  *     @def TEGRA186_CLK_SOR0_PAD_CLKOUT  *     @def TEGRA186_CLK_SOR1_PAD_CLKOUT  *     @def TEGRA186_CLK_I2S1_SYNC_INPUT  *     @def TEGRA186_CLK_I2S2_SYNC_INPUT  *     @def TEGRA186_CLK_I2S3_SYNC_INPUT  *     @def TEGRA186_CLK_I2S4_SYNC_INPUT  *     @def TEGRA186_CLK_I2S5_SYNC_INPUT  *     @def TEGRA186_CLK_I2S6_SYNC_INPUT  *     @def TEGRA186_CLK_SPDIFIN_SYNC_INPUT  *   @}  *  *   @defgroup extern_output external output clocks  *   @{  *     @def TEGRA186_CLK_EXTPERIPH1  *     @def TEGRA186_CLK_EXTPERIPH2  *     @def TEGRA186_CLK_EXTPERIPH3  *     @def TEGRA186_CLK_EXTPERIPH4  *   @}  *  *   @defgroup display_clks display related clocks  *   @{  *     @def TEGRA186_CLK_CEC  *     @def TEGRA186_CLK_DSIC  *     @def TEGRA186_CLK_DSIC_LP  *     @def TEGRA186_CLK_DSID  *     @def TEGRA186_CLK_DSID_LP  *     @def TEGRA186_CLK_DPAUX1  *     @def TEGRA186_CLK_DPAUX  *     @def TEGRA186_CLK_HDA2HDMICODEC  *     @def TEGRA186_CLK_NVDISPLAY_DISP  *     @def TEGRA186_CLK_NVDISPLAY_DSC  *     @def TEGRA186_CLK_NVDISPLAY_P0  *     @def TEGRA186_CLK_NVDISPLAY_P1  *     @def TEGRA186_CLK_NVDISPLAY_P2  *     @def TEGRA186_CLK_NVDISPLAYHUB  *     @def TEGRA186_CLK_SOR_SAFE  *     @def TEGRA186_CLK_SOR0  *     @def TEGRA186_CLK_SOR0_OUT  *     @def TEGRA186_CLK_SOR1  *     @def TEGRA186_CLK_SOR1_OUT  *     @def TEGRA186_CLK_DSI  *     @def TEGRA186_CLK_MIPI_CAL  *     @def TEGRA186_CLK_DSIA_LP  *     @def TEGRA186_CLK_DSIB  *     @def TEGRA186_CLK_DSIB_LP  *   @}  *  *   @defgroup camera_clks camera related clocks  *   @{  *     @def TEGRA186_CLK_NVCSI  *     @def TEGRA186_CLK_NVCSILP  *     @def TEGRA186_CLK_VI  *   @}  *  *   @defgroup audio_clks audio related clocks  *   @{  *     @def TEGRA186_CLK_ACLK  *     @def TEGRA186_CLK_ADSP  *     @def TEGRA186_CLK_ADSPNEON  *     @def TEGRA186_CLK_AHUB  *     @def TEGRA186_CLK_APE  *     @def TEGRA186_CLK_APB2APE  *     @def TEGRA186_CLK_AUD_MCLK  *     @def TEGRA186_CLK_DMIC1  *     @def TEGRA186_CLK_DMIC2  *     @def TEGRA186_CLK_DMIC3  *     @def TEGRA186_CLK_DMIC4  *     @def TEGRA186_CLK_DSPK1  *     @def TEGRA186_CLK_DSPK2  *     @def TEGRA186_CLK_HDA  *     @def TEGRA186_CLK_HDA2CODEC_2X  *     @def TEGRA186_CLK_I2S1  *     @def TEGRA186_CLK_I2S2  *     @def TEGRA186_CLK_I2S3  *     @def TEGRA186_CLK_I2S4  *     @def TEGRA186_CLK_I2S5  *     @def TEGRA186_CLK_I2S6  *     @def TEGRA186_CLK_MAUD  *     @def TEGRA186_CLK_PLL_A_OUT0  *     @def TEGRA186_CLK_SPDIF_DOUBLER  *     @def TEGRA186_CLK_SPDIF_IN  *     @def TEGRA186_CLK_SPDIF_OUT  *     @def TEGRA186_CLK_SYNC_DMIC1  *     @def TEGRA186_CLK_SYNC_DMIC2  *     @def TEGRA186_CLK_SYNC_DMIC3  *     @def TEGRA186_CLK_SYNC_DMIC4  *     @def TEGRA186_CLK_SYNC_DMIC5  *     @def TEGRA186_CLK_SYNC_DSPK1  *     @def TEGRA186_CLK_SYNC_DSPK2  *     @def TEGRA186_CLK_SYNC_I2S1  *     @def TEGRA186_CLK_SYNC_I2S2  *     @def TEGRA186_CLK_SYNC_I2S3  *     @def TEGRA186_CLK_SYNC_I2S4  *     @def TEGRA186_CLK_SYNC_I2S5  *     @def TEGRA186_CLK_SYNC_I2S6  *     @def TEGRA186_CLK_SYNC_SPDIF  *   @}  *  *   @defgroup uart_clks UART clocks  *   @{  *     @def TEGRA186_CLK_AON_UART_FST_MIPI_CAL  *     @def TEGRA186_CLK_UARTA  *     @def TEGRA186_CLK_UARTB  *     @def TEGRA186_CLK_UARTC  *     @def TEGRA186_CLK_UARTD  *     @def TEGRA186_CLK_UARTE  *     @def TEGRA186_CLK_UARTF  *     @def TEGRA186_CLK_UARTG  *     @def TEGRA186_CLK_UART_FST_MIPI_CAL  *   @}  *  *   @defgroup i2c_clks I2C clocks  *   @{  *     @def TEGRA186_CLK_AON_I2C_SLOW  *     @def TEGRA186_CLK_I2C1  *     @def TEGRA186_CLK_I2C2  *     @def TEGRA186_CLK_I2C3  *     @def TEGRA186_CLK_I2C4  *     @def TEGRA186_CLK_I2C5  *     @def TEGRA186_CLK_I2C6  *     @def TEGRA186_CLK_I2C8  *     @def TEGRA186_CLK_I2C9  *     @def TEGRA186_CLK_I2C1  *     @def TEGRA186_CLK_I2C12  *     @def TEGRA186_CLK_I2C13  *     @def TEGRA186_CLK_I2C14  *     @def TEGRA186_CLK_I2C_SLOW  *     @def TEGRA186_CLK_VI_I2C  *   @}  *  *   @defgroup spi_clks SPI clocks  *   @{  *     @def TEGRA186_CLK_SPI1  *     @def TEGRA186_CLK_SPI2  *     @def TEGRA186_CLK_SPI3  *     @def TEGRA186_CLK_SPI4  *   @}  *  *   @defgroup storage storage related clocks  *   @{  *     @def TEGRA186_CLK_SATA  *     @def TEGRA186_CLK_SATA_OOB  *     @def TEGRA186_CLK_SATA_IOBIST  *     @def TEGRA186_CLK_SDMMC_LEGACY_TM  *     @def TEGRA186_CLK_SDMMC1  *     @def TEGRA186_CLK_SDMMC2  *     @def TEGRA186_CLK_SDMMC3  *     @def TEGRA186_CLK_SDMMC4  *     @def TEGRA186_CLK_QSPI  *     @def TEGRA186_CLK_QSPI_OUT  *     @def TEGRA186_CLK_UFSDEV_REF  *     @def TEGRA186_CLK_UFSHC  *   @}  *  *   @defgroup pwm_clks PWM clocks  *   @{  *     @def TEGRA186_CLK_PWM1  *     @def TEGRA186_CLK_PWM2  *     @def TEGRA186_CLK_PWM3  *     @def TEGRA186_CLK_PWM4  *     @def TEGRA186_CLK_PWM5  *     @def TEGRA186_CLK_PWM6  *     @def TEGRA186_CLK_PWM7  *     @def TEGRA186_CLK_PWM8  *   @}  *  *   @defgroup plls PLLs and related clocks  *   @{  *     @def TEGRA186_CLK_PLLREFE_OUT_GATED  *     @def TEGRA186_CLK_PLLREFE_OUT1  *     @def TEGRA186_CLK_PLLD_OUT1  *     @def TEGRA186_CLK_PLLP_OUT0  *     @def TEGRA186_CLK_PLLP_OUT5  *     @def TEGRA186_CLK_PLLA  *     @def TEGRA186_CLK_PLLE_PWRSEQ  *     @def TEGRA186_CLK_PLLA_OUT1  *     @def TEGRA186_CLK_PLLREFE_REF  *     @def TEGRA186_CLK_UPHY_PLL0_PWRSEQ  *     @def TEGRA186_CLK_UPHY_PLL1_PWRSEQ  *     @def TEGRA186_CLK_PLLREFE_PLLE_PASSTHROUGH  *     @def TEGRA186_CLK_PLLREFE_PEX  *     @def TEGRA186_CLK_PLLREFE_IDDQ  *     @def TEGRA186_CLK_PLLC_OUT_AON  *     @def TEGRA186_CLK_PLLC_OUT_ISP  *     @def TEGRA186_CLK_PLLC_OUT_VE  *     @def TEGRA186_CLK_PLLC4_OUT  *     @def TEGRA186_CLK_PLLREFE_OUT  *     @def TEGRA186_CLK_PLLREFE_PLL_REF  *     @def TEGRA186_CLK_PLLE  *     @def TEGRA186_CLK_PLLC  *     @def TEGRA186_CLK_PLLP  *     @def TEGRA186_CLK_PLLD  *     @def TEGRA186_CLK_PLLD2  *     @def TEGRA186_CLK_PLLREFE_VCO  *     @def TEGRA186_CLK_PLLC2  *     @def TEGRA186_CLK_PLLC3  *     @def TEGRA186_CLK_PLLDP  *     @def TEGRA186_CLK_PLLC4_VCO  *     @def TEGRA186_CLK_PLLA1  *     @def TEGRA186_CLK_PLLNVCSI  *     @def TEGRA186_CLK_PLLDISPHUB  *     @def TEGRA186_CLK_PLLD3  *     @def TEGRA186_CLK_PLLBPMPCAM  *     @def TEGRA186_CLK_PLLAON  *     @def TEGRA186_CLK_PLLU  *     @def TEGRA186_CLK_PLLC4_VCO_DIV2  *     @def TEGRA186_CLK_PLL_REF  *     @def TEGRA186_CLK_PLLREFE_OUT1_DIV5  *     @def TEGRA186_CLK_UTMIP_PLL_PWRSEQ  *     @def TEGRA186_CLK_PLL_U_48M  *     @def TEGRA186_CLK_PLL_U_480M  *     @def TEGRA186_CLK_PLLC4_OUT0  *     @def TEGRA186_CLK_PLLC4_OUT1  *     @def TEGRA186_CLK_PLLC4_OUT2  *     @def TEGRA186_CLK_PLLC4_OUT_MUX  *     @def TEGRA186_CLK_DFLLDISP_DIV  *     @def TEGRA186_CLK_PLLDISPHUB_DIV  *     @def TEGRA186_CLK_PLLP_DIV8  *   @}  *  *   @defgroup nafll_clks NAFLL clock sources  *   @{  *     @def TEGRA186_CLK_NAFLL_AXI_CBB  *     @def TEGRA186_CLK_NAFLL_BCPU  *     @def TEGRA186_CLK_NAFLL_BPMP  *     @def TEGRA186_CLK_NAFLL_DISP  *     @def TEGRA186_CLK_NAFLL_GPU  *     @def TEGRA186_CLK_NAFLL_ISP  *     @def TEGRA186_CLK_NAFLL_MCPU  *     @def TEGRA186_CLK_NAFLL_NVDEC  *     @def TEGRA186_CLK_NAFLL_NVENC  *     @def TEGRA186_CLK_NAFLL_NVJPG  *     @def TEGRA186_CLK_NAFLL_SCE  *     @def TEGRA186_CLK_NAFLL_SE  *     @def TEGRA186_CLK_NAFLL_TSEC  *     @def TEGRA186_CLK_NAFLL_TSECB  *     @def TEGRA186_CLK_NAFLL_VI  *     @def TEGRA186_CLK_NAFLL_VIC  *   @}  *  *   @defgroup mphy MPHY related clocks  *   @{  *     @def TEGRA186_CLK_MPHY_L0_RX_SYMB  *     @def TEGRA186_CLK_MPHY_L0_RX_LS_BIT  *     @def TEGRA186_CLK_MPHY_L0_TX_SYMB  *     @def TEGRA186_CLK_MPHY_L0_TX_LS_3XBIT  *     @def TEGRA186_CLK_MPHY_L0_RX_ANA  *     @def TEGRA186_CLK_MPHY_L1_RX_ANA  *     @def TEGRA186_CLK_MPHY_IOBIST  *     @def TEGRA186_CLK_MPHY_TX_1MHZ_REF  *     @def TEGRA186_CLK_MPHY_CORE_PLL_FIXED  *   @}  *  *   @defgroup eavb EAVB related clocks  *   @{  *     @def TEGRA186_CLK_EQOS_AXI  *     @def TEGRA186_CLK_EQOS_PTP_REF  *     @def TEGRA186_CLK_EQOS_RX  *     @def TEGRA186_CLK_EQOS_RX_INPUT  *     @def TEGRA186_CLK_EQOS_TX  *   @}  *  *   @defgroup usb USB related clocks  *   @{  *     @def TEGRA186_CLK_PEX_USB_PAD0_MGMT  *     @def TEGRA186_CLK_PEX_USB_PAD1_MGMT  *     @def TEGRA186_CLK_HSIC_TRK  *     @def TEGRA186_CLK_USB2_TRK  *     @def TEGRA186_CLK_USB2_HSIC_TRK  *     @def TEGRA186_CLK_XUSB_CORE_SS  *     @def TEGRA186_CLK_XUSB_CORE_DEV  *     @def TEGRA186_CLK_XUSB_FALCON  *     @def TEGRA186_CLK_XUSB_FS  *     @def TEGRA186_CLK_XUSB  *     @def TEGRA186_CLK_XUSB_DEV  *     @def TEGRA186_CLK_XUSB_HOST  *     @def TEGRA186_CLK_XUSB_SS  *   @}  *  *   @defgroup bigblock compute block related clocks  *   @{  *     @def TEGRA186_CLK_GPCCLK  *     @def TEGRA186_CLK_GPC2CLK  *     @def TEGRA186_CLK_GPU  *     @def TEGRA186_CLK_HOST1X  *     @def TEGRA186_CLK_ISP  *     @def TEGRA186_CLK_NVDEC  *     @def TEGRA186_CLK_NVENC  *     @def TEGRA186_CLK_NVJPG  *     @def TEGRA186_CLK_SE  *     @def TEGRA186_CLK_TSEC  *     @def TEGRA186_CLK_TSECB  *     @def TEGRA186_CLK_VIC  *   @}  *  *   @defgroup can CAN bus related clocks  *   @{  *     @def TEGRA186_CLK_CAN1  *     @def TEGRA186_CLK_CAN1_HOST  *     @def TEGRA186_CLK_CAN2  *     @def TEGRA186_CLK_CAN2_HOST  *   @}  *  *   @defgroup system basic system clocks  *   @{  *     @def TEGRA186_CLK_ACTMON  *     @def TEGRA186_CLK_AON_APB  *     @def TEGRA186_CLK_AON_CPU_NIC  *     @def TEGRA186_CLK_AON_NIC  *     @def TEGRA186_CLK_AXI_CBB  *     @def TEGRA186_CLK_BPMP_APB  *     @def TEGRA186_CLK_BPMP_CPU_NIC  *     @def TEGRA186_CLK_BPMP_NIC_RATE  *     @def TEGRA186_CLK_CLK_M  *     @def TEGRA186_CLK_EMC  *     @def TEGRA186_CLK_MSS_ENCRYPT  *     @def TEGRA186_CLK_SCE_APB  *     @def TEGRA186_CLK_SCE_CPU_NIC  *     @def TEGRA186_CLK_SCE_NIC  *     @def TEGRA186_CLK_TSC  *   @}  *  *   @defgroup pcie_clks PCIe related clocks  *   @{  *     @def TEGRA186_CLK_AFI  *     @def TEGRA186_CLK_PCIE  *     @def TEGRA186_CLK_PCIE2_IOBIST  *     @def TEGRA186_CLK_PCIERX0  *     @def TEGRA186_CLK_PCIERX1  *     @def TEGRA186_CLK_PCIERX2  *     @def TEGRA186_CLK_PCIERX3  *     @def TEGRA186_CLK_PCIERX4  *   @}  */
end_comment

begin_comment
comment|/** @brief output of gate CLK_ENB_FUSE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_FUSE
value|0
end_define

begin_comment
comment|/**  * @brief It's not what you think  * @details output of gate CLK_ENB_GPU. This output connects to the GPU  * pwrclk. @warning: This is almost certainly not the clock you think  * it is. If you're looking for the clock of the graphics engine, see  * TEGRA186_GPCCLK  */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_GPU
value|1
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_PCIE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PCIE
value|3
end_define

begin_comment
comment|/** @brief output of the divider IPFS_CLK_DIVISOR */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_AFI
value|4
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_PCIE2_IOBIST */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PCIE2_IOBIST
value|5
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_PCIERX0*/
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PCIERX0
value|6
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_PCIERX1*/
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PCIERX1
value|7
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_PCIERX2*/
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PCIERX2
value|8
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_PCIERX3*/
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PCIERX3
value|9
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_PCIERX4*/
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PCIERX4
value|10
end_define

begin_comment
comment|/** @brief output branch of PLL_C for ISP, controlled by gate CLK_ENB_PLLC_OUT_ISP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC_OUT_ISP
value|11
end_define

begin_comment
comment|/** @brief output branch of PLL_C for VI, controlled by gate CLK_ENB_PLLC_OUT_VE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC_OUT_VE
value|12
end_define

begin_comment
comment|/** @brief output branch of PLL_C for AON domain, controlled by gate CLK_ENB_PLLC_OUT_AON */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC_OUT_AON
value|13
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_SOR_SAFE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SOR_SAFE
value|39
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2S2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S2
value|42
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2S3 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S3
value|43
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SPDF_IN */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SPDIF_IN
value|44
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_SPDIF_DOUBLER */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SPDIF_DOUBLER
value|45
end_define

begin_comment
comment|/**  @clkdesc{spi_clks, out, mux, CLK_RST_CONTROLLER_CLK_SOURCE_SPI3} */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SPI3
value|46
end_define

begin_comment
comment|/** @clkdesc{i2c_clks, out, mux, CLK_RST_CONTROLLER_CLK_SOURCE_I2C1} */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C1
value|47
end_define

begin_comment
comment|/** @clkdesc{i2c_clks, out, mux, CLK_RST_CONTROLLER_CLK_SOURCE_I2C5} */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C5
value|48
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SPI1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SPI1
value|49
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_ISP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_ISP
value|50
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_VI */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_VI
value|51
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SDMMC1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SDMMC1
value|52
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SDMMC2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SDMMC2
value|53
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SDMMC4 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SDMMC4
value|54
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_UARTA */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UARTA
value|55
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_UARTB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UARTB
value|56
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_HOST1X */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_HOST1X
value|57
end_define

begin_comment
comment|/**  * @brief controls the EMC clock frequency.  * @details Doing a clk_set_rate on this clock will select the  * appropriate clock source, program the source rate and execute a  * specific sequence to switch to the new clock source for both memory  * controllers. This can be used to control the balance between memory  * throughput and memory controller power.  */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_EMC
value|58
end_define

begin_comment
comment|/* @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_EXTPERIPH4 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_EXTPERIPH4
value|73
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SPI4 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SPI4
value|74
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C3 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C3
value|75
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SDMMC3 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SDMMC3
value|76
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_UARTD */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UARTD
value|77
end_define

begin_comment
comment|/** output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2S1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S1
value|79
end_define

begin_comment
comment|/** output of gate CLK_ENB_DTV */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DTV
value|80
end_define

begin_comment
comment|/** output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_TSEC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_TSEC
value|81
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_DP2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DP2
value|82
end_define

begin_comment
comment|/** output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2S4 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S4
value|84
end_define

begin_comment
comment|/** output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2S5 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S5
value|85
end_define

begin_comment
comment|/** output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C4 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C4
value|86
end_define

begin_comment
comment|/** output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_AHUB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_AHUB
value|87
end_define

begin_comment
comment|/** output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_HDA2CODEC_2X */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_HDA2CODEC_2X
value|88
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_EXTPERIPH1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_EXTPERIPH1
value|89
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_EXTPERIPH2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_EXTPERIPH2
value|90
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_EXTPERIPH3 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_EXTPERIPH3
value|91
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C_SLOW */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C_SLOW
value|92
end_define

begin_comment
comment|/** @brief output of the SOR1_CLK_SRC mux in CLK_RST_CONTROLLER_CLK_SOURCE_SOR1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SOR1
value|93
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_CEC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_CEC
value|94
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_DPAUX1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DPAUX1
value|95
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_DPAUX */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DPAUX
value|96
end_define

begin_comment
comment|/** @brief output of the SOR0_CLK_SRC mux in CLK_RST_CONTROLLER_CLK_SOURCE_SOR0 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SOR0
value|97
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_HDA2HDMICODEC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_HDA2HDMICODEC
value|98
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SATA */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SATA
value|99
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_SATA_OOB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SATA_OOB
value|100
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_SATA_IOBIST */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SATA_IOBIST
value|101
end_define

begin_comment
comment|/** output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_HDA */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_HDA
value|102
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SE
value|103
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_APB2APE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_APB2APE
value|104
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_APE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_APE
value|105
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_IQC1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_IQC1
value|106
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_IQC2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_IQC2
value|107
end_define

begin_comment
comment|/** divide by 2 version of TEGRA186_CLK_PLLREFE_VCO */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLREFE_OUT
value|108
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_PLLREFE_PLL_REF */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLREFE_PLL_REF
value|109
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_PLLC4_OUT */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC4_OUT
value|110
end_define

begin_comment
comment|/** @brief output of mux xusb_core_clk_switch on page 67 of T186_Clocks_IAS.doc */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_XUSB
value|111
end_define

begin_comment
comment|/** controls xusb_dev_ce signal on page 66 and 67 of T186_Clocks_IAS.doc */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_XUSB_DEV
value|112
end_define

begin_comment
comment|/** controls xusb_host_ce signal on page 67 of T186_Clocks_IAS.doc */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_XUSB_HOST
value|113
end_define

begin_comment
comment|/** controls xusb_ss_ce signal on page 67 of T186_Clocks_IAS.doc */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_XUSB_SS
value|114
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_DSI */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DSI
value|115
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_MIPI_CAL */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MIPI_CAL
value|116
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DSIA_LP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DSIA_LP
value|117
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_DSIB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DSIB
value|118
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DSIB_LP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DSIB_LP
value|119
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DMIC1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DMIC1
value|122
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DMIC2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DMIC2
value|123
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_AUD_MCLK */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_AUD_MCLK
value|124
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C6 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C6
value|125
end_define

begin_comment
comment|/**output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_UART_FST_MIPI_CAL */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UART_FST_MIPI_CAL
value|126
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_VIC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_VIC
value|127
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SDMMC_LEGACY_TM */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SDMMC_LEGACY_TM
value|128
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_NVDEC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVDEC
value|129
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_NVJPG */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVJPG
value|130
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_NVENC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVENC
value|131
end_define

begin_comment
comment|/** @brief output of the QSPI_CLK_SRC mux in CLK_RST_CONTROLLER_CLK_SOURCE_QSPI */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_QSPI
value|132
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_VI_I2C */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_VI_I2C
value|133
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_HSIC_TRK */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_HSIC_TRK
value|134
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_USB2_TRK */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_USB2_TRK
value|135
end_define

begin_comment
comment|/** output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_MAUD */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MAUD
value|136
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_TSECB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_TSECB
value|137
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_ADSP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_ADSP
value|138
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_ADSPNEON */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_ADSPNEON
value|139
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_MPHY_L0_RX_LS_SYMB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MPHY_L0_RX_SYMB
value|140
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_MPHY_L0_RX_LS_BIT */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MPHY_L0_RX_LS_BIT
value|141
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_MPHY_L0_TX_LS_SYMB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MPHY_L0_TX_SYMB
value|142
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_MPHY_L0_TX_LS_3XBIT */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MPHY_L0_TX_LS_3XBIT
value|143
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_MPHY_L0_RX_ANA */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MPHY_L0_RX_ANA
value|144
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_MPHY_L1_RX_ANA */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MPHY_L1_RX_ANA
value|145
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_MPHY_IOBIST */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MPHY_IOBIST
value|146
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_MPHY_TX_1MHZ_REF */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MPHY_TX_1MHZ_REF
value|147
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_MPHY_CORE_PLL_FIXED */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MPHY_CORE_PLL_FIXED
value|148
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_AXI_CBB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_AXI_CBB
value|149
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DMIC3 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DMIC3
value|150
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DMIC4 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DMIC4
value|151
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DSPK1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DSPK1
value|152
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DSPK2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DSPK2
value|153
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C6 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S6
value|154
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_NVDISPLAY_P0 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVDISPLAY_P0
value|155
end_define

begin_comment
comment|/** @brief output of the NVDISPLAY_DISP_CLK_SRC mux in CLK_RST_CONTROLLER_CLK_SOURCE_NVDISPLAY_DISP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVDISPLAY_DISP
value|156
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_NVDISPLAY_DSC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVDISPLAY_DSC
value|157
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_NVDISPLAYHUB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVDISPLAYHUB
value|158
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_NVDISPLAY_P1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVDISPLAY_P1
value|159
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_NVDISPLAY_P2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVDISPLAY_P2
value|160
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_TACH */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_TACH
value|166
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_EQOS */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_EQOS_AXI
value|167
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_EQOS_RX */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_EQOS_RX
value|168
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_UFSHC_CG_SYS */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UFSHC
value|178
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_UFSDEV_REF */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UFSDEV_REF
value|179
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_NVCSI */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVCSI
value|180
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_NVCSILP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NVCSILP
value|181
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C7 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C7
value|182
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C9 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C9
value|183
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C12 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C12
value|184
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C13 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C13
value|185
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C14 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C14
value|186
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_PWM1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PWM1
value|187
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_PWM2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PWM2
value|188
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_PWM3 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PWM3
value|189
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_PWM5 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PWM5
value|190
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_PWM6 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PWM6
value|191
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_PWM7 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PWM7
value|192
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_PWM8 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PWM8
value|193
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_UARTE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UARTE
value|194
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_UARTF */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UARTF
value|195
end_define

begin_comment
comment|/** @deprecated */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DBGAPB
value|196
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_BPMP_CPU_NIC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_BPMP_CPU_NIC
value|197
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_BPMP_APB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_BPMP_APB
value|199
end_define

begin_comment
comment|/** @brief output of mux controlled by TEGRA186_CLK_SOC_ACTMON */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_ACTMON
value|201
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_AON_CPU_NIC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_AON_CPU_NIC
value|208
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_CAN1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_CAN1
value|210
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_CAN1_HOST */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_CAN1_HOST
value|211
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_CAN2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_CAN2
value|212
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_CAN2_HOST */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_CAN2_HOST
value|213
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_AON_APB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_AON_APB
value|214
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_UARTC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UARTC
value|215
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_UARTG */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UARTG
value|216
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_AON_UART_FST_MIPI_CAL */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_AON_UART_FST_MIPI_CAL
value|217
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C2
value|218
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C8 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C8
value|219
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_I2C10 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2C10
value|220
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_AON_I2C_SLOW */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_AON_I2C_SLOW
value|221
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SPI2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SPI2
value|222
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DMIC5 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DMIC5
value|223
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_AON_TOUCH */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_AON_TOUCH
value|224
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_PWM4 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PWM4
value|225
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_TSC. This clock object is read only and is used for all timers in the system. */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_TSC
value|226
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_MSS_ENCRYPT */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_MSS_ENCRYPT
value|227
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SCE_CPU_NIC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SCE_CPU_NIC
value|228
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SCE_APB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SCE_APB
value|230
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_DSIC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DSIC
value|231
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DSIC_LP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DSIC_LP
value|232
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_DSID */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DSID
value|233
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_DSID_LP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DSID_LP
value|234
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_PEX_SATA_USB_RX_BYP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PEX_SATA_USB_RX_BYP
value|236
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_CLK_SOURCE_SPDIF_OUT */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SPDIF_OUT
value|238
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_EQOS_PTP_REF_CLK_0 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_EQOS_PTP_REF
value|239
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_EQOS_TX_CLK */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_EQOS_TX
value|240
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_USB2_HSIC_TRK */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_USB2_HSIC_TRK
value|241
end_define

begin_comment
comment|/** @brief output of mux xusb_ss_clk_switch on page 66 of T186_Clocks_IAS.doc */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_XUSB_CORE_SS
value|242
end_define

begin_comment
comment|/** @brief output of mux xusb_core_dev_clk_switch on page 67 of T186_Clocks_IAS.doc */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_XUSB_CORE_DEV
value|243
end_define

begin_comment
comment|/** @brief output of mux xusb_core_falcon_clk_switch on page 67 of T186_Clocks_IAS.doc */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_XUSB_FALCON
value|244
end_define

begin_comment
comment|/** @brief output of mux xusb_fs_clk_switch on page 66 of T186_Clocks_IAS.doc */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_XUSB_FS
value|245
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_PLLA_OUT */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLL_A_OUT0
value|246
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_I2S1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_I2S1
value|247
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_I2S2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_I2S2
value|248
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_I2S3 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_I2S3
value|249
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_I2S4 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_I2S4
value|250
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_I2S5 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_I2S5
value|251
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_I2S6 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_I2S6
value|252
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_DSPK1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_DSPK1
value|253
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_DSPK2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_DSPK2
value|254
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_DMIC1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_DMIC1
value|255
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_DMIC2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_DMIC2
value|256
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_DMIC3 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_DMIC3
value|257
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_DMIC4 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_DMIC4
value|259
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_AUDIO_SYNC_CLK_SPDIF */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SYNC_SPDIF
value|260
end_define

begin_comment
comment|/** @brief output of gate CLK_ENB_PLLREFE_OUT */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLREFE_OUT_GATED
value|261
end_define

begin_comment
comment|/** @brief output of the divider PLLREFE_DIVP in CLK_RST_CONTROLLER_PLLREFE_BASE. PLLREFE has 2 outputs:   *      * VCO/pdiv defined by this clock object   *      * VCO/2 defined by TEGRA186_CLK_PLLREFE_OUT   */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLREFE_OUT1
value|262
end_define

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLD_OUT1
value|267
end_define

begin_comment
comment|/** @brief output of the divider PLLP_DIVP in CLK_RST_CONTROLLER_PLLP_BASE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLP_OUT0
value|269
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_PLLP_OUTC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLP_OUT5
value|270
end_define

begin_comment
comment|/** PLL controlled by CLK_RST_CONTROLLER_PLLA_BASE for use by audio clocks */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLA
value|271
end_define

begin_comment
comment|/** @brief output of mux controlled by CLK_RST_CONTROLLER_ACLK_BURST_POLICY divided by the divider controlled by ACLK_CLK_DIVISOR in CLK_RST_CONTROLLER_SUPER_ACLK_DIVIDER */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_ACLK
value|273
end_define

begin_comment
comment|/** fixed 48MHz clock divided down from TEGRA186_CLK_PLL_U */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLL_U_48M
value|274
end_define

begin_comment
comment|/** fixed 480MHz clock divided down from TEGRA186_CLK_PLL_U */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLL_U_480M
value|275
end_define

begin_comment
comment|/** @brief output of the divider PLLC4_DIVP in CLK_RST_CONTROLLER_PLLC4_BASE. Output frequency is TEGRA186_CLK_PLLC4_VCO/PLLC4_DIVP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC4_OUT0
value|276
end_define

begin_comment
comment|/** fixed /3 divider. Output frequency of this clock is TEGRA186_CLK_PLLC4_VCO/3 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC4_OUT1
value|277
end_define

begin_comment
comment|/** fixed /5 divider. Output frequency of this clock is TEGRA186_CLK_PLLC4_VCO/5 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC4_OUT2
value|278
end_define

begin_comment
comment|/** @brief output of mux controlled by PLLC4_CLK_SEL in CLK_RST_CONTROLLER_PLLC4_MISC1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC4_OUT_MUX
value|279
end_define

begin_comment
comment|/** @brief output of divider NVDISPLAY_DISP_CLK_DIVISOR in CLK_RST_CONTROLLER_CLK_SOURCE_NVDISPLAY_DISP when DFLLDISP_DIV is selected in NVDISPLAY_DISP_CLK_SRC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DFLLDISP_DIV
value|284
end_define

begin_comment
comment|/** @brief output of divider NVDISPLAY_DISP_CLK_DIVISOR in CLK_RST_CONTROLLER_CLK_SOURCE_NVDISPLAY_DISP when PLLDISPHUB_DIV is selected in NVDISPLAY_DISP_CLK_SRC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLDISPHUB_DIV
value|285
end_define

begin_comment
comment|/** fixed /8 divider which is used as the input for TEGRA186_CLK_SOR_SAFE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLP_DIV8
value|286
end_define

begin_comment
comment|/** @brief output of divider CLK_RST_CONTROLLER_BPMP_NIC_RATE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_BPMP_NIC
value|287
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_PLLA1_OUT1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLL_A_OUT1
value|288
end_define

begin_comment
comment|/** @deprecated */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_GPC2CLK
value|289
end_define

begin_comment
comment|/** A fake clock which must be enabled during KFUSE read operations to ensure adequate VDD_CORE voltage. */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_KFUSE
value|293
end_define

begin_comment
comment|/**  * @brief controls the PLLE hardware sequencer.  * @details This clock only has enable and disable methods. When the  * PLLE hw sequencer is enabled, PLLE, will be enabled or disabled by  * hw based on the control signals from the PCIe, SATA and XUSB  * clocks. When the PLLE hw sequencer is disabled, the state of PLLE  * is controlled by sw using clk_enable/clk_disable on  * TEGRA186_CLK_PLLE.  */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLE_PWRSEQ
value|294
end_define

begin_comment
comment|/** fixed 60MHz clock divided down from, TEGRA186_CLK_PLL_U */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLREFE_REF
value|295
end_define

begin_comment
comment|/** @brief output of mux controlled by SOR0_CLK_SEL0 and SOR0_CLK_SEL1 in CLK_RST_CONTROLLER_CLK_SOURCE_SOR0 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SOR0_OUT
value|296
end_define

begin_comment
comment|/** @brief output of mux controlled by SOR1_CLK_SEL0 and SOR1_CLK_SEL1 in CLK_RST_CONTROLLER_CLK_SOURCE_SOR1 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SOR1_OUT
value|297
end_define

begin_comment
comment|/** @brief fixed /5 divider.  Output frequency of this clock is TEGRA186_CLK_PLLREFE_OUT1/5. Used as input for TEGRA186_CLK_EQOS_AXI */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLREFE_OUT1_DIV5
value|298
end_define

begin_comment
comment|/** @brief controls the UTMIP_PLL (aka PLLU) hardware sqeuencer */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UTMIP_PLL_PWRSEQ
value|301
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_PEX_USB_PAD_PLL0_MGMT */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PEX_USB_PAD0_MGMT
value|302
end_define

begin_comment
comment|/** @brief output of the divider CLK_RST_CONTROLLER_CLK_SOURCE_PEX_USB_PAD_PLL1_MGMT */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PEX_USB_PAD1_MGMT
value|303
end_define

begin_comment
comment|/** @brief controls the UPHY_PLL0 hardware sqeuencer */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UPHY_PLL0_PWRSEQ
value|304
end_define

begin_comment
comment|/** @brief controls the UPHY_PLL1 hardware sqeuencer */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_UPHY_PLL1_PWRSEQ
value|305
end_define

begin_comment
comment|/** @brief control for PLLREFE_IDDQ in CLK_RST_CONTROLLER_PLLREFE_MISC so the bypass output even be used when the PLL is disabled */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLREFE_PLLE_PASSTHROUGH
value|306
end_define

begin_comment
comment|/** @brief output of the mux controlled by PLLREFE_SEL_CLKIN_PEX in CLK_RST_CONTROLLER_PLLREFE_MISC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLREFE_PEX
value|307
end_define

begin_comment
comment|/** @brief control for PLLREFE_IDDQ in CLK_RST_CONTROLLER_PLLREFE_MISC to turn on the PLL when enabled */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLREFE_IDDQ
value|308
end_define

begin_comment
comment|/** @brief output of the divider QSPI_CLK_DIV2_SEL in CLK_RST_CONTROLLER_CLK_SOURCE_QSPI */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_QSPI_OUT
value|309
end_define

begin_comment
comment|/**  * @brief GPC2CLK-div-2  * @details fixed /2 divider. Output frequency is  * TEGRA186_CLK_GPC2CLK/2. The frequency of this clock is the  * frequency at which the GPU graphics engine runs. */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_GPCCLK
value|310
end_define

begin_comment
comment|/** @brief output of divider CLK_RST_CONTROLLER_AON_NIC_RATE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_AON_NIC
value|450
end_define

begin_comment
comment|/** @brief output of divider CLK_RST_CONTROLLER_SCE_NIC_RATE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SCE_NIC
value|451
end_define

begin_comment
comment|/** Fixed 100MHz PLL for PCIe, SATA and superspeed USB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLE
value|512
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLC_BASE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC
value|513
end_define

begin_comment
comment|/** Fixed 408MHz PLL for use by peripheral clocks */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLP
value|516
end_define

begin_comment
comment|/** @deprecated */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLL_P
value|TEGRA186_CLK_PLLP
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLD_BASE for use by DSI */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLD
value|518
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLD2_BASE for use by HDMI or DP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLD2
value|519
end_define

begin_comment
comment|/**  * @brief PLL controlled by CLK_RST_CONTROLLER_PLLREFE_BASE.  * @details Note that this clock only controls the VCO output, before  * the post-divider. See TEGRA186_CLK_PLLREFE_OUT1 for more  * information.  */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLREFE_VCO
value|520
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLC2_BASE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC2
value|521
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLC3_BASE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC3
value|522
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLDP_BASE for use as the DP link clock */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLDP
value|523
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLC4_BASE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC4_VCO
value|524
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLA1_BASE for use by audio clocks */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLA1
value|525
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLNVCSI_BASE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLNVCSI
value|526
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLDISPHUB_BASE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLDISPHUB
value|527
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLD3_BASE for use by HDMI or DP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLD3
value|528
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLBPMPCAM_BASE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLBPMPCAM
value|531
end_define

begin_comment
comment|/** @brief PLL controlled by CLK_RST_CONTROLLER_PLLAON_BASE for use by IP blocks in the AON domain */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLAON
value|532
end_define

begin_comment
comment|/** Fixed frequency 960MHz PLL for USB and EAVB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLU
value|533
end_define

begin_comment
comment|/** fixed /2 divider. Output frequency is TEGRA186_CLK_PLLC4_VCO/2 */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLLC4_VCO_DIV2
value|535
end_define

begin_comment
comment|/** @brief NAFLL clock source for AXI_CBB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_AXI_CBB
value|564
end_define

begin_comment
comment|/** @brief NAFLL clock source for BPMP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_BPMP
value|565
end_define

begin_comment
comment|/** @brief NAFLL clock source for ISP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_ISP
value|566
end_define

begin_comment
comment|/** @brief NAFLL clock source for NVDEC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_NVDEC
value|567
end_define

begin_comment
comment|/** @brief NAFLL clock source for NVENC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_NVENC
value|568
end_define

begin_comment
comment|/** @brief NAFLL clock source for NVJPG */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_NVJPG
value|569
end_define

begin_comment
comment|/** @brief NAFLL clock source for SCE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_SCE
value|570
end_define

begin_comment
comment|/** @brief NAFLL clock source for SE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_SE
value|571
end_define

begin_comment
comment|/** @brief NAFLL clock source for TSEC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_TSEC
value|572
end_define

begin_comment
comment|/** @brief NAFLL clock source for TSECB */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_TSECB
value|573
end_define

begin_comment
comment|/** @brief NAFLL clock source for VI */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_VI
value|574
end_define

begin_comment
comment|/** @brief NAFLL clock source for VIC */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_VIC
value|575
end_define

begin_comment
comment|/** @brief NAFLL clock source for DISP */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_DISP
value|576
end_define

begin_comment
comment|/** @brief NAFLL clock source for GPU */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_GPU
value|577
end_define

begin_comment
comment|/** @brief NAFLL clock source for M-CPU cluster */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_MCPU
value|578
end_define

begin_comment
comment|/** @brief NAFLL clock source for B-CPU cluster */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_NAFLL_BCPU
value|579
end_define

begin_comment
comment|/** @brief input from Tegra's CLK_32K_IN pad */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_CLK_32K
value|608
end_define

begin_comment
comment|/** @brief output of divider CLK_RST_CONTROLLER_CLK_M_DIVIDE */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_CLK_M
value|609
end_define

begin_comment
comment|/** @brief output of divider PLL_REF_DIV in CLK_RST_CONTROLLER_OSC_CTRL */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_PLL_REF
value|610
end_define

begin_comment
comment|/** @brief input from Tegra's XTAL_IN */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_OSC
value|612
end_define

begin_comment
comment|/** @brief clock recovered from EAVB input */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_EQOS_RX_INPUT
value|613
end_define

begin_comment
comment|/** @brief clock recovered from DTV input */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_DTV_INPUT
value|614
end_define

begin_comment
comment|/** @brief SOR0 brick output which feeds into SOR0_CLK_SEL mux in CLK_RST_CONTROLLER_CLK_SOURCE_SOR0*/
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SOR0_PAD_CLKOUT
value|615
end_define

begin_comment
comment|/** @brief SOR1 brick output which feeds into SOR1_CLK_SEL mux in CLK_RST_CONTROLLER_CLK_SOURCE_SOR1*/
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SOR1_PAD_CLKOUT
value|616
end_define

begin_comment
comment|/** @brief clock recovered from I2S1 input */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S1_SYNC_INPUT
value|617
end_define

begin_comment
comment|/** @brief clock recovered from I2S2 input */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S2_SYNC_INPUT
value|618
end_define

begin_comment
comment|/** @brief clock recovered from I2S3 input */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S3_SYNC_INPUT
value|619
end_define

begin_comment
comment|/** @brief clock recovered from I2S4 input */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S4_SYNC_INPUT
value|620
end_define

begin_comment
comment|/** @brief clock recovered from I2S5 input */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S5_SYNC_INPUT
value|621
end_define

begin_comment
comment|/** @brief clock recovered from I2S6 input */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_I2S6_SYNC_INPUT
value|622
end_define

begin_comment
comment|/** @brief clock recovered from SPDIFIN input */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_SPDIFIN_SYNC_INPUT
value|623
end_define

begin_comment
comment|/**  * @brief subject to change  * @details maximum clock identifier value plus one.  */
end_comment

begin_define
define|#
directive|define
name|TEGRA186_CLK_CLK_MAX
value|624
end_define

begin_comment
comment|/** @} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

