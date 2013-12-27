begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006-2007 The Regents of the University of California.  * Copyright (c) 2004-2008 Voltaire Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBDIAG_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_IBDIAG_COMMON_H_
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|argv0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ibdebug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*========================================================*/
end_comment

begin_comment
comment|/*                External interface                      */
end_comment

begin_comment
comment|/*========================================================*/
end_comment

begin_undef
undef|#
directive|undef
name|DEBUG
end_undef

begin_define
define|#
directive|define
name|DEBUG
value|if (ibdebug || verbose) IBWARN
end_define

begin_define
define|#
directive|define
name|VERBOSE
value|if (ibdebug || verbose> 1) IBWARN
end_define

begin_define
define|#
directive|define
name|IBERROR
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|iberror(__FUNCTION__, fmt, ## args)
end_define

begin_function_decl
name|void
name|iberror
parameter_list|(
specifier|const
name|char
modifier|*
name|fn
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<ibdiag_version.h>
end_include

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|get_build_version
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|"BUILD VERSION: "
name|IBDIAG_VERSION
literal|" Build date: "
name|__DATE__
literal|" "
name|__TIME__
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBDIAG_COMMON_H_ */
end_comment

end_unit

