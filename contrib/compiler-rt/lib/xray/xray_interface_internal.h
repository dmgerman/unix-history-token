begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_interface_internal.h -------------------------------*- C++ -*-===//
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
comment|// Implementation of the API functions. See also include/xray/xray_interface.h.
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
name|XRAY_INTERFACE_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_INTERFACE_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_platform.h"
end_include

begin_include
include|#
directive|include
file|"xray/xray_interface.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_extern
extern|extern
literal|"C"
block|{
struct|struct
name|XRaySledEntry
block|{
if|#
directive|if
name|SANITIZER_WORDSIZE
operator|==
literal|64
name|uint64_t
name|Address
decl_stmt|;
name|uint64_t
name|Function
decl_stmt|;
name|unsigned
name|char
name|Kind
decl_stmt|;
name|unsigned
name|char
name|AlwaysInstrument
decl_stmt|;
name|unsigned
name|char
name|Padding
index|[
literal|14
index|]
decl_stmt|;
comment|// Need 32 bytes
elif|#
directive|elif
name|SANITIZER_WORDSIZE
operator|==
literal|32
name|uint32_t
name|Address
decl_stmt|;
name|uint32_t
name|Function
decl_stmt|;
name|unsigned
name|char
name|Kind
decl_stmt|;
name|unsigned
name|char
name|AlwaysInstrument
decl_stmt|;
name|unsigned
name|char
name|Padding
index|[
literal|6
index|]
decl_stmt|;
comment|// Need 16 bytes
else|#
directive|else
error|#
directive|error
literal|"Unsupported word size."
endif|#
directive|endif
block|}
struct|;
block|}
end_extern

begin_decl_stmt
name|namespace
name|__xray
block|{
struct|struct
name|XRaySledMap
block|{
specifier|const
name|XRaySledEntry
modifier|*
name|Sleds
decl_stmt|;
name|size_t
name|Entries
decl_stmt|;
block|}
struct|;
name|bool
name|patchFunctionEntry
parameter_list|(
name|bool
name|Enable
parameter_list|,
name|uint32_t
name|FuncId
parameter_list|,
specifier|const
name|XRaySledEntry
modifier|&
name|Sled
parameter_list|,
name|void
function_decl|(
modifier|*
name|Trampoline
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
name|bool
name|patchFunctionExit
parameter_list|(
name|bool
name|Enable
parameter_list|,
name|uint32_t
name|FuncId
parameter_list|,
specifier|const
name|XRaySledEntry
modifier|&
name|Sled
parameter_list|)
function_decl|;
name|bool
name|patchFunctionTailExit
parameter_list|(
name|bool
name|Enable
parameter_list|,
name|uint32_t
name|FuncId
parameter_list|,
specifier|const
name|XRaySledEntry
modifier|&
name|Sled
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __xray
end_comment

begin_extern
extern|extern
literal|"C"
block|{
comment|// The following functions have to be defined in assembler, on a per-platform
comment|// basis. See xray_trampoline_*.S files for implementations.
specifier|extern
name|void
name|__xray_FunctionEntry
parameter_list|()
function_decl|;
specifier|extern
name|void
name|__xray_FunctionExit
parameter_list|()
function_decl|;
specifier|extern
name|void
name|__xray_FunctionTailExit
parameter_list|()
function_decl|;
specifier|extern
name|void
name|__xray_ArgLoggerEntry
parameter_list|()
function_decl|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

