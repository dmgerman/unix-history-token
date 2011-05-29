begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acmacros.h - C macros for the entire subsystem.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2011, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACMACROS_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACMACROS_H__
end_define

begin_comment
comment|/*  * Extract data using a pointer. Any more than a byte and we  * get into potential aligment issues -- see the STORE macros below.  * Use with care.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_GET8
parameter_list|(
name|ptr
parameter_list|)
value|*ACPI_CAST_PTR (UINT8, ptr)
end_define

begin_define
define|#
directive|define
name|ACPI_GET16
parameter_list|(
name|ptr
parameter_list|)
value|*ACPI_CAST_PTR (UINT16, ptr)
end_define

begin_define
define|#
directive|define
name|ACPI_GET32
parameter_list|(
name|ptr
parameter_list|)
value|*ACPI_CAST_PTR (UINT32, ptr)
end_define

begin_define
define|#
directive|define
name|ACPI_GET64
parameter_list|(
name|ptr
parameter_list|)
value|*ACPI_CAST_PTR (UINT64, ptr)
end_define

begin_define
define|#
directive|define
name|ACPI_SET8
parameter_list|(
name|ptr
parameter_list|)
value|*ACPI_CAST_PTR (UINT8, ptr)
end_define

begin_define
define|#
directive|define
name|ACPI_SET16
parameter_list|(
name|ptr
parameter_list|)
value|*ACPI_CAST_PTR (UINT16, ptr)
end_define

begin_define
define|#
directive|define
name|ACPI_SET32
parameter_list|(
name|ptr
parameter_list|)
value|*ACPI_CAST_PTR (UINT32, ptr)
end_define

begin_define
define|#
directive|define
name|ACPI_SET64
parameter_list|(
name|ptr
parameter_list|)
value|*ACPI_CAST_PTR (UINT64, ptr)
end_define

begin_comment
comment|/*  * printf() format helpers  */
end_comment

begin_comment
comment|/* Split 64-bit integer into two 32-bit values. Use with %8.8X%8.8X */
end_comment

begin_define
define|#
directive|define
name|ACPI_FORMAT_UINT64
parameter_list|(
name|i
parameter_list|)
value|ACPI_HIDWORD(i), ACPI_LODWORD(i)
end_define

begin_if
if|#
directive|if
name|ACPI_MACHINE_WIDTH
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|ACPI_FORMAT_NATIVE_UINT
parameter_list|(
name|i
parameter_list|)
value|ACPI_FORMAT_UINT64(i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_FORMAT_NATIVE_UINT
parameter_list|(
name|i
parameter_list|)
value|0, (i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros for moving data around to/from buffers that are possibly unaligned.  * If the hardware supports the transfer of unaligned data, just do the store.  * Otherwise, we have to move one byte at a time.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_BIG_ENDIAN
end_ifdef

begin_comment
comment|/*  * Macros for big-endian machines  */
end_comment

begin_comment
comment|/* These macros reverse the bytes during the move, converting little-endian to big endian */
end_comment

begin_comment
comment|/* Big Endian<==        Little Endian */
end_comment

begin_comment
comment|/*  Hi...Lo                     Lo...Hi     */
end_comment

begin_comment
comment|/* 16-bit source, 16/32/64 destination */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_16_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{((  UINT8 *)(void *)(d))[0] = ((UINT8 *)(void *)(s))[1];\                                          ((  UINT8 *)(void *)(d))[1] = ((UINT8 *)(void *)(s))[0];}
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_16_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{(*(UINT32 *)(void *)(d))=0;\                                            ((UINT8 *)(void *)(d))[2] = ((UINT8 *)(void *)(s))[1];\                                            ((UINT8 *)(void *)(d))[3] = ((UINT8 *)(void *)(s))[0];}
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_16_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{(*(UINT64 *)(void *)(d))=0;\                                            ((UINT8 *)(void *)(d))[6] = ((UINT8 *)(void *)(s))[1];\                                            ((UINT8 *)(void *)(d))[7] = ((UINT8 *)(void *)(s))[0];}
end_define

begin_comment
comment|/* 32-bit source, 16/32/64 destination */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_32_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_16_TO_16(d, s)
end_define

begin_comment
comment|/* Truncate to 16 */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_32_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{((  UINT8 *)(void *)(d))[0] = ((UINT8 *)(void *)(s))[3];\                                          ((  UINT8 *)(void *)(d))[1] = ((UINT8 *)(void *)(s))[2];\                                          ((  UINT8 *)(void *)(d))[2] = ((UINT8 *)(void *)(s))[1];\                                          ((  UINT8 *)(void *)(d))[3] = ((UINT8 *)(void *)(s))[0];}
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_32_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{(*(UINT64 *)(void *)(d))=0;\                                            ((UINT8 *)(void *)(d))[4] = ((UINT8 *)(void *)(s))[3];\                                            ((UINT8 *)(void *)(d))[5] = ((UINT8 *)(void *)(s))[2];\                                            ((UINT8 *)(void *)(d))[6] = ((UINT8 *)(void *)(s))[1];\                                            ((UINT8 *)(void *)(d))[7] = ((UINT8 *)(void *)(s))[0];}
end_define

begin_comment
comment|/* 64-bit source, 16/32/64 destination */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_64_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_16_TO_16(d, s)
end_define

begin_comment
comment|/* Truncate to 16 */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_64_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_32_TO_32(d, s)
end_define

begin_comment
comment|/* Truncate to 32 */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_64_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{((  UINT8 *)(void *)(d))[0] = ((UINT8 *)(void *)(s))[7];\                                          ((  UINT8 *)(void *)(d))[1] = ((UINT8 *)(void *)(s))[6];\                                          ((  UINT8 *)(void *)(d))[2] = ((UINT8 *)(void *)(s))[5];\                                          ((  UINT8 *)(void *)(d))[3] = ((UINT8 *)(void *)(s))[4];\                                          ((  UINT8 *)(void *)(d))[4] = ((UINT8 *)(void *)(s))[3];\                                          ((  UINT8 *)(void *)(d))[5] = ((UINT8 *)(void *)(s))[2];\                                          ((  UINT8 *)(void *)(d))[6] = ((UINT8 *)(void *)(s))[1];\                                          ((  UINT8 *)(void *)(d))[7] = ((UINT8 *)(void *)(s))[0];}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Macros for little-endian machines  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MISALIGNMENT_NOT_SUPPORTED
end_ifndef

begin_comment
comment|/* The hardware supports unaligned transfers, just do the little-endian move */
end_comment

begin_comment
comment|/* 16-bit source, 16/32/64 destination */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_16_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|*(UINT16 *)(void *)(d) = *(UINT16 *)(void *)(s)
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_16_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|*(UINT32 *)(void *)(d) = *(UINT16 *)(void *)(s)
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_16_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|*(UINT64 *)(void *)(d) = *(UINT16 *)(void *)(s)
end_define

begin_comment
comment|/* 32-bit source, 16/32/64 destination */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_32_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_16_TO_16(d, s)
end_define

begin_comment
comment|/* Truncate to 16 */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_32_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|*(UINT32 *)(void *)(d) = *(UINT32 *)(void *)(s)
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_32_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|*(UINT64 *)(void *)(d) = *(UINT32 *)(void *)(s)
end_define

begin_comment
comment|/* 64-bit source, 16/32/64 destination */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_64_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_16_TO_16(d, s)
end_define

begin_comment
comment|/* Truncate to 16 */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_64_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_32_TO_32(d, s)
end_define

begin_comment
comment|/* Truncate to 32 */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_64_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|*(UINT64 *)(void *)(d) = *(UINT64 *)(void *)(s)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * The hardware does not support unaligned transfers. We must move the  * data one byte at a time. These macros work whether the source or  * the destination (or both) is/are unaligned. (Little-endian move)  */
end_comment

begin_comment
comment|/* 16-bit source, 16/32/64 destination */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_16_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{((  UINT8 *)(void *)(d))[0] = ((UINT8 *)(void *)(s))[0];\                                          ((  UINT8 *)(void *)(d))[1] = ((UINT8 *)(void *)(s))[1];}
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_16_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{(*(UINT32 *)(void *)(d)) = 0; ACPI_MOVE_16_TO_16(d, s);}
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_16_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{(*(UINT64 *)(void *)(d)) = 0; ACPI_MOVE_16_TO_16(d, s);}
end_define

begin_comment
comment|/* 32-bit source, 16/32/64 destination */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_32_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_16_TO_16(d, s)
end_define

begin_comment
comment|/* Truncate to 16 */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_32_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{((  UINT8 *)(void *)(d))[0] = ((UINT8 *)(void *)(s))[0];\                                          ((  UINT8 *)(void *)(d))[1] = ((UINT8 *)(void *)(s))[1];\                                          ((  UINT8 *)(void *)(d))[2] = ((UINT8 *)(void *)(s))[2];\                                          ((  UINT8 *)(void *)(d))[3] = ((UINT8 *)(void *)(s))[3];}
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_32_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{(*(UINT64 *)(void *)(d)) = 0; ACPI_MOVE_32_TO_32(d, s);}
end_define

begin_comment
comment|/* 64-bit source, 16/32/64 destination */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_64_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_16_TO_16(d, s)
end_define

begin_comment
comment|/* Truncate to 16 */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_64_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_32_TO_32(d, s)
end_define

begin_comment
comment|/* Truncate to 32 */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_64_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{((  UINT8 *)(void *)(d))[0] = ((UINT8 *)(void *)(s))[0];\                                          ((  UINT8 *)(void *)(d))[1] = ((UINT8 *)(void *)(s))[1];\                                          ((  UINT8 *)(void *)(d))[2] = ((UINT8 *)(void *)(s))[2];\                                          ((  UINT8 *)(void *)(d))[3] = ((UINT8 *)(void *)(s))[3];\                                          ((  UINT8 *)(void *)(d))[4] = ((UINT8 *)(void *)(s))[4];\                                          ((  UINT8 *)(void *)(d))[5] = ((UINT8 *)(void *)(s))[5];\                                          ((  UINT8 *)(void *)(d))[6] = ((UINT8 *)(void *)(s))[6];\                                          ((  UINT8 *)(void *)(d))[7] = ((UINT8 *)(void *)(s))[7];}
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
comment|/*  * Fast power-of-two math macros for non-optimized compilers  */
end_comment

begin_define
define|#
directive|define
name|_ACPI_DIV
parameter_list|(
name|value
parameter_list|,
name|PowerOf2
parameter_list|)
value|((UINT32) ((value)>> (PowerOf2)))
end_define

begin_define
define|#
directive|define
name|_ACPI_MUL
parameter_list|(
name|value
parameter_list|,
name|PowerOf2
parameter_list|)
value|((UINT32) ((value)<< (PowerOf2)))
end_define

begin_define
define|#
directive|define
name|_ACPI_MOD
parameter_list|(
name|value
parameter_list|,
name|Divisor
parameter_list|)
value|((UINT32) ((value)& ((Divisor) -1)))
end_define

begin_define
define|#
directive|define
name|ACPI_DIV_2
parameter_list|(
name|a
parameter_list|)
value|_ACPI_DIV(a, 1)
end_define

begin_define
define|#
directive|define
name|ACPI_MUL_2
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MUL(a, 1)
end_define

begin_define
define|#
directive|define
name|ACPI_MOD_2
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MOD(a, 2)
end_define

begin_define
define|#
directive|define
name|ACPI_DIV_4
parameter_list|(
name|a
parameter_list|)
value|_ACPI_DIV(a, 2)
end_define

begin_define
define|#
directive|define
name|ACPI_MUL_4
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MUL(a, 2)
end_define

begin_define
define|#
directive|define
name|ACPI_MOD_4
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MOD(a, 4)
end_define

begin_define
define|#
directive|define
name|ACPI_DIV_8
parameter_list|(
name|a
parameter_list|)
value|_ACPI_DIV(a, 3)
end_define

begin_define
define|#
directive|define
name|ACPI_MUL_8
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MUL(a, 3)
end_define

begin_define
define|#
directive|define
name|ACPI_MOD_8
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MOD(a, 8)
end_define

begin_define
define|#
directive|define
name|ACPI_DIV_16
parameter_list|(
name|a
parameter_list|)
value|_ACPI_DIV(a, 4)
end_define

begin_define
define|#
directive|define
name|ACPI_MUL_16
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MUL(a, 4)
end_define

begin_define
define|#
directive|define
name|ACPI_MOD_16
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MOD(a, 16)
end_define

begin_define
define|#
directive|define
name|ACPI_DIV_32
parameter_list|(
name|a
parameter_list|)
value|_ACPI_DIV(a, 5)
end_define

begin_define
define|#
directive|define
name|ACPI_MUL_32
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MUL(a, 5)
end_define

begin_define
define|#
directive|define
name|ACPI_MOD_32
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MOD(a, 32)
end_define

begin_comment
comment|/*  * Rounding macros (Power of two boundaries only)  */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN
parameter_list|(
name|value
parameter_list|,
name|boundary
parameter_list|)
value|(((ACPI_SIZE)(value))& \                                                 (~(((ACPI_SIZE) boundary)-1)))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP
parameter_list|(
name|value
parameter_list|,
name|boundary
parameter_list|)
value|((((ACPI_SIZE)(value)) + \                                                 (((ACPI_SIZE) boundary)-1))& \                                                 (~(((ACPI_SIZE) boundary)-1)))
end_define

begin_comment
comment|/* Note: sizeof(ACPI_SIZE) evaluates to either 4 or 8 (32- vs 64-bit mode) */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_TO_32BIT
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_DOWN(a, 4)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_TO_64BIT
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_DOWN(a, 8)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_TO_NATIVE_WORD
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_DOWN(a, sizeof(ACPI_SIZE))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_TO_32BIT
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_UP(a, 4)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_TO_64BIT
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_UP(a, 8)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_TO_NATIVE_WORD
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_UP(a, sizeof(ACPI_SIZE))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_BITS_UP_TO_BYTES
parameter_list|(
name|a
parameter_list|)
value|ACPI_DIV_8((a) + 7)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_BITS_DOWN_TO_BYTES
parameter_list|(
name|a
parameter_list|)
value|ACPI_DIV_8((a))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_TO_1K
parameter_list|(
name|a
parameter_list|)
value|(((a) + 1023)>> 10)
end_define

begin_comment
comment|/* Generic (non-power-of-two) rounding */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_TO
parameter_list|(
name|value
parameter_list|,
name|boundary
parameter_list|)
value|(((value) + ((boundary)-1)) / (boundary))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_MISALIGNED
parameter_list|(
name|value
parameter_list|)
value|(((ACPI_SIZE) value)& (sizeof(ACPI_SIZE)-1))
end_define

begin_comment
comment|/*  * Bitmask creation  * Bit positions start at zero.  * MASK_BITS_ABOVE creates a mask starting AT the position and above  * MASK_BITS_BELOW creates a mask starting one bit BELOW the position  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MASK_BITS_ABOVE
parameter_list|(
name|position
parameter_list|)
value|(~((ACPI_UINT64_MAX)<< ((UINT32) (position))))
end_define

begin_define
define|#
directive|define
name|ACPI_MASK_BITS_BELOW
parameter_list|(
name|position
parameter_list|)
value|((ACPI_UINT64_MAX)<< ((UINT32) (position)))
end_define

begin_comment
comment|/* Bitfields within ACPI registers */
end_comment

begin_define
define|#
directive|define
name|ACPI_REGISTER_PREPARE_BITS
parameter_list|(
name|Val
parameter_list|,
name|Pos
parameter_list|,
name|Mask
parameter_list|)
value|((Val<< Pos)& Mask)
end_define

begin_define
define|#
directive|define
name|ACPI_REGISTER_INSERT_VALUE
parameter_list|(
name|Reg
parameter_list|,
name|Pos
parameter_list|,
name|Mask
parameter_list|,
name|Val
parameter_list|)
value|Reg = (Reg& (~(Mask))) | ACPI_REGISTER_PREPARE_BITS(Val, Pos, Mask)
end_define

begin_define
define|#
directive|define
name|ACPI_INSERT_BITS
parameter_list|(
name|Target
parameter_list|,
name|Mask
parameter_list|,
name|Source
parameter_list|)
value|Target = ((Target& (~(Mask))) | (Source& Mask))
end_define

begin_comment
comment|/*  * An ACPI_NAMESPACE_NODE can appear in some contexts  * where a pointer to an ACPI_OPERAND_OBJECT can also  * appear. This macro is used to distinguish them.  *  * The "Descriptor" field is the first field in both structures.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_GET_DESCRIPTOR_TYPE
parameter_list|(
name|d
parameter_list|)
value|(((ACPI_DESCRIPTOR *)(void *)(d))->Common.DescriptorType)
end_define

begin_define
define|#
directive|define
name|ACPI_SET_DESCRIPTOR_TYPE
parameter_list|(
name|d
parameter_list|,
name|t
parameter_list|)
value|(((ACPI_DESCRIPTOR *)(void *)(d))->Common.DescriptorType = t)
end_define

begin_comment
comment|/*  * Macros for the master AML opcode table  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DISASSEMBLER
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_DEBUG_OUTPUT
argument_list|)
end_if

begin_define
define|#
directive|define
name|ACPI_OP
parameter_list|(
name|Name
parameter_list|,
name|PArgs
parameter_list|,
name|IArgs
parameter_list|,
name|ObjType
parameter_list|,
name|Class
parameter_list|,
name|Type
parameter_list|,
name|Flags
parameter_list|)
define|\
value|{Name, (UINT32)(PArgs), (UINT32)(IArgs), (UINT32)(Flags), ObjType, Class, Type}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_OP
parameter_list|(
name|Name
parameter_list|,
name|PArgs
parameter_list|,
name|IArgs
parameter_list|,
name|ObjType
parameter_list|,
name|Class
parameter_list|,
name|Type
parameter_list|,
name|Flags
parameter_list|)
define|\
value|{(UINT32)(PArgs), (UINT32)(IArgs), (UINT32)(Flags), ObjType, Class, Type}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARG_TYPE_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|ARG_1
parameter_list|(
name|x
parameter_list|)
value|((UINT32)(x))
end_define

begin_define
define|#
directive|define
name|ARG_2
parameter_list|(
name|x
parameter_list|)
value|((UINT32)(x)<< (1 * ARG_TYPE_WIDTH))
end_define

begin_define
define|#
directive|define
name|ARG_3
parameter_list|(
name|x
parameter_list|)
value|((UINT32)(x)<< (2 * ARG_TYPE_WIDTH))
end_define

begin_define
define|#
directive|define
name|ARG_4
parameter_list|(
name|x
parameter_list|)
value|((UINT32)(x)<< (3 * ARG_TYPE_WIDTH))
end_define

begin_define
define|#
directive|define
name|ARG_5
parameter_list|(
name|x
parameter_list|)
value|((UINT32)(x)<< (4 * ARG_TYPE_WIDTH))
end_define

begin_define
define|#
directive|define
name|ARG_6
parameter_list|(
name|x
parameter_list|)
value|((UINT32)(x)<< (5 * ARG_TYPE_WIDTH))
end_define

begin_define
define|#
directive|define
name|ARGI_LIST1
parameter_list|(
name|a
parameter_list|)
value|(ARG_1(a))
end_define

begin_define
define|#
directive|define
name|ARGI_LIST2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(ARG_1(b)|ARG_2(a))
end_define

begin_define
define|#
directive|define
name|ARGI_LIST3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(ARG_1(c)|ARG_2(b)|ARG_3(a))
end_define

begin_define
define|#
directive|define
name|ARGI_LIST4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|(ARG_1(d)|ARG_2(c)|ARG_3(b)|ARG_4(a))
end_define

begin_define
define|#
directive|define
name|ARGI_LIST5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|(ARG_1(e)|ARG_2(d)|ARG_3(c)|ARG_4(b)|ARG_5(a))
end_define

begin_define
define|#
directive|define
name|ARGI_LIST6
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|(ARG_1(f)|ARG_2(e)|ARG_3(d)|ARG_4(c)|ARG_5(b)|ARG_6(a))
end_define

begin_define
define|#
directive|define
name|ARGP_LIST1
parameter_list|(
name|a
parameter_list|)
value|(ARG_1(a))
end_define

begin_define
define|#
directive|define
name|ARGP_LIST2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(ARG_1(a)|ARG_2(b))
end_define

begin_define
define|#
directive|define
name|ARGP_LIST3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(ARG_1(a)|ARG_2(b)|ARG_3(c))
end_define

begin_define
define|#
directive|define
name|ARGP_LIST4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|(ARG_1(a)|ARG_2(b)|ARG_3(c)|ARG_4(d))
end_define

begin_define
define|#
directive|define
name|ARGP_LIST5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|(ARG_1(a)|ARG_2(b)|ARG_3(c)|ARG_4(d)|ARG_5(e))
end_define

begin_define
define|#
directive|define
name|ARGP_LIST6
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|(ARG_1(a)|ARG_2(b)|ARG_3(c)|ARG_4(d)|ARG_5(e)|ARG_6(f))
end_define

begin_define
define|#
directive|define
name|GET_CURRENT_ARG_TYPE
parameter_list|(
name|List
parameter_list|)
value|(List& ((UINT32) 0x1F))
end_define

begin_define
define|#
directive|define
name|INCREMENT_ARG_LIST
parameter_list|(
name|List
parameter_list|)
value|(List>>= ((UINT32) ARG_TYPE_WIDTH))
end_define

begin_comment
comment|/*  * Ascii error messages can be configured out  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_NO_ERROR_MESSAGES
end_ifndef

begin_comment
comment|/*  * Error reporting. Callers module and line number are inserted by AE_INFO,  * the plist contains a set of parens to allow variable-length lists.  * These macros are used for both the debug and non-debug versions of the code.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_ERROR_NAMESPACE
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
value|AcpiUtNamespaceError (AE_INFO, s, e);
end_define

begin_define
define|#
directive|define
name|ACPI_ERROR_METHOD
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|,
name|e
parameter_list|)
value|AcpiUtMethodError (AE_INFO, s, n, p, e);
end_define

begin_define
define|#
directive|define
name|ACPI_WARN_PREDEFINED
parameter_list|(
name|plist
parameter_list|)
value|AcpiUtPredefinedWarning plist
end_define

begin_define
define|#
directive|define
name|ACPI_INFO_PREDEFINED
parameter_list|(
name|plist
parameter_list|)
value|AcpiUtPredefinedInfo plist
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* No error messages */
end_comment

begin_define
define|#
directive|define
name|ACPI_ERROR_NAMESPACE
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_ERROR_METHOD
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|,
name|e
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_WARN_PREDEFINED
parameter_list|(
name|plist
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_INFO_PREDEFINED
parameter_list|(
name|plist
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_NO_ERROR_MESSAGES */
end_comment

begin_comment
comment|/*  * Debug macros that are conditionally compiled  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
end_ifdef

begin_comment
comment|/*  * Function entry tracing  */
end_comment

begin_define
define|#
directive|define
name|ACPI_FUNCTION_TRACE
parameter_list|(
name|a
parameter_list|)
value|ACPI_FUNCTION_NAME(a) \                                             AcpiUtTrace(ACPI_DEBUG_PARAMETERS)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_TRACE_PTR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ACPI_FUNCTION_NAME(a) \                                             AcpiUtTracePtr(ACPI_DEBUG_PARAMETERS, (void *)b)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_TRACE_U32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ACPI_FUNCTION_NAME(a) \                                             AcpiUtTraceU32(ACPI_DEBUG_PARAMETERS, (UINT32)b)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_TRACE_STR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ACPI_FUNCTION_NAME(a) \                                             AcpiUtTraceStr(ACPI_DEBUG_PARAMETERS, (char *)b)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_ENTRY
parameter_list|()
value|AcpiUtTrackStackPtr()
end_define

begin_comment
comment|/*  * Function exit tracing.  * WARNING: These macros include a return statement. This is usually considered  * bad form, but having a separate exit macro is very ugly and difficult to maintain.  * One of the FUNCTION_TRACE macros above must be used in conjunction with these macros  * so that "_AcpiFunctionName" is defined.  *  * Note: the DO_WHILE0 macro is used to prevent some compilers from complaining  * about these constructs.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_USE_DO_WHILE_0
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DO_WHILE0
parameter_list|(
name|a
parameter_list|)
value|do a while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_DO_WHILE0
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|return_VOID
value|ACPI_DO_WHILE0 ({ \                                             AcpiUtExit (ACPI_DEBUG_PARAMETERS); \                                             return;})
end_define

begin_comment
comment|/*  * There are two versions of most of the return macros. The default version is  * safer, since it avoids side-effects by guaranteeing that the argument will  * not be evaluated twice.  *  * A less-safe version of the macros is provided for optional use if the  * compiler uses excessive CPU stack (for example, this may happen in the  * debug case if code optimzation is disabled.)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_SIMPLE_RETURN_MACROS
end_ifndef

begin_define
define|#
directive|define
name|return_ACPI_STATUS
parameter_list|(
name|s
parameter_list|)
value|ACPI_DO_WHILE0 ({ \                                             register ACPI_STATUS _s = (s); \                                             AcpiUtStatusExit (ACPI_DEBUG_PARAMETERS, _s); \                                             return (_s); })
end_define

begin_define
define|#
directive|define
name|return_PTR
parameter_list|(
name|s
parameter_list|)
value|ACPI_DO_WHILE0 ({ \                                             register void *_s = (void *) (s); \                                             AcpiUtPtrExit (ACPI_DEBUG_PARAMETERS, (UINT8 *) _s); \                                             return (_s); })
end_define

begin_define
define|#
directive|define
name|return_VALUE
parameter_list|(
name|s
parameter_list|)
value|ACPI_DO_WHILE0 ({ \                                             register UINT64 _s = (s); \                                             AcpiUtValueExit (ACPI_DEBUG_PARAMETERS, _s); \                                             return (_s); })
end_define

begin_define
define|#
directive|define
name|return_UINT8
parameter_list|(
name|s
parameter_list|)
value|ACPI_DO_WHILE0 ({ \                                             register UINT8 _s = (UINT8) (s); \                                             AcpiUtValueExit (ACPI_DEBUG_PARAMETERS, (UINT64) _s); \                                             return (_s); })
end_define

begin_define
define|#
directive|define
name|return_UINT32
parameter_list|(
name|s
parameter_list|)
value|ACPI_DO_WHILE0 ({ \                                             register UINT32 _s = (UINT32) (s); \                                             AcpiUtValueExit (ACPI_DEBUG_PARAMETERS, (UINT64) _s); \                                             return (_s); })
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Use original less-safe macros */
end_comment

begin_define
define|#
directive|define
name|return_ACPI_STATUS
parameter_list|(
name|s
parameter_list|)
value|ACPI_DO_WHILE0 ({ \                                             AcpiUtStatusExit (ACPI_DEBUG_PARAMETERS, (s)); \                                             return((s)); })
end_define

begin_define
define|#
directive|define
name|return_PTR
parameter_list|(
name|s
parameter_list|)
value|ACPI_DO_WHILE0 ({ \                                             AcpiUtPtrExit (ACPI_DEBUG_PARAMETERS, (UINT8 *) (s)); \                                             return((s)); })
end_define

begin_define
define|#
directive|define
name|return_VALUE
parameter_list|(
name|s
parameter_list|)
value|ACPI_DO_WHILE0 ({ \                                             AcpiUtValueExit (ACPI_DEBUG_PARAMETERS, (UINT64) (s)); \                                             return((s)); })
end_define

begin_define
define|#
directive|define
name|return_UINT8
parameter_list|(
name|s
parameter_list|)
value|return_VALUE(s)
end_define

begin_define
define|#
directive|define
name|return_UINT32
parameter_list|(
name|s
parameter_list|)
value|return_VALUE(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_SIMPLE_RETURN_MACROS */
end_comment

begin_comment
comment|/* Conditional execution */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUG_EXEC
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_ONLY_MEMBERS
parameter_list|(
name|a
parameter_list|)
value|a;
end_define

begin_define
define|#
directive|define
name|_VERBOSE_STRUCTURES
end_define

begin_comment
comment|/* Various object display routines for debug */
end_comment

begin_define
define|#
directive|define
name|ACPI_DUMP_STACK_ENTRY
parameter_list|(
name|a
parameter_list|)
value|AcpiExDumpOperand((a), 0)
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_OPERANDS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|AcpiExDumpOperands(a, b, c)
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_ENTRY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|AcpiNsDumpEntry (a, b)
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_PATHNAME
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|AcpiNsDumpPathname(a, b, c, d)
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_BUFFER
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|AcpiUtDumpBuffer((UINT8 *) a, b, DB_BYTE_DISPLAY, _COMPONENT)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * This is the non-debug case -- make everything go away,  * leaving no executable debug code!  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUG_EXEC
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_ONLY_MEMBERS
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_TRACE
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_TRACE_PTR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_TRACE_U32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_TRACE_STR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_EXIT
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_STATUS_EXIT
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_VALUE_EXIT
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_ENTRY
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_STACK_ENTRY
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_OPERANDS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_ENTRY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_TABLES
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_PATHNAME
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_BUFFER
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_PRINT
parameter_list|(
name|pl
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_PRINT_RAW
parameter_list|(
name|pl
parameter_list|)
end_define

begin_define
define|#
directive|define
name|return_VOID
value|return
end_define

begin_define
define|#
directive|define
name|return_ACPI_STATUS
parameter_list|(
name|s
parameter_list|)
value|return(s)
end_define

begin_define
define|#
directive|define
name|return_VALUE
parameter_list|(
name|s
parameter_list|)
value|return(s)
end_define

begin_define
define|#
directive|define
name|return_UINT8
parameter_list|(
name|s
parameter_list|)
value|return(s)
end_define

begin_define
define|#
directive|define
name|return_UINT32
parameter_list|(
name|s
parameter_list|)
value|return(s)
end_define

begin_define
define|#
directive|define
name|return_PTR
parameter_list|(
name|s
parameter_list|)
value|return(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DEBUG_OUTPUT */
end_comment

begin_comment
comment|/*  * Some code only gets executed when the debugger is built in.  * Note that this is entirely independent of whether the  * DEBUG_PRINT stuff (set by ACPI_DEBUG_OUTPUT) is on, or not.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUGGER
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DEBUGGER_EXEC
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_DEBUGGER_EXEC
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Memory allocation tracking (DEBUG ONLY)  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MEM_PARAMETERS
value|_COMPONENT, _AcpiModuleName, __LINE__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_DBG_TRACK_ALLOCATIONS
end_ifndef

begin_comment
comment|/* Memory allocation */
end_comment

begin_define
define|#
directive|define
name|ACPI_ALLOCATE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtAllocate((ACPI_SIZE) (a), ACPI_MEM_PARAMETERS)
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_ZEROED
parameter_list|(
name|a
parameter_list|)
value|AcpiUtAllocateZeroed((ACPI_SIZE) (a), ACPI_MEM_PARAMETERS)
end_define

begin_define
define|#
directive|define
name|ACPI_FREE
parameter_list|(
name|a
parameter_list|)
value|AcpiOsFree(a)
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_TRACKING
parameter_list|(
name|a
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Memory allocation */
end_comment

begin_define
define|#
directive|define
name|ACPI_ALLOCATE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtAllocateAndTrack((ACPI_SIZE) (a), ACPI_MEM_PARAMETERS)
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_ZEROED
parameter_list|(
name|a
parameter_list|)
value|AcpiUtAllocateZeroedAndTrack((ACPI_SIZE) (a), ACPI_MEM_PARAMETERS)
end_define

begin_define
define|#
directive|define
name|ACPI_FREE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtFreeAndTrack(a, ACPI_MEM_PARAMETERS)
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_TRACKING
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DBG_TRACK_ALLOCATIONS */
end_comment

begin_comment
comment|/*  * Macros used for ACPICA utilities only  */
end_comment

begin_comment
comment|/* Generate a UUID */
end_comment

begin_define
define|#
directive|define
name|ACPI_INIT_UUID
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d0
parameter_list|,
name|d1
parameter_list|,
name|d2
parameter_list|,
name|d3
parameter_list|,
name|d4
parameter_list|,
name|d5
parameter_list|,
name|d6
parameter_list|,
name|d7
parameter_list|)
define|\
value|(a)& 0xFF, ((a)>> 8)& 0xFF, ((a)>> 16)& 0xFF, ((a)>> 24)& 0xFF, \     (b)& 0xFF, ((b)>> 8)& 0xFF, \     (c)& 0xFF, ((c)>> 8)& 0xFF, \     (d0), (d1), (d2), (d3), (d4), (d5), (d6), (d7)
end_define

begin_define
define|#
directive|define
name|ACPI_IS_OCTAL_DIGIT
parameter_list|(
name|d
parameter_list|)
value|(((char)(d)>= '0')&& ((char)(d)<= '7'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACMACROS_H */
end_comment

end_unit

