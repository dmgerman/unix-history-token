begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_FILE_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|APR_FILE_INFO_H
end_define

begin_comment
comment|/**  * @file apr_file_info.h  * @brief APR File Information  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_user.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_tables.h"
end_include

begin_include
include|#
directive|include
file|"apr_time.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_SYS_UIO_H
end_if

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/**  * @defgroup apr_file_info File Information  * @ingroup APR   * @{  */
comment|/* Many applications use the type member to determine the  * existance of a file or initialization of the file info,  * so the APR_NOFILE value must be distinct from APR_UNKFILE.  */
comment|/** apr_filetype_e values for the filetype member of the   * apr_file_info_t structure  * @warning: Not all of the filetypes below can be determined.  * For example, a given platform might not correctly report   * a socket descriptor as APR_SOCK if that type isn't   * well-identified on that platform.  In such cases where  * a filetype exists but cannot be described by the recognized  * flags below, the filetype will be APR_UNKFILE.  If the  * filetype member is not determined, the type will be APR_NOFILE.  */
typedef|typedef
enum|enum
block|{
name|APR_NOFILE
init|=
literal|0
block|,
comment|/**< no file type determined */
name|APR_REG
block|,
comment|/**< a regular file */
name|APR_DIR
block|,
comment|/**< a directory */
name|APR_CHR
block|,
comment|/**< a character device */
name|APR_BLK
block|,
comment|/**< a block device */
name|APR_PIPE
block|,
comment|/**< a FIFO / pipe */
name|APR_LNK
block|,
comment|/**< a symbolic link */
name|APR_SOCK
block|,
comment|/**< a [unix domain] socket */
name|APR_UNKFILE
init|=
literal|127
comment|/**< a file of some other unknown type */
block|}
name|apr_filetype_e
typedef|;
comment|/**  * @defgroup apr_file_permissions File Permissions flags   * @{  */
define|#
directive|define
name|APR_FPROT_USETID
value|0x8000
comment|/**< Set user id */
define|#
directive|define
name|APR_FPROT_UREAD
value|0x0400
comment|/**< Read by user */
define|#
directive|define
name|APR_FPROT_UWRITE
value|0x0200
comment|/**< Write by user */
define|#
directive|define
name|APR_FPROT_UEXECUTE
value|0x0100
comment|/**< Execute by user */
define|#
directive|define
name|APR_FPROT_GSETID
value|0x4000
comment|/**< Set group id */
define|#
directive|define
name|APR_FPROT_GREAD
value|0x0040
comment|/**< Read by group */
define|#
directive|define
name|APR_FPROT_GWRITE
value|0x0020
comment|/**< Write by group */
define|#
directive|define
name|APR_FPROT_GEXECUTE
value|0x0010
comment|/**< Execute by group */
define|#
directive|define
name|APR_FPROT_WSTICKY
value|0x2000
comment|/**< Sticky bit */
define|#
directive|define
name|APR_FPROT_WREAD
value|0x0004
comment|/**< Read by others */
define|#
directive|define
name|APR_FPROT_WWRITE
value|0x0002
comment|/**< Write by others */
define|#
directive|define
name|APR_FPROT_WEXECUTE
value|0x0001
comment|/**< Execute by others */
define|#
directive|define
name|APR_FPROT_OS_DEFAULT
value|0x0FFF
comment|/**< use OS's default permissions */
comment|/* additional permission flags for apr_file_copy  and apr_file_append */
define|#
directive|define
name|APR_FPROT_FILE_SOURCE_PERMS
value|0x1000
comment|/**< Copy source file's permissions */
comment|/* backcompat */
define|#
directive|define
name|APR_USETID
value|APR_FPROT_USETID
comment|/**< @deprecated @see APR_FPROT_USETID     */
define|#
directive|define
name|APR_UREAD
value|APR_FPROT_UREAD
comment|/**< @deprecated @see APR_FPROT_UREAD      */
define|#
directive|define
name|APR_UWRITE
value|APR_FPROT_UWRITE
comment|/**< @deprecated @see APR_FPROT_UWRITE     */
define|#
directive|define
name|APR_UEXECUTE
value|APR_FPROT_UEXECUTE
comment|/**< @deprecated @see APR_FPROT_UEXECUTE   */
define|#
directive|define
name|APR_GSETID
value|APR_FPROT_GSETID
comment|/**< @deprecated @see APR_FPROT_GSETID     */
define|#
directive|define
name|APR_GREAD
value|APR_FPROT_GREAD
comment|/**< @deprecated @see APR_FPROT_GREAD      */
define|#
directive|define
name|APR_GWRITE
value|APR_FPROT_GWRITE
comment|/**< @deprecated @see APR_FPROT_GWRITE     */
define|#
directive|define
name|APR_GEXECUTE
value|APR_FPROT_GEXECUTE
comment|/**< @deprecated @see APR_FPROT_GEXECUTE   */
define|#
directive|define
name|APR_WSTICKY
value|APR_FPROT_WSTICKY
comment|/**< @deprecated @see APR_FPROT_WSTICKY    */
define|#
directive|define
name|APR_WREAD
value|APR_FPROT_WREAD
comment|/**< @deprecated @see APR_FPROT_WREAD      */
define|#
directive|define
name|APR_WWRITE
value|APR_FPROT_WWRITE
comment|/**< @deprecated @see APR_FPROT_WWRITE     */
define|#
directive|define
name|APR_WEXECUTE
value|APR_FPROT_WEXECUTE
comment|/**< @deprecated @see APR_FPROT_WEXECUTE   */
define|#
directive|define
name|APR_OS_DEFAULT
value|APR_FPROT_OS_DEFAULT
comment|/**< @deprecated @see APR_FPROT_OS_DEFAULT */
define|#
directive|define
name|APR_FILE_SOURCE_PERMS
value|APR_FPROT_FILE_SOURCE_PERMS
comment|/**< @deprecated @see APR_FPROT_FILE_SOURCE_PERMS */
comment|/** @} */
comment|/**  * Structure for referencing directories.  */
typedef|typedef
name|struct
name|apr_dir_t
name|apr_dir_t
typedef|;
comment|/**  * Structure for determining file permissions.  */
typedef|typedef
name|apr_int32_t
name|apr_fileperms_t
typedef|;
if|#
directive|if
operator|(
name|defined
name|WIN32
operator|)
operator|||
operator|(
name|defined
name|NETWARE
operator|)
comment|/**  * Structure for determining the device the file is on.  */
typedef|typedef
name|apr_uint32_t
name|apr_dev_t
typedef|;
else|#
directive|else
comment|/**  * Structure for determining the device the file is on.  */
typedef|typedef
name|dev_t
name|apr_dev_t
typedef|;
endif|#
directive|endif
comment|/**  * @defgroup apr_file_stat Stat Functions  * @{  */
comment|/** file info structure */
typedef|typedef
name|struct
name|apr_finfo_t
name|apr_finfo_t
typedef|;
define|#
directive|define
name|APR_FINFO_LINK
value|0x00000001
comment|/**< Stat the link not the file itself if it is a link */
define|#
directive|define
name|APR_FINFO_MTIME
value|0x00000010
comment|/**< Modification Time */
define|#
directive|define
name|APR_FINFO_CTIME
value|0x00000020
comment|/**< Creation or inode-changed time */
define|#
directive|define
name|APR_FINFO_ATIME
value|0x00000040
comment|/**< Access Time */
define|#
directive|define
name|APR_FINFO_SIZE
value|0x00000100
comment|/**< Size of the file */
define|#
directive|define
name|APR_FINFO_CSIZE
value|0x00000200
comment|/**< Storage size consumed by the file */
define|#
directive|define
name|APR_FINFO_DEV
value|0x00001000
comment|/**< Device */
define|#
directive|define
name|APR_FINFO_INODE
value|0x00002000
comment|/**< Inode */
define|#
directive|define
name|APR_FINFO_NLINK
value|0x00004000
comment|/**< Number of links */
define|#
directive|define
name|APR_FINFO_TYPE
value|0x00008000
comment|/**< Type */
define|#
directive|define
name|APR_FINFO_USER
value|0x00010000
comment|/**< User */
define|#
directive|define
name|APR_FINFO_GROUP
value|0x00020000
comment|/**< Group */
define|#
directive|define
name|APR_FINFO_UPROT
value|0x00100000
comment|/**< User protection bits */
define|#
directive|define
name|APR_FINFO_GPROT
value|0x00200000
comment|/**< Group protection bits */
define|#
directive|define
name|APR_FINFO_WPROT
value|0x00400000
comment|/**< World protection bits */
define|#
directive|define
name|APR_FINFO_ICASE
value|0x01000000
comment|/**< if dev is case insensitive */
define|#
directive|define
name|APR_FINFO_NAME
value|0x02000000
comment|/**< ->name in proper case */
define|#
directive|define
name|APR_FINFO_MIN
value|0x00008170
comment|/**< type, mtime, ctime, atime, size */
define|#
directive|define
name|APR_FINFO_IDENT
value|0x00003000
comment|/**< dev and inode */
define|#
directive|define
name|APR_FINFO_OWNER
value|0x00030000
comment|/**< user and group */
define|#
directive|define
name|APR_FINFO_PROT
value|0x00700000
comment|/**<  all protections */
define|#
directive|define
name|APR_FINFO_NORM
value|0x0073b170
comment|/**<  an atomic unix apr_stat() */
define|#
directive|define
name|APR_FINFO_DIRENT
value|0x02000000
comment|/**<  an atomic unix apr_dir_read() */
comment|/**  * The file information structure.  This is analogous to the POSIX  * stat structure.  */
struct|struct
name|apr_finfo_t
block|{
comment|/** Allocates memory and closes lingering handles in the specified pool */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
comment|/** The bitmask describing valid fields of this apr_finfo_t structure       *  including all available 'wanted' fields and potentially more */
name|apr_int32_t
name|valid
decl_stmt|;
comment|/** The access permissions of the file.  Mimics Unix access rights. */
name|apr_fileperms_t
name|protection
decl_stmt|;
comment|/** The type of file.  One of APR_REG, APR_DIR, APR_CHR, APR_BLK, APR_PIPE,       * APR_LNK or APR_SOCK.  If the type is undetermined, the value is APR_NOFILE.      * If the type cannot be determined, the value is APR_UNKFILE.      */
name|apr_filetype_e
name|filetype
decl_stmt|;
comment|/** The user id that owns the file */
name|apr_uid_t
name|user
decl_stmt|;
comment|/** The group id that owns the file */
name|apr_gid_t
name|group
decl_stmt|;
comment|/** The inode of the file. */
name|apr_ino_t
name|inode
decl_stmt|;
comment|/** The id of the device the file is on. */
name|apr_dev_t
name|device
decl_stmt|;
comment|/** The number of hard links to the file. */
name|apr_int32_t
name|nlink
decl_stmt|;
comment|/** The size of the file */
name|apr_off_t
name|size
decl_stmt|;
comment|/** The storage size consumed by the file */
name|apr_off_t
name|csize
decl_stmt|;
comment|/** The time the file was last accessed */
name|apr_time_t
name|atime
decl_stmt|;
comment|/** The time the file was last modified */
name|apr_time_t
name|mtime
decl_stmt|;
comment|/** The time the file was created, or the inode was last changed */
name|apr_time_t
name|ctime
decl_stmt|;
comment|/** The pathname of the file (possibly unrooted) */
specifier|const
name|char
modifier|*
name|fname
decl_stmt|;
comment|/** The file's name (no path) in filesystem case */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/** Unused */
name|struct
name|apr_file_t
modifier|*
name|filehand
decl_stmt|;
block|}
struct|;
comment|/**  * get the specified file's stats.  The file is specified by filename,   * instead of using a pre-opened file.  * @param finfo Where to store the information about the file, which is  * never touched if the call fails.  * @param fname The name of the file to stat.  * @param wanted The desired apr_finfo_t fields, as a bit flag of APR_FINFO_                  values   * @param pool the pool to use to allocate the new file.   *  * @note If @c APR_INCOMPLETE is returned all the fields in @a finfo may  *       not be filled in, and you need to check the @c finfo->valid bitmask  *       to verify that what you're looking for is there.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_stat
argument_list|(
argument|apr_finfo_t *finfo
argument_list|,
argument|const char *fname
argument_list|,
argument|apr_int32_t wanted
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/** @} */
comment|/**  * @defgroup apr_dir Directory Manipulation Functions  * @{  */
comment|/**  * Open the specified directory.  * @param new_dir The opened directory descriptor.  * @param dirname The full path to the directory (use / on all systems)  * @param pool The pool to use.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dir_open
argument_list|(
name|apr_dir_t
operator|*
operator|*
name|new_dir
argument_list|,
specifier|const
name|char
operator|*
name|dirname
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * close the specified directory.   * @param thedir the directory descriptor to close.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dir_close
argument_list|(
name|apr_dir_t
operator|*
name|thedir
argument_list|)
expr_stmt|;
comment|/**  * Read the next entry from the specified directory.   * @param finfo the file info structure and filled in by apr_dir_read  * @param wanted The desired apr_finfo_t fields, as a bit flag of APR_FINFO_                  values   * @param thedir the directory descriptor returned from apr_dir_open  * @remark No ordering is guaranteed for the entries read.  *  * @note If @c APR_INCOMPLETE is returned all the fields in @a finfo may  *       not be filled in, and you need to check the @c finfo->valid bitmask  *       to verify that what you're looking for is there. When no more  *       entries are available, APR_ENOENT is returned.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dir_read
argument_list|(
argument|apr_finfo_t *finfo
argument_list|,
argument|apr_int32_t wanted
argument_list|,
argument|apr_dir_t *thedir
argument_list|)
empty_stmt|;
comment|/**  * Rewind the directory to the first entry.  * @param thedir the directory descriptor to rewind.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dir_rewind
argument_list|(
name|apr_dir_t
operator|*
name|thedir
argument_list|)
expr_stmt|;
comment|/** @} */
comment|/**  * @defgroup apr_filepath Filepath Manipulation Functions  * @{  */
comment|/** Cause apr_filepath_merge to fail if addpath is above rootpath   * @bug in APR 0.9 and 1.x, this flag's behavior is undefined  * if the rootpath is NULL or empty.  In APR 2.0 this should be  * changed to imply NOTABSOLUTE if the rootpath is NULL or empty.  */
define|#
directive|define
name|APR_FILEPATH_NOTABOVEROOT
value|0x01
comment|/** internal: Only meaningful with APR_FILEPATH_NOTABOVEROOT */
define|#
directive|define
name|APR_FILEPATH_SECUREROOTTEST
value|0x02
comment|/** Cause apr_filepath_merge to fail if addpath is above rootpath,  * even given a rootpath /foo/bar and an addpath ../bar/bash  */
define|#
directive|define
name|APR_FILEPATH_SECUREROOT
value|0x03
comment|/** Fail apr_filepath_merge if the merged path is relative */
define|#
directive|define
name|APR_FILEPATH_NOTRELATIVE
value|0x04
comment|/** Fail apr_filepath_merge if the merged path is absolute */
define|#
directive|define
name|APR_FILEPATH_NOTABSOLUTE
value|0x08
comment|/** Return the file system's native path format (e.g. path delimiters  * of ':' on MacOS9, '\' on Win32, etc.) */
define|#
directive|define
name|APR_FILEPATH_NATIVE
value|0x10
comment|/** Resolve the true case of existing directories and file elements  * of addpath, (resolving any aliases on Win32) and append a proper   * trailing slash if a directory  */
define|#
directive|define
name|APR_FILEPATH_TRUENAME
value|0x20
comment|/**  * Extract the rootpath from the given filepath  * @param rootpath the root file path returned with APR_SUCCESS or APR_EINCOMPLETE  * @param filepath the pathname to parse for its root component  * @param flags the desired rules to apply, from  *<PRE>  *      APR_FILEPATH_NATIVE    Use native path separators (e.g. '\' on Win32)  *      APR_FILEPATH_TRUENAME  Tests that the root exists, and makes it proper  *</PRE>  * @param p the pool to allocate the new path string from  * @remark on return, filepath points to the first non-root character in the  * given filepath.  In the simplest example, given a filepath of "/foo",   * returns the rootpath of "/" and filepath points at "foo".  This is far   * more complex on other platforms, which will canonicalize the root form  * to a consistant format, given the APR_FILEPATH_TRUENAME flag, and also  * test for the validity of that root (e.g., that a drive d:/ or network   * share //machine/foovol/).   * The function returns APR_ERELATIVE if filepath isn't rooted (an  * error), APR_EINCOMPLETE if the root path is ambiguous (but potentially  * legitimate, e.g. "/" on Windows is incomplete because it doesn't specify  * the drive letter), or APR_EBADPATH if the root is simply invalid.  * APR_SUCCESS is returned if filepath is an absolute path.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_filepath_root
argument_list|(
argument|const char **rootpath
argument_list|,
argument|const char **filepath
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|apr_pool_t *p
argument_list|)
empty_stmt|;
comment|/**  * Merge additional file path onto the previously processed rootpath  * @param newpath the merged paths returned  * @param rootpath the root file path (NULL uses the current working path)  * @param addpath the path to add to the root path  * @param flags the desired APR_FILEPATH_ rules to apply when merging  * @param p the pool to allocate the new path string from  * @remark if the flag APR_FILEPATH_TRUENAME is given, and the addpath   * contains wildcard characters ('*', '?') on platforms that don't support   * such characters within filenames, the paths will be merged, but the   * result code will be APR_EPATHWILD, and all further segments will not  * reflect the true filenames including the wildcard and following segments.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_filepath_merge
argument_list|(
argument|char **newpath
argument_list|,
argument|const char *rootpath
argument_list|,
argument|const char *addpath
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|apr_pool_t *p
argument_list|)
empty_stmt|;
comment|/**  * Split a search path into separate components  * @param pathelts the returned components of the search path  * @param liststr the search path (e.g.,<tt>getenv("PATH")</tt>)  * @param p the pool to allocate the array and path components from  * @remark empty path components do not become part of @a pathelts.  * @remark the path separator in @a liststr is system specific;  * e.g., ':' on Unix, ';' on Windows, etc.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_filepath_list_split
argument_list|(
name|apr_array_header_t
operator|*
operator|*
name|pathelts
argument_list|,
specifier|const
name|char
operator|*
name|liststr
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Merge a list of search path components into a single search path  * @param liststr the returned search path; may be NULL if @a pathelts is empty  * @param pathelts the components of the search path  * @param p the pool to allocate the search path from  * @remark emtpy strings in the source array are ignored.  * @remark the path separator in @a liststr is system specific;  * e.g., ':' on Unix, ';' on Windows, etc.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_filepath_list_merge
argument_list|(
name|char
operator|*
operator|*
name|liststr
argument_list|,
name|apr_array_header_t
operator|*
name|pathelts
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Return the default file path (for relative file names)  * @param path the default path string returned  * @param flags optional flag APR_FILEPATH_NATIVE to retrieve the  *              default file path in os-native format.  * @param p the pool to allocate the default path string from  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_filepath_get
argument_list|(
argument|char **path
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|apr_pool_t *p
argument_list|)
empty_stmt|;
comment|/**  * Set the default file path (for relative file names)  * @param path the default path returned  * @param p the pool to allocate any working storage  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_filepath_set
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/** The FilePath character encoding is unknown */
define|#
directive|define
name|APR_FILEPATH_ENCODING_UNKNOWN
value|0
comment|/** The FilePath character encoding is locale-dependent */
define|#
directive|define
name|APR_FILEPATH_ENCODING_LOCALE
value|1
comment|/** The FilePath character encoding is UTF-8 */
define|#
directive|define
name|APR_FILEPATH_ENCODING_UTF8
value|2
comment|/**  * Determine the encoding used internally by the FilePath functions  * @param style points to a variable which receives the encoding style flag  * @param p the pool to allocate any working storage  * @remark Use @c apr_os_locale_encoding and/or @c apr_os_default_encoding  * to get the name of the path encoding if it's not UTF-8.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_filepath_encoding
argument_list|(
name|int
operator|*
name|style
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/** @} */
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! APR_FILE_INFO_H */
end_comment

end_unit

