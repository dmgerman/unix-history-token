begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sta.h -- Private #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       sta.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_STA_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_STA_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFESTA_pooldispDISCARD
block|,
comment|/* Default state. */
name|FFESTA_pooldispPRESERVE
block|,
comment|/* Preserve through end of program unit. */
name|FFESTA_pooldisp
block|}
name|ffestaPooldisp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FFESTA_tokensMAX
value|10
end_define

begin_comment
comment|/* Max # tokens in fixed positions. */
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
file|"bad.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_include
include|#
directive|include
file|"str.h"
end_include

begin_include
include|#
directive|include
file|"symbol.h"
end_include

begin_typedef
typedef|typedef
name|mallocPool
name|ffestaPool
typedef|;
end_typedef

begin_comment
comment|/* No need for use count yet. */
end_comment

begin_comment
comment|/* Structure definitions. */
end_comment

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|ffelexToken
name|ffesta_tokens
index|[
name|FFESTA_tokensMAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffestrFirst
name|ffesta_first_kw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffestrSecond
name|ffesta_second_kw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mallocPool
name|ffesta_output_pool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mallocPool
name|ffesta_scratch_pool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffelexToken
name|ffesta_construct_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffelexToken
name|ffesta_label_token
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffesta_seen_first_exec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffesta_is_entry_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffesta_line_has_semicolons
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|ffesta_confirmed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_eof
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffesta_ffebad_start
parameter_list|(
name|ffebad
name|errnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_ffebad_here_current_stmt
parameter_list|(
name|ffebadIndex
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffesta_first
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_init_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_init_3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffesta_is_inhibited
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_terminate_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_terminate_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_terminate_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_terminate_3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_terminate_4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_ffebad_here_doiter
parameter_list|(
name|ffebadIndex
name|i
parameter_list|,
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesymbol
name|ffesta_sym_end_transition
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesymbol
name|ffesta_sym_exec_transition
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_ffebad_1p
parameter_list|(
name|ffebad
name|msg
parameter_list|,
name|ffelexToken
name|names_token
parameter_list|,
name|ffeTokenLength
name|index
parameter_list|,
name|ffelexToken
name|next_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_ffebad_1sp
parameter_list|(
name|ffebad
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|ffelexToken
name|names_token
parameter_list|,
name|ffeTokenLength
name|index
parameter_list|,
name|ffelexToken
name|next_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_ffebad_1st
parameter_list|(
name|ffebad
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_ffebad_1t
parameter_list|(
name|ffebad
name|msg
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_ffebad_2st
parameter_list|(
name|ffebad
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|ffelexToken
name|t1
parameter_list|,
name|ffelexToken
name|t2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_ffebad_2t
parameter_list|(
name|ffebad
name|msg
parameter_list|,
name|ffelexToken
name|t1
parameter_list|,
name|ffelexToken
name|t2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffesta_zero
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffesta_two
parameter_list|(
name|ffelexToken
name|first
parameter_list|,
name|ffelexToken
name|second
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestaPooldisp
name|ffesta_outpooldisp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesta_set_outpooldisp
parameter_list|(
name|ffestaPooldisp
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffesta_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesta_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesta_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesta_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesta_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesta_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesta_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesta_terminate_4
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
comment|/* ! GCC_F_STA_H */
end_comment

end_unit

