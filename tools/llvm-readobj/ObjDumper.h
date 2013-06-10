begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjDumper.h -------------------------------------------------------===//
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
name|LLVM_READOBJ_OBJDUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_READOBJ_OBJDUMPER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|ObjectFile
decl_stmt|;
block|}
name|class
name|error_code
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|OwningPtr
expr_stmt|;
name|class
name|StreamWriter
decl_stmt|;
name|class
name|ObjDumper
block|{
name|public
label|:
name|ObjDumper
argument_list|(
name|StreamWriter
operator|&
name|Writer
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|ObjDumper
argument_list|()
expr_stmt|;
name|virtual
name|void
name|printFileHeaders
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printSections
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printRelocations
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printSymbols
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printDynamicSymbols
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printUnwindInfo
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Only implemented for ELF at this time.
name|virtual
name|void
name|printDynamicTable
parameter_list|()
block|{ }
name|virtual
name|void
name|printNeededLibraries
parameter_list|()
block|{ }
name|virtual
name|void
name|printProgramHeaders
parameter_list|()
block|{ }
name|protected
label|:
name|StreamWriter
modifier|&
name|W
decl_stmt|;
block|}
empty_stmt|;
name|error_code
name|createCOFFDumper
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|,
name|StreamWriter
operator|&
name|Writer
argument_list|,
name|OwningPtr
operator|<
name|ObjDumper
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
name|error_code
name|createELFDumper
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|,
name|StreamWriter
operator|&
name|Writer
argument_list|,
name|OwningPtr
operator|<
name|ObjDumper
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
name|error_code
name|createMachODumper
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|,
name|StreamWriter
operator|&
name|Writer
argument_list|,
name|OwningPtr
operator|<
name|ObjDumper
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
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

