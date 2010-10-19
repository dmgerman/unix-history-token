begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the Intel 860 architecture.    Copyright 1992, 1995, 2000, 2002 Free Software Foundation, Inc.    Created mostly by substituting "860" for "386" in cpu-i386.c    Harry Dolan<dolan@ssd.intel.com>, October 1995  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
name|bfd_i860_arch
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
name|bfd_arch_i860
block|,
comment|/* Architecture */
literal|0
block|,
comment|/* Only one machine */
literal|"i860"
block|,
comment|/* Architecture name */
literal|"i860"
block|,
comment|/* Printable name */
literal|3
block|,
comment|/* Section alignment exponent */
name|TRUE
block|,
comment|/* Is this the default architecture? */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
literal|0
block|,
comment|/* Next in list */
block|}
decl_stmt|;
end_decl_stmt

end_unit

