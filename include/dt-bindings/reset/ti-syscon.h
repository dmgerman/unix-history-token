begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * TI Syscon Reset definitions  *  * Copyright (C) 2015-2016 Texas Instruments Incorporated - http://www.ti.com/  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_RESET_TI_SYSCON_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_RESET_TI_SYSCON_H__
end_define

begin_comment
comment|/*  * The reset does not support the feature and corresponding  * values are not valid  */
end_comment

begin_define
define|#
directive|define
name|ASSERT_NONE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DEASSERT_NONE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|STATUS_NONE
value|(1<< 2)
end_define

begin_comment
comment|/* When set this function is activated by setting(vs clearing) this bit */
end_comment

begin_define
define|#
directive|define
name|ASSERT_SET
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DEASSERT_SET
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|STATUS_SET
value|(1<< 5)
end_define

begin_comment
comment|/* The following are the inverse of the above and are added for consistency */
end_comment

begin_define
define|#
directive|define
name|ASSERT_CLEAR
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|DEASSERT_CLEAR
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|STATUS_CLEAR
value|(0<< 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

