begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-LTOModule.h - LLVM Link Time Optimizer ------------------------------===//
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
comment|// This file declares the LTOModule class.
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
name|LLVM_LTO_LTOMODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LTO_LTOMODULE_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/lto.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/IRObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ModuleSymbolTable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
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

begin_comment
comment|// Forward references to llvm classes.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// C++ class which implements the opaque lto_module_t type.
comment|///
struct|struct
name|LTOModule
block|{
name|private
label|:
struct|struct
name|NameAndAttributes
block|{
name|StringRef
name|name
decl_stmt|;
name|uint32_t
name|attributes
init|=
literal|0
decl_stmt|;
name|bool
name|isFunction
init|=
literal|0
decl_stmt|;
specifier|const
name|GlobalValue
modifier|*
name|symbol
init|=
literal|0
decl_stmt|;
block|}
struct|;
name|std
operator|::
name|unique_ptr
operator|<
name|LLVMContext
operator|>
name|OwnedContext
expr_stmt|;
name|std
operator|::
name|string
name|LinkerOpts
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|Mod
expr_stmt|;
name|MemoryBufferRef
name|MBRef
decl_stmt|;
name|ModuleSymbolTable
name|SymTab
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|TargetMachine
operator|>
name|_target
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|NameAndAttributes
operator|>
name|_symbols
expr_stmt|;
comment|// _defines and _undefines only needed to disambiguate tentative definitions
name|StringSet
operator|<
operator|>
name|_defines
expr_stmt|;
name|StringMap
operator|<
name|NameAndAttributes
operator|>
name|_undefines
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|_asm_undefines
expr_stmt|;
name|LTOModule
argument_list|(
argument|std::unique_ptr<Module> M
argument_list|,
argument|MemoryBufferRef MBRef
argument_list|,
argument|TargetMachine *TM
argument_list|)
empty_stmt|;
name|public
label|:
operator|~
name|LTOModule
argument_list|()
expr_stmt|;
comment|/// Returns 'true' if the file or memory contents is LLVM bitcode.
specifier|static
name|bool
name|isBitcodeFile
parameter_list|(
specifier|const
name|void
modifier|*
name|mem
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isBitcodeFile
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// Returns 'true' if the Module is produced for ThinLTO.
name|bool
name|isThinLTO
parameter_list|()
function_decl|;
comment|/// Returns 'true' if the memory buffer is LLVM bitcode for the specified
comment|/// triple.
specifier|static
name|bool
name|isBitcodeForTarget
parameter_list|(
name|MemoryBuffer
modifier|*
name|memBuffer
parameter_list|,
name|StringRef
name|triplePrefix
parameter_list|)
function_decl|;
comment|/// Returns a string representing the producer identification stored in the
comment|/// bitcode, or "" if the bitcode does not contains any.
comment|///
specifier|static
name|std
operator|::
name|string
name|getProducerString
argument_list|(
name|MemoryBuffer
operator|*
name|Buffer
argument_list|)
expr_stmt|;
comment|/// Create a MemoryBuffer from a memory range with an optional name.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|makeBuffer
argument_list|(
argument|const void *mem
argument_list|,
argument|size_t length
argument_list|,
argument|StringRef name =
literal|""
argument_list|)
expr_stmt|;
comment|/// Create an LTOModule. N.B. These methods take ownership of the buffer. The
comment|/// caller must have initialized the Targets, the TargetMCs, the AsmPrinters,
comment|/// and the AsmParsers by calling:
comment|///
comment|/// InitializeAllTargets();
comment|/// InitializeAllTargetMCs();
comment|/// InitializeAllAsmPrinters();
comment|/// InitializeAllAsmParsers();
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|LTOModule
operator|>>
name|createFromFile
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|StringRef path
argument_list|,
argument|const TargetOptions&options
argument_list|)
expr_stmt|;
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|LTOModule
operator|>>
name|createFromOpenFile
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|int fd
argument_list|,
argument|StringRef path
argument_list|,
argument|size_t size
argument_list|,
argument|const TargetOptions&options
argument_list|)
expr_stmt|;
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|LTOModule
operator|>>
name|createFromOpenFileSlice
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|int fd
argument_list|,
argument|StringRef path
argument_list|,
argument|size_t map_size
argument_list|,
argument|off_t offset
argument_list|,
argument|const TargetOptions&options
argument_list|)
expr_stmt|;
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|LTOModule
operator|>>
name|createFromBuffer
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|const void *mem
argument_list|,
argument|size_t length
argument_list|,
argument|const TargetOptions&options
argument_list|,
argument|StringRef path =
literal|""
argument_list|)
expr_stmt|;
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|LTOModule
operator|>>
name|createInLocalContext
argument_list|(
argument|std::unique_ptr<LLVMContext> Context
argument_list|,
argument|const void *mem
argument_list|,
argument|size_t length
argument_list|,
argument|const TargetOptions&options
argument_list|,
argument|StringRef path
argument_list|)
expr_stmt|;
specifier|const
name|Module
operator|&
name|getModule
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Mod
return|;
block|}
name|Module
modifier|&
name|getModule
parameter_list|()
block|{
return|return
operator|*
name|Mod
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|takeModule
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|Mod
argument_list|)
return|;
block|}
comment|/// Return the Module's target triple.
specifier|const
name|std
operator|::
name|string
operator|&
name|getTargetTriple
argument_list|()
block|{
return|return
name|getModule
argument_list|()
operator|.
name|getTargetTriple
argument_list|()
return|;
block|}
comment|/// Set the Module's target triple.
name|void
name|setTargetTriple
parameter_list|(
name|StringRef
name|Triple
parameter_list|)
block|{
name|getModule
argument_list|()
operator|.
name|setTargetTriple
argument_list|(
name|Triple
argument_list|)
expr_stmt|;
block|}
comment|/// Get the number of symbols
name|uint32_t
name|getSymbolCount
parameter_list|()
block|{
return|return
name|_symbols
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Get the attributes for a symbol at the specified index.
name|lto_symbol_attributes
name|getSymbolAttributes
parameter_list|(
name|uint32_t
name|index
parameter_list|)
block|{
if|if
condition|(
name|index
operator|<
name|_symbols
operator|.
name|size
argument_list|()
condition|)
return|return
name|lto_symbol_attributes
argument_list|(
name|_symbols
index|[
name|index
index|]
operator|.
name|attributes
argument_list|)
return|;
return|return
name|lto_symbol_attributes
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// Get the name of the symbol at the specified index.
name|StringRef
name|getSymbolName
parameter_list|(
name|uint32_t
name|index
parameter_list|)
block|{
if|if
condition|(
name|index
operator|<
name|_symbols
operator|.
name|size
argument_list|()
condition|)
return|return
name|_symbols
index|[
name|index
index|]
operator|.
name|name
return|;
return|return
name|StringRef
argument_list|()
return|;
block|}
specifier|const
name|GlobalValue
modifier|*
name|getSymbolGV
parameter_list|(
name|uint32_t
name|index
parameter_list|)
block|{
if|if
condition|(
name|index
operator|<
name|_symbols
operator|.
name|size
argument_list|()
condition|)
return|return
name|_symbols
index|[
name|index
index|]
operator|.
name|symbol
return|;
return|return
name|nullptr
return|;
block|}
name|StringRef
name|getLinkerOpts
parameter_list|()
block|{
return|return
name|LinkerOpts
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
operator|&
name|getAsmUndefinedRefs
argument_list|()
block|{
return|return
name|_asm_undefines
return|;
block|}
name|private
label|:
comment|/// Parse metadata from the module
comment|// FIXME: it only parses "llvm.linker.options" metadata at the moment
name|void
name|parseMetadata
parameter_list|()
function_decl|;
comment|/// Parse the symbols from the module and model-level ASM and add them to
comment|/// either the defined or undefined lists.
name|void
name|parseSymbols
parameter_list|()
function_decl|;
comment|/// Add a symbol which isn't defined just yet to a list to be resolved later.
name|void
name|addPotentialUndefinedSymbol
argument_list|(
name|ModuleSymbolTable
operator|::
name|Symbol
name|Sym
argument_list|,
name|bool
name|isFunc
argument_list|)
decl_stmt|;
comment|/// Add a defined symbol to the list.
name|void
name|addDefinedSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|GlobalValue
modifier|*
name|def
parameter_list|,
name|bool
name|isFunction
parameter_list|)
function_decl|;
comment|/// Add a data symbol as defined to the list.
name|void
name|addDefinedDataSymbol
argument_list|(
name|ModuleSymbolTable
operator|::
name|Symbol
name|Sym
argument_list|)
decl_stmt|;
name|void
name|addDefinedDataSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|GlobalValue
modifier|*
name|v
parameter_list|)
function_decl|;
comment|/// Add a function symbol as defined to the list.
name|void
name|addDefinedFunctionSymbol
argument_list|(
name|ModuleSymbolTable
operator|::
name|Symbol
name|Sym
argument_list|)
decl_stmt|;
name|void
name|addDefinedFunctionSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// Add a global symbol from module-level ASM to the defined list.
name|void
name|addAsmGlobalSymbol
parameter_list|(
name|StringRef
parameter_list|,
name|lto_symbol_attributes
name|scope
parameter_list|)
function_decl|;
comment|/// Add a global symbol from module-level ASM to the undefined list.
name|void
name|addAsmGlobalSymbolUndef
parameter_list|(
name|StringRef
parameter_list|)
function_decl|;
comment|/// Parse i386/ppc ObjC class data structure.
name|void
name|addObjCClass
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|clgv
parameter_list|)
function_decl|;
comment|/// Parse i386/ppc ObjC category data structure.
name|void
name|addObjCCategory
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|clgv
parameter_list|)
function_decl|;
comment|/// Parse i386/ppc ObjC class list data structure.
name|void
name|addObjCClassRef
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|clgv
parameter_list|)
function_decl|;
comment|/// Get string that the data pointer points to.
name|bool
name|objcClassNameFromExpression
argument_list|(
specifier|const
name|Constant
operator|*
name|c
argument_list|,
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
decl_stmt|;
comment|/// Create an LTOModule (private version).
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|LTOModule
operator|>>
name|makeLTOModule
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|,
argument|const TargetOptions&options
argument_list|,
argument|LLVMContext&Context
argument_list|,
argument|bool ShouldBeLazy
argument_list|)
expr_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

