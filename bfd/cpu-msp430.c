begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD library support routines for the MSP architecture.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.    Contributed by Dmitry Diky<diwil@mail.ru>     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|compatible
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

begin_define
define|#
directive|define
name|N
parameter_list|(
name|addr_bits
parameter_list|,
name|machine
parameter_list|,
name|print
parameter_list|,
define|default, next)		\ {								\   16,
comment|/* 16 bits in a word.  */
define|\   addr_bits,
comment|/* Bits in an address.  */
define|\   8,
comment|/* 8 bits in a byte.  */
define|\   bfd_arch_msp430,						\   machine,
comment|/* Machine number.  */
define|\   "msp430",
comment|/* Architecture name.   */
define|\   print,
comment|/* Printable name.  */
define|\   1,
comment|/* Section align power.  */
define|\   default,
comment|/* The default machine.  */
define|\   compatible,							\   bfd_default_scan,						\   next								\ }
end_define

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_struct
index|[]
init|=
block|{
comment|/* msp430x11x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp11
argument_list|,
literal|"msp:11"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|1
index|]
argument_list|)
block|,
comment|/* msp430x11x1.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp110
argument_list|,
literal|"msp:110"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|2
index|]
argument_list|)
block|,
comment|/* msp430x12x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp12
argument_list|,
literal|"msp:12"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|3
index|]
argument_list|)
block|,
comment|/* msp430x13x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp13
argument_list|,
literal|"msp:13"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|4
index|]
argument_list|)
block|,
comment|/* msp430x14x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp14
argument_list|,
literal|"msp:14"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|5
index|]
argument_list|)
block|,
comment|/* msp430x15x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp15
argument_list|,
literal|"msp:15"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|6
index|]
argument_list|)
block|,
comment|/* msp430x16x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp16
argument_list|,
literal|"msp:16"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|7
index|]
argument_list|)
block|,
comment|/* msp430x21x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp21
argument_list|,
literal|"msp:21"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|8
index|]
argument_list|)
block|,
comment|/* msp430x31x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp31
argument_list|,
literal|"msp:31"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|9
index|]
argument_list|)
block|,
comment|/* msp430x32x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp32
argument_list|,
literal|"msp:32"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|10
index|]
argument_list|)
block|,
comment|/* msp430x33x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp33
argument_list|,
literal|"msp:33"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|11
index|]
argument_list|)
block|,
comment|/* msp430x41x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp41
argument_list|,
literal|"msp:41"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|12
index|]
argument_list|)
block|,
comment|/* msp430x42x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp42
argument_list|,
literal|"msp:42"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|13
index|]
argument_list|)
block|,
comment|/* msp430x43x.  */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp43
argument_list|,
literal|"msp:43"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|14
index|]
argument_list|)
block|,
comment|/* msp430x44x.  */
name|N
argument_list|(
literal|16
argument_list|,
argument|bfd_mach_msp43
argument_list|,
literal|"msp:44"
argument_list|,
argument|FALSE
argument_list|,
argument|NULL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_msp430_arch
init|=
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_msp14
argument_list|,
literal|"msp:14"
argument_list|,
name|TRUE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This routine is provided two arch_infos and works out which MSP    machine which would be compatible with both and returns a pointer    to its info structure.  */
end_comment

begin_function
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|compatible
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
comment|/* If a& b are for different architectures we can do nothing.  */
if|if
condition|(
name|a
operator|->
name|arch
operator|!=
name|b
operator|->
name|arch
condition|)
return|return
name|NULL
return|;
if|if
condition|(
name|a
operator|->
name|mach
operator|<=
name|b
operator|->
name|mach
condition|)
return|return
name|b
return|;
return|return
name|a
return|;
block|}
end_function

end_unit

