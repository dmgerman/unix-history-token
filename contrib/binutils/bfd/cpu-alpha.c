begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the Alpha architecture.    Copyright 1992, 1993, 1998, 2000 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|{							\     BITS_WORD,
comment|/* bits in a word */
value|\     BITS_ADDR,
comment|/* bits in an address */
value|\     8,
comment|/* 8 bits in a byte */
value|\     bfd_arch_alpha,					\     NUMBER,						\     "alpha",						\     PRINT,						\     3,							\     DEFAULT,						\     bfd_default_compatible, 				\     bfd_default_scan,					\     NEXT,						\   }
end_define

begin_define
define|#
directive|define
name|NN
parameter_list|(
name|index
parameter_list|)
value|(&arch_info_struct[index])
end_define

begin_comment
comment|/* These exist only so that we can resonably disassemble PALcode.  */
end_comment

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
literal|64
argument_list|,
literal|64
argument_list|,
name|bfd_mach_alpha_ev4
argument_list|,
literal|"alpha:ev4"
argument_list|,
name|false
argument_list|,
name|NN
argument_list|(
literal|1
argument_list|)
argument_list|)
block|,
name|N
argument_list|(
literal|64
argument_list|,
literal|64
argument_list|,
name|bfd_mach_alpha_ev5
argument_list|,
literal|"alpha:ev5"
argument_list|,
name|false
argument_list|,
name|NN
argument_list|(
literal|2
argument_list|)
argument_list|)
block|,
name|N
argument_list|(
literal|64
argument_list|,
literal|64
argument_list|,
name|bfd_mach_alpha_ev6
argument_list|,
literal|"alpha:ev6"
argument_list|,
name|false
argument_list|,
literal|0
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_alpha_arch
init|=
name|N
argument_list|(
literal|64
argument_list|,
literal|64
argument_list|,
literal|0
argument_list|,
literal|"alpha"
argument_list|,
name|true
argument_list|,
name|NN
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

