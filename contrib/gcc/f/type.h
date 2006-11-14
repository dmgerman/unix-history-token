begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface definitions for Fortran type abstraction    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_TYPE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_TYPE_H
end_define

begin_typedef
typedef|typedef
name|struct
name|_ffetype_
modifier|*
name|ffetype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffetype_indexes_
modifier|*
name|ffetype_indexes_
typedef|;
end_typedef

begin_struct
struct|struct
name|_ffetype_
block|{
name|ffetype_indexes_
name|kinds_
decl_stmt|;
name|ffetype_indexes_
name|stars_
decl_stmt|;
name|int
name|alignment_
decl_stmt|;
name|int
name|modulo_
decl_stmt|;
name|int
name|size_
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffetype_indexes_
block|{
name|ffetype
name|type_
index|[
literal|40
index|]
decl_stmt|;
comment|/* *n, KIND=n: 0<= n<= 39. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ffetype_alignment
parameter_list|(
name|t
parameter_list|)
value|((t)->alignment_)
end_define

begin_define
define|#
directive|define
name|ffetype_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetype_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetype_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetype_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetype_init_4
parameter_list|()
end_define

begin_function_decl
name|ffetype
name|ffetype_lookup_kind
parameter_list|(
name|ffetype
name|base_type
parameter_list|,
name|int
name|kind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffetype
name|ffetype_lookup_star
parameter_list|(
name|ffetype
name|base_type
parameter_list|,
name|int
name|star
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffetype_modulo
parameter_list|(
name|t
parameter_list|)
value|((t)->modulo_)
end_define

begin_function_decl
name|ffetype
name|ffetype_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffetype_set_ams
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
value|((t)->alignment_ = (a), \ 				  (t)->modulo_ = (m), \ 				  (t)->size_ = (s))
end_define

begin_function_decl
name|void
name|ffetype_set_kind
parameter_list|(
name|ffetype
name|base_type
parameter_list|,
name|int
name|kind
parameter_list|,
name|ffetype
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffetype_set_star
parameter_list|(
name|ffetype
name|base_type
parameter_list|,
name|int
name|star
parameter_list|,
name|ffetype
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffetype_size
parameter_list|(
name|t
parameter_list|)
value|((t)->size_)
end_define

begin_define
define|#
directive|define
name|ffetype_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetype_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetype_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetype_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffetype_terminate_4
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_TYPE_H */
end_comment

end_unit

