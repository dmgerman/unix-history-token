begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: resource.h,v 1.4.206.1 2004/03/06 08:14:47 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_RESOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_RESOURCE_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_define
define|#
directive|define
name|ISC_RESOURCE_UNLIMITED
value|((isc_resourcevalue_t)ISC_UINT64_MAX)
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_resource_setlimit
parameter_list|(
name|isc_resource_t
name|resource
parameter_list|,
name|isc_resourcevalue_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the maximum limit for a system resource.  *  * Notes:  *	If 'value' exceeds the maximum possible on the operating system,  *	it is silently limited to that maximum -- or to "infinity", if  *	the operating system has that concept.  ISC_RESOURCE_UNLIMITED  *	can be used to explicitly ask for the maximum.  *  * Requires:  *	'resource' is a valid member of the isc_resource_t enumeration.  *  * Returns:  *	ISC_R_SUCCESS	Success.  *	ISC_R_NOTIMPLEMENTED	'resource' is not a type known by the OS.  *	ISC_R_NOPERM	The calling process did not have adequate permission  *			to change the resource limit.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_resource_getlimit
parameter_list|(
name|isc_resource_t
name|resource
parameter_list|,
name|isc_resourcevalue_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the maximum limit for a system resource.  *  * Notes:  *	'value' is set to the maximum limit.  *  *	ISC_RESOURCE_UNLIMITED is the maximum value of isc_resourcevalue_t.  *  *	On many (all?) Unix systems, RLIM_INFINITY is a valid value that is  *	significantly less than ISC_RESOURCE_UNLIMITED, but which in practice  *	behaves the same.  *  *	The current ISC libdns configuration file parser assigns a value  *	of ISC_UINT32_MAX for a size_spec of "unlimited" and ISC_UNIT32_MAX - 1  *	for "default", the latter of which is supposed to represent "the  *	limit that was in force when the server started".  Since these are  *	valid values in the middle of the range of isc_resourcevalue_t,  *	there is the possibility for confusion over what exactly those  *	particular values are supposed to represent in a particular context --  *	discrete integral values or generalized concepts.  *  * Requires:  *	'resource' is a valid member of the isc_resource_t enumeration.  *  * Returns:  *	ISC_R_SUCCESS		Success.  *	ISC_R_NOTIMPLEMENTED	'resource' is not a type known by the OS.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_RESOURCE_H */
end_comment

end_unit

