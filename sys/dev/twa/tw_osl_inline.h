begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-07 Applied Micro Circuits Corporation.  * Copyright (c) 2004-05 Vinod Kashyap.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * AMCC'S 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  * Modifications by: Adam Radford  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TW_OSL_INLINE_H
end_ifndef

begin_define
define|#
directive|define
name|TW_OSL_INLINE_H
end_define

begin_comment
comment|/*  * Inline functions shared between OSL and CL, and defined by OSL.  */
end_comment

begin_include
include|#
directive|include
file|<dev/twa/tw_osl.h>
end_include

begin_comment
comment|/*  * Function name:	tw_osl_init_lock  * Description:		Initializes a lock.  *  * Input:		ctlr_handle	-- ptr to controller handle  *			lock_name	-- string indicating name of the lock  * Output:		lock		-- ptr to handle to the initialized lock  * Return value:	None  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_init_lock
parameter_list|(
name|ctlr_handle
parameter_list|,
name|lock_name
parameter_list|,
name|lock
parameter_list|)
define|\
value|mtx_init(lock, lock_name, NULL, MTX_SPIN)
end_define

begin_comment
comment|/*  * Function name:	tw_osl_destroy_lock  * Description:		Destroys a previously initialized lock.  *  * Input:		ctlr_handle	-- ptr to controller handle  *			lock		-- ptr to handle to the lock to be  *						destroyed  * Output:		None  * Return value:	None  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_destroy_lock
parameter_list|(
name|ctlr_handle
parameter_list|,
name|lock
parameter_list|)
define|\
value|mtx_destroy(lock)
end_define

begin_comment
comment|/*  * Function name:	tw_osl_get_lock  * Description:		Acquires the specified lock.  *  * Input:		ctlr_handle	-- ptr to controller handle  *			lock		-- ptr to handle to the lock to be  *						acquired  * Output:		None  * Return value:	None  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_get_lock
parameter_list|(
name|ctlr_handle
parameter_list|,
name|lock
parameter_list|)
define|\
value|mtx_lock_spin(lock)
end_define

begin_comment
comment|/*  * Function name:	tw_osl_free_lock  * Description:		Frees a previously acquired lock.  *  * Input:		ctlr_handle	-- ptr to controller handle  *			lock		-- ptr to handle to the lock to be freed  * Output:		None  * Return value:	None  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_free_lock
parameter_list|(
name|ctlr_handle
parameter_list|,
name|lock
parameter_list|)
define|\
value|mtx_unlock_spin(lock)
end_define

begin_comment
comment|/*  * Function name:	tw_osl_ctlr_ready  * Description:		CL calls this function to notify the OS Layer that it  *			is ready to accept new requests.  This function is  *			called only if a call to tw_osl_ctlr_busy has been  *			made previously.  We don't use this function as of now.  *  * Input:		ctlr_handle	-- ptr to controller handle  * Output:		None  * Return value:	None  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_ctlr_ready
parameter_list|(
name|ctlr_handle
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
end_ifdef

begin_comment
comment|/*  * Function name:	tw_osl_dbg_printf  * Description:		Prints passed info (prefixed by ctlr name)to syslog  *  * Input:		ctlr_handle -- controller handle  *			fmt -- format string for the arguments to follow  *			... -- variable number of arguments, to be printed  *				based on the fmt string  * Output:		None  * Return value:	Number of bytes printed  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_dbg_printf
parameter_list|(
name|ctlr_handle
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|twa_printf((ctlr_handle->osl_ctlr_ctxt), fmt, ##args)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_DEBUG */
end_comment

begin_comment
comment|/*  * Function name:	tw_osl_notify_event  * Description:		Prints passed event info (prefixed by ctlr name)  *			to syslog  *  * Input:		ctlr_handle -- controller handle  *			event -- ptr to a packet describing the event/error  * Output:		None  * Return value:	None  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_notify_event
parameter_list|(
name|ctlr_handle
parameter_list|,
name|event
parameter_list|)
define|\
value|twa_printf((ctlr_handle->osl_ctlr_ctxt),			\ 		"%s: (0x%02X: 0x%04X): %s: %s\n",			\ 		event->severity_str,					\ 		event->event_src,					\ 		event->aen_code,					\ 		event->parameter_data +					\ 			strlen(event->parameter_data) + 1,		\ 		event->parameter_data)
end_define

begin_comment
comment|/*  * Function name:	tw_osl_read_reg  * Description:		Reads a register on the controller  *  * Input:		ctlr_handle -- controller handle  *			offset -- offset from Base Address  *			size -- # of bytes to read  * Output:		None  * Return value:	Value read  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_read_reg
value|tw_osl_read_reg_inline
end_define

begin_function
specifier|static
name|__inline
name|TW_UINT32
name|tw_osl_read_reg_inline
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_INT32
name|offset
parameter_list|,
name|TW_INT32
name|size
parameter_list|)
block|{
name|bus_space_tag_t
name|bus_tag
init|=
operator|(
operator|(
expr|struct
name|twa_softc
operator|*
operator|)
operator|(
name|ctlr_handle
operator|->
name|osl_ctlr_ctxt
operator|)
operator|)
operator|->
name|bus_tag
decl_stmt|;
name|bus_space_handle_t
name|bus_handle
init|=
operator|(
operator|(
expr|struct
name|twa_softc
operator|*
operator|)
operator|(
name|ctlr_handle
operator|->
name|osl_ctlr_ctxt
operator|)
operator|)
operator|->
name|bus_handle
decl_stmt|;
if|if
condition|(
name|size
operator|==
literal|4
condition|)
return|return
operator|(
operator|(
name|TW_UINT32
operator|)
name|bus_space_read_4
argument_list|(
name|bus_tag
argument_list|,
name|bus_handle
argument_list|,
name|offset
argument_list|)
operator|)
return|;
elseif|else
if|if
condition|(
name|size
operator|==
literal|2
condition|)
return|return
operator|(
operator|(
name|TW_UINT32
operator|)
name|bus_space_read_2
argument_list|(
name|bus_tag
argument_list|,
name|bus_handle
argument_list|,
name|offset
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
operator|(
name|TW_UINT32
operator|)
name|bus_space_read_1
argument_list|(
name|bus_tag
argument_list|,
name|bus_handle
argument_list|,
name|offset
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Function name:	tw_osl_write_reg  * Description:		Writes to a register on the controller  *  * Input:		ctlr_handle -- controller handle  *			offset -- offset from Base Address  *			value -- value to write  *			size -- # of bytes to write  * Output:		None  * Return value:	None  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_write_reg
value|tw_osl_write_reg_inline
end_define

begin_function
specifier|static
name|__inline
name|TW_VOID
name|tw_osl_write_reg_inline
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_INT32
name|offset
parameter_list|,
name|TW_INT32
name|value
parameter_list|,
name|TW_INT32
name|size
parameter_list|)
block|{
name|bus_space_tag_t
name|bus_tag
init|=
operator|(
operator|(
expr|struct
name|twa_softc
operator|*
operator|)
operator|(
name|ctlr_handle
operator|->
name|osl_ctlr_ctxt
operator|)
operator|)
operator|->
name|bus_tag
decl_stmt|;
name|bus_space_handle_t
name|bus_handle
init|=
operator|(
operator|(
expr|struct
name|twa_softc
operator|*
operator|)
operator|(
name|ctlr_handle
operator|->
name|osl_ctlr_ctxt
operator|)
operator|)
operator|->
name|bus_handle
decl_stmt|;
if|if
condition|(
name|size
operator|==
literal|4
condition|)
name|bus_space_write_4
argument_list|(
name|bus_tag
argument_list|,
name|bus_handle
argument_list|,
name|offset
argument_list|,
name|value
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|size
operator|==
literal|2
condition|)
name|bus_space_write_2
argument_list|(
name|bus_tag
argument_list|,
name|bus_handle
argument_list|,
name|offset
argument_list|,
operator|(
name|TW_INT16
operator|)
name|value
argument_list|)
expr_stmt|;
else|else
name|bus_space_write_1
argument_list|(
name|bus_tag
argument_list|,
name|bus_handle
argument_list|,
name|offset
argument_list|,
operator|(
name|TW_INT8
operator|)
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_PCI_CONFIG_ACCESSIBLE
end_ifdef

begin_comment
comment|/*  * Function name:	tw_osl_read_pci_config  * Description:		Reads from the PCI config space.  *  * Input:		sc	-- ptr to per ctlr structure  *			offset	-- register offset  *			size	-- # of bytes to be read  * Output:		None  * Return value:	Value read  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_read_pci_config
parameter_list|(
name|ctlr_handle
parameter_list|,
name|offset
parameter_list|,
name|size
parameter_list|)
define|\
value|pci_read_config(						\ 		((struct twa_softc *)(ctlr_handle->osl_ctlr_ctxt))->bus_dev, \ 		offset, size)
end_define

begin_comment
comment|/*  * Function name:	tw_osl_write_pci_config  * Description:		Writes to the PCI config space.  *  * Input:		sc	-- ptr to per ctlr structure  *			offset	-- register offset  *			value	-- value to write  *			size	-- # of bytes to be written  * Output:		None  * Return value:	None  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_write_pci_config
parameter_list|(
name|ctlr_handle
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|,
name|size
parameter_list|)
define|\
value|pci_write_config(						\ 		((struct twa_softc *)(ctlr_handle->osl_ctlr_ctxt))->bus_dev, \ 		offset
comment|/*PCIR_STATUS*/
value|, value, size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_PCI_CONFIG_ACCESSIBLE */
end_comment

begin_comment
comment|/*  * Function name:	tw_osl_get_local_time  * Description:		Gets the local time  *  * Input:		None  * Output:		None  * Return value:	local time  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_get_local_time
parameter_list|()
define|\
value|(time_second - utc_offset())
end_define

begin_comment
comment|/*  * Function name:	tw_osl_delay  * Description:		Spin for the specified time  *  * Input:		usecs -- micro-seconds to spin  * Output:		None  * Return value:	None  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_delay
parameter_list|(
name|usecs
parameter_list|)
value|DELAY(usecs)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_CAN_SLEEP
end_ifdef

begin_comment
comment|/*  * Function name:	tw_osl_sleep  * Description:		Sleep for the specified time, or until woken up  *  * Input:		ctlr_handle -- controller handle  *			sleep_handle -- handle to sleep on  *			timeout -- time period (in ms) to sleep  * Output:		None  * Return value:	0 -- successfully woken up  *			EWOULDBLOCK -- time out  *			ERESTART -- woken up by a signal  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_sleep
parameter_list|(
name|ctlr_handle
parameter_list|,
name|sleep_handle
parameter_list|,
name|timeout
parameter_list|)
define|\
value|tsleep((TW_VOID *)sleep_handle, PRIBIO, NULL, timeout)
end_define

begin_comment
comment|/*  * Function name:	tw_osl_wakeup  * Description:		Wake up a sleeping process  *  * Input:		ctlr_handle -- controller handle  *			sleep_handle -- handle of sleeping process to be 					woken up  * Output:		None  * Return value:	None  */
end_comment

begin_define
define|#
directive|define
name|tw_osl_wakeup
parameter_list|(
name|ctlr_handle
parameter_list|,
name|sleep_handle
parameter_list|)
define|\
value|wakeup_one(sleep_handle)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_CAN_SLEEP */
end_comment

begin_comment
comment|/* Allows setting breakpoints in the CL code for debugging purposes. */
end_comment

begin_define
define|#
directive|define
name|tw_osl_breakpoint
parameter_list|()
value|breakpoint()
end_define

begin_comment
comment|/* Text name of current function. */
end_comment

begin_define
define|#
directive|define
name|tw_osl_cur_func
parameter_list|()
value|__func__
end_define

begin_comment
comment|/* Copy 'size' bytes from 'src' to 'dest'. */
end_comment

begin_define
define|#
directive|define
name|tw_osl_memcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|size
parameter_list|)
value|bcopy(src, dest, size)
end_define

begin_comment
comment|/* Zero 'size' bytes starting at 'addr'. */
end_comment

begin_define
define|#
directive|define
name|tw_osl_memzero
value|bzero
end_define

begin_comment
comment|/* Standard sprintf. */
end_comment

begin_define
define|#
directive|define
name|tw_osl_sprintf
value|sprintf
end_define

begin_comment
comment|/* Copy string 'src' to 'dest'. */
end_comment

begin_define
define|#
directive|define
name|tw_osl_strcpy
value|strcpy
end_define

begin_comment
comment|/* Return length of string pointed at by 'str'. */
end_comment

begin_define
define|#
directive|define
name|tw_osl_strlen
value|strlen
end_define

begin_comment
comment|/* Standard vsprintf. */
end_comment

begin_define
define|#
directive|define
name|tw_osl_vsprintf
value|vsprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_INLINE_H */
end_comment

end_unit

