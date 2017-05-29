begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBStructuredData.h --------------------------------------*- C++ -*-===//
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
name|SBStructuredData_h
end_ifndef

begin_define
define|#
directive|define
name|SBStructuredData_h
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBModule.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBStructuredData
block|{
name|public
label|:
name|SBStructuredData
argument_list|()
expr_stmt|;
name|SBStructuredData
argument_list|(
specifier|const
name|lldb
operator|::
name|SBStructuredData
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|SBStructuredData
argument_list|(
specifier|const
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
expr_stmt|;
operator|~
name|SBStructuredData
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBStructuredData
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBStructuredData
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBError
name|SetFromJSON
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|stream
argument_list|)
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBError
name|GetAsJSON
argument_list|(
argument|lldb::SBStream&stream
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBError
name|GetDescription
argument_list|(
argument|lldb::SBStream&stream
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the type of data in this data structure
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|StructuredDataType
name|GetType
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the size (i.e. number of elements) in this data structure
comment|/// if it is an array or dictionary type. For other types, 0 will be
comment|//  returned.
comment|//------------------------------------------------------------------
name|size_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the value corresponding to a key if this data structure
comment|/// is a dictionary type.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBStructuredData
name|GetValueForKey
argument_list|(
argument|const char *key
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the value corresponding to an index if this data structure
comment|/// is array.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBStructuredData
name|GetItemAtIndex
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the integer value if this data structure is an integer type.
comment|//------------------------------------------------------------------
name|uint64_t
name|GetIntegerValue
argument_list|(
name|uint64_t
name|fail_value
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the floating point value if this data structure is a floating
comment|/// type.
comment|//------------------------------------------------------------------
name|double
name|GetFloatValue
argument_list|(
name|double
name|fail_value
operator|=
literal|0.0
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the boolean value if this data structure is a boolean type.
comment|//------------------------------------------------------------------
name|bool
name|GetBooleanValue
argument_list|(
name|bool
name|fail_value
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Provides the string value if this data structure is a string type.
comment|///
comment|/// @param[out] dst
comment|///     pointer where the string value will be written. In case it is null,
comment|///     nothing will be written at @dst.
comment|///
comment|/// @param[in] dst_len
comment|///     max number of characters that can be written at @dst. In case it is
comment|///     zero, nothing will be written at @dst. If this length is not enough
comment|///     to write the complete string value, (dst_len-1) bytes of the string
comment|///     value will be written at @dst followed by a null character.
comment|///
comment|/// @return
comment|///     Returns the byte size needed to completely write the string value at
comment|///     @dst in all cases.
comment|//------------------------------------------------------------------
name|size_t
name|GetStringValue
argument_list|(
name|char
operator|*
name|dst
argument_list|,
name|size_t
name|dst_len
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|friend
name|class
name|SBTraceOptions
decl_stmt|;
name|StructuredDataImplUP
name|m_impl_up
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SBStructuredData_h */
end_comment

end_unit

