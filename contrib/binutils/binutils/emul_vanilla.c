begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Binutils emulation layer.    Copyright (C) 2002 Free Software Foundation, Inc.    Written by Tom Rix, Red Hat Inc.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"binemul.h"
end_include

begin_decl_stmt
name|struct
name|bin_emulation_xfer_struct
name|bin_vanilla_emulation
init|=
block|{
name|ar_emul_default_usage
block|,
name|ar_emul_default_append
block|,
name|ar_emul_default_replace
block|,
name|ar_emul_default_parse_arg
block|, }
decl_stmt|;
end_decl_stmt

end_unit

