begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995, 1999  *	Berkeley Software Design, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * THIS SOFTWARE IS PROVIDED BY Berkeley Software Design, Inc. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Berkeley Software Design, Inc. BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	BSDI ifaddrs.h,v 2.5 2000/02/23 14:51:59 dab Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IFADDRS_H_
end_ifndef

begin_define
define|#
directive|define
name|_IFADDRS_H_
end_define

begin_struct
struct|struct
name|ifaddrs
block|{
name|struct
name|ifaddrs
modifier|*
name|ifa_next
decl_stmt|;
name|char
modifier|*
name|ifa_name
decl_stmt|;
name|u_int
name|ifa_flags
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|ifa_addr
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|ifa_netmask
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|ifa_dstaddr
decl_stmt|;
name|void
modifier|*
name|ifa_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This may have been defined in<net/if.h>.  Note that if<net/if.h> is  * to be included it must be included before this header file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ifa_broadaddr
end_ifndef

begin_define
define|#
directive|define
name|ifa_broadaddr
value|ifa_dstaddr
end_define

begin_comment
comment|/* broadcast address interface */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|getifaddrs
parameter_list|(
name|struct
name|ifaddrs
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|freeifaddrs
parameter_list|(
name|struct
name|ifaddrs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

