begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective C Runtime nil receiver function    Copyright (C) 1993, 1995, 1996, 2002 Free Software Foundation, Inc.    Contributed by Kresten Krab Thorup  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled with    GCC to produce an executable, this does not cause the resulting executable    to be covered by the GNU General Public License. This exception does not    however invalidate any other reasons why the executable file might be    covered by the GNU General Public License.  */
end_comment

begin_comment
comment|/* This is the nil method, the function that is called when the receiver    of a method is nil */
end_comment

begin_include
include|#
directive|include
file|"runtime.h"
end_include

begin_comment
comment|/* When the receiver of a method invocation is nil, the runtime    returns nil_method() as the method implementation.  This function    will be casted to whatever function was supposed to be executed to    execute that method (that function will take an id, followed by a    SEL, followed by who knows what arguments, depends on the method),    and executed.        For this reason, nil_method() should be a function which can be    called in place of any function taking an 'id' argument followed by    a 'SEL' argument, followed by zero, or one, or any number of    arguments (both a fixed number, or a variable number !).        There is no "proper" implementation of such a nil_method function    in C, however in all existing implementations it does not matter    when extra arguments are present, so we can simply create a function    taking a receiver and a selector, and all other arguments will be    ignored. :-) */
end_comment

begin_decl_stmt
name|id
name|nil_method
argument_list|(
name|id
name|receiver
argument_list|,
name|SEL
name|op
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|)
block|{
return|return
name|receiver
return|;
block|}
end_decl_stmt

end_unit

