begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for ARM PECOFF files.    Copyright 1995, 1996, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_LITTLE_SYM
end_ifndef

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|armpe_little_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"pe-arm-little"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|armpe_big_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"pe-arm-big"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|COFF_WITH_PE
end_define

begin_define
define|#
directive|define
name|PCRELOFFSET
value|true
end_define

begin_define
define|#
directive|define
name|COFF_LONG_SECTION_NAMES
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_arm_allocate_interworking_sections
end_ifndef

begin_define
define|#
directive|define
name|bfd_arm_allocate_interworking_sections
define|\
value|bfd_arm_pe_allocate_interworking_sections
end_define

begin_define
define|#
directive|define
name|bfd_arm_get_bfd_for_interworking
define|\
value|bfd_arm_pe_get_bfd_for_interworking
end_define

begin_define
define|#
directive|define
name|bfd_arm_process_before_allocation
define|\
value|bfd_arm_pe_process_before_allocation
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_WINCE
end_ifdef

begin_define
define|#
directive|define
name|TARGET_UNDERSCORE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"coff-arm.c"
end_include

end_unit

