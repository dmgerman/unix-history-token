begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* equiv.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995, 1996 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       equiv.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H_f_equiv
end_ifndef

begin_define
define|#
directive|define
name|_H_f_equiv
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ffeequiv_
modifier|*
name|ffeequiv
typedef|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"bld.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"storag.h"
end_include

begin_include
include|#
directive|include
file|"symbol.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffeequiv_
block|{
name|ffeequiv
name|next
decl_stmt|;
name|ffeequiv
name|previous
decl_stmt|;
name|ffesymbol
name|common
decl_stmt|;
comment|/* Common area for this equiv, if any. */
name|ffebld
name|list
decl_stmt|;
comment|/* List of lists of equiv exprs. */
name|bool
name|is_save
decl_stmt|;
comment|/* Any SAVEd members? */
name|bool
name|is_init
decl_stmt|;
comment|/* Any initialized members? */
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|ffeequiv_add
parameter_list|(
name|ffeequiv
name|eq
parameter_list|,
name|ffebld
name|list
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetFFE
end_if

begin_function_decl
name|void
name|ffeequiv_dump
parameter_list|(
name|ffeequiv
name|eq
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffeequiv_exec_transition
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeequiv_init_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeequiv_kill
parameter_list|(
name|ffeequiv
name|victim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffeequiv_layout_cblock
parameter_list|(
name|ffestorag
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeequiv
name|ffeequiv_merge
parameter_list|(
name|ffeequiv
name|eq1
parameter_list|,
name|ffeequiv
name|eq2
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeequiv
name|ffeequiv_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesymbol
name|ffeequiv_symbol
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeequiv_update_init
parameter_list|(
name|ffeequiv
name|eq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeequiv_update_save
parameter_list|(
name|ffeequiv
name|eq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffeequiv_common
parameter_list|(
name|e
parameter_list|)
value|((e)->common)
end_define

begin_define
define|#
directive|define
name|ffeequiv_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeequiv_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeequiv_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeequiv_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeequiv_is_init
parameter_list|(
name|e
parameter_list|)
value|((e)->is_init)
end_define

begin_define
define|#
directive|define
name|ffeequiv_is_save
parameter_list|(
name|e
parameter_list|)
value|((e)->is_save)
end_define

begin_define
define|#
directive|define
name|ffeequiv_list
parameter_list|(
name|e
parameter_list|)
value|((e)->list)
end_define

begin_define
define|#
directive|define
name|ffeequiv_next
parameter_list|(
name|e
parameter_list|)
value|((e)->next)
end_define

begin_define
define|#
directive|define
name|ffeequiv_previous
parameter_list|(
name|e
parameter_list|)
value|((e)->previous)
end_define

begin_define
define|#
directive|define
name|ffeequiv_set_common
parameter_list|(
name|e
parameter_list|,
name|c
parameter_list|)
value|((e)->common = (c))
end_define

begin_define
define|#
directive|define
name|ffeequiv_set_init
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|((e)->init = (i))
end_define

begin_define
define|#
directive|define
name|ffeequiv_set_is_init
parameter_list|(
name|e
parameter_list|,
name|in
parameter_list|)
value|((e)->is_init = (in))
end_define

begin_define
define|#
directive|define
name|ffeequiv_set_is_save
parameter_list|(
name|e
parameter_list|,
name|sa
parameter_list|)
value|((e)->is_save = (sa))
end_define

begin_define
define|#
directive|define
name|ffeequiv_set_list
parameter_list|(
name|e
parameter_list|,
name|l
parameter_list|)
value|((e)->list = (l))
end_define

begin_define
define|#
directive|define
name|ffeequiv_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeequiv_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeequiv_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeequiv_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeequiv_terminate_4
parameter_list|()
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

