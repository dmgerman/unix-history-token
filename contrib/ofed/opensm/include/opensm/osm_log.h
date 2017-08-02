begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2012 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_log_t.  *	This object represents the log file.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_LOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_LOG_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__WIN__
end_ifndef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<complib/cl_spinlock.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|STRICT_OSM_LOG_FORMAT
value|__attribute__((format(printf, 3, 4)))
end_define

begin_define
define|#
directive|define
name|STRICT_OSM_LOG_V2_FORMAT
value|__attribute__((format(printf, 4, 5)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRICT_OSM_LOG_FORMAT
end_define

begin_define
define|#
directive|define
name|STRICT_OSM_LOG_V2_FORMAT
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|LOG_ENTRY_SIZE_MAX
value|4096
end_define

begin_define
define|#
directive|define
name|BUF_SIZE
value|LOG_ENTRY_SIZE_MAX
end_define

begin_define
define|#
directive|define
name|__func__
value|__FUNCTION__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FILE_ID
end_ifdef

begin_define
define|#
directive|define
name|OSM_LOG_ENTER
parameter_list|(
name|OSM_LOG_PTR
parameter_list|)
define|\
value|osm_log_v2( OSM_LOG_PTR, OSM_LOG_FUNCS, FILE_ID, \ 		    "%s: [\n", __func__);
end_define

begin_define
define|#
directive|define
name|OSM_LOG_EXIT
parameter_list|(
name|OSM_LOG_PTR
parameter_list|)
define|\
value|osm_log_v2( OSM_LOG_PTR, OSM_LOG_FUNCS, FILE_ID, \ 		    "%s: ]\n", __func__);
end_define

begin_define
define|#
directive|define
name|OSM_LOG_IS_ACTIVE_V2
parameter_list|(
name|OSM_LOG_PTR
parameter_list|,
name|OSM_LOG_FUNCS
parameter_list|)
define|\
value|osm_log_is_active_v2( OSM_LOG_PTR, OSM_LOG_FUNCS, FILE_ID)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_LOG_ENTER
parameter_list|(
name|OSM_LOG_PTR
parameter_list|)
define|\
value|osm_log( OSM_LOG_PTR, OSM_LOG_FUNCS, \ 		 "%s: [\n", __func__);
end_define

begin_define
define|#
directive|define
name|OSM_LOG_EXIT
parameter_list|(
name|OSM_LOG_PTR
parameter_list|)
define|\
value|osm_log( OSM_LOG_PTR, OSM_LOG_FUNCS, \ 		 "%s: ]\n", __func__);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****h* OpenSM/Log * NAME *	Log * * DESCRIPTION * * AUTHOR * *********/
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|osm_log_level_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OSM_LOG_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|OSM_LOG_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|OSM_LOG_INFO
value|0x02
end_define

begin_define
define|#
directive|define
name|OSM_LOG_VERBOSE
value|0x04
end_define

begin_define
define|#
directive|define
name|OSM_LOG_DEBUG
value|0x08
end_define

begin_define
define|#
directive|define
name|OSM_LOG_FUNCS
value|0x10
end_define

begin_define
define|#
directive|define
name|OSM_LOG_FRAMES
value|0x20
end_define

begin_define
define|#
directive|define
name|OSM_LOG_ROUTING
value|0x40
end_define

begin_define
define|#
directive|define
name|OSM_LOG_ALL
value|0x7f
end_define

begin_define
define|#
directive|define
name|OSM_LOG_SYS
value|0x80
end_define

begin_comment
comment|/* 	DEFAULT - turn on ERROR and INFO only */
end_comment

begin_define
define|#
directive|define
name|OSM_LOG_DEFAULT_LEVEL
value|OSM_LOG_ERROR | OSM_LOG_INFO
end_define

begin_comment
comment|/****s* OpenSM: Log/osm_log_t * NAME *	osm_log_t * * DESCRIPTION * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_log
block|{
name|osm_log_level_t
name|level
decl_stmt|;
name|cl_spinlock_t
name|lock
decl_stmt|;
name|unsigned
name|long
name|count
decl_stmt|;
name|unsigned
name|long
name|max_size
decl_stmt|;
name|boolean_t
name|flush
decl_stmt|;
name|FILE
modifier|*
name|out_port
decl_stmt|;
name|boolean_t
name|accum_log_file
decl_stmt|;
name|boolean_t
name|daemon
decl_stmt|;
name|char
modifier|*
name|log_file_name
decl_stmt|;
name|char
modifier|*
name|log_prefix
decl_stmt|;
name|osm_log_level_t
name|per_mod_log_tbl
index|[
literal|256
index|]
decl_stmt|;
block|}
name|osm_log_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_define
define|#
directive|define
name|OSM_LOG_MOD_NAME_MAX
value|32
end_define

begin_comment
comment|/****f* OpenSM: Log/osm_get_log_per_module  * NAME  *	osm_get_log_per_module  *  * DESCRIPTION  *	This looks up the given file ID in the per module log table.  *	NOTE: this code is not thread safe. Need to grab the lock before  *	calling it.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|osm_log_level_t
name|osm_get_log_per_module
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
specifier|const
name|int
name|file_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  *	p_log  *		[in] Pointer to a Log object to construct.  *  *	file_id  *		[in] File ID for module  *  * RETURN VALUES  *	The log level from the per module logging structure for this file ID.  *********/
end_comment

begin_comment
comment|/****f* OpenSM: Log/osm_set_log_per_module  * NAME  *	osm_set_log_per_module  *  * DESCRIPTION  *	This sets log level for the given file ID in the per module log table.  *	NOTE: this code is not thread safe. Need to grab the lock before  *	calling it.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|void
name|osm_set_log_per_module
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
specifier|const
name|int
name|file_id
parameter_list|,
name|IN
name|osm_log_level_t
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  *	p_log  *		[in] Pointer to a Log object to construct.  *  *	file_id  *		[in] File ID for module  *  *	level  *		[in] Log level of the module  *  * RETURN VALUES  *	This function does not return a value.  *********/
end_comment

begin_comment
comment|/****f* OpenSM: Log/osm_reset_log_per_module  * NAME  *	osm_reset_log_per_module  *  * DESCRIPTION  *	This resets log level for the entire per module log table.  *	NOTE: this code is not thread safe. Need to grab the lock before  *	calling it.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|void
name|osm_reset_log_per_module
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  *	p_log  *		[in] Pointer to a Log object to construct.  *  * RETURN VALUES  *	This function does not return a value.  *********/
end_comment

begin_comment
comment|/****f* OpenSM: Log/osm_log_construct * NAME *	osm_log_construct * * DESCRIPTION *	This function constructs a Log object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_log_construct
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
block|{
name|cl_spinlock_construct
argument_list|(
operator|&
name|p_log
operator|->
name|lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to a Log object to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling osm_log_init, osm_log_init_v2, osm_log_destroy * *	Calling osm_log_construct is a prerequisite to calling any other *	method except osm_log_init or osm_log_init_v2. * * SEE ALSO *	Log object, osm_log_init, osm_log_init_v2, *	osm_log_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Log/osm_log_destroy * NAME *	osm_log_destroy * * DESCRIPTION *	The osm_log_destroy function destroys the object, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_log_destroy
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
block|{
name|cl_spinlock_destroy
argument_list|(
operator|&
name|p_log
operator|->
name|lock
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_log
operator|->
name|out_port
operator|!=
name|stdout
condition|)
block|{
name|fclose
argument_list|(
name|p_log
operator|->
name|out_port
argument_list|)
expr_stmt|;
name|p_log
operator|->
name|out_port
operator|=
name|stdout
expr_stmt|;
block|}
name|closelog
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the object to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified *	Log object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to *	osm_log_construct, osm_log_init, or osm_log_init_v2. * * SEE ALSO *	Log object, osm_log_construct, *	osm_log_init, osm_log_init_v2 *********/
end_comment

begin_comment
comment|/****f* OpenSM: Log/osm_log_init_v2 * NAME *	osm_log_init_v2 * * DESCRIPTION *	The osm_log_init_v2 function initializes a *	Log object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_log_init_v2
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|boolean_t
name|flush
parameter_list|,
name|IN
name|uint8_t
name|log_flags
parameter_list|,
name|IN
specifier|const
name|char
modifier|*
name|log_file
parameter_list|,
name|IN
name|unsigned
name|long
name|max_size
parameter_list|,
name|IN
name|boolean_t
name|accum_log_file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the log object. * *	flush *		[in] Set to TRUE directs the log to flush all log messages *		immediately.  This severely degrades log performance, *		and is normally used for debugging only. * *	log_flags *		[in] The log verbosity level to be used. * *	log_file *		[in] if not NULL defines the name of the log file. Otherwise *		it is stdout. * * RETURN VALUES *	CL_SUCCESS if the Log object was initialized *	successfully. * * NOTES *	Allows calling other Log methods. * * SEE ALSO *	Log object, osm_log_construct, *	osm_log_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Log/osm_log_reopen_file * NAME *	osm_log_reopen_file * * DESCRIPTION *	The osm_log_reopen_file function reopens the log file * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_log_reopen_file
parameter_list|(
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the log object. * * RETURN VALUES *	0 on success or nonzero value otherwise. *********/
end_comment

begin_comment
comment|/****f* OpenSM: Log/osm_log_init * NAME *	osm_log_init * * DESCRIPTION *	The osm_log_init function initializes a *	Log object for use. It is a wrapper for osm_log_init_v2(). * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_log_init
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|boolean_t
name|flush
parameter_list|,
name|IN
name|uint8_t
name|log_flags
parameter_list|,
name|IN
specifier|const
name|char
modifier|*
name|log_file
parameter_list|,
name|IN
name|boolean_t
name|accum_log_file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Same as osm_log_init_v2() but without max_size parameter  */
end_comment

begin_decl_stmt
name|void
name|osm_log
argument_list|(
name|IN
name|osm_log_t
operator|*
name|p_log
argument_list|,
name|IN
name|osm_log_level_t
name|verbosity
argument_list|,
name|IN
specifier|const
name|char
operator|*
name|p_str
argument_list|,
operator|...
argument_list|)
name|STRICT_OSM_LOG_FORMAT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|osm_log_v2
argument_list|(
name|IN
name|osm_log_t
operator|*
name|p_log
argument_list|,
name|IN
name|osm_log_level_t
name|verbosity
argument_list|,
name|IN
specifier|const
name|int
name|file_id
argument_list|,
name|IN
specifier|const
name|char
operator|*
name|p_str
argument_list|,
operator|...
argument_list|)
name|STRICT_OSM_LOG_V2_FORMAT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****f* OpenSM: Log/osm_log_get_level * NAME *	osm_log_get_level * * DESCRIPTION *	Returns the current log level. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_log_level_t
name|osm_log_get_level
parameter_list|(
name|IN
specifier|const
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
block|{
return|return
name|p_log
operator|->
name|level
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the log object. * * RETURN VALUES *	Returns the current log level. * * NOTES * * SEE ALSO *	Log object, osm_log_construct, *	osm_log_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Log/osm_log_set_level * NAME *	osm_log_set_level * * DESCRIPTION *	Sets the current log level. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_log_set_level
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_log_level_t
name|level
parameter_list|)
block|{
name|p_log
operator|->
name|level
operator|=
name|level
expr_stmt|;
name|osm_log
argument_list|(
name|p_log
argument_list|,
name|OSM_LOG_ALL
argument_list|,
literal|"Setting log level to: 0x%02x\n"
argument_list|,
name|level
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the log object. * *	level *		[in] New level to set. * * RETURN VALUES *	This function does not return a value. * * NOTES * * SEE ALSO *	Log object, osm_log_construct, *	osm_log_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Log/osm_log_is_active * NAME *	osm_log_is_active * * DESCRIPTION *	Returns TRUE if the specified log level would be logged. *	FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_log_is_active
parameter_list|(
name|IN
specifier|const
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_log_level_t
name|level
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p_log
operator|->
name|level
operator|&
name|level
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to the log object. * *	level *		[in] Level to check. * * RETURN VALUES *	Returns TRUE if the specified log level would be logged. *	FALSE otherwise. * * NOTES * * SEE ALSO *	Log object, osm_log_construct, *	osm_log_destroy *********/
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_log_is_active_v2
parameter_list|(
name|IN
specifier|const
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_log_level_t
name|level
parameter_list|,
name|IN
specifier|const
name|int
name|file_id
parameter_list|)
block|{
if|if
condition|(
operator|(
name|p_log
operator|->
name|level
operator|&
name|level
operator|)
operator|!=
literal|0
condition|)
return|return
literal|1
return|;
if|if
condition|(
operator|(
name|level
operator|&
name|p_log
operator|->
name|per_mod_log_tbl
index|[
name|file_id
index|]
operator|)
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|osm_log_msg_box
parameter_list|(
name|osm_log_t
modifier|*
name|log
parameter_list|,
name|osm_log_level_t
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|func_name
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|osm_log_msg_box_v2
parameter_list|(
name|osm_log_t
modifier|*
name|log
parameter_list|,
name|osm_log_level_t
name|level
parameter_list|,
specifier|const
name|int
name|file_id
parameter_list|,
specifier|const
name|char
modifier|*
name|func_name
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|osm_log_raw
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_log_level_t
name|verbosity
parameter_list|,
name|IN
specifier|const
name|char
modifier|*
name|p_buf
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FILE_ID
end_ifdef

begin_define
define|#
directive|define
name|OSM_LOG
parameter_list|(
name|log
parameter_list|,
name|level
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do { \ 		if (osm_log_is_active_v2(log, (level), FILE_ID)) \ 			osm_log_v2(log, level, FILE_ID, "%s: " fmt, __func__, ## __VA_ARGS__); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|OSM_LOG_MSG_BOX
parameter_list|(
name|log
parameter_list|,
name|level
parameter_list|,
name|msg
parameter_list|)
define|\
value|osm_log_msg_box_v2(log, level, FILE_ID, __func__, msg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OSM_LOG
parameter_list|(
name|log
parameter_list|,
name|level
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do { \ 		if (osm_log_is_active(log, (level))) \ 			osm_log(log, level, "%s: " fmt, __func__, ## __VA_ARGS__); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|OSM_LOG_MSG_BOX
parameter_list|(
name|log
parameter_list|,
name|level
parameter_list|,
name|msg
parameter_list|)
define|\
value|osm_log_msg_box(log, level, __func__, msg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DBG_CL_LOCK
value|0
end_define

begin_define
define|#
directive|define
name|CL_PLOCK_EXCL_ACQUIRE
parameter_list|(
name|__exp__
parameter_list|)
define|\
value|{											    		\    if (DBG_CL_LOCK)                      \      printf("cl_plock_excl_acquire: Acquiring %p file %s, line %d\n", \           __exp__,__FILE__, __LINE__);            \    cl_plock_excl_acquire( __exp__ );      \    if (DBG_CL_LOCK)                      \      printf("cl_plock_excl_acquire: Acquired %p file %s, line %d\n", \           __exp__,__FILE__, __LINE__);            \ }
end_define

begin_define
define|#
directive|define
name|CL_PLOCK_ACQUIRE
parameter_list|(
name|__exp__
parameter_list|)
define|\
value|{											    		\    if (DBG_CL_LOCK)                      \      printf("cl_plock_acquire: Acquiring %p file %s, line %d\n", \           __exp__,__FILE__, __LINE__);            \    cl_plock_acquire( __exp__ );      \    if (DBG_CL_LOCK)                      \      printf("cl_plock_acquire: Acquired %p file %s, line %d\n", \           __exp__,__FILE__, __LINE__);            \ }
end_define

begin_define
define|#
directive|define
name|CL_PLOCK_RELEASE
parameter_list|(
name|__exp__
parameter_list|)
define|\
value|{											    		\    if (DBG_CL_LOCK)                      \      printf("cl_plock_release: Releasing %p file %s, line %d\n", \           __exp__,__FILE__, __LINE__);            \    cl_plock_release( __exp__ );      \    if (DBG_CL_LOCK)                      \      printf("cl_plock_release: Released  %p file %s, line %d\n", \           __exp__,__FILE__, __LINE__);            \ }
end_define

begin_define
define|#
directive|define
name|DBG_CL_SPINLOCK
value|0
end_define

begin_define
define|#
directive|define
name|CL_SPINLOCK_RELEASE
parameter_list|(
name|__exp__
parameter_list|)
define|\
value|{											    		\    if (DBG_CL_SPINLOCK)                      \      printf("cl_spinlock_release: Releasing %p file %s, line %d\n", \           __exp__,__FILE__, __LINE__);            \    cl_spinlock_release( __exp__ );      \    if (DBG_CL_SPINLOCK)                      \      printf("cl_spinlock_release: Released  %p file %s, line %d\n", \           __exp__,__FILE__, __LINE__);            \ }
end_define

begin_define
define|#
directive|define
name|CL_SPINLOCK_ACQUIRE
parameter_list|(
name|__exp__
parameter_list|)
define|\
value|{											    		\    if (DBG_CL_SPINLOCK)                      \      printf("cl_spinlock_acquire: Acquiring %p file %s, line %d\n", \           __exp__,__FILE__, __LINE__);            \    cl_spinlock_acquire( __exp__ );      \    if (DBG_CL_SPINLOCK)                      \      printf("cl_spinlock_acquire: Acquired %p file %s, line %d\n", \           __exp__,__FILE__, __LINE__);            \ }
end_define

begin_comment
comment|/****f* OpenSM: Helper/osm_is_debug * NAME *	osm_is_debug * * DESCRIPTION *	The osm_is_debug function returns TRUE if the opensm was compiled *	in debug mode, and FALSE otherwise. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_is_debug
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	None * * RETURN VALUE *	TRUE if compiled in debug version. FALSE otherwise. * * NOTES * *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_LOG_H_ */
end_comment

end_unit

