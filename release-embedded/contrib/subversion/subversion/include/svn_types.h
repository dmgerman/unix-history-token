begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_types.h  * @brief Subversion's data types  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_TYPES_H
end_define

begin_comment
comment|/* ### this should go away, but it causes too much breakage right now */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/* for ULONG_MAX */
end_comment

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_comment
comment|/* for apr_size_t, apr_int64_t, ... */
end_comment

begin_include
include|#
directive|include
file|<apr_errno.h>
end_include

begin_comment
comment|/* for apr_status_t */
end_comment

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_comment
comment|/* for apr_pool_t */
end_comment

begin_include
include|#
directive|include
file|<apr_hash.h>
end_include

begin_comment
comment|/* for apr_hash_t */
end_comment

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_comment
comment|/* for apr_array_push() */
end_comment

begin_include
include|#
directive|include
file|<apr_time.h>
end_include

begin_comment
comment|/* for apr_time_t */
end_comment

begin_include
include|#
directive|include
file|<apr_strings.h>
end_include

begin_comment
comment|/* for apr_atoi64() */
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
comment|/** Macro used to mark deprecated functions.  *  * @since New in 1.6.  */
ifndef|#
directive|ifndef
name|SVN_DEPRECATED
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SWIGPERL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SWIGPYTHON
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SWIGRUBY
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>=
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|1
operator|)
operator|)
define|#
directive|define
name|SVN_DEPRECATED
value|__attribute__((deprecated))
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1300
define|#
directive|define
name|SVN_DEPRECATED
value|__declspec(deprecated)
else|#
directive|else
define|#
directive|define
name|SVN_DEPRECATED
endif|#
directive|endif
else|#
directive|else
define|#
directive|define
name|SVN_DEPRECATED
endif|#
directive|endif
endif|#
directive|endif
comment|/** Indicate whether the current platform supports unaligned data access.  *  * On the majority of machines running SVN (x86 / x64), unaligned access  * is much cheaper than repeated aligned access. Define this macro to 1  * on those machines.  * Unaligned access on other machines (e.g. IA64) will trigger memory  * access faults or simply misbehave.  *  * Note: Some platforms may only support unaligned access for integers  * (PowerPC).  As a result this macro should only be used to determine  * if unaligned access is supported for integers.  *  * @since New in 1.7.  */
ifndef|#
directive|ifndef
name|SVN_UNALIGNED_ACCESS_IS_OK
if|#
directive|if
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
define|#
directive|define
name|SVN_UNALIGNED_ACCESS_IS_OK
value|1
else|#
directive|else
define|#
directive|define
name|SVN_UNALIGNED_ACCESS_IS_OK
value|0
endif|#
directive|endif
endif|#
directive|endif
comment|/** YABT:  Yet Another Boolean Type */
typedef|typedef
name|int
name|svn_boolean_t
typedef|;
ifndef|#
directive|ifndef
name|TRUE
comment|/** uhh... true */
define|#
directive|define
name|TRUE
value|1
endif|#
directive|endif
comment|/* TRUE */
ifndef|#
directive|ifndef
name|FALSE
comment|/** uhh... false */
define|#
directive|define
name|FALSE
value|0
endif|#
directive|endif
comment|/* FALSE */
comment|/** Subversion error object.  *  * Defined here, rather than in svn_error.h, to avoid a recursive @#include  * situation.  */
typedef|typedef
struct|struct
name|svn_error_t
block|{
comment|/** APR error value; possibly an SVN_ custom error code (see    * `svn_error_codes.h' for a full listing).    */
name|apr_status_t
name|apr_err
decl_stmt|;
comment|/** Details from the producer of error.    *    * Note that if this error was generated by Subversion's API, you'll    * probably want to use svn_err_best_message() to get a single    * descriptive string for this error chain (see the @a child member)    * or svn_handle_error2() to print the error chain in full.  This is    * because Subversion's API functions sometimes add many links to    * the error chain that lack details (used only to produce virtual    * stack traces).  (Use svn_error_purge_tracing() to remove those    * trace-only links from the error chain.)    */
specifier|const
name|char
modifier|*
name|message
decl_stmt|;
comment|/** Pointer to the error we "wrap" (may be @c NULL).  Via this    * member, individual error object can be strung together into an    * "error chain".    */
name|struct
name|svn_error_t
modifier|*
name|child
decl_stmt|;
comment|/** The pool in which this error object is allocated.  (If    * Subversion's APIs are used to manage error chains, then this pool    * will contain the whole error chain of which this object is a    * member.) */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
comment|/** Source file where the error originated (iff @c SVN_DEBUG;    * undefined otherwise).    */
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
comment|/** Source line where the error originated (iff @c SVN_DEBUG;    * undefined otherwise).    */
name|long
name|line
decl_stmt|;
block|}
name|svn_error_t
typedef|;
comment|/* See svn_version.h.    Defined here to avoid including svn_version.h from all public headers. */
typedef|typedef
name|struct
name|svn_version_t
name|svn_version_t
typedef|;
comment|/** @defgroup APR_ARRAY_compat_macros APR Array Compatibility Helper Macros  * These macros are provided by APR itself from version 1.3.  * Definitions are provided here for when using older versions of APR.  * @{  */
comment|/** index into an apr_array_header_t */
ifndef|#
directive|ifndef
name|APR_ARRAY_IDX
define|#
directive|define
name|APR_ARRAY_IDX
parameter_list|(
name|ary
parameter_list|,
name|i
parameter_list|,
name|type
parameter_list|)
value|(((type *)(ary)->elts)[i])
endif|#
directive|endif
comment|/** easier array-pushing syntax */
ifndef|#
directive|ifndef
name|APR_ARRAY_PUSH
define|#
directive|define
name|APR_ARRAY_PUSH
parameter_list|(
name|ary
parameter_list|,
name|type
parameter_list|)
value|(*((type *)apr_array_push(ary)))
endif|#
directive|endif
comment|/** @} */
comment|/** @defgroup apr_hash_utilities APR Hash Table Helpers  * These functions enable the caller to dereference an APR hash table index  * without type casts or temporary variables.  *  * ### These are private, and may go away when APR implements them natively.  * @{  */
comment|/** Return the key of the hash table entry indexed by @a hi. */
specifier|const
name|void
modifier|*
name|svn__apr_hash_index_key
parameter_list|(
specifier|const
name|apr_hash_index_t
modifier|*
name|hi
parameter_list|)
function_decl|;
comment|/** Return the key length of the hash table entry indexed by @a hi. */
name|apr_ssize_t
name|svn__apr_hash_index_klen
parameter_list|(
specifier|const
name|apr_hash_index_t
modifier|*
name|hi
parameter_list|)
function_decl|;
comment|/** Return the value of the hash table entry indexed by @a hi. */
name|void
modifier|*
name|svn__apr_hash_index_val
parameter_list|(
specifier|const
name|apr_hash_index_t
modifier|*
name|hi
parameter_list|)
function_decl|;
comment|/** @} */
comment|/** On Windows, APR_STATUS_IS_ENOTDIR includes several kinds of  * invalid-pathname error but not ERROR_INVALID_NAME, so we include it.  * We also include ERROR_DIRECTORY as that was not included in apr versions  * before 1.4.0 and this fix is not backported */
comment|/* ### These fixes should go into APR. */
ifndef|#
directive|ifndef
name|WIN32
define|#
directive|define
name|SVN__APR_STATUS_IS_ENOTDIR
parameter_list|(
name|s
parameter_list|)
value|APR_STATUS_IS_ENOTDIR(s)
else|#
directive|else
define|#
directive|define
name|SVN__APR_STATUS_IS_ENOTDIR
parameter_list|(
name|s
parameter_list|)
value|(APR_STATUS_IS_ENOTDIR(s) \                       || ((s) == APR_OS_START_SYSERR + ERROR_DIRECTORY) \                       || ((s) == APR_OS_START_SYSERR + ERROR_INVALID_NAME))
endif|#
directive|endif
comment|/** On Windows, APR_STATUS_IS_EPIPE does not include ERROR_NO_DATA error.  * So we include it.*/
comment|/* ### These fixes should go into APR. */
ifndef|#
directive|ifndef
name|WIN32
define|#
directive|define
name|SVN__APR_STATUS_IS_EPIPE
parameter_list|(
name|s
parameter_list|)
value|APR_STATUS_IS_EPIPE(s)
else|#
directive|else
define|#
directive|define
name|SVN__APR_STATUS_IS_EPIPE
parameter_list|(
name|s
parameter_list|)
value|(APR_STATUS_IS_EPIPE(s) \                       || ((s) == APR_OS_START_SYSERR + ERROR_NO_DATA))
endif|#
directive|endif
comment|/** @} */
comment|/** The various types of nodes in the Subversion filesystem. */
typedef|typedef
enum|enum
name|svn_node_kind_t
block|{
comment|/** absent */
name|svn_node_none
block|,
comment|/** regular file */
name|svn_node_file
block|,
comment|/** directory */
name|svn_node_dir
block|,
comment|/** something's here, but we don't know what */
name|svn_node_unknown
block|,
comment|/**    * symbolic link    * @note This value is not currently used by the public API.    * @since New in 1.8.    */
name|svn_node_symlink
block|}
name|svn_node_kind_t
typedef|;
comment|/** Return a constant string expressing @a kind as an English word, e.g.,  * "file", "dir", etc.  The string is not localized, as it may be used for  * client<->server communications.  If the kind is not recognized, return  * "unknown".  *  * @since New in 1.6.  */
specifier|const
name|char
modifier|*
name|svn_node_kind_to_word
parameter_list|(
name|svn_node_kind_t
name|kind
parameter_list|)
function_decl|;
comment|/** Return the appropriate node_kind for @a word.  @a word is as  * returned from svn_node_kind_to_word().  If @a word does not  * represent a recognized kind or is @c NULL, return #svn_node_unknown.  *  * @since New in 1.6.  */
name|svn_node_kind_t
name|svn_node_kind_from_word
parameter_list|(
specifier|const
name|char
modifier|*
name|word
parameter_list|)
function_decl|;
comment|/** Generic three-state property to represent an unknown value for values  * that are just like booleans.  The values have been set deliberately to  * make tristates disjoint from #svn_boolean_t.  *  * @note It is unsafe to use apr_pcalloc() to allocate these, since '0' is  * not a valid value.  *  * @since New in 1.7. */
typedef|typedef
enum|enum
name|svn_tristate_t
block|{
comment|/** state known to be false (the constant does not evaulate to false) */
name|svn_tristate_false
init|=
literal|2
block|,
comment|/** state known to be true */
name|svn_tristate_true
block|,
comment|/** state could be true or false */
name|svn_tristate_unknown
block|}
name|svn_tristate_t
typedef|;
comment|/** Return a constant string "true", "false" or NULL representing the value of  * @a tristate.  *  * @since New in 1.7.  */
specifier|const
name|char
modifier|*
name|svn_tristate__to_word
parameter_list|(
name|svn_tristate_t
name|tristate
parameter_list|)
function_decl|;
comment|/** Return the appropriate tristate for @a word. If @a word is "true", returns  * #svn_tristate_true; if @a word is "false", returns #svn_tristate_false,  * for all other values (including NULL) returns #svn_tristate_unknown.  *  * @since New in 1.7.  */
name|svn_tristate_t
name|svn_tristate__from_word
parameter_list|(
specifier|const
name|char
modifier|*
name|word
parameter_list|)
function_decl|;
comment|/** About Special Files in Subversion  *  * Subversion denotes files that cannot be portably created or  * modified as "special" files (svn_node_special).  It stores these  * files in the repository as a plain text file with the svn:special  * property set.  The file contents contain: a platform-specific type  * string, a space character, then any information necessary to create  * the file on a supported platform.  For example, if a symbolic link  * were being represented, the repository file would have the  * following contents:  *  * "link /path/to/link/target"  *  * Where 'link' is the identifier string showing that this special  * file should be a symbolic link and '/path/to/link/target' is the  * destination of the symbolic link.  *  * Special files are stored in the text-base exactly as they are  * stored in the repository.  The platform specific files are created  * in the working copy at EOL/keyword translation time using  * svn_subst_copy_and_translate2().  If the current platform does not  * support a specific special file type, the file is copied into the  * working copy as it is seen in the repository.  Because of this,  * users of other platforms can still view and modify the special  * files, even if they do not have their unique properties.  *  * New types of special files can be added by:  *  1. Implementing a platform-dependent routine to create a uniquely  *     named special file and one to read the special file in  *     libsvn_subr/io.c.  *  2. Creating a new textual name similar to  *     SVN_SUBST__SPECIAL_LINK_STR in libsvn_subr/subst.c.  *  3. Handling the translation/detranslation case for the new type in  *     create_special_file and detranslate_special_file, using the  *     routines from 1.  */
comment|/** A revision number. */
typedef|typedef
name|long
name|int
name|svn_revnum_t
typedef|;
comment|/** Valid revision numbers begin at 0 */
define|#
directive|define
name|SVN_IS_VALID_REVNUM
parameter_list|(
name|n
parameter_list|)
value|((n)>= 0)
comment|/** The 'official' invalid revision num */
define|#
directive|define
name|SVN_INVALID_REVNUM
value|((svn_revnum_t) -1)
comment|/** Not really invalid...just unimportant -- one day, this can be its  * own unique value, for now, just make it the same as  * #SVN_INVALID_REVNUM.  */
define|#
directive|define
name|SVN_IGNORED_REVNUM
value|((svn_revnum_t) -1)
comment|/** Convert NULL-terminated C string @a str to a revision number. */
define|#
directive|define
name|SVN_STR_TO_REV
parameter_list|(
name|str
parameter_list|)
value|((svn_revnum_t) atol(str))
comment|/**  * Parse NULL-terminated C string @a str as a revision number and  * store its value in @a rev.  If @a endptr is non-NULL, then the  * address of the first non-numeric character in @a str is stored in  * it.  If there are no digits in @a str, then @a endptr is set (if  * non-NULL), and the error #SVN_ERR_REVNUM_PARSE_FAILURE error is  * returned.  Negative numbers parsed from @a str are considered  * invalid, and result in the same error.  *  * @since New in 1.5.  */
name|svn_error_t
modifier|*
name|svn_revnum_parse
parameter_list|(
name|svn_revnum_t
modifier|*
name|rev
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|endptr
parameter_list|)
function_decl|;
comment|/** Originally intended to be used in printf()-style functions to format  * revision numbers.  Deprecated due to incompatibilities with language  * translation tools (e.g. gettext).  *  * New code should use a bare "%ld" format specifier for formatting revision  * numbers.  *  * @deprecated Provided for backward compatibility with the 1.0 API.  */
define|#
directive|define
name|SVN_REVNUM_T_FMT
value|"ld"
comment|/** The size of a file in the Subversion FS. */
typedef|typedef
name|apr_int64_t
name|svn_filesize_t
typedef|;
comment|/** The 'official' invalid file size constant. */
define|#
directive|define
name|SVN_INVALID_FILESIZE
value|((svn_filesize_t) -1)
comment|/** In printf()-style functions, format file sizes using this. */
define|#
directive|define
name|SVN_FILESIZE_T_FMT
value|APR_INT64_T_FMT
ifndef|#
directive|ifndef
name|DOXYGEN_SHOULD_SKIP_THIS
comment|/* Parse a base-10 numeric string into a 64-bit unsigned numeric value. */
comment|/* NOTE: Private. For use by Subversion's own code only. See issue #1644. */
comment|/* FIXME: APR should supply a function to do this, such as "apr_atoui64". */
define|#
directive|define
name|svn__atoui64
parameter_list|(
name|X
parameter_list|)
value|((apr_uint64_t) apr_atoi64(X))
endif|#
directive|endif
comment|/** An enum to indicate whether recursion is needed. */
enum|enum
name|svn_recurse_kind
block|{
name|svn_nonrecursive
init|=
literal|1
block|,
name|svn_recursive
block|}
enum|;
comment|/** The concept of depth for directories.  *  * @note This is similar to, but not exactly the same as, the WebDAV  * and LDAP concepts of depth.  *  * @since New in 1.5.  */
typedef|typedef
enum|enum
name|svn_depth_t
block|{
comment|/* The order of these depths is important: the higher the number,      the deeper it descends.  This allows us to compare two depths      numerically to decide which should govern. */
comment|/** Depth undetermined or ignored.  In some contexts, this means the       client should choose an appropriate default depth.  The server       will generally treat it as #svn_depth_infinity. */
name|svn_depth_unknown
init|=
operator|-
literal|2
block|,
comment|/** Exclude (i.e., don't descend into) directory D.       @note In Subversion 1.5, svn_depth_exclude is *not* supported       anywhere in the client-side (libsvn_wc/libsvn_client/etc) code;       it is only supported as an argument to set_path functions in the       ra and repos reporters.  (This will enable future versions of       Subversion to run updates, etc, against 1.5 servers with proper       svn_depth_exclude behavior, once we get a chance to implement       client-side support for svn_depth_exclude.)   */
name|svn_depth_exclude
init|=
operator|-
literal|1
block|,
comment|/** Just the named directory D, no entries.  Updates will not pull in       any files or subdirectories not already present. */
name|svn_depth_empty
init|=
literal|0
block|,
comment|/** D + its file children, but not subdirs.  Updates will pull in any       files not already present, but not subdirectories. */
name|svn_depth_files
init|=
literal|1
block|,
comment|/** D + immediate children (D and its entries).  Updates will pull in       any files or subdirectories not already present; those       subdirectories' this_dir entries will have depth-empty. */
name|svn_depth_immediates
init|=
literal|2
block|,
comment|/** D + all descendants (full recursion from D).  Updates will pull       in any files or subdirectories not already present; those       subdirectories' this_dir entries will have depth-infinity.       Equivalent to the pre-1.5 default update behavior. */
name|svn_depth_infinity
init|=
literal|3
block|}
name|svn_depth_t
typedef|;
comment|/** Return a constant string expressing @a depth as an English word,  * e.g., "infinity", "immediates", etc.  The string is not localized,  * as it may be used for client<->server communications.  *  * @since New in 1.5.  */
specifier|const
name|char
modifier|*
name|svn_depth_to_word
parameter_list|(
name|svn_depth_t
name|depth
parameter_list|)
function_decl|;
comment|/** Return the appropriate depth for @a depth_str.  @a word is as  * returned from svn_depth_to_word().  If @a depth_str does not  * represent a recognized depth, return #svn_depth_unknown.  *  * @since New in 1.5.  */
name|svn_depth_t
name|svn_depth_from_word
parameter_list|(
specifier|const
name|char
modifier|*
name|word
parameter_list|)
function_decl|;
comment|/** Return #svn_depth_infinity if boolean @a recurse is TRUE, else  * return #svn_depth_files.  *  * @note New code should never need to use this, it is called only  * from pre-depth APIs, for compatibility.  *  * @since New in 1.5.  */
define|#
directive|define
name|SVN_DEPTH_INFINITY_OR_FILES
parameter_list|(
name|recurse
parameter_list|)
define|\
value|((recurse) ? svn_depth_infinity : svn_depth_files)
comment|/** Return #svn_depth_infinity if boolean @a recurse is TRUE, else  * return #svn_depth_immediates.  *  * @note New code should never need to use this, it is called only  * from pre-depth APIs, for compatibility.  *  * @since New in 1.5.  */
define|#
directive|define
name|SVN_DEPTH_INFINITY_OR_IMMEDIATES
parameter_list|(
name|recurse
parameter_list|)
define|\
value|((recurse) ? svn_depth_infinity : svn_depth_immediates)
comment|/** Return #svn_depth_infinity if boolean @a recurse is TRUE, else  * return #svn_depth_empty.  *  * @note New code should never need to use this, it is called only  * from pre-depth APIs, for compatibility.  *  * @since New in 1.5.  */
define|#
directive|define
name|SVN_DEPTH_INFINITY_OR_EMPTY
parameter_list|(
name|recurse
parameter_list|)
define|\
value|((recurse) ? svn_depth_infinity : svn_depth_empty)
comment|/** Return a recursion boolean based on @a depth.  *  * Although much code has been converted to use depth, some code still  * takes a recurse boolean.  In most cases, it makes sense to treat  * unknown or infinite depth as recursive, and any other depth as  * non-recursive (which in turn usually translates to #svn_depth_files).  */
define|#
directive|define
name|SVN_DEPTH_IS_RECURSIVE
parameter_list|(
name|depth
parameter_list|)
define|\
value|((depth) == svn_depth_infinity || (depth) == svn_depth_unknown)
comment|/**  * It is sometimes convenient to indicate which parts of an #svn_dirent_t  * object you are actually interested in, so that calculating and sending  * the data corresponding to the other fields can be avoided.  These values  * can be used for that purpose.  *  * @defgroup svn_dirent_fields Dirent fields  * @{  */
comment|/** An indication that you are interested in the @c kind field */
define|#
directive|define
name|SVN_DIRENT_KIND
value|0x00001
comment|/** An indication that you are interested in the @c size field */
define|#
directive|define
name|SVN_DIRENT_SIZE
value|0x00002
comment|/** An indication that you are interested in the @c has_props field */
define|#
directive|define
name|SVN_DIRENT_HAS_PROPS
value|0x00004
comment|/** An indication that you are interested in the @c created_rev field */
define|#
directive|define
name|SVN_DIRENT_CREATED_REV
value|0x00008
comment|/** An indication that you are interested in the @c time field */
define|#
directive|define
name|SVN_DIRENT_TIME
value|0x00010
comment|/** An indication that you are interested in the @c last_author field */
define|#
directive|define
name|SVN_DIRENT_LAST_AUTHOR
value|0x00020
comment|/** A combination of all the dirent fields */
define|#
directive|define
name|SVN_DIRENT_ALL
value|~((apr_uint32_t ) 0)
comment|/** @} */
comment|/** A general subversion directory entry.  *  * @note To allow for extending the #svn_dirent_t structure in future  * releases, always use svn_dirent_create() to allocate the stucture.  *  * @since New in 1.6.  */
typedef|typedef
struct|struct
name|svn_dirent_t
block|{
comment|/** node kind */
name|svn_node_kind_t
name|kind
decl_stmt|;
comment|/** length of file text, or 0 for directories */
name|svn_filesize_t
name|size
decl_stmt|;
comment|/** does the node have props? */
name|svn_boolean_t
name|has_props
decl_stmt|;
comment|/** last rev in which this node changed */
name|svn_revnum_t
name|created_rev
decl_stmt|;
comment|/** time of created_rev (mod-time) */
name|apr_time_t
name|time
decl_stmt|;
comment|/** author of created_rev */
specifier|const
name|char
modifier|*
name|last_author
decl_stmt|;
comment|/* IMPORTANT: If you extend this struct, check svn_dirent_dup(). */
block|}
name|svn_dirent_t
typedef|;
comment|/** Return a deep copy of @a dirent, allocated in @a pool.  *  * @since New in 1.4.  */
name|svn_dirent_t
modifier|*
name|svn_dirent_dup
parameter_list|(
specifier|const
name|svn_dirent_t
modifier|*
name|dirent
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Create a new svn_dirent_t instance with all values initialized to their  * not-available values.  *  * @since New in 1.8.  */
name|svn_dirent_t
modifier|*
name|svn_dirent_create
parameter_list|(
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/** Keyword substitution.  *  * All the keywords Subversion recognizes.  *  * Note that there is a better, more general proposal out there, which  * would take care of both internationalization issues and custom  * keywords (e.g., $NetBSD$).  See  *  * @verbatim       http://subversion.tigris.org/servlets/ReadMsg?list=dev&msgNo=8921       =====       From: "Jonathan M. Manning"<jmanning@alisa-jon.net>       To: dev@subversion.tigris.org       Date: Fri, 14 Dec 2001 11:56:54 -0500       Message-ID:<87970000.1008349014@bdldevel.bl.bdx.com>       Subject: Re: keywords @endverbatim  *  * and Eric Gillespie's support of same:  *  * @verbatim       http://subversion.tigris.org/servlets/ReadMsg?list=dev&msgNo=8757       =====       From: "Eric Gillespie, Jr."<epg@pretzelnet.org>       To: dev@subversion.tigris.org       Date: Wed, 12 Dec 2001 09:48:42 -0500       Message-ID:<87k7vsebp1.fsf@vger.pretzelnet.org>       Subject: Re: Customizable Keywords @endverbatim  *  * However, it is considerably more complex than the scheme below.  * For now we're going with simplicity, hopefully the more general  * solution can be done post-1.0.  *  * @defgroup svn_types_keywords Keyword definitions  * @{  */
comment|/** The maximum size of an expanded or un-expanded keyword. */
define|#
directive|define
name|SVN_KEYWORD_MAX_LEN
value|255
comment|/** The most recent revision in which this file was changed. */
define|#
directive|define
name|SVN_KEYWORD_REVISION_LONG
value|"LastChangedRevision"
comment|/** Short version of LastChangedRevision */
define|#
directive|define
name|SVN_KEYWORD_REVISION_SHORT
value|"Rev"
comment|/** Medium version of LastChangedRevision, matching the one CVS uses.  * @since New in 1.1. */
define|#
directive|define
name|SVN_KEYWORD_REVISION_MEDIUM
value|"Revision"
comment|/** The most recent date (repository time) when this file was changed. */
define|#
directive|define
name|SVN_KEYWORD_DATE_LONG
value|"LastChangedDate"
comment|/** Short version of LastChangedDate */
define|#
directive|define
name|SVN_KEYWORD_DATE_SHORT
value|"Date"
comment|/** Who most recently committed to this file. */
define|#
directive|define
name|SVN_KEYWORD_AUTHOR_LONG
value|"LastChangedBy"
comment|/** Short version of LastChangedBy */
define|#
directive|define
name|SVN_KEYWORD_AUTHOR_SHORT
value|"Author"
comment|/** The URL for the head revision of this file. */
define|#
directive|define
name|SVN_KEYWORD_URL_LONG
value|"HeadURL"
comment|/** Short version of HeadURL */
define|#
directive|define
name|SVN_KEYWORD_URL_SHORT
value|"URL"
comment|/** A compressed combination of the other four keywords. */
define|#
directive|define
name|SVN_KEYWORD_ID
value|"Id"
comment|/** A full combination of the first four keywords.  * @since New in 1.6. */
define|#
directive|define
name|SVN_KEYWORD_HEADER
value|"Header"
comment|/** @} */
comment|/** All information about a commit.  *  * @note Objects of this type should always be created using the  * svn_create_commit_info() function.  *  * @since New in 1.3.  */
typedef|typedef
struct|struct
name|svn_commit_info_t
block|{
comment|/** just-committed revision. */
name|svn_revnum_t
name|revision
decl_stmt|;
comment|/** server-side date of the commit. */
specifier|const
name|char
modifier|*
name|date
decl_stmt|;
comment|/** author of the commit. */
specifier|const
name|char
modifier|*
name|author
decl_stmt|;
comment|/** error message from post-commit hook, or NULL. */
specifier|const
name|char
modifier|*
name|post_commit_err
decl_stmt|;
comment|/** repository root, may be @c NULL if unknown.       @since New in 1.7. */
specifier|const
name|char
modifier|*
name|repos_root
decl_stmt|;
block|}
name|svn_commit_info_t
typedef|;
comment|/**  * Allocate an object of type #svn_commit_info_t in @a pool and  * return it.  *  * The @c revision field of the new struct is set to #SVN_INVALID_REVNUM.  * All other fields are initialized to @c NULL.  *  * @note Any object of the type #svn_commit_info_t should  * be created using this function.  * This is to provide for extending the svn_commit_info_t in  * the future.  *  * @since New in 1.3.  */
name|svn_commit_info_t
modifier|*
name|svn_create_commit_info
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return a deep copy @a src_commit_info allocated in @a pool.  *  * @since New in 1.4.  */
name|svn_commit_info_t
modifier|*
name|svn_commit_info_dup
parameter_list|(
specifier|const
name|svn_commit_info_t
modifier|*
name|src_commit_info
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * A structure to represent a path that changed for a log entry.  *  * @note To allow for extending the #svn_log_changed_path2_t structure in  * future releases, always use svn_log_changed_path2_create() to allocate  * the structure.  *  * @since New in 1.6.  */
typedef|typedef
struct|struct
name|svn_log_changed_path2_t
block|{
comment|/** 'A'dd, 'D'elete, 'R'eplace, 'M'odify */
name|char
name|action
decl_stmt|;
comment|/** Source path of copy (if any). */
specifier|const
name|char
modifier|*
name|copyfrom_path
decl_stmt|;
comment|/** Source revision of copy (if any). */
name|svn_revnum_t
name|copyfrom_rev
decl_stmt|;
comment|/** The type of the node, may be svn_node_unknown. */
name|svn_node_kind_t
name|node_kind
decl_stmt|;
comment|/** Is the text modified, may be svn_tristate_unknown.    * @since New in 1.7. */
name|svn_tristate_t
name|text_modified
decl_stmt|;
comment|/** Are properties modified, may be svn_tristate_unknown.    * @since New in 1.7. */
name|svn_tristate_t
name|props_modified
decl_stmt|;
comment|/* NOTE: Add new fields at the end to preserve binary compatibility.      Also, if you add fields here, you have to update      svn_log_changed_path2_dup(). */
block|}
name|svn_log_changed_path2_t
typedef|;
comment|/**  * Returns an #svn_log_changed_path2_t, allocated in @a pool with all fields  * initialized to NULL, None or empty values.  *  * @note To allow for extending the #svn_log_changed_path2_t structure in  * future releases, this function should always be used to allocate the  * structure.  *  * @since New in 1.6.  */
name|svn_log_changed_path2_t
modifier|*
name|svn_log_changed_path2_create
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return a deep copy of @a changed_path, allocated in @a pool.  *  * @since New in 1.6.  */
name|svn_log_changed_path2_t
modifier|*
name|svn_log_changed_path2_dup
parameter_list|(
specifier|const
name|svn_log_changed_path2_t
modifier|*
name|changed_path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * A structure to represent a path that changed for a log entry.  Same as  * the first three fields of #svn_log_changed_path2_t.  *  * @deprecated Provided for backward compatibility with the 1.5 API.  */
typedef|typedef
struct|struct
name|svn_log_changed_path_t
block|{
comment|/** 'A'dd, 'D'elete, 'R'eplace, 'M'odify */
name|char
name|action
decl_stmt|;
comment|/** Source path of copy (if any). */
specifier|const
name|char
modifier|*
name|copyfrom_path
decl_stmt|;
comment|/** Source revision of copy (if any). */
name|svn_revnum_t
name|copyfrom_rev
decl_stmt|;
block|}
name|svn_log_changed_path_t
typedef|;
comment|/**  * Return a deep copy of @a changed_path, allocated in @a pool.  *  * @since New in 1.3.  * @deprecated Provided for backward compatibility with the 1.5 API.  */
name|SVN_DEPRECATED
name|svn_log_changed_path_t
modifier|*
name|svn_log_changed_path_dup
parameter_list|(
specifier|const
name|svn_log_changed_path_t
modifier|*
name|changed_path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * A structure to represent all the information about a particular log entry.  *  * @note To allow for extending the #svn_log_entry_t structure in future  * releases, always use svn_log_entry_create() to allocate the structure.  *  * @since New in 1.5.  */
typedef|typedef
struct|struct
name|svn_log_entry_t
block|{
comment|/** A hash containing as keys every path committed in @a revision; the    * values are (#svn_log_changed_path_t *) structures.    *    * The subversion core libraries will always set this field to the same    * value as changed_paths2 for compatibility reasons.    *    * @deprecated Provided for backward compatibility with the 1.5 API.    */
name|apr_hash_t
modifier|*
name|changed_paths
decl_stmt|;
comment|/** The revision of the commit. */
name|svn_revnum_t
name|revision
decl_stmt|;
comment|/** The hash of requested revision properties, which may be NULL if it    * would contain no revprops.  Maps (const char *) property name to    * (svn_string_t *) property value. */
name|apr_hash_t
modifier|*
name|revprops
decl_stmt|;
comment|/**    * Whether or not this message has children.    *    * When a log operation requests additional merge information, extra log    * entries may be returned as a result of this entry.  The new entries, are    * considered children of the original entry, and will follow it.  When    * the HAS_CHILDREN flag is set, the receiver should increment its stack    * depth, and wait until an entry is provided with SVN_INVALID_REVNUM which    * indicates the end of the children.    *    * For log operations which do not request additional merge information, the    * HAS_CHILDREN flag is always FALSE.    *    * For more information see:    * https://svn.apache.org/repos/asf/subversion/trunk/notes/merge-tracking/design.html#commutative-reporting    */
name|svn_boolean_t
name|has_children
decl_stmt|;
comment|/** A hash containing as keys every path committed in @a revision; the    * values are (#svn_log_changed_path2_t *) structures.    *    * If this value is not @c NULL, it MUST have the same value as    * changed_paths or svn_log_entry_dup() will not create an identical copy.    *    * The subversion core libraries will always set this field to the same    * value as changed_paths for compatibility with users assuming an older    * version.    *    * @note See http://svn.haxx.se/dev/archive-2010-08/0362.shtml for    * further explanation.    *    * @since New in 1.6.    */
name|apr_hash_t
modifier|*
name|changed_paths2
decl_stmt|;
comment|/**    * Whether @a revision should be interpreted as non-inheritable in the    * same sense of #svn_merge_range_t.    *    * Only set when this #svn_log_entry_t instance is returned by the    * libsvn_client mergeinfo apis. Currently always FALSE when the    * #svn_log_entry_t instance is reported by the ra layer.    *    * @since New in 1.7.    */
name|svn_boolean_t
name|non_inheritable
decl_stmt|;
comment|/**    * Whether @a revision is a merged revision resulting from a reverse merge.    *    * @since New in 1.7.    */
name|svn_boolean_t
name|subtractive_merge
decl_stmt|;
comment|/* NOTE: Add new fields at the end to preserve binary compatibility.      Also, if you add fields here, you have to update      svn_log_entry_dup(). */
block|}
name|svn_log_entry_t
typedef|;
comment|/**  * Returns an #svn_log_entry_t, allocated in @a pool with all fields  * initialized to NULL values.  *  * @note To allow for extending the #svn_log_entry_t structure in future  * releases, this function should always be used to allocate the structure.  *  * @since New in 1.5.  */
name|svn_log_entry_t
modifier|*
name|svn_log_entry_create
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return a deep copy of @a log_entry, allocated in @a pool.  *  * The resulting svn_log_entry_t has @c changed_paths set to the same  * value as @c changed_path2. @c changed_paths will be @c NULL if  * @c changed_paths2 was @c NULL.  *  * @since New in 1.6.  */
name|svn_log_entry_t
modifier|*
name|svn_log_entry_dup
parameter_list|(
specifier|const
name|svn_log_entry_t
modifier|*
name|log_entry
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** The callback invoked by log message loopers, such as  * #svn_ra_plugin_t.get_log() and svn_repos_get_logs().  *  * This function is invoked once on each log message, in the order  * determined by the caller (see above-mentioned functions).  *  * @a baton is what you think it is, and @a log_entry contains relevant  * information for the log message.  Any of @a log_entry->author,  * @a log_entry->date, or @a log_entry->message may be @c NULL.  *  * If @a log_entry->date is neither NULL nor the empty string, it was  * generated by svn_time_to_cstring() and can be converted to  * @c apr_time_t with svn_time_from_cstring().  *  * If @a log_entry->changed_paths is non-@c NULL, then it contains as keys  * every path committed in @a log_entry->revision; the values are  * (#svn_log_changed_path_t *) structures.  *  * If @a log_entry->has_children is @c TRUE, the message will be followed  * immediately by any number of merged revisions (child messages), which are  * terminated by an invocation with SVN_INVALID_REVNUM.  This usage may  * be recursive.  *  * Use @a pool for temporary allocation.  If the caller is iterating  * over log messages, invoking this receiver on each, we recommend the  * standard pool loop recipe: create a subpool, pass it as @a pool to  * each call, clear it after each iteration, destroy it after the loop  * is done.  (For allocation that must last beyond the lifetime of a  * given receiver call, use a pool in @a baton.)  *  * @since New in 1.5.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_log_entry_receiver_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|svn_log_entry_t
modifier|*
name|log_entry
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Similar to #svn_log_entry_receiver_t, except this uses separate  * parameters for each part of the log entry.  *  * @deprecated Provided for backward compatibility with the 1.4 API.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_log_message_receiver_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|apr_hash_t
modifier|*
name|changed_paths
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
specifier|const
name|char
modifier|*
name|author
parameter_list|,
specifier|const
name|char
modifier|*
name|date
parameter_list|,
comment|/* use svn_time_from_cstring() if need apr_time_t */
specifier|const
name|char
modifier|*
name|message
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Callback function type for commits.  *  * When a commit succeeds, an instance of this is invoked with the  * @a commit_info, along with the @a baton closure.  * @a pool can be used for temporary allocations.  *  * @since New in 1.4.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_commit_callback2_t
function_decl|)
parameter_list|(
specifier|const
name|svn_commit_info_t
modifier|*
name|commit_info
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Same as #svn_commit_callback2_t, but uses individual  * data elements instead of the #svn_commit_info_t structure  *  * @deprecated Provided for backward compatibility with the 1.3 API.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_commit_callback_t
function_decl|)
parameter_list|(
name|svn_revnum_t
name|new_revision
parameter_list|,
specifier|const
name|char
modifier|*
name|date
parameter_list|,
specifier|const
name|char
modifier|*
name|author
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|/** A buffer size that may be used when processing a stream of data.  *  * @note We don't use this constant any longer, since it is considered to be  * unnecessarily large.  *  * @deprecated Provided for backwards compatibility with the 1.3 API.  */
define|#
directive|define
name|SVN_STREAM_CHUNK_SIZE
value|102400
ifndef|#
directive|ifndef
name|DOXYGEN_SHOULD_SKIP_THIS
comment|/*  * The maximum amount we (ideally) hold in memory at a time when  * processing a stream of data.  *  * For example, when copying data from one stream to another, do it in  * blocks of this size.  *  * NOTE: This is an internal macro, put here for convenience.  * No public API may depend on the particular value of this macro.  */
define|#
directive|define
name|SVN__STREAM_CHUNK_SIZE
value|16384
endif|#
directive|endif
comment|/** The maximum amount we can ever hold in memory. */
comment|/* FIXME: Should this be the same as SVN_STREAM_CHUNK_SIZE? */
define|#
directive|define
name|SVN_MAX_OBJECT_SIZE
value|(((apr_size_t) -1) / 2)
comment|/* ### Note: despite being about mime-TYPES, these probably don't  * ### belong in svn_types.h.  However, no other header is more  * ### appropriate, and didn't feel like creating svn_validate.h for  * ### so little.  */
comment|/** Validate @a mime_type.  *  * If @a mime_type does not contain a "/", or ends with non-alphanumeric  * data, return #SVN_ERR_BAD_MIME_TYPE, else return success.  *  * Use @a pool only to find error allocation.  *  * Goal: to match both "foo/bar" and "foo/bar; charset=blah", without  * being too strict about it, but to disallow mime types that have  * quotes, newlines, or other garbage on the end, such as might be  * unsafe in an HTTP header.  */
name|svn_error_t
modifier|*
name|svn_mime_type_validate
parameter_list|(
specifier|const
name|char
modifier|*
name|mime_type
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return FALSE iff @a mime_type is a textual type.  *  * All mime types that start with "text/" are textual, plus some special  * cases (for example, "image/x-xbitmap").  */
name|svn_boolean_t
name|svn_mime_type_is_binary
parameter_list|(
specifier|const
name|char
modifier|*
name|mime_type
parameter_list|)
function_decl|;
comment|/** A user defined callback that subversion will call with a user defined  * baton to see if the current operation should be continued.  If the operation  * should continue, the function should return #SVN_NO_ERROR, if not, it  * should return #SVN_ERR_CANCELLED.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_cancel_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|cancel_baton
parameter_list|)
function_decl|;
comment|/**  * A lock object, for client& server to share.  *  * A lock represents the exclusive right to add, delete, or modify a  * path.  A lock is created in a repository, wholly controlled by the  * repository.  A "lock-token" is the lock's UUID, and can be used to  * learn more about a lock's fields, and or/make use of the lock.  * Because a lock is immutable, a client is free to not only cache the  * lock-token, but the lock's fields too, for convenience.  *  * Note that the 'is_dav_comment' field is wholly ignored by every  * library except for mod_dav_svn.  The field isn't even marshalled  * over the network to the client.  Assuming lock structures are  * created with apr_pcalloc(), a default value of 0 is universally safe.  *  * @note in the current implementation, only files are lockable.  *  * @since New in 1.2.  */
typedef|typedef
struct|struct
name|svn_lock_t
block|{
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
comment|/**< the path this lock applies to */
specifier|const
name|char
modifier|*
name|token
decl_stmt|;
comment|/**< unique URI representing lock */
specifier|const
name|char
modifier|*
name|owner
decl_stmt|;
comment|/**< the username which owns the lock */
specifier|const
name|char
modifier|*
name|comment
decl_stmt|;
comment|/**< (optional) description of lock  */
name|svn_boolean_t
name|is_dav_comment
decl_stmt|;
comment|/**< was comment made by generic DAV client? */
name|apr_time_t
name|creation_date
decl_stmt|;
comment|/**< when lock was made */
name|apr_time_t
name|expiration_date
decl_stmt|;
comment|/**< (optional) when lock will expire;                                       If value is 0, lock will never expire. */
block|}
name|svn_lock_t
typedef|;
comment|/**  * Returns an #svn_lock_t, allocated in @a pool with all fields initialized  * to NULL values.  *  * @note To allow for extending the #svn_lock_t structure in the future  * releases, this function should always be used to allocate the structure.  *  * @since New in 1.2.  */
name|svn_lock_t
modifier|*
name|svn_lock_create
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return a deep copy of @a lock, allocated in @a pool.  *  * @since New in 1.2.  */
name|svn_lock_t
modifier|*
name|svn_lock_dup
parameter_list|(
specifier|const
name|svn_lock_t
modifier|*
name|lock
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return a formatted Universal Unique IDentifier (UUID) string.  *  * @since New in 1.4.  */
specifier|const
name|char
modifier|*
name|svn_uuid_generate
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Mergeinfo representing a merge of a range of revisions.  *  * @since New in 1.5  */
typedef|typedef
struct|struct
name|svn_merge_range_t
block|{
comment|/**    * If the 'start' field is less than the 'end' field then 'start' is    * exclusive and 'end' inclusive of the range described.  This is termed    * a forward merge range.  If 'start' is greater than 'end' then the    * opposite is true.  This is termed a reverse merge range.  If 'start'    * equals 'end' the meaning of the range is not defined.    */
name|svn_revnum_t
name|start
decl_stmt|;
name|svn_revnum_t
name|end
decl_stmt|;
comment|/**    * Whether this merge range should be inherited by treewise    * descendants of the path to which the range applies. */
name|svn_boolean_t
name|inheritable
decl_stmt|;
block|}
name|svn_merge_range_t
typedef|;
comment|/**  * Return a copy of @a range, allocated in @a pool.  *  * @since New in 1.5.  */
name|svn_merge_range_t
modifier|*
name|svn_merge_range_dup
parameter_list|(
specifier|const
name|svn_merge_range_t
modifier|*
name|range
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Returns true if the changeset committed in revision @a rev is one  * of the changesets in the range @a range.  *  * @since New in 1.5.  */
name|svn_boolean_t
name|svn_merge_range_contains_rev
parameter_list|(
specifier|const
name|svn_merge_range_t
modifier|*
name|range
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|)
function_decl|;
comment|/** @defgroup node_location_seg_reporting Node location segment reporting.  *  @{ */
comment|/**  * A representation of a segment of an object's version history with an  * emphasis on the object's location in the repository as of various  * revisions.  *  * @since New in 1.5.  */
typedef|typedef
struct|struct
name|svn_location_segment_t
block|{
comment|/** The beginning (oldest) and ending (youngest) revisions for this       segment, both inclusive. */
name|svn_revnum_t
name|range_start
decl_stmt|;
name|svn_revnum_t
name|range_end
decl_stmt|;
comment|/** The absolute (sans leading slash) path for this segment.  May be       NULL to indicate gaps in an object's history.  */
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
block|}
name|svn_location_segment_t
typedef|;
comment|/**  * A callback invoked by generators of #svn_location_segment_t  * objects, used to report information about a versioned object's  * history in terms of its location in the repository filesystem over  * time.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_location_segment_receiver_t
function_decl|)
parameter_list|(
name|svn_location_segment_t
modifier|*
name|segment
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return a deep copy of @a segment, allocated in @a pool.  *  * @since New in 1.5.  */
name|svn_location_segment_t
modifier|*
name|svn_location_segment_dup
parameter_list|(
specifier|const
name|svn_location_segment_t
modifier|*
name|segment
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** @} */
comment|/** A line number, such as in a file or a stream.  *  * @since New in 1.7.  */
typedef|typedef
name|unsigned
name|long
name|svn_linenum_t
typedef|;
comment|/** The maximum value of an svn_linenum_t.  *  * @since New in 1.7.  */
define|#
directive|define
name|SVN_LINENUM_MAX_VALUE
value|ULONG_MAX
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

begin_comment
comment|/*  * Everybody and their brother needs to deal with svn_error_t, the error  * codes, and whatever else. While they *should* go and include svn_error.h  * in order to do that... bah. Let's just help everybody out and include  * that header whenever somebody grabs svn_types.h.  *  * Note that we do this at the END of this header so that its contents  * are available to svn_error.h (our guards will prevent the circular  * include). We also need to do the include *outside* of the cplusplus  * guard.  */
end_comment

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_comment
comment|/*  * Subversion developers may want to use some additional debugging facilities  * while working on the code. We'll pull that in here, so individual source  * files don't have to include this header manually.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_DEBUG
end_ifdef

begin_include
include|#
directive|include
file|"private/svn_debug.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_TYPES_H */
end_comment

end_unit

