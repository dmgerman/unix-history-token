begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file mpidebug.h  *  \brief The file defines the debug constants and structures  *  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MPIDEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__MPIDEBUG_H__
end_define

begin_comment
comment|/*******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_DEBUG_TRACE_BUFFER_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|MPI_DEBUG_TRACE_OB_IOMB_SIZE
value|128
end_define

begin_comment
comment|/* 64 */
end_comment

begin_define
define|#
directive|define
name|MPI_DEBUG_TRACE_IB_IOMB_SIZE
value|128
end_define

begin_comment
comment|/* 64 */
end_comment

begin_define
define|#
directive|define
name|MPI_DEBUG_TRACE_IBQ
value|1
end_define

begin_define
define|#
directive|define
name|MPI_DEBUG_TRACE_OBQ
value|0
end_define

begin_define
define|#
directive|define
name|MPI_DEBUG_TRACE_QNUM_ERROR
value|100
end_define

begin_comment
comment|/* Added to Qnumber to indicate error */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mpiObDebugTraceEntry_s
block|{
name|bit64
name|Time
decl_stmt|;
name|bit32
name|QNum
decl_stmt|;
name|bit32
name|pici
decl_stmt|;
name|void
modifier|*
name|pEntry
decl_stmt|;
name|bit32
name|Iomb
index|[
name|MPI_DEBUG_TRACE_OB_IOMB_SIZE
operator|/
literal|4
index|]
decl_stmt|;
block|}
name|mpiDebugObTraceEntry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpiIbDebugTraceEntry_s
block|{
name|bit64
name|Time
decl_stmt|;
name|bit32
name|QNum
decl_stmt|;
name|bit32
name|pici
decl_stmt|;
name|void
modifier|*
name|pEntry
decl_stmt|;
name|bit32
name|Iomb
index|[
name|MPI_DEBUG_TRACE_IB_IOMB_SIZE
operator|/
literal|4
index|]
decl_stmt|;
block|}
name|mpiDebugIbTraceEntry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpiIbDebugTrace_s
block|{
name|bit32
name|Idx
decl_stmt|;
name|bit32
name|Pad
decl_stmt|;
name|mpiDebugIbTraceEntry_t
name|Data
index|[
name|MPI_DEBUG_TRACE_BUFFER_MAX
index|]
decl_stmt|;
block|}
name|mpiDebugIbTrace_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mpiObDebugTrace_s
block|{
name|bit32
name|Idx
decl_stmt|;
name|bit32
name|Pad
decl_stmt|;
name|mpiDebugObTraceEntry_t
name|Data
index|[
name|MPI_DEBUG_TRACE_BUFFER_MAX
index|]
decl_stmt|;
block|}
name|mpiDebugObTrace_t
typedef|;
end_typedef

begin_function_decl
name|void
name|mpiTraceInit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpiTraceAdd
parameter_list|(
name|bit32
name|q
parameter_list|,
name|bit32
name|pici
parameter_list|,
name|bit32
name|ib
parameter_list|,
name|void
modifier|*
name|iomb
parameter_list|,
name|bit32
name|numBytes
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MPIDEBUG_H__ */
end_comment

begin_comment
comment|/******************************************************************** **  File that contains debug-specific APIs ( driver tracing etc ) *********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SPCDEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__SPCDEBUG_H__
end_define

begin_comment
comment|/* ** console and trace levels */
end_comment

begin_define
define|#
directive|define
name|hpDBG_ALWAYS
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|hpDBG_IOMB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|hpDBG_REGISTERS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|hpDBG_TICK_INT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|hpDBG_SCREAM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|hpDBG_VERY_LOUD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|hpDBG_LOUD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|hpDBG_ERROR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|hpDBG_NEVER
value|0x00000000
end_define

begin_define
define|#
directive|define
name|smTraceDestBuffer
value|0x00000001
end_define

begin_define
define|#
directive|define
name|smTraceDestRegister
value|0x00000002
end_define

begin_define
define|#
directive|define
name|smTraceDestDebugger
value|0x00000004
end_define

begin_define
define|#
directive|define
name|siTraceDestMask
value|(smTraceDestBuffer    |  \                              smTraceDestRegister  |  \                              smTraceDestDebugger)
end_define

begin_comment
comment|/* Trace buffer will continuously  */
end_comment

begin_comment
comment|/* trace and wrap-around on itself */
end_comment

begin_comment
comment|/* when it reaches the end         */
end_comment

begin_define
define|#
directive|define
name|hpDBG_TraceBufferWrapAround
value|0x80000000
end_define

begin_comment
comment|/* This features enables logging of trace time       */
end_comment

begin_comment
comment|/* stamps.  Only certain key routines use this       */
end_comment

begin_comment
comment|/* feature because it tends to clog up the trace     */
end_comment

begin_comment
comment|/* buffer.                                           */
end_comment

begin_define
define|#
directive|define
name|hpDBG_TraceBufferUseTimeStamp
value|0x40000000
end_define

begin_comment
comment|/* This features enables logging of trace sequential */
end_comment

begin_comment
comment|/* stamps.  Only certain key routines use this       */
end_comment

begin_comment
comment|/* feature because it tends to clog up the trace     */
end_comment

begin_comment
comment|/* buffer.                                           */
end_comment

begin_define
define|#
directive|define
name|hpDBG_TraceBufferUseSequenceStamp
value|0x20000000
end_define

begin_comment
comment|/* Trace IDs of various state machines */
end_comment

begin_define
define|#
directive|define
name|fiTraceSmChip
value|'C'
end_define

begin_define
define|#
directive|define
name|fiTraceSmPort
value|'P'
end_define

begin_define
define|#
directive|define
name|fiTraceSmLogin
value|'L'
end_define

begin_define
define|#
directive|define
name|fiTraceSmXchg
value|'X'
end_define

begin_define
define|#
directive|define
name|fiTraceSmFabr
value|'F'
end_define

begin_define
define|#
directive|define
name|fiTraceDiscFab
value|'D'
end_define

begin_define
define|#
directive|define
name|fiTraceDiscLoop
value|'M'
end_define

begin_define
define|#
directive|define
name|fiTraceFc2
value|'A'
end_define

begin_define
define|#
directive|define
name|fiTraceTgtState
value|'S'
end_define

begin_define
define|#
directive|define
name|fiTraceIniState
value|'I'
end_define

begin_comment
comment|/* Trace IDs of various queues  */
end_comment

begin_define
define|#
directive|define
name|fiSfsFreeList
value|'Z'
end_define

begin_define
define|#
directive|define
name|fiSestFreeList
value|'W'
end_define

begin_define
define|#
directive|define
name|fiOsSfsFreeList
value|'G'
end_define

begin_define
define|#
directive|define
name|fiLgnFreeList
value|'K'
end_define

begin_define
define|#
directive|define
name|fiPortalFreeList
value|'l'
end_define

begin_define
define|#
directive|define
name|fiBusyList
value|'N'
end_define

begin_define
define|#
directive|define
name|fiOsSfsAllocList
value|'B'
end_define

begin_define
define|#
directive|define
name|fiTimerList
value|'V'
end_define

begin_define
define|#
directive|define
name|fiSfsWaitForRspList
value|'I'
end_define

begin_define
define|#
directive|define
name|fiLgnBusyList
value|'J'
end_define

begin_define
define|#
directive|define
name|fiPortalBusyList
value|'g'
end_define

begin_define
define|#
directive|define
name|fiWait4ErqList
value|'o'
end_define

begin_define
define|#
directive|define
name|fiXchgAbortList
value|'U'
end_define

begin_define
define|#
directive|define
name|fiXchgWaitList
value|'b'
end_define

begin_comment
comment|/* not used right now */
end_comment

begin_define
define|#
directive|define
name|fiSfsDeferFreeList
value|'q'
end_define

begin_define
define|#
directive|define
name|fiDeferBusyList
value|'m'
end_define

begin_define
define|#
directive|define
name|fiInvalidList
value|'X'
end_define

begin_define
define|#
directive|define
name|fiInvalidatedList
value|'a'
end_define

begin_define
define|#
directive|define
name|fiTmpXchList
value|'n'
end_define

begin_define
define|#
directive|define
name|TMP_TRACE_BUFF_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|FC_TRACE_LINE_SIZE
value|70
end_define

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* Macro Conventions:  we are assuming that the macros will be called inside  */
end_comment

begin_comment
comment|/*                     a function that already has a workable saRoot variable */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* fiTraceState : ==>        _!n_        _ss: XXXXXXXX       _se: XXXXXXXX    */
end_comment

begin_comment
comment|/*              statemachine --^     currentstate--^    triggerevent--^       */
end_comment

begin_comment
comment|/*              NOTE: shorthand forms available as macros below.              */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SA_ENABLE_TRACE_FUNCTIONS
end_ifdef

begin_function_decl
name|void
name|siResetTraceBuffer
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|siTraceFuncEnter
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|mask
parameter_list|,
name|bit32
name|fileid
parameter_list|,
name|char
modifier|*
name|funcid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GLOBAL
name|void
name|siTraceFuncExit
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|mask
parameter_list|,
name|char
name|fileid
parameter_list|,
name|char
modifier|*
name|funcid
parameter_list|,
name|char
name|exitId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|siTrace
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|mask
parameter_list|,
name|char
modifier|*
name|uId
parameter_list|,
name|bit32
name|value
parameter_list|,
name|bit32
name|dataSizeInBits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|siTrace64
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|mask
parameter_list|,
name|char
modifier|*
name|uId
parameter_list|,
name|bit64
name|value
parameter_list|,
name|bit32
name|dataSizeInBits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bit32
name|siGetCurrentTraceIndex
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|siTraceListRemove
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|mask
parameter_list|,
name|char
name|listId
parameter_list|,
name|bitptr
name|exchangeId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|siTraceListAdd
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|mask
parameter_list|,
name|char
name|listId
parameter_list|,
name|bitptr
name|exchangeId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|siTraceState
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|mask
parameter_list|,
name|bit32
name|statemachine
parameter_list|,
name|bit32
name|currentstate
parameter_list|,
name|bit32
name|triggerevent
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|smTraceState
parameter_list|(
name|L
parameter_list|,
name|S
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,S,C,T)
end_define

begin_define
define|#
directive|define
name|smTraceChipState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,fiTraceSmChip,C,T)
end_define

begin_define
define|#
directive|define
name|smTraceFabricState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,fiTraceSmFabr,C,T)
end_define

begin_define
define|#
directive|define
name|smTracePortState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,fiTraceSmPort,C,T)
end_define

begin_define
define|#
directive|define
name|smTraceLoginState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,fiTraceSmLogin,C,T)
end_define

begin_define
define|#
directive|define
name|smTraceXchgState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,fiTraceSmXchg,C,T)
end_define

begin_define
define|#
directive|define
name|smTraceDiscFabState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,fiTraceDiscFab,C,T)
end_define

begin_define
define|#
directive|define
name|smTraceDiscLoopState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,fiTraceDiscLoop,C,T)
end_define

begin_define
define|#
directive|define
name|smTraceFc2State
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,fiTraceFc2,C,T)
end_define

begin_define
define|#
directive|define
name|smTraceScsiTgtState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,fiTraceTgtState,C,T)
end_define

begin_define
define|#
directive|define
name|smTraceScsiIniState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
value|siTraceState(agRoot,L,fiTraceIniState,C,T)
end_define

begin_define
define|#
directive|define
name|smResetTraceBuffer
parameter_list|(
name|L
parameter_list|)
value|siResetTraceBuffer(L)
end_define

begin_define
define|#
directive|define
name|smTraceFuncEnter
parameter_list|(
name|L
parameter_list|,
name|I
parameter_list|)
value|siTraceFuncEnter(agRoot,L,siTraceFileID,I)
end_define

begin_define
define|#
directive|define
name|smTraceFuncExit
parameter_list|(
name|L
parameter_list|,
name|S
parameter_list|,
name|I
parameter_list|)
value|siTraceFuncExit(agRoot,L,siTraceFileID,I,S)
end_define

begin_define
define|#
directive|define
name|smGetCurrentTraceIndex
parameter_list|(
name|L
parameter_list|)
value|siGetCurrentTraceIndex(L)
end_define

begin_define
define|#
directive|define
name|smTraceListRemove
parameter_list|(
name|R
parameter_list|,
name|L
parameter_list|,
name|I
parameter_list|,
name|V
parameter_list|)
value|siTraceListRemove(R,L,I,V)
end_define

begin_define
define|#
directive|define
name|smTraceListAdd
parameter_list|(
name|R
parameter_list|,
name|L
parameter_list|,
name|I
parameter_list|,
name|V
parameter_list|)
value|siTraceListAdd(R,L,I,V)
end_define

begin_define
define|#
directive|define
name|smTrace
parameter_list|(
name|L
parameter_list|,
name|I
parameter_list|,
name|V
parameter_list|)
define|\
comment|/*lint -e506 */
define|\
comment|/*lint -e774 */
define|\
value|if (sizeof(V) == 8) {siTrace64(agRoot,L,I,(bit64)V,64);}  \     else {siTrace(agRoot,L,I,(bit32)V,32);}
end_define

begin_comment
unit|\
comment|/*lint +e506 */
end_comment

begin_comment
unit|\
comment|/*lint +e774 */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|siTraceState
parameter_list|(
name|agRoot
parameter_list|,
name|L
parameter_list|,
name|fiTraceSmXchg
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceState
parameter_list|(
name|L
parameter_list|,
name|S
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceChipState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceFabricState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTracePortState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceLoginState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceXchgState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceDiscFabState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceDiscLoopState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceFc2State
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceScsiTgtState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceScsiIniState
parameter_list|(
name|L
parameter_list|,
name|C
parameter_list|,
name|T
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smResetTraceBuffer
parameter_list|(
name|agRoot
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceFuncEnter
parameter_list|(
name|L
parameter_list|,
name|I
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceFuncExit
parameter_list|(
name|L
parameter_list|,
name|S
parameter_list|,
name|I
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smGetCurrentTraceIndex
parameter_list|(
name|L
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceListRemove
parameter_list|(
name|L
parameter_list|,
name|I
parameter_list|,
name|V
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTraceListAdd
parameter_list|(
name|L
parameter_list|,
name|I
parameter_list|,
name|V
parameter_list|)
end_define

begin_define
define|#
directive|define
name|smTrace
parameter_list|(
name|L
parameter_list|,
name|I
parameter_list|,
name|V
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|hpTraceBufferParms_s
block|{
name|bit32
name|TraceCompiled
decl_stmt|;
name|bit32
name|BufferSize
decl_stmt|;
name|bit32
name|CurrentTraceIndexWrapCount
decl_stmt|;
name|bit32
name|CurrentIndex
decl_stmt|;
name|bit32
name|TraceWrap
decl_stmt|;
name|bit8
modifier|*
name|pTrace
decl_stmt|;
name|bit32
modifier|*
name|pCurrentTraceIndex
decl_stmt|;
name|bit32
modifier|*
name|pTraceIndexWrapCount
decl_stmt|;
name|bit32
modifier|*
name|pTraceMask
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hpTraceBufferParms_s
name|hpTraceBufferParms_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|SA_ENABLE_TRACE_FUNCTIONS
end_ifdef

begin_function_decl
name|GLOBAL
name|void
name|siTraceGetInfo
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|hpTraceBufferParms_t
modifier|*
name|pBParms
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|smTraceGetInfo
parameter_list|(
name|R
parameter_list|,
name|P
parameter_list|)
value|siTraceGetInfo(R,P)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|smTraceGetInfo
parameter_list|(
name|R
parameter_list|,
name|P
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|siEnableTracing
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SA_ENABLE_TRACE_FUNCTIONS
end_ifdef

begin_function_decl
name|GLOBAL
name|void
name|siTraceSetMask
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|TraceMask
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|smTraceSetMask
parameter_list|(
name|R
parameter_list|,
name|P
parameter_list|)
value|siTraceSetMask(R,P)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|smTraceSetMask
parameter_list|(
name|R
parameter_list|,
name|P
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA_ENABLE_TRACE_FUNCTIONS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef __SPCDEBUG_H__ */
end_comment

end_unit

