begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2017, Intel Corporation   All rights reserved.    Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions are met:     1. Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.     2. Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.     3. Neither the name of the Intel Corporation nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXV_NETMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXV_NETMAP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_NETMAP
end_ifdef

begin_include
include|#
directive|include
file|<net/netmap.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<dev/netmap/netmap_kern.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|ixv_crcstrip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ixgbe_netmap.c contains functions for netmap  * support that extend the standard driver.  See additional  * comments in ixgbe_netmap.c.  */
end_comment

begin_function_decl
name|void
name|ixv_netmap_attach
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ixv_netmap_attach
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|netmap_detach
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_NETMAP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXV_NETMAP_H_ */
end_comment

end_unit

