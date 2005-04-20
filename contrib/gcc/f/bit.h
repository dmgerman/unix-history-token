begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bit.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       bit.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_BIT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_BIT_H
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
name|_ffebit_
modifier|*
name|ffebit
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ffebitCount
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffebitCount_f
value|"l"
end_define

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
name|_ffebit_
block|{
name|mallocPool
name|pool
decl_stmt|;
name|ffebitCount
name|size
decl_stmt|;
name|unsigned
name|char
name|bits
index|[
literal|1
index|]
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
name|ffebit_count
parameter_list|(
name|ffebit
name|b
parameter_list|,
name|ffebitCount
name|offset
parameter_list|,
name|bool
name|value
parameter_list|,
name|ffebitCount
name|range
parameter_list|,
name|ffebitCount
modifier|*
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebit_kill
parameter_list|(
name|ffebit
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebit
name|ffebit_new
parameter_list|(
name|mallocPool
name|pool
parameter_list|,
name|ffebitCount
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebit_set
parameter_list|(
name|ffebit
name|b
parameter_list|,
name|ffebitCount
name|offset
parameter_list|,
name|bool
name|value
parameter_list|,
name|ffebitCount
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebit_test
parameter_list|(
name|ffebit
name|b
parameter_list|,
name|ffebitCount
name|offset
parameter_list|,
name|bool
modifier|*
name|value
parameter_list|,
name|ffebitCount
modifier|*
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
name|ffebit_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebit_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebit_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebit_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebit_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebit_pool
parameter_list|(
name|b
parameter_list|)
value|((b)->pool)
end_define

begin_define
define|#
directive|define
name|ffebit_size
parameter_list|(
name|b
parameter_list|)
value|((b)->size)
end_define

begin_define
define|#
directive|define
name|ffebit_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebit_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebit_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebit_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebit_terminate_4
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
comment|/* ! GCC_F_BIT_H */
end_comment

end_unit

