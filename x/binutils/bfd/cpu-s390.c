begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the s390 processor.    Copyright 2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Carl B. Pedersen and Martin Schwidefsky.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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
name|bfd_s390_64_arch
init|=
block|{
literal|64
block|,
comment|/* bits in a word */
literal|64
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_s390
block|,
name|bfd_mach_s390_64
block|,
literal|"s390"
block|,
literal|"s390:64-bit"
block|,
literal|3
block|,
comment|/* section alignment power */
name|TRUE
block|,
comment|/* the default */
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
name|bfd_s390_arch
init|=
block|{
literal|32
block|,
comment|/* bits in a word */
literal|32
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_s390
block|,
name|bfd_mach_s390_31
block|,
literal|"s390"
block|,
literal|"s390:31-bit"
block|,
literal|3
block|,
comment|/* section alignment power */
name|TRUE
block|,
comment|/* the default */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|bfd_s390_64_arch
block|}
decl_stmt|;
end_decl_stmt

end_unit

