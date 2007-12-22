begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Return nonzero value if number is negative. */
end_comment

begin_comment
comment|/* Copyright (C) 1997, 1998, 1999 Free Software Foundation, Inc.     This file is part of the GNU ISO C++ Library.  This library is free    software; you can redistribute it and/or modify it under the    terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option)    any later version.     This library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this library; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,    USA.     As a special exception, you may use this file as part of a free software    library without restriction.  Specifically, if other files instantiate    templates or use macros or inline functions from this file, or you compile    this file and link it with other files to produce an executable, this    file does not by itself cause the resulting executable to be covered by    the GNU General Public License.  This exception does not however    invalidate any other reasons why the executable file might be covered by    the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|"mathconf.h"
end_include

begin_function
name|int
name|__signbitl
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
if|#
directive|if
name|LDBL_MANT_DIG
operator|==
literal|113
name|Int64_t
name|msw
decl_stmt|;
name|GET_LDOUBLE_MSW64
argument_list|(
name|msw
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|msw
operator|<
literal|0
return|;
else|#
directive|else
name|Int32_t
name|e
decl_stmt|;
name|GET_LDOUBLE_EXP
argument_list|(
name|e
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|e
operator|&
literal|0x8000
return|;
endif|#
directive|endif
block|}
end_function

end_unit

