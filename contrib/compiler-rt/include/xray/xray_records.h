begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_records.h ------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of XRay, a dynamic runtime instrumentation system.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This header exposes some record types useful for the XRay in-memory logging
end_comment

begin_comment
comment|// implementation.
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
name|XRAY_XRAY_RECORDS_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_XRAY_RECORDS_H
end_define

begin_decl_stmt
name|namespace
name|__xray
block|{
enum|enum
name|FileTypes
block|{
name|NAIVE_LOG
init|=
literal|0
block|,
name|FDR_LOG
init|=
literal|1
block|, }
enum|;
comment|// FDR mode use of the union field in the XRayFileHeader.
struct|struct
name|alignas
argument_list|(
literal|16
argument_list|)
name|FdrAdditionalHeaderData
block|{
name|uint64_t
name|ThreadBufferSize
decl_stmt|;
block|}
struct|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|FdrAdditionalHeaderData
argument_list|)
operator|==
literal|16
argument_list|,
literal|"FdrAdditionalHeaderData != 16 bytes"
argument_list|)
expr_stmt|;
comment|// This data structure is used to describe the contents of the file. We use this
comment|// for versioning the supported XRay file formats.
struct|struct
name|alignas
argument_list|(
literal|32
argument_list|)
name|XRayFileHeader
block|{
name|uint16_t
name|Version
init|=
literal|0
decl_stmt|;
comment|// The type of file we're writing out. See the FileTypes enum for more
comment|// information. This allows different implementations of the XRay logging to
comment|// have different files for different information being stored.
name|uint16_t
name|Type
init|=
literal|0
decl_stmt|;
comment|// What follows are a set of flags that indicate useful things for when
comment|// reading the data in the file.
name|bool
name|ConstantTSC
range|:
literal|1
decl_stmt|;
name|bool
name|NonstopTSC
range|:
literal|1
decl_stmt|;
comment|// The frequency by which TSC increases per-second.
name|alignas
argument_list|(
literal|8
argument_list|)
name|uint64_t
name|CycleFrequency
init|=
literal|0
decl_stmt|;
union|union
block|{
name|char
name|FreeForm
index|[
literal|16
index|]
decl_stmt|;
comment|// The current civiltime timestamp, as retrived from 'clock_gettime'. This
comment|// allows readers of the file to determine when the file was created or
comment|// written down.
name|struct
name|timespec
name|TS
decl_stmt|;
name|struct
name|FdrAdditionalHeaderData
name|FdrData
decl_stmt|;
block|}
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|XRayFileHeader
argument_list|)
operator|==
literal|32
argument_list|,
literal|"XRayFileHeader != 32 bytes"
argument_list|)
expr_stmt|;
enum|enum
name|RecordTypes
block|{
name|NORMAL
init|=
literal|0
block|, }
enum|;
struct|struct
name|alignas
argument_list|(
literal|32
argument_list|)
name|XRayRecord
block|{
comment|// This is the type of the record being written. We use 16 bits to allow us to
comment|// treat this as a discriminant, and so that the first 4 bytes get packed
comment|// properly. See RecordTypes for more supported types.
name|uint16_t
name|RecordType
init|=
literal|0
decl_stmt|;
comment|// The CPU where the thread is running. We assume number of CPUs<= 256.
name|uint8_t
name|CPU
init|=
literal|0
decl_stmt|;
comment|// The type of the event. Usually either ENTER = 0 or EXIT = 1.
name|uint8_t
name|Type
init|=
literal|0
decl_stmt|;
comment|// The function ID for the record.
name|int32_t
name|FuncId
init|=
literal|0
decl_stmt|;
comment|// Get the full 8 bytes of the TSC when we get the log record.
name|uint64_t
name|TSC
init|=
literal|0
decl_stmt|;
comment|// The thread ID for the currently running thread.
name|uint32_t
name|TId
init|=
literal|0
decl_stmt|;
comment|// Use some bytes in the end of the record for buffers.
name|char
name|Buffer
index|[
literal|4
index|]
init|=
block|{}
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|XRayRecord
argument_list|)
operator|==
literal|32
argument_list|,
literal|"XRayRecord != 32 bytes"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __xray
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XRAY_XRAY_RECORDS_H
end_comment

end_unit

