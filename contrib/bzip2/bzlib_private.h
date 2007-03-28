begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-------------------------------------------------------------*/
end_comment

begin_comment
comment|/*--- Private header file for the library.                  ---*/
end_comment

begin_comment
comment|/*---                                       bzlib_private.h ---*/
end_comment

begin_comment
comment|/*-------------------------------------------------------------*/
end_comment

begin_comment
comment|/* ------------------------------------------------------------------    This file is part of bzip2/libbzip2, a program and library for    lossless, block-sorting data compression.     bzip2/libbzip2 version 1.0.4 of 20 December 2006    Copyright (C) 1996-2006 Julian Seward<jseward@bzip.org>     Please read the WARNING, DISCLAIMER and PATENTS sections in the     README file.     This program is released under the terms of the license contained    in the file LICENSE.    ------------------------------------------------------------------ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BZLIB_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|_BZLIB_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BZ_NO_STDIO
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bzlib.h"
end_include

begin_comment
comment|/*-- General stuff. --*/
end_comment

begin_define
define|#
directive|define
name|BZ_VERSION
value|"1.0.4, 20-Dec-2006"
end_define

begin_typedef
typedef|typedef
name|char
name|Char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Bool
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UChar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UInt32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|Int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UInt16
typedef|;
end_typedef

begin_define
define|#
directive|define
name|True
value|((Bool)1)
end_define

begin_define
define|#
directive|define
name|False
value|((Bool)0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|__inline__
end_define

begin_comment
comment|/* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BZ_NO_STDIO
end_ifndef

begin_function_decl
specifier|extern
name|void
name|BZ2_bz__AssertH__fail
parameter_list|(
name|int
name|errcode
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AssertH
parameter_list|(
name|cond
parameter_list|,
name|errcode
parameter_list|)
define|\
value|{ if (!(cond)) BZ2_bz__AssertH__fail ( errcode ); }
end_define

begin_if
if|#
directive|if
name|BZ_DEBUG
end_if

begin_define
define|#
directive|define
name|AssertD
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
define|\
value|{ if (!(cond)) {       \       fprintf ( stderr,   \         "\n\nlibbzip2(debug build): internal error\n\t%s\n", msg );\       exit(1); \    }}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AssertD
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VPrintf0
parameter_list|(
name|zf
parameter_list|)
define|\
value|fprintf(stderr,zf)
end_define

begin_define
define|#
directive|define
name|VPrintf1
parameter_list|(
name|zf
parameter_list|,
name|za1
parameter_list|)
define|\
value|fprintf(stderr,zf,za1)
end_define

begin_define
define|#
directive|define
name|VPrintf2
parameter_list|(
name|zf
parameter_list|,
name|za1
parameter_list|,
name|za2
parameter_list|)
define|\
value|fprintf(stderr,zf,za1,za2)
end_define

begin_define
define|#
directive|define
name|VPrintf3
parameter_list|(
name|zf
parameter_list|,
name|za1
parameter_list|,
name|za2
parameter_list|,
name|za3
parameter_list|)
define|\
value|fprintf(stderr,zf,za1,za2,za3)
end_define

begin_define
define|#
directive|define
name|VPrintf4
parameter_list|(
name|zf
parameter_list|,
name|za1
parameter_list|,
name|za2
parameter_list|,
name|za3
parameter_list|,
name|za4
parameter_list|)
define|\
value|fprintf(stderr,zf,za1,za2,za3,za4)
end_define

begin_define
define|#
directive|define
name|VPrintf5
parameter_list|(
name|zf
parameter_list|,
name|za1
parameter_list|,
name|za2
parameter_list|,
name|za3
parameter_list|,
name|za4
parameter_list|,
name|za5
parameter_list|)
define|\
value|fprintf(stderr,zf,za1,za2,za3,za4,za5)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|bz_internal_error
parameter_list|(
name|int
name|errcode
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AssertH
parameter_list|(
name|cond
parameter_list|,
name|errcode
parameter_list|)
define|\
value|{ if (!(cond)) bz_internal_error ( errcode ); }
end_define

begin_define
define|#
directive|define
name|AssertD
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|VPrintf0
parameter_list|(
name|zf
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|VPrintf1
parameter_list|(
name|zf
parameter_list|,
name|za1
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|VPrintf2
parameter_list|(
name|zf
parameter_list|,
name|za1
parameter_list|,
name|za2
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|VPrintf3
parameter_list|(
name|zf
parameter_list|,
name|za1
parameter_list|,
name|za2
parameter_list|,
name|za3
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|VPrintf4
parameter_list|(
name|zf
parameter_list|,
name|za1
parameter_list|,
name|za2
parameter_list|,
name|za3
parameter_list|,
name|za4
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|VPrintf5
parameter_list|(
name|zf
parameter_list|,
name|za1
parameter_list|,
name|za2
parameter_list|,
name|za3
parameter_list|,
name|za4
parameter_list|,
name|za5
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BZALLOC
parameter_list|(
name|nnn
parameter_list|)
value|(strm->bzalloc)(strm->opaque,(nnn),1)
end_define

begin_define
define|#
directive|define
name|BZFREE
parameter_list|(
name|ppp
parameter_list|)
value|(strm->bzfree)(strm->opaque,(ppp))
end_define

begin_comment
comment|/*-- Header bytes. --*/
end_comment

begin_define
define|#
directive|define
name|BZ_HDR_B
value|0x42
end_define

begin_comment
comment|/* 'B' */
end_comment

begin_define
define|#
directive|define
name|BZ_HDR_Z
value|0x5a
end_define

begin_comment
comment|/* 'Z' */
end_comment

begin_define
define|#
directive|define
name|BZ_HDR_h
value|0x68
end_define

begin_comment
comment|/* 'h' */
end_comment

begin_define
define|#
directive|define
name|BZ_HDR_0
value|0x30
end_define

begin_comment
comment|/* '0' */
end_comment

begin_comment
comment|/*-- Constants for the back end. --*/
end_comment

begin_define
define|#
directive|define
name|BZ_MAX_ALPHA_SIZE
value|258
end_define

begin_define
define|#
directive|define
name|BZ_MAX_CODE_LEN
value|23
end_define

begin_define
define|#
directive|define
name|BZ_RUNA
value|0
end_define

begin_define
define|#
directive|define
name|BZ_RUNB
value|1
end_define

begin_define
define|#
directive|define
name|BZ_N_GROUPS
value|6
end_define

begin_define
define|#
directive|define
name|BZ_G_SIZE
value|50
end_define

begin_define
define|#
directive|define
name|BZ_N_ITERS
value|4
end_define

begin_define
define|#
directive|define
name|BZ_MAX_SELECTORS
value|(2 + (900000 / BZ_G_SIZE))
end_define

begin_comment
comment|/*-- Stuff for randomising repetitive blocks. --*/
end_comment

begin_decl_stmt
specifier|extern
name|Int32
name|BZ2_rNums
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BZ_RAND_DECLS
define|\
value|Int32 rNToGo;                               \    Int32 rTPos                                 \  #define BZ_RAND_INIT_MASK                      \    s->rNToGo = 0;                              \    s->rTPos  = 0                               \  #define BZ_RAND_MASK ((s->rNToGo == 1) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|BZ_RAND_UPD_MASK
define|\
value|if (s->rNToGo == 0) {                       \       s->rNToGo = BZ2_rNums[s->rTPos];         \       s->rTPos++;                              \       if (s->rTPos == 512) s->rTPos = 0;       \    }                                           \    s->rNToGo--;
end_define

begin_comment
comment|/*-- Stuff for doing CRCs. --*/
end_comment

begin_decl_stmt
specifier|extern
name|UInt32
name|BZ2_crc32Table
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BZ_INITIALISE_CRC
parameter_list|(
name|crcVar
parameter_list|)
define|\
value|{                                              \    crcVar = 0xffffffffL;                       \ }
end_define

begin_define
define|#
directive|define
name|BZ_FINALISE_CRC
parameter_list|(
name|crcVar
parameter_list|)
define|\
value|{                                              \    crcVar = ~(crcVar);                         \ }
end_define

begin_define
define|#
directive|define
name|BZ_UPDATE_CRC
parameter_list|(
name|crcVar
parameter_list|,
name|cha
parameter_list|)
define|\
value|{                                              \    crcVar = (crcVar<< 8) ^                    \             BZ2_crc32Table[(crcVar>> 24) ^    \                            ((UChar)cha)];      \ }
end_define

begin_comment
comment|/*-- States and modes for compression. --*/
end_comment

begin_define
define|#
directive|define
name|BZ_M_IDLE
value|1
end_define

begin_define
define|#
directive|define
name|BZ_M_RUNNING
value|2
end_define

begin_define
define|#
directive|define
name|BZ_M_FLUSHING
value|3
end_define

begin_define
define|#
directive|define
name|BZ_M_FINISHING
value|4
end_define

begin_define
define|#
directive|define
name|BZ_S_OUTPUT
value|1
end_define

begin_define
define|#
directive|define
name|BZ_S_INPUT
value|2
end_define

begin_define
define|#
directive|define
name|BZ_N_RADIX
value|2
end_define

begin_define
define|#
directive|define
name|BZ_N_QSORT
value|12
end_define

begin_define
define|#
directive|define
name|BZ_N_SHELL
value|18
end_define

begin_define
define|#
directive|define
name|BZ_N_OVERSHOOT
value|(BZ_N_RADIX + BZ_N_QSORT + BZ_N_SHELL + 2)
end_define

begin_comment
comment|/*-- Structure holding all the compression-side stuff. --*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* pointer back to the struct bz_stream */
name|bz_stream
modifier|*
name|strm
decl_stmt|;
comment|/* mode this stream is in, and whether inputting */
comment|/* or outputting data */
name|Int32
name|mode
decl_stmt|;
name|Int32
name|state
decl_stmt|;
comment|/* remembers avail_in when flush/finish requested */
name|UInt32
name|avail_in_expect
decl_stmt|;
comment|/* for doing the block sorting */
name|UInt32
modifier|*
name|arr1
decl_stmt|;
name|UInt32
modifier|*
name|arr2
decl_stmt|;
name|UInt32
modifier|*
name|ftab
decl_stmt|;
name|Int32
name|origPtr
decl_stmt|;
comment|/* aliases for arr1 and arr2 */
name|UInt32
modifier|*
name|ptr
decl_stmt|;
name|UChar
modifier|*
name|block
decl_stmt|;
name|UInt16
modifier|*
name|mtfv
decl_stmt|;
name|UChar
modifier|*
name|zbits
decl_stmt|;
comment|/* for deciding when to use the fallback sorting algorithm */
name|Int32
name|workFactor
decl_stmt|;
comment|/* run-length-encoding of the input */
name|UInt32
name|state_in_ch
decl_stmt|;
name|Int32
name|state_in_len
decl_stmt|;
name|BZ_RAND_DECLS
expr_stmt|;
comment|/* input and output limits and current posns */
name|Int32
name|nblock
decl_stmt|;
name|Int32
name|nblockMAX
decl_stmt|;
name|Int32
name|numZ
decl_stmt|;
name|Int32
name|state_out_pos
decl_stmt|;
comment|/* map of bytes used in block */
name|Int32
name|nInUse
decl_stmt|;
name|Bool
name|inUse
index|[
literal|256
index|]
decl_stmt|;
name|UChar
name|unseqToSeq
index|[
literal|256
index|]
decl_stmt|;
comment|/* the buffer for bit stream creation */
name|UInt32
name|bsBuff
decl_stmt|;
name|Int32
name|bsLive
decl_stmt|;
comment|/* block and combined CRCs */
name|UInt32
name|blockCRC
decl_stmt|;
name|UInt32
name|combinedCRC
decl_stmt|;
comment|/* misc administratium */
name|Int32
name|verbosity
decl_stmt|;
name|Int32
name|blockNo
decl_stmt|;
name|Int32
name|blockSize100k
decl_stmt|;
comment|/* stuff for coding the MTF values */
name|Int32
name|nMTF
decl_stmt|;
name|Int32
name|mtfFreq
index|[
name|BZ_MAX_ALPHA_SIZE
index|]
decl_stmt|;
name|UChar
name|selector
index|[
name|BZ_MAX_SELECTORS
index|]
decl_stmt|;
name|UChar
name|selectorMtf
index|[
name|BZ_MAX_SELECTORS
index|]
decl_stmt|;
name|UChar
name|len
index|[
name|BZ_N_GROUPS
index|]
index|[
name|BZ_MAX_ALPHA_SIZE
index|]
decl_stmt|;
name|Int32
name|code
index|[
name|BZ_N_GROUPS
index|]
index|[
name|BZ_MAX_ALPHA_SIZE
index|]
decl_stmt|;
name|Int32
name|rfreq
index|[
name|BZ_N_GROUPS
index|]
index|[
name|BZ_MAX_ALPHA_SIZE
index|]
decl_stmt|;
comment|/* second dimension: only 3 needed; 4 makes index calculations faster */
name|UInt32
name|len_pack
index|[
name|BZ_MAX_ALPHA_SIZE
index|]
index|[
literal|4
index|]
decl_stmt|;
block|}
name|EState
typedef|;
end_typedef

begin_comment
comment|/*-- externs for compression. --*/
end_comment

begin_function_decl
specifier|extern
name|void
name|BZ2_blockSort
parameter_list|(
name|EState
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|BZ2_compressBlock
parameter_list|(
name|EState
modifier|*
parameter_list|,
name|Bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|BZ2_bsInitWrite
parameter_list|(
name|EState
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|BZ2_hbAssignCodes
parameter_list|(
name|Int32
modifier|*
parameter_list|,
name|UChar
modifier|*
parameter_list|,
name|Int32
parameter_list|,
name|Int32
parameter_list|,
name|Int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|BZ2_hbMakeCodeLengths
parameter_list|(
name|UChar
modifier|*
parameter_list|,
name|Int32
modifier|*
parameter_list|,
name|Int32
parameter_list|,
name|Int32
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-- states for decompression. --*/
end_comment

begin_define
define|#
directive|define
name|BZ_X_IDLE
value|1
end_define

begin_define
define|#
directive|define
name|BZ_X_OUTPUT
value|2
end_define

begin_define
define|#
directive|define
name|BZ_X_MAGIC_1
value|10
end_define

begin_define
define|#
directive|define
name|BZ_X_MAGIC_2
value|11
end_define

begin_define
define|#
directive|define
name|BZ_X_MAGIC_3
value|12
end_define

begin_define
define|#
directive|define
name|BZ_X_MAGIC_4
value|13
end_define

begin_define
define|#
directive|define
name|BZ_X_BLKHDR_1
value|14
end_define

begin_define
define|#
directive|define
name|BZ_X_BLKHDR_2
value|15
end_define

begin_define
define|#
directive|define
name|BZ_X_BLKHDR_3
value|16
end_define

begin_define
define|#
directive|define
name|BZ_X_BLKHDR_4
value|17
end_define

begin_define
define|#
directive|define
name|BZ_X_BLKHDR_5
value|18
end_define

begin_define
define|#
directive|define
name|BZ_X_BLKHDR_6
value|19
end_define

begin_define
define|#
directive|define
name|BZ_X_BCRC_1
value|20
end_define

begin_define
define|#
directive|define
name|BZ_X_BCRC_2
value|21
end_define

begin_define
define|#
directive|define
name|BZ_X_BCRC_3
value|22
end_define

begin_define
define|#
directive|define
name|BZ_X_BCRC_4
value|23
end_define

begin_define
define|#
directive|define
name|BZ_X_RANDBIT
value|24
end_define

begin_define
define|#
directive|define
name|BZ_X_ORIGPTR_1
value|25
end_define

begin_define
define|#
directive|define
name|BZ_X_ORIGPTR_2
value|26
end_define

begin_define
define|#
directive|define
name|BZ_X_ORIGPTR_3
value|27
end_define

begin_define
define|#
directive|define
name|BZ_X_MAPPING_1
value|28
end_define

begin_define
define|#
directive|define
name|BZ_X_MAPPING_2
value|29
end_define

begin_define
define|#
directive|define
name|BZ_X_SELECTOR_1
value|30
end_define

begin_define
define|#
directive|define
name|BZ_X_SELECTOR_2
value|31
end_define

begin_define
define|#
directive|define
name|BZ_X_SELECTOR_3
value|32
end_define

begin_define
define|#
directive|define
name|BZ_X_CODING_1
value|33
end_define

begin_define
define|#
directive|define
name|BZ_X_CODING_2
value|34
end_define

begin_define
define|#
directive|define
name|BZ_X_CODING_3
value|35
end_define

begin_define
define|#
directive|define
name|BZ_X_MTF_1
value|36
end_define

begin_define
define|#
directive|define
name|BZ_X_MTF_2
value|37
end_define

begin_define
define|#
directive|define
name|BZ_X_MTF_3
value|38
end_define

begin_define
define|#
directive|define
name|BZ_X_MTF_4
value|39
end_define

begin_define
define|#
directive|define
name|BZ_X_MTF_5
value|40
end_define

begin_define
define|#
directive|define
name|BZ_X_MTF_6
value|41
end_define

begin_define
define|#
directive|define
name|BZ_X_ENDHDR_2
value|42
end_define

begin_define
define|#
directive|define
name|BZ_X_ENDHDR_3
value|43
end_define

begin_define
define|#
directive|define
name|BZ_X_ENDHDR_4
value|44
end_define

begin_define
define|#
directive|define
name|BZ_X_ENDHDR_5
value|45
end_define

begin_define
define|#
directive|define
name|BZ_X_ENDHDR_6
value|46
end_define

begin_define
define|#
directive|define
name|BZ_X_CCRC_1
value|47
end_define

begin_define
define|#
directive|define
name|BZ_X_CCRC_2
value|48
end_define

begin_define
define|#
directive|define
name|BZ_X_CCRC_3
value|49
end_define

begin_define
define|#
directive|define
name|BZ_X_CCRC_4
value|50
end_define

begin_comment
comment|/*-- Constants for the fast MTF decoder. --*/
end_comment

begin_define
define|#
directive|define
name|MTFA_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|MTFL_SIZE
value|16
end_define

begin_comment
comment|/*-- Structure holding all the decompression-side stuff. --*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* pointer back to the struct bz_stream */
name|bz_stream
modifier|*
name|strm
decl_stmt|;
comment|/* state indicator for this stream */
name|Int32
name|state
decl_stmt|;
comment|/* for doing the final run-length decoding */
name|UChar
name|state_out_ch
decl_stmt|;
name|Int32
name|state_out_len
decl_stmt|;
name|Bool
name|blockRandomised
decl_stmt|;
name|BZ_RAND_DECLS
expr_stmt|;
comment|/* the buffer for bit stream reading */
name|UInt32
name|bsBuff
decl_stmt|;
name|Int32
name|bsLive
decl_stmt|;
comment|/* misc administratium */
name|Int32
name|blockSize100k
decl_stmt|;
name|Bool
name|smallDecompress
decl_stmt|;
name|Int32
name|currBlockNo
decl_stmt|;
name|Int32
name|verbosity
decl_stmt|;
comment|/* for undoing the Burrows-Wheeler transform */
name|Int32
name|origPtr
decl_stmt|;
name|UInt32
name|tPos
decl_stmt|;
name|Int32
name|k0
decl_stmt|;
name|Int32
name|unzftab
index|[
literal|256
index|]
decl_stmt|;
name|Int32
name|nblock_used
decl_stmt|;
name|Int32
name|cftab
index|[
literal|257
index|]
decl_stmt|;
name|Int32
name|cftabCopy
index|[
literal|257
index|]
decl_stmt|;
comment|/* for undoing the Burrows-Wheeler transform (FAST) */
name|UInt32
modifier|*
name|tt
decl_stmt|;
comment|/* for undoing the Burrows-Wheeler transform (SMALL) */
name|UInt16
modifier|*
name|ll16
decl_stmt|;
name|UChar
modifier|*
name|ll4
decl_stmt|;
comment|/* stored and calculated CRCs */
name|UInt32
name|storedBlockCRC
decl_stmt|;
name|UInt32
name|storedCombinedCRC
decl_stmt|;
name|UInt32
name|calculatedBlockCRC
decl_stmt|;
name|UInt32
name|calculatedCombinedCRC
decl_stmt|;
comment|/* map of bytes used in block */
name|Int32
name|nInUse
decl_stmt|;
name|Bool
name|inUse
index|[
literal|256
index|]
decl_stmt|;
name|Bool
name|inUse16
index|[
literal|16
index|]
decl_stmt|;
name|UChar
name|seqToUnseq
index|[
literal|256
index|]
decl_stmt|;
comment|/* for decoding the MTF values */
name|UChar
name|mtfa
index|[
name|MTFA_SIZE
index|]
decl_stmt|;
name|Int32
name|mtfbase
index|[
literal|256
operator|/
name|MTFL_SIZE
index|]
decl_stmt|;
name|UChar
name|selector
index|[
name|BZ_MAX_SELECTORS
index|]
decl_stmt|;
name|UChar
name|selectorMtf
index|[
name|BZ_MAX_SELECTORS
index|]
decl_stmt|;
name|UChar
name|len
index|[
name|BZ_N_GROUPS
index|]
index|[
name|BZ_MAX_ALPHA_SIZE
index|]
decl_stmt|;
name|Int32
name|limit
index|[
name|BZ_N_GROUPS
index|]
index|[
name|BZ_MAX_ALPHA_SIZE
index|]
decl_stmt|;
name|Int32
name|base
index|[
name|BZ_N_GROUPS
index|]
index|[
name|BZ_MAX_ALPHA_SIZE
index|]
decl_stmt|;
name|Int32
name|perm
index|[
name|BZ_N_GROUPS
index|]
index|[
name|BZ_MAX_ALPHA_SIZE
index|]
decl_stmt|;
name|Int32
name|minLens
index|[
name|BZ_N_GROUPS
index|]
decl_stmt|;
comment|/* save area for scalars in the main decompress code */
name|Int32
name|save_i
decl_stmt|;
name|Int32
name|save_j
decl_stmt|;
name|Int32
name|save_t
decl_stmt|;
name|Int32
name|save_alphaSize
decl_stmt|;
name|Int32
name|save_nGroups
decl_stmt|;
name|Int32
name|save_nSelectors
decl_stmt|;
name|Int32
name|save_EOB
decl_stmt|;
name|Int32
name|save_groupNo
decl_stmt|;
name|Int32
name|save_groupPos
decl_stmt|;
name|Int32
name|save_nextSym
decl_stmt|;
name|Int32
name|save_nblockMAX
decl_stmt|;
name|Int32
name|save_nblock
decl_stmt|;
name|Int32
name|save_es
decl_stmt|;
name|Int32
name|save_N
decl_stmt|;
name|Int32
name|save_curr
decl_stmt|;
name|Int32
name|save_zt
decl_stmt|;
name|Int32
name|save_zn
decl_stmt|;
name|Int32
name|save_zvec
decl_stmt|;
name|Int32
name|save_zj
decl_stmt|;
name|Int32
name|save_gSel
decl_stmt|;
name|Int32
name|save_gMinlen
decl_stmt|;
name|Int32
modifier|*
name|save_gLimit
decl_stmt|;
name|Int32
modifier|*
name|save_gBase
decl_stmt|;
name|Int32
modifier|*
name|save_gPerm
decl_stmt|;
block|}
name|DState
typedef|;
end_typedef

begin_comment
comment|/*-- Macros for decompression. --*/
end_comment

begin_define
define|#
directive|define
name|BZ_GET_FAST
parameter_list|(
name|cccc
parameter_list|)
define|\
value|s->tPos = s->tt[s->tPos];                 \     cccc = (UChar)(s->tPos& 0xff);           \     s->tPos>>= 8;
end_define

begin_define
define|#
directive|define
name|BZ_GET_FAST_C
parameter_list|(
name|cccc
parameter_list|)
define|\
value|c_tPos = c_tt[c_tPos];                    \     cccc = (UChar)(c_tPos& 0xff);            \     c_tPos>>= 8;
end_define

begin_define
define|#
directive|define
name|SET_LL4
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
define|\
value|{ if (((i)& 0x1) == 0)                                    \         s->ll4[(i)>> 1] = (s->ll4[(i)>> 1]& 0xf0) | (n); else    \         s->ll4[(i)>> 1] = (s->ll4[(i)>> 1]& 0x0f) | ((n)<< 4);  \    }
end_define

begin_define
define|#
directive|define
name|GET_LL4
parameter_list|(
name|i
parameter_list|)
define|\
value|((((UInt32)(s->ll4[(i)>> 1]))>> (((i)<< 2)& 0x4))& 0xF)
end_define

begin_define
define|#
directive|define
name|SET_LL
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
define|\
value|{ s->ll16[i] = (UInt16)(n& 0x0000ffff);  \      SET_LL4(i, n>> 16);                    \    }
end_define

begin_define
define|#
directive|define
name|GET_LL
parameter_list|(
name|i
parameter_list|)
define|\
value|(((UInt32)s->ll16[i]) | (GET_LL4(i)<< 16))
end_define

begin_define
define|#
directive|define
name|BZ_GET_SMALL
parameter_list|(
name|cccc
parameter_list|)
define|\
value|cccc = BZ2_indexIntoF ( s->tPos, s->cftab );    \       s->tPos = GET_LL(s->tPos);
end_define

begin_comment
comment|/*-- externs for decompression. --*/
end_comment

begin_function_decl
specifier|extern
name|Int32
name|BZ2_indexIntoF
parameter_list|(
name|Int32
parameter_list|,
name|Int32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Int32
name|BZ2_decompress
parameter_list|(
name|DState
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|BZ2_hbCreateDecodeTables
parameter_list|(
name|Int32
modifier|*
parameter_list|,
name|Int32
modifier|*
parameter_list|,
name|Int32
modifier|*
parameter_list|,
name|UChar
modifier|*
parameter_list|,
name|Int32
parameter_list|,
name|Int32
parameter_list|,
name|Int32
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-- BZ_NO_STDIO seems to make NULL disappear on some platforms. --*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BZ_NO_STDIO
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
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
comment|/*-------------------------------------------------------------*/
end_comment

begin_comment
comment|/*--- end                                   bzlib_private.h ---*/
end_comment

begin_comment
comment|/*-------------------------------------------------------------*/
end_comment

end_unit

