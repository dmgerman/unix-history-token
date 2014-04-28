begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants specific to AM33XX pinctrl bindings.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_AM33XX_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_AM33XX_H
end_define

begin_include
include|#
directive|include
file|<dt-bindings/pinctrl/omap.h>
end_include

begin_comment
comment|/* am33xx specific mux bit defines */
end_comment

begin_undef
undef|#
directive|undef
name|PULL_ENA
end_undef

begin_undef
undef|#
directive|undef
name|INPUT_EN
end_undef

begin_define
define|#
directive|define
name|PULL_DISABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|INPUT_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SLEWCTRL_FAST
value|(1<< 6)
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

