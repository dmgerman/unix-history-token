begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* te-ppcnw.h -- Power PC running Netware environment declarations.    Copyright 1994, 1995, 2000 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_comment
comment|/* Added these, because if we don't know what we're targetting we may    need an assembler version of libgcc, and that will use local    labels.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_DOLLAR
value|1
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_comment
comment|/* these define interfaces */
end_comment

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_comment
comment|/* gcc uses escape sequences for ppc/netware.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_STRING_ESCAPES
end_undef

end_unit

