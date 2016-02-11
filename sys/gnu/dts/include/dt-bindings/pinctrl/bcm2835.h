begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header providing constants for bcm2835 pinctrl bindings.  *  * Copyright (C) 2015 Stefan Wahren<stefan.wahren@i2se.com>  *  * The code contained herein is licensed under the GNU General Public  * License. You may obtain a copy of the GNU General Public License  * Version 2 at the following locations:  *  * http://www.opensource.org/licenses/gpl-license.html  * http://www.gnu.org/copyleft/gpl.html  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_PINCTRL_BCM2835_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_PINCTRL_BCM2835_H__
end_define

begin_comment
comment|/* brcm,function property */
end_comment

begin_define
define|#
directive|define
name|BCM2835_FSEL_GPIO_IN
value|0
end_define

begin_define
define|#
directive|define
name|BCM2835_FSEL_GPIO_OUT
value|1
end_define

begin_define
define|#
directive|define
name|BCM2835_FSEL_ALT5
value|2
end_define

begin_define
define|#
directive|define
name|BCM2835_FSEL_ALT4
value|3
end_define

begin_define
define|#
directive|define
name|BCM2835_FSEL_ALT0
value|4
end_define

begin_define
define|#
directive|define
name|BCM2835_FSEL_ALT1
value|5
end_define

begin_define
define|#
directive|define
name|BCM2835_FSEL_ALT2
value|6
end_define

begin_define
define|#
directive|define
name|BCM2835_FSEL_ALT3
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_PINCTRL_BCM2835_H__ */
end_comment

end_unit

