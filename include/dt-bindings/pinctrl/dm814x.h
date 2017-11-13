begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * This header provides constants specific to DM814X pinctrl bindings.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_DM814X_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_DM814X_H
end_define

begin_include
include|#
directive|include
file|<dt-bindings/pinctrl/omap.h>
end_include

begin_undef
undef|#
directive|undef
name|INPUT_EN
end_undef

begin_undef
undef|#
directive|undef
name|PULL_UP
end_undef

begin_undef
undef|#
directive|undef
name|PULL_ENA
end_undef

begin_comment
comment|/*  * Note that dm814x silicon revision 2.1 and older require input enabled  * (bit 18 set) for all 3.3V I/Os to avoid cumulative hardware damage. For  * more info, see errata advisory 2.1.87. We leave bit 18 out of  * function-mask in dm814x.h and rely on the bootloader for it.  */
end_comment

begin_define
define|#
directive|define
name|INPUT_EN
value|(1<< 18)
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
name|PULL_DISABLE
value|(1<< 16)
end_define

begin_comment
comment|/* update macro depending on INPUT_EN and PULL_ENA */
end_comment

begin_undef
undef|#
directive|undef
name|PIN_OUTPUT
end_undef

begin_undef
undef|#
directive|undef
name|PIN_OUTPUT_PULLUP
end_undef

begin_undef
undef|#
directive|undef
name|PIN_OUTPUT_PULLDOWN
end_undef

begin_undef
undef|#
directive|undef
name|PIN_INPUT
end_undef

begin_undef
undef|#
directive|undef
name|PIN_INPUT_PULLUP
end_undef

begin_undef
undef|#
directive|undef
name|PIN_INPUT_PULLDOWN
end_undef

begin_define
define|#
directive|define
name|PIN_OUTPUT
value|(PULL_DISABLE)
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
value|0
end_define

begin_define
define|#
directive|define
name|PIN_INPUT
value|(INPUT_EN | PULL_DISABLE)
end_define

begin_define
define|#
directive|define
name|PIN_INPUT_PULLUP
value|(INPUT_EN | PULL_UP)
end_define

begin_define
define|#
directive|define
name|PIN_INPUT_PULLDOWN
value|(INPUT_EN)
end_define

begin_comment
comment|/* undef non-existing modes */
end_comment

begin_undef
undef|#
directive|undef
name|PIN_OFF_NONE
end_undef

begin_undef
undef|#
directive|undef
name|PIN_OFF_OUTPUT_HIGH
end_undef

begin_undef
undef|#
directive|undef
name|PIN_OFF_OUTPUT_LOW
end_undef

begin_undef
undef|#
directive|undef
name|PIN_OFF_INPUT_PULLUP
end_undef

begin_undef
undef|#
directive|undef
name|PIN_OFF_INPUT_PULLDOWN
end_undef

begin_undef
undef|#
directive|undef
name|PIN_OFF_WAKEUPENABLE
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

