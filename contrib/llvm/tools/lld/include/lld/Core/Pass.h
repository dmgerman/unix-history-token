begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------ Core/Pass.h - Base class for linker passes ----------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_CORE_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_PASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|SimpleFile
decl_stmt|;
comment|/// Once the core linking is done (which resolves references, coalesces atoms
comment|/// and produces a complete Atom graph), the linker runs a series of passes
comment|/// on the Atom graph. The graph is modeled as a File, which means the pass
comment|/// has access to all the atoms and to File level attributes. Each pass does
comment|/// a particular transformation to the Atom graph or to the File attributes.
comment|///
comment|/// This is the abstract base class for all passes.  A Pass does its
comment|/// actual work in it perform() method.  It can iterator over Atoms in the
comment|/// graph using the *begin()/*end() atom iterator of the File.  It can add
comment|/// new Atoms to the graph using the File's addAtom() method.
name|class
name|Pass
block|{
name|public
label|:
name|virtual
operator|~
name|Pass
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Do the actual work of the Pass.
name|virtual
name|llvm
operator|::
name|Error
name|perform
argument_list|(
name|SimpleFile
operator|&
name|mergedFile
argument_list|)
operator|=
literal|0
expr_stmt|;
name|protected
label|:
comment|// Only subclassess can be instantiated.
name|Pass
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_PASS_H
end_comment

end_unit

