begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro defintions for IBM AIX PS/2 (i386).    Copyright 1986, 1987, 1989, 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Changes for IBM AIX PS/2 by Minh Tran-Le (tranle@intellicorp.com).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386AIX_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386AIX_H
value|1
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_include
include|#
directive|include
file|<sys/reg.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|I386
end_ifndef

begin_define
define|#
directive|define
name|I386
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|I386_AIX_TARGET
end_ifndef

begin_define
define|#
directive|define
name|I386_AIX_TARGET
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero if register N requires conversion    from raw format to virtual format.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERTIBLE
end_undef

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N< FP0_REGNUM) ? 0 : 1)
end_define

begin_comment
comment|/* Convert data from raw format for register REGNUM in buffer FROM    to virtual format with type TYPE in buffer TO.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERT_TO_VIRTUAL
end_undef

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_VIRTUAL
parameter_list|(
name|REGNUM
parameter_list|,
name|TYPE
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|{ \   double val; \   i387_to_double ((FROM), (char *)&val); \   store_floating ((TO), TYPE_LENGTH (TYPE), val); \ }
end_define

begin_decl_stmt
specifier|extern
name|void
name|i387_to_double
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert data from virtual format with type TYPE in buffer FROM    to raw format for register REGNUM in buffer TO.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERT_TO_RAW
end_undef

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_RAW
parameter_list|(
name|TYPE
parameter_list|,
name|REGNUM
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|{ \   double val = extract_floating ((FROM), TYPE_LENGTH (TYPE)); \   double_to_i387((char *)&val, (TO)); \ }
end_define

begin_decl_stmt
specifier|extern
name|void
name|double_to_i387
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_I386AIX_H */
end_comment

end_unit

