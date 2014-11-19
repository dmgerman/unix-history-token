begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants specific to AM43XX pinctrl bindings.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_PINCTRL_AM43XX_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_PINCTRL_AM43XX_H
end_define

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

begin_define
define|#
directive|define
name|MUX_MODE8
value|8
end_define

begin_define
define|#
directive|define
name|PULL_DISABLE
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
name|SLEWCTRL_FAST
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DS0_PULL_UP_DOWN_EN
value|(1<< 27)
end_define

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

