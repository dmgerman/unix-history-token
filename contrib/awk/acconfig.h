begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * acconfig.h -- configuration definitions for gawk.  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1995-1997 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Programming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA  */
end_comment

begin_expr_stmt
unit|@
name|TOP
expr|@
undef|#
directive|undef
name|HAVE_STRINGIZE
comment|/* can use ANSI # operator in cpp */
undef|#
directive|undef
name|REGEX_MALLOC
comment|/* use malloc instead of alloca in regex.c */
undef|#
directive|undef
name|SPRINTF_RET
comment|/* return type of sprintf */
undef|#
directive|undef
name|BITOPS
comment|/* bitwise ops (undocumented feature) */
undef|#
directive|undef
name|NONDECDATA
comment|/* non-decimal input data (undocumented feature) */
expr|@
name|BOTTOM
expr|@
end_expr_stmt

begin_include
include|#
directive|include
file|<custom.h>
end_include

begin_comment
comment|/* overrides for stuff autoconf can't deal with */
end_comment

end_unit

