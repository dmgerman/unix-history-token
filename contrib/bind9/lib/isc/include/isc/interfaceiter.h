begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: interfaceiter.h,v 1.10.206.1 2004/03/06 08:14:42 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_INTERFACEITER_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_INTERFACEITER_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Interface iterator  *  * Iterate over the list of network interfaces.  *  * Interfaces whose address family is not supported are ignored and never  * returned by the iterator.  Interfaces whose netmask, interface flags,  * or similar cannot be obtained are also ignored, and the failure is logged.  *  * Standards:  *	The API for scanning varies greatly among operating systems.  *	This module attempts to hide the differences.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/netaddr.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_comment
comment|/*  * Public structure describing a network interface.  */
end_comment

begin_struct
struct|struct
name|isc_interface
block|{
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Interface name, null-terminated. */
name|unsigned
name|int
name|af
decl_stmt|;
comment|/* Address family. */
name|isc_netaddr_t
name|address
decl_stmt|;
comment|/* Local address. */
name|isc_netaddr_t
name|netmask
decl_stmt|;
comment|/* Network mask. */
name|isc_netaddr_t
name|dstaddress
decl_stmt|;
comment|/* Destination address 					   (point-to-point only). */
name|isc_uint32_t
name|flags
decl_stmt|;
comment|/* Flags; see below. */
block|}
struct|;
end_struct

begin_comment
comment|/* Interface flags. */
end_comment

begin_define
define|#
directive|define
name|INTERFACE_F_UP
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|INTERFACE_F_POINTTOPOINT
value|0x00000002U
end_define

begin_define
define|#
directive|define
name|INTERFACE_F_LOOPBACK
value|0x00000004U
end_define

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_interfaceiter_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_interfaceiter_t
modifier|*
modifier|*
name|iterp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create an iterator for traversing the operating system's list  * of network interfaces.  *  * Returns:  *	ISC_R_SUCCESS  * 	ISC_R_NOMEMORY  *	Various network-related errors  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_interfaceiter_first
parameter_list|(
name|isc_interfaceiter_t
modifier|*
name|iter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Position the iterator on the first interface.  *  * Returns:  *	ISC_R_SUCCESS		Success.  *	ISC_R_NOMORE		There are no interfaces.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_interfaceiter_current
parameter_list|(
name|isc_interfaceiter_t
modifier|*
name|iter
parameter_list|,
name|isc_interface_t
modifier|*
name|ifdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get information about the interface the iterator is currently  * positioned at and store it at *ifdata.  *  * Requires:  * 	The iterator has been successfully positioned using  * 	isc_interface_iter_first() / isc_interface_iter_next().  *  * Returns:  *	ISC_R_SUCCESS		Success.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_interfaceiter_next
parameter_list|(
name|isc_interfaceiter_t
modifier|*
name|iter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Position the iterator on the next interface.  *  * Requires:  * 	The iterator has been successfully positioned using  * 	isc_interface_iter_first() / isc_interface_iter_next().  *  * Returns:  *	ISC_R_SUCCESS		Success.  *	ISC_R_NOMORE		There are no more interfaces.  */
end_comment

begin_function_decl
name|void
name|isc_interfaceiter_destroy
parameter_list|(
name|isc_interfaceiter_t
modifier|*
modifier|*
name|iterp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy the iterator.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_INTERFACEITER_H */
end_comment

end_unit

