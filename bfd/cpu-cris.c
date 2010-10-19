begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the Axis CRIS architecture.    Copyright 2000, 2002, 2004, 2005 Free Software Foundation, Inc.    Contributed by Axis Communications AB.    Written by Hans-Peter Nilsson.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
comment|/* This routine is provided two arch_infos and returns the lowest common    denominator.  CRIS v0..v10 vs. v32 are not compatible in general, but    there's a compatible subset for which we provide an arch_info.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|get_compatible
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
name|get_compatible
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
comment|/* Arches must match.  */
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
comment|/* If either is the compatible mach, return the other.  */
if|if
condition|(
name|a
operator|->
name|mach
operator|==
name|bfd_mach_cris_v10_v32
condition|)
return|return
name|b
return|;
if|if
condition|(
name|b
operator|->
name|mach
operator|==
name|bfd_mach_cris_v10_v32
condition|)
return|return
name|a
return|;
if|#
directive|if
literal|0
comment|/* The code below is disabled but kept as a warning.      See ldlang.c:lang_check.  Quite illogically, incompatible arches      (as signalled by this function) are only *warned* about, while with      this function signalling compatible ones, we can have the      cris_elf_merge_private_bfd_data function return an error.  This is      undoubtedly a FIXME: in general.  Also, the      command_line.warn_mismatch flag and the --no-warn-mismatch option      are misnamed for the multitude of ports that signal compatibility:      it is there an error, not a warning.  We work around it by      pretending matching machs here.  */
comment|/* Except for the compatible mach, machs must match.  */
block|if (a->mach != b->mach)     return NULL;
endif|#
directive|endif
return|return
name|a
return|;
block|}
end_function

begin_define
define|#
directive|define
name|N
parameter_list|(
name|NUMBER
parameter_list|,
name|PRINT
parameter_list|,
name|NEXT
parameter_list|)
define|\
value|{ 32, 32, 8, bfd_arch_cris, NUMBER, "cris", PRINT, 1, FALSE, \    get_compatible, bfd_default_scan, NEXT }
end_define

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|bfd_cris_arch_compat_v10_v32
init|=
name|N
argument_list|(
name|bfd_mach_cris_v10_v32
argument_list|,
literal|"cris:common_v10_v32"
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|bfd_cris_arch_v32
init|=
name|N
argument_list|(
name|bfd_mach_cris_v32
argument_list|,
literal|"crisv32"
argument_list|,
operator|&
name|bfd_cris_arch_compat_v10_v32
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_cris_arch
init|=
block|{
literal|32
block|,
comment|/* There's 32 bits_per_word.  */
literal|32
block|,
comment|/* There's 32 bits_per_address.  */
literal|8
block|,
comment|/* There's 8 bits_per_byte.  */
name|bfd_arch_cris
block|,
comment|/* One of enum bfd_architecture, defined 				   in archures.c and provided in 				   generated header files.  */
name|bfd_mach_cris_v0_v10
block|,
comment|/* Random BFD-internal number for this 				   machine, similarly listed in 				   archures.c.  Not emitted in output.  */
literal|"cris"
block|,
comment|/* The arch_name.  */
literal|"cris"
block|,
comment|/* The printable name is the same.  */
literal|1
block|,
comment|/* Section alignment power; each section 				   is aligned to (only) 2^1 bytes.  */
name|TRUE
block|,
comment|/* This is the default "machine".  */
name|get_compatible
block|,
comment|/* A function for testing 				   "machine" compatibility of two 				   bfd_arch_info_type.  */
name|bfd_default_scan
block|,
comment|/* Check if a bfd_arch_info_type is a 				   match.  */
operator|&
name|bfd_cris_arch_v32
comment|/* Pointer to next bfd_arch_info_type in 				   the same family.  */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Local variables:  * eval: (c-set-style "gnu")  * indent-tabs-mode: t  * End:  */
end_comment

end_unit

