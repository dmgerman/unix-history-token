begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD support for the ARC processor    Copyright 1994, 1995, 1997 Free Software Foundation, Inc.    Contributed by Doug Evans (dje@cygnus.com).  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|ARC
parameter_list|(
name|mach
parameter_list|,
name|print_name
parameter_list|,
name|default_p
parameter_list|,
name|next
parameter_list|)
define|\
value|{					\     32,
comment|/* 32 bits in a word */
value|\     32,
comment|/* 32 bits in an address */
value|\     8,
comment|/* 8 bits in a byte */
value|\     bfd_arch_arc,			\     mach,				\     "arc",				\     print_name,				\     4,
comment|/* section alignment power */
value|\     default_p,				\     bfd_default_compatible, 		\     bfd_default_scan,			\     next,				\   }
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* ??? Not currently needed, but keep in for future reference.  */
end_comment

begin_endif
unit|static const bfd_arch_info_type arch_info_struct[] = {   ARC (bfd_mach_arc_foo, "arc-foo", false,&arch_info_struct[1]),   ARC (bfd_mach_arc_bar, "arc-bar", false, 0), };
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_arc_arch
init|=
name|ARC
argument_list|(
name|bfd_mach_arc_base
argument_list|,
literal|"arc-base"
argument_list|,
name|true
argument_list|,
literal|0
comment|/*&arch_info_struct[0]*/
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Utility routines.  */
end_comment

begin_comment
comment|/* Given cpu type NAME, return its bfd_mach_arc_xxx value.    Returns -1 if not found.  */
end_comment

begin_function
name|int
name|arc_get_mach
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
specifier|const
name|bfd_arch_info_type
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
operator|&
name|bfd_arc_arch
init|;
name|p
operator|!=
name|NULL
condition|;
name|p
operator|=
name|p
operator|->
name|next
control|)
block|{
comment|/* +4: skip over "arc-" */
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
name|p
operator|->
name|printable_name
operator|+
literal|4
argument_list|)
operator|==
literal|0
condition|)
return|return
name|p
operator|->
name|mach
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function

end_unit

