begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the MAXQ20/10 architecture.    Copyright  2004, 2005  Free Software Foundation, Inc.     Written by Vineet Sharma(vineets@noida.hcltech.com) 	      Inderpreet Singh(inderpreetb@noida.hcltech.com)		     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
comment|/* MAXQ Archtecture info.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|bfd_maxq10_arch
init|=
block|{
literal|16
block|,
comment|/* 16 bits in a word.  */
literal|16
block|,
comment|/* 16 bits in an address.  */
literal|8
block|,
comment|/* 16 bits in a byte.  */
name|bfd_arch_maxq
block|,
comment|/* Architecture number.  */
name|bfd_mach_maxq10
block|,
comment|/* Machine number.  */
literal|"maxq"
block|,
comment|/* Architecture name.  */
literal|"maxq10"
block|,
comment|/* Machine name.  */
literal|0
block|,
comment|/* Section align power.  */
name|FALSE
block|,
comment|/* Not the default machine.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_maxq_arch
init|=
block|{
literal|16
block|,
comment|/* 16 bits in a word.  */
literal|16
block|,
comment|/* 16 bits in an address.  */
literal|8
block|,
comment|/* 16 bits in a byte.  */
name|bfd_arch_maxq
block|,
comment|/* Architecture number.  */
name|bfd_mach_maxq20
block|,
comment|/* Machine number.  */
literal|"maxq"
block|,
comment|/* Architecture name.  */
literal|"maxq20"
block|,
comment|/* Machine name.  */
literal|0
block|,
comment|/* Section align power.  */
name|TRUE
block|,
comment|/* This is the default machine.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|bfd_maxq10_arch
block|}
decl_stmt|;
end_decl_stmt

end_unit

