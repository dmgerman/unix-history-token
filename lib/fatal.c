begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is part of GNU cpio.    Copyright (C) 2005 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public    License along with this program; if not, write to the Free    Software Foundation, Inc., 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301 USA.  */
end_comment

begin_include
include|#
directive|include
file|<system.h>
end_include

begin_include
include|#
directive|include
file|<paxlib.h>
end_include

begin_function
name|void
name|fatal_exit
parameter_list|()
block|{
name|exit
argument_list|(
name|PAXEXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

