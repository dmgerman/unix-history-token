begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for rs6000 support    Copyright (C) 1990, 1991 Free Software Foundation, Inc.    FIXME: Can someone provide a transliteration of this name into ASCII?    Using the following chars caused a compiler warning on HIUX (so I replaced    them with octal escapes), and isn't useful without an understanding of what    character set it is.    Written by Mimi Ph\373\364ng-Th\345o V\365 of IBM    and John Gilmore of Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* The RS/6000 architecture is compatible with the PowerPC common    architecture.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|rs6000_compatible
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
name|rs6000_compatible
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
name|BFD_ASSERT
argument_list|(
name|a
operator|->
name|arch
operator|==
name|bfd_arch_rs6000
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|b
operator|->
name|arch
condition|)
block|{
default|default:
return|return
name|NULL
return|;
case|case
name|bfd_arch_rs6000
case|:
return|return
name|bfd_default_compatible
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
case|case
name|bfd_arch_powerpc
case|:
if|if
condition|(
name|b
operator|->
name|mach
operator|==
literal|0
condition|)
return|return
name|b
return|;
return|return
name|NULL
return|;
block|}
comment|/*NOTREACHED*/
block|}
end_function

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_rs6000_arch
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
name|bfd_arch_rs6000
block|,
literal|6000
block|,
comment|/* only 1 machine */
literal|"rs6000"
block|,
literal|"rs6000:6000"
block|,
literal|3
block|,
name|true
block|,
comment|/* the one and only */
name|rs6000_compatible
block|,
name|bfd_default_scan
block|,
literal|0
block|,   }
decl_stmt|;
end_decl_stmt

end_unit

