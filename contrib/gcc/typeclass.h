begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Type class enum    Copyright (C) 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TYPECLASS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TYPECLASS_H
end_define

begin_comment
comment|/* Values returned by __builtin_classify_type.  */
end_comment

begin_enum
enum|enum
name|type_class
block|{
name|no_type_class
init|=
operator|-
literal|1
block|,
name|void_type_class
block|,
name|integer_type_class
block|,
name|char_type_class
block|,
name|enumeral_type_class
block|,
name|boolean_type_class
block|,
name|pointer_type_class
block|,
name|reference_type_class
block|,
name|offset_type_class
block|,
name|real_type_class
block|,
name|complex_type_class
block|,
name|function_type_class
block|,
name|method_type_class
block|,
name|record_type_class
block|,
name|union_type_class
block|,
name|array_type_class
block|,
name|string_type_class
block|,
name|lang_type_class
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_TYPECLASS_H */
end_comment

end_unit

