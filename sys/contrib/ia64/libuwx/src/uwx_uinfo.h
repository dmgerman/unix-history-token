begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2003 Hewlett-Packard Development Company, L.P. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
end_comment

begin_struct_decl
struct_decl|struct
name|uwx_utable_entry
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|uwx_decode_uinfo
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_utable_entry
modifier|*
name|uentry
parameter_list|,
name|uint64_t
modifier|*
modifier|*
name|rstatep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uwx_default_rstate
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|uint64_t
modifier|*
modifier|*
name|rstatep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Region header record */
end_comment

begin_struct
struct|struct
name|uwx_rhdr
block|{
name|int
name|is_prologue
decl_stmt|;
comment|/* true if prologue region */
name|unsigned
name|int
name|rlen
decl_stmt|;
comment|/* length of region (# instruction slots) */
name|int
name|mask
decl_stmt|;
comment|/* register save mask */
name|int
name|grsave
decl_stmt|;
comment|/* first gr used for saving */
name|unsigned
name|int
name|ecount
decl_stmt|;
comment|/* epilogue count (0 = no epilogue) */
name|unsigned
name|int
name|epilogue_t
decl_stmt|;
comment|/* epilogue "t" value */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|uwx_bstream
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|uwx_decode_rhdr
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_bstream
modifier|*
name|bstream
parameter_list|,
name|struct
name|uwx_rhdr
modifier|*
name|rhdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uwx_decode_prologue
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_bstream
modifier|*
name|bstream
parameter_list|,
name|struct
name|uwx_scoreboard
modifier|*
name|scoreboard
parameter_list|,
name|struct
name|uwx_rhdr
modifier|*
name|rhdr
parameter_list|,
name|int
name|ip_slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uwx_decode_body
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_bstream
modifier|*
name|bstream
parameter_list|,
name|struct
name|uwx_scoreboard
modifier|*
name|scoreboard
parameter_list|,
name|struct
name|uwx_rhdr
modifier|*
name|rhdr
parameter_list|,
name|int
name|ip_slot
parameter_list|)
function_decl|;
end_function_decl

end_unit

