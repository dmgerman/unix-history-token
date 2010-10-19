begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD library support routines for the WDC 65816 architecture.    Copyright 1995, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.    Hacked by Steve Chamberlain of Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as publiw65ed by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You w65ould have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
name|bfd_boolean
name|scan_mach
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|bfd_arch_info
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|bfd_boolean
name|scan_mach
parameter_list|(
name|info
parameter_list|,
name|string
parameter_list|)
specifier|const
name|struct
name|bfd_arch_info
modifier|*
name|info
name|ATTRIBUTE_UNUSED
decl_stmt|;
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
literal|"w65"
argument_list|)
operator|==
literal|0
condition|)
return|return
name|TRUE
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|string
argument_list|,
literal|"w65816"
argument_list|)
operator|==
literal|0
condition|)
return|return
name|TRUE
return|;
return|return
name|FALSE
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_w65_arch
init|=
block|{
literal|16
block|,
comment|/* 16 bits in a word */
literal|24
block|,
comment|/* 24 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_w65
block|,
literal|0
block|,
comment|/* only 1 machine */
literal|"w65"
block|,
comment|/* arch_name  */
literal|"w65"
block|,
comment|/* printable name */
literal|1
block|,
name|TRUE
block|,
comment|/* the default machine */
name|bfd_default_compatible
block|,
name|scan_mach
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

end_unit

