begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  This is part of GNU C++ Library. Copyright (C) 1994 Free Software Foundation  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_comment
comment|/* terminate(), unexpected(), set_terminate(), set_unexpected() as    well as the default terminate func and default unexpected func */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern int printf();
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vfp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_function
name|void
name|__default_terminate
parameter_list|()
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|__default_unexpected
parameter_list|()
block|{
name|__default_terminate
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
name|vfp
name|__terminate_func
init|=
name|__default_terminate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|vfp
name|__unexpected_func
init|=
name|__default_unexpected
decl_stmt|;
end_decl_stmt

begin_function
name|vfp
name|set_terminate
parameter_list|(
name|func
parameter_list|)
name|vfp
name|func
decl_stmt|;
block|{
name|vfp
name|old
init|=
name|__terminate_func
decl_stmt|;
name|__terminate_func
operator|=
name|func
expr_stmt|;
return|return
name|old
return|;
block|}
end_function

begin_function
name|vfp
name|set_unexpected
parameter_list|(
name|func
parameter_list|)
name|vfp
name|func
decl_stmt|;
block|{
name|vfp
name|old
init|=
name|__unexpected_func
decl_stmt|;
name|__unexpected_func
operator|=
name|func
expr_stmt|;
return|return
name|old
return|;
block|}
end_function

begin_function
name|void
name|terminate
parameter_list|()
block|{
name|__terminate_func
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|unexpected
parameter_list|()
block|{
name|__unexpected_func
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

