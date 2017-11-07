begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2012 Freescale Semiconductor, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          ncsw_ext.h   @Description   General NetCommSw Standard Definitions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NCSW_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__NCSW_EXT_H
end_define

begin_include
include|#
directive|include
file|"memcpy_ext.h"
end_include

begin_define
define|#
directive|define
name|WRITE_BLOCK
value|IOMemSet32
end_define

begin_comment
comment|/* include memcpy_ext.h */
end_comment

begin_define
define|#
directive|define
name|COPY_BLOCK
value|Mem2IOCpy32
end_define

begin_comment
comment|/* include memcpy_ext.h */
end_comment

begin_define
define|#
directive|define
name|PTR_TO_UINT
parameter_list|(
name|_ptr
parameter_list|)
value|((uintptr_t)(_ptr))
end_define

begin_define
define|#
directive|define
name|UINT_TO_PTR
parameter_list|(
name|_val
parameter_list|)
value|((void*)(uintptr_t)(_val))
end_define

begin_define
define|#
directive|define
name|PTR_MOVE
parameter_list|(
name|_ptr
parameter_list|,
name|_offset
parameter_list|)
value|(void*)((uint8_t*)(_ptr) + (_offset))
end_define

begin_define
define|#
directive|define
name|WRITE_UINT8_UINT24
parameter_list|(
name|arg
parameter_list|,
name|data08
parameter_list|,
name|data24
parameter_list|)
define|\
value|WRITE_UINT32(arg,((uint32_t)(data08)<<24)|((uint32_t)(data24)&0x00FFFFFF))
end_define

begin_define
define|#
directive|define
name|WRITE_UINT24_UINT8
parameter_list|(
name|arg
parameter_list|,
name|data24
parameter_list|,
name|data08
parameter_list|)
define|\
value|WRITE_UINT32(arg,((uint32_t)(data24)<< 8)|((uint32_t)(data08)&0x000000FF))
end_define

begin_comment
comment|/* Little-Endian access macros */
end_comment

begin_define
define|#
directive|define
name|WRITE_UINT16_LE
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
define|\
value|WRITE_UINT16((arg), SwapUint16(data))
end_define

begin_define
define|#
directive|define
name|WRITE_UINT32_LE
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
define|\
value|WRITE_UINT32((arg), SwapUint32(data))
end_define

begin_define
define|#
directive|define
name|WRITE_UINT64_LE
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
define|\
value|WRITE_UINT64((arg), SwapUint64(data))
end_define

begin_define
define|#
directive|define
name|GET_UINT16_LE
parameter_list|(
name|arg
parameter_list|)
define|\
value|SwapUint16(GET_UINT16(arg))
end_define

begin_define
define|#
directive|define
name|GET_UINT32_LE
parameter_list|(
name|arg
parameter_list|)
define|\
value|SwapUint32(GET_UINT32(arg))
end_define

begin_define
define|#
directive|define
name|GET_UINT64_LE
parameter_list|(
name|arg
parameter_list|)
define|\
value|SwapUint64(GET_UINT64(arg))
end_define

begin_comment
comment|/* Write and Read again macros */
end_comment

begin_define
define|#
directive|define
name|WRITE_UINT_SYNC
parameter_list|(
name|size
parameter_list|,
name|arg
parameter_list|,
name|data
parameter_list|)
define|\
value|do {                                    \         WRITE_UINT##size((arg), (data));    \         CORE_MemoryBarrier();               \     } while (0)
end_define

begin_define
define|#
directive|define
name|WRITE_UINT8_SYNC
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
value|WRITE_UINT_SYNC(8, (arg), (data))
end_define

begin_define
define|#
directive|define
name|WRITE_UINT16_SYNC
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
value|WRITE_UINT_SYNC(16, (arg), (data))
end_define

begin_define
define|#
directive|define
name|WRITE_UINT32_SYNC
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
value|WRITE_UINT_SYNC(32, (arg), (data))
end_define

begin_define
define|#
directive|define
name|MAKE_UINT64
parameter_list|(
name|high32
parameter_list|,
name|low32
parameter_list|)
value|(((uint64_t)high32<< 32) | (low32))
end_define

begin_comment
comment|/*----------------------*/
end_comment

begin_comment
comment|/* Miscellaneous macros */
end_comment

begin_comment
comment|/*----------------------*/
end_comment

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|_x
parameter_list|)
value|((void)(_x))
end_define

begin_define
define|#
directive|define
name|KILOBYTE
value|0x400UL
end_define

begin_comment
comment|/* 1024 */
end_comment

begin_define
define|#
directive|define
name|MEGABYTE
value|(KILOBYTE * KILOBYTE)
end_define

begin_comment
comment|/* 1024*1024 */
end_comment

begin_define
define|#
directive|define
name|GIGABYTE
value|((uint64_t)(KILOBYTE * MEGABYTE))
end_define

begin_comment
comment|/* 1024*1024*1024 */
end_comment

begin_define
define|#
directive|define
name|TERABYTE
value|((uint64_t)(KILOBYTE * GIGABYTE))
end_define

begin_comment
comment|/* 1024*1024*1024*1024 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_IRQ
end_ifndef

begin_define
define|#
directive|define
name|NO_IRQ
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NCSW_MASTER_ID
value|(0)
end_define

begin_comment
comment|/* Macro for checking if a number is a power of 2 */
end_comment

begin_define
define|#
directive|define
name|POWER_OF_2
parameter_list|(
name|n
parameter_list|)
value|(!((n)& ((n)-1)))
end_define

begin_comment
comment|/* Macro for calculating log of base 2 */
end_comment

begin_define
define|#
directive|define
name|LOG2
parameter_list|(
name|num
parameter_list|,
name|log2Num
parameter_list|)
define|\
value|do                          \     {                           \         uint64_t tmp = (num);   \         log2Num = 0;            \         while (tmp> 1)         \         {                       \             log2Num++;          \             tmp>>= 1;          \         }                       \     } while (0)
end_define

begin_define
define|#
directive|define
name|NEXT_POWER_OF_2
parameter_list|(
name|_num
parameter_list|,
name|_nextPow
parameter_list|)
define|\
value|do                                      \ {                                       \     if (POWER_OF_2(_num))               \         _nextPow = (_num);              \     else                                \     {                                   \         uint64_t tmp = (_num);          \         _nextPow = 1;                   \         while (tmp)                     \         {                               \             _nextPow<<= 1;             \             tmp>>= 1;                  \         }                               \     }                                   \ } while (0)
end_define

begin_comment
comment|/* Ceiling division - not the fastest way, but safer in terms of overflow */
end_comment

begin_define
define|#
directive|define
name|DIV_CEIL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)/(y)) + (((((x)/(y))*(y)) == (x)) ? 0 : 1))
end_define

begin_comment
comment|/* Round up a number to be a multiple of a second number */
end_comment

begin_define
define|#
directive|define
name|ROUND_UP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x) + (y) - 1) / (y)) * (y))
end_define

begin_comment
comment|/* Timing macro for converting usec units to number of ticks.   */
end_comment

begin_comment
comment|/* (number of usec *  clock_Hz) / 1,000,000) - since            */
end_comment

begin_comment
comment|/* clk is in MHz units, no division needed.                     */
end_comment

begin_define
define|#
directive|define
name|USEC_TO_CLK
parameter_list|(
name|usec
parameter_list|,
name|clk
parameter_list|)
value|((usec) * (clk))
end_define

begin_define
define|#
directive|define
name|CYCLES_TO_USEC
parameter_list|(
name|cycles
parameter_list|,
name|clk
parameter_list|)
value|((cycles) / (clk))
end_define

begin_comment
comment|/* Timing macros for converting between nsec units and number of clocks. */
end_comment

begin_define
define|#
directive|define
name|NSEC_TO_CLK
parameter_list|(
name|nsec
parameter_list|,
name|clk
parameter_list|)
value|DIV_CEIL(((nsec) * (clk)), 1000)
end_define

begin_define
define|#
directive|define
name|CYCLES_TO_NSEC
parameter_list|(
name|cycles
parameter_list|,
name|clk
parameter_list|)
value|(((cycles) * 1000) / (clk))
end_define

begin_comment
comment|/* Timing macros for converting between psec units and number of clocks. */
end_comment

begin_define
define|#
directive|define
name|PSEC_TO_CLK
parameter_list|(
name|psec
parameter_list|,
name|clk
parameter_list|)
value|DIV_CEIL(((psec) * (clk)), 1000000)
end_define

begin_define
define|#
directive|define
name|CYCLES_TO_PSEC
parameter_list|(
name|cycles
parameter_list|,
name|clk
parameter_list|)
value|(((cycles) * 1000000) / (clk))
end_define

begin_comment
comment|/* Min, Max macros */
end_comment

begin_define
define|#
directive|define
name|IN_RANGE
parameter_list|(
name|min
parameter_list|,
name|val
parameter_list|,
name|max
parameter_list|)
value|((min)<=(val)&& (val)<=(max))
end_define

begin_define
define|#
directive|define
name|ABS
parameter_list|(
name|a
parameter_list|)
value|((a<0)?(a*-1):a)
end_define

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|ARRAY_SIZE
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|arr
parameter_list|)
value|(sizeof(arr) / sizeof((arr)[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(ARRAY_SIZE) */
end_comment

begin_comment
comment|/* possible alignments */
end_comment

begin_define
define|#
directive|define
name|HALF_WORD_ALIGNMENT
value|2
end_define

begin_define
define|#
directive|define
name|WORD_ALIGNMENT
value|4
end_define

begin_define
define|#
directive|define
name|DOUBLE_WORD_ALIGNMENT
value|8
end_define

begin_define
define|#
directive|define
name|BURST_ALIGNMENT
value|32
end_define

begin_define
define|#
directive|define
name|HALF_WORD_ALIGNED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|WORD_ALIGNED
value|0x00000003
end_define

begin_define
define|#
directive|define
name|DOUBLE_WORD_ALIGNED
value|0x00000007
end_define

begin_define
define|#
directive|define
name|BURST_ALIGNED
value|0x0000001f
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IS_ALIGNED
end_ifndef

begin_define
define|#
directive|define
name|IS_ALIGNED
parameter_list|(
name|n
parameter_list|,
name|align
parameter_list|)
value|(!((uint32_t)(n)& (align - 1)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IS_ALIGNED */
end_comment

begin_define
define|#
directive|define
name|LAST_BUF
value|1
end_define

begin_define
define|#
directive|define
name|FIRST_BUF
value|2
end_define

begin_define
define|#
directive|define
name|SINGLE_BUF
value|(LAST_BUF | FIRST_BUF)
end_define

begin_define
define|#
directive|define
name|MIDDLE_BUF
value|4
end_define

begin_define
define|#
directive|define
name|ARRAY_END
value|-1
end_define

begin_define
define|#
directive|define
name|ILLEGAL_BASE
value|(~0)
end_define

begin_define
define|#
directive|define
name|BUF_POSITION
parameter_list|(
name|first
parameter_list|,
name|last
parameter_list|)
value|state[(!!(last))<<1 | !!(first)]
end_define

begin_define
define|#
directive|define
name|DECLARE_POSITION
value|static uint8_t state[4] = { (uint8_t)MIDDLE_BUF, (uint8_t)FIRST_BUF, (uint8_t)LAST_BUF, (uint8_t)SINGLE_BUF };
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Timers operation mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_TimerMode
block|{
name|e_TIMER_MODE_INVALID
init|=
literal|0
block|,
name|e_TIMER_MODE_FREE_RUN
block|,
comment|/**< Free run - counter continues to increase                                    after reaching the reference value. */
name|e_TIMER_MODE_PERIODIC
block|,
comment|/**< Periodic - counter restarts counting from 0                                    after reaching the reference value. */
name|e_TIMER_MODE_SINGLE
comment|/**< Single (one-shot) - counter stops counting                                    after reaching the reference value. */
block|}
name|e_TimerMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration (bit flags) of communication modes (Transmit,                 receive or both). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_CommMode
block|{
name|e_COMM_MODE_NONE
init|=
literal|0
block|,
comment|/**< No transmit/receive communication */
name|e_COMM_MODE_RX
init|=
literal|1
block|,
comment|/**< Only receive communication */
name|e_COMM_MODE_TX
init|=
literal|2
block|,
comment|/**< Only transmit communication */
name|e_COMM_MODE_RX_AND_TX
init|=
literal|3
comment|/**< Both transmit and receive communication */
block|}
name|e_CommMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   General Diagnostic Mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_DiagMode
block|{
name|e_DIAG_MODE_NONE
init|=
literal|0
block|,
comment|/**< Normal operation; no diagnostic mode */
name|e_DIAG_MODE_CTRL_LOOPBACK
block|,
comment|/**< Loopback in the controller */
name|e_DIAG_MODE_CHIP_LOOPBACK
block|,
comment|/**< Loopback in the chip but not in the                                      controller; e.g. IO-pins, SerDes, etc. */
name|e_DIAG_MODE_PHY_LOOPBACK
block|,
comment|/**< Loopback in the external PHY */
name|e_DIAG_MODE_EXT_LOOPBACK
block|,
comment|/**< Loopback in the external line (beyond the PHY) */
name|e_DIAG_MODE_CTRL_ECHO
block|,
comment|/**< Echo incoming data by the controller */
name|e_DIAG_MODE_PHY_ECHO
comment|/**< Echo incoming data by the PHY */
block|}
name|e_DiagMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Possible RxStore callback responses. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_RxStoreResponse
block|{
name|e_RX_STORE_RESPONSE_PAUSE
comment|/**< Pause invoking callback with received data;                                          in polling mode, start again invoking callback                                          only next time user invokes the receive routine;                                          in interrupt mode, start again invoking callback                                          only next time a receive event triggers an interrupt;                                          in all cases, received data that are pending are not                                          lost, rather, their processing is temporarily deferred;                                          in all cases, received data are processed in the order                                          in which they were received. */
block|,
name|e_RX_STORE_RESPONSE_CONTINUE
comment|/**< Continue invoking callback with received data. */
block|}
name|e_RxStoreResponse
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   General Handle */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|t_Handle
typedef|;
end_typedef

begin_comment
comment|/**< handle, used as object's descriptor */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   MUTEX type */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|t_Mutex
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Error Code.                  The high word of the error code is the code of the software                 module (driver). The low word is the error type (e_ErrorType).                 To get the values from the error code, use GET_ERROR_TYPE()                 and GET_ERROR_MODULE(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|t_Error
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   General prototype of interrupt service routine (ISR).   @Param[in]     handle - Optional handle of the module handling the interrupt.   @Return        None  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_Isr
function_decl|)
parameter_list|(
name|t_Handle
name|handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Anchor        mem_attr   @Collection    Memory Attributes                  Various attributes of memory partitions. These values may be                 or'ed together to create a mask of all memory attributes.  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MEMORY_ATTR_CACHEABLE
value|0x00000001
end_define

begin_comment
comment|/**< Memory is cacheable */
end_comment

begin_define
define|#
directive|define
name|MEMORY_ATTR_QE_2ND_BUS_ACCESS
value|0x00000002
end_define

begin_comment
comment|/**< Memory can be accessed by QUICC Engine                                              through its secondary bus interface */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_GetBufFunction   @Description   User callback function called by driver to get data buffer.                  User provides this function. Driver invokes it.   @Param[in]     h_BufferPool        - A handle to buffer pool manager  @Param[out]    p_BufContextHandle  - Returns the user's private context that                                       should be associated with the buffer   @Return        Pointer to data buffer, NULL if error  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint8_t
modifier|*
function_decl|(
name|t_GetBufFunction
function_decl|)
parameter_list|(
name|t_Handle
name|h_BufferPool
parameter_list|,
name|t_Handle
modifier|*
name|p_BufContextHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_PutBufFunction   @Description   User callback function called by driver to return data buffer.                  User provides this function. Driver invokes it.   @Param[in]     h_BufferPool    - A handle to buffer pool manager  @Param[in]     p_Buffer        - A pointer to buffer to return  @Param[in]     h_BufContext    - The user's private context associated with                                   the returned buffer   @Return        E_OK on success; Error code otherwise  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|t_Error
function_decl|(
name|t_PutBufFunction
function_decl|)
parameter_list|(
name|t_Handle
name|h_BufferPool
parameter_list|,
name|uint8_t
modifier|*
name|p_Buffer
parameter_list|,
name|t_Handle
name|h_BufContext
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_PhysToVirt   @Description   Translates a physical address to the matching virtual address.   @Param[in]     addr - The physical address to translate.   @Return        Virtual address. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|t_PhysToVirt
parameter_list|(
name|physAddress_t
name|addr
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_VirtToPhys   @Description   Translates a virtual address to the matching physical address.   @Param[in]     addr - The virtual address to translate.   @Return        Physical address. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|physAddress_t
name|t_VirtToPhys
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Buffer Pool Information Structure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_BufferPoolInfo
block|{
name|t_Handle
name|h_BufferPool
decl_stmt|;
comment|/**< A handle to the buffer pool manager */
name|t_GetBufFunction
modifier|*
name|f_GetBuf
decl_stmt|;
comment|/**< User callback to get a free buffer */
name|t_PutBufFunction
modifier|*
name|f_PutBuf
decl_stmt|;
comment|/**< User callback to return a buffer */
name|uint16_t
name|bufferSize
decl_stmt|;
comment|/**< Buffer size (in bytes) */
name|t_PhysToVirt
modifier|*
name|f_PhysToVirt
decl_stmt|;
comment|/**< User callback to translate pool buffers                                              physical addresses to virtual addresses  */
name|t_VirtToPhys
modifier|*
name|f_VirtToPhys
decl_stmt|;
comment|/**< User callback to translate pool buffers                                              virtual addresses to physical addresses */
block|}
name|t_BufferPoolInfo
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   User callback function called by driver when transmit completed.                  User provides this function. Driver invokes it.   @Param[in]     h_App           - Application's handle, as was provided to the                                   driver by the user  @Param[in]     queueId         - Transmit queue ID  @Param[in]     p_Data          - Pointer to the data buffer  @Param[in]     h_BufContext    - The user's private context associated with                                   the given data buffer  @Param[in]     status          - Transmit status and errors  @Param[in]     flags           - Driver-dependent information  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_TxConfFunction
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|uint32_t
name|queueId
parameter_list|,
name|uint8_t
modifier|*
name|p_Data
parameter_list|,
name|t_Handle
name|h_BufContext
parameter_list|,
name|uint16_t
name|status
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   User callback function called by driver with receive data.                  User provides this function. Driver invokes it.   @Param[in]     h_App           - Application's handle, as was provided to the                                   driver by the user  @Param[in]     queueId         - Receive queue ID  @Param[in]     p_Data          - Pointer to the buffer with received data  @Param[in]     h_BufContext    - The user's private context associated with                                   the given data buffer  @Param[in]     length          - Length of received data  @Param[in]     status          - Receive status and errors  @Param[in]     position        - Position of buffer in frame  @Param[in]     flags           - Driver-dependent information   @Retval        e_RX_STORE_RESPONSE_CONTINUE - order the driver to continue Rx                                                operation for all ready data.  @Retval        e_RX_STORE_RESPONSE_PAUSE    - order the driver to stop Rx operation.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|e_RxStoreResponse
function_decl|(
name|t_RxStoreFunction
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|uint32_t
name|queueId
parameter_list|,
name|uint8_t
modifier|*
name|p_Data
parameter_list|,
name|t_Handle
name|h_BufContext
parameter_list|,
name|uint32_t
name|length
parameter_list|,
name|uint16_t
name|status
parameter_list|,
name|uint8_t
name|position
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NCSW_EXT_H */
end_comment

end_unit

