begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acbuffer.h - Support for buffers returned by ACPI predefined names  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACBUFFER_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACBUFFER_H__
end_define

begin_comment
comment|/*  * Contains buffer structures for these predefined names:  * _FDE, _GRT, _GTM, _PLD, _SRT  */
end_comment

begin_comment
comment|/*  * Note: C bitfields are not used for this reason:  *  * "Bitfields are great and easy to read, but unfortunately the C language  * does not specify the layout of bitfields in memory, which means they are  * essentially useless for dealing with packed data in on-disk formats or  * binary wire protocols." (Or ACPI tables and buffers.) "If you ask me,  * this decision was a design error in C. Ritchie could have picked an order  * and stuck with it." Norman Ramsey.  * See http://stackoverflow.com/a/1053662/41661  */
end_comment

begin_comment
comment|/* _FDE return value */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_fde_info
block|{
name|UINT32
name|Floppy0
decl_stmt|;
name|UINT32
name|Floppy1
decl_stmt|;
name|UINT32
name|Floppy2
decl_stmt|;
name|UINT32
name|Floppy3
decl_stmt|;
name|UINT32
name|Tape
decl_stmt|;
block|}
name|ACPI_FDE_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * _GRT return value  * _SRT input value  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_grt_info
block|{
name|UINT16
name|Year
decl_stmt|;
name|UINT8
name|Month
decl_stmt|;
name|UINT8
name|Day
decl_stmt|;
name|UINT8
name|Hour
decl_stmt|;
name|UINT8
name|Minute
decl_stmt|;
name|UINT8
name|Second
decl_stmt|;
name|UINT8
name|Valid
decl_stmt|;
name|UINT16
name|Milliseconds
decl_stmt|;
name|UINT16
name|Timezone
decl_stmt|;
name|UINT8
name|Daylight
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ACPI_GRT_INFO
typedef|;
end_typedef

begin_comment
comment|/* _GTM return value */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_gtm_info
block|{
name|UINT32
name|PioSpeed0
decl_stmt|;
name|UINT32
name|DmaSpeed0
decl_stmt|;
name|UINT32
name|PioSpeed1
decl_stmt|;
name|UINT32
name|DmaSpeed1
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
block|}
name|ACPI_GTM_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * Formatted _PLD return value. The minimum size is a package containing  * one buffer.  * Revision 1: Buffer is 16 bytes (128 bits)  * Revision 2: Buffer is 20 bytes (160 bits)  *  * Note: This structure is returned from the AcpiDecodePldBuffer  * interface.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pld_info
block|{
name|UINT8
name|Revision
decl_stmt|;
name|UINT8
name|IgnoreColor
decl_stmt|;
name|UINT8
name|Red
decl_stmt|;
name|UINT8
name|Green
decl_stmt|;
name|UINT8
name|Blue
decl_stmt|;
name|UINT16
name|Width
decl_stmt|;
name|UINT16
name|Height
decl_stmt|;
name|UINT8
name|UserVisible
decl_stmt|;
name|UINT8
name|Dock
decl_stmt|;
name|UINT8
name|Lid
decl_stmt|;
name|UINT8
name|Panel
decl_stmt|;
name|UINT8
name|VerticalPosition
decl_stmt|;
name|UINT8
name|HorizontalPosition
decl_stmt|;
name|UINT8
name|Shape
decl_stmt|;
name|UINT8
name|GroupOrientation
decl_stmt|;
name|UINT8
name|GroupToken
decl_stmt|;
name|UINT8
name|GroupPosition
decl_stmt|;
name|UINT8
name|Bay
decl_stmt|;
name|UINT8
name|Ejectable
decl_stmt|;
name|UINT8
name|OspmEjectRequired
decl_stmt|;
name|UINT8
name|CabinetNumber
decl_stmt|;
name|UINT8
name|CardCageNumber
decl_stmt|;
name|UINT8
name|Reference
decl_stmt|;
name|UINT8
name|Rotation
decl_stmt|;
name|UINT8
name|Order
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT16
name|VerticalOffset
decl_stmt|;
name|UINT16
name|HorizontalOffset
decl_stmt|;
block|}
name|ACPI_PLD_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * Macros to:  *     1) Convert a _PLD buffer to internal ACPI_PLD_INFO format - ACPI_PLD_GET*  *        (Used by AcpiDecodePldBuffer)  *     2) Construct a _PLD buffer - ACPI_PLD_SET*  *        (Intended for BIOS use only)  */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_REV1_BUFFER_SIZE
value|16
end_define

begin_comment
comment|/* For Revision 1 of the buffer (From ACPI spec) */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_REV2_BUFFER_SIZE
value|20
end_define

begin_comment
comment|/* For Revision 2 of the buffer (From ACPI spec) */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_BUFFER_SIZE
value|20
end_define

begin_comment
comment|/* For Revision 2 of the buffer (From ACPI spec) */
end_comment

begin_comment
comment|/* First 32-bit dword, bits 0:32 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_REVISION
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 0, ACPI_7BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_REVISION
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 0, ACPI_7BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 0, Len 7 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_IGNORE_COLOR
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 7, ACPI_1BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_IGNORE_COLOR
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 7, ACPI_1BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 7, Len 1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_RED
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 8, ACPI_8BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_RED
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 8, ACPI_8BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 8, Len 8 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_GREEN
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 16, ACPI_8BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_GREEN
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 16, ACPI_8BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 16, Len 8 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_BLUE
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 24, ACPI_8BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_BLUE
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 24, ACPI_8BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 24, Len 8 */
end_comment

begin_comment
comment|/* Second 32-bit dword, bits 33:63 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_WIDTH
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 0, ACPI_16BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_WIDTH
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 0, ACPI_16BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 32+0=32, Len 16 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_HEIGHT
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 16, ACPI_16BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_HEIGHT
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 16, ACPI_16BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 32+16=48, Len 16 */
end_comment

begin_comment
comment|/* Third 32-bit dword, bits 64:95 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_USER_VISIBLE
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 0, ACPI_1BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_USER_VISIBLE
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 0, ACPI_1BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+0=64, Len 1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_DOCK
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 1, ACPI_1BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_DOCK
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 1, ACPI_1BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+1=65, Len 1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_LID
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 2, ACPI_1BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_LID
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 2, ACPI_1BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+2=66, Len 1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_PANEL
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 3, ACPI_3BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_PANEL
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 3, ACPI_3BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+3=67, Len 3 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_VERTICAL
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 6, ACPI_2BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_VERTICAL
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 6, ACPI_2BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+6=70, Len 2 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_HORIZONTAL
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 8, ACPI_2BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_HORIZONTAL
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 8, ACPI_2BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+8=72, Len 2 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_SHAPE
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 10, ACPI_4BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_SHAPE
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 10, ACPI_4BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+10=74, Len 4 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_ORIENTATION
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 14, ACPI_1BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_ORIENTATION
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 14, ACPI_1BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+14=78, Len 1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_TOKEN
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 15, ACPI_8BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_TOKEN
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 15, ACPI_8BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+15=79, Len 8 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_POSITION
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 23, ACPI_8BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_POSITION
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 23, ACPI_8BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+23=87, Len 8 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_BAY
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 31, ACPI_1BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_BAY
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 31, ACPI_1BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 64+31=95, Len 1 */
end_comment

begin_comment
comment|/* Fourth 32-bit dword, bits 96:127 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_EJECTABLE
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 0, ACPI_1BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_EJECTABLE
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 0, ACPI_1BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 96+0=96, Len 1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_OSPM_EJECT
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 1, ACPI_1BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_OSPM_EJECT
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 1, ACPI_1BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 96+1=97, Len 1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_CABINET
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 2, ACPI_8BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_CABINET
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 2, ACPI_8BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 96+2=98, Len 8 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_CARD_CAGE
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 10, ACPI_8BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_CARD_CAGE
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 10, ACPI_8BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 96+10=106, Len 8 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_REFERENCE
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 18, ACPI_1BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_REFERENCE
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 18, ACPI_1BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 96+18=114, Len 1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_ROTATION
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 19, ACPI_4BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_ROTATION
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 19, ACPI_4BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 96+19=115, Len 4 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_ORDER
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 23, ACPI_5BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_ORDER
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 23, ACPI_5BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 96+23=119, Len 5 */
end_comment

begin_comment
comment|/* Fifth 32-bit dword, bits 128:159 (Revision 2 of _PLD only) */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_VERT_OFFSET
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 0, ACPI_16BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_VERT_OFFSET
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 0, ACPI_16BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 128+0=128, Len 16 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PLD_GET_HORIZ_OFFSET
parameter_list|(
name|dword
parameter_list|)
value|ACPI_GET_BITS (dword, 16, ACPI_16BIT_MASK)
end_define

begin_define
define|#
directive|define
name|ACPI_PLD_SET_HORIZ_OFFSET
parameter_list|(
name|dword
parameter_list|,
name|value
parameter_list|)
value|ACPI_SET_BITS (dword, 16, ACPI_16BIT_MASK, value)
end_define

begin_comment
comment|/* Offset 128+16=144, Len 16 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACBUFFER_H */
end_comment

end_unit

