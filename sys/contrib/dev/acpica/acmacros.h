begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acmacros.h - C macros for the entire subsystem.  *       $Revision: 1.195 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
comment|/*  * Data manipulation macros  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LOWORD
parameter_list|(
name|l
parameter_list|)
value|((UINT16)(UINT32)(l))
end_define

begin_define
define|#
directive|define
name|ACPI_HIWORD
parameter_list|(
name|l
parameter_list|)
value|((UINT16)((((UINT32)(l))>> 16)& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|ACPI_LOBYTE
parameter_list|(
name|l
parameter_list|)
value|((UINT8)(UINT16)(l))
end_define

begin_define
define|#
directive|define
name|ACPI_HIBYTE
parameter_list|(
name|l
parameter_list|)
value|((UINT8)((((UINT16)(l))>> 8)& 0xFF))
end_define

begin_define
define|#
directive|define
name|ACPI_SET_BIT
parameter_list|(
name|target
parameter_list|,
name|bit
parameter_list|)
value|((target) |= (bit))
end_define

begin_define
define|#
directive|define
name|ACPI_CLEAR_BIT
parameter_list|(
name|target
parameter_list|,
name|bit
parameter_list|)
value|((target)&= ~(bit))
end_define

begin_define
define|#
directive|define
name|ACPI_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_define
define|#
directive|define
name|ACPI_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_comment
comment|/* Size calculation */
end_comment

begin_define
define|#
directive|define
name|ACPI_ARRAY_LENGTH
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x) / sizeof((x)[0]))
end_define

begin_comment
comment|/*  * Full 64-bit integer must be available on both 32-bit and 64-bit platforms  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LODWORD
parameter_list|(
name|l
parameter_list|)
value|((UINT32)(UINT64)(l))
end_define

begin_define
define|#
directive|define
name|ACPI_HIDWORD
parameter_list|(
name|l
parameter_list|)
value|((UINT32)(((*(UINT64_STRUCT *)(void *)(&l))).Hi))
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
value|ACPI_HIDWORD(i),ACPI_LODWORD(i)
end_define

begin_comment
comment|/*  * Extract data using a pointer.  Any more than a byte and we  * get into potential aligment issues -- see the STORE macros below.  * Use with care.  */
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
comment|/*  * Pointer manipulation  */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAST_PTR
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|)
value|((t *) (ACPI_UINTPTR_T) (p))
end_define

begin_define
define|#
directive|define
name|ACPI_CAST_INDIRECT_PTR
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|)
value|((t **) (ACPI_UINTPTR_T) (p))
end_define

begin_define
define|#
directive|define
name|ACPI_ADD_PTR
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|ACPI_CAST_PTR (t, (ACPI_CAST_PTR (UINT8,(a)) + (ACPI_NATIVE_UINT)(b)))
end_define

begin_define
define|#
directive|define
name|ACPI_PTR_DIFF
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(ACPI_NATIVE_UINT) (ACPI_CAST_PTR (UINT8,(a)) - ACPI_CAST_PTR (UINT8,(b)))
end_define

begin_comment
comment|/* Pointer/Integer type conversions */
end_comment

begin_define
define|#
directive|define
name|ACPI_TO_POINTER
parameter_list|(
name|i
parameter_list|)
value|ACPI_ADD_PTR (void,(void *) NULL,(ACPI_NATIVE_UINT) i)
end_define

begin_define
define|#
directive|define
name|ACPI_TO_INTEGER
parameter_list|(
name|p
parameter_list|)
value|ACPI_PTR_DIFF (p,(void *) NULL)
end_define

begin_define
define|#
directive|define
name|ACPI_OFFSET
parameter_list|(
name|d
parameter_list|,
name|f
parameter_list|)
value|(ACPI_SIZE) ACPI_PTR_DIFF (&(((d *)0)->f),(void *) NULL)
end_define

begin_define
define|#
directive|define
name|ACPI_PHYSADDR_TO_PTR
parameter_list|(
name|i
parameter_list|)
value|ACPI_TO_POINTER(i)
end_define

begin_define
define|#
directive|define
name|ACPI_PTR_TO_PHYSADDR
parameter_list|(
name|i
parameter_list|)
value|ACPI_TO_INTEGER(i)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MISALIGNMENT_NOT_SUPPORTED
end_ifndef

begin_define
define|#
directive|define
name|ACPI_COMPARE_NAME
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*ACPI_CAST_PTR (UINT32,(a)) == *ACPI_CAST_PTR (UINT32,(b)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_COMPARE_NAME
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(!ACPI_STRNCMP (ACPI_CAST_PTR (char,(a)), ACPI_CAST_PTR (char,(b)), ACPI_NAME_SIZE))
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
comment|/* This macro sets a buffer index, starting from the end of the buffer */
end_comment

begin_define
define|#
directive|define
name|ACPI_BUFFER_INDEX
parameter_list|(
name|BufLen
parameter_list|,
name|BufOffset
parameter_list|,
name|ByteGran
parameter_list|)
value|((BufLen) - (((BufOffset)+1) * (ByteGran)))
end_define

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
value|ACPI_MOVE_16_TO_16(d,s)
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
value|ACPI_MOVE_16_TO_16(d,s)
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
value|ACPI_MOVE_32_TO_32(d,s)
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

begin_comment
comment|/* This macro sets a buffer index, starting from the beginning of the buffer */
end_comment

begin_define
define|#
directive|define
name|ACPI_BUFFER_INDEX
parameter_list|(
name|BufLen
parameter_list|,
name|BufOffset
parameter_list|,
name|ByteGran
parameter_list|)
value|(BufOffset)
end_define

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
value|ACPI_MOVE_16_TO_16(d,s)
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
value|ACPI_MOVE_16_TO_16(d,s)
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
value|ACPI_MOVE_32_TO_32(d,s)
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
comment|/*  * The hardware does not support unaligned transfers.  We must move the  * data one byte at a time.  These macros work whether the source or  * the destination (or both) is/are unaligned.  (Little-endian move)  */
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
value|{(*(UINT32 *)(void *)(d)) = 0; ACPI_MOVE_16_TO_16(d,s);}
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
value|{(*(UINT64 *)(void *)(d)) = 0; ACPI_MOVE_16_TO_16(d,s);}
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
value|ACPI_MOVE_16_TO_16(d,s)
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
value|{(*(UINT64 *)(void *)(d)) = 0; ACPI_MOVE_32_TO_32(d,s);}
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
value|ACPI_MOVE_16_TO_16(d,s)
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
value|ACPI_MOVE_32_TO_32(d,s)
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
comment|/* Macros based on machine integer width */
end_comment

begin_if
if|#
directive|if
name|ACPI_MACHINE_WIDTH
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|ACPI_MOVE_SIZE_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_32_TO_16(d,s)
end_define

begin_elif
elif|#
directive|elif
name|ACPI_MACHINE_WIDTH
operator|==
literal|64
end_elif

begin_define
define|#
directive|define
name|ACPI_MOVE_SIZE_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|ACPI_MOVE_64_TO_16(d,s)
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|unknown ACPI_MACHINE_WIDTH
end_error

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
value|_ACPI_DIV(a,1)
end_define

begin_define
define|#
directive|define
name|ACPI_MUL_2
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MUL(a,1)
end_define

begin_define
define|#
directive|define
name|ACPI_MOD_2
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MOD(a,2)
end_define

begin_define
define|#
directive|define
name|ACPI_DIV_4
parameter_list|(
name|a
parameter_list|)
value|_ACPI_DIV(a,2)
end_define

begin_define
define|#
directive|define
name|ACPI_MUL_4
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MUL(a,2)
end_define

begin_define
define|#
directive|define
name|ACPI_MOD_4
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MOD(a,4)
end_define

begin_define
define|#
directive|define
name|ACPI_DIV_8
parameter_list|(
name|a
parameter_list|)
value|_ACPI_DIV(a,3)
end_define

begin_define
define|#
directive|define
name|ACPI_MUL_8
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MUL(a,3)
end_define

begin_define
define|#
directive|define
name|ACPI_MOD_8
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MOD(a,8)
end_define

begin_define
define|#
directive|define
name|ACPI_DIV_16
parameter_list|(
name|a
parameter_list|)
value|_ACPI_DIV(a,4)
end_define

begin_define
define|#
directive|define
name|ACPI_MUL_16
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MUL(a,4)
end_define

begin_define
define|#
directive|define
name|ACPI_MOD_16
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MOD(a,16)
end_define

begin_define
define|#
directive|define
name|ACPI_DIV_32
parameter_list|(
name|a
parameter_list|)
value|_ACPI_DIV(a,5)
end_define

begin_define
define|#
directive|define
name|ACPI_MUL_32
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MUL(a,5)
end_define

begin_define
define|#
directive|define
name|ACPI_MOD_32
parameter_list|(
name|a
parameter_list|)
value|_ACPI_MOD(a,32)
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
value|(((ACPI_NATIVE_UINT)(value))& \                                                 (~(((ACPI_NATIVE_UINT) boundary)-1)))
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
value|((((ACPI_NATIVE_UINT)(value)) + \                                                 (((ACPI_NATIVE_UINT) boundary)-1))& \                                                 (~(((ACPI_NATIVE_UINT) boundary)-1)))
end_define

begin_comment
comment|/* Note: sizeof(ACPI_NATIVE_UINT) evaluates to either 2, 4, or 8 */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_TO_32BIT
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_DOWN(a,4)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_TO_64BIT
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_DOWN(a,8)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_TO_NATIVE_WORD
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_DOWN(a,sizeof(ACPI_NATIVE_UINT))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_TO_32BIT
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_UP(a,4)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_TO_64BIT
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_UP(a,8)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_TO_NATIVE_WORD
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_UP(a,sizeof(ACPI_NATIVE_UINT))
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
value|(((ACPI_NATIVE_UINT)value)& (sizeof(ACPI_NATIVE_UINT)-1))
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
value|(~((ACPI_INTEGER_MAX)<< ((UINT32) (position))))
end_define

begin_define
define|#
directive|define
name|ACPI_MASK_BITS_BELOW
parameter_list|(
name|position
parameter_list|)
value|((ACPI_INTEGER_MAX)<< ((UINT32) (position)))
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

begin_comment
comment|/*  * An ACPI_NAMESPACE_NODE * can appear in some contexts,  * where a pointer to an ACPI_OPERAND_OBJECT  can also  * appear.  This macro is used to distinguish them.  *  * The "Descriptor" field is the first field in both structures.  */
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
comment|/* Macro to test the object type */
end_comment

begin_define
define|#
directive|define
name|ACPI_GET_OBJECT_TYPE
parameter_list|(
name|d
parameter_list|)
value|(((ACPI_OPERAND_OBJECT *)(void *)(d))->Common.Type)
end_define

begin_comment
comment|/* Macro to check the table flags for SINGLE or MULTIPLE tables are allowed */
end_comment

begin_define
define|#
directive|define
name|ACPI_IS_SINGLE_TABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x01) == ACPI_TABLE_SINGLE ? 1 : 0)
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
value|{Name,(UINT32)(PArgs),(UINT32)(IArgs),(UINT32)(Flags),ObjType,Class,Type}
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
value|{(UINT32)(PArgs),(UINT32)(IArgs),(UINT32)(Flags),ObjType,Class,Type}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DISASSEMBLER
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DISASM_ONLY_MEMBERS
parameter_list|(
name|a
parameter_list|)
value|a;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_DISASM_ONLY_MEMBERS
parameter_list|(
name|a
parameter_list|)
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DEBUG_OUTPUT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|ACPI_NO_ERROR_MESSAGES
argument_list|)
end_if

begin_comment
comment|/*  * Module name is include in both debug and non-debug versions primarily for  * error messages. The __FILE__ macro is not very useful for this, because it  * often includes the entire pathname to the module  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MODULE_NAME
parameter_list|(
name|Name
parameter_list|)
value|static char ACPI_UNUSED_VAR *_AcpiModuleName = Name;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_MODULE_NAME
parameter_list|(
name|Name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ascii error messages can be configured out  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_NO_ERROR_MESSAGES
end_ifndef

begin_define
define|#
directive|define
name|AE_INFO
value|_AcpiModuleName, __LINE__
end_define

begin_comment
comment|/*  * Error reporting. Callers module and line number are inserted by AE_INFO,  * the plist contains a set of parens to allow variable-length lists.  * These macros are used for both the debug and non-debug versions of the code.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_INFO
parameter_list|(
name|plist
parameter_list|)
value|AcpiUtInfo plist
end_define

begin_define
define|#
directive|define
name|ACPI_WARNING
parameter_list|(
name|plist
parameter_list|)
value|AcpiUtWarning plist
end_define

begin_define
define|#
directive|define
name|ACPI_EXCEPTION
parameter_list|(
name|plist
parameter_list|)
value|AcpiUtException plist
end_define

begin_define
define|#
directive|define
name|ACPI_ERROR
parameter_list|(
name|plist
parameter_list|)
value|AcpiUtError plist
end_define

begin_define
define|#
directive|define
name|ACPI_ERROR_NAMESPACE
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
value|AcpiNsReportError (AE_INFO, s, e);
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
value|AcpiNsReportMethodError (AE_INFO, s, n, p, e);
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
name|ACPI_INFO
parameter_list|(
name|plist
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_WARNING
parameter_list|(
name|plist
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_EXCEPTION
parameter_list|(
name|plist
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_ERROR
parameter_list|(
name|plist
parameter_list|)
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Debug macros that are conditionally compiled  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
end_ifdef

begin_comment
comment|/*  * Common parameters used for debug output functions:  * line number, function name, module(file) name, component ID  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUG_PARAMETERS
value|__LINE__, ACPI_GET_FUNCTION_NAME, _AcpiModuleName, _COMPONENT
end_define

begin_comment
comment|/*  * Function entry tracing  */
end_comment

begin_comment
comment|/*  * If ACPI_GET_FUNCTION_NAME was not defined in the compiler-dependent header,  * define it now. This is the case where there the compiler does not support  * a __FUNCTION__ macro or equivalent. We save the function name on the  * local stack.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_GET_FUNCTION_NAME
end_ifndef

begin_define
define|#
directive|define
name|ACPI_GET_FUNCTION_NAME
value|_AcpiFunctionName
end_define

begin_comment
comment|/*  * The Name parameter should be the procedure name as a quoted string.  * This is declared as a local string ("MyFunctionName") so that it can  * be also used by the function exit macros below.  * Note: (const char) is used to be compatible with the debug interfaces  * and macros such as __FUNCTION__.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_FUNCTION_NAME
parameter_list|(
name|Name
parameter_list|)
value|const char *_AcpiFunctionName = #Name;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Compiler supports __FUNCTION__ (or equivalent) -- Ignore this macro */
end_comment

begin_define
define|#
directive|define
name|ACPI_FUNCTION_NAME
parameter_list|(
name|Name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|ACPI_FUNCTION_NAME(a) \                                             AcpiUtTracePtr(ACPI_DEBUG_PARAMETERS,(void *)b)
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
value|ACPI_FUNCTION_NAME(a) \                                             AcpiUtTraceU32(ACPI_DEBUG_PARAMETERS,(UINT32)b)
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
value|ACPI_FUNCTION_NAME(a) \                                             AcpiUtTraceStr(ACPI_DEBUG_PARAMETERS,(char *)b)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_ENTRY
parameter_list|()
value|AcpiUtTrackStackPtr()
end_define

begin_comment
comment|/*  * Function exit tracing.  * WARNING: These macros include a return statement.  This is usually considered  * bad form, but having a separate exit macro is very ugly and difficult to maintain.  * One of the FUNCTION_TRACE macros above must be used in conjunction with these macros  * so that "_AcpiFunctionName" is defined.  *  * Note: the DO_WHILE0 macro is used to prevent some compilers from complaining  * about these constructs.  */
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
value|ACPI_DO_WHILE0 ({ \                                             register ACPI_INTEGER _s = (s); \                                             AcpiUtValueExit (ACPI_DEBUG_PARAMETERS, _s); \                                             return (_s); })
end_define

begin_define
define|#
directive|define
name|return_UINT8
parameter_list|(
name|s
parameter_list|)
value|ACPI_DO_WHILE0 ({ \                                             register UINT8 _s = (UINT8) (s); \                                             AcpiUtValueExit (ACPI_DEBUG_PARAMETERS, (ACPI_INTEGER) _s); \                                             return (_s); })
end_define

begin_define
define|#
directive|define
name|return_UINT32
parameter_list|(
name|s
parameter_list|)
value|ACPI_DO_WHILE0 ({ \                                             register UINT32 _s = (UINT32) (s); \                                             AcpiUtValueExit (ACPI_DEBUG_PARAMETERS, (ACPI_INTEGER) _s); \                                             return (_s); })
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
value|ACPI_DO_WHILE0 ({ \                                             AcpiUtValueExit (ACPI_DEBUG_PARAMETERS, (ACPI_INTEGER) (s)); \                                             return((s)); })
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
name|ACPI_NORMAL_EXEC
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_DEFINE
parameter_list|(
name|a
parameter_list|)
value|a;
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
comment|/* Stack and buffer dumping */
end_comment

begin_define
define|#
directive|define
name|ACPI_DUMP_STACK_ENTRY
parameter_list|(
name|a
parameter_list|)
value|AcpiExDumpOperand((a),0)
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
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|AcpiExDumpOperands(a,b,c,d,e,_AcpiModuleName,__LINE__)
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
value|AcpiNsDumpEntry (a,b)
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
value|AcpiNsDumpPathname(a,b,c,d)
end_define

begin_define
define|#
directive|define
name|ACPI_DUMP_RESOURCE_LIST
parameter_list|(
name|a
parameter_list|)
value|AcpiRsDumpResourceList(a)
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
value|AcpiUtDumpBuffer((UINT8 *)a,b,DB_BYTE_DISPLAY,_COMPONENT)
end_define

begin_comment
comment|/*  * Master debug print macros  * Print iff:  *    1) Debug print for the current component is enabled  *    2) Debug error level or trace level for the print statement is enabled  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUG_PRINT
parameter_list|(
name|plist
parameter_list|)
value|AcpiUtDebugPrint plist
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_PRINT_RAW
parameter_list|(
name|plist
parameter_list|)
value|AcpiUtDebugPrintRaw plist
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
name|ACPI_NORMAL_EXEC
parameter_list|(
name|a
parameter_list|)
value|a;
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_DEFINE
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
name|ACPI_FUNCTION_NAME
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
parameter_list|,
name|d
parameter_list|,
name|e
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
name|ACPI_DUMP_RESOURCE_LIST
parameter_list|(
name|a
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

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
end_ifdef

begin_comment
comment|/*  * 1) Set name to blanks  * 2) Copy the object name  */
end_comment

begin_define
define|#
directive|define
name|ACPI_ADD_OBJECT_NAME
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ACPI_MEMSET (a->Common.Name, ' ', sizeof (a->Common.Name));\                                         ACPI_STRNCPY (a->Common.Name, AcpiGbl_NsTypeNames[b], sizeof (a->Common.Name))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_ADD_OBJECT_NAME
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Memory allocation tracking (DEBUG ONLY)  */
end_comment

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
value|AcpiUtAllocate((ACPI_SIZE)(a),_COMPONENT,_AcpiModuleName,__LINE__)
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_ZEROED
parameter_list|(
name|a
parameter_list|)
value|AcpiUtAllocateZeroed((ACPI_SIZE)(a), _COMPONENT,_AcpiModuleName,__LINE__)
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
value|AcpiUtAllocateAndTrack((ACPI_SIZE)(a),_COMPONENT,_AcpiModuleName,__LINE__)
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_ZEROED
parameter_list|(
name|a
parameter_list|)
value|AcpiUtAllocateZeroedAndTrack((ACPI_SIZE)(a), _COMPONENT,_AcpiModuleName,__LINE__)
end_define

begin_define
define|#
directive|define
name|ACPI_FREE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtFreeAndTrack(a,_COMPONENT,_AcpiModuleName,__LINE__)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACMACROS_H */
end_comment

end_unit

