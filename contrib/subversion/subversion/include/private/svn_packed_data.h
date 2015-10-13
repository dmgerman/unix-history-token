begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* packed_data.h : Interface to the packed binary stream data structure  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_PACKED_DATA_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_PACKED_DATA_H
end_define

begin_include
include|#
directive|include
file|"svn_string.h"
end_include

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/* This API provides Yet Another Serialization Framework.  *  * It is geared towards efficiently encoding collections of structured  * binary data (e.g. an array of noderev objects).  The basic idea is to  * transform them into hierarchies of streams with each stream usually  * corresponding to a single attribute in the original data structures.  * The user is free model the mapping structure<-> streams mapping as she  * sees fit.  *  * With all data inside the same (sub-)stream carrying similar attribute  * values, the whole stream lends itself to data compression.  Strings /  * plain byte sequences will be stored as is.  Numbers use a 7b/8b encoding  * scheme to eliminate leading zeros.  Because values are often dependent  * (increasing offsets, roughly similar revision number, etc.), streams  * can be configured as storing (hopefully shorter) deltas instead of the  * original value.  *  * Two stream types are provided: integer and byte streams.  While the  * first store 64 bit integers only and can be configured to assume  * signed and / or deltifyable data, the second will store arbitrary  * byte sequences including their length.  At the root level, you may  * create an arbitrary number of integer and byte streams.  Any stream  * may have an arbitrary number of sub-streams of the same kind.  You  * should create the full stream hierarchy before writing any data to it.  *  * As a convenience, when an integer stream has sub-streams, you may write  * to the parent stream instead of all sub-streams individually and the  * values will be passed down automatically in a round-robin fashion.  * Reading from the parent stream is similarly supported.  *  * When all data has been added to the stream, it can be written to an  * ordinary svn_stream_t.  First, we write a description of the stream  * structure (types, sub-streams, sizes and configurations) followed by  * zlib compressed stream content.  For each top-level stream, all sub-  * stream data will be concatenated and then compressed as a single block.  * To maximize the effect of this, make sure all data in that stream  * hierarchy has a similar value distribution.  *  * Reading data starts with an svn_stream_t and automatically recreates  * the stream hierarchies.  You only need to extract data from it in the  * same order as you wrote it.  *  * Although not enforced programmatically, you may either only write to a  * stream hierarchy or only read from it but you cannot do both on the  * same data structure.  */
comment|/* We pack / unpack integers en block to minimize calling and setup overhead.  * This is the number of integers we put into a buffer before writing them  * them to / after reading them from the 7b/8b stream.  Under 64 bits, this  * value creates a 128 byte data structure (14 + 2 integers, 8 bytes each).  */
define|#
directive|define
name|SVN__PACKED_DATA_BUFFER_SIZE
value|14
comment|/* Data types. */
comment|/* Opaque type for the root object.  */
typedef|typedef
name|struct
name|svn_packed__data_root_t
name|svn_packed__data_root_t
typedef|;
comment|/* Opaque type for byte streams.  */
typedef|typedef
name|struct
name|svn_packed__byte_stream_t
name|svn_packed__byte_stream_t
typedef|;
comment|/* Semi-opaque type for integer streams.  We expose the unpacked buffer  * to allow for replacing svn_packed__add_uint and friends by macros.  */
typedef|typedef
struct|struct
name|svn_packed__int_stream_t
block|{
comment|/* pointer to the remainder of the data structure */
name|void
modifier|*
name|private_data
decl_stmt|;
comment|/* number of value entries in BUFFER */
name|apr_size_t
name|buffer_used
decl_stmt|;
comment|/* unpacked integers (either yet to be packed or pre-fetched from the    * packed buffers).  Only the first BUFFER_USED entries are valid. */
name|apr_uint64_t
name|buffer
index|[
name|SVN__PACKED_DATA_BUFFER_SIZE
index|]
decl_stmt|;
block|}
name|svn_packed__int_stream_t
typedef|;
comment|/* Writing data. */
comment|/* Return a new serialization root object, allocated in POOL.  */
name|svn_packed__data_root_t
modifier|*
name|svn_packed__data_create_root
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Create and return a new top-level integer stream in ROOT.  If signed,  * negative numbers will be put into that stream, SIGNED_INTS should be  * TRUE as a more efficient encoding will be used in that case.  Set  * DIFF to TRUE if you expect the difference between consecutive numbers  * to be much smaller (~100 times) than the actual numbers.  */
name|svn_packed__int_stream_t
modifier|*
name|svn_packed__create_int_stream
parameter_list|(
name|svn_packed__data_root_t
modifier|*
name|root
parameter_list|,
name|svn_boolean_t
name|diff
parameter_list|,
name|svn_boolean_t
name|signed_ints
parameter_list|)
function_decl|;
comment|/* Create and return a sub-stream to the existing integer stream PARENT.  * If signed, negative numbers will be put into that stream, SIGNED_INTS  * should be TRUE as a more efficient encoding will be used in that case.  * Set DIFF to TRUE if you expect the difference between consecutive numbers  * to be much smaller (~100 times) than the actual numbers.  */
name|svn_packed__int_stream_t
modifier|*
name|svn_packed__create_int_substream
parameter_list|(
name|svn_packed__int_stream_t
modifier|*
name|parent
parameter_list|,
name|svn_boolean_t
name|diff
parameter_list|,
name|svn_boolean_t
name|signed_ints
parameter_list|)
function_decl|;
comment|/* Create and return a new top-level byte sequence stream in ROOT.  */
name|svn_packed__byte_stream_t
modifier|*
name|svn_packed__create_bytes_stream
parameter_list|(
name|svn_packed__data_root_t
modifier|*
name|root
parameter_list|)
function_decl|;
comment|/* Write the unsigned integer VALUE to STEAM.  */
name|void
name|svn_packed__add_uint
parameter_list|(
name|svn_packed__int_stream_t
modifier|*
name|stream
parameter_list|,
name|apr_uint64_t
name|value
parameter_list|)
function_decl|;
comment|/* Write the signed integer VALUE to STEAM.  */
name|void
name|svn_packed__add_int
parameter_list|(
name|svn_packed__int_stream_t
modifier|*
name|stream
parameter_list|,
name|apr_int64_t
name|value
parameter_list|)
function_decl|;
comment|/* Write the sequence stating at DATA containing LEN bytes to STEAM.  */
name|void
name|svn_packed__add_bytes
parameter_list|(
name|svn_packed__byte_stream_t
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/* Write all contents of ROOT (including all sub-streams) to STREAM.  * Use SCRATCH_POOL for temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_packed__data_write
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|svn_packed__data_root_t
modifier|*
name|root
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Reading data. */
comment|/* Return the first integer stream in ROOT.  Returns NULL in case there  * aren't any.  */
name|svn_packed__int_stream_t
modifier|*
name|svn_packed__first_int_stream
parameter_list|(
name|svn_packed__data_root_t
modifier|*
name|root
parameter_list|)
function_decl|;
comment|/* Return the first byte sequence stream in ROOT.  Returns NULL in case  * there aren't any.  */
name|svn_packed__byte_stream_t
modifier|*
name|svn_packed__first_byte_stream
parameter_list|(
name|svn_packed__data_root_t
modifier|*
name|root
parameter_list|)
function_decl|;
comment|/* Return the next (sibling) integer stream to STREAM.  Returns NULL in  * case there isn't any.  */
name|svn_packed__int_stream_t
modifier|*
name|svn_packed__next_int_stream
parameter_list|(
name|svn_packed__int_stream_t
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Return the next (sibling) byte sequence stream to STREAM.  Returns NULL  * in case there isn't any.  */
name|svn_packed__byte_stream_t
modifier|*
name|svn_packed__next_byte_stream
parameter_list|(
name|svn_packed__byte_stream_t
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Return the first sub-stream of STREAM.  Returns NULL in case there  * isn't any.  */
name|svn_packed__int_stream_t
modifier|*
name|svn_packed__first_int_substream
parameter_list|(
name|svn_packed__int_stream_t
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Return the number of integers left to read from STREAM.  */
name|apr_size_t
name|svn_packed__int_count
parameter_list|(
name|svn_packed__int_stream_t
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Return the number of bytes left to read from STREAM.  */
name|apr_size_t
name|svn_packed__byte_count
parameter_list|(
name|svn_packed__byte_stream_t
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Return the next number from STREAM as unsigned integer.  Returns 0 when  * reading beyond the end of the stream.  */
name|apr_uint64_t
name|svn_packed__get_uint
parameter_list|(
name|svn_packed__int_stream_t
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Return the next number from STREAM as signed integer.  Returns 0 when  * reading beyond the end of the stream.  */
name|apr_int64_t
name|svn_packed__get_int
parameter_list|(
name|svn_packed__int_stream_t
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Return the next byte sequence from STREAM and set *LEN to the length  * of that sequence.  Sets *LEN to 0 when reading beyond the end of the  * stream.  */
specifier|const
name|char
modifier|*
name|svn_packed__get_bytes
parameter_list|(
name|svn_packed__byte_stream_t
modifier|*
name|stream
parameter_list|,
name|apr_size_t
modifier|*
name|len
parameter_list|)
function_decl|;
comment|/* Allocate a new packed data root in RESULT_POOL, read its structure and  * stream contents from STREAM and return it in *ROOT_P.  Use SCRATCH_POOL  * for temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_packed__data_read
parameter_list|(
name|svn_packed__data_root_t
modifier|*
modifier|*
name|root_p
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_PACKED_DATA_H */
end_comment

end_unit

