begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD library support routines for the Renesas / SuperH SH architecture.    Copyright 1993, 1994, 1997, 1998, 2000, 2001, 2002, 2003, 2004, 2005,    2007 Free Software Foundation, Inc.    Hacked by Steve Chamberlain of Cygnus Support.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"../opcodes/sh-opc.h"
end_include

begin_define
define|#
directive|define
name|SH_NEXT
value|arch_info_struct + 0
end_define

begin_define
define|#
directive|define
name|SH2_NEXT
value|arch_info_struct + 1
end_define

begin_define
define|#
directive|define
name|SH2E_NEXT
value|arch_info_struct + 2
end_define

begin_define
define|#
directive|define
name|SH_DSP_NEXT
value|arch_info_struct + 3
end_define

begin_define
define|#
directive|define
name|SH3_NEXT
value|arch_info_struct + 4
end_define

begin_define
define|#
directive|define
name|SH3_NOMMU_NEXT
value|arch_info_struct + 5
end_define

begin_define
define|#
directive|define
name|SH3_DSP_NEXT
value|arch_info_struct + 6
end_define

begin_define
define|#
directive|define
name|SH3E_NEXT
value|arch_info_struct + 7
end_define

begin_define
define|#
directive|define
name|SH4_NEXT
value|arch_info_struct + 8
end_define

begin_define
define|#
directive|define
name|SH4A_NEXT
value|arch_info_struct + 9
end_define

begin_define
define|#
directive|define
name|SH4AL_DSP_NEXT
value|arch_info_struct + 10
end_define

begin_define
define|#
directive|define
name|SH4_NOFPU_NEXT
value|arch_info_struct + 11
end_define

begin_define
define|#
directive|define
name|SH4_NOMMU_NOFPU_NEXT
value|arch_info_struct + 12
end_define

begin_define
define|#
directive|define
name|SH4A_NOFPU_NEXT
value|arch_info_struct + 13
end_define

begin_define
define|#
directive|define
name|SH2A_NEXT
value|arch_info_struct + 14
end_define

begin_define
define|#
directive|define
name|SH2A_NOFPU_NEXT
value|arch_info_struct + 15
end_define

begin_define
define|#
directive|define
name|SH2A_NOFPU_OR_SH4_NOMMU_NOFPU_NEXT
value|arch_info_struct + 16
end_define

begin_define
define|#
directive|define
name|SH2A_NOFPU_OR_SH3_NOMMU_NEXT
value|arch_info_struct + 17
end_define

begin_define
define|#
directive|define
name|SH2A_OR_SH4_NEXT
value|arch_info_struct + 18
end_define

begin_define
define|#
directive|define
name|SH2A_OR_SH3E_NEXT
value|arch_info_struct + 19
end_define

begin_define
define|#
directive|define
name|SH64_NEXT
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
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh2
block|,
literal|"sh"
block|,
comment|/* Architecture name.  */
literal|"sh2"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH2_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh2e
block|,
literal|"sh"
block|,
comment|/* Architecture name.  */
literal|"sh2e"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH2E_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh_dsp
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh-dsp"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH_DSP_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh3
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh3"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH3_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh3_nommu
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh3-nommu"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH3_NOMMU_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh3_dsp
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh3-dsp"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH3_DSP_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh3e
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh3e"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH3E_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh4
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh4"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH4_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh4a
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh4a"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH4A_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh4al_dsp
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh4al-dsp"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH4AL_DSP_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh4_nofpu
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh4-nofpu"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH4_NOFPU_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh4_nommu_nofpu
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh4-nommu-nofpu"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH4_NOMMU_NOFPU_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh4a_nofpu
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh4a-nofpu"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH4A_NOFPU_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh2a
block|,
literal|"sh"
block|,
comment|/* Architecture name.  */
literal|"sh2a"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH2A_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh2a_nofpu
block|,
literal|"sh"
block|,
comment|/* Architecture name.  */
literal|"sh2a-nofpu"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH2A_NOFPU_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh2a_nofpu_or_sh4_nommu_nofpu
block|,
literal|"sh"
block|,
comment|/* Architecture name.  */
literal|"sh2a-nofpu-or-sh4-nommu-nofpu"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH2A_NOFPU_OR_SH4_NOMMU_NOFPU_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh2a_nofpu_or_sh3_nommu
block|,
literal|"sh"
block|,
comment|/* Architecture name. .  */
literal|"sh2a-nofpu-or-sh3-nommu"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH2A_NOFPU_OR_SH3_NOMMU_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh2a_or_sh4
block|,
literal|"sh"
block|,
comment|/* Architecture name.  */
literal|"sh2a-or-sh4"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH2A_OR_SH4_NEXT
block|}
block|,
block|{
literal|32
block|,
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh2a_or_sh3e
block|,
literal|"sh"
block|,
comment|/* Architecture name.  */
literal|"sh2a-or-sh3e"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH2A_OR_SH3E_NEXT
block|}
block|,
block|{
literal|64
block|,
comment|/* 64 bits in a word.  */
literal|64
block|,
comment|/* 64 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh5
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh5"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|FALSE
block|,
comment|/* Not the default.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH64_NEXT
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
comment|/* 32 bits in a word.  */
literal|32
block|,
comment|/* 32 bits in an address.  */
literal|8
block|,
comment|/* 8 bits in a byte.  */
name|bfd_arch_sh
block|,
name|bfd_mach_sh
block|,
literal|"sh"
block|,
comment|/* Architecture name.   */
literal|"sh"
block|,
comment|/* Machine name.  */
literal|1
block|,
name|TRUE
block|,
comment|/* The default machine.  */
name|bfd_default_compatible
block|,
name|bfd_default_scan
block|,
name|SH_NEXT
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This table defines the mappings from the BFD internal numbering    system to the opcodes internal flags system.    It is used by the functions defined below.    The prototypes for these SH specific functions are found in    sh-opc.h .  */
end_comment

begin_struct
specifier|static
struct|struct
block|{
name|unsigned
name|long
name|bfd_mach
decl_stmt|,
name|arch
decl_stmt|,
name|arch_up
decl_stmt|;
block|}
name|bfd_to_arch_table
index|[]
init|=
block|{
block|{
name|bfd_mach_sh
block|,
name|arch_sh1
block|,
name|arch_sh_up
block|}
block|,
block|{
name|bfd_mach_sh2
block|,
name|arch_sh2
block|,
name|arch_sh2_up
block|}
block|,
block|{
name|bfd_mach_sh2e
block|,
name|arch_sh2e
block|,
name|arch_sh2e_up
block|}
block|,
block|{
name|bfd_mach_sh_dsp
block|,
name|arch_sh_dsp
block|,
name|arch_sh_dsp_up
block|}
block|,
block|{
name|bfd_mach_sh2a
block|,
name|arch_sh2a
block|,
name|arch_sh2a_up
block|}
block|,
block|{
name|bfd_mach_sh2a_nofpu
block|,
name|arch_sh2a_nofpu
block|,
name|arch_sh2a_nofpu_up
block|}
block|,
block|{
name|bfd_mach_sh2a_nofpu_or_sh4_nommu_nofpu
block|,
name|arch_sh2a_nofpu_or_sh4_nommu_nofpu
block|,
name|arch_sh2a_nofpu_or_sh4_nommu_nofpu_up
block|}
block|,
block|{
name|bfd_mach_sh2a_nofpu_or_sh3_nommu
block|,
name|arch_sh2a_nofpu_or_sh3_nommu
block|,
name|arch_sh2a_nofpu_or_sh3_nommu_up
block|}
block|,
block|{
name|bfd_mach_sh2a_or_sh4
block|,
name|arch_sh2a_or_sh4
block|,
name|arch_sh2a_or_sh4_up
block|}
block|,
block|{
name|bfd_mach_sh2a_or_sh3e
block|,
name|arch_sh2a_or_sh3e
block|,
name|arch_sh2a_or_sh3e_up
block|}
block|,
block|{
name|bfd_mach_sh3
block|,
name|arch_sh3
block|,
name|arch_sh3_up
block|}
block|,
block|{
name|bfd_mach_sh3_nommu
block|,
name|arch_sh3_nommu
block|,
name|arch_sh3_nommu_up
block|}
block|,
block|{
name|bfd_mach_sh3_dsp
block|,
name|arch_sh3_dsp
block|,
name|arch_sh3_dsp_up
block|}
block|,
block|{
name|bfd_mach_sh3e
block|,
name|arch_sh3e
block|,
name|arch_sh3e_up
block|}
block|,
block|{
name|bfd_mach_sh4
block|,
name|arch_sh4
block|,
name|arch_sh4_up
block|}
block|,
block|{
name|bfd_mach_sh4a
block|,
name|arch_sh4a
block|,
name|arch_sh4a_up
block|}
block|,
block|{
name|bfd_mach_sh4al_dsp
block|,
name|arch_sh4al_dsp
block|,
name|arch_sh4al_dsp_up
block|}
block|,
block|{
name|bfd_mach_sh4_nofpu
block|,
name|arch_sh4_nofpu
block|,
name|arch_sh4_nofpu_up
block|}
block|,
block|{
name|bfd_mach_sh4_nommu_nofpu
block|,
name|arch_sh4_nommu_nofpu
block|,
name|arch_sh4_nommu_nofpu_up
block|}
block|,
block|{
name|bfd_mach_sh4a_nofpu
block|,
name|arch_sh4a_nofpu
block|,
name|arch_sh4a_nofpu_up
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
comment|/* Terminator.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Convert a BFD mach number into the right opcodes arch flags    using the table above.  */
end_comment

begin_function
name|unsigned
name|int
name|sh_get_arch_from_bfd_mach
parameter_list|(
name|unsigned
name|long
name|mach
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|bfd_to_arch_table
index|[
name|i
index|]
operator|.
name|bfd_mach
operator|!=
literal|0
condition|)
if|if
condition|(
name|bfd_to_arch_table
index|[
name|i
index|]
operator|.
name|bfd_mach
operator|==
name|mach
condition|)
return|return
name|bfd_to_arch_table
index|[
name|i
index|]
operator|.
name|arch
return|;
else|else
name|i
operator|++
expr_stmt|;
comment|/* Machine not found.   */
name|BFD_FAIL
argument_list|()
expr_stmt|;
return|return
name|SH_ARCH_UNKNOWN_ARCH
return|;
block|}
end_function

begin_comment
comment|/* Convert a BFD mach number into a set of opcodes arch flags    describing all the compatible architectures (i.e. arch_up)    using the table above.  */
end_comment

begin_function
name|unsigned
name|int
name|sh_get_arch_up_from_bfd_mach
parameter_list|(
name|unsigned
name|long
name|mach
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|bfd_to_arch_table
index|[
name|i
index|]
operator|.
name|bfd_mach
operator|!=
literal|0
condition|)
if|if
condition|(
name|bfd_to_arch_table
index|[
name|i
index|]
operator|.
name|bfd_mach
operator|==
name|mach
condition|)
return|return
name|bfd_to_arch_table
index|[
name|i
index|]
operator|.
name|arch_up
return|;
else|else
name|i
operator|++
expr_stmt|;
comment|/* Machine not found.  */
name|BFD_FAIL
argument_list|()
expr_stmt|;
return|return
name|SH_ARCH_UNKNOWN_ARCH
return|;
block|}
end_function

begin_comment
comment|/* Convert an arbitary arch_set - not necessarily corresponding    directly to anything in the table above - to the most generic    architecture which supports all the required features, and    return the corresponding BFD mach.  */
end_comment

begin_function
name|unsigned
name|long
name|sh_get_bfd_mach_from_arch_set
parameter_list|(
name|unsigned
name|int
name|arch_set
parameter_list|)
block|{
name|unsigned
name|long
name|result
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|best
init|=
operator|~
name|arch_set
decl_stmt|;
name|unsigned
name|int
name|co_mask
init|=
operator|~
literal|0
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|/* If arch_set permits variants with no coprocessor then do not allow      the other irrelevant co-processor bits to influence the choice:        e.g. if dsp is disallowed by arch_set, then the algorithm would        prefer fpu variants over nofpu variants because they also disallow        dsp - even though the nofpu would be the most correct choice.      This assumes that EVERY fpu/dsp variant has a no-coprocessor      counter-part, or their non-fpu/dsp instructions do not have the      no co-processor bit set.  */
if|if
condition|(
name|arch_set
operator|&
name|arch_sh_no_co
condition|)
name|co_mask
operator|=
operator|~
operator|(
name|arch_sh_sp_fpu
operator||
name|arch_sh_dp_fpu
operator||
name|arch_sh_has_dsp
operator|)
expr_stmt|;
while|while
condition|(
name|bfd_to_arch_table
index|[
name|i
index|]
operator|.
name|bfd_mach
operator|!=
literal|0
condition|)
block|{
name|unsigned
name|int
name|try
init|=
name|bfd_to_arch_table
index|[
name|i
index|]
operator|.
name|arch_up
operator|&
name|co_mask
decl_stmt|;
comment|/* Conceptually: Find the architecture with the least number 	 of extra features or, if they have the same number, then 	 the greatest number of required features.  Disregard          architectures where the required features alone do 	 not describe a valid architecture.  */
if|if
condition|(
operator|(
operator|(
name|try
operator|&
operator|~
name|arch_set
operator|)
operator|<
operator|(
name|best
operator|&
operator|~
name|arch_set
operator|)
operator|||
operator|(
operator|(
name|try
operator|&
operator|~
name|arch_set
operator|)
operator|==
operator|(
name|best
operator|&
operator|~
name|arch_set
operator|)
operator|&&
operator|(
operator|~
name|try
operator|&
name|arch_set
operator|)
operator|<
operator|(
operator|~
name|best
operator|&
name|arch_set
operator|)
operator|)
operator|)
operator|&&
name|SH_MERGE_ARCH_SET_VALID
argument_list|(
name|try
argument_list|,
name|arch_set
argument_list|)
condition|)
block|{
name|result
operator|=
name|bfd_to_arch_table
index|[
name|i
index|]
operator|.
name|bfd_mach
expr_stmt|;
name|best
operator|=
name|try
expr_stmt|;
block|}
name|i
operator|++
expr_stmt|;
block|}
comment|/* This might happen if a new variant is added to sh-opc.h      but no corresponding entry is added to the table above.  */
name|BFD_ASSERT
argument_list|(
name|result
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|/* Merge the architecture type of two BFD files, such that the    resultant architecture supports all the features required    by the two input BFDs.    If the input BFDs are multually incompatible - i.e. one uses    DSP while the other uses FPU - or there is no known architecture    that fits the requirements then an error is emitted.  */
end_comment

begin_function
name|bfd_boolean
name|sh_merge_bfd_arch
parameter_list|(
name|bfd
modifier|*
name|ibfd
parameter_list|,
name|bfd
modifier|*
name|obfd
parameter_list|)
block|{
name|unsigned
name|int
name|old_arch
decl_stmt|,
name|new_arch
decl_stmt|,
name|merged_arch
decl_stmt|;
if|if
condition|(
operator|!
name|_bfd_generic_verify_endian_match
argument_list|(
name|ibfd
argument_list|,
name|obfd
argument_list|)
condition|)
return|return
name|FALSE
return|;
name|old_arch
operator|=
name|sh_get_arch_up_from_bfd_mach
argument_list|(
name|bfd_get_mach
argument_list|(
name|obfd
argument_list|)
argument_list|)
expr_stmt|;
name|new_arch
operator|=
name|sh_get_arch_up_from_bfd_mach
argument_list|(
name|bfd_get_mach
argument_list|(
name|ibfd
argument_list|)
argument_list|)
expr_stmt|;
name|merged_arch
operator|=
name|SH_MERGE_ARCH_SET
argument_list|(
name|old_arch
argument_list|,
name|new_arch
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|SH_VALID_CO_ARCH_SET
argument_list|(
name|merged_arch
argument_list|)
condition|)
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%B: uses %s instructions while previous modules use %s instructions"
argument_list|,
name|ibfd
argument_list|,
name|SH_ARCH_SET_HAS_DSP
argument_list|(
name|new_arch
argument_list|)
condition|?
literal|"dsp"
else|:
literal|"floating point"
argument_list|,
name|SH_ARCH_SET_HAS_DSP
argument_list|(
name|new_arch
argument_list|)
condition|?
literal|"floating point"
else|:
literal|"dsp"
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
elseif|else
if|if
condition|(
operator|!
name|SH_VALID_ARCH_SET
argument_list|(
name|merged_arch
argument_list|)
condition|)
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"internal error: merge of architecture '%s' with architecture '%s' produced unknown architecture\n"
argument_list|,
name|bfd_printable_name
argument_list|(
name|obfd
argument_list|)
argument_list|,
name|bfd_printable_name
argument_list|(
name|ibfd
argument_list|)
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
name|bfd_default_set_arch_mach
argument_list|(
name|obfd
argument_list|,
name|bfd_arch_sh
argument_list|,
name|sh_get_bfd_mach_from_arch_set
argument_list|(
name|merged_arch
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

end_unit

