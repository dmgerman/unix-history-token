begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sts.h -- Private #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       sts.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H_f_sts
end_ifndef

begin_define
define|#
directive|define
name|_H_f_sts
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
name|_ffests_
modifier|*
name|ffests
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffests_
name|ffestsHolder
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|ffestsLength
typedef|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffests_
block|{
name|char
modifier|*
name|text_
decl_stmt|;
name|mallocPool
name|pool_
decl_stmt|;
name|ffestsLength
name|len_
decl_stmt|;
name|ffestsLength
name|max_
decl_stmt|;
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
name|ffests_kill
parameter_list|(
name|ffests
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffests_new
parameter_list|(
name|ffests
name|s
parameter_list|,
name|mallocPool
name|pool
parameter_list|,
name|ffestsLength
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffests_printf_1D
parameter_list|(
name|ffests
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|ctl
parameter_list|,
name|long
name|arg1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffests_printf_1U
parameter_list|(
name|ffests
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|ctl
parameter_list|,
name|unsigned
name|long
name|arg1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffests_printf_1s
parameter_list|(
name|ffests
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|ctl
parameter_list|,
specifier|const
name|char
modifier|*
name|arg1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffests_printf_2Us
parameter_list|(
name|ffests
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|ctl
parameter_list|,
name|unsigned
name|long
name|arg1
parameter_list|,
specifier|const
name|char
modifier|*
name|arg2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffests_putc
parameter_list|(
name|ffests
name|s
parameter_list|,
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffests_puts
parameter_list|(
name|ffests
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffests_puttext
parameter_list|(
name|ffests
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|,
name|ffestsLength
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffests_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffests_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffests_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffests_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffests_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffests_length
parameter_list|(
name|s
parameter_list|)
value|((s)->len_)
end_define

begin_define
define|#
directive|define
name|ffests_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffests_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffests_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffests_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffests_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffests_text
parameter_list|(
name|s
parameter_list|)
value|((s)->text_)
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

