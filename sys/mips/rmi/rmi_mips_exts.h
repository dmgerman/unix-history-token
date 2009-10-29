begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MIPS_EXTS_H__
end_ifndef

begin_define
define|#
directive|define
name|__MIPS_EXTS_H__
end_define

begin_define
define|#
directive|define
name|enable_KX
parameter_list|(
name|flags
parameter_list|)
value|__asm__ __volatile__ (          \ 		".set push\n"              \ 		".set noat\n"               \ 		".set noreorder\n"     \ 		"mfc0 %0, $12\n\t"             \ 		"ori $1, %0, 0x81\n\t"   \ 		"xori $1, 1\n\t"      \ 		"mtc0 $1, $12\n"       \ 		".set pop\n"          \ 		: "=r"(flags) )
end_define

begin_define
define|#
directive|define
name|disable_KX
parameter_list|(
name|flags
parameter_list|)
value|__asm__ __volatile__ (          \ 		".set push\n"              \ 		"mtc0 %0, $12\n"       \ 		".set pop\n"          \ 		: : "r"(flags) )
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_IFU
value|0
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_ICU
value|1
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_IEU
value|2
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_LSU
value|3
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_MMU
value|4
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_PRF
value|5
end_define

begin_define
define|#
directive|define
name|LSU_CERRLOG_REGID
value|9
end_define

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|read_32bit_phnx_ctrl_reg
parameter_list|(
name|int
name|block
parameter_list|,
name|int
name|reg
parameter_list|)
block|{
name|unsigned
name|int
name|__res
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(                                    			".set\tpush\n\t"                             			".set\tnoreorder\n\t"  			"move $9, %1\n"
comment|/* "mfcr\t$8, $9\n\t"          */
asm|".word 0x71280018\n" 			"move %0, $8\n" 			".set\tpop"        			: "=r" (__res) : "r"((block<<8)|reg) 			: "$8", "$9" 			);
return|return
name|__res
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|write_32bit_phnx_ctrl_reg
parameter_list|(
name|int
name|block
parameter_list|,
name|int
name|reg
parameter_list|,
name|unsigned
name|int
name|value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(             			".set\tpush\n\t" 			".set\tnoreorder\n\t" 			"move $8, %0\n" 			"move $9, %1\n"
comment|/* "mtcr\t$8, $9\n\t"  */
asm|".word 0x71280019\n" 			".set\tpop" 			: 			: "r" (value), "r"((block<<8)|reg) 			: "$8", "$9" 			);
block|}
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|read_64bit_phnx_ctrl_reg
parameter_list|(
name|int
name|block
parameter_list|,
name|int
name|reg
parameter_list|)
block|{
name|unsigned
name|int
name|high
decl_stmt|,
name|low
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(					 		".set\tmips64\n\t"				 		"move    $9, %2\n"
comment|/* "mfcr    $8, $9\n" */
asm|".word   0x71280018\n" 		"dsrl32  %0, $8, 0\n\t"			         		"dsll32  $8, $8, 0\n\t"                          		"dsrl32  %1, $8, 0\n\t"                          		".set mips0"					 		: "=r" (high), "=r"(low) 		: "r"((block<<8)|reg) 		: "$8", "$9" 		);
return|return
operator|(
operator|(
operator|(
operator|(
name|unsigned
name|long
name|long
operator|)
name|high
operator|)
operator|<<
literal|32
operator|)
operator||
name|low
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|write_64bit_phnx_ctrl_reg
parameter_list|(
name|int
name|block
parameter_list|,
name|int
name|reg
parameter_list|,
name|unsigned
name|long
name|long
name|value
parameter_list|)
block|{
name|__uint32_t
name|low
decl_stmt|,
name|high
decl_stmt|;
name|high
operator|=
name|value
operator|>>
literal|32
expr_stmt|;
name|low
operator|=
name|value
operator|&
literal|0xffffffff
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		".set push\n" 		".set noreorder\n" 		".set mips4\n\t"
comment|/* Set up "rs" */
asm|"move $9, %0\n"
comment|/* Store 64 bit value in "rt" */
asm|"dsll32 $10, %1, 0  \n\t" 		"dsll32 $8, %2, 0  \n\t" 		"dsrl32 $8, $8, 0  \n\t" 		"or     $10, $8, $8 \n\t"  		".word 0x71280019\n"
comment|/* mtcr $8, $9 */
asm|".set pop\n"  		:
comment|/* No outputs */
asm|: "r"((block<<8)|reg), "r" (high), "r" (low) 		: "$8", "$9", "$10" 		);
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

