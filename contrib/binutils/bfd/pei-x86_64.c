begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for Intel 386 PE IMAGE COFF files.    Copyright 2006, 2007 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.        Written by Kai Tietz, OneVision Software GmbH&CoKg.  */
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

begin_define
define|#
directive|define
name|TARGET_SYM
value|x86_64pei_vec
end_define

begin_define
define|#
directive|define
name|TARGET_NAME
value|"pei-x86-64"
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
name|COFF_WITH_pex64
end_define

begin_define
define|#
directive|define
name|PCRELOFFSET
value|TRUE
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
name|COFF_SUPPORT_GNU_LINKONCE
end_define

begin_define
define|#
directive|define
name|COFF_LONG_FILENAMES
end_define

begin_define
define|#
directive|define
name|COFF_SECTION_ALIGNMENT_ENTRIES
define|\
value|{ COFF_SECTION_NAME_EXACT_MATCH (".bss"), \   COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 4 }, \ { COFF_SECTION_NAME_EXACT_MATCH (".data"), \   COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 4 }, \ { COFF_SECTION_NAME_EXACT_MATCH (".rdata"), \   COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 4 }, \ { COFF_SECTION_NAME_EXACT_MATCH (".text"), \   COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 4 }, \ { COFF_SECTION_NAME_PARTIAL_MATCH (".idata"), \   COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 2 }, \ { COFF_SECTION_NAME_EXACT_MATCH (".pdata"), \   COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 2 }, \ { COFF_SECTION_NAME_PARTIAL_MATCH (".debug"), \   COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 0 }, \ { COFF_SECTION_NAME_PARTIAL_MATCH (".gnu.linkonce.wi."), \   COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 0 }
end_define

begin_include
include|#
directive|include
file|"coff-x86_64.c"
end_include

end_unit

