begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the HP Precision Architecture architecture.    Copyright 1992, 1995, 1998, 1999, 2000, 2002, 2003, 2007    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|bfd_hppa10_arch
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
name|bfd_arch_hppa
block|,
name|bfd_mach_hppa10
block|,
comment|/* By convention PA1.0 = 10 */
literal|"hppa"
block|,
literal|"hppa1.0"
block|,
literal|3
block|,
name|TRUE
block|,
comment|/* Unless we use 1.1 specific features */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PA2.0 in narrow mode */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|bfd_hppa20_arch
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
name|bfd_arch_hppa
block|,
name|bfd_mach_hppa20
block|,
comment|/* By convention PA2.0 = 20 */
literal|"hppa"
block|,
literal|"hppa2.0"
block|,
literal|3
block|,
name|FALSE
block|,
comment|/* Unless we use 1.1 specific features */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|bfd_hppa10_arch
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PA2.0 in wide mode */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|bfd_hppa20w_arch
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
name|bfd_arch_hppa
block|,
name|bfd_mach_hppa20w
block|,
comment|/* ??? How best to describe wide mode here?  */
literal|"hppa"
block|,
literal|"hppa2.0w"
block|,
literal|3
block|,
name|FALSE
block|,
comment|/* Unless we use 1.1 specific features */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|bfd_hppa20_arch
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_hppa_arch
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
name|bfd_arch_hppa
block|,
name|bfd_mach_hppa11
block|,
comment|/* By convention PA1.1 = 11 */
literal|"hppa"
block|,
literal|"hppa1.1"
block|,
literal|3
block|,
name|FALSE
block|,
comment|/* 1.1 specific features used */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|bfd_hppa20w_arch
block|, }
decl_stmt|;
end_decl_stmt

end_unit

