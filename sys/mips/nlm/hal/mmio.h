begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  * NETLOGIC_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_NLMIO_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_NLMIO_H__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_comment
comment|/*  * For o32 compilation, we have to disable interrupts and enable KX bit to  * access 64 bit addresses or data.  *  * We need to disable interrupts because we save just the lower 32 bits of  * registers in  interrupt handling. So if we get hit by an interrupt while  * using the upper 32 bits of a register, we lose.  */
end_comment

begin_function
specifier|static
name|__inline__
name|uint32_t
name|nlm_enable_kx
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|sr
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    "mfc0	%0, $12		\n\t"
comment|/* read status reg */
asm|"move	$8, %0		\n\t" 	    "ori	$8, $8, 0x81	\n\t"
comment|/* set KX, and IE */
asm|"xori	$8, $8, 0x1	\n\t"
comment|/* flip IE */
asm|"mtc0	$8, $12		\n\t"
comment|/* update status reg */
asm|: "=r"(sr) 	    : : "$8");
return|return
operator|(
name|sr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_restore_kx
parameter_list|(
name|uint32_t
name|sr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("mtc0	%0, $12" : : "r"(sr));
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline__
name|uint32_t
name|nlm_load_word
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|addr
parameter_list|)
block|{
return|return
operator|(
operator|*
name|addr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_store_word
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
operator|*
name|addr
operator|=
name|val
expr_stmt|;
block|}
end_function

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
name|__inline__
name|uint64_t
name|nlm_load_dword
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|addr
parameter_list|)
block|{
return|return
operator|(
operator|*
name|addr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_store_dword
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|addr
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
operator|*
name|addr
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* o32 */
end_comment

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_load_dword
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|addr
parameter_list|)
block|{
name|uint32_t
name|valhi
decl_stmt|,
name|vallo
decl_stmt|,
name|sr
decl_stmt|;
name|sr
operator|=
name|nlm_enable_kx
argument_list|()
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "ld		$8, 0(%2)	\n\t" 	    "dsra32	%0, $8, 0	\n\t" 	    "sll	%1, $8, 0	\n\t" 	    ".set	pop		\n" 	    : "=r"(valhi), "=r"(vallo) 	    : "r"(addr) 	    : "$8" );
name|nlm_restore_kx
argument_list|(
name|sr
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|valhi
operator|<<
literal|32
operator|)
operator||
name|vallo
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_store_dword
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|addr
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint32_t
name|valhi
decl_stmt|,
name|vallo
decl_stmt|,
name|sr
decl_stmt|;
name|valhi
operator|=
name|val
operator|>>
literal|32
expr_stmt|;
name|vallo
operator|=
name|val
operator|&
literal|0xffffffff
expr_stmt|;
name|sr
operator|=
name|nlm_enable_kx
argument_list|()
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "dsll32	$8, %1, 0	\n\t" 	    "dsll32	$9, %2, 0	\n\t"
comment|/* get rid of the */
asm|"dsrl32	$9, $9, 0	\n\t"
comment|/* sign extend */
asm|"or		$9, $9, $8	\n\t" 	    "sd		$9, 0(%0)	\n\t" 	    ".set	pop		\n" 	    : : "r"(addr), "r"(valhi), "r"(vallo) 	    : "$8", "$9", "memory");
name|nlm_restore_kx
argument_list|(
name|sr
argument_list|)
expr_stmt|;
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
end_if

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_load_word_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|p
init|=
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|addr
decl_stmt|;
return|return
operator|(
operator|*
name|p
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_store_word_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|p
init|=
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|addr
decl_stmt|;
operator|*
name|p
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_load_dword_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
block|{
specifier|volatile
name|uint64_t
modifier|*
name|p
init|=
operator|(
specifier|volatile
name|uint64_t
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|addr
decl_stmt|;
return|return
operator|(
operator|*
name|p
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_store_dword_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
specifier|volatile
name|uint64_t
modifier|*
name|p
init|=
operator|(
specifier|volatile
name|uint64_t
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|addr
decl_stmt|;
operator|*
name|p
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_elif

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_load_word_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "lw		%0, 0(%1)	\n\t" 	    ".set	pop		\n" 	    : "=r"(val) 	    : "r"(addr));
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_store_word_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "sw		%0, 0(%1)	\n\t" 	    ".set	pop		\n" 	    : : "r"(val), "r"(addr) 	    : "memory");
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_load_dword_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
block|{
name|uint64_t
name|val
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "ld		%0, 0(%1)	\n\t" 	    ".set	pop		\n" 	    : "=r"(val) 	    : "r"(addr));
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_store_dword_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "sd		%0, 0(%1)	\n\t" 	    ".set	pop		\n" 	    : : "r"(val), "r"(addr) 	    : "memory");
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* o32 */
end_comment

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_load_word_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|,
name|addrhi
decl_stmt|,
name|addrlo
decl_stmt|,
name|sr
decl_stmt|;
name|addrhi
operator|=
name|addr
operator|>>
literal|32
expr_stmt|;
name|addrlo
operator|=
name|addr
operator|&
literal|0xffffffff
expr_stmt|;
name|sr
operator|=
name|nlm_enable_kx
argument_list|()
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "dsll32	$8, %1, 0	\n\t" 	    "dsll32	$9, %2, 0	\n\t"
comment|/* get rid of the */
asm|"dsrl32	$9, $9, 0	\n\t"
comment|/* sign extend */
asm|"or		$9, $9, $8	\n\t" 	    "lw		%0, 0($9)	\n\t" 	    ".set	pop		\n" 	    :	"=r"(val) 	    :	"r"(addrhi), "r"(addrlo) 	    :	"$8", "$9");
name|nlm_restore_kx
argument_list|(
name|sr
argument_list|)
expr_stmt|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_store_word_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|addrhi
decl_stmt|,
name|addrlo
decl_stmt|,
name|sr
decl_stmt|;
name|addrhi
operator|=
name|addr
operator|>>
literal|32
expr_stmt|;
name|addrlo
operator|=
name|addr
operator|&
literal|0xffffffff
expr_stmt|;
name|sr
operator|=
name|nlm_enable_kx
argument_list|()
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "dsll32	$8, %1, 0	\n\t" 	    "dsll32	$9, %2, 0	\n\t"
comment|/* get rid of the */
asm|"dsrl32	$9, $9, 0	\n\t"
comment|/* sign extend */
asm|"or		$9, $9, $8	\n\t" 	    "sw		%0, 0($9)	\n\t" 	    ".set	pop		\n" 	    :: "r"(val), "r"(addrhi), "r"(addrlo) 	    :	"$8", "$9", "memory");
name|nlm_restore_kx
argument_list|(
name|sr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_load_dword_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
block|{
name|uint32_t
name|addrh
decl_stmt|,
name|addrl
decl_stmt|,
name|sr
decl_stmt|;
name|uint32_t
name|valh
decl_stmt|,
name|vall
decl_stmt|;
name|addrh
operator|=
name|addr
operator|>>
literal|32
expr_stmt|;
name|addrl
operator|=
name|addr
operator|&
literal|0xffffffff
expr_stmt|;
name|sr
operator|=
name|nlm_enable_kx
argument_list|()
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "dsll32	$8, %2, 0	\n\t" 	    "dsll32	$9, %3, 0	\n\t"
comment|/* get rid of the */
asm|"dsrl32	$9, $9, 0	\n\t"
comment|/* sign extend */
asm|"or		$9, $9, $8	\n\t" 	    "ld		$8, 0($9)	\n\t" 	    "dsra32	%0, $8, 0	\n\t" 	    "sll	%1, $8, 0	\n\t" 	    ".set	pop		\n" 	    : "=r"(valh), "=r"(vall) 	    : "r"(addrh), "r"(addrl) 	    : "$8", "$9");
name|nlm_restore_kx
argument_list|(
name|sr
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|valh
operator|<<
literal|32
operator|)
operator||
name|vall
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_store_dword_daddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint32_t
name|addrh
decl_stmt|,
name|addrl
decl_stmt|,
name|sr
decl_stmt|;
name|uint32_t
name|valh
decl_stmt|,
name|vall
decl_stmt|;
name|addrh
operator|=
name|addr
operator|>>
literal|32
expr_stmt|;
name|addrl
operator|=
name|addr
operator|&
literal|0xffffffff
expr_stmt|;
name|valh
operator|=
name|val
operator|>>
literal|32
expr_stmt|;
name|vall
operator|=
name|val
operator|&
literal|0xffffffff
expr_stmt|;
name|sr
operator|=
name|nlm_enable_kx
argument_list|()
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "dsll32	$8, %2, 0	\n\t" 	    "dsll32	$9, %3, 0	\n\t"
comment|/* get rid of the */
asm|"dsrl32	$9, $9, 0	\n\t"
comment|/* sign extend */
asm|"or		$9, $9, $8	\n\t" 	    "dsll32	$8, %0, 0	\n\t" 	    "dsll32	$10, %1, 0	\n\t"
comment|/* get rid of the */
asm|"dsrl32	$10, $10, 0	\n\t"
comment|/* sign extend */
asm|"or		$8, $8, $10	\n\t" 	    "sd		$8, 0($9)	\n\t" 	    ".set	pop		\n" 	    : :	"r"(valh), "r"(vall), "r"(addrh), "r"(addrl) 	    :	"$8", "$9", "memory");
name|nlm_restore_kx
argument_list|(
name|sr
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mips_n64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

