begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * gzip.h -- common declarations for all gzip modules  * Copyright (C) 1992-1993 Jean-loup Gailly.  * Adapted for FreeBSD boot unpacker by Serge Vakulenko.  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uchar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ulong
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_define
define|#
directive|define
name|STORED
value|0
end_define

begin_comment
comment|/* Compression methods */
end_comment

begin_define
define|#
directive|define
name|COMPRESSED
value|1
end_define

begin_define
define|#
directive|define
name|PACKED
value|2
end_define

begin_define
define|#
directive|define
name|DEFLATED
value|8
end_define

begin_comment
comment|/* methods 3 to 7 reserved */
end_comment

begin_define
define|#
directive|define
name|INBUFSIZ
value|0x8000
end_define

begin_comment
comment|/* input buffer size */
end_comment

begin_define
define|#
directive|define
name|OUTBUFSIZ
value|16384
end_define

begin_comment
comment|/* output buffer size */
end_comment

begin_define
define|#
directive|define
name|OUTBUF_EXTRA
value|2048
end_define

begin_comment
comment|/* required by unlzw() */
end_comment

begin_define
define|#
directive|define
name|GZIP_MAGIC
value|"\037\213"
end_define

begin_comment
comment|/* gzip files, 1F 8B */
end_comment

begin_define
define|#
directive|define
name|OLD_GZIP_MAGIC
value|"\037\236"
end_define

begin_comment
comment|/* gzip 0.5 = freeze 1.x */
end_comment

begin_define
define|#
directive|define
name|PKZIP_MAGIC
value|"PK\003\004"
end_define

begin_comment
comment|/* pkzip files */
end_comment

begin_define
define|#
directive|define
name|PACK_MAGIC
value|"\037\036"
end_define

begin_comment
comment|/* packed files */
end_comment

begin_define
define|#
directive|define
name|LZW_MAGIC
value|"\037\235"
end_define

begin_comment
comment|/* lzw files, 1F 9D */
end_comment

begin_comment
comment|/* gzip flag byte */
end_comment

begin_define
define|#
directive|define
name|ASCII_FLAG
value|0x01
end_define

begin_comment
comment|/* file probably ascii text */
end_comment

begin_define
define|#
directive|define
name|CONTINUATION
value|0x02
end_define

begin_comment
comment|/* cont. of multi-part gzip file */
end_comment

begin_define
define|#
directive|define
name|EXTRA_FIELD
value|0x04
end_define

begin_comment
comment|/* extra field present */
end_comment

begin_define
define|#
directive|define
name|ORIG_NAME
value|0x08
end_define

begin_comment
comment|/* original file name present */
end_comment

begin_define
define|#
directive|define
name|COMMENT
value|0x10
end_define

begin_comment
comment|/* file comment present */
end_comment

begin_define
define|#
directive|define
name|ENCRYPTED
value|0x20
end_define

begin_comment
comment|/* file is encrypted */
end_comment

begin_define
define|#
directive|define
name|RESERVED
value|0xC0
end_define

begin_comment
comment|/* reserved */
end_comment

begin_comment
comment|/* window size--must be a power of two, and */
end_comment

begin_comment
comment|/* at least 32K for zip's deflate method */
end_comment

begin_define
define|#
directive|define
name|WSIZE
value|0x8000
end_define

begin_decl_stmt
specifier|extern
name|int
name|method
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* compression method */
end_comment

begin_decl_stmt
specifier|extern
name|uchar
modifier|*
name|inbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input buffer */
end_comment

begin_decl_stmt
specifier|extern
name|uchar
modifier|*
name|outbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output buffer */
end_comment

begin_decl_stmt
specifier|extern
name|uchar
modifier|*
name|window
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sliding window and suffix table (unlzw) */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|insize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* valid bytes in inbuf */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|inptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index of next byte to be processed in inbuf */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|outcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bytes in output buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pkzip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set for a pkzip file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|extended
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if extended local header */
end_comment

begin_decl_stmt
specifier|extern
name|ulong
name|crc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shift register contents */
end_comment

begin_decl_stmt
specifier|extern
name|ulong
name|output_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total output bytes */
end_comment

begin_function_decl
specifier|extern
name|void
name|unzip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_zipfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|updcrc
parameter_list|(
name|uchar
modifier|*
name|s
parameter_list|,
name|unsigned
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_bufs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fill_inbuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flush_window
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|error
parameter_list|(
name|char
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|uchar
name|get_byte
parameter_list|()
block|{
if|if
condition|(
name|inptr
operator|>=
name|insize
condition|)
name|fill_inbuf
argument_list|()
expr_stmt|;
return|return
operator|(
name|inbuf
index|[
name|inptr
operator|++
index|]
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|put_char
parameter_list|(
name|uchar
name|c
parameter_list|)
block|{
name|window
index|[
name|outcnt
operator|++
index|]
operator|=
name|c
expr_stmt|;
if|if
condition|(
name|outcnt
operator|==
name|WSIZE
condition|)
name|flush_window
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

