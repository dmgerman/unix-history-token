begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the score processor    Copyright 2006, 2007 Free Software Foundation, Inc.       Contributed by    Mei Ligang (ligang@sunnorth.com.cn)    Pei-Lin Tsai (pltsai@sunplus.com)       This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
name|bfd_score_arch
init|=
block|{
literal|32
block|,
comment|/* There's 32 bits_per_word.  */
literal|32
block|,
comment|/* There's 32 bits_per_address.  */
literal|8
block|,
comment|/* There's 8 bits_per_byte.  */
name|bfd_arch_score
block|,
comment|/* One of enum bfd_architecture, defined 				   in archures.c and provided in 				   generated header files.  */
literal|0
block|,
comment|/* Only 1 machine, but #255 for 				   historical reasons.  */
literal|"score"
block|,
comment|/* The arch_name.  */
literal|"score"
block|,
comment|/* The printable name is the same.  */
literal|4
block|,
comment|/* Section alignment power; each section 				   is aligned to (only) 2^4 bytes.  */
name|TRUE
block|,
comment|/* This is the default "machine", since 				   there's only one.  */
name|bfd_default_compatible
block|,
comment|/* A default function for testing 				   "machine" compatibility of two 				   bfd_arch_info_type.  */
name|bfd_default_scan
block|,
comment|/* Check if an bfd_arch_info_type is a 				   match.  */
name|NULL
comment|/* Pointer to next bfd_arch_info_type in 				   the same family.  */
block|}
decl_stmt|;
end_decl_stmt

end_unit

