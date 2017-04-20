begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InstrumentationMap.h - XRay Instrumentation Map ----------*- C++ -*-===//
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
comment|// Defines the interface for extracting the instrumentation map from an
end_comment

begin_comment
comment|// XRay-instrumented binary.
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
name|LLVM_XRAY_INSTRUMENTATION_MAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_XRAY_INSTRUMENTATION_MAP_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLTraits.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|xray
block|{
comment|// Forward declare to make a friend.
name|class
name|InstrumentationMap
decl_stmt|;
comment|/// Loads the instrumentation map from |Filename|. This auto-deduces the type of
comment|/// the instrumentation map.
name|Expected
operator|<
name|InstrumentationMap
operator|>
name|loadInstrumentationMap
argument_list|(
argument|StringRef Filename
argument_list|)
expr_stmt|;
comment|/// Represents an XRay instrumentation sled entry from an object file.
struct|struct
name|SledEntry
block|{
comment|/// Each entry here represents the kinds of supported instrumentation map
comment|/// entries.
name|enum
name|class
name|FunctionKinds
block|{
name|ENTRY
operator|,
name|EXIT
operator|,
name|TAIL
block|}
empty_stmt|;
comment|/// The address of the sled.
name|uint64_t
name|Address
decl_stmt|;
comment|/// The address of the function.
name|uint64_t
name|Function
decl_stmt|;
comment|/// The kind of sled.
name|FunctionKinds
name|Kind
decl_stmt|;
comment|/// Whether the sled was annotated to always be instrumented.
name|bool
name|AlwaysInstrument
decl_stmt|;
block|}
struct|;
struct|struct
name|YAMLXRaySledEntry
block|{
name|int32_t
name|FuncId
decl_stmt|;
name|yaml
operator|::
name|Hex64
name|Address
expr_stmt|;
name|yaml
operator|::
name|Hex64
name|Function
expr_stmt|;
name|SledEntry
operator|::
name|FunctionKinds
name|Kind
expr_stmt|;
name|bool
name|AlwaysInstrument
decl_stmt|;
name|std
operator|::
name|string
name|FunctionName
expr_stmt|;
block|}
struct|;
comment|/// The InstrumentationMap represents the computed function id's and indicated
comment|/// function addresses from an object file (or a YAML file). This provides an
comment|/// interface to just the mapping between the function id, and the function
comment|/// address.
comment|///
comment|/// We also provide raw access to the actual instrumentation map entries we find
comment|/// associated with a particular object file.
comment|///
name|class
name|InstrumentationMap
block|{
name|public
label|:
name|using
name|FunctionAddressMap
init|=
name|std
operator|::
name|unordered_map
operator|<
name|int32_t
decl_stmt|,
name|uint64_t
decl|>
decl_stmt|;
name|using
name|FunctionAddressReverseMap
init|=
name|std
operator|::
name|unordered_map
operator|<
name|uint64_t
decl_stmt|,
name|int32_t
decl|>
decl_stmt|;
name|using
name|SledContainer
init|=
name|std
operator|::
name|vector
operator|<
name|SledEntry
operator|>
decl_stmt|;
name|private
label|:
name|SledContainer
name|Sleds
decl_stmt|;
name|FunctionAddressMap
name|FunctionAddresses
decl_stmt|;
name|FunctionAddressReverseMap
name|FunctionIds
decl_stmt|;
name|friend
name|Expected
operator|<
name|InstrumentationMap
operator|>
name|loadInstrumentationMap
argument_list|(
name|StringRef
argument_list|)
expr_stmt|;
name|public
label|:
comment|/// Provides a raw accessor to the unordered map of function addresses.
specifier|const
name|FunctionAddressMap
modifier|&
name|getFunctionAddresses
parameter_list|()
block|{
return|return
name|FunctionAddresses
return|;
block|}
comment|/// Returns an XRay computed function id, provided a function address.
name|Optional
operator|<
name|int32_t
operator|>
name|getFunctionId
argument_list|(
argument|uint64_t Addr
argument_list|)
specifier|const
expr_stmt|;
comment|/// Returns the function address for a function id.
name|Optional
operator|<
name|uint64_t
operator|>
name|getFunctionAddr
argument_list|(
argument|int32_t FuncId
argument_list|)
specifier|const
expr_stmt|;
comment|/// Provide read-only access to the entries of the instrumentation map.
specifier|const
name|SledContainer
operator|&
name|sleds
argument_list|()
specifier|const
block|{
return|return
name|Sleds
return|;
block|}
empty_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace xray
name|namespace
name|yaml
block|{
name|template
operator|<
operator|>
expr|struct
name|ScalarEnumerationTraits
operator|<
name|xray
operator|::
name|SledEntry
operator|::
name|FunctionKinds
operator|>
block|{
specifier|static
name|void
name|enumeration
argument_list|(
argument|IO&IO
argument_list|,
argument|xray::SledEntry::FunctionKinds&Kind
argument_list|)
block|{
name|IO
operator|.
name|enumCase
argument_list|(
name|Kind
argument_list|,
literal|"function-enter"
argument_list|,
name|xray
operator|::
name|SledEntry
operator|::
name|FunctionKinds
operator|::
name|ENTRY
argument_list|)
block|;
name|IO
operator|.
name|enumCase
argument_list|(
name|Kind
argument_list|,
literal|"function-exit"
argument_list|,
name|xray
operator|::
name|SledEntry
operator|::
name|FunctionKinds
operator|::
name|EXIT
argument_list|)
block|;
name|IO
operator|.
name|enumCase
argument_list|(
name|Kind
argument_list|,
literal|"tail-exit"
argument_list|,
name|xray
operator|::
name|SledEntry
operator|::
name|FunctionKinds
operator|::
name|TAIL
argument_list|)
block|;   }
block|}
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|xray
operator|::
name|YAMLXRaySledEntry
operator|>
block|{
specifier|static
name|void
name|mapping
argument_list|(
argument|IO&IO
argument_list|,
argument|xray::YAMLXRaySledEntry&Entry
argument_list|)
block|{
name|IO
operator|.
name|mapRequired
argument_list|(
literal|"id"
argument_list|,
name|Entry
operator|.
name|FuncId
argument_list|)
block|;
name|IO
operator|.
name|mapRequired
argument_list|(
literal|"address"
argument_list|,
name|Entry
operator|.
name|Address
argument_list|)
block|;
name|IO
operator|.
name|mapRequired
argument_list|(
literal|"function"
argument_list|,
name|Entry
operator|.
name|Function
argument_list|)
block|;
name|IO
operator|.
name|mapRequired
argument_list|(
literal|"kind"
argument_list|,
name|Entry
operator|.
name|Kind
argument_list|)
block|;
name|IO
operator|.
name|mapRequired
argument_list|(
literal|"always-instrument"
argument_list|,
name|Entry
operator|.
name|AlwaysInstrument
argument_list|)
block|;
name|IO
operator|.
name|mapOptional
argument_list|(
literal|"function-name"
argument_list|,
name|Entry
operator|.
name|FunctionName
argument_list|)
block|;   }
specifier|static
name|constexpr
name|bool
name|flow
operator|=
name|true
block|; }
expr_stmt|;
block|}
comment|// end namespace yaml
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_macro
name|LLVM_YAML_IS_SEQUENCE_VECTOR
argument_list|(
argument|xray::YAMLXRaySledEntry
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_XRAY_INSTRUMENTATION_MAP_H
end_comment

end_unit

