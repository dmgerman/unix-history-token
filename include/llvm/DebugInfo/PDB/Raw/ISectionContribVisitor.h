begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ISectionContribVisitor.h ---------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_PDB_RAW_ISECTIONCONTRIBVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_ISECTIONCONTRIBVISITOR_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
struct_decl|struct
name|SectionContrib
struct_decl|;
struct_decl|struct
name|SectionContrib2
struct_decl|;
name|class
name|ISectionContribVisitor
block|{
name|public
label|:
name|virtual
operator|~
name|ISectionContribVisitor
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|void
name|visit
parameter_list|(
specifier|const
name|SectionContrib
modifier|&
name|C
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|visit
parameter_list|(
specifier|const
name|SectionContrib2
modifier|&
name|C
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
comment|// end namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_RAW_ISECTIONCONTRIBVISITOR_H
end_comment

end_unit

