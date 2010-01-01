begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Module.h - C++ class to represent a VM module ------*- C++ -*-===//
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
comment|/// Module.h This file contains the declarations for the Module class.
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
name|LLVM_MODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MODULE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/GlobalVariable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/GlobalAlias.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
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
name|class
name|FunctionType
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|template
operator|<
operator|>
expr|struct
name|ilist_traits
operator|<
name|Function
operator|>
operator|:
name|public
name|SymbolTableListTraits
operator|<
name|Function
operator|,
name|Module
operator|>
block|{
comment|// createSentinel is used to get hold of the node that marks the end of the
comment|// list... (same trick used here as in ilist_traits<Instruction>)
name|Function
operator|*
name|createSentinel
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Function
operator|*
operator|>
operator|(
operator|&
name|Sentinel
operator|)
return|;
block|}
specifier|static
name|void
name|destroySentinel
argument_list|(
argument|Function*
argument_list|)
block|{}
name|Function
operator|*
name|provideInitialHead
argument_list|()
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
name|Function
operator|*
name|ensureHead
argument_list|(
argument|Function*
argument_list|)
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
specifier|static
name|void
name|noteHead
argument_list|(
argument|Function*
argument_list|,
argument|Function*
argument_list|)
block|{}
name|private
operator|:
name|mutable
name|ilist_node
operator|<
name|Function
operator|>
name|Sentinel
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|ilist_traits
operator|<
name|GlobalVariable
operator|>
operator|:
name|public
name|SymbolTableListTraits
operator|<
name|GlobalVariable
operator|,
name|Module
operator|>
block|{
comment|// createSentinel is used to create a node that marks the end of the list.
specifier|static
name|GlobalVariable
operator|*
name|createSentinel
argument_list|()
block|;
specifier|static
name|void
name|destroySentinel
argument_list|(
argument|GlobalVariable *GV
argument_list|)
block|{
name|delete
name|GV
block|; }
block|}
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|ilist_traits
operator|<
name|GlobalAlias
operator|>
operator|:
name|public
name|SymbolTableListTraits
operator|<
name|GlobalAlias
operator|,
name|Module
operator|>
block|{
comment|// createSentinel is used to create a node that marks the end of the list.
specifier|static
name|GlobalAlias
operator|*
name|createSentinel
argument_list|()
block|;
specifier|static
name|void
name|destroySentinel
argument_list|(
argument|GlobalAlias *GA
argument_list|)
block|{
name|delete
name|GA
block|; }
block|}
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|ilist_traits
operator|<
name|NamedMDNode
operator|>
operator|:
name|public
name|SymbolTableListTraits
operator|<
name|NamedMDNode
operator|,
name|Module
operator|>
block|{
comment|// createSentinel is used to get hold of a node that marks the end of
comment|// the list...
name|NamedMDNode
operator|*
name|createSentinel
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|NamedMDNode
operator|*
operator|>
operator|(
operator|&
name|Sentinel
operator|)
return|;
block|}
specifier|static
name|void
name|destroySentinel
argument_list|(
argument|NamedMDNode*
argument_list|)
block|{}
name|NamedMDNode
operator|*
name|provideInitialHead
argument_list|()
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
name|NamedMDNode
operator|*
name|ensureHead
argument_list|(
argument|NamedMDNode*
argument_list|)
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
specifier|static
name|void
name|noteHead
argument_list|(
argument|NamedMDNode*
argument_list|,
argument|NamedMDNode*
argument_list|)
block|{}
name|private
operator|:
name|mutable
name|ilist_node
operator|<
name|NamedMDNode
operator|>
name|Sentinel
block|; }
expr_stmt|;
comment|/// A Module instance is used to store all the information related to an
comment|/// LLVM module. Modules are the top level container of all other LLVM
comment|/// Intermediate Representation (IR) objects. Each module directly contains a
comment|/// list of globals variables, a list of functions, a list of libraries (or
comment|/// other modules) this module depends on, a symbol table, and various data
comment|/// about the target's characteristics.
comment|///
comment|/// A module maintains a GlobalValRefMap object that is used to hold all
comment|/// constant references to global variables in the module.  When a global
comment|/// variable is destroyed, it should have no entries in the GlobalValueRefMap.
comment|/// @brief The main container class for the LLVM Intermediate Representation.
name|class
name|Module
block|{
comment|/// @name Types And Enumerations
comment|/// @{
name|public
label|:
comment|/// The type for the list of global variables.
typedef|typedef
name|iplist
operator|<
name|GlobalVariable
operator|>
name|GlobalListType
expr_stmt|;
comment|/// The type for the list of functions.
typedef|typedef
name|iplist
operator|<
name|Function
operator|>
name|FunctionListType
expr_stmt|;
comment|/// The type for the list of aliases.
typedef|typedef
name|iplist
operator|<
name|GlobalAlias
operator|>
name|AliasListType
expr_stmt|;
comment|/// The type for the list of named metadata.
typedef|typedef
name|iplist
operator|<
name|NamedMDNode
operator|>
name|NamedMDListType
expr_stmt|;
comment|/// The type for the list of dependent libraries.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|LibraryListType
expr_stmt|;
comment|/// The Global Variable iterator.
typedef|typedef
name|GlobalListType
operator|::
name|iterator
name|global_iterator
expr_stmt|;
comment|/// The Global Variable constant iterator.
typedef|typedef
name|GlobalListType
operator|::
name|const_iterator
name|const_global_iterator
expr_stmt|;
comment|/// The Function iterators.
typedef|typedef
name|FunctionListType
operator|::
name|iterator
name|iterator
expr_stmt|;
comment|/// The Function constant iterator
typedef|typedef
name|FunctionListType
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|/// The Global Alias iterators.
typedef|typedef
name|AliasListType
operator|::
name|iterator
name|alias_iterator
expr_stmt|;
comment|/// The Global Alias constant iterator
typedef|typedef
name|AliasListType
operator|::
name|const_iterator
name|const_alias_iterator
expr_stmt|;
comment|/// The named metadata iterators.
typedef|typedef
name|NamedMDListType
operator|::
name|iterator
name|named_metadata_iterator
expr_stmt|;
comment|/// The named metadata constant interators.
typedef|typedef
name|NamedMDListType
operator|::
name|const_iterator
name|const_named_metadata_iterator
expr_stmt|;
comment|/// The Library list iterator.
typedef|typedef
name|LibraryListType
operator|::
name|const_iterator
name|lib_iterator
expr_stmt|;
comment|/// An enumeration for describing the endianess of the target machine.
enum|enum
name|Endianness
block|{
name|AnyEndianness
block|,
name|LittleEndian
block|,
name|BigEndian
block|}
enum|;
comment|/// An enumeration for describing the size of a pointer on the target machine.
enum|enum
name|PointerSize
block|{
name|AnyPointerSize
block|,
name|Pointer32
block|,
name|Pointer64
block|}
enum|;
comment|/// @}
comment|/// @name Member Variables
comment|/// @{
name|private
label|:
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
comment|///< The LLVMContext from which types and
comment|///< constants are allocated.
name|GlobalListType
name|GlobalList
decl_stmt|;
comment|///< The Global Variables in the module
name|FunctionListType
name|FunctionList
decl_stmt|;
comment|///< The Functions in the module
name|AliasListType
name|AliasList
decl_stmt|;
comment|///< The Aliases in the module
name|LibraryListType
name|LibraryList
decl_stmt|;
comment|///< The Libraries needed by the module
name|NamedMDListType
name|NamedMDList
decl_stmt|;
comment|///< The named metadata in the module
name|std
operator|::
name|string
name|GlobalScopeAsm
expr_stmt|;
comment|///< Inline Asm at global scope.
name|ValueSymbolTable
modifier|*
name|ValSymTab
decl_stmt|;
comment|///< Symbol table for values
name|TypeSymbolTable
modifier|*
name|TypeSymTab
decl_stmt|;
comment|///< Symbol table for types
name|std
operator|::
name|string
name|ModuleID
expr_stmt|;
comment|///< Human readable identifier for the module
name|std
operator|::
name|string
name|TargetTriple
expr_stmt|;
comment|///< Platform target triple Module compiled on
name|std
operator|::
name|string
name|DataLayout
expr_stmt|;
comment|///< Target data description
name|friend
name|class
name|Constant
decl_stmt|;
comment|/// @}
comment|/// @name Constructors
comment|/// @{
name|public
label|:
comment|/// The Module constructor. Note that there is no default constructor. You
comment|/// must provide a name for the module upon construction.
name|explicit
name|Module
parameter_list|(
name|StringRef
name|ModuleID
parameter_list|,
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
comment|/// The module destructor. This will dropAllReferences.
operator|~
name|Module
argument_list|()
expr_stmt|;
comment|/// @}
comment|/// @name Module Level Accessors
comment|/// @{
comment|/// Get the module identifier which is, essentially, the name of the module.
comment|/// @returns the module identifier as a string
specifier|const
name|std
operator|::
name|string
operator|&
name|getModuleIdentifier
argument_list|()
specifier|const
block|{
return|return
name|ModuleID
return|;
block|}
comment|/// Get the data layout string for the module's target platform.  This encodes
comment|/// the type sizes and alignments expected by this module.
comment|/// @returns the data layout as a string
specifier|const
name|std
operator|::
name|string
operator|&
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|DataLayout
return|;
block|}
comment|/// Get the target triple which is a string describing the target host.
comment|/// @returns a string containing the target triple.
specifier|const
name|std
operator|::
name|string
operator|&
name|getTargetTriple
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
return|;
block|}
comment|/// Get the target endian information.
comment|/// @returns Endianess - an enumeration for the endianess of the target
name|Endianness
name|getEndianness
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the target pointer size.
comment|/// @returns PointerSize - an enumeration for the size of the target's pointer
name|PointerSize
name|getPointerSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the global data context.
comment|/// @returns LLVMContext - a container for LLVM's global information
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
comment|/// Get any module-scope inline assembly blocks.
comment|/// @returns a string containing the module-scope inline assembly blocks.
specifier|const
name|std
operator|::
name|string
operator|&
name|getModuleInlineAsm
argument_list|()
specifier|const
block|{
return|return
name|GlobalScopeAsm
return|;
block|}
comment|/// @}
comment|/// @name Module Level Mutators
comment|/// @{
comment|/// Set the module identifier.
name|void
name|setModuleIdentifier
parameter_list|(
name|StringRef
name|ID
parameter_list|)
block|{
name|ModuleID
operator|=
name|ID
expr_stmt|;
block|}
comment|/// Set the data layout
name|void
name|setDataLayout
parameter_list|(
name|StringRef
name|DL
parameter_list|)
block|{
name|DataLayout
operator|=
name|DL
expr_stmt|;
block|}
comment|/// Set the target triple.
name|void
name|setTargetTriple
parameter_list|(
name|StringRef
name|T
parameter_list|)
block|{
name|TargetTriple
operator|=
name|T
expr_stmt|;
block|}
comment|/// Set the module-scope inline assembly blocks.
name|void
name|setModuleInlineAsm
parameter_list|(
name|StringRef
name|Asm
parameter_list|)
block|{
name|GlobalScopeAsm
operator|=
name|Asm
expr_stmt|;
block|}
comment|/// Append to the module-scope inline assembly blocks, automatically
comment|/// appending a newline to the end.
name|void
name|appendModuleInlineAsm
parameter_list|(
name|StringRef
name|Asm
parameter_list|)
block|{
name|GlobalScopeAsm
operator|+=
name|Asm
expr_stmt|;
name|GlobalScopeAsm
operator|+=
literal|'\n'
expr_stmt|;
block|}
comment|/// @}
comment|/// @name Generic Value Accessors
comment|/// @{
comment|/// getNamedValue - Return the first global value in the module with
comment|/// the specified name, of arbitrary type.  This method returns null
comment|/// if a global with the specified name is not found.
name|GlobalValue
modifier|*
name|getNamedValue
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// getMDKindID - Return a unique non-zero ID for the specified metadata kind.
comment|/// This ID is uniqued across modules in the current LLVMContext.
name|unsigned
name|getMDKindID
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// getMDKindNames - Populate client supplied SmallVector with the name for
comment|/// custom metadata IDs registered in this LLVMContext.   ID #0 is not used,
comment|/// so it is filled in as an empty string.
name|void
name|getMDKindNames
argument_list|(
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Function Accessors
comment|/// @{
comment|/// getOrInsertFunction - Look up the specified function in the module symbol
comment|/// table.  Four possibilities:
comment|///   1. If it does not exist, add a prototype for the function and return it.
comment|///   2. If it exists, and has a local linkage, the existing function is
comment|///      renamed and a new one is inserted.
comment|///   3. Otherwise, if the existing function has the correct prototype, return
comment|///      the existing function.
comment|///   4. Finally, the function exists but has the wrong prototype: return the
comment|///      function with a constantexpr cast to the right prototype.
name|Constant
modifier|*
name|getOrInsertFunction
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|FunctionType
modifier|*
name|T
parameter_list|,
name|AttrListPtr
name|AttributeList
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|getOrInsertFunction
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|FunctionType
modifier|*
name|T
parameter_list|)
function_decl|;
comment|/// getOrInsertFunction - Look up the specified function in the module symbol
comment|/// table.  If it does not exist, add a prototype for the function and return
comment|/// it.  This function guarantees to return a constant of pointer to the
comment|/// specified function type or a ConstantExpr BitCast of that type if the
comment|/// named function has a different type.  This version of the method takes a
comment|/// null terminated list of function arguments, which makes it easier for
comment|/// clients to use.
name|Constant
modifier|*
name|getOrInsertFunction
argument_list|(
name|StringRef
name|Name
argument_list|,
name|AttrListPtr
name|AttributeList
argument_list|,
specifier|const
name|Type
operator|*
name|RetTy
argument_list|,
operator|...
argument_list|)
name|END_WITH_NULL
decl_stmt|;
comment|/// getOrInsertFunction - Same as above, but without the attributes.
name|Constant
modifier|*
name|getOrInsertFunction
argument_list|(
name|StringRef
name|Name
argument_list|,
specifier|const
name|Type
operator|*
name|RetTy
argument_list|,
operator|...
argument_list|)
name|END_WITH_NULL
decl_stmt|;
name|Constant
modifier|*
name|getOrInsertTargetIntrinsic
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|FunctionType
modifier|*
name|Ty
parameter_list|,
name|AttrListPtr
name|AttributeList
parameter_list|)
function_decl|;
comment|/// getFunction - Look up the specified function in the module symbol table.
comment|/// If it does not exist, return null.
name|Function
modifier|*
name|getFunction
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Global Variable Accessors
comment|/// @{
comment|/// getGlobalVariable - Look up the specified global variable in the module
comment|/// symbol table.  If it does not exist, return null. If AllowInternal is set
comment|/// to true, this function will return types that have InternalLinkage. By
comment|/// default, these types are not returned.
name|GlobalVariable
modifier|*
name|getGlobalVariable
argument_list|(
name|StringRef
name|Name
argument_list|,
name|bool
name|AllowInternal
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// getNamedGlobal - Return the first global variable in the module with the
comment|/// specified name, of arbitrary type.  This method returns null if a global
comment|/// with the specified name is not found.
name|GlobalVariable
modifier|*
name|getNamedGlobal
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
block|{
return|return
name|getGlobalVariable
argument_list|(
name|Name
argument_list|,
name|true
argument_list|)
return|;
block|}
comment|/// getOrInsertGlobal - Look up the specified global in the module symbol
comment|/// table.
comment|///   1. If it does not exist, add a declaration of the global and return it.
comment|///   2. Else, the global exists but has the wrong type: return the function
comment|///      with a constantexpr cast to the right type.
comment|///   3. Finally, if the existing global is the correct delclaration, return
comment|///      the existing global.
name|Constant
modifier|*
name|getOrInsertGlobal
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Global Alias Accessors
comment|/// @{
comment|/// getNamedAlias - Return the first global alias in the module with the
comment|/// specified name, of arbitrary type.  This method returns null if a global
comment|/// with the specified name is not found.
name|GlobalAlias
modifier|*
name|getNamedAlias
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Named Metadata Accessors
comment|/// @{
comment|/// getNamedMetadata - Return the first NamedMDNode in the module with the
comment|/// specified name. This method returns null if a NamedMDNode with the
comment|/// specified name is not found.
name|NamedMDNode
modifier|*
name|getNamedMetadata
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// getOrInsertNamedMetadata - Return the first named MDNode in the module
comment|/// with the specified name. This method returns a new NamedMDNode if a
comment|/// NamedMDNode with the specified name is not found.
name|NamedMDNode
modifier|*
name|getOrInsertNamedMetadata
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Type Accessors
comment|/// @{
comment|/// addTypeName - Insert an entry in the symbol table mapping Str to Type.  If
comment|/// there is already an entry for this name, true is returned and the symbol
comment|/// table is not modified.
name|bool
name|addTypeName
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// getTypeName - If there is at least one entry in the symbol table for the
comment|/// specified type, return it.
name|std
operator|::
name|string
name|getTypeName
argument_list|(
argument|const Type *Ty
argument_list|)
specifier|const
expr_stmt|;
comment|/// getTypeByName - Return the type with the specified name in this module, or
comment|/// null if there is none by that name.
specifier|const
name|Type
modifier|*
name|getTypeByName
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Direct access to the globals list, functions list, and symbol table
comment|/// @{
comment|/// Get the Module's list of global variables (constant).
specifier|const
name|GlobalListType
operator|&
name|getGlobalList
argument_list|()
specifier|const
block|{
return|return
name|GlobalList
return|;
block|}
comment|/// Get the Module's list of global variables.
name|GlobalListType
modifier|&
name|getGlobalList
parameter_list|()
block|{
return|return
name|GlobalList
return|;
block|}
specifier|static
name|iplist
operator|<
name|GlobalVariable
operator|>
name|Module
operator|::
operator|*
name|getSublistAccess
argument_list|(
argument|GlobalVariable*
argument_list|)
block|{
return|return
operator|&
name|Module
operator|::
name|GlobalList
return|;
block|}
comment|/// Get the Module's list of functions (constant).
specifier|const
name|FunctionListType
operator|&
name|getFunctionList
argument_list|()
specifier|const
block|{
return|return
name|FunctionList
return|;
block|}
comment|/// Get the Module's list of functions.
name|FunctionListType
modifier|&
name|getFunctionList
parameter_list|()
block|{
return|return
name|FunctionList
return|;
block|}
specifier|static
name|iplist
operator|<
name|Function
operator|>
name|Module
operator|::
operator|*
name|getSublistAccess
argument_list|(
argument|Function*
argument_list|)
block|{
return|return
operator|&
name|Module
operator|::
name|FunctionList
return|;
block|}
comment|/// Get the Module's list of aliases (constant).
specifier|const
name|AliasListType
operator|&
name|getAliasList
argument_list|()
specifier|const
block|{
return|return
name|AliasList
return|;
block|}
comment|/// Get the Module's list of aliases.
name|AliasListType
modifier|&
name|getAliasList
parameter_list|()
block|{
return|return
name|AliasList
return|;
block|}
specifier|static
name|iplist
operator|<
name|GlobalAlias
operator|>
name|Module
operator|::
operator|*
name|getSublistAccess
argument_list|(
argument|GlobalAlias*
argument_list|)
block|{
return|return
operator|&
name|Module
operator|::
name|AliasList
return|;
block|}
comment|/// Get the Module's list of named metadata (constant).
specifier|const
name|NamedMDListType
operator|&
name|getNamedMDList
argument_list|()
specifier|const
block|{
return|return
name|NamedMDList
return|;
block|}
comment|/// Get the Module's list of named metadata.
name|NamedMDListType
modifier|&
name|getNamedMDList
parameter_list|()
block|{
return|return
name|NamedMDList
return|;
block|}
specifier|static
name|iplist
operator|<
name|NamedMDNode
operator|>
name|Module
operator|::
operator|*
name|getSublistAccess
argument_list|(
argument|NamedMDNode *
argument_list|)
block|{
return|return
operator|&
name|Module
operator|::
name|NamedMDList
return|;
block|}
comment|/// Get the symbol table of global variable and function identifiers
specifier|const
name|ValueSymbolTable
operator|&
name|getValueSymbolTable
argument_list|()
specifier|const
block|{
return|return
operator|*
name|ValSymTab
return|;
block|}
comment|/// Get the Module's symbol table of global variable and function identifiers.
name|ValueSymbolTable
modifier|&
name|getValueSymbolTable
parameter_list|()
block|{
return|return
operator|*
name|ValSymTab
return|;
block|}
comment|/// Get the symbol table of types
specifier|const
name|TypeSymbolTable
operator|&
name|getTypeSymbolTable
argument_list|()
specifier|const
block|{
return|return
operator|*
name|TypeSymTab
return|;
block|}
comment|/// Get the Module's symbol table of types
name|TypeSymbolTable
modifier|&
name|getTypeSymbolTable
parameter_list|()
block|{
return|return
operator|*
name|TypeSymTab
return|;
block|}
comment|/// @}
comment|/// @name Global Variable Iteration
comment|/// @{
comment|/// Get an iterator to the first global variable
name|global_iterator
name|global_begin
parameter_list|()
block|{
return|return
name|GlobalList
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// Get a constant iterator to the first global variable
name|const_global_iterator
name|global_begin
argument_list|()
specifier|const
block|{
return|return
name|GlobalList
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// Get an iterator to the last global variable
name|global_iterator
name|global_end
parameter_list|()
block|{
return|return
name|GlobalList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Get a constant iterator to the last global variable
name|const_global_iterator
name|global_end
argument_list|()
specifier|const
block|{
return|return
name|GlobalList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Determine if the list of globals is empty.
name|bool
name|global_empty
argument_list|()
specifier|const
block|{
return|return
name|GlobalList
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Function Iteration
comment|/// @{
comment|/// Get an iterator to the first function.
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|FunctionList
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// Get a constant iterator to the first function.
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|FunctionList
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// Get an iterator to the last function.
name|iterator
name|end
parameter_list|()
block|{
return|return
name|FunctionList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Get a constant iterator to the last function.
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|FunctionList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Determine how many functions are in the Module's list of functions.
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|FunctionList
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Determine if the list of functions is empty.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|FunctionList
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Dependent Library Iteration
comment|/// @{
comment|/// @brief Get a constant iterator to beginning of dependent library list.
specifier|inline
name|lib_iterator
name|lib_begin
argument_list|()
specifier|const
block|{
return|return
name|LibraryList
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// @brief Get a constant iterator to end of dependent library list.
specifier|inline
name|lib_iterator
name|lib_end
argument_list|()
specifier|const
block|{
return|return
name|LibraryList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// @brief Returns the number of items in the list of libraries.
specifier|inline
name|size_t
name|lib_size
argument_list|()
specifier|const
block|{
return|return
name|LibraryList
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// @brief Add a library to the list of dependent libraries
name|void
name|addLibrary
parameter_list|(
name|StringRef
name|Lib
parameter_list|)
function_decl|;
comment|/// @brief Remove a library from the list of dependent libraries
name|void
name|removeLibrary
parameter_list|(
name|StringRef
name|Lib
parameter_list|)
function_decl|;
comment|/// @brief Get all the libraries
specifier|inline
specifier|const
name|LibraryListType
operator|&
name|getLibraries
argument_list|()
specifier|const
block|{
return|return
name|LibraryList
return|;
block|}
comment|/// @}
comment|/// @name Alias Iteration
comment|/// @{
comment|/// Get an iterator to the first alias.
name|alias_iterator
name|alias_begin
parameter_list|()
block|{
return|return
name|AliasList
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// Get a constant iterator to the first alias.
name|const_alias_iterator
name|alias_begin
argument_list|()
specifier|const
block|{
return|return
name|AliasList
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// Get an iterator to the last alias.
name|alias_iterator
name|alias_end
parameter_list|()
block|{
return|return
name|AliasList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Get a constant iterator to the last alias.
name|const_alias_iterator
name|alias_end
argument_list|()
specifier|const
block|{
return|return
name|AliasList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Determine how many aliases are in the Module's list of aliases.
name|size_t
name|alias_size
argument_list|()
specifier|const
block|{
return|return
name|AliasList
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Determine if the list of aliases is empty.
name|bool
name|alias_empty
argument_list|()
specifier|const
block|{
return|return
name|AliasList
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Named Metadata Iteration
comment|/// @{
comment|/// Get an iterator to the first named metadata.
name|named_metadata_iterator
name|named_metadata_begin
parameter_list|()
block|{
return|return
name|NamedMDList
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// Get a constant iterator to the first named metadata.
name|const_named_metadata_iterator
name|named_metadata_begin
argument_list|()
specifier|const
block|{
return|return
name|NamedMDList
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// Get an iterator to the last named metadata.
name|named_metadata_iterator
name|named_metadata_end
parameter_list|()
block|{
return|return
name|NamedMDList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Get a constant iterator to the last named metadata.
name|const_named_metadata_iterator
name|named_metadata_end
argument_list|()
specifier|const
block|{
return|return
name|NamedMDList
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Determine how many NamedMDNodes are in the Module's list of named metadata.
name|size_t
name|named_metadata_size
argument_list|()
specifier|const
block|{
return|return
name|NamedMDList
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Determine if the list of named metadata is empty.
name|bool
name|named_metadata_empty
argument_list|()
specifier|const
block|{
return|return
name|NamedMDList
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Utility functions for printing and dumping Module objects
comment|/// @{
comment|/// Print the module to an output stream with AssemblyAnnotationWriter.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|AssemblyAnnotationWriter
operator|*
name|AAW
argument_list|)
decl|const
decl_stmt|;
comment|/// Dump the module to stderr (for debugging).
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function causes all the subinstructions to "let go" of all references
comment|/// that they are maintaining.  This allows one to 'delete' a whole class at
comment|/// a time, even though there may be circular references... first all
comment|/// references are dropped, and all use counts go to zero.  Then everything
comment|/// is delete'd for real.  Note that no operations are valid on an object
comment|/// that has "dropped all references", except operator delete.
name|void
name|dropAllReferences
parameter_list|()
function_decl|;
comment|/// @}
block|}
empty_stmt|;
comment|/// An raw_ostream inserter for modules.
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|O
operator|,
specifier|const
name|Module
operator|&
name|M
operator|)
block|{
name|M
operator|.
name|print
argument_list|(
name|O
argument_list|,
literal|0
argument_list|)
block|;
return|return
name|O
return|;
block|}
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

