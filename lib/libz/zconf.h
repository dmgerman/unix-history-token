begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* zconf.h -- configuration of the zlib compression library  * Copyright (C) 1995-2013 Jean-loup Gailly.  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment

begin_comment
comment|/* @(#) $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZCONF_H
end_ifndef

begin_define
define|#
directive|define
name|ZCONF_H
end_define

begin_comment
comment|/*  * If you *really* need a unique prefix for all types and library functions,  * compile with -DZ_PREFIX. The "standard" zlib should be compiled without it.  * Even better than compiling with -DZ_PREFIX would be to use configure to set  * this permanently in zconf.h using "./configure --zprefix".  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|Z_PREFIX
end_ifdef

begin_comment
comment|/* may be set to #if 1 by ./configure */
end_comment

begin_define
define|#
directive|define
name|Z_PREFIX_SET
end_define

begin_comment
comment|/* all linked symbols */
end_comment

begin_define
define|#
directive|define
name|_dist_code
value|z__dist_code
end_define

begin_define
define|#
directive|define
name|_length_code
value|z__length_code
end_define

begin_define
define|#
directive|define
name|_tr_align
value|z__tr_align
end_define

begin_define
define|#
directive|define
name|_tr_flush_bits
value|z__tr_flush_bits
end_define

begin_define
define|#
directive|define
name|_tr_flush_block
value|z__tr_flush_block
end_define

begin_define
define|#
directive|define
name|_tr_init
value|z__tr_init
end_define

begin_define
define|#
directive|define
name|_tr_stored_block
value|z__tr_stored_block
end_define

begin_define
define|#
directive|define
name|_tr_tally
value|z__tr_tally
end_define

begin_define
define|#
directive|define
name|adler32
value|z_adler32
end_define

begin_define
define|#
directive|define
name|adler32_combine
value|z_adler32_combine
end_define

begin_define
define|#
directive|define
name|adler32_combine64
value|z_adler32_combine64
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|Z_SOLO
end_ifndef

begin_define
define|#
directive|define
name|compress
value|z_compress
end_define

begin_define
define|#
directive|define
name|compress2
value|z_compress2
end_define

begin_define
define|#
directive|define
name|compressBound
value|z_compressBound
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|crc32
value|z_crc32
end_define

begin_define
define|#
directive|define
name|crc32_combine
value|z_crc32_combine
end_define

begin_define
define|#
directive|define
name|crc32_combine64
value|z_crc32_combine64
end_define

begin_define
define|#
directive|define
name|deflate
value|z_deflate
end_define

begin_define
define|#
directive|define
name|deflateBound
value|z_deflateBound
end_define

begin_define
define|#
directive|define
name|deflateCopy
value|z_deflateCopy
end_define

begin_define
define|#
directive|define
name|deflateEnd
value|z_deflateEnd
end_define

begin_define
define|#
directive|define
name|deflateInit2_
value|z_deflateInit2_
end_define

begin_define
define|#
directive|define
name|deflateInit_
value|z_deflateInit_
end_define

begin_define
define|#
directive|define
name|deflateParams
value|z_deflateParams
end_define

begin_define
define|#
directive|define
name|deflatePending
value|z_deflatePending
end_define

begin_define
define|#
directive|define
name|deflatePrime
value|z_deflatePrime
end_define

begin_define
define|#
directive|define
name|deflateReset
value|z_deflateReset
end_define

begin_define
define|#
directive|define
name|deflateResetKeep
value|z_deflateResetKeep
end_define

begin_define
define|#
directive|define
name|deflateSetDictionary
value|z_deflateSetDictionary
end_define

begin_define
define|#
directive|define
name|deflateSetHeader
value|z_deflateSetHeader
end_define

begin_define
define|#
directive|define
name|deflateTune
value|z_deflateTune
end_define

begin_define
define|#
directive|define
name|deflate_copyright
value|z_deflate_copyright
end_define

begin_define
define|#
directive|define
name|get_crc_table
value|z_get_crc_table
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|Z_SOLO
end_ifndef

begin_define
define|#
directive|define
name|gz_error
value|z_gz_error
end_define

begin_define
define|#
directive|define
name|gz_intmax
value|z_gz_intmax
end_define

begin_define
define|#
directive|define
name|gz_strwinerror
value|z_gz_strwinerror
end_define

begin_define
define|#
directive|define
name|gzbuffer
value|z_gzbuffer
end_define

begin_define
define|#
directive|define
name|gzclearerr
value|z_gzclearerr
end_define

begin_define
define|#
directive|define
name|gzclose
value|z_gzclose
end_define

begin_define
define|#
directive|define
name|gzclose_r
value|z_gzclose_r
end_define

begin_define
define|#
directive|define
name|gzclose_w
value|z_gzclose_w
end_define

begin_define
define|#
directive|define
name|gzdirect
value|z_gzdirect
end_define

begin_define
define|#
directive|define
name|gzdopen
value|z_gzdopen
end_define

begin_define
define|#
directive|define
name|gzeof
value|z_gzeof
end_define

begin_define
define|#
directive|define
name|gzerror
value|z_gzerror
end_define

begin_define
define|#
directive|define
name|gzflush
value|z_gzflush
end_define

begin_define
define|#
directive|define
name|gzgetc
value|z_gzgetc
end_define

begin_define
define|#
directive|define
name|gzgetc_
value|z_gzgetc_
end_define

begin_define
define|#
directive|define
name|gzgets
value|z_gzgets
end_define

begin_define
define|#
directive|define
name|gzoffset
value|z_gzoffset
end_define

begin_define
define|#
directive|define
name|gzoffset64
value|z_gzoffset64
end_define

begin_define
define|#
directive|define
name|gzopen
value|z_gzopen
end_define

begin_define
define|#
directive|define
name|gzopen64
value|z_gzopen64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|gzopen_w
value|z_gzopen_w
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gzprintf
value|z_gzprintf
end_define

begin_define
define|#
directive|define
name|gzvprintf
value|z_gzvprintf
end_define

begin_define
define|#
directive|define
name|gzputc
value|z_gzputc
end_define

begin_define
define|#
directive|define
name|gzputs
value|z_gzputs
end_define

begin_define
define|#
directive|define
name|gzread
value|z_gzread
end_define

begin_define
define|#
directive|define
name|gzrewind
value|z_gzrewind
end_define

begin_define
define|#
directive|define
name|gzseek
value|z_gzseek
end_define

begin_define
define|#
directive|define
name|gzseek64
value|z_gzseek64
end_define

begin_define
define|#
directive|define
name|gzsetparams
value|z_gzsetparams
end_define

begin_define
define|#
directive|define
name|gztell
value|z_gztell
end_define

begin_define
define|#
directive|define
name|gztell64
value|z_gztell64
end_define

begin_define
define|#
directive|define
name|gzungetc
value|z_gzungetc
end_define

begin_define
define|#
directive|define
name|gzwrite
value|z_gzwrite
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|inflate
value|z_inflate
end_define

begin_define
define|#
directive|define
name|inflateBack
value|z_inflateBack
end_define

begin_define
define|#
directive|define
name|inflateBackEnd
value|z_inflateBackEnd
end_define

begin_define
define|#
directive|define
name|inflateBackInit_
value|z_inflateBackInit_
end_define

begin_define
define|#
directive|define
name|inflateCopy
value|z_inflateCopy
end_define

begin_define
define|#
directive|define
name|inflateEnd
value|z_inflateEnd
end_define

begin_define
define|#
directive|define
name|inflateGetHeader
value|z_inflateGetHeader
end_define

begin_define
define|#
directive|define
name|inflateInit2_
value|z_inflateInit2_
end_define

begin_define
define|#
directive|define
name|inflateInit_
value|z_inflateInit_
end_define

begin_define
define|#
directive|define
name|inflateMark
value|z_inflateMark
end_define

begin_define
define|#
directive|define
name|inflatePrime
value|z_inflatePrime
end_define

begin_define
define|#
directive|define
name|inflateReset
value|z_inflateReset
end_define

begin_define
define|#
directive|define
name|inflateReset2
value|z_inflateReset2
end_define

begin_define
define|#
directive|define
name|inflateSetDictionary
value|z_inflateSetDictionary
end_define

begin_define
define|#
directive|define
name|inflateGetDictionary
value|z_inflateGetDictionary
end_define

begin_define
define|#
directive|define
name|inflateSync
value|z_inflateSync
end_define

begin_define
define|#
directive|define
name|inflateSyncPoint
value|z_inflateSyncPoint
end_define

begin_define
define|#
directive|define
name|inflateUndermine
value|z_inflateUndermine
end_define

begin_define
define|#
directive|define
name|inflateResetKeep
value|z_inflateResetKeep
end_define

begin_define
define|#
directive|define
name|inflate_copyright
value|z_inflate_copyright
end_define

begin_define
define|#
directive|define
name|inflate_fast
value|z_inflate_fast
end_define

begin_define
define|#
directive|define
name|inflate_table
value|z_inflate_table
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|Z_SOLO
end_ifndef

begin_define
define|#
directive|define
name|uncompress
value|z_uncompress
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|zError
value|z_zError
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|Z_SOLO
end_ifndef

begin_define
define|#
directive|define
name|zcalloc
value|z_zcalloc
end_define

begin_define
define|#
directive|define
name|zcfree
value|z_zcfree
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|zlibCompileFlags
value|z_zlibCompileFlags
end_define

begin_define
define|#
directive|define
name|zlibVersion
value|z_zlibVersion
end_define

begin_comment
comment|/* all zlib typedefs in zlib.h and zconf.h */
end_comment

begin_define
define|#
directive|define
name|Byte
value|z_Byte
end_define

begin_define
define|#
directive|define
name|Bytef
value|z_Bytef
end_define

begin_define
define|#
directive|define
name|alloc_func
value|z_alloc_func
end_define

begin_define
define|#
directive|define
name|charf
value|z_charf
end_define

begin_define
define|#
directive|define
name|free_func
value|z_free_func
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|Z_SOLO
end_ifndef

begin_define
define|#
directive|define
name|gzFile
value|z_gzFile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gz_header
value|z_gz_header
end_define

begin_define
define|#
directive|define
name|gz_headerp
value|z_gz_headerp
end_define

begin_define
define|#
directive|define
name|in_func
value|z_in_func
end_define

begin_define
define|#
directive|define
name|intf
value|z_intf
end_define

begin_define
define|#
directive|define
name|out_func
value|z_out_func
end_define

begin_define
define|#
directive|define
name|uInt
value|z_uInt
end_define

begin_define
define|#
directive|define
name|uIntf
value|z_uIntf
end_define

begin_define
define|#
directive|define
name|uLong
value|z_uLong
end_define

begin_define
define|#
directive|define
name|uLongf
value|z_uLongf
end_define

begin_define
define|#
directive|define
name|voidp
value|z_voidp
end_define

begin_define
define|#
directive|define
name|voidpc
value|z_voidpc
end_define

begin_define
define|#
directive|define
name|voidpf
value|z_voidpf
end_define

begin_comment
comment|/* all zlib structs in zlib.h and zconf.h */
end_comment

begin_define
define|#
directive|define
name|gz_header_s
value|z_gz_header_s
end_define

begin_define
define|#
directive|define
name|internal_state
value|z_internal_state
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|MSDOS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|OS_2
argument_list|)
operator|||
name|defined
argument_list|(
name|__OS2__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|OS2
argument_list|)
end_if

begin_define
define|#
directive|define
name|OS2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WINDOWS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WINDOWS
argument_list|)
end_if

begin_define
define|#
directive|define
name|WINDOWS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32_WCE
argument_list|)
operator|||
name|defined
argument_list|(
name|__WIN32__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32
end_ifndef

begin_define
define|#
directive|define
name|WIN32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|OS2
argument_list|)
operator|||
name|defined
argument_list|(
name|WINDOWS
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FLAT__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__386__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|SYS16BIT
end_ifndef

begin_define
define|#
directive|define
name|SYS16BIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Compile with -DMAXSEG_64K if the alloc function cannot allocate more  * than 64k bytes at a time (needed on systems with 16-bit int).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS16BIT
end_ifdef

begin_define
define|#
directive|define
name|MAXSEG_64K
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_define
define|#
directive|define
name|UNALIGNED_OK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC_VERSION__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|STDC
end_ifndef

begin_define
define|#
directive|define
name|STDC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|199901L
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|STDC99
end_ifndef

begin_define
define|#
directive|define
name|STDC99
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|STDC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|STDC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|WINDOWS
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|STDC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|OS2
argument_list|)
operator|||
name|defined
argument_list|(
name|__HOS_AIX__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|STDC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OS400__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STDC
argument_list|)
end_if

begin_comment
comment|/* iSeries (formerly AS/400). */
end_comment

begin_define
define|#
directive|define
name|STDC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDC
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|const
end_ifndef

begin_comment
comment|/* cannot use !defined(STDC)&& !defined(const) on Mac */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* note: need a more gentle solution here */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ZLIB_CONST
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|z_const
argument_list|)
end_if

begin_define
define|#
directive|define
name|z_const
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|z_const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some Mac compilers merge all .h files incorrectly: */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|||
name|defined
argument_list|(
name|applec
argument_list|)
operator|||
name|defined
argument_list|(
name|THINK_C
argument_list|)
operator|||
name|defined
argument_list|(
name|__SC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_DUMMY_DECL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Maximum value for memLevel in deflateInit2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_MEM_LEVEL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXSEG_64K
end_ifdef

begin_define
define|#
directive|define
name|MAX_MEM_LEVEL
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAX_MEM_LEVEL
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Maximum value for windowBits in deflateInit2 and inflateInit2.  * WARNING: reducing MAX_WBITS makes minigzip unable to extract .gz files  * created by gzip. (Files created by minigzip can still be extracted by  * gzip.)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_WBITS
end_ifndef

begin_define
define|#
directive|define
name|MAX_WBITS
value|15
end_define

begin_comment
comment|/* 32K LZ77 window */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The memory requirements for deflate are (in bytes):             (1<< (windowBits+2)) +  (1<< (memLevel+9))  that is: 128K for windowBits=15  +  128K for memLevel = 8  (default values)  plus a few kilobytes for small objects. For example, if you want to reduce  the default memory requirements from 256K to 128K, compile with      make CFLAGS="-O -DMAX_WBITS=14 -DMAX_MEM_LEVEL=7"  Of course this will generally degrade compression (there's no free lunch).     The memory requirements for inflate are (in bytes) 1<< windowBits  that is, 32K for windowBits=15 (default value) plus a few kilobytes  for small objects. */
end_comment

begin_comment
comment|/* Type declarations */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OF
end_ifndef

begin_comment
comment|/* function prototypes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STDC
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Z_ARG
end_ifndef

begin_comment
comment|/* function prototypes for stdarg */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDC
argument_list|)
operator|||
name|defined
argument_list|(
name|Z_HAVE_STDARG_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|Z_ARG
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
name|Z_ARG
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following definitions for FAR are needed only for MSDOS mixed  * model programming (small or medium model with some far allocations).  * This was tested only with MSC; for other MSDOS compilers you may have  * to define NO_MEMCPY in zutil.h.  If you don't need the mixed model,  * just define FAR to be empty.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS16BIT
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|M_I86SM
argument_list|)
operator|||
name|defined
argument_list|(
name|M_I86MM
argument_list|)
end_if

begin_comment
comment|/* MSC small or medium model */
end_comment

begin_define
define|#
directive|define
name|SMALL_MEDIUM
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|FAR
value|_far
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FAR
value|far
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__SMALL__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MEDIUM__
argument_list|)
operator|)
end_if

begin_comment
comment|/* Turbo C small or medium model */
end_comment

begin_define
define|#
directive|define
name|SMALL_MEDIUM
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__BORLANDC__
end_ifdef

begin_define
define|#
directive|define
name|FAR
value|_far
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FAR
value|far
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WINDOWS
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_comment
comment|/* If building or using zlib as a DLL, define ZLIB_DLL.     * This is not mandatory, but it offers a little performance increase.     */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ZLIB_DLL
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|||
operator|(
name|__BORLANDC__
operator|>=
literal|0x500
operator|)
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|ZLIB_INTERNAL
end_ifdef

begin_define
define|#
directive|define
name|ZEXTERN
value|extern __declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ZEXTERN
value|extern __declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZLIB_DLL */
end_comment

begin_comment
comment|/* If building or using zlib with the WINAPI/WINAPIV calling convention,     * define ZLIB_WINAPI.     * Caution: the standard ZLIB1.DLL is NOT compiled using ZLIB_WINAPI.     */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ZLIB_WINAPI
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|FAR
end_ifdef

begin_undef
undef|#
directive|undef
name|FAR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|/* No need for _export, use ZLIB.DEF instead. */
end_comment

begin_comment
comment|/* For complete Windows compatibility, use WINAPI, not __stdcall. */
end_comment

begin_define
define|#
directive|define
name|ZEXPORT
value|WINAPI
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|ZEXPORTVA
value|WINAPIV
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ZEXPORTVA
value|FAR CDECL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BEOS__
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|ZLIB_DLL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ZLIB_INTERNAL
end_ifdef

begin_define
define|#
directive|define
name|ZEXPORT
value|__declspec(dllexport)
end_define

begin_define
define|#
directive|define
name|ZEXPORTVA
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ZEXPORT
value|__declspec(dllimport)
end_define

begin_define
define|#
directive|define
name|ZEXPORTVA
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ZEXTERN
end_ifndef

begin_define
define|#
directive|define
name|ZEXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ZEXPORT
end_ifndef

begin_define
define|#
directive|define
name|ZEXPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ZEXPORTVA
end_ifndef

begin_define
define|#
directive|define
name|ZEXPORTVA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FAR
end_ifndef

begin_define
define|#
directive|define
name|FAR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MACTYPES__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Byte
typedef|;
end_typedef

begin_comment
comment|/* 8 bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uInt
typedef|;
end_typedef

begin_comment
comment|/* 16 bits or more */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uLong
typedef|;
end_typedef

begin_comment
comment|/* 32 bits or more */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL_MEDIUM
end_ifdef

begin_comment
comment|/* Borland C/C++ and some old MSC versions ignore FAR inside typedef */
end_comment

begin_define
define|#
directive|define
name|Bytef
value|Byte FAR
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|Byte
name|FAR
name|Bytef
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
name|FAR
name|charf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|FAR
name|intf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uInt
name|FAR
name|uIntf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uLong
name|FAR
name|uLongf
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|STDC
end_ifdef

begin_typedef
typedef|typedef
name|void
specifier|const
modifier|*
name|voidpc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|FAR
modifier|*
name|voidpf
typedef|;
end_typedef

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
name|Byte
specifier|const
modifier|*
name|voidpc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Byte
name|FAR
modifier|*
name|voidpf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Byte
modifier|*
name|voidp
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Z_U4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Z_SOLO
argument_list|)
operator|&&
name|defined
argument_list|(
name|STDC
argument_list|)
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_if
if|#
directive|if
operator|(
name|UINT_MAX
operator|==
literal|0xffffffffUL
operator|)
end_if

begin_define
define|#
directive|define
name|Z_U4
value|unsigned
end_define

begin_elif
elif|#
directive|elif
operator|(
name|ULONG_MAX
operator|==
literal|0xffffffffUL
operator|)
end_elif

begin_define
define|#
directive|define
name|Z_U4
value|unsigned long
end_define

begin_elif
elif|#
directive|elif
operator|(
name|USHRT_MAX
operator|==
literal|0xffffffffUL
operator|)
end_elif

begin_define
define|#
directive|define
name|Z_U4
value|unsigned short
end_define

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
name|Z_U4
end_ifdef

begin_typedef
typedef|typedef
name|Z_U4
name|z_crc_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|z_crc_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* was set to #if 0 by ./configure */
end_comment

begin_define
define|#
directive|define
name|Z_HAVE_UNISTD_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDARG_H
end_ifdef

begin_comment
comment|/* may be set to #if 1 by ./configure */
end_comment

begin_define
define|#
directive|define
name|Z_HAVE_STDARG_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|Z_SOLO
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* for off_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDC
argument_list|)
operator|||
name|defined
argument_list|(
name|Z_HAVE_STDARG_H
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|Z_SOLO
end_ifndef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/* for va_list */
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
name|_WIN32
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|Z_SOLO
end_ifndef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* for wchar_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* a little trick to accommodate both "#define _LARGEFILE64_SOURCE" and  * "#define _LARGEFILE64_SOURCE 1" as requesting 64-bit operations, (even  * though the former does not conform to the LFS document), but considering  * both "#undef _LARGEFILE64_SOURCE" and "#define _LARGEFILE64_SOURCE 0" as  * equivalently requesting no 64-bit operations  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LARGEFILE64_SOURCE
argument_list|)
operator|&&
operator|-
name|_LARGEFILE64_SOURCE
operator|-
operator|-
literal|1
operator|==
literal|1
end_if

begin_undef
undef|#
directive|undef
name|_LARGEFILE64_SOURCE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__WATCOMC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Z_HAVE_UNISTD_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|Z_HAVE_UNISTD_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Z_SOLO
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|Z_HAVE_UNISTD_H
argument_list|)
operator|||
name|defined
argument_list|(
name|_LARGEFILE64_SOURCE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* for SEEK_*, off_t, and _LFS64_LARGEFILE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_include
include|#
directive|include
file|<unixio.h>
end_include

begin_comment
comment|/* for off_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|z_off_t
end_ifndef

begin_define
define|#
directive|define
name|z_off_t
value|off_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LFS64_LARGEFILE
argument_list|)
operator|&&
name|_LFS64_LARGEFILE
operator|-
literal|0
end_if

begin_define
define|#
directive|define
name|Z_LFS64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LARGEFILE64_SOURCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|Z_LFS64
argument_list|)
end_if

begin_define
define|#
directive|define
name|Z_LARGE64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_FILE_OFFSET_BITS
argument_list|)
operator|&&
name|_FILE_OFFSET_BITS
operator|-
literal|0
operator|==
literal|64
operator|&&
name|defined
argument_list|(
name|Z_LFS64
argument_list|)
end_if

begin_define
define|#
directive|define
name|Z_WANT64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SEEK_SET
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Z_SOLO
argument_list|)
end_if

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* Seek from beginning of file.  */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_comment
comment|/* Seek from current position.  */
end_comment

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_comment
comment|/* Set file pointer to EOF plus "offset" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is hard-configured for FreeBSD.  */
end_comment

begin_define
define|#
directive|define
name|z_off_t
value|off_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_FILE_OFFSET_BITS
end_ifndef

begin_define
define|#
directive|define
name|_FILE_OFFSET_BITS
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|z_off_t
end_ifndef

begin_define
define|#
directive|define
name|z_off_t
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
name|defined
argument_list|(
name|Z_LARGE64
argument_list|)
end_if

begin_define
define|#
directive|define
name|z_off64_t
value|off64_t
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Z_SOLO
argument_list|)
end_if

begin_define
define|#
directive|define
name|z_off64_t
value|__int64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|z_off64_t
value|z_off_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MVS linker does not support external names larger than 8 bytes */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MVS__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|deflateInit_
name|,
literal|"DEIN"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|deflateInit2_
name|,
literal|"DEIN2"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|deflateEnd
name|,
literal|"DEEND"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|deflateBound
name|,
literal|"DEBND"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflateInit_
name|,
literal|"ININ"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflateInit2_
name|,
literal|"ININ2"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflateEnd
name|,
literal|"INEND"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflateSync
name|,
literal|"INSY"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflateSetDictionary
name|,
literal|"INSEDI"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|compressBound
name|,
literal|"CMBND"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_table
name|,
literal|"INTABL"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_fast
name|,
literal|"INFA"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_copyright
name|,
literal|"INCOPY"
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZCONF_H */
end_comment

end_unit

