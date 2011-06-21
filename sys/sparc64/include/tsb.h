begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: BSDI: pmap.v9.h,v 1.10.2.6 1999/08/23 22:18:44 cp Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TSB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TSB_H_
end_define

begin_define
define|#
directive|define
name|TSB_PAGES_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|TSB_PAGES
value|(1<< TSB_PAGES_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSB_BSHIFT
value|(TSB_PAGES_SHIFT + PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSB_BSIZE
value|(1<< TSB_BSHIFT)
end_define

begin_define
define|#
directive|define
name|TSB_BUCKET_SHIFT
value|(2)
end_define

begin_define
define|#
directive|define
name|TSB_BUCKET_SIZE
value|(1<< TSB_BUCKET_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSB_BUCKET_ADDRESS_BITS
define|\
value|(TSB_BSHIFT - TSB_BUCKET_SHIFT - TTE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSB_BUCKET_MASK
value|((1<< TSB_BUCKET_ADDRESS_BITS) - 1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_define
define|#
directive|define
name|TSB_SIZE
value|(TSB_BSIZE / sizeof(struct tte))
end_define

begin_decl_stmt
specifier|extern
name|struct
name|tte
modifier|*
name|tsb_kernel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_size_t
name|tsb_kernel_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_size_t
name|tsb_kernel_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|tsb_kernel_phys
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|tte
operator|*
name|tsb_vpntobucket
argument_list|(
argument|pmap_t pm
argument_list|,
argument|vm_offset_t vpn
argument_list|)
block|{
return|return
operator|(
operator|&
name|pm
operator|->
name|pm_tsb
index|[
operator|(
name|vpn
operator|&
name|TSB_BUCKET_MASK
operator|)
operator|<<
name|TSB_BUCKET_SHIFT
index|]
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|tte
operator|*
name|tsb_vtobucket
argument_list|(
argument|pmap_t pm
argument_list|,
argument|u_long sz
argument_list|,
argument|vm_offset_t va
argument_list|)
block|{
return|return
operator|(
name|tsb_vpntobucket
argument_list|(
name|pm
argument_list|,
name|va
operator|>>
name|TTE_PAGE_SHIFT
argument_list|(
name|sz
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|tte
operator|*
name|tsb_kvpntotte
argument_list|(
argument|vm_offset_t vpn
argument_list|)
block|{
return|return
operator|(
operator|&
name|tsb_kernel
index|[
name|vpn
operator|&
name|tsb_kernel_mask
index|]
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|tte
operator|*
name|tsb_kvtotte
argument_list|(
argument|vm_offset_t va
argument_list|)
block|{
return|return
operator|(
name|tsb_kvpntotte
argument_list|(
name|va
operator|>>
name|PAGE_SHIFT
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|int
function_decl|(
name|tsb_callback_t
function_decl|)
parameter_list|(
name|struct
name|pmap
modifier|*
parameter_list|,
name|struct
name|pmap
modifier|*
parameter_list|,
name|struct
name|tte
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|struct
name|tte
modifier|*
name|tsb_tte_lookup
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsb_tte_remove
parameter_list|(
name|struct
name|tte
modifier|*
name|stp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tte
modifier|*
name|tsb_tte_enter
parameter_list|(
name|pmap_t
name|pm
parameter_list|,
name|vm_page_t
name|m
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|u_long
name|sz
parameter_list|,
name|u_long
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsb_tte_local_remove
parameter_list|(
name|struct
name|tte
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsb_foreach
parameter_list|(
name|pmap_t
name|pm1
parameter_list|,
name|pmap_t
name|pm2
parameter_list|,
name|vm_offset_t
name|start
parameter_list|,
name|vm_offset_t
name|end
parameter_list|,
name|tsb_callback_t
modifier|*
name|callback
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_MACHINE_TSB_H_ */
end_comment

end_unit

