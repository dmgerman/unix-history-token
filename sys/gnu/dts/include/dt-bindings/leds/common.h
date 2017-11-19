begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * This header provides macros for the common LEDs device tree bindings.  *  * Copyright (C) 2015, Samsung Electronics Co., Ltd.  *  * Author: Jacek Anaszewski<j.anaszewski@samsung.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_LEDS_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_LEDS_H
end_define

begin_comment
comment|/* External trigger type */
end_comment

begin_define
define|#
directive|define
name|LEDS_TRIG_TYPE_EDGE
value|0
end_define

begin_define
define|#
directive|define
name|LEDS_TRIG_TYPE_LEVEL
value|1
end_define

begin_comment
comment|/* Boost modes */
end_comment

begin_define
define|#
directive|define
name|LEDS_BOOST_OFF
value|0
end_define

begin_define
define|#
directive|define
name|LEDS_BOOST_ADAPTIVE
value|1
end_define

begin_define
define|#
directive|define
name|LEDS_BOOST_FIXED
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_LEDS_H */
end_comment

end_unit

