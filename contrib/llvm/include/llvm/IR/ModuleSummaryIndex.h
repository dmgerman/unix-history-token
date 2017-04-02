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
comment|/// Struct to hold value either by GUID or GlobalValue*. Values in combined
comment|/// indexes as well as indirect calls are GUIDs, all others are GlobalValues.
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
name|GlobalValue
modifier|*
name|GV
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
name|GlobalValue
operator|*
name|GV
argument_list|)
operator|:
name|GV
argument_list|(
argument|GV
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
comment|/// Constructor for a GlobalValue* value
name|ValueInfo
argument_list|(
specifier|const
name|GlobalValue
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
comment|/// Accessor for GlobalValue* value
specifier|const
name|GlobalValue
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
name|GV
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
name|GlobalValue
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
name|GlobalValue
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
if|if
condition|(
name|L
operator|.
name|isGUID
argument_list|()
operator|!=
name|R
operator|.
name|isGUID
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|L
operator|.
name|isGUID
argument_list|()
condition|?
operator|(
name|L
operator|.
name|getGUID
argument_list|()
operator|==
name|R
operator|.
name|getGUID
argument_list|()
operator|)
else|:
operator|(
name|L
operator|.
name|getValue
argument_list|()
operator|==
name|R
operator|.
name|getValue
argument_list|()
operator|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
name|ValueInfo
name|I
parameter_list|)
block|{
return|return
name|I
operator|.
name|isGUID
argument_list|()
condition|?
name|I
operator|.
name|getGUID
argument_list|()
else|:
operator|(
name|uintptr_t
operator|)
name|I
operator|.
name|getValue
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Function and variable summary information to aid decisions and
end_comment

begin_comment
comment|/// implementation of importing.
end_comment

begin_decl_stmt
name|class
name|GlobalValueSummary
block|{
name|public
label|:
comment|/// \brief Sububclass discriminator (for dyn_cast<> et al.)
enum|enum
name|SummaryKind
enum|:
name|unsigned
block|{
name|AliasKind
block|,
name|FunctionKind
block|,
name|GlobalVarKind
block|}
enum|;
comment|/// Group flags (Linkage, NotEligibleToImport, etc.) as a bitfield.
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
comment|/// Indicate if the global value cannot be imported (e.g. it cannot
comment|/// be renamed or references something that can't be renamed).
name|unsigned
name|NotEligibleToImport
range|:
literal|1
decl_stmt|;
comment|/// Indicate that the global value must be considered a live root for
comment|/// index-based liveness analysis. Used for special LLVM values such as
comment|/// llvm.global_ctors that the linker does not know about.
name|unsigned
name|LiveRoot
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
name|NotEligibleToImport
argument_list|,
name|bool
name|LiveRoot
argument_list|)
range|:
name|Linkage
argument_list|(
name|Linkage
argument_list|)
decl_stmt|,
name|NotEligibleToImport
argument_list|(
name|NotEligibleToImport
argument_list|)
decl_stmt|,
name|LiveRoot
argument_list|(
name|LiveRoot
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
name|GVFlags
name|Flags
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
argument_list|,
argument|std::vector<ValueInfo> Refs
argument_list|)
block|:
name|Kind
argument_list|(
name|K
argument_list|)
operator|,
name|Flags
argument_list|(
name|Flags
argument_list|)
operator|,
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
parameter_list|()
block|{
name|Flags
operator|.
name|LiveRoot
operator|=
name|true
expr_stmt|;
block|}
comment|/// Flag that this global value cannot be imported.
name|void
name|setNotEligibleToImport
parameter_list|()
block|{
name|Flags
operator|.
name|NotEligibleToImport
operator|=
name|true
expr_stmt|;
block|}
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Alias summary information.
end_comment

begin_decl_stmt
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
comment|/// List of type identifiers used by this function, represented as GUIDs.
name|std
operator|::
name|vector
operator|<
name|GlobalValue
operator|::
name|GUID
operator|>
name|TypeIdList
block|;
name|public
operator|:
comment|/// Summary constructors.
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
argument|std::vector<GlobalValue::GUID> TypeIds
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
name|std
operator|::
name|move
argument_list|(
name|CGEdges
argument_list|)
argument_list|)
block|,
name|TypeIdList
argument_list|(
argument|std::move(TypeIds)
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
comment|/// Returns the list of type identifiers used by this function.
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
return|return
name|TypeIdList
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
name|TypeIdSummary
block|{
name|TypeTestResolution
name|TTRes
block|; }
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
end_decl_stmt

begin_comment
comment|/// Map from global value GUID to corresponding summary structures.
end_comment

begin_comment
comment|/// Use a std::map rather than a DenseMap since it will likely incur
end_comment

begin_comment
comment|/// less overhead, as the value type is not very small and the size
end_comment

begin_comment
comment|/// of the map is unknown, resulting in inefficiencies due to repeated
end_comment

begin_comment
comment|/// insertions and resizing.
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|/// Type used for iterating through the global value summary map.
end_comment

begin_typedef
typedef|typedef
name|GlobalValueSummaryMapTy
operator|::
name|const_iterator
name|const_gvsummary_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|GlobalValueSummaryMapTy
operator|::
name|iterator
name|gvsummary_iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// String table to hold/own module path strings, which additionally holds the
end_comment

begin_comment
comment|/// module ID assigned to each module during the plugin step, as well as a hash
end_comment

begin_comment
comment|/// of the module. The StringMap makes a copy of and owns inserted strings.
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|/// Map of global value GUID to its summary, used to identify values defined in
end_comment

begin_comment
comment|/// a particular module, and provide efficient access to their summary.
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|/// Class to hold module path string table and global value map,
end_comment

begin_comment
comment|/// and encapsulate methods for operating on them.
end_comment

begin_decl_stmt
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
operator|,
name|TypeIdSummary
operator|>
name|TypeIdMap
expr_stmt|;
comment|// YAML I/O support.
name|friend
name|yaml
operator|::
name|MappingTraits
operator|<
name|ModuleSummaryIndex
operator|>
expr_stmt|;
name|public
label|:
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
end_decl_stmt

begin_comment
comment|/// Returns the first GlobalValueSummary for \p GV, asserting that there
end_comment

begin_comment
comment|/// is only one if \p PerModuleIndex.
end_comment

begin_decl_stmt
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
end_decl_stmt

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
comment|/// Add the given per-module index into this module index/summary,
end_comment

begin_comment
comment|/// assigning it the given module ID. Each module merged in should have
end_comment

begin_comment
comment|/// a unique ID, necessary for consistent renaming of promoted
end_comment

begin_comment
comment|/// static (local) variables.
end_comment

begin_decl_stmt
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

begin_comment
comment|/// Remove entries in the GlobalValueMap that have empty summaries due to the
end_comment

begin_comment
comment|/// eager nature of map entry creation during VST parsing. These would
end_comment

begin_comment
comment|/// also be suppressed during combined index generation in mergeFrom(),
end_comment

begin_comment
comment|/// but if there was only one module or this was the first module we might
end_comment

begin_comment
comment|/// not invoke mergeFrom.
end_comment

begin_function_decl
name|void
name|removeEmptySummaryEntries
parameter_list|()
function_decl|;
end_function_decl

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
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

