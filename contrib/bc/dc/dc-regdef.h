begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * definitions for dc's "register" declarations  *  * Copyright (C) 1994 Free Software Foundation, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, you can either send email to this  * program's author (see below) or write to:  *  *    The Free Software Foundation, Inc.  *    59 Temple Place, Suite 330  *    Boston, MA 02111 USA  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/* UCHAR_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* determine how many register stacks there are */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DC_REGCOUNT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|UCHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|DC_REGCOUNT
value|256
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DC_REGCOUNT
value|(UCHAR_MAX+1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DC_REGCOUNT */
end_comment

begin_comment
comment|/* efficiency hack for masking arbritrary integers to 0..(DC_REGCOUNT-1) */
end_comment

begin_if
if|#
directive|if
operator|(
name|DC_REGCOUNT
operator|&
operator|(
name|DC_REGCOUNT
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
end_if

begin_comment
comment|/* DC_REGCOUNT is power of 2 */
end_comment

begin_define
define|#
directive|define
name|regmap
parameter_list|(
name|r
parameter_list|)
value|((r)& (DC_REGCOUNT-1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|regmap
parameter_list|(
name|r
parameter_list|)
value|((r) % DC_REGCOUNT)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

