begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for Intel 386 PECOFF files.    Copyright 1995 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
name|E_FILENMLEN
value|18
end_define

begin_define
define|#
directive|define
name|PPC
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_powerpcle_pe_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"pe-powerpcle"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_powerpc_pe_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"pe-powerpc"
end_define

begin_define
define|#
directive|define
name|COFF_OBJ_WITH_PE
end_define

begin_define
define|#
directive|define
name|COFF_WITH_PE
end_define

begin_comment
comment|/* FIXME: verify PCRELOFFSET is always false */
end_comment

begin_include
include|#
directive|include
file|"coff-ppc.c"
end_include

end_unit

