begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface for the NXConstantString class for Objective-C.    Copyright (C) 1995, 2004 Free Software Foundation, Inc.    Contributed by Pieter J. Schoenmakers<tiggr@es.ele.tue.nl>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"Object.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
block|@
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
operator|-
operator|(
name|unsigned
name|int
operator|)
name|length
expr_stmt|;
block|@
name|end
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

