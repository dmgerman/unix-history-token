begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Ppmd.h -- PPMD codec common code 2010-03-12 : Igor Pavlov : Public domain This code is based on PPMd var.H (2001): Dmitry Shkarin : Public domain */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_BUILD
end_ifndef

begin_error
error|#
directive|error
error|This header is only to be used internally to libarchive.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_PPMD_PRIVATE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_PPMD_PRIVATE_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"archive_read_private.h"
end_include

begin_comment
comment|/*** Begin defined in Types.h ***/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ZCONF_H
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Byte
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|_LZMA_UINT32_IS_ULONG
end_ifdef

begin_typedef
typedef|typedef
name|long
name|Int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|UInt32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_SZ_NO_INT_64
end_ifdef

begin_comment
comment|/* define _SZ_NO_INT_64, if your compiler doesn't support 64-bit integers.    NOTES: Some code will work incorrectly in that case! */
end_comment

begin_typedef
typedef|typedef
name|long
name|Int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|UInt64
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|__int64
name|Int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|UInt64
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UINT64_CONST
parameter_list|(
name|n
parameter_list|)
value|n
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|long
name|int
name|Int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|int
name|UInt64
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UINT64_CONST
parameter_list|(
name|n
parameter_list|)
value|n ## ULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|Bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|True
value|1
end_define

begin_define
define|#
directive|define
name|False
value|0
end_define

begin_comment
comment|/* The following interfaces use first parameter as pointer to structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|archive_read
modifier|*
name|a
decl_stmt|;
name|Byte
function_decl|(
modifier|*
name|Read
function_decl|)
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/* reads one byte, returns 0 in case of EOF or error */
block|}
name|IByteIn
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|archive_write
modifier|*
name|a
decl_stmt|;
name|void
function_decl|(
modifier|*
name|Write
function_decl|)
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|Byte
name|b
parameter_list|)
function_decl|;
block|}
name|IByteOut
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
function_decl|(
modifier|*
name|Alloc
function_decl|)
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|Free
function_decl|)
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|void
modifier|*
name|address
parameter_list|)
function_decl|;
comment|/* address can be 0 */
block|}
name|ISzAlloc
typedef|;
end_typedef

begin_comment
comment|/*** End defined in Types.h ***/
end_comment

begin_comment
comment|/*** Begin defined in CpuArch.h ***/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MY_CPU_X86
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
name|MY_CPU_X86
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_ARM
argument_list|)
end_if

begin_define
define|#
directive|define
name|MY_CPU_32BIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MY_CPU_32BIT
end_ifdef

begin_define
define|#
directive|define
name|PPMD_32BIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*** End defined in CpuArch.h ***/
end_comment

begin_define
define|#
directive|define
name|PPMD_INT_BITS
value|7
end_define

begin_define
define|#
directive|define
name|PPMD_PERIOD_BITS
value|7
end_define

begin_define
define|#
directive|define
name|PPMD_BIN_SCALE
value|(1<< (PPMD_INT_BITS + PPMD_PERIOD_BITS))
end_define

begin_define
define|#
directive|define
name|PPMD_GET_MEAN_SPEC
parameter_list|(
name|summ
parameter_list|,
name|shift
parameter_list|,
name|round
parameter_list|)
value|(((summ) + (1<< ((shift) - (round))))>> (shift))
end_define

begin_define
define|#
directive|define
name|PPMD_GET_MEAN
parameter_list|(
name|summ
parameter_list|)
value|PPMD_GET_MEAN_SPEC((summ), PPMD_PERIOD_BITS, 2)
end_define

begin_define
define|#
directive|define
name|PPMD_UPDATE_PROB_0
parameter_list|(
name|prob
parameter_list|)
value|((prob) + (1<< PPMD_INT_BITS) - PPMD_GET_MEAN(prob))
end_define

begin_define
define|#
directive|define
name|PPMD_UPDATE_PROB_1
parameter_list|(
name|prob
parameter_list|)
value|((prob) - PPMD_GET_MEAN(prob))
end_define

begin_define
define|#
directive|define
name|PPMD_N1
value|4
end_define

begin_define
define|#
directive|define
name|PPMD_N2
value|4
end_define

begin_define
define|#
directive|define
name|PPMD_N3
value|4
end_define

begin_define
define|#
directive|define
name|PPMD_N4
value|((128 + 3 - 1 * PPMD_N1 - 2 * PPMD_N2 - 3 * PPMD_N3) / 4)
end_define

begin_define
define|#
directive|define
name|PPMD_NUM_INDEXES
value|(PPMD_N1 + PPMD_N2 + PPMD_N3 + PPMD_N4)
end_define

begin_comment
comment|/* SEE-contexts for PPM-contexts with masked symbols */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UInt16
name|Summ
decl_stmt|;
comment|/* Freq */
name|Byte
name|Shift
decl_stmt|;
comment|/* Speed of Freq change; low Shift is for fast change */
name|Byte
name|Count
decl_stmt|;
comment|/* Count to next change of Shift */
block|}
name|CPpmd_See
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Ppmd_See_Update
parameter_list|(
name|p
parameter_list|)
value|if ((p)->Shift< PPMD_PERIOD_BITS&& --(p)->Count == 0) \     { (p)->Summ<<= 1; (p)->Count = (Byte)(3<< (p)->Shift++); }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Byte
name|Symbol
decl_stmt|;
name|Byte
name|Freq
decl_stmt|;
name|UInt16
name|SuccessorLow
decl_stmt|;
name|UInt16
name|SuccessorHigh
decl_stmt|;
block|}
name|CPpmd_State
typedef|;
end_typedef

begin_typedef
typedef|typedef
ifdef|#
directive|ifdef
name|PPMD_32BIT
name|CPpmd_State
modifier|*
else|#
directive|else
name|UInt32
endif|#
directive|endif
name|CPpmd_State_Ref
typedef|;
end_typedef

begin_typedef
typedef|typedef
ifdef|#
directive|ifdef
name|PPMD_32BIT
name|void
modifier|*
else|#
directive|else
name|UInt32
endif|#
directive|endif
name|CPpmd_Void_Ref
typedef|;
end_typedef

begin_typedef
typedef|typedef
ifdef|#
directive|ifdef
name|PPMD_32BIT
name|Byte
modifier|*
else|#
directive|else
name|UInt32
endif|#
directive|endif
name|CPpmd_Byte_Ref
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PPMD_SetAllBitsIn256Bytes
parameter_list|(
name|p
parameter_list|)
define|\
value|{ unsigned j; for (j = 0; j< 256 / sizeof(p[0]); j += 8) { \   p[j+7] = p[j+6] = p[j+5] = p[j+4] = p[j+3] = p[j+2] = p[j+1] = p[j+0] = ~(size_t)0; }}
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

