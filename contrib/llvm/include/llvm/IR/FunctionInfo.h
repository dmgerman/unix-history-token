begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/FunctionInfo.h - Function Info Index ---------------*- C++ -*-===//
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
comment|/// FunctionInfo.h This file contains the declarations the classes that hold
end_comment

begin_comment
comment|///  the function info index and summary.
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
name|LLVM_IR_FUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_FUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
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
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Function summary information to aid decisions and implementation of
comment|/// importing.
comment|///
comment|/// This is a separate class from FunctionInfo to enable lazy reading of this
comment|/// function summary information from the combined index file during imporing.
name|class
name|FunctionSummary
block|{
name|private
label|:
comment|/// \brief Path of module containing function IR, used to locate module when
comment|/// importing this function.
comment|///
comment|/// This is only used during parsing of the combined function index, or when
comment|/// parsing the per-module index for creation of the combined function index,
comment|/// not during writing of the per-module index which doesn't contain a
comment|/// module path string table.
name|StringRef
name|ModulePath
decl_stmt|;
comment|/// \brief Used to flag functions that have local linkage types and need to
comment|/// have module identifier appended before placing into the combined
comment|/// index, to disambiguate from other functions with the same name.
comment|///
comment|/// This is only used in the per-module function index, as it is consumed
comment|/// while creating the combined index.
name|bool
name|IsLocalFunction
decl_stmt|;
comment|// The rest of the information is used to help decide whether importing
comment|// is likely to be profitable.
comment|// Other information will be added as the importing is tuned, such
comment|// as hotness (when profile available), and other function characteristics.
comment|/// Number of instructions (ignoring debug instructions, e.g.) computed
comment|/// during the initial compile step when the function index is first built.
name|unsigned
name|InstCount
decl_stmt|;
name|public
label|:
comment|/// Construct a summary object from summary data expected for all
comment|/// summary records.
name|FunctionSummary
argument_list|(
argument|unsigned NumInsts
argument_list|)
block|:
name|InstCount
argument_list|(
argument|NumInsts
argument_list|)
block|{}
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
comment|/// Record whether this is a local function in the per-module index.
name|void
name|setLocalFunction
parameter_list|(
name|bool
name|IsLocal
parameter_list|)
block|{
name|IsLocalFunction
operator|=
name|IsLocal
expr_stmt|;
block|}
comment|/// Check whether this was a local function, for use in creating
comment|/// the combined index.
name|bool
name|isLocalFunction
argument_list|()
specifier|const
block|{
return|return
name|IsLocalFunction
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
block|}
empty_stmt|;
comment|/// \brief Class to hold pointer to function summary and information required
comment|/// for parsing it.
comment|///
comment|/// For the per-module index, this holds the bitcode offset
comment|/// of the corresponding function block. For the combined index,
comment|/// after parsing of the \a ValueSymbolTable, this initially
comment|/// holds the offset of the corresponding function summary bitcode
comment|/// record. After parsing the associated summary information from the summary
comment|/// block the \a FunctionSummary is populated and stored here.
name|class
name|FunctionInfo
block|{
name|private
label|:
comment|/// Function summary information used to help make ThinLTO importing
comment|/// decisions.
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionSummary
operator|>
name|Summary
expr_stmt|;
comment|/// \brief The bitcode offset corresponding to either the associated
comment|/// function's function body record, or its function summary record,
comment|/// depending on whether this is a per-module or combined index.
comment|///
comment|/// This bitcode offset is written to or read from the associated
comment|/// \a ValueSymbolTable entry for the function.
comment|/// For the per-module index this holds the bitcode offset of the
comment|/// function's body record  within bitcode module block in its module,
comment|/// which is used during lazy function parsing or ThinLTO importing.
comment|/// For the combined index this holds the offset of the corresponding
comment|/// function summary record, to enable associating the combined index
comment|/// VST records with the summary records.
name|uint64_t
name|BitcodeIndex
decl_stmt|;
name|public
label|:
comment|/// Constructor used during parsing of VST entries.
name|FunctionInfo
argument_list|(
argument|uint64_t FuncOffset
argument_list|)
block|:
name|Summary
argument_list|(
name|nullptr
argument_list|)
operator|,
name|BitcodeIndex
argument_list|(
argument|FuncOffset
argument_list|)
block|{}
comment|/// Constructor used for per-module index bitcode writing.
name|FunctionInfo
argument_list|(
argument|uint64_t FuncOffset
argument_list|,
argument|std::unique_ptr<FunctionSummary> FuncSummary
argument_list|)
operator|:
name|Summary
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|FuncSummary
argument_list|)
argument_list|)
operator|,
name|BitcodeIndex
argument_list|(
argument|FuncOffset
argument_list|)
block|{}
comment|/// Record the function summary information parsed out of the function
comment|/// summary block during parsing or combined index creation.
name|void
name|setFunctionSummary
argument_list|(
argument|std::unique_ptr<FunctionSummary> FuncSummary
argument_list|)
block|{
name|Summary
operator|=
name|std
operator|::
name|move
argument_list|(
name|FuncSummary
argument_list|)
block|;   }
comment|/// Get the function summary recorded for this function.
name|FunctionSummary
operator|*
name|functionSummary
argument_list|()
specifier|const
block|{
return|return
name|Summary
operator|.
name|get
argument_list|()
return|;
block|}
comment|/// Get the bitcode index recorded for this function, depending on
comment|/// the index type.
name|uint64_t
name|bitcodeIndex
argument_list|()
specifier|const
block|{
return|return
name|BitcodeIndex
return|;
block|}
comment|/// Record the bitcode index for this function, depending on
comment|/// the index type.
name|void
name|setBitcodeIndex
parameter_list|(
name|uint64_t
name|FuncOffset
parameter_list|)
block|{
name|BitcodeIndex
operator|=
name|FuncOffset
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// List of function info structures for a particular function name held
comment|/// in the FunctionMap. Requires a vector in the case of multiple
comment|/// COMDAT functions of the same name.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionInfo
operator|>>
name|FunctionInfoList
expr_stmt|;
comment|/// Map from function name to corresponding function info structures.
typedef|typedef
name|StringMap
operator|<
name|FunctionInfoList
operator|>
name|FunctionInfoMapTy
expr_stmt|;
comment|/// Type used for iterating through the function info map.
typedef|typedef
name|FunctionInfoMapTy
operator|::
name|const_iterator
name|const_funcinfo_iterator
expr_stmt|;
typedef|typedef
name|FunctionInfoMapTy
operator|::
name|iterator
name|funcinfo_iterator
expr_stmt|;
comment|/// String table to hold/own module path strings, which additionally holds the
comment|/// module ID assigned to each module during the plugin step. The StringMap
comment|/// makes a copy of and owns inserted strings.
typedef|typedef
name|StringMap
operator|<
name|uint64_t
operator|>
name|ModulePathStringTableTy
expr_stmt|;
comment|/// Class to hold module path string table and function map,
comment|/// and encapsulate methods for operating on them.
name|class
name|FunctionInfoIndex
block|{
name|private
label|:
comment|/// Map from function name to list of function information instances
comment|/// for functions of that name (may be duplicates in the COMDAT case, e.g.).
name|FunctionInfoMapTy
name|FunctionMap
decl_stmt|;
comment|/// Holds strings for combined index, mapping to the corresponding module ID.
name|ModulePathStringTableTy
name|ModulePathStringTable
decl_stmt|;
name|public
label|:
name|FunctionInfoIndex
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|// Disable the copy constructor and assignment operators, so
comment|// no unexpected copying/moving occurs.
name|FunctionInfoIndex
argument_list|(
specifier|const
name|FunctionInfoIndex
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
name|FunctionInfoIndex
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|funcinfo_iterator
name|begin
parameter_list|()
block|{
return|return
name|FunctionMap
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_funcinfo_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|FunctionMap
operator|.
name|begin
argument_list|()
return|;
block|}
name|funcinfo_iterator
name|end
parameter_list|()
block|{
return|return
name|FunctionMap
operator|.
name|end
argument_list|()
return|;
block|}
name|const_funcinfo_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|FunctionMap
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Get the list of function info objects for a given function.
specifier|const
name|FunctionInfoList
modifier|&
name|getFunctionInfoList
parameter_list|(
name|StringRef
name|FuncName
parameter_list|)
block|{
return|return
name|FunctionMap
index|[
name|FuncName
index|]
return|;
block|}
comment|/// Get the list of function info objects for a given function.
specifier|const
name|const_funcinfo_iterator
name|findFunctionInfoList
argument_list|(
name|StringRef
name|FuncName
argument_list|)
decl|const
block|{
return|return
name|FunctionMap
operator|.
name|find
argument_list|(
name|FuncName
argument_list|)
return|;
block|}
comment|/// Add a function info for a function of the given name.
name|void
name|addFunctionInfo
argument_list|(
name|StringRef
name|FuncName
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionInfo
operator|>
name|Info
argument_list|)
block|{
name|FunctionMap
index|[
name|FuncName
index|]
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Info
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// Iterator to allow writer to walk through table during emission.
name|iterator_range
operator|<
name|StringMap
operator|<
name|uint64_t
operator|>
operator|::
name|const_iterator
operator|>
name|modPathStringEntries
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|make_range
argument_list|(
name|ModulePathStringTable
operator|.
name|begin
argument_list|()
argument_list|,
name|ModulePathStringTable
operator|.
name|end
argument_list|()
argument_list|)
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
return|;
block|}
comment|/// Add the given per-module index into this function index/summary,
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
name|FunctionInfoIndex
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
argument|uint64_t ModId
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
name|raw_svector_ostream
argument_list|(
name|NewName
argument_list|)
operator|<<
name|ModId
block|;
return|return
name|NewName
operator|.
name|str
argument_list|()
return|;
block|}
comment|/// Add a new module path, mapped to the given module Id, and return StringRef
comment|/// owned by string table map.
name|StringRef
name|addModulePath
parameter_list|(
name|StringRef
name|ModPath
parameter_list|,
name|uint64_t
name|ModId
parameter_list|)
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
name|ModId
argument_list|)
argument_list|)
operator|.
name|first
operator|->
name|first
argument_list|()
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
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

