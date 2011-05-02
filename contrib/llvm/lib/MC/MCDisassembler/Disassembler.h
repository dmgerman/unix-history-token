begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------- Disassembler.h - LLVM Disassembler -----------*- C++ -*-===//
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
comment|// This file defines the interface for the Disassembly library's disassembler
end_comment

begin_comment
comment|// context.  The disassembler is responsible for producing strings for
end_comment

begin_comment
comment|// individual instructions according to a given architecture and disassembly
end_comment

begin_comment
comment|// syntax.
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
name|LLVM_MC_DISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_DISASSEMBLER_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Disassembler.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetAsmInfo
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCDisassembler
decl_stmt|;
name|class
name|MCInstPrinter
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|//
comment|// This is the disassembler context returned by LLVMCreateDisasm().
comment|//
name|class
name|LLVMDisasmContext
block|{
name|private
label|:
comment|//
comment|// The passed parameters when the disassembler context is created.
comment|//
comment|// The TripleName for this disassembler.
name|std
operator|::
name|string
name|TripleName
expr_stmt|;
comment|// The pointer to the caller's block of symbolic information.
name|void
modifier|*
name|DisInfo
decl_stmt|;
comment|// The Triple specific symbolic information type returned by GetOpInfo.
name|int
name|TagType
decl_stmt|;
comment|// The function to get the symbolic information for operands.
name|LLVMOpInfoCallback
name|GetOpInfo
decl_stmt|;
comment|// The function to look up a symbol name.
name|LLVMSymbolLookupCallback
name|SymbolLookUp
decl_stmt|;
comment|//
comment|// The objects created and saved by LLVMCreateDisasm() then used by
comment|// LLVMDisasmInstruction().
comment|//
comment|// The LLVM target corresponding to the disassembler.
comment|// FIXME: using llvm::OwningPtr<const llvm::Target> causes a malloc error
comment|//        when this LLVMDisasmContext is deleted.
specifier|const
name|Target
modifier|*
name|TheTarget
decl_stmt|;
comment|// The assembly information for the target architecture.
name|llvm
operator|::
name|OwningPtr
operator|<
specifier|const
name|llvm
operator|::
name|MCAsmInfo
operator|>
name|MAI
expr_stmt|;
comment|// The target machine instance.
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|TargetMachine
operator|>
name|TM
expr_stmt|;
comment|// The disassembler for the target architecture.
comment|// FIXME: using llvm::OwningPtr<const llvm::TargetAsmInfo> causes a malloc
comment|//        error when this LLVMDisasmContext is deleted.
specifier|const
name|TargetAsmInfo
modifier|*
name|Tai
decl_stmt|;
comment|// The assembly context for creating symbols and MCExprs.
name|llvm
operator|::
name|OwningPtr
operator|<
specifier|const
name|llvm
operator|::
name|MCContext
operator|>
name|Ctx
expr_stmt|;
comment|// The disassembler for the target architecture.
name|llvm
operator|::
name|OwningPtr
operator|<
specifier|const
name|llvm
operator|::
name|MCDisassembler
operator|>
name|DisAsm
expr_stmt|;
comment|// The instruction printer for the target architecture.
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|MCInstPrinter
operator|>
name|IP
expr_stmt|;
name|public
label|:
name|LLVMDisasmContext
argument_list|(
argument|std::string tripleName
argument_list|,
argument|void *disInfo
argument_list|,
argument|int tagType
argument_list|,
argument|LLVMOpInfoCallback getOpInfo
argument_list|,
argument|LLVMSymbolLookupCallback symbolLookUp
argument_list|,
argument|const Target *theTarget
argument_list|,
argument|const MCAsmInfo *mAI
argument_list|,
argument|llvm::TargetMachine *tM
argument_list|,
argument|const TargetAsmInfo *tai
argument_list|,
argument|llvm::MCContext *ctx
argument_list|,
argument|const MCDisassembler *disAsm
argument_list|,
argument|MCInstPrinter *iP
argument_list|)
block|:
name|TripleName
argument_list|(
name|tripleName
argument_list|)
operator|,
name|DisInfo
argument_list|(
name|disInfo
argument_list|)
operator|,
name|TagType
argument_list|(
name|tagType
argument_list|)
operator|,
name|GetOpInfo
argument_list|(
name|getOpInfo
argument_list|)
operator|,
name|SymbolLookUp
argument_list|(
name|symbolLookUp
argument_list|)
operator|,
name|TheTarget
argument_list|(
name|theTarget
argument_list|)
operator|,
name|Tai
argument_list|(
argument|tai
argument_list|)
block|{
name|TM
operator|.
name|reset
argument_list|(
name|tM
argument_list|)
block|;
name|MAI
operator|.
name|reset
argument_list|(
name|mAI
argument_list|)
block|;
name|Ctx
operator|.
name|reset
argument_list|(
name|ctx
argument_list|)
block|;
name|DisAsm
operator|.
name|reset
argument_list|(
name|disAsm
argument_list|)
block|;
name|IP
operator|.
name|reset
argument_list|(
name|iP
argument_list|)
block|;   }
specifier|const
name|MCDisassembler
operator|*
name|getDisAsm
argument_list|()
specifier|const
block|{
return|return
name|DisAsm
operator|.
name|get
argument_list|()
return|;
block|}
name|MCInstPrinter
modifier|*
name|getIP
parameter_list|()
block|{
return|return
name|IP
operator|.
name|get
argument_list|()
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

