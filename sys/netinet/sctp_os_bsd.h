begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
name|__sctp_os_bsd_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctp_os_bsd_h__
end_define

begin_comment
comment|/*  * includes  */
end_comment

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_comment
comment|/*  *  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mbuf
modifier|*
name|sctp_mbuf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USER_ADDR_NULL
value|(NULL)
end_define

begin_comment
comment|/* FIX ME: temp */
end_comment

begin_comment
comment|/*  * general memory allocation  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MALLOC
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|size
parameter_list|,
name|name
parameter_list|)
define|\
value|do { \ 	MALLOC(var, type, size, M_PCB, M_NOWAIT); \     } while (0)
end_define

begin_define
define|#
directive|define
name|SCTP_FREE
parameter_list|(
name|var
parameter_list|)
value|FREE(var, M_PCB)
end_define

begin_define
define|#
directive|define
name|SCTP_MALLOC_SONAME
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|size
parameter_list|)
define|\
value|do { \ 	MALLOC(var, type, size, M_SONAME, M_WAITOK | M_ZERO); \     } while (0)
end_define

begin_define
define|#
directive|define
name|SCTP_FREE_SONAME
parameter_list|(
name|var
parameter_list|)
value|FREE(var, M_SONAME)
end_define

begin_comment
comment|/*  * zone allocation functions  */
end_comment

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_comment
comment|/* SCTP_ZONE_INIT: initialize the zone */
end_comment

begin_typedef
typedef|typedef
name|struct
name|uma_zone
modifier|*
name|sctp_zone_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UMA_ZFLAG_FULL
value|0x0020
end_define

begin_define
define|#
directive|define
name|SCTP_ZONE_INIT
parameter_list|(
name|zone
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|,
name|number
parameter_list|)
value|{ \ 	zone = uma_zcreate(name, size, NULL, NULL, NULL, NULL, UMA_ALIGN_PTR,\ 		UMA_ZFLAG_FULL); \ 	uma_zone_set_max(zone, number); \ }
end_define

begin_comment
comment|/* SCTP_ZONE_GET: allocate element from the zone */
end_comment

begin_define
define|#
directive|define
name|SCTP_ZONE_GET
parameter_list|(
name|zone
parameter_list|)
define|\
value|uma_zalloc(zone, M_NOWAIT);
end_define

begin_comment
comment|/* SCTP_ZONE_FREE: free element from the zone */
end_comment

begin_define
define|#
directive|define
name|SCTP_ZONE_FREE
parameter_list|(
name|zone
parameter_list|,
name|element
parameter_list|)
define|\
value|uma_zfree(zone, element);
end_define

begin_comment
comment|/*  * Functions  */
end_comment

begin_define
define|#
directive|define
name|sctp_read_random
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|)
value|read_random(buf, len)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

