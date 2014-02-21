begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Modifications of internal.h and m68k.h needed by A/UX     Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.        Suggested by Ian Lance Taylor<ian@cygnus.com> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GNU_COFF_AUX_H
end_ifndef

begin_define
define|#
directive|define
name|GNU_COFF_AUX_H
value|1
end_define

begin_include
include|#
directive|include
file|"coff/internal.h"
end_include

begin_include
include|#
directive|include
file|"coff/m68k.h"
end_include

begin_comment
comment|/* Section contains 64-byte padded pathnames of shared libraries */
end_comment

begin_undef
undef|#
directive|undef
name|STYP_LIB
end_undef

begin_define
define|#
directive|define
name|STYP_LIB
value|0x200
end_define

begin_comment
comment|/* Section contains shared library initialization code */
end_comment

begin_undef
undef|#
directive|undef
name|STYP_INIT
end_undef

begin_define
define|#
directive|define
name|STYP_INIT
value|0x400
end_define

begin_comment
comment|/* Section contains .ident information */
end_comment

begin_undef
undef|#
directive|undef
name|STYP_IDENT
end_undef

begin_define
define|#
directive|define
name|STYP_IDENT
value|0x800
end_define

begin_comment
comment|/* Section types used by bfd and gas not defined (directly) by A/UX */
end_comment

begin_undef
undef|#
directive|undef
name|STYP_OVER
end_undef

begin_define
define|#
directive|define
name|STYP_OVER
value|0
end_define

begin_undef
undef|#
directive|undef
name|STYP_INFO
end_undef

begin_define
define|#
directive|define
name|STYP_INFO
value|STYP_IDENT
end_define

begin_comment
comment|/* Traditional name of the section tagged with STYP_LIB */
end_comment

begin_define
define|#
directive|define
name|_LIB
value|".lib"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNU_COFF_AUX_H */
end_comment

end_unit

