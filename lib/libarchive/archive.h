begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2004 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Linux requires this for off_t */
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_comment
comment|/* For int64_t */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* For ssize_t and size_t */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_BYTES_PER_RECORD
value|512
end_define

begin_define
define|#
directive|define
name|ARCHIVE_DEFAULT_BYTES_PER_BLOCK
value|10240
end_define

begin_comment
comment|/* Declare our basic types. */
end_comment

begin_struct_decl
struct_decl|struct
name|archive
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|archive_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Error codes: Use archive_errno() and archive_error_string()  * to retrieve details.  Unless specified otherwise, all functions  * that return 'int' use these codes.  */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_EOF
value|1
end_define

begin_comment
comment|/* Found end of archive. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_OK
value|0
end_define

begin_comment
comment|/* Operation was successful. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_WARN
value|(-1)
end_define

begin_comment
comment|/* Sucess, but minor problem. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_RETRY
value|(-2)
end_define

begin_comment
comment|/* Retry might succeed. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_FATAL
value|(-3)
end_define

begin_comment
comment|/* No more operations are possible. */
end_comment

begin_comment
comment|/*  * As far as possible, archive_errno returns standard platform errno codes.  * Of course, the details vary by platform, so the actual definitions  * here are stored in "archive_platform.h".  The symbols are listed here  * for reference; as a rule, clients should not need to know the exact  * platform-dependent error code.  */
end_comment

begin_comment
comment|/* Unrecognized or invalid file format. */
end_comment

begin_comment
comment|/* #define	ARCHIVE_ERRNO_FILE_FORMAT */
end_comment

begin_comment
comment|/* Illegal usage of the library. */
end_comment

begin_comment
comment|/* #define	ARCHIVE_ERRNO_PROGRAMMER_ERROR */
end_comment

begin_comment
comment|/* Unknown or unclassified error. */
end_comment

begin_comment
comment|/* #define	ARCHIVE_ERRNO_MISC */
end_comment

begin_comment
comment|/*  * Callbacks are invoked to automatically read/write/open/close the archive.  * You can provide your own for complex tasks (like breaking archives  * across multiple tapes) or use standard ones built into the library.  */
end_comment

begin_comment
comment|/* Returns pointer and size of next block of data from archive. */
end_comment

begin_typedef
typedef|typedef
name|ssize_t
name|archive_read_callback
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
modifier|*
name|_client_data
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|_buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Returns size actually written, zero on EOF, -1 on error. */
end_comment

begin_typedef
typedef|typedef
name|ssize_t
name|archive_write_callback
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
modifier|*
name|_client_data
parameter_list|,
name|void
modifier|*
name|_buffer
parameter_list|,
name|size_t
name|_length
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|archive_open_callback
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
modifier|*
name|_client_data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|archive_close_callback
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
modifier|*
name|_client_data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Codes for archive_compression.  */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_COMPRESSION_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ARCHIVE_COMPRESSION_GZIP
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_COMPRESSION_BZIP2
value|2
end_define

begin_define
define|#
directive|define
name|ARCHIVE_COMPRESSION_COMPRESS
value|3
end_define

begin_comment
comment|/*  * Codes returned by archive_format.  *  * Top 16 bits identifies the format family (e.g., "tar"); lower  * 16 bits indicate the variant.  This is updated by read_next_header.  * Note that the lower 16 bits will often vary from entry to entry.  */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_BASE_MASK
value|0xff0000U
end_define

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_CPIO
value|0x10000
end_define

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_CPIO_POSIX
value|(ARCHIVE_FORMAT_CPIO | 1)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_SHAR
value|0x20000
end_define

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_SHAR_BASE
value|(ARCHIVE_FORMAT_SHAR | 1)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_SHAR_DUMP
value|(ARCHIVE_FORMAT_SHAR | 2)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_TAR
value|0x30000
end_define

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_TAR_USTAR
value|(ARCHIVE_FORMAT_TAR | 1)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_TAR_PAX_INTERCHANGE
value|(ARCHIVE_FORMAT_TAR | 2)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_TAR_PAX_RESTRICTED
value|(ARCHIVE_FORMAT_TAR | 3)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_FORMAT_TAR_GNUTAR
value|(ARCHIVE_FORMAT_TAR | 4)
end_define

begin_comment
comment|/*-  * Basic outline for reading an archive:  *   1) Ask archive_read_new for an archive reader object.  *   2) Update any global properties as appropriate.  *      In particular, you'll certainly want to call appropriate  *      archive_read_support_XXX functions.  *   3) Call archive_read_open_XXX to open the archive  *   4) Repeatedly call archive_read_next_header to get information about  *      successive archive entries.  Call archive_read_data to extract  *      data for entries of interest.  *   5) Call archive_read_finish to destroy the object.  */
end_comment

begin_function_decl
name|struct
name|archive
modifier|*
name|archive_read_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The archive_read_support_XXX calls enable auto-detect for this  * archive handle.  They also link in the necessary support code.  * For example, if you don't want bzlib linked in, don't invoke  * support_compression_bzip2().  The "all" functions provide the  * obvious shorthand.  */
end_comment

begin_function_decl
name|int
name|archive_read_support_compression_all
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_support_compression_bzip2
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_support_compression_compress
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_support_compression_gzip
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_support_compression_none
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_support_format_all
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_support_format_cpio
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_support_format_gnutar
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_support_format_tar
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Open the archive using callbacks for archive I/O. */
end_comment

begin_function_decl
name|int
name|archive_read_open
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
modifier|*
name|_client_data
parameter_list|,
name|archive_open_callback
modifier|*
parameter_list|,
name|archive_read_callback
modifier|*
parameter_list|,
name|archive_close_callback
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The archive_read_open_file function is a convenience function built  * on archive_read_open that uses a canned callback suitable for  * common situations.  Note that a NULL filename indicates stdin.  */
end_comment

begin_function_decl
name|int
name|archive_read_open_file
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|_file
parameter_list|,
name|size_t
name|_block_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_open_fd
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|int
name|_fd
parameter_list|,
name|size_t
name|_block_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parses and returns next entry header. */
end_comment

begin_function_decl
name|int
name|archive_read_next_header
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|struct
name|archive_entry
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Retrieve the byte offset in UNCOMPRESSED data where last-read  * header started.  */
end_comment

begin_function_decl
name|int64_t
name|archive_read_header_position
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read data from the body of an entry.  Similar to read(2). */
end_comment

begin_function_decl
name|ssize_t
name|archive_read_data
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * A zero-copy version of archive_read_data that also exposes the file offset  * of each returned block.  Note that the client has no way to specify  * the desired size of the block.  The API does gaurantee that offsets will  * be strictly increasing and that returned blocks will not overlap.  */
end_comment

begin_function_decl
name|int
name|archive_read_data_block
parameter_list|(
name|struct
name|archive
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|buff
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|,
name|off_t
modifier|*
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-  * Some convenience functions that are built on archive_read_data:  *  'skip': skips entire entry  *  'into_buffer': writes data into memory buffer that you provide  *  'into_fd': writes data to specified filedes  */
end_comment

begin_function_decl
name|int
name|archive_read_data_skip
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_data_into_buffer
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|ssize_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_read_data_into_fd
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-  * Convenience function to recreate the current entry (whose header  * has just been read) on disk.  *  * This does quite a bit more than just copy data to disk. It also:  *  - Creates intermediate directories as required.  *  - Manages directory permissions:  non-writable directories will  *    be initially created with write permission enabled; when the  *    archive is closed, dir permissions are edited to the values specified  *    in the archive.  *  - Checks hardlinks:  hardlinks will not be extracted unless the  *    linked-to file was also extracted within the same session. (TODO)  */
end_comment

begin_comment
comment|/* The "flags" argument selects optional behavior, 'OR' the flags you want. */
end_comment

begin_comment
comment|/* TODO: The 'Default' comments here are not quite correct; clean this up. */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_EXTRACT_OWNER
value|(1)
end_define

begin_comment
comment|/* Default: owner/group not restored */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_EXTRACT_PERM
value|(2)
end_define

begin_comment
comment|/* Default: restore perm only for reg file*/
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_EXTRACT_TIME
value|(4)
end_define

begin_comment
comment|/* Default: mod time not restored */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_EXTRACT_NO_OVERWRITE
value|(8)
end_define

begin_comment
comment|/* Default: Replace files on disk */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE_EXTRACT_UNLINK
value|(16)
end_define

begin_comment
comment|/* Default: don't unlink existing files */
end_comment

begin_function_decl
name|int
name|archive_read_extract
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|struct
name|archive_entry
modifier|*
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_read_extract_set_progress_callback
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
name|_progress_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|_user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Close the file, release any resources, and destroy the object. */
end_comment

begin_function_decl
name|void
name|archive_read_finish
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-  * To create an archive:  *   1) Ask archive_write_new for a archive writer object.  *   2) Set any global properties.  In particular, you should register  *      open/write/close callbacks.  *   3) Call archive_write_open to open the file  *   4) For each entry:  *      - construct an appropriate struct archive_entry structure  *      - archive_write_header to write the header  *      - archive_write_data to write the entry data  *   5) archive_write_finish to close the output and cleanup the writer  */
end_comment

begin_function_decl
name|struct
name|archive
modifier|*
name|archive_write_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_set_bytes_per_block
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|int
name|bytes_per_block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX This is badly misnamed; suggestions appreciated. XXX */
end_comment

begin_function_decl
name|int
name|archive_write_set_bytes_in_last_block
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|int
name|bytes_in_last_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_set_compression_bzip2
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_set_compression_gzip
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_set_compression_none
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A convenience function to set the format based on the code or name. */
end_comment

begin_function_decl
name|int
name|archive_write_set_format
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|int
name|format_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_set_format_by_name
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* To minimize link pollution, use one or more of the following. */
end_comment

begin_function_decl
name|int
name|archive_write_set_format_cpio
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TODO: int archive_write_set_format_old_tar(struct archive *); */
end_comment

begin_function_decl
name|int
name|archive_write_set_format_pax
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_set_format_pax_restricted
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_set_format_shar
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_set_format_shar_dump
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_set_format_ustar
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_open
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|archive_open_callback
modifier|*
parameter_list|,
name|archive_write_callback
modifier|*
parameter_list|,
name|archive_close_callback
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_open_fd
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|int
name|_fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_open_file
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|_file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Note that the library will truncate writes beyond the size provided  * to archive_write_header or pad if the provided data is short.  */
end_comment

begin_function_decl
name|int
name|archive_write_header
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_write_data
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_write_finish
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Accessor functions to read/set various information in  * the struct archive object:  */
end_comment

begin_comment
comment|/* Bytes written after compression or read before decompression. */
end_comment

begin_function_decl
name|int64_t
name|archive_position_compressed
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Bytes written to compressor or read from decompressor. */
end_comment

begin_function_decl
name|int64_t
name|archive_position_uncompressed
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_compression_name
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_compression
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_errno
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_error_string
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_format_name
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_format
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* void		 archive_set_errno(struct archive *, int); */
end_comment

begin_comment
comment|/* void		 archive_error_printf(struct archive *, const char *fmt, ...); */
end_comment

begin_function_decl
name|void
name|archive_set_error
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|int
name|_err
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ARCHIVE_H_INCLUDED */
end_comment

end_unit

