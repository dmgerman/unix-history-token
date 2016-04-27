begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_iocpltypes.h - data structures for overlapped IO  *  * Written by Juergen Perlinger (perlinger@ntp.org) for the NTP project.  * The contents of 'html/copyright.html' apply.  *  * --------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_IOCPLTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_IOCPLTYPES_H
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<Windows.h>
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_comment
comment|/* ---------------------------------------------------------------------  * forward declarations to avoid deep header nesting  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|IoCtx
name|IoCtx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|refclockio
name|RIO_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|interface
name|endpt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|recvbuf
name|recvbuf_t
typedef|;
end_typedef

begin_comment
comment|/* ---------------------------------------------------------------------  * shared lock to avoid concurrent deletes on IO related stuff like  * RIO or ENDPOINT blocks.  *  * Basically we wwould need a multiple-reader/single-writer lock,  * but for now we do full mutual exclusion.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|SharedLock
name|SharedLock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|SharedLock
name|CSharedLock_t
typedef|;
end_typedef

begin_struct
struct|struct
name|SharedLock
block|{
name|CRITICAL_SECTION
name|mutex
index|[
literal|1
index|]
decl_stmt|;
specifier|volatile
name|u_long
name|refc_count
decl_stmt|;
union|union
block|{
name|RIO_t
modifier|*
name|rio
decl_stmt|;
comment|/*  RIO back-link (for offload)	*/
name|endpt
modifier|*
name|ept
decl_stmt|;
comment|/*  inetrface backlink		*/
name|ULONG_PTR
name|key
decl_stmt|;
comment|/*  as key for IOCPL queue	*/
name|void
modifier|*
name|any
decl_stmt|;
block|}
name|rsrc
union|;
comment|/* registered source		*/
name|HANDLE
name|handles
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0->COM/SOCK 1->BCASTSOCK	*/
name|int
name|riofd
decl_stmt|;
comment|/* FD for comports		*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|__fastcall
modifier|*
name|LockPredicateT
function_decl|)
parameter_list|(
name|CSharedLock_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|SharedLock_t
modifier|*
name|__fastcall
name|slCreate
parameter_list|(
name|void
modifier|*
name|rsrc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SharedLock_t
modifier|*
name|__fastcall
name|slAttach
parameter_list|(
name|SharedLock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SharedLock_t
modifier|*
name|__fastcall
name|slDetach
parameter_list|(
name|SharedLock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SharedLock_t
modifier|*
name|__fastcall
name|slAttachShared
parameter_list|(
name|SharedLock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SharedLock_t
modifier|*
name|__fastcall
name|slDetachShared
parameter_list|(
name|SharedLock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SharedLock_t
modifier|*
name|__fastcall
name|slAttachExclusive
parameter_list|(
name|SharedLock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SharedLock_t
modifier|*
name|__fastcall
name|slDetachExclusive
parameter_list|(
name|SharedLock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|__fastcall
name|slRefClockOK
parameter_list|(
name|CSharedLock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|__fastcall
name|slEndPointOK
parameter_list|(
name|CSharedLock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|slQueueLocked
parameter_list|(
name|SharedLock_t
modifier|*
parameter_list|,
name|LockPredicateT
parameter_list|,
name|recvbuf_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * storage type for PPS data (DCD change counts& times)  * ---------------------------------------------------------------------  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|PpsData
name|PPSData_t
typedef|;
end_typedef

begin_struct
struct|struct
name|PpsData
block|{
name|u_long
name|cc_assert
decl_stmt|;
name|u_long
name|cc_clear
decl_stmt|;
name|l_fp
name|ts_assert
decl_stmt|;
name|l_fp
name|ts_clear
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|PpsDataEx
name|PPSDataEx_t
typedef|;
end_typedef

begin_struct
struct|struct
name|PpsDataEx
block|{
name|u_long
name|cov_count
decl_stmt|;
name|PPSData_t
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ---------------------------------------------------------------------  * device context; uses reference counting to avoid nasty surprises.  * Currently this stores only the PPS time stamps, but it could be  * easily extended.  * ---------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|PPS_QUEUE_LEN
value|8u
end_define

begin_comment
comment|/* must be power of two! */
end_comment

begin_define
define|#
directive|define
name|PPS_QUEUE_MSK
value|(PPS_QUEUE_LEN-1)
end_define

begin_comment
comment|/* mask for easy MOD ops */
end_comment

begin_typedef
typedef|typedef
name|struct
name|DeviceContext
name|DevCtx_t
typedef|;
end_typedef

begin_struct
struct|struct
name|DeviceContext
block|{
specifier|volatile
name|u_long
name|ref_count
decl_stmt|;
specifier|volatile
name|u_long
name|cov_count
decl_stmt|;
name|PPSData_t
name|pps_data
decl_stmt|;
name|PPSDataEx_t
name|pps_buff
index|[
name|PPS_QUEUE_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|DevCtx_t
modifier|*
name|__fastcall
name|DevCtxAlloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DevCtx_t
modifier|*
name|__fastcall
name|DevCtxAttach
parameter_list|(
name|DevCtx_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DevCtx_t
modifier|*
name|__fastcall
name|DevCtxDetach
parameter_list|(
name|DevCtx_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * I/O context structure  *  * This is an extended overlapped structure. Some fields are only used  * for serial I/O, others are used for all operations. The serial I/O is  * more interesting since the same context object is used for waiting,  * actual I/O and possibly offload processing in a worker thread until  * a complete operation cycle is done.  *  * In this case the I/O context is used to gather all the bits that are  * finally needed for the processing of the buffer.  * ---------------------------------------------------------------------  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|IoCompleteFunc
function_decl|)
parameter_list|(
name|ULONG_PTR
parameter_list|,
name|IoCtx_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

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
name|201
name|)
end_pragma

begin_comment
comment|/* nonstd extension nameless union */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|IoCtx
block|{
name|OVERLAPPED
name|ol
decl_stmt|;
comment|/* 'kernel' part of the context	*/
union|union
block|{
name|recvbuf_t
modifier|*
name|recv_buf
decl_stmt|;
comment|/* incoming -> buffer structure	*/
name|void
modifier|*
name|trans_buf
decl_stmt|;
comment|/* outgoing -> char array	*/
name|PPSData_t
modifier|*
name|pps_buf
decl_stmt|;
comment|/* for reading PPS seq/stamps	*/
name|HANDLE
name|ppswake
decl_stmt|;
comment|/* pps wakeup for attach	*/
block|}
union|;
union|union
block|{
name|HANDLE
name|hnd
decl_stmt|;
comment|/*  IO handle (the real McCoy)	*/
name|SOCKET
name|sfd
decl_stmt|;
comment|/*  socket descriptor		*/
block|}
name|io
union|;
comment|/* the IO resource used		*/
name|IoCompleteFunc
name|onIoDone
decl_stmt|;
comment|/* HL callback to execute	*/
name|SharedLock_t
modifier|*
name|slock
decl_stmt|;
name|DevCtx_t
modifier|*
name|devCtx
decl_stmt|;
name|DWORD
name|errCode
decl_stmt|;
comment|/* error code of last I/O	*/
name|DWORD
name|byteCount
decl_stmt|;
comment|/* byte count     "             */
name|u_int
name|flRawMem
range|:
literal|1
decl_stmt|;
comment|/* buffer is raw memory -> free */
struct|struct
block|{
name|l_fp
name|DCDSTime
decl_stmt|;
comment|/* PPS-hack: time of DCD ON	*/
name|l_fp
name|FlagTime
decl_stmt|;
comment|/* time stamp of flag/event char*/
name|l_fp
name|RecvTime
decl_stmt|;
comment|/* time stamp of callback	*/
name|DWORD
name|com_events
decl_stmt|;
comment|/* buffer for COM events	*/
name|u_int
name|flTsDCDS
range|:
literal|1
decl_stmt|;
comment|/* DCDSTime valid?		*/
name|u_int
name|flTsFlag
range|:
literal|1
decl_stmt|;
comment|/* FlagTime valid?		*/
block|}
name|aux
struct|;
block|}
struct|;
end_struct

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

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|__fastcall
modifier|*
name|IoCtxStarterT
function_decl|)
parameter_list|(
name|IoCtx_t
modifier|*
parameter_list|,
name|recvbuf_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|IoCtx_t
modifier|*
name|__fastcall
name|IoCtxAlloc
parameter_list|(
name|SharedLock_t
modifier|*
parameter_list|,
name|DevCtx_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__fastcall
name|IoCtxFree
parameter_list|(
name|IoCtx_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__fastcall
name|IoCtxRelease
parameter_list|(
name|IoCtx_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|IoCtxStartLocked
parameter_list|(
name|IoCtx_t
modifier|*
parameter_list|,
name|IoCtxStarterT
parameter_list|,
name|recvbuf_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!defined(NTP_IOCPLTYPES_H)*/
end_comment

end_unit

