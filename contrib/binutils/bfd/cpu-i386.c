begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the Intel 386 architecture.    Copyright 1992, 1994, 1995, 1996, 1998, 2000, 2001    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
specifier|const
name|bfd_arch_info_type
name|bfd_i386_arch_intel_syntax
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
name|bfd_arch_i386
block|,
name|bfd_mach_i386_i386_intel_syntax
block|,
literal|"i386:intel"
block|,
literal|"i386:intel"
block|,
literal|3
block|,
name|true
block|,
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_x86_64_arch_intel_syntax
init|=
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
name|bfd_arch_i386
block|,
name|bfd_mach_x86_64_intel_syntax
block|,
literal|"i386:intel"
block|,
literal|"i386:x86-64:intel"
block|,
literal|3
block|,
name|true
block|,
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|bfd_i386_arch_intel_syntax
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|i8086_arch
init|=
block|{
literal|32
block|,
comment|/* 32 bits in a word */
literal|32
block|,
comment|/* 32 bits in an address (well, not really) */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_i386
block|,
name|bfd_mach_i386_i8086
block|,
literal|"i8086"
block|,
literal|"i8086"
block|,
literal|3
block|,
name|false
block|,
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|bfd_x86_64_arch_intel_syntax
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_x86_64_arch
init|=
block|{
literal|64
block|,
comment|/* 32 bits in a word */
literal|64
block|,
comment|/* 32 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_i386
block|,
name|bfd_mach_x86_64
block|,
literal|"i386"
block|,
literal|"i386:x86-64"
block|,
literal|3
block|,
name|true
block|,
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|i8086_arch
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_i386_arch
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
name|bfd_arch_i386
block|,
name|bfd_mach_i386_i386
block|,
literal|"i386"
block|,
literal|"i386"
block|,
literal|3
block|,
name|true
block|,
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|bfd_x86_64_arch
block|}
decl_stmt|;
end_decl_stmt

end_unit

