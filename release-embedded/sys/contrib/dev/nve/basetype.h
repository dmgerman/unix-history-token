begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************\ |*                                                                           *| |*       Copyright 2001-2004 NVIDIA Corporation.  All Rights Reserved.       *| |*                                                                           *| |*     THE INFORMATION CONTAINED HEREIN  IS PROPRIETARY AND CONFIDENTIAL     *| |*     TO NVIDIA, CORPORATION.   USE,  REPRODUCTION OR DISCLOSURE TO ANY     *| |*     THIRD PARTY IS SUBJECT TO WRITTEN PRE-APPROVAL BY NVIDIA, CORP.       *| |*                                                                           *| |*     THE INFORMATION CONTAINED HEREIN IS PROVIDED  "AS IS" WITHOUT         *| |*     EXPRESS OR IMPLIED WARRANTY OF ANY KIND, INCLUDING ALL IMPLIED        *| |*     WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A     *| |*     PARTICULAR PURPOSE.                                                   *| |*                                                                           *| \***************************************************************************/
end_comment

begin_comment
comment|/*++  File:  	basetype.h   Abstract:  	This file contains the base type definitions used by the networking driver.   Revision History:  	SNo.	Date		Author				Description 	1.	2/7/2000	AJha				Created	  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BASETYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BASETYPE_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IN
end_ifndef

begin_define
define|#
directive|define
name|IN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OUT
end_ifndef

begin_define
define|#
directive|define
name|OUT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// Useful "types"
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|//
end_comment

begin_comment
comment|// Don't use as these are going to be deleted soon. Use NV_ instead
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|PVOID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UCHAR
modifier|*
name|PUCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|USHORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|USHORT
modifier|*
name|PUSHORT
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ULONG
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
name|ULONG
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|ULONG
modifier|*
name|PULONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|CHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|SHORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|LONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
modifier|*
name|PUINT
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NV_VOID
value|void
end_define

begin_typedef
typedef|typedef
name|NV_VOID
modifier|*
name|PNV_VOID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|NV_BOOLEAN
typedef|,
modifier|*
name|PNV_BOOLEAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|NV_UINT8
typedef|,
modifier|*
name|PNV_UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|NV_UINT16
typedef|,
modifier|*
name|PNV_UINT16
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|NV_UINT32
typedef|,
modifier|*
name|PNV_UINT32
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
name|NV_UINT32
typedef|,
modifier|*
name|PNV_UINT32
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|signed
name|char
name|NV_SINT8
typedef|,
modifier|*
name|PNV_SINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|NV_SINT16
typedef|,
modifier|*
name|PNV_SINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|NV_SINT32
typedef|,
modifier|*
name|PNV_SINT32
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|NV_UINT64
typedef|,
modifier|*
name|PNV_UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|long
name|NV_SINT64
typedef|,
modifier|*
name|PNV_SINT64
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1200
end_if

begin_comment
comment|// MSVC 6.0 onwards
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|NV_UINT64
typedef|,
modifier|*
name|PNV_UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|__int64
name|NV_SINT64
typedef|,
modifier|*
name|PNV_SINT64
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
name|NV_UINT64
typedef|,
modifier|*
name|PNV_UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|NV_SINT64
typedef|,
modifier|*
name|PNV_SINT64
typedef|;
end_typedef

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
name|_AMD64_
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|NV_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|NV_INT
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
name|linux
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|NV_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|long
name|NV_INT
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|NV_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|__int64
name|NV_INT
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// Floating point definitions
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|float
name|NV_REAL32
typedef|;
end_typedef

begin_comment
comment|// 4-byte floating point
end_comment

begin_typedef
typedef|typedef
name|double
name|NV_REAL64
typedef|;
end_typedef

begin_comment
comment|// 8-byte floating point
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit defintions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NV_BIT
parameter_list|(
name|bitpos
parameter_list|)
value|(1<< (bitpos))
end_define

begin_comment
comment|// NV_BIT_SET
end_comment

begin_comment
comment|// Sets the specified bit position (0..31).
end_comment

begin_comment
comment|// Parameter bits can be 1 byte to 4 bytes, but the caller needs to make sure bitpos fits into it.
end_comment

begin_comment
comment|// x = 0xA0
end_comment

begin_comment
comment|// NV_BIT_SET(x, 1)
end_comment

begin_comment
comment|// Result: x = 0xA2
end_comment

begin_define
define|#
directive|define
name|NV_BIT_SET
parameter_list|(
name|bits
parameter_list|,
name|bitpos
parameter_list|)
value|((bits) |= (NV_BIT(bitpos)))
end_define

begin_comment
comment|// NV_BIT_CLEAR
end_comment

begin_comment
comment|// Clears the specified bit position (0..31)
end_comment

begin_comment
comment|// Parameter bits can be 1 byte to 4 bytes, but the caller needs to make sure bitpos fits into it.
end_comment

begin_comment
comment|// x = 0xAA
end_comment

begin_comment
comment|// NV_BIT_CLEAR(x, 1)
end_comment

begin_comment
comment|// Result: x = 0xA8
end_comment

begin_define
define|#
directive|define
name|NV_BIT_CLEAR
parameter_list|(
name|bits
parameter_list|,
name|bitpos
parameter_list|)
value|((bits)&= (~NV_BIT(bitpos)))
end_define

begin_comment
comment|// NV_BIT_GET
end_comment

begin_comment
comment|// Gets the bit at the specified bit position (0..31)
end_comment

begin_comment
comment|// Parameter bits can be 1 byte to 4 bytes, but the caller needs to make sure bitpos fits into it.
end_comment

begin_comment
comment|// Result is either 1 or 0.
end_comment

begin_comment
comment|// x = 0xAA
end_comment

begin_comment
comment|// NV_BIT_GET(x, 1)
end_comment

begin_comment
comment|// Result: x = 1
end_comment

begin_define
define|#
directive|define
name|NV_BIT_GET
parameter_list|(
name|bits
parameter_list|,
name|bitpos
parameter_list|)
value|(((bits)>> (bitpos))& 0x0001)
end_define

begin_comment
comment|// NV_BIT_GETVALUE
end_comment

begin_comment
comment|// Gets the value from a 32 bit ULONG at specified bit position.
end_comment

begin_comment
comment|// Parameter bits needs to be 4 bytes long.
end_comment

begin_comment
comment|// Ex. ul32 = 0xFEDCBA98
end_comment

begin_comment
comment|// ulVal = NV_BIT_GETVALUE(ul32, 3, 0)  : Gets value from Bit position 3 to 0
end_comment

begin_comment
comment|// Result : ulVal = 8
end_comment

begin_define
define|#
directive|define
name|NV_BIT_GETVALUE
parameter_list|(
name|ulOrigValue
parameter_list|,
name|bitposHi
parameter_list|,
name|bitposLow
parameter_list|)
value|(((ulOrigValue)>> (bitposLow))& (~(0xFFFFFFFF<< ((bitposHi) - (bitposLow) +1))))
end_define

begin_comment
comment|// NV_BIT_SETVALUE
end_comment

begin_comment
comment|// Set a value in a 32 bit ULONG at a specific bit position.
end_comment

begin_comment
comment|// Parameter bits needs to be 4 bytes long.
end_comment

begin_comment
comment|// Ex. ul32 = 0xFEDCBA98
end_comment

begin_comment
comment|// NV_BIT_SETVALUE(ul32, 0xF, 3, 0)  : Sets value at Bit position 3 to 0
end_comment

begin_comment
comment|// Result : ul32 becomes 0xFEDCBA9F
end_comment

begin_define
define|#
directive|define
name|NV_BIT_SETVALUE
parameter_list|(
name|ulOrigValue
parameter_list|,
name|ulWindowValue
parameter_list|,
name|bitposHi
parameter_list|,
name|bitposLow
parameter_list|)
define|\
value|((ulOrigValue) = ((((ulOrigValue)& (~ ((0xFFFFFFFF>> (31 - (bitposHi)))& (0xFFFFFFFF<< (bitposLow))))) | ((ulWindowValue)<< (bitposLow)))))
end_define

begin_define
define|#
directive|define
name|NV_BYTE
parameter_list|(
name|ulus
parameter_list|,
name|bytepos
parameter_list|)
value|((ulus>> (8 * (bytepos)))& 0xFF)
end_define

begin_define
define|#
directive|define
name|SWAP_U16
parameter_list|(
name|us
parameter_list|)
value|((((us)& 0x00FF)<< 8) | \                       (((us)& 0xFF00)>> 8))
end_define

begin_define
define|#
directive|define
name|SWAP_U32
parameter_list|(
name|ul
parameter_list|)
value|((((ul)& 0x000000FF)<< 24) |   \                         (((ul)& 0x0000FF00)<<  8) |	  \                         (((ul)& 0x00FF0000)>>  8) |	  \                         (((ul)& 0xFF000000)>> 24))
end_define

begin_define
define|#
directive|define
name|NV_FIELD_OFFSET
parameter_list|(
name|TYPE
parameter_list|,
name|FIELD
parameter_list|)
value|((NV_UINT32)((NV_UINT64)&((TYPE *)0)->FIELD))
end_define

begin_define
define|#
directive|define
name|ADDRESS_OFFSET
parameter_list|(
name|structure
parameter_list|,
name|member
parameter_list|)
value|((NV_UINT32) ((NV_UINT8 *)&(structure).member  \                                                             - (NV_UINT8 *)&(structure)))
end_define

begin_define
define|#
directive|define
name|NV_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a< b) ? a : b)
end_define

begin_define
define|#
directive|define
name|NV_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a> b) ? a : b)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AMD64
end_ifdef

begin_define
define|#
directive|define
name|PNV_VOID_TO_NV_UINT64
parameter_list|(
name|x
parameter_list|)
value|((NV_UINT64)(x))
end_define

begin_define
define|#
directive|define
name|PNV_VOID_TO_NV_UINT32
parameter_list|(
name|x
parameter_list|)
value|((NV_UINT32)(NV_UINT64)(x))
end_define

begin_define
define|#
directive|define
name|NV_UINT64_TO_PNV_VOID
parameter_list|(
name|x
parameter_list|)
value|((PNV_VOID)(x))
end_define

begin_define
define|#
directive|define
name|NV_UINT32_TO_PNV_VOID
parameter_list|(
name|x
parameter_list|)
value|((PNV_VOID)(NV_UINT64)(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PNV_VOID_TO_NV_UINT64
parameter_list|(
name|x
parameter_list|)
value|((NV_UINT64)(NV_UINT32)(x))
end_define

begin_define
define|#
directive|define
name|PNV_VOID_TO_NV_UINT32
parameter_list|(
name|x
parameter_list|)
value|((NV_UINT32)(x))
end_define

begin_define
define|#
directive|define
name|NV_UINT64_TO_PNV_VOID
parameter_list|(
name|x
parameter_list|)
value|((PNV_VOID)(NV_UINT32)(x))
end_define

begin_define
define|#
directive|define
name|NV_UINT32_TO_PNV_VOID
parameter_list|(
name|x
parameter_list|)
value|((PNV_VOID)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NV_MAKE_TAG32
parameter_list|(
name|s
parameter_list|)
value|(((NV_UINT32)((s)[3])<< 24) | ((NV_UINT32)((s)[2])<< 16) | \                                      ((NV_UINT32)((s)[1])<<  8) | ((NV_UINT32)((s)[0])))
end_define

begin_define
define|#
directive|define
name|NV_MAKE_TAG64
parameter_list|(
name|s
parameter_list|)
value|(((NV_UINT64)((s)[7])<< 56) | ((NV_UINT64)((s)[6])<< 48) | \                                      ((NV_UINT64)((s)[5])<< 40) | ((NV_UINT64)((s)[4])<< 32) | \                                      ((NV_UINT64)((s)[3])<< 24) | ((NV_UINT64)((s)[2])<< 16) | \                                      ((NV_UINT64)((s)[1])<<  8) | ((NV_UINT64)((s)[0])))
end_define

begin_typedef
typedef|typedef
union|union
name|_NVLARGE_INTEGER
block|{
if|#
directive|if
literal|0
comment|// NO UNNAMED UNIONS ALLOWED !@
block|struct {         NV_UINT32   LowPart;         NV_SINT32   HighPart;     };
endif|#
directive|endif
struct|struct
block|{
name|NV_UINT32
name|LowPart
decl_stmt|;
name|NV_SINT32
name|HighPart
decl_stmt|;
block|}
name|u
struct|;
name|NV_SINT64
name|QuadPart
decl_stmt|;
block|}
name|NVLARGE_INTEGER
operator|,
typedef|*
name|PNVLARGE_INTEGER
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|NV_WCHAR
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
name|NV_WCHAR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|NV_WCHAR
modifier|*
name|PNV_WSTR
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NV_API_CALL
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|NV_API_CALL
value|__attribute__ ((regparm(0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NV_API_CALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NV_API_CALL
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
comment|// _BASETYPE_H_
end_comment

end_unit

