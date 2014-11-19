begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013-2014 Hisilicon Limited.  * Copyright (c) 2013-2014 Linaro Limited.  *  * Author: Haojian Zhuang<haojian.zhuang@linaro.org>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write to the Free Software Foundation, Inc.,  * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_HIP04_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_HIP04_CLOCK_H
end_define

begin_define
define|#
directive|define
name|HIP04_NONE_CLOCK
value|0
end_define

begin_comment
comment|/* fixed rate& fixed factor clocks */
end_comment

begin_define
define|#
directive|define
name|HIP04_OSC50M
value|1
end_define

begin_define
define|#
directive|define
name|HIP04_CLK_50M
value|2
end_define

begin_define
define|#
directive|define
name|HIP04_CLK_168M
value|3
end_define

begin_define
define|#
directive|define
name|HIP04_NR_CLKS
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_HIP04_CLOCK_H */
end_comment

end_unit

