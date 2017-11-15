begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016-present, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under both the BSD-style license (found in the  * LICENSE file in the root directory of this source tree) and the GPLv2 (found  * in the COPYING file in the root directory of this source tree).  */
end_comment

begin_comment
comment|/******* EXPOSED TYPES ********************************************************/
end_comment

begin_comment
comment|/* * Contains the parsed contents of a dictionary * This includes Huffman and FSE tables used for decoding and data on offsets */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dictionary_s
name|dictionary_t
typedef|;
end_typedef

begin_comment
comment|/******* END EXPOSED TYPES ****************************************************/
end_comment

begin_comment
comment|/******* DECOMPRESSION FUNCTIONS **********************************************/
end_comment

begin_comment
comment|/// Zstandard decompression functions.
end_comment

begin_comment
comment|/// `dst` must point to a space at least as large as the reconstructed output.
end_comment

begin_function_decl
name|size_t
name|ZSTD_decompress
parameter_list|(
name|void
modifier|*
specifier|const
name|dst
parameter_list|,
specifier|const
name|size_t
name|dst_len
parameter_list|,
specifier|const
name|void
modifier|*
specifier|const
name|src
parameter_list|,
specifier|const
name|size_t
name|src_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// If `dict != NULL` and `dict_len>= 8`, does the same thing as
end_comment

begin_comment
comment|/// `ZSTD_decompress` but uses the provided dict
end_comment

begin_function_decl
name|size_t
name|ZSTD_decompress_with_dict
parameter_list|(
name|void
modifier|*
specifier|const
name|dst
parameter_list|,
specifier|const
name|size_t
name|dst_len
parameter_list|,
specifier|const
name|void
modifier|*
specifier|const
name|src
parameter_list|,
specifier|const
name|size_t
name|src_len
parameter_list|,
name|dictionary_t
modifier|*
name|parsed_dict
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the decompressed size of an input stream so memory can be allocated in
end_comment

begin_comment
comment|/// advance
end_comment

begin_comment
comment|/// Returns -1 if the size can't be determined
end_comment

begin_comment
comment|/// Assumes decompression of a single frame
end_comment

begin_function_decl
name|size_t
name|ZSTD_get_decompressed_size
parameter_list|(
specifier|const
name|void
modifier|*
specifier|const
name|src
parameter_list|,
specifier|const
name|size_t
name|src_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******* END DECOMPRESSION FUNCTIONS ******************************************/
end_comment

begin_comment
comment|/******* DICTIONARY MANAGEMENT ***********************************************/
end_comment

begin_comment
comment|/*  * Return a valid dictionary_t pointer for use with dictionary initialization  * or decompression  */
end_comment

begin_function_decl
name|dictionary_t
modifier|*
name|create_dictionary
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Parse a provided dictionary blob for use in decompression  * `src` -- must point to memory space representing the dictionary  * `src_len` -- must provide the dictionary size  * `dict` -- will contain the parsed contents of the dictionary and  *        can be used for decompression  */
end_comment

begin_function_decl
name|void
name|parse_dictionary
parameter_list|(
name|dictionary_t
modifier|*
specifier|const
name|dict
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|src_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free internal Huffman tables, FSE tables, and dictionary content  */
end_comment

begin_function_decl
name|void
name|free_dictionary
parameter_list|(
name|dictionary_t
modifier|*
specifier|const
name|dict
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******* END DICTIONARY MANAGEMENT *******************************************/
end_comment

end_unit

