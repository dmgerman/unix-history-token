begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ModuleSummaryIndex.h - Module Summary Index --------*- C++ -*-===//
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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
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
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|<array>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Class to accumulate and hold information about a callee.
struct|struct
name|CalleeInfo
block|{
comment|/// The static number of callsites calling corresponding function.
name|unsigned
name|CallsiteCount
decl_stmt|;
comment|/// The cumulative profile count of calls to corresponding function
comment|/// (if using PGO, otherwise 0).
name|uint64_t
name|ProfileCount
decl_stmt|;
name|CalleeInfo
argument_list|()
operator|:
name|CallsiteCount
argument_list|(
literal|0
argument_list|)
operator|,
name|ProfileCount
argument_list|(
literal|0
argument_list|)
block|{}
name|CalleeInfo
argument_list|(
argument|unsigned CallsiteCount
argument_list|,
argument|uint64_t ProfileCount
argument_list|)
operator|:
name|CallsiteCount
argument_list|(
name|CallsiteCount
argument_list|)
operator|,
name|ProfileCount
argument_list|(
argument|ProfileCount
argument_list|)
block|{}
name|CalleeInfo
operator|&
name|operator
operator|+=
operator|(
name|uint64_t
name|RHSProfileCount
operator|)
block|{
name|CallsiteCount
operator|++
block|;
name|ProfileCount
operator|+=
name|RHSProfileCount
block|;
return|return
operator|*
name|this
return|;
block|}
block|}
struct|;
comment|/// Struct to hold value either by GUID or Value*, depending on whether this
comment|/// is a combined or per-module index, respectively.
struct|struct
name|ValueInfo
block|{
comment|/// The value representation used in this instance.
enum|enum
name|ValueInfoKind
block|{
name|VI_GUID
block|,
name|VI_Value
block|,   }
enum|;
comment|/// Union of the two possible value types.
union|union
name|ValueUnion
block|{
name|GlobalValue
operator|::
name|GUID
name|Id
expr_stmt|;
specifier|const
name|Value
modifier|*
name|V
decl_stmt|;
name|ValueUnion
argument_list|(
argument|GlobalValue::GUID Id
argument_list|)
block|:
name|Id
argument_list|(
argument|Id
argument_list|)
block|{}
name|ValueUnion
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
operator|:
name|V
argument_list|(
argument|V
argument_list|)
block|{}
block|}
union|;
comment|/// The value being represented.
name|ValueUnion
name|TheValue
decl_stmt|;
comment|/// The value representation.
name|ValueInfoKind
name|Kind
decl_stmt|;
comment|/// Constructor for a GUID value
name|ValueInfo
argument_list|(
argument|GlobalValue::GUID Id =
literal|0
argument_list|)
block|:
name|TheValue
argument_list|(
name|Id
argument_list|)
operator|,
name|Kind
argument_list|(
argument|VI_GUID
argument_list|)
block|{}
comment|/// Constructor for a Value* value
name|ValueInfo
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
operator|:
name|TheValue
argument_list|(
name|V
argument_list|)
operator|,
name|Kind
argument_list|(
argument|VI_Value
argument_list|)
block|{}
comment|/// Accessor for GUID value
name|GlobalValue
operator|::
name|GUID
name|getGUID
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|VI_GUID
operator|&&
literal|"Not a GUID type"
argument_list|)
block|;
return|return
name|TheValue
operator|.
name|Id
return|;
block|}
comment|/// Accessor for Value* value
specifier|const
name|Value
operator|*
name|getValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|VI_Value
operator|&&
literal|"Not a Value type"
argument_list|)
block|;
return|return
name|TheValue
operator|.
name|V
return|;
block|}
name|bool
name|isGUID
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|VI_GUID
return|;
block|}
block|}
struct|;
comment|/// \brief Function and variable summary information to aid decisions and
comment|/// implementation of importing.
name|class
name|GlobalValueSummary
block|{
name|public
label|:
comment|/// \brief Sububclass discriminator (for dyn_cast<> et al.)
enum|enum
name|SummaryKind
block|{
name|AliasKind
block|,
name|FunctionKind
block|,
name|GlobalVarKind
block|}
enum|;
comment|/// Group flags (Linkage, hasSection, isOptSize, etc.) as a bitfield.
struct|struct
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
range|:
literal|4
decl_stmt|;
comment|/// Indicate if the global value is located in a specific section.
name|unsigned
name|HasSection
range|:
literal|1
decl_stmt|;
comment|/// Convenience Constructors
name|explicit
name|GVFlags
argument_list|(
name|GlobalValue
operator|::
name|LinkageTypes
name|Linkage
argument_list|,
name|bool
name|HasSection
argument_list|)
range|:
name|Linkage
argument_list|(
name|Linkage
argument_list|)
decl_stmt|,
name|HasSection
argument_list|(
name|HasSection
argument_list|)
block|{}
name|GVFlags
argument_list|(
specifier|const
name|GlobalValue
operator|&
name|GV
argument_list|)
operator|:
name|Linkage
argument_list|(
name|GV
operator|.
name|getLinkage
argument_list|()
argument_list|)
operator|,
name|HasSection
argument_list|(
argument|GV.hasSection()
argument_list|)
block|{}
block|}
struct|;
name|private
label|:
comment|/// Kind of summary for use in dyn_cast<> et al.
name|SummaryKind
name|Kind
decl_stmt|;
comment|/// This is the hash of the name of the symbol in the original file. It is
comment|/// identical to the GUID for global symbols, but differs for local since the
comment|/// GUID includes the module level id in the hash.
name|GlobalValue
operator|::
name|GUID
name|OriginalName
expr_stmt|;
comment|/// \brief Path of module IR containing value's definition, used to locate
comment|/// module during importing.
comment|///
comment|/// This is only used during parsing of the combined index, or when
comment|/// parsing the per-module index for creation of the combined summary index,
comment|/// not during writing of the per-module index which doesn't contain a
comment|/// module path string table.
name|StringRef
name|ModulePath
decl_stmt|;
name|GVFlags
name|Flags
decl_stmt|;
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
expr_stmt|;
name|protected
label|:
comment|/// GlobalValueSummary constructor.
name|GlobalValueSummary
argument_list|(
argument|SummaryKind K
argument_list|,
argument|GVFlags Flags
argument_list|)
block|:
name|Kind
argument_list|(
name|K
argument_list|)
operator|,
name|Flags
argument_list|(
argument|Flags
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
expr_stmt|;
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
name|GlobalValue
operator|::
name|GUID
name|Name
argument_list|)
block|{
name|OriginalName
operator|=
name|Name
expr_stmt|;
block|}
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
parameter_list|(
name|StringRef
name|ModPath
parameter_list|)
block|{
name|ModulePath
operator|=
name|ModPath
expr_stmt|;
block|}
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
parameter_list|()
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
name|GlobalValue
operator|::
name|LinkageTypes
name|Linkage
argument_list|)
block|{
name|Flags
operator|.
name|Linkage
operator|=
name|Linkage
expr_stmt|;
block|}
comment|/// Return true if this summary is for a GlobalValue that needs promotion
comment|/// to be referenced from another module.
name|bool
name|needsRenaming
argument_list|()
specifier|const
block|{
return|return
name|GlobalValue
operator|::
name|isLocalLinkage
argument_list|(
name|linkage
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return true if this global value is located in a specific section.
name|bool
name|hasSection
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|.
name|HasSection
return|;
block|}
comment|/// Record a reference from this global value to the global value identified
comment|/// by \p RefGUID.
name|void
name|addRefEdge
argument_list|(
name|GlobalValue
operator|::
name|GUID
name|RefGUID
argument_list|)
block|{
name|RefEdgeList
operator|.
name|push_back
argument_list|(
name|RefGUID
argument_list|)
expr_stmt|;
block|}
comment|/// Record a reference from this global value to the global value identified
comment|/// by \p RefV.
name|void
name|addRefEdge
parameter_list|(
specifier|const
name|Value
modifier|*
name|RefV
parameter_list|)
block|{
name|RefEdgeList
operator|.
name|push_back
argument_list|(
name|RefV
argument_list|)
expr_stmt|;
block|}
comment|/// Record a reference from this global value to each global value identified
comment|/// in \p RefEdges.
name|void
name|addRefEdges
argument_list|(
name|DenseSet
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|&
name|RefEdges
argument_list|)
block|{
for|for
control|(
name|auto
operator|&
name|RI
operator|:
name|RefEdges
control|)
name|addRefEdge
argument_list|(
name|RI
argument_list|)
expr_stmt|;
block|}
comment|/// Return the list of values referenced by this global value definition.
name|std
operator|::
name|vector
operator|<
name|ValueInfo
operator|>
operator|&
name|refs
argument_list|()
block|{
return|return
name|RefEdgeList
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|ValueInfo
operator|>
operator|&
name|refs
argument_list|()
specifier|const
block|{
return|return
name|RefEdgeList
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Alias summary information.
name|class
name|AliasSummary
range|:
name|public
name|GlobalValueSummary
block|{
name|GlobalValueSummary
operator|*
name|AliaseeSummary
block|;
name|public
operator|:
comment|/// Summary constructors.
name|AliasSummary
argument_list|(
argument|GVFlags Flags
argument_list|)
operator|:
name|GlobalValueSummary
argument_list|(
argument|AliasKind
argument_list|,
argument|Flags
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
return|return
name|const_cast
operator|<
name|AliasSummary
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getAliasee
argument_list|()
return|;
block|}
name|GlobalValueSummary
operator|&
name|getAliasee
argument_list|()
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
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ValueInfo
operator|,
name|CalleeInfo
operator|>
name|EdgeTy
expr_stmt|;
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
name|public
operator|:
comment|/// Summary constructors.
name|FunctionSummary
argument_list|(
argument|GVFlags Flags
argument_list|,
argument|unsigned NumInsts
argument_list|)
operator|:
name|GlobalValueSummary
argument_list|(
name|FunctionKind
argument_list|,
name|Flags
argument_list|)
block|,
name|InstCount
argument_list|(
argument|NumInsts
argument_list|)
block|{}
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
comment|/// Record a call graph edge from this function to the function identified
comment|/// by \p CalleeGUID, with \p CalleeInfo including the cumulative profile
comment|/// count (across all calls from this function) or 0 if no PGO.
name|void
name|addCallGraphEdge
argument_list|(
argument|GlobalValue::GUID CalleeGUID
argument_list|,
argument|CalleeInfo Info
argument_list|)
block|{
name|CallGraphEdgeList
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|CalleeGUID
argument_list|,
name|Info
argument_list|)
argument_list|)
block|;   }
comment|/// Record a call graph edge from this function to each function GUID recorded
comment|/// in \p CallGraphEdges.
name|void
name|addCallGraphEdges
argument_list|(
argument|DenseMap<GlobalValue::GUID
argument_list|,
argument|CalleeInfo>&CallGraphEdges
argument_list|)
block|{
for|for
control|(
name|auto
operator|&
name|EI
operator|:
name|CallGraphEdges
control|)
name|addCallGraphEdge
argument_list|(
name|EI
operator|.
name|first
argument_list|,
name|EI
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
comment|/// Record a call graph edge from this function to the function identified
comment|/// by \p CalleeV, with \p CalleeInfo including the cumulative profile
comment|/// count (across all calls from this function) or 0 if no PGO.
name|void
name|addCallGraphEdge
argument_list|(
argument|const Value *CalleeV
argument_list|,
argument|CalleeInfo Info
argument_list|)
block|{
name|CallGraphEdgeList
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|CalleeV
argument_list|,
name|Info
argument_list|)
argument_list|)
block|;   }
comment|/// Record a call graph edge from this function to each function recorded
comment|/// in \p CallGraphEdges.
name|void
name|addCallGraphEdges
argument_list|(
argument|DenseMap<const Value *
argument_list|,
argument|CalleeInfo>&CallGraphEdges
argument_list|)
block|{
for|for
control|(
name|auto
operator|&
name|EI
operator|:
name|CallGraphEdges
control|)
name|addCallGraphEdge
argument_list|(
name|EI
operator|.
name|first
argument_list|,
name|EI
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
comment|/// Return the list of<CalleeValueInfo, CalleeInfo> pairs.
name|std
operator|::
name|vector
operator|<
name|EdgeTy
operator|>
operator|&
name|calls
argument_list|()
block|{
return|return
name|CallGraphEdgeList
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|EdgeTy
operator|>
operator|&
name|calls
argument_list|()
specifier|const
block|{
return|return
name|CallGraphEdgeList
return|;
block|}
expr|}
block|;
comment|/// \brief Global variable summary information to aid decisions and
comment|/// implementation of importing.
comment|///
comment|/// Currently this doesn't add anything to the base \p GlobalValueSummary,
comment|/// but is a placeholder as additional info may be added to the summary
comment|/// for variables.
name|class
name|GlobalVarSummary
operator|:
name|public
name|GlobalValueSummary
block|{
name|public
operator|:
comment|/// Summary constructors.
name|GlobalVarSummary
argument_list|(
argument|GVFlags Flags
argument_list|)
operator|:
name|GlobalValueSummary
argument_list|(
argument|GlobalVarKind
argument_list|,
argument|Flags
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
block|;
comment|/// 160 bits SHA1
typedef|typedef
name|std
operator|::
name|array
operator|<
name|uint32_t
operator|,
literal|5
operator|>
name|ModuleHash
expr_stmt|;
comment|/// List of global value summary structures for a particular value held
comment|/// in the GlobalValueMap. Requires a vector in the case of multiple
comment|/// COMDAT values of the same name.
typedef|typedef
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
name|GlobalValueSummaryList
expr_stmt|;
comment|/// Map from global value GUID to corresponding summary structures.
comment|/// Use a std::map rather than a DenseMap since it will likely incur
comment|/// less overhead, as the value type is not very small and the size
comment|/// of the map is unknown, resulting in inefficiencies due to repeated
comment|/// insertions and resizing.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|GlobalValue
operator|::
name|GUID
operator|,
name|GlobalValueSummaryList
operator|>
name|GlobalValueSummaryMapTy
expr_stmt|;
comment|/// Type used for iterating through the global value summary map.
typedef|typedef
name|GlobalValueSummaryMapTy
operator|::
name|const_iterator
name|const_gvsummary_iterator
expr_stmt|;
typedef|typedef
name|GlobalValueSummaryMapTy
operator|::
name|iterator
name|gvsummary_iterator
expr_stmt|;
comment|/// String table to hold/own module path strings, which additionally holds the
comment|/// module ID assigned to each module during the plugin step, as well as a hash
comment|/// of the module. The StringMap makes a copy of and owns inserted strings.
typedef|typedef
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
name|ModulePathStringTableTy
expr_stmt|;
comment|/// Map of global value GUID to its summary, used to identify values defined in
comment|/// a particular module, and provide efficient access to their summary.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|GlobalValue
operator|::
name|GUID
operator|,
name|GlobalValueSummary
operator|*
operator|>
name|GVSummaryMapTy
expr_stmt|;
comment|/// Class to hold module path string table and global value map,
comment|/// and encapsulate methods for operating on them.
name|class
name|ModuleSummaryIndex
block|{
name|private
label|:
comment|/// Map from value name to list of summary instances for values of that
comment|/// name (may be duplicates in the COMDAT case, e.g.).
name|GlobalValueSummaryMapTy
name|GlobalValueMap
decl_stmt|;
comment|/// Holds strings for combined index, mapping to the corresponding module ID.
name|ModulePathStringTableTy
name|ModulePathStringTable
decl_stmt|;
name|public
label|:
name|ModuleSummaryIndex
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|// Disable the copy constructor and assignment operators, so
comment|// no unexpected copying/moving occurs.
name|ModuleSummaryIndex
argument_list|(
specifier|const
name|ModuleSummaryIndex
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|ModuleSummaryIndex
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|gvsummary_iterator
name|begin
parameter_list|()
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
parameter_list|()
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
comment|/// Get the list of global value summary objects for a given value name.
specifier|const
name|GlobalValueSummaryList
modifier|&
name|getGlobalValueSummaryList
parameter_list|(
name|StringRef
name|ValueName
parameter_list|)
block|{
return|return
name|GlobalValueMap
index|[
name|GlobalValue
operator|::
name|getGUID
argument_list|(
name|ValueName
argument_list|)
index|]
return|;
block|}
comment|/// Get the list of global value summary objects for a given value name.
specifier|const
name|const_gvsummary_iterator
name|findGlobalValueSummaryList
argument_list|(
name|StringRef
name|ValueName
argument_list|)
decl|const
block|{
return|return
name|GlobalValueMap
operator|.
name|find
argument_list|(
name|GlobalValue
operator|::
name|getGUID
argument_list|(
name|ValueName
argument_list|)
argument_list|)
return|;
block|}
comment|/// Get the list of global value summary objects for a given value GUID.
specifier|const
name|const_gvsummary_iterator
name|findGlobalValueSummaryList
argument_list|(
name|GlobalValue
operator|::
name|GUID
name|ValueGUID
argument_list|)
decl|const
block|{
return|return
name|GlobalValueMap
operator|.
name|find
argument_list|(
name|ValueGUID
argument_list|)
return|;
block|}
comment|/// Add a global value summary for a value of the given name.
name|void
name|addGlobalValueSummary
argument_list|(
name|StringRef
name|ValueName
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|GlobalValueSummary
operator|>
name|Summary
argument_list|)
block|{
name|GlobalValueMap
index|[
name|GlobalValue
operator|::
name|getGUID
argument_list|(
name|ValueName
argument_list|)
index|]
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
expr_stmt|;
block|}
comment|/// Add a global value summary for a value of the given GUID.
name|void
name|addGlobalValueSummary
argument_list|(
name|GlobalValue
operator|::
name|GUID
name|ValueGUID
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|GlobalValueSummary
operator|>
name|Summary
argument_list|)
block|{
name|GlobalValueMap
index|[
name|ValueGUID
index|]
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
expr_stmt|;
block|}
comment|/// Find the summary for global \p GUID in module \p ModuleId, or nullptr if
comment|/// not found.
name|GlobalValueSummary
modifier|*
name|findSummaryInModule
argument_list|(
name|GlobalValue
operator|::
name|GUID
name|ValueGUID
argument_list|,
name|StringRef
name|ModuleId
argument_list|)
decl|const
block|{
name|auto
name|CalleeInfoList
init|=
name|findGlobalValueSummaryList
argument_list|(
name|ValueGUID
argument_list|)
decl_stmt|;
if|if
condition|(
name|CalleeInfoList
operator|==
name|end
argument_list|()
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
name|CalleeInfoList
operator|->
name|second
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
block|)
decl_stmt|;
if|if
condition|(
name|Summary
operator|==
name|CalleeInfoList
operator|->
name|second
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|Summary
operator|->
name|get
argument_list|()
return|;
block|}
comment|/// Returns the first GlobalValueSummary for \p GV, asserting that there
comment|/// is only one if \p PerModuleIndex.
name|GlobalValueSummary
modifier|*
name|getGlobalValueSummary
argument_list|(
specifier|const
name|GlobalValue
operator|&
name|GV
argument_list|,
name|bool
name|PerModuleIndex
operator|=
name|true
argument_list|)
decl|const
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
expr_stmt|;
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
comment|/// Returns the first GlobalValueSummary for \p ValueGUID, asserting that
comment|/// there
comment|/// is only one if \p PerModuleIndex.
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
comment|/// Table of modules, containing module hash and id.
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
comment|/// Table of modules, containing hash and id.
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
comment|/// Get the module ID recorded for the given module path.
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
comment|/// Get the module SHA1 hash recorded for the given module path.
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
comment|/// Add the given per-module index into this module index/summary,
comment|/// assigning it the given module ID. Each module merged in should have
comment|/// a unique ID, necessary for consistent renaming of promoted
comment|/// static (local) variables.
name|void
name|mergeFrom
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleSummaryIndex
operator|>
name|Other
argument_list|,
name|uint64_t
name|NextModuleId
argument_list|)
decl_stmt|;
comment|/// Convenience method for creating a promoted global name
comment|/// for the given value name of a local, and its original module's ID.
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
comment|/// Helper to obtain the unpromoted name for a global value (or the original
comment|/// name if not promoted).
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
comment|/// Add a new module path with the given \p Hash, mapped to the given \p
comment|/// ModID, and return an iterator to the entry in the index.
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
comment|/// Check if the given Module has any functions available for exporting
comment|/// in the index. We consider any module present in the ModulePathStringTable
comment|/// to have exported functions.
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
comment|/// Remove entries in the GlobalValueMap that have empty summaries due to the
comment|/// eager nature of map entry creation during VST parsing. These would
comment|/// also be suppressed during combined index generation in mergeFrom(),
comment|/// but if there was only one module or this was the first module we might
comment|/// not invoke mergeFrom.
name|void
name|removeEmptySummaryEntries
parameter_list|()
function_decl|;
comment|/// Collect for the given module the list of function it defines
comment|/// (GUID -> Summary).
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
comment|/// Collect for each module the list of Summaries it defines (GUID ->
comment|/// Summary).
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

