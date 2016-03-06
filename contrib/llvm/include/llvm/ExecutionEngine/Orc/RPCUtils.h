begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- RPCUTils.h - Basic tilities for building RPC APIs ----*- C++ -*-===//
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
comment|// Basic utilities for building RPC APIs.
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
name|LLVM_EXECUTIONENGINE_ORC_RPCUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_RPCUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
name|namespace
name|remote
block|{
comment|// Base class containing utilities that require partial specialization.
comment|// These cannot be included in RPC, as template class members cannot be
comment|// partially specialized.
name|class
name|RPCBase
block|{
name|protected
label|:
name|template
operator|<
name|typename
name|ProcedureIdT
operator|,
name|ProcedureIdT
name|ProcId
operator|,
name|typename
operator|...
name|Ts
operator|>
name|class
name|ProcedureHelper
block|{
name|public
operator|:
specifier|static
specifier|const
name|ProcedureIdT
name|Id
operator|=
name|ProcId
block|;   }
expr_stmt|;
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|Proc
operator|>
name|class
name|CallHelper
expr_stmt|;
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|ProcedureIdT
operator|,
name|ProcedureIdT
name|ProcId
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|class
name|CallHelper
operator|<
name|ChannelT
operator|,
name|ProcedureHelper
operator|<
name|ProcedureIdT
operator|,
name|ProcId
operator|,
name|ArgTs
operator|...
operator|>>
block|{
name|public
operator|:
specifier|static
name|std
operator|::
name|error_code
name|call
argument_list|(
argument|ChannelT&C
argument_list|,
argument|const ArgTs&... Args
argument_list|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|serialize
argument_list|(
name|C
argument_list|,
name|ProcId
argument_list|)
condition|)
return|return
name|EC
return|;
comment|// If you see a compile-error on this line you're probably calling a
comment|// function with the wrong signature.
return|return
name|serialize_seq
argument_list|(
name|C
argument_list|,
name|Args
operator|...
argument_list|)
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|Proc
operator|>
name|class
name|HandlerHelper
expr_stmt|;
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|ProcedureIdT
operator|,
name|ProcedureIdT
name|ProcId
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|class
name|HandlerHelper
operator|<
name|ChannelT
operator|,
name|ProcedureHelper
operator|<
name|ProcedureIdT
operator|,
name|ProcId
operator|,
name|ArgTs
operator|...
operator|>>
block|{
name|public
operator|:
name|template
operator|<
name|typename
name|HandlerT
operator|>
specifier|static
name|std
operator|::
name|error_code
name|handle
argument_list|(
argument|ChannelT&C
argument_list|,
argument|HandlerT Handler
argument_list|)
block|{
return|return
name|readAndHandle
argument_list|(
name|C
argument_list|,
name|Handler
argument_list|,
name|llvm
operator|::
name|index_sequence_for
operator|<
name|ArgTs
operator|...
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
name|private
operator|:
name|template
operator|<
name|typename
name|HandlerT
block|,
name|size_t
operator|...
name|Is
operator|>
specifier|static
name|std
operator|::
name|error_code
name|readAndHandle
argument_list|(
argument|ChannelT&C
argument_list|,
argument|HandlerT Handler
argument_list|,
argument|llvm::index_sequence<Is...> _
argument_list|)
block|{
name|std
operator|::
name|tuple
operator|<
name|ArgTs
operator|...
operator|>
name|RPCArgs
block|;
if|if
condition|(
name|auto
name|EC
init|=
name|deserialize_seq
argument_list|(
name|C
argument_list|,
name|std
operator|::
name|get
operator|<
name|Is
operator|>
operator|(
name|RPCArgs
operator|)
operator|...
argument_list|)
condition|)
return|return
name|EC
return|;
return|return
name|Handler
argument_list|(
name|std
operator|::
name|get
operator|<
name|Is
operator|>
operator|(
name|RPCArgs
operator|)
operator|...
argument_list|)
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|ClassT
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|class
name|MemberFnWrapper
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|error_code
argument_list|(
name|ClassT
operator|::
operator|*
name|MethodT
argument_list|)
argument_list|(
name|ArgTs
operator|...
argument_list|)
expr_stmt|;
name|MemberFnWrapper
argument_list|(
argument|ClassT&Instance
argument_list|,
argument|MethodT Method
argument_list|)
operator|:
name|Instance
argument_list|(
name|Instance
argument_list|)
operator|,
name|Method
argument_list|(
argument|Method
argument_list|)
block|{}
name|std
operator|::
name|error_code
name|operator
argument_list|()
operator|(
name|ArgTs
operator|&
operator|...
name|Args
operator|)
block|{
return|return
operator|(
name|Instance
operator|.*
name|Method
operator|)
operator|(
name|Args
operator|...
operator|)
return|;
block|}
name|private
label|:
name|ClassT
modifier|&
name|Instance
decl_stmt|;
name|MethodT
name|Method
decl_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
operator|...
name|ArgTs
operator|>
name|class
name|ReadArgs
block|{
name|public
operator|:
name|std
operator|::
name|error_code
name|operator
argument_list|()
operator|(
operator|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|ArgT
block|,
name|typename
operator|...
name|ArgTs
operator|>
name|class
name|ReadArgs
operator|<
name|ArgT
block|,
name|ArgTs
operator|...
operator|>
operator|:
name|public
name|ReadArgs
operator|<
name|ArgTs
operator|...
operator|>
block|{
name|public
operator|:
name|ReadArgs
argument_list|(
name|ArgT
operator|&
name|Arg
argument_list|,
name|ArgTs
operator|&
operator|...
name|Args
argument_list|)
operator|:
name|ReadArgs
operator|<
name|ArgTs
operator|...
operator|>
operator|(
name|Args
operator|...
operator|)
block|,
name|Arg
argument_list|(
argument|Arg
argument_list|)
block|{}
name|std
operator|::
name|error_code
name|operator
argument_list|()
operator|(
name|ArgT
operator|&
name|ArgVal
operator|,
name|ArgTs
operator|&
operator|...
name|ArgVals
operator|)
block|{
name|this
operator|->
name|Arg
operator|=
name|std
operator|::
name|move
argument_list|(
name|ArgVal
argument_list|)
block|;
return|return
name|ReadArgs
operator|<
name|ArgTs
operator|...
operator|>
operator|::
name|operator
argument_list|()
argument_list|(
name|ArgVals
operator|...
argument_list|)
return|;
block|}
name|private
operator|:
name|ArgT
operator|&
name|Arg
block|;   }
block|; }
expr_stmt|;
comment|/// Contains primitive utilities for defining, calling and handling calls to
comment|/// remote procedures. ChannelT is a bidirectional stream conforming to the
comment|/// RPCChannel interface (see RPCChannel.h), and ProcedureIdT is a procedure
comment|/// identifier type that must be serializable on ChannelT.
comment|///
comment|/// These utilities support the construction of very primitive RPC utilities.
comment|/// Their intent is to ensure correct serialization and deserialization of
comment|/// procedure arguments, and to keep the client and server's view of the API in
comment|/// sync.
comment|///
comment|/// These utilities do not support return values. These can be handled by
comment|/// declaring a corresponding '.*Response' procedure and expecting it after a
comment|/// call). They also do not support versioning: the client and server *must* be
comment|/// compiled with the same procedure definitions.
comment|///
comment|///
comment|///
comment|/// Overview (see comments individual types/methods for details):
comment|///
comment|/// Procedure<Id, Args...> :
comment|///
comment|///   associates a unique serializable id with an argument list.
comment|///
comment|///
comment|/// call<Proc>(Channel, Args...) :
comment|///
comment|///   Calls the remote procedure 'Proc' by serializing Proc's id followed by its
comment|/// arguments and sending the resulting bytes to 'Channel'.
comment|///
comment|///
comment|/// handle<Proc>(Channel,<functor matching std::error_code(Args...)> :
comment|///
comment|///   Handles a call to 'Proc' by deserializing its arguments and calling the
comment|/// given functor. This assumes that the id for 'Proc' has already been
comment|/// deserialized.
comment|///
comment|/// expect<Proc>(Channel,<functor matching std::error_code(Args...)> :
comment|///
comment|///   The same as 'handle', except that the procedure id should not have been
comment|/// read yet. Expect will deserialize the id and assert that it matches Proc's
comment|/// id. If it does not, and unexpected RPC call error is returned.
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|ProcedureIdT
operator|=
name|uint32_t
operator|>
name|class
name|RPC
operator|:
name|public
name|RPCBase
block|{
name|public
operator|:
comment|/// Utility class for defining/referring to RPC procedures.
comment|///
comment|/// Typedefs of this utility are used when calling/handling remote procedures.
comment|///
comment|/// ProcId should be a unique value of ProcedureIdT (i.e. not used with any
comment|/// other Procedure typedef in the RPC API being defined.
comment|///
comment|/// the template argument Ts... gives the argument list for the remote
comment|/// procedure.
comment|///
comment|/// E.g.
comment|///
comment|///   typedef Procedure<0, bool> Proc1;
comment|///   typedef Procedure<1, std::string, std::vector<int>> Proc2;
comment|///
comment|///   if (auto EC = call<Proc1>(Channel, true))
comment|///     /* handle EC */;
comment|///
comment|///   if (auto EC = expect<Proc2>(Channel,
comment|///         [](std::string&S, std::vector<int>&V) {
comment|///           // Stuff.
comment|///           return std::error_code();
comment|///         })
comment|///     /* handle EC */;
comment|///
name|template
operator|<
name|ProcedureIdT
name|ProcId
block|,
name|typename
operator|...
name|Ts
operator|>
name|using
name|Procedure
operator|=
name|ProcedureHelper
operator|<
name|ProcedureIdT
block|,
name|ProcId
block|,
name|Ts
operator|...
operator|>
block|;
comment|/// Serialize Args... to channel C, but do not call C.send().
comment|///
comment|/// For buffered channels, this can be used to queue up several calls before
comment|/// flushing the channel.
name|template
operator|<
name|typename
name|Proc
block|,
name|typename
operator|...
name|ArgTs
operator|>
specifier|static
name|std
operator|::
name|error_code
name|appendCall
argument_list|(
argument|ChannelT&C
argument_list|,
argument|const ArgTs&... Args
argument_list|)
block|{
return|return
name|CallHelper
operator|<
name|ChannelT
operator|,
name|Proc
operator|>
operator|::
name|call
argument_list|(
name|C
argument_list|,
name|Args
operator|...
argument_list|)
return|;
block|}
comment|/// Serialize Args... to channel C and call C.send().
name|template
operator|<
name|typename
name|Proc
block|,
name|typename
operator|...
name|ArgTs
operator|>
specifier|static
name|std
operator|::
name|error_code
name|call
argument_list|(
argument|ChannelT&C
argument_list|,
argument|const ArgTs&... Args
argument_list|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|appendCall
operator|<
name|Proc
operator|>
operator|(
name|C
expr|,
name|Args
operator|...
operator|)
condition|)
return|return
name|EC
return|;
return|return
name|C
operator|.
name|send
argument_list|()
return|;
block|}
comment|/// Deserialize and return an enum whose underlying type is ProcedureIdT.
specifier|static
name|std
operator|::
name|error_code
name|getNextProcId
argument_list|(
argument|ChannelT&C
argument_list|,
argument|ProcedureIdT&Id
argument_list|)
block|{
return|return
name|deserialize
argument_list|(
name|C
argument_list|,
name|Id
argument_list|)
return|;
block|}
comment|/// Deserialize args for Proc from C and call Handler. The signature of
comment|/// handler must conform to 'std::error_code(Args...)' where Args... matches
comment|/// the arguments used in the Proc typedef.
name|template
operator|<
name|typename
name|Proc
operator|,
name|typename
name|HandlerT
operator|>
specifier|static
name|std
operator|::
name|error_code
name|handle
argument_list|(
argument|ChannelT&C
argument_list|,
argument|HandlerT Handler
argument_list|)
block|{
return|return
name|HandlerHelper
operator|<
name|ChannelT
operator|,
name|Proc
operator|>
operator|::
name|handle
argument_list|(
name|C
argument_list|,
name|Handler
argument_list|)
return|;
block|}
comment|/// Helper version of 'handle' for calling member functions.
name|template
operator|<
name|typename
name|Proc
operator|,
name|typename
name|ClassT
operator|,
name|typename
operator|...
name|ArgTs
operator|>
specifier|static
name|std
operator|::
name|error_code
name|handle
argument_list|(
argument|ChannelT&C
argument_list|,
argument|ClassT&Instance
argument_list|,
argument|std::error_code (ClassT::*HandlerMethod)(ArgTs...)
argument_list|)
block|{
return|return
name|handle
operator|<
name|Proc
operator|>
operator|(
name|C
operator|,
name|MemberFnWrapper
operator|<
name|ClassT
operator|,
name|ArgTs
operator|...
operator|>
operator|(
name|Instance
operator|,
name|HandlerMethod
operator|)
operator|)
return|;
block|}
comment|/// Deserialize a ProcedureIdT from C and verify it matches the id for Proc.
comment|/// If the id does match, deserialize the arguments and call the handler
comment|/// (similarly to handle).
comment|/// If the id does not match, return an unexpect RPC call error and do not
comment|/// deserialize any further bytes.
name|template
operator|<
name|typename
name|Proc
operator|,
name|typename
name|HandlerT
operator|>
specifier|static
name|std
operator|::
name|error_code
name|expect
argument_list|(
argument|ChannelT&C
argument_list|,
argument|HandlerT Handler
argument_list|)
block|{
name|ProcedureIdT
name|ProcId
block|;
if|if
condition|(
name|auto
name|EC
init|=
name|getNextProcId
argument_list|(
name|C
argument_list|,
name|ProcId
argument_list|)
condition|)
return|return
name|EC
return|;
if|if
condition|(
name|ProcId
operator|!=
name|Proc
operator|::
name|Id
condition|)
return|return
name|orcError
argument_list|(
name|OrcErrorCode
operator|::
name|UnexpectedRPCCall
argument_list|)
return|;
return|return
name|handle
operator|<
name|Proc
operator|>
operator|(
name|C
operator|,
name|Handler
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Helper version of expect for calling member functions.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Proc
operator|,
name|typename
name|ClassT
operator|,
name|typename
operator|...
name|ArgTs
operator|>
specifier|static
name|std
operator|::
name|error_code
name|expect
argument_list|(
argument|ChannelT&C
argument_list|,
argument|ClassT&Instance
argument_list|,
argument|std::error_code (ClassT::*HandlerMethod)(ArgTs...)
argument_list|)
block|{
return|return
name|expect
operator|<
name|Proc
operator|>
operator|(
name|C
operator|,
name|MemberFnWrapper
operator|<
name|ClassT
operator|,
name|ArgTs
operator|...
operator|>
operator|(
name|Instance
operator|,
name|HandlerMethod
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Helper for handling setter procedures - this method returns a functor that
end_comment

begin_comment
comment|/// sets the variables referred to by Args... to values deserialized from the
end_comment

begin_comment
comment|/// channel.
end_comment

begin_comment
comment|/// E.g.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   typedef Procedure<0, bool, int> Proc1;
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   ...
end_comment

begin_comment
comment|///   bool B;
end_comment

begin_comment
comment|///   int I;
end_comment

begin_comment
comment|///   if (auto EC = expect<Proc1>(Channel, readArgs(B, I)))
end_comment

begin_comment
comment|///     /* Handle Args */ ;
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|ArgTs
operator|>
specifier|static
name|ReadArgs
operator|<
name|ArgTs
operator|...
operator|>
name|readArgs
argument_list|(
argument|ArgTs&... Args
argument_list|)
block|{
return|return
name|ReadArgs
operator|<
name|ArgTs
operator|...
operator|>
operator|(
name|Args
operator|...
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace remote
end_comment

begin_comment
unit|}
comment|// end namespace orc
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

