begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* version.c -- distribution and version numbers. */
end_comment

begin_comment
comment|/* Copyright (C) 1989 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 1, or (at your option) any later    version.     Bash is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License along    with Bash; see the file COPYING.  If not, write to the Free Software    Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|dist_version
init|=
name|DISTVERSION
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|build_version
init|=
name|BUILDVERSION
decl_stmt|;
end_decl_stmt

end_unit

