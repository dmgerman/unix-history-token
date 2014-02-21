begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for ARM WINCE PE files.    Copyright 2006 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_UNDERSCORE
value|0
end_define

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|arm_wince_pe_little_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"pe-arm-wince-little"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|arm_wince_pe_big_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"pe-arm-wince-big"
end_define

begin_define
define|#
directive|define
name|bfd_arm_allocate_interworking_sections
define|\
value|bfd_arm_wince_pe_allocate_interworking_sections
end_define

begin_define
define|#
directive|define
name|bfd_arm_get_bfd_for_interworking
define|\
value|bfd_arm_wince_pe_get_bfd_for_interworking
end_define

begin_define
define|#
directive|define
name|bfd_arm_process_before_allocation
define|\
value|bfd_arm_wince_pe_process_before_allocation
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_include
include|#
directive|include
file|"pe-arm.c"
end_include

end_unit

