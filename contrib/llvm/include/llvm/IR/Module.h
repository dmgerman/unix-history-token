begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Module.h - C++ class to represent a VM module -------*- C++ -*-===//
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
name|LLVM_IR_MODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_MODULE_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
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
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Comdat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalAlias.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalIFunc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalVariable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/SymbolTableListTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
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
file|<iterator>
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
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Error
decl_stmt|;
name|class
name|FunctionType
decl_stmt|;
name|class
name|GVMaterializer
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|RandomNumberGenerator
decl_stmt|;
name|template
operator|<
name|class
name|PtrType
operator|>
name|class
name|SmallPtrSetImpl
expr_stmt|;
name|class
name|StructType
decl_stmt|;
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
name|using
name|GlobalListType
init|=
name|SymbolTableList
operator|<
name|GlobalVariable
operator|>
decl_stmt|;
comment|/// The type for the list of functions.
name|using
name|FunctionListType
init|=
name|SymbolTableList
operator|<
name|Function
operator|>
decl_stmt|;
comment|/// The type for the list of aliases.
name|using
name|AliasListType
init|=
name|SymbolTableList
operator|<
name|GlobalAlias
operator|>
decl_stmt|;
comment|/// The type for the list of ifuncs.
name|using
name|IFuncListType
init|=
name|SymbolTableList
operator|<
name|GlobalIFunc
operator|>
decl_stmt|;
comment|/// The type for the list of named metadata.
name|using
name|NamedMDListType
init|=
name|ilist
operator|<
name|NamedMDNode
operator|>
decl_stmt|;
comment|/// The type of the comdat "symbol" table.
name|using
name|ComdatSymTabType
init|=
name|StringMap
operator|<
name|Comdat
operator|>
decl_stmt|;
comment|/// The Global Variable iterator.
name|using
name|global_iterator
init|=
name|GlobalListType
operator|::
name|iterator
decl_stmt|;
comment|/// The Global Variable constant iterator.
name|using
name|const_global_iterator
init|=
name|GlobalListType
operator|::
name|const_iterator
decl_stmt|;
comment|/// The Function iterators.
name|using
name|iterator
init|=
name|FunctionListType
operator|::
name|iterator
decl_stmt|;
comment|/// The Function constant iterator
name|using
name|const_iterator
init|=
name|FunctionListType
operator|::
name|const_iterator
decl_stmt|;
comment|/// The Function reverse iterator.
name|using
name|reverse_iterator
init|=
name|FunctionListType
operator|::
name|reverse_iterator
decl_stmt|;
comment|/// The Function constant reverse iterator.
name|using
name|const_reverse_iterator
init|=
name|FunctionListType
operator|::
name|const_reverse_iterator
decl_stmt|;
comment|/// The Global Alias iterators.
name|using
name|alias_iterator
init|=
name|AliasListType
operator|::
name|iterator
decl_stmt|;
comment|/// The Global Alias constant iterator
name|using
name|const_alias_iterator
init|=
name|AliasListType
operator|::
name|const_iterator
decl_stmt|;
comment|/// The Global IFunc iterators.
name|using
name|ifunc_iterator
init|=
name|IFuncListType
operator|::
name|iterator
decl_stmt|;
comment|/// The Global IFunc constant iterator
name|using
name|const_ifunc_iterator
init|=
name|IFuncListType
operator|::
name|const_iterator
decl_stmt|;
comment|/// The named metadata iterators.
name|using
name|named_metadata_iterator
init|=
name|NamedMDListType
operator|::
name|iterator
decl_stmt|;
comment|/// The named metadata constant iterators.
name|using
name|const_named_metadata_iterator
init|=
name|NamedMDListType
operator|::
name|const_iterator
decl_stmt|;
comment|/// This enumeration defines the supported behaviors of module flags.
enum|enum
name|ModFlagBehavior
block|{
comment|/// Emits an error if two values disagree, otherwise the resulting value is
comment|/// that of the operands.
name|Error
init|=
literal|1
block|,
comment|/// Emits a warning if two values disagree. The result value will be the
comment|/// operand for the flag from the first module being linked.
name|Warning
init|=
literal|2
block|,
comment|/// Adds a requirement that another module flag be present and have a
comment|/// specified value after linking is performed. The value must be a metadata
comment|/// pair, where the first element of the pair is the ID of the module flag
comment|/// to be restricted, and the second element of the pair is the value the
comment|/// module flag should be restricted to. This behavior can be used to
comment|/// restrict the allowable results (via triggering of an error) of linking
comment|/// IDs with the **Override** behavior.
name|Require
init|=
literal|3
block|,
comment|/// Uses the specified value, regardless of the behavior or value of the
comment|/// other module. If both modules specify **Override**, but the values
comment|/// differ, an error will be emitted.
name|Override
init|=
literal|4
block|,
comment|/// Appends the two values, which are required to be metadata nodes.
name|Append
init|=
literal|5
block|,
comment|/// Appends the two values, which are required to be metadata
comment|/// nodes. However, duplicate entries in the second list are dropped
comment|/// during the append operation.
name|AppendUnique
init|=
literal|6
block|,
comment|/// Takes the max of the two values, which are required to be integers.
name|Max
init|=
literal|7
block|,
comment|// Markers:
name|ModFlagBehaviorFirstVal
init|=
name|Error
block|,
name|ModFlagBehaviorLastVal
init|=
name|Max
block|}
enum|;
comment|/// Checks if Metadata represents a valid ModFlagBehavior, and stores the
comment|/// converted result in MFB.
specifier|static
name|bool
name|isValidModFlagBehavior
parameter_list|(
name|Metadata
modifier|*
name|MD
parameter_list|,
name|ModFlagBehavior
modifier|&
name|MFB
parameter_list|)
function_decl|;
struct|struct
name|ModuleFlagEntry
block|{
name|ModFlagBehavior
name|Behavior
decl_stmt|;
name|MDString
modifier|*
name|Key
decl_stmt|;
name|Metadata
modifier|*
name|Val
decl_stmt|;
name|ModuleFlagEntry
argument_list|(
argument|ModFlagBehavior B
argument_list|,
argument|MDString *K
argument_list|,
argument|Metadata *V
argument_list|)
block|:
name|Behavior
argument_list|(
name|B
argument_list|)
operator|,
name|Key
argument_list|(
name|K
argument_list|)
operator|,
name|Val
argument_list|(
argument|V
argument_list|)
block|{}
block|}
struct|;
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
name|IFuncListType
name|IFuncList
decl_stmt|;
comment|///< The IFuncs in the module
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
name|ComdatSymTabType
name|ComdatSymTab
decl_stmt|;
comment|///< Symbol table for COMDATs
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|OwnedMemoryBuffer
expr_stmt|;
comment|///< Memory buffer directly owned by this
comment|///< module, for legacy clients only.
name|std
operator|::
name|unique_ptr
operator|<
name|GVMaterializer
operator|>
name|Materializer
expr_stmt|;
comment|///< Used to materialize GlobalValues
name|std
operator|::
name|string
name|ModuleID
expr_stmt|;
comment|///< Human readable identifier for the module
name|std
operator|::
name|string
name|SourceFileName
expr_stmt|;
comment|///< Original source file name for module,
comment|///< recorded in bitcode.
name|std
operator|::
name|string
name|TargetTriple
expr_stmt|;
comment|///< Platform target triple Module compiled on
comment|///< Format: (arch)(sub)-(vendor)-(sys0-(abi)
name|void
modifier|*
name|NamedMDSymTab
decl_stmt|;
comment|///< NamedMDNode names.
name|DataLayout
name|DL
decl_stmt|;
comment|///< DataLayout associated with the module
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
comment|/// Get the module's original source file name. When compiling from
comment|/// bitcode, this is taken from a bitcode record where it was recorded.
comment|/// For other compiles it is the same as the ModuleID, which would
comment|/// contain the source file name.
specifier|const
name|std
operator|::
name|string
operator|&
name|getSourceFileName
argument_list|()
specifier|const
block|{
return|return
name|SourceFileName
return|;
block|}
comment|/// \brief Get a short "name" for the module.
comment|///
comment|/// This is useful for debugging or logging. It is essentially a convenience
comment|/// wrapper around getModuleIdentifier().
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|ModuleID
return|;
block|}
comment|/// Get the data layout string for the module's target platform. This is
comment|/// equivalent to getDataLayout()->getStringRepresentation().
specifier|const
name|std
operator|::
name|string
operator|&
name|getDataLayoutStr
argument_list|()
specifier|const
block|{
return|return
name|DL
operator|.
name|getStringRepresentation
argument_list|()
return|;
block|}
comment|/// Get the data layout for the module's target platform.
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// Get a RandomNumberGenerator salted for use with this module. The
comment|/// RNG can be seeded via -rng-seed=<uint64> and is salted with the
comment|/// ModuleID and the provided pass salt. The returned RNG should not
comment|/// be shared across threads or passes.
comment|///
comment|/// A unique RNG per pass ensures a reproducible random stream even
comment|/// when other randomness consuming passes are added or removed. In
comment|/// addition, the random stream will be reproducible across LLVM
comment|/// versions when the pass does not change.
name|std
operator|::
name|unique_ptr
operator|<
name|RandomNumberGenerator
operator|>
name|createRNG
argument_list|(
argument|const Pass* P
argument_list|)
specifier|const
expr_stmt|;
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
comment|/// Set the module's original source file name.
name|void
name|setSourceFileName
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
name|SourceFileName
operator|=
name|Name
expr_stmt|;
block|}
comment|/// Set the data layout
name|void
name|setDataLayout
parameter_list|(
name|StringRef
name|Desc
parameter_list|)
function_decl|;
name|void
name|setDataLayout
parameter_list|(
specifier|const
name|DataLayout
modifier|&
name|Other
parameter_list|)
function_decl|;
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
comment|/// A trailing newline is added if the input doesn't have one.
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
if|if
condition|(
operator|!
name|GlobalScopeAsm
operator|.
name|empty
argument_list|()
operator|&&
name|GlobalScopeAsm
operator|.
name|back
argument_list|()
operator|!=
literal|'\n'
condition|)
name|GlobalScopeAsm
operator|+=
literal|'\n'
expr_stmt|;
block|}
comment|/// Append to the module-scope inline assembly blocks.
comment|/// A trailing newline is added if the input doesn't have one.
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
if|if
condition|(
operator|!
name|GlobalScopeAsm
operator|.
name|empty
argument_list|()
operator|&&
name|GlobalScopeAsm
operator|.
name|back
argument_list|()
operator|!=
literal|'\n'
condition|)
name|GlobalScopeAsm
operator|+=
literal|'\n'
expr_stmt|;
block|}
comment|/// @}
comment|/// @name Generic Value Accessors
comment|/// @{
comment|/// Return the global value in the module with the specified name, of
comment|/// arbitrary type. This method returns null if a global with the specified
comment|/// name is not found.
name|GlobalValue
modifier|*
name|getNamedValue
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// Return a unique non-zero ID for the specified metadata kind. This ID is
comment|/// uniqued across modules in the current LLVMContext.
name|unsigned
name|getMDKindID
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// Populate client supplied SmallVector with the name for custom metadata IDs
comment|/// registered in this LLVMContext.
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
comment|/// Populate client supplied SmallVector with the bundle tags registered in
comment|/// this LLVMContext.  The bundle tags are ordered by increasing bundle IDs.
comment|/// \see LLVMContext::getOperandBundleTagID
name|void
name|getOperandBundleTags
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
comment|/// Return the type with the specified name, or null if there is none by that
comment|/// name.
name|StructType
modifier|*
name|getTypeByName
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|StructType
operator|*
operator|>
name|getIdentifiedStructTypes
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// @name Function Accessors
comment|/// @{
comment|/// Look up the specified function in the module symbol table. Four
comment|/// possibilities:
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
name|FunctionType
modifier|*
name|T
parameter_list|,
name|AttributeList
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
name|FunctionType
modifier|*
name|T
parameter_list|)
function_decl|;
comment|/// Look up the specified function in the module symbol table. If it does not
comment|/// exist, add a prototype for the function and return it. This function
comment|/// guarantees to return a constant of pointer to the specified function type
comment|/// or a ConstantExpr BitCast of that type if the named function has a
comment|/// different type. This version of the method takes a list of
comment|/// function arguments, which makes it easier for clients to use.
name|template
operator|<
name|typename
operator|...
name|ArgsTy
operator|>
name|Constant
operator|*
name|getOrInsertFunction
argument_list|(
argument|StringRef Name
argument_list|,
argument|AttributeList AttributeList
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArgsTy... Args
argument_list|)
block|{
name|SmallVector
operator|<
name|Type
operator|*
block|,
sizeof|sizeof...
argument_list|(
name|ArgsTy
argument_list|)
operator|>
name|ArgTys
block|{
name|Args
operator|...
block|}
block|;
return|return
name|getOrInsertFunction
argument_list|(
name|Name
argument_list|,
name|FunctionType
operator|::
name|get
argument_list|(
name|RetTy
argument_list|,
name|ArgTys
argument_list|,
name|false
argument_list|)
argument_list|,
name|AttributeList
argument_list|)
return|;
block|}
comment|/// Same as above, but without the attributes.
name|template
operator|<
name|typename
operator|...
name|ArgsTy
operator|>
name|Constant
operator|*
name|getOrInsertFunction
argument_list|(
argument|StringRef Name
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArgsTy... Args
argument_list|)
block|{
return|return
name|getOrInsertFunction
argument_list|(
name|Name
argument_list|,
name|AttributeList
block|{}
argument_list|,
name|RetTy
argument_list|,
name|Args
operator|...
argument_list|)
return|;
block|}
comment|/// Look up the specified function in the module symbol table. If it does not
comment|/// exist, return null.
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
comment|/// Look up the specified global variable in the module symbol table. If it
comment|/// does not exist, return null. If AllowInternal is set to true, this
comment|/// function will return types that have InternalLinkage. By default, these
comment|/// types are not returned.
name|GlobalVariable
modifier|*
name|getGlobalVariable
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
name|false
argument_list|)
return|;
block|}
name|GlobalVariable
modifier|*
name|getGlobalVariable
argument_list|(
name|StringRef
name|Name
argument_list|,
name|bool
name|AllowInternal
argument_list|)
decl|const
decl_stmt|;
name|GlobalVariable
modifier|*
name|getGlobalVariable
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
name|AllowInternal
init|=
name|false
parameter_list|)
block|{
return|return
name|static_cast
operator|<
specifier|const
name|Module
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getGlobalVariable
argument_list|(
name|Name
argument_list|,
name|AllowInternal
argument_list|)
return|;
block|}
comment|/// Return the global variable in the module with the specified name, of
comment|/// arbitrary type. This method returns null if a global with the specified
comment|/// name is not found.
specifier|const
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
name|GlobalVariable
modifier|*
name|getNamedGlobal
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
return|return
name|const_cast
operator|<
name|GlobalVariable
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|Module
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getNamedGlobal
argument_list|(
name|Name
argument_list|)
operator|)
return|;
block|}
comment|/// Look up the specified global in the module symbol table.
comment|///   1. If it does not exist, add a declaration of the global and return it.
comment|///   2. Else, the global exists but has the wrong type: return the function
comment|///      with a constantexpr cast to the right type.
comment|///   3. Finally, if the existing global is the correct declaration, return
comment|///      the existing global.
name|Constant
modifier|*
name|getOrInsertGlobal
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Global Alias Accessors
comment|/// @{
comment|/// Return the global alias in the module with the specified name, of
comment|/// arbitrary type. This method returns null if a global with the specified
comment|/// name is not found.
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
comment|/// @name Global IFunc Accessors
comment|/// @{
comment|/// Return the global ifunc in the module with the specified name, of
comment|/// arbitrary type. This method returns null if a global with the specified
comment|/// name is not found.
name|GlobalIFunc
modifier|*
name|getNamedIFunc
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Named Metadata Accessors
comment|/// @{
comment|/// Return the first NamedMDNode in the module with the specified name. This
comment|/// method returns null if a NamedMDNode with the specified name is not found.
name|NamedMDNode
modifier|*
name|getNamedMetadata
argument_list|(
specifier|const
name|Twine
operator|&
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the named MDNode in the module with the specified name. This method
comment|/// returns a new NamedMDNode if a NamedMDNode with the specified name is not
comment|/// found.
name|NamedMDNode
modifier|*
name|getOrInsertNamedMetadata
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// Remove the given NamedMDNode from this module and delete it.
name|void
name|eraseNamedMetadata
parameter_list|(
name|NamedMDNode
modifier|*
name|NMD
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Comdat Accessors
comment|/// @{
comment|/// Return the Comdat in the module with the specified name. It is created
comment|/// if it didn't already exist.
name|Comdat
modifier|*
name|getOrInsertComdat
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Module Flags Accessors
comment|/// @{
comment|/// Returns the module flags in the provided vector.
name|void
name|getModuleFlagsMetadata
argument_list|(
name|SmallVectorImpl
operator|<
name|ModuleFlagEntry
operator|>
operator|&
name|Flags
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the corresponding value if Key appears in module flags, otherwise
comment|/// return null.
name|Metadata
modifier|*
name|getModuleFlag
argument_list|(
name|StringRef
name|Key
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns the NamedMDNode in the module that represents module-level flags.
comment|/// This method returns null if there are no module-level flags.
name|NamedMDNode
operator|*
name|getModuleFlagsMetadata
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns the NamedMDNode in the module that represents module-level flags.
comment|/// If module-level flags aren't found, it creates the named metadata that
comment|/// contains them.
name|NamedMDNode
modifier|*
name|getOrInsertModuleFlagsMetadata
parameter_list|()
function_decl|;
comment|/// Add a module-level flag to the module-level flags metadata. It will create
comment|/// the module-level flags named metadata if it doesn't already exist.
name|void
name|addModuleFlag
parameter_list|(
name|ModFlagBehavior
name|Behavior
parameter_list|,
name|StringRef
name|Key
parameter_list|,
name|Metadata
modifier|*
name|Val
parameter_list|)
function_decl|;
name|void
name|addModuleFlag
parameter_list|(
name|ModFlagBehavior
name|Behavior
parameter_list|,
name|StringRef
name|Key
parameter_list|,
name|Constant
modifier|*
name|Val
parameter_list|)
function_decl|;
name|void
name|addModuleFlag
parameter_list|(
name|ModFlagBehavior
name|Behavior
parameter_list|,
name|StringRef
name|Key
parameter_list|,
name|uint32_t
name|Val
parameter_list|)
function_decl|;
name|void
name|addModuleFlag
parameter_list|(
name|MDNode
modifier|*
name|Node
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Materialization
comment|/// @{
comment|/// Sets the GVMaterializer to GVM. This module must not yet have a
comment|/// Materializer. To reset the materializer for a module that already has one,
comment|/// call materializeAll first. Destroying this module will destroy
comment|/// its materializer without materializing any more GlobalValues. Without
comment|/// destroying the Module, there is no way to detach or destroy a materializer
comment|/// without materializing all the GVs it controls, to avoid leaving orphan
comment|/// unmaterialized GVs.
name|void
name|setMaterializer
parameter_list|(
name|GVMaterializer
modifier|*
name|GVM
parameter_list|)
function_decl|;
comment|/// Retrieves the GVMaterializer, if any, for this Module.
name|GVMaterializer
operator|*
name|getMaterializer
argument_list|()
specifier|const
block|{
return|return
name|Materializer
operator|.
name|get
argument_list|()
return|;
block|}
name|bool
name|isMaterialized
argument_list|()
specifier|const
block|{
return|return
operator|!
name|getMaterializer
argument_list|()
return|;
block|}
comment|/// Make sure the GlobalValue is fully read.
name|llvm
operator|::
name|Error
name|materialize
argument_list|(
name|GlobalValue
operator|*
name|GV
argument_list|)
expr_stmt|;
comment|/// Make sure all GlobalValues in this Module are fully read and clear the
comment|/// Materializer.
name|llvm
operator|::
name|Error
name|materializeAll
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|Error
name|materializeMetadata
argument_list|()
expr_stmt|;
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
name|GlobalListType
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
name|FunctionListType
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
name|AliasListType
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
comment|/// Get the Module's list of ifuncs (constant).
specifier|const
name|IFuncListType
operator|&
name|getIFuncList
argument_list|()
specifier|const
block|{
return|return
name|IFuncList
return|;
block|}
comment|/// Get the Module's list of ifuncs.
name|IFuncListType
modifier|&
name|getIFuncList
parameter_list|()
block|{
return|return
name|IFuncList
return|;
block|}
specifier|static
name|IFuncListType
name|Module
operator|::
operator|*
name|getSublistAccess
argument_list|(
argument|GlobalIFunc*
argument_list|)
block|{
return|return
operator|&
name|Module
operator|::
name|IFuncList
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
name|NamedMDListType
name|Module
operator|::
operator|*
name|getSublistAccess
argument_list|(
argument|NamedMDNode*
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
comment|/// Get the Module's symbol table for COMDATs (constant).
specifier|const
name|ComdatSymTabType
operator|&
name|getComdatSymbolTable
argument_list|()
specifier|const
block|{
return|return
name|ComdatSymTab
return|;
block|}
comment|/// Get the Module's symbol table for COMDATs.
name|ComdatSymTabType
modifier|&
name|getComdatSymbolTable
parameter_list|()
block|{
return|return
name|ComdatSymTab
return|;
block|}
comment|/// @}
comment|/// @name Global Variable Iteration
comment|/// @{
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
name|iterator_range
operator|<
name|global_iterator
operator|>
name|globals
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|global_begin
argument_list|()
argument_list|,
name|global_end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|const_global_iterator
operator|>
name|globals
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|global_begin
argument_list|()
argument_list|,
name|global_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Function Iteration
comment|/// @{
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
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|FunctionList
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|FunctionList
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|FunctionList
operator|.
name|rend
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|FunctionList
operator|.
name|rend
argument_list|()
return|;
block|}
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
name|iterator_range
operator|<
name|iterator
operator|>
name|functions
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|const_iterator
operator|>
name|functions
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Alias Iteration
comment|/// @{
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
name|iterator_range
operator|<
name|alias_iterator
operator|>
name|aliases
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|alias_begin
argument_list|()
argument_list|,
name|alias_end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|const_alias_iterator
operator|>
name|aliases
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|alias_begin
argument_list|()
argument_list|,
name|alias_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name IFunc Iteration
comment|/// @{
name|ifunc_iterator
name|ifunc_begin
parameter_list|()
block|{
return|return
name|IFuncList
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_ifunc_iterator
name|ifunc_begin
argument_list|()
specifier|const
block|{
return|return
name|IFuncList
operator|.
name|begin
argument_list|()
return|;
block|}
name|ifunc_iterator
name|ifunc_end
parameter_list|()
block|{
return|return
name|IFuncList
operator|.
name|end
argument_list|()
return|;
block|}
name|const_ifunc_iterator
name|ifunc_end
argument_list|()
specifier|const
block|{
return|return
name|IFuncList
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|ifunc_size
argument_list|()
specifier|const
block|{
return|return
name|IFuncList
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|ifunc_empty
argument_list|()
specifier|const
block|{
return|return
name|IFuncList
operator|.
name|empty
argument_list|()
return|;
block|}
name|iterator_range
operator|<
name|ifunc_iterator
operator|>
name|ifuncs
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|ifunc_begin
argument_list|()
argument_list|,
name|ifunc_end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|const_ifunc_iterator
operator|>
name|ifuncs
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|ifunc_begin
argument_list|()
argument_list|,
name|ifunc_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Convenience iterators
comment|/// @{
name|using
name|global_object_iterator
init|=
name|concat_iterator
operator|<
name|GlobalObject
decl_stmt|,
name|iterator
decl_stmt|,
name|global_iterator
decl|>
decl_stmt|;
name|using
name|const_global_object_iterator
init|=
name|concat_iterator
operator|<
specifier|const
name|GlobalObject
decl_stmt|,
name|const_iterator
decl_stmt|,
name|const_global_iterator
decl|>
decl_stmt|;
name|iterator_range
operator|<
name|global_object_iterator
operator|>
name|global_objects
argument_list|()
block|{
return|return
name|concat
operator|<
name|GlobalObject
operator|>
operator|(
name|functions
argument_list|()
operator|,
name|globals
argument_list|()
operator|)
return|;
block|}
name|iterator_range
operator|<
name|const_global_object_iterator
operator|>
name|global_objects
argument_list|()
specifier|const
block|{
return|return
name|concat
operator|<
specifier|const
name|GlobalObject
operator|>
operator|(
name|functions
argument_list|()
operator|,
name|globals
argument_list|()
operator|)
return|;
block|}
name|global_object_iterator
name|global_object_begin
parameter_list|()
block|{
return|return
name|global_objects
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|global_object_iterator
name|global_object_end
parameter_list|()
block|{
return|return
name|global_objects
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|const_global_object_iterator
name|global_object_begin
argument_list|()
specifier|const
block|{
return|return
name|global_objects
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_global_object_iterator
name|global_object_end
argument_list|()
specifier|const
block|{
return|return
name|global_objects
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|using
name|global_value_iterator
init|=
name|concat_iterator
operator|<
name|GlobalValue
decl_stmt|,
name|iterator
decl_stmt|,
name|global_iterator
decl_stmt|,
name|alias_iterator
decl_stmt|,
name|ifunc_iterator
decl|>
decl_stmt|;
name|using
name|const_global_value_iterator
init|=
name|concat_iterator
operator|<
specifier|const
name|GlobalValue
decl_stmt|,
name|const_iterator
decl_stmt|,
name|const_global_iterator
decl_stmt|,
name|const_alias_iterator
decl_stmt|,
name|const_ifunc_iterator
decl|>
decl_stmt|;
name|iterator_range
operator|<
name|global_value_iterator
operator|>
name|global_values
argument_list|()
block|{
return|return
name|concat
operator|<
name|GlobalValue
operator|>
operator|(
name|functions
argument_list|()
operator|,
name|globals
argument_list|()
operator|,
name|aliases
argument_list|()
operator|,
name|ifuncs
argument_list|()
operator|)
return|;
block|}
name|iterator_range
operator|<
name|const_global_value_iterator
operator|>
name|global_values
argument_list|()
specifier|const
block|{
return|return
name|concat
operator|<
specifier|const
name|GlobalValue
operator|>
operator|(
name|functions
argument_list|()
operator|,
name|globals
argument_list|()
operator|,
name|aliases
argument_list|()
operator|,
name|ifuncs
argument_list|()
operator|)
return|;
block|}
name|global_value_iterator
name|global_value_begin
parameter_list|()
block|{
return|return
name|global_values
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|global_value_iterator
name|global_value_end
parameter_list|()
block|{
return|return
name|global_values
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|const_global_value_iterator
name|global_value_begin
argument_list|()
specifier|const
block|{
return|return
name|global_values
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_global_value_iterator
name|global_value_end
argument_list|()
specifier|const
block|{
return|return
name|global_values
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Named Metadata Iteration
comment|/// @{
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
name|iterator_range
operator|<
name|named_metadata_iterator
operator|>
name|named_metadata
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|named_metadata_begin
argument_list|()
argument_list|,
name|named_metadata_end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|const_named_metadata_iterator
operator|>
name|named_metadata
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|named_metadata_begin
argument_list|()
argument_list|,
name|named_metadata_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// An iterator for DICompileUnits that skips those marked NoDebug.
name|class
name|debug_compile_units_iterator
range|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|input_iterator_tag
decl_stmt|,
name|DICompileUnit
modifier|*
decl|>
block|{
name|NamedMDNode
modifier|*
name|CUs
decl_stmt|;
name|unsigned
name|Idx
decl_stmt|;
name|void
name|SkipNoDebugCUs
parameter_list|()
function_decl|;
name|public
label|:
name|explicit
name|debug_compile_units_iterator
argument_list|(
argument|NamedMDNode *CUs
argument_list|,
argument|unsigned Idx
argument_list|)
block|:
name|CUs
argument_list|(
name|CUs
argument_list|)
operator|,
name|Idx
argument_list|(
argument|Idx
argument_list|)
block|{
name|SkipNoDebugCUs
argument_list|()
block|;     }
name|debug_compile_units_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|Idx
block|;
name|SkipNoDebugCUs
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|debug_compile_units_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|debug_compile_units_iterator
name|T
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
name|Idx
block|;
return|return
name|T
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|debug_compile_units_iterator
operator|&
name|I
operator|)
specifier|const
block|{
return|return
name|Idx
operator|==
name|I
operator|.
name|Idx
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|debug_compile_units_iterator
operator|&
name|I
operator|)
specifier|const
block|{
return|return
name|Idx
operator|!=
name|I
operator|.
name|Idx
return|;
block|}
name|DICompileUnit
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
name|DICompileUnit
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
name|debug_compile_units_iterator
name|debug_compile_units_begin
argument_list|()
specifier|const
block|{
name|auto
operator|*
name|CUs
operator|=
name|getNamedMetadata
argument_list|(
literal|"llvm.dbg.cu"
argument_list|)
block|;
return|return
name|debug_compile_units_iterator
argument_list|(
name|CUs
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|debug_compile_units_iterator
name|debug_compile_units_end
argument_list|()
specifier|const
block|{
name|auto
operator|*
name|CUs
operator|=
name|getNamedMetadata
argument_list|(
literal|"llvm.dbg.cu"
argument_list|)
block|;
return|return
name|debug_compile_units_iterator
argument_list|(
name|CUs
argument_list|,
name|CUs
condition|?
name|CUs
operator|->
name|getNumOperands
argument_list|()
else|:
literal|0
argument_list|)
return|;
block|}
comment|/// Return an iterator for all DICompileUnits listed in this Module's
comment|/// llvm.dbg.cu named metadata node and aren't explicitly marked as
comment|/// NoDebug.
name|iterator_range
operator|<
name|debug_compile_units_iterator
operator|>
name|debug_compile_units
argument_list|()
specifier|const
block|{
name|auto
operator|*
name|CUs
operator|=
name|getNamedMetadata
argument_list|(
literal|"llvm.dbg.cu"
argument_list|)
block|;
return|return
name|make_range
argument_list|(
name|debug_compile_units_iterator
argument_list|(
name|CUs
argument_list|,
literal|0
argument_list|)
argument_list|,
name|debug_compile_units_iterator
argument_list|(
name|CUs
argument_list|,
name|CUs
condition|?
name|CUs
operator|->
name|getNumOperands
argument_list|()
else|:
literal|0
argument_list|)
argument_list|)
return|;
block|}
comment|/// @}
comment|/// Destroy ConstantArrays in LLVMContext if they are not used.
comment|/// ConstantArrays constructed during linking can cause quadratic memory
comment|/// explosion. Releasing all unused constants can cause a 20% LTO compile-time
comment|/// slowdown for a large application.
comment|///
comment|/// NOTE: Constants are currently owned by LLVMContext. This can then only
comment|/// be called where all uses of the LLVMContext are understood.
name|void
name|dropTriviallyDeadConstantArrays
parameter_list|()
function_decl|;
comment|/// @name Utility functions for printing and dumping Module objects
comment|/// @{
comment|/// Print the module to an output stream with an optional
comment|/// AssemblyAnnotationWriter.  If \c ShouldPreserveUseListOrder, then include
comment|/// uselistorder directives so that use-lists can be recreated when reading
comment|/// the assembly.
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
argument_list|,
name|bool
name|ShouldPreserveUseListOrder
operator|=
name|false
argument_list|,
name|bool
name|IsForDebug
operator|=
name|false
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
comment|/// @name Utility functions for querying Debug information.
comment|/// @{
comment|/// \brief Returns the Number of Register ParametersDwarf Version by checking
comment|/// module flags.
name|unsigned
name|getNumberRegisterParameters
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the Dwarf Version by checking module flags.
name|unsigned
name|getDwarfVersion
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the CodeView Version by checking module flags.
comment|/// Returns zero if not present in module.
name|unsigned
name|getCodeViewFlag
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// @name Utility functions for querying and setting PIC level
comment|/// @{
comment|/// \brief Returns the PIC level (small or large model)
name|PICLevel
operator|::
name|Level
name|getPICLevel
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Set the PIC level (small or large model)
name|void
name|setPICLevel
argument_list|(
name|PICLevel
operator|::
name|Level
name|PL
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// @}
comment|/// @name Utility functions for querying and setting PIE level
comment|/// @{
comment|/// \brief Returns the PIE level (small or large model)
name|PIELevel
operator|::
name|Level
name|getPIELevel
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Set the PIE level (small or large model)
name|void
name|setPIELevel
argument_list|(
name|PIELevel
operator|::
name|Level
name|PL
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// @name Utility functions for querying and setting PGO summary
comment|/// @{
comment|/// \brief Attach profile summary metadata to this module.
name|void
name|setProfileSummary
parameter_list|(
name|Metadata
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// \brief Returns profile summary metadata
name|Metadata
modifier|*
name|getProfileSummary
parameter_list|()
function_decl|;
comment|/// @}
comment|/// Take ownership of the given memory buffer.
name|void
name|setOwnedMemoryBuffer
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|MB
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Given "llvm.used" or "llvm.compiler.used" as a global name, collect
end_comment

begin_comment
comment|/// the initializer elements of that global in Set and return the global itself.
end_comment

begin_decl_stmt
name|GlobalVariable
modifier|*
name|collectUsedGlobalVariables
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|,
name|SmallPtrSetImpl
operator|<
name|GlobalValue
operator|*
operator|>
operator|&
name|Set
argument_list|,
name|bool
name|CompilerUsed
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// An raw_ostream inserter for modules.
end_comment

begin_expr_stmt
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
name|nullptr
argument_list|)
block|;
return|return
name|O
return|;
block|}
end_expr_stmt

begin_comment
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
end_comment

begin_macro
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
argument_list|(
argument|Module
argument_list|,
argument|LLVMModuleRef
argument_list|)
end_macro

begin_comment
comment|/* LLVMModuleProviderRef exists for historical reasons, but now just holds a  * Module.  */
end_comment

begin_function
specifier|inline
name|Module
modifier|*
name|unwrap
parameter_list|(
name|LLVMModuleProviderRef
name|MP
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|Module
operator|*
operator|>
operator|(
name|MP
operator|)
return|;
block|}
end_function

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_MODULE_H
end_comment

end_unit

