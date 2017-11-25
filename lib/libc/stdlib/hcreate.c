begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2015 Nuxi, https://nuxi.nl/  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<search.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/*  * Thread unsafe interface: use a single process-wide hash table and  * forward calls to *_r() functions.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|hsearch_data
name|global_hashtable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|global_hashtable_initialized
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|hcreate
parameter_list|(
name|size_t
name|nel
parameter_list|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|void
name|hdestroy
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Destroy global hash table if present. */
if|if
condition|(
name|global_hashtable_initialized
condition|)
block|{
name|hdestroy_r
argument_list|(
operator|&
name|global_hashtable
argument_list|)
expr_stmt|;
name|global_hashtable_initialized
operator|=
name|false
expr_stmt|;
block|}
block|}
end_function

begin_function
name|ENTRY
modifier|*
name|hsearch
parameter_list|(
name|ENTRY
name|item
parameter_list|,
name|ACTION
name|action
parameter_list|)
block|{
name|ENTRY
modifier|*
name|retval
decl_stmt|;
comment|/* Create global hash table if needed. */
if|if
condition|(
operator|!
name|global_hashtable_initialized
condition|)
block|{
if|if
condition|(
name|hcreate_r
argument_list|(
literal|0
argument_list|,
operator|&
name|global_hashtable
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|global_hashtable_initialized
operator|=
name|true
expr_stmt|;
block|}
if|if
condition|(
name|hsearch_r
argument_list|(
name|item
argument_list|,
name|action
argument_list|,
operator|&
name|retval
argument_list|,
operator|&
name|global_hashtable
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

end_unit

