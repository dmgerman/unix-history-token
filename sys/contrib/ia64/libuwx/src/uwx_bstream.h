begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002,2003 Hewlett-Packard Company  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included  * in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_struct
struct|struct
name|uwx_bstream
block|{
name|copyin_cb
name|copyin
decl_stmt|;
name|intptr_t
name|cb_token
decl_stmt|;
name|uint64_t
name|source
decl_stmt|;
name|uint64_t
name|buf
decl_stmt|;
name|unsigned
name|char
modifier|*
name|bufp
decl_stmt|;
name|int
name|nbuf
decl_stmt|;
name|unsigned
name|int
name|ntotal
decl_stmt|;
name|int
name|request
decl_stmt|;
name|int
name|peekc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* uwx_init_bstream: initialize a byte stream for reading */
end_comment

begin_function_decl
specifier|extern
name|void
name|uwx_init_bstream
parameter_list|(
name|struct
name|uwx_bstream
modifier|*
name|bstream
parameter_list|,
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|uint64_t
name|source
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|,
name|int
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uwx_get_byte: read the next byte from the byte stream */
end_comment

begin_function_decl
specifier|extern
name|int
name|uwx_get_byte
parameter_list|(
name|struct
name|uwx_bstream
modifier|*
name|bstream
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uwx_unget_byte: push a byte back onto the byte stream */
end_comment

begin_function_decl
specifier|extern
name|int
name|uwx_unget_byte
parameter_list|(
name|struct
name|uwx_bstream
modifier|*
name|bstream
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uwx_get_uleb128: read a ULEB128 value from the byte stream */
end_comment

begin_function_decl
specifier|extern
name|int
name|uwx_get_uleb128
parameter_list|(
name|struct
name|uwx_bstream
modifier|*
name|bstream
parameter_list|,
name|uint64_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

end_unit

