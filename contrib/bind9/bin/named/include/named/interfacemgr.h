begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: interfacemgr.h,v 1.23.24.7 2004/04/29 01:31:22 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_INTERFACEMGR_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_INTERFACEMGR_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Interface manager  *  * The interface manager monitors the operating system's list  * of network interfaces, creating and destroying listeners  * as needed.  *  * Reliability:  *	No impact expected.  *  * Resources:  *  * Security:  * 	The server will only be able to bind to the DNS port on  *	newly discovered interfaces if it is running as root.  *  * Standards:  *	The API for scanning varies greatly among operating systems.  *	This module attempts to hide the differences.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/mem.h>
end_include

begin_include
include|#
directive|include
file|<isc/socket.h>
end_include

begin_include
include|#
directive|include
file|<dns/result.h>
end_include

begin_include
include|#
directive|include
file|<named/listenlist.h>
end_include

begin_include
include|#
directive|include
file|<named/types.h>
end_include

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_define
define|#
directive|define
name|IFACE_MAGIC
value|ISC_MAGIC('I',':','-',')')
end_define

begin_define
define|#
directive|define
name|NS_INTERFACE_VALID
parameter_list|(
name|t
parameter_list|)
value|ISC_MAGIC_VALID(t, IFACE_MAGIC)
end_define

begin_define
define|#
directive|define
name|NS_INTERFACEFLAG_ANYADDR
value|0x01U
end_define

begin_comment
comment|/* bound to "any" address */
end_comment

begin_struct
struct|struct
name|ns_interface
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
comment|/* Magic number. */
name|ns_interfacemgr_t
modifier|*
name|mgr
decl_stmt|;
comment|/* Interface manager. */
name|isc_mutex_t
name|lock
decl_stmt|;
name|int
name|references
decl_stmt|;
comment|/* Locked */
name|unsigned
name|int
name|generation
decl_stmt|;
comment|/* Generation number. */
name|isc_sockaddr_t
name|addr
decl_stmt|;
comment|/* Address and port. */
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* Interface characteristics */
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Null terminated. */
name|dns_dispatch_t
modifier|*
name|udpdispatch
decl_stmt|;
comment|/* UDP dispatcher. */
name|isc_socket_t
modifier|*
name|tcpsocket
decl_stmt|;
comment|/* TCP socket. */
name|int
name|ntcptarget
decl_stmt|;
comment|/* Desired number of concurrent 						   TCP accepts */
name|int
name|ntcpcurrent
decl_stmt|;
comment|/* Current ditto, locked */
name|ns_clientmgr_t
modifier|*
name|clientmgr
decl_stmt|;
comment|/* Client manager. */
name|ISC_LINK
argument_list|(
argument|ns_interface_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|isc_result_t
name|ns_interfacemgr_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|,
name|isc_socketmgr_t
modifier|*
name|socketmgr
parameter_list|,
name|dns_dispatchmgr_t
modifier|*
name|dispatchmgr
parameter_list|,
name|ns_interfacemgr_t
modifier|*
modifier|*
name|mgrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new interface manager.  *  * Initially, the new manager will not listen on any interfaces.  * Call ns_interfacemgr_setlistenon() and/or ns_interfacemgr_setlistenon6()  * to set nonempty listen-on lists.  */
end_comment

begin_function_decl
name|void
name|ns_interfacemgr_attach
parameter_list|(
name|ns_interfacemgr_t
modifier|*
name|source
parameter_list|,
name|ns_interfacemgr_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_interfacemgr_detach
parameter_list|(
name|ns_interfacemgr_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_interfacemgr_shutdown
parameter_list|(
name|ns_interfacemgr_t
modifier|*
name|mgr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_interfacemgr_scan
parameter_list|(
name|ns_interfacemgr_t
modifier|*
name|mgr
parameter_list|,
name|isc_boolean_t
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Scan the operatings system's list of network interfaces  * and create listeners when new interfaces are discovered.  * Shut down the sockets for interfaces that go away.  *  * This should be called once on server startup and then  * periodically according to the 'interface-interval' option  * in named.conf.  */
end_comment

begin_function_decl
name|void
name|ns_interfacemgr_adjust
parameter_list|(
name|ns_interfacemgr_t
modifier|*
name|mgr
parameter_list|,
name|ns_listenlist_t
modifier|*
name|list
parameter_list|,
name|isc_boolean_t
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Similar to ns_interfacemgr_scan(), but this function also tries to see the  * need for an explicit listen-on when a list element in 'list' is going to  * override an already-listening a wildcard interface.  *  * This function does not update localhost and localnets ACLs.  *  * This should be called once on server startup, after configuring views and  * zones.  */
end_comment

begin_function_decl
name|void
name|ns_interfacemgr_setlistenon4
parameter_list|(
name|ns_interfacemgr_t
modifier|*
name|mgr
parameter_list|,
name|ns_listenlist_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the IPv4 "listen-on" list of 'mgr' to 'value'.  * The previous IPv4 listen-on list is freed.  */
end_comment

begin_function_decl
name|void
name|ns_interfacemgr_setlistenon6
parameter_list|(
name|ns_interfacemgr_t
modifier|*
name|mgr
parameter_list|,
name|ns_listenlist_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the IPv6 "listen-on" list of 'mgr' to 'value'.  * The previous IPv6 listen-on list is freed.  */
end_comment

begin_function_decl
name|dns_aclenv_t
modifier|*
name|ns_interfacemgr_getaclenv
parameter_list|(
name|ns_interfacemgr_t
modifier|*
name|mgr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_interface_attach
parameter_list|(
name|ns_interface_t
modifier|*
name|source
parameter_list|,
name|ns_interface_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_interface_detach
parameter_list|(
name|ns_interface_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_interface_shutdown
parameter_list|(
name|ns_interface_t
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Stop listening for queries on interface 'ifp'.  * May safely be called multiple times.  */
end_comment

begin_function_decl
name|void
name|ns_interfacemgr_dumprecursing
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|ns_interfacemgr_t
modifier|*
name|mgr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_INTERFACEMGR_H */
end_comment

end_unit

