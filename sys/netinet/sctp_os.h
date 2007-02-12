begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2007, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__sctp_os_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctp_os_h__
end_define

begin_comment
comment|/*  * General kernel memory allocation:  *  SCTP_MALLOC(element, type, size, name)  *  SCTP_FREE(element)  * Kernel memory allocation for "soname"- memory must be zeroed.  *  SCTP_MALLOC_SONAME(name, type, size)  *  SCTP_FREE_SONAME(name)  */
end_comment

begin_comment
comment|/*  * Zone(pool) allocation routines: MUST be defined for each OS.  *  zone = zone/pool pointer.  *  name = string name of the zone/pool.  *  size = size of each zone/pool element.  *  number = number of elements in zone/pool.  *  type = structure type to allocate  *  * sctp_zone_t  * SCTP_ZONE_INIT(zone, name, size, number)  * SCTP_ZONE_GET(zone, type)  * SCTP_ZONE_FREE(zone, element)  * SCTP_ZONE_DESTROY(zone)  */
end_comment

begin_include
include|#
directive|include
file|<netinet/sctp_os_bsd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

