begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/alpha/include/ucontext.h,v 1.3 1999/10/08  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_UCONTEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_UCONTEXT_H_
end_define

begin_struct
struct|struct
name|__mcontext
block|{
name|uint64_t
name|mc_global
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|mc_out
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|mc_local
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|mc_in
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|mc_fp
index|[
literal|64
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|64
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|__mcontext
name|mcontext_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|mc_flags
value|mc_global[0]
end_define

begin_define
define|#
directive|define
name|mc_sp
value|mc_out[6]
end_define

begin_define
define|#
directive|define
name|mc_fprs
value|mc_local[0]
end_define

begin_define
define|#
directive|define
name|mc_fsr
value|mc_local[1]
end_define

begin_define
define|#
directive|define
name|mc_gsr
value|mc_local[2]
end_define

begin_define
define|#
directive|define
name|mc_tnpc
value|mc_in[0]
end_define

begin_define
define|#
directive|define
name|mc_tpc
value|mc_in[1]
end_define

begin_define
define|#
directive|define
name|mc_tstate
value|mc_in[2]
end_define

begin_define
define|#
directive|define
name|mc_y
value|mc_in[4]
end_define

begin_define
define|#
directive|define
name|mc_wstate
value|mc_in[5]
end_define

begin_define
define|#
directive|define
name|_MC_VERSION_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|_MC_VERSION_BITS
value|32
end_define

begin_define
define|#
directive|define
name|_MC_VERSION
value|1L
end_define

begin_define
define|#
directive|define
name|_MC_FLAGS_SHIFT
value|32
end_define

begin_define
define|#
directive|define
name|_MC_FLAGS_BITS
value|32
end_define

begin_define
define|#
directive|define
name|_MC_VOLUNTARY
value|((1L<< 0)<< _MC_FLAGS_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_UCONTEXT_H_ */
end_comment

end_unit

