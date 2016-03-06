begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- dfsan.h -------------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of DataFlowSanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Private DFSan header.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DFSAN_H
end_ifndef

begin_define
define|#
directive|define
name|DFSAN_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"dfsan_platform.h"
end_include

begin_comment
comment|// Copy declarations from public sanitizer/dfsan_interface.h header here.
end_comment

begin_typedef
typedef|typedef
name|u16
name|dfsan_label
typedef|;
end_typedef

begin_struct
struct|struct
name|dfsan_label_info
block|{
name|dfsan_label
name|l1
decl_stmt|;
name|dfsan_label
name|l2
decl_stmt|;
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
name|void
modifier|*
name|userdata
decl_stmt|;
block|}
struct|;
end_struct

begin_extern
extern|extern
literal|"C"
block|{
name|void
name|dfsan_add_label
parameter_list|(
name|dfsan_label
name|label
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|void
name|dfsan_set_label
parameter_list|(
name|dfsan_label
name|label
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|dfsan_label
name|dfsan_read_label
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|dfsan_label
name|dfsan_union
parameter_list|(
name|dfsan_label
name|l1
parameter_list|,
name|dfsan_label
name|l2
parameter_list|)
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|dfsan_set_label
argument_list|(
argument|dfsan_label label
argument_list|,
argument|T&data
argument_list|)
block|{
comment|// NOLINT
name|dfsan_set_label
argument_list|(
name|label
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|&
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|; }
name|namespace
name|__dfsan
block|{
name|void
name|InitializeInterceptors
argument_list|()
block|;
specifier|inline
name|dfsan_label
operator|*
name|shadow_for
argument_list|(
argument|void *ptr
argument_list|)
block|{
return|return
operator|(
name|dfsan_label
operator|*
operator|)
operator|(
operator|(
operator|(
operator|(
name|uptr
operator|)
name|ptr
operator|)
operator|&
name|ShadowMask
argument_list|()
operator|)
operator|<<
literal|1
operator|)
return|;
block|}
specifier|inline
specifier|const
name|dfsan_label
operator|*
name|shadow_for
argument_list|(
argument|const void *ptr
argument_list|)
block|{
return|return
name|shadow_for
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|ptr
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_struct
struct|struct
name|Flags
block|{
define|#
directive|define
name|DFSAN_FLAG
parameter_list|(
name|Type
parameter_list|,
name|Name
parameter_list|,
name|DefaultValue
parameter_list|,
name|Description
parameter_list|)
value|Type Name;
include|#
directive|include
file|"dfsan_flags.inc"
undef|#
directive|undef
name|DFSAN_FLAG
name|void
name|SetDefaults
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|Flags
name|flags_data
decl_stmt|;
end_decl_stmt

begin_function
specifier|inline
name|Flags
modifier|&
name|flags
parameter_list|()
block|{
return|return
name|flags_data
return|;
block|}
end_function

begin_comment
unit|}
comment|// namespace __dfsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// DFSAN_H
end_comment

end_unit

