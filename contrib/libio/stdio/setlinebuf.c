begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1993, 1997 Free Software Foundation, Inc.    This file is part of the GNU IO Library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2, or (at    your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this library; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.     As a special exception, if you link this library with files    compiled with a GNU compiler to produce an executable, this does    not cause the resulting executable to be covered by the GNU General    Public License.  This exception does not however invalidate any    other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_include
include|#
directive|include
file|"libioP.h"
end_include

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_undef
undef|#
directive|undef
name|setlinebuf
end_undef

begin_function
name|void
name|setlinebuf
parameter_list|(
name|stream
parameter_list|)
name|_IO_FILE
modifier|*
name|stream
decl_stmt|;
block|{
name|_IO_setvbuf
argument_list|(
name|stream
argument_list|,
name|NULL
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

