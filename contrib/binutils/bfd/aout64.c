begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for 64-bit a.out files.    Copyright 1990, 1991, 1992, 1994 Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|ARCH_SIZE
value|64
end_define

begin_comment
comment|/* aoutx.h requires definitions for BMAGIC and QMAGIC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BMAGIC
end_ifndef

begin_define
define|#
directive|define
name|BMAGIC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|QMAGIC
end_ifndef

begin_define
define|#
directive|define
name|QMAGIC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"aoutx.h"
end_include

end_unit

