begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Dummy subroutines for language-specific support on Windows.    Contributed by Danny Smith (dannysmith@users.sourceforge.net)    Copyright (C) 2005    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"regs.h"
end_include

begin_include
include|#
directive|include
file|"hard-reg-set.h"
end_include

begin_include
include|#
directive|include
file|"output.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_include
include|#
directive|include
file|"tm_p.h"
end_include

begin_include
include|#
directive|include
file|"toplev.h"
end_include

begin_include
include|#
directive|include
file|"hashtab.h"
end_include

begin_function
name|bool
name|i386_pe_type_dllimport_p
parameter_list|(
name|tree
name|decl
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|i386_pe_type_dllexport_p
parameter_list|(
name|tree
name|decl
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
name|void
name|i386_pe_adjust_class_at_definition
parameter_list|(
name|tree
name|t
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

end_unit

