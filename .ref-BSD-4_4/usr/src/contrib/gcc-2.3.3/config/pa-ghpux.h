begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for HP-UX using GNU as.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"pa.h"
end_include

begin_comment
comment|/* Make GCC agree with types.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* Like the default, except no -lg.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}"
end_define

begin_comment
comment|/* Control how gcc finds libgcc.a and how it passes -L options.  */
end_comment

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL
end_define

begin_define
define|#
directive|define
name|RELATIVE_PREFIX_NOT_LINKDIR
end_define

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dhppa -Dhp9000s800 -D__hp9000s800 -Dhp9k8 -DPWB -Dhpux -Dunix -D_HPUX_SOURCE"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-u main -a archive"
end_define

end_unit

