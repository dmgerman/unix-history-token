begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osmtest_t.  *	This object represents the OSMTest Test object.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMTEST_BASE_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSMTEST_BASE_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__WIN__
end_ifndef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<vendor/winosm_common.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OSMTEST_MAX_LINE_LEN
value|120
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|OSMTEST_FILE_PATH_MAX
value|4096
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSMTEST_FILE_PATH_MAX
value|PATH_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STRESS_SMALL_RMPP_THR
value|100000
end_define

begin_comment
comment|/*     Take long times when quering big clusters (over 40 nodes) , an average of : 0.25 sec for query     each query receives 1000 records */
end_comment

begin_define
define|#
directive|define
name|STRESS_LARGE_RMPP_THR
value|4000
end_define

begin_define
define|#
directive|define
name|STRESS_LARGE_PR_RMPP_THR
value|20000
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|p_file
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSMTEST_BASE_H_ */
end_comment

end_unit

