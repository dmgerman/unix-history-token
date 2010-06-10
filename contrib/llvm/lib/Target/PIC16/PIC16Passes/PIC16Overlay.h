begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PIC16Overlay.h - Interface for PIC16 Frame Overlay -*- C++ -*-===//
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
comment|// This file contains the PIC16 Overlay infrastructure.
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
name|PIC16FRAMEOVERLAY_H
end_ifndef

begin_define
define|#
directive|define
name|PIC16FRAMEOVERLAY_H
end_define

begin_expr_stmt
name|using
name|std
operator|::
name|string
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations.
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|AnalysisUsage
decl_stmt|;
name|class
name|CallGraphNode
decl_stmt|;
name|class
name|CallGraph
decl_stmt|;
name|namespace
name|PIC16OVERLAY
block|{
enum|enum
name|OverlayConsts
block|{
name|StartInterruptColor
init|=
literal|200
block|,
name|StartIndirectCallColor
init|=
literal|300
block|}
enum|;
block|}
name|class
name|PIC16Overlay
range|:
name|public
name|ModulePass
block|{
name|std
operator|::
name|string
name|OverlayStr
block|;
name|unsigned
name|InterruptDepth
block|;
name|unsigned
name|IndirectCallColor
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Class identification
name|PIC16Overlay
argument_list|()
operator|:
name|ModulePass
argument_list|(
argument|&ID
argument_list|)
block|{
name|OverlayStr
operator|=
literal|"Overlay="
block|;
name|InterruptDepth
operator|=
name|PIC16OVERLAY
operator|::
name|StartInterruptColor
block|;
name|IndirectCallColor
operator|=
name|PIC16OVERLAY
operator|::
name|StartIndirectCallColor
block|;     }
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|runOnModule
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|private
operator|:
name|unsigned
name|getColor
argument_list|(
name|Function
operator|*
name|Fn
argument_list|)
block|;
name|void
name|setColor
argument_list|(
argument|Function *Fn
argument_list|,
argument|unsigned Color
argument_list|)
block|;
name|unsigned
name|ModifyDepthForInterrupt
argument_list|(
argument|CallGraphNode *CGN
argument_list|,
argument|unsigned Depth
argument_list|)
block|;
name|void
name|MarkIndirectlyCalledFunctions
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|DFSTraverse
argument_list|(
argument|CallGraphNode *CGN
argument_list|,
argument|unsigned Depth
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End of  namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

