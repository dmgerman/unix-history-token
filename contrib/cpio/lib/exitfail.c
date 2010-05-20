begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Failure exit status     Copyright (C) 2002, 2003, 2005, 2006, 2007 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|"exitfail.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_decl_stmt
name|int
specifier|volatile
name|exit_failure
init|=
name|EXIT_FAILURE
decl_stmt|;
end_decl_stmt

end_unit

