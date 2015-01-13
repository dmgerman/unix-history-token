begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2013 Mark R. V. Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RANDOM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_RANDOM_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|read_random
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Note: if you add or remove members of random_entropy_source, remember to also update the  * KASSERT regarding what valid members are in random_harvest_internal(), and remember the  * strings in the static array random_source_descr[] in random_harvestq.c.  *  * NOTE: complain loudly to markm@ or on the lists if this enum gets more than 32  * distinct values (0-31)! ENTROPYSOURCE may be == 32, but not> 32.  */
end_comment

begin_enum
enum|enum
name|random_entropy_source
block|{
name|RANDOM_START
init|=
literal|0
block|,
name|RANDOM_CACHED
init|=
literal|0
block|,
comment|/* Environmental sources */
name|RANDOM_ATTACH
block|,
name|RANDOM_KEYBOARD
block|,
name|RANDOM_MOUSE
block|,
name|RANDOM_NET_TUN
block|,
name|RANDOM_NET_ETHER
block|,
name|RANDOM_NET_NG
block|,
name|RANDOM_INTERRUPT
block|,
name|RANDOM_SWI
block|,
name|RANDOM_UMA_ALLOC
block|,
name|RANDOM_ENVIRONMENTAL_END
block|,
comment|/* This one is wasted */
comment|/* High-quality HW RNGs from here on. */
name|RANDOM_PURE_OCTEON
block|,
name|RANDOM_PURE_SAFE
block|,
name|RANDOM_PURE_GLXSB
block|,
name|RANDOM_PURE_UBSEC
block|,
name|RANDOM_PURE_HIFN
block|,
name|RANDOM_PURE_RDRAND
block|,
name|RANDOM_PURE_NEHEMIAH
block|,
name|RANDOM_PURE_RNDTEST
block|,
name|RANDOM_PURE_VIRTIO
block|,
name|ENTROPYSOURCE
block|}
enum|;
end_enum

begin_function_decl
name|void
name|random_harvest
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|random_entropy_source
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_RANDOM_H_ */
end_comment

end_unit

