begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  * NETLOGIC_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_MIPS_EXTNS_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_MIPS_EXTNS_H__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_function
specifier|static
name|__inline__
name|int32_t
name|nlm_swapw
parameter_list|(
name|int32_t
modifier|*
name|loc
parameter_list|,
name|int32_t
name|val
parameter_list|)
block|{
name|int32_t
name|oldval
init|=
literal|0
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		".set push\n" 		".set noreorder\n" 		"move $9, %2\n" 		"move $8, %3\n" 		".word 0x71280014\n"
comment|/* "swapw $8, $9\n" */
asm|"move %1, $8\n" 		".set pop\n" 		: "+m" (*loc), "=r" (oldval) 		: "r" (loc), "r" (val) 		: "$8", "$9" );
return|return
name|oldval
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint32_t
name|nlm_swapwu
parameter_list|(
name|int32_t
modifier|*
name|loc
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|oldval
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		".set push\n" 		".set noreorder\n" 		"move $9, %2\n" 		"move $8, %3\n" 		".word 0x71280015\n"
comment|/* "swapwu $8, $9\n" */
asm|"move %1, $8\n" 		".set pop\n" 		: "+m" (*loc), "=r" (oldval) 		: "r" (loc), "r" (val) 		: "$8", "$9" );
return|return
name|oldval
return|;
block|}
end_function

begin_if
if|#
directive|if
operator|(
name|__mips
operator|==
literal|64
operator|)
end_if

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_swapd
parameter_list|(
name|int32_t
modifier|*
name|loc
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|oldval
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		".set push\n" 		".set noreorder\n" 		"move $9, %2\n" 		"move $8, %3\n" 		".word 0x71280014\n"
comment|/* "swapw $8, $9\n" */
asm|"move %1, $8\n" 		".set pop\n" 		: "+m" (*loc), "=r" (oldval) 		: "r" (loc), "r" (val) 		: "$8", "$9" );
return|return
name|oldval
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|uint64_t
name|nlm_mfcr
parameter_list|(
name|uint32_t
name|reg
parameter_list|)
block|{
name|uint64_t
name|res
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push\n\t" 	    ".set	noreorder\n\t" 	    "move	$9, %1\n\t" 	    ".word	0x71280018\n\t"
comment|/* mfcr $8, $9 */
asm|"move	%0, $8\n\t" 	    ".set	pop\n" 	    : "=r" (res) : "r"(reg) 	    : "$8", "$9" 	);
return|return
operator|(
name|res
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|nlm_mtcr
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push\n\t" 	    ".set	noreorder\n\t" 	    "move	$8, %0\n" 	    "move	$9, %1\n" 	    ".word	0x71280019\n"
comment|/* mtcr $8, $9  */
asm|".set	pop\n" 	    : 	    : "r" (value), "r" (reg) 	    : "$8", "$9" 	);
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !(defined(__mips_n64) || defined(__mips_n32)) */
end_comment

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_mfcr
parameter_list|(
name|uint32_t
name|reg
parameter_list|)
block|{
name|uint64_t
name|hi
decl_stmt|;
name|uint64_t
name|lo
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(                 ".set push\n"                 ".set mips64\n"                 "move   $8, %2\n"                 ".word  0x71090018\n" 		"nop	\n"                 "dsra32 %0, $9, 0\n"                 "sll    %1, $9, 0\n"                 ".set pop\n"                 : "=r"(hi), "=r"(lo)                 : "r"(reg) : "$8", "$9");
return|return
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|hi
operator|)
operator|<<
literal|32
operator|)
operator||
name|lo
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_mtcr
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint32_t
name|hi
decl_stmt|,
name|lo
decl_stmt|;
name|hi
operator|=
name|val
operator|>>
literal|32
expr_stmt|;
name|lo
operator|=
name|val
operator|&
literal|0xffffffff
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|(                 ".set push\n"                 ".set mips64\n"                 "move   $9, %0\n"                 "dsll32 $9, %1, 0\n"                 "dsll32 $8, %0, 0\n"                 "dsrl32 $9, $9, 0\n"                 "or     $9, $9, $8\n"                 "move   $8, %2\n"                 ".word  0x71090019\n" 		"nop	\n"                 ".set pop\n"                 ::"r"(hi), "r"(lo), "r"(reg)                 : "$8", "$9");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(__mips_n64) || defined(__mips_n32)) */
end_comment

begin_comment
comment|/* dcrc2 */
end_comment

begin_comment
comment|/* XLP additional instructions */
end_comment

begin_comment
comment|/*  * Atomic increment a unsigned  int  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|nlm_ldaddwu
parameter_list|(
name|unsigned
name|int
name|value
parameter_list|,
name|unsigned
name|int
modifier|*
name|addr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push\n" 	    ".set	noreorder\n" 	    "move	$8, %2\n" 	    "move	$9, %3\n" 	    ".word	0x71280011\n"
comment|/* ldaddwu $8, $9 */
asm|"move	%0, $8\n" 	    ".set	pop\n" 	    : "=&r"(value), "+m"(*addr) 	    : "0"(value), "r" ((unsigned long)addr) 	    :  "$8", "$9");
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

