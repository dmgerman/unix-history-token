begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DIERef.h ------------------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DIERef_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DIERef_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/dwarf.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_decl_stmt
name|class
name|DWARFFormValue
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|DIERef
block|{
name|DIERef
argument_list|()
expr_stmt|;
name|explicit
name|DIERef
parameter_list|(
name|dw_offset_t
name|d
parameter_list|)
function_decl|;
name|DIERef
argument_list|(
argument|dw_offset_t c
argument_list|,
argument|dw_offset_t d
argument_list|)
empty_stmt|;
name|explicit
name|DIERef
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|)
decl_stmt|;
name|explicit
name|DIERef
parameter_list|(
specifier|const
name|DWARFFormValue
modifier|&
name|form_value
parameter_list|)
function_decl|;
name|lldb
operator|::
name|user_id_t
name|GetUID
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|DIERef
operator|&
name|ref
operator|)
specifier|const
block|{
return|return
name|die_offset
operator|<
name|ref
operator|.
name|die_offset
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|DIERef
operator|&
name|ref
operator|)
block|{
return|return
name|die_offset
operator|<
name|ref
operator|.
name|die_offset
return|;
block|}
name|dw_offset_t
name|cu_offset
decl_stmt|;
name|dw_offset_t
name|die_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|DIERef
operator|>
name|DIEArray
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DIERef_h_
end_comment

end_unit

