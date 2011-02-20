begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CXTranslationUnit.h - Routines for manipulating CXTranslationUnits -===//
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
comment|// This file defines routines for manipulating CXTranslationUnits.
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
name|LLVM_CLANG_CXTRANSLATIONUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CXTRANSLATIONUNIT_H
end_define

begin_extern
extern|extern
literal|"C"
block|{
struct|struct
name|CXTranslationUnitImpl
block|{
name|void
modifier|*
name|TUData
decl_stmt|;
name|void
modifier|*
name|StringPool
decl_stmt|;
block|}
struct|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

