begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the Infineon XC16X Microcontroller.    Copyright 2006, 2007 Free Software Foundation, Inc.    Contributed by KPIT Cummins Infosystems      This file is part of BFD, the Binary File Descriptor library.    Contributed by Anil Paranjpe(anilp1@kpitcummins.com)     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
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
specifier|const
name|bfd_arch_info_type
name|xc16xs_info_struct
init|=
block|{
literal|16
block|,
comment|/* Bits per word.  */
literal|16
block|,
comment|/* Bits per address.  */
literal|8
block|,
comment|/* Bits per byte.  */
name|bfd_arch_xc16x
block|,
comment|/* Architecture.  */
name|bfd_mach_xc16xs
block|,
comment|/* Machine.  */
literal|"xc16x"
block|,
comment|/* Architecture name.  */
literal|"xc16xs"
block|,
comment|/* Printable name.  */
literal|1
block|,
comment|/* Section alignment - 16 bit.  */
name|TRUE
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|xc16xl_info_struct
init|=
block|{
literal|16
block|,
comment|/* Bits per word.  */
literal|32
block|,
comment|/* Bits per address.  */
literal|8
block|,
comment|/* Bits per byte.  */
name|bfd_arch_xc16x
block|,
comment|/* Architecture.  */
name|bfd_mach_xc16xl
block|,
comment|/* Machine.  */
literal|"xc16x"
block|,
comment|/* Architecture name.  */
literal|"xc16xl"
block|,
comment|/* Printable name.  */
literal|1
block|,
comment|/* Section alignment - 16 bit.  */
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
name|xc16xs_info_struct
comment|/* Next in list.  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_xc16x_arch
init|=
block|{
literal|16
block|,
comment|/* Bits per word.  */
literal|16
block|,
comment|/* Bits per address.  */
literal|8
block|,
comment|/* Bits per byte.  */
name|bfd_arch_xc16x
block|,
comment|/* Architecture.  */
name|bfd_mach_xc16x
block|,
comment|/* Machine.  */
literal|"xc16x"
block|,
comment|/* Architecture name.  */
literal|"xc16x"
block|,
comment|/* Printable name.  */
literal|1
block|,
comment|/* Section alignment - 16 bit.  */
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
name|xc16xl_info_struct
comment|/* Next in list.  */
block|}
decl_stmt|;
end_decl_stmt

end_unit

