begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPURuntimeMetadata.h - AMDGPU Runtime Metadata -------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// Enums and structure types used by runtime metadata.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Runtime requests certain information (metadata) about kernels to be able
end_comment

begin_comment
comment|/// to execute the kernels and answer the queries about the kernels.
end_comment

begin_comment
comment|/// The metadata is represented as a note element in the .note ELF section of a
end_comment

begin_comment
comment|/// binary (code object). The desc field of the note element is a YAML string
end_comment

begin_comment
comment|/// consisting of key-value pairs. Each key is a string. Each value can be
end_comment

begin_comment
comment|/// an integer, a string, or an YAML sequence. There are 3 levels of YAML maps.
end_comment

begin_comment
comment|/// At the beginning of the YAML string is the module level YAML map. A
end_comment

begin_comment
comment|/// kernel-level YAML map is in the amd.Kernels sequence. A
end_comment

begin_comment
comment|/// kernel-argument-level map is in the amd.Args sequence.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The format should be kept backward compatible. New enum values and bit
end_comment

begin_comment
comment|/// fields should be appended at the end. It is suggested to bump up the
end_comment

begin_comment
comment|/// revision number whenever the format changes and document the change
end_comment

begin_comment
comment|/// in the revision in this header.
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

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_AMDGPU_AMDGPURUNTIMEMETADATA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPURUNTIMEMETADATA_H
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|AMDGPU
block|{
name|namespace
name|RuntimeMD
block|{
comment|// Version and revision of runtime metadata
specifier|const
name|unsigned
name|char
name|MDVersion
init|=
literal|2
decl_stmt|;
specifier|const
name|unsigned
name|char
name|MDRevision
init|=
literal|0
decl_stmt|;
comment|// Name of keys for runtime metadata.
name|namespace
name|KeyName
block|{
specifier|const
name|char
name|MDVersion
index|[]
init|=
literal|"amd.MDVersion"
decl_stmt|;
comment|// Runtime metadata version
specifier|const
name|char
name|Language
index|[]
init|=
literal|"amd.Language"
decl_stmt|;
comment|// Language
specifier|const
name|char
name|LanguageVersion
index|[]
init|=
literal|"amd.LanguageVersion"
decl_stmt|;
comment|// Language version
specifier|const
name|char
name|Kernels
index|[]
init|=
literal|"amd.Kernels"
decl_stmt|;
comment|// Kernels
specifier|const
name|char
name|KernelName
index|[]
init|=
literal|"amd.KernelName"
decl_stmt|;
comment|// Kernel name
specifier|const
name|char
name|Args
index|[]
init|=
literal|"amd.Args"
decl_stmt|;
comment|// Kernel arguments
specifier|const
name|char
name|ArgSize
index|[]
init|=
literal|"amd.ArgSize"
decl_stmt|;
comment|// Kernel arg size
specifier|const
name|char
name|ArgAlign
index|[]
init|=
literal|"amd.ArgAlign"
decl_stmt|;
comment|// Kernel arg alignment
specifier|const
name|char
name|ArgTypeName
index|[]
init|=
literal|"amd.ArgTypeName"
decl_stmt|;
comment|// Kernel type name
specifier|const
name|char
name|ArgName
index|[]
init|=
literal|"amd.ArgName"
decl_stmt|;
comment|// Kernel name
specifier|const
name|char
name|ArgKind
index|[]
init|=
literal|"amd.ArgKind"
decl_stmt|;
comment|// Kernel argument kind
specifier|const
name|char
name|ArgValueType
index|[]
init|=
literal|"amd.ArgValueType"
decl_stmt|;
comment|// Kernel argument value type
specifier|const
name|char
name|ArgAddrQual
index|[]
init|=
literal|"amd.ArgAddrQual"
decl_stmt|;
comment|// Kernel argument address qualifier
specifier|const
name|char
name|ArgAccQual
index|[]
init|=
literal|"amd.ArgAccQual"
decl_stmt|;
comment|// Kernel argument access qualifier
specifier|const
name|char
name|ArgIsConst
index|[]
init|=
literal|"amd.ArgIsConst"
decl_stmt|;
comment|// Kernel argument is const qualified
specifier|const
name|char
name|ArgIsRestrict
index|[]
init|=
literal|"amd.ArgIsRestrict"
decl_stmt|;
comment|// Kernel argument is restrict qualified
specifier|const
name|char
name|ArgIsVolatile
index|[]
init|=
literal|"amd.ArgIsVolatile"
decl_stmt|;
comment|// Kernel argument is volatile qualified
specifier|const
name|char
name|ArgIsPipe
index|[]
init|=
literal|"amd.ArgIsPipe"
decl_stmt|;
comment|// Kernel argument is pipe qualified
specifier|const
name|char
name|ReqdWorkGroupSize
index|[]
init|=
literal|"amd.ReqdWorkGroupSize"
decl_stmt|;
comment|// Required work group size
specifier|const
name|char
name|WorkGroupSizeHint
index|[]
init|=
literal|"amd.WorkGroupSizeHint"
decl_stmt|;
comment|// Work group size hint
specifier|const
name|char
name|VecTypeHint
index|[]
init|=
literal|"amd.VecTypeHint"
decl_stmt|;
comment|// Vector type hint
specifier|const
name|char
name|KernelIndex
index|[]
init|=
literal|"amd.KernelIndex"
decl_stmt|;
comment|// Kernel index for device enqueue
specifier|const
name|char
name|NoPartialWorkGroups
index|[]
init|=
literal|"amd.NoPartialWorkGroups"
decl_stmt|;
comment|// No partial work groups
specifier|const
name|char
name|PrintfInfo
index|[]
init|=
literal|"amd.PrintfInfo"
decl_stmt|;
comment|// Prinf function call information
specifier|const
name|char
name|ArgActualAcc
index|[]
init|=
literal|"amd.ArgActualAcc"
decl_stmt|;
comment|// The actual kernel argument access qualifier
specifier|const
name|char
name|ArgPointeeAlign
index|[]
init|=
literal|"amd.ArgPointeeAlign"
decl_stmt|;
comment|// Alignment of pointee type
block|}
name|namespace
name|KernelArg
block|{
enum|enum
name|Kind
enum|:
name|uint8_t
block|{
name|ByValue
init|=
literal|0
block|,
name|GlobalBuffer
init|=
literal|1
block|,
name|DynamicSharedPointer
init|=
literal|2
block|,
name|Sampler
init|=
literal|3
block|,
name|Image
init|=
literal|4
block|,
name|Pipe
init|=
literal|5
block|,
name|Queue
init|=
literal|6
block|,
name|HiddenGlobalOffsetX
init|=
literal|7
block|,
name|HiddenGlobalOffsetY
init|=
literal|8
block|,
name|HiddenGlobalOffsetZ
init|=
literal|9
block|,
name|HiddenNone
init|=
literal|10
block|,
name|HiddenPrintfBuffer
init|=
literal|11
block|,
name|HiddenDefaultQueue
init|=
literal|12
block|,
name|HiddenCompletionAction
init|=
literal|13
block|,     }
enum|;
enum|enum
name|ValueType
enum|:
name|uint16_t
block|{
name|Struct
init|=
literal|0
block|,
name|I8
init|=
literal|1
block|,
name|U8
init|=
literal|2
block|,
name|I16
init|=
literal|3
block|,
name|U16
init|=
literal|4
block|,
name|F16
init|=
literal|5
block|,
name|I32
init|=
literal|6
block|,
name|U32
init|=
literal|7
block|,
name|F32
init|=
literal|8
block|,
name|I64
init|=
literal|9
block|,
name|U64
init|=
literal|10
block|,
name|F64
init|=
literal|11
block|,     }
enum|;
comment|// Avoid using 'None' since it conflicts with a macro in X11 header file.
enum|enum
name|AccessQualifer
enum|:
name|uint8_t
block|{
name|AccNone
init|=
literal|0
block|,
name|ReadOnly
init|=
literal|1
block|,
name|WriteOnly
init|=
literal|2
block|,
name|ReadWrite
init|=
literal|3
block|,     }
enum|;
enum|enum
name|AddressSpaceQualifer
enum|:
name|uint8_t
block|{
name|Private
init|=
literal|0
block|,
name|Global
init|=
literal|1
block|,
name|Constant
init|=
literal|2
block|,
name|Local
init|=
literal|3
block|,
name|Generic
init|=
literal|4
block|,
name|Region
init|=
literal|5
block|,     }
enum|;
block|}
comment|// namespace KernelArg
comment|// Invalid values are used to indicate an optional key should not be emitted.
specifier|const
name|uint8_t
name|INVALID_ADDR_QUAL
init|=
literal|0xff
decl_stmt|;
specifier|const
name|uint8_t
name|INVALID_ACC_QUAL
init|=
literal|0xff
decl_stmt|;
specifier|const
name|uint32_t
name|INVALID_KERNEL_INDEX
init|=
operator|~
literal|0U
decl_stmt|;
name|namespace
name|KernelArg
block|{
comment|// In-memory representation of kernel argument information.
struct|struct
name|Metadata
block|{
name|uint32_t
name|Size
decl_stmt|;
name|uint32_t
name|Align
decl_stmt|;
name|uint32_t
name|PointeeAlign
decl_stmt|;
name|uint8_t
name|Kind
decl_stmt|;
name|uint16_t
name|ValueType
decl_stmt|;
name|std
operator|::
name|string
name|TypeName
expr_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|uint8_t
name|AddrQual
decl_stmt|;
name|uint8_t
name|AccQual
decl_stmt|;
name|uint8_t
name|IsVolatile
decl_stmt|;
name|uint8_t
name|IsConst
decl_stmt|;
name|uint8_t
name|IsRestrict
decl_stmt|;
name|uint8_t
name|IsPipe
decl_stmt|;
name|Metadata
argument_list|()
operator|:
name|Size
argument_list|(
literal|0
argument_list|)
operator|,
name|Align
argument_list|(
literal|0
argument_list|)
operator|,
name|PointeeAlign
argument_list|(
literal|0
argument_list|)
operator|,
name|Kind
argument_list|(
literal|0
argument_list|)
operator|,
name|ValueType
argument_list|(
literal|0
argument_list|)
operator|,
name|AddrQual
argument_list|(
name|INVALID_ADDR_QUAL
argument_list|)
operator|,
name|AccQual
argument_list|(
name|INVALID_ACC_QUAL
argument_list|)
operator|,
name|IsVolatile
argument_list|(
literal|0
argument_list|)
operator|,
name|IsConst
argument_list|(
literal|0
argument_list|)
operator|,
name|IsRestrict
argument_list|(
literal|0
argument_list|)
operator|,
name|IsPipe
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
block|}
name|namespace
name|Kernel
block|{
comment|// In-memory representation of kernel information.
struct|struct
name|Metadata
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|std
operator|::
name|string
name|Language
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|LanguageVersion
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|ReqdWorkGroupSize
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|WorkGroupSizeHint
expr_stmt|;
name|std
operator|::
name|string
name|VecTypeHint
expr_stmt|;
name|uint32_t
name|KernelIndex
decl_stmt|;
name|uint8_t
name|NoPartialWorkGroups
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|KernelArg
operator|::
name|Metadata
operator|>
name|Args
expr_stmt|;
name|Metadata
argument_list|()
operator|:
name|KernelIndex
argument_list|(
name|INVALID_KERNEL_INDEX
argument_list|)
operator|,
name|NoPartialWorkGroups
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
block|}
name|namespace
name|Program
block|{
comment|// In-memory representation of program information.
struct|struct
name|Metadata
block|{
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|MDVersionSeq
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|PrintfInfo
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Kernel
operator|::
name|Metadata
operator|>
name|Kernels
expr_stmt|;
name|explicit
name|Metadata
parameter_list|()
block|{}
comment|// Construct from an YAML string.
name|explicit
name|Metadata
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|YAML
argument_list|)
decl_stmt|;
comment|// Convert to YAML string.
name|std
operator|::
name|string
name|toYAML
argument_list|()
expr_stmt|;
comment|// Convert from YAML string.
specifier|static
name|Metadata
name|fromYAML
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|S
argument_list|)
decl_stmt|;
block|}
struct|;
block|}
block|}
comment|// namespace RuntimeMD
block|}
end_decl_stmt

begin_comment
comment|// namespace AMDGPU
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_AMDGPU_AMDGPURUNTIMEMETADATA_H
end_comment

end_unit

