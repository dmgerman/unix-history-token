begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBDefines.h ---------------------------------------------*- C++ -*-===//
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
name|LLDB_SBDefines_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBDefines_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-versioning.h"
end_include

begin_comment
comment|// Forward Declarations
end_comment

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBAddress
decl_stmt|;
name|class
name|SBBlock
decl_stmt|;
name|class
name|SBBreakpoint
decl_stmt|;
name|class
name|SBBreakpointLocation
decl_stmt|;
name|class
name|SBBroadcaster
decl_stmt|;
name|class
name|SBCommand
decl_stmt|;
name|class
name|SBCommandInterpreter
decl_stmt|;
name|class
name|SBCommandPluginInterface
decl_stmt|;
name|class
name|SBCommandReturnObject
decl_stmt|;
name|class
name|SBCommunication
decl_stmt|;
name|class
name|SBCompileUnit
decl_stmt|;
name|class
name|SBData
decl_stmt|;
name|class
name|SBDebugger
decl_stmt|;
name|class
name|SBDeclaration
decl_stmt|;
name|class
name|SBError
decl_stmt|;
name|class
name|SBEvent
decl_stmt|;
name|class
name|SBEventList
decl_stmt|;
name|class
name|SBExpressionOptions
decl_stmt|;
name|class
name|SBFileSpec
decl_stmt|;
name|class
name|SBFileSpecList
decl_stmt|;
name|class
name|SBFrame
decl_stmt|;
name|class
name|SBFunction
decl_stmt|;
name|class
name|SBHostOS
decl_stmt|;
name|class
name|SBInstruction
decl_stmt|;
name|class
name|SBInstructionList
decl_stmt|;
name|class
name|SBLineEntry
decl_stmt|;
name|class
name|SBListener
decl_stmt|;
name|class
name|SBModule
decl_stmt|;
name|class
name|SBModuleSpec
decl_stmt|;
name|class
name|SBModuleSpecList
decl_stmt|;
name|class
name|SBProcess
decl_stmt|;
name|class
name|SBSourceManager
decl_stmt|;
name|class
name|SBStream
decl_stmt|;
name|class
name|SBStringList
decl_stmt|;
name|class
name|SBSymbol
decl_stmt|;
name|class
name|SBSymbolContext
decl_stmt|;
name|class
name|SBSymbolContextList
decl_stmt|;
name|class
name|SBTarget
decl_stmt|;
name|class
name|SBThread
decl_stmt|;
name|class
name|SBType
decl_stmt|;
name|class
name|SBTypeCategory
decl_stmt|;
name|class
name|SBTypeFilter
decl_stmt|;
name|class
name|SBTypeFormat
decl_stmt|;
name|class
name|SBTypeNameSpecifier
decl_stmt|;
name|class
name|SBTypeSummary
decl_stmt|;
ifndef|#
directive|ifndef
name|LLDB_DISABLE_PYTHON
name|class
name|SBTypeSynthetic
decl_stmt|;
endif|#
directive|endif
name|class
name|SBTypeList
decl_stmt|;
name|class
name|SBValue
decl_stmt|;
name|class
name|SBValueList
decl_stmt|;
name|class
name|SBWatchpoint
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBDefines_h_
end_comment

end_unit

