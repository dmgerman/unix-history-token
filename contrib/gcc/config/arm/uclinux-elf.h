begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for ARM running ucLinux using ELF    Copyright (C) 1999, 2001 Free Software Foundation, Inc.    Contributed by Philip Blundell<pb@nexus.co.uk>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* We don't want a PLT.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_PLT_RELOC
end_undef

begin_define
define|#
directive|define
name|NEED_PLT_RELOC
value|0
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM/ELF ucLinux)", stderr);
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(ARM_FLAG_APCS_32 | ARM_FLAG_MMU_TRAPS | ARM_FLAG_SINGLE_PIC_BASE)
end_define

end_unit

