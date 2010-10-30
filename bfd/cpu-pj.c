begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD library support routines for the Pico Java architecture.    Copyright 1999, 2000, 2001, 2002, 2007 Free Software Foundation, Inc.    Hacked by Steve Chamberlain of Transmeta. sac@pobox.com  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
name|bfd_pj_arch
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
name|bfd_arch_pj
block|,
literal|0
block|,
literal|"pj"
block|,
comment|/* arch_name  */
literal|"pj"
block|,
comment|/* printable name */
literal|1
block|,
name|TRUE
block|,
comment|/* the default machine */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

