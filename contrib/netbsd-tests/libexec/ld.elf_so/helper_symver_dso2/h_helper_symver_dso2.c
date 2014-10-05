begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: h_helper_symver_dso2.c,v 1.1 2011/06/25 05:45:13 nonaka Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by NONAKA Kimihiro.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_asm
asm|__asm(".symver testfunc_new, testfunc@@V_3");
end_asm

begin_asm
asm|__asm(".symver testfunc_compat1, testfunc@V_1");
end_asm

begin_asm
asm|__asm(".symver testfunc_compat2, testfunc@V_2");
end_asm

begin_function_decl
name|int
name|testfunc_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|testfunc_compat1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|testfunc_compat2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|testfunc_new
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|3
return|;
block|}
end_function

begin_function
name|int
name|testfunc_compat1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|testfunc_compat2
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|2
return|;
block|}
end_function

end_unit

