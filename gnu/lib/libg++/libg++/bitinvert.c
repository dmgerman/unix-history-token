begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1994 Free Software Foundation  This file is part of the GNU BitString Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_comment
comment|/*  Written by Per Bothner (bothner@cygnus.com) */
end_comment

begin_include
include|#
directive|include
file|"bitprims.h"
end_include

begin_function
name|void
name|_BS_invert
parameter_list|(
name|ptr
parameter_list|,
name|offset
parameter_list|,
name|length
parameter_list|)
specifier|register
name|_BS_word
modifier|*
name|ptr
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|_BS_size_t
name|length
decl_stmt|;
block|{
undef|#
directive|undef
name|DOIT
define|#
directive|define
name|DOIT
parameter_list|(
name|WORD
parameter_list|,
name|MASK
parameter_list|)
value|((WORD) ^= (MASK))
include|#
directive|include
file|"bitdo1.h"
block|}
end_function

end_unit

