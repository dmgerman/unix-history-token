begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===----- trampoline_setup.c - Implement __trampoline_setup -------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_function_decl
specifier|extern
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
function_decl|;
end_function_decl

begin_comment
comment|/*  * The ppc compiler generates calls to __trampoline_setup() when creating   * trampoline functions on the stack for use with nested functions.  * This function creates a custom 40-byte trampoline function on the stack   * which loads r11 with a pointer to the outer function's locals  * and then jumps to the target nested function.  */
end_comment

begin_if
if|#
directive|if
name|__ppc__
operator|&&
operator|!
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_if

begin_function
name|COMPILER_RT_ABI
name|void
name|__trampoline_setup
parameter_list|(
name|uint32_t
modifier|*
name|trampOnStack
parameter_list|,
name|int
name|trampSizeAllocated
parameter_list|,
specifier|const
name|void
modifier|*
name|realFunc
parameter_list|,
name|void
modifier|*
name|localsPtr
parameter_list|)
block|{
comment|/* should never happen, but if compiler did not allocate */
comment|/* enough space on stack for the trampoline, abort */
if|if
condition|(
name|trampSizeAllocated
operator|<
literal|40
condition|)
name|compilerrt_abort
argument_list|()
expr_stmt|;
comment|/* create trampoline */
name|trampOnStack
index|[
literal|0
index|]
operator|=
literal|0x7c0802a6
expr_stmt|;
comment|/* mflr r0 */
name|trampOnStack
index|[
literal|1
index|]
operator|=
literal|0x4800000d
expr_stmt|;
comment|/* bl Lbase */
name|trampOnStack
index|[
literal|2
index|]
operator|=
operator|(
name|uint32_t
operator|)
name|realFunc
expr_stmt|;
name|trampOnStack
index|[
literal|3
index|]
operator|=
operator|(
name|uint32_t
operator|)
name|localsPtr
expr_stmt|;
name|trampOnStack
index|[
literal|4
index|]
operator|=
literal|0x7d6802a6
expr_stmt|;
comment|/* Lbase: mflr r11 */
name|trampOnStack
index|[
literal|5
index|]
operator|=
literal|0x818b0000
expr_stmt|;
comment|/* lwz    r12,0(r11) */
name|trampOnStack
index|[
literal|6
index|]
operator|=
literal|0x7c0803a6
expr_stmt|;
comment|/* mtlr r0 */
name|trampOnStack
index|[
literal|7
index|]
operator|=
literal|0x7d8903a6
expr_stmt|;
comment|/* mtctr r12 */
name|trampOnStack
index|[
literal|8
index|]
operator|=
literal|0x816b0004
expr_stmt|;
comment|/* lwz    r11,4(r11) */
name|trampOnStack
index|[
literal|9
index|]
operator|=
literal|0x4e800420
expr_stmt|;
comment|/* bctr */
comment|/* clear instruction cache */
name|__clear_cache
argument_list|(
name|trampOnStack
argument_list|,
operator|&
name|trampOnStack
index|[
literal|10
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ppc__&& !defined(__powerpc64__) */
end_comment

end_unit

