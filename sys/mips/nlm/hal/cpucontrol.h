begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_HAL_CPUCONTROL_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_HAL_CPUCONTROL_H__
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
name|CPU_BLOCKID_SCH
value|7
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_SCU
value|8
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_FPU
value|9
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_MAP
value|10
end_define

begin_define
define|#
directive|define
name|LSU_DEFEATURE
value|0x304
end_define

begin_define
define|#
directive|define
name|LSU_DEBUG_ADDR
value|0x305
end_define

begin_define
define|#
directive|define
name|LSU_DEBUG_DATA0
value|0x306
end_define

begin_define
define|#
directive|define
name|LSU_CERRLOG_REGID
value|0x09
end_define

begin_define
define|#
directive|define
name|SCHED_DEFEATURE
value|0x700
end_define

begin_comment
comment|/* Offsets of interest from the 'MAP' Block */
end_comment

begin_define
define|#
directive|define
name|MAP_THREADMODE
value|0x00
end_define

begin_define
define|#
directive|define
name|MAP_EXT_EBASE_ENABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|MAP_CCDI_CONFIG
value|0x08
end_define

begin_define
define|#
directive|define
name|MAP_THRD0_CCDI_STATUS
value|0x0c
end_define

begin_define
define|#
directive|define
name|MAP_THRD1_CCDI_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|MAP_THRD2_CCDI_STATUS
value|0x14
end_define

begin_define
define|#
directive|define
name|MAP_THRD3_CCDI_STATUS
value|0x18
end_define

begin_define
define|#
directive|define
name|MAP_THRD0_DEBUG_MODE
value|0x1c
end_define

begin_define
define|#
directive|define
name|MAP_THRD1_DEBUG_MODE
value|0x20
end_define

begin_define
define|#
directive|define
name|MAP_THRD2_DEBUG_MODE
value|0x24
end_define

begin_define
define|#
directive|define
name|MAP_THRD3_DEBUG_MODE
value|0x28
end_define

begin_define
define|#
directive|define
name|MAP_MISC_STATE
value|0x60
end_define

begin_define
define|#
directive|define
name|MAP_DEBUG_READ_CTL
value|0x64
end_define

begin_define
define|#
directive|define
name|MAP_DEBUG_READ_REG0
value|0x68
end_define

begin_define
define|#
directive|define
name|MAP_DEBUG_READ_REG1
value|0x6c
end_define

begin_define
define|#
directive|define
name|MMU_SETUP
value|0x400
end_define

begin_define
define|#
directive|define
name|MMU_LFSRSEED
value|0x401
end_define

begin_define
define|#
directive|define
name|MMU_HPW_NUM_PAGE_LVL
value|0x410
end_define

begin_define
define|#
directive|define
name|MMU_PGWKR_PGDBASE
value|0x411
end_define

begin_define
define|#
directive|define
name|MMU_PGWKR_PGDSHFT
value|0x412
end_define

begin_define
define|#
directive|define
name|MMU_PGWKR_PGDMASK
value|0x413
end_define

begin_define
define|#
directive|define
name|MMU_PGWKR_PUDSHFT
value|0x414
end_define

begin_define
define|#
directive|define
name|MMU_PGWKR_PUDMASK
value|0x415
end_define

begin_define
define|#
directive|define
name|MMU_PGWKR_PMDSHFT
value|0x416
end_define

begin_define
define|#
directive|define
name|MMU_PGWKR_PMDMASK
value|0x417
end_define

begin_define
define|#
directive|define
name|MMU_PGWKR_PTESHFT
value|0x418
end_define

begin_define
define|#
directive|define
name|MMU_PGWKR_PTEMASK
value|0x419
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
name|uint32_t
name|hi
decl_stmt|,
name|lo
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set push\n" 	    ".set mips64\n" 	    "move   $8, %2\n" 	    ".word  0x71090018\n" 	    "nop	\n" 	    "dsra32 %0, $9, 0\n" 	    "sll    %1, $9, 0\n" 	    ".set pop\n" 	    : "=r"(hi), "=r"(lo) 	    : "r"(reg) : "$8", "$9");
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
asm|( 	    ".set push\n" 	    ".set mips64\n" 	    "move   $9, %0\n" 	    "dsll32 $9, %1, 0\n" 	    "dsll32 $8, %0, 0\n" 	    "dsrl32 $9, $9, 0\n" 	    "or     $9, $9, $8\n" 	    "move   $8, %2\n" 	    ".word  0x71090019\n" 	    "nop	\n" 	    ".set pop\n" 	    : :"r"(hi), "r"(lo), "r"(reg) 	    : "$8", "$9");
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
comment|/* hashindex_en = 1 to enable hash mode, hashindex_en=0 to disable  * global_mode = 1 to enable global mode, global_mode=0 to disable  * clk_gating = 0 to enable clock gating, clk_gating=1 to disable  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|nlm_mmu_setup
parameter_list|(
name|int
name|hashindex_en
parameter_list|,
name|int
name|global_mode
parameter_list|,
name|int
name|clk_gating
parameter_list|)
block|{
name|uint32_t
name|mmusetup
init|=
literal|0
decl_stmt|;
name|mmusetup
operator||=
operator|(
name|hashindex_en
operator|<<
literal|13
operator|)
expr_stmt|;
name|mmusetup
operator||=
operator|(
name|clk_gating
operator|<<
literal|3
operator|)
expr_stmt|;
name|mmusetup
operator||=
operator|(
name|global_mode
operator|<<
literal|0
operator|)
expr_stmt|;
name|nlm_mtcr
argument_list|(
name|MMU_SETUP
argument_list|,
name|mmusetup
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_mmu_lfsr_seed
parameter_list|(
name|int
name|thr0_seed
parameter_list|,
name|int
name|thr1_seed
parameter_list|,
name|int
name|thr2_seed
parameter_list|,
name|int
name|thr3_seed
parameter_list|)
block|{
name|uint32_t
name|seed
init|=
name|nlm_mfcr
argument_list|(
name|MMU_LFSRSEED
argument_list|)
decl_stmt|;
name|seed
operator||=
operator|(
operator|(
name|thr3_seed
operator|&
literal|0x7f
operator|)
operator|<<
literal|23
operator|)
expr_stmt|;
name|seed
operator||=
operator|(
operator|(
name|thr2_seed
operator|&
literal|0x7f
operator|)
operator|<<
literal|16
operator|)
expr_stmt|;
name|seed
operator||=
operator|(
operator|(
name|thr1_seed
operator|&
literal|0x7f
operator|)
operator|<<
literal|7
operator|)
expr_stmt|;
name|seed
operator||=
operator|(
operator|(
name|thr0_seed
operator|&
literal|0x7f
operator|)
operator|<<
literal|0
operator|)
expr_stmt|;
name|nlm_mtcr
argument_list|(
name|MMU_LFSRSEED
argument_list|,
name|seed
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NLM_CPUCONTROL_H__ */
end_comment

end_unit

