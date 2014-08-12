begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_FILE_IO_H
end_ifndef

begin_define
define|#
directive|define
name|APR_FILE_IO_H
end_define

begin_comment
comment|/**  * @file apr_file_io.h  * @brief APR File I/O Handling  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
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

begin_include
include|#
directive|include
file|"apr_file_info.h"
end_include

begin_include
include|#
directive|include
file|"apr_inherit.h"
end_include

begin_define
define|#
directive|define
name|APR_WANT_STDIO
end_define

begin_comment
comment|/**< for SEEK_* */
end_comment

begin_define
define|#
directive|define
name|APR_WANT_IOVEC
end_define

begin_comment
comment|/**< for apr_file_writev */
end_comment

begin_include
include|#
directive|include
file|"apr_want.h"
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
comment|/**  * @defgroup apr_file_io File I/O Handling Functions  * @ingroup APR   * @{  */
comment|/**  * @defgroup apr_file_open_flags File Open Flags/Routines  * @{  */
comment|/* Note to implementors: Values in the range 0x00100000--0x80000000    are reserved for platform-specific values. */
define|#
directive|define
name|APR_FOPEN_READ
value|0x00001
comment|/**< Open the file for reading */
define|#
directive|define
name|APR_FOPEN_WRITE
value|0x00002
comment|/**< Open the file for writing */
define|#
directive|define
name|APR_FOPEN_CREATE
value|0x00004
comment|/**< Create the file if not there */
define|#
directive|define
name|APR_FOPEN_APPEND
value|0x00008
comment|/**< Append to the end of the file */
define|#
directive|define
name|APR_FOPEN_TRUNCATE
value|0x00010
comment|/**< Open the file and truncate                                          to 0 length */
define|#
directive|define
name|APR_FOPEN_BINARY
value|0x00020
comment|/**< Open the file in binary mode 				         (This flag is ignored on UNIX  					 because it has no meaning)*/
define|#
directive|define
name|APR_FOPEN_EXCL
value|0x00040
comment|/**< Open should fail if #APR_FOPEN_CREATE                                          and file exists. */
define|#
directive|define
name|APR_FOPEN_BUFFERED
value|0x00080
comment|/**< Open the file for buffered I/O */
define|#
directive|define
name|APR_FOPEN_DELONCLOSE
value|0x00100
comment|/**< Delete the file after close */
define|#
directive|define
name|APR_FOPEN_XTHREAD
value|0x00200
comment|/**< Platform dependent tag to open                                          the file for use across multiple                                          threads */
define|#
directive|define
name|APR_FOPEN_SHARELOCK
value|0x00400
comment|/**< Platform dependent support for                                          higher level locked read/write                                          access to support writes across                                          process/machines */
define|#
directive|define
name|APR_FOPEN_NOCLEANUP
value|0x00800
comment|/**< Do not register a cleanup                                          when the file is opened. The 					 apr_os_file_t handle in apr_file_t 					 will not be closed when the pool 					 is destroyed. */
define|#
directive|define
name|APR_FOPEN_SENDFILE_ENABLED
value|0x01000
comment|/**< Advisory flag that this                                              file should support                                              apr_socket_sendfile operation */
define|#
directive|define
name|APR_FOPEN_LARGEFILE
value|0x04000
comment|/**< Platform dependent flag to enable                                        * large file support, see WARNING below                                        */
define|#
directive|define
name|APR_FOPEN_SPARSE
value|0x08000
comment|/**< Platform dependent flag to enable                                        * sparse file support, see WARNING below                                        */
define|#
directive|define
name|APR_FOPEN_NONBLOCK
value|0x40000
comment|/**< Platform dependent flag to enable                                        * non blocking file io */
comment|/* backcompat */
define|#
directive|define
name|APR_READ
value|APR_FOPEN_READ
comment|/**< @deprecated @see APR_FOPEN_READ */
define|#
directive|define
name|APR_WRITE
value|APR_FOPEN_WRITE
comment|/**< @deprecated @see APR_FOPEN_WRITE */
define|#
directive|define
name|APR_CREATE
value|APR_FOPEN_CREATE
comment|/**< @deprecated @see APR_FOPEN_CREATE */
define|#
directive|define
name|APR_APPEND
value|APR_FOPEN_APPEND
comment|/**< @deprecated @see APR_FOPEN_APPEND */
define|#
directive|define
name|APR_TRUNCATE
value|APR_FOPEN_TRUNCATE
comment|/**< @deprecated @see APR_FOPEN_TRUNCATE */
define|#
directive|define
name|APR_BINARY
value|APR_FOPEN_BINARY
comment|/**< @deprecated @see APR_FOPEN_BINARY */
define|#
directive|define
name|APR_EXCL
value|APR_FOPEN_EXCL
comment|/**< @deprecated @see APR_FOPEN_EXCL */
define|#
directive|define
name|APR_BUFFERED
value|APR_FOPEN_BUFFERED
comment|/**< @deprecated @see APR_FOPEN_BUFFERED */
define|#
directive|define
name|APR_DELONCLOSE
value|APR_FOPEN_DELONCLOSE
comment|/**< @deprecated @see APR_FOPEN_DELONCLOSE */
define|#
directive|define
name|APR_XTHREAD
value|APR_FOPEN_XTHREAD
comment|/**< @deprecated @see APR_FOPEN_XTHREAD */
define|#
directive|define
name|APR_SHARELOCK
value|APR_FOPEN_SHARELOCK
comment|/**< @deprecated @see APR_FOPEN_SHARELOCK */
define|#
directive|define
name|APR_FILE_NOCLEANUP
value|APR_FOPEN_NOCLEANUP
comment|/**< @deprecated @see APR_FOPEN_NOCLEANUP */
define|#
directive|define
name|APR_SENDFILE_ENABLED
value|APR_FOPEN_SENDFILE_ENABLED
comment|/**< @deprecated @see APR_FOPEN_SENDFILE_ENABLED */
define|#
directive|define
name|APR_LARGEFILE
value|APR_FOPEN_LARGEFILE
comment|/**< @deprecated @see APR_FOPEN_LARGEFILE */
comment|/** @def APR_FOPEN_LARGEFILE   * @warning APR_FOPEN_LARGEFILE flag only has effect on some  * platforms where sizeof(apr_off_t) == 4.  Where implemented, it  * allows opening and writing to a file which exceeds the size which  * can be represented by apr_off_t (2 gigabytes).  When a file's size  * does exceed 2Gb, apr_file_info_get() will fail with an error on the  * descriptor, likewise apr_stat()/apr_lstat() will fail on the  * filename.  apr_dir_read() will fail with #APR_INCOMPLETE on a  * directory entry for a large file depending on the particular  * APR_FINFO_* flags.  Generally, it is not recommended to use this  * flag.  *  * @def APR_FOPEN_SPARSE  * @warning APR_FOPEN_SPARSE may, depending on platform, convert a  * normal file to a sparse file.  Some applications may be unable  * to decipher a sparse file, so it's critical that the sparse file  * flag should only be used for files accessed only by APR or other  * applications known to be able to decipher them.  APR does not  * guarantee that it will compress the file into sparse segments  * if it was previously created and written without the sparse flag.  * On platforms which do not understand, or on file systems which  * cannot handle sparse files, the flag is ignored by apr_file_open().  *  * @def APR_FOPEN_NONBLOCK  * @warning APR_FOPEN_NONBLOCK is not implemented on all platforms.  * Callers should be prepared for it to fail with #APR_ENOTIMPL.  */
comment|/** @} */
comment|/**  * @defgroup apr_file_seek_flags File Seek Flags  * @{  */
comment|/* flags for apr_file_seek */
comment|/** Set the file position */
define|#
directive|define
name|APR_SET
value|SEEK_SET
comment|/** Current */
define|#
directive|define
name|APR_CUR
value|SEEK_CUR
comment|/** Go to end of file */
define|#
directive|define
name|APR_END
value|SEEK_END
comment|/** @} */
comment|/**  * @defgroup apr_file_attrs_set_flags File Attribute Flags  * @{  */
comment|/* flags for apr_file_attrs_set */
define|#
directive|define
name|APR_FILE_ATTR_READONLY
value|0x01
comment|/**< File is read-only */
define|#
directive|define
name|APR_FILE_ATTR_EXECUTABLE
value|0x02
comment|/**< File is executable */
define|#
directive|define
name|APR_FILE_ATTR_HIDDEN
value|0x04
comment|/**< File is hidden */
comment|/** @} */
comment|/**  * @defgroup apr_file_writev{_full} max iovec size  * @{  */
if|#
directive|if
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
define|#
directive|define
name|APR_MAX_IOVEC_SIZE
value|1024
comment|/**< System dependent maximum                                                      size of an iovec array */
elif|#
directive|elif
name|defined
argument_list|(
name|IOV_MAX
argument_list|)
define|#
directive|define
name|APR_MAX_IOVEC_SIZE
value|IOV_MAX
elif|#
directive|elif
name|defined
argument_list|(
name|MAX_IOVEC
argument_list|)
define|#
directive|define
name|APR_MAX_IOVEC_SIZE
value|MAX_IOVEC
else|#
directive|else
define|#
directive|define
name|APR_MAX_IOVEC_SIZE
value|1024
endif|#
directive|endif
comment|/** @} */
comment|/** File attributes */
typedef|typedef
name|apr_uint32_t
name|apr_fileattrs_t
typedef|;
comment|/** Type to pass as whence argument to apr_file_seek. */
typedef|typedef
name|int
name|apr_seek_where_t
typedef|;
comment|/**  * Structure for referencing files.  */
typedef|typedef
name|struct
name|apr_file_t
name|apr_file_t
typedef|;
comment|/* File lock types/flags */
comment|/**  * @defgroup apr_file_lock_types File Lock Types  * @{  */
define|#
directive|define
name|APR_FLOCK_SHARED
value|1
comment|/**< Shared lock. More than one process                                            or thread can hold a shared lock                                            at any given time. Essentially,                                            this is a "read lock", preventing                                            writers from establishing an                                            exclusive lock. */
define|#
directive|define
name|APR_FLOCK_EXCLUSIVE
value|2
comment|/**< Exclusive lock. Only one process                                            may hold an exclusive lock at any                                            given time. This is analogous to                                            a "write lock". */
define|#
directive|define
name|APR_FLOCK_TYPEMASK
value|0x000F
comment|/**< mask to extract lock type */
define|#
directive|define
name|APR_FLOCK_NONBLOCK
value|0x0010
comment|/**< do not block while acquiring the                                            file lock */
comment|/** @} */
comment|/**  * Open the specified file.  * @param newf The opened file descriptor.  * @param fname The full path to the file (using / on all systems)  * @param flag Or'ed value of:  * @li #APR_FOPEN_READ           open for reading  * @li #APR_FOPEN_WRITE          open for writing  * @li #APR_FOPEN_CREATE         create the file if not there  * @li #APR_FOPEN_APPEND         file ptr is set to end prior to all writes  * @li #APR_FOPEN_TRUNCATE       set length to zero if file exists  * @li #APR_FOPEN_BINARY         not a text file  * @li #APR_FOPEN_BUFFERED       buffer the data.  Default is non-buffered  * @li #APR_FOPEN_EXCL           return error if #APR_FOPEN_CREATE and file exists  * @li #APR_FOPEN_DELONCLOSE     delete the file after closing  * @li #APR_FOPEN_XTHREAD        Platform dependent tag to open the file  *                               for use across multiple threads  * @li #APR_FOPEN_SHARELOCK      Platform dependent support for higher  *                               level locked read/write access to support  *                               writes across process/machines  * @li #APR_FOPEN_NOCLEANUP      Do not register a cleanup with the pool   *                               passed in on the @a pool argument (see below)  * @li #APR_FOPEN_SENDFILE_ENABLED  Open with appropriate platform semantics  *                               for sendfile operations.  Advisory only,  *                               apr_socket_sendfile does not check this flag  * @li #APR_FOPEN_LARGEFILE      Platform dependent flag to enable large file  *                               support, see WARNING below   * @li #APR_FOPEN_SPARSE         Platform dependent flag to enable sparse file  *                               support, see WARNING below  * @li #APR_FOPEN_NONBLOCK       Platform dependent flag to enable  *                               non blocking file io  * @param perm Access permissions for file.  * @param pool The pool to use.  * @remark If perm is #APR_FPROT_OS_DEFAULT and the file is being created,  * appropriate default permissions will be used.  * @remark By default, the returned file descriptor will not be  * inherited by child processes created by apr_proc_create().  This  * can be changed using apr_file_inherit_set().  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_open
argument_list|(
argument|apr_file_t **newf
argument_list|,
argument|const char *fname
argument_list|,
argument|apr_int32_t flag
argument_list|,
argument|apr_fileperms_t perm
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Close the specified file.  * @param file The file descriptor to close.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_close
argument_list|(
name|apr_file_t
operator|*
name|file
argument_list|)
expr_stmt|;
comment|/**  * Delete the specified file.  * @param path The full path to the file (using / on all systems)  * @param pool The pool to use.  * @remark If the file is open, it won't be removed until all  * instances are closed.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_remove
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Rename the specified file.  * @param from_path The full path to the original file (using / on all systems)  * @param to_path The full path to the new file (using / on all systems)  * @param pool The pool to use.  * @warning If a file exists at the new location, then it will be  * overwritten.  Moving files or directories across devices may not be  * possible.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_rename
argument_list|(
specifier|const
name|char
operator|*
name|from_path
argument_list|,
specifier|const
name|char
operator|*
name|to_path
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Create a hard link to the specified file.  * @param from_path The full path to the original file (using / on all systems)  * @param to_path The full path to the new file (using / on all systems)  * @remark Both files must reside on the same device.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_link
argument_list|(
specifier|const
name|char
operator|*
name|from_path
argument_list|,
specifier|const
name|char
operator|*
name|to_path
argument_list|)
expr_stmt|;
comment|/**  * Copy the specified file to another file.  * @param from_path The full path to the original file (using / on all systems)  * @param to_path The full path to the new file (using / on all systems)  * @param perms Access permissions for the new file if it is created.  *     In place of the usual or'd combination of file permissions, the  *     value #APR_FPROT_FILE_SOURCE_PERMS may be given, in which case the source  *     file's permissions are copied.  * @param pool The pool to use.  * @remark The new file does not need to exist, it will be created if required.  * @warning If the new file already exists, its contents will be overwritten.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_copy
argument_list|(
argument|const char *from_path
argument_list|,
argument|const char *to_path
argument_list|,
argument|apr_fileperms_t perms
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Append the specified file to another file.  * @param from_path The full path to the source file (use / on all systems)  * @param to_path The full path to the destination file (use / on all systems)  * @param perms Access permissions for the destination file if it is created.  *     In place of the usual or'd combination of file permissions, the  *     value #APR_FPROT_FILE_SOURCE_PERMS may be given, in which case the source  *     file's permissions are copied.  * @param pool The pool to use.  * @remark The new file does not need to exist, it will be created if required.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_append
argument_list|(
argument|const char *from_path
argument_list|,
argument|const char *to_path
argument_list|,
argument|apr_fileperms_t perms
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Are we at the end of the file  * @param fptr The apr file we are testing.  * @remark Returns #APR_EOF if we are at the end of file, #APR_SUCCESS otherwise.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_eof
argument_list|(
name|apr_file_t
operator|*
name|fptr
argument_list|)
expr_stmt|;
comment|/**  * Open standard error as an apr file pointer.  * @param thefile The apr file to use as stderr.  * @param pool The pool to allocate the file out of.  *   * @remark The only reason that the apr_file_open_std* functions exist  * is that you may not always have a stderr/out/in on Windows.  This  * is generally a problem with newer versions of Windows and services.  *   * @remark The other problem is that the C library functions generally work  * differently on Windows and Unix.  So, by using apr_file_open_std*  * functions, you can get a handle to an APR struct that works with  * the APR functions which are supposed to work identically on all  * platforms.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_open_stderr
argument_list|(
name|apr_file_t
operator|*
operator|*
name|thefile
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * open standard output as an apr file pointer.  * @param thefile The apr file to use as stdout.  * @param pool The pool to allocate the file out of.  *   * @remark See remarks for apr_file_open_stderr().  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_open_stdout
argument_list|(
name|apr_file_t
operator|*
operator|*
name|thefile
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * open standard input as an apr file pointer.  * @param thefile The apr file to use as stdin.  * @param pool The pool to allocate the file out of.  *   * @remark See remarks for apr_file_open_stderr().  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_open_stdin
argument_list|(
name|apr_file_t
operator|*
operator|*
name|thefile
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * open standard error as an apr file pointer, with flags.  * @param thefile The apr file to use as stderr.  * @param flags The flags to open the file with. Only the   *              @li #APR_FOPEN_EXCL  *              @li #APR_FOPEN_BUFFERED  *              @li #APR_FOPEN_XTHREAD  *              @li #APR_FOPEN_SHARELOCK   *              @li #APR_FOPEN_SENDFILE_ENABLED  *              @li #APR_FOPEN_LARGEFILE  *  *              flags should be used. The #APR_FOPEN_WRITE flag will  *              be set unconditionally.  * @param pool The pool to allocate the file out of.  *   * @remark See remarks for apr_file_open_stderr().  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_open_flags_stderr
argument_list|(
argument|apr_file_t **thefile
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * open standard output as an apr file pointer, with flags.  * @param thefile The apr file to use as stdout.  * @param flags The flags to open the file with. Only the   *              @li #APR_FOPEN_EXCL  *              @li #APR_FOPEN_BUFFERED  *              @li #APR_FOPEN_XTHREAD  *              @li #APR_FOPEN_SHARELOCK   *              @li #APR_FOPEN_SENDFILE_ENABLED  *              @li #APR_FOPEN_LARGEFILE  *  *              flags should be used. The #APR_FOPEN_WRITE flag will  *              be set unconditionally.  * @param pool The pool to allocate the file out of.  *   * @remark See remarks for apr_file_open_stderr().  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_open_flags_stdout
argument_list|(
argument|apr_file_t **thefile
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * open standard input as an apr file pointer, with flags.  * @param thefile The apr file to use as stdin.  * @param flags The flags to open the file with. Only the   *              @li #APR_FOPEN_EXCL  *              @li #APR_FOPEN_BUFFERED  *              @li #APR_FOPEN_XTHREAD  *              @li #APR_FOPEN_SHARELOCK   *              @li #APR_FOPEN_SENDFILE_ENABLED  *              @li #APR_FOPEN_LARGEFILE  *  *              flags should be used. The #APR_FOPEN_WRITE flag will  *              be set unconditionally.  * @param pool The pool to allocate the file out of.  *   * @remark See remarks for apr_file_open_stderr().  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_open_flags_stdin
argument_list|(
argument|apr_file_t **thefile
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Read data from the specified file.  * @param thefile The file descriptor to read from.  * @param buf The buffer to store the data to.  * @param nbytes On entry, the number of bytes to read; on exit, the number  * of bytes read.  *  * @remark apr_file_read() will read up to the specified number of  * bytes, but never more.  If there isn't enough data to fill that  * number of bytes, all of the available data is read.  The third  * argument is modified to reflect the number of bytes read.  If a  * char was put back into the stream via ungetc, it will be the first  * character returned.  *  * @remark It is not possible for both bytes to be read and an #APR_EOF  * or other error to be returned.  #APR_EINTR is never returned.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_read
argument_list|(
name|apr_file_t
operator|*
name|thefile
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|apr_size_t
operator|*
name|nbytes
argument_list|)
expr_stmt|;
comment|/**  * Write data to the specified file.  * @param thefile The file descriptor to write to.  * @param buf The buffer which contains the data.  * @param nbytes On entry, the number of bytes to write; on exit, the number   *               of bytes written.  *  * @remark apr_file_write() will write up to the specified number of  * bytes, but never more.  If the OS cannot write that many bytes, it  * will write as many as it can.  The third argument is modified to  * reflect the * number of bytes written.  *  * @remark It is possible for both bytes to be written and an error to  * be returned.  #APR_EINTR is never returned.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_write
argument_list|(
name|apr_file_t
operator|*
name|thefile
argument_list|,
specifier|const
name|void
operator|*
name|buf
argument_list|,
name|apr_size_t
operator|*
name|nbytes
argument_list|)
expr_stmt|;
comment|/**  * Write data from iovec array to the specified file.  * @param thefile The file descriptor to write to.  * @param vec The array from which to get the data to write to the file.  * @param nvec The number of elements in the struct iovec array. This must   *             be smaller than #APR_MAX_IOVEC_SIZE.  If it isn't, the function   *             will fail with #APR_EINVAL.  * @param nbytes The number of bytes written.  *  * @remark It is possible for both bytes to be written and an error to  * be returned.  #APR_EINTR is never returned.  *  * @remark apr_file_writev() is available even if the underlying  * operating system doesn't provide writev().  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_writev
argument_list|(
argument|apr_file_t *thefile
argument_list|,
argument|const struct iovec *vec
argument_list|,
argument|apr_size_t nvec
argument_list|,
argument|apr_size_t *nbytes
argument_list|)
empty_stmt|;
comment|/**  * Read data from the specified file, ensuring that the buffer is filled  * before returning.  * @param thefile The file descriptor to read from.  * @param buf The buffer to store the data to.  * @param nbytes The number of bytes to read.  * @param bytes_read If non-NULL, this will contain the number of bytes read.  *  * @remark apr_file_read_full() will read up to the specified number of  * bytes, but never more.  If there isn't enough data to fill that  * number of bytes, then the process/thread will block until it is  * available or EOF is reached.  If a char was put back into the  * stream via ungetc, it will be the first character returned.  *  * @remark It is possible for both bytes to be read and an error to be  * returned.  And if *bytes_read is less than nbytes, an accompanying  * error is _always_ returned.  *  * @remark #APR_EINTR is never returned.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_read_full
argument_list|(
argument|apr_file_t *thefile
argument_list|,
argument|void *buf
argument_list|,
argument|apr_size_t nbytes
argument_list|,
argument|apr_size_t *bytes_read
argument_list|)
empty_stmt|;
comment|/**  * Write data to the specified file, ensuring that all of the data is  * written before returning.  * @param thefile The file descriptor to write to.  * @param buf The buffer which contains the data.  * @param nbytes The number of bytes to write.  * @param bytes_written If non-NULL, set to the number of bytes written.  *   * @remark apr_file_write_full() will write up to the specified number of  * bytes, but never more.  If the OS cannot write that many bytes, the  * process/thread will block until they can be written. Exceptional  * error such as "out of space" or "pipe closed" will terminate with  * an error.  *  * @remark It is possible for both bytes to be written and an error to  * be returned.  And if *bytes_written is less than nbytes, an  * accompanying error is _always_ returned.  *  * @remark #APR_EINTR is never returned.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_write_full
argument_list|(
argument|apr_file_t *thefile
argument_list|,
argument|const void *buf
argument_list|,
argument|apr_size_t nbytes
argument_list|,
argument|apr_size_t *bytes_written
argument_list|)
empty_stmt|;
comment|/**  * Write data from iovec array to the specified file, ensuring that all of the  * data is written before returning.  * @param thefile The file descriptor to write to.  * @param vec The array from which to get the data to write to the file.  * @param nvec The number of elements in the struct iovec array. This must   *             be smaller than #APR_MAX_IOVEC_SIZE.  If it isn't, the function   *             will fail with #APR_EINVAL.  * @param nbytes The number of bytes written.  *  * @remark apr_file_writev_full() is available even if the underlying  * operating system doesn't provide writev().  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_writev_full
argument_list|(
argument|apr_file_t *thefile
argument_list|,
argument|const struct iovec *vec
argument_list|,
argument|apr_size_t nvec
argument_list|,
argument|apr_size_t *nbytes
argument_list|)
empty_stmt|;
comment|/**  * Write a character into the specified file.  * @param ch The character to write.  * @param thefile The file descriptor to write to  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_putc
argument_list|(
argument|char ch
argument_list|,
argument|apr_file_t *thefile
argument_list|)
empty_stmt|;
comment|/**  * Read a character from the specified file.  * @param ch The character to read into  * @param thefile The file descriptor to read from  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_getc
argument_list|(
name|char
operator|*
name|ch
argument_list|,
name|apr_file_t
operator|*
name|thefile
argument_list|)
expr_stmt|;
comment|/**  * Put a character back onto a specified stream.  * @param ch The character to write.  * @param thefile The file descriptor to write to  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_ungetc
argument_list|(
argument|char ch
argument_list|,
argument|apr_file_t *thefile
argument_list|)
empty_stmt|;
comment|/**  * Read a line from the specified file  * @param str The buffer to store the string in.   * @param len The length of the string  * @param thefile The file descriptor to read from  * @remark The buffer will be NUL-terminated if any characters are stored.  *         The newline at the end of the line will not be stripped.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_gets
argument_list|(
argument|char *str
argument_list|,
argument|int len
argument_list|,
argument|apr_file_t *thefile
argument_list|)
empty_stmt|;
comment|/**  * Write the string into the specified file.  * @param str The string to write.   * @param thefile The file descriptor to write to  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_puts
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|,
name|apr_file_t
operator|*
name|thefile
argument_list|)
expr_stmt|;
comment|/**  * Flush the file's buffer.  * @param thefile The file descriptor to flush  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_flush
argument_list|(
name|apr_file_t
operator|*
name|thefile
argument_list|)
expr_stmt|;
comment|/**  * Transfer all file modified data and metadata to disk.  * @param thefile The file descriptor to sync  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_sync
argument_list|(
name|apr_file_t
operator|*
name|thefile
argument_list|)
expr_stmt|;
comment|/**  * Transfer all file modified data to disk.  * @param thefile The file descriptor to sync  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_datasync
argument_list|(
name|apr_file_t
operator|*
name|thefile
argument_list|)
expr_stmt|;
comment|/**  * Duplicate the specified file descriptor.  * @param new_file The structure to duplicate into.   * @param old_file The file to duplicate.  * @param p The pool to use for the new file.  * @remark *new_file must point to a valid apr_file_t, or point to NULL.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_dup
argument_list|(
name|apr_file_t
operator|*
operator|*
name|new_file
argument_list|,
name|apr_file_t
operator|*
name|old_file
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Duplicate the specified file descriptor and close the original  * @param new_file The old file that is to be closed and reused  * @param old_file The file to duplicate  * @param p        The pool to use for the new file  *  * @remark new_file MUST point at a valid apr_file_t. It cannot be NULL.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_dup2
argument_list|(
name|apr_file_t
operator|*
name|new_file
argument_list|,
name|apr_file_t
operator|*
name|old_file
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Move the specified file descriptor to a new pool  * @param new_file Pointer in which to return the new apr_file_t  * @param old_file The file to move  * @param p        The pool to which the descriptor is to be moved  * @remark Unlike apr_file_dup2(), this function doesn't do an  *         OS dup() operation on the underlying descriptor; it just  *         moves the descriptor's apr_file_t wrapper to a new pool.  * @remark The new pool need not be an ancestor of old_file's pool.  * @remark After calling this function, old_file may not be used  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_setaside
argument_list|(
name|apr_file_t
operator|*
operator|*
name|new_file
argument_list|,
name|apr_file_t
operator|*
name|old_file
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Give the specified apr file handle a new buffer   * @param thefile  The file handle that is to be modified  * @param buffer   The buffer  * @param bufsize  The size of the buffer  * @remark It is possible to add a buffer to previously unbuffered  *         file handles, the #APR_FOPEN_BUFFERED flag will be added to  *         the file handle's flags. Likewise, with buffer=NULL and  *         bufsize=0 arguments it is possible to make a previously  *         buffered file handle unbuffered.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_buffer_set
argument_list|(
argument|apr_file_t *thefile
argument_list|,
argument|char * buffer
argument_list|,
argument|apr_size_t bufsize
argument_list|)
empty_stmt|;
comment|/**  * Get the size of any buffer for the specified apr file handle   * @param thefile  The file handle   */
name|APR_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_file_buffer_size_get
argument_list|(
name|apr_file_t
operator|*
name|thefile
argument_list|)
expr_stmt|;
comment|/**  * Move the read/write file offset to a specified byte within a file.  * @param thefile The file descriptor  * @param where How to move the pointer, one of:  *              @li #APR_SET  --  set the offset to offset  *              @li #APR_CUR  --  add the offset to the current position   *              @li #APR_END  --  add the offset to the current file size   * @param offset The offset to move the pointer to.  * @remark The third argument is modified to be the offset the pointer           was actually moved to.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_seek
argument_list|(
argument|apr_file_t *thefile
argument_list|,
argument|apr_seek_where_t where
argument_list|,
argument|apr_off_t *offset
argument_list|)
empty_stmt|;
comment|/**  * Create an anonymous pipe.  * @param in The newly created pipe's file for reading.  * @param out The newly created pipe's file for writing.  * @param pool The pool to operate on.  * @remark By default, the returned file descriptors will be inherited  * by child processes created using apr_proc_create().  This can be  * changed using apr_file_inherit_unset().  * @bug  Some platforms cannot toggle between blocking and nonblocking,  * and when passing a pipe as a standard handle to an application which  * does not expect it, a non-blocking stream will fluxor the client app.  * @deprecated @see apr_file_pipe_create_ex()  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_pipe_create
argument_list|(
name|apr_file_t
operator|*
operator|*
name|in
argument_list|,
name|apr_file_t
operator|*
operator|*
name|out
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Create an anonymous pipe which portably supports async timeout options.  * @param in The newly created pipe's file for reading.  * @param out The newly created pipe's file for writing.  * @param blocking one of these values defined in apr_thread_proc.h;  *                 @li #APR_FULL_BLOCK  *                 @li #APR_READ_BLOCK  *                 @li #APR_WRITE_BLOCK  *                 @li #APR_FULL_NONBLOCK  * @param pool The pool to operate on.  * @remark By default, the returned file descriptors will be inherited  * by child processes created using apr_proc_create().  This can be  * changed using apr_file_inherit_unset().  * @remark Some platforms cannot toggle between blocking and nonblocking,  * and when passing a pipe as a standard handle to an application which  * does not expect it, a non-blocking stream will fluxor the client app.  * Use this function rather than apr_file_pipe_create() to create pipes   * where one or both ends require non-blocking semantics.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_pipe_create_ex
argument_list|(
argument|apr_file_t **in
argument_list|,
argument|apr_file_t **out
argument_list|,
argument|apr_int32_t blocking
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Create a named pipe.  * @param filename The filename of the named pipe  * @param perm The permissions for the newly created pipe.  * @param pool The pool to operate on.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_namedpipe_create
argument_list|(
argument|const char *filename
argument_list|,
argument|apr_fileperms_t perm
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Get the timeout value for a pipe or manipulate the blocking state.  * @param thepipe The pipe we are getting a timeout for.  * @param timeout The current timeout value in microseconds.   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_pipe_timeout_get
argument_list|(
name|apr_file_t
operator|*
name|thepipe
argument_list|,
name|apr_interval_time_t
operator|*
name|timeout
argument_list|)
expr_stmt|;
comment|/**  * Set the timeout value for a pipe or manipulate the blocking state.  * @param thepipe The pipe we are setting a timeout on.  * @param timeout The timeout value in microseconds.  Values< 0 mean wait   *        forever, 0 means do not wait at all.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_pipe_timeout_set
argument_list|(
argument|apr_file_t *thepipe
argument_list|,
argument|apr_interval_time_t timeout
argument_list|)
empty_stmt|;
comment|/** file (un)locking functions. */
comment|/**  * Establish a lock on the specified, open file. The lock may be advisory  * or mandatory, at the discretion of the platform. The lock applies to  * the file as a whole, rather than a specific range. Locks are established  * on a per-thread/process basis; a second lock by the same thread will not  * block.  * @param thefile The file to lock.  * @param type The type of lock to establish on the file.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_lock
argument_list|(
argument|apr_file_t *thefile
argument_list|,
argument|int type
argument_list|)
empty_stmt|;
comment|/**  * Remove any outstanding locks on the file.  * @param thefile The file to unlock.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_unlock
argument_list|(
name|apr_file_t
operator|*
name|thefile
argument_list|)
expr_stmt|;
comment|/**accessor and general file_io functions. */
comment|/**  * return the file name of the current file.  * @param new_path The path of the file.    * @param thefile The currently open file.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_name_get
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|new_path
argument_list|,
name|apr_file_t
operator|*
name|thefile
argument_list|)
expr_stmt|;
comment|/**  * Return the data associated with the current file.  * @param data The user data associated with the file.    * @param key The key to use for retrieving data associated with this file.  * @param file The currently open file.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_data_get
argument_list|(
name|void
operator|*
operator|*
name|data
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|apr_file_t
operator|*
name|file
argument_list|)
expr_stmt|;
comment|/**  * Set the data associated with the current file.  * @param file The currently open file.  * @param data The user data to associate with the file.    * @param key The key to use for associating data with the file.  * @param cleanup The cleanup routine to use when the file is destroyed.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_data_set
argument_list|(
name|apr_file_t
operator|*
name|file
argument_list|,
name|void
operator|*
name|data
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|apr_status_t
argument_list|(
operator|*
name|cleanup
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|/**  * Write a string to a file using a printf format.  * @param fptr The file to write to.  * @param format The format string  * @param ... The values to substitute in the format string  * @return The number of bytes written  */
name|APR_DECLARE_NONSTD
argument_list|(
argument|int
argument_list|)
name|apr_file_printf
argument_list|(
argument|apr_file_t *fptr
argument_list|,
argument|const char *format
argument_list|,
argument|...
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * set the specified file's permission bits.  * @param fname The file (name) to apply the permissions to.  * @param perms The permission bits to apply to the file.  *  * @warning Some platforms may not be able to apply all of the  * available permission bits; #APR_INCOMPLETE will be returned if some  * permissions are specified which could not be set.  *  * @warning Platforms which do not implement this feature will return  * #APR_ENOTIMPL.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_perms_set
argument_list|(
argument|const char *fname
argument_list|,
argument|apr_fileperms_t perms
argument_list|)
empty_stmt|;
comment|/**  * Set attributes of the specified file.  * @param fname The full path to the file (using / on all systems)  * @param attributes Or'd combination of  *            @li #APR_FILE_ATTR_READONLY   - make the file readonly  *            @li #APR_FILE_ATTR_EXECUTABLE - make the file executable  *            @li #APR_FILE_ATTR_HIDDEN     - make the file hidden  * @param attr_mask Mask of valid bits in attributes.  * @param pool the pool to use.  * @remark This function should be used in preference to explicit manipulation  *      of the file permissions, because the operations to provide these  *      attributes are platform specific and may involve more than simply  *      setting permission bits.  * @warning Platforms which do not implement this feature will return  *      #APR_ENOTIMPL.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_attrs_set
argument_list|(
argument|const char *fname
argument_list|,
argument|apr_fileattrs_t attributes
argument_list|,
argument|apr_fileattrs_t attr_mask
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Set the mtime of the specified file.  * @param fname The full path to the file (using / on all systems)  * @param mtime The mtime to apply to the file.  * @param pool The pool to use.  * @warning Platforms which do not implement this feature will return  *      #APR_ENOTIMPL.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_mtime_set
argument_list|(
argument|const char *fname
argument_list|,
argument|apr_time_t mtime
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Create a new directory on the file system.  * @param path the path for the directory to be created. (use / on all systems)  * @param perm Permissions for the new directory.  * @param pool the pool to use.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dir_make
argument_list|(
argument|const char *path
argument_list|,
argument|apr_fileperms_t perm
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/** Creates a new directory on the file system, but behaves like  * 'mkdir -p'. Creates intermediate directories as required. No error  * will be reported if PATH already exists.  * @param path the path for the directory to be created. (use / on all systems)  * @param perm Permissions for the new directory.  * @param pool the pool to use.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dir_make_recursive
argument_list|(
argument|const char *path
argument_list|,
argument|apr_fileperms_t perm
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Remove directory from the file system.  * @param path the path for the directory to be removed. (use / on all systems)  * @param pool the pool to use.  * @remark Removing a directory which is in-use (e.g., the current working  * directory, or during apr_dir_read, or with an open file) is not portable.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dir_remove
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * get the specified file's stats.  * @param finfo Where to store the information about the file.  * @param wanted The desired apr_finfo_t fields, as a bit flag of APR_FINFO_* values   * @param thefile The file to get information about.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_info_get
argument_list|(
argument|apr_finfo_t *finfo
argument_list|,
argument|apr_int32_t wanted
argument_list|,
argument|apr_file_t *thefile
argument_list|)
empty_stmt|;
comment|/**  * Truncate the file's length to the specified offset  * @param fp The file to truncate  * @param offset The offset to truncate to.  * @remark The read/write file offset is repositioned to offset.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_trunc
argument_list|(
argument|apr_file_t *fp
argument_list|,
argument|apr_off_t offset
argument_list|)
empty_stmt|;
comment|/**  * Retrieve the flags that were passed into apr_file_open()  * when the file was opened.  * @return apr_int32_t the flags  */
name|APR_DECLARE
argument_list|(
argument|apr_int32_t
argument_list|)
name|apr_file_flags_get
argument_list|(
name|apr_file_t
operator|*
name|f
argument_list|)
expr_stmt|;
comment|/**  * Get the pool used by the file.  */
name|APR_POOL_DECLARE_ACCESSOR
argument_list|(
name|file
argument_list|)
expr_stmt|;
comment|/**  * Set a file to be inherited by child processes.  *  */
name|APR_DECLARE_INHERIT_SET
argument_list|(
name|file
argument_list|)
expr_stmt|;
comment|/**  * Unset a file from being inherited by child processes.  */
name|APR_DECLARE_INHERIT_UNSET
argument_list|(
name|file
argument_list|)
expr_stmt|;
comment|/**  * Open a temporary file  * @param fp The apr file to use as a temporary file.  * @param templ The template to use when creating a temp file.  * @param flags The flags to open the file with. If this is zero,  *              the file is opened with   *              #APR_FOPEN_CREATE | #APR_FOPEN_READ | #APR_FOPEN_WRITE |  *              #APR_FOPEN_EXCL | #APR_FOPEN_DELONCLOSE  * @param p The pool to allocate the file out of.  * @remark     * This function  generates  a unique temporary file name from template.    * The last six characters of template must be XXXXXX and these are replaced   * with a string that makes the filename unique. Since it will  be  modified,  * template must not be a string constant, but should be declared as a character  * array.    *  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_file_mktemp
argument_list|(
argument|apr_file_t **fp
argument_list|,
argument|char *templ
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|apr_pool_t *p
argument_list|)
empty_stmt|;
comment|/**  * Find an existing directory suitable as a temporary storage location.  * @param temp_dir The temp directory.  * @param p The pool to use for any necessary allocations.  * @remark     * This function uses an algorithm to search for a directory that an  * an application can use for temporary storage.  *  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_temp_dir_get
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|temp_dir
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
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
comment|/* ! APR_FILE_IO_H */
end_comment

end_unit

