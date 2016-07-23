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
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/Orc/OrcError.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_comment
comment|// concrt.h depends on eh.h for __uncaught_exception declaration
end_comment

begin_comment
comment|// even if we disable exceptions.
end_comment

begin_include
include|#
directive|include
file|<eh.h>
end_include

begin_comment
comment|// Disable warnings from ppltasks.h transitively included by<future>.
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4530
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4062
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<future>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

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
comment|/// Describes reserved RPC Function Ids.
comment|///
comment|/// The default implementation will serve for integer and enum function id
comment|/// types. If you want to use a custom type as your FunctionId you can
comment|/// specialize this class and provide unique values for InvalidId,
comment|/// ResponseId and FirstValidId.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|RPCFunctionIdTraits
block|{
name|public
operator|:
specifier|static
specifier|const
name|T
name|InvalidId
operator|=
name|static_cast
operator|<
name|T
operator|>
operator|(
literal|0
operator|)
block|;
specifier|static
specifier|const
name|T
name|ResponseId
operator|=
name|static_cast
operator|<
name|T
operator|>
operator|(
literal|1
operator|)
block|;
specifier|static
specifier|const
name|T
name|FirstValidId
operator|=
name|static_cast
operator|<
name|T
operator|>
operator|(
literal|2
operator|)
block|; }
expr_stmt|;
comment|// Base class containing utilities that require partial specialization.
comment|// These cannot be included in RPC, as template class members cannot be
comment|// partially specialized.
name|class
name|RPCBase
block|{
name|protected
label|:
comment|// RPC Function description type.
comment|//
comment|// This class provides the information and operations needed to support the
comment|// RPC primitive operations (call, expect, etc) for a given function. It
comment|// is specialized for void and non-void functions to deal with the differences
comment|// betwen the two. Both specializations have the same interface:
comment|//
comment|// Id - The function's unique identifier.
comment|// OptionalReturn - The return type for asyncronous calls.
comment|// ErrorReturn - The return type for synchronous calls.
comment|// optionalToErrorReturn - Conversion from a valid OptionalReturn to an
comment|//                         ErrorReturn.
comment|// readResult - Deserialize a result from a channel.
comment|// abandon - Abandon a promised (asynchronous) result.
comment|// respond - Retun a result on the channel.
name|template
operator|<
name|typename
name|FunctionIdT
operator|,
name|FunctionIdT
name|FuncId
operator|,
name|typename
name|FnT
operator|>
name|class
name|FunctionHelper
block|{}
expr_stmt|;
comment|// RPC Function description specialization for non-void functions.
name|template
operator|<
name|typename
name|FunctionIdT
operator|,
name|FunctionIdT
name|FuncId
operator|,
name|typename
name|RetT
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|class
name|FunctionHelper
operator|<
name|FunctionIdT
operator|,
name|FuncId
operator|,
name|RetT
argument_list|(
name|ArgTs
operator|...
argument_list|)
operator|>
block|{
name|public
operator|:
name|static_assert
argument_list|(
name|FuncId
operator|!=
name|RPCFunctionIdTraits
operator|<
name|FunctionIdT
operator|>
operator|::
name|InvalidId
operator|&&
name|FuncId
operator|!=
name|RPCFunctionIdTraits
operator|<
name|FunctionIdT
operator|>
operator|::
name|ResponseId
argument_list|,
literal|"Cannot define custom function with InvalidId or ResponseId. "
literal|"Please use RPCFunctionTraits<FunctionIdT>::FirstValidId."
argument_list|)
block|;
specifier|static
specifier|const
name|FunctionIdT
name|Id
operator|=
name|FuncId
block|;
typedef|typedef
name|Optional
operator|<
name|RetT
operator|>
name|OptionalReturn
expr_stmt|;
typedef|typedef
name|Expected
operator|<
name|RetT
operator|>
name|ErrorReturn
expr_stmt|;
specifier|static
name|ErrorReturn
name|optionalToErrorReturn
argument_list|(
name|OptionalReturn
operator|&&
name|V
argument_list|)
block|{
name|assert
argument_list|(
name|V
operator|&&
literal|"Return value not available"
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|V
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|ChannelT
operator|>
specifier|static
name|Error
name|readResult
argument_list|(
argument|ChannelT&C
argument_list|,
argument|std::promise<OptionalReturn>&P
argument_list|)
block|{
name|RetT
name|Val
block|;
name|auto
name|Err
operator|=
name|deserialize
argument_list|(
name|C
argument_list|,
name|Val
argument_list|)
block|;
name|auto
name|Err2
operator|=
name|endReceiveMessage
argument_list|(
name|C
argument_list|)
block|;
name|Err
operator|=
name|joinErrors
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|Err2
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|Err
condition|)
block|{
name|P
operator|.
name|set_value
argument_list|(
name|OptionalReturn
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|Err
return|;
block|}
name|P
operator|.
name|set_value
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Val
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
specifier|static
name|void
name|abandon
argument_list|(
name|std
operator|::
name|promise
operator|<
name|OptionalReturn
operator|>
operator|&
name|P
argument_list|)
block|{
name|P
operator|.
name|set_value
argument_list|(
name|OptionalReturn
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|SequenceNumberT
operator|>
specifier|static
name|Error
name|respond
argument_list|(
argument|ChannelT&C
argument_list|,
argument|SequenceNumberT SeqNo
argument_list|,
argument|ErrorReturn&Result
argument_list|)
block|{
name|FunctionIdT
name|ResponseId
operator|=
name|RPCFunctionIdTraits
operator|<
name|FunctionIdT
operator|>
operator|::
name|ResponseId
block|;
comment|// If the handler returned an error then bail out with that.
if|if
condition|(
operator|!
name|Result
condition|)
return|return
name|Result
operator|.
name|takeError
argument_list|()
return|;
comment|// Otherwise open a new message on the channel and send the result.
if|if
condition|(
name|auto
name|Err
init|=
name|startSendMessage
argument_list|(
name|C
argument_list|)
condition|)
return|return
name|Err
return|;
if|if
condition|(
name|auto
name|Err
init|=
name|serializeSeq
argument_list|(
name|C
argument_list|,
name|ResponseId
argument_list|,
name|SeqNo
argument_list|,
operator|*
name|Result
argument_list|)
condition|)
return|return
name|Err
return|;
return|return
name|endSendMessage
argument_list|(
name|C
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|// RPC Function description specialization for void functions.
name|template
operator|<
name|typename
name|FunctionIdT
operator|,
name|FunctionIdT
name|FuncId
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|class
name|FunctionHelper
operator|<
name|FunctionIdT
operator|,
name|FuncId
operator|,
name|void
argument_list|(
name|ArgTs
operator|...
argument_list|)
operator|>
block|{
name|public
operator|:
name|static_assert
argument_list|(
name|FuncId
operator|!=
name|RPCFunctionIdTraits
operator|<
name|FunctionIdT
operator|>
operator|::
name|InvalidId
operator|&&
name|FuncId
operator|!=
name|RPCFunctionIdTraits
operator|<
name|FunctionIdT
operator|>
operator|::
name|ResponseId
argument_list|,
literal|"Cannot define custom function with InvalidId or ResponseId. "
literal|"Please use RPCFunctionTraits<FunctionIdT>::FirstValidId."
argument_list|)
block|;
specifier|static
specifier|const
name|FunctionIdT
name|Id
operator|=
name|FuncId
block|;
typedef|typedef
name|bool
name|OptionalReturn
typedef|;
typedef|typedef
name|Error
name|ErrorReturn
typedef|;
specifier|static
name|ErrorReturn
name|optionalToErrorReturn
argument_list|(
name|OptionalReturn
operator|&&
name|V
argument_list|)
block|{
name|assert
argument_list|(
name|V
operator|&&
literal|"Return value not available"
argument_list|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|ChannelT
operator|>
specifier|static
name|Error
name|readResult
argument_list|(
argument|ChannelT&C
argument_list|,
argument|std::promise<OptionalReturn>&P
argument_list|)
block|{
comment|// Void functions don't have anything to deserialize, so we're good.
name|P
operator|.
name|set_value
argument_list|(
name|true
argument_list|)
block|;
return|return
name|endReceiveMessage
argument_list|(
name|C
argument_list|)
return|;
block|}
specifier|static
name|void
name|abandon
argument_list|(
name|std
operator|::
name|promise
operator|<
name|OptionalReturn
operator|>
operator|&
name|P
argument_list|)
block|{
name|P
operator|.
name|set_value
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|SequenceNumberT
operator|>
specifier|static
name|Error
name|respond
argument_list|(
argument|ChannelT&C
argument_list|,
argument|SequenceNumberT SeqNo
argument_list|,
argument|ErrorReturn&Result
argument_list|)
block|{
specifier|const
name|FunctionIdT
name|ResponseId
operator|=
name|RPCFunctionIdTraits
operator|<
name|FunctionIdT
operator|>
operator|::
name|ResponseId
block|;
comment|// If the handler returned an error then bail out with that.
if|if
condition|(
name|Result
condition|)
return|return
name|std
operator|::
name|move
argument_list|(
name|Result
argument_list|)
return|;
comment|// Otherwise open a new message on the channel and send the result.
if|if
condition|(
name|auto
name|Err
init|=
name|startSendMessage
argument_list|(
name|C
argument_list|)
condition|)
return|return
name|Err
return|;
if|if
condition|(
name|auto
name|Err
init|=
name|serializeSeq
argument_list|(
name|C
argument_list|,
name|ResponseId
argument_list|,
name|SeqNo
argument_list|)
condition|)
return|return
name|Err
return|;
return|return
name|endSendMessage
argument_list|(
name|C
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|// Helper for the call primitive.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|SequenceNumberT
operator|,
name|typename
name|Func
operator|>
name|class
name|CallHelper
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|SequenceNumberT
operator|,
name|typename
name|FunctionIdT
operator|,
name|FunctionIdT
name|FuncId
operator|,
name|typename
name|RetT
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
name|SequenceNumberT
operator|,
name|FunctionHelper
operator|<
name|FunctionIdT
operator|,
name|FuncId
operator|,
name|RetT
argument_list|(
name|ArgTs
operator|...
argument_list|)
operator|>>
block|{
name|public
operator|:
specifier|static
name|Error
name|call
argument_list|(
argument|ChannelT&C
argument_list|,
argument|SequenceNumberT SeqNo
argument_list|,
argument|const ArgTs&... Args
argument_list|)
block|{
if|if
condition|(
name|auto
name|Err
init|=
name|startSendMessage
argument_list|(
name|C
argument_list|)
condition|)
return|return
name|Err
return|;
if|if
condition|(
name|auto
name|Err
init|=
name|serializeSeq
argument_list|(
name|C
argument_list|,
name|FuncId
argument_list|,
name|SeqNo
argument_list|,
name|Args
operator|...
argument_list|)
condition|)
return|return
name|Err
return|;
end_expr_stmt

begin_return
return|return
name|endSendMessage
argument_list|(
name|C
argument_list|)
return|;
end_return

begin_empty_stmt
unit|}   }
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Helper for handle primitive.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|SequenceNumberT
operator|,
name|typename
name|Func
operator|>
name|class
name|HandlerHelper
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|SequenceNumberT
operator|,
name|typename
name|FunctionIdT
operator|,
name|FunctionIdT
name|FuncId
operator|,
name|typename
name|RetT
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
name|SequenceNumberT
operator|,
name|FunctionHelper
operator|<
name|FunctionIdT
operator|,
name|FuncId
operator|,
name|RetT
argument_list|(
name|ArgTs
operator|...
argument_list|)
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
name|Error
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
end_expr_stmt

begin_typedef
typedef|typedef
name|FunctionHelper
operator|<
name|FunctionIdT
operator|,
name|FuncId
operator|,
name|RetT
argument_list|(
name|ArgTs
operator|...
argument_list|)
operator|>
name|Func
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|HandlerT
operator|,
name|size_t
operator|...
name|Is
operator|>
specifier|static
name|Error
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
name|SequenceNumberT
name|SeqNo
block|;
comment|// GCC 4.7 and 4.8 incorrectly issue a -Wunused-but-set-variable warning
comment|// for RPCArgs. Void cast RPCArgs to work around this for now.
comment|// FIXME: Remove this workaround once we can assume a working GCC version.
operator|(
name|void
operator|)
name|RPCArgs
block|;
if|if
condition|(
name|auto
name|Err
init|=
name|deserializeSeq
argument_list|(
name|C
argument_list|,
name|SeqNo
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
name|Err
return|;
end_expr_stmt

begin_comment
comment|// We've deserialized the arguments, so unlock the channel for reading
end_comment

begin_comment
comment|// before we call the handler. This allows recursive RPC calls.
end_comment

begin_if
if|if
condition|(
name|auto
name|Err
init|=
name|endReceiveMessage
argument_list|(
name|C
argument_list|)
condition|)
return|return
name|Err
return|;
end_if

begin_comment
comment|// Run the handler and get the result.
end_comment

begin_decl_stmt
name|auto
name|Result
init|=
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Return the result to the client.
end_comment

begin_return
return|return
name|Func
operator|::
name|template
name|respond
operator|<
name|ChannelT
operator|,
name|SequenceNumberT
operator|>
operator|(
name|C
operator|,
name|SeqNo
operator|,
name|Result
operator|)
return|;
end_return

begin_empty_stmt
unit|}   }
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Helper for wrapping member functions up as functors.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ClassT
operator|,
name|typename
name|RetT
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
name|RetT
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
name|RetT
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
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|ClassT
modifier|&
name|Instance
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MethodT
name|Method
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Helper that provides a Functor for deserializing arguments.
end_comment

begin_expr_stmt
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
name|Error
name|operator
argument_list|()
operator|(
operator|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|ArgT
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|class
name|ReadArgs
operator|<
name|ArgT
operator|,
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
name|Error
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
expr_stmt|;
end_expr_stmt

begin_comment
unit|}; };
comment|/// Contains primitive utilities for defining, calling and handling calls to
end_comment

begin_comment
comment|/// remote procedures. ChannelT is a bidirectional stream conforming to the
end_comment

begin_comment
comment|/// RPCChannel interface (see RPCChannel.h), and FunctionIdT is a procedure
end_comment

begin_comment
comment|/// identifier type that must be serializable on ChannelT.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These utilities support the construction of very primitive RPC utilities.
end_comment

begin_comment
comment|/// Their intent is to ensure correct serialization and deserialization of
end_comment

begin_comment
comment|/// procedure arguments, and to keep the client and server's view of the API in
end_comment

begin_comment
comment|/// sync.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These utilities do not support return values. These can be handled by
end_comment

begin_comment
comment|/// declaring a corresponding '.*Response' procedure and expecting it after a
end_comment

begin_comment
comment|/// call). They also do not support versioning: the client and server *must* be
end_comment

begin_comment
comment|/// compiled with the same procedure definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Overview (see comments individual types/methods for details):
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Function<Id, Args...> :
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   associates a unique serializable id with an argument list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// call<Func>(Channel, Args...) :
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Calls the remote procedure 'Func' by serializing Func's id followed by its
end_comment

begin_comment
comment|/// arguments and sending the resulting bytes to 'Channel'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// handle<Func>(Channel,<functor matching Error(Args...)> :
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Handles a call to 'Func' by deserializing its arguments and calling the
end_comment

begin_comment
comment|/// given functor. This assumes that the id for 'Func' has already been
end_comment

begin_comment
comment|/// deserialized.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// expect<Func>(Channel,<functor matching Error(Args...)> :
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   The same as 'handle', except that the procedure id should not have been
end_comment

begin_comment
comment|/// read yet. Expect will deserialize the id and assert that it matches Func's
end_comment

begin_comment
comment|/// id. If it does not, and unexpected RPC call error is returned.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ChannelT
operator|,
name|typename
name|FunctionIdT
operator|=
name|uint32_t
operator|,
name|typename
name|SequenceNumberT
operator|=
name|uint16_t
operator|>
name|class
name|RPC
operator|:
name|public
name|RPCBase
block|{
name|public
operator|:
comment|/// RPC default constructor.
name|RPC
argument_list|()
operator|=
expr|default
block|;
comment|/// RPC instances cannot be copied.
name|RPC
argument_list|(
specifier|const
name|RPC
operator|&
argument_list|)
operator|=
name|delete
block|;
comment|/// RPC instances cannot be copied.
name|RPC
operator|&
name|operator
operator|=
operator|(
specifier|const
name|RPC
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// RPC move constructor.
comment|// FIXME: Remove once MSVC can synthesize move ops.
name|RPC
argument_list|(
name|RPC
operator|&&
name|Other
argument_list|)
operator|:
name|SequenceNumberMgr
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|SequenceNumberMgr
argument_list|)
argument_list|)
block|,
name|OutstandingResults
argument_list|(
argument|std::move(Other.OutstandingResults)
argument_list|)
block|{}
comment|/// RPC move assignment.
comment|// FIXME: Remove once MSVC can synthesize move ops.
name|RPC
operator|&
name|operator
operator|=
operator|(
name|RPC
operator|&&
name|Other
operator|)
block|{
name|SequenceNumberMgr
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|SequenceNumberMgr
argument_list|)
block|;
name|OutstandingResults
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|OutstandingResults
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Utility class for defining/referring to RPC procedures.
comment|///
comment|/// Typedefs of this utility are used when calling/handling remote procedures.
comment|///
comment|/// FuncId should be a unique value of FunctionIdT (i.e. not used with any
comment|/// other Function typedef in the RPC API being defined.
comment|///
comment|/// the template argument Ts... gives the argument list for the remote
comment|/// procedure.
comment|///
comment|/// E.g.
comment|///
comment|///   typedef Function<0, bool> Func1;
comment|///   typedef Function<1, std::string, std::vector<int>> Func2;
comment|///
comment|///   if (auto Err = call<Func1>(Channel, true))
comment|///     /* handle Err */;
comment|///
comment|///   if (auto Err = expect<Func2>(Channel,
comment|///         [](std::string&S, std::vector<int>&V) {
comment|///           // Stuff.
comment|///           return Error::success();
comment|///         })
comment|///     /* handle Err */;
comment|///
name|template
operator|<
name|FunctionIdT
name|FuncId
operator|,
name|typename
name|FnT
operator|>
name|using
name|Function
operator|=
name|FunctionHelper
operator|<
name|FunctionIdT
operator|,
name|FuncId
operator|,
name|FnT
operator|>
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return type for asynchronous call primitives.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|>
name|using
name|AsyncCallResult
operator|=
name|std
operator|::
name|future
operator|<
name|typename
name|Func
operator|::
name|OptionalReturn
operator|>
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return type for asynchronous call-with-seq primitives.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|>
name|using
name|AsyncCallWithSeqResult
operator|=
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|future
operator|<
name|typename
name|Func
operator|::
name|OptionalReturn
operator|>
operator|,
name|SequenceNumberT
operator|>
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Serialize Args... to channel C, but do not call C.send().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns an error (on serialization failure) or a pair of:
end_comment

begin_comment
comment|/// (1) A future Optional<T> (or future<bool> for void functions), and
end_comment

begin_comment
comment|/// (2) A sequence number.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This utility function is primarily used for single-threaded mode support,
end_comment

begin_comment
comment|/// where the sequence number can be used to wait for the corresponding
end_comment

begin_comment
comment|/// result. In multi-threaded mode the appendCallAsync method, which does not
end_comment

begin_comment
comment|/// return the sequence numeber, should be preferred.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|Expected
operator|<
name|AsyncCallWithSeqResult
operator|<
name|Func
operator|>>
name|appendCallAsyncWithSeq
argument_list|(
argument|ChannelT&C
argument_list|,
argument|const ArgTs&... Args
argument_list|)
block|{
name|auto
name|SeqNo
operator|=
name|SequenceNumberMgr
operator|.
name|getSequenceNumber
argument_list|()
block|;
name|std
operator|::
name|promise
operator|<
name|typename
name|Func
operator|::
name|OptionalReturn
operator|>
name|Promise
block|;
name|auto
name|Result
operator|=
name|Promise
operator|.
name|get_future
argument_list|()
block|;
name|OutstandingResults
index|[
name|SeqNo
index|]
operator|=
name|createOutstandingResult
operator|<
name|Func
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|Promise
argument_list|)
operator|)
block|;
if|if
condition|(
name|auto
name|Err
init|=
name|CallHelper
operator|<
name|ChannelT
condition|,
name|SequenceNumberT
condition|,
name|Func
decl|>::
name|call
argument_list|(
name|C
argument_list|,
name|SeqNo
argument_list|,
name|Args
operator|...
argument_list|)
condition|)
block|{
name|abandonOutstandingResults
argument_list|()
expr_stmt|;
return|return
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
return|;
block|}
end_expr_stmt

begin_else
else|else
return|return
name|AsyncCallWithSeqResult
operator|<
name|Func
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|Result
argument_list|)
operator|,
name|SeqNo
operator|)
return|;
end_else

begin_comment
unit|}
comment|/// The same as appendCallAsyncWithSeq, except that it calls C.send() to
end_comment

begin_comment
comment|/// flush the channel after serializing the call.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Func
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|Expected
operator|<
name|AsyncCallWithSeqResult
operator|<
name|Func
operator|>>
name|callAsyncWithSeq
argument_list|(
argument|ChannelT&C
argument_list|,
argument|const ArgTs&... Args
argument_list|)
block|{
name|auto
name|Result
operator|=
name|appendCallAsyncWithSeq
operator|<
name|Func
operator|>
operator|(
name|C
operator|,
name|Args
operator|...
operator|)
block|;
if|if
condition|(
operator|!
name|Result
condition|)
return|return
name|Result
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|auto
name|Err
init|=
name|C
operator|.
name|send
argument_list|()
condition|)
block|{
name|abandonOutstandingResults
argument_list|()
expr_stmt|;
return|return
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
return|;
block|}
end_if

begin_return
return|return
name|Result
return|;
end_return

begin_comment
unit|}
comment|/// Serialize Args... to channel C, but do not call send.
end_comment

begin_comment
comment|/// Returns an error if serialization fails, otherwise returns a
end_comment

begin_comment
comment|/// std::future<Optional<T>> (or a future<bool> for void functions).
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Func
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|Expected
operator|<
name|AsyncCallResult
operator|<
name|Func
operator|>>
name|appendCallAsync
argument_list|(
argument|ChannelT&C
argument_list|,
argument|const ArgTs&... Args
argument_list|)
block|{
name|auto
name|ResAndSeqOrErr
operator|=
name|appendCallAsyncWithSeq
operator|<
name|Func
operator|>
operator|(
name|C
operator|,
name|Args
operator|...
operator|)
block|;
if|if
condition|(
name|ResAndSeqOrErr
condition|)
return|return
name|std
operator|::
name|move
argument_list|(
name|ResAndSeqOrErr
operator|->
name|first
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|ResAndSeqOrErr
operator|.
name|getError
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// The same as appendCallAsync, except that it calls C.send to flush the
end_comment

begin_comment
comment|/// channel after serializing the call.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Func
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|Expected
operator|<
name|AsyncCallResult
operator|<
name|Func
operator|>>
name|callAsync
argument_list|(
argument|ChannelT&C
argument_list|,
argument|const ArgTs&... Args
argument_list|)
block|{
name|auto
name|ResAndSeqOrErr
operator|=
name|callAsyncWithSeq
operator|<
name|Func
operator|>
operator|(
name|C
operator|,
name|Args
operator|...
operator|)
block|;
if|if
condition|(
name|ResAndSeqOrErr
condition|)
return|return
name|std
operator|::
name|move
argument_list|(
name|ResAndSeqOrErr
operator|->
name|first
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|ResAndSeqOrErr
operator|.
name|getError
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// This can be used in single-threaded mode.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Func
operator|,
name|typename
name|HandleFtor
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|typename
name|Func
operator|::
name|ErrorReturn
name|callSTHandling
argument_list|(
argument|ChannelT&C
argument_list|,
argument|HandleFtor&HandleOther
argument_list|,
argument|const ArgTs&... Args
argument_list|)
block|{
if|if
condition|(
name|auto
name|ResultAndSeqNoOrErr
init|=
name|callAsyncWithSeq
operator|<
name|Func
operator|>
operator|(
name|C
expr|,
name|Args
operator|...
operator|)
condition|)
block|{
name|auto
operator|&
name|ResultAndSeqNo
operator|=
operator|*
name|ResultAndSeqNoOrErr
expr_stmt|;
if|if
condition|(
name|auto
name|Err
init|=
name|waitForResult
argument_list|(
name|C
argument_list|,
name|ResultAndSeqNo
operator|.
name|second
argument_list|,
name|HandleOther
argument_list|)
condition|)
return|return
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
return|;
return|return
name|Func
operator|::
name|optionalToErrorReturn
argument_list|(
name|ResultAndSeqNo
operator|.
name|first
operator|.
name|get
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_else
else|else
return|return
name|ResultAndSeqNoOrErr
operator|.
name|takeError
argument_list|()
return|;
end_else

begin_comment
unit|}
comment|// This can be used in single-threaded mode.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Func
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|typename
name|Func
operator|::
name|ErrorReturn
name|callST
argument_list|(
argument|ChannelT&C
argument_list|,
argument|const ArgTs&... Args
argument_list|)
block|{
return|return
name|callSTHandling
operator|<
name|Func
operator|>
operator|(
name|C
operator|,
name|handleNone
operator|,
name|Args
operator|...
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Start receiving a new function call.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Calls startReceiveMessage on the channel, then deserializes a FunctionId
end_comment

begin_comment
comment|/// into Id.
end_comment

begin_function
name|Error
name|startReceivingFunction
parameter_list|(
name|ChannelT
modifier|&
name|C
parameter_list|,
name|FunctionIdT
modifier|&
name|Id
parameter_list|)
block|{
if|if
condition|(
name|auto
name|Err
init|=
name|startReceiveMessage
argument_list|(
name|C
argument_list|)
condition|)
return|return
name|Err
return|;
return|return
name|deserialize
argument_list|(
name|C
argument_list|,
name|Id
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Deserialize args for Func from C and call Handler. The signature of
end_comment

begin_comment
comment|/// handler must conform to 'Error(Args...)' where Args... matches
end_comment

begin_comment
comment|/// the arguments used in the Func typedef.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|,
name|typename
name|HandlerT
operator|>
specifier|static
name|Error
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
name|SequenceNumberT
operator|,
name|Func
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
end_expr_stmt

begin_comment
comment|/// Helper version of 'handle' for calling member functions.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|,
name|typename
name|ClassT
operator|,
name|typename
name|RetT
operator|,
name|typename
operator|...
name|ArgTs
operator|>
specifier|static
name|Error
name|handle
argument_list|(
argument|ChannelT&C
argument_list|,
argument|ClassT&Instance
argument_list|,
argument|RetT (ClassT::*HandlerMethod)(ArgTs...)
argument_list|)
block|{
return|return
name|handle
operator|<
name|Func
operator|>
operator|(
name|C
operator|,
name|MemberFnWrapper
operator|<
name|ClassT
operator|,
name|RetT
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
comment|/// Deserialize a FunctionIdT from C and verify it matches the id for Func.
end_comment

begin_comment
comment|/// If the id does match, deserialize the arguments and call the handler
end_comment

begin_comment
comment|/// (similarly to handle).
end_comment

begin_comment
comment|/// If the id does not match, return an unexpect RPC call error and do not
end_comment

begin_comment
comment|/// deserialize any further bytes.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|,
name|typename
name|HandlerT
operator|>
name|Error
name|expect
argument_list|(
argument|ChannelT&C
argument_list|,
argument|HandlerT Handler
argument_list|)
block|{
name|FunctionIdT
name|FuncId
block|;
if|if
condition|(
name|auto
name|Err
init|=
name|startReceivingFunction
argument_list|(
name|C
argument_list|,
name|FuncId
argument_list|)
condition|)
return|return
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|FuncId
operator|!=
name|Func
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
end_if

begin_return
return|return
name|handle
operator|<
name|Func
operator|>
operator|(
name|C
operator|,
name|Handler
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// Helper version of expect for calling member functions.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Func
operator|,
name|typename
name|ClassT
operator|,
name|typename
operator|...
name|ArgTs
operator|>
specifier|static
name|Error
name|expect
argument_list|(
argument|ChannelT&C
argument_list|,
argument|ClassT&Instance
argument_list|,
argument|Error (ClassT::*HandlerMethod)(ArgTs...)
argument_list|)
block|{
return|return
name|expect
operator|<
name|Func
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
comment|///   typedef Function<0, bool, int> Func1;
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
comment|///   if (auto Err = expect<Func1>(Channel, readArgs(B, I)))
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
comment|/// Read a response from Channel.
end_comment

begin_comment
comment|/// This should be called from the receive loop to retrieve results.
end_comment

begin_function
name|Error
name|handleResponse
parameter_list|(
name|ChannelT
modifier|&
name|C
parameter_list|,
name|SequenceNumberT
modifier|*
name|SeqNoRet
init|=
name|nullptr
parameter_list|)
block|{
name|SequenceNumberT
name|SeqNo
decl_stmt|;
if|if
condition|(
name|auto
name|Err
init|=
name|deserialize
argument_list|(
name|C
argument_list|,
name|SeqNo
argument_list|)
condition|)
block|{
name|abandonOutstandingResults
argument_list|()
expr_stmt|;
return|return
name|Err
return|;
block|}
if|if
condition|(
name|SeqNoRet
condition|)
operator|*
name|SeqNoRet
operator|=
name|SeqNo
expr_stmt|;
name|auto
name|I
init|=
name|OutstandingResults
operator|.
name|find
argument_list|(
name|SeqNo
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|OutstandingResults
operator|.
name|end
argument_list|()
condition|)
block|{
name|abandonOutstandingResults
argument_list|()
expr_stmt|;
return|return
name|orcError
argument_list|(
name|OrcErrorCode
operator|::
name|UnexpectedRPCResponse
argument_list|)
return|;
block|}
if|if
condition|(
name|auto
name|Err
init|=
name|I
operator|->
name|second
operator|->
name|readResult
argument_list|(
name|C
argument_list|)
condition|)
block|{
name|abandonOutstandingResults
argument_list|()
expr_stmt|;
comment|// FIXME: Release sequence numbers?
return|return
name|Err
return|;
block|}
name|OutstandingResults
operator|.
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
name|SequenceNumberMgr
operator|.
name|releaseSequenceNumber
argument_list|(
name|SeqNo
argument_list|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Loop waiting for a result with the given sequence number.
end_comment

begin_comment
comment|// This can be used as a receive loop if the user doesn't have a default.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|HandleOtherFtor
operator|>
name|Error
name|waitForResult
argument_list|(
argument|ChannelT&C
argument_list|,
argument|SequenceNumberT TgtSeqNo
argument_list|,
argument|HandleOtherFtor&HandleOther = handleNone
argument_list|)
block|{
name|bool
name|GotTgtResult
operator|=
name|false
block|;
while|while
condition|(
operator|!
name|GotTgtResult
condition|)
block|{
name|FunctionIdT
name|Id
init|=
name|RPCFunctionIdTraits
operator|<
name|FunctionIdT
operator|>
operator|::
name|InvalidId
decl_stmt|;
if|if
condition|(
name|auto
name|Err
init|=
name|startReceivingFunction
argument_list|(
name|C
argument_list|,
name|Id
argument_list|)
condition|)
return|return
name|Err
return|;
if|if
condition|(
name|Id
operator|==
name|RPCFunctionIdTraits
operator|<
name|FunctionIdT
operator|>
operator|::
name|ResponseId
condition|)
block|{
name|SequenceNumberT
name|SeqNo
decl_stmt|;
if|if
condition|(
name|auto
name|Err
init|=
name|handleResponse
argument_list|(
name|C
argument_list|,
operator|&
name|SeqNo
argument_list|)
condition|)
return|return
name|Err
return|;
name|GotTgtResult
operator|=
operator|(
name|SeqNo
operator|==
name|TgtSeqNo
operator|)
expr_stmt|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|auto
name|Err
init|=
name|HandleOther
argument_list|(
name|C
argument_list|,
name|Id
argument_list|)
condition|)
return|return
name|Err
return|;
end_elseif

begin_expr_stmt
unit|}      return
name|Error
operator|::
name|success
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Default handler for 'other' (non-response) functions when waiting for a
end_comment

begin_comment
comment|// result from the channel.
end_comment

begin_function
unit|static
name|Error
name|handleNone
parameter_list|(
name|ChannelT
modifier|&
parameter_list|,
name|FunctionIdT
parameter_list|)
block|{
return|return
name|orcError
argument_list|(
name|OrcErrorCode
operator|::
name|UnexpectedRPCCall
argument_list|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Manage sequence numbers.
end_comment

begin_decl_stmt
name|class
name|SequenceNumberManager
block|{
name|public
label|:
name|SequenceNumberManager
argument_list|()
operator|=
expr|default
expr_stmt|;
name|SequenceNumberManager
argument_list|(
specifier|const
name|SequenceNumberManager
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|SequenceNumberManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SequenceNumberManager
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|SequenceNumberManager
argument_list|(
name|SequenceNumberManager
operator|&&
name|Other
argument_list|)
operator|:
name|NextSequenceNumber
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|NextSequenceNumber
argument_list|)
argument_list|)
operator|,
name|FreeSequenceNumbers
argument_list|(
argument|std::move(Other.FreeSequenceNumbers)
argument_list|)
block|{}
name|SequenceNumberManager
operator|&
name|operator
operator|=
operator|(
name|SequenceNumberManager
operator|&&
name|Other
operator|)
block|{
name|NextSequenceNumber
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|NextSequenceNumber
argument_list|)
block|;
name|FreeSequenceNumbers
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|FreeSequenceNumbers
argument_list|)
block|;     }
name|void
name|reset
argument_list|()
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|Lock
argument_list|(
name|SeqNoLock
argument_list|)
block|;
name|NextSequenceNumber
operator|=
literal|0
block|;
name|FreeSequenceNumbers
operator|.
name|clear
argument_list|()
block|;     }
name|SequenceNumberT
name|getSequenceNumber
argument_list|()
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|Lock
argument_list|(
name|SeqNoLock
argument_list|)
block|;
if|if
condition|(
name|FreeSequenceNumbers
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NextSequenceNumber
operator|++
return|;
name|auto
name|SequenceNumber
operator|=
name|FreeSequenceNumbers
operator|.
name|back
argument_list|()
expr_stmt|;
name|FreeSequenceNumbers
operator|.
name|pop_back
argument_list|()
expr_stmt|;
return|return
name|SequenceNumber
return|;
block|}
end_decl_stmt

begin_function
name|void
name|releaseSequenceNumber
parameter_list|(
name|SequenceNumberT
name|SequenceNumber
parameter_list|)
block|{
name|std
operator|::
name|lock_guard
operator|<
name|std
operator|::
name|mutex
operator|>
name|Lock
argument_list|(
name|SeqNoLock
argument_list|)
expr_stmt|;
name|FreeSequenceNumbers
operator|.
name|push_back
argument_list|(
name|SequenceNumber
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|mutex
name|SeqNoLock
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|SequenceNumberT
name|NextSequenceNumber
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|SequenceNumberT
operator|>
name|FreeSequenceNumbers
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Base class for results that haven't been returned from the other end of the
end_comment

begin_comment
comment|// RPC connection yet.
end_comment

begin_decl_stmt
name|class
name|OutstandingResult
block|{
name|public
label|:
name|virtual
operator|~
name|OutstandingResult
argument_list|()
block|{}
name|virtual
name|Error
name|readResult
argument_list|(
name|ChannelT
operator|&
name|C
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|abandon
parameter_list|()
init|=
literal|0
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Outstanding results for a specific function.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|>
name|class
name|OutstandingResultImpl
operator|:
name|public
name|OutstandingResult
block|{
name|private
operator|:
name|public
operator|:
name|OutstandingResultImpl
argument_list|(
argument|std::promise<typename Func::OptionalReturn>&&P
argument_list|)
operator|:
name|P
argument_list|(
argument|std::move(P)
argument_list|)
block|{}
name|Error
name|readResult
argument_list|(
argument|ChannelT&C
argument_list|)
name|override
block|{
return|return
name|Func
operator|::
name|readResult
argument_list|(
name|C
argument_list|,
name|P
argument_list|)
return|;
block|}
name|void
name|abandon
argument_list|()
name|override
block|{
name|Func
operator|::
name|abandon
argument_list|(
name|P
argument_list|)
block|; }
name|private
operator|:
name|std
operator|::
name|promise
operator|<
name|typename
name|Func
operator|::
name|OptionalReturn
operator|>
name|P
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Create an outstanding result for the given function.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|>
name|std
operator|::
name|unique_ptr
operator|<
name|OutstandingResult
operator|>
name|createOutstandingResult
argument_list|(
argument|std::promise<typename Func::OptionalReturn>&&P
argument_list|)
block|{
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|OutstandingResultImpl
operator|<
name|Func
operator|>>
operator|(
name|std
operator|::
name|move
argument_list|(
name|P
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Abandon all outstanding results.
end_comment

begin_function
name|void
name|abandonOutstandingResults
parameter_list|()
block|{
for|for
control|(
name|auto
operator|&
name|KV
operator|:
name|OutstandingResults
control|)
name|KV
operator|.
name|second
operator|->
name|abandon
argument_list|()
expr_stmt|;
name|OutstandingResults
operator|.
name|clear
argument_list|()
expr_stmt|;
name|SequenceNumberMgr
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|SequenceNumberManager
name|SequenceNumberMgr
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|map
operator|<
name|SequenceNumberT
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|OutstandingResult
operator|>>
name|OutstandingResults
expr_stmt|;
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

