begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * unzip.c -- decompress files in gzip or pkzip format.  * Copyright (C) 1992-1993 Jean-loup Gailly  *  * Adapted for Linux booting by Hannu Savolainen 1993  * Adapted for FreeBSD booting by Serge Vakulenko  *  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  *  * The code in this file is derived from the file funzip.c written  * and put in the public domain by Mark Adler.  */
end_comment

begin_comment
comment|/*  * This version can extract files in gzip or pkzip format.  * For the latter, only the first entry is extracted, and it has to be  * either deflated or stored.  */
end_comment

begin_include
include|#
directive|include
file|"gzip.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/inflate.h>
end_include

begin_comment
comment|/* PKZIP header definitions */
end_comment

begin_define
define|#
directive|define
name|LOCSIG
value|0x04034b50L
end_define

begin_comment
comment|/* four-byte lead-in (lsb first) */
end_comment

begin_define
define|#
directive|define
name|LOCFLG
value|6
end_define

begin_comment
comment|/* offset of bit flag */
end_comment

begin_define
define|#
directive|define
name|CRPFLG
value|1
end_define

begin_comment
comment|/*  bit for encrypted entry */
end_comment

begin_define
define|#
directive|define
name|EXTFLG
value|8
end_define

begin_comment
comment|/*  bit for extended local header */
end_comment

begin_define
define|#
directive|define
name|LOCHOW
value|8
end_define

begin_comment
comment|/* offset of compression method */
end_comment

begin_define
define|#
directive|define
name|LOCTIM
value|10
end_define

begin_comment
comment|/* file mod time (for decryption) */
end_comment

begin_define
define|#
directive|define
name|LOCCRC
value|14
end_define

begin_comment
comment|/* offset of crc */
end_comment

begin_define
define|#
directive|define
name|LOCSIZ
value|18
end_define

begin_comment
comment|/* offset of compressed size */
end_comment

begin_define
define|#
directive|define
name|LOCLEN
value|22
end_define

begin_comment
comment|/* offset of uncompressed length */
end_comment

begin_define
define|#
directive|define
name|LOCFIL
value|26
end_define

begin_comment
comment|/* offset of file name field length */
end_comment

begin_define
define|#
directive|define
name|LOCEXT
value|28
end_define

begin_comment
comment|/* offset of extra field length */
end_comment

begin_define
define|#
directive|define
name|LOCHDR
value|30
end_define

begin_comment
comment|/* size of local header, including sig */
end_comment

begin_define
define|#
directive|define
name|EXTHDR
value|16
end_define

begin_comment
comment|/* size of extended local header, inc sig */
end_comment

begin_decl_stmt
name|int
name|pkzip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set for a pkzip file */
end_comment

begin_decl_stmt
name|int
name|extended
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if extended local header */
end_comment

begin_comment
comment|/* Macros for getting two-byte and four-byte header values */
end_comment

begin_define
define|#
directive|define
name|SH
parameter_list|(
name|p
parameter_list|)
value|((ushort)(uchar)((p)[0]) | ((ushort)(uchar)((p)[1])<< 8))
end_define

begin_define
define|#
directive|define
name|LG
parameter_list|(
name|p
parameter_list|)
value|((ulong)(SH(p)) | ((ulong)(SH((p)+2))<< 16))
end_define

begin_comment
comment|/*  * Check zip file and advance inptr to the start of the compressed data.  * Get ofname from the local header if necessary.  */
end_comment

begin_function
name|void
name|check_zipfile
parameter_list|()
block|{
name|uchar
modifier|*
name|h
init|=
name|inbuf
operator|+
name|inptr
decl_stmt|;
comment|/* first local header */
comment|/* Check validity of local header, and skip name and extra fields */
name|inptr
operator|+=
name|LOCHDR
operator|+
name|SH
argument_list|(
name|h
operator|+
name|LOCFIL
argument_list|)
operator|+
name|SH
argument_list|(
name|h
operator|+
name|LOCEXT
argument_list|)
expr_stmt|;
if|if
condition|(
name|inptr
operator|>
name|insize
operator|||
name|LG
argument_list|(
name|h
argument_list|)
operator|!=
name|LOCSIG
condition|)
name|error
argument_list|(
literal|"input not a zip"
argument_list|)
expr_stmt|;
name|method
operator|=
name|h
index|[
name|LOCHOW
index|]
expr_stmt|;
if|if
condition|(
name|method
operator|!=
name|STORED
operator|&&
name|method
operator|!=
name|DEFLATED
condition|)
name|error
argument_list|(
literal|"first entry not deflated or stored--can't extract"
argument_list|)
expr_stmt|;
comment|/* If entry encrypted, decrypt and validate encryption header */
if|if
condition|(
name|h
index|[
name|LOCFLG
index|]
operator|&
name|CRPFLG
condition|)
name|error
argument_list|(
literal|"encrypted file"
argument_list|)
expr_stmt|;
comment|/* Save flags for unzip() */
name|extended
operator|=
operator|(
name|h
index|[
name|LOCFLG
index|]
operator|&
name|EXTFLG
operator|)
operator|!=
literal|0
expr_stmt|;
name|pkzip
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|int
name|Flush
parameter_list|(
name|void
modifier|*
name|nu
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|u_long
name|cnt
parameter_list|)
block|{
name|outcnt
operator|=
name|cnt
expr_stmt|;
name|flush_window
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|NextByte
parameter_list|(
name|void
modifier|*
name|nu
parameter_list|)
block|{
return|return
operator|(
operator|(
name|int
operator|)
name|get_byte
argument_list|()
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|inflate
name|infl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* put it into the BSS */
end_comment

begin_comment
comment|/*  * Unzip in to out.  This routine works on both gzip and pkzip files.  *  * IN assertions: the buffer inbuf contains already the beginning of  * the compressed data, from offsets inptr to insize-1 included.  * The magic header has already been checked. The output buffer is cleared.  */
end_comment

begin_function
name|void
name|unzip
parameter_list|()
block|{
name|ulong
name|orig_crc
init|=
literal|0
decl_stmt|;
comment|/* original crc */
name|ulong
name|orig_len
init|=
literal|0
decl_stmt|;
comment|/* original uncompressed length */
name|uchar
name|buf
index|[
name|EXTHDR
index|]
decl_stmt|;
comment|/* extended local header */
name|int
name|n
decl_stmt|,
name|res
decl_stmt|;
name|crc
operator|=
literal|0xffffffffL
expr_stmt|;
comment|/* initialize crc */
if|if
condition|(
name|pkzip
operator|&&
operator|!
name|extended
condition|)
block|{
comment|/* crc and length at the end otherwise */
name|orig_crc
operator|=
name|LG
argument_list|(
name|inbuf
operator|+
name|LOCCRC
argument_list|)
expr_stmt|;
name|orig_len
operator|=
name|LG
argument_list|(
name|inbuf
operator|+
name|LOCLEN
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|method
operator|!=
name|DEFLATED
condition|)
name|error
argument_list|(
literal|"internal error, invalid method"
argument_list|)
expr_stmt|;
name|infl
operator|.
name|gz_input
operator|=
name|NextByte
expr_stmt|;
name|infl
operator|.
name|gz_output
operator|=
name|Flush
expr_stmt|;
name|infl
operator|.
name|gz_slide
operator|=
name|window
expr_stmt|;
name|res
operator|=
name|inflate
argument_list|(
operator|&
name|infl
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|==
literal|3
condition|)
name|error
argument_list|(
literal|"out of memory"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|res
operator|!=
literal|0
condition|)
name|error
argument_list|(
literal|"invalid compressed format"
argument_list|)
expr_stmt|;
comment|/* Get the crc and original length */
if|if
condition|(
operator|!
name|pkzip
condition|)
block|{
comment|/* crc32 (see algorithm.doc) 		 * uncompressed input size modulo 2^32 		 */
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
literal|8
condition|;
name|n
operator|++
control|)
name|buf
index|[
name|n
index|]
operator|=
name|get_byte
argument_list|()
expr_stmt|;
comment|/* may cause an error if EOF */
name|orig_crc
operator|=
name|LG
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|orig_len
operator|=
name|LG
argument_list|(
name|buf
operator|+
literal|4
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|extended
condition|)
block|{
comment|/* If extended header, check it */
comment|/* signature - 4bytes: 0x50 0x4b 0x07 0x08 		 * CRC-32 value 		 * compressed size 4-bytes 		 * uncompressed size 4-bytes 		 */
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|EXTHDR
condition|;
name|n
operator|++
control|)
name|buf
index|[
name|n
index|]
operator|=
name|get_byte
argument_list|()
expr_stmt|;
comment|/* may cause an error if EOF */
name|orig_crc
operator|=
name|LG
argument_list|(
name|buf
operator|+
literal|4
argument_list|)
expr_stmt|;
name|orig_len
operator|=
name|LG
argument_list|(
name|buf
operator|+
literal|12
argument_list|)
expr_stmt|;
block|}
comment|/* Validate decompression */
if|if
condition|(
name|orig_crc
operator|!=
operator|(
name|crc
operator|^
literal|0xffffffffL
operator|)
condition|)
name|error
argument_list|(
literal|"crc error"
argument_list|)
expr_stmt|;
if|if
condition|(
name|orig_len
operator|!=
name|output_ptr
condition|)
name|error
argument_list|(
literal|"length error"
argument_list|)
expr_stmt|;
comment|/* Check if there are more entries in a pkzip file */
if|if
condition|(
name|pkzip
operator|&&
name|inptr
operator|+
literal|4
operator|<
name|insize
operator|&&
name|LG
argument_list|(
name|inbuf
operator|+
name|inptr
argument_list|)
operator|==
name|LOCSIG
condition|)
name|error
argument_list|(
literal|"zip file has more than one entry"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

