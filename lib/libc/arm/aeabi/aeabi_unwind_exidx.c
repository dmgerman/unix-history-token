begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/elf.h>
end_include

begin_include
include|#
directive|include
file|<link.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/*  * ARM EABI unwind helper.  *  * This finds the exidx section address and size associated with a given code  * address.  There are separate implementations for static and dynamic code.  *  * GCC expects this function to exist as __gnu_Unwind_Find_exidx(), clang and  * BSD tools expect it to be dl_unwind_find_exidx().  Both have the same API, so  * we set up an alias for GCC.  */
end_comment

begin_expr_stmt
name|__strong_reference
argument_list|(
name|dl_unwind_find_exidx
argument_list|,
name|__gnu_Unwind_Find_exidx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Each entry in the exidx section is a pair of 32-bit words.  We don't  * interpret the contents of the entries here; this typedef is just a local  * convenience for using sizeof() and doing pointer math.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|exidx_entry
block|{
name|uint32_t
name|data
index|[
literal|2
index|]
decl_stmt|;
block|}
name|exidx_entry
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__PIC__
end_ifdef

begin_comment
comment|/*  * Unwind helper for dynamically linked code.  *  * This finds the shared object that contains the given address, and returns the  * address of the exidx section in that shared object along with the number of  * entries in that section, or NULL if it wasn't found.  */
end_comment

begin_function
name|void
modifier|*
name|dl_unwind_find_exidx
parameter_list|(
specifier|const
name|void
modifier|*
name|pc
parameter_list|,
name|int
modifier|*
name|pcount
parameter_list|)
block|{
specifier|const
name|Elf_Phdr
modifier|*
name|hdr
decl_stmt|;
name|struct
name|dl_phdr_info
name|info
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|_rtld_addr_phdr
argument_list|(
name|pc
argument_list|,
operator|&
name|info
argument_list|)
condition|)
block|{
name|hdr
operator|=
name|info
operator|.
name|dlpi_phdr
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|info
operator|.
name|dlpi_phnum
condition|;
name|i
operator|++
operator|,
name|hdr
operator|++
control|)
block|{
if|if
condition|(
name|hdr
operator|->
name|p_type
operator|==
name|PT_ARM_EXIDX
condition|)
block|{
operator|*
name|pcount
operator|=
name|hdr
operator|->
name|p_memsz
operator|/
sizeof|sizeof
argument_list|(
name|exidx_entry
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|void
operator|*
operator|)
operator|(
name|info
operator|.
name|dlpi_addr
operator|+
name|hdr
operator|->
name|p_vaddr
operator|)
operator|)
return|;
block|}
block|}
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__PIC__ */
end_comment

begin_comment
comment|/*  * Unwind helper for statically linked code.  *  * In a statically linked program, the linker populates a pair of symbols with  * the addresses of the start and end of the exidx table, so returning the  * address and count of elements is pretty straighforward.  */
end_comment

begin_function
name|void
modifier|*
name|dl_unwind_find_exidx
parameter_list|(
specifier|const
name|void
modifier|*
name|pc
parameter_list|,
name|int
modifier|*
name|pcount
parameter_list|)
block|{
specifier|extern
name|struct
name|exidx_entry
name|__exidx_start
decl_stmt|;
specifier|extern
name|struct
name|exidx_entry
name|__exidx_end
decl_stmt|;
operator|*
name|pcount
operator|=
call|(
name|int
call|)
argument_list|(
operator|&
name|__exidx_end
operator|-
operator|&
name|__exidx_start
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|__exidx_start
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PIC__ */
end_comment

end_unit

