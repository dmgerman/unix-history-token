begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * thermal_exynos.h - Samsung EXYNOS TMU device tree definitions  *  *  Copyright (C) 2014 Samsung Electronics  *  Lukasz Majewski<l.majewski@samsung.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXYNOS_THERMAL_TMU_DT_H
end_ifndef

begin_define
define|#
directive|define
name|_EXYNOS_THERMAL_TMU_DT_H
end_define

begin_define
define|#
directive|define
name|TYPE_ONE_POINT_TRIMMING
value|0
end_define

begin_define
define|#
directive|define
name|TYPE_ONE_POINT_TRIMMING_25
value|1
end_define

begin_define
define|#
directive|define
name|TYPE_ONE_POINT_TRIMMING_85
value|2
end_define

begin_define
define|#
directive|define
name|TYPE_TWO_POINT_TRIMMING
value|3
end_define

begin_define
define|#
directive|define
name|TYPE_NONE
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EXYNOS_THERMAL_TMU_DT_H */
end_comment

end_unit

