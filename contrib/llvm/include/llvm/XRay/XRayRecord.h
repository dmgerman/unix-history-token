begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- XRayRecord.h - XRay Trace Record -----------------------------------===//
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
comment|// This file replicates the record definition for XRay log entries. This should
end_comment

begin_comment
comment|// follow the evolution of the log record versions supported in the compiler-rt
end_comment

begin_comment
comment|// xray project.
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
name|LLVM_XRAY_XRAY_RECORD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_XRAY_XRAY_RECORD_H
end_define

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
name|xray
block|{
comment|/// XRay traces all have a header providing some top-matter information useful
comment|/// to help tools determine how to interpret the information available in the
comment|/// trace.
struct|struct
name|XRayFileHeader
block|{
comment|/// Version of the XRay implementation that produced this file.
name|uint16_t
name|Version
init|=
literal|0
decl_stmt|;
comment|/// A numeric identifier for the type of file this is. Best used in
comment|/// combination with Version.
name|uint16_t
name|Type
init|=
literal|0
decl_stmt|;
comment|/// Whether the CPU that produced the timestamp counters (TSC) move at a
comment|/// constant rate.
name|bool
name|ConstantTSC
decl_stmt|;
comment|/// Whether the CPU that produced the timestamp counters (TSC) do not stop.
name|bool
name|NonstopTSC
decl_stmt|;
comment|/// The number of cycles per second for the CPU that produced the timestamp
comment|/// counter (TSC) values. Useful for estimating the amount of time that
comment|/// elapsed between two TSCs on some platforms.
name|uint64_t
name|CycleFrequency
init|=
literal|0
decl_stmt|;
comment|// This is different depending on the type of xray record. The naive format
comment|// stores a Wallclock timespec. FDR logging stores the size of a thread
comment|// buffer.
name|char
name|FreeFormData
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
comment|/// Determines the supported types of records that could be seen in XRay traces.
comment|/// This may or may not correspond to actual record types in the raw trace (as
comment|/// the loader implementation may synthesize this information in the process of
comment|/// of loading).
name|enum
name|class
name|RecordTypes
block|{
name|ENTER
operator|,
name|EXIT
block|}
empty_stmt|;
struct|struct
name|XRayRecord
block|{
comment|/// The type of record.
name|uint16_t
name|RecordType
decl_stmt|;
comment|/// The CPU where the thread is running. We assume number of CPUs<= 65536.
name|uint16_t
name|CPU
decl_stmt|;
comment|/// Identifies the type of record.
name|RecordTypes
name|Type
decl_stmt|;
comment|/// The function ID for the record.
name|int32_t
name|FuncId
decl_stmt|;
comment|/// Get the full 8 bytes of the TSC when we get the log record.
name|uint64_t
name|TSC
decl_stmt|;
comment|/// The thread ID for the currently running thread.
name|uint32_t
name|TId
decl_stmt|;
block|}
struct|;
block|}
comment|// namespace xray
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_XRAY_XRAY_RECORD_H
end_comment

end_unit

