begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2003-2006 Hewlett-Packard Development Company, L.P. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
end_comment

begin_struct_decl
struct_decl|struct
name|uwx_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uwx_symbol_cache
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|uwx_find_symbol
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_symbol_cache
modifier|*
modifier|*
name|symbol_cache_p
parameter_list|,
name|char
modifier|*
name|module_name
parameter_list|,
name|uint64_t
name|relip
parameter_list|,
name|char
modifier|*
modifier|*
name|func_name_p
parameter_list|,
name|uint64_t
modifier|*
name|offset_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|uwx_release_symbol_cache
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_symbol_cache
modifier|*
name|symbol_cache
parameter_list|)
function_decl|;
end_function_decl

end_unit

