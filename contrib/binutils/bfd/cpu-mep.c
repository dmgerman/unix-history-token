begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the Toshiba Media Engine Processor.    Copyright (C) 2001, 2002, 2004, 2007 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_define
define|#
directive|define
name|MA
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|,
name|def
parameter_list|,
name|y
parameter_list|)
value|{ 32, 32, 8, bfd_arch_mep, x, "mep", n, \ 	2, def, bfd_default_compatible, bfd_default_scan, y }
end_define

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|bfd_h1_arch
init|=
name|MA
argument_list|(
name|bfd_mach_mep_h1
argument_list|,
literal|"h1"
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_mep_arch
init|=
name|MA
argument_list|(
name|bfd_mach_mep
argument_list|,
literal|"mep"
argument_list|,
name|TRUE
argument_list|,
operator|&
name|bfd_h1_arch
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

