begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bfd initialization stuff    Copyright (C) 1990-1991 Free Software Foundation, Inc.    Written by Steve Chamberlain of Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"libbfd.h"
end_include

begin_function_decl
specifier|extern
name|void
name|DEFUN_VOID
parameter_list|(
name|bfd_section_init
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|boolean
name|initialized
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SECTION 	Initialization  	This is the initialization section  */
end_comment

begin_comment
comment|/* FUNCTION 	bfd_init  SYNOPSIS 	void bfd_init(void);  DESCRIPTION 	This routine must be called before any other bfd function to 	initialize magical internal data structures. */
end_comment

begin_function
name|void
name|DEFUN_VOID
parameter_list|(
name|bfd_init
parameter_list|)
block|{
if|if
condition|(
name|initialized
operator|==
name|false
condition|)
block|{
name|initialized
operator|=
name|true
expr_stmt|;
name|bfd_arch_init
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* INTERNAL_FUNCTION 	bfd_check_init  DESCRIPTION 	This routine is called before any other bfd function using 	initialized data is used to ensure that the structures have 	been initialized. Soon this function will go away, and the bfd 	library will assume that bfd_init has been called.  SYNOPSIS 	void bfd_check_init(void); */
end_comment

begin_function
name|void
name|DEFUN_VOID
parameter_list|(
name|bfd_check_init
parameter_list|)
block|{
if|if
condition|(
name|initialized
operator|==
name|false
condition|)
block|{
name|bfd_init
argument_list|()
expr_stmt|;
block|}
block|}
end_function

end_unit

