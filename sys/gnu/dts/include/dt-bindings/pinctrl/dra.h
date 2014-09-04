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

begin_endif
endif|#
directive|endif
end_endif

end_unit

