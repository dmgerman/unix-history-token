begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the OpenRISC architecture.    Copyright 2001, 2002 Free Software Foundation, Inc.    Contributed by Johan Rydberg, jrydberg@opencores.org  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_define
define|#
directive|define
name|N
parameter_list|(
name|BITS_WORD
parameter_list|,
name|BITS_ADDR
parameter_list|,
name|NUMBER
parameter_list|,
name|PRINT
parameter_list|,
name|DEFAULT
parameter_list|,
name|NEXT
parameter_list|)
define|\
value|{                                                           \     BITS_WORD,
comment|/* bits in a word */
value|\     BITS_ADDR,
comment|/* bits in an address */
value|\     8,
comment|/* 8 bits in a byte */
value|\     bfd_arch_openrisc,                                        \     NUMBER,                                                   \     "openrisc",                                               \     PRINT,                                                    \     2,                                                        \     DEFAULT,                                                  \     bfd_default_compatible,                                   \     bfd_default_scan,                                         \     NEXT,                                                     \   }
end_define

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_openrisc_arch
init|=
name|N
argument_list|(
literal|32
argument_list|,
literal|32
argument_list|,
literal|0
argument_list|,
literal|"openrisc"
argument_list|,
name|TRUE
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

