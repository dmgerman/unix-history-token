begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler    for an Intel i386 or later processor running OS/2 2.x.    Copyright (C) 1993, 1994, 1995 Free Software Foundation, Inc.    Contributed by Samuel Figueroa (figueroa@cs.nyu.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_TARGET_MACHINE
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_TARGET_MACHINE
value|"i386-os2"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"/st:1048576/pm:vio/noi/a:16/e/bas:65536/nol"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"libgcc libc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STARTFILE_SPEC
end_ifndef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"libcrt.lib"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MD_EXEC_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"\\gcc\\bin\\"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_STARTFILE_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|"\\gcc\\lib\\"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL_INCLUDE_DIR
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_INCLUDE_DIR
value|"\\gcc\\include"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_include
include|#
directive|include
file|"i386/gstabs.h"
end_include

begin_define
define|#
directive|define
name|USE_COLLECT
end_define

begin_define
define|#
directive|define
name|BIGGEST_FIELD_ALIGNMENT
define|\
value|(maximum_field_alignment ? maximum_field_alignment : 32)
end_define

begin_decl_stmt
specifier|extern
name|int
name|maximum_field_alignment
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|PCC_BITFIELD_TYPE_MATTERS
end_undef

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|(maximum_field_alignment == 0)
end_define

begin_comment
comment|/* Define this macro if it is advisable to hold scalars in registers    in a wider mode than that declared by the program.  In such cases,    the value is constrained to be within the bounds of the declared    type, but kept valid in the wider mode.  The signedness of the    extension may differ from that of the type.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_MODE
parameter_list|(
name|MODE
parameter_list|,
name|UNSIGNEDP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|if (GET_MODE_CLASS (MODE) == MODE_INT         \&& GET_MODE_SIZE (MODE)< UNITS_PER_WORD) \       (MODE) = SImode;
end_define

begin_comment
comment|/* Define this if function arguments should also be promoted using the above    procedure.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_FUNCTION_ARGS
end_define

begin_comment
comment|/* Likewise, if the function return value is promoted.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_FUNCTION_RETURN
end_define

end_unit

