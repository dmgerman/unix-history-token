begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Paul Kranenburg.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: NetBSD: sbusvar.h,v 1.12 2001/09/24 23:49:34 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_SBUS_OFW_SBUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_SBUS_OFW_SBUS_H_
end_define

begin_comment
comment|/* Device register space description */
end_comment

begin_struct
struct|struct
name|sbus_regs
block|{
name|u_int32_t
name|sbr_slot
decl_stmt|;
name|u_int32_t
name|sbr_offset
decl_stmt|;
name|u_int32_t
name|sbr_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Address translation accross busses */
end_comment

begin_struct
struct|struct
name|sbus_ranges
block|{
name|u_int32_t
name|cspace
decl_stmt|;
comment|/* Client space */
name|u_int32_t
name|coffset
decl_stmt|;
comment|/* Client offset */
name|u_int32_t
name|pspace
decl_stmt|;
comment|/* Parent space */
name|u_int32_t
name|poffset
decl_stmt|;
comment|/* Parent offset */
name|u_int32_t
name|size
decl_stmt|;
comment|/* Size in bytes of this range */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SPARC64_SBUS_OFW_SBUS_H_ */
end_comment

end_unit

