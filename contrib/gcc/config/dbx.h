begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Prefer DBX (stabs) debugging information.    Copyright (C) 1996 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file causes gcc to prefer using DBX (stabs) debugging    information.  The configure script will add a #include of this file    to tm.h when --with-stabs is used for certain targets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DBX_DEBUGGING_INFO
end_ifndef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

end_unit

