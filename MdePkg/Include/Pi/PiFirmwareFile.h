begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The firmware file related definitions in PI.  Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License that accompanies this distribution. The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   PI Version 1.4.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_FIRMWARE_FILE_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_FIRMWARE_FILE_H__
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used to verify the integrity of the file.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
comment|///
comment|/// The IntegrityCheck.Checksum.Header field is an 8-bit checksum of the file
comment|/// header. The State and IntegrityCheck.Checksum.File fields are assumed
comment|/// to be zero and the checksum is calculated such that the entire header sums to zero.
comment|///
name|UINT8
name|Header
decl_stmt|;
comment|///
comment|/// If the FFS_ATTRIB_CHECKSUM (see definition below) bit of the Attributes
comment|/// field is set to one, the IntegrityCheck.Checksum.File field is an 8-bit
comment|/// checksum of the file data.
comment|/// If the FFS_ATTRIB_CHECKSUM bit of the Attributes field is cleared to zero,
comment|/// the IntegrityCheck.Checksum.File field must be initialized with a value of
comment|/// 0xAA. The IntegrityCheck.Checksum.File field is valid any time the
comment|/// EFI_FILE_DATA_VALID bit is set in the State field.
comment|///
name|UINT8
name|File
decl_stmt|;
block|}
name|Checksum
struct|;
comment|///
comment|/// This is the full 16 bits of the IntegrityCheck field.
comment|///
name|UINT16
name|Checksum16
decl_stmt|;
block|}
name|EFI_FFS_INTEGRITY_CHECK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FFS_FIXED_CHECKSUM is the checksum value used when the
end_comment

begin_comment
comment|/// FFS_ATTRIB_CHECKSUM attribute bit is clear.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|FFS_FIXED_CHECKSUM
value|0xAA
end_define

begin_typedef
typedef|typedef
name|UINT8
name|EFI_FV_FILETYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_FFS_FILE_ATTRIBUTES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_FFS_FILE_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// File Types Definitions
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_ALL
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_RAW
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_FREEFORM
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_SECURITY_CORE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_PEI_CORE
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_DXE_CORE
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_PEIM
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_DRIVER
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_COMBINED_PEIM_DRIVER
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_APPLICATION
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_SMM
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_FIRMWARE_VOLUME_IMAGE
value|0x0B
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_COMBINED_SMM_DXE
value|0x0C
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_SMM_CORE
value|0x0D
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_OEM_MIN
value|0xc0
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_OEM_MAX
value|0xdf
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_DEBUG_MIN
value|0xe0
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_DEBUG_MAX
value|0xef
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_FFS_MIN
value|0xf0
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_FFS_MAX
value|0xff
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILETYPE_FFS_PAD
value|0xf0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// FFS File Attributes.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|FFS_ATTRIB_LARGE_FILE
value|0x01
end_define

begin_define
define|#
directive|define
name|FFS_ATTRIB_FIXED
value|0x04
end_define

begin_define
define|#
directive|define
name|FFS_ATTRIB_DATA_ALIGNMENT
value|0x38
end_define

begin_define
define|#
directive|define
name|FFS_ATTRIB_CHECKSUM
value|0x40
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// FFS File State Bits.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_FILE_HEADER_CONSTRUCTION
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_FILE_HEADER_VALID
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_FILE_DATA_VALID
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_FILE_MARKED_FOR_UPDATE
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_FILE_DELETED
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_FILE_HEADER_INVALID
value|0x20
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each file begins with the header that describe the
end_comment

begin_comment
comment|/// contents and state of the files.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This GUID is the file name. It is used to uniquely identify the file.
comment|///
name|EFI_GUID
name|Name
decl_stmt|;
comment|///
comment|/// Used to verify the integrity of the file.
comment|///
name|EFI_FFS_INTEGRITY_CHECK
name|IntegrityCheck
decl_stmt|;
comment|///
comment|/// Identifies the type of file.
comment|///
name|EFI_FV_FILETYPE
name|Type
decl_stmt|;
comment|///
comment|/// Declares various file attribute bits.
comment|///
name|EFI_FFS_FILE_ATTRIBUTES
name|Attributes
decl_stmt|;
comment|///
comment|/// The length of the file in bytes, including the FFS header.
comment|///
name|UINT8
name|Size
index|[
literal|3
index|]
decl_stmt|;
comment|///
comment|/// Used to track the state of the file throughout the life of the file from creation to deletion.
comment|///
name|EFI_FFS_FILE_STATE
name|State
decl_stmt|;
block|}
name|EFI_FFS_FILE_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This GUID is the file name. It is used to uniquely identify the file. There may be only
comment|/// one instance of a file with the file name GUID of Name in any given firmware
comment|/// volume, except if the file type is EFI_FV_FILETYPE_FFS_PAD.
comment|///
name|EFI_GUID
name|Name
decl_stmt|;
comment|///
comment|/// Used to verify the integrity of the file.
comment|///
name|EFI_FFS_INTEGRITY_CHECK
name|IntegrityCheck
decl_stmt|;
comment|///
comment|/// Identifies the type of file.
comment|///
name|EFI_FV_FILETYPE
name|Type
decl_stmt|;
comment|///
comment|/// Declares various file attribute bits.
comment|///
name|EFI_FFS_FILE_ATTRIBUTES
name|Attributes
decl_stmt|;
comment|///
comment|/// The length of the file in bytes, including the FFS header.
comment|/// The length of the file data is either (Size - sizeof(EFI_FFS_FILE_HEADER)). This calculation means a
comment|/// zero-length file has a Size of 24 bytes, which is sizeof(EFI_FFS_FILE_HEADER).
comment|/// Size is not required to be a multiple of 8 bytes. Given a file F, the next file header is
comment|/// located at the next 8-byte aligned firmware volume offset following the last byte of the file F.
comment|///
name|UINT8
name|Size
index|[
literal|3
index|]
decl_stmt|;
comment|///
comment|/// Used to track the state of the file throughout the life of the file from creation to deletion.
comment|///
name|EFI_FFS_FILE_STATE
name|State
decl_stmt|;
comment|///
comment|/// If FFS_ATTRIB_LARGE_FILE is set in Attributes, then ExtendedSize exists and Size must be set to zero.
comment|/// If FFS_ATTRIB_LARGE_FILE is not set then EFI_FFS_FILE_HEADER is used.
comment|///
name|UINT64
name|ExtendedSize
decl_stmt|;
block|}
name|EFI_FFS_FILE_HEADER2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IS_FFS_FILE2
parameter_list|(
name|FfsFileHeaderPtr
parameter_list|)
define|\
value|(((((EFI_FFS_FILE_HEADER *) (UINTN) FfsFileHeaderPtr)->Attributes)& FFS_ATTRIB_LARGE_FILE) == FFS_ATTRIB_LARGE_FILE)
end_define

begin_define
define|#
directive|define
name|FFS_FILE_SIZE
parameter_list|(
name|FfsFileHeaderPtr
parameter_list|)
define|\
value|((UINT32) (*((UINT32 *) ((EFI_FFS_FILE_HEADER *) (UINTN) FfsFileHeaderPtr)->Size)& 0x00ffffff))
end_define

begin_define
define|#
directive|define
name|FFS_FILE2_SIZE
parameter_list|(
name|FfsFileHeaderPtr
parameter_list|)
define|\
value|((UINT32) (((EFI_FFS_FILE_HEADER2 *) (UINTN) FfsFileHeaderPtr)->ExtendedSize))
end_define

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SECTION_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Pseudo type. It is used as a wild card when retrieving sections.
end_comment

begin_comment
comment|///  The section type EFI_SECTION_ALL matches all section types.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SECTION_ALL
value|0x00
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Encapsulation section Type values.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SECTION_COMPRESSION
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_GUID_DEFINED
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_DISPOSABLE
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Leaf section Type values.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SECTION_PE32
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_PIC
value|0x11
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_TE
value|0x12
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_DXE_DEPEX
value|0x13
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_VERSION
value|0x14
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_USER_INTERFACE
value|0x15
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_COMPATIBILITY16
value|0x16
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_FIRMWARE_VOLUME_IMAGE
value|0x17
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_FREEFORM_SUBTYPE_GUID
value|0x18
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_RAW
value|0x19
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_PEI_DEPEX
value|0x1B
end_define

begin_define
define|#
directive|define
name|EFI_SECTION_SMM_DEPEX
value|0x1C
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Common section header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// A 24-bit unsigned integer that contains the total size of the section in bytes,
comment|/// including the EFI_COMMON_SECTION_HEADER.
comment|///
name|UINT8
name|Size
index|[
literal|3
index|]
decl_stmt|;
name|EFI_SECTION_TYPE
name|Type
decl_stmt|;
comment|///
comment|/// Declares the section type.
comment|///
block|}
name|EFI_COMMON_SECTION_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// A 24-bit unsigned integer that contains the total size of the section in bytes,
comment|/// including the EFI_COMMON_SECTION_HEADER.
comment|///
name|UINT8
name|Size
index|[
literal|3
index|]
decl_stmt|;
name|EFI_SECTION_TYPE
name|Type
decl_stmt|;
comment|///
comment|/// If Size is 0xFFFFFF, then ExtendedSize contains the size of the section. If
comment|/// Size is not equal to 0xFFFFFF, then this field does not exist.
comment|///
name|UINT32
name|ExtendedSize
decl_stmt|;
block|}
name|EFI_COMMON_SECTION_HEADER2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Leaf section type that contains an
end_comment

begin_comment
comment|/// IA-32 16-bit executable image.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER
name|EFI_COMPATIBILITY16_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER2
name|EFI_COMPATIBILITY16_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// CompressionType of EFI_COMPRESSION_SECTION.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_NOT_COMPRESSED
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_STANDARD_COMPRESSION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// An encapsulation section type in which the
end_comment

begin_comment
comment|/// section data is compressed.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Usual common section header. CommonHeader.Type = EFI_SECTION_COMPRESSION.
comment|///
name|EFI_COMMON_SECTION_HEADER
name|CommonHeader
decl_stmt|;
comment|///
comment|/// The UINT32 that indicates the size of the section data after decompression.
comment|///
name|UINT32
name|UncompressedLength
decl_stmt|;
comment|///
comment|/// Indicates which compression algorithm is used.
comment|///
name|UINT8
name|CompressionType
decl_stmt|;
block|}
name|EFI_COMPRESSION_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Usual common section header. CommonHeader.Type = EFI_SECTION_COMPRESSION.
comment|///
name|EFI_COMMON_SECTION_HEADER2
name|CommonHeader
decl_stmt|;
comment|///
comment|/// UINT32 that indicates the size of the section data after decompression.
comment|///
name|UINT32
name|UncompressedLength
decl_stmt|;
comment|///
comment|/// Indicates which compression algorithm is used.
comment|///
name|UINT8
name|CompressionType
decl_stmt|;
block|}
name|EFI_COMPRESSION_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// An encapsulation section type in which the section data is disposable.
end_comment

begin_comment
comment|/// A disposable section is an encapsulation section in which the section data may be disposed of during
end_comment

begin_comment
comment|/// the process of creating or updating a firmware image without significant impact on the usefulness of
end_comment

begin_comment
comment|/// the file. The Type field in the section header is set to EFI_SECTION_DISPOSABLE. This
end_comment

begin_comment
comment|/// allows optional or descriptive data to be included with the firmware file which can be removed in
end_comment

begin_comment
comment|/// order to conserve space. The contents of this section are implementation specific, but might contain
end_comment

begin_comment
comment|/// debug data or detailed integration instructions.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER
name|EFI_DISPOSABLE_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER2
name|EFI_DISPOSABLE_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The leaf section which could be used to determine the dispatch order of DXEs.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER
name|EFI_DXE_DEPEX_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER2
name|EFI_DXE_DEPEX_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The leaf section which contains a PI FV.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER
name|EFI_FIRMWARE_VOLUME_IMAGE_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER2
name|EFI_FIRMWARE_VOLUME_IMAGE_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The leaf section which contains a single GUID.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Common section header. CommonHeader.Type = EFI_SECTION_FREEFORM_SUBTYPE_GUID.
comment|///
name|EFI_COMMON_SECTION_HEADER
name|CommonHeader
decl_stmt|;
comment|///
comment|/// This GUID is defined by the creator of the file. It is a vendor-defined file type.
comment|///
name|EFI_GUID
name|SubTypeGuid
decl_stmt|;
block|}
name|EFI_FREEFORM_SUBTYPE_GUID_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The common section header. CommonHeader.Type = EFI_SECTION_FREEFORM_SUBTYPE_GUID.
comment|///
name|EFI_COMMON_SECTION_HEADER2
name|CommonHeader
decl_stmt|;
comment|///
comment|/// This GUID is defined by the creator of the file. It is a vendor-defined file type.
comment|///
name|EFI_GUID
name|SubTypeGuid
decl_stmt|;
block|}
name|EFI_FREEFORM_SUBTYPE_GUID_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Attributes of EFI_GUID_DEFINED_SECTION.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_GUIDED_SECTION_PROCESSING_REQUIRED
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_GUIDED_SECTION_AUTH_STATUS_VALID
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The leaf section which is encapsulation defined by specific GUID.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The common section header. CommonHeader.Type = EFI_SECTION_GUID_DEFINED.
comment|///
name|EFI_COMMON_SECTION_HEADER
name|CommonHeader
decl_stmt|;
comment|///
comment|/// The GUID that defines the format of the data that follows. It is a vendor-defined section type.
comment|///
name|EFI_GUID
name|SectionDefinitionGuid
decl_stmt|;
comment|///
comment|/// Contains the offset in bytes from the beginning of the common header to the first byte of the data.
comment|///
name|UINT16
name|DataOffset
decl_stmt|;
comment|///
comment|/// The bit field that declares some specific characteristics of the section contents.
comment|///
name|UINT16
name|Attributes
decl_stmt|;
block|}
name|EFI_GUID_DEFINED_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The common section header. CommonHeader.Type = EFI_SECTION_GUID_DEFINED.
comment|///
name|EFI_COMMON_SECTION_HEADER2
name|CommonHeader
decl_stmt|;
comment|///
comment|/// The GUID that defines the format of the data that follows. It is a vendor-defined section type.
comment|///
name|EFI_GUID
name|SectionDefinitionGuid
decl_stmt|;
comment|///
comment|/// Contains the offset in bytes from the beginning of the common header to the first byte of the data.
comment|///
name|UINT16
name|DataOffset
decl_stmt|;
comment|///
comment|/// The bit field that declares some specific characteristics of the section contents.
comment|///
name|UINT16
name|Attributes
decl_stmt|;
block|}
name|EFI_GUID_DEFINED_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The leaf section which contains PE32+ image.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER
name|EFI_PE32_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER2
name|EFI_PE32_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The leaf section used to determine the dispatch order of PEIMs.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER
name|EFI_PEI_DEPEX_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER2
name|EFI_PEI_DEPEX_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A leaf section type that contains a position-independent-code (PIC) image.
end_comment

begin_comment
comment|/// A PIC image section is a leaf section that contains a position-independent-code (PIC) image.
end_comment

begin_comment
comment|/// In addition to normal PE32+ images that contain relocation information, PEIM executables may be
end_comment

begin_comment
comment|/// PIC and are referred to as PIC images. A PIC image is the same as a PE32+ image except that all
end_comment

begin_comment
comment|/// relocation information has been stripped from the image and the image can be moved and will
end_comment

begin_comment
comment|/// execute correctly without performing any relocation or other fix-ups. EFI_PIC_SECTION2 must
end_comment

begin_comment
comment|/// be used if the section is 16MB or larger.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER
name|EFI_PIC_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER2
name|EFI_PIC_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The leaf section which constains the position-independent-code image.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER
name|EFI_TE_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER2
name|EFI_TE_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The leaf section which contains an array of zero or more bytes.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER
name|EFI_RAW_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER2
name|EFI_RAW_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The SMM dependency expression section is a leaf section that contains a dependency expression that
end_comment

begin_comment
comment|/// is used to determine the dispatch order for SMM drivers. Before the SMRAM invocation of the
end_comment

begin_comment
comment|/// SMM driver's entry point, this dependency expression must evaluate to TRUE. See the Platform
end_comment

begin_comment
comment|/// Initialization Specification, Volume 2, for details regarding the format of the dependency expression.
end_comment

begin_comment
comment|/// The dependency expression may refer to protocols installed in either the UEFI or the SMM protocol
end_comment

begin_comment
comment|/// database. EFI_SMM_DEPEX_SECTION2 must be used if the section is 16MB or larger.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER
name|EFI_SMM_DEPEX_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_COMMON_SECTION_HEADER2
name|EFI_SMM_DEPEX_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The leaf section which contains a unicode string that
end_comment

begin_comment
comment|/// is human readable file name.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_COMMON_SECTION_HEADER
name|CommonHeader
decl_stmt|;
comment|///
comment|/// Array of unicode string.
comment|///
name|CHAR16
name|FileNameString
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_USER_INTERFACE_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_COMMON_SECTION_HEADER2
name|CommonHeader
decl_stmt|;
name|CHAR16
name|FileNameString
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_USER_INTERFACE_SECTION2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The leaf section which contains a numeric build number and
end_comment

begin_comment
comment|/// an optional unicode string that represents the file revision.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_COMMON_SECTION_HEADER
name|CommonHeader
decl_stmt|;
name|UINT16
name|BuildNumber
decl_stmt|;
comment|///
comment|/// Array of unicode string.
comment|///
name|CHAR16
name|VersionString
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_VERSION_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_COMMON_SECTION_HEADER2
name|CommonHeader
decl_stmt|;
comment|///
comment|/// A UINT16 that represents a particular build. Subsequent builds have monotonically
comment|/// increasing build numbers relative to earlier builds.
comment|///
name|UINT16
name|BuildNumber
decl_stmt|;
name|CHAR16
name|VersionString
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_VERSION_SECTION2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IS_SECTION2
parameter_list|(
name|SectionHeaderPtr
parameter_list|)
define|\
value|((UINT32) (*((UINT32 *) ((EFI_COMMON_SECTION_HEADER *) (UINTN) SectionHeaderPtr)->Size)& 0x00ffffff) == 0x00ffffff)
end_define

begin_define
define|#
directive|define
name|SECTION_SIZE
parameter_list|(
name|SectionHeaderPtr
parameter_list|)
define|\
value|((UINT32) (*((UINT32 *) ((EFI_COMMON_SECTION_HEADER *) (UINTN) SectionHeaderPtr)->Size)& 0x00ffffff))
end_define

begin_define
define|#
directive|define
name|SECTION2_SIZE
parameter_list|(
name|SectionHeaderPtr
parameter_list|)
define|\
value|(((EFI_COMMON_SECTION_HEADER2 *) (UINTN) SectionHeaderPtr)->ExtendedSize)
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

