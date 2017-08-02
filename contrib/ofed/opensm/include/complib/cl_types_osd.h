begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2012 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Defines sized datatypes for Linux User mode  *  exported sizes are int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t  *  int64_t, uint64_t.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_TYPES_OSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_TYPES_OSD_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DEBUG_
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__IA64__
end_ifdef

begin_define
define|#
directive|define
name|cl_break
parameter_list|()
value|asm("   break 0")
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __IA64__ */
end_comment

begin_define
define|#
directive|define
name|cl_break
parameter_list|()
value|asm("   int $3")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IA64__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _DEBUG_ */
end_comment

begin_define
define|#
directive|define
name|cl_break
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * Branch prediction hints  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_BUILTIN_EXPECT
argument_list|)
end_if

begin_define
define|#
directive|define
name|PT
parameter_list|(
name|exp
parameter_list|)
value|__builtin_expect( ((uintptr_t)(exp)), 1 )
end_define

begin_define
define|#
directive|define
name|PF
parameter_list|(
name|exp
parameter_list|)
value|__builtin_expect( ((uintptr_t)(exp)), 0 )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PT
parameter_list|(
name|exp
parameter_list|)
value|(exp)
end_define

begin_define
define|#
directive|define
name|PF
parameter_list|(
name|exp
parameter_list|)
value|(exp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DEBUG_
argument_list|)
end_if

begin_define
define|#
directive|define
name|CL_ASSERT
value|assert
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _DEBUG_ */
end_comment

begin_define
define|#
directive|define
name|CL_ASSERT
parameter_list|(
name|__exp__
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEBUG_ */
end_comment

begin_comment
comment|/*  * Types not explicitly defined are native to the platform.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|boolean_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|volatile
name|int32_t
name|atomic32_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|(void*)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UNUSED_PARAM
parameter_list|(
name|P
parameter_list|)
end_define

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_TYPES_OSD_H_ */
end_comment

end_unit

