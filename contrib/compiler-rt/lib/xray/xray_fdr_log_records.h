begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_fdr_log_records.h  -------------------------------------------===//
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
comment|// This file is a part of XRay, a function call tracing system.
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
name|XRAY_XRAY_FDR_LOG_RECORDS_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_XRAY_FDR_LOG_RECORDS_H
end_define

begin_decl_stmt
name|enum
name|class
name|RecordType
range|:
name|uint8_t
block|{
name|Function
block|,
name|Metadata
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A MetadataRecord encodes the kind of record in its first byte, and have 15
end_comment

begin_comment
comment|// additional bytes in the end to hold free-form data.
end_comment

begin_struct
struct|struct
name|alignas
argument_list|(
literal|16
argument_list|)
name|MetadataRecord
block|{
comment|// A MetadataRecord must always have a type of 1.
comment|/* RecordType */
name|uint8_t
name|Type
range|:
literal|1
decl_stmt|;
comment|// Each kind of record is represented as a 7-bit value (even though we use an
comment|// unsigned 8-bit enum class to do so).
name|enum
name|class
name|RecordKinds
range|:
name|uint8_t
block|{
name|NewBuffer
block|,
name|EndOfBuffer
block|,
name|NewCPUId
block|,
name|TSCWrap
block|,
name|WalltimeMarker
block|,
name|CustomEventMarker
block|,   }
decl_stmt|;
comment|// Use 7 bits to identify this record type.
comment|/* RecordKinds */
name|uint8_t
name|RecordKind
range|:
literal|7
decl_stmt|;
name|char
name|Data
index|[
literal|15
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|MetadataRecord
argument_list|)
operator|==
literal|16
argument_list|,
literal|"Wrong size for MetadataRecord."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|alignas
argument_list|(
literal|8
argument_list|)
name|FunctionRecord
block|{
comment|// A FunctionRecord must always have a type of 0.
comment|/* RecordType */
name|uint8_t
name|Type
range|:
literal|1
decl_stmt|;
name|enum
name|class
name|RecordKinds
block|{
name|FunctionEnter
operator|=
literal|0x00
operator|,
name|FunctionExit
operator|=
literal|0x01
operator|,
name|FunctionTailExit
operator|=
literal|0x02
operator|,
block|}
empty_stmt|;
comment|/* RecordKinds */
name|uint8_t
name|RecordKind
range|:
literal|3
decl_stmt|;
comment|// We only use 28 bits of the function ID, so that we can use as few bytes as
comment|// possible. This means we only support 2^28 (268,435,456) unique function ids
comment|// in a single binary.
name|int
name|FuncId
range|:
literal|28
decl_stmt|;
comment|// We use another 4 bytes to hold the delta between the previous entry's TSC.
comment|// In case we've found that the distance is greater than the allowable 32 bits
comment|// (either because we are running in a different CPU and the TSC might be
comment|// different then), we should use a MetadataRecord before this FunctionRecord
comment|// that will contain the full TSC for that CPU, and keep this to 0.
name|uint32_t
name|TSCDelta
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|FunctionRecord
argument_list|)
operator|==
literal|8
argument_list|,
literal|"Wrong size for FunctionRecord."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XRAY_XRAY_FDR_LOG_RECORDS_H
end_comment

end_unit

