begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * evtchn.h  *   * Data structures and definitions private to the FreeBSD implementation  * of the Xen event channel API.  *   * Copyright (c) 2004, K A Fraser  * Copyright (c) 2012, Spectra Logic Corporation  *  * This file may be distributed separately from the Linux kernel, or  * incorporated into other software packages, subject to the following license:  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_EVTCHN_EVTCHNVAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_EVTCHN_EVTCHNVAR_H__
end_define

begin_include
include|#
directive|include
file|<xen/hypervisor.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/event_channel.h>
end_include

begin_enum
enum|enum
name|evtchn_type
block|{
name|EVTCHN_TYPE_UNBOUND
block|,
name|EVTCHN_TYPE_PIRQ
block|,
name|EVTCHN_TYPE_VIRQ
block|,
name|EVTCHN_TYPE_IPI
block|,
name|EVTCHN_TYPE_PORT
block|,
name|EVTCHN_TYPE_COUNT
block|}
enum|;
end_enum

begin_comment
comment|/** Submit a port notification for delivery to a userland evtchn consumer */
end_comment

begin_function_decl
name|void
name|evtchn_device_upcall
parameter_list|(
name|evtchn_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Disable signal delivery for an event channel port, returning its  * previous mask state.  *  * \param port  The event channel port to query and mask.  *  * \returns  1 if event delivery was previously disabled.  Otherwise 0.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|evtchn_test_and_set_mask
parameter_list|(
name|evtchn_port_t
name|port
parameter_list|)
block|{
name|shared_info_t
modifier|*
name|s
init|=
name|HYPERVISOR_shared_info
decl_stmt|;
return|return
name|synch_test_and_set_bit
argument_list|(
name|port
argument_list|,
name|s
operator|->
name|evtchn_mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Clear any pending event for the given event channel port.  *  * \param port  The event channel port to clear.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|evtchn_clear_port
parameter_list|(
name|evtchn_port_t
name|port
parameter_list|)
block|{
name|shared_info_t
modifier|*
name|s
init|=
name|HYPERVISOR_shared_info
decl_stmt|;
name|synch_clear_bit
argument_list|(
name|port
argument_list|,
operator|&
name|s
operator|->
name|evtchn_pending
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Disable signal delivery for an event channel port.  *  * \param port  The event channel port to mask.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|evtchn_mask_port
parameter_list|(
name|evtchn_port_t
name|port
parameter_list|)
block|{
name|shared_info_t
modifier|*
name|s
init|=
name|HYPERVISOR_shared_info
decl_stmt|;
name|synch_set_bit
argument_list|(
name|port
argument_list|,
operator|&
name|s
operator|->
name|evtchn_mask
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Enable signal delivery for an event channel port.  *  * \param port  The event channel port to enable.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|evtchn_unmask_port
parameter_list|(
name|evtchn_port_t
name|port
parameter_list|)
block|{
name|evtchn_unmask_t
name|op
init|=
block|{
operator|.
name|port
operator|=
name|port
block|}
decl_stmt|;
name|HYPERVISOR_event_channel_op
argument_list|(
name|EVTCHNOP_unmask
argument_list|,
operator|&
name|op
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_EVTCHN_EVTCHNVAR_H__ */
end_comment

end_unit

