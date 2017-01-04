begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * A C++ I/O streams interface to the zlib gz* functions  *  * by Ludwig Schwardt<schwardt@sun.ac.za>  * original version by Kevin Ruland<kevin@rodin.wustl.edu>  *  * This version is standard-compliant and compatible with gcc 3.x.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZFSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|ZFSTREAM_H
end_define

begin_include
include|#
directive|include
file|<istream>
end_include

begin_comment
comment|// not iostream, since we don't need cin/cout
end_comment

begin_include
include|#
directive|include
file|<ostream>
end_include

begin_include
include|#
directive|include
file|"zlib.h"
end_include

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/**  *  @brief  Gzipped file stream buffer class.  *  *  This class implements basic_filebuf for gzipped files. It doesn't yet support  *  seeking (allowed by zlib but slow/limited), putback and read/write access  *  (tricky). Otherwise, it attempts to be a drop-in replacement for the standard  *  file streambuf. */
end_comment

begin_decl_stmt
name|class
name|gzfilebuf
range|:
name|public
name|std
operator|::
name|streambuf
block|{
name|public
operator|:
comment|//  Default constructor.
name|gzfilebuf
argument_list|()
block|;
comment|//  Destructor.
name|virtual
operator|~
name|gzfilebuf
argument_list|()
block|;
comment|/**    *  @brief  Set compression level and strategy on the fly.    *  @param  comp_level  Compression level (see zlib.h for allowed values)    *  @param  comp_strategy  Compression strategy (see zlib.h for allowed values)    *  @return  Z_OK on success, Z_STREAM_ERROR otherwise.    *    *  Unfortunately, these parameters cannot be modified separately, as the    *  previous zfstream version assumed. Since the strategy is seldom changed,    *  it can default and setcompression(level) then becomes like the old    *  setcompressionlevel(level).   */
name|int
name|setcompression
argument_list|(
argument|int comp_level
argument_list|,
argument|int comp_strategy = Z_DEFAULT_STRATEGY
argument_list|)
block|;
comment|/**    *  @brief  Check if file is open.    *  @return  True if file is open.   */
name|bool
name|is_open
argument_list|()
specifier|const
block|{
return|return
operator|(
name|file
operator|!=
name|NULL
operator|)
return|;
block|}
comment|/**    *  @brief  Open gzipped file.    *  @param  name  File name.    *  @param  mode  Open mode flags.    *  @return  @c this on success, NULL on failure.   */
name|gzfilebuf
operator|*
name|open
argument_list|(
argument|const char* name
argument_list|,
argument|std::ios_base::openmode mode
argument_list|)
block|;
comment|/**    *  @brief  Attach to already open gzipped file.    *  @param  fd  File descriptor.    *  @param  mode  Open mode flags.    *  @return  @c this on success, NULL on failure.   */
name|gzfilebuf
operator|*
name|attach
argument_list|(
argument|int fd
argument_list|,
argument|std::ios_base::openmode mode
argument_list|)
block|;
comment|/**    *  @brief  Close gzipped file.    *  @return  @c this on success, NULL on failure.   */
name|gzfilebuf
operator|*
name|close
argument_list|()
block|;
name|protected
operator|:
comment|/**    *  @brief  Convert ios open mode int to mode string used by zlib.    *  @return  True if valid mode flag combination.   */
name|bool
name|open_mode
argument_list|(
argument|std::ios_base::openmode mode
argument_list|,
argument|char* c_mode
argument_list|)
specifier|const
block|;
comment|/**    *  @brief  Number of characters available in stream buffer.    *  @return  Number of characters.    *    *  This indicates number of characters in get area of stream buffer.    *  These characters can be read without accessing the gzipped file.   */
name|virtual
name|std
operator|::
name|streamsize
name|showmanyc
argument_list|()
block|;
comment|/**    *  @brief  Fill get area from gzipped file.    *  @return  First character in get area on success, EOF on error.    *    *  This actually reads characters from gzipped file to stream    *  buffer. Always buffered.   */
name|virtual
name|int_type
name|underflow
argument_list|()
block|;
comment|/**    *  @brief  Write put area to gzipped file.    *  @param  c  Extra character to add to buffer contents.    *  @return  Non-EOF on success, EOF on error.    *    *  This actually writes characters in stream buffer to    *  gzipped file. With unbuffered output this is done one    *  character at a time.   */
name|virtual
name|int_type
name|overflow
argument_list|(
argument|int_type c = traits_type::eof()
argument_list|)
block|;
comment|/**    *  @brief  Installs external stream buffer.    *  @param  p  Pointer to char buffer.    *  @param  n  Size of external buffer.    *  @return  @c this on success, NULL on failure.    *    *  Call setbuf(0,0) to enable unbuffered output.   */
name|virtual
name|std
operator|::
name|streambuf
operator|*
name|setbuf
argument_list|(
argument|char_type* p
argument_list|,
argument|std::streamsize n
argument_list|)
block|;
comment|/**    *  @brief  Flush stream buffer to file.    *  @return  0 on success, -1 on error.    *    *  This calls underflow(EOF) to do the job.   */
name|virtual
name|int
name|sync
argument_list|()
block|;
comment|//
comment|// Some future enhancements
comment|//
comment|//  virtual int_type uflow();
comment|//  virtual int_type pbackfail(int_type c = traits_type::eof());
comment|//  virtual pos_type
comment|//  seekoff(off_type off,
comment|//          std::ios_base::seekdir way,
comment|//          std::ios_base::openmode mode = std::ios_base::in|std::ios_base::out);
comment|//  virtual pos_type
comment|//  seekpos(pos_type sp,
comment|//          std::ios_base::openmode mode = std::ios_base::in|std::ios_base::out);
name|private
operator|:
comment|/**    *  @brief  Allocate internal buffer.    *    *  This function is safe to call multiple times. It will ensure    *  that a proper internal buffer exists if it is required. If the    *  buffer already exists or is external, the buffer pointers will be    *  reset to their original state.   */
name|void
name|enable_buffer
argument_list|()
block|;
comment|/**    *  @brief  Destroy internal buffer.    *    *  This function is safe to call multiple times. It will ensure    *  that the internal buffer is deallocated if it exists. In any    *  case, it will also reset the buffer pointers.   */
name|void
name|disable_buffer
argument_list|()
block|;
comment|/**    *  Underlying file pointer.   */
name|gzFile
name|file
block|;
comment|/**    *  Mode in which file was opened.   */
name|std
operator|::
name|ios_base
operator|::
name|openmode
name|io_mode
block|;
comment|/**    *  @brief  True if this object owns file descriptor.    *    *  This makes the class responsible for closing the file    *  upon destruction.   */
name|bool
name|own_fd
block|;
comment|/**    *  @brief  Stream buffer.    *    *  For simplicity this remains allocated on the free store for the    *  entire life span of the gzfilebuf object, unless replaced by setbuf.   */
name|char_type
operator|*
name|buffer
block|;
comment|/**    *  @brief  Stream buffer size.    *    *  Defaults to system default buffer size (typically 8192 bytes).    *  Modified by setbuf.   */
name|std
operator|::
name|streamsize
name|buffer_size
block|;
comment|/**    *  @brief  True if this object owns stream buffer.    *    *  This makes the class responsible for deleting the buffer    *  upon destruction.   */
name|bool
name|own_buffer
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/**  *  @brief  Gzipped file input stream class.  *  *  This class implements ifstream for gzipped files. Seeking and putback  *  is not supported yet. */
end_comment

begin_decl_stmt
name|class
name|gzifstream
range|:
name|public
name|std
operator|::
name|istream
block|{
name|public
operator|:
comment|//  Default constructor
name|gzifstream
argument_list|()
block|;
comment|/**    *  @brief  Construct stream on gzipped file to be opened.    *  @param  name  File name.    *  @param  mode  Open mode flags (forced to contain ios::in).   */
name|explicit
name|gzifstream
argument_list|(
argument|const char* name
argument_list|,
argument|std::ios_base::openmode mode = std::ios_base::in
argument_list|)
block|;
comment|/**    *  @brief  Construct stream on already open gzipped file.    *  @param  fd    File descriptor.    *  @param  mode  Open mode flags (forced to contain ios::in).   */
name|explicit
name|gzifstream
argument_list|(
argument|int fd
argument_list|,
argument|std::ios_base::openmode mode = std::ios_base::in
argument_list|)
block|;
comment|/**    *  Obtain underlying stream buffer.   */
name|gzfilebuf
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|gzfilebuf
operator|*
operator|>
operator|(
operator|&
name|sb
operator|)
return|;
block|}
comment|/**    *  @brief  Check if file is open.    *  @return  True if file is open.   */
name|bool
name|is_open
argument_list|()
block|{
return|return
name|sb
operator|.
name|is_open
argument_list|()
return|;
block|}
comment|/**    *  @brief  Open gzipped file.    *  @param  name  File name.    *  @param  mode  Open mode flags (forced to contain ios::in).    *    *  Stream will be in state good() if file opens successfully;    *  otherwise in state fail(). This differs from the behavior of    *  ifstream, which never sets the state to good() and therefore    *  won't allow you to reuse the stream for a second file unless    *  you manually clear() the state. The choice is a matter of    *  convenience.   */
name|void
name|open
argument_list|(
argument|const char* name
argument_list|,
argument|std::ios_base::openmode mode = std::ios_base::in
argument_list|)
block|;
comment|/**    *  @brief  Attach to already open gzipped file.    *  @param  fd  File descriptor.    *  @param  mode  Open mode flags (forced to contain ios::in).    *    *  Stream will be in state good() if attach succeeded; otherwise    *  in state fail().   */
name|void
name|attach
argument_list|(
argument|int fd
argument_list|,
argument|std::ios_base::openmode mode = std::ios_base::in
argument_list|)
block|;
comment|/**    *  @brief  Close gzipped file.    *    *  Stream will be in state fail() if close failed.   */
name|void
name|close
argument_list|()
block|;
name|private
operator|:
comment|/**    *  Underlying stream buffer.   */
name|gzfilebuf
name|sb
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/**  *  @brief  Gzipped file output stream class.  *  *  This class implements ofstream for gzipped files. Seeking and putback  *  is not supported yet. */
end_comment

begin_decl_stmt
name|class
name|gzofstream
range|:
name|public
name|std
operator|::
name|ostream
block|{
name|public
operator|:
comment|//  Default constructor
name|gzofstream
argument_list|()
block|;
comment|/**    *  @brief  Construct stream on gzipped file to be opened.    *  @param  name  File name.    *  @param  mode  Open mode flags (forced to contain ios::out).   */
name|explicit
name|gzofstream
argument_list|(
argument|const char* name
argument_list|,
argument|std::ios_base::openmode mode = std::ios_base::out
argument_list|)
block|;
comment|/**    *  @brief  Construct stream on already open gzipped file.    *  @param  fd    File descriptor.    *  @param  mode  Open mode flags (forced to contain ios::out).   */
name|explicit
name|gzofstream
argument_list|(
argument|int fd
argument_list|,
argument|std::ios_base::openmode mode = std::ios_base::out
argument_list|)
block|;
comment|/**    *  Obtain underlying stream buffer.   */
name|gzfilebuf
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|gzfilebuf
operator|*
operator|>
operator|(
operator|&
name|sb
operator|)
return|;
block|}
comment|/**    *  @brief  Check if file is open.    *  @return  True if file is open.   */
name|bool
name|is_open
argument_list|()
block|{
return|return
name|sb
operator|.
name|is_open
argument_list|()
return|;
block|}
comment|/**    *  @brief  Open gzipped file.    *  @param  name  File name.    *  @param  mode  Open mode flags (forced to contain ios::out).    *    *  Stream will be in state good() if file opens successfully;    *  otherwise in state fail(). This differs from the behavior of    *  ofstream, which never sets the state to good() and therefore    *  won't allow you to reuse the stream for a second file unless    *  you manually clear() the state. The choice is a matter of    *  convenience.   */
name|void
name|open
argument_list|(
argument|const char* name
argument_list|,
argument|std::ios_base::openmode mode = std::ios_base::out
argument_list|)
block|;
comment|/**    *  @brief  Attach to already open gzipped file.    *  @param  fd  File descriptor.    *  @param  mode  Open mode flags (forced to contain ios::out).    *    *  Stream will be in state good() if attach succeeded; otherwise    *  in state fail().   */
name|void
name|attach
argument_list|(
argument|int fd
argument_list|,
argument|std::ios_base::openmode mode = std::ios_base::out
argument_list|)
block|;
comment|/**    *  @brief  Close gzipped file.    *    *  Stream will be in state fail() if close failed.   */
name|void
name|close
argument_list|()
block|;
name|private
operator|:
comment|/**    *  Underlying stream buffer.   */
name|gzfilebuf
name|sb
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/**  *  @brief  Gzipped file output stream manipulator class.  *  *  This class defines a two-argument manipulator for gzofstream. It is used  *  as base for the setcompression(int,int) manipulator. */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|class
name|gzomanip2
block|{
name|public
operator|:
comment|// Allows insertor to peek at internals
name|template
operator|<
name|typename
name|Ta
block|,
name|typename
name|Tb
operator|>
name|friend
name|gzofstream
operator|&
name|operator
operator|<<
operator|(
name|gzofstream
operator|&
operator|,
specifier|const
name|gzomanip2
operator|<
name|Ta
operator|,
name|Tb
operator|>
operator|&
operator|)
block|;
comment|// Constructor
name|gzomanip2
argument_list|(
argument|gzofstream& (*f)(gzofstream&, T1, T2)
argument_list|,
argument|T1 v1
argument_list|,
argument|T2 v2
argument_list|)
block|;
name|private
operator|:
comment|// Underlying manipulator function
name|gzofstream
operator|&
call|(
modifier|*
name|func
call|)
argument_list|(
name|gzofstream
operator|&
argument_list|,
name|T1
argument_list|,
name|T2
argument_list|)
block|;
comment|// Arguments for manipulator function
name|T1
name|val1
block|;
name|T2
name|val2
block|;   }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|// Manipulator function thunks through to stream buffer
end_comment

begin_function
specifier|inline
name|gzofstream
modifier|&
name|setcompression
parameter_list|(
name|gzofstream
modifier|&
name|gzs
parameter_list|,
name|int
name|l
parameter_list|,
name|int
name|s
init|=
name|Z_DEFAULT_STRATEGY
parameter_list|)
block|{
operator|(
name|gzs
operator|.
name|rdbuf
argument_list|()
operator|)
operator|->
name|setcompression
argument_list|(
name|l
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
name|gzs
return|;
block|}
end_function

begin_comment
comment|// Manipulator constructor stores arguments
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
specifier|inline
name|gzomanip2
operator|<
name|T1
operator|,
name|T2
operator|>
operator|::
name|gzomanip2
argument_list|(
argument|gzofstream&(*f)(gzofstream&, T1, T2)
argument_list|,
argument|T1 v1
argument_list|,
argument|T2 v2
argument_list|)
operator|:
name|func
argument_list|(
name|f
argument_list|)
operator|,
name|val1
argument_list|(
name|v1
argument_list|)
operator|,
name|val2
argument_list|(
argument|v2
argument_list|)
block|{ }
comment|// Insertor applies underlying manipulator function to stream
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
specifier|inline
name|gzofstream
operator|&
name|operator
operator|<<
operator|(
name|gzofstream
operator|&
name|s
operator|,
specifier|const
name|gzomanip2
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|m
operator|)
block|{
return|return
call|(
modifier|*
name|m
operator|.
name|func
call|)
argument_list|(
name|s
argument_list|,
name|m
operator|.
name|val1
argument_list|,
name|m
operator|.
name|val2
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Insert this onto stream to simplify setting of compression level
end_comment

begin_expr_stmt
specifier|inline
name|gzomanip2
operator|<
name|int
operator|,
name|int
operator|>
name|setcompression
argument_list|(
argument|int l
argument_list|,
argument|int s = Z_DEFAULT_STRATEGY
argument_list|)
block|{
return|return
name|gzomanip2
operator|<
name|int
operator|,
name|int
operator|>
operator|(
operator|&
name|setcompression
operator|,
name|l
operator|,
name|s
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ZFSTREAM_H
end_comment

end_unit

