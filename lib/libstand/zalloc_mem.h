begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This module derived from code donated to the FreeBSD Project by   * Matthew Dillon<dillon@backplane.com>  *  * Copyright (c) 1998 The FreeBSD Project  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * H/MEM.H  *  * Basic memory pool / memory node structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|MemNode
block|{
name|struct
name|MemNode
modifier|*
name|mr_Next
decl_stmt|;
name|iaddr_t
name|mr_Bytes
decl_stmt|;
block|}
name|MemNode
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|MemPool
block|{
name|void
modifier|*
name|mp_Base
decl_stmt|;
name|void
modifier|*
name|mp_End
decl_stmt|;
name|MemNode
modifier|*
name|mp_First
decl_stmt|;
name|iaddr_t
name|mp_Size
decl_stmt|;
name|iaddr_t
name|mp_Used
decl_stmt|;
block|}
name|MemPool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MEMNODE_SIZE_MASK
value|((sizeof(MemNode)<= 8) ? 7 : 15)
end_define

begin_define
define|#
directive|define
name|ZNOTE_FREE
value|0
end_define

begin_define
define|#
directive|define
name|ZNOTE_REUSE
value|1
end_define

end_unit

