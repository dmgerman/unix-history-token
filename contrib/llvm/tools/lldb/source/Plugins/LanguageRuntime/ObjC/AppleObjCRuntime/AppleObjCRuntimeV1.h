begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AppleObjCRuntimeV1.h ------------------------------------*- C++ -*-===//
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
name|liblldb_AppleObjCRuntimeV1_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AppleObjCRuntimeV1_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ObjCLanguageRuntime.h"
end_include

begin_include
include|#
directive|include
file|"AppleObjCRuntime.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|AppleObjCRuntimeV1
range|:
name|public
name|AppleObjCRuntime
block|{
name|public
operator|:
operator|~
name|AppleObjCRuntimeV1
argument_list|()
name|override
operator|=
expr|default
block|;
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|LanguageRuntime
operator|*
name|CreateInstance
argument_list|(
argument|Process *process
argument_list|,
argument|lldb::LanguageType language
argument_list|)
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCLanguageRuntime* runtime
argument_list|)
block|{
switch|switch
condition|(
name|runtime
operator|->
name|GetRuntimeVersion
argument_list|()
condition|)
block|{
case|case
name|ObjCRuntimeVersions
operator|::
name|eAppleObjC_V1
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
name|class
name|ClassDescriptorV1
operator|:
name|public
name|ObjCLanguageRuntime
operator|::
name|ClassDescriptor
block|{
name|public
operator|:
name|ClassDescriptorV1
argument_list|(
name|ValueObject
operator|&
name|isa_pointer
argument_list|)
block|;
name|ClassDescriptorV1
argument_list|(
argument|ObjCISA isa
argument_list|,
argument|lldb::ProcessSP process_sp
argument_list|)
block|;
operator|~
name|ClassDescriptorV1
argument_list|()
name|override
operator|=
expr|default
block|;
name|ConstString
name|GetClassName
argument_list|()
name|override
block|{
return|return
name|m_name
return|;
block|}
name|ClassDescriptorSP
name|GetSuperclass
argument_list|()
name|override
block|;
name|ClassDescriptorSP
name|GetMetaclass
argument_list|()
specifier|const
name|override
block|;
name|bool
name|IsValid
argument_list|()
name|override
block|{
return|return
name|m_valid
return|;
block|}
comment|// v1 does not support tagged pointers
name|bool
name|GetTaggedPointerInfo
argument_list|(
argument|uint64_t* info_bits = nullptr
argument_list|,
argument|uint64_t* value_bits = nullptr
argument_list|,
argument|uint64_t* payload = nullptr
argument_list|)
name|override
block|{
return|return
name|false
return|;
block|}
name|uint64_t
name|GetInstanceSize
argument_list|()
name|override
block|{
return|return
name|m_instance_size
return|;
block|}
name|ObjCISA
name|GetISA
argument_list|()
name|override
block|{
return|return
name|m_isa
return|;
block|}
name|bool
name|Describe
argument_list|(
argument|std::function<void (ObjCLanguageRuntime::ObjCISA)> const&superclass_func
argument_list|,
argument|std::function<bool (const char *, const char *)> const&instance_method_func
argument_list|,
argument|std::function<bool (const char *, const char *)> const&class_method_func
argument_list|,
argument|std::function<bool (const char *, const char *,                  lldb::addr_t, uint64_t)> const&ivar_func
argument_list|)
specifier|const
name|override
block|;
name|protected
operator|:
name|void
name|Initialize
argument_list|(
argument|ObjCISA isa
argument_list|,
argument|lldb::ProcessSP process_sp
argument_list|)
block|;
name|private
operator|:
name|ConstString
name|m_name
block|;
name|ObjCISA
name|m_isa
block|;
name|ObjCISA
name|m_parent_isa
block|;
name|bool
name|m_valid
block|;
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
block|;
name|uint64_t
name|m_instance_size
block|;     }
block|;
comment|// These are generic runtime functions:
name|bool
name|GetDynamicTypeAndAddress
argument_list|(
argument|ValueObject&in_value
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|,
argument|TypeAndOrName&class_type_or_name
argument_list|,
argument|Address&address
argument_list|,
argument|Value::ValueType&value_type
argument_list|)
name|override
block|;
name|UtilityFunction
operator|*
name|CreateObjectChecker
argument_list|(
argument|const char *
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
name|ObjCRuntimeVersions
name|GetRuntimeVersion
argument_list|()
specifier|const
name|override
block|{
return|return
name|ObjCRuntimeVersions
operator|::
name|eAppleObjC_V1
return|;
block|}
name|void
name|UpdateISAToDescriptorMapIfNeeded
argument_list|()
name|override
block|;
name|DeclVendor
operator|*
name|GetDeclVendor
argument_list|()
name|override
block|;
name|protected
operator|:
name|lldb
operator|::
name|BreakpointResolverSP
name|CreateExceptionResolver
argument_list|(
argument|Breakpoint *bkpt
argument_list|,
argument|bool catch_bp
argument_list|,
argument|bool throw_bp
argument_list|)
name|override
block|;
name|class
name|HashTableSignature
block|{
name|public
operator|:
name|HashTableSignature
argument_list|()
operator|:
name|m_count
argument_list|(
literal|0
argument_list|)
block|,
name|m_num_buckets
argument_list|(
literal|0
argument_list|)
block|,
name|m_buckets_ptr
argument_list|(
argument|LLDB_INVALID_ADDRESS
argument_list|)
block|{         }
name|bool
name|NeedsUpdate
argument_list|(
argument|uint32_t count
argument_list|,
argument|uint32_t num_buckets
argument_list|,
argument|lldb::addr_t buckets_ptr
argument_list|)
block|{
return|return
name|m_count
operator|!=
name|count
operator|||
name|m_num_buckets
operator|!=
name|num_buckets
operator|||
name|m_buckets_ptr
operator|!=
name|buckets_ptr
return|;
block|}
name|void
name|UpdateSignature
argument_list|(
argument|uint32_t count
argument_list|,
argument|uint32_t num_buckets
argument_list|,
argument|lldb::addr_t buckets_ptr
argument_list|)
block|{
name|m_count
operator|=
name|count
block|;
name|m_num_buckets
operator|=
name|num_buckets
block|;
name|m_buckets_ptr
operator|=
name|buckets_ptr
block|;         }
name|protected
operator|:
name|uint32_t
name|m_count
block|;
name|uint32_t
name|m_num_buckets
block|;
name|lldb
operator|::
name|addr_t
name|m_buckets_ptr
block|;     }
block|;
name|lldb
operator|::
name|addr_t
name|GetISAHashTablePointer
argument_list|()
block|;
name|HashTableSignature
name|m_hash_signature
block|;
name|lldb
operator|::
name|addr_t
name|m_isa_hash_table_ptr
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|DeclVendor
operator|>
name|m_decl_vendor_ap
block|;
name|private
operator|:
name|AppleObjCRuntimeV1
argument_list|(
name|Process
operator|*
name|process
argument_list|)
block|; }
decl_stmt|;
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
comment|// liblldb_AppleObjCRuntimeV1_h_
end_comment

end_unit

