begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- OrcRemoteTargetRPCAPI.h - Orc Remote-target RPC API ----*- C++ -*-===//
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
comment|// This file defines the Orc remote-target RPC API. It should not be used
end_comment

begin_comment
comment|// directly, but is used by the RemoteTargetClient and RemoteTargetServer
end_comment

begin_comment
comment|// classes.
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
name|LLVM_EXECUTIONENGINE_ORC_ORCREMOTETARGETRPCAPI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_ORCREMOTETARGETRPCAPI_H
end_define

begin_include
include|#
directive|include
file|"JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"RPCChannel.h"
end_include

begin_include
include|#
directive|include
file|"RPCUtils.h"
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
name|class
name|OrcRemoteTargetRPCAPI
range|:
name|public
name|RPC
operator|<
name|RPCChannel
operator|>
block|{
name|protected
operator|:
name|class
name|ResourceIdMgr
block|{
name|public
operator|:
typedef|typedef
name|uint64_t
name|ResourceId
typedef|;
name|ResourceIdMgr
argument_list|()
operator|:
name|NextId
argument_list|(
literal|0
argument_list|)
block|{}
name|ResourceId
name|getNext
argument_list|()
block|{
if|if
condition|(
operator|!
name|FreeIds
operator|.
name|empty
argument_list|()
condition|)
block|{
name|ResourceId
name|I
init|=
name|FreeIds
operator|.
name|back
argument_list|()
decl_stmt|;
name|FreeIds
operator|.
name|pop_back
argument_list|()
expr_stmt|;
return|return
name|I
return|;
block|}
return|return
name|NextId
operator|++
return|;
block|}
name|void
name|release
argument_list|(
argument|ResourceId I
argument_list|)
block|{
name|FreeIds
operator|.
name|push_back
argument_list|(
name|I
argument_list|)
block|; }
name|private
operator|:
name|ResourceId
name|NextId
block|;
name|std
operator|::
name|vector
operator|<
name|ResourceId
operator|>
name|FreeIds
block|;   }
decl_stmt|;
name|public
label|:
enum|enum
name|JITProcId
enum|:
name|uint32_t
block|{
name|InvalidId
init|=
literal|0
block|,
name|CallIntVoidId
block|,
name|CallIntVoidResponseId
block|,
name|CallMainId
block|,
name|CallMainResponseId
block|,
name|CallVoidVoidId
block|,
name|CallVoidVoidResponseId
block|,
name|CreateRemoteAllocatorId
block|,
name|CreateIndirectStubsOwnerId
block|,
name|DestroyRemoteAllocatorId
block|,
name|DestroyIndirectStubsOwnerId
block|,
name|EmitIndirectStubsId
block|,
name|EmitIndirectStubsResponseId
block|,
name|EmitResolverBlockId
block|,
name|EmitTrampolineBlockId
block|,
name|EmitTrampolineBlockResponseId
block|,
name|GetSymbolAddressId
block|,
name|GetSymbolAddressResponseId
block|,
name|GetRemoteInfoId
block|,
name|GetRemoteInfoResponseId
block|,
name|ReadMemId
block|,
name|ReadMemResponseId
block|,
name|ReserveMemId
block|,
name|ReserveMemResponseId
block|,
name|RequestCompileId
block|,
name|RequestCompileResponseId
block|,
name|SetProtectionsId
block|,
name|TerminateSessionId
block|,
name|WriteMemId
block|,
name|WritePtrId
block|}
enum|;
specifier|static
specifier|const
name|char
modifier|*
name|getJITProcIdName
parameter_list|(
name|JITProcId
name|Id
parameter_list|)
function_decl|;
typedef|typedef
name|Procedure
operator|<
name|CallIntVoidId
operator|,
name|TargetAddress
comment|/* FnAddr */
operator|>
name|CallIntVoid
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|CallIntVoidResponseId
operator|,
name|int
comment|/* Result */
operator|>
name|CallIntVoidResponse
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|CallMainId
operator|,
name|TargetAddress
comment|/* FnAddr */
operator|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
comment|/* Args */
expr|>
name|CallMain
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|CallMainResponseId
operator|,
name|int
comment|/* Result */
operator|>
name|CallMainResponse
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|CallVoidVoidId
operator|,
name|TargetAddress
comment|/* FnAddr */
operator|>
name|CallVoidVoid
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|CallVoidVoidResponseId
operator|>
name|CallVoidVoidResponse
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|CreateRemoteAllocatorId
operator|,
name|ResourceIdMgr
operator|::
name|ResourceId
comment|/* Allocator ID */
operator|>
name|CreateRemoteAllocator
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|CreateIndirectStubsOwnerId
operator|,
name|ResourceIdMgr
operator|::
name|ResourceId
comment|/* StubsOwner ID */
operator|>
name|CreateIndirectStubsOwner
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|DestroyRemoteAllocatorId
operator|,
name|ResourceIdMgr
operator|::
name|ResourceId
comment|/* Allocator ID */
operator|>
name|DestroyRemoteAllocator
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|DestroyIndirectStubsOwnerId
operator|,
name|ResourceIdMgr
operator|::
name|ResourceId
comment|/* StubsOwner ID */
operator|>
name|DestroyIndirectStubsOwner
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|EmitIndirectStubsId
operator|,
name|ResourceIdMgr
operator|::
name|ResourceId
comment|/* StubsOwner ID */
operator|,
name|uint32_t
comment|/* NumStubsRequired */
operator|>
name|EmitIndirectStubs
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|EmitIndirectStubsResponseId
operator|,
name|TargetAddress
comment|/* StubsBaseAddr */
operator|,
name|TargetAddress
comment|/* PtrsBaseAddr */
operator|,
name|uint32_t
comment|/* NumStubsEmitted */
operator|>
name|EmitIndirectStubsResponse
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|EmitResolverBlockId
operator|>
name|EmitResolverBlock
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|EmitTrampolineBlockId
operator|>
name|EmitTrampolineBlock
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|EmitTrampolineBlockResponseId
operator|,
name|TargetAddress
comment|/* BlockAddr */
operator|,
name|uint32_t
comment|/* NumTrampolines */
operator|>
name|EmitTrampolineBlockResponse
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|GetSymbolAddressId
operator|,
name|std
operator|::
name|string
comment|/*SymbolName*/
operator|>
name|GetSymbolAddress
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|GetSymbolAddressResponseId
operator|,
name|uint64_t
comment|/* SymbolAddr */
operator|>
name|GetSymbolAddressResponse
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|GetRemoteInfoId
operator|>
name|GetRemoteInfo
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|GetRemoteInfoResponseId
operator|,
name|std
operator|::
name|string
comment|/* Triple */
operator|,
name|uint32_t
comment|/* PointerSize */
operator|,
name|uint32_t
comment|/* PageSize */
operator|,
name|uint32_t
comment|/* TrampolineSize */
operator|,
name|uint32_t
comment|/* IndirectStubSize */
operator|>
name|GetRemoteInfoResponse
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|ReadMemId
operator|,
name|TargetAddress
comment|/* Src */
operator|,
name|uint64_t
comment|/* Size */
operator|>
name|ReadMem
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|ReadMemResponseId
operator|>
name|ReadMemResponse
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|ReserveMemId
operator|,
name|ResourceIdMgr
operator|::
name|ResourceId
comment|/* Id */
operator|,
name|uint64_t
comment|/* Size */
operator|,
name|uint32_t
comment|/* Align */
operator|>
name|ReserveMem
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|ReserveMemResponseId
operator|,
name|TargetAddress
comment|/* Addr */
operator|>
name|ReserveMemResponse
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|RequestCompileId
operator|,
name|TargetAddress
comment|/* TrampolineAddr */
operator|>
name|RequestCompile
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|RequestCompileResponseId
operator|,
name|TargetAddress
comment|/* ImplAddr */
operator|>
name|RequestCompileResponse
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|SetProtectionsId
operator|,
name|ResourceIdMgr
operator|::
name|ResourceId
comment|/* Id */
operator|,
name|TargetAddress
comment|/* Dst */
operator|,
name|uint32_t
comment|/* ProtFlags */
operator|>
name|SetProtections
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|TerminateSessionId
operator|>
name|TerminateSession
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|WriteMemId
operator|,
name|TargetAddress
comment|/* Dst */
operator|,
name|uint64_t
comment|/* Size */
comment|/* Data should follow */
operator|>
name|WriteMem
expr_stmt|;
typedef|typedef
name|Procedure
operator|<
name|WritePtrId
operator|,
name|TargetAddress
comment|/* Dst */
operator|,
name|TargetAddress
comment|/* Val */
operator|>
name|WritePtr
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace remote
block|}
end_decl_stmt

begin_comment
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

