begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* unzip.c -- decompress files in gzip or pkzip format.  * Copyright (C) 1992-1993 Jean-loup Gailly  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  *  * The code in this file is derived from the file funzip.c written  * and put in the public domain by Mark Adler.  */
end_comment

begin_comment
comment|/*    This version can extract files in gzip or pkzip format.    For the latter, only the first entry is extracted, and it has to be    either deflated or stored.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RCSID
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_include
include|#
directive|include
file|"gzip.h"
end_include

begin_include
include|#
directive|include
file|"crypt.h"
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

begin_comment
comment|/* Globals */
end_comment

begin_decl_stmt
name|int
name|decrypt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag to turn on decryption */
end_comment

begin_decl_stmt
name|char
modifier|*
name|key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* not used--needed to link crypt.c */
end_comment

begin_decl_stmt
name|int
name|pkzip
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set for a pkzip file */
end_comment

begin_decl_stmt
name|int
name|ext_header
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if extended local header */
end_comment

begin_comment
comment|/* ===========================================================================  * Check zip file and advance inptr to the start of the compressed data.  * Get ofname from the local header if necessary.  */
end_comment

begin_function
name|int
name|check_zipfile
parameter_list|(
name|in
parameter_list|)
name|int
name|in
decl_stmt|;
comment|/* input file descriptors */
block|{
name|uch
modifier|*
name|h
init|=
name|inbuf
operator|+
name|inptr
decl_stmt|;
comment|/* first local header */
name|ifd
operator|=
name|in
expr_stmt|;
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
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n%s: %s: not a valid zip file\n"
argument_list|,
name|progname
argument_list|,
name|ifname
argument_list|)
expr_stmt|;
name|exit_code
operator|=
name|ERROR
expr_stmt|;
return|return
name|ERROR
return|;
block|}
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
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n%s: %s: first entry not deflated or stored -- use unzip\n"
argument_list|,
name|progname
argument_list|,
name|ifname
argument_list|)
expr_stmt|;
name|exit_code
operator|=
name|ERROR
expr_stmt|;
return|return
name|ERROR
return|;
block|}
comment|/* If entry encrypted, decrypt and validate encryption header */
if|if
condition|(
operator|(
name|decrypt
operator|=
name|h
index|[
name|LOCFLG
index|]
operator|&
name|CRPFLG
operator|)
operator|!=
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n%s: %s: encrypted file -- use unzip\n"
argument_list|,
name|progname
argument_list|,
name|ifname
argument_list|)
expr_stmt|;
name|exit_code
operator|=
name|ERROR
expr_stmt|;
return|return
name|ERROR
return|;
block|}
comment|/* Save flags for unzip() */
name|ext_header
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
comment|/* Get ofname and time stamp from local header (to be done) */
return|return
name|OK
return|;
block|}
end_function

begin_comment
comment|/* ===========================================================================  * Unzip in to out.  This routine works on both gzip and pkzip files.  *  * IN assertions: the buffer inbuf contains already the beginning of  *   the compressed data, from offsets inptr to insize-1 included.  *   The magic header has already been checked. The output buffer is cleared.  */
end_comment

begin_function
name|int
name|unzip
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|)
name|int
name|in
decl_stmt|,
name|out
decl_stmt|;
comment|/* input and output file descriptors */
block|{
name|ulg
name|orig_crc
init|=
literal|0
decl_stmt|;
comment|/* original crc */
name|ulg
name|orig_len
init|=
literal|0
decl_stmt|;
comment|/* original uncompressed length */
name|int
name|n
decl_stmt|;
name|uch
name|buf
index|[
name|EXTHDR
index|]
decl_stmt|;
comment|/* extended local header */
name|ifd
operator|=
name|in
expr_stmt|;
name|ofd
operator|=
name|out
expr_stmt|;
name|updcrc
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* initialize crc */
if|if
condition|(
name|pkzip
operator|&&
operator|!
name|ext_header
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
comment|/* Decompress */
if|if
condition|(
name|method
operator|==
name|DEFLATED
condition|)
block|{
name|int
name|res
init|=
name|inflate
argument_list|()
decl_stmt|;
if|if
condition|(
name|res
operator|==
literal|3
condition|)
block|{
name|error
argument_list|(
literal|"out of memory"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|res
operator|!=
literal|0
condition|)
block|{
name|error
argument_list|(
literal|"invalid compressed data--format violated"
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|pkzip
operator|&&
name|method
operator|==
name|STORED
condition|)
block|{
specifier|register
name|ulg
name|n
init|=
name|LG
argument_list|(
name|inbuf
operator|+
name|LOCLEN
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|!=
name|LG
argument_list|(
name|inbuf
operator|+
name|LOCSIZ
argument_list|)
operator|-
operator|(
name|decrypt
condition|?
name|RAND_HEAD_LEN
else|:
literal|0
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"len %ld, siz %ld\n"
argument_list|,
name|n
argument_list|,
name|LG
argument_list|(
name|inbuf
operator|+
name|LOCSIZ
argument_list|)
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|"invalid compressed data--length mismatch"
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|n
operator|--
condition|)
block|{
name|uch
name|c
init|=
operator|(
name|uch
operator|)
name|get_byte
argument_list|()
decl_stmt|;
ifdef|#
directive|ifdef
name|CRYPT
if|if
condition|(
name|decrypt
condition|)
name|zdecode
argument_list|(
name|c
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|put_ubyte
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
name|flush_window
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|error
argument_list|(
literal|"internal error, invalid method"
argument_list|)
expr_stmt|;
block|}
comment|/* Get the crc and original length */
if|if
condition|(
operator|!
name|pkzip
condition|)
block|{
comment|/* crc32  (see algorithm.doc) 	 * uncompressed input size modulo 2^32          */
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
block|{
name|buf
index|[
name|n
index|]
operator|=
operator|(
name|uch
operator|)
name|get_byte
argument_list|()
expr_stmt|;
comment|/* may cause an error if EOF */
block|}
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
name|ext_header
condition|)
block|{
comment|/* If extended header, check it */
comment|/* signature - 4bytes: 0x50 0x4b 0x07 0x08 	 * CRC-32 value          * compressed size 4-bytes          * uncompressed size 4-bytes 	 */
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
block|{
name|buf
index|[
name|n
index|]
operator|=
operator|(
name|uch
operator|)
name|get_byte
argument_list|()
expr_stmt|;
comment|/* may cause an error if EOF */
block|}
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
name|updcrc
argument_list|(
name|outbuf
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"invalid compressed data--crc error"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|orig_len
operator|!=
operator|(
name|ulg
operator|)
name|bytes_out
condition|)
block|{
name|error
argument_list|(
literal|"invalid compressed data--length error"
argument_list|)
expr_stmt|;
block|}
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
block|{
if|if
condition|(
name|to_stdout
condition|)
block|{
name|WARN
argument_list|(
operator|(
name|stderr
operator|,
literal|"%s: %s has more than one entry--rest ignored\n"
operator|,
name|progname
operator|,
name|ifname
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Don't destroy the input zip file */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s has more than one entry -- unchanged\n"
argument_list|,
name|progname
argument_list|,
name|ifname
argument_list|)
expr_stmt|;
name|exit_code
operator|=
name|ERROR
expr_stmt|;
name|ext_header
operator|=
name|pkzip
operator|=
literal|0
expr_stmt|;
return|return
name|ERROR
return|;
block|}
block|}
name|ext_header
operator|=
name|pkzip
operator|=
literal|0
expr_stmt|;
comment|/* for next file */
return|return
name|OK
return|;
block|}
end_function

end_unit

