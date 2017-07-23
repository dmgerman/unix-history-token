begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AMDGPUCodeObjectMetadata.h -----------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief AMDGPU Code Object Metadata definitions and in-memory
end_comment

begin_comment
comment|/// representations.
end_comment

begin_comment
comment|///
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
name|LLVM_SUPPORT_AMDGPUCODEOBJECTMETADATA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_AMDGPUCODEOBJECTMETADATA_H
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|AMDGPU
block|{
comment|//===----------------------------------------------------------------------===//
comment|// Code Object Metadata.
comment|//===----------------------------------------------------------------------===//
name|namespace
name|CodeObject
block|{
comment|/// \brief Code object metadata major version.
name|constexpr
name|uint32_t
name|MetadataVersionMajor
init|=
literal|1
decl_stmt|;
comment|/// \brief Code object metadata minor version.
name|constexpr
name|uint32_t
name|MetadataVersionMinor
init|=
literal|0
decl_stmt|;
comment|/// \brief Code object metadata beginning assembler directive.
name|constexpr
name|char
name|MetadataAssemblerDirectiveBegin
index|[]
init|=
literal|".amdgpu_code_object_metadata"
decl_stmt|;
comment|/// \brief Code object metadata ending assembler directive.
name|constexpr
name|char
name|MetadataAssemblerDirectiveEnd
index|[]
init|=
literal|".end_amdgpu_code_object_metadata"
decl_stmt|;
comment|/// \brief Access qualifiers.
name|enum
name|class
name|AccessQualifier
range|:
name|uint8_t
block|{
name|Default
operator|=
literal|0
block|,
name|ReadOnly
operator|=
literal|1
block|,
name|WriteOnly
operator|=
literal|2
block|,
name|ReadWrite
operator|=
literal|3
block|,
name|Unknown
operator|=
literal|0xff
block|}
decl_stmt|;
comment|/// \brief Address space qualifiers.
name|enum
name|class
name|AddressSpaceQualifier
range|:
name|uint8_t
block|{
name|Private
operator|=
literal|0
block|,
name|Global
operator|=
literal|1
block|,
name|Constant
operator|=
literal|2
block|,
name|Local
operator|=
literal|3
block|,
name|Generic
operator|=
literal|4
block|,
name|Region
operator|=
literal|5
block|,
name|Unknown
operator|=
literal|0xff
block|}
decl_stmt|;
comment|/// \brief Value kinds.
name|enum
name|class
name|ValueKind
range|:
name|uint8_t
block|{
name|ByValue
operator|=
literal|0
block|,
name|GlobalBuffer
operator|=
literal|1
block|,
name|DynamicSharedPointer
operator|=
literal|2
block|,
name|Sampler
operator|=
literal|3
block|,
name|Image
operator|=
literal|4
block|,
name|Pipe
operator|=
literal|5
block|,
name|Queue
operator|=
literal|6
block|,
name|HiddenGlobalOffsetX
operator|=
literal|7
block|,
name|HiddenGlobalOffsetY
operator|=
literal|8
block|,
name|HiddenGlobalOffsetZ
operator|=
literal|9
block|,
name|HiddenNone
operator|=
literal|10
block|,
name|HiddenPrintfBuffer
operator|=
literal|11
block|,
name|HiddenDefaultQueue
operator|=
literal|12
block|,
name|HiddenCompletionAction
operator|=
literal|13
block|,
name|Unknown
operator|=
literal|0xff
block|}
decl_stmt|;
comment|/// \brief Value types.
name|enum
name|class
name|ValueType
range|:
name|uint8_t
block|{
name|Struct
operator|=
literal|0
block|,
name|I8
operator|=
literal|1
block|,
name|U8
operator|=
literal|2
block|,
name|I16
operator|=
literal|3
block|,
name|U16
operator|=
literal|4
block|,
name|F16
operator|=
literal|5
block|,
name|I32
operator|=
literal|6
block|,
name|U32
operator|=
literal|7
block|,
name|F32
operator|=
literal|8
block|,
name|I64
operator|=
literal|9
block|,
name|U64
operator|=
literal|10
block|,
name|F64
operator|=
literal|11
block|,
name|Unknown
operator|=
literal|0xff
block|}
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// Kernel Metadata.
comment|//===----------------------------------------------------------------------===//
name|namespace
name|Kernel
block|{
comment|//===----------------------------------------------------------------------===//
comment|// Kernel Attributes Metadata.
comment|//===----------------------------------------------------------------------===//
name|namespace
name|Attrs
block|{
name|namespace
name|Key
block|{
comment|/// \brief Key for Kernel::Attr::Metadata::mReqdWorkGroupSize.
name|constexpr
name|char
name|ReqdWorkGroupSize
index|[]
init|=
literal|"ReqdWorkGroupSize"
decl_stmt|;
comment|/// \brief Key for Kernel::Attr::Metadata::mWorkGroupSizeHint.
name|constexpr
name|char
name|WorkGroupSizeHint
index|[]
init|=
literal|"WorkGroupSizeHint"
decl_stmt|;
comment|/// \brief Key for Kernel::Attr::Metadata::mVecTypeHint.
name|constexpr
name|char
name|VecTypeHint
index|[]
init|=
literal|"VecTypeHint"
decl_stmt|;
block|}
comment|// end namespace Key
comment|/// \brief In-memory representation of kernel attributes metadata.
struct|struct
name|Metadata
name|final
block|{
comment|/// \brief 'reqd_work_group_size' attribute. Optional.
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|mReqdWorkGroupSize
operator|=
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|(
operator|)
expr_stmt|;
comment|/// \brief 'work_group_size_hint' attribute. Optional.
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|mWorkGroupSizeHint
operator|=
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|(
operator|)
expr_stmt|;
comment|/// \brief 'vec_type_hint' attribute. Optional.
name|std
operator|::
name|string
name|mVecTypeHint
operator|=
name|std
operator|::
name|string
argument_list|()
expr_stmt|;
comment|/// \brief Default constructor.
name|Metadata
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \returns True if kernel attributes metadata is empty, false otherwise.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|mReqdWorkGroupSize
operator|.
name|empty
argument_list|()
operator|&&
name|mWorkGroupSizeHint
operator|.
name|empty
argument_list|()
operator|&&
name|mVecTypeHint
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \returns True if kernel attributes metadata is not empty, false otherwise.
name|bool
name|notEmpty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|empty
argument_list|()
return|;
block|}
block|}
struct|;
block|}
comment|// end namespace Attrs
comment|//===----------------------------------------------------------------------===//
comment|// Kernel Argument Metadata.
comment|//===----------------------------------------------------------------------===//
name|namespace
name|Arg
block|{
name|namespace
name|Key
block|{
comment|/// \brief Key for Kernel::Arg::Metadata::mSize.
name|constexpr
name|char
name|Size
index|[]
init|=
literal|"Size"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mAlign.
name|constexpr
name|char
name|Align
index|[]
init|=
literal|"Align"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mValueKind.
name|constexpr
name|char
name|ValueKind
index|[]
init|=
literal|"ValueKind"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mValueType.
name|constexpr
name|char
name|ValueType
index|[]
init|=
literal|"ValueType"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mPointeeAlign.
name|constexpr
name|char
name|PointeeAlign
index|[]
init|=
literal|"PointeeAlign"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mAccQual.
name|constexpr
name|char
name|AccQual
index|[]
init|=
literal|"AccQual"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mAddrSpaceQual.
name|constexpr
name|char
name|AddrSpaceQual
index|[]
init|=
literal|"AddrSpaceQual"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mIsConst.
name|constexpr
name|char
name|IsConst
index|[]
init|=
literal|"IsConst"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mIsPipe.
name|constexpr
name|char
name|IsPipe
index|[]
init|=
literal|"IsPipe"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mIsRestrict.
name|constexpr
name|char
name|IsRestrict
index|[]
init|=
literal|"IsRestrict"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mIsVolatile.
name|constexpr
name|char
name|IsVolatile
index|[]
init|=
literal|"IsVolatile"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mName.
name|constexpr
name|char
name|Name
index|[]
init|=
literal|"Name"
decl_stmt|;
comment|/// \brief Key for Kernel::Arg::Metadata::mTypeName.
name|constexpr
name|char
name|TypeName
index|[]
init|=
literal|"TypeName"
decl_stmt|;
block|}
comment|// end namespace Key
comment|/// \brief In-memory representation of kernel argument metadata.
struct|struct
name|Metadata
name|final
block|{
comment|/// \brief Size in bytes. Required.
name|uint32_t
name|mSize
init|=
literal|0
decl_stmt|;
comment|/// \brief Alignment in bytes. Required.
name|uint32_t
name|mAlign
init|=
literal|0
decl_stmt|;
comment|/// \brief Value kind. Required.
name|ValueKind
name|mValueKind
init|=
name|ValueKind
operator|::
name|Unknown
decl_stmt|;
comment|/// \brief Value type. Required.
name|ValueType
name|mValueType
init|=
name|ValueType
operator|::
name|Unknown
decl_stmt|;
comment|/// \brief Pointee alignment in bytes. Optional.
name|uint32_t
name|mPointeeAlign
init|=
literal|0
decl_stmt|;
comment|/// \brief Access qualifier. Optional.
name|AccessQualifier
name|mAccQual
init|=
name|AccessQualifier
operator|::
name|Unknown
decl_stmt|;
comment|/// \brief Address space qualifier. Optional.
name|AddressSpaceQualifier
name|mAddrSpaceQual
init|=
name|AddressSpaceQualifier
operator|::
name|Unknown
decl_stmt|;
comment|/// \brief True if 'const' qualifier is specified. Optional.
name|bool
name|mIsConst
init|=
name|false
decl_stmt|;
comment|/// \brief True if 'pipe' qualifier is specified. Optional.
name|bool
name|mIsPipe
init|=
name|false
decl_stmt|;
comment|/// \brief True if 'restrict' qualifier is specified. Optional.
name|bool
name|mIsRestrict
init|=
name|false
decl_stmt|;
comment|/// \brief True if 'volatile' qualifier is specified. Optional.
name|bool
name|mIsVolatile
init|=
name|false
decl_stmt|;
comment|/// \brief Name. Optional.
name|std
operator|::
name|string
name|mName
operator|=
name|std
operator|::
name|string
argument_list|()
expr_stmt|;
comment|/// \brief Type name. Optional.
name|std
operator|::
name|string
name|mTypeName
operator|=
name|std
operator|::
name|string
argument_list|()
expr_stmt|;
comment|/// \brief Default constructor.
name|Metadata
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
struct|;
block|}
comment|// end namespace Arg
comment|//===----------------------------------------------------------------------===//
comment|// Kernel Code Properties Metadata.
comment|//===----------------------------------------------------------------------===//
name|namespace
name|CodeProps
block|{
name|namespace
name|Key
block|{
comment|/// \brief Key for Kernel::CodeProps::Metadata::mKernargSegmentSize.
name|constexpr
name|char
name|KernargSegmentSize
index|[]
init|=
literal|"KernargSegmentSize"
decl_stmt|;
comment|/// \brief Key for Kernel::CodeProps::Metadata::mWorkgroupGroupSegmentSize.
name|constexpr
name|char
name|WorkgroupGroupSegmentSize
index|[]
init|=
literal|"WorkgroupGroupSegmentSize"
decl_stmt|;
comment|/// \brief Key for Kernel::CodeProps::Metadata::mWorkitemPrivateSegmentSize.
name|constexpr
name|char
name|WorkitemPrivateSegmentSize
index|[]
init|=
literal|"WorkitemPrivateSegmentSize"
decl_stmt|;
comment|/// \brief Key for Kernel::CodeProps::Metadata::mWavefrontNumSGPRs.
name|constexpr
name|char
name|WavefrontNumSGPRs
index|[]
init|=
literal|"WavefrontNumSGPRs"
decl_stmt|;
comment|/// \brief Key for Kernel::CodeProps::Metadata::mWorkitemNumVGPRs.
name|constexpr
name|char
name|WorkitemNumVGPRs
index|[]
init|=
literal|"WorkitemNumVGPRs"
decl_stmt|;
comment|/// \brief Key for Kernel::CodeProps::Metadata::mKernargSegmentAlign.
name|constexpr
name|char
name|KernargSegmentAlign
index|[]
init|=
literal|"KernargSegmentAlign"
decl_stmt|;
comment|/// \brief Key for Kernel::CodeProps::Metadata::mGroupSegmentAlign.
name|constexpr
name|char
name|GroupSegmentAlign
index|[]
init|=
literal|"GroupSegmentAlign"
decl_stmt|;
comment|/// \brief Key for Kernel::CodeProps::Metadata::mPrivateSegmentAlign.
name|constexpr
name|char
name|PrivateSegmentAlign
index|[]
init|=
literal|"PrivateSegmentAlign"
decl_stmt|;
comment|/// \brief Key for Kernel::CodeProps::Metadata::mWavefrontSize.
name|constexpr
name|char
name|WavefrontSize
index|[]
init|=
literal|"WavefrontSize"
decl_stmt|;
block|}
comment|// end namespace Key
comment|/// \brief In-memory representation of kernel code properties metadata.
struct|struct
name|Metadata
name|final
block|{
comment|/// \brief Size in bytes of the kernarg segment memory. Kernarg segment memory
comment|/// holds the values of the arguments to the kernel. Optional.
name|uint64_t
name|mKernargSegmentSize
init|=
literal|0
decl_stmt|;
comment|/// \brief Size in bytes of the group segment memory required by a workgroup.
comment|/// This value does not include any dynamically allocated group segment memory
comment|/// that may be added when the kernel is dispatched. Optional.
name|uint32_t
name|mWorkgroupGroupSegmentSize
init|=
literal|0
decl_stmt|;
comment|/// \brief Size in bytes of the private segment memory required by a workitem.
comment|/// Private segment memory includes arg, spill and private segments. Optional.
name|uint32_t
name|mWorkitemPrivateSegmentSize
init|=
literal|0
decl_stmt|;
comment|/// \brief Total number of SGPRs used by a wavefront. Optional.
name|uint16_t
name|mWavefrontNumSGPRs
init|=
literal|0
decl_stmt|;
comment|/// \brief Total number of VGPRs used by a workitem. Optional.
name|uint16_t
name|mWorkitemNumVGPRs
init|=
literal|0
decl_stmt|;
comment|/// \brief Maximum byte alignment of variables used by the kernel in the
comment|/// kernarg memory segment. Expressed as a power of two. Optional.
name|uint8_t
name|mKernargSegmentAlign
init|=
literal|0
decl_stmt|;
comment|/// \brief Maximum byte alignment of variables used by the kernel in the
comment|/// group memory segment. Expressed as a power of two. Optional.
name|uint8_t
name|mGroupSegmentAlign
init|=
literal|0
decl_stmt|;
comment|/// \brief Maximum byte alignment of variables used by the kernel in the
comment|/// private memory segment. Expressed as a power of two. Optional.
name|uint8_t
name|mPrivateSegmentAlign
init|=
literal|0
decl_stmt|;
comment|/// \brief Wavefront size. Expressed as a power of two. Optional.
name|uint8_t
name|mWavefrontSize
init|=
literal|0
decl_stmt|;
comment|/// \brief Default constructor.
name|Metadata
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \returns True if kernel code properties metadata is empty, false
comment|/// otherwise.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|notEmpty
argument_list|()
return|;
block|}
comment|/// \returns True if kernel code properties metadata is not empty, false
comment|/// otherwise.
name|bool
name|notEmpty
argument_list|()
specifier|const
block|{
return|return
name|mKernargSegmentSize
operator|||
name|mWorkgroupGroupSegmentSize
operator|||
name|mWorkitemPrivateSegmentSize
operator|||
name|mWavefrontNumSGPRs
operator|||
name|mWorkitemNumVGPRs
operator|||
name|mKernargSegmentAlign
operator|||
name|mGroupSegmentAlign
operator|||
name|mPrivateSegmentAlign
operator|||
name|mWavefrontSize
return|;
block|}
block|}
struct|;
block|}
comment|// end namespace CodeProps
comment|//===----------------------------------------------------------------------===//
comment|// Kernel Debug Properties Metadata.
comment|//===----------------------------------------------------------------------===//
name|namespace
name|DebugProps
block|{
name|namespace
name|Key
block|{
comment|/// \brief Key for Kernel::DebugProps::Metadata::mDebuggerABIVersion.
name|constexpr
name|char
name|DebuggerABIVersion
index|[]
init|=
literal|"DebuggerABIVersion"
decl_stmt|;
comment|/// \brief Key for Kernel::DebugProps::Metadata::mReservedNumVGPRs.
name|constexpr
name|char
name|ReservedNumVGPRs
index|[]
init|=
literal|"ReservedNumVGPRs"
decl_stmt|;
comment|/// \brief Key for Kernel::DebugProps::Metadata::mReservedFirstVGPR.
name|constexpr
name|char
name|ReservedFirstVGPR
index|[]
init|=
literal|"ReservedFirstVGPR"
decl_stmt|;
comment|/// \brief Key for Kernel::DebugProps::Metadata::mPrivateSegmentBufferSGPR.
name|constexpr
name|char
name|PrivateSegmentBufferSGPR
index|[]
init|=
literal|"PrivateSegmentBufferSGPR"
decl_stmt|;
comment|/// \brief Key for
comment|///     Kernel::DebugProps::Metadata::mWavefrontPrivateSegmentOffsetSGPR.
name|constexpr
name|char
name|WavefrontPrivateSegmentOffsetSGPR
index|[]
init|=
literal|"WavefrontPrivateSegmentOffsetSGPR"
decl_stmt|;
block|}
comment|// end namespace Key
comment|/// \brief In-memory representation of kernel debug properties metadata.
struct|struct
name|Metadata
name|final
block|{
comment|/// \brief Debugger ABI version. Optional.
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|mDebuggerABIVersion
operator|=
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|(
operator|)
expr_stmt|;
comment|/// \brief Consecutive number of VGPRs reserved for debugger use. Must be 0 if
comment|/// mDebuggerABIVersion is not set. Optional.
name|uint16_t
name|mReservedNumVGPRs
init|=
literal|0
decl_stmt|;
comment|/// \brief First fixed VGPR reserved. Must be uint16_t(-1) if
comment|/// mDebuggerABIVersion is not set or mReservedFirstVGPR is 0. Optional.
name|uint16_t
name|mReservedFirstVGPR
init|=
name|uint16_t
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
comment|/// \brief Fixed SGPR of the first of 4 SGPRs used to hold the scratch V# used
comment|/// for the entire kernel execution. Must be uint16_t(-1) if
comment|/// mDebuggerABIVersion is not set or SGPR not used or not known. Optional.
name|uint16_t
name|mPrivateSegmentBufferSGPR
init|=
name|uint16_t
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
comment|/// \brief Fixed SGPR used to hold the wave scratch offset for the entire
comment|/// kernel execution. Must be uint16_t(-1) if mDebuggerABIVersion is not set
comment|/// or SGPR is not used or not known. Optional.
name|uint16_t
name|mWavefrontPrivateSegmentOffsetSGPR
init|=
name|uint16_t
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
comment|/// \brief Default constructor.
name|Metadata
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \returns True if kernel debug properties metadata is empty, false
comment|/// otherwise.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|notEmpty
argument_list|()
return|;
block|}
comment|/// \returns True if kernel debug properties metadata is not empty, false
comment|/// otherwise.
name|bool
name|notEmpty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|mDebuggerABIVersion
operator|.
name|empty
argument_list|()
return|;
block|}
block|}
struct|;
block|}
comment|// end namespace DebugProps
name|namespace
name|Key
block|{
comment|/// \brief Key for Kernel::Metadata::mName.
name|constexpr
name|char
name|Name
index|[]
init|=
literal|"Name"
decl_stmt|;
comment|/// \brief Key for Kernel::Metadata::mLanguage.
name|constexpr
name|char
name|Language
index|[]
init|=
literal|"Language"
decl_stmt|;
comment|/// \brief Key for Kernel::Metadata::mLanguageVersion.
name|constexpr
name|char
name|LanguageVersion
index|[]
init|=
literal|"LanguageVersion"
decl_stmt|;
comment|/// \brief Key for Kernel::Metadata::mAttrs.
name|constexpr
name|char
name|Attrs
index|[]
init|=
literal|"Attrs"
decl_stmt|;
comment|/// \brief Key for Kernel::Metadata::mArgs.
name|constexpr
name|char
name|Args
index|[]
init|=
literal|"Args"
decl_stmt|;
comment|/// \brief Key for Kernel::Metadata::mCodeProps.
name|constexpr
name|char
name|CodeProps
index|[]
init|=
literal|"CodeProps"
decl_stmt|;
comment|/// \brief Key for Kernel::Metadata::mDebugProps.
name|constexpr
name|char
name|DebugProps
index|[]
init|=
literal|"DebugProps"
decl_stmt|;
block|}
comment|// end namespace Key
comment|/// \brief In-memory representation of kernel metadata.
struct|struct
name|Metadata
name|final
block|{
comment|/// \brief Name. Required.
name|std
operator|::
name|string
name|mName
operator|=
name|std
operator|::
name|string
argument_list|()
expr_stmt|;
comment|/// \brief Language. Optional.
name|std
operator|::
name|string
name|mLanguage
operator|=
name|std
operator|::
name|string
argument_list|()
expr_stmt|;
comment|/// \brief Language version. Optional.
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|mLanguageVersion
operator|=
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|(
operator|)
expr_stmt|;
comment|/// \brief Attributes metadata. Optional.
name|Attrs
operator|::
name|Metadata
name|mAttrs
operator|=
name|Attrs
operator|::
name|Metadata
argument_list|()
expr_stmt|;
comment|/// \brief Arguments metadata. Optional.
name|std
operator|::
name|vector
operator|<
name|Arg
operator|::
name|Metadata
operator|>
name|mArgs
operator|=
name|std
operator|::
name|vector
operator|<
name|Arg
operator|::
name|Metadata
operator|>
operator|(
operator|)
expr_stmt|;
comment|/// \brief Code properties metadata. Optional.
name|CodeProps
operator|::
name|Metadata
name|mCodeProps
operator|=
name|CodeProps
operator|::
name|Metadata
argument_list|()
expr_stmt|;
comment|/// \brief Debug properties metadata. Optional.
name|DebugProps
operator|::
name|Metadata
name|mDebugProps
operator|=
name|DebugProps
operator|::
name|Metadata
argument_list|()
expr_stmt|;
comment|/// \brief Default constructor.
name|Metadata
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
struct|;
block|}
comment|// end namespace Kernel
name|namespace
name|Key
block|{
comment|/// \brief Key for CodeObject::Metadata::mVersion.
name|constexpr
name|char
name|Version
index|[]
init|=
literal|"Version"
decl_stmt|;
comment|/// \brief Key for CodeObject::Metadata::mPrintf.
name|constexpr
name|char
name|Printf
index|[]
init|=
literal|"Printf"
decl_stmt|;
comment|/// \brief Key for CodeObject::Metadata::mKernels.
name|constexpr
name|char
name|Kernels
index|[]
init|=
literal|"Kernels"
decl_stmt|;
block|}
comment|// end namespace Key
comment|/// \brief In-memory representation of code object metadata.
struct|struct
name|Metadata
name|final
block|{
comment|/// \brief Code object metadata version. Required.
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|mVersion
operator|=
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|(
operator|)
expr_stmt|;
comment|/// \brief Printf metadata. Optional.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|mPrintf
operator|=
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|(
operator|)
expr_stmt|;
comment|/// \brief Kernels metadata. Optional.
name|std
operator|::
name|vector
operator|<
name|Kernel
operator|::
name|Metadata
operator|>
name|mKernels
operator|=
name|std
operator|::
name|vector
operator|<
name|Kernel
operator|::
name|Metadata
operator|>
operator|(
operator|)
expr_stmt|;
comment|/// \brief Default constructor.
name|Metadata
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \brief Converts \p YamlString to \p CodeObjectMetadata.
specifier|static
name|std
operator|::
name|error_code
name|fromYamlString
argument_list|(
argument|std::string YamlString
argument_list|,
argument|Metadata&CodeObjectMetadata
argument_list|)
expr_stmt|;
comment|/// \brief Converts \p CodeObjectMetadata to \p YamlString.
specifier|static
name|std
operator|::
name|error_code
name|toYamlString
argument_list|(
argument|Metadata CodeObjectMetadata
argument_list|,
argument|std::string&YamlString
argument_list|)
expr_stmt|;
block|}
struct|;
block|}
comment|// end namespace CodeObject
block|}
comment|// end namespace AMDGPU
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
comment|// LLVM_SUPPORT_AMDGPUCODEOBJECTMETADATA_H
end_comment

end_unit

