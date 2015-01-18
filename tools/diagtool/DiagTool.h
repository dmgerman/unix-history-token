begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DiagTool.h - Classes for defining diagtool tools -------------------===//
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
comment|// This file implements the boilerplate for defining diagtool tools.
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
name|LLVM_CLANG_TOOLS_DIAGTOOL_DIAGTOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLS_DIAGTOOL_DIAGTOOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ManagedStatic.h"
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
name|diagtool
block|{
name|class
name|DiagTool
block|{
specifier|const
name|std
operator|::
name|string
name|cmd
expr_stmt|;
specifier|const
name|std
operator|::
name|string
name|description
expr_stmt|;
name|public
label|:
name|DiagTool
argument_list|(
argument|llvm::StringRef toolCmd
argument_list|,
argument|llvm::StringRef toolDesc
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|DiagTool
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|cmd
return|;
block|}
name|llvm
operator|::
name|StringRef
name|getDescription
argument_list|()
specifier|const
block|{
return|return
name|description
return|;
block|}
name|virtual
name|int
name|run
argument_list|(
name|unsigned
name|argc
argument_list|,
name|char
operator|*
name|argv
index|[]
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|out
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
name|class
name|DiagTools
block|{
name|void
modifier|*
name|tools
decl_stmt|;
name|public
label|:
name|DiagTools
argument_list|()
expr_stmt|;
operator|~
name|DiagTools
argument_list|()
expr_stmt|;
name|DiagTool
modifier|*
name|getTool
argument_list|(
name|llvm
operator|::
name|StringRef
name|toolCmd
argument_list|)
decl_stmt|;
name|void
name|registerTool
parameter_list|(
name|DiagTool
modifier|*
name|tool
parameter_list|)
function_decl|;
name|void
name|printCommands
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|out
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
extern|extern llvm::ManagedStatic<DiagTools> diagTools;
name|template
operator|<
name|typename
name|DIAGTOOL
operator|>
name|class
name|RegisterDiagTool
block|{
name|public
operator|:
name|RegisterDiagTool
argument_list|()
block|{
name|diagTools
operator|->
name|registerTool
argument_list|(
argument|new DIAGTOOL()
argument_list|)
block|; }
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end diagtool namespace
end_comment

begin_define
define|#
directive|define
name|DEF_DIAGTOOL
parameter_list|(
name|NAME
parameter_list|,
name|DESC
parameter_list|,
name|CLSNAME
parameter_list|)
define|\
value|namespace {\ class CLSNAME : public diagtool::DiagTool {\ public:\   CLSNAME() : DiagTool(NAME, DESC) {}\   virtual ~CLSNAME() {}\   int run(unsigned argc, char *argv[], llvm::raw_ostream&out) override;\ };\ diagtool::RegisterDiagTool<CLSNAME> Register##CLSNAME;\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

