begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declare the class Protocol for Objective C programs.    Copyright (C) 1993, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__Protocol_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__Protocol_INCLUDE_GNU
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
name|Protocol
range|:
name|Object
block|{ @
name|private
name|char
operator|*
name|protocol_name
block|;         struct
name|objc_protocol_list
operator|*
name|protocol_list
block|;         struct
name|objc_method_description_list
operator|*
name|instance_methods
block|,
operator|*
name|class_methods
block|;  }
comment|/* Obtaining attributes intrinsic to the protocol */
operator|-
operator|(
specifier|const
name|char
operator|*
operator|)
name|name
decl_stmt|;
comment|/* Testing protocol conformance */
operator|-
operator|(
name|BOOL
operator|)
name|conformsTo
operator|:
operator|(
name|Protocol
operator|*
operator|)
name|aProtocolObject
expr_stmt|;
comment|/* Looking up information specific to a protocol */
operator|-
operator|(
expr|struct
name|objc_method_description
operator|*
operator|)
name|descriptionForInstanceMethod
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
operator|-
operator|(
expr|struct
name|objc_method_description
operator|*
operator|)
name|descriptionForClassMethod
operator|:
operator|(
name|SEL
operator|)
name|aSel
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

begin_comment
comment|/* not __Protocol_INCLUDE_GNU */
end_comment

end_unit

