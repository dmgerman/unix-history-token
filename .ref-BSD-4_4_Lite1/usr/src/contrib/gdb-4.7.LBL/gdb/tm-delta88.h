begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine description for Motorola Delta 88 box, for GDB.    Copyright 1986, 1987, 1988, 1989, 1990, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-m88k.h"
end_include

begin_comment
comment|/* BCS is a standard for binary compatibility.  This machine uses it.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BCS
argument_list|)
end_if

begin_define
define|#
directive|define
name|BCS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DELTA88
end_define

end_unit

