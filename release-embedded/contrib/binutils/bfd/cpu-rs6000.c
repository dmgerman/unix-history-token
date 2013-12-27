begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for rs6000 support    Copyright 1990, 1991, 1993, 1995, 2000, 2002, 2003, 2007    Free Software Foundation, Inc.    Written by Mimi Phuong-Thao Vo of IBM    and John Gilmore of Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_comment
comment|/* The RS/6000 architecture is compatible with the PowerPC common    architecture.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|rs6000_compatible
name|PARAMS
argument_list|(
operator|(
specifier|const
name|bfd_arch_info_type
operator|*
operator|,
specifier|const
name|bfd_arch_info_type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|rs6000_compatible
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
specifier|const
name|bfd_arch_info_type
modifier|*
name|a
decl_stmt|;
specifier|const
name|bfd_arch_info_type
modifier|*
name|b
decl_stmt|;
block|{
name|BFD_ASSERT
argument_list|(
name|a
operator|->
name|arch
operator|==
name|bfd_arch_rs6000
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
name|bfd_arch_rs6000
case|:
return|return
name|bfd_default_compatible
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
case|case
name|bfd_arch_powerpc
case|:
if|if
condition|(
name|a
operator|->
name|mach
operator|==
name|bfd_mach_rs6k
condition|)
return|return
name|b
return|;
return|return
name|NULL
return|;
block|}
comment|/*NOTREACHED*/
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_struct
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
name|bfd_arch_rs6000
block|,
name|bfd_mach_rs6k_rs1
block|,
literal|"rs6000"
block|,
literal|"rs6000:rs1"
block|,
literal|3
block|,
name|FALSE
block|,
comment|/* not the default */
name|rs6000_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|1
index|]
block|}
block|,
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
name|bfd_arch_rs6000
block|,
name|bfd_mach_rs6k_rsc
block|,
literal|"rs6000"
block|,
literal|"rs6000:rsc"
block|,
literal|3
block|,
name|FALSE
block|,
comment|/* not the default */
name|rs6000_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|2
index|]
block|}
block|,
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
name|bfd_arch_rs6000
block|,
name|bfd_mach_rs6k_rs2
block|,
literal|"rs6000"
block|,
literal|"rs6000:rs2"
block|,
literal|3
block|,
name|FALSE
block|,
comment|/* not the default */
name|rs6000_compatible
block|,
name|bfd_default_scan
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_rs6000_arch
init|=
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
name|bfd_arch_rs6000
block|,
name|bfd_mach_rs6k
block|,
comment|/* POWER common architecture */
literal|"rs6000"
block|,
literal|"rs6000:6000"
block|,
literal|3
block|,
name|TRUE
block|,
comment|/* the default */
name|rs6000_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|0
index|]
block|}
decl_stmt|;
end_decl_stmt

end_unit

