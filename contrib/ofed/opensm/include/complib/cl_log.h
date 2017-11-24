begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Declaration of logging mechanisms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_LOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_LOG_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_types.h>
end_include

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

begin_comment
comment|/****h* Component Library/Log Provider * NAME *	Log Provider * * DESCRIPTION *	The log provider allows users to log information in a system log instead of *	the console or debugger target. **********/
end_comment

begin_comment
comment|/****d* Component Library: Log Provider/cl_log_type_t * NAME *	cl_log_type_t * * DESCRIPTION *	The cl_log_type_t enumerated type is used to differentiate between *	different types of log entries. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_cl_log_type
block|{
name|CL_LOG_INFO
block|,
name|CL_LOG_WARN
block|,
name|CL_LOG_ERROR
block|}
name|cl_log_type_t
typedef|;
end_typedef

begin_comment
comment|/* * VALUES *	CL_LOG_INFO *		Indicates a log entry is purely informational. * *	CL_LOG_WARN *		Indicates a log entry is a warning but non-fatal. * *	CL_LOG_ERROR *		Indicates a log entry is a fatal error. * * SEE ALSO *	Log Provider, cl_log_event *********/
end_comment

begin_comment
comment|/****f* Component Library: Log Provider/cl_log_event * NAME *	cl_log_event * * DESCRIPTION *	The cl_log_event function adds a new entry to the system log. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_log_event
parameter_list|(
name|IN
specifier|const
name|char
modifier|*
specifier|const
name|name
parameter_list|,
name|IN
specifier|const
name|cl_log_type_t
name|type
parameter_list|,
name|IN
specifier|const
name|char
modifier|*
specifier|const
name|message
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|p_data
name|OPTIONAL
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|data_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	name *		[in] Pointer to an ANSI string containing the name of the source for *		the log entry. * *	type *		[in] Defines the type of log entry to add to the system log. *		See the definition of cl_log_type_t for acceptable values. * *	message *		[in] Pointer to an ANSI string containing the text for the log entry. *		The message should not be terminated with a new line, as the log *		provider appends a new line to all log entries. * *	p_data *		[in] Optional pointer to data providing context for the log entry. *		At most 256 bytes of data can be successfully logged. * *	data_len *		[in] Length of the buffer pointed to by the p_data parameter.  Ignored *		if p_data is NULL. * * RETURN VALUE *	This function does not return a value. * * NOTES *	If the data length exceeds the maximum supported, the event is logged *	without its accompanying data. * * SEE ALSO *	Log Provider, cl_log_type_t *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_LOG_H_ */
end_comment

end_unit

