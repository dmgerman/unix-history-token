begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-1999 Distributed Processing Technology Corporation  * All rights reserved.  *  * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *  * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OSD_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|__OSD_UTIL_H
end_define

begin_comment
comment|/*File - OSD_UTIL.H  ****************************************************************************  *  *Description:  *  *      This file contains defines and function prototypes that are  *operating system dependent.  The resources defined in this file  *are not specific to any particular application.  *  *Copyright Distributed Processing Technology, Corp.  *        140 Candace Dr.  *        Maitland, Fl. 32751   USA  *        Phone: (407) 830-5522  Fax: (407) 260-5366  *        All Rights Reserved  *  *Author:       Doug Anderson  *Date:         1/7/94  *  *Editors:  *  *Remarks:  *  *  *****************************************************************************/
end_comment

begin_comment
comment|/*Definitions - Defines& Constants ----------------------------------------- */
end_comment

begin_comment
comment|/*----------------------------- */
end_comment

begin_comment
comment|/* Operating system selections: */
end_comment

begin_comment
comment|/*----------------------------- */
end_comment

begin_comment
comment|/*#define               _DPT_MSDOS      */
end_comment

begin_comment
comment|/*#define               _DPT_WIN_3X     */
end_comment

begin_comment
comment|/*#define               _DPT_WIN_4X     */
end_comment

begin_comment
comment|/*#define               _DPT_WIN_NT     */
end_comment

begin_comment
comment|/*#define               _DPT_NETWARE    */
end_comment

begin_comment
comment|/*#define               _DPT_OS2        */
end_comment

begin_comment
comment|/*#define               _DPT_SCO        */
end_comment

begin_comment
comment|/*#define               _DPT_UNIXWARE   */
end_comment

begin_comment
comment|/*#define               _DPT_SOLARIS    */
end_comment

begin_comment
comment|/*#define               _DPT_NEXTSTEP   */
end_comment

begin_comment
comment|/*#define               _DPT_BANYAN     */
end_comment

begin_comment
comment|/*-------------------------------- */
end_comment

begin_comment
comment|/* Include the OS specific defines */
end_comment

begin_comment
comment|/*-------------------------------- */
end_comment

begin_comment
comment|/*#define       OS_SELECTION    From Above List */
end_comment

begin_comment
comment|/*#define       SEMAPHORE_T     ??? */
end_comment

begin_comment
comment|/*#define       DLL_HANDLE_T    ??? */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|"i386/isa/dpt_osd_defs.h"
end_include

begin_elif
elif|#
directive|elif
operator|(
operator|(
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|)
end_elif

begin_if
if|#
directive|if
operator|(
name|KERN_VERSION
operator|<
literal|3
operator|)
end_if

begin_include
include|#
directive|include
file|"i386/isa/dpt_osd_defs.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"dev/asr/osd_defs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"osd_defs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DPT_UNALIGNED
end_ifndef

begin_define
define|#
directive|define
name|DPT_UNALIGNED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DPT_EXPORT
end_ifndef

begin_define
define|#
directive|define
name|DPT_EXPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DPT_IMPORT
end_ifndef

begin_define
define|#
directive|define
name|DPT_IMPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DPT_RUNTIME_IMPORT
end_ifndef

begin_define
define|#
directive|define
name|DPT_RUNTIME_IMPORT
value|DPT_IMPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*--------------------- */
end_comment

begin_comment
comment|/* OS dependent defines */
end_comment

begin_comment
comment|/*--------------------- */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_WIN_3X
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DPT_16_BIT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_DPT_32_BIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_SCO
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_UNIXWARE
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_SOLARIS
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|SNI_MIPS
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_BSDI
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_FREE_BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_LINUX
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DPT_UNIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_WIN_3x
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_WIN_4X
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_WIN_NT
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|_DPT_OS2
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DPT_DLL_SUPPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_DPT_MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_DPT_WIN_3X
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_DPT_NETWARE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DPT_PREEMPTIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_DPT_MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_DPT_WIN_3X
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DPT_MULTI_THREADED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_DPT_MSDOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DPT_MULTI_TASKING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These exist for platforms that   */
end_comment

begin_comment
comment|/* chunk when accessing mis-aligned */
end_comment

begin_comment
comment|/* data                             */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SNI_MIPS
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_SOLARIS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_DPT_STRICT_ALIGN
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DPT_STRICT_ALIGN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine if in C or C++ mode */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|_DPT_CPP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_DPT_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Under Solaris the compiler refuses to accept code like:           */
end_comment

begin_comment
comment|/*   { {"DPT"}, 0, NULL .... },                                      */
end_comment

begin_comment
comment|/* and complains about the {"DPT"} part by saying "cannot use { }    */
end_comment

begin_comment
comment|/* to initialize char*".                                             */
end_comment

begin_comment
comment|/*                                                                   */
end_comment

begin_comment
comment|/* By defining these ugly macros we can get around this and also     */
end_comment

begin_comment
comment|/* not have to copy and #ifdef large sections of code.  I know that  */
end_comment

begin_comment
comment|/* these macros are *really* ugly, but they should help reduce       */
end_comment

begin_comment
comment|/* maintenance in the long run.                                      */
end_comment

begin_comment
comment|/*                                                                   */
end_comment

begin_comment
comment|/* In the meantime, just pray that we can all move to Win32 as soon  */
end_comment

begin_comment
comment|/* as possible...                                                    */
end_comment

begin_comment
comment|/*-------------------------------------------------------------------*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DPTSQO
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_SOLARIS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DPTSQO
end_define

begin_define
define|#
directive|define
name|DPTSQC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPTSQO
value|{
end_define

begin_define
define|#
directive|define
name|DPTSQC
value|}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* solaris */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DPTSQO */
end_comment

begin_comment
comment|/*---------------------- */
end_comment

begin_comment
comment|/* OS dependent typedefs */
end_comment

begin_comment
comment|/*---------------------- */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_SCO
argument_list|)
end_if

begin_define
define|#
directive|define
name|BYTE
value|unsigned char
end_define

begin_define
define|#
directive|define
name|WORD
value|unsigned short
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_DPT_TYPEDEFS
end_ifndef

begin_define
define|#
directive|define
name|_DPT_TYPEDEFS
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uSHORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uLONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uCHAR
name|u8
index|[
literal|4
index|]
decl_stmt|;
name|uSHORT
name|u16
index|[
literal|2
index|]
decl_stmt|;
name|uLONG
name|u32
decl_stmt|;
block|}
name|access_U
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NULL
argument_list|)
end_if

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
comment|/*Prototypes - function ----------------------------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
comment|/* Declare all these functions as "C" functions */
endif|#
directive|endif
comment|/*------------------------ */
comment|/* Byte reversal functions */
comment|/*------------------------ */
comment|/* Reverses the byte ordering of a 2 byte variable */
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|osdSwap2
argument_list|)
operator|)
name|uSHORT
name|osdSwap2
parameter_list|(
name|DPT_UNALIGNED
name|uSHORT
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// !osdSwap2
comment|/* Reverses the byte ordering of a 4 byte variable and shifts left 8 bits */
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|osdSwap3
argument_list|)
operator|)
name|uLONG
name|osdSwap3
parameter_list|(
name|DPT_UNALIGNED
name|uLONG
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// !osdSwap3
ifdef|#
directive|ifdef
name|_DPT_NETWARE
include|#
directive|include
file|"novpass.h"
comment|/* For DPT_Bswapl() prototype */
comment|/* Inline the byte swap */
ifdef|#
directive|ifdef
name|__cplusplus
specifier|inline
name|uLONG
name|osdSwap4
parameter_list|(
name|uLONG
modifier|*
name|inLong
parameter_list|)
block|{
return|return
operator|*
name|inLong
operator|=
name|DPT_Bswapl
argument_list|(
operator|*
name|inLong
argument_list|)
return|;
block|}
else|#
directive|else
define|#
directive|define
name|osdSwap4
parameter_list|(
name|inLong
parameter_list|)
value|DPT_Bswapl(inLong)
endif|#
directive|endif
comment|// cplusplus
else|#
directive|else
comment|/* Reverses the byte ordering of a 4 byte variable */
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|osdSwap4
argument_list|)
operator|)
name|uLONG
name|osdSwap4
parameter_list|(
name|DPT_UNALIGNED
name|uLONG
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// !osdSwap4
comment|/* The following functions ALWAYS swap regardless of the *    * presence of DPT_BIG_ENDIAN                            */
name|uSHORT
name|trueSwap2
parameter_list|(
name|DPT_UNALIGNED
name|uSHORT
modifier|*
parameter_list|)
function_decl|;
name|uLONG
name|trueSwap4
parameter_list|(
name|DPT_UNALIGNED
name|uLONG
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// netware
comment|/*-------------------------------------*  * Network order swap functions        *  *                                     *  * These functions/macros will be used *  * by the structure insert()/extract() *  * functions.                          *  *  * We will enclose all structure       *  * portability modifications inside    *  * #ifdefs.  When we are ready, we     *  * will #define DPT_PORTABLE to begin  *  * using the modifications.            *  *-------------------------------------*/
name|uLONG
name|netSwap4
parameter_list|(
name|uLONG
name|val
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
comment|// for big-endian we need to swap
ifndef|#
directive|ifndef
name|NET_SWAP_2
define|#
directive|define
name|NET_SWAP_2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8) | ((x)<< 8))
endif|#
directive|endif
comment|// NET_SWAP_2
ifndef|#
directive|ifndef
name|NET_SWAP_4
define|#
directive|define
name|NET_SWAP_4
parameter_list|(
name|x
parameter_list|)
value|netSwap4((x))
endif|#
directive|endif
comment|// NET_SWAP_4
else|#
directive|else
comment|/* for little-endian we don't need to do anything */
ifndef|#
directive|ifndef
name|NET_SWAP_2
define|#
directive|define
name|NET_SWAP_2
parameter_list|(
name|x
parameter_list|)
value|(x)
endif|#
directive|endif
comment|// NET_SWAP_2
ifndef|#
directive|ifndef
name|NET_SWAP_4
define|#
directive|define
name|NET_SWAP_4
parameter_list|(
name|x
parameter_list|)
value|(x)
endif|#
directive|endif
comment|// NET_SWAP_4
endif|#
directive|endif
comment|// big endian
comment|/*----------------------------------- */
comment|/* Run-time loadable module functions */
comment|/*----------------------------------- */
comment|/* Loads the specified run-time loadable DLL */
name|DLL_HANDLE_T
name|osdLoadModule
parameter_list|(
name|uCHAR
modifier|*
parameter_list|)
function_decl|;
comment|/* Unloads the specified run-time loadable DLL */
name|uSHORT
name|osdUnloadModule
parameter_list|(
name|DLL_HANDLE_T
parameter_list|)
function_decl|;
comment|/* Returns a pointer to a function inside a run-time loadable DLL */
name|void
modifier|*
name|osdGetFnAddr
parameter_list|(
name|DLL_HANDLE_T
parameter_list|,
name|uCHAR
modifier|*
parameter_list|)
function_decl|;
comment|/*--------------------------------------- */
comment|/* Mutually exclusive semaphore functions */
comment|/*--------------------------------------- */
comment|/* Create a named semaphore */
name|SEMAPHORE_T
name|osdCreateNamedSemaphore
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Create a mutually exlusive semaphore */
name|SEMAPHORE_T
name|osdCreateSemaphore
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* create an event semaphore */
name|SEMAPHORE_T
name|osdCreateEventSemaphore
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* create a named event semaphore */
name|SEMAPHORE_T
name|osdCreateNamedEventSemaphore
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Destroy the specified mutually exclusive semaphore object */
name|uSHORT
name|osdDestroySemaphore
parameter_list|(
name|SEMAPHORE_T
parameter_list|)
function_decl|;
comment|/* Request access to the specified mutually exclusive semaphore */
name|uLONG
name|osdRequestSemaphore
parameter_list|(
name|SEMAPHORE_T
parameter_list|,
name|uLONG
parameter_list|)
function_decl|;
comment|/* Release access to the specified mutually exclusive semaphore */
name|uSHORT
name|osdReleaseSemaphore
parameter_list|(
name|SEMAPHORE_T
parameter_list|)
function_decl|;
comment|/* wait for a event to happen */
name|uLONG
name|osdWaitForEventSemaphore
parameter_list|(
name|SEMAPHORE_T
parameter_list|,
name|uLONG
parameter_list|)
function_decl|;
comment|/* signal an event */
name|uLONG
name|osdSignalEventSemaphore
parameter_list|(
name|SEMAPHORE_T
parameter_list|)
function_decl|;
comment|/* reset the event */
name|uLONG
name|osdResetEventSemaphore
parameter_list|(
name|SEMAPHORE_T
parameter_list|)
function_decl|;
comment|/*----------------- */
comment|/* Thread functions */
comment|/*----------------- */
comment|/* Releases control to the task switcher in non-preemptive */
comment|/* multitasking operating systems. */
name|void
name|osdSwitchThreads
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Starts a thread function */
name|uLONG
name|osdStartThread
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* what is my thread id */
name|uLONG
name|osdGetThreadID
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* wakes up the specifed thread */
name|void
name|osdWakeThread
parameter_list|(
name|uLONG
parameter_list|)
function_decl|;
comment|/* osd sleep for x miliseconds */
name|void
name|osdSleep
parameter_list|(
name|uLONG
parameter_list|)
function_decl|;
define|#
directive|define
name|DPT_THREAD_PRIORITY_LOWEST
value|0x00
define|#
directive|define
name|DPT_THREAD_PRIORITY_NORMAL
value|0x01
define|#
directive|define
name|DPT_THREAD_PRIORITY_HIGHEST
value|0x02
name|uCHAR
name|osdSetThreadPriority
parameter_list|(
name|uLONG
name|tid
parameter_list|,
name|uCHAR
name|priority
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|/* end the xtern "C" declaration */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* osd_util_h */
end_comment

end_unit

