begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Run-time module for GNU C++ compiled shared libraries.  *  * The linker constructs the following arrays of pointers to global  * constructors and destructors. The first element contains the  * number of pointers in each.  * The tables are also null-terminated.  */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|__CTOR_LIST__
index|[]
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|__DTOR_LIST__
index|[]
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|__dtors
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|long
name|i
init|=
operator|(
name|unsigned
name|long
operator|)
name|__DTOR_LIST__
index|[
literal|0
index|]
decl_stmt|;
name|void
function_decl|(
modifier|*
modifier|*
name|p
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|__DTOR_LIST__
operator|+
name|i
function_decl|;
while|while
condition|(
name|i
operator|--
condition|)
operator|(
operator|*
operator|*
name|p
operator|--
operator|)
operator|(
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|__ctors
parameter_list|(
name|void
parameter_list|)
block|{
name|void
function_decl|(
modifier|*
modifier|*
name|p
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|__CTOR_LIST__
operator|+
literal|1
function_decl|;
while|while
condition|(
operator|*
name|p
condition|)
operator|(
operator|*
operator|*
name|p
operator|++
operator|)
operator|(
operator|)
expr_stmt|;
block|}
end_function

begin_extern
extern|extern void __init(
end_extern

begin_asm
unit|)
asm|asm(".init");
end_asm

begin_extern
extern|extern void __fini(
end_extern

begin_asm
unit|)
asm|asm(".fini");
end_asm

begin_function
name|void
name|__init
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|initialized
init|=
literal|0
decl_stmt|;
comment|/* 	 * Call global constructors. 	 * Arrange to call global destructors at exit. 	 */
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|initialized
operator|=
literal|1
expr_stmt|;
name|__ctors
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|__fini
parameter_list|(
name|void
parameter_list|)
block|{
name|__dtors
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Make sure there is at least one constructor and one destructor in the  * shared library.  Otherwise, the linker does not realize that the  * constructor and destructor lists are linker sets.  It treats them as  * commons and resolves them to the lists from the main program.  That  * causes multiple invocations of the main program's static constructors  * and destructors, which is very bad.  */
end_comment

begin_function
specifier|static
name|void
name|do_nothing
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* Linker magic to add an element to a constructor or destructor list. */
end_comment

begin_define
define|#
directive|define
name|TEXT_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
define|\
value|asm(".stabs \"_" #set "\", 23, 0, 0, _" #sym)
end_define

begin_expr_stmt
name|TEXT_SET
argument_list|(
name|__CTOR_LIST__
argument_list|,
name|do_nothing
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TEXT_SET
argument_list|(
name|__DTOR_LIST__
argument_list|,
name|do_nothing
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

