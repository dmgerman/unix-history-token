begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the SPARC architecture.    Copyright 1992, 1995, 1996, 1998, 2000 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* Don't mix 32 bit and 64 bit files.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|sparc_compatible
name|PARAMS
argument_list|(
operator|(
specifier|const
name|bfd_arch_info_type
operator|*
operator|,
specifier|const
name|bfd_arch_info_type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|sparc_compatible
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
specifier|const
name|bfd_arch_info_type
modifier|*
name|a
decl_stmt|;
specifier|const
name|bfd_arch_info_type
modifier|*
name|b
decl_stmt|;
block|{
if|if
condition|(
name|a
operator|->
name|bits_per_word
operator|!=
name|b
operator|->
name|bits_per_word
condition|)
return|return
name|NULL
return|;
return|return
name|bfd_default_compatible
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

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
comment|/* bits in a word */
literal|32
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_sparc
block|,
name|bfd_mach_sparc_sparclet
block|,
literal|"sparc"
block|,
literal|"sparc:sparclet"
block|,
literal|3
block|,
name|false
block|,
name|sparc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|1
index|]
block|,   }
block|,
block|{
literal|32
block|,
comment|/* bits in a word */
literal|32
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_sparc
block|,
name|bfd_mach_sparc_sparclite
block|,
literal|"sparc"
block|,
literal|"sparc:sparclite"
block|,
literal|3
block|,
name|false
block|,
name|sparc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|2
index|]
block|,   }
block|,
block|{
literal|32
block|,
comment|/* bits in a word */
literal|32
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_sparc
block|,
name|bfd_mach_sparc_v8plus
block|,
literal|"sparc"
block|,
literal|"sparc:v8plus"
block|,
literal|3
block|,
name|false
block|,
name|sparc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|3
index|]
block|,   }
block|,
block|{
literal|32
block|,
comment|/* bits in a word */
literal|32
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_sparc
block|,
name|bfd_mach_sparc_v8plusa
block|,
literal|"sparc"
block|,
literal|"sparc:v8plusa"
block|,
literal|3
block|,
name|false
block|,
name|sparc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|4
index|]
block|,   }
block|,
block|{
literal|32
block|,
comment|/* bits in a word */
literal|32
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_sparc
block|,
name|bfd_mach_sparc_sparclite_le
block|,
literal|"sparc"
block|,
literal|"sparc:sparclite_le"
block|,
literal|3
block|,
name|false
block|,
name|sparc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|5
index|]
block|,   }
block|,
block|{
literal|64
block|,
comment|/* bits in a word */
literal|64
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_sparc
block|,
name|bfd_mach_sparc_v9
block|,
literal|"sparc"
block|,
literal|"sparc:v9"
block|,
literal|3
block|,
name|false
block|,
name|sparc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|6
index|]
block|,   }
block|,
block|{
literal|64
block|,
comment|/* bits in a word */
literal|64
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_sparc
block|,
name|bfd_mach_sparc_v9a
block|,
literal|"sparc"
block|,
literal|"sparc:v9a"
block|,
literal|3
block|,
name|false
block|,
name|sparc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|7
index|]
block|,   }
block|,
block|{
literal|32
block|,
comment|/* bits in a word */
literal|32
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_sparc
block|,
name|bfd_mach_sparc_v8plusb
block|,
literal|"sparc"
block|,
literal|"sparc:v8plusb"
block|,
literal|3
block|,
name|false
block|,
name|sparc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|8
index|]
block|,   }
block|,
block|{
literal|64
block|,
comment|/* bits in a word */
literal|64
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_sparc
block|,
name|bfd_mach_sparc_v9b
block|,
literal|"sparc"
block|,
literal|"sparc:v9b"
block|,
literal|3
block|,
name|false
block|,
name|sparc_compatible
block|,
name|bfd_default_scan
block|,
literal|0
block|,   }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_sparc_arch
init|=
block|{
literal|32
block|,
comment|/* bits in a word */
literal|32
block|,
comment|/* bits in an address */
literal|8
block|,
comment|/* bits in a byte */
name|bfd_arch_sparc
block|,
name|bfd_mach_sparc
block|,
literal|"sparc"
block|,
literal|"sparc"
block|,
literal|3
block|,
name|true
block|,
comment|/* the default */
name|sparc_compatible
block|,
name|bfd_default_scan
block|,
operator|&
name|arch_info_struct
index|[
literal|0
index|]
block|,   }
decl_stmt|;
end_decl_stmt

end_unit

