begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * profile_p.c - compile profile.c with profiling turned on.  */
end_comment

begin_comment
comment|/*   * Copyright (C) 2001 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Programming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA  */
end_comment

begin_define
define|#
directive|define
name|PROFILING
value|1
end_define

begin_include
include|#
directive|include
file|"profile.c"
end_include

end_unit

