begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RawConstants.h -------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_PDB_RAW_PDBRAWCONSTANTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_PDBRAWCONSTANTS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitmaskEnum.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
specifier|const
name|uint16_t
name|kInvalidStreamIndex
init|=
literal|0xFFFF
decl_stmt|;
enum|enum
name|PdbRaw_ImplVer
enum|:
name|uint32_t
block|{
name|PdbImplVC2
init|=
literal|19941610
block|,
name|PdbImplVC4
init|=
literal|19950623
block|,
name|PdbImplVC41
init|=
literal|19950814
block|,
name|PdbImplVC50
init|=
literal|19960307
block|,
name|PdbImplVC98
init|=
literal|19970604
block|,
name|PdbImplVC70Dep
init|=
literal|19990604
block|,
comment|// deprecated
name|PdbImplVC70
init|=
literal|20000404
block|,
name|PdbImplVC80
init|=
literal|20030901
block|,
name|PdbImplVC110
init|=
literal|20091201
block|,
name|PdbImplVC140
init|=
literal|20140508
block|, }
enum|;
name|enum
name|class
name|PdbRaw_FeatureSig
range|:
name|uint32_t
block|{
name|VC110
operator|=
name|PdbImplVC110
block|,
name|VC140
operator|=
name|PdbImplVC140
block|,
name|NoTypeMerge
operator|=
literal|0x4D544F4E
block|,
name|MinimalDebugInfo
operator|=
literal|0x494E494D
block|, }
decl_stmt|;
enum|enum
name|PdbRaw_Features
enum|:
name|uint32_t
block|{
name|PdbFeatureNone
init|=
literal|0x0
block|,
name|PdbFeatureContainsIdStream
init|=
literal|0x1
block|,
name|PdbFeatureMinimalDebugInfo
init|=
literal|0x2
block|,
name|PdbFeatureNoTypeMerging
init|=
literal|0x4
block|,
name|LLVM_MARK_AS_BITMASK_ENUM
argument_list|(
comment|/* LargestValue = */
argument|PdbFeatureNoTypeMerging
argument_list|)
block|}
enum|;
enum|enum
name|PdbRaw_DbiVer
enum|:
name|uint32_t
block|{
name|PdbDbiVC41
init|=
literal|930803
block|,
name|PdbDbiV50
init|=
literal|19960307
block|,
name|PdbDbiV60
init|=
literal|19970606
block|,
name|PdbDbiV70
init|=
literal|19990903
block|,
name|PdbDbiV110
init|=
literal|20091201
block|}
enum|;
enum|enum
name|PdbRaw_TpiVer
enum|:
name|uint32_t
block|{
name|PdbTpiV40
init|=
literal|19950410
block|,
name|PdbTpiV41
init|=
literal|19951122
block|,
name|PdbTpiV50
init|=
literal|19961031
block|,
name|PdbTpiV70
init|=
literal|19990903
block|,
name|PdbTpiV80
init|=
literal|20040203
block|, }
enum|;
enum|enum
name|PdbRaw_DbiSecContribVer
enum|:
name|uint32_t
block|{
name|DbiSecContribVer60
init|=
literal|0xeffe0000
operator|+
literal|19970605
block|,
name|DbiSecContribV2
init|=
literal|0xeffe0000
operator|+
literal|20140516
block|}
enum|;
enum|enum
name|SpecialStream
enum|:
name|uint32_t
block|{
comment|// Stream 0 contains the copy of previous version of the MSF directory.
comment|// We are not currently using it, but technically if we find the main
comment|// MSF is corrupted, we could fallback to it.
name|OldMSFDirectory
init|=
literal|0
block|,
name|StreamPDB
init|=
literal|1
block|,
name|StreamTPI
init|=
literal|2
block|,
name|StreamDBI
init|=
literal|3
block|,
name|StreamIPI
init|=
literal|4
block|,
name|kSpecialStreamCount
block|}
enum|;
name|enum
name|class
name|DbgHeaderType
range|:
name|uint16_t
block|{
name|FPO
block|,
name|Exception
block|,
name|Fixup
block|,
name|OmapToSrc
block|,
name|OmapFromSrc
block|,
name|SectionHdr
block|,
name|TokenRidMap
block|,
name|Xdata
block|,
name|Pdata
block|,
name|NewFPO
block|,
name|SectionHdrOrig
block|,
name|Max
block|}
decl_stmt|;
name|enum
name|class
name|OMFSegDescFlags
range|:
name|uint16_t
block|{
name|Read
operator|=
literal|1
operator|<<
literal|0
block|,
comment|// Segment is readable.
name|Write
operator|=
literal|1
operator|<<
literal|1
block|,
comment|// Segment is writable.
name|Execute
operator|=
literal|1
operator|<<
literal|2
block|,
comment|// Segment is executable.
name|AddressIs32Bit
operator|=
literal|1
operator|<<
literal|3
block|,
comment|// Descriptor describes a 32-bit linear address.
name|IsSelector
operator|=
literal|1
operator|<<
literal|8
block|,
comment|// Frame represents a selector.
name|IsAbsoluteAddress
operator|=
literal|1
operator|<<
literal|9
block|,
comment|// Frame represents an absolute address.
name|IsGroup
operator|=
literal|1
operator|<<
literal|10
comment|// If set, descriptor represents a group.
block|}
decl_stmt|;
block|}
comment|// end namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_RAW_PDBRAWCONSTANTS_H
end_comment

end_unit

