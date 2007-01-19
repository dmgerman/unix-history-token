begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996  * 	The President and Fellows of Harvard College. All rights reserved.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Aaron Brown and  *	Harvard University.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)cache.h	8.1 (Berkeley) 6/11/93  *	from: NetBSD: cache.h,v 1.3 2000/08/01 00:28:02 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CACHE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CACHE_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DCACHE_COLOR_BITS
value|(1)
end_define

begin_define
define|#
directive|define
name|DCACHE_COLORS
value|(1<< DCACHE_COLOR_BITS)
end_define

begin_define
define|#
directive|define
name|DCACHE_COLOR_MASK
value|(DCACHE_COLORS - 1)
end_define

begin_define
define|#
directive|define
name|DCACHE_COLOR
parameter_list|(
name|va
parameter_list|)
value|(((va)>> PAGE_SHIFT)& DCACHE_COLOR_MASK)
end_define

begin_define
define|#
directive|define
name|DCACHE_OTHER_COLOR
parameter_list|(
name|color
parameter_list|)
define|\
value|((color) ^ DCACHE_COLOR_BITS)
end_define

begin_define
define|#
directive|define
name|DC_TAG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|DC_VALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DC_TAG_BITS
value|28
end_define

begin_define
define|#
directive|define
name|DC_VALID_BITS
value|2
end_define

begin_define
define|#
directive|define
name|DC_TAG_MASK
value|((1<< DC_TAG_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|DC_VALID_MASK
value|((1<< DC_VALID_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|IC_TAG_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|IC_VALID_SHIFT
value|36
end_define

begin_define
define|#
directive|define
name|IC_TAG_BITS
value|28
end_define

begin_define
define|#
directive|define
name|IC_VALID_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IC_TAG_MASK
value|((1<< IC_TAG_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|IC_VALID_MASK
value|((1<< IC_VALID_BITS) - 1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Cache control information.  */
end_comment

begin_struct
struct|struct
name|cacheinfo
block|{
name|u_int
name|c_enabled
decl_stmt|;
comment|/* true => cache is enabled */
name|u_int
name|ic_size
decl_stmt|;
comment|/* instruction cache */
name|u_int
name|ic_set
decl_stmt|;
name|u_int
name|ic_l2set
decl_stmt|;
name|u_int
name|ic_assoc
decl_stmt|;
name|u_int
name|ic_linesize
decl_stmt|;
name|u_int
name|dc_size
decl_stmt|;
comment|/* data cache */
name|u_int
name|dc_l2size
decl_stmt|;
name|u_int
name|dc_assoc
decl_stmt|;
name|u_int
name|dc_linesize
decl_stmt|;
name|u_int
name|ec_size
decl_stmt|;
comment|/* external cache info */
name|u_int
name|ec_assoc
decl_stmt|;
name|u_int
name|ec_l2set
decl_stmt|;
name|u_int
name|ec_linesize
decl_stmt|;
name|u_int
name|ec_l2linesize
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|void
name|cache_enable_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|cache_flush_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|dcache_page_inval_t
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|icache_page_inval_t
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|cache_init
parameter_list|(
name|phandle_t
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|cache_enable_t
name|cheetah_cache_enable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|cache_flush_t
name|cheetah_cache_flush
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dcache_page_inval_t
name|cheetah_dcache_page_inval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|icache_page_inval_t
name|cheetah_icache_page_inval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|cache_enable_t
name|spitfire_cache_enable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|cache_flush_t
name|spitfire_cache_flush
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dcache_page_inval_t
name|spitfire_dcache_page_inval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|icache_page_inval_t
name|spitfire_icache_page_inval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cache_enable_t
modifier|*
name|cache_enable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cache_flush_t
modifier|*
name|cache_flush
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dcache_page_inval_t
modifier|*
name|dcache_page_inval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|icache_page_inval_t
modifier|*
name|icache_page_inval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cacheinfo
name|cache
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CACHE_H_ */
end_comment

end_unit

