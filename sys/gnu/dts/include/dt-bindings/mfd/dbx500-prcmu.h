begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the PRCMU bindings.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_MFD_PRCMU_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_MFD_PRCMU_H
end_define

begin_comment
comment|/*  * Clock identifiers.  */
end_comment

begin_define
define|#
directive|define
name|ARMCLK
value|0
end_define

begin_define
define|#
directive|define
name|PRCMU_ACLK
value|1
end_define

begin_define
define|#
directive|define
name|PRCMU_SVAMMCSPCLK
value|2
end_define

begin_define
define|#
directive|define
name|PRCMU_SDMMCHCLK
value|2
end_define

begin_comment
comment|/* DBx540 only. */
end_comment

begin_define
define|#
directive|define
name|PRCMU_SIACLK
value|3
end_define

begin_define
define|#
directive|define
name|PRCMU_SIAMMDSPCLK
value|3
end_define

begin_comment
comment|/* DBx540 only. */
end_comment

begin_define
define|#
directive|define
name|PRCMU_SGACLK
value|4
end_define

begin_define
define|#
directive|define
name|PRCMU_UARTCLK
value|5
end_define

begin_define
define|#
directive|define
name|PRCMU_MSP02CLK
value|6
end_define

begin_define
define|#
directive|define
name|PRCMU_MSP1CLK
value|7
end_define

begin_define
define|#
directive|define
name|PRCMU_I2CCLK
value|8
end_define

begin_define
define|#
directive|define
name|PRCMU_SDMMCCLK
value|9
end_define

begin_define
define|#
directive|define
name|PRCMU_SLIMCLK
value|10
end_define

begin_define
define|#
directive|define
name|PRCMU_CAMCLK
value|10
end_define

begin_comment
comment|/* DBx540 only. */
end_comment

begin_define
define|#
directive|define
name|PRCMU_PER1CLK
value|11
end_define

begin_define
define|#
directive|define
name|PRCMU_PER2CLK
value|12
end_define

begin_define
define|#
directive|define
name|PRCMU_PER3CLK
value|13
end_define

begin_define
define|#
directive|define
name|PRCMU_PER5CLK
value|14
end_define

begin_define
define|#
directive|define
name|PRCMU_PER6CLK
value|15
end_define

begin_define
define|#
directive|define
name|PRCMU_PER7CLK
value|16
end_define

begin_define
define|#
directive|define
name|PRCMU_LCDCLK
value|17
end_define

begin_define
define|#
directive|define
name|PRCMU_BMLCLK
value|18
end_define

begin_define
define|#
directive|define
name|PRCMU_HSITXCLK
value|19
end_define

begin_define
define|#
directive|define
name|PRCMU_HSIRXCLK
value|20
end_define

begin_define
define|#
directive|define
name|PRCMU_HDMICLK
value|21
end_define

begin_define
define|#
directive|define
name|PRCMU_APEATCLK
value|22
end_define

begin_define
define|#
directive|define
name|PRCMU_APETRACECLK
value|23
end_define

begin_define
define|#
directive|define
name|PRCMU_MCDECLK
value|24
end_define

begin_define
define|#
directive|define
name|PRCMU_IPI2CCLK
value|25
end_define

begin_define
define|#
directive|define
name|PRCMU_DSIALTCLK
value|26
end_define

begin_define
define|#
directive|define
name|PRCMU_DMACLK
value|27
end_define

begin_define
define|#
directive|define
name|PRCMU_B2R2CLK
value|28
end_define

begin_define
define|#
directive|define
name|PRCMU_TVCLK
value|29
end_define

begin_define
define|#
directive|define
name|SPARE_UNIPROCLK
value|30
end_define

begin_define
define|#
directive|define
name|PRCMU_SSPCLK
value|31
end_define

begin_define
define|#
directive|define
name|PRCMU_RNGCLK
value|32
end_define

begin_define
define|#
directive|define
name|PRCMU_UICCCLK
value|33
end_define

begin_define
define|#
directive|define
name|PRCMU_G1CLK
value|34
end_define

begin_comment
comment|/* DBx540 only. */
end_comment

begin_define
define|#
directive|define
name|PRCMU_HVACLK
value|35
end_define

begin_comment
comment|/* DBx540 only. */
end_comment

begin_define
define|#
directive|define
name|PRCMU_SPARE1CLK
value|36
end_define

begin_define
define|#
directive|define
name|PRCMU_SPARE2CLK
value|37
end_define

begin_define
define|#
directive|define
name|PRCMU_NUM_REG_CLOCKS
value|38
end_define

begin_define
define|#
directive|define
name|PRCMU_RTCCLK
value|PRCMU_NUM_REG_CLOCKS
end_define

begin_define
define|#
directive|define
name|PRCMU_SYSCLK
value|39
end_define

begin_define
define|#
directive|define
name|PRCMU_CDCLK
value|40
end_define

begin_define
define|#
directive|define
name|PRCMU_TIMCLK
value|41
end_define

begin_define
define|#
directive|define
name|PRCMU_PLLSOC0
value|42
end_define

begin_define
define|#
directive|define
name|PRCMU_PLLSOC1
value|43
end_define

begin_define
define|#
directive|define
name|PRCMU_ARMSS
value|44
end_define

begin_define
define|#
directive|define
name|PRCMU_PLLDDR
value|45
end_define

begin_comment
comment|/* DSI Clocks */
end_comment

begin_define
define|#
directive|define
name|PRCMU_PLLDSI
value|46
end_define

begin_define
define|#
directive|define
name|PRCMU_DSI0CLK
value|47
end_define

begin_define
define|#
directive|define
name|PRCMU_DSI1CLK
value|48
end_define

begin_define
define|#
directive|define
name|PRCMU_DSI0ESCCLK
value|49
end_define

begin_define
define|#
directive|define
name|PRCMU_DSI1ESCCLK
value|50
end_define

begin_define
define|#
directive|define
name|PRCMU_DSI2ESCCLK
value|51
end_define

begin_comment
comment|/* LCD DSI PLL - Ux540 only */
end_comment

begin_define
define|#
directive|define
name|PRCMU_PLLDSI_LCD
value|52
end_define

begin_define
define|#
directive|define
name|PRCMU_DSI0CLK_LCD
value|53
end_define

begin_define
define|#
directive|define
name|PRCMU_DSI1CLK_LCD
value|54
end_define

begin_define
define|#
directive|define
name|PRCMU_DSI0ESCCLK_LCD
value|55
end_define

begin_define
define|#
directive|define
name|PRCMU_DSI1ESCCLK_LCD
value|56
end_define

begin_define
define|#
directive|define
name|PRCMU_DSI2ESCCLK_LCD
value|57
end_define

begin_define
define|#
directive|define
name|PRCMU_NUM_CLKS
value|58
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

