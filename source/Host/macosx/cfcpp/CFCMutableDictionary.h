begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CFCMutableDictionary.h ----------------------------------*- C++ -*-===//
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
name|CoreFoundationCPP_CFMutableDictionary_h_
end_ifndef

begin_define
define|#
directive|define
name|CoreFoundationCPP_CFMutableDictionary_h_
end_define

begin_include
include|#
directive|include
file|"CFCReleaser.h"
end_include

begin_decl_stmt
name|class
name|CFCMutableDictionary
range|:
name|public
name|CFCReleaser
operator|<
name|CFMutableDictionaryRef
operator|>
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|CFCMutableDictionary
argument_list|(
argument|CFMutableDictionaryRef s = NULL
argument_list|)
block|;
name|CFCMutableDictionary
argument_list|(
specifier|const
name|CFCMutableDictionary
operator|&
name|rhs
argument_list|)
block|;
name|virtual
operator|~
name|CFCMutableDictionary
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Operators
comment|//------------------------------------------------------------------
specifier|const
name|CFCMutableDictionary
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CFCMutableDictionary
operator|&
name|rhs
operator|)
block|;
name|CFIndex
name|GetCount
argument_list|()
specifier|const
block|;
name|CFIndex
name|GetCountOfKey
argument_list|(
argument|const void *value
argument_list|)
specifier|const
block|;
name|CFIndex
name|GetCountOfValue
argument_list|(
argument|const void *value
argument_list|)
specifier|const
block|;
name|void
name|GetKeysAndValues
argument_list|(
argument|const void **keys
argument_list|,
argument|const void **values
argument_list|)
specifier|const
block|;
specifier|const
name|void
operator|*
name|GetValue
argument_list|(
argument|const void *key
argument_list|)
specifier|const
block|;
name|Boolean
name|GetValueIfPresent
argument_list|(
argument|const void *key
argument_list|,
argument|const void **value_handle
argument_list|)
specifier|const
block|;
name|bool
name|AddValue
argument_list|(
argument|CFStringRef key
argument_list|,
argument|const void *value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValue
argument_list|(
argument|CFStringRef key
argument_list|,
argument|const void *value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|AddValueSInt8
argument_list|(
argument|CFStringRef key
argument_list|,
argument|int8_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValueSInt8
argument_list|(
argument|CFStringRef key
argument_list|,
argument|int8_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|AddValueSInt16
argument_list|(
argument|CFStringRef key
argument_list|,
argument|int16_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValueSInt16
argument_list|(
argument|CFStringRef key
argument_list|,
argument|int16_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|AddValueSInt32
argument_list|(
argument|CFStringRef key
argument_list|,
argument|int32_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValueSInt32
argument_list|(
argument|CFStringRef key
argument_list|,
argument|int32_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|AddValueSInt64
argument_list|(
argument|CFStringRef key
argument_list|,
argument|int64_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValueSInt64
argument_list|(
argument|CFStringRef key
argument_list|,
argument|int64_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|AddValueUInt8
argument_list|(
argument|CFStringRef key
argument_list|,
argument|uint8_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValueUInt8
argument_list|(
argument|CFStringRef key
argument_list|,
argument|uint8_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|AddValueUInt16
argument_list|(
argument|CFStringRef key
argument_list|,
argument|uint16_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValueUInt16
argument_list|(
argument|CFStringRef key
argument_list|,
argument|uint16_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|AddValueUInt32
argument_list|(
argument|CFStringRef key
argument_list|,
argument|uint32_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValueUInt32
argument_list|(
argument|CFStringRef key
argument_list|,
argument|uint32_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|AddValueUInt64
argument_list|(
argument|CFStringRef key
argument_list|,
argument|uint64_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValueUInt64
argument_list|(
argument|CFStringRef key
argument_list|,
argument|uint64_t value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|AddValueDouble
argument_list|(
argument|CFStringRef key
argument_list|,
argument|double value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValueDouble
argument_list|(
argument|CFStringRef key
argument_list|,
argument|double value
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|AddValueCString
argument_list|(
argument|CFStringRef key
argument_list|,
argument|const char *cstr
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|bool
name|SetValueCString
argument_list|(
argument|CFStringRef key
argument_list|,
argument|const char *cstr
argument_list|,
argument|bool can_create = false
argument_list|)
block|;
name|void
name|RemoveValue
argument_list|(
specifier|const
name|void
operator|*
name|value
argument_list|)
block|;
name|void
name|ReplaceValue
argument_list|(
specifier|const
name|void
operator|*
name|key
argument_list|,
specifier|const
name|void
operator|*
name|value
argument_list|)
block|;
name|void
name|RemoveAllValues
argument_list|()
block|;
name|CFMutableDictionaryRef
name|Dictionary
argument_list|(
argument|bool can_create
argument_list|)
block|;
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from CFCMutableDictionary can see and modify these
comment|//------------------------------------------------------------------
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// For CFCMutableDictionary only
comment|//------------------------------------------------------------------
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CoreFoundationCPP_CFMutableDictionary_h_
end_comment

end_unit

