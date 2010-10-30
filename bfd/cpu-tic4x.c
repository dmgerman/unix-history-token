begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bfd back-end for TMS320C[34]x support    Copyright 1996, 1997, 2002, 2003, 2007 Free Software Foundation, Inc.     Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz)     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_decl_stmt
specifier|static
name|bfd_boolean
name|tic4x_scan
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
name|tic4x_scan
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
comment|/* Allow strings of form [ti][Cc][34][0-9], let's not be too picky      about strange numbered machines in C3x or C4x series.  */
if|if
condition|(
name|string
index|[
literal|0
index|]
operator|==
literal|'t'
operator|&&
name|string
index|[
literal|1
index|]
operator|==
literal|'i'
condition|)
name|string
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|==
literal|'C'
operator|||
operator|*
name|string
operator|==
literal|'c'
condition|)
name|string
operator|++
expr_stmt|;
if|if
condition|(
name|string
index|[
literal|1
index|]
operator|<
literal|'0'
operator|&&
name|string
index|[
literal|1
index|]
operator|>
literal|'9'
condition|)
return|return
name|FALSE
return|;
if|if
condition|(
operator|*
name|string
operator|==
literal|'3'
condition|)
return|return
operator|(
name|info
operator|->
name|mach
operator|==
name|bfd_mach_tic3x
operator|)
return|;
elseif|else
if|if
condition|(
operator|*
name|string
operator|==
literal|'4'
condition|)
return|return
name|info
operator|->
name|mach
operator|==
name|bfd_mach_tic4x
return|;
return|return
name|FALSE
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_tic3x_arch
init|=
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|32
block|,
comment|/* 32 bits in a byte.  */
name|bfd_arch_tic4x
block|,
name|bfd_mach_tic3x
block|,
comment|/* Machine number.  */
literal|"tic3x"
block|,
comment|/* Architecture name.  */
literal|"tms320c3x"
block|,
comment|/* Printable name.  */
literal|0
block|,
comment|/* Alignment power.  */
name|FALSE
block|,
comment|/* Not the default architecture.  */
name|bfd_default_compatible
block|,
name|tic4x_scan
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_tic4x_arch
init|=
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|32
block|,
comment|/* 32 bits in a byte.  */
name|bfd_arch_tic4x
block|,
name|bfd_mach_tic4x
block|,
comment|/* Machine number.  */
literal|"tic4x"
block|,
comment|/* Architecture name.  */
literal|"tms320c4x"
block|,
comment|/* Printable name.  */
literal|0
block|,
comment|/* Alignment power.  */
name|TRUE
block|,
comment|/* The default architecture.  */
name|bfd_default_compatible
block|,
name|tic4x_scan
block|,
operator|&
name|bfd_tic3x_arch
block|,   }
decl_stmt|;
end_decl_stmt

end_unit

