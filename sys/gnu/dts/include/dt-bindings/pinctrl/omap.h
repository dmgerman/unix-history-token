begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for OMAP pinctrl bindings.  *  * Copyright (C) 2009 Nokia  * Copyright (C) 2009-2010 Texas Instruments  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_OMAP_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_OMAP_H
end_define

begin_comment
comment|/* 34xx mux mode options for each pin. See TRM for options */
end_comment

begin_define
define|#
directive|define
name|MUX_MODE0
value|0
end_define

begin_define
define|#
directive|define
name|MUX_MODE1
value|1
end_define

begin_define
define|#
directive|define
name|MUX_MODE2
value|2
end_define

begin_define
define|#
directive|define
name|MUX_MODE3
value|3
end_define

begin_define
define|#
directive|define
name|MUX_MODE4
value|4
end_define

begin_define
define|#
directive|define
name|MUX_MODE5
value|5
end_define

begin_define
define|#
directive|define
name|MUX_MODE6
value|6
end_define

begin_define
define|#
directive|define
name|MUX_MODE7
value|7
end_define

begin_comment
comment|/* 24xx/34xx mux bit defines */
end_comment

begin_define
define|#
directive|define
name|PULL_ENA
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PULL_UP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ALTELECTRICALSEL
value|(1<< 5)
end_define

begin_comment
comment|/* omap3/4/5 specific mux bit defines */
end_comment

begin_define
define|#
directive|define
name|INPUT_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|OFF_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|OFFOUT_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|OFFOUT_VAL
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|OFF_PULL_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|OFF_PULL_UP
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|WAKEUP_EN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|WAKEUP_EVENT
value|(1<< 15)
end_define

begin_comment
comment|/* Active pin states */
end_comment

begin_define
define|#
directive|define
name|PIN_OUTPUT
value|0
end_define

begin_define
define|#
directive|define
name|PIN_OUTPUT_PULLUP
value|(PIN_OUTPUT | PULL_ENA | PULL_UP)
end_define

begin_define
define|#
directive|define
name|PIN_OUTPUT_PULLDOWN
value|(PIN_OUTPUT | PULL_ENA)
end_define

begin_define
define|#
directive|define
name|PIN_INPUT
value|INPUT_EN
end_define

begin_define
define|#
directive|define
name|PIN_INPUT_PULLUP
value|(PULL_ENA | INPUT_EN | PULL_UP)
end_define

begin_define
define|#
directive|define
name|PIN_INPUT_PULLDOWN
value|(PULL_ENA | INPUT_EN)
end_define

begin_comment
comment|/* Off mode states */
end_comment

begin_define
define|#
directive|define
name|PIN_OFF_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PIN_OFF_OUTPUT_HIGH
value|(OFF_EN | OFFOUT_EN | OFFOUT_VAL)
end_define

begin_define
define|#
directive|define
name|PIN_OFF_OUTPUT_LOW
value|(OFF_EN | OFFOUT_EN)
end_define

begin_define
define|#
directive|define
name|PIN_OFF_INPUT_PULLUP
value|(OFF_EN | OFFOUT_EN | OFF_PULL_EN | OFF_PULL_UP)
end_define

begin_define
define|#
directive|define
name|PIN_OFF_INPUT_PULLDOWN
value|(OFF_EN | OFFOUT_EN | OFF_PULL_EN)
end_define

begin_define
define|#
directive|define
name|PIN_OFF_WAKEUPENABLE
value|WAKEUP_EN
end_define

begin_comment
comment|/*  * Macros to allow using the absolute physical address instead of the  * padconf registers instead of the offset from padconf base.  */
end_comment

begin_define
define|#
directive|define
name|OMAP_IOPAD_OFFSET
parameter_list|(
name|pa
parameter_list|,
name|offset
parameter_list|)
value|(((pa)& 0xffff) - (offset))
end_define

begin_define
define|#
directive|define
name|OMAP2420_CORE_IOPAD
parameter_list|(
name|pa
parameter_list|,
name|val
parameter_list|)
value|OMAP_IOPAD_OFFSET((pa), 0x0030) (val)
end_define

begin_define
define|#
directive|define
name|OMAP2430_CORE_IOPAD
parameter_list|(
name|pa
parameter_list|,
name|val
parameter_list|)
value|OMAP_IOPAD_OFFSET((pa), 0x2030) (val)
end_define

begin_define
define|#
directive|define
name|OMAP3_CORE1_IOPAD
parameter_list|(
name|pa
parameter_list|,
name|val
parameter_list|)
value|OMAP_IOPAD_OFFSET((pa), 0x2030) (val)
end_define

begin_define
define|#
directive|define
name|OMAP3430_CORE2_IOPAD
parameter_list|(
name|pa
parameter_list|,
name|val
parameter_list|)
value|OMAP_IOPAD_OFFSET((pa), 0x25d8) (val)
end_define

begin_define
define|#
directive|define
name|OMAP3630_CORE2_IOPAD
parameter_list|(
name|pa
parameter_list|,
name|val
parameter_list|)
value|OMAP_IOPAD_OFFSET((pa), 0x25a0) (val)
end_define

begin_define
define|#
directive|define
name|OMAP3_WKUP_IOPAD
parameter_list|(
name|pa
parameter_list|,
name|val
parameter_list|)
value|OMAP_IOPAD_OFFSET((pa), 0x2a00) (val)
end_define

begin_define
define|#
directive|define
name|DM814X_IOPAD
parameter_list|(
name|pa
parameter_list|,
name|val
parameter_list|)
value|OMAP_IOPAD_OFFSET((pa), 0x0800) (val)
end_define

begin_define
define|#
directive|define
name|DM816X_IOPAD
parameter_list|(
name|pa
parameter_list|,
name|val
parameter_list|)
value|OMAP_IOPAD_OFFSET((pa), 0x0800) (val)
end_define

begin_define
define|#
directive|define
name|AM33XX_IOPAD
parameter_list|(
name|pa
parameter_list|,
name|val
parameter_list|)
value|OMAP_IOPAD_OFFSET((pa), 0x0800) (val)
end_define

begin_comment
comment|/*  * Macros to allow using the offset from the padconf physical address  * instead  of the offset from padconf base.  */
end_comment

begin_define
define|#
directive|define
name|OMAP_PADCONF_OFFSET
parameter_list|(
name|offset
parameter_list|,
name|base_offset
parameter_list|)
value|((offset) - (base_offset))
end_define

begin_define
define|#
directive|define
name|OMAP4_IOPAD
parameter_list|(
name|offset
parameter_list|,
name|val
parameter_list|)
value|OMAP_PADCONF_OFFSET((offset), 0x0040) (val)
end_define

begin_define
define|#
directive|define
name|OMAP5_IOPAD
parameter_list|(
name|offset
parameter_list|,
name|val
parameter_list|)
value|OMAP_PADCONF_OFFSET((offset), 0x0040) (val)
end_define

begin_comment
comment|/*  * Define some commonly used pins configured by the boards.  * Note that some boards use alternative pins, so check  * the schematics before using these.  */
end_comment

begin_define
define|#
directive|define
name|OMAP3_UART1_RX
value|0x152
end_define

begin_define
define|#
directive|define
name|OMAP3_UART2_RX
value|0x14a
end_define

begin_define
define|#
directive|define
name|OMAP3_UART3_RX
value|0x16e
end_define

begin_define
define|#
directive|define
name|OMAP4_UART2_RX
value|0xdc
end_define

begin_define
define|#
directive|define
name|OMAP4_UART3_RX
value|0x104
end_define

begin_define
define|#
directive|define
name|OMAP4_UART4_RX
value|0x11c
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

