begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------- StackMapPrinter.h - Pretty-print stackmaps --------*- C++ -*-===//
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
name|LLVM_TOOLS_LLVM_READOBJ_STACKMAPPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_READOBJ_STACKMAPPRINTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Object/StackMapParser.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Pretty print a stackmap to the given ostream.
name|template
operator|<
name|typename
name|OStreamT
operator|,
name|typename
name|StackMapParserT
operator|>
name|void
name|prettyPrintStackMap
argument_list|(
argument|OStreamT&OS
argument_list|,
argument|const StackMapParserT&SMP
argument_list|)
block|{
name|OS
operator|<<
literal|"LLVM StackMap Version: "
operator|<<
name|SMP
operator|.
name|getVersion
argument_list|()
operator|<<
literal|"\nNum Functions: "
operator|<<
name|SMP
operator|.
name|getNumFunctions
argument_list|()
block|;
comment|// Functions:
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|F
range|:
name|SMP
operator|.
name|functions
argument_list|()
control|)
name|OS
operator|<<
literal|"\n  Function address: "
operator|<<
name|F
operator|.
name|getFunctionAddress
argument_list|()
operator|<<
literal|", stack size: "
operator|<<
name|F
operator|.
name|getStackSize
argument_list|()
operator|<<
literal|", callsite record count: "
operator|<<
name|F
operator|.
name|getRecordCount
argument_list|()
expr_stmt|;
comment|// Constants:
name|OS
operator|<<
literal|"\nNum Constants: "
operator|<<
name|SMP
operator|.
name|getNumConstants
argument_list|()
expr_stmt|;
name|unsigned
name|ConstantIndex
init|=
literal|0
decl_stmt|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|C
range|:
name|SMP
operator|.
name|constants
argument_list|()
control|)
name|OS
operator|<<
literal|"\n  #"
operator|<<
operator|++
name|ConstantIndex
operator|<<
literal|": "
operator|<<
name|C
operator|.
name|getValue
argument_list|()
expr_stmt|;
comment|// Records:
name|OS
operator|<<
literal|"\nNum Records: "
operator|<<
name|SMP
operator|.
name|getNumRecords
argument_list|()
expr_stmt|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|R
range|:
name|SMP
operator|.
name|records
argument_list|()
control|)
block|{
name|OS
operator|<<
literal|"\n  Record ID: "
operator|<<
name|R
operator|.
name|getID
argument_list|()
operator|<<
literal|", instruction offset: "
operator|<<
name|R
operator|.
name|getInstructionOffset
argument_list|()
operator|<<
literal|"\n    "
operator|<<
name|R
operator|.
name|getNumLocations
argument_list|()
operator|<<
literal|" locations:"
expr_stmt|;
name|unsigned
name|LocationIndex
init|=
literal|0
decl_stmt|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Loc
range|:
name|R
operator|.
name|locations
argument_list|()
control|)
block|{
name|OS
operator|<<
literal|"\n      #"
operator|<<
operator|++
name|LocationIndex
operator|<<
literal|": "
expr_stmt|;
switch|switch
condition|(
name|Loc
operator|.
name|getKind
argument_list|()
condition|)
block|{
case|case
name|StackMapParserT
operator|::
name|LocationKind
operator|::
name|Register
case|:
name|OS
operator|<<
literal|"Register R#"
operator|<<
name|Loc
operator|.
name|getDwarfRegNum
argument_list|()
expr_stmt|;
break|break;
case|case
name|StackMapParserT
operator|::
name|LocationKind
operator|::
name|Direct
case|:
name|OS
operator|<<
literal|"Direct R#"
operator|<<
name|Loc
operator|.
name|getDwarfRegNum
argument_list|()
operator|<<
literal|" + "
operator|<<
name|Loc
operator|.
name|getOffset
argument_list|()
expr_stmt|;
break|break;
case|case
name|StackMapParserT
operator|::
name|LocationKind
operator|::
name|Indirect
case|:
name|OS
operator|<<
literal|"Indirect [R#"
operator|<<
name|Loc
operator|.
name|getDwarfRegNum
argument_list|()
operator|<<
literal|" + "
operator|<<
name|Loc
operator|.
name|getOffset
argument_list|()
operator|<<
literal|"]"
expr_stmt|;
break|break;
case|case
name|StackMapParserT
operator|::
name|LocationKind
operator|::
name|Constant
case|:
name|OS
operator|<<
literal|"Constant "
operator|<<
name|Loc
operator|.
name|getSmallConstant
argument_list|()
expr_stmt|;
break|break;
case|case
name|StackMapParserT
operator|::
name|LocationKind
operator|::
name|ConstantIndex
case|:
name|OS
operator|<<
literal|"ConstantIndex #"
operator|<<
name|Loc
operator|.
name|getConstantIndex
argument_list|()
operator|<<
literal|" ("
operator|<<
name|SMP
operator|.
name|getConstant
argument_list|(
name|Loc
operator|.
name|getConstantIndex
argument_list|()
argument_list|)
operator|.
name|getValue
argument_list|()
operator|<<
literal|")"
expr_stmt|;
break|break;
block|}
block|}
name|OS
operator|<<
literal|"\n    "
operator|<<
name|R
operator|.
name|getNumLiveOuts
argument_list|()
operator|<<
literal|" live-outs: [ "
expr_stmt|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|LO
range|:
name|R
operator|.
name|liveouts
argument_list|()
control|)
name|OS
operator|<<
literal|"R#"
operator|<<
name|LO
operator|.
name|getDwarfRegNum
argument_list|()
operator|<<
literal|" ("
operator|<<
name|LO
operator|.
name|getSizeInBytes
argument_list|()
operator|<<
literal|"-bytes) "
expr_stmt|;
name|OS
operator|<<
literal|"]\n"
expr_stmt|;
block|}
name|OS
operator|<<
literal|"\n"
expr_stmt|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

