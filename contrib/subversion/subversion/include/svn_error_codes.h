begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_error_codes.h  * @brief Subversion error codes.  */
end_comment

begin_comment
comment|/* What's going on here?     In order to define error codes and their associated description    strings in the same place, we overload the SVN_ERRDEF() macro with    two definitions below.  Both take two arguments, an error code name    and a description string.  One definition of the macro just throws    away the string and defines enumeration constants using the error    code names -- that definition is used by the header file that    exports error codes to the rest of Subversion.  The other    definition creates a static table mapping the enum codes to their    corresponding strings -- that definition is used by the C file that    implements svn_strerror().     The header and C files both include this file, using #defines to    control which version of the macro they get. */
end_comment

begin_comment
comment|/* Process this file if we're building an error array, or if we have    not defined the enumerated constants yet.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SVN_ERROR_BUILD_ARRAY
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|SVN_ERROR_ENUM_DEFINED
argument_list|)
end_if

begin_comment
comment|/* Note: despite lacking double underscores in its name, the macro    SVN_ERROR_BUILD_ARRAY is an implementation detail of Subversion and not    a public API. */
end_comment

begin_include
include|#
directive|include
file|<apr_errno.h>
end_include

begin_comment
comment|/* APR's error system */
end_comment

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
ifndef|#
directive|ifndef
name|DOXYGEN_SHOULD_SKIP_THIS
if|#
directive|if
name|defined
argument_list|(
name|SVN_ERROR_BUILD_ARRAY
argument_list|)
define|#
directive|define
name|SVN_ERROR_START
define|\
value|static const err_defn error_table[] = { \           { SVN_WARNING, "SVN_WARNING", "Warning" },
define|#
directive|define
name|SVN_ERRDEF
parameter_list|(
name|num
parameter_list|,
name|offset
parameter_list|,
name|str
parameter_list|)
value|{ num, #num, str },
define|#
directive|define
name|SVN_ERROR_END
value|{ 0, NULL, NULL } };
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|SVN_ERROR_ENUM_DEFINED
argument_list|)
define|#
directive|define
name|SVN_ERROR_START
define|\
value|typedef enum svn_errno_t { \           SVN_WARNING = APR_OS_START_USERERR + 1,
define|#
directive|define
name|SVN_ERRDEF
parameter_list|(
name|num
parameter_list|,
name|offset
parameter_list|,
name|str
parameter_list|)
comment|/** str */
value|num = offset,
define|#
directive|define
name|SVN_ERROR_END
value|SVN_ERR_LAST } svn_errno_t;
define|#
directive|define
name|SVN_ERROR_ENUM_DEFINED
endif|#
directive|endif
comment|/* Define custom Subversion error numbers, in the range reserved for    that in APR: from APR_OS_START_USERERR to APR_OS_START_SYSERR (see    apr_errno.h).     Error numbers are divided into categories of up to 5000 errors    each.  Since we're dividing up the APR user error space, which has    room for 500,000 errors, we can have up to 100 categories.    Categories are fixed-size; if a category has fewer than 5000    errors, then it just ends with a range of unused numbers.     To maintain binary compatibility, please observe these guidelines:        - When adding a new error, always add on the end of the         appropriate category, so that the real values of existing         errors are not changed.        - When deleting an error, leave a placeholder comment indicating         the offset, again so that the values of other errors are not         perturbed. */
define|#
directive|define
name|SVN_ERR_CATEGORY_SIZE
value|5000
comment|/* Leave one category of room at the beginning, for SVN_WARNING and    any other such beasts we might create in the future. */
define|#
directive|define
name|SVN_ERR_BAD_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + ( 1 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_XML_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + ( 2 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_IO_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + ( 3 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_STREAM_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + ( 4 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_NODE_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + ( 5 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_ENTRY_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + ( 6 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_WC_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + ( 7 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_FS_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + ( 8 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_REPOS_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + ( 9 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_RA_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (10 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_RA_DAV_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (11 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_RA_LOCAL_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (12 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_SVNDIFF_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (13 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_APMOD_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (14 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_CLIENT_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (15 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_MISC_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (16 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_CL_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (17 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_RA_SVN_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (18 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_AUTHN_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (19 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_AUTHZ_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (20 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_DIFF_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (21 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_RA_SERF_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (22 * SVN_ERR_CATEGORY_SIZE))
define|#
directive|define
name|SVN_ERR_MALFUNC_CATEGORY_START
value|(APR_OS_START_USERERR \                                          + (23 * SVN_ERR_CATEGORY_SIZE))
endif|#
directive|endif
comment|/* DOXYGEN_SHOULD_SKIP_THIS */
comment|/** Collection of Subversion error code values, located within the  * APR user error space. */
name|SVN_ERROR_START
comment|/* validation ("BAD_FOO") errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_CONTAINING_POOL
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Bad parent pool passed to svn_make_pool()"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_FILENAME
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Bogus filename"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_URL
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Bogus URL"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_DATE
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Bogus date"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_MIME_TYPE
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Bogus mime-type"
argument_list|)
comment|/** @since New in 1.5.    *    * Note that there was an unused slot sitting here at    * SVN_ERR_BAD_CATEGORY_START + 5, so error codes after this aren't    * necessarily "New in 1.5" just because they come later.    */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_PROPERTY_VALUE
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Wrong or unexpected property value"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_VERSION_FILE_FORMAT
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Version file format not correct"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_RELATIVE_PATH
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"Path is not an immediate child of the specified directory"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_UUID
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|8
argument_list|,
literal|"Bogus UUID"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_CONFIG_VALUE
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|9
argument_list|,
literal|"Invalid configuration value"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_SERVER_SPECIFICATION
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|10
argument_list|,
literal|"Bogus server specification"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_CHECKSUM_KIND
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|11
argument_list|,
literal|"Unsupported checksum type"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_CHECKSUM_PARSE
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|12
argument_list|,
literal|"Invalid character in hex checksum"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_TOKEN
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|13
argument_list|,
literal|"Unknown string value of token"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_CHANGELIST_NAME
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|14
argument_list|,
literal|"Invalid changelist name"
argument_list|)
comment|/** @since New in 1.8. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_ATOMIC
argument_list|,
name|SVN_ERR_BAD_CATEGORY_START
operator|+
literal|15
argument_list|,
literal|"Invalid atomic"
argument_list|)
comment|/* xml errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_XML_ATTRIB_NOT_FOUND
argument_list|,
name|SVN_ERR_XML_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"No such XML tag attribute"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_XML_MISSING_ANCESTRY
argument_list|,
name|SVN_ERR_XML_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"<delta-pkg> is missing ancestry"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_XML_UNKNOWN_ENCODING
argument_list|,
name|SVN_ERR_XML_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Unrecognized binary data encoding; can't decode"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_XML_MALFORMED
argument_list|,
name|SVN_ERR_XML_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"XML data was not well-formed"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_XML_UNESCAPABLE_DATA
argument_list|,
name|SVN_ERR_XML_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Data cannot be safely XML-escaped"
argument_list|)
comment|/* io errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_IO_INCONSISTENT_EOL
argument_list|,
name|SVN_ERR_IO_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Inconsistent line ending style"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_IO_UNKNOWN_EOL
argument_list|,
name|SVN_ERR_IO_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Unrecognized line ending style"
argument_list|)
comment|/** @deprecated Unused, slated for removal in the next major release. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_IO_CORRUPT_EOL
argument_list|,
name|SVN_ERR_IO_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Line endings other than expected"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_IO_UNIQUE_NAMES_EXHAUSTED
argument_list|,
name|SVN_ERR_IO_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Ran out of unique names"
argument_list|)
comment|/** @deprecated Unused, slated for removal in the next major release. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_IO_PIPE_FRAME_ERROR
argument_list|,
name|SVN_ERR_IO_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Framing error in pipe protocol"
argument_list|)
comment|/** @deprecated Unused, slated for removal in the next major release. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_IO_PIPE_READ_ERROR
argument_list|,
name|SVN_ERR_IO_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Read error in pipe"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_IO_WRITE_ERROR
argument_list|,
name|SVN_ERR_IO_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Write error"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_IO_PIPE_WRITE_ERROR
argument_list|,
name|SVN_ERR_IO_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"Write error in pipe"
argument_list|)
comment|/* stream errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_STREAM_UNEXPECTED_EOF
argument_list|,
name|SVN_ERR_STREAM_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Unexpected EOF on stream"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_STREAM_MALFORMED_DATA
argument_list|,
name|SVN_ERR_STREAM_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Malformed stream data"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_STREAM_UNRECOGNIZED_DATA
argument_list|,
name|SVN_ERR_STREAM_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Unrecognized stream data"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_STREAM_SEEK_NOT_SUPPORTED
argument_list|,
name|SVN_ERR_STREAM_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Stream doesn't support seeking"
argument_list|)
comment|/* node errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_NODE_UNKNOWN_KIND
argument_list|,
name|SVN_ERR_NODE_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Unknown svn_node_kind"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_NODE_UNEXPECTED_KIND
argument_list|,
name|SVN_ERR_NODE_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Unexpected node kind found"
argument_list|)
comment|/* entry errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ENTRY_NOT_FOUND
argument_list|,
name|SVN_ERR_ENTRY_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Can't find an entry"
argument_list|)
comment|/* UNUSED error slot:                    + 1 */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ENTRY_EXISTS
argument_list|,
name|SVN_ERR_ENTRY_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Entry already exists"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ENTRY_MISSING_REVISION
argument_list|,
name|SVN_ERR_ENTRY_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Entry has no revision"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ENTRY_MISSING_URL
argument_list|,
name|SVN_ERR_ENTRY_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Entry has no URL"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ENTRY_ATTRIBUTE_INVALID
argument_list|,
name|SVN_ERR_ENTRY_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Entry has an invalid attribute"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ENTRY_FORBIDDEN
argument_list|,
name|SVN_ERR_ENTRY_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Can't create an entry for a forbidden name"
argument_list|)
comment|/* wc errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_OBSTRUCTED_UPDATE
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Obstructed update"
argument_list|)
comment|/** @deprecated Unused, slated for removal in the next major release. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_UNWIND_MISMATCH
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Mismatch popping the WC unwind stack"
argument_list|)
comment|/** @deprecated Unused, slated for removal in the next major release. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_UNWIND_EMPTY
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Attempt to pop empty WC unwind stack"
argument_list|)
comment|/** @deprecated Unused, slated for removal in the next major release. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_UNWIND_NOT_EMPTY
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Attempt to unlock with non-empty unwind stack"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_LOCKED
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Attempted to lock an already-locked dir"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_NOT_LOCKED
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Working copy not locked; this is probably a bug, please report"
argument_list|)
comment|/** @deprecated Unused, slated for removal in the next major release. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_INVALID_LOCK
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Invalid lock"
argument_list|)
comment|/** @since New in 1.7. Previously this error number was used by    * #SVN_ERR_WC_NOT_DIRECTORY, which is now an alias for this error. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_NOT_WORKING_COPY
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"Path is not a working copy directory"
argument_list|)
comment|/** @deprecated Provided for backward compatibility with the 1.6 API.    * Use #SVN_ERR_WC_NOT_WORKING_COPY. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_NOT_DIRECTORY
argument_list|,
name|SVN_ERR_WC_NOT_WORKING_COPY
argument_list|,
literal|"Path is not a working copy directory"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_NOT_FILE
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|8
argument_list|,
literal|"Path is not a working copy file"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_BAD_ADM_LOG
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|9
argument_list|,
literal|"Problem running log"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_PATH_NOT_FOUND
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|10
argument_list|,
literal|"Can't find a working copy path"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_NOT_UP_TO_DATE
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|11
argument_list|,
literal|"Working copy is not up-to-date"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_LEFT_LOCAL_MOD
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|12
argument_list|,
literal|"Left locally modified or unversioned files"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_SCHEDULE_CONFLICT
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|13
argument_list|,
literal|"Unmergeable scheduling requested on an entry"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_PATH_FOUND
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|14
argument_list|,
literal|"Found a working copy path"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_FOUND_CONFLICT
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|15
argument_list|,
literal|"A conflict in the working copy obstructs the current operation"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_CORRUPT
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|16
argument_list|,
literal|"Working copy is corrupt"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_CORRUPT_TEXT_BASE
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|17
argument_list|,
literal|"Working copy text base is corrupt"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_NODE_KIND_CHANGE
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|18
argument_list|,
literal|"Cannot change node kind"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_INVALID_OP_ON_CWD
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|19
argument_list|,
literal|"Invalid operation on the current working directory"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_BAD_ADM_LOG_START
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|20
argument_list|,
literal|"Problem on first log entry in a working copy"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_UNSUPPORTED_FORMAT
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|21
argument_list|,
literal|"Unsupported working copy format"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_BAD_PATH
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|22
argument_list|,
literal|"Path syntax not supported in this context"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_INVALID_SCHEDULE
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|23
argument_list|,
literal|"Invalid schedule"
argument_list|)
comment|/** @since New in 1.3. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_INVALID_RELOCATION
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|24
argument_list|,
literal|"Invalid relocation"
argument_list|)
comment|/** @since New in 1.3. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_INVALID_SWITCH
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|25
argument_list|,
literal|"Invalid switch"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_MISMATCHED_CHANGELIST
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|26
argument_list|,
literal|"Changelist doesn't match"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_CONFLICT_RESOLVER_FAILURE
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|27
argument_list|,
literal|"Conflict resolution failed"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_COPYFROM_PATH_NOT_FOUND
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|28
argument_list|,
literal|"Failed to locate 'copyfrom' path in working copy"
argument_list|)
comment|/** @since New in 1.5.    * @deprecated Provided for backward compatibility with the 1.6 API.    * This event is not an error, and is now reported    * via the standard notification mechanism instead. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_CHANGELIST_MOVE
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|29
argument_list|,
literal|"Moving a path from one changelist to another"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_CANNOT_DELETE_FILE_EXTERNAL
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|30
argument_list|,
literal|"Cannot delete a file external"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_CANNOT_MOVE_FILE_EXTERNAL
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|31
argument_list|,
literal|"Cannot move a file external"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_DB_ERROR
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|32
argument_list|,
literal|"Something's amiss with the wc sqlite database"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_MISSING
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|33
argument_list|,
literal|"The working copy is missing"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_NOT_SYMLINK
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|34
argument_list|,
literal|"The specified node is not a symlink"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_PATH_UNEXPECTED_STATUS
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|35
argument_list|,
literal|"The specified path has an unexpected status"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_UPGRADE_REQUIRED
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|36
argument_list|,
literal|"The working copy needs to be upgraded"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_CLEANUP_REQUIRED
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|37
argument_list|,
literal|"Previous operation has not finished; "
literal|"run 'cleanup' if it was interrupted"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_INVALID_OPERATION_DEPTH
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|38
argument_list|,
literal|"The operation cannot be performed with the specified depth"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_PATH_ACCESS_DENIED
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|39
argument_list|,
literal|"Couldn't open a working copy file because access was denied"
argument_list|)
comment|/** @since New in 1.8. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_MIXED_REVISIONS
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|40
argument_list|,
literal|"Mixed-revision working copy was found but not expected"
argument_list|)
comment|/** @since New in 1.8 */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_WC_DUPLICATE_EXTERNALS_TARGET
argument_list|,
name|SVN_ERR_WC_CATEGORY_START
operator|+
literal|41
argument_list|,
literal|"Duplicate targets in svn:externals property"
argument_list|)
comment|/* fs errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_GENERAL
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"General filesystem error"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_CLEANUP
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Error closing filesystem"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_ALREADY_OPEN
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Filesystem is already open"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NOT_OPEN
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Filesystem is not open"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_CORRUPT
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Filesystem is corrupt"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_PATH_SYNTAX
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Invalid filesystem path syntax"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_SUCH_REVISION
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Invalid filesystem revision number"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_SUCH_TRANSACTION
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"Invalid filesystem transaction name"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_SUCH_ENTRY
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|8
argument_list|,
literal|"Filesystem directory has no such entry"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_SUCH_REPRESENTATION
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|9
argument_list|,
literal|"Filesystem has no such representation"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_SUCH_STRING
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|10
argument_list|,
literal|"Filesystem has no such string"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_SUCH_COPY
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|11
argument_list|,
literal|"Filesystem has no such copy"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_TRANSACTION_NOT_MUTABLE
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|12
argument_list|,
literal|"The specified transaction is not mutable"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NOT_FOUND
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|13
argument_list|,
literal|"Filesystem has no item"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_ID_NOT_FOUND
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|14
argument_list|,
literal|"Filesystem has no such node-rev-id"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NOT_ID
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|15
argument_list|,
literal|"String does not represent a node or node-rev-id"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NOT_DIRECTORY
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|16
argument_list|,
literal|"Name does not refer to a filesystem directory"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NOT_FILE
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|17
argument_list|,
literal|"Name does not refer to a filesystem file"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NOT_SINGLE_PATH_COMPONENT
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|18
argument_list|,
literal|"Name is not a single path component"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NOT_MUTABLE
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|19
argument_list|,
literal|"Attempt to change immutable filesystem node"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_ALREADY_EXISTS
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|20
argument_list|,
literal|"Item already exists in filesystem"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_ROOT_DIR
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|21
argument_list|,
literal|"Attempt to remove or recreate fs root dir"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NOT_TXN_ROOT
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|22
argument_list|,
literal|"Object is not a transaction root"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NOT_REVISION_ROOT
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|23
argument_list|,
literal|"Object is not a revision root"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_CONFLICT
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|24
argument_list|,
literal|"Merge conflict during commit"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_REP_CHANGED
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|25
argument_list|,
literal|"A representation vanished or changed between reads"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_REP_NOT_MUTABLE
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|26
argument_list|,
literal|"Tried to change an immutable representation"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_MALFORMED_SKEL
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|27
argument_list|,
literal|"Malformed skeleton data"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_TXN_OUT_OF_DATE
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|28
argument_list|,
literal|"Transaction is out of date"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_BERKELEY_DB
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|29
argument_list|,
literal|"Berkeley DB error"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_BERKELEY_DB_DEADLOCK
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|30
argument_list|,
literal|"Berkeley DB deadlock error"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_TRANSACTION_DEAD
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|31
argument_list|,
literal|"Transaction is dead"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_TRANSACTION_NOT_DEAD
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|32
argument_list|,
literal|"Transaction is not dead"
argument_list|)
comment|/** @since New in 1.1. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_UNKNOWN_FS_TYPE
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|33
argument_list|,
literal|"Unknown FS type"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_USER
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|34
argument_list|,
literal|"No user associated with filesystem"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_PATH_ALREADY_LOCKED
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|35
argument_list|,
literal|"Path is already locked"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_PATH_NOT_LOCKED
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|36
argument_list|,
literal|"Path is not locked"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_BAD_LOCK_TOKEN
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|37
argument_list|,
literal|"Lock token is incorrect"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_LOCK_TOKEN
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|38
argument_list|,
literal|"No lock token provided"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_LOCK_OWNER_MISMATCH
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|39
argument_list|,
literal|"Username does not match lock owner"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_SUCH_LOCK
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|40
argument_list|,
literal|"Filesystem has no such lock"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_LOCK_EXPIRED
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|41
argument_list|,
literal|"Lock has expired"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_OUT_OF_DATE
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|42
argument_list|,
literal|"Item is out of date"
argument_list|)
comment|/**@since New in 1.2.    *    * This is analogous to SVN_ERR_REPOS_UNSUPPORTED_VERSION.  To avoid    * confusion with "versions" (i.e., releases) of Subversion, we've    * started calling this the "format" number instead.  The old    * SVN_ERR_REPOS_UNSUPPORTED_VERSION error predates this and so    * retains its name.    */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_UNSUPPORTED_FORMAT
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|43
argument_list|,
literal|"Unsupported FS format"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_REP_BEING_WRITTEN
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|44
argument_list|,
literal|"Representation is being written"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_TXN_NAME_TOO_LONG
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|45
argument_list|,
literal|"The generated transaction name is too long"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_SUCH_NODE_ORIGIN
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|46
argument_list|,
literal|"Filesystem has no such node origin record"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_UNSUPPORTED_UPGRADE
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|47
argument_list|,
literal|"Filesystem upgrade is not supported"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_NO_SUCH_CHECKSUM_REP
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|48
argument_list|,
literal|"Filesystem has no such checksum-representation index record"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_PROP_BASEVALUE_MISMATCH
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|49
argument_list|,
literal|"Property value in filesystem differs from the provided "
literal|"base value"
argument_list|)
comment|/** @since New in 1.8. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_INCORRECT_EDITOR_COMPLETION
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|50
argument_list|,
literal|"The filesystem editor completion process was not followed"
argument_list|)
comment|/** @since New in 1.8. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_PACKED_REVPROP_READ_FAILURE
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|51
argument_list|,
literal|"A packed revprop could not be read"
argument_list|)
comment|/** @since New in 1.8. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_FS_REVPROP_CACHE_INIT_FAILURE
argument_list|,
name|SVN_ERR_FS_CATEGORY_START
operator|+
literal|52
argument_list|,
literal|"Could not initialize the revprop caching infrastructure."
argument_list|)
comment|/* repos errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_LOCKED
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"The repository is locked, perhaps for db recovery"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_HOOK_FAILURE
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"A repository hook failed"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_BAD_ARGS
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Incorrect arguments supplied"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_NO_DATA_FOR_REPORT
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"A report cannot be generated because no data was supplied"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_BAD_REVISION_REPORT
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Bogus revision report"
argument_list|)
comment|/* This is analogous to SVN_ERR_FS_UNSUPPORTED_FORMAT.  To avoid    * confusion with "versions" (i.e., releases) of Subversion, we    * started using the word "format" instead of "version".  However,    * this error code's name predates that decision.    */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_UNSUPPORTED_VERSION
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Unsupported repository version"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_DISABLED_FEATURE
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Disabled repository feature"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_POST_COMMIT_HOOK_FAILED
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"Error running post-commit hook"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_POST_LOCK_HOOK_FAILED
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|8
argument_list|,
literal|"Error running post-lock hook"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_POST_UNLOCK_HOOK_FAILED
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|9
argument_list|,
literal|"Error running post-unlock hook"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REPOS_UNSUPPORTED_UPGRADE
argument_list|,
name|SVN_ERR_REPOS_CATEGORY_START
operator|+
literal|10
argument_list|,
literal|"Repository upgrade is not supported"
argument_list|)
comment|/* generic RA errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_ILLEGAL_URL
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Bad URL passed to RA layer"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_NOT_AUTHORIZED
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Authorization failed"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_UNKNOWN_AUTH
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Unknown authorization method"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_NOT_IMPLEMENTED
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Repository access method not implemented"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_OUT_OF_DATE
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Item is out of date"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_NO_REPOS_UUID
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Repository has no UUID"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_UNSUPPORTED_ABI_VERSION
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Unsupported RA plugin ABI version"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_NOT_LOCKED
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"Path is not locked"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_PARTIAL_REPLAY_NOT_SUPPORTED
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|8
argument_list|,
literal|"Server can only replay from the root of a repository"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_UUID_MISMATCH
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|9
argument_list|,
literal|"Repository UUID does not match expected UUID"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_REPOS_ROOT_URL_MISMATCH
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|10
argument_list|,
literal|"Repository root URL does not match expected root URL"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SESSION_URL_MISMATCH
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|11
argument_list|,
literal|"Session URL does not match expected session URL"
argument_list|)
comment|/** @since New in 1.8. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_CANNOT_CREATE_TUNNEL
argument_list|,
name|SVN_ERR_RA_CATEGORY_START
operator|+
literal|12
argument_list|,
literal|"Can't create tunnel"
argument_list|)
comment|/* ra_dav errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_SOCK_INIT
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"RA layer failed to init socket layer"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_CREATING_REQUEST
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"RA layer failed to create HTTP request"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_REQUEST_FAILED
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"RA layer request failed"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_OPTIONS_REQ_FAILED
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"RA layer didn't receive requested OPTIONS info"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_PROPS_NOT_FOUND
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"RA layer failed to fetch properties"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_ALREADY_EXISTS
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"RA layer file already exists"
argument_list|)
comment|/** @deprecated To improve consistency between ra layers, this error code       is replaced by SVN_ERR_BAD_CONFIG_VALUE.       Slated for removal in the next major release. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_INVALID_CONFIG_VALUE
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Invalid configuration value"
argument_list|)
comment|/** @deprecated To improve consistency between ra layers, this error code       is replaced in ra_serf by SVN_ERR_FS_NOT_FOUND.       Slated for removal in the next major release. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_PATH_NOT_FOUND
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"HTTP Path Not Found"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_PROPPATCH_FAILED
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|8
argument_list|,
literal|"Failed to execute WebDAV PROPPATCH"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_MALFORMED_DATA
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|9
argument_list|,
literal|"Malformed network data"
argument_list|)
comment|/** @since New in 1.3 */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_RESPONSE_HEADER_BADNESS
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|10
argument_list|,
literal|"Unable to extract data from response header"
argument_list|)
comment|/** @since New in 1.5 */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_RELOCATED
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|11
argument_list|,
literal|"Repository has been moved"
argument_list|)
comment|/** @since New in 1.7 */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_CONN_TIMEOUT
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|12
argument_list|,
literal|"Connection timed out"
argument_list|)
comment|/** @since New in 1.6 */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_DAV_FORBIDDEN
argument_list|,
name|SVN_ERR_RA_DAV_CATEGORY_START
operator|+
literal|13
argument_list|,
literal|"URL access forbidden for unknown reason"
argument_list|)
comment|/* ra_local errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_LOCAL_REPOS_NOT_FOUND
argument_list|,
name|SVN_ERR_RA_LOCAL_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Couldn't find a repository"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_LOCAL_REPOS_OPEN_FAILED
argument_list|,
name|SVN_ERR_RA_LOCAL_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Couldn't open a repository"
argument_list|)
comment|/* svndiff errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SVNDIFF_INVALID_HEADER
argument_list|,
name|SVN_ERR_SVNDIFF_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Svndiff data has invalid header"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SVNDIFF_CORRUPT_WINDOW
argument_list|,
name|SVN_ERR_SVNDIFF_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Svndiff data contains corrupt window"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SVNDIFF_BACKWARD_VIEW
argument_list|,
name|SVN_ERR_SVNDIFF_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Svndiff data contains backward-sliding source view"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SVNDIFF_INVALID_OPS
argument_list|,
name|SVN_ERR_SVNDIFF_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Svndiff data contains invalid instruction"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SVNDIFF_UNEXPECTED_END
argument_list|,
name|SVN_ERR_SVNDIFF_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Svndiff data ends unexpectedly"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SVNDIFF_INVALID_COMPRESSED_DATA
argument_list|,
name|SVN_ERR_SVNDIFF_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Svndiff compressed data is invalid"
argument_list|)
comment|/* mod_dav_svn errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_APMOD_MISSING_PATH_TO_FS
argument_list|,
name|SVN_ERR_APMOD_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Apache has no path to an SVN filesystem"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_APMOD_MALFORMED_URI
argument_list|,
name|SVN_ERR_APMOD_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Apache got a malformed URI"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_APMOD_ACTIVITY_NOT_FOUND
argument_list|,
name|SVN_ERR_APMOD_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Activity not found"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_APMOD_BAD_BASELINE
argument_list|,
name|SVN_ERR_APMOD_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Baseline incorrect"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_APMOD_CONNECTION_ABORTED
argument_list|,
name|SVN_ERR_APMOD_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Input/output error"
argument_list|)
comment|/* libsvn_client errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_VERSIONED_PATH_REQUIRED
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"A path under version control is needed for this operation"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_RA_ACCESS_REQUIRED
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Repository access is needed for this operation"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_BAD_REVISION
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Bogus revision information given"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_DUPLICATE_COMMIT_URL
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Attempting to commit to a URL more than once"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_IS_BINARY_FILE
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Operation does not apply to binary file"
argument_list|)
comment|/*### SVN_PROP_EXTERNALS needed to be replaced with "svn:externals"          in order to get gettext translatable strings */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_INVALID_EXTERNALS_DESCRIPTION
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Format of an svn:externals property was invalid"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_MODIFIED
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Attempting restricted operation for modified resource"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_IS_DIRECTORY
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"Operation does not apply to directory"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_REVISION_RANGE
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|8
argument_list|,
literal|"Revision range is not allowed"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_INVALID_RELOCATION
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|9
argument_list|,
literal|"Inter-repository relocation not allowed"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_REVISION_AUTHOR_CONTAINS_NEWLINE
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|10
argument_list|,
literal|"Author name cannot contain a newline"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_PROPERTY_NAME
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|11
argument_list|,
literal|"Bad property name"
argument_list|)
comment|/** @since New in 1.1. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_UNRELATED_RESOURCES
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|12
argument_list|,
literal|"Two versioned resources are unrelated"
argument_list|)
comment|/** @since New in 1.2. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_MISSING_LOCK_TOKEN
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|13
argument_list|,
literal|"Path has no lock token"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_MULTIPLE_SOURCES_DISALLOWED
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|14
argument_list|,
literal|"Operation does not support multiple sources"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_NO_VERSIONED_PARENT
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|15
argument_list|,
literal|"No versioned parent directories"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_NOT_READY_TO_MERGE
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|16
argument_list|,
literal|"Working copy and merge source not ready for reintegration"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_FILE_EXTERNAL_OVERWRITE_VERSIONED
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|17
argument_list|,
literal|"A file external cannot overwrite an existing versioned item"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_PATCH_BAD_STRIP_COUNT
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|18
argument_list|,
literal|"Invalid path component strip count specified"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_CYCLE_DETECTED
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|19
argument_list|,
literal|"Detected a cycle while processing the operation"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_MERGE_UPDATE_REQUIRED
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|20
argument_list|,
literal|"Working copy and merge source not ready for reintegration"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_INVALID_MERGEINFO_NO_MERGETRACKING
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|21
argument_list|,
literal|"Invalid mergeinfo detected in merge target"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_NO_LOCK_TOKEN
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|22
argument_list|,
literal|"Can't perform this operation without a valid lock token"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CLIENT_FORBIDDEN_BY_SERVER
argument_list|,
name|SVN_ERR_CLIENT_CATEGORY_START
operator|+
literal|23
argument_list|,
literal|"The operation is forbidden by the server"
argument_list|)
comment|/* misc errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BASE
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"A problem occurred; see other errors for details"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_PLUGIN_LOAD_FAILURE
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Failure loading plugin"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_MALFORMED_FILE
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Malformed file"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_INCOMPLETE_DATA
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Incomplete data"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_INCORRECT_PARAMS
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Incorrect parameters given"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_UNVERSIONED_RESOURCE
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Tried a versioning operation on an unversioned resource"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_TEST_FAILED
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Test failed"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_UNSUPPORTED_FEATURE
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"Trying to use an unsupported feature"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_BAD_PROP_KIND
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|8
argument_list|,
literal|"Unexpected or unknown property kind"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ILLEGAL_TARGET
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|9
argument_list|,
literal|"Illegal target for the requested operation"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_DELTA_MD5_CHECKSUM_ABSENT
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|10
argument_list|,
literal|"MD5 checksum is missing"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_DIR_NOT_EMPTY
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|11
argument_list|,
literal|"Directory needs to be empty but is not"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_EXTERNAL_PROGRAM
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|12
argument_list|,
literal|"Error calling external program"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SWIG_PY_EXCEPTION_SET
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|13
argument_list|,
literal|"Python exception has been set with the error"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CHECKSUM_MISMATCH
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|14
argument_list|,
literal|"A checksum mismatch occurred"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CANCELLED
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|15
argument_list|,
literal|"The operation was interrupted"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_INVALID_DIFF_OPTION
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|16
argument_list|,
literal|"The specified diff option is not supported"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_PROPERTY_NOT_FOUND
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|17
argument_list|,
literal|"Property not found"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_NO_AUTH_FILE_PATH
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|18
argument_list|,
literal|"No auth file path available"
argument_list|)
comment|/** @since New in 1.1. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_VERSION_MISMATCH
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|19
argument_list|,
literal|"Incompatible library version"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_MERGEINFO_PARSE_ERROR
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|20
argument_list|,
literal|"Mergeinfo parse error"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CEASE_INVOCATION
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|21
argument_list|,
literal|"Cease invocation of this API"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_REVNUM_PARSE_FAILURE
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|22
argument_list|,
literal|"Error parsing revision number"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ITER_BREAK
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|23
argument_list|,
literal|"Iteration terminated before completion"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_UNKNOWN_CHANGELIST
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|24
argument_list|,
literal|"Unknown changelist"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RESERVED_FILENAME_SPECIFIED
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|25
argument_list|,
literal|"Reserved directory name in command line arguments"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_UNKNOWN_CAPABILITY
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|26
argument_list|,
literal|"Inquiry about unknown capability"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_TEST_SKIPPED
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|27
argument_list|,
literal|"Test skipped"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_NO_APR_MEMCACHE
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|28
argument_list|,
literal|"APR memcache library not available"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ATOMIC_INIT_FAILURE
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|29
argument_list|,
literal|"Couldn't perform atomic initialization"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SQLITE_ERROR
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|30
argument_list|,
literal|"SQLite error"
argument_list|)
comment|/** @since New in 1.6. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SQLITE_READONLY
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|31
argument_list|,
literal|"Attempted to write to readonly SQLite db"
argument_list|)
comment|/** @since New in 1.6.    * @deprecated the internal sqlite support code does not manage schemas    * any longer.  */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SQLITE_UNSUPPORTED_SCHEMA
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|32
argument_list|,
literal|"Unsupported schema found in SQLite db"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SQLITE_BUSY
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|33
argument_list|,
literal|"The SQLite db is busy"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SQLITE_RESETTING_FOR_ROLLBACK
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|34
argument_list|,
literal|"SQLite busy at transaction rollback; "
literal|"resetting all busy SQLite statements to allow rollback"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_SQLITE_CONSTRAINT
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|35
argument_list|,
literal|"Constraint error in SQLite db"
argument_list|)
comment|/** @since New in 1.8. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_TOO_MANY_MEMCACHED_SERVERS
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|36
argument_list|,
literal|"Too many memcached servers configured"
argument_list|)
comment|/** @since New in 1.8. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_MALFORMED_VERSION_STRING
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|37
argument_list|,
literal|"Failed to parse version number string"
argument_list|)
comment|/** @since New in 1.8. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CORRUPTED_ATOMIC_STORAGE
argument_list|,
name|SVN_ERR_MISC_CATEGORY_START
operator|+
literal|38
argument_list|,
literal|"Atomic data storage is corrupt"
argument_list|)
comment|/* command-line client errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_ARG_PARSING_ERROR
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Error parsing arguments"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_INSUFFICIENT_ARGS
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Not enough arguments provided"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_MUTUALLY_EXCLUSIVE_ARGS
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Mutually exclusive arguments specified"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_ADM_DIR_RESERVED
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Attempted command in administrative dir"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_LOG_MESSAGE_IS_VERSIONED_FILE
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"The log message file is under version control"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_LOG_MESSAGE_IS_PATHNAME
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"The log message is a pathname"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_COMMIT_IN_ADDED_DIR
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Committing in directory scheduled for addition"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_NO_EXTERNAL_EDITOR
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"No external editor available"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_BAD_LOG_MESSAGE
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|8
argument_list|,
literal|"Something is wrong with the log message's contents"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_UNNECESSARY_LOG_MESSAGE
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|9
argument_list|,
literal|"A log message was given where none was necessary"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_NO_EXTERNAL_MERGE_TOOL
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|10
argument_list|,
literal|"No external merge tool available"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CL_ERROR_PROCESSING_EXTERNALS
argument_list|,
name|SVN_ERR_CL_CATEGORY_START
operator|+
literal|11
argument_list|,
literal|"Failed processing one or more externals definitions"
argument_list|)
comment|/* ra_svn errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SVN_CMD_ERR
argument_list|,
name|SVN_ERR_RA_SVN_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Special code for wrapping server errors to report to client"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SVN_UNKNOWN_CMD
argument_list|,
name|SVN_ERR_RA_SVN_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Unknown svn protocol command"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SVN_CONNECTION_CLOSED
argument_list|,
name|SVN_ERR_RA_SVN_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Network connection closed unexpectedly"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SVN_IO_ERROR
argument_list|,
name|SVN_ERR_RA_SVN_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Network read/write error"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SVN_MALFORMED_DATA
argument_list|,
name|SVN_ERR_RA_SVN_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Malformed network data"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SVN_REPOS_NOT_FOUND
argument_list|,
name|SVN_ERR_RA_SVN_CATEGORY_START
operator|+
literal|5
argument_list|,
literal|"Couldn't find a repository"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SVN_BAD_VERSION
argument_list|,
name|SVN_ERR_RA_SVN_CATEGORY_START
operator|+
literal|6
argument_list|,
literal|"Client/server version mismatch"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SVN_NO_MECHANISMS
argument_list|,
name|SVN_ERR_RA_SVN_CATEGORY_START
operator|+
literal|7
argument_list|,
literal|"Cannot negotiate authentication mechanism"
argument_list|)
comment|/** @since New in 1.7  */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SVN_EDIT_ABORTED
argument_list|,
name|SVN_ERR_RA_SVN_CATEGORY_START
operator|+
literal|8
argument_list|,
literal|"Editor drive was aborted"
argument_list|)
comment|/* libsvn_auth errors */
comment|/* this error can be used when an auth provider doesn't have           the creds, but no other "real" error occurred. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_AUTHN_CREDS_UNAVAILABLE
argument_list|,
name|SVN_ERR_AUTHN_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Credential data unavailable"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_AUTHN_NO_PROVIDER
argument_list|,
name|SVN_ERR_AUTHN_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"No authentication provider available"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_AUTHN_PROVIDERS_EXHAUSTED
argument_list|,
name|SVN_ERR_AUTHN_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"All authentication providers exhausted"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_AUTHN_CREDS_NOT_SAVED
argument_list|,
name|SVN_ERR_AUTHN_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Credentials not saved"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_AUTHN_FAILED
argument_list|,
name|SVN_ERR_AUTHN_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Authentication failed"
argument_list|)
comment|/* authorization errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_AUTHZ_ROOT_UNREADABLE
argument_list|,
name|SVN_ERR_AUTHZ_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Read access denied for root of edit"
argument_list|)
comment|/** @since New in 1.1. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_AUTHZ_UNREADABLE
argument_list|,
name|SVN_ERR_AUTHZ_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Item is not readable"
argument_list|)
comment|/** @since New in 1.1. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_AUTHZ_PARTIALLY_READABLE
argument_list|,
name|SVN_ERR_AUTHZ_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Item is partially readable"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_AUTHZ_INVALID_CONFIG
argument_list|,
name|SVN_ERR_AUTHZ_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"Invalid authz configuration"
argument_list|)
comment|/** @since New in 1.3 */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_AUTHZ_UNWRITABLE
argument_list|,
name|SVN_ERR_AUTHZ_CATEGORY_START
operator|+
literal|4
argument_list|,
literal|"Item is not writable"
argument_list|)
comment|/* libsvn_diff errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_DIFF_DATASOURCE_MODIFIED
argument_list|,
name|SVN_ERR_DIFF_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Diff data source modified unexpectedly"
argument_list|)
comment|/* libsvn_ra_serf errors */
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SERF_SSPI_INITIALISATION_FAILED
argument_list|,
name|SVN_ERR_RA_SERF_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Initialization of SSPI library failed"
argument_list|)
comment|/** @since New in 1.5. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SERF_SSL_CERT_UNTRUSTED
argument_list|,
name|SVN_ERR_RA_SERF_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"Server SSL certificate untrusted"
argument_list|)
comment|/** @since New in 1.7.       @deprecated GSSAPI now handled by serf rather than libsvn_ra_serf. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SERF_GSSAPI_INITIALISATION_FAILED
argument_list|,
name|SVN_ERR_RA_SERF_CATEGORY_START
operator|+
literal|2
argument_list|,
literal|"Initialization of the GSSAPI context failed"
argument_list|)
comment|/** @since New in 1.7. */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_RA_SERF_WRAPPED_ERROR
argument_list|,
name|SVN_ERR_RA_SERF_CATEGORY_START
operator|+
literal|3
argument_list|,
literal|"While handling serf response:"
argument_list|)
comment|/* malfunctions such as assertion failures */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ASSERTION_FAIL
argument_list|,
name|SVN_ERR_MALFUNC_CATEGORY_START
operator|+
literal|0
argument_list|,
literal|"Assertion failure"
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_ASSERTION_ONLY_TRACING_LINKS
argument_list|,
name|SVN_ERR_MALFUNC_CATEGORY_START
operator|+
literal|1
argument_list|,
literal|"No non-tracing links found in the error chain"
argument_list|)
name|SVN_ERROR_END
undef|#
directive|undef
name|SVN_ERROR_START
undef|#
directive|undef
name|SVN_ERRDEF
undef|#
directive|undef
name|SVN_ERROR_END
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
comment|/* defined(SVN_ERROR_BUILD_ARRAY) || !defined(SVN_ERROR_ENUM_DEFINED) */
end_comment

end_unit

