begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007, 2008  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: os.h,v 1.29 2008-10-24 01:44:48 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NS_OS_H
end_ifndef

begin_define
define|#
directive|define
name|NS_OS_H
value|1
end_define

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_function_decl
name|void
name|ns_os_init
parameter_list|(
specifier|const
name|char
modifier|*
name|progname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_daemonize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_opendevnull
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_closedevnull
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_chroot
parameter_list|(
specifier|const
name|char
modifier|*
name|root
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_inituserinfo
parameter_list|(
specifier|const
name|char
modifier|*
name|username
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_changeuser
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_adjustnofile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_minprivs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_writepidfile
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|isc_boolean_t
name|first_time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|ns_os_gethostname
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_shutdownmsg
parameter_list|(
name|char
modifier|*
name|command
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_tzset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_os_started
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NS_OS_H */
end_comment

end_unit

