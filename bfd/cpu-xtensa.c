begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the Xtensa processor.    Copyright 2003 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
name|bfd_xtensa_arch
init|=
block|{
literal|32
block|,
comment|/* Bits per word.  */
literal|32
block|,
comment|/* Bits per address.  */
literal|8
block|,
comment|/* Bits per byte.  */
name|bfd_arch_xtensa
block|,
comment|/* Architecture.  */
name|bfd_mach_xtensa
block|,
comment|/* Machine.  */
literal|"xtensa"
block|,
comment|/* Architecture name.  */
literal|"xtensa"
block|,
comment|/* Printable name.  */
literal|4
block|,
comment|/* Section align power.  */
name|TRUE
block|,
comment|/* The default?  */
name|bfd_default_compatible
block|,
comment|/* Architecture comparison fn.  */
name|bfd_default_scan
block|,
comment|/* String to architecture convert fn.  */
name|NULL
comment|/* Next in list.  */
block|}
decl_stmt|;
end_decl_stmt

end_unit

