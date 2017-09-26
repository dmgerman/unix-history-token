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

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
name|class
name|DynamicLibrary
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Platform
decl_stmt|;
name|class
name|ExecutionContext
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|sys
operator|::
name|DynamicLibrary
argument_list|(
operator|*
name|LoadPluginCallbackType
argument_list|)
argument_list|(
specifier|const
name|lldb
operator|::
name|DebuggerSP
operator|&
name|debugger_sp
argument_list|,
specifier|const
name|FileSpec
operator|&
name|spec
argument_list|,
name|Status
operator|&
name|error
argument_list|)
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// Every register is described in detail including its name, alternate
comment|// name (optional), encoding, size in bytes and the default display
comment|// format.
comment|//----------------------------------------------------------------------
struct|struct
name|RegisterInfo
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
comment|// The byte offset in the register context data where
comment|// this register's value is found.
comment|// This is optional, and can be 0 if a particular RegisterContext does not
comment|// need to
comment|// address its registers by byte offset.
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
comment|// Holds all of the various register
comment|// numbers for all register kinds
name|uint32_t
modifier|*
name|value_regs
decl_stmt|;
comment|// List of registers (terminated with
comment|// LLDB_INVALID_REGNUM).  If this value is not
comment|// null, all registers in this list will be read first, at which point the
comment|// value
comment|// for this register will be valid.  For example, the value list for ah
comment|// would be eax (x86) or rax (x64).
name|uint32_t
modifier|*
name|invalidate_regs
decl_stmt|;
comment|// List of registers (terminated with
comment|// LLDB_INVALID_REGNUM).  If this value is not
comment|// null, all registers in this list will be invalidated when the value of this
comment|// register changes.  For example, the invalidate list for eax would be rax
comment|// ax, ah, and al.
specifier|const
name|uint8_t
modifier|*
name|dynamic_size_dwarf_expr_bytes
decl_stmt|;
comment|// A DWARF expression that when
comment|// evaluated gives
comment|// the byte size of this register.
name|size_t
name|dynamic_size_dwarf_len
decl_stmt|;
comment|// The length of the DWARF expression in bytes
comment|// in the dynamic_size_dwarf_expr_bytes member.
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|data
argument_list|(
argument|const uint8_t *context_base
argument_list|)
specifier|const
block|{
return|return
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|(
name|context_base
operator|+
name|byte_offset
operator|,
name|byte_size
operator|)
return|;
block|}
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|mutable_data
argument_list|(
argument|uint8_t *context_base
argument_list|)
specifier|const
block|{
return|return
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
operator|(
name|context_base
operator|+
name|byte_offset
operator|,
name|byte_size
operator|)
return|;
block|}
block|}
struct|;
comment|//----------------------------------------------------------------------
comment|// Registers are grouped into register sets
comment|//----------------------------------------------------------------------
struct|struct
name|RegisterSet
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
comment|// An array of register indices in this set.  The
comment|// values in this array are
comment|// *indices* (not register numbers) into a particular RegisterContext's
comment|// register array.  For example, if eax is defined at index 4 for a
comment|// particular RegisterContext, eax would be included in this RegisterSet
comment|// by adding the value 4.  Not by adding the value lldb_eax_i386.
block|}
struct|;
struct|struct
name|OptionEnumValueElement
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
struct|;
struct|struct
name|OptionValidator
block|{
name|virtual
operator|~
name|OptionValidator
argument_list|()
block|{}
name|virtual
name|bool
name|IsValid
argument_list|(
argument|Platform&platform
argument_list|,
argument|const ExecutionContext&target
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|char
operator|*
name|ShortConditionString
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|char
operator|*
name|LongConditionString
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
struct|;
struct|struct
name|OptionDefinition
block|{
name|uint32_t
name|usage_mask
decl_stmt|;
comment|// Used to mark options that can be used together.  If (1
comment|//<< n& usage_mask) != 0
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
name|OptionValidator
modifier|*
name|validator
decl_stmt|;
comment|// If non-NULL, option is valid iff
comment|// |validator->IsValid()|, otherwise always valid.
name|OptionEnumValueElement
modifier|*
name|enum_values
decl_stmt|;
comment|// If non-NULL an array of enum values.
name|uint32_t
name|completion_type
decl_stmt|;
comment|// Cookie the option class can use to do define the
comment|// argument completion.
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
comment|// Full text explaining what this options does and
comment|// what (if any) argument to
comment|// pass it.
block|}
struct|;
typedef|typedef
struct|struct
name|type128
block|{
name|uint64_t
name|x
index|[
literal|2
index|]
decl_stmt|;
block|}
name|type128
typedef|;
typedef|typedef
struct|struct
name|type256
block|{
name|uint64_t
name|x
index|[
literal|4
index|]
decl_stmt|;
block|}
name|type256
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

