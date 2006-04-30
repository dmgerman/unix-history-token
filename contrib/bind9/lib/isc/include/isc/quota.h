begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: quota.h,v 1.8.12.6 2005/08/11 15:00:08 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_QUOTA_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_QUOTA_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Quota  *  * The isc_quota_t object is a simple helper object for implementing  * quotas on things like the number of simultaneous connections to  * a server.  It keeps track of the amount of quota in use, and  * encapsulates the locking necessary to allow multiple tasks to  * share a quota.  */
end_comment

begin_comment
comment|/***  *** Imports.  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_comment
comment|/*****  ***** Types.  *****/
end_comment

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_struct
struct|struct
name|isc_quota
block|{
name|isc_mutex_t
name|lock
decl_stmt|;
comment|/* Locked by lock. */
name|int
name|max
decl_stmt|;
name|int
name|used
decl_stmt|;
name|int
name|soft
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|isc_result_t
name|isc_quota_init
parameter_list|(
name|isc_quota_t
modifier|*
name|quota
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize a quota object.  *  * Returns:  * 	ISC_R_SUCCESS  *	Other error	Lock creation failed.  */
end_comment

begin_function_decl
name|void
name|isc_quota_destroy
parameter_list|(
name|isc_quota_t
modifier|*
name|quota
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy a quota object.  */
end_comment

begin_function_decl
name|void
name|isc_quota_soft
parameter_list|(
name|isc_quota_t
modifier|*
name|quota
parameter_list|,
name|int
name|soft
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Turn on/off soft quotas.  */
end_comment

begin_function_decl
name|void
name|isc_quota_max
parameter_list|(
name|isc_quota_t
modifier|*
name|quota
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Re-set a maximum quota.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_quota_reserve
parameter_list|(
name|isc_quota_t
modifier|*
name|quota
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attempt to reserve one unit of 'quota'.  *  * Returns:  * 	ISC_R_SUCCESS	Success  *	ISC_R_SOFTQUOTA	Success soft quota reached  *	ISC_R_QUOTA	Quota is full  */
end_comment

begin_function_decl
name|void
name|isc_quota_release
parameter_list|(
name|isc_quota_t
modifier|*
name|quota
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Release one unit of quota.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_quota_attach
parameter_list|(
name|isc_quota_t
modifier|*
name|quota
parameter_list|,
name|isc_quota_t
modifier|*
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like isc_quota_reserve, and also attaches '*p' to the  * quota if successful (ISC_R_SUCCESS or ISC_R_SOFTQUOTA).  */
end_comment

begin_function_decl
name|void
name|isc_quota_detach
parameter_list|(
name|isc_quota_t
modifier|*
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like isc_quota_release, and also detaches '*p' from the  * quota.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_QUOTA_H */
end_comment

end_unit

