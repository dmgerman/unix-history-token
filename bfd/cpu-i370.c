begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD i370 CPU definition    Copyright 1994, 1995, 1996, 1998, 1999, 2000, 2002, 2005, 2007    Free Software Foundation, Inc.    Contributed by Ian Lance Taylor, Cygnus Support.    Hacked by Linas Vepstas<linas@linas.org> in 1998, 1999     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,    MA 02110-1301, USA.  */
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
name|arch_info_struct
index|[]
init|=
block|{
comment|/* Hack alert: old old machines are really 16 and 24 bit arch ...  */
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_i370
block|,
literal|360
block|,
comment|/* For the 360.  */
literal|"i370"
block|,
literal|"i370:360"
block|,
literal|3
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
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
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_i370
block|,
literal|370
block|,
comment|/* For the 370.  */
literal|"i370"
block|,
literal|"i370:370"
block|,
literal|3
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_i370_arch
init|=
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_i370
block|,
literal|0
block|,
comment|/* For the 360/370 common architecture.  */
literal|"i370"
block|,
literal|"i370:common"
block|,
literal|3
block|,
name|TRUE
block|,
comment|/* The default.  */
name|bfd_default_compatible
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

