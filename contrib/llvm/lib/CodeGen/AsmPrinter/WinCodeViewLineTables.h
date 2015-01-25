begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/lib/CodeGen/AsmPrinter/WinCodeViewLineTables.h ----*- C++ -*--===//
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
comment|// This file contains support for writing line tables info into COFF files.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_WINCODEVIEWLINETABLES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_WINCODEVIEWLINETABLES_H
end_define

begin_include
include|#
directive|include
file|"AsmPrinterHandler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LexicalScopes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineModuleInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLoweringObjectFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Collects and handles line tables information in a CodeView format.
name|class
name|WinCodeViewLineTables
range|:
name|public
name|AsmPrinterHandler
block|{
name|AsmPrinter
operator|*
name|Asm
block|;
name|DebugLoc
name|PrevInstLoc
block|;
comment|// For each function, store a vector of labels to its instructions, as well as
comment|// to the end of the function.
block|struct
name|FunctionInfo
block|{
name|SmallVector
operator|<
name|MCSymbol
operator|*
block|,
literal|10
operator|>
name|Instrs
block|;
name|MCSymbol
operator|*
name|End
block|;
name|FunctionInfo
argument_list|()
operator|:
name|End
argument_list|(
argument|nullptr
argument_list|)
block|{}
block|}
operator|*
name|CurFn
block|;
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
operator|,
name|FunctionInfo
operator|>
name|FnDebugInfoTy
expr_stmt|;
name|FnDebugInfoTy
name|FnDebugInfo
decl_stmt|;
comment|// Store the functions we've visited in a vector so we can maintain a stable
comment|// order while emitting subsections.
name|SmallVector
operator|<
specifier|const
name|Function
operator|*
operator|,
literal|10
operator|>
name|VisitedFunctions
expr_stmt|;
comment|// InstrInfoTy - Holds the Filename:LineNumber information for every
comment|// instruction with a unique debug location.
struct|struct
name|InstrInfoTy
block|{
name|StringRef
name|Filename
decl_stmt|;
name|unsigned
name|LineNumber
decl_stmt|;
name|InstrInfoTy
argument_list|()
operator|:
name|LineNumber
argument_list|(
literal|0
argument_list|)
block|{}
name|InstrInfoTy
argument_list|(
argument|StringRef Filename
argument_list|,
argument|unsigned LineNumber
argument_list|)
operator|:
name|Filename
argument_list|(
name|Filename
argument_list|)
operator|,
name|LineNumber
argument_list|(
argument|LineNumber
argument_list|)
block|{}
block|}
struct|;
name|DenseMap
operator|<
name|MCSymbol
operator|*
operator|,
name|InstrInfoTy
operator|>
name|InstrInfo
expr_stmt|;
comment|// FileNameRegistry - Manages filenames observed while generating debug info
comment|// by filtering out duplicates and bookkeeping the offsets in the string
comment|// table to be generated.
struct|struct
name|FileNameRegistryTy
block|{
name|SmallVector
operator|<
name|StringRef
operator|,
literal|10
operator|>
name|Filenames
expr_stmt|;
struct|struct
name|PerFileInfo
block|{
name|size_t
name|FilenameID
decl_stmt|,
name|StartOffset
decl_stmt|;
block|}
struct|;
name|StringMap
operator|<
name|PerFileInfo
operator|>
name|Infos
expr_stmt|;
comment|// The offset in the string table where we'll write the next unique
comment|// filename.
name|size_t
name|LastOffset
decl_stmt|;
name|FileNameRegistryTy
argument_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
comment|// Add Filename to the registry, if it was not observed before.
name|void
name|add
parameter_list|(
name|StringRef
name|Filename
parameter_list|)
block|{
if|if
condition|(
name|Infos
operator|.
name|count
argument_list|(
name|Filename
argument_list|)
condition|)
return|return;
name|size_t
name|OldSize
init|=
name|Infos
operator|.
name|size
argument_list|()
decl_stmt|;
name|Infos
index|[
name|Filename
index|]
operator|.
name|FilenameID
operator|=
name|OldSize
expr_stmt|;
name|Infos
index|[
name|Filename
index|]
operator|.
name|StartOffset
operator|=
name|LastOffset
expr_stmt|;
name|LastOffset
operator|+=
name|Filename
operator|.
name|size
argument_list|()
operator|+
literal|1
expr_stmt|;
name|Filenames
operator|.
name|push_back
argument_list|(
name|Filename
argument_list|)
expr_stmt|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|LastOffset
operator|=
literal|1
expr_stmt|;
name|Infos
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Filenames
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
name|FileNameRegistry
struct|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|StringRef
operator|>
operator|,
name|char
operator|*
operator|>
name|DirAndFilenameToFilepathMapTy
expr_stmt|;
name|DirAndFilenameToFilepathMapTy
name|DirAndFilenameToFilepathMap
decl_stmt|;
name|StringRef
name|getFullFilepath
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|S
parameter_list|)
function_decl|;
name|void
name|maybeRecordLocation
parameter_list|(
name|DebugLoc
name|DL
parameter_list|,
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
block|{
name|assert
argument_list|(
name|CurFn
operator|==
name|nullptr
argument_list|)
expr_stmt|;
name|FileNameRegistry
operator|.
name|clear
argument_list|()
expr_stmt|;
name|InstrInfo
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|void
name|emitDebugInfoForFunction
parameter_list|(
specifier|const
name|Function
modifier|*
name|GV
parameter_list|)
function_decl|;
name|public
label|:
name|WinCodeViewLineTables
argument_list|(
name|AsmPrinter
operator|*
name|Asm
argument_list|)
expr_stmt|;
operator|~
name|WinCodeViewLineTables
argument_list|()
block|{
for|for
control|(
name|DirAndFilenameToFilepathMapTy
operator|::
name|iterator
name|I
operator|=
name|DirAndFilenameToFilepathMap
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|DirAndFilenameToFilepathMap
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|free
argument_list|(
name|I
operator|->
name|second
argument_list|)
expr_stmt|;
block|}
name|void
name|setSymbolSize
argument_list|(
specifier|const
name|llvm
operator|::
name|MCSymbol
operator|*
argument_list|,
name|uint64_t
argument_list|)
name|override
block|{}
comment|/// \brief Emit the COFF section that holds the line table information.
name|void
name|endModule
argument_list|()
name|override
expr_stmt|;
comment|/// \brief Gather pre-function debug information.
name|void
name|beginFunction
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
name|override
decl_stmt|;
comment|/// \brief Gather post-function debug information.
name|void
name|endFunction
argument_list|(
specifier|const
name|MachineFunction
operator|*
argument_list|)
name|override
decl_stmt|;
comment|/// \brief Process beginning of an instruction.
name|void
name|beginInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
name|override
decl_stmt|;
comment|/// \brief Process end of an instruction.
name|void
name|endInstruction
parameter_list|()
function|override
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

