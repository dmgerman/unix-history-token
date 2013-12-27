begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== MipsELFStreamer.h - MipsELFStreamer ------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                    The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENCE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===-------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPSELFSTREAMER_H_
end_ifndef

begin_define
define|#
directive|define
name|MIPSELFSTREAMER_H_
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCELFStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsAsmPrinter
decl_stmt|;
name|class
name|MipsSubtarget
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MipsELFStreamer
range|:
name|public
name|MCELFStreamer
block|{
name|public
operator|:
name|MipsELFStreamer
argument_list|(
argument|MCContext&Context
argument_list|,
argument|MCAsmBackend&TAB
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|MCCodeEmitter *Emitter
argument_list|,
argument|bool RelaxAll
argument_list|,
argument|bool NoExecStack
argument_list|)
operator|:
name|MCELFStreamer
argument_list|(
argument|SK_MipsELFStreamer
argument_list|,
argument|Context
argument_list|,
argument|TAB
argument_list|,
argument|OS
argument_list|,
argument|Emitter
argument_list|)
block|{   }
operator|~
name|MipsELFStreamer
argument_list|()
block|{}
name|void
name|emitELFHeaderFlagsCG
argument_list|(
specifier|const
name|MipsSubtarget
operator|&
name|Subtarget
argument_list|)
block|;
name|void
name|emitMipsSTOCG
argument_list|(
argument|const MipsSubtarget&Subtarget
argument_list|,
argument|MCSymbol *Sym
argument_list|,
argument|unsigned Val
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCStreamer *S
argument_list|)
block|{
return|return
name|S
operator|->
name|getKind
argument_list|()
operator|==
name|SK_MipsELFStreamer
return|;
block|}
expr|}
block|;
name|MCELFStreamer
operator|*
name|createMipsELFStreamer
argument_list|(
argument|MCContext&Context
argument_list|,
argument|MCAsmBackend&TAB
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|MCCodeEmitter *Emitter
argument_list|,
argument|bool RelaxAll
argument_list|,
argument|bool NoExecStack
argument_list|)
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPSELFSTREAMER_H_ */
end_comment

end_unit

