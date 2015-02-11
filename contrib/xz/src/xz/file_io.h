begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       file_io.h
end_comment

begin_comment
comment|/// \brief      I/O types and functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Some systems have suboptimal BUFSIZ. Use a bit bigger value on them.
end_comment

begin_comment
comment|// We also need that IO_BUFFER_SIZE is a multiple of 8 (sizeof(uint64_t))
end_comment

begin_if
if|#
directive|if
name|BUFSIZ
operator|<=
literal|1024
end_if

begin_define
define|#
directive|define
name|IO_BUFFER_SIZE
value|8192
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IO_BUFFER_SIZE
value|(BUFSIZ& ~7U)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// is_sparse() accesses the buffer as uint64_t for maximum speed.
end_comment

begin_comment
comment|/// Use an union to make sure that the buffer is properly aligned.
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|u8
index|[
name|IO_BUFFER_SIZE
index|]
decl_stmt|;
name|uint32_t
name|u32
index|[
name|IO_BUFFER_SIZE
operator|/
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
index|]
decl_stmt|;
name|uint64_t
name|u64
index|[
name|IO_BUFFER_SIZE
operator|/
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
index|]
decl_stmt|;
block|}
name|io_buf
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/// Name of the source filename (as given on the command line) or
comment|/// pointer to static "(stdin)" when reading from standard input.
specifier|const
name|char
modifier|*
name|src_name
decl_stmt|;
comment|/// Destination filename converted from src_name or pointer to static
comment|/// "(stdout)" when writing to standard output.
name|char
modifier|*
name|dest_name
decl_stmt|;
comment|/// File descriptor of the source file
name|int
name|src_fd
decl_stmt|;
comment|/// File descriptor of the target file
name|int
name|dest_fd
decl_stmt|;
comment|/// True once end of the source file has been detected.
name|bool
name|src_eof
decl_stmt|;
comment|/// If true, we look for long chunks of zeros and try to create
comment|/// a sparse file.
name|bool
name|dest_try_sparse
decl_stmt|;
comment|/// This is used only if dest_try_sparse is true. This holds the
comment|/// number of zero bytes we haven't written out, because we plan
comment|/// to make that byte range a sparse chunk.
name|off_t
name|dest_pending_sparse
decl_stmt|;
comment|/// Stat of the source file.
name|struct
name|stat
name|src_st
decl_stmt|;
comment|/// Stat of the destination file.
name|struct
name|stat
name|dest_st
decl_stmt|;
block|}
name|file_pair
typedef|;
end_typedef

begin_comment
comment|/// \brief      Initialize the I/O module
end_comment

begin_function_decl
specifier|extern
name|void
name|io_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_DOSLIKE
end_ifndef

begin_comment
comment|/// \brief      Write a byte to user_abort_pipe[1]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is called from a signal handler.
end_comment

begin_function_decl
specifier|extern
name|void
name|io_write_to_user_abort_pipe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief      Disable creation of sparse files when decompressing
end_comment

begin_function_decl
specifier|extern
name|void
name|io_no_sparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Open the source file
end_comment

begin_function_decl
specifier|extern
name|file_pair
modifier|*
name|io_open_src
parameter_list|(
specifier|const
name|char
modifier|*
name|src_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Open the destination file
end_comment

begin_function_decl
specifier|extern
name|bool
name|io_open_dest
parameter_list|(
name|file_pair
modifier|*
name|pair
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Closes the file descriptors and frees possible allocated memory
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The success argument determines if source or destination file gets
end_comment

begin_comment
comment|/// unlinked:
end_comment

begin_comment
comment|///  - false: The destination file is unlinked.
end_comment

begin_comment
comment|///  - true: The source file is unlinked unless writing to stdout or --keep
end_comment

begin_comment
comment|///    was used.
end_comment

begin_function_decl
specifier|extern
name|void
name|io_close
parameter_list|(
name|file_pair
modifier|*
name|pair
parameter_list|,
name|bool
name|success
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Reads from the source file to a buffer
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      pair    File pair having the source file open for reading
end_comment

begin_comment
comment|/// \param      buf     Destination buffer to hold the read data
end_comment

begin_comment
comment|/// \param      size    Size of the buffer; assumed be smaller than SSIZE_MAX
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     On success, number of bytes read is returned. On end of
end_comment

begin_comment
comment|///             file zero is returned and pair->src_eof set to true.
end_comment

begin_comment
comment|///             On error, SIZE_MAX is returned and error message printed.
end_comment

begin_function_decl
specifier|extern
name|size_t
name|io_read
parameter_list|(
name|file_pair
modifier|*
name|pair
parameter_list|,
name|io_buf
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Fix the position in src_fd
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used when --single-thream has been specified and decompression
end_comment

begin_comment
comment|/// is successful. If the input file descriptor supports seeking, this
end_comment

begin_comment
comment|/// function fixes the input position to point to the next byte after the
end_comment

begin_comment
comment|/// decompressed stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      pair        File pair having the source file open for reading
end_comment

begin_comment
comment|/// \param      rewind_size How many bytes of extra have been read i.e.
end_comment

begin_comment
comment|///                         how much to seek backwards.
end_comment

begin_function_decl
specifier|extern
name|void
name|io_fix_src_pos
parameter_list|(
name|file_pair
modifier|*
name|pair
parameter_list|,
name|size_t
name|rewind_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Read from source file from given offset to a buffer
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is remotely similar to standard pread(). This uses lseek() though,
end_comment

begin_comment
comment|/// so the read offset is changed on each call.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      pair    Seekable source file
end_comment

begin_comment
comment|/// \param      buf     Destination buffer
end_comment

begin_comment
comment|/// \param      size    Amount of data to read
end_comment

begin_comment
comment|/// \param      pos     Offset relative to the beginning of the file,
end_comment

begin_comment
comment|///                     from which the data should be read.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     On success, false is returned. On error, error message
end_comment

begin_comment
comment|///             is printed and true is returned.
end_comment

begin_function_decl
specifier|extern
name|bool
name|io_pread
parameter_list|(
name|file_pair
modifier|*
name|pair
parameter_list|,
name|io_buf
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|off_t
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Writes a buffer to the destination file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      pair    File pair having the destination file open for writing
end_comment

begin_comment
comment|/// \param      buf     Buffer containing the data to be written
end_comment

begin_comment
comment|/// \param      size    Size of the buffer; assumed be smaller than SSIZE_MAX
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     On success, zero is returned. On error, -1 is returned
end_comment

begin_comment
comment|///             and error message printed.
end_comment

begin_function_decl
specifier|extern
name|bool
name|io_write
parameter_list|(
name|file_pair
modifier|*
name|pair
parameter_list|,
specifier|const
name|io_buf
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

end_unit

