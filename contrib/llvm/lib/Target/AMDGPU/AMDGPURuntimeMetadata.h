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
comment|/// The metadata is represented as a byte stream in an ELF section of a
end_comment

begin_comment
comment|/// binary (code object). The byte stream consists of key-value pairs.
end_comment

begin_comment
comment|/// Each key is an 8 bit unsigned integer. Each value can be an integer,
end_comment

begin_comment
comment|/// a string, or a stream of key-value pairs. There are 3 levels of key-value
end_comment

begin_comment
comment|/// pair streams. At the beginning of the ELF section is the top level
end_comment

begin_comment
comment|/// key-value pair stream. A kernel-level key-value pair stream starts after
end_comment

begin_comment
comment|/// encountering KeyKernelBegin and ends immediately before encountering
end_comment

begin_comment
comment|/// KeyKernelEnd. A kernel-argument-level key-value pair stream starts
end_comment

begin_comment
comment|/// after encountering KeyArgBegin and ends immediately before encountering
end_comment

begin_comment
comment|/// KeyArgEnd. A kernel-level key-value pair stream can only appear in a top
end_comment

begin_comment
comment|/// level key-value pair stream. A kernel-argument-level key-value pair stream
end_comment

begin_comment
comment|/// can only appear in a kernel-level key-value pair stream.
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
file|<stdint.h>
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
literal|1
decl_stmt|;
specifier|const
name|unsigned
name|char
name|MDRevision
init|=
literal|0
decl_stmt|;
comment|// ELF section name containing runtime metadata
specifier|const
name|char
name|SectionName
index|[]
init|=
literal|".AMDGPU.runtime_metadata"
decl_stmt|;
comment|// Enumeration values of keys in runtime metadata.
enum|enum
name|Key
block|{
name|KeyNull
init|=
literal|0
block|,
comment|// Place holder. Ignored when encountered
name|KeyMDVersion
init|=
literal|1
block|,
comment|// Runtime metadata version
name|KeyLanguage
init|=
literal|2
block|,
comment|// Language
name|KeyLanguageVersion
init|=
literal|3
block|,
comment|// Language version
name|KeyKernelBegin
init|=
literal|4
block|,
comment|// Beginning of kernel-level stream
name|KeyKernelEnd
init|=
literal|5
block|,
comment|// End of kernel-level stream
name|KeyKernelName
init|=
literal|6
block|,
comment|// Kernel name
name|KeyArgBegin
init|=
literal|7
block|,
comment|// Beginning of kernel-arg-level stream
name|KeyArgEnd
init|=
literal|8
block|,
comment|// End of kernel-arg-level stream
name|KeyArgSize
init|=
literal|9
block|,
comment|// Kernel arg size
name|KeyArgAlign
init|=
literal|10
block|,
comment|// Kernel arg alignment
name|KeyArgTypeName
init|=
literal|11
block|,
comment|// Kernel type name
name|KeyArgName
init|=
literal|12
block|,
comment|// Kernel name
name|KeyArgTypeKind
init|=
literal|13
block|,
comment|// Kernel argument type kind
name|KeyArgValueType
init|=
literal|14
block|,
comment|// Kernel argument value type
name|KeyArgAddrQual
init|=
literal|15
block|,
comment|// Kernel argument address qualifier
name|KeyArgAccQual
init|=
literal|16
block|,
comment|// Kernel argument access qualifier
name|KeyArgIsConst
init|=
literal|17
block|,
comment|// Kernel argument is const qualified
name|KeyArgIsRestrict
init|=
literal|18
block|,
comment|// Kernel argument is restrict qualified
name|KeyArgIsVolatile
init|=
literal|19
block|,
comment|// Kernel argument is volatile qualified
name|KeyArgIsPipe
init|=
literal|20
block|,
comment|// Kernel argument is pipe qualified
name|KeyReqdWorkGroupSize
init|=
literal|21
block|,
comment|// Required work group size
name|KeyWorkGroupSizeHint
init|=
literal|22
block|,
comment|// Work group size hint
name|KeyVecTypeHint
init|=
literal|23
block|,
comment|// Vector type hint
name|KeyKernelIndex
init|=
literal|24
block|,
comment|// Kernel index for device enqueue
name|KeySGPRs
init|=
literal|25
block|,
comment|// Number of SGPRs
name|KeyVGPRs
init|=
literal|26
block|,
comment|// Number of VGPRs
name|KeyMinWavesPerSIMD
init|=
literal|27
block|,
comment|// Minimum number of waves per SIMD
name|KeyMaxWavesPerSIMD
init|=
literal|28
block|,
comment|// Maximum number of waves per SIMD
name|KeyFlatWorkGroupSizeLimits
init|=
literal|29
block|,
comment|// Flat work group size limits
name|KeyMaxWorkGroupSize
init|=
literal|30
block|,
comment|// Maximum work group size
name|KeyNoPartialWorkGroups
init|=
literal|31
block|,
comment|// No partial work groups
block|}
enum|;
enum|enum
name|Language
enum|:
name|uint8_t
block|{
name|OpenCL_C
init|=
literal|0
block|,
name|HCC
init|=
literal|1
block|,
name|OpenMP
init|=
literal|2
block|,
name|OpenCL_CPP
init|=
literal|3
block|, }
enum|;
enum|enum
name|LanguageVersion
enum|:
name|uint16_t
block|{
name|V100
init|=
literal|100
block|,
name|V110
init|=
literal|110
block|,
name|V120
init|=
literal|120
block|,
name|V200
init|=
literal|200
block|,
name|V210
init|=
literal|210
block|,   }
enum|;
name|namespace
name|KernelArg
block|{
enum|enum
name|TypeKind
enum|:
name|uint8_t
block|{
name|Value
init|=
literal|0
block|,
name|Pointer
init|=
literal|1
block|,
name|Image
init|=
literal|2
block|,
name|Sampler
init|=
literal|3
block|,
name|Queue
init|=
literal|4
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
enum|enum
name|AccessQualifer
enum|:
name|uint8_t
block|{
name|None
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
block|}
comment|// namespace KernelArg
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

