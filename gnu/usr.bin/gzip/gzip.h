begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gzip.h -- common declarations for all gzip modules  * Copyright (C) 1992-1993 Jean-loup Gailly.  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|PROTO
argument_list|)
end_if

begin_define
define|#
directive|define
name|OF
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OF
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|voidp
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|voidp
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I don't like nested includes, but the string and io functions are used  * too often  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_STRING_H
argument_list|)
operator|||
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_MEMORY_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset ((voidp)(s), 0, (n))
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|bcopy((s), (d), (n))
end_define

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|bcmp((s1), (s2), (n))
end_define

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|bzero((s), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RETSIGTYPE
end_ifndef

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|local
value|static
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uch
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ush
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ulg
typedef|;
end_typedef

begin_comment
comment|/* Return codes from gzip */
end_comment

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_define
define|#
directive|define
name|WARNING
value|2
end_define

begin_comment
comment|/* Compression methods (see algorithm.doc) */
end_comment

begin_define
define|#
directive|define
name|STORED
value|0
end_define

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
name|LZHED
value|3
end_define

begin_comment
comment|/* methods 4 to 7 reserved */
end_comment

begin_define
define|#
directive|define
name|DEFLATED
value|8
end_define

begin_define
define|#
directive|define
name|MAX_METHODS
value|9
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

begin_comment
comment|/* To save memory for 16 bit systems, some arrays are overlaid between  * the various modules:  * deflate:  prev+head   window      d_buf  l_buf  outbuf  * unlzw:    tab_prefix  tab_suffix  stack  inbuf  outbuf  * inflate:              window             inbuf  * unpack:               window             inbuf  prefix_len  * unlzh:    left+right  window      c_table inbuf c_len  * For compression, input is done in window[]. For decompression, output  * is done in window except for unlzw.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INBUFSIZ
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL_MEM
end_ifdef

begin_define
define|#
directive|define
name|INBUFSIZ
value|0x2000
end_define

begin_comment
comment|/* input buffer size */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INBUFSIZ
value|0x8000
end_define

begin_comment
comment|/* input buffer size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INBUF_EXTRA
value|64
end_define

begin_comment
comment|/* required by unlzw() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OUTBUFSIZ
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL_MEM
end_ifdef

begin_define
define|#
directive|define
name|OUTBUFSIZ
value|8192
end_define

begin_comment
comment|/* output buffer size */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OUTBUFSIZ
value|16384
end_define

begin_comment
comment|/* output buffer size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OUTBUF_EXTRA
value|2048
end_define

begin_comment
comment|/* required by unlzw() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIST_BUFSIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL_MEM
end_ifdef

begin_define
define|#
directive|define
name|DIST_BUFSIZE
value|0x2000
end_define

begin_comment
comment|/* buffer for distances, see trees.c */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIST_BUFSIZE
value|0x8000
end_define

begin_comment
comment|/* buffer for distances, see trees.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DYN_ALLOC
end_ifdef

begin_define
define|#
directive|define
name|EXTERN
parameter_list|(
name|type
parameter_list|,
name|array
parameter_list|)
value|extern type * near array
end_define

begin_define
define|#
directive|define
name|DECLARE
parameter_list|(
name|type
parameter_list|,
name|array
parameter_list|,
name|size
parameter_list|)
value|type * near array
end_define

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|type
parameter_list|,
name|array
parameter_list|,
name|size
parameter_list|)
value|{ \       array = (type*)fcalloc((size_t)(((size)+1L)/2), 2*sizeof(type)); \       if (array == NULL) error("insufficient memory"); \    }
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|array
parameter_list|)
value|{if (array != NULL) fcfree(array), array=NULL;}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
parameter_list|(
name|type
parameter_list|,
name|array
parameter_list|)
value|extern type array[]
end_define

begin_define
define|#
directive|define
name|DECLARE
parameter_list|(
name|type
parameter_list|,
name|array
parameter_list|,
name|size
parameter_list|)
value|type array[size]
end_define

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|type
parameter_list|,
name|array
parameter_list|,
name|size
parameter_list|)
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|array
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|EXTERN
argument_list|(
name|uch
argument_list|,
name|inbuf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* input buffer */
end_comment

begin_expr_stmt
name|EXTERN
argument_list|(
name|uch
argument_list|,
name|outbuf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* output buffer */
end_comment

begin_expr_stmt
name|EXTERN
argument_list|(
name|ush
argument_list|,
name|d_buf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* buffer for distances, see trees.c */
end_comment

begin_expr_stmt
name|EXTERN
argument_list|(
name|uch
argument_list|,
name|window
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Sliding window and suffix table (unlzw) */
end_comment

begin_define
define|#
directive|define
name|tab_suffix
value|window
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXSEG_64K
end_ifndef

begin_define
define|#
directive|define
name|tab_prefix
value|prev
end_define

begin_comment
comment|/* hash link (see deflate.c) */
end_comment

begin_define
define|#
directive|define
name|head
value|(prev+WSIZE)
end_define

begin_comment
comment|/* hash head (see deflate.c) */
end_comment

begin_expr_stmt
name|EXTERN
argument_list|(
name|ush
argument_list|,
name|tab_prefix
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* prefix code (see unlzw.c) */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|tab_prefix0
value|prev
end_define

begin_define
define|#
directive|define
name|head
value|tab_prefix1
end_define

begin_expr_stmt
name|EXTERN
argument_list|(
name|ush
argument_list|,
name|tab_prefix0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* prefix for even codes */
end_comment

begin_expr_stmt
name|EXTERN
argument_list|(
name|ush
argument_list|,
name|tab_prefix1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* prefix for odd  codes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|long
name|bytes_in
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of input bytes */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|bytes_out
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of output bytes */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|header_bytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes in gzip header */
end_comment

begin_define
define|#
directive|define
name|isize
value|bytes_in
end_define

begin_comment
comment|/* for compatibility with old zip sources (to be cleaned) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ifd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ofd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ifname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file name or "stdin" */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ofname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file name or "stdout" */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|time_stamp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* original time stamp (modification time) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|ifile_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file size, -1 for devices (debug only) */
end_comment

begin_typedef
typedef|typedef
name|int
name|file_t
typedef|;
end_typedef

begin_comment
comment|/* Do not use stdio */
end_comment

begin_define
define|#
directive|define
name|NO_FILE
value|(-1)
end_define

begin_comment
comment|/* in memory compression */
end_comment

begin_define
define|#
directive|define
name|PACK_MAGIC
value|"\037\036"
end_define

begin_comment
comment|/* Magic header for packed files */
end_comment

begin_define
define|#
directive|define
name|GZIP_MAGIC
value|"\037\213"
end_define

begin_comment
comment|/* Magic header for gzip files, 1F 8B */
end_comment

begin_define
define|#
directive|define
name|OLD_GZIP_MAGIC
value|"\037\236"
end_define

begin_comment
comment|/* Magic header for gzip 0.5 = freeze 1.x */
end_comment

begin_define
define|#
directive|define
name|LZH_MAGIC
value|"\037\240"
end_define

begin_comment
comment|/* Magic header for SCO LZH Compress files*/
end_comment

begin_define
define|#
directive|define
name|PKZIP_MAGIC
value|"\120\113\003\004"
end_define

begin_comment
comment|/* Magic header for pkzip files */
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
comment|/* bit 0 set: file probably ascii text */
end_comment

begin_define
define|#
directive|define
name|CONTINUATION
value|0x02
end_define

begin_comment
comment|/* bit 1 set: continuation of multi-part gzip file */
end_comment

begin_define
define|#
directive|define
name|EXTRA_FIELD
value|0x04
end_define

begin_comment
comment|/* bit 2 set: extra field present */
end_comment

begin_define
define|#
directive|define
name|ORIG_NAME
value|0x08
end_define

begin_comment
comment|/* bit 3 set: original file name present */
end_comment

begin_define
define|#
directive|define
name|COMMENT
value|0x10
end_define

begin_comment
comment|/* bit 4 set: file comment present */
end_comment

begin_define
define|#
directive|define
name|ENCRYPTED
value|0x20
end_define

begin_comment
comment|/* bit 5 set: file is encrypted */
end_comment

begin_define
define|#
directive|define
name|RESERVED
value|0xC0
end_define

begin_comment
comment|/* bit 6,7:   reserved */
end_comment

begin_comment
comment|/* internal file attribute */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN
value|0xffff
end_define

begin_define
define|#
directive|define
name|BINARY
value|0
end_define

begin_define
define|#
directive|define
name|ASCII
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WSIZE
end_ifndef

begin_define
define|#
directive|define
name|WSIZE
value|0x8000
end_define

begin_comment
comment|/* window size--must be a power of two, and */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  at least 32K for zip's deflate method */
end_comment

begin_define
define|#
directive|define
name|MIN_MATCH
value|3
end_define

begin_define
define|#
directive|define
name|MAX_MATCH
value|258
end_define

begin_comment
comment|/* The minimum and maximum match lengths */
end_comment

begin_define
define|#
directive|define
name|MIN_LOOKAHEAD
value|(MAX_MATCH+MIN_MATCH+1)
end_define

begin_comment
comment|/* Minimum amount of lookahead, except at the end of the input file.  * See deflate.c for comments about the MIN_MATCH+1.  */
end_comment

begin_define
define|#
directive|define
name|MAX_DIST
value|(WSIZE-MIN_LOOKAHEAD)
end_define

begin_comment
comment|/* In order to simplify the code, particularly on 16 bit machines, match  * distances are limited to MAX_DIST instead of WSIZE.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|decrypt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag to turn on decryption */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|exit_code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program exit code */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* be verbose (-v) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|quiet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* be quiet (-q) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* compression level */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check .z file integrity */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|to_stdout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output to stdout (-c) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|save_orig_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if original name must be saved */
end_comment

begin_define
define|#
directive|define
name|get_byte
parameter_list|()
value|(inptr< insize ? inbuf[inptr++] : fill_inbuf(0))
end_define

begin_define
define|#
directive|define
name|try_byte
parameter_list|()
value|(inptr< insize ? inbuf[inptr++] : fill_inbuf(1))
end_define

begin_comment
comment|/* put_byte is used for the compressed output, put_ubyte for the  * uncompressed output. However unlzw() uses window for its  * suffix table instead of its output buffer, so it does not use put_ubyte  * (to be cleaned up).  */
end_comment

begin_define
define|#
directive|define
name|put_byte
parameter_list|(
name|c
parameter_list|)
value|{outbuf[outcnt++]=(uch)(c); if (outcnt==OUTBUFSIZ)\    flush_outbuf();}
end_define

begin_define
define|#
directive|define
name|put_ubyte
parameter_list|(
name|c
parameter_list|)
value|{window[outcnt++]=(uch)(c); if (outcnt==WSIZE)\    flush_window();}
end_define

begin_comment
comment|/* Output a 16 bit value, lsb first */
end_comment

begin_define
define|#
directive|define
name|put_short
parameter_list|(
name|w
parameter_list|)
define|\
value|{ if (outcnt< OUTBUFSIZ-2) { \     outbuf[outcnt++] = (uch) ((w)& 0xff); \     outbuf[outcnt++] = (uch) ((ush)(w)>> 8); \   } else { \     put_byte((uch)((w)& 0xff)); \     put_byte((uch)((ush)(w)>> 8)); \   } \ }
end_define

begin_comment
comment|/* Output a 32 bit value to the bit stream, lsb first */
end_comment

begin_define
define|#
directive|define
name|put_long
parameter_list|(
name|n
parameter_list|)
value|{ \     put_short((n)& 0xffff); \     put_short(((ulg)(n))>> 16); \ }
end_define

begin_define
define|#
directive|define
name|seekable
parameter_list|()
value|0
end_define

begin_comment
comment|/* force sequential output */
end_comment

begin_define
define|#
directive|define
name|translate_eol
value|0
end_define

begin_comment
comment|/* no option -a yet */
end_comment

begin_define
define|#
directive|define
name|tolow
parameter_list|(
name|c
parameter_list|)
value|(isupper(c) ? (c)-'A'+'a' : (c))
end_define

begin_comment
comment|/* force to lower case */
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
value|((ush)(uch)((p)[0]) | ((ush)(uch)((p)[1])<< 8))
end_define

begin_define
define|#
directive|define
name|LG
parameter_list|(
name|p
parameter_list|)
value|((ulg)(SH(p)) | ((ulg)(SH((p)+2))<< 16))
end_define

begin_comment
comment|/* Diagnostic functions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|Assert
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
value|{if(!(cond)) error(msg);}
end_define

begin_define
define|#
directive|define
name|Trace
parameter_list|(
name|x
parameter_list|)
value|fprintf x
end_define

begin_define
define|#
directive|define
name|Tracev
parameter_list|(
name|x
parameter_list|)
value|{if (verbose) fprintf x ;}
end_define

begin_define
define|#
directive|define
name|Tracevv
parameter_list|(
name|x
parameter_list|)
value|{if (verbose>1) fprintf x ;}
end_define

begin_define
define|#
directive|define
name|Tracec
parameter_list|(
name|c
parameter_list|,
name|x
parameter_list|)
value|{if (verbose&& (c)) fprintf x ;}
end_define

begin_define
define|#
directive|define
name|Tracecv
parameter_list|(
name|c
parameter_list|,
name|x
parameter_list|)
value|{if (verbose>1&& (c)) fprintf x ;}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Assert
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Trace
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Tracev
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Tracevv
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Tracec
parameter_list|(
name|c
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Tracecv
parameter_list|(
name|c
parameter_list|,
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WARN
parameter_list|(
name|msg
parameter_list|)
value|{if (!quiet) fprintf msg ; \ 		   if (exit_code == OK) exit_code = WARNING;}
end_define

begin_comment
comment|/* in zip.c: */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|zip
name|OF
argument_list|(
operator|(
name|int
name|in
operator|,
name|int
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|file_read
name|OF
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|unsigned
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in unzip.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unzip
name|OF
argument_list|(
operator|(
name|int
name|in
operator|,
name|int
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check_zipfile
name|OF
argument_list|(
operator|(
name|int
name|in
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in unpack.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unpack
name|OF
argument_list|(
operator|(
name|int
name|in
operator|,
name|int
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in unlzh.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unlzh
name|OF
argument_list|(
operator|(
name|int
name|in
operator|,
name|int
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in gzip.c */
end_comment

begin_decl_stmt
name|RETSIGTYPE
name|abort_gzip
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in deflate.c */
end_comment

begin_decl_stmt
name|void
name|lm_init
name|OF
argument_list|(
operator|(
name|int
name|pack_level
operator|,
name|ush
operator|*
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ulg
name|deflate
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in trees.c */
end_comment

begin_decl_stmt
name|void
name|ct_init
name|OF
argument_list|(
operator|(
name|ush
operator|*
name|attr
operator|,
name|int
operator|*
name|method
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ct_tally
name|OF
argument_list|(
operator|(
name|int
name|dist
operator|,
name|int
name|lc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ulg
name|flush_block
name|OF
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|ulg
name|stored_len
operator|,
name|int
name|eof
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in bits.c */
end_comment

begin_decl_stmt
name|void
name|bi_init
name|OF
argument_list|(
operator|(
name|file_t
name|zipfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|send_bits
name|OF
argument_list|(
operator|(
name|int
name|value
operator|,
name|int
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|bi_reverse
name|OF
argument_list|(
operator|(
name|unsigned
name|value
operator|,
name|int
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bi_windup
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|copy_block
name|OF
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|unsigned
name|len
operator|,
name|int
name|header
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern   int (*read_buf
end_extern

begin_expr_stmt
unit|)
name|OF
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|unsigned
name|size
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* in util.c: */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|copy
name|OF
argument_list|(
operator|(
name|int
name|in
operator|,
name|int
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ulg
name|updcrc
name|OF
argument_list|(
operator|(
name|uch
operator|*
name|s
operator|,
name|unsigned
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_bufs
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fill_inbuf
name|OF
argument_list|(
operator|(
name|int
name|eof_ok
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flush_outbuf
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flush_window
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_buf
name|OF
argument_list|(
operator|(
name|int
name|fd
operator|,
name|voidp
name|buf
operator|,
name|unsigned
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strlwr
name|OF
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|basename
name|OF
argument_list|(
operator|(
name|char
operator|*
name|fname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|make_simple_name
name|OF
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|add_envopt
name|OF
argument_list|(
operator|(
name|int
operator|*
name|argcp
operator|,
name|char
operator|*
operator|*
operator|*
name|argvp
operator|,
name|char
operator|*
name|env
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|error
name|OF
argument_list|(
operator|(
name|char
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|warn
name|OF
argument_list|(
operator|(
name|char
operator|*
name|a
operator|,
name|char
operator|*
name|b
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|read_error
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_error
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|display_ratio
name|OF
argument_list|(
operator|(
name|long
name|num
operator|,
name|long
name|den
operator|,
name|FILE
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|voidp
name|xmalloc
name|OF
argument_list|(
operator|(
name|unsigned
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in inflate.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inflate
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

