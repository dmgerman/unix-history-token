begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Encoding of types for Objective C.    Copyright (C) 1993, 1997 Free Software Foundation, Inc.  Author: Kresten Krab Thorup  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__encoding_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__encoding_INCLUDE_GNU
end_define

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"objc/objc-api.h"
end_include

begin_define
define|#
directive|define
name|_C_CONST
value|'r'
end_define

begin_define
define|#
directive|define
name|_C_IN
value|'n'
end_define

begin_define
define|#
directive|define
name|_C_INOUT
value|'N'
end_define

begin_define
define|#
directive|define
name|_C_OUT
value|'o'
end_define

begin_define
define|#
directive|define
name|_C_BYCOPY
value|'O'
end_define

begin_define
define|#
directive|define
name|_C_ONEWAY
value|'V'
end_define

begin_define
define|#
directive|define
name|_F_CONST
value|0x01
end_define

begin_define
define|#
directive|define
name|_F_IN
value|0x01
end_define

begin_define
define|#
directive|define
name|_F_OUT
value|0x02
end_define

begin_define
define|#
directive|define
name|_F_INOUT
value|0x03
end_define

begin_define
define|#
directive|define
name|_F_BYCOPY
value|0x04
end_define

begin_define
define|#
directive|define
name|_F_ONEWAY
value|0x08
end_define

begin_function_decl
name|int
name|objc_aligned_size
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_sizeof_type
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_alignof_type
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_aligned_size
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|objc_promoted_size
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|objc_skip_type_qualifiers
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|objc_skip_typespec
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|objc_skip_offset
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|objc_skip_argspec
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|method_get_number_of_arguments
parameter_list|(
name|struct
name|objc_method
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|method_get_sizeof_arguments
parameter_list|(
name|struct
name|objc_method
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|method_get_first_argument
parameter_list|(
name|struct
name|objc_method
modifier|*
parameter_list|,
name|arglist_t
name|argframe
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|method_get_next_argument
parameter_list|(
name|arglist_t
name|argframe
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|method_get_nth_argument
parameter_list|(
name|struct
name|objc_method
modifier|*
name|m
parameter_list|,
name|arglist_t
name|argframe
parameter_list|,
name|int
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|objc_get_type_qualifiers
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __encoding_INCLUDE_GNU */
end_comment

end_unit

