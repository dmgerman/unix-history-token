begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolContextScope.h ------------------------------------*- C++ -*-===//
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
name|liblldb_SymbolContextScope_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SymbolContextScope_h_
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
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class SymbolContextScope SymbolContextScope.h "lldb/Symbol/SymbolContextScope.h"
comment|/// @brief Inherit from this if your object is part of a symbol context
comment|///        and can reconstruct its symbol context.
comment|///
comment|/// Many objects that are part of a symbol context that have pointers
comment|/// back to parent objects that own them. Any members of a symbol
comment|/// context that, once they are built, will not go away, can inherit
comment|/// from this pure virtual class and can then reconstruct their symbol
comment|/// context without having to keep a complete SymbolContext object in
comment|/// the object.
comment|///
comment|/// Examples of these objects include:
comment|///     @li Module
comment|///     @li CompileUnit
comment|///     @li Function
comment|///     @li Block
comment|///     @li Symbol
comment|///
comment|/// Other objects can store a "SymbolContextScope *" using any pointers
comment|/// to one of the above objects. This allows clients to hold onto a
comment|/// pointer that uniquely will identify a symbol context. Those clients
comment|/// can then always reconstruct the symbol context using the pointer, or
comment|/// use it to uniquely identify a symbol context for an object.
comment|///
comment|/// Example objects include that currently use "SymbolContextScope *"
comment|/// objects include:
comment|///     @li Variable objects that can reconstruct where they are scoped
comment|///         by making sure the SymbolContextScope * comes from the scope
comment|///         in which the variable was declared. If a variable is a global,
comment|///         the appropriate CompileUnit * will be used when creating the
comment|///         variable. A static function variables, can the Block scope
comment|///         in which the variable is defined. Function arguments can use
comment|///         the Function object as their scope. The SymbolFile parsers
comment|///         will set these correctly as the variables are parsed.
comment|///     @li Type objects that know exactly in which scope they
comment|///         originated much like the variables above.
comment|///     @li StackID objects that are able to know that if the CFA
comment|///         (stack pointer at the beginning of a function) and the
comment|///         start PC for the function/symbol and the SymbolContextScope
comment|///         pointer (a unique pointer that identifies a symbol context
comment|///         location) match within the same thread, that the stack
comment|///         frame is the same as the previous stack frame.
comment|///
comment|/// Objects that adhere to this protocol can reconstruct enough of a
comment|/// symbol context to allow functions that take a symbol context to be
comment|/// called. Lists can also be created using a SymbolContextScope* and
comment|/// and object pairs that allow large collections of objects to be
comment|/// passed around with minimal overhead.
comment|//----------------------------------------------------------------------
name|class
name|SymbolContextScope
block|{
name|public
label|:
name|virtual
operator|~
name|SymbolContextScope
argument_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Reconstruct the object's symbol context into \a sc.
comment|///
comment|/// The object should fill in as much of the SymbolContext as it
comment|/// can so function calls that require a symbol context can be made
comment|/// for the given object.
comment|///
comment|/// @param[out] sc
comment|///     A symbol context object pointer that gets filled in.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|CalculateSymbolContext
argument_list|(
name|SymbolContext
operator|*
name|sc
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|lldb
operator|::
name|ModuleSP
name|CalculateSymbolContextModule
argument_list|()
block|{
return|return
name|lldb
operator|::
name|ModuleSP
argument_list|()
return|;
block|}
name|virtual
name|CompileUnit
modifier|*
name|CalculateSymbolContextCompileUnit
parameter_list|()
block|{
return|return
name|NULL
return|;
block|}
name|virtual
name|Function
modifier|*
name|CalculateSymbolContextFunction
parameter_list|()
block|{
return|return
name|NULL
return|;
block|}
name|virtual
name|Block
modifier|*
name|CalculateSymbolContextBlock
parameter_list|()
block|{
return|return
name|NULL
return|;
block|}
name|virtual
name|Symbol
modifier|*
name|CalculateSymbolContextSymbol
parameter_list|()
block|{
return|return
name|NULL
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Dump the object's symbol context to the stream \a s.
comment|///
comment|/// The object should dump its symbol context to the stream \a s.
comment|/// This function is widely used in the DumpDebug and verbose output
comment|/// for lldb objects.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object's symbol context.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DumpSymbolContext
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_SymbolContextScope_h_
end_comment

end_unit

