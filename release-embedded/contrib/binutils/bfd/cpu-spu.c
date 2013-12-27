begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 2006, 2007 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation, Inc.,    51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"libbfd.h"
end_include

begin_function
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|spu_compatible
parameter_list|(
specifier|const
name|bfd_arch_info_type
modifier|*
name|a
parameter_list|,
specifier|const
name|bfd_arch_info_type
modifier|*
name|b
parameter_list|)
block|{
name|BFD_ASSERT
argument_list|(
name|a
operator|->
name|arch
operator|==
name|bfd_arch_spu
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|b
operator|->
name|arch
condition|)
block|{
default|default:
return|return
name|NULL
return|;
case|case
name|bfd_arch_spu
case|:
return|return
name|bfd_default_compatible
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
comment|/*NOTREACHED*/
block|}
end_function

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_spu_arch
index|[]
init|=
block|{
block|{
literal|32
block|,
comment|/* 32 bits in a word */
literal|32
block|,
comment|/* 32 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_spu
block|,
comment|/* architecture */
name|bfd_mach_spu
block|,
comment|/* machine */
literal|"spu"
block|,
comment|/* architecture name */
literal|"spu:256K"
block|,
comment|/* printable name */
literal|3
block|,
comment|/* aligned power */
name|TRUE
block|,
comment|/* the default machine for the architecture */
name|spu_compatible
block|,
comment|/* the spu is only compatible with itself, see above */
name|bfd_default_scan
block|,
literal|0
block|,
comment|/* next -- there are none! */
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

