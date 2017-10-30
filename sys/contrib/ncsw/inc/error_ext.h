begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2012 Freescale Semiconductor, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          error_ext.h   @Description   Error definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ERROR_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__ERROR_EXT_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCSW_FREEBSD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"xx_ext.h"
end_include

begin_include
include|#
directive|include
file|"core_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         gen_id  General Drivers Utilities   @Description   External routines.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         gen_error_id  Errors, Events and Debug   @Description   External routines.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************** The scheme below provides the bits description for error codes:   0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15 |       Reserved (should be zero)      |              Module ID               |   16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31 |                               Error Type                                    | ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ERROR_CODE
parameter_list|(
name|_err
parameter_list|)
value|((((uint32_t)_err)& 0x0000FFFF) | __ERR_MODULE__)
end_define

begin_define
define|#
directive|define
name|GET_ERROR_TYPE
parameter_list|(
name|_errcode
parameter_list|)
value|((_errcode)& 0x0000FFFF)
end_define

begin_comment
comment|/**< Extract module code from error code (#t_Error) */
end_comment

begin_define
define|#
directive|define
name|GET_ERROR_MODULE
parameter_list|(
name|_errcode
parameter_list|)
value|((_errcode)& 0x00FF0000)
end_define

begin_comment
comment|/**< Extract error type (#e_ErrorType) from                                      error code (#t_Error) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description    Error Type Enumeration */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_ErrorType
comment|/*   Comments / Associated Message Strings                      */
block|{
comment|/* ------------------------------------------------------------ */
name|E_OK
init|=
literal|0
comment|/*   Never use "RETURN_ERROR" with E_OK; Use "return E_OK;"     */
block|,
name|E_WRITE_FAILED
init|=
name|EIO
comment|/**< Write access failed on memory/device.                      */
comment|/*   String: none, or device name.                              */
block|,
name|E_NO_DEVICE
init|=
name|ENXIO
comment|/**< The associated device is not initialized.                  */
comment|/*   String: none.                                              */
block|,
name|E_NOT_AVAILABLE
init|=
name|EAGAIN
comment|/**< Resource is unavailable.                                   */
comment|/*   String: none, unless the operation is not the main goal                                  of the function (in this case add resource description).   */
block|,
name|E_NO_MEMORY
init|=
name|ENOMEM
comment|/**< External memory allocation failed.                         */
comment|/*   String: description of item for which allocation failed.   */
block|,
name|E_INVALID_ADDRESS
init|=
name|EFAULT
comment|/**< Invalid address.                                           */
comment|/*   String: description of the specific violation.             */
block|,
name|E_BUSY
init|=
name|EBUSY
comment|/**< Resource or module is busy.                                */
comment|/*   String: none, unless the operation is not the main goal                                  of the function (in this case add resource description).   */
block|,
name|E_ALREADY_EXISTS
init|=
name|EEXIST
comment|/**< Requested resource or item already exists.                 */
comment|/*   Use when resource duplication or sharing are not allowed.                                  String: none, unless the operation is not the main goal                                  of the function (in this case add item description).       */
block|,
name|E_INVALID_OPERATION
init|=
name|ENODEV
comment|/**< The operation/command is invalid (unrecognized).           */
comment|/*   String: none.                                              */
block|,
name|E_INVALID_VALUE
init|=
name|EDOM
comment|/**< Invalid value.                                             */
comment|/*   Use for non-enumeration parameters, and                                  only when other error types are not suitable.                                  String: parameter description + "(should be<attribute>)",                                  e.g: "Maximum Rx buffer length (should be divisible by 8)",                                       "Channel number (should be even)".                    */
block|,
name|E_NOT_IN_RANGE
init|=
name|ERANGE
comment|/**< Parameter value is out of range.                           */
comment|/*   Don't use this error for enumeration parameters.                                  String: parameter description + "(should be %d-%d)",                                  e.g: "Number of pad characters (should be 0-15)".          */
block|,
name|E_NOT_SUPPORTED
init|=
name|ENOSYS
comment|/**< The function is not supported or not implemented.          */
comment|/*   String: none.                                              */
block|,
name|E_INVALID_STATE
comment|/**< The operation is not allowed in current module state.      */
comment|/*   String: none.                                              */
block|,
name|E_INVALID_HANDLE
comment|/**< Invalid handle of module or object.                        */
comment|/*   String: none, unless the function takes in more than one                                  handle (in this case add the handle description)           */
block|,
name|E_INVALID_ID
comment|/**< Invalid module ID (usually enumeration or index).          */
comment|/*   String: none, unless the function takes in more than one                                  ID (in this case add the ID description)                   */
block|,
name|E_NULL_POINTER
comment|/**< Unexpected NULL pointer.                                   */
comment|/*   String: pointer description.                               */
block|,
name|E_INVALID_SELECTION
comment|/**< Invalid selection or mode.                                 */
comment|/*   Use for enumeration values, only when other error types                                  are not suitable.                                  String: parameter description.                             */
block|,
name|E_INVALID_COMM_MODE
comment|/**< Invalid communication mode.                                */
comment|/*   String: none, unless the function takes in more than one                                  communication mode indications (in this case add                                  parameter description).                                    */
block|,
name|E_INVALID_MEMORY_TYPE
comment|/**< Invalid memory type.                                       */
comment|/*   String: none, unless the function takes in more than one                                  memory types (in this case add memory description,                                  e.g: "Data memory", "Buffer descriptors memory").          */
block|,
name|E_INVALID_CLOCK
comment|/**< Invalid clock.                                             */
comment|/*   String: none, unless the function takes in more than one                                  clocks (in this case add clock description,                                  e.g: "Rx clock", "Tx clock").                              */
block|,
name|E_CONFLICT
comment|/**< Some setting conflicts with another setting.               */
comment|/*   String: description of the conflicting settings.           */
block|,
name|E_NOT_ALIGNED
comment|/**< Non-aligned address.                                       */
comment|/*   String: parameter description + "(should be %d-bytes aligned)",                                  e.g: "Rx data buffer (should be 32-bytes aligned)".        */
block|,
name|E_NOT_FOUND
comment|/**< Requested resource or item was not found.                  */
comment|/*   Use only when the resource/item is uniquely identified.                                  String: none, unless the operation is not the main goal                                  of the function (in this case add item description).       */
block|,
name|E_FULL
comment|/**< Resource is full.                                          */
comment|/*   String: none, unless the operation is not the main goal                                  of the function (in this case add resource description).   */
block|,
name|E_EMPTY
comment|/**< Resource is empty.                                         */
comment|/*   String: none, unless the operation is not the main goal                                  of the function (in this case add resource description).   */
block|,
name|E_ALREADY_FREE
comment|/**< Specified resource or item is already free or deleted.     */
comment|/*   String: none, unless the operation is not the main goal                                  of the function (in this case add item description).       */
block|,
name|E_READ_FAILED
comment|/**< Read access failed on memory/device.                       */
comment|/*   String: none, or device name.                              */
block|,
name|E_INVALID_FRAME
comment|/**< Invalid frame object (NULL handle or missing buffers).     */
comment|/*   String: none.                                              */
block|,
name|E_SEND_FAILED
comment|/**< Send operation failed on device.                           */
comment|/*   String: none, or device name.                              */
block|,
name|E_RECEIVE_FAILED
comment|/**< Receive operation failed on device.                        */
comment|/*   String: none, or device name.                              */
block|,
name|E_TIMEOUT
comment|/* = ETIMEDOUT*/
comment|/**< The operation timed out.                                   */
comment|/*   String: none.                                              */
block|,
name|E_DUMMY_LAST
comment|/* NEVER USED */
block|}
name|e_ErrorType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description    Event Type Enumeration */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_Event
comment|/*   Comments / Associated Flags and Message Strings            */
block|{
comment|/* ------------------------------------------------------------ */
name|EV_NO_EVENT
init|=
literal|0
comment|/**< No event; Never used.                                      */
block|,
name|EV_RX_DISCARD
comment|/**< Received packet discarded (by the driver, and only for                                  complete packets);                                  Flags: error flags in case of error, zero otherwise.       */
comment|/*   String: reason for discard, e.g: "Error in frame",                                  "Disordered frame", "Incomplete frame", "No frame object". */
block|,
name|EV_RX_ERROR
comment|/**< Receive error (by hardware/firmware);                                  Flags: usually status flags from the buffer descriptor.    */
comment|/*   String: none.                                              */
block|,
name|EV_TX_ERROR
comment|/**< Transmit error (by hardware/firmware);                                  Flags: usually status flags from the buffer descriptor.    */
comment|/*   String: none.                                              */
block|,
name|EV_NO_BUFFERS
comment|/**< System ran out of buffer objects;                                  Flags: zero.                                               */
comment|/*   String: none.                                              */
block|,
name|EV_NO_MB_FRAMES
comment|/**< System ran out of multi-buffer frame objects;                                  Flags: zero.                                               */
comment|/*   String: none.                                              */
block|,
name|EV_NO_SB_FRAMES
comment|/**< System ran out of single-buffer frame objects;                                  Flags: zero.                                               */
comment|/*   String: none.                                              */
block|,
name|EV_TX_QUEUE_FULL
comment|/**< Transmit queue is full;                                  Flags: zero.                                               */
comment|/*   String: none.                                              */
block|,
name|EV_RX_QUEUE_FULL
comment|/**< Receive queue is full;                                  Flags: zero.                                               */
comment|/*   String: none.                                              */
block|,
name|EV_INTR_QUEUE_FULL
comment|/**< Interrupt queue overflow;                                  Flags: zero.                                               */
comment|/*   String: none.                                              */
block|,
name|EV_NO_DATA_BUFFER
comment|/**< Data buffer allocation (from higher layer) failed;                                  Flags: zero.                                               */
comment|/*   String: none.                                              */
block|,
name|EV_OBJ_POOL_EMPTY
comment|/**< Objects pool is empty;                                  Flags: zero.                                               */
comment|/*   String: object description (name).                         */
block|,
name|EV_BUS_ERROR
comment|/**< Illegal access on bus;                                  Flags: the address (if available) or bus identifier        */
comment|/*   String: bus/address/module description.                    */
block|,
name|EV_PTP_TXTS_QUEUE_FULL
comment|/**< PTP Tx timestamps queue is full;                                  Flags: zero.                                               */
comment|/*   String: none.                                              */
block|,
name|EV_PTP_RXTS_QUEUE_FULL
comment|/**< PTP Rx timestamps queue is full;                                  Flags: zero.                                               */
comment|/*   String: none.                                              */
block|,
name|EV_DUMMY_LAST
block|}
name|e_Event
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    Debug Levels for Errors and Events                  The level description refers to errors only.                 For events, classification is done by the user.                  The TRACE, INFO and WARNING levels are allowed only when using                 the DBG macro, and are not allowed when using the error macros                 (RETURN_ERROR or REPORT_ERROR).  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|REPORT_LEVEL_CRITICAL
value|1
end_define

begin_comment
comment|/**< Crasher: Incorrect flow, NULL pointers/handles. */
end_comment

begin_define
define|#
directive|define
name|REPORT_LEVEL_MAJOR
value|2
end_define

begin_comment
comment|/**< Cannot proceed: Invalid operation, parameters or                                              configuration. */
end_comment

begin_define
define|#
directive|define
name|REPORT_LEVEL_MINOR
value|3
end_define

begin_comment
comment|/**< Recoverable problem: a repeating call with the same                                              parameters may be successful. */
end_comment

begin_define
define|#
directive|define
name|REPORT_LEVEL_WARNING
value|4
end_define

begin_comment
comment|/**< Something is not exactly right, yet it is not an error. */
end_comment

begin_define
define|#
directive|define
name|REPORT_LEVEL_INFO
value|5
end_define

begin_comment
comment|/**< Messages which may be of interest to user/programmer. */
end_comment

begin_define
define|#
directive|define
name|REPORT_LEVEL_TRACE
value|6
end_define

begin_comment
comment|/**< Program flow messages. */
end_comment

begin_define
define|#
directive|define
name|EVENT_DISABLED
value|0xFF
end_define

begin_comment
comment|/**< Disabled event (not reported at all) */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_define
define|#
directive|define
name|NO_MSG
value|("")
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG_GLOBAL_LEVEL
end_ifndef

begin_define
define|#
directive|define
name|DEBUG_GLOBAL_LEVEL
value|REPORT_LEVEL_WARNING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_GLOBAL_LEVEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ERROR_GLOBAL_LEVEL
end_ifndef

begin_define
define|#
directive|define
name|ERROR_GLOBAL_LEVEL
value|DEBUG_GLOBAL_LEVEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ERROR_GLOBAL_LEVEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT_GLOBAL_LEVEL
end_ifndef

begin_define
define|#
directive|define
name|EVENT_GLOBAL_LEVEL
value|REPORT_LEVEL_MINOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT_GLOBAL_LEVEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EVENT_LOCAL_LEVEL
end_ifdef

begin_define
define|#
directive|define
name|EVENT_DYNAMIC_LEVEL
value|EVENT_LOCAL_LEVEL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVENT_DYNAMIC_LEVEL
value|EVENT_GLOBAL_LEVEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT_LOCAL_LEVEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG_DYNAMIC_LEVEL
end_ifndef

begin_define
define|#
directive|define
name|DEBUG_USING_STATIC_LEVEL
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_STATIC_LEVEL
end_ifdef

begin_define
define|#
directive|define
name|DEBUG_DYNAMIC_LEVEL
value|DEBUG_STATIC_LEVEL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG_DYNAMIC_LEVEL
value|DEBUG_GLOBAL_LEVEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_STATIC_LEVEL */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DEBUG_DYNAMIC_LEVEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_STATIC_LEVEL
end_ifdef

begin_error
error|#
directive|error
literal|"Please use either DEBUG_STATIC_LEVEL or DEBUG_DYNAMIC_LEVEL (not both)"
end_error

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|DEBUG_DYNAMIC_LEVEL
init|=
name|DEBUG_GLOBAL_LEVEL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_STATIC_LEVEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DEBUG_DYNAMIC_LEVEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ERROR_DYNAMIC_LEVEL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ERROR_STATIC_LEVEL
end_ifdef

begin_define
define|#
directive|define
name|ERROR_DYNAMIC_LEVEL
value|ERROR_STATIC_LEVEL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ERROR_DYNAMIC_LEVEL
value|ERROR_GLOBAL_LEVEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ERROR_STATIC_LEVEL */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ERROR_DYNAMIC_LEVEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ERROR_STATIC_LEVEL
end_ifdef

begin_error
error|#
directive|error
literal|"Please use either ERROR_STATIC_LEVEL or ERROR_DYNAMIC_LEVEL (not both)"
end_error

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|ERROR_DYNAMIC_LEVEL
init|=
name|ERROR_GLOBAL_LEVEL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ERROR_STATIC_LEVEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ERROR_DYNAMIC_LEVEL */
end_comment

begin_define
define|#
directive|define
name|PRINT_FORMAT
value|"[CPU%02d, %s:%d %s]"
end_define

begin_define
define|#
directive|define
name|PRINT_FMT_PARAMS
value|PCPU_GET(cpuid), __FILE__, __LINE__, __FUNCTION__
end_define

begin_if
if|#
directive|if
operator|(
operator|!
operator|(
name|defined
argument_list|(
name|DEBUG_ERRORS
argument_list|)
operator|)
operator|||
operator|(
name|DEBUG_ERRORS
operator|==
literal|0
operator|)
operator|)
end_if

begin_comment
comment|/* No debug/error/event messages at all */
end_comment

begin_define
define|#
directive|define
name|DBG
parameter_list|(
name|_level
parameter_list|,
name|_vmsg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|REPORT_ERROR
parameter_list|(
name|_level
parameter_list|,
name|_err
parameter_list|,
name|_vmsg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RETURN_ERROR
parameter_list|(
name|_level
parameter_list|,
name|_err
parameter_list|,
name|_vmsg
parameter_list|)
define|\
value|return ERROR_CODE(_err)
end_define

begin_if
if|#
directive|if
operator|(
name|REPORT_EVENTS
operator|>
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|REPORT_EVENT
parameter_list|(
name|_ev
parameter_list|,
name|_appId
parameter_list|,
name|_flg
parameter_list|,
name|_vmsg
parameter_list|)
define|\
value|do { \         if (_ev##_LEVEL<= EVENT_DYNAMIC_LEVEL) { \             XX_EventById((uint32_t)(_ev), (t_Handle)(_appId), (uint16_t)(_flg), NO_MSG); \         } \     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REPORT_EVENT
parameter_list|(
name|_ev
parameter_list|,
name|_appId
parameter_list|,
name|_flg
parameter_list|,
name|_vmsg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (REPORT_EVENTS> 0) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DEBUG_ERRORS> 0 */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|dbgLevelStrings
index|[]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|(
name|REPORT_EVENTS
operator|>
literal|0
operator|)
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|eventStrings
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (REPORT_EVENTS> 0) */
end_comment

begin_function_decl
name|char
modifier|*
name|ErrTypeStrings
parameter_list|(
name|e_ErrorType
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|DEBUG_USING_STATIC_LEVEL
argument_list|)
operator|)
operator|&&
operator|(
name|DEBUG_DYNAMIC_LEVEL
operator|<
name|REPORT_LEVEL_WARNING
operator|)
operator|)
end_if

begin_comment
comment|/* No need for DBG macro - debug level is higher anyway */
end_comment

begin_define
define|#
directive|define
name|DBG
parameter_list|(
name|_level
parameter_list|,
name|_vmsg
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBG
parameter_list|(
name|_level
parameter_list|,
name|_vmsg
parameter_list|)
define|\
value|do { \         if (REPORT_LEVEL_##_level<= DEBUG_DYNAMIC_LEVEL) { \             XX_Print("> %s (%s) " PRINT_FORMAT ": ", \                      dbgLevelStrings[REPORT_LEVEL_##_level - 1], \                      __STRING(__ERR_MODULE__), \                      PRINT_FMT_PARAMS); \             XX_Print _vmsg; \             XX_Print("\r\n"); \         } \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(DEBUG_USING_STATIC_LEVEL)&& (DEBUG_DYNAMIC_LEVEL< WARNING)) */
end_comment

begin_define
define|#
directive|define
name|REPORT_ERROR
parameter_list|(
name|_level
parameter_list|,
name|_err
parameter_list|,
name|_vmsg
parameter_list|)
define|\
value|do { \         if (REPORT_LEVEL_##_level<= ERROR_DYNAMIC_LEVEL) { \             XX_Print("! %s %s Error " PRINT_FORMAT ": %s; ", \                      dbgLevelStrings[REPORT_LEVEL_##_level - 1], \                      __STRING(__ERR_MODULE__), \                      PRINT_FMT_PARAMS, \                      ErrTypeStrings((e_ErrorType)GET_ERROR_TYPE(_err))); \             XX_Print _vmsg; \             XX_Print("\r\n"); \         } \     } while (0)
end_define

begin_define
define|#
directive|define
name|RETURN_ERROR
parameter_list|(
name|_level
parameter_list|,
name|_err
parameter_list|,
name|_vmsg
parameter_list|)
define|\
value|do { \         REPORT_ERROR(_level, (_err), _vmsg); \         return ERROR_CODE(_err); \     } while (0)
end_define

begin_if
if|#
directive|if
operator|(
name|REPORT_EVENTS
operator|>
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|REPORT_EVENT
parameter_list|(
name|_ev
parameter_list|,
name|_appId
parameter_list|,
name|_flg
parameter_list|,
name|_vmsg
parameter_list|)
define|\
value|do { \         if (_ev##_LEVEL<= EVENT_DYNAMIC_LEVEL) { \             XX_Print("~ %s %s Event " PRINT_FORMAT ": %s (flags: 0x%04x); ", \                      dbgLevelStrings[_ev##_LEVEL - 1], \                      __STRING(__ERR_MODULE__), \                      PRINT_FMT_PARAMS, \                      eventStrings[((_ev) - EV_NO_EVENT - 1)], \                      (uint16_t)(_flg)); \             XX_Print _vmsg; \             XX_Print("\r\n"); \             XX_EventById((uint32_t)(_ev), (t_Handle)(_appId), (uint16_t)(_flg), NO_MSG); \         } \     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not REPORT_EVENTS */
end_comment

begin_define
define|#
directive|define
name|REPORT_EVENT
parameter_list|(
name|_ev
parameter_list|,
name|_appId
parameter_list|,
name|_flg
parameter_list|,
name|_vmsg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (REPORT_EVENTS> 0) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DEBUG_ERRORS> 0) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      ASSERT_COND   @Description   Assertion macro.   @Param[in]     _cond - The condition being checked, in positive form;                         Failure of the condition triggers the assert. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DISABLE_ASSERTIONS
end_ifdef

begin_define
define|#
directive|define
name|ASSERT_COND
parameter_list|(
name|_cond
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT_COND
parameter_list|(
name|_cond
parameter_list|)
define|\
value|do { \         if (!(_cond)) { \             XX_Print("*** ASSERT_COND failed " PRINT_FORMAT "\r\n", \                     PRINT_FMT_PARAMS); \             XX_Exit(1); \         } \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DISABLE_ASSERTIONS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DISABLE_INIT_PARAMETERS_CHECK
end_ifdef

begin_define
define|#
directive|define
name|CHECK_INIT_PARAMETERS
parameter_list|(
name|handle
parameter_list|,
name|f_check
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CHECK_INIT_PARAMETERS_RETURN_VALUE
parameter_list|(
name|handle
parameter_list|,
name|f_check
parameter_list|,
name|retval
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK_INIT_PARAMETERS
parameter_list|(
name|handle
parameter_list|,
name|f_check
parameter_list|)
define|\
value|do { \         t_Error err = f_check(handle); \         if (err != E_OK) { \             RETURN_ERROR(MAJOR, err, NO_MSG); \         } \     } while (0)
end_define

begin_define
define|#
directive|define
name|CHECK_INIT_PARAMETERS_RETURN_VALUE
parameter_list|(
name|handle
parameter_list|,
name|f_check
parameter_list|,
name|retval
parameter_list|)
define|\
value|do { \         t_Error err = f_check(handle); \         if (err != E_OK) { \             REPORT_ERROR(MAJOR, err, NO_MSG); \             return (retval); \         } \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DISABLE_INIT_PARAMETERS_CHECK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DISABLE_SANITY_CHECKS
end_ifdef

begin_define
define|#
directive|define
name|SANITY_CHECK_RETURN_ERROR
parameter_list|(
name|_cond
parameter_list|,
name|_err
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SANITY_CHECK_RETURN_VALUE
parameter_list|(
name|_cond
parameter_list|,
name|_err
parameter_list|,
name|retval
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SANITY_CHECK_RETURN
parameter_list|(
name|_cond
parameter_list|,
name|_err
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SANITY_CHECK_EXIT
parameter_list|(
name|_cond
parameter_list|,
name|_err
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DISABLE_SANITY_CHECKS */
end_comment

begin_define
define|#
directive|define
name|SANITY_CHECK_RETURN_ERROR
parameter_list|(
name|_cond
parameter_list|,
name|_err
parameter_list|)
define|\
value|do { \         if (!(_cond)) { \             RETURN_ERROR(CRITICAL, (_err), NO_MSG); \         } \     } while (0)
end_define

begin_define
define|#
directive|define
name|SANITY_CHECK_RETURN_VALUE
parameter_list|(
name|_cond
parameter_list|,
name|_err
parameter_list|,
name|retval
parameter_list|)
define|\
value|do { \         if (!(_cond)) { \             REPORT_ERROR(CRITICAL, (_err), NO_MSG); \             return (retval); \         } \     } while (0)
end_define

begin_define
define|#
directive|define
name|SANITY_CHECK_RETURN
parameter_list|(
name|_cond
parameter_list|,
name|_err
parameter_list|)
define|\
value|do { \         if (!(_cond)) { \             REPORT_ERROR(CRITICAL, (_err), NO_MSG); \             return; \         } \     } while (0)
end_define

begin_define
define|#
directive|define
name|SANITY_CHECK_EXIT
parameter_list|(
name|_cond
parameter_list|,
name|_err
parameter_list|)
define|\
value|do { \         if (!(_cond)) { \             REPORT_ERROR(CRITICAL, (_err), NO_MSG); \             XX_Exit(1); \         } \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DISABLE_SANITY_CHECKS */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of Debug/error Utils group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of General Utils group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ERROR_EXT_H */
end_comment

end_unit

