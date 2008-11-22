begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__INCmvOsBsdh
end_ifndef

begin_define
define|#
directive|define
name|__INCmvOsBsdh
end_define

begin_if
if|#
directive|if
name|DBG
end_if

begin_define
define|#
directive|define
name|MV_DEBUG_LOG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ENABLE_READ_AHEAD
end_define

begin_define
define|#
directive|define
name|ENABLE_WRITE_CACHE
end_define

begin_comment
comment|/* Typedefs    */
end_comment

begin_comment
comment|/*#define HPTLIBAPI __attribute__((regparm(0))) */
end_comment

begin_define
define|#
directive|define
name|HPTLIBAPI
end_define

begin_define
define|#
directive|define
name|FAR
end_define

begin_define
define|#
directive|define
name|SS_SEG
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FASTCALL
end_ifdef

begin_undef
undef|#
directive|undef
name|FASTCALL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FASTCALL
value|HPTLIBAPI
end_define

begin_define
define|#
directive|define
name|PASCAL
value|HPTLIBAPI
end_define

begin_typedef
typedef|typedef
name|unsigned
name|short
name|USHORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|PUCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
modifier|*
name|PUSHORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BOOLEAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|WORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT
typedef|,
name|BOOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BYTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|PVOID
typedef|,
modifier|*
name|LPVOID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|LONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ULONG
typedef|,
modifier|*
name|PULONG
typedef|,
name|LBA_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|DWORD
typedef|,
modifier|*
name|LPDWORD
typedef|,
modifier|*
name|PDWORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ULONG_PTR
typedef|,
name|UINT_PTR
typedef|,
name|BUS_ADDR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|HPT_U64
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mvBoolean
block|{
name|MV_FALSE
block|,
name|MV_TRUE
block|}
name|MV_BOOLEAN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System dependant typedefs */
end_comment

begin_typedef
typedef|typedef
name|void
name|MV_VOID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|MV_U32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|MV_U16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|MV_U8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|MV_VOID_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|MV_U32
modifier|*
name|MV_U32_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|MV_U16
modifier|*
name|MV_U16_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|MV_U8
modifier|*
name|MV_U8_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|MV_CHAR_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|MV_BUS_ADDR_T
typedef|;
end_typedef

begin_comment
comment|/* System dependent macro for flushing CPU write cache */
end_comment

begin_define
define|#
directive|define
name|MV_CPU_WRITE_BUFFER_FLUSH
parameter_list|()
end_define

begin_comment
comment|/* System dependent little endian from / to CPU conversions */
end_comment

begin_define
define|#
directive|define
name|MV_CPU_TO_LE16
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|MV_CPU_TO_LE32
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|MV_LE16_TO_CPU
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|MV_LE32_TO_CPU
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* System dependent register read / write in byte/word/dword variants */
end_comment

begin_function_decl
specifier|extern
name|void
name|HPTLIBAPI
name|MV_REG_WRITE_BYTE
parameter_list|(
name|MV_BUS_ADDR_T
name|base
parameter_list|,
name|MV_U32
name|offset
parameter_list|,
name|MV_U8
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HPTLIBAPI
name|MV_REG_WRITE_WORD
parameter_list|(
name|MV_BUS_ADDR_T
name|base
parameter_list|,
name|MV_U32
name|offset
parameter_list|,
name|MV_U16
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HPTLIBAPI
name|MV_REG_WRITE_DWORD
parameter_list|(
name|MV_BUS_ADDR_T
name|base
parameter_list|,
name|MV_U32
name|offset
parameter_list|,
name|MV_U32
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|MV_U8
name|HPTLIBAPI
name|MV_REG_READ_BYTE
parameter_list|(
name|MV_BUS_ADDR_T
name|base
parameter_list|,
name|MV_U32
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|MV_U16
name|HPTLIBAPI
name|MV_REG_READ_WORD
parameter_list|(
name|MV_BUS_ADDR_T
name|base
parameter_list|,
name|MV_U32
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|MV_U32
name|HPTLIBAPI
name|MV_REG_READ_DWORD
parameter_list|(
name|MV_BUS_ADDR_T
name|base
parameter_list|,
name|MV_U32
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* System dependent structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mvOsSemaphore
block|{
name|int
name|notused
decl_stmt|;
block|}
name|MV_OS_SEMAPHORE
typedef|;
end_typedef

begin_comment
comment|/* Functions (User implemented)*/
end_comment

begin_function_decl
name|ULONG_PTR
name|HPTLIBAPI
name|fOsPhysicalAddress
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Semaphore init, take and release */
end_comment

begin_define
define|#
directive|define
name|mvOsSemInit
parameter_list|(
name|p
parameter_list|)
value|(MV_TRUE)
end_define

begin_define
define|#
directive|define
name|mvOsSemTake
parameter_list|(
name|p
parameter_list|)
value|(MV_TRUE)
end_define

begin_define
define|#
directive|define
name|mvOsSemRelease
parameter_list|(
name|p
parameter_list|)
value|(MV_TRUE)
end_define

begin_comment
comment|/* Delay function in micro seconds resolution */
end_comment

begin_function_decl
name|void
name|HPTLIBAPI
name|mvMicroSecondsDelay
parameter_list|(
name|MV_U32
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* System logging function */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MV_DEBUG_LOG
end_ifdef

begin_function_decl
name|int
name|mvLogMsg
parameter_list|(
name|MV_U8
parameter_list|,
name|MV_CHAR_PTR
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_mvLogMsg
parameter_list|(
name|x
parameter_list|)
value|mvLogMsg x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mvLogMsg
parameter_list|(
name|x
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_mvLogMsg
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************************************************************************  * Debug support  *************************************************************************/
end_comment

begin_if
if|#
directive|if
name|DEBUG
end_if

begin_define
define|#
directive|define
name|HPT_ASSERT
parameter_list|(
name|x
parameter_list|)
value|do { if (!(x)) { \ 						printf("ASSERT fail at %s line %d", __FILE__, __LINE__); \ 						while (1); \ 					  }} while (0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|hpt_dbg_level
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KdPrintI
parameter_list|(
name|_x_
parameter_list|)
value|do{ if (hpt_dbg_level>2) printf _x_; }while(0)
end_define

begin_define
define|#
directive|define
name|KdPrintW
parameter_list|(
name|_x_
parameter_list|)
value|do{ if (hpt_dbg_level>1) printf _x_; }while(0)
end_define

begin_define
define|#
directive|define
name|KdPrintE
parameter_list|(
name|_x_
parameter_list|)
value|do{ if (hpt_dbg_level>0) printf _x_; }while(0)
end_define

begin_define
define|#
directive|define
name|KdPrint
parameter_list|(
name|x
parameter_list|)
value|KdPrintI(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HPT_ASSERT
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KdPrint
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KdPrintI
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KdPrintW
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KdPrintE
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

