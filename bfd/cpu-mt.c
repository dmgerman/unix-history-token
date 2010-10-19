begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the Morpho Technologies MT processor.    Copyright (C) 2001, 2002, 2005 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|arch_info_struct
index|[]
init|=
block|{
block|{
literal|32
block|,
comment|/* Bits per word - not really true.  */
literal|32
block|,
comment|/* Bits per address.  */
literal|8
block|,
comment|/* Bits per byte.  */
name|bfd_arch_mt
block|,
comment|/* Architecture.  */
name|bfd_mach_mrisc2
block|,
comment|/* Machine.  */
literal|"mt"
block|,
comment|/* Architecture name.  */
literal|"ms1-003"
block|,
comment|/* Printable name.  */
literal|1
block|,
comment|/* Section align power.  */
name|FALSE
block|,
comment|/* The default ?  */
name|bfd_default_compatible
block|,
comment|/* Architecture comparison fn.  */
name|bfd_default_scan
block|,
comment|/* String to architecture convert fn.  */
operator|&
name|arch_info_struct
index|[
literal|1
index|]
comment|/* Next in list.  */
block|}
block|,
block|{
literal|32
block|,
comment|/* Bits per word - not really true.  */
literal|32
block|,
comment|/* Bits per address.  */
literal|8
block|,
comment|/* Bits per byte.  */
name|bfd_arch_mt
block|,
comment|/* Architecture.  */
name|bfd_mach_ms2
block|,
comment|/* Machine.  */
literal|"mt"
block|,
comment|/* Architecture name.  */
literal|"ms2"
block|,
comment|/* Printable name.  */
literal|1
block|,
comment|/* Section align power.  */
name|FALSE
block|,
comment|/* The default ?  */
name|bfd_default_compatible
block|,
comment|/* Architecture comparison fn.  */
name|bfd_default_scan
block|,
comment|/* String to architecture convert fn.  */
name|NULL
comment|/* Next in list.  */
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_mt_arch
init|=
block|{
literal|32
block|,
comment|/* Bits per word - not really true.  */
literal|32
block|,
comment|/* Bits per address.  */
literal|8
block|,
comment|/* Bits per byte.  */
name|bfd_arch_mt
block|,
comment|/* Architecture.  */
name|bfd_mach_ms1
block|,
comment|/* Machine.  */
literal|"mt"
block|,
comment|/* Architecture name.  */
literal|"ms1"
block|,
comment|/* Printable name.  */
literal|1
block|,
comment|/* Section align power.  */
name|TRUE
block|,
comment|/* The default ?  */
name|bfd_default_compatible
block|,
comment|/* Architecture comparison fn.  */
name|bfd_default_scan
block|,
comment|/* String to architecture convert fn.  */
operator|&
name|arch_info_struct
index|[
literal|0
index|]
comment|/* Next in list.  */
block|}
decl_stmt|;
end_decl_stmt

end_unit

