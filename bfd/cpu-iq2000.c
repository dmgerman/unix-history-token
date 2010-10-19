begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the Vitesse IQ2000 processor.    Copyright (C) 2003 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_struct
index|[]
init|=
block|{
block|{
literal|32
block|,
comment|/* bits per word */
literal|32
block|,
comment|/* bits per address */
literal|8
block|,
comment|/* bits per byte */
name|bfd_arch_iq2000
block|,
comment|/* architecture */
name|bfd_mach_iq10
block|,
comment|/* machine */
literal|"iq2000"
block|,
comment|/* architecture name */
literal|"iq10"
block|,
comment|/* printable name */
literal|3
block|,
comment|/* section align power */
name|FALSE
block|,
comment|/* the default ? */
name|bfd_default_compatible
block|,
comment|/* architecture comparison fn */
name|bfd_default_scan
block|,
comment|/* string to architecture convert fn */
name|NULL
comment|/* next in list */
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_iq2000_arch
init|=
block|{
literal|32
block|,
comment|/* bits per word */
literal|32
block|,
comment|/* bits per address */
literal|8
block|,
comment|/* bits per byte */
name|bfd_arch_iq2000
block|,
comment|/* architecture */
name|bfd_mach_iq2000
block|,
comment|/* machine */
literal|"iq2000"
block|,
comment|/* architecture name */
literal|"iq2000"
block|,
comment|/* printable name */
literal|3
block|,
comment|/* section align power */
name|TRUE
block|,
comment|/* the default ? */
name|bfd_default_compatible
block|,
comment|/* architecture comparison fn */
name|bfd_default_scan
block|,
comment|/* string to architecture convert fn */
operator|&
name|arch_info_struct
index|[
literal|0
index|]
block|,
comment|/* next in list */
block|}
decl_stmt|;
end_decl_stmt

end_unit

