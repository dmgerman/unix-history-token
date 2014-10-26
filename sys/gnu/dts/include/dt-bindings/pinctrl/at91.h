begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for most at91 pinctrl bindings.  *  * Copyright (C) 2013 Jean-Christophe PLAGNIOL-VILLARD<plagnioj@jcrosoft.com>  *  * GPLv2 only  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_AT91_PINCTRL_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_AT91_PINCTRL_H__
end_define

begin_define
define|#
directive|define
name|AT91_PINCTRL_NONE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|AT91_PINCTRL_PULL_UP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AT91_PINCTRL_MULTI_DRIVE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AT91_PINCTRL_DEGLITCH
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AT91_PINCTRL_PULL_DOWN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AT91_PINCTRL_DIS_SCHMIT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AT91_PINCTRL_DEBOUNCE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AT91_PINCTRL_DEBOUNCE_VAL
parameter_list|(
name|x
parameter_list|)
value|(x<< 17)
end_define

begin_define
define|#
directive|define
name|AT91_PINCTRL_PULL_UP_DEGLITCH
value|(AT91_PINCTRL_PULL_UP | AT91_PINCTRL_DEGLITCH)
end_define

begin_define
define|#
directive|define
name|AT91_PIOA
value|0
end_define

begin_define
define|#
directive|define
name|AT91_PIOB
value|1
end_define

begin_define
define|#
directive|define
name|AT91_PIOC
value|2
end_define

begin_define
define|#
directive|define
name|AT91_PIOD
value|3
end_define

begin_define
define|#
directive|define
name|AT91_PIOE
value|4
end_define

begin_define
define|#
directive|define
name|AT91_PERIPH_GPIO
value|0
end_define

begin_define
define|#
directive|define
name|AT91_PERIPH_A
value|1
end_define

begin_define
define|#
directive|define
name|AT91_PERIPH_B
value|2
end_define

begin_define
define|#
directive|define
name|AT91_PERIPH_C
value|3
end_define

begin_define
define|#
directive|define
name|AT91_PERIPH_D
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_AT91_PINCTRL_H__ */
end_comment

end_unit

