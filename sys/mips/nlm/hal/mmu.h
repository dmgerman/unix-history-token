begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XLP_MMU_H__
end_ifndef

begin_define
define|#
directive|define
name|__XLP_MMU_H__
end_define

begin_include
include|#
directive|include
file|<mips/nlm/hal/mips-extns.h>
end_include

begin_function
specifier|static
name|__inline__
name|uint32_t
name|nlm_read_c0_config6
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|rv
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		".set	push\n" 		".set	mips64\n" 		"mfc0	%0, $16, 6\n" 		".set	pop\n"  		: "=r" (rv));
return|return
name|rv
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_write_c0_config6
parameter_list|(
name|uint32_t
name|value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( 		".set	push\n" 		".set	mips64\n" 		"mtc0	%0, $16, 6\n" 		".set	pop\n"  		: : "r" (value));
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint32_t
name|nlm_read_c0_config7
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|rv
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		".set	push\n" 		".set	mips64\n" 		"mfc0	%0, $16, 7\n" 		".set	pop\n"  		: "=r" (rv));
return|return
name|rv
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_write_c0_config7
parameter_list|(
name|uint32_t
name|value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( 		".set	push\n" 		".set	mips64\n" 		"mtc0	%0, $16, 7\n" 		".set	pop\n"  		: : "r" (value));
block|}
end_function

begin_comment
comment|/**  * On power on reset, XLP comes up with 64 TLBs.  * Large-variable-tlb's (ELVT) and extended TLB is disabled.  * Enabling large-variable-tlb's sets up the standard  * TLB size from 64 to 128 TLBs.  * Enabling fixed TLB (EFT) sets up an additional 2048 tlbs.  * ELVT + EFT = 128 + 2048 = 2176 TLB entries.  * threads  64-entry-standard-tlb    128-entry-standard-tlb  * per      std-tlb-only| std+EFT  | std-tlb-only| std+EFT  * core                 |          |             |  * --------------------------------------------------------  * 1         64           64+2048     128          128+2048  * 2         64           64+1024      64           64+1024  * 4         32           32+512       32           32+512  *  * 1(G)      64           64+2048     128          128+2048  * 2(G)      128         128+2048     128          128+2048  * 4(G)      128         128+2048     128          128+2048  * (G) = Global mode  */
end_comment

begin_comment
comment|/* en = 1 to enable  * en = 0 to disable  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_large_variable_tlb_en
parameter_list|(
name|int
name|en
parameter_list|)
block|{
name|unsigned
name|int
name|val
decl_stmt|;
name|val
operator|=
name|nlm_read_c0_config6
argument_list|()
expr_stmt|;
name|val
operator||=
operator|(
name|en
operator|<<
literal|5
operator|)
expr_stmt|;
name|nlm_write_c0_config6
argument_list|(
name|val
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/* en = 1 to enable  * en = 0 to disable  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_pagewalker_en
parameter_list|(
name|int
name|en
parameter_list|)
block|{
name|unsigned
name|int
name|val
decl_stmt|;
name|val
operator|=
name|nlm_read_c0_config6
argument_list|()
expr_stmt|;
name|val
operator||=
operator|(
name|en
operator|<<
literal|3
operator|)
expr_stmt|;
name|nlm_write_c0_config6
argument_list|(
name|val
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/* en = 1 to enable  * en = 0 to disable  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_extended_tlb_en
parameter_list|(
name|int
name|en
parameter_list|)
block|{
name|unsigned
name|int
name|val
decl_stmt|;
name|val
operator|=
name|nlm_read_c0_config6
argument_list|()
expr_stmt|;
name|val
operator||=
operator|(
name|en
operator|<<
literal|2
operator|)
expr_stmt|;
name|nlm_write_c0_config6
argument_list|(
name|val
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_get_num_combined_tlbs
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|nlm_read_c0_config6
argument_list|()
operator|>>
literal|16
operator|)
operator|&
literal|0xffff
operator|)
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* get number of variable TLB entries */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|nlm_get_num_vtlbs
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|nlm_read_c0_config6
argument_list|()
operator|>>
literal|6
operator|)
operator|&
literal|0x3ff
operator|)
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_setup_extended_pagemask
parameter_list|(
name|int
name|mask
parameter_list|)
block|{
name|nlm_write_c0_config7
argument_list|(
name|mask
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

