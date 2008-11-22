begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2003 Hewlett-Packard Development Company, L.P. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
end_comment

begin_struct
struct|struct
name|uwx_utable_entry
block|{
name|uint64_t
name|code_start
decl_stmt|;
name|uint64_t
name|code_end
decl_stmt|;
name|uint64_t
name|unwind_info
decl_stmt|;
name|uint64_t
name|unwind_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|uwx_search_utable
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|uint64_t
name|ip
parameter_list|,
name|uint64_t
modifier|*
name|uvec
parameter_list|,
name|struct
name|uwx_utable_entry
modifier|*
name|uentry
parameter_list|)
function_decl|;
end_function_decl

end_unit

