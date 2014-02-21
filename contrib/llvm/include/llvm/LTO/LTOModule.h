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
name|LTO_MODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LTO_MODULE_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/lto.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
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
file|"llvm/MC/MCContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/Mangler.h"
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
block|}
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// LTOModule - C++ class which implements the opaque lto_module_t type.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|LTOModule
block|{
name|private
label|:
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|uint8_t
operator|>
name|StringSet
expr_stmt|;
struct|struct
name|NameAndAttributes
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|uint32_t
name|attributes
decl_stmt|;
name|bool
name|isFunction
decl_stmt|;
specifier|const
name|llvm
operator|::
name|GlobalValue
operator|*
name|symbol
expr_stmt|;
block|}
struct|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|Module
operator|>
name|_module
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
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
name|_defines
decl_stmt|;
name|llvm
operator|::
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
specifier|const
name|char
operator|*
operator|>
name|_asm_undefines
expr_stmt|;
name|llvm
operator|::
name|MCContext
name|_context
expr_stmt|;
comment|// Use mangler to add GlobalPrefix to names to match linker names.
name|llvm
operator|::
name|Mangler
name|_mangler
expr_stmt|;
name|LTOModule
argument_list|(
name|llvm
operator|::
name|Module
operator|*
name|m
argument_list|,
name|llvm
operator|::
name|TargetMachine
operator|*
name|t
argument_list|)
expr_stmt|;
name|public
label|:
comment|/// isBitcodeFile - Returns 'true' if the file or memory contents is LLVM
comment|/// bitcode.
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
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
comment|/// isBitcodeFileForTarget - Returns 'true' if the file or memory contents
comment|/// is LLVM bitcode for the specified triple.
specifier|static
name|bool
name|isBitcodeFileForTarget
parameter_list|(
specifier|const
name|void
modifier|*
name|mem
parameter_list|,
name|size_t
name|length
parameter_list|,
specifier|const
name|char
modifier|*
name|triplePrefix
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isBitcodeFileForTarget
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|triplePrefix
parameter_list|)
function_decl|;
comment|/// makeLTOModule - Create an LTOModule. N.B. These methods take ownership
comment|/// of the buffer. The caller must have initialized the Targets, the
comment|/// TargetMCs, the AsmPrinters, and the AsmParsers by calling:
comment|///
comment|/// InitializeAllTargets();
comment|/// InitializeAllTargetMCs();
comment|/// InitializeAllAsmPrinters();
comment|/// InitializeAllAsmParsers();
specifier|static
name|LTOModule
modifier|*
name|makeLTOModule
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|llvm
operator|::
name|TargetOptions
name|options
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
specifier|static
name|LTOModule
modifier|*
name|makeLTOModule
argument_list|(
name|int
name|fd
argument_list|,
specifier|const
name|char
operator|*
name|path
argument_list|,
name|size_t
name|size
argument_list|,
name|llvm
operator|::
name|TargetOptions
name|options
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
specifier|static
name|LTOModule
modifier|*
name|makeLTOModule
argument_list|(
name|int
name|fd
argument_list|,
specifier|const
name|char
operator|*
name|path
argument_list|,
name|size_t
name|map_size
argument_list|,
name|off_t
name|offset
argument_list|,
name|llvm
operator|::
name|TargetOptions
name|options
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
specifier|static
name|LTOModule
modifier|*
name|makeLTOModule
argument_list|(
specifier|const
name|void
operator|*
name|mem
argument_list|,
name|size_t
name|length
argument_list|,
name|llvm
operator|::
name|TargetOptions
name|options
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
comment|/// getTargetTriple - Return the Module's target triple.
specifier|const
name|char
modifier|*
name|getTargetTriple
parameter_list|()
block|{
return|return
name|_module
operator|->
name|getTargetTriple
argument_list|()
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|/// setTargetTriple - Set the Module's target triple.
name|void
name|setTargetTriple
parameter_list|(
specifier|const
name|char
modifier|*
name|triple
parameter_list|)
block|{
name|_module
operator|->
name|setTargetTriple
argument_list|(
name|triple
argument_list|)
expr_stmt|;
block|}
comment|/// getSymbolCount - Get the number of symbols
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
comment|/// getSymbolAttributes - Get the attributes for a symbol at the specified
comment|/// index.
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
comment|/// getSymbolName - Get the name of the symbol at the specified index.
specifier|const
name|char
modifier|*
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
name|NULL
return|;
block|}
comment|/// getLLVVMModule - Return the Module.
name|llvm
operator|::
name|Module
operator|*
name|getLLVVMModule
argument_list|()
block|{
return|return
name|_module
operator|.
name|get
argument_list|()
return|;
block|}
comment|/// getAsmUndefinedRefs -
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
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
comment|/// parseSymbols - Parse the symbols from the module and model-level ASM and
comment|/// add them to either the defined or undefined lists.
name|bool
name|parseSymbols
argument_list|(
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
comment|/// addPotentialUndefinedSymbol - Add a symbol which isn't defined just yet
comment|/// to a list to be resolved later.
name|void
name|addPotentialUndefinedSymbol
argument_list|(
specifier|const
name|llvm
operator|::
name|GlobalValue
operator|*
name|dcl
argument_list|,
name|bool
name|isFunc
argument_list|)
decl_stmt|;
comment|/// addDefinedSymbol - Add a defined symbol to the list.
name|void
name|addDefinedSymbol
argument_list|(
specifier|const
name|llvm
operator|::
name|GlobalValue
operator|*
name|def
argument_list|,
name|bool
name|isFunction
argument_list|)
decl_stmt|;
comment|/// addDefinedFunctionSymbol - Add a function symbol as defined to the list.
name|void
name|addDefinedFunctionSymbol
argument_list|(
specifier|const
name|llvm
operator|::
name|Function
operator|*
name|f
argument_list|)
decl_stmt|;
comment|/// addDefinedDataSymbol - Add a data symbol as defined to the list.
name|void
name|addDefinedDataSymbol
argument_list|(
specifier|const
name|llvm
operator|::
name|GlobalValue
operator|*
name|v
argument_list|)
decl_stmt|;
comment|/// addAsmGlobalSymbols - Add global symbols from module-level ASM to the
comment|/// defined or undefined lists.
name|bool
name|addAsmGlobalSymbols
argument_list|(
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
comment|/// addAsmGlobalSymbol - Add a global symbol from module-level ASM to the
comment|/// defined list.
name|void
name|addAsmGlobalSymbol
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|lto_symbol_attributes
name|scope
parameter_list|)
function_decl|;
comment|/// addAsmGlobalSymbolUndef - Add a global symbol from module-level ASM to
comment|/// the undefined list.
name|void
name|addAsmGlobalSymbolUndef
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/// addObjCClass - Parse i386/ppc ObjC class data structure.
name|void
name|addObjCClass
argument_list|(
specifier|const
name|llvm
operator|::
name|GlobalVariable
operator|*
name|clgv
argument_list|)
decl_stmt|;
comment|/// addObjCCategory - Parse i386/ppc ObjC category data structure.
name|void
name|addObjCCategory
argument_list|(
specifier|const
name|llvm
operator|::
name|GlobalVariable
operator|*
name|clgv
argument_list|)
decl_stmt|;
comment|/// addObjCClassRef - Parse i386/ppc ObjC class list data structure.
name|void
name|addObjCClassRef
argument_list|(
specifier|const
name|llvm
operator|::
name|GlobalVariable
operator|*
name|clgv
argument_list|)
decl_stmt|;
comment|/// objcClassNameFromExpression - Get string that the data pointer points
comment|/// to.
name|bool
name|objcClassNameFromExpression
argument_list|(
specifier|const
name|llvm
operator|::
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
comment|/// isTargetMatch - Returns 'true' if the memory buffer is for the specified
comment|/// target triple.
specifier|static
name|bool
name|isTargetMatch
argument_list|(
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|memBuffer
argument_list|,
specifier|const
name|char
operator|*
name|triplePrefix
argument_list|)
decl_stmt|;
comment|/// makeLTOModule - Create an LTOModule (private version). N.B. This
comment|/// method takes ownership of the buffer.
specifier|static
name|LTOModule
modifier|*
name|makeLTOModule
argument_list|(
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|buffer
argument_list|,
name|llvm
operator|::
name|TargetOptions
name|options
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
comment|/// makeBuffer - Create a MemoryBuffer from a memory range.
specifier|static
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|makeBuffer
argument_list|(
argument|const void *mem
argument_list|,
argument|size_t length
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LTO_MODULE_H
end_comment

end_unit

