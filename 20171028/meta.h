begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $NetBSD: meta.h,v 1.5 2016/05/12 20:28:34 sjg Exp $ */
end_comment

begin_comment
comment|/*  * Things needed for 'meta' mode.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009-2010, Juniper Networks, Inc.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions   * are met:   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.    * 3. Neither the name of the copyright holders nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.   *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BuildMon
block|{
name|char
name|meta_fname
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|int
name|filemon_fd
decl_stmt|;
name|int
name|mon_fd
decl_stmt|;
name|FILE
modifier|*
name|mfp
decl_stmt|;
block|}
name|BuildMon
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Boolean
name|useMeta
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|Job
struct_decl|;
end_struct_decl

begin_comment
comment|/* not defined yet */
end_comment

begin_function_decl
name|void
name|meta_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|meta_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|meta_mode_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|meta_job_start
parameter_list|(
name|struct
name|Job
modifier|*
parameter_list|,
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|meta_job_child
parameter_list|(
name|struct
name|Job
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|meta_job_error
parameter_list|(
name|struct
name|Job
modifier|*
parameter_list|,
name|GNode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|meta_job_output
parameter_list|(
name|struct
name|Job
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|meta_cmd_finish
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|meta_job_finish
parameter_list|(
name|struct
name|Job
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|meta_oodate
parameter_list|(
name|GNode
modifier|*
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|meta_compat_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|meta_compat_child
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|meta_compat_parent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

