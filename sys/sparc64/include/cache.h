begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996  * 	The President and Fellows of Harvard College. All rights reserved.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Aaron Brown and  *	Harvard University.  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)cache.h	8.1 (Berkeley) 6/11/93  *	from: NetBSD: cache.h,v 1.3 2000/08/01 00:28:02 eeh Exp  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_comment
comment|/*  * Cache diagnostic access definitions.  */
end_comment

begin_comment
comment|/* ASI offsets for I$ diagnostic access */
end_comment

begin_define
define|#
directive|define
name|ICDA_SET_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|ICDA_SET_MASK
value|(1UL<< ICDA_SET_SHIFT)
end_define

begin_define
define|#
directive|define
name|ICDA_SET
parameter_list|(
name|a
parameter_list|)
value|(((a)<< ICDA_SET_SHIFT)& ICDA_SET_MASK)
end_define

begin_comment
comment|/* I$ tag/valid format */
end_comment

begin_define
define|#
directive|define
name|ICDT_TAG_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ICDT_TAG_BITS
value|28
end_define

begin_define
define|#
directive|define
name|ICDT_TAG_MASK
value|(((1UL<< ICDT_TAG_BITS) - 1)<< ICDT_TAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|ICDT_TAG
parameter_list|(
name|x
parameter_list|)
value|(((x)& ICDT_TAG_MASK)>> ICDT_TAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|ICDT_VALID
value|(1UL<< 36)
end_define

begin_comment
comment|/* D$ tag/valid format */
end_comment

begin_define
define|#
directive|define
name|DCDT_TAG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|DCDT_TAG_BITS
value|28
end_define

begin_define
define|#
directive|define
name|DCDT_TAG_MASK
value|(((1UL<< DCDT_TAG_BITS) - 1)<< DCDT_TAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCDT_TAG
parameter_list|(
name|x
parameter_list|)
value|(((x)& DCDT_TAG_MASK)>> DCDT_TAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCDT_VALID_BITS
value|2
end_define

begin_define
define|#
directive|define
name|DCDT_VALID_MASK
value|((1UL<< DCDT_VALID_BITS) - 1)
end_define

begin_comment
comment|/* E$ ASI_ECACHE_W/ASI_ECACHE_R address flags */
end_comment

begin_define
define|#
directive|define
name|ECDA_DATA
value|(1UL<< 39)
end_define

begin_define
define|#
directive|define
name|ECDA_TAG
value|(1UL<< 40)
end_define

begin_comment
comment|/* E$ tag/state/parity format */
end_comment

begin_define
define|#
directive|define
name|ECDT_TAG_BITS
value|13
end_define

begin_define
define|#
directive|define
name|ECDT_TAG_SIZE
value|(1UL<< ECDT_TAG_BITS)
end_define

begin_define
define|#
directive|define
name|ECDT_TAG_MASK
value|(ECDT_TAG_SIZE - 1)
end_define

begin_comment
comment|/*  * Do two virtual addresses (at which the same page is mapped) form and illegal  * alias in D$? XXX: should use cache.dc_size here.  */
end_comment

begin_define
define|#
directive|define
name|DCACHE_BOUNDARY
value|0x4000
end_define

begin_define
define|#
directive|define
name|DCACHE_BMASK
value|(DCACHE_BOUNDARY - 1)
end_define

begin_define
define|#
directive|define
name|CACHE_BADALIAS
parameter_list|(
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|(((v1)& DCACHE_BMASK) != ((v2)& DCACHE_BMASK))
end_define

begin_comment
comment|/*  * Routines for dealing with the cache.  */
end_comment

begin_function_decl
name|void
name|cache_init
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* turn it on */
end_comment

begin_function_decl
name|void
name|icache_flush
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|icache_inval_phys
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dcache_flush
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dcache_inval
parameter_list|(
name|pmap_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dcache_inval_phys
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dcache_blast
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecache_flush
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void	ecache_inval_phys(vm_offset_t, vm_offset_t);
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Cache control information.  */
end_comment

begin_struct
struct|struct
name|cacheinfo
block|{
name|int
name|c_enabled
decl_stmt|;
comment|/* true => cache is enabled */
name|int
name|ic_size
decl_stmt|;
comment|/* instruction cache */
name|int
name|ic_set
decl_stmt|;
name|int
name|ic_l2set
decl_stmt|;
name|int
name|ic_assoc
decl_stmt|;
name|int
name|ic_linesize
decl_stmt|;
name|int
name|dc_size
decl_stmt|;
comment|/* data cache */
name|int
name|dc_l2size
decl_stmt|;
name|int
name|dc_assoc
decl_stmt|;
name|int
name|dc_linesize
decl_stmt|;
name|int
name|ec_size
decl_stmt|;
comment|/* external cache info */
name|int
name|ec_assoc
decl_stmt|;
name|int
name|ec_l2set
decl_stmt|;
name|int
name|ec_linesize
decl_stmt|;
name|int
name|ec_l2linesize
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CACHE_H_ */
end_comment

end_unit

