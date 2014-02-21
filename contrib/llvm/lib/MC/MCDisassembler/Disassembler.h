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
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|MCInstrInfo
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|Target
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
comment|// The register information for the target architecture.
name|llvm
operator|::
name|OwningPtr
operator|<
specifier|const
name|llvm
operator|::
name|MCRegisterInfo
operator|>
name|MRI
expr_stmt|;
comment|// The subtarget information for the target architecture.
name|llvm
operator|::
name|OwningPtr
operator|<
specifier|const
name|llvm
operator|::
name|MCSubtargetInfo
operator|>
name|MSI
expr_stmt|;
comment|// The instruction information for the target architecture.
name|llvm
operator|::
name|OwningPtr
operator|<
specifier|const
name|llvm
operator|::
name|MCInstrInfo
operator|>
name|MII
expr_stmt|;
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
comment|// The options used to set up the disassembler.
name|uint64_t
name|Options
decl_stmt|;
comment|// The CPU string.
name|std
operator|::
name|string
name|CPU
expr_stmt|;
name|public
label|:
comment|// Comment stream and backing vector.
name|SmallString
operator|<
literal|128
operator|>
name|CommentsToEmit
expr_stmt|;
name|raw_svector_ostream
name|CommentStream
decl_stmt|;
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
argument|const MCRegisterInfo *mRI
argument_list|,
argument|const MCSubtargetInfo *mSI
argument_list|,
argument|const MCInstrInfo *mII
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
name|Options
argument_list|(
literal|0
argument_list|)
operator|,
name|CommentStream
argument_list|(
argument|CommentsToEmit
argument_list|)
block|{
name|MAI
operator|.
name|reset
argument_list|(
name|mAI
argument_list|)
block|;
name|MRI
operator|.
name|reset
argument_list|(
name|mRI
argument_list|)
block|;
name|MSI
operator|.
name|reset
argument_list|(
name|mSI
argument_list|)
block|;
name|MII
operator|.
name|reset
argument_list|(
name|mII
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
name|std
operator|::
name|string
operator|&
name|getTripleName
argument_list|()
specifier|const
block|{
return|return
name|TripleName
return|;
block|}
name|void
operator|*
name|getDisInfo
argument_list|()
specifier|const
block|{
return|return
name|DisInfo
return|;
block|}
name|int
name|getTagType
argument_list|()
specifier|const
block|{
return|return
name|TagType
return|;
block|}
name|LLVMOpInfoCallback
name|getGetOpInfo
argument_list|()
specifier|const
block|{
return|return
name|GetOpInfo
return|;
block|}
name|LLVMSymbolLookupCallback
name|getSymbolLookupCallback
argument_list|()
specifier|const
block|{
return|return
name|SymbolLookUp
return|;
block|}
specifier|const
name|Target
operator|*
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|TheTarget
return|;
block|}
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
specifier|const
name|MCAsmInfo
operator|*
name|getAsmInfo
argument_list|()
specifier|const
block|{
return|return
name|MAI
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|MCInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
return|return
name|MII
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|MCRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|MRI
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|MCSubtargetInfo
operator|*
name|getSubtargetInfo
argument_list|()
specifier|const
block|{
return|return
name|MSI
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
name|void
name|setIP
parameter_list|(
name|MCInstPrinter
modifier|*
name|NewIP
parameter_list|)
block|{
name|IP
operator|.
name|reset
argument_list|(
name|NewIP
argument_list|)
expr_stmt|;
block|}
name|uint64_t
name|getOptions
argument_list|()
specifier|const
block|{
return|return
name|Options
return|;
block|}
name|void
name|addOptions
parameter_list|(
name|uint64_t
name|Options
parameter_list|)
block|{
name|this
operator|->
name|Options
operator||=
name|Options
expr_stmt|;
block|}
name|StringRef
name|getCPU
argument_list|()
specifier|const
block|{
return|return
name|CPU
return|;
block|}
name|void
name|setCPU
parameter_list|(
specifier|const
name|char
modifier|*
name|CPU
parameter_list|)
block|{
name|this
operator|->
name|CPU
operator|=
name|CPU
expr_stmt|;
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

