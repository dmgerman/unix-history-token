begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for HP/Intel IA-64 EFI application files.    Copyright 1999, 2000, 2001 Free Software Foundation, Inc.    Contributed by David Mosberger<davidm@hpl.hp.com>  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_define
define|#
directive|define
name|TARGET_SYM
value|bfd_efi_app_ia64_vec
end_define

begin_define
define|#
directive|define
name|TARGET_NAME
value|"efi-app-ia64"
end_define

begin_define
define|#
directive|define
name|COFF_IMAGE_WITH_PE
end_define

begin_define
define|#
directive|define
name|COFF_WITH_PE
end_define

begin_define
define|#
directive|define
name|COFF_WITH_pep
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
name|TARGET_UNDERSCORE
value|'_'
end_define

begin_define
define|#
directive|define
name|COFF_LONG_SECTION_NAMES
end_define

begin_define
define|#
directive|define
name|PEI_TARGET_SUBSYSTEM
value|IMAGE_SUBSYSTEM_EFI_APPLICATION
end_define

begin_define
define|#
directive|define
name|PEI_FORCE_MINIMUM_ALIGNMENT
end_define

begin_include
include|#
directive|include
file|"coff-ia64.c"
end_include

end_unit

