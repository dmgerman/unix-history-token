begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* stream.h */
end_comment

begin_comment
comment|/* Definitions for Ghostscript stream package */
end_comment

begin_comment
comment|/* Requires stdio.h */
end_comment

begin_comment
comment|/*  * Note that the stream package works with bytes, not chars.  * This is to ensure unsigned representation on all systems.  * A stream currently can only be read or written, not both.  * Note also that the read procedure returns an int,  * not a char or a byte, so we can use negative values for EOFC and ERRC.  * We distinguish "data" from "signal" results (EOFC, ERRC) with a macro:  */
end_comment

begin_define
define|#
directive|define
name|char_is_data
parameter_list|(
name|c
parameter_list|)
value|((c)>= 0)
end_define

begin_define
define|#
directive|define
name|char_is_signal
parameter_list|(
name|c
parameter_list|)
value|((c)< 0)
end_define

begin_typedef
typedef|typedef
name|struct
name|stream_s
name|stream
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Store # available for reading. */
comment|/* Return 0 if OK, ERRC if error or not implemented. */
name|int
argument_list|(
operator|*
name|available
argument_list|)
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|long
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Set position. */
comment|/* Return 0 if OK, ERRC if error or not implemented. */
name|int
argument_list|(
operator|*
name|seek
argument_list|)
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|long
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Flush buffered data. */
comment|/* Return 0 if OK, ERRC if error. */
name|int
argument_list|(
operator|*
name|flush
argument_list|)
argument_list|(
name|P1
argument_list|(
name|stream
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Flush data (if writing)& close stream. */
comment|/* Return 0 if OK, ERRC if error. */
name|int
argument_list|(
operator|*
name|close
argument_list|)
argument_list|(
name|P1
argument_list|(
name|stream
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Refill buffer and reset cptr. */
comment|/* Return ERRC if not implemented; */
comment|/* otherwise, set end_status appropriately and return 0. */
name|int
argument_list|(
operator|*
name|read_buf
argument_list|)
argument_list|(
name|P1
argument_list|(
name|stream
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Write buffer, reset cptr. */
comment|/* Return 0 if OK, ERRC if error or not implemented. */
name|int
argument_list|(
operator|*
name|write_buf
argument_list|)
argument_list|(
name|P1
argument_list|(
name|stream
operator|*
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|stream_procs
typedef|;
end_typedef

begin_comment
comment|/* Structs for specialized streams -- see below. */
end_comment

begin_struct_decl
struct_decl|struct
name|lzw_decode_table_s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lzw_encode_table_s
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|stream_s
block|{
name|byte
modifier|*
name|cptr
decl_stmt|;
comment|/* pointer to last byte */
comment|/* read or written */
name|byte
modifier|*
name|endptr
decl_stmt|;
comment|/* pointer to last byte */
comment|/* containing data for reading, */
comment|/* or to be filled for writing */
name|byte
modifier|*
name|cbuf
decl_stmt|;
comment|/* base of buffer */
name|uint
name|bsize
decl_stmt|;
comment|/* size of buffer, 0 if closed */
name|uint
name|cbsize
decl_stmt|;
comment|/* size of buffer */
name|char
name|mode
decl_stmt|;
comment|/* 2 if reading, 1 if writing */
define|#
directive|define
name|s_mode_read
value|2
define|#
directive|define
name|s_mode_write
value|1
define|#
directive|define
name|s_is_valid
parameter_list|(
name|s
parameter_list|)
value|((s)->mode != 0)
define|#
directive|define
name|s_is_reading
parameter_list|(
name|s
parameter_list|)
value|((s)->mode == s_mode_read)
define|#
directive|define
name|s_is_writing
parameter_list|(
name|s
parameter_list|)
value|((s)->mode == s_mode_write)
name|int
name|end_status
decl_stmt|;
comment|/* EOFC if at EOF when buffer */
comment|/* becomes empty, ERRC if error */
name|long
name|position
decl_stmt|;
comment|/* file position of beginning of */
comment|/* buffer, -1 means not seekable */
name|stream_procs
name|procs
decl_stmt|;
name|int
name|num_format
decl_stmt|;
comment|/* format for Level 2 */
comment|/* encoded number reader */
comment|/* (only used locally) */
comment|/* strm is non-zero iff this is a filter stream. */
name|stream
modifier|*
name|strm
decl_stmt|;
comment|/* the underlying stream */
name|int
name|strm_is_temp
decl_stmt|;
comment|/* if true, strm is a temporary */
comment|/* stream and should be freed */
comment|/* when this stream is closed */
comment|/* 	 * If were were able to program in a real object-oriented style,  	 * the remaining data would be per-subclass.  It's just too much 	 * of a nuisance to do this in C, so we allocate space for the 	 * private data of ALL subclasses. 	 */
comment|/* The following are for file streams. */
name|FILE
modifier|*
name|file
decl_stmt|;
comment|/* file handle for C library */
name|int
name|can_close
decl_stmt|;
comment|/* 0 for stdin/out/err, */
comment|/* -1 for line/statementedit, */
comment|/* 1 for other files */
name|stream
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
comment|/* keep track of all files */
comment|/* The following is used by several decoding filters. */
name|int
name|odd
decl_stmt|;
comment|/* odd digit */
comment|/* The following are for RunLengthEncode filters. */
name|ulong
name|record_size
decl_stmt|;
comment|/* The following is for RunLengthEncode and PFBDecode. */
name|ulong
name|record_left
decl_stmt|;
comment|/* bytes left in current record */
comment|/* The following are for PFBDecode. */
name|int
name|record_type
decl_stmt|;
comment|/* The following are for eexec streams. */
name|ushort
name|cstate
decl_stmt|;
comment|/* encryption state */
name|int
name|binary
decl_stmt|;
comment|/* true=binary, false=hex */
comment|/* The following are for LZW encoding/decoding streams. */
name|int
name|enhanced
decl_stmt|;
comment|/* if true, use Aladdin's */
comment|/* enhanced compression algorithm */
comment|/* (Patent Pending) */
name|byte
name|bits
decl_stmt|;
comment|/* most recent byte of input or */
comment|/* current byte of output */
name|int
name|bits_left
decl_stmt|;
comment|/* # of unused low bits in above, [0..7] */
name|struct
name|lzw_decode_table_s
modifier|*
name|decode_table
decl_stmt|;
comment|/* decoding table */
name|struct
name|lzw_encode_table_s
modifier|*
name|encode_table
decl_stmt|;
comment|/* encoding table */
name|uint
name|next_code
decl_stmt|;
comment|/* next code to be assigned */
name|int
name|code_size
decl_stmt|;
comment|/* current # of bits per code */
name|int
name|prev_code
decl_stmt|;
comment|/* previous code recognized */
comment|/* or assigned */
block|}
struct|;
end_struct

begin_comment
comment|/* Stream functions.  Some of these are macros -- beware. */
end_comment

begin_comment
comment|/* Also note that unlike the C stream library, */
end_comment

begin_comment
comment|/* ALL stream procedures take the stream as the first argument. */
end_comment

begin_define
define|#
directive|define
name|sendbufp
parameter_list|(
name|s
parameter_list|)
value|((s)->cptr>= (s)->endptr)
end_define

begin_comment
comment|/* not for clients */
end_comment

begin_comment
comment|/* Following are valid for all streams. */
end_comment

begin_comment
comment|/* flush is a no-op for read streams. */
end_comment

begin_comment
comment|/* close is NOT a no-op for non-file streams -- */
end_comment

begin_comment
comment|/* it actively disables them. */
end_comment

begin_comment
comment|/* The close routine must do a flush if needed. */
end_comment

begin_define
define|#
directive|define
name|sseekable
parameter_list|(
name|s
parameter_list|)
value|((s)->position>= 0)
end_define

begin_define
define|#
directive|define
name|serrorp
parameter_list|(
name|s
parameter_list|)
value|((s)->cptr>= (s)->endptr&& (s)->end_status == ERRC)
end_define

begin_define
define|#
directive|define
name|savailable
parameter_list|(
name|s
parameter_list|,
name|pl
parameter_list|)
value|(*(s)->procs.available)(s,pl)
end_define

begin_define
define|#
directive|define
name|sflush
parameter_list|(
name|s
parameter_list|)
value|(*(s)->procs.flush)(s)
end_define

begin_define
define|#
directive|define
name|sclose
parameter_list|(
name|s
parameter_list|)
value|(*(s)->procs.close)(s)
end_define

begin_comment
comment|/* Following are only valid for read streams. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|spgetc
argument_list|(
name|P1
argument_list|(
name|stream
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sgetc
parameter_list|(
name|s
parameter_list|)
value|(!sendbufp(s) ? *++((s)->cptr) : spgetc(s))
end_define

begin_decl_stmt
specifier|extern
name|uint
name|sgets
argument_list|(
name|P3
argument_list|(
name|stream
operator|*
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sreadhex
argument_list|(
name|P6
argument_list|(
name|stream
operator|*
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|,
name|uint
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sungetc
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|byte
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ERRC on error, 0 if OK */
end_comment

begin_define
define|#
directive|define
name|sputback
parameter_list|(
name|s
parameter_list|)
value|((s)->cptr--)
end_define

begin_define
define|#
directive|define
name|seofp
parameter_list|(
name|s
parameter_list|)
value|(sendbufp(s)&& (s)->end_status == EOFC)
end_define

begin_comment
comment|/* Following are only valid for write streams. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|spputc
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|byte
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sputc
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
define|\
value|(!sendbufp(s) ? ((int)(*++((s)->cptr)=(c))) : spputc((s),(c)))
end_define

begin_decl_stmt
specifier|extern
name|uint
name|sputs
argument_list|(
name|P3
argument_list|(
name|stream
operator|*
argument_list|,
specifier|const
name|byte
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Following are only valid for positionable streams. */
end_comment

begin_define
define|#
directive|define
name|stell
parameter_list|(
name|s
parameter_list|)
value|((s)->cptr + 1 - (s)->cbuf + (s)->position)
end_define

begin_define
define|#
directive|define
name|sseek
parameter_list|(
name|s
parameter_list|,
name|pos
parameter_list|)
value|(*(s)->procs.seek)(s,(long)(pos))
end_define

begin_comment
comment|/* Following are for high-performance clients. */
end_comment

begin_comment
comment|/* bufptr points to the next item, bufend points beyond the last item. */
end_comment

begin_define
define|#
directive|define
name|sbufptr
parameter_list|(
name|s
parameter_list|)
value|((s)->cptr + 1)
end_define

begin_define
define|#
directive|define
name|sbufend
parameter_list|(
name|s
parameter_list|)
value|((s)->endptr + 1)
end_define

begin_define
define|#
directive|define
name|ssetbufptr
parameter_list|(
name|s
parameter_list|,
name|ptr
parameter_list|)
value|((s)->cptr = (ptr) - 1)
end_define

begin_define
define|#
directive|define
name|sbufavailable
parameter_list|(
name|s
parameter_list|)
value|((s)->endptr - (s)->cptr)
end_define

begin_comment
comment|/* We cast EOFC and ERRC to int explicitly, because some compilers */
end_comment

begin_comment
comment|/* don't do this if the other arm of a conditional is a byte. */
end_comment

begin_comment
comment|/* Clients should use char_is_data and char_is_signal (see above) */
end_comment

begin_comment
comment|/* to test for exceptional results. */
end_comment

begin_define
define|#
directive|define
name|EOFC
value|((int)(-1))
end_define

begin_define
define|#
directive|define
name|ERRC
value|((int)(-2))
end_define

begin_comment
comment|/****** ERRC IS NOT RECOGNIZED IN MOST PLACES YET ******/
end_comment

begin_comment
comment|/* Stream creation procedures */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sread_string
argument_list|(
name|P3
argument_list|(
name|stream
operator|*
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|,
name|swrite_string
argument_list|(
name|P3
argument_list|(
name|stream
operator|*
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sread_file
argument_list|(
name|P4
argument_list|(
name|stream
operator|*
argument_list|,
name|FILE
operator|*
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|,
name|swrite_file
argument_list|(
name|P4
argument_list|(
name|stream
operator|*
argument_list|,
name|FILE
operator|*
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Standard stream initialization */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|s_std_init
argument_list|(
name|P5
argument_list|(
name|stream
operator|*
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|,
name|stream_procs
operator|*
argument_list|,
name|int
comment|/*mode*/
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Standard stream finalization */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|s_disable
argument_list|(
name|P1
argument_list|(
name|stream
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic stream procedures exported for filters */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|s_std_null
argument_list|(
name|P1
argument_list|(
name|stream
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|s_std_noavailable
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|long
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|s_std_close
argument_list|(
name|P1
argument_list|(
name|stream
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

