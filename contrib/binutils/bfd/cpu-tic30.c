begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the Texas Instruments TMS320C30 architecture.    Copyright 1998 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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
name|bfd_tic30_arch
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
name|bfd_arch_tic30
block|,
literal|0
block|,
comment|/* only 1 machine */
literal|"tic30"
block|,
literal|"tms320c30"
block|,
literal|2
block|,
name|true
block|,
comment|/* the one and only */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

end_unit

