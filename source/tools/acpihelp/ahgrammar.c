begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahgrammar - AML grammar items  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"acpihelp.h"
end_include

begin_decl_stmt
specifier|const
name|AH_AML_TYPE
name|Gbl_AmlTypesInfo
index|[]
init|=
block|{
block|{
literal|"ComputationalData"
block|,
literal|"ComputationalData :=\n"
literal|"ByteConst | WordConst | DWordConst | QWordConst |\n"
literal|"String | ConstObj | RevisionOp | DefBuffer\n\n"
literal|"DataObject := ComputationalData | DefPackage | DefVarPackage\n"
literal|"DataRefObject := DataObject | ObjectReference | DDBHandle\n\n"
literal|"ByteConst := BytePrefix ByteData\n"
literal|"BytePrefix := 0x0A\n"
literal|"ByteList := Nothing |<ByteData ByteList>\n"
literal|"ByteData := 0x00 - 0xFF\n\n"
literal|"WordConst := WordPrefix WordData\n"
literal|"WordPrefix := 0x0B\n"
literal|"WordData := 0x0000-0xFFFF\n\n"
literal|"DWordConst := DWordPrefix DWordData\n"
literal|"DWordPrefix := 0x0C\n"
literal|"DWordData := 0x00000000-0xFFFFFFFF\n\n"
literal|"QWordConst := QWordPrefix QWordData\n"
literal|"QWordPrefix := 0x0E\n"
literal|"QWordData := 0x0000000000000000-0xFFFFFFFFFFFFFFFF\n\n"
literal|"String := StringPrefix AsciiCharList NullChar\n"
literal|"StringPrefix := 0x0D\n"
literal|"AsciiCharList := Nothing |<AsciiChar AsciiCharList>\n"
literal|"AsciiChar := 0x01 - 0x7F\n"
literal|"NullChar := 0x00\n\n"
literal|"ConstObj := ZeroOp | OneOp | OnesOp\n\n"
block|}
block|,
block|{
literal|"DefinitionBlock"
block|,
literal|"DefinitionBlockHeader :=\n"
literal|"TableSignature TableLength SpecCompliance Checksum\n"
literal|"OemID OemTableID OemRevision CreatorID CreatorRevision\n\n"
literal|"TableSignature := AsciiChar AsciiChar AsciiChar AsciiChar\n"
literal|"TableLength := DWordData\n"
literal|"// Length of the table in bytes including\n"
literal|"// the block header.\n\n"
literal|"SpecCompliance := ByteData\n"
literal|"// The revision of the structure\n\n"
literal|"CheckSum := ByteData\n"
literal|"// Byte checksum of the entire table\n\n"
literal|"OemID := ByteData(6)\n"
literal|"// OEM ID of up to 6 characters. If the OEM\n"
literal|"// ID is shorter than 6 characters, it\n"
literal|"// can be terminated with a NULL\n"
literal|"// character.\n\n"
literal|"OemTableID := ByteData(8)\n"
literal|"// OEM Table ID of up to 8 characters. If\n"
literal|"// the OEM Table ID is shorter than 8\n"
literal|"// characters, it can be terminated with\n"
literal|"// a NULL character.\n"
literal|"OemRevision := DWordData\n"
literal|"// OEM Table Revision\n\n"
literal|"CreatorID := DWordData\n"
literal|"// Vendor ID of the ASL compiler\n"
literal|"CreatorRevision := DWordData\n"
literal|"// Revision of the ASL compiler\n"
block|}
block|,
block|{
literal|"FieldFlags"
block|,
literal|"FieldFlags := ByteData\n"
literal|"// bits 0-3: AccessType\n"
literal|"//     0 AnyAcc\n"
literal|"//     1 ByteAcc\n"
literal|"//     2 WordAcc\n"
literal|"//     3 DWordAcc\n"
literal|"//     4 QWordAcc\n"
literal|"//     5 BufferAcc\n"
literal|"//     6 Reserved\n"
literal|"//     7 Reserved\n"
literal|"// bit 4: LockRule\n"
literal|"//     0 NoLock\n"
literal|"//     1 Lock\n"
literal|"// bits 5-6: UpdateRule\n"
literal|"//     0 Preserve\n"
literal|"//     1 WriteAsOnes\n"
literal|"//     2 WriteAsZeros\n"
literal|"// bit 7:\n"
literal|"//     0 Reserved (must be 0)\n"
block|}
block|,
block|{
literal|"FieldList"
block|,
literal|"FieldList := Nothing |<FieldElement FieldList>\n\n"
literal|"FieldElement := NamedField | ReservedField | AccessField |\n"
literal|"    ExtendedAccessField | ConnectField\n\n"
literal|"NamedField := NameSeg PkgLength\n"
literal|"ReservedField := 0x00 PkgLength\n\n"
literal|"AccessField := 0x01 AccessType\n"
literal|"AccessField := 0x01 AccessType AccessAttrib\n\n"
literal|"AccessType := ByteData\n"
literal|"// Bits 0:3 - Same as AccessType bits of FieldFlags.\n"
literal|"// Bits 4:5 - Reserved\n"
literal|"// Bits 7:6 - 0 = AccessAttribute\n"
literal|"//     Normal Access Attributes\n"
literal|"//     1 = AttribBytes (x)\n"
literal|"//     2 = AttribRawBytes (x)\n"
literal|"//     3 = AttribRawProcessBytes (x)\n"
literal|"//     Note: 'x' is encoded as bits 0:7 of the AccessAttrib byte.\n\n"
literal|"AccessAttrib := ByteData\n"
literal|"// bits 0:7: Byte length\n"
literal|"//\n"
literal|"// If AccessType is BufferAcc for the SMB or\n"
literal|"// GPIO OpRegions, AccessAttrib can be one of\n"
literal|"// the following values:\n"
literal|"// 0x02 AttribQuick\n"
literal|"// 0x04 AttribSendReceive\n"
literal|"// 0x06 AttribByte\n"
literal|"// 0x08 AttribWord\n"
literal|"// 0x0A AttribBlock\n"
literal|"// 0x0C AttribProcessCall\n"
literal|"// 0x0D AttribBlockProcessCall\n\n"
literal|"ExtendedAccessField := 0x03 AccessType ExtendedAccessAttrib AccessLength\n"
literal|"ExtendedAccessAttrib := ByteData\n"
literal|"// 0x0B AttribBytes\n"
literal|"// 0x0E AttribRawBytes\n"
literal|"// 0x0F AttribRawProcess\n\n"
literal|"ConnectField := 0x02 NameString> |<0x02 BufferData\n"
block|}
block|,
block|{
literal|"MatchOpcode"
block|,
literal|"DefMatch := MatchOp SearchPkg MatchOpcode Operand MatchOpcode Operand StartIndex\n"
literal|"MatchOp := 0x89\n"
literal|"SearchPkg := TermArg => Package\n"
literal|"MatchOpcode := ByteData\n"
literal|"// 0 MTR\n"
literal|"// 1 MEQ\n"
literal|"// 2 MLE\n"
literal|"// 3 MLT\n"
literal|"// 4 MGE\n"
literal|"// 5 MGT\n"
block|}
block|,
block|{
literal|"MethodFlags"
block|,
literal|"DefMethod := MethodOp PkgLength NameString MethodFlags TermList\n"
literal|"MethodOp := 0x14\n"
literal|"MethodFlags := ByteData\n"
literal|"// bit 0-2: ArgCount (0-7)\n"
literal|"// bit 3: SerializeFlag\n"
literal|"//   0 NotSerialized\n"
literal|"//   1 Serialized\n"
literal|"// bit 4-7: SyncLevel (0x00-0x0f)\n"
block|}
block|,
block|{
literal|"Miscellaneous"
block|,
literal|"ZeroOp := 0x00\n"
literal|"OneOp := 0x01\n"
literal|"OnesOp := 0xFF\n"
literal|"RevisionOp := ExtOpPrefix 0x30\n"
literal|"ExtOpPrefix := 0x5B\n"
block|}
block|,
block|{
literal|"NameSeg"
block|,
literal|"NameSeg :=<LeadNameChar NameChar NameChar NameChar>\n"
literal|"// Note: NameSegs shorter than 4 characters are filled with\n"
literal|"// trailing underscores.\n\n"
literal|"NameChar := DigitChar | LeadNameChar\n"
literal|"LeadNameChar := 'A'-'Z' | '_' (0x41 - 0x5A) | (0x5F)\n"
literal|"DigitChar := '0'-'9' (0x30 - 0x39)\n"
block|}
block|,
block|{
literal|"NameString"
block|,
literal|"NameString :=<RootChar NamePath> |<PrefixPath NamePath>\n"
literal|"PrefixPath := Nothing |<ParentPrefixChar PrefixPath>\n"
literal|"RootChar := '\\' (0x5C)\n"
literal|"ParentPrefixChar := '^' (0x5E)\n"
block|}
block|,
block|{
literal|"NamePath"
block|,
literal|"NamePath := NameSeg | DualNamePath | MultiNamePath | NullName\n"
literal|"DualNamePath := DualNamePrefix NameSeg NameSeg\n"
literal|"DualNamePrefix := 0x2E\n"
literal|"MultiNamePath := MultiNamePrefix SegCount NameSeg(SegCount)\n"
literal|"MultiNamePrefix := 0x2F\n"
literal|"SegCount := ByteData\n"
literal|"// Note: SegCount can be from 1 to 255. For example: MultiNamePrefix(35)\n"
literal|"// is encoded as 0x2f 0x23 and followed by 35 NameSegs. So, the total\n"
literal|"// encoding length will be 1 + 1 + (35 * 4) = 142. Notice that:\n"
literal|"// DualNamePrefix NameSeg NameSeg has a smaller encoding than the\n"
literal|"// encoding of: MultiNamePrefix(2) NameSeg NameSeg\n\n"
literal|"SimpleName := NameString | ArgObj | LocalObj\n"
literal|"SuperName := SimpleName | DebugObj | Type6Opcode\n"
literal|"NullName := 0x00\n"
literal|"Target := SuperName | NullName\n"
block|}
block|,
block|{
literal|"PkgLength"
block|,
literal|"PkgLength := PkgLeadByte |\n"
literal|"<PkgLeadByte ByteData> |\n"
literal|"<PkgLeadByte ByteData ByteData> |\n"
literal|"<PkgLeadByte ByteData ByteData ByteData>\n\n"
literal|"PkgLeadByte :=\n"
literal|"bit 7-6: Count of ByteData that follows (0-3)\n"
literal|"bit 5-4: Only used if (PkgLength< 63)\n"
literal|"bit 3-0: Least significant package length nybble\n"
literal|"// Note: The high 2 bits of the first byte reveal how many follow bytes\n"
literal|"// are in the PkgLength. If the PkgLength has only one byte, bit 0 through 5\n"
literal|"// are used to encode the package length (in other words, values 0-63). If\n"
literal|"// the package length value is more than 63, more than one byte must be\n"
literal|"// used for the encoding in which case bit 4 and 5 of the PkgLeadByte are\n"
literal|"// reserved and must be zero. If the multiple bytes encoding is used, bits\n"
literal|"// 0-3 of the PkgLeadByte become the least significant 4 bits of the\n"
literal|"// resulting package length value. The next ByteData will become the next\n"
literal|"// least significant 8 bits of the resulting value and so on, up to 3\n"
literal|"// ByteData bytes. Thus, the maximum package length is 2**28.\n"
block|}
block|,
block|{
literal|"RegionSpace"
block|,
literal|"RegionSpace := ByteData\n"
literal|"// 0x00 SystemMemory\n"
literal|"// 0x01 SystemIO\n"
literal|"// 0x02 PCI_Config\n"
literal|"// 0x03 EmbeddedControl\n"
literal|"// 0x04 SMBus\n"
literal|"// 0x05 SystemCMOS\n"
literal|"// 0x06 PciBarTarget\n"
literal|"// 0x07 IPMI\n"
literal|"// 0x08 GeneralPurposeIO\n"
literal|"// 0x09 GenericSerialBus\n"
literal|"// 0x0A Platform Communications Channel\n"
literal|"// 0x0B-0x7E: Reserved\n"
literal|"// 0x7F: Functional Fixed Hardware\n"
literal|"// 0x80-0xBF: Reserved\n"
literal|"// 0xC0-0xFF: OEM Defined\n"
block|}
block|,
block|{
literal|"TermObj"
block|,
literal|"TermObj := NameSpaceModifierObj | NamedObj | Type1Opcode | Type2Opcode\n"
literal|"TermList := Nothing |<TermObj TermList>\n\n"
literal|"MethodInvocation := NameString TermArgList\n"
literal|"TermArgList := Nothing |<TermArg TermArgList>\n"
literal|"TermArg := Type2Opcode | DataObject | ArgObj | LocalObj\n\n"
literal|"ObjectList := Nothing |<Object ObjectList>\n"
literal|"Object := NameSpaceModifierObj | NamedObj\n"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

