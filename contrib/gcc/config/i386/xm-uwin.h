begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for hosting on Windows32.    using GNU tools and the Windows32 API Library.    Copyright (C) 1999 Free Software Foundation, Inc.    Contributed by Mumit Khan<khan@xraylith.wisc.edu>.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ONLY_INT_FIELD
end_ifndef

begin_define
define|#
directive|define
name|ONLY_INT_FIELDS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_PROTOTYPES
end_ifndef

begin_define
define|#
directive|define
name|USE_PROTOTYPES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* U/WIN system calls only support '/' */
end_comment

begin_undef
undef|#
directive|undef
name|DIR_SEPARATOR
end_undef

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|'/'
end_define

begin_undef
undef|#
directive|undef
name|EXECUTABLE_SUFFIX
end_undef

begin_define
define|#
directive|define
name|EXECUTABLE_SUFFIX
value|".exe"
end_define

begin_undef
undef|#
directive|undef
name|PATH_SEPARATOR
end_undef

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|':'
end_define

end_unit

