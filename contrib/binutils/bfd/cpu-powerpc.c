begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD PowerPC CPU definition    Copyright 1994, 1995, 1996, 2000 Free Software Foundation, Inc.    Contributed by Ian Lance Taylor, Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* The common PowerPC architecture is compatible with the RS/6000.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|powerpc_compatible
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
name|powerpc_compatible
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
name|bfd_arch_powerpc
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
name|bfd_arch_powerpc
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
name|bfd_arch_rs6000
case|:
if|if
condition|(
name|a
operator|->
name|mach
operator|==
literal|0
condition|)
return|return
name|a
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
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_603
block|,
literal|"powerpc"
block|,
literal|"powerpc:603"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
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
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_ec603e
block|,
literal|"powerpc"
block|,
literal|"powerpc:EC603e"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
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
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_604
block|,
literal|"powerpc"
block|,
literal|"powerpc:604"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|3
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
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_403
block|,
literal|"powerpc"
block|,
literal|"powerpc:403"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|4
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
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_601
block|,
literal|"powerpc"
block|,
literal|"powerpc:601"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|5
index|]
block|}
block|,
block|{
literal|64
block|,
comment|/* 64 bits in a word */
literal|64
block|,
comment|/* 64 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_620
block|,
literal|"powerpc"
block|,
literal|"powerpc:620"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|6
index|]
block|}
block|,
block|{
literal|64
block|,
comment|/* 64 bits in a word */
literal|64
block|,
comment|/* 64 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_630
block|,
literal|"powerpc"
block|,
literal|"powerpc:630"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|7
index|]
block|}
block|,
block|{
literal|64
block|,
comment|/* 64 bits in a word */
literal|64
block|,
comment|/* 64 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_a35
block|,
literal|"powerpc"
block|,
literal|"powerpc:a35"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|8
index|]
block|}
block|,
block|{
literal|64
block|,
comment|/* 64 bits in a word */
literal|64
block|,
comment|/* 64 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_rs64ii
block|,
literal|"powerpc"
block|,
literal|"powerpc:rs64ii"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|9
index|]
block|}
block|,
block|{
literal|64
block|,
comment|/* 64 bits in a word */
literal|64
block|,
comment|/* 64 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_rs64iii
block|,
literal|"powerpc"
block|,
literal|"powerpc:rs64iii"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|10
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
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_7400
block|,
literal|"powerpc"
block|,
literal|"powerpc:7400"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|11
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
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc_860
block|,
literal|"powerpc"
block|,
literal|"powerpc:MPC8XX"
block|,
literal|3
block|,
name|false
block|,
comment|/* not the default */
name|powerpc_compatible
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
name|bfd_powerpc_arch
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
name|bfd_arch_powerpc
block|,
name|bfd_mach_ppc
block|,
comment|/* for the POWER/PowerPC common architecture */
literal|"powerpc"
block|,
literal|"powerpc:common"
block|,
literal|3
block|,
name|true
block|,
comment|/* the default */
name|powerpc_compatible
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

