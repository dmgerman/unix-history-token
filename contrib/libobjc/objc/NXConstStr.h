begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface for the NXConstantString class for Objective-C.    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by Pieter J. Schoenmakers<tiggr@es.ele.tue.nl>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__nxconstantstring_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__nxconstantstring_INCLUDE_GNU
end_define

begin_include
include|#
directive|include
file|"objc/Object.h"
end_include

begin_decl_stmt
unit|@
name|interface
name|NXConstantString
range|:
name|Object
block|{
name|char
operator|*
name|c_string
block|;
name|unsigned
name|int
name|len
block|; }
operator|-
operator|(
specifier|const
name|char
operator|*
operator|)
name|cString
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|unsigned
name|int
operator|)
name|length
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

