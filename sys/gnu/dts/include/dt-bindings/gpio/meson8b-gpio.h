begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * GPIO definitions for Amlogic Meson8b SoCs  *  * Copyright (C) 2015 Endless Mobile, Inc.  * Author: Carlo Caione<carlo@endlessm.com>  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License  * version 2 as published by the Free Software Foundation.  *  * You should have received a copy of the GNU General Public License  * along with this program. If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_MESON8B_GPIO_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_MESON8B_GPIO_H
end_define

begin_include
include|#
directive|include
file|<dt-bindings/gpio/meson8-gpio.h>
end_include

begin_comment
comment|/* GPIO Bank DIF */
end_comment

begin_define
define|#
directive|define
name|DIF_0_P
value|120
end_define

begin_define
define|#
directive|define
name|DIF_0_N
value|121
end_define

begin_define
define|#
directive|define
name|DIF_1_P
value|122
end_define

begin_define
define|#
directive|define
name|DIF_1_N
value|123
end_define

begin_define
define|#
directive|define
name|DIF_2_P
value|124
end_define

begin_define
define|#
directive|define
name|DIF_2_N
value|125
end_define

begin_define
define|#
directive|define
name|DIF_3_P
value|126
end_define

begin_define
define|#
directive|define
name|DIF_3_N
value|127
end_define

begin_define
define|#
directive|define
name|DIF_4_P
value|128
end_define

begin_define
define|#
directive|define
name|DIF_4_N
value|129
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_MESON8B_GPIO_H */
end_comment

end_unit

