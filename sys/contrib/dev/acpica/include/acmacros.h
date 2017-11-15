begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acmacros.h - C macros for the entire subsystem.  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
comment|/*  * Extract data using a pointer. Any more than a byte and we  * get into potential alignment issues -- see the STORE macros below.  * Use with care.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAST8
parameter_list|(
name|ptr
parameter_list|)
value|ACPI_CAST_PTR (UINT8, (ptr))
end_define

begin_define
define|#
directive|define
name|ACPI_CAST16
parameter_list|(
name|ptr
parameter_list|)
value|ACPI_CAST_PTR (UINT16, (ptr))
end_define

begin_define
define|#
directive|define
name|ACPI_CAST32
parameter_list|(
name|ptr
parameter_list|)
value|ACPI_CAST_PTR (UINT32, (ptr))
end_define

begin_define
define|#
directive|define
name|ACPI_CAST64
parameter_list|(
name|ptr
parameter_list|)
value|ACPI_CAST_PTR (UINT64, (ptr))
end_define

begin_define
define|#
directive|define
name|ACPI_GET8
parameter_list|(
name|ptr
parameter_list|)
value|(*ACPI_CAST8 (ptr))
end_define

begin_define
define|#
directive|define
name|ACPI_GET16
parameter_list|(
name|ptr
parameter_list|)
value|(*ACPI_CAST16 (ptr))
end_define

begin_define
define|#
directive|define
name|ACPI_GET32
parameter_list|(
name|ptr
parameter_list|)
value|(*ACPI_CAST32 (ptr))
end_define

begin_define
define|#
directive|define
name|ACPI_GET64
parameter_list|(
name|ptr
parameter_list|)
value|(*ACPI_CAST64 (ptr))
end_define

begin_define
define|#
directive|define
name|ACPI_SET8
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|(*ACPI_CAST8 (ptr) = (UINT8) (val))
end_define

begin_define
define|#
directive|define
name|ACPI_SET16
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|(*ACPI_CAST16 (ptr) = (UINT16) (val))
end_define

begin_define
define|#
directive|define
name|ACPI_SET32
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|(*ACPI_CAST32 (ptr) = (UINT32) (val))
end_define

begin_define
define|#
directive|define
name|ACPI_SET64
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|(*ACPI_CAST64 (ptr) = (UINT64) (val))
end_define

begin_comment
comment|/*  * printf() format helper. This macro is a workaround for the difficulties  * with emitting 64-bit integers and 64-bit pointers with the same code  * for both 32-bit and 64-bit hosts.  */
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
comment|/* Test for ASCII character */
end_comment

begin_define
define|#
directive|define
name|ACPI_IS_ASCII
parameter_list|(
name|c
parameter_list|)
value|((c)< 0x80)
end_define

begin_comment
comment|/* Signed integers */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIGN_POSITIVE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_SIGN_NEGATIVE
value|1
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
comment|/* Generic bit manipulation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_NATIVE_BIT_FINDER
end_ifndef

begin_define
define|#
directive|define
name|__ACPI_FIND_LAST_BIT_2
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT8)  (a))& 0x02) ? (r)+1 : (r))
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_LAST_BIT_4
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT8)  (a))& 0x0C) ? \                                              __ACPI_FIND_LAST_BIT_2  ((a)>>2,  (r)+2) : \                                              __ACPI_FIND_LAST_BIT_2  ((a), (r)))
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_LAST_BIT_8
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT8)  (a))& 0xF0) ? \                                              __ACPI_FIND_LAST_BIT_4  ((a)>>4,  (r)+4) : \                                              __ACPI_FIND_LAST_BIT_4  ((a), (r)))
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_LAST_BIT_16
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT16) (a))& 0xFF00) ? \                                              __ACPI_FIND_LAST_BIT_8  ((a)>>8,  (r)+8) : \                                              __ACPI_FIND_LAST_BIT_8  ((a), (r)))
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_LAST_BIT_32
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT32) (a))& 0xFFFF0000) ? \                                              __ACPI_FIND_LAST_BIT_16 ((a)>>16, (r)+16) : \                                              __ACPI_FIND_LAST_BIT_16 ((a), (r)))
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_LAST_BIT_64
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT64) (a))& 0xFFFFFFFF00000000) ? \                                              __ACPI_FIND_LAST_BIT_32 ((a)>>32, (r)+32) : \                                              __ACPI_FIND_LAST_BIT_32 ((a), (r)))
end_define

begin_define
define|#
directive|define
name|ACPI_FIND_LAST_BIT_8
parameter_list|(
name|a
parameter_list|)
value|((a) ? __ACPI_FIND_LAST_BIT_8 (a, 1) : 0)
end_define

begin_define
define|#
directive|define
name|ACPI_FIND_LAST_BIT_16
parameter_list|(
name|a
parameter_list|)
value|((a) ? __ACPI_FIND_LAST_BIT_16 (a, 1) : 0)
end_define

begin_define
define|#
directive|define
name|ACPI_FIND_LAST_BIT_32
parameter_list|(
name|a
parameter_list|)
value|((a) ? __ACPI_FIND_LAST_BIT_32 (a, 1) : 0)
end_define

begin_define
define|#
directive|define
name|ACPI_FIND_LAST_BIT_64
parameter_list|(
name|a
parameter_list|)
value|((a) ? __ACPI_FIND_LAST_BIT_64 (a, 1) : 0)
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_FIRST_BIT_2
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT8) (a))& 0x01) ? (r) : (r)+1)
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_FIRST_BIT_4
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT8) (a))& 0x03) ? \                                              __ACPI_FIND_FIRST_BIT_2  ((a), (r)) : \                                              __ACPI_FIND_FIRST_BIT_2  ((a)>>2, (r)+2))
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_FIRST_BIT_8
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT8) (a))& 0x0F) ? \                                              __ACPI_FIND_FIRST_BIT_4  ((a), (r)) : \                                              __ACPI_FIND_FIRST_BIT_4  ((a)>>4, (r)+4))
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_FIRST_BIT_16
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT16) (a))& 0x00FF) ? \                                              __ACPI_FIND_FIRST_BIT_8  ((a), (r)) : \                                              __ACPI_FIND_FIRST_BIT_8  ((a)>>8, (r)+8))
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_FIRST_BIT_32
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT32) (a))& 0x0000FFFF) ? \                                              __ACPI_FIND_FIRST_BIT_16 ((a), (r)) : \                                              __ACPI_FIND_FIRST_BIT_16 ((a)>>16, (r)+16))
end_define

begin_define
define|#
directive|define
name|__ACPI_FIND_FIRST_BIT_64
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|)
value|((((UINT64) (a))& 0x00000000FFFFFFFF) ? \                                              __ACPI_FIND_FIRST_BIT_32 ((a), (r)) : \                                              __ACPI_FIND_FIRST_BIT_32 ((a)>>32, (r)+32))
end_define

begin_define
define|#
directive|define
name|ACPI_FIND_FIRST_BIT_8
parameter_list|(
name|a
parameter_list|)
value|((a) ? __ACPI_FIND_FIRST_BIT_8 (a, 1) : 0)
end_define

begin_define
define|#
directive|define
name|ACPI_FIND_FIRST_BIT_16
parameter_list|(
name|a
parameter_list|)
value|((a) ? __ACPI_FIND_FIRST_BIT_16 (a, 1) : 0)
end_define

begin_define
define|#
directive|define
name|ACPI_FIND_FIRST_BIT_32
parameter_list|(
name|a
parameter_list|)
value|((a) ? __ACPI_FIND_FIRST_BIT_32 (a, 1) : 0)
end_define

begin_define
define|#
directive|define
name|ACPI_FIND_FIRST_BIT_64
parameter_list|(
name|a
parameter_list|)
value|((a) ? __ACPI_FIND_FIRST_BIT_64 (a, 1) : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_NATIVE_BIT_FINDER */
end_comment

begin_comment
comment|/* Generic (power-of-two) rounding */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_POWER_OF_TWO_8
parameter_list|(
name|a
parameter_list|)
value|((UINT8) \                                             (((UINT16) 1)<<  ACPI_FIND_LAST_BIT_8  ((a)  - 1)))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_POWER_OF_TWO_8
parameter_list|(
name|a
parameter_list|)
value|((UINT8) \                                             (((UINT16) 1)<< (ACPI_FIND_LAST_BIT_8  ((a)) - 1)))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_POWER_OF_TWO_16
parameter_list|(
name|a
parameter_list|)
value|((UINT16) \                                             (((UINT32) 1)<<  ACPI_FIND_LAST_BIT_16 ((a)  - 1)))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_POWER_OF_TWO_16
parameter_list|(
name|a
parameter_list|)
value|((UINT16) \                                             (((UINT32) 1)<< (ACPI_FIND_LAST_BIT_16 ((a)) - 1)))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_POWER_OF_TWO_32
parameter_list|(
name|a
parameter_list|)
value|((UINT32) \                                             (((UINT64) 1)<<  ACPI_FIND_LAST_BIT_32 ((a)  - 1)))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_POWER_OF_TWO_32
parameter_list|(
name|a
parameter_list|)
value|((UINT32) \                                             (((UINT64) 1)<< (ACPI_FIND_LAST_BIT_32 ((a)) - 1)))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_ALIGNED
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|(((a)& ((s) - 1)) == 0)
end_define

begin_define
define|#
directive|define
name|ACPI_IS_POWER_OF_TWO
parameter_list|(
name|a
parameter_list|)
value|ACPI_IS_ALIGNED(a, a)
end_define

begin_comment
comment|/*  * Bitmask creation  * Bit positions start at zero.  * MASK_BITS_ABOVE creates a mask starting AT the position and above  * MASK_BITS_BELOW creates a mask starting one bit BELOW the position  * MASK_BITS_ABOVE/BELOW accepts a bit offset to create a mask  * MASK_BITS_ABOVE/BELOW_32/64 accepts a bit width to create a mask  * Note: The ACPI_INTEGER_BIT_SIZE check is used to bypass compiler  * differences with the shift operator  */
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

begin_define
define|#
directive|define
name|ACPI_MASK_BITS_ABOVE_32
parameter_list|(
name|width
parameter_list|)
value|((UINT32) ACPI_MASK_BITS_ABOVE(width))
end_define

begin_define
define|#
directive|define
name|ACPI_MASK_BITS_BELOW_32
parameter_list|(
name|width
parameter_list|)
value|((UINT32) ACPI_MASK_BITS_BELOW(width))
end_define

begin_define
define|#
directive|define
name|ACPI_MASK_BITS_ABOVE_64
parameter_list|(
name|width
parameter_list|)
value|((width) == ACPI_INTEGER_BIT_SIZE ? \                                                 ACPI_UINT64_MAX : \                                                 ACPI_MASK_BITS_ABOVE(width))
end_define

begin_define
define|#
directive|define
name|ACPI_MASK_BITS_BELOW_64
parameter_list|(
name|width
parameter_list|)
value|((width) == ACPI_INTEGER_BIT_SIZE ? \                                                 (UINT64) 0 : \                                                 ACPI_MASK_BITS_BELOW(width))
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
define|\
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
define|\
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
define|\
value|Target = ((Target& (~(Mask))) | (Source& Mask))
end_define

begin_comment
comment|/* Generic bitfield macros and masks */
end_comment

begin_define
define|#
directive|define
name|ACPI_GET_BITS
parameter_list|(
name|SourcePtr
parameter_list|,
name|Position
parameter_list|,
name|Mask
parameter_list|)
define|\
value|((*(SourcePtr)>> (Position))& (Mask))
end_define

begin_define
define|#
directive|define
name|ACPI_SET_BITS
parameter_list|(
name|TargetPtr
parameter_list|,
name|Position
parameter_list|,
name|Mask
parameter_list|,
name|Value
parameter_list|)
define|\
value|(*(TargetPtr) |= (((Value)& (Mask))<< (Position)))
end_define

begin_define
define|#
directive|define
name|ACPI_1BIT_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACPI_2BIT_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ACPI_3BIT_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|ACPI_4BIT_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|ACPI_5BIT_MASK
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|ACPI_6BIT_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|ACPI_7BIT_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|ACPI_8BIT_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|ACPI_16BIT_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|ACPI_24BIT_MASK
value|0x00FFFFFF
end_define

begin_comment
comment|/* Macros to extract flag bits from position zero */
end_comment

begin_define
define|#
directive|define
name|ACPI_GET_1BIT_FLAG
parameter_list|(
name|Value
parameter_list|)
value|((Value)& ACPI_1BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_GET_2BIT_FLAG
parameter_list|(
name|Value
parameter_list|)
value|((Value)& ACPI_2BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_GET_3BIT_FLAG
parameter_list|(
name|Value
parameter_list|)
value|((Value)& ACPI_3BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_GET_4BIT_FLAG
parameter_list|(
name|Value
parameter_list|)
value|((Value)& ACPI_4BIT_MASK)
end_define

begin_comment
comment|/* Macros to extract flag bits from position one and above */
end_comment

begin_define
define|#
directive|define
name|ACPI_EXTRACT_1BIT_FLAG
parameter_list|(
name|Field
parameter_list|,
name|Position
parameter_list|)
value|(ACPI_GET_1BIT_FLAG ((Field)>> Position))
end_define

begin_define
define|#
directive|define
name|ACPI_EXTRACT_2BIT_FLAG
parameter_list|(
name|Field
parameter_list|,
name|Position
parameter_list|)
value|(ACPI_GET_2BIT_FLAG ((Field)>> Position))
end_define

begin_define
define|#
directive|define
name|ACPI_EXTRACT_3BIT_FLAG
parameter_list|(
name|Field
parameter_list|,
name|Position
parameter_list|)
value|(ACPI_GET_3BIT_FLAG ((Field)>> Position))
end_define

begin_define
define|#
directive|define
name|ACPI_EXTRACT_4BIT_FLAG
parameter_list|(
name|Field
parameter_list|,
name|Position
parameter_list|)
value|(ACPI_GET_4BIT_FLAG ((Field)>> Position))
end_define

begin_comment
comment|/* ACPI Pathname helpers */
end_comment

begin_define
define|#
directive|define
name|ACPI_IS_ROOT_PREFIX
parameter_list|(
name|c
parameter_list|)
value|((c) == (UINT8) 0x5C)
end_define

begin_comment
comment|/* Backslash */
end_comment

begin_define
define|#
directive|define
name|ACPI_IS_PARENT_PREFIX
parameter_list|(
name|c
parameter_list|)
value|((c) == (UINT8) 0x5E)
end_define

begin_comment
comment|/* Carat */
end_comment

begin_define
define|#
directive|define
name|ACPI_IS_PATH_SEPARATOR
parameter_list|(
name|c
parameter_list|)
value|((c) == (UINT8) 0x2E)
end_define

begin_comment
comment|/* Period (dot) */
end_comment

begin_comment
comment|/*  * An object of type ACPI_NAMESPACE_NODE can appear in some contexts  * where a pointer to an object of type ACPI_OPERAND_OBJECT can also  * appear. This macro is used to distinguish them.  *  * The "DescriptorType" field is the second field in both structures.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_GET_DESCRIPTOR_PTR
parameter_list|(
name|d
parameter_list|)
value|(((ACPI_DESCRIPTOR *)(void *)(d))->Common.CommonPointer)
end_define

begin_define
define|#
directive|define
name|ACPI_SET_DESCRIPTOR_PTR
parameter_list|(
name|d
parameter_list|,
name|p
parameter_list|)
value|(((ACPI_DESCRIPTOR *)(void *)(d))->Common.CommonPointer = (p))
end_define

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
value|(((ACPI_DESCRIPTOR *)(void *)(d))->Common.DescriptorType = (t))
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
comment|/*  * Error reporting. The callers module and line number are inserted by AE_INFO,  * the plist contains a set of parens to allow variable-length lists.  * These macros are used for both the debug and non-debug versions of the code.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_ERROR_NAMESPACE
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|,
name|e
parameter_list|)
value|AcpiUtPrefixedNamespaceError (AE_INFO, s, p, e);
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

begin_define
define|#
directive|define
name|ACPI_BIOS_ERROR_PREDEFINED
parameter_list|(
name|plist
parameter_list|)
value|AcpiUtPredefinedBiosError plist
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

begin_define
define|#
directive|define
name|ACPI_BIOS_ERROR_PREDEFINED
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

begin_if
if|#
directive|if
operator|(
operator|!
name|ACPI_REDUCED_HARDWARE
operator|)
end_if

begin_define
define|#
directive|define
name|ACPI_HW_OPTIONAL_FUNCTION
parameter_list|(
name|addr
parameter_list|)
value|addr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_HW_OPTIONAL_FUNCTION
parameter_list|(
name|addr
parameter_list|)
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Macors used for the ASL-/ASL+ converter utility  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_ASL_COMPILER
end_ifdef

begin_define
define|#
directive|define
name|ASL_CV_LABEL_FILENODE
parameter_list|(
name|a
parameter_list|)
value|CvLabelFileNode(a);
end_define

begin_define
define|#
directive|define
name|ASL_CV_CAPTURE_COMMENTS_ONLY
parameter_list|(
name|a
parameter_list|)
value|CvCaptureCommentsOnly (a);
end_define

begin_define
define|#
directive|define
name|ASL_CV_CAPTURE_COMMENTS
parameter_list|(
name|a
parameter_list|)
value|CvCaptureComments (a);
end_define

begin_define
define|#
directive|define
name|ASL_CV_TRANSFER_COMMENTS
parameter_list|(
name|a
parameter_list|)
value|CvTransferComments (a);
end_define

begin_define
define|#
directive|define
name|ASL_CV_CLOSE_PAREN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CvCloseParenWriteComment(a,b);
end_define

begin_define
define|#
directive|define
name|ASL_CV_CLOSE_BRACE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CvCloseBraceWriteComment(a,b);
end_define

begin_define
define|#
directive|define
name|ASL_CV_SWITCH_FILES
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CvSwitchFiles(a,b);
end_define

begin_define
define|#
directive|define
name|ASL_CV_CLEAR_OP_COMMENTS
parameter_list|(
name|a
parameter_list|)
value|CvClearOpComments(a);
end_define

begin_define
define|#
directive|define
name|ASL_CV_PRINT_ONE_COMMENT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|CvPrintOneCommentType (a,b,c,d);
end_define

begin_define
define|#
directive|define
name|ASL_CV_PRINT_ONE_COMMENT_LIST
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CvPrintOneCommentList (a,b);
end_define

begin_define
define|#
directive|define
name|ASL_CV_FILE_HAS_SWITCHED
parameter_list|(
name|a
parameter_list|)
value|CvFileHasSwitched(a)
end_define

begin_define
define|#
directive|define
name|ASL_CV_INIT_FILETREE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|CvInitFileTree(a,b,c);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASL_CV_LABEL_FILENODE
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASL_CV_CAPTURE_COMMENTS_ONLY
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASL_CV_CAPTURE_COMMENTS
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASL_CV_TRANSFER_COMMENTS
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASL_CV_CLOSE_PAREN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|AcpiOsPrintf (")");
end_define

begin_define
define|#
directive|define
name|ASL_CV_CLOSE_BRACE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|AcpiOsPrintf ("}");
end_define

begin_define
define|#
directive|define
name|ASL_CV_SWITCH_FILES
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASL_CV_CLEAR_OP_COMMENTS
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASL_CV_PRINT_ONE_COMMENT
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
name|ASL_CV_PRINT_ONE_COMMENT_LIST
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASL_CV_FILE_HAS_SWITCHED
parameter_list|(
name|a
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|ASL_CV_INIT_FILETREE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
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
comment|/* ACMACROS_H */
end_comment

end_unit

