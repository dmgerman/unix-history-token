begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AppleObjCRuntimeV2.h ------------------------------------*- C++ -*-===//
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
name|liblldb_AppleObjCRuntimeV2_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AppleObjCRuntimeV2_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

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
name|class
name|RemoteNXMapTable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|AppleObjCRuntimeV2
range|:
name|public
name|AppleObjCRuntime
block|{
name|public
operator|:
operator|~
name|AppleObjCRuntimeV2
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
name|eAppleObjC_V2
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
name|eAppleObjC_V2
return|;
block|}
name|size_t
name|GetByteOffsetForIvar
argument_list|(
argument|CompilerType&parent_qual_type
argument_list|,
argument|const char *ivar_name
argument_list|)
name|override
block|;
name|void
name|UpdateISAToDescriptorMapIfNeeded
argument_list|()
name|override
block|;
name|ConstString
name|GetActualTypeName
argument_list|(
argument|ObjCLanguageRuntime::ObjCISA isa
argument_list|)
name|override
block|;
name|ClassDescriptorSP
name|GetClassDescriptor
argument_list|(
argument|ValueObject& in_value
argument_list|)
name|override
block|;
name|ClassDescriptorSP
name|GetClassDescriptorFromISA
argument_list|(
argument|ObjCISA isa
argument_list|)
name|override
block|;
name|DeclVendor
operator|*
name|GetDeclVendor
argument_list|()
name|override
block|;
name|lldb
operator|::
name|addr_t
name|LookupRuntimeSymbol
argument_list|(
argument|const ConstString&name
argument_list|)
name|override
block|;
name|EncodingToTypeSP
name|GetEncodingToType
argument_list|()
name|override
block|;
name|TaggedPointerVendor
operator|*
name|GetTaggedPointerVendor
argument_list|()
name|override
block|{
return|return
name|m_tagged_pointer_vendor_ap
operator|.
name|get
argument_list|()
return|;
block|}
comment|// none of these are valid ISAs - we use them to infer the type
comment|// of tagged pointers - if we have something meaningful to say
comment|// we report an actual type - otherwise, we just say tagged
comment|// there is no connection between the values here and the tagged pointers map
specifier|static
specifier|const
name|ObjCLanguageRuntime
operator|::
name|ObjCISA
name|g_objc_Tagged_ISA
operator|=
literal|1
block|;
specifier|static
specifier|const
name|ObjCLanguageRuntime
operator|::
name|ObjCISA
name|g_objc_Tagged_ISA_NSAtom
operator|=
literal|2
block|;
specifier|static
specifier|const
name|ObjCLanguageRuntime
operator|::
name|ObjCISA
name|g_objc_Tagged_ISA_NSNumber
operator|=
literal|3
block|;
specifier|static
specifier|const
name|ObjCLanguageRuntime
operator|::
name|ObjCISA
name|g_objc_Tagged_ISA_NSDateTS
operator|=
literal|4
block|;
specifier|static
specifier|const
name|ObjCLanguageRuntime
operator|::
name|ObjCISA
name|g_objc_Tagged_ISA_NSManagedObject
operator|=
literal|5
block|;
specifier|static
specifier|const
name|ObjCLanguageRuntime
operator|::
name|ObjCISA
name|g_objc_Tagged_ISA_NSDate
operator|=
literal|6
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
name|private
operator|:
name|class
name|HashTableSignature
block|{
name|public
operator|:
name|HashTableSignature
argument_list|()
block|;
name|bool
name|NeedsUpdate
argument_list|(
name|Process
operator|*
name|process
argument_list|,
name|AppleObjCRuntimeV2
operator|*
name|runtime
argument_list|,
name|RemoteNXMapTable
operator|&
name|hash_table
argument_list|)
block|;
name|void
name|UpdateSignature
argument_list|(
specifier|const
name|RemoteNXMapTable
operator|&
name|hash_table
argument_list|)
block|;
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
name|class
name|NonPointerISACache
block|{
name|public
operator|:
specifier|static
name|NonPointerISACache
operator|*
name|CreateInstance
argument_list|(
name|AppleObjCRuntimeV2
operator|&
name|runtime
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|objc_module_sp
argument_list|)
block|;
name|ObjCLanguageRuntime
operator|::
name|ClassDescriptorSP
name|GetClassDescriptor
argument_list|(
argument|ObjCISA isa
argument_list|)
block|;
name|private
operator|:
name|NonPointerISACache
argument_list|(
argument|AppleObjCRuntimeV2& runtime
argument_list|,
argument|uint64_t objc_debug_isa_class_mask
argument_list|,
argument|uint64_t objc_debug_isa_magic_mask
argument_list|,
argument|uint64_t objc_debug_isa_magic_value
argument_list|)
block|;
name|bool
name|EvaluateNonPointerISA
argument_list|(
argument|ObjCISA isa
argument_list|,
argument|ObjCISA& ret_isa
argument_list|)
block|;
name|AppleObjCRuntimeV2
operator|&
name|m_runtime
block|;
name|std
operator|::
name|map
operator|<
name|ObjCISA
block|,
name|ObjCLanguageRuntime
operator|::
name|ClassDescriptorSP
operator|>
name|m_cache
block|;
name|uint64_t
name|m_objc_debug_isa_class_mask
block|;
name|uint64_t
name|m_objc_debug_isa_magic_mask
block|;
name|uint64_t
name|m_objc_debug_isa_magic_value
block|;
name|friend
name|class
name|AppleObjCRuntimeV2
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|NonPointerISACache
argument_list|)
block|;     }
block|;
name|class
name|TaggedPointerVendorV2
operator|:
name|public
name|ObjCLanguageRuntime
operator|::
name|TaggedPointerVendor
block|{
name|public
operator|:
operator|~
name|TaggedPointerVendorV2
argument_list|()
name|override
operator|=
expr|default
block|;
specifier|static
name|TaggedPointerVendorV2
operator|*
name|CreateInstance
argument_list|(
name|AppleObjCRuntimeV2
operator|&
name|runtime
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|objc_module_sp
argument_list|)
block|;
name|protected
operator|:
name|AppleObjCRuntimeV2
operator|&
name|m_runtime
block|;
name|TaggedPointerVendorV2
argument_list|(
name|AppleObjCRuntimeV2
operator|&
name|runtime
argument_list|)
operator|:
name|TaggedPointerVendor
argument_list|()
block|,
name|m_runtime
argument_list|(
argument|runtime
argument_list|)
block|{         }
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TaggedPointerVendorV2
argument_list|)
block|;     }
block|;
name|class
name|TaggedPointerVendorRuntimeAssisted
operator|:
name|public
name|TaggedPointerVendorV2
block|{
name|public
operator|:
name|bool
name|IsPossibleTaggedPointer
argument_list|(
argument|lldb::addr_t ptr
argument_list|)
name|override
block|;
name|ObjCLanguageRuntime
operator|::
name|ClassDescriptorSP
name|GetClassDescriptor
argument_list|(
argument|lldb::addr_t ptr
argument_list|)
name|override
block|;
name|protected
operator|:
name|TaggedPointerVendorRuntimeAssisted
argument_list|(
argument|AppleObjCRuntimeV2& runtime
argument_list|,
argument|uint64_t objc_debug_taggedpointer_mask
argument_list|,
argument|uint32_t objc_debug_taggedpointer_slot_shift
argument_list|,
argument|uint32_t objc_debug_taggedpointer_slot_mask
argument_list|,
argument|uint32_t objc_debug_taggedpointer_payload_lshift
argument_list|,
argument|uint32_t objc_debug_taggedpointer_payload_rshift
argument_list|,
argument|lldb::addr_t objc_debug_taggedpointer_classes
argument_list|)
block|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint8_t
operator|,
name|ObjCLanguageRuntime
operator|::
name|ClassDescriptorSP
operator|>
name|Cache
expr_stmt|;
typedef|typedef
name|Cache
operator|::
name|iterator
name|CacheIterator
expr_stmt|;
name|Cache
name|m_cache
decl_stmt|;
name|uint64_t
name|m_objc_debug_taggedpointer_mask
decl_stmt|;
name|uint32_t
name|m_objc_debug_taggedpointer_slot_shift
decl_stmt|;
name|uint32_t
name|m_objc_debug_taggedpointer_slot_mask
decl_stmt|;
name|uint32_t
name|m_objc_debug_taggedpointer_payload_lshift
decl_stmt|;
name|uint32_t
name|m_objc_debug_taggedpointer_payload_rshift
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|m_objc_debug_taggedpointer_classes
expr_stmt|;
name|friend
name|class
name|AppleObjCRuntimeV2
operator|::
name|TaggedPointerVendorV2
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TaggedPointerVendorRuntimeAssisted
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|TaggedPointerVendorLegacy
range|:
name|public
name|TaggedPointerVendorV2
block|{
name|public
operator|:
name|bool
name|IsPossibleTaggedPointer
argument_list|(
argument|lldb::addr_t ptr
argument_list|)
name|override
block|;
name|ObjCLanguageRuntime
operator|::
name|ClassDescriptorSP
name|GetClassDescriptor
argument_list|(
argument|lldb::addr_t ptr
argument_list|)
name|override
block|;
name|protected
operator|:
name|TaggedPointerVendorLegacy
argument_list|(
name|AppleObjCRuntimeV2
operator|&
name|runtime
argument_list|)
operator|:
name|TaggedPointerVendorV2
argument_list|(
argument|runtime
argument_list|)
block|{         }
name|friend
name|class
name|AppleObjCRuntimeV2
operator|::
name|TaggedPointerVendorV2
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TaggedPointerVendorLegacy
argument_list|)
block|;     }
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|DescriptorMapUpdateResult
block|{
name|bool
name|update_ran
decl_stmt|;
name|bool
name|any_found
decl_stmt|;
name|DescriptorMapUpdateResult
argument_list|(
argument|bool ran
argument_list|,
argument|bool found
argument_list|)
block|{
name|update_ran
operator|=
name|ran
expr_stmt|;
name|any_found
operator|=
name|found
expr_stmt|;
block|}
specifier|static
name|DescriptorMapUpdateResult
name|Fail
parameter_list|()
block|{
return|return
block|{
name|false
block|,
name|false
block|}
return|;
block|}
specifier|static
name|DescriptorMapUpdateResult
name|Success
parameter_list|()
block|{
return|return
block|{
name|true
block|,
name|true
block|}
return|;
block|}
block|}
struct|;
end_struct

begin_expr_stmt
name|AppleObjCRuntimeV2
argument_list|(
name|Process
operator|*
name|process
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|objc_module_sp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|ObjCISA
name|GetPointerISA
parameter_list|(
name|ObjCISA
name|isa
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|IsTaggedPointer
argument_list|(
name|lldb
operator|::
name|addr_t
name|ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|GetISAHashTablePointer
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|UpdateISAToDescriptorMapFromMemory
parameter_list|(
name|RemoteNXMapTable
modifier|&
name|hash_table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|UpdateISAToDescriptorMapDynamic
parameter_list|(
name|RemoteNXMapTable
modifier|&
name|hash_table
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|uint32_t
name|ParseClassInfoArray
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|uint32_t
name|num_class_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|DescriptorMapUpdateResult
name|UpdateISAToDescriptorMapSharedCache
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|WarnIfNoClassesCached
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|GetSharedCacheReadOnlyAddress
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|friend
name|class
name|ClassDescriptorV2
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|UtilityFunction
operator|>
name|m_get_class_info_code
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_get_class_info_args
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Mutex
name|m_get_class_info_args_mutex
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|UtilityFunction
operator|>
name|m_get_shared_cache_class_info_code
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_get_shared_cache_class_info_args
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Mutex
name|m_get_shared_cache_class_info_args_mutex
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|DeclVendor
operator|>
name|m_decl_vendor_ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_isa_hash_table_ptr
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|HashTableSignature
name|m_hash_signature
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_has_object_getClass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_loaded_objc_opt
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|NonPointerISACache
operator|>
name|m_non_pointer_isa_cache_ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|TaggedPointerVendor
operator|>
name|m_tagged_pointer_vendor_ap
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|EncodingToTypeSP
name|m_encoding_to_type_sp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_noclasses_warning_emitted
decl_stmt|;
end_decl_stmt

begin_comment
unit|};      }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_AppleObjCRuntimeV2_h_
end_comment

end_unit

