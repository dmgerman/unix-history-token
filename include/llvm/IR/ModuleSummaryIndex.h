begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ModuleSummaryIndex.h - Module Summary Index ---------*- C++ -*-===//
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
comment|/// @file
end_comment

begin_comment
comment|/// ModuleSummaryIndex.h This file contains the declarations the classes that
end_comment

begin_comment
comment|///  hold the module index and summary for function importing.
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
name|LLVM_IR_MODULESUMMARYINDEX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_MODULESUMMARYINDEX_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<array>
end_include

begin_include
include|#
directive|include
file|<cassert>
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

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
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
name|yaml
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|MappingTraits
expr_stmt|;
block|}
comment|// end namespace yaml
comment|/// \brief Class to accumulate and hold information about a callee.
struct|struct
name|CalleeInfo
block|{
name|enum
name|class
name|HotnessType
range|:
name|uint8_t
block|{
name|Unknown
operator|=
literal|0
block|,
name|Cold
operator|=
literal|1
block|,
name|None
operator|=
literal|2
block|,
name|Hot
operator|=
literal|3
block|}
decl_stmt|;
name|HotnessType
name|Hotness
init|=
name|HotnessType
operator|::
name|Unknown
decl_stmt|;
name|CalleeInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|CalleeInfo
argument_list|(
argument|HotnessType Hotness
argument_list|)
block|:
name|Hotness
argument_list|(
argument|Hotness
argument_list|)
block|{}
name|void
name|updateHotness
parameter_list|(
specifier|const
name|HotnessType
name|OtherHotness
parameter_list|)
block|{
name|Hotness
operator|=
name|std
operator|::
name|max
argument_list|(
name|Hotness
argument_list|,
name|OtherHotness
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
name|class
name|GlobalValueSummary
decl_stmt|;
name|using
name|GlobalValueSummaryList
init|=
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|GlobalValueSummary
operator|>>
decl_stmt|;
struct|struct
name|GlobalValueSummaryInfo
block|{
comment|/// The GlobalValue corresponding to this summary. This is only used in
comment|/// per-module summaries.
specifier|const
name|GlobalValue
modifier|*
name|GV
init|=
name|nullptr
decl_stmt|;
comment|/// List of global value summary structures for a particular value held
comment|/// in the GlobalValueMap. Requires a vector in the case of multiple
comment|/// COMDAT values of the same name.
name|GlobalValueSummaryList
name|SummaryList
decl_stmt|;
block|}
struct|;
comment|/// Map from global value GUID to corresponding summary structures. Use a
comment|/// std::map rather than a DenseMap so that pointers to the map's value_type
comment|/// (which are used by ValueInfo) are not invalidated by insertion. Also it will
comment|/// likely incur less overhead, as the value type is not very small and the size
comment|/// of the map is unknown, resulting in inefficiencies due to repeated
comment|/// insertions and resizing.
name|using
name|GlobalValueSummaryMapTy
init|=
name|std
operator|::
name|map
operator|<
name|GlobalValue
operator|::
name|GUID
decl_stmt|,
name|GlobalValueSummaryInfo
decl|>
decl_stmt|;
comment|/// Struct that holds a reference to a particular GUID in a global value
comment|/// summary.
struct|struct
name|ValueInfo
block|{
specifier|const
name|GlobalValueSummaryMapTy
operator|::
name|value_type
operator|*
name|Ref
operator|=
name|nullptr
expr_stmt|;
name|ValueInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
name|ValueInfo
argument_list|(
specifier|const
name|GlobalValueSummaryMapTy
operator|::
name|value_type
operator|*
name|Ref
argument_list|)
operator|:
name|Ref
argument_list|(
argument|Ref
argument_list|)
block|{}
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Ref
return|;
block|}
name|GlobalValue
operator|::
name|GUID
name|getGUID
argument_list|()
specifier|const
block|{
return|return
name|Ref
operator|->
name|first
return|;
block|}
specifier|const
name|GlobalValue
operator|*
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Ref
operator|->
name|second
operator|.
name|GV
return|;
block|}
name|ArrayRef
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|GlobalValueSummary
operator|>>
name|getSummaryList
argument_list|()
specifier|const
block|{
return|return
name|Ref
operator|->
name|second
operator|.
name|SummaryList
return|;
block|}
block|}
struct|;
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|ValueInfo
operator|>
block|{
specifier|static
specifier|inline
name|ValueInfo
name|getEmptyKey
argument_list|()
block|{
return|return
name|ValueInfo
argument_list|(
operator|(
name|GlobalValueSummaryMapTy
operator|::
name|value_type
operator|*
operator|)
operator|-
literal|1
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|ValueInfo
name|getTombstoneKey
argument_list|()
block|{
return|return
name|ValueInfo
argument_list|(
operator|(
name|GlobalValueSummaryMapTy
operator|::
name|value_type
operator|*
operator|)
operator|-
literal|2
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|ValueInfo L
argument_list|,
argument|ValueInfo R
argument_list|)
block|{
return|return
name|L
operator|.
name|Ref
operator|==
name|R
operator|.
name|Ref
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|ValueInfo I
argument_list|)
block|{
return|return
operator|(
name|uintptr_t
operator|)
name|I
operator|.
name|Ref
return|;
block|}
expr|}
block|;
comment|/// \brief Function and variable summary information to aid decisions and
comment|/// implementation of importing.
name|class
name|GlobalValueSummary
block|{
name|public
operator|:
comment|/// \brief Sububclass discriminator (for dyn_cast<> et al.)
expr|enum
name|SummaryKind
operator|:
name|unsigned
block|{
name|AliasKind
block|,
name|FunctionKind
block|,
name|GlobalVarKind
block|}
block|;
comment|/// Group flags (Linkage, NotEligibleToImport, etc.) as a bitfield.
block|struct
name|GVFlags
block|{
comment|/// \brief The linkage type of the associated global value.
comment|///
comment|/// One use is to flag values that have local linkage types and need to
comment|/// have module identifier appended before placing into the combined
comment|/// index, to disambiguate from other values with the same name.
comment|/// In the future this will be used to update and optimize linkage
comment|/// types based on global summary-based analysis.
name|unsigned
name|Linkage
operator|:
literal|4
block|;
comment|/// Indicate if the global value cannot be imported (e.g. it cannot
comment|/// be renamed or references something that can't be renamed).
name|unsigned
name|NotEligibleToImport
operator|:
literal|1
block|;
comment|/// Indicate that the global value must be considered a live root for
comment|/// index-based liveness analysis. Used for special LLVM values such as
comment|/// llvm.global_ctors that the linker does not know about.
name|unsigned
name|LiveRoot
operator|:
literal|1
block|;
comment|/// Convenience Constructors
name|explicit
name|GVFlags
argument_list|(
argument|GlobalValue::LinkageTypes Linkage
argument_list|,
argument|bool NotEligibleToImport
argument_list|,
argument|bool LiveRoot
argument_list|)
operator|:
name|Linkage
argument_list|(
name|Linkage
argument_list|)
block|,
name|NotEligibleToImport
argument_list|(
name|NotEligibleToImport
argument_list|)
block|,
name|LiveRoot
argument_list|(
argument|LiveRoot
argument_list|)
block|{}
block|}
block|;
name|private
operator|:
comment|/// Kind of summary for use in dyn_cast<> et al.
name|SummaryKind
name|Kind
block|;
name|GVFlags
name|Flags
block|;
comment|/// This is the hash of the name of the symbol in the original file. It is
comment|/// identical to the GUID for global symbols, but differs for local since the
comment|/// GUID includes the module level id in the hash.
name|GlobalValue
operator|::
name|GUID
name|OriginalName
operator|=
literal|0
block|;
comment|/// \brief Path of module IR containing value's definition, used to locate
comment|/// module during importing.
comment|///
comment|/// This is only used during parsing of the combined index, or when
comment|/// parsing the per-module index for creation of the combined summary index,
comment|/// not during writing of the per-module index which doesn't contain a
comment|/// module path string table.
name|StringRef
name|ModulePath
block|;
comment|/// List of values referenced by this global value's definition
comment|/// (either by the initializer of a global variable, or referenced
comment|/// from within a function). This does not include functions called, which
comment|/// are listed in the derived FunctionSummary object.
name|std
operator|::
name|vector
operator|<
name|ValueInfo
operator|>
name|RefEdgeList
block|;
name|protected
operator|:
name|GlobalValueSummary
argument_list|(
argument|SummaryKind K
argument_list|,
argument|GVFlags Flags
argument_list|,
argument|std::vector<ValueInfo> Refs
argument_list|)
operator|:
name|Kind
argument_list|(
name|K
argument_list|)
block|,
name|Flags
argument_list|(
name|Flags
argument_list|)
block|,
name|RefEdgeList
argument_list|(
argument|std::move(Refs)
argument_list|)
block|{}
name|public
operator|:
name|virtual
operator|~
name|GlobalValueSummary
argument_list|()
operator|=
expr|default
block|;
comment|/// Returns the hash of the original name, it is identical to the GUID for
comment|/// externally visible symbols, but not for local ones.
name|GlobalValue
operator|::
name|GUID
name|getOriginalName
argument_list|()
block|{
return|return
name|OriginalName
return|;
block|}
comment|/// Initialize the original name hash in this summary.
name|void
name|setOriginalName
argument_list|(
argument|GlobalValue::GUID Name
argument_list|)
block|{
name|OriginalName
operator|=
name|Name
block|; }
comment|/// Which kind of summary subclass this is.
name|SummaryKind
name|getSummaryKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// Set the path to the module containing this function, for use in
comment|/// the combined index.
name|void
name|setModulePath
argument_list|(
argument|StringRef ModPath
argument_list|)
block|{
name|ModulePath
operator|=
name|ModPath
block|; }
comment|/// Get the path to the module containing this function.
name|StringRef
name|modulePath
argument_list|()
specifier|const
block|{
return|return
name|ModulePath
return|;
block|}
comment|/// Get the flags for this GlobalValue (see \p struct GVFlags).
name|GVFlags
name|flags
argument_list|()
block|{
return|return
name|Flags
return|;
block|}
comment|/// Return linkage type recorded for this global value.
name|GlobalValue
operator|::
name|LinkageTypes
name|linkage
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|GlobalValue
operator|::
name|LinkageTypes
operator|>
operator|(
name|Flags
operator|.
name|Linkage
operator|)
return|;
block|}
comment|/// Sets the linkage to the value determined by global summary-based
comment|/// optimization. Will be applied in the ThinLTO backends.
name|void
name|setLinkage
argument_list|(
argument|GlobalValue::LinkageTypes Linkage
argument_list|)
block|{
name|Flags
operator|.
name|Linkage
operator|=
name|Linkage
block|;   }
comment|/// Return true if this global value can't be imported.
name|bool
name|notEligibleToImport
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|.
name|NotEligibleToImport
return|;
block|}
comment|/// Return true if this global value must be considered a root for live
comment|/// value analysis on the index.
name|bool
name|liveRoot
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|.
name|LiveRoot
return|;
block|}
comment|/// Flag that this global value must be considered a root for live
comment|/// value analysis on the index.
name|void
name|setLiveRoot
argument_list|()
block|{
name|Flags
operator|.
name|LiveRoot
operator|=
name|true
block|; }
comment|/// Flag that this global value cannot be imported.
name|void
name|setNotEligibleToImport
argument_list|()
block|{
name|Flags
operator|.
name|NotEligibleToImport
operator|=
name|true
block|; }
comment|/// Return the list of values referenced by this global value definition.
name|ArrayRef
operator|<
name|ValueInfo
operator|>
name|refs
argument_list|()
specifier|const
block|{
return|return
name|RefEdgeList
return|;
block|}
expr|}
block|;
comment|/// \brief Alias summary information.
name|class
name|AliasSummary
operator|:
name|public
name|GlobalValueSummary
block|{
name|GlobalValueSummary
operator|*
name|AliaseeSummary
block|;
name|public
operator|:
name|AliasSummary
argument_list|(
argument|GVFlags Flags
argument_list|,
argument|std::vector<ValueInfo> Refs
argument_list|)
operator|:
name|GlobalValueSummary
argument_list|(
argument|AliasKind
argument_list|,
argument|Flags
argument_list|,
argument|std::move(Refs)
argument_list|)
block|{}
comment|/// Check if this is an alias summary.
specifier|static
name|bool
name|classof
argument_list|(
argument|const GlobalValueSummary *GVS
argument_list|)
block|{
return|return
name|GVS
operator|->
name|getSummaryKind
argument_list|()
operator|==
name|AliasKind
return|;
block|}
name|void
name|setAliasee
argument_list|(
argument|GlobalValueSummary *Aliasee
argument_list|)
block|{
name|AliaseeSummary
operator|=
name|Aliasee
block|; }
specifier|const
name|GlobalValueSummary
operator|&
name|getAliasee
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|AliaseeSummary
operator|&&
literal|"Unexpected missing aliasee summary"
argument_list|)
block|;
return|return
operator|*
name|AliaseeSummary
return|;
block|}
name|GlobalValueSummary
operator|&
name|getAliasee
argument_list|()
block|{
return|return
name|const_cast
operator|<
name|GlobalValueSummary
operator|&
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|AliasSummary
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getAliasee
argument_list|()
operator|)
return|;
block|}
expr|}
block|;
comment|/// \brief Function summary information to aid decisions and implementation of
comment|/// importing.
name|class
name|FunctionSummary
operator|:
name|public
name|GlobalValueSummary
block|{
name|public
operator|:
comment|///<CalleeValueInfo, CalleeInfo> call edge pair.
name|using
name|EdgeTy
operator|=
name|std
operator|::
name|pair
operator|<
name|ValueInfo
block|,
name|CalleeInfo
operator|>
block|;
comment|/// An "identifier" for a virtual function. This contains the type identifier
comment|/// represented as a GUID and the offset from the address point to the virtual
comment|/// function pointer, where "address point" is as defined in the Itanium ABI:
comment|/// https://mentorembedded.github.io/cxx-abi/abi.html#vtable-general
block|struct
name|VFuncId
block|{
name|GlobalValue
operator|::
name|GUID
name|GUID
block|;
name|uint64_t
name|Offset
block|;   }
block|;
comment|/// A specification for a virtual function call with all constant integer
comment|/// arguments. This is used to perform virtual constant propagation on the
comment|/// summary.
block|struct
name|ConstVCall
block|{
name|VFuncId
name|VFunc
block|;
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>
name|Args
block|;   }
block|;
name|private
operator|:
comment|/// Number of instructions (ignoring debug instructions, e.g.) computed
comment|/// during the initial compile step when the summary index is first built.
name|unsigned
name|InstCount
block|;
comment|/// List of<CalleeValueInfo, CalleeInfo> call edge pairs from this function.
name|std
operator|::
name|vector
operator|<
name|EdgeTy
operator|>
name|CallGraphEdgeList
block|;
comment|/// All type identifier related information. Because these fields are
comment|/// relatively uncommon we only allocate space for them if necessary.
block|struct
name|TypeIdInfo
block|{
comment|/// List of type identifiers used by this function in llvm.type.test
comment|/// intrinsics other than by an llvm.assume intrinsic, represented as GUIDs.
name|std
operator|::
name|vector
operator|<
name|GlobalValue
operator|::
name|GUID
operator|>
name|TypeTests
block|;
comment|/// List of virtual calls made by this function using (respectively)
comment|/// llvm.assume(llvm.type.test) or llvm.type.checked.load intrinsics that do
comment|/// not have all constant integer arguments.
name|std
operator|::
name|vector
operator|<
name|VFuncId
operator|>
name|TypeTestAssumeVCalls
block|,
name|TypeCheckedLoadVCalls
block|;
comment|/// List of virtual calls made by this function using (respectively)
comment|/// llvm.assume(llvm.type.test) or llvm.type.checked.load intrinsics with
comment|/// all constant integer arguments.
name|std
operator|::
name|vector
operator|<
name|ConstVCall
operator|>
name|TypeTestAssumeConstVCalls
block|,
name|TypeCheckedLoadConstVCalls
block|;   }
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|TypeIdInfo
operator|>
name|TIdInfo
block|;
name|public
operator|:
name|FunctionSummary
argument_list|(
argument|GVFlags Flags
argument_list|,
argument|unsigned NumInsts
argument_list|,
argument|std::vector<ValueInfo> Refs
argument_list|,
argument|std::vector<EdgeTy> CGEdges
argument_list|,
argument|std::vector<GlobalValue::GUID> TypeTests
argument_list|,
argument|std::vector<VFuncId> TypeTestAssumeVCalls
argument_list|,
argument|std::vector<VFuncId> TypeCheckedLoadVCalls
argument_list|,
argument|std::vector<ConstVCall> TypeTestAssumeConstVCalls
argument_list|,
argument|std::vector<ConstVCall> TypeCheckedLoadConstVCalls
argument_list|)
operator|:
name|GlobalValueSummary
argument_list|(
name|FunctionKind
argument_list|,
name|Flags
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|Refs
argument_list|)
argument_list|)
block|,
name|InstCount
argument_list|(
name|NumInsts
argument_list|)
block|,
name|CallGraphEdgeList
argument_list|(
argument|std::move(CGEdges)
argument_list|)
block|{
if|if
condition|(
operator|!
name|TypeTests
operator|.
name|empty
argument_list|()
operator|||
operator|!
name|TypeTestAssumeVCalls
operator|.
name|empty
argument_list|()
operator|||
operator|!
name|TypeCheckedLoadVCalls
operator|.
name|empty
argument_list|()
operator|||
operator|!
name|TypeTestAssumeConstVCalls
operator|.
name|empty
argument_list|()
operator|||
operator|!
name|TypeCheckedLoadConstVCalls
operator|.
name|empty
argument_list|()
condition|)
name|TIdInfo
operator|=
name|llvm
operator|::
name|make_unique
operator|<
name|TypeIdInfo
operator|>
operator|(
name|TypeIdInfo
block|{
name|std
operator|::
name|move
argument_list|(
name|TypeTests
argument_list|)
block|,
name|std
operator|::
name|move
argument_list|(
name|TypeTestAssumeVCalls
argument_list|)
block|,
name|std
operator|::
name|move
argument_list|(
name|TypeCheckedLoadVCalls
argument_list|)
block|,
name|std
operator|::
name|move
argument_list|(
name|TypeTestAssumeConstVCalls
argument_list|)
block|,
name|std
operator|::
name|move
argument_list|(
argument|TypeCheckedLoadConstVCalls
argument_list|)
block|}
operator|)
expr_stmt|;
block|}
comment|/// Check if this is a function summary.
specifier|static
name|bool
name|classof
argument_list|(
argument|const GlobalValueSummary *GVS
argument_list|)
block|{
return|return
name|GVS
operator|->
name|getSummaryKind
argument_list|()
operator|==
name|FunctionKind
return|;
block|}
comment|/// Get the instruction count recorded for this function.
name|unsigned
name|instCount
argument_list|()
specifier|const
block|{
return|return
name|InstCount
return|;
block|}
comment|/// Return the list of<CalleeValueInfo, CalleeInfo> pairs.
name|ArrayRef
operator|<
name|EdgeTy
operator|>
name|calls
argument_list|()
specifier|const
block|{
return|return
name|CallGraphEdgeList
return|;
block|}
comment|/// Returns the list of type identifiers used by this function in
comment|/// llvm.type.test intrinsics other than by an llvm.assume intrinsic,
comment|/// represented as GUIDs.
name|ArrayRef
operator|<
name|GlobalValue
operator|::
name|GUID
operator|>
name|type_tests
argument_list|()
specifier|const
block|{
if|if
condition|(
name|TIdInfo
condition|)
return|return
name|TIdInfo
operator|->
name|TypeTests
return|;
return|return
block|{}
return|;
block|}
comment|/// Returns the list of virtual calls made by this function using
comment|/// llvm.assume(llvm.type.test) intrinsics that do not have all constant
comment|/// integer arguments.
name|ArrayRef
operator|<
name|VFuncId
operator|>
name|type_test_assume_vcalls
argument_list|()
specifier|const
block|{
if|if
condition|(
name|TIdInfo
condition|)
return|return
name|TIdInfo
operator|->
name|TypeTestAssumeVCalls
return|;
return|return
block|{}
return|;
block|}
comment|/// Returns the list of virtual calls made by this function using
comment|/// llvm.type.checked.load intrinsics that do not have all constant integer
comment|/// arguments.
name|ArrayRef
operator|<
name|VFuncId
operator|>
name|type_checked_load_vcalls
argument_list|()
specifier|const
block|{
if|if
condition|(
name|TIdInfo
condition|)
return|return
name|TIdInfo
operator|->
name|TypeCheckedLoadVCalls
return|;
return|return
block|{}
return|;
block|}
comment|/// Returns the list of virtual calls made by this function using
comment|/// llvm.assume(llvm.type.test) intrinsics with all constant integer
comment|/// arguments.
name|ArrayRef
operator|<
name|ConstVCall
operator|>
name|type_test_assume_const_vcalls
argument_list|()
specifier|const
block|{
if|if
condition|(
name|TIdInfo
condition|)
return|return
name|TIdInfo
operator|->
name|TypeTestAssumeConstVCalls
return|;
return|return
block|{}
return|;
block|}
comment|/// Returns the list of virtual calls made by this function using
comment|/// llvm.type.checked.load intrinsics with all constant integer arguments.
name|ArrayRef
operator|<
name|ConstVCall
operator|>
name|type_checked_load_const_vcalls
argument_list|()
specifier|const
block|{
if|if
condition|(
name|TIdInfo
condition|)
return|return
name|TIdInfo
operator|->
name|TypeCheckedLoadConstVCalls
return|;
return|return
block|{}
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Add a type test to the summary. This is used by WholeProgramDevirt if we
end_comment

begin_comment
comment|/// were unable to devirtualize a checked call.
end_comment

begin_decl_stmt
name|void
name|addTypeTest
argument_list|(
name|GlobalValue
operator|::
name|GUID
name|Guid
argument_list|)
block|{
if|if
condition|(
operator|!
name|TIdInfo
condition|)
name|TIdInfo
operator|=
name|llvm
operator|::
name|make_unique
operator|<
name|TypeIdInfo
operator|>
operator|(
operator|)
expr_stmt|;
name|TIdInfo
operator|->
name|TypeTests
operator|.
name|push_back
argument_list|(
name|Guid
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|FunctionSummary
operator|::
name|VFuncId
operator|>
block|{
specifier|static
name|FunctionSummary
operator|::
name|VFuncId
name|getEmptyKey
argument_list|()
block|{
return|return
block|{
literal|0
block|,
name|uint64_t
argument_list|(
argument|-
literal|1
argument_list|)
block|}
return|;
block|}
specifier|static
name|FunctionSummary
operator|::
name|VFuncId
name|getTombstoneKey
argument_list|()
block|{
return|return
block|{
literal|0
block|,
name|uint64_t
argument_list|(
argument|-
literal|2
argument_list|)
block|}
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
name|bool
name|isEqual
argument_list|(
name|FunctionSummary
operator|::
name|VFuncId
name|L
argument_list|,
name|FunctionSummary
operator|::
name|VFuncId
name|R
argument_list|)
block|{
return|return
name|L
operator|.
name|GUID
operator|==
name|R
operator|.
name|GUID
operator|&&
name|L
operator|.
name|Offset
operator|==
name|R
operator|.
name|Offset
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|getHashValue
argument_list|(
name|FunctionSummary
operator|::
name|VFuncId
name|I
argument_list|)
block|{
return|return
name|I
operator|.
name|GUID
return|;
block|}
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|FunctionSummary
operator|::
name|ConstVCall
operator|>
block|{
specifier|static
name|FunctionSummary
operator|::
name|ConstVCall
name|getEmptyKey
argument_list|()
block|{
return|return
block|{
block|{
literal|0
block|,
name|uint64_t
argument_list|(
argument|-
literal|1
argument_list|)
block|}
block|,
block|{}
block|}
return|;
block|}
specifier|static
name|FunctionSummary
operator|::
name|ConstVCall
name|getTombstoneKey
argument_list|()
block|{
return|return
block|{
block|{
literal|0
block|,
name|uint64_t
argument_list|(
argument|-
literal|2
argument_list|)
block|}
block|,
block|{}
block|}
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
name|bool
name|isEqual
argument_list|(
name|FunctionSummary
operator|::
name|ConstVCall
name|L
argument_list|,
name|FunctionSummary
operator|::
name|ConstVCall
name|R
argument_list|)
block|{
return|return
name|DenseMapInfo
operator|<
name|FunctionSummary
operator|::
name|VFuncId
operator|>
operator|::
name|isEqual
argument_list|(
name|L
operator|.
name|VFunc
argument_list|,
name|R
operator|.
name|VFunc
argument_list|)
operator|&&
name|L
operator|.
name|Args
operator|==
name|R
operator|.
name|Args
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|getHashValue
argument_list|(
name|FunctionSummary
operator|::
name|ConstVCall
name|I
argument_list|)
block|{
return|return
name|I
operator|.
name|VFunc
operator|.
name|GUID
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Global variable summary information to aid decisions and
end_comment

begin_comment
comment|/// implementation of importing.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Currently this doesn't add anything to the base \p GlobalValueSummary,
end_comment

begin_comment
comment|/// but is a placeholder as additional info may be added to the summary
end_comment

begin_comment
comment|/// for variables.
end_comment

begin_decl_stmt
name|class
name|GlobalVarSummary
range|:
name|public
name|GlobalValueSummary
block|{
name|public
operator|:
name|GlobalVarSummary
argument_list|(
argument|GVFlags Flags
argument_list|,
argument|std::vector<ValueInfo> Refs
argument_list|)
operator|:
name|GlobalValueSummary
argument_list|(
argument|GlobalVarKind
argument_list|,
argument|Flags
argument_list|,
argument|std::move(Refs)
argument_list|)
block|{}
comment|/// Check if this is a global variable summary.
specifier|static
name|bool
name|classof
argument_list|(
argument|const GlobalValueSummary *GVS
argument_list|)
block|{
return|return
name|GVS
operator|->
name|getSummaryKind
argument_list|()
operator|==
name|GlobalVarKind
return|;
block|}
expr|}
block|;  struct
name|TypeTestResolution
block|{
comment|/// Specifies which kind of type check we should emit for this byte array.
comment|/// See http://clang.llvm.org/docs/ControlFlowIntegrityDesign.html for full
comment|/// details on each kind of check; the enumerators are described with
comment|/// reference to that document.
block|enum
name|Kind
block|{
name|Unsat
block|,
comment|///< Unsatisfiable type (i.e. no global has this type metadata)
name|ByteArray
block|,
comment|///< Test a byte array (first example)
name|Inline
block|,
comment|///< Inlined bit vector ("Short Inline Bit Vectors")
name|Single
block|,
comment|///< Single element (last example in "Short Inline Bit Vectors")
name|AllOnes
block|,
comment|///< All-ones bit vector ("Eliminating Bit Vector Checks for
comment|///  All-Ones Bit Vectors")
block|}
name|TheKind
operator|=
name|Unsat
block|;
comment|/// Range of size-1 expressed as a bit width. For example, if the size is in
comment|/// range [1,256], this number will be 8. This helps generate the most compact
comment|/// instruction sequences.
name|unsigned
name|SizeM1BitWidth
operator|=
literal|0
block|; }
block|;  struct
name|WholeProgramDevirtResolution
block|{   enum
name|Kind
block|{
name|Indir
block|,
comment|///< Just do a regular virtual call
name|SingleImpl
block|,
comment|///< Single implementation devirtualization
block|}
name|TheKind
operator|=
name|Indir
block|;
name|std
operator|::
name|string
name|SingleImplName
block|;    struct
name|ByArg
block|{     enum
name|Kind
block|{
name|Indir
block|,
comment|///< Just do a regular virtual call
name|UniformRetVal
block|,
comment|///< Uniform return value optimization
name|UniqueRetVal
block|,
comment|///< Unique return value optimization
name|VirtualConstProp
block|,
comment|///< Virtual constant propagation
block|}
name|TheKind
operator|=
name|Indir
block|;
comment|/// Additional information for the resolution:
comment|/// - UniformRetVal: the uniform return value.
comment|/// - UniqueRetVal: the return value associated with the unique vtable (0 or
comment|///   1).
name|uint64_t
name|Info
operator|=
literal|0
block|;   }
block|;
comment|/// Resolutions for calls with all constant integer arguments (excluding the
comment|/// first argument, "this"), where the key is the argument vector.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>
block|,
name|ByArg
operator|>
name|ResByArg
block|; }
block|;  struct
name|TypeIdSummary
block|{
name|TypeTestResolution
name|TTRes
block|;
comment|/// Mapping from byte offset to whole-program devirt resolution for that
comment|/// (typeid, byte offset) pair.
name|std
operator|::
name|map
operator|<
name|uint64_t
block|,
name|WholeProgramDevirtResolution
operator|>
name|WPDRes
block|; }
block|;
comment|/// 160 bits SHA1
name|using
name|ModuleHash
operator|=
name|std
operator|::
name|array
operator|<
name|uint32_t
block|,
literal|5
operator|>
block|;
comment|/// Type used for iterating through the global value summary map.
name|using
name|const_gvsummary_iterator
operator|=
name|GlobalValueSummaryMapTy
operator|::
name|const_iterator
block|;
name|using
name|gvsummary_iterator
operator|=
name|GlobalValueSummaryMapTy
operator|::
name|iterator
block|;
comment|/// String table to hold/own module path strings, which additionally holds the
comment|/// module ID assigned to each module during the plugin step, as well as a hash
comment|/// of the module. The StringMap makes a copy of and owns inserted strings.
name|using
name|ModulePathStringTableTy
operator|=
name|StringMap
operator|<
name|std
operator|::
name|pair
operator|<
name|uint64_t
block|,
name|ModuleHash
operator|>>
block|;
comment|/// Map of global value GUID to its summary, used to identify values defined in
comment|/// a particular module, and provide efficient access to their summary.
name|using
name|GVSummaryMapTy
operator|=
name|std
operator|::
name|map
operator|<
name|GlobalValue
operator|::
name|GUID
block|,
name|GlobalValueSummary
operator|*
operator|>
block|;
comment|/// Class to hold module path string table and global value map,
comment|/// and encapsulate methods for operating on them.
name|class
name|ModuleSummaryIndex
block|{
name|private
operator|:
comment|/// Map from value name to list of summary instances for values of that
comment|/// name (may be duplicates in the COMDAT case, e.g.).
name|GlobalValueSummaryMapTy
name|GlobalValueMap
block|;
comment|/// Holds strings for combined index, mapping to the corresponding module ID.
name|ModulePathStringTableTy
name|ModulePathStringTable
block|;
comment|/// Mapping from type identifiers to summary information for that type
comment|/// identifier.
comment|// FIXME: Add bitcode read/write support for this field.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
block|,
name|TypeIdSummary
operator|>
name|TypeIdMap
block|;
comment|/// Mapping from original ID to GUID. If original ID can map to multiple
comment|/// GUIDs, it will be mapped to 0.
name|std
operator|::
name|map
operator|<
name|GlobalValue
operator|::
name|GUID
block|,
name|GlobalValue
operator|::
name|GUID
operator|>
name|OidGuidMap
block|;
comment|// YAML I/O support.
name|friend
name|yaml
operator|::
name|MappingTraits
operator|<
name|ModuleSummaryIndex
operator|>
block|;
name|GlobalValueSummaryMapTy
operator|::
name|value_type
operator|*
name|getOrInsertValuePtr
argument_list|(
argument|GlobalValue::GUID GUID
argument_list|)
block|{
return|return
operator|&
operator|*
name|GlobalValueMap
operator|.
name|emplace
argument_list|(
name|GUID
argument_list|,
name|GlobalValueSummaryInfo
block|{}
argument_list|)
operator|.
name|first
return|;
block|}
name|public
operator|:
name|gvsummary_iterator
name|begin
argument_list|()
block|{
return|return
name|GlobalValueMap
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_gvsummary_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|GlobalValueMap
operator|.
name|begin
argument_list|()
return|;
block|}
name|gvsummary_iterator
name|end
argument_list|()
block|{
return|return
name|GlobalValueMap
operator|.
name|end
argument_list|()
return|;
block|}
name|const_gvsummary_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|GlobalValueMap
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|GlobalValueMap
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Return a ValueInfo for GUID if it exists, otherwise return ValueInfo().
name|ValueInfo
name|getValueInfo
argument_list|(
argument|GlobalValue::GUID GUID
argument_list|)
specifier|const
block|{
name|auto
name|I
operator|=
name|GlobalValueMap
operator|.
name|find
argument_list|(
name|GUID
argument_list|)
block|;
return|return
name|ValueInfo
argument_list|(
name|I
operator|==
name|GlobalValueMap
operator|.
name|end
argument_list|()
condition|?
name|nullptr
else|:
operator|&
operator|*
name|I
argument_list|)
return|;
block|}
comment|/// Return a ValueInfo for \p GUID.
name|ValueInfo
name|getOrInsertValueInfo
argument_list|(
argument|GlobalValue::GUID GUID
argument_list|)
block|{
return|return
name|ValueInfo
argument_list|(
name|getOrInsertValuePtr
argument_list|(
name|GUID
argument_list|)
argument_list|)
return|;
block|}
comment|/// Return a ValueInfo for \p GV and mark it as belonging to GV.
name|ValueInfo
name|getOrInsertValueInfo
argument_list|(
argument|const GlobalValue *GV
argument_list|)
block|{
name|auto
name|VP
operator|=
name|getOrInsertValuePtr
argument_list|(
name|GV
operator|->
name|getGUID
argument_list|()
argument_list|)
block|;
name|VP
operator|->
name|second
operator|.
name|GV
operator|=
name|GV
block|;
return|return
name|ValueInfo
argument_list|(
name|VP
argument_list|)
return|;
block|}
comment|/// Return the GUID for \p OriginalId in the OidGuidMap.
name|GlobalValue
operator|::
name|GUID
name|getGUIDFromOriginalID
argument_list|(
argument|GlobalValue::GUID OriginalID
argument_list|)
specifier|const
block|{
specifier|const
name|auto
name|I
operator|=
name|OidGuidMap
operator|.
name|find
argument_list|(
name|OriginalID
argument_list|)
block|;
return|return
name|I
operator|==
name|OidGuidMap
operator|.
name|end
argument_list|()
condition|?
literal|0
else|:
name|I
operator|->
name|second
return|;
block|}
comment|/// Add a global value summary for a value of the given name.
name|void
name|addGlobalValueSummary
argument_list|(
argument|StringRef ValueName
argument_list|,
argument|std::unique_ptr<GlobalValueSummary> Summary
argument_list|)
block|{
name|addGlobalValueSummary
argument_list|(
name|getOrInsertValueInfo
argument_list|(
name|GlobalValue
operator|::
name|getGUID
argument_list|(
name|ValueName
argument_list|)
argument_list|)
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|Summary
argument_list|)
argument_list|)
block|;   }
comment|/// Add a global value summary for the given ValueInfo.
name|void
name|addGlobalValueSummary
argument_list|(
argument|ValueInfo VI
argument_list|,
argument|std::unique_ptr<GlobalValueSummary> Summary
argument_list|)
block|{
name|addOriginalName
argument_list|(
name|VI
operator|.
name|getGUID
argument_list|()
argument_list|,
name|Summary
operator|->
name|getOriginalName
argument_list|()
argument_list|)
block|;
comment|// Here we have a notionally const VI, but the value it points to is owned
comment|// by the non-const *this.
name|const_cast
operator|<
name|GlobalValueSummaryMapTy
operator|::
name|value_type
operator|*
operator|>
operator|(
name|VI
operator|.
name|Ref
operator|)
operator|->
name|second
operator|.
name|SummaryList
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Summary
argument_list|)
argument_list|)
block|;   }
comment|/// Add an original name for the value of the given GUID.
name|void
name|addOriginalName
argument_list|(
argument|GlobalValue::GUID ValueGUID
argument_list|,
argument|GlobalValue::GUID OrigGUID
argument_list|)
block|{
if|if
condition|(
name|OrigGUID
operator|==
literal|0
operator|||
name|ValueGUID
operator|==
name|OrigGUID
condition|)
return|return;
if|if
condition|(
name|OidGuidMap
operator|.
name|count
argument_list|(
name|OrigGUID
argument_list|)
operator|&&
name|OidGuidMap
index|[
name|OrigGUID
index|]
operator|!=
name|ValueGUID
condition|)
name|OidGuidMap
index|[
name|OrigGUID
index|]
operator|=
literal|0
expr_stmt|;
else|else
name|OidGuidMap
index|[
name|OrigGUID
index|]
operator|=
name|ValueGUID
expr_stmt|;
block|}
comment|/// Find the summary for global \p GUID in module \p ModuleId, or nullptr if
comment|/// not found.
name|GlobalValueSummary
operator|*
name|findSummaryInModule
argument_list|(
argument|GlobalValue::GUID ValueGUID
argument_list|,
argument|StringRef ModuleId
argument_list|)
specifier|const
block|{
name|auto
name|CalleeInfo
operator|=
name|getValueInfo
argument_list|(
name|ValueGUID
argument_list|)
block|;
if|if
condition|(
operator|!
name|CalleeInfo
condition|)
block|{
return|return
name|nullptr
return|;
comment|// This function does not have a summary
block|}
name|auto
name|Summary
init|=
name|llvm
operator|::
name|find_if
argument_list|(
name|CalleeInfo
operator|.
name|getSummaryList
argument_list|()
argument_list|,
index|[
operator|&
index|]
operator|(
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|GlobalValueSummary
operator|>
operator|&
name|Summary
operator|)
block|{
return|return
name|Summary
operator|->
name|modulePath
argument_list|()
operator|==
name|ModuleId
return|;
block|}
argument_list|)
decl_stmt|;
if|if
condition|(
name|Summary
operator|==
name|CalleeInfo
operator|.
name|getSummaryList
argument_list|()
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
end_decl_stmt

begin_return
return|return
name|Summary
operator|->
name|get
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// Returns the first GlobalValueSummary for \p GV, asserting that there
end_comment

begin_comment
comment|/// is only one if \p PerModuleIndex.
end_comment

begin_expr_stmt
unit|GlobalValueSummary
operator|*
name|getGlobalValueSummary
argument_list|(
argument|const GlobalValue&GV
argument_list|,
argument|bool PerModuleIndex = true
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|GV
operator|.
name|hasName
argument_list|()
operator|&&
literal|"Can't get GlobalValueSummary for GV with no name"
argument_list|)
block|;
return|return
name|getGlobalValueSummary
argument_list|(
name|GlobalValue
operator|::
name|getGUID
argument_list|(
name|GV
operator|.
name|getName
argument_list|()
argument_list|)
argument_list|,
name|PerModuleIndex
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the first GlobalValueSummary for \p ValueGUID, asserting that
end_comment

begin_comment
comment|/// there
end_comment

begin_comment
comment|/// is only one if \p PerModuleIndex.
end_comment

begin_decl_stmt
name|GlobalValueSummary
modifier|*
name|getGlobalValueSummary
argument_list|(
name|GlobalValue
operator|::
name|GUID
name|ValueGUID
argument_list|,
name|bool
name|PerModuleIndex
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Table of modules, containing module hash and id.
end_comment

begin_expr_stmt
specifier|const
name|StringMap
operator|<
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|ModuleHash
operator|>>
operator|&
name|modulePaths
argument_list|()
specifier|const
block|{
return|return
name|ModulePathStringTable
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Table of modules, containing hash and id.
end_comment

begin_expr_stmt
name|StringMap
operator|<
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|ModuleHash
operator|>>
operator|&
name|modulePaths
argument_list|()
block|{
return|return
name|ModulePathStringTable
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Get the module ID recorded for the given module path.
end_comment

begin_decl_stmt
name|uint64_t
name|getModuleId
argument_list|(
specifier|const
name|StringRef
name|ModPath
argument_list|)
decl|const
block|{
return|return
name|ModulePathStringTable
operator|.
name|lookup
argument_list|(
name|ModPath
argument_list|)
operator|.
name|first
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Get the module SHA1 hash recorded for the given module path.
end_comment

begin_decl_stmt
specifier|const
name|ModuleHash
modifier|&
name|getModuleHash
argument_list|(
specifier|const
name|StringRef
name|ModPath
argument_list|)
decl|const
block|{
name|auto
name|It
init|=
name|ModulePathStringTable
operator|.
name|find
argument_list|(
name|ModPath
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|It
operator|!=
name|ModulePathStringTable
operator|.
name|end
argument_list|()
operator|&&
literal|"Module not registered"
argument_list|)
expr_stmt|;
return|return
name|It
operator|->
name|second
operator|.
name|second
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Convenience method for creating a promoted global name
end_comment

begin_comment
comment|/// for the given value name of a local, and its original module's ID.
end_comment

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|getGlobalNameForLocal
argument_list|(
argument|StringRef Name
argument_list|,
argument|ModuleHash ModHash
argument_list|)
block|{
name|SmallString
operator|<
literal|256
operator|>
name|NewName
argument_list|(
name|Name
argument_list|)
block|;
name|NewName
operator|+=
literal|".llvm."
block|;
name|NewName
operator|+=
name|utohexstr
argument_list|(
name|ModHash
index|[
literal|0
index|]
argument_list|)
block|;
comment|// Take the first 32 bits
return|return
name|NewName
operator|.
name|str
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Helper to obtain the unpromoted name for a global value (or the original
end_comment

begin_comment
comment|/// name if not promoted).
end_comment

begin_function
specifier|static
name|StringRef
name|getOriginalNameBeforePromote
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|StringRef
operator|>
name|Pair
operator|=
name|Name
operator|.
name|split
argument_list|(
literal|".llvm."
argument_list|)
expr_stmt|;
return|return
name|Pair
operator|.
name|first
return|;
block|}
end_function

begin_comment
comment|/// Add a new module path with the given \p Hash, mapped to the given \p
end_comment

begin_comment
comment|/// ModID, and return an iterator to the entry in the index.
end_comment

begin_expr_stmt
name|ModulePathStringTableTy
operator|::
name|iterator
name|addModulePath
argument_list|(
argument|StringRef ModPath
argument_list|,
argument|uint64_t ModId
argument_list|,
argument|ModuleHash Hash = ModuleHash{{
literal|0
argument|}}
argument_list|)
block|{
return|return
name|ModulePathStringTable
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|ModPath
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|ModId
argument_list|,
name|Hash
argument_list|)
argument_list|)
argument_list|)
operator|.
name|first
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Check if the given Module has any functions available for exporting
end_comment

begin_comment
comment|/// in the index. We consider any module present in the ModulePathStringTable
end_comment

begin_comment
comment|/// to have exported functions.
end_comment

begin_decl_stmt
name|bool
name|hasExportedFunctions
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|)
decl|const
block|{
return|return
name|ModulePathStringTable
operator|.
name|count
argument_list|(
name|M
operator|.
name|getModuleIdentifier
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|TypeIdSummary
operator|>
operator|&
name|typeIds
argument_list|()
specifier|const
block|{
return|return
name|TypeIdMap
return|;
block|}
end_expr_stmt

begin_comment
comment|/// This accessor should only be used when exporting because it can mutate the
end_comment

begin_comment
comment|/// map.
end_comment

begin_function
name|TypeIdSummary
modifier|&
name|getOrInsertTypeIdSummary
parameter_list|(
name|StringRef
name|TypeId
parameter_list|)
block|{
return|return
name|TypeIdMap
index|[
name|TypeId
index|]
return|;
block|}
end_function

begin_comment
comment|/// This returns either a pointer to the type id summary (if present in the
end_comment

begin_comment
comment|/// summary map) or null (if not present). This may be used when importing.
end_comment

begin_decl_stmt
specifier|const
name|TypeIdSummary
modifier|*
name|getTypeIdSummary
argument_list|(
name|StringRef
name|TypeId
argument_list|)
decl|const
block|{
name|auto
name|I
init|=
name|TypeIdMap
operator|.
name|find
argument_list|(
name|TypeId
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|TypeIdMap
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
operator|&
name|I
operator|->
name|second
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Collect for the given module the list of function it defines
end_comment

begin_comment
comment|/// (GUID -> Summary).
end_comment

begin_decl_stmt
name|void
name|collectDefinedFunctionsForModule
argument_list|(
name|StringRef
name|ModulePath
argument_list|,
name|GVSummaryMapTy
operator|&
name|GVSummaryMap
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Collect for each module the list of Summaries it defines (GUID ->
end_comment

begin_comment
comment|/// Summary).
end_comment

begin_decl_stmt
name|void
name|collectDefinedGVSummariesPerModule
argument_list|(
name|StringMap
operator|<
name|GVSummaryMapTy
operator|>
operator|&
name|ModuleToDefinedGVSummaries
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_MODULESUMMARYINDEX_H
end_comment

end_unit

