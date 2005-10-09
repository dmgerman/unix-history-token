begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* global.c:  This defines the global variables. */
end_comment

begin_comment
comment|/*  This file is part of GNU bc.     Copyright (C) 1991-1994, 1997, 2000 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2 of the License , or     (at your option) any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; see the file COPYING.  If not, write to       The Free Software Foundation, Inc.       59 Temple Place, Suite 330       Boston, MA 02111 USA      You may contact the author by:        e-mail:  philnelson@acm.org       us-mail:  Philip A. Nelson                 Computer Science Department, 9062                 Western Washington University                 Bellingham, WA 98226-9062         *************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"bcdefs.h"
end_include

begin_comment
comment|/* Since we want to define them here, we use the following define. */
end_comment

begin_undef
undef|#
directive|undef
name|EXTERN
end_undef

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_comment
comment|/* Define all the global variables for bc. */
end_comment

begin_include
include|#
directive|include
file|"global.h"
end_include

begin_decl_stmt
name|CONST
name|char
modifier|*
name|libmath
index|[]
init|=
include|#
directive|include
file|"libmath.h"
decl_stmt|;
end_decl_stmt

end_unit

