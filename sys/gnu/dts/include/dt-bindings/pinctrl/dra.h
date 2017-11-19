begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for DRA pinctrl bindings.  *  * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/  * Author: Rajendra Nayak<rnayak@ti.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_DRA_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_DRA_H
end_define

begin_comment
comment|/* DRA7 mux mode options for each pin. See TRM for options */
end_comment

begin_define
define|#
directive|define
name|MUX_MODE0
value|0x0
end_define

begin_define
define|#
directive|define
name|MUX_MODE1
value|0x1
end_define

begin_define
define|#
directive|define
name|MUX_MODE2
value|0x2
end_define

begin_define
define|#
directive|define
name|MUX_MODE3
value|0x3
end_define

begin_define
define|#
directive|define
name|MUX_MODE4
value|0x4
end_define

begin_define
define|#
directive|define
name|MUX_MODE5
value|0x5
end_define

begin_define
define|#
directive|define
name|MUX_MODE6
value|0x6
end_define

begin_define
define|#
directive|define
name|MUX_MODE7
value|0x7
end_define

begin_define
define|#
directive|define
name|MUX_MODE8
value|0x8
end_define

begin_define
define|#
directive|define
name|MUX_MODE9
value|0x9
end_define

begin_define
define|#
directive|define
name|MUX_MODE10
value|0xa
end_define

begin_define
define|#
directive|define
name|MUX_MODE11
value|0xb
end_define

begin_define
define|#
directive|define
name|MUX_MODE12
value|0xc
end_define

begin_define
define|#
directive|define
name|MUX_MODE13
value|0xd
end_define

begin_define
define|#
directive|define
name|MUX_MODE14
value|0xe
end_define

begin_define
define|#
directive|define
name|MUX_MODE15
value|0xf
end_define

begin_comment
comment|/* Certain pins need virtual mode, but note: they may glitch */
end_comment

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE0
value|(MODE_SELECT | (0x0<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE1
value|(MODE_SELECT | (0x1<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE2
value|(MODE_SELECT | (0x2<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE3
value|(MODE_SELECT | (0x3<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE4
value|(MODE_SELECT | (0x4<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE5
value|(MODE_SELECT | (0x5<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE6
value|(MODE_SELECT | (0x6<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE7
value|(MODE_SELECT | (0x7<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE8
value|(MODE_SELECT | (0x8<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE9
value|(MODE_SELECT | (0x9<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE10
value|(MODE_SELECT | (0xa<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE11
value|(MODE_SELECT | (0xb<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE12
value|(MODE_SELECT | (0xc<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE13
value|(MODE_SELECT | (0xd<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE14
value|(MODE_SELECT | (0xe<< 4))
end_define

begin_define
define|#
directive|define
name|MUX_VIRTUAL_MODE15
value|(MODE_SELECT | (0xf<< 4))
end_define

begin_define
define|#
directive|define
name|MODE_SELECT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PULL_ENA
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|PULL_DIS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PULL_UP
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|INPUT_EN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|SLEWCONTROL
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|WAKEUP_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|WAKEUP_EVENT
value|(1<< 25)
end_define

begin_comment
comment|/* Active pin states */
end_comment

begin_define
define|#
directive|define
name|PIN_OUTPUT
value|(0 | PULL_DIS)
end_define

begin_define
define|#
directive|define
name|PIN_OUTPUT_PULLUP
value|(PULL_UP)
end_define

begin_define
define|#
directive|define
name|PIN_OUTPUT_PULLDOWN
value|(0)
end_define

begin_define
define|#
directive|define
name|PIN_INPUT
value|(INPUT_EN | PULL_DIS)
end_define

begin_define
define|#
directive|define
name|PIN_INPUT_SLEW
value|(INPUT_EN | SLEWCONTROL)
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
comment|/*  * Macro to allow using the absolute physical address instead of the  * padconf registers instead of the offset from padconf base.  */
end_comment

begin_define
define|#
directive|define
name|DRA7XX_CORE_IOPAD
parameter_list|(
name|pa
parameter_list|,
name|val
parameter_list|)
value|(((pa)& 0xffff) - 0x3400) (val)
end_define

begin_comment
comment|/* DRA7 IODELAY configuration parameters */
end_comment

begin_define
define|#
directive|define
name|A_DELAY_PS
parameter_list|(
name|val
parameter_list|)
value|((val)& 0xffff)
end_define

begin_define
define|#
directive|define
name|G_DELAY_PS
parameter_list|(
name|val
parameter_list|)
value|((val)& 0xffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

