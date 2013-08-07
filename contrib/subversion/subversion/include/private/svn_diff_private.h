begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_DIFF_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_DIFF_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
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
comment|/* The separator string used below the "Index:" or similar line of  * Subversion's Unidiff-like diff format.  */
define|#
directive|define
name|SVN_DIFF__EQUAL_STRING
define|\
value|"==================================================================="
comment|/* The separator string used below the "Properties on ..." line of  * Subversion's Unidiff-like diff format.  */
define|#
directive|define
name|SVN_DIFF__UNDER_STRING
define|\
value|"___________________________________________________________________"
comment|/* The string used to mark a line in a hunk that doesn't end with a newline,  * when diffing a file.  Intentionally not marked for translation, for wider  * interoperability with patch(1) programs. */
define|#
directive|define
name|SVN_DIFF__NO_NEWLINE_AT_END_OF_FILE
define|\
value|"\\ No newline at end of file"
comment|/* The string used to mark a line in a hunk that doesn't end with a newline,  * when diffing a Subversion property. */
define|#
directive|define
name|SVN_DIFF__NO_NEWLINE_AT_END_OF_PROPERTY
define|\
value|"\\ No newline at end of property"
comment|/* Write a unidiff "---" and "+++" header to OUTPUT_STREAM.  *  * Write "---" followed by a space and OLD_HEADER and a newline,  * then "+++" followed by a space and NEW_HEADER and a newline.  *  * The text will be encoded into HEADER_ENCODING.  */
name|svn_error_t
modifier|*
name|svn_diff__unidiff_write_header
parameter_list|(
name|svn_stream_t
modifier|*
name|output_stream
parameter_list|,
specifier|const
name|char
modifier|*
name|header_encoding
parameter_list|,
specifier|const
name|char
modifier|*
name|old_header
parameter_list|,
specifier|const
name|char
modifier|*
name|new_header
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Display property changes in pseudo-Unidiff format.  *  * Write to @a outstream the changes described by @a propchanges based on  * original properties @a original_props.  *  * Write all mark-up text (headers and so on) using the character encoding  * @a encoding.  *  *   ### I think the idea is: we want the output to use @a encoding, and  *       we will assume the text of the user's files and the values of any  *       user-defined properties are already using @a encoding, so we don't  *       want to re-code the *whole* output.  *       So, shouldn't we also convert all prop names and all 'svn:*' prop  *       values to @a encoding, since we know those are stored in UTF-8?  *  * @a original_props is a hash mapping (const char *) property names to  * (svn_string_t *) values.  @a propchanges is an array of svn_prop_t  * representing the new values for any of the properties that changed, with  * a NULL value to represent deletion.  *  * If @a pretty_print_mergeinfo is true, then describe 'svn:mergeinfo'  * property changes in a human-readable form that says what changes were  * merged or reverse merged; otherwise (or if the mergeinfo property values  * don't parse correctly) display them just like any other property.  *  * Use @a pool for temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_diff__display_prop_diffs
parameter_list|(
name|svn_stream_t
modifier|*
name|outstream
parameter_list|,
specifier|const
name|char
modifier|*
name|encoding
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|propchanges
parameter_list|,
name|apr_hash_t
modifier|*
name|original_props
parameter_list|,
name|svn_boolean_t
name|pretty_print_mergeinfo
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
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
comment|/* SVN_DIFF_PRIVATE_H */
end_comment

end_unit

