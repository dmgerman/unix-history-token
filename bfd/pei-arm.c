begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for arm PE IMAGE COFF files.    Copyright 1995, 1996, 1999, 2002 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|armpei_little_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"pei-arm-little"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|armpei_big_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"pei-arm-big"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|PCRELOFFSET
value|TRUE
end_define

begin_define
define|#
directive|define
name|COFF_LONG_SECTION_NAMES
end_define

begin_include
include|#
directive|include
file|"coff-arm.c"
end_include

end_unit

