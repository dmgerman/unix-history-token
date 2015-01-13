begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- enable_execute_stack.c - Implement __enable_execute_stack ---------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_comment
comment|/* #include "config.h"  * FIXME: CMake - include when cmake system is ready.  * Remove #define HAVE_SYSCONF 1 line.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__APPLE__
end_ifndef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __APPLE__ */
end_comment

begin_if
if|#
directive|if
name|__LP64__
end_if

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|48
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The compiler generates calls to __enable_execute_stack() when creating   * trampoline functions on the stack for use with nested functions.  * It is expected to mark the page(s) containing the address   * and the next 48 bytes as executable.  Since the stack is normally rw-  * that means changing the protection on those page(s) to rwx.   */
end_comment

begin_function
name|COMPILER_RT_ABI
name|void
name|__enable_execute_stack
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
block|{
if|#
directive|if
name|__APPLE__
comment|/* On Darwin, pagesize is always 4096 bytes */
specifier|const
name|uintptr_t
name|pageSize
init|=
literal|4096
decl_stmt|;
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|HAVE_SYSCONF
argument_list|)
error|#
directive|error
literal|"HAVE_SYSCONF not defined! See enable_execute_stack.c"
else|#
directive|else
specifier|const
name|uintptr_t
name|pageSize
init|=
name|sysconf
argument_list|(
name|_SC_PAGESIZE
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|/* __APPLE__ */
specifier|const
name|uintptr_t
name|pageAlignMask
init|=
operator|~
operator|(
name|pageSize
operator|-
literal|1
operator|)
decl_stmt|;
name|uintptr_t
name|p
init|=
operator|(
name|uintptr_t
operator|)
name|addr
decl_stmt|;
name|unsigned
name|char
modifier|*
name|startPage
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|(
name|p
operator|&
name|pageAlignMask
operator|)
decl_stmt|;
name|unsigned
name|char
modifier|*
name|endPage
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|(
operator|(
name|p
operator|+
name|TRAMPOLINE_SIZE
operator|+
name|pageSize
operator|)
operator|&
name|pageAlignMask
operator|)
decl_stmt|;
name|size_t
name|length
init|=
name|endPage
operator|-
name|startPage
decl_stmt|;
operator|(
name|void
operator|)
name|mprotect
argument_list|(
operator|(
name|void
operator|*
operator|)
name|startPage
argument_list|,
name|length
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
operator||
name|PROT_EXEC
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

