begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Stub functions for Objective-C and Objective-C++ routines    that are called from within the C and C++ front-ends,    respectively.    Copyright (C) 1991, 1995, 1997, 1998,    1999, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"c-common.h"
end_include

begin_function
name|tree
name|lookup_interface
parameter_list|(
name|tree
name|arg
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|is_class_name
parameter_list|(
name|tree
name|arg
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|objc_is_object_ptr
parameter_list|(
name|tree
name|arg
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|tree
name|lookup_objc_ivar
parameter_list|(
name|tree
name|arg
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|objc_check_decl
parameter_list|(
name|tree
name|decl
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_function
name|int
name|objc_comptypes
parameter_list|(
name|tree
name|lhs
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|rhs
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|reflexive
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
name|tree
name|objc_message_selector
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

