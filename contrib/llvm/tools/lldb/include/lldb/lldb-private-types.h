begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-private-types.h ------------------------------------*- C++ -*-===//
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
name|liblldb_lldb_private_types_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_lldb_private_types_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// Every register is described in detail including its name, alternate
comment|// name (optional), encoding, size in bytes and the default display
comment|// format.
comment|//----------------------------------------------------------------------
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|// Name of this register, can't be NULL
specifier|const
name|char
modifier|*
name|alt_name
decl_stmt|;
comment|// Alternate name of this register, can be NULL
name|uint32_t
name|byte_size
decl_stmt|;
comment|// Size in bytes of the register
name|uint32_t
name|byte_offset
decl_stmt|;
comment|// The byte offset in the register context data where this register's value is found
name|lldb
operator|::
name|Encoding
name|encoding
expr_stmt|;
comment|// Encoding of the register bits
name|lldb
operator|::
name|Format
name|format
expr_stmt|;
comment|// Default display format
name|uint32_t
name|kinds
index|[
name|lldb
operator|::
name|kNumRegisterKinds
index|]
decl_stmt|;
comment|// Holds all of the various register numbers for all register kinds
name|uint32_t
modifier|*
name|value_regs
decl_stmt|;
comment|// List of registers that must be terminated with LLDB_INVALID_REGNUM
name|uint32_t
modifier|*
name|invalidate_regs
decl_stmt|;
comment|// List of registers that must be invalidated when this register is modified, list must be terminated with LLDB_INVALID_REGNUM
block|}
name|RegisterInfo
typedef|;
comment|//----------------------------------------------------------------------
comment|// Registers are grouped into register sets
comment|//----------------------------------------------------------------------
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|// Name of this register set
specifier|const
name|char
modifier|*
name|short_name
decl_stmt|;
comment|// A short name for this register set
name|size_t
name|num_registers
decl_stmt|;
comment|// The number of registers in REGISTERS array below
specifier|const
name|uint32_t
modifier|*
name|registers
decl_stmt|;
comment|// An array of register numbers in this set
block|}
name|RegisterSet
typedef|;
typedef|typedef
struct|struct
block|{
name|int64_t
name|value
decl_stmt|;
specifier|const
name|char
modifier|*
name|string_value
decl_stmt|;
specifier|const
name|char
modifier|*
name|usage
decl_stmt|;
block|}
name|OptionEnumValueElement
typedef|;
typedef|typedef
struct|struct
block|{
name|uint32_t
name|usage_mask
decl_stmt|;
comment|// Used to mark options that can be used together.  If (1<< n& usage_mask) != 0
comment|// then this option belongs to option set n.
name|bool
name|required
decl_stmt|;
comment|// This option is required (in the current usage level)
specifier|const
name|char
modifier|*
name|long_option
decl_stmt|;
comment|// Full name for this option.
name|int
name|short_option
decl_stmt|;
comment|// Single character for this option.
name|int
name|option_has_arg
decl_stmt|;
comment|// no_argument, required_argument or optional_argument
name|OptionEnumValueElement
modifier|*
name|enum_values
decl_stmt|;
comment|// If non-NULL an array of enum values.
name|uint32_t
name|completion_type
decl_stmt|;
comment|// Cookie the option class can use to do define the argument completion.
name|lldb
operator|::
name|CommandArgumentType
name|argument_type
expr_stmt|;
comment|// Type of argument this option takes
specifier|const
name|char
modifier|*
name|usage_text
decl_stmt|;
comment|// Full text explaining what this options does and what (if any) argument to
comment|// pass it.
block|}
name|OptionDefinition
typedef|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_lldb_private_types_h_
end_comment

end_unit

