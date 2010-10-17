begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD library support routines for the AVR architecture.    Copyright 1999, 2000, 2002 Free Software Foundation, Inc.    Contributed by Denis Chertykov<denisc@overta.ru>  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
specifier|const
name|bfd_arch_info_type
modifier|*
name|compatible
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

begin_define
define|#
directive|define
name|N
parameter_list|(
name|addr_bits
parameter_list|,
name|machine
parameter_list|,
name|print
parameter_list|,
define|default, next)		\ {								\   8,
comment|/* 8 bits in a word */
define|\   addr_bits,
comment|/* bits in an address */
define|\   8,
comment|/* 8 bits in a byte */
define|\   bfd_arch_avr,							\   machine,
comment|/* machine */
define|\   "avr",
comment|/* arch_name  */
define|\   print,
comment|/* printable name */
define|\   1,
comment|/* section align power */
define|\   default,
comment|/* the default machine */
define|\   compatible,							\   bfd_default_scan,						\   next								\ }
end_define

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|arch_info_struct
index|[]
init|=
block|{
comment|/* AT90S1200, ATtiny1x, ATtiny28 */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_avr1
argument_list|,
literal|"avr:1"
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
comment|/* AT90S2xxx, AT90S4xxx, AT90S8xxx, ATtiny22 */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_avr2
argument_list|,
literal|"avr:2"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|2
index|]
argument_list|)
block|,
comment|/* ATmega103, ATmega603 */
name|N
argument_list|(
literal|22
argument_list|,
name|bfd_mach_avr3
argument_list|,
literal|"avr:3"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|3
index|]
argument_list|)
block|,
comment|/* ATmega83, ATmega85 */
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_avr4
argument_list|,
literal|"avr:4"
argument_list|,
name|FALSE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|4
index|]
argument_list|)
block|,
comment|/* ATmega161, ATmega163, ATmega32, AT94K */
name|N
argument_list|(
literal|22
argument_list|,
argument|bfd_mach_avr5
argument_list|,
literal|"avr:5"
argument_list|,
argument|FALSE
argument_list|,
argument|NULL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_avr_arch
init|=
name|N
argument_list|(
literal|16
argument_list|,
name|bfd_mach_avr2
argument_list|,
literal|"avr"
argument_list|,
name|TRUE
argument_list|,
operator|&
name|arch_info_struct
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This routine is provided two arch_infos and works out which AVR    machine which would be compatible with both and returns a pointer    to its info structure.  */
end_comment

begin_function
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|compatible
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
comment|/* If a& b are for different architectures we can do nothing.  */
if|if
condition|(
name|a
operator|->
name|arch
operator|!=
name|b
operator|->
name|arch
condition|)
return|return
name|NULL
return|;
comment|/* Special case for ATmega[16]03 (avr:3) and ATmega83 (avr:4).  */
if|if
condition|(
operator|(
name|a
operator|->
name|mach
operator|==
name|bfd_mach_avr3
operator|&&
name|b
operator|->
name|mach
operator|==
name|bfd_mach_avr4
operator|)
operator|||
operator|(
name|a
operator|->
name|mach
operator|==
name|bfd_mach_avr4
operator|&&
name|b
operator|->
name|mach
operator|==
name|bfd_mach_avr3
operator|)
condition|)
return|return
name|NULL
return|;
comment|/* So far all newer AVR architecture cores are supersets of previous      cores.  */
if|if
condition|(
name|a
operator|->
name|mach
operator|<=
name|b
operator|->
name|mach
condition|)
return|return
name|b
return|;
if|if
condition|(
name|a
operator|->
name|mach
operator|>=
name|b
operator|->
name|mach
condition|)
return|return
name|a
return|;
comment|/* Never reached!  */
return|return
name|NULL
return|;
block|}
end_function

end_unit

