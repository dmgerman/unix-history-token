begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for DEC Alpha, osf[23].    Copyright (C) 1997 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* In OSF 2 or 3, linking with -lprof1 doesn't require -lpdf.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-lprof1} %{pg:-lprof1} %{a:-lprof2} -lc"
end_define

begin_comment
comment|/* As of OSF 3.2, as still can't subtract adjacent labels.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_AS_CAN_SUBTRACT_LABELS
end_undef

begin_define
define|#
directive|define
name|TARGET_AS_CAN_SUBTRACT_LABELS
value|0
end_define

begin_comment
comment|/* The frame unwind data requires the ability to subtract labels.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF2_UNWIND_INFO
end_undef

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

end_unit

