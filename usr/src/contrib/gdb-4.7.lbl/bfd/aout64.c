begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for 64-bit a.out files.    Copyright 1990, 1991, 1992  Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_64_BIT
end_ifdef

begin_define
define|#
directive|define
name|ARCH_SIZE
value|64
end_define

begin_include
include|#
directive|include
file|"aoutx.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Prevent "empty translation unit" warnings from the idiots at X3J11. */
end_comment

begin_decl_stmt
specifier|static
name|char
name|ansi_c_idiots
init|=
literal|69
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

