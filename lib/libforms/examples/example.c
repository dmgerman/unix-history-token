begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	Paul Richards.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,   *    verbatim and that no modifications are made prior to this   *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Paul Richards.  * 4. The name Paul Richards may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY PAUL RICHARDS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL PAUL RICHARDS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<strhash.h>
end_include

begin_include
include|#
directive|include
file|<ncurses.h>
end_include

begin_include
include|#
directive|include
file|"../forms.h"
end_include

begin_function_decl
name|void
name|UserRoutine
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|()
block|{
name|struct
name|Tuple
modifier|*
name|tuple
decl_stmt|;
name|struct
name|Form
modifier|*
name|form1
decl_stmt|,
modifier|*
name|form2
decl_stmt|;
name|int
name|res
decl_stmt|;
if|if
condition|(
name|load_objects
argument_list|(
literal|"example.frm"
argument_list|)
operator|==
name|ST_ERROR
condition|)
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bind_tuple
argument_list|(
name|root_table
argument_list|,
literal|"User_Routine"
argument_list|,
name|TT_FUNC
argument_list|,
operator|&
name|UserRoutine
argument_list|)
expr_stmt|;
name|start_object
argument_list|(
literal|"adduser"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|UserRoutine
parameter_list|(
name|OBJECT
modifier|*
name|obj
parameter_list|)
block|{
comment|/* Just draw a box and return */
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

