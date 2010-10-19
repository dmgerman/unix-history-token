begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bfd back-end for TI TMS320C80 (MVP) support    Copyright 1996, 2002 Free Software Foundation, Inc.    Written by Fred Fish at Cygnus support (fnf@cygnus.com)  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
name|bfd_tic80_arch
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
name|bfd_arch_tic80
block|,
comment|/* bfd_architecture enum */
literal|0
block|,
comment|/* only 1 machine */
literal|"tic80"
block|,
comment|/* architecture name */
literal|"tic80"
block|,
comment|/* printable name */
literal|2
block|,
comment|/* section alignment power */
name|TRUE
block|,
comment|/* default machine for architecture */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|NULL
block|,
comment|/* Pointer to next in chain */
block|}
decl_stmt|;
end_decl_stmt

end_unit

