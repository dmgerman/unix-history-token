begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acmacros.h - C macros for the entire subsystem.  *       $Revision: 115 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2002, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
value|((UINT16)(NATIVE_UINT)(l))
end_define

begin_define
define|#
directive|define
name|ACPI_HIWORD
parameter_list|(
name|l
parameter_list|)
value|((UINT16)((((NATIVE_UINT)(l))>> 16)& 0xFFFF))
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

begin_ifdef
ifdef|#
directive|ifdef
name|_IA16
end_ifdef

begin_comment
comment|/*  * For 16-bit addresses, we have to assume that the upper 32 bits  * are zero.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LODWORD
parameter_list|(
name|l
parameter_list|)
value|(l)
end_define

begin_define
define|#
directive|define
name|ACPI_HIDWORD
parameter_list|(
name|l
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|ACPI_GET_ADDRESS
parameter_list|(
name|a
parameter_list|)
value|((a).Lo)
end_define

begin_define
define|#
directive|define
name|ACPI_STORE_ADDRESS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{(a).Hi=0;(a).Lo=(b);}
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_ADDRESS
parameter_list|(
name|a
parameter_list|)
value|((a).Hi | (a).Lo)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_NO_INTEGER64_SUPPORT
end_ifdef

begin_comment
comment|/*  * ACPI_INTEGER is 32-bits, no 64-bit support on this platform  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LODWORD
parameter_list|(
name|l
parameter_list|)
value|((UINT32)(l))
end_define

begin_define
define|#
directive|define
name|ACPI_HIDWORD
parameter_list|(
name|l
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|ACPI_GET_ADDRESS
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_define
define|#
directive|define
name|ACPI_STORE_ADDRESS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)=(b))
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_ADDRESS
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Full 64-bit address/integer on both 32-bit and 64-bit platforms  */
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
value|((UINT32)(((*(UINT64_STRUCT *)(&l))).Hi))
end_define

begin_define
define|#
directive|define
name|ACPI_GET_ADDRESS
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_define
define|#
directive|define
name|ACPI_STORE_ADDRESS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)=(b))
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_ADDRESS
parameter_list|(
name|a
parameter_list|)
value|(a)
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
comment|/*   * Extract a byte of data using a pointer.  Any more than a byte and we   * get into potential aligment issues -- see the STORE macros below   */
end_comment

begin_define
define|#
directive|define
name|ACPI_GET8
parameter_list|(
name|addr
parameter_list|)
value|(*(UINT8*)(addr))
end_define

begin_comment
comment|/* Pointer arithmetic */
end_comment

begin_define
define|#
directive|define
name|ACPI_PTR_ADD
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|(t *) ((char *)(a) + (b))
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
value|(NATIVE_UINT) ((char *)(a) - (char *)(b))
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
value|ACPI_PTR_ADD (void,NULL,(NATIVE_UINT)i)
end_define

begin_define
define|#
directive|define
name|ACPI_TO_INTEGER
parameter_list|(
name|p
parameter_list|)
value|ACPI_PTR_DIFF (p,NULL)
end_define

begin_define
define|#
directive|define
name|ACPI_OFFSET
parameter_list|(
name|d
parameter_list|,
name|o
parameter_list|)
value|((ACPI_SIZE) ACPI_TO_INTEGER (&(((d *)0)->o)))
end_define

begin_define
define|#
directive|define
name|ACPI_FADT_OFFSET
parameter_list|(
name|o
parameter_list|)
value|ACPI_OFFSET (FADT_DESCRIPTOR, o)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_IA16
end_ifdef

begin_define
define|#
directive|define
name|ACPI_PHYSADDR_TO_PTR
parameter_list|(
name|i
parameter_list|)
value|(void *)(i)
end_define

begin_define
define|#
directive|define
name|ACPI_PTR_TO_PHYSADDR
parameter_list|(
name|i
parameter_list|)
value|(char *)(i)
end_define

begin_else
else|#
directive|else
end_else

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
name|_HW_ALIGNMENT_SUPPORT
end_ifdef

begin_comment
comment|/* The hardware supports unaligned transfers, just do the move */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_UNALIGNED16_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|*(UINT16 *)(d) = *(UINT16 *)(s)
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_UNALIGNED32_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|*(UINT32 *)(d) = *(UINT32 *)(s)
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_UNALIGNED16_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|*(UINT32 *)(d) = *(UINT16 *)(s)
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_UNALIGNED64_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|*(UINT64 *)(d) = *(UINT64 *)(s)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * The hardware does not support unaligned transfers.  We must move the  * data one byte at a time.  These macros work whether the source or  * the destination (or both) is/are unaligned.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MOVE_UNALIGNED16_TO_16
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{((UINT8 *)(d))[0] = ((UINT8 *)(s))[0];\                                              ((UINT8 *)(d))[1] = ((UINT8 *)(s))[1];}
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_UNALIGNED32_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{((UINT8 *)(d))[0] = ((UINT8 *)(s))[0];\                                              ((UINT8 *)(d))[1] = ((UINT8 *)(s))[1];\                                              ((UINT8 *)(d))[2] = ((UINT8 *)(s))[2];\                                              ((UINT8 *)(d))[3] = ((UINT8 *)(s))[3];}
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_UNALIGNED16_TO_32
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{(*(UINT32*)(d)) = 0; ACPI_MOVE_UNALIGNED16_TO_16(d,s);}
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_UNALIGNED64_TO_64
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|{((UINT8 *)(d))[0] = ((UINT8 *)(s))[0];\                                              ((UINT8 *)(d))[1] = ((UINT8 *)(s))[1];\                                              ((UINT8 *)(d))[2] = ((UINT8 *)(s))[2];\                                              ((UINT8 *)(d))[3] = ((UINT8 *)(s))[3];\                                              ((UINT8 *)(d))[4] = ((UINT8 *)(s))[4];\                                              ((UINT8 *)(d))[5] = ((UINT8 *)(s))[5];\                                              ((UINT8 *)(d))[6] = ((UINT8 *)(s))[6];\                                              ((UINT8 *)(d))[7] = ((UINT8 *)(s))[7];}
end_define

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
value|(((NATIVE_UINT)(value))& (~((boundary)-1)))
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
value|((((NATIVE_UINT)(value)) + ((boundary)-1))& (~((boundary)-1)))
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_TO_32_BITS
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_DOWN(a,4)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_DOWN_TO_64_BITS
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
value|ACPI_ROUND_DOWN(a,ALIGNED_ADDRESS_BOUNDARY)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_TO_32BITS
parameter_list|(
name|a
parameter_list|)
value|ACPI_ROUND_UP(a,4)
end_define

begin_define
define|#
directive|define
name|ACPI_ROUND_UP_TO_64BITS
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
value|ACPI_ROUND_UP(a,ALIGNED_ADDRESS_BOUNDARY)
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
value|(~(((ACPI_INTEGER)(-1))<< ((UINT32) (position))))
end_define

begin_define
define|#
directive|define
name|ACPI_MASK_BITS_BELOW
parameter_list|(
name|position
parameter_list|)
value|(((ACPI_INTEGER)(-1))<< ((UINT32) (position)))
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
comment|/* Macros for GAS addressing */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IA16
end_ifndef

begin_define
define|#
directive|define
name|ACPI_PCI_DEVICE_MASK
value|(UINT64) 0x0000FFFF00000000
end_define

begin_define
define|#
directive|define
name|ACPI_PCI_FUNCTION_MASK
value|(UINT64) 0x00000000FFFF0000
end_define

begin_define
define|#
directive|define
name|ACPI_PCI_REGISTER_MASK
value|(UINT64) 0x000000000000FFFF
end_define

begin_define
define|#
directive|define
name|ACPI_PCI_FUNCTION
parameter_list|(
name|a
parameter_list|)
value|(UINT16) ((((a)& ACPI_PCI_FUNCTION_MASK)>> 16))
end_define

begin_define
define|#
directive|define
name|ACPI_PCI_DEVICE
parameter_list|(
name|a
parameter_list|)
value|(UINT16) ((((a)& ACPI_PCI_DEVICE_MASK)>> 32))
end_define

begin_define
define|#
directive|define
name|ACPI_PCI_REGISTER
parameter_list|(
name|a
parameter_list|)
value|(UINT16) (((a)& ACPI_PCI_REGISTER_MASK))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* No support for GAS and PCI IDs in 16-bit mode  */
end_comment

begin_define
define|#
directive|define
name|ACPI_PCI_FUNCTION
parameter_list|(
name|a
parameter_list|)
value|(UINT16) ((a)& 0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|ACPI_PCI_DEVICE
parameter_list|(
name|a
parameter_list|)
value|(UINT16) ((a)& 0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|ACPI_PCI_REGISTER
parameter_list|(
name|a
parameter_list|)
value|(UINT16) ((a)& 0x0000FFFF)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|(((ACPI_NAMESPACE_NODE *)d)->Descriptor)
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
value|(((ACPI_NAMESPACE_NODE *)d)->Descriptor = t)
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
value|(((ACPI_OPERAND_OBJECT *)d)->Common.Type)
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
comment|/*  * Macro to check if a pointer is within an ACPI table.  * Parameter (a) is the pointer to check.  Parameter (b) must be defined  * as a pointer to an ACPI_TABLE_HEADER.  (b+1) then points past the header,  * and ((UINT8 *)b+b->Length) points one byte past the end of the table.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IA16
end_ifndef

begin_define
define|#
directive|define
name|ACPI_IS_IN_ACPI_TABLE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((UINT8 *)(a)>= (UINT8 *)(b + 1))&&\                                          ((UINT8 *)(a)< ((UINT8 *)b + b->Length)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_IS_IN_ACPI_TABLE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(_segment)(a) == (_segment)(b)&&\                                         (((UINT8 *)(a)>= (UINT8 *)(b + 1))&&\                                         ((UINT8 *)(a)< ((UINT8 *)b + b->Length)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros for the master AML opcode table  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG
end_ifdef

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
value|{Name,PArgs,IArgs,Flags,ObjType,Class,Type}
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
value|{PArgs,IArgs,Flags,ObjType,Class,Type}
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
comment|/*  * Build a GAS structure from earlier ACPI table entries (V1.0 and 0.71 extensions)  *  * 1) Address space  * 2) Length in bytes -- convert to length in bits  * 3) Bit offset is zero  * 4) Reserved field is zero  * 5) Expand address to 64 bits  */
end_comment

begin_define
define|#
directive|define
name|ASL_BUILD_GAS_FROM_ENTRY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|{a.AddressSpaceId = (UINT8) d;\                                              a.RegisterBitWidth = (UINT8) ACPI_MUL_8 (b);\                                              a.RegisterBitOffset = 0;\                                              a.Reserved = 0;\                                              ACPI_STORE_ADDRESS (a.Address,c);}
end_define

begin_comment
comment|/* ACPI V1.0 entries -- address space is always I/O */
end_comment

begin_define
define|#
directive|define
name|ASL_BUILD_GAS_FROM_V1_ENTRY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|ASL_BUILD_GAS_FROM_ENTRY(a,b,c,ACPI_ADR_SPACE_SYSTEM_IO)
end_define

begin_comment
comment|/*  * Reporting macros that are never compiled out  */
end_comment

begin_define
define|#
directive|define
name|ACPI_PARAM_LIST
parameter_list|(
name|pl
parameter_list|)
value|pl
end_define

begin_comment
comment|/*  * Error reporting.  These versions add callers module and line#.  Since  * _THIS_MODULE gets compiled out when ACPI_DEBUG isn't defined, only  * use it in debug mode.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ACPI_REPORT_INFO
parameter_list|(
name|fp
parameter_list|)
value|{AcpiUtReportInfo(_THIS_MODULE,__LINE__,_COMPONENT); \                                                 AcpiOsPrintf ACPI_PARAM_LIST(fp);}
end_define

begin_define
define|#
directive|define
name|ACPI_REPORT_ERROR
parameter_list|(
name|fp
parameter_list|)
value|{AcpiUtReportError(_THIS_MODULE,__LINE__,_COMPONENT); \                                                 AcpiOsPrintf ACPI_PARAM_LIST(fp);}
end_define

begin_define
define|#
directive|define
name|ACPI_REPORT_WARNING
parameter_list|(
name|fp
parameter_list|)
value|{AcpiUtReportWarning(_THIS_MODULE,__LINE__,_COMPONENT); \                                                 AcpiOsPrintf ACPI_PARAM_LIST(fp);}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_REPORT_INFO
parameter_list|(
name|fp
parameter_list|)
value|{AcpiUtReportInfo("ACPI",__LINE__,_COMPONENT); \                                                 AcpiOsPrintf ACPI_PARAM_LIST(fp);}
end_define

begin_define
define|#
directive|define
name|ACPI_REPORT_ERROR
parameter_list|(
name|fp
parameter_list|)
value|{AcpiUtReportError("ACPI",__LINE__,_COMPONENT); \                                                 AcpiOsPrintf ACPI_PARAM_LIST(fp);}
end_define

begin_define
define|#
directive|define
name|ACPI_REPORT_WARNING
parameter_list|(
name|fp
parameter_list|)
value|{AcpiUtReportWarning("ACPI",__LINE__,_COMPONENT); \                                                 AcpiOsPrintf ACPI_PARAM_LIST(fp);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Error reporting.  These versions pass thru the module and line# */
end_comment

begin_define
define|#
directive|define
name|_ACPI_REPORT_INFO
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|fp
parameter_list|)
value|{AcpiUtReportInfo(a,b,c); \                                                 AcpiOsPrintf ACPI_PARAM_LIST(fp);}
end_define

begin_define
define|#
directive|define
name|_ACPI_REPORT_ERROR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|fp
parameter_list|)
value|{AcpiUtReportError(a,b,c); \                                                 AcpiOsPrintf ACPI_PARAM_LIST(fp);}
end_define

begin_define
define|#
directive|define
name|_ACPI_REPORT_WARNING
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|fp
parameter_list|)
value|{AcpiUtReportWarning(a,b,c); \                                                 AcpiOsPrintf ACPI_PARAM_LIST(fp);}
end_define

begin_comment
comment|/*  * Debug macros that are conditionally compiled  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ACPI_MODULE_NAME
parameter_list|(
name|name
parameter_list|)
value|static char *_THIS_MODULE = name;
end_define

begin_comment
comment|/*  * Function entry tracing.  * The first parameter should be the procedure name as a quoted string.  This is declared  * as a local string ("_ProcName) so that it can be also used by the function exit macros below.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_FUNCTION_NAME
parameter_list|(
name|a
parameter_list|)
value|ACPI_DEBUG_PRINT_INFO _Dbg;     \                                         _Dbg.ComponentId = _COMPONENT;  \                                         _Dbg.ProcName    = a;           \                                         _Dbg.ModuleName  = _THIS_MODULE;
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_TRACE
parameter_list|(
name|a
parameter_list|)
value|ACPI_FUNCTION_NAME(a)\                                             AcpiUtTrace(__LINE__,&_Dbg)
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
value|ACPI_FUNCTION_NAME(a)\                                             AcpiUtTracePtr(__LINE__,&_Dbg,(void *)b)
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
value|ACPI_FUNCTION_NAME(a)\                                             AcpiUtTraceU32(__LINE__,&_Dbg,(UINT32)b)
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
value|ACPI_FUNCTION_NAME(a)\                                             AcpiUtTraceStr(__LINE__,&_Dbg,(NATIVE_CHAR *)b)
end_define

begin_define
define|#
directive|define
name|ACPI_FUNCTION_ENTRY
parameter_list|()
value|AcpiUtTrackStackPtr()
end_define

begin_comment
comment|/*  * Function exit tracing.  * WARNING: These macros include a return statement.  This is usually considered  * bad form, but having a separate exit macro is very ugly and difficult to maintain.  * One of the FUNCTION_TRACE macros above must be used in conjunction with these macros  * so that "_ProcName" is defined.  */
end_comment

begin_define
define|#
directive|define
name|return_VOID
value|{AcpiUtExit(__LINE__,&_Dbg);return;}
end_define

begin_define
define|#
directive|define
name|return_ACPI_STATUS
parameter_list|(
name|s
parameter_list|)
value|{AcpiUtStatusExit(__LINE__,&_Dbg,s);return(s);}
end_define

begin_define
define|#
directive|define
name|return_VALUE
parameter_list|(
name|s
parameter_list|)
value|{AcpiUtValueExit(__LINE__,&_Dbg,s);return(s);}
end_define

begin_define
define|#
directive|define
name|return_PTR
parameter_list|(
name|s
parameter_list|)
value|{AcpiUtPtrExit(__LINE__,&_Dbg,(UINT8 *)s);return(s);}
end_define

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
name|_OPCODE_NAMES
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
value|AcpiExDumpOperand(a)
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
value|AcpiExDumpOperands(a,b,c,d,e,_THIS_MODULE,__LINE__)
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
name|ACPI_DUMP_TABLES
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|AcpiNsDumpTables(a,b)
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

begin_define
define|#
directive|define
name|ACPI_BREAK_MSG
parameter_list|(
name|a
parameter_list|)
value|AcpiOsSignal (ACPI_SIGNAL_BREAKPOINT,(a))
end_define

begin_comment
comment|/*  * Generate INT3 on ACPI_ERROR (Debug only!)  */
end_comment

begin_define
define|#
directive|define
name|ACPI_ERROR_BREAK
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_ERROR_BREAK
end_ifdef

begin_define
define|#
directive|define
name|ACPI_BREAK_ON_ERROR
parameter_list|(
name|lvl
parameter_list|)
value|if ((lvl)&ACPI_ERROR) \                                             AcpiOsSignal(ACPI_SIGNAL_BREAKPOINT,"Fatal error encountered\n")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_BREAK_ON_ERROR
parameter_list|(
name|lvl
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Master debug print macros  * Print iff:  *    1) Debug print for the current component is enabled  *    2) Debug error level or trace level for the print statement is enabled  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUG_PRINT
parameter_list|(
name|pl
parameter_list|)
value|AcpiUtDebugPrint ACPI_PARAM_LIST(pl)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_PRINT_RAW
parameter_list|(
name|pl
parameter_list|)
value|AcpiUtDebugPrintRaw ACPI_PARAM_LIST(pl)
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
name|ACPI_MODULE_NAME
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_THIS_MODULE
value|""
end_define

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
name|ACPI_BREAK_MSG
parameter_list|(
name|a
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
comment|/*  * Some code only gets executed when the debugger is built in.  * Note that this is entirely independent of whether the  * DEBUG_PRINT stuff (set by ACPI_DEBUG) is on, or not.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_DEBUGGER
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
comment|/*  * For 16-bit code, we want to shrink some things even though  * we are using ACPI_DEBUG to get the debug output  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_IA16
end_ifdef

begin_undef
undef|#
directive|undef
name|ACPI_DEBUG_ONLY_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_VERBOSE_STRUCTURES
end_undef

begin_define
define|#
directive|define
name|ACPI_DEBUG_ONLY_MEMBERS
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
name|ACPI_DEBUG
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
name|ACPI_MEM_ALLOCATE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtAllocate(a,_COMPONENT,_THIS_MODULE,__LINE__)
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_CALLOCATE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtCallocate(a, _COMPONENT,_THIS_MODULE,__LINE__)
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_FREE
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
name|ACPI_MEM_ALLOCATE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtAllocateAndTrack(a,_COMPONENT,_THIS_MODULE,__LINE__)
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_CALLOCATE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtCallocateAndTrack(a, _COMPONENT,_THIS_MODULE,__LINE__)
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_FREE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtFreeAndTrack(a,_COMPONENT,_THIS_MODULE,__LINE__)
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

begin_define
define|#
directive|define
name|ACPI_GET_STACK_POINTER
value|_asm {mov eax, ebx}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACMACROS_H */
end_comment

end_unit

