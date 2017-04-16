begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- clear_cache.c - Implement __clear_cache ---------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_if
if|#
directive|if
name|__APPLE__
end_if

begin_include
include|#
directive|include
file|<libkern/OSCacheControl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_comment
comment|/* Forward declare Win32 APIs since the GCC mode driver does not handle the    newer SDKs as well as needed.  */
end_comment

begin_function_decl
name|uint32_t
name|FlushInstructionCache
parameter_list|(
name|uintptr_t
name|hProcess
parameter_list|,
name|void
modifier|*
name|lpBaseAddress
parameter_list|,
name|uintptr_t
name|dwSize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uintptr_t
name|GetCurrentProcess
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__Bitrig__
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/cachectl.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ANDROID__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__LP64__
argument_list|)
end_if

begin_comment
comment|/*      * clear_mips_cache - Invalidates instruction cache for Mips.      */
end_comment

begin_function
specifier|static
name|void
name|clear_mips_cache
parameter_list|(
specifier|const
name|void
modifier|*
name|Addr
parameter_list|,
name|size_t
name|Size
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|(         ".set push\n"         ".set noreorder\n"         ".set noat\n"         "beq %[Size], $zero, 20f\n"
comment|/* If size == 0, branch around. */
asm|"nop\n"         "daddu %[Size], %[Addr], %[Size]\n"
comment|/* Calculate end address + 1 */
asm|"rdhwr $v0, $1\n"
comment|/* Get step size for SYNCI.                                                 $1 is $HW_SYNCI_Step */
asm|"beq $v0, $zero, 20f\n"
comment|/* If no caches require                                                 synchronization, branch                                                 around. */
asm|"nop\n"         "10:\n"         "synci 0(%[Addr])\n"
comment|/* Synchronize all caches around                                                 address. */
asm|"daddu %[Addr], %[Addr], $v0\n"
comment|/* Add step size. */
asm|"sltu $at, %[Addr], %[Size]\n"
comment|/* Compare current with end                                                 address. */
asm|"bne $at, $zero, 10b\n"
comment|/* Branch if more to do. */
asm|"nop\n"         "sync\n"
comment|/* Clear memory hazards. */
asm|"20:\n"         "bal 30f\n"         "nop\n"         "30:\n"         "daddiu $ra, $ra, 12\n"
comment|/* $ra has a value of $pc here.                                                 Add offset of 12 to point to the                                                 instruction after the last nop.                                               */
asm|"jr.hb $ra\n"
comment|/* Return, clearing instruction                                                 hazards. */
asm|"nop\n"         ".set pop\n"         : [Addr] "+r"(Addr), [Size] "+r"(Size)         :: "at", "ra", "v0", "memory"       );
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

begin_comment
comment|/*  * The compiler generates calls to __clear_cache() when creating   * trampoline functions on the stack for use with nested functions.  * It is expected to invalidate the instruction cache for the   * specified range.  */
end_comment

begin_function
name|void
name|__clear_cache
parameter_list|(
name|void
modifier|*
name|start
parameter_list|,
name|void
modifier|*
name|end
parameter_list|)
block|{
if|#
directive|if
name|__i386__
operator|||
name|__x86_64__
operator|||
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
comment|/*  * Intel processors have a unified instruction and data cache  * so there is nothing to do  */
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__Bitrig__
argument_list|)
name|struct
name|arm_sync_icache_args
name|arg
decl_stmt|;
name|arg
operator|.
name|addr
operator|=
operator|(
name|uintptr_t
operator|)
name|start
expr_stmt|;
name|arg
operator|.
name|len
operator|=
operator|(
name|uintptr_t
operator|)
name|end
operator|-
operator|(
name|uintptr_t
operator|)
name|start
expr_stmt|;
name|sysarch
argument_list|(
name|ARM_SYNC_ICACHE
argument_list|,
operator|&
name|arg
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__linux__
argument_list|)
comment|/*      * We used to include asm/unistd.h for the __ARM_NR_cacheflush define, but      * it also brought many other unused defines, as well as a dependency on      * kernel headers to be installed.      *      * This value is stable at least since Linux 3.13 and should remain so for      * compatibility reasons, warranting it's re-definition here.      */
define|#
directive|define
name|__ARM_NR_cacheflush
value|0x0f0002
specifier|register
name|int
name|start_reg
asm|__asm("r0") = (int) (intptr_t) start;
specifier|const
specifier|register
name|int
name|end_reg
asm|__asm("r1") = (int) (intptr_t) end;
specifier|const
specifier|register
name|int
name|flags
asm|__asm("r2") = 0;
specifier|const
specifier|register
name|int
name|syscall_nr
asm|__asm("r7") = __ARM_NR_cacheflush;
asm|__asm __volatile("svc 0x0"
range|:
literal|"=r"
operator|(
name|start_reg
operator|)
operator|:
literal|"r"
operator|(
name|syscall_nr
operator|)
decl_stmt|, "r"
argument_list|(
name|start_reg
argument_list|)
decl_stmt|, "r"
argument_list|(
name|end_reg
argument_list|)
decl_stmt|,                             "r"
argument_list|(
name|flags
argument_list|)
decl_stmt|);
if|if
condition|(
name|start_reg
operator|!=
literal|0
condition|)
block|{
name|compilerrt_abort
argument_list|()
expr_stmt|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
name|FlushInstructionCache
argument_list|(
name|GetCurrentProcess
argument_list|()
argument_list|,
name|start
argument_list|,
name|end
operator|-
name|start
argument_list|)
expr_stmt|;
else|#
directive|else
name|compilerrt_abort
argument_list|()
expr_stmt|;
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips__
argument_list|)
specifier|const
name|uintptr_t
name|start_int
init|=
operator|(
name|uintptr_t
operator|)
name|start
decl_stmt|;
specifier|const
name|uintptr_t
name|end_int
init|=
operator|(
name|uintptr_t
operator|)
name|end
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__ANDROID__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__LP64__
argument_list|)
comment|// Call synci implementation for short address range.
specifier|const
name|uintptr_t
name|address_range_limit
init|=
literal|256
decl_stmt|;
if|if
condition|(
operator|(
name|end_int
operator|-
name|start_int
operator|)
operator|<=
name|address_range_limit
condition|)
block|{
name|clear_mips_cache
argument_list|(
name|start
argument_list|,
operator|(
name|end_int
operator|-
name|start_int
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|syscall
argument_list|(
name|__NR_cacheflush
argument_list|,
name|start
argument_list|,
operator|(
name|end_int
operator|-
name|start_int
operator|)
argument_list|,
name|BCACHE
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|syscall
argument_list|(
name|__NR_cacheflush
argument_list|,
name|start
argument_list|,
operator|(
name|end_int
operator|-
name|start_int
operator|)
argument_list|,
name|BCACHE
argument_list|)
expr_stmt|;
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|__aarch64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
name|uint64_t
name|xstart
init|=
operator|(
name|uint64_t
operator|)
operator|(
name|uintptr_t
operator|)
name|start
decl_stmt|;
name|uint64_t
name|xend
init|=
operator|(
name|uint64_t
operator|)
operator|(
name|uintptr_t
operator|)
name|end
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
comment|// Get Cache Type Info
name|uint64_t
name|ctr_el0
decl_stmt|;
asm|__asm __volatile("mrs %0, ctr_el0" : "=r"(ctr_el0));
comment|/*    * dc& ic instructions must use 64bit registers so we don't use    * uintptr_t in case this runs in an IPL32 environment.    */
specifier|const
name|size_t
name|dcache_line_size
init|=
literal|4
operator|<<
operator|(
operator|(
name|ctr_el0
operator|>>
literal|16
operator|)
operator|&
literal|15
operator|)
decl_stmt|;
for|for
control|(
name|addr
operator|=
name|xstart
init|;
name|addr
operator|<
name|xend
condition|;
name|addr
operator|+=
name|dcache_line_size
control|)
asm|__asm __volatile("dc cvau, %0" :: "r"(addr));
asm|__asm __volatile("dsb ish");
specifier|const
name|size_t
name|icache_line_size
init|=
literal|4
operator|<<
operator|(
operator|(
name|ctr_el0
operator|>>
literal|0
operator|)
operator|&
literal|15
operator|)
decl_stmt|;
for|for
control|(
name|addr
operator|=
name|xstart
init|;
name|addr
operator|<
name|xend
condition|;
name|addr
operator|+=
name|icache_line_size
control|)
asm|__asm __volatile("ic ivau, %0" :: "r"(addr));
asm|__asm __volatile("isb sy");
else|#
directive|else
if|#
directive|if
name|__APPLE__
comment|/* On Darwin, sys_icache_invalidate() provides this functionality */
name|sys_icache_invalidate
argument_list|(
name|start
argument_list|,
name|end
operator|-
name|start
argument_list|)
expr_stmt|;
else|#
directive|else
name|compilerrt_abort
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function

end_unit

