begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for SunOS 4.x with gas    Copyright (C) 1997 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* gas supports unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|UNALIGNED_DOUBLE_INT_ASM_OP
value|".uaxword"
end_define

begin_define
define|#
directive|define
name|UNALIGNED_INT_ASM_OP
value|".uaword"
end_define

begin_define
define|#
directive|define
name|UNALIGNED_SHORT_ASM_OP
value|".uahalf"
end_define

begin_comment
comment|/* defaults.h will define DWARF2_UNWIND_INFO for us.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF2_UNWIND_INFO
end_undef

end_unit

