begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * random.h - redefine name of random lib routines to avoid conflicts  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1996, 2001 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Programming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|initstate
value|gawk_initstate
end_define

begin_define
define|#
directive|define
name|setstate
value|gawk_setstate
end_define

begin_define
define|#
directive|define
name|random
value|gawk_random
end_define

begin_define
define|#
directive|define
name|srandom
value|gawk_srandom
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_undef
undef|#
directive|undef
name|__P
end_undef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|s
parameter_list|)
value|s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|s
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|long
name|random
parameter_list|()
function_decl|;
end_function_decl

end_unit

