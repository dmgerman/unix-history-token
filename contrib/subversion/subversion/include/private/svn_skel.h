begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* svn_skel.h : interface to `skeleton' functions  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_SKEL_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_SKEL_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"svn_string.h"
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
comment|/* What is a skel?  */
comment|/* Subversion needs to read a lot of structured data from database    records.  Instead of writing a half-dozen parsers and getting lazy    about error-checking, we define a reasonably dense, open-ended    syntax for strings and lists, and then use that for the concrete    representation of files, directories, property lists, etc.  This    lets us handle all the fussy character-by-character testing and    sanity checks all in one place, allowing the users of this library    to focus on higher-level consistency.     A `skeleton' (or `skel') is either an atom, or a list.  A list may    contain zero or more elements, each of which may be an atom or a    list.     Here's a description of the syntax of a skel:     A "whitespace" byte is 9, 10, 12, 13, or 32 (ASCII tab, newline,    form feed, carriage return, or space).     A "digit" byte is 48 -- 57 (ASCII digits).     A "name" byte is 65 -- 90, or 97 -- 122 (ASCII upper- and    lower-case characters).     An atom has one the following two forms:    - any string of bytes whose first byte is a name character, and      which contains no whitespace characters, bytes 40 (ASCII '(') or      bytes 41 (ASCII ')') (`implicit-length form'), or    - a string of digit bytes, followed by exactly one whitespace      character, followed by N bytes, where N is the value of the digit      bytes as a decimal number (`explicit-length form').     In the first case, the `contents' of the atom are the entire string    of characters.  In the second case, the contents of the atom are    the N bytes after the count and whitespace.     A list consists of a byte 40 (ASCII '('), followed by a series of    atoms or lists, followed by a byte 41 (ASCII ')').  There may be    zero or more whitespace characters after the '(' and before the    ')', and between any pair of elements.  If two consecutive elements    are atoms, they must be separated by at least one whitespace    character.  */
comment|/* The `skel' structure.  */
comment|/* A structure representing the results of parsing an array of bytes    as a skel.  */
struct|struct
name|svn_skel_t
block|{
comment|/* True if the string was an atom, false if it was a list.       If the string is an atom, DATA points to the beginning of its      contents, and LEN gives the content length, in bytes.       If the string is a list, DATA and LEN delimit the entire body of      the list.  */
name|svn_boolean_t
name|is_atom
decl_stmt|;
specifier|const
name|char
modifier|*
name|data
decl_stmt|;
name|apr_size_t
name|len
decl_stmt|;
comment|/* If the string is a list, CHILDREN is a pointer to a      null-terminated linked list of skel objects representing the      elements of the list, linked through their NEXT pointers.  */
name|struct
name|svn_skel_t
modifier|*
name|children
decl_stmt|;
name|struct
name|svn_skel_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
typedef|typedef
name|struct
name|svn_skel_t
name|svn_skel_t
typedef|;
comment|/* Operations on skels.  */
comment|/* Parse the LEN bytes at DATA as the concrete representation of a    skel, and return a skel object allocated from POOL describing its    contents.  If the data is not a properly-formed SKEL object, return    zero.     The returned skel objects point into the block indicated by DATA    and LEN; we don't copy the contents. */
name|svn_skel_t
modifier|*
name|svn_skel__parse
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|len
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Create an atom skel whose contents are the C string STR, allocated    from POOL.  */
name|svn_skel_t
modifier|*
name|svn_skel__str_atom
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Create an atom skel whose contents are the LEN bytes at ADDR,    allocated from POOL.  */
name|svn_skel_t
modifier|*
name|svn_skel__mem_atom
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|apr_size_t
name|len
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Create an empty list skel, allocated from POOL.  */
name|svn_skel_t
modifier|*
name|svn_skel__make_empty_list
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Duplicates the skel structure SRC_SKEL and if DUP_DATA is true also the    data it references in RESULT_POOL */
name|svn_skel_t
modifier|*
name|svn_skel__dup
parameter_list|(
specifier|const
name|svn_skel_t
modifier|*
name|src_skel
parameter_list|,
name|svn_boolean_t
name|dup_data
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Prepend SKEL to LIST.  */
name|void
name|svn_skel__prepend
parameter_list|(
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
name|svn_skel_t
modifier|*
name|list
parameter_list|)
function_decl|;
comment|/* Append SKEL to LIST. Note: this must traverse the LIST, so you    generally want to use svn_skel__prepend().     NOTE: careful of the argument order here.  */
name|void
name|svn_skel__append
parameter_list|(
name|svn_skel_t
modifier|*
name|list
parameter_list|,
name|svn_skel_t
modifier|*
name|skel
parameter_list|)
function_decl|;
comment|/* Create an atom skel whose contents are the string representation    of the integer VALUE, allocated in RESULT_POOL, and then prepend    it to SKEL.  */
name|void
name|svn_skel__prepend_int
parameter_list|(
name|apr_int64_t
name|value
parameter_list|,
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Create an atom skel (allocated from RESULT_POOL) whose contents refer    to the string VALUE, then prepend it to SKEL.     NOTE: VALUE must have a lifetime *at least* that of RESULT_POOL. This    function does NOT copy it into RESULT_POOL.  */
name|void
name|svn_skel__prepend_str
parameter_list|(
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Parse SKEL as an integer and return the result in *N.  * SCRATCH_POOL is used for temporary memory.  */
name|svn_error_t
modifier|*
name|svn_skel__parse_int
parameter_list|(
name|apr_int64_t
modifier|*
name|n
parameter_list|,
specifier|const
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Return a string whose contents are a concrete representation of    SKEL.  Allocate the string from POOL.  */
name|svn_stringbuf_t
modifier|*
name|svn_skel__unparse
parameter_list|(
specifier|const
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Return true iff SKEL is an atom whose data is the same as STR.  */
name|svn_boolean_t
name|svn_skel__matches_atom
parameter_list|(
specifier|const
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
comment|/* Return the length of the list skel SKEL.  Atoms have a length of -1.  */
name|int
name|svn_skel__list_length
parameter_list|(
specifier|const
name|svn_skel_t
modifier|*
name|skel
parameter_list|)
function_decl|;
comment|/* Parse a `PROPLIST' SKEL into a regular hash of properties,    *PROPLIST_P, which has const char * property names, and    svn_string_t * values. Use RESULT_POOL for all allocations.  */
name|svn_error_t
modifier|*
name|svn_skel__parse_proplist
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|proplist_p
parameter_list|,
specifier|const
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Parse a `IPROPS' SKEL into a depth-first ordered array of    svn_prop_inherited_item_t * structures *IPROPS. Use RESULT_POOL    for all allocations.  */
name|svn_error_t
modifier|*
name|svn_skel__parse_iprops
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|iprops
parameter_list|,
specifier|const
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Parse a `PROPLIST' SKEL looking for PROPNAME.  If PROPNAME is found    then return its value in *PROVAL, allocated in RESULT_POOL. */
name|svn_error_t
modifier|*
name|svn_skel__parse_prop
parameter_list|(
name|svn_string_t
modifier|*
modifier|*
name|propval
parameter_list|,
specifier|const
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Unparse a PROPLIST hash (which has const char * property names and    svn_string_t * values) into a `PROPLIST' skel *SKEL_P.  Use POOL    for all allocations.  */
name|svn_error_t
modifier|*
name|svn_skel__unparse_proplist
parameter_list|(
name|svn_skel_t
modifier|*
modifier|*
name|skel_p
parameter_list|,
specifier|const
name|apr_hash_t
modifier|*
name|proplist
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Unparse INHERITED_PROPS, a depth-first ordered array of    svn_prop_inherited_item_t * structures, into a `IPROPS' skel *SKEL_P.    Use RESULT_POOL for all allocations. */
name|svn_error_t
modifier|*
name|svn_skel__unparse_iproplist
parameter_list|(
name|svn_skel_t
modifier|*
modifier|*
name|skel_p
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|inherited_props
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
comment|/* SVN_SKEL_H */
end_comment

end_unit

