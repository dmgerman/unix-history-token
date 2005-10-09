begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* implic.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       implic.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_IMPLIC_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_IMPLIC_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_comment
comment|/* Typedefs. */
end_comment

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_include
include|#
directive|include
file|"symbol.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|bool
name|ffeimplic_establish_initial
parameter_list|(
name|char
name|c
parameter_list|,
name|ffeinfoBasictype
name|basic_type
parameter_list|,
name|ffeinfoKindtype
name|kind_type
parameter_list|,
name|ffetargetCharacterSize
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffeimplic_establish_symbol
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeimplic_init_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeimplic_none
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeinfoBasictype
name|ffeimplic_peek_symbol_type
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeimplic_terminate_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffeimplic_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeimplic_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeimplic_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeimplic_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeimplic_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeimplic_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeimplic_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeimplic_terminate_4
parameter_list|()
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_IMPLIC_H */
end_comment

end_unit

