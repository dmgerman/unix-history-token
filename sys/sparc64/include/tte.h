begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: BSDI: pmap.v9.h,v 1.10.2.6 1999/08/23 22:18:44 cp Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TTE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TTE_H_
end_define

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_define
define|#
directive|define
name|TTE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|STTE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|TT_CTX_SHIFT
value|(48)
end_define

begin_define
define|#
directive|define
name|TT_VA_SHIFT
value|(22)
end_define

begin_define
define|#
directive|define
name|TT_VPN_SHIFT
value|(9)
end_define

begin_define
define|#
directive|define
name|TT_CTX_SIZE
value|(13)
end_define

begin_define
define|#
directive|define
name|TT_VA_SIZE
value|(42)
end_define

begin_define
define|#
directive|define
name|TT_CTX_MASK
value|((1L<< TT_CTX_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|TT_VA_MASK
value|((1L<< TT_VA_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|TT_G
value|(1L<< 63)
end_define

begin_define
define|#
directive|define
name|TT_CTX
parameter_list|(
name|ctx
parameter_list|)
value|(((u_long)(ctx)& TT_CTX_MASK)<< TT_CTX_SHIFT)
end_define

begin_define
define|#
directive|define
name|TT_VA
parameter_list|(
name|va
parameter_list|)
value|((u_long)(va)>> TT_VA_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_SIZE_SHIFT
value|(61)
end_define

begin_define
define|#
directive|define
name|TD_SOFT2_SHIFT
value|(50)
end_define

begin_define
define|#
directive|define
name|TD_DIAG_SHIFT
value|(41)
end_define

begin_define
define|#
directive|define
name|TD_PA_SHIFT
value|(13)
end_define

begin_define
define|#
directive|define
name|TD_SOFT_SHIFT
value|(7)
end_define

begin_define
define|#
directive|define
name|TD_SIZE_SIZE
value|(2)
end_define

begin_define
define|#
directive|define
name|TD_SOFT2_SIZE
value|(9)
end_define

begin_define
define|#
directive|define
name|TD_DIAG_SIZE
value|(9)
end_define

begin_define
define|#
directive|define
name|TD_PA_SIZE
value|(28)
end_define

begin_define
define|#
directive|define
name|TD_SOFT_SIZE
value|(6)
end_define

begin_define
define|#
directive|define
name|TD_SIZE_MASK
value|(((1L<< TD_SIZE_SIZE) - 1)<< TD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_SOFT2_MASK
value|(((1L<< TD_SOFT2_SIZE) - 1)<< TD_SOFT2_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_DIAG_MASK
value|(((1L<< TD_DIAG_SIZE) - 1)<< TD_DIAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_PA_MASK
value|(((1L<< TD_PA_SIZE) - 1)<< TD_PA_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_SOFT_MASK
value|(((1L<< TD_SOFT_SIZE) - 1)<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_VA_LOW_SHIFT
value|TD_SOFT2_SHIFT
end_define

begin_define
define|#
directive|define
name|TD_VA_LOW_MASK
value|TD_SOFT2_MASK
end_define

begin_define
define|#
directive|define
name|TS_EXEC
value|(1L<< 4)
end_define

begin_define
define|#
directive|define
name|TS_INIT
value|(1L<< 3)
end_define

begin_define
define|#
directive|define
name|TS_MNG
value|(1L<< 2)
end_define

begin_define
define|#
directive|define
name|TS_REF
value|(1L<< 1)
end_define

begin_define
define|#
directive|define
name|TS_W
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|TD_V
value|(1L<< 63)
end_define

begin_define
define|#
directive|define
name|TD_8K
value|(0L<< TD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_64K
value|(1L<< TD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_512K
value|(2L<< TD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_4M
value|(3L<< TD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_NFO
value|(1L<< 60)
end_define

begin_define
define|#
directive|define
name|TD_IE
value|(1L<< 59)
end_define

begin_define
define|#
directive|define
name|TD_VPN_LOW
parameter_list|(
name|vpn
parameter_list|)
value|((vpn<< TD_SOFT2_SHIFT)& TD_SOFT2_MASK)
end_define

begin_define
define|#
directive|define
name|TD_VA_LOW
parameter_list|(
name|va
parameter_list|)
value|(TD_VPN_LOW((va)>> PAGE_SHIFT))
end_define

begin_define
define|#
directive|define
name|TD_PA
parameter_list|(
name|pa
parameter_list|)
value|((pa)& TD_PA_MASK)
end_define

begin_define
define|#
directive|define
name|TD_EXEC
value|(TS_EXEC<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_INIT
value|(TS_INIT<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_MNG
value|(TS_MNG<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_REF
value|(TS_REF<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_SW
value|(TS_W<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_L
value|(1L<< 6)
end_define

begin_define
define|#
directive|define
name|TD_CP
value|(1L<< 5)
end_define

begin_define
define|#
directive|define
name|TD_CV
value|(1L<< 4)
end_define

begin_define
define|#
directive|define
name|TD_E
value|(1L<< 3)
end_define

begin_define
define|#
directive|define
name|TD_P
value|(1L<< 2)
end_define

begin_define
define|#
directive|define
name|TD_W
value|(1L<< 1)
end_define

begin_define
define|#
directive|define
name|TD_G
value|(1L<< 0)
end_define

begin_struct
struct|struct
name|tte
block|{
name|u_long
name|tte_tag
decl_stmt|;
name|u_long
name|tte_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|stte
block|{
name|struct
name|tte
name|st_tte
decl_stmt|;
name|vm_offset_t
name|st_next
decl_stmt|;
name|vm_offset_t
name|st_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|u_int
name|tte_get_ctx
parameter_list|(
name|struct
name|tte
name|tte
parameter_list|)
block|{
return|return
operator|(
operator|(
name|tte
operator|.
name|tte_tag
operator|>>
name|TT_CTX_SHIFT
operator|)
operator|&
name|TT_CTX_MASK
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|vm_offset_t
name|tte_get_vpn
parameter_list|(
name|struct
name|tte
name|tte
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|tte
operator|.
name|tte_tag
operator|&
name|TT_VA_MASK
operator|)
operator|<<
name|TT_VPN_SHIFT
operator|)
operator||
operator|(
operator|(
name|tte
operator|.
name|tte_data
operator|&
name|TD_VA_LOW_MASK
operator|)
operator|>>
name|TD_VA_LOW_SHIFT
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|vm_offset_t
name|tte_get_va
parameter_list|(
name|struct
name|tte
name|tte
parameter_list|)
block|{
return|return
operator|(
name|tte_get_vpn
argument_list|(
name|tte
argument_list|)
operator|<<
name|PAGE_SHIFT
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|tte_invalidate
parameter_list|(
name|struct
name|tte
modifier|*
name|tp
parameter_list|)
block|{
name|atomic_clear_long
argument_list|(
operator|&
name|tp
operator|->
name|tte_data
argument_list|,
name|TD_V
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|tte_match
parameter_list|(
name|struct
name|tte
name|tte
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
block|{
return|return
operator|(
operator|(
name|tte
operator|.
name|tte_data
operator|&
name|TD_V
operator|)
operator|!=
literal|0
operator|&&
operator|(
operator|(
name|tte
operator|.
name|tte_tag
operator|^
name|TT_VA
argument_list|(
name|va
argument_list|)
operator|)
operator|&
name|TT_VA_MASK
operator|)
operator|==
literal|0
operator|&&
operator|(
operator|(
name|tte
operator|.
name|tte_data
operator|^
name|TD_VA_LOW
argument_list|(
name|va
argument_list|)
operator|)
operator|&
name|TD_VA_LOW_MASK
operator|)
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_TTE_H_ */
end_comment

end_unit

