begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running LynxOS, using Lynx's old as and ld.    Copyright (C) 1993, 1995 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<i386/gstabs.h>
end_include

begin_include
include|#
directive|include
file|<lynx-ng.h>
end_include

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -DI386 -DLynx -DIBITS32 \   -Asystem=unix -Asystem=lynx"
end_define

begin_comment
comment|/* Provide required defaults for linker switches.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-P1000 %{msystem-v:-V} %{mcoff:-k}"
end_define

begin_comment
comment|/* Apparently LynxOS clobbers ebx when you call into the OS.  */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_USED_REGISTERS
end_undef

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
comment|/*ax,dx,cx,bx,si,di,bp,sp,st,st1,st2,st3,st4,st5,st6,st7,arg*/
define|\
value|{  1, 1, 1, 1, 0, 0, 0, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1 }
end_define

end_unit

