begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD library support routines for the Hitachi-SH architecture.    Copyright (C) 1993 Free Software Foundation, Inc.    Hacked by Steve Chamberlain of Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_function
specifier|static
name|boolean
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
decl_stmt|;
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
block|{
if|if
condition|(
name|strcasecmp
argument_list|(
name|info
operator|->
name|printable_name
argument_list|,
name|string
argument_list|)
operator|==
literal|0
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This routine is provided two arch_infos and returns whether    they'd be compatible */
end_comment

begin_endif
unit|static const bfd_arch_info_type * compatible (a,b)      const bfd_arch_info_type *a;      const bfd_arch_info_type *b; {   if (a->arch != b->arch || a->mach != b->mach)    return NULL;   return a; }
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SH_NEXT
value|&arch_info_struct[0]
end_define

begin_define
define|#
directive|define
name|SH3_NEXT
value|&arch_info_struct[1]
end_define

begin_define
define|#
directive|define
name|SH3E_NEXT
value|&arch_info_struct[2]
end_define

begin_define
define|#
directive|define
name|SH4_NEXT
value|NULL
end_define

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
comment|/* 32 bits in a word */
literal|32
block|,
comment|/* 32 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_sh
block|,
name|bfd_mach_sh3
block|,
literal|"sh"
block|,
comment|/* arch_name  */
literal|"sh3"
block|,
comment|/* printable name */
literal|1
block|,
name|false
block|,
comment|/* not the default */
name|bfd_default_compatible
block|,
name|scan_mach
block|,
name|SH3_NEXT
block|}
block|,
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
name|bfd_arch_sh
block|,
name|bfd_mach_sh3e
block|,
literal|"sh"
block|,
comment|/* arch_name  */
literal|"sh3e"
block|,
comment|/* printable name */
literal|1
block|,
name|false
block|,
comment|/* not the default */
name|bfd_default_compatible
block|,
name|scan_mach
block|,
name|SH3E_NEXT
block|}
block|,
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
name|bfd_arch_sh
block|,
name|bfd_mach_sh4
block|,
literal|"sh"
block|,
comment|/* arch_name  */
literal|"sh4"
block|,
comment|/* printable name */
literal|1
block|,
name|false
block|,
comment|/* not the default */
name|bfd_default_compatible
block|,
name|scan_mach
block|,
name|SH4_NEXT
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_sh_arch
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
name|bfd_arch_sh
block|,
name|bfd_mach_sh
block|,
literal|"sh"
block|,
comment|/* arch_name  */
literal|"sh"
block|,
comment|/* printable name */
literal|1
block|,
name|true
block|,
comment|/* the default machine */
name|bfd_default_compatible
block|,
name|scan_mach
block|,
name|SH_NEXT
block|}
decl_stmt|;
end_decl_stmt

end_unit

