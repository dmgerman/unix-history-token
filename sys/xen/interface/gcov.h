begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * gcov.h  *  * Coverage structures exported by Xen.  * Structure is different from Gcc one.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2013, Citrix Systems R&D Ltd.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_GCOV_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_GCOV_H__
value|__XEN_PUBLIC_GCOV_H__
end_define

begin_define
define|#
directive|define
name|XENCOV_COUNTERS
value|5
end_define

begin_define
define|#
directive|define
name|XENCOV_TAG_BASE
value|0x58544300u
end_define

begin_define
define|#
directive|define
name|XENCOV_TAG_FILE
value|(XENCOV_TAG_BASE+0x46u)
end_define

begin_define
define|#
directive|define
name|XENCOV_TAG_FUNC
value|(XENCOV_TAG_BASE+0x66u)
end_define

begin_define
define|#
directive|define
name|XENCOV_TAG_COUNTER
parameter_list|(
name|n
parameter_list|)
value|(XENCOV_TAG_BASE+0x30u+((n)&0xfu))
end_define

begin_define
define|#
directive|define
name|XENCOV_TAG_END
value|(XENCOV_TAG_BASE+0x2eu)
end_define

begin_define
define|#
directive|define
name|XENCOV_IS_TAG_COUNTER
parameter_list|(
name|n
parameter_list|)
define|\
value|((n)>= XENCOV_TAG_COUNTER(0)&& (n)< XENCOV_TAG_COUNTER(XENCOV_COUNTERS))
end_define

begin_define
define|#
directive|define
name|XENCOV_COUNTER_NUM
parameter_list|(
name|n
parameter_list|)
value|((n)-XENCOV_TAG_COUNTER(0))
end_define

begin_comment
comment|/*  * The main structure for the blob is  * BLOB := FILE.. END  * FILE := TAG_FILE VERSION STAMP FILENAME COUNTERS FUNCTIONS  * FILENAME := LEN characters  *   characters are padded to 32 bit  * LEN := 32 bit value  * COUNTERS := TAG_COUNTER(n) NUM COUNTER..  * NUM := 32 bit valie  * COUNTER := 64 bit value  * FUNCTIONS := TAG_FUNC NUM FUNCTION..  * FUNCTION := IDENT CHECKSUM NUM_COUNTERS  *  * All tagged structures are aligned to 8 bytes  */
end_comment

begin_comment
comment|/**  * File information  * Prefixed with XENCOV_TAG_FILE and a string with filename  * Aligned to 8 bytes  */
end_comment

begin_struct
struct|struct
name|xencov_file
block|{
name|uint32_t
name|tag
decl_stmt|;
comment|/* XENCOV_TAG_FILE */
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|stamp
decl_stmt|;
name|uint32_t
name|fn_len
decl_stmt|;
name|char
name|filename
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Counters information  * Prefixed with XENCOV_TAG_COUNTER(n) where n is 0..(XENCOV_COUNTERS-1)  * Aligned to 8 bytes  */
end_comment

begin_struct
struct|struct
name|xencov_counter
block|{
name|uint32_t
name|tag
decl_stmt|;
comment|/* XENCOV_TAG_COUNTER(n) */
name|uint32_t
name|num
decl_stmt|;
name|uint64_t
name|values
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Information for each function  * Number of counter is equal to the number of counter structures got before  */
end_comment

begin_struct
struct|struct
name|xencov_function
block|{
name|uint32_t
name|ident
decl_stmt|;
name|uint32_t
name|checksum
decl_stmt|;
name|uint32_t
name|num_counters
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Information for all functions  * Aligned to 8 bytes  */
end_comment

begin_struct
struct|struct
name|xencov_functions
block|{
name|uint32_t
name|tag
decl_stmt|;
comment|/* XENCOV_TAG_FUNC */
name|uint32_t
name|num
decl_stmt|;
name|struct
name|xencov_function
name|xencov_function
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Terminator  */
end_comment

begin_struct
struct|struct
name|xencov_end
block|{
name|uint32_t
name|tag
decl_stmt|;
comment|/* XENCOV_TAG_END */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_GCOV_H__ */
end_comment

end_unit

