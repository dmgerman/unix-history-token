begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* zconf.h -- configuration of the zlib compression library  * Copyright (C) 1995-2002 Jean-loup Gailly.  * For conditions of distribution and use, see copyright notice in zlib.h   */
end_comment

begin_comment
comment|/* @(#) $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZCONF_H
end_ifndef

begin_define
define|#
directive|define
name|_ZCONF_H
end_define

begin_comment
comment|/*  * If you *really* need a unique prefix for all types and library functions,  * compile with -DZ_PREFIX. The "standard" zlib should be compiled without it.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|Z_PREFIX
end_ifdef

begin_define
define|#
directive|define
name|deflateInit_
value|z_deflateInit_
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
name|deflateEnd
value|z_deflateEnd
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
name|inflate
value|z_inflate
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
name|deflateInit2_
value|z_deflateInit2_
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
name|deflateCopy
value|z_deflateCopy
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
name|deflateParams
value|z_deflateParams
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
name|inflateSetDictionary
value|z_inflateSetDictionary
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
name|inflateReset
value|z_inflateReset
end_define

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
name|uncompress
value|z_uncompress
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
name|crc32
value|z_crc32
end_define

begin_define
define|#
directive|define
name|get_crc_table
value|z_get_crc_table
end_define

begin_define
define|#
directive|define
name|Byte
value|z_Byte
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
name|uLong
value|z_uLong
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
name|charf
value|z_charf
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
name|uIntf
value|z_uIntf
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
name|voidpf
value|z_voidpf
end_define

begin_define
define|#
directive|define
name|voidp
value|z_voidp
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
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__WIN32__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|WIN32
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
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__386__
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__32BIT__
end_ifndef

begin_define
define|#
directive|define
name|__32BIT__
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

begin_comment
comment|/*  * Compile with -DMAXSEG_64K if the alloc function cannot allocate more  * than 64k bytes at a time (needed on systems with 16-bit int).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__32BIT__
argument_list|)
end_if

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
name|_WINDOWS
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|STDC
argument_list|)
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
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__OS2__
argument_list|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Old Borland C incorrectly complains about missing returns: */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|&&
operator|(
name|__BORLANDC__
operator|<
literal|0x500
operator|)
end_if

begin_define
define|#
directive|define
name|NEED_DUMMY_RETURN
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

begin_comment
comment|/* The following definitions for FAR are needed only for MSDOS mixed  * model programming (small or medium model with some far allocations).  * This was tested only with MSC; for other MSDOS compilers you may have  * to define NO_MEMCPY in zutil.h.  If you don't need the mixed model,  * just define FAR to be empty.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|M_I86SM
argument_list|)
operator|||
name|defined
argument_list|(
name|M_I86MM
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__32BIT__
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
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|&&
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

begin_ifndef
ifndef|#
directive|ifndef
name|__32BIT__
end_ifndef

begin_define
define|#
directive|define
name|SMALL_MEDIUM
end_define

begin_define
define|#
directive|define
name|FAR
value|_far
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
comment|/* Compile with -DZLIB_DLL for Windows DLL support */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ZLIB_DLL
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WINDOWS
argument_list|)
operator|||
name|defined
argument_list|(
name|WINDOWS
argument_list|)
end_if

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
value|FAR _cdecl _export
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
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|__BORLANDC__
operator|>=
literal|0x0500
operator|)
operator|&&
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_define
define|#
directive|define
name|ZEXPORT
value|__declspec(dllexport) WINAPI
end_define

begin_define
define|#
directive|define
name|ZEXPORTRVA
value|__declspec(dllexport) WINAPIV
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
name|_Windows
argument_list|)
operator|&&
name|defined
argument_list|(
name|__DLL__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ZEXPORT
value|_export
end_define

begin_define
define|#
directive|define
name|ZEXPORTVA
value|_export
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ZLIB_DLL
argument_list|)
end_if

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
name|MACOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_OS_MAC
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* for off_t */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* for SEEK_* and off_t */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

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
name|inflate_blocks
name|,
literal|"INBL"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_blocks_new
name|,
literal|"INBLNE"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_blocks_free
name|,
literal|"INBLFR"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_blocks_reset
name|,
literal|"INBLRE"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_codes_free
name|,
literal|"INCOFR"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_codes
name|,
literal|"INCO"
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
name|inflate_flush
name|,
literal|"INFLU"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_mask
name|,
literal|"INMA"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_set_dictionary
name|,
literal|"INSEDI2"
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

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_trees_bits
name|,
literal|"INTRBI"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_trees_dynamic
name|,
literal|"INTRDY"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_trees_fixed
name|,
literal|"INTRFI"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|inflate_trees_free
name|,
literal|"INTRFR"
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
comment|/* _ZCONF_H */
end_comment

end_unit

