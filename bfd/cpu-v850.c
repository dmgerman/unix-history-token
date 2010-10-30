begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the NEC V850 processor    Copyright 1996, 1997, 1998, 2000, 2001, 2002, 2003, 2007    Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_include
include|#
directive|include
file|"safe-ctype.h"
end_include

begin_define
define|#
directive|define
name|N
parameter_list|(
name|number
parameter_list|,
name|print
parameter_list|,
define|default, next)  \ {  32, 32, 8, bfd_arch_v850, number, "v850", print, 2, default, \      bfd_default_compatible, bfd_default_scan, next }
end_define

begin_define
define|#
directive|define
name|NEXT
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
name|N
argument_list|(
name|bfd_mach_v850e1
argument_list|,
literal|"v850e1"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|1
index|]
argument_list|)
block|,
name|N
argument_list|(
argument|bfd_mach_v850e
argument_list|,
literal|"v850e"
argument_list|,
argument|FALSE
argument_list|,
argument|NULL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|NEXT
end_undef

begin_define
define|#
directive|define
name|NEXT
value|& arch_info_struct[0]
end_define

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_v850_arch
init|=
name|N
argument_list|(
name|bfd_mach_v850
argument_list|,
literal|"v850"
argument_list|,
name|TRUE
argument_list|,
name|NEXT
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

