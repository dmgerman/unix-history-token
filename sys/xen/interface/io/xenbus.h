begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*****************************************************************************  * xenbus.h  *  * Xenbus protocol details.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (C) 2005 XenSource Ltd.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_PUBLIC_IO_XENBUS_H
end_ifndef

begin_define
define|#
directive|define
name|_XEN_PUBLIC_IO_XENBUS_H
end_define

begin_comment
comment|/*  * The state of either end of the Xenbus, i.e. the current communication  * status of initialisation across the bus.  States here imply nothing about  * the state of the connection between the driver and the kernel's device  * layers.  */
end_comment

begin_enum
enum|enum
name|xenbus_state
block|{
name|XenbusStateUnknown
init|=
literal|0
block|,
name|XenbusStateInitialising
init|=
literal|1
block|,
comment|/*      * InitWait: Finished early initialisation but waiting for information      * from the peer or hotplug scripts.      */
name|XenbusStateInitWait
init|=
literal|2
block|,
comment|/*      * Initialised: Waiting for a connection from the peer.      */
name|XenbusStateInitialised
init|=
literal|3
block|,
name|XenbusStateConnected
init|=
literal|4
block|,
comment|/*      * Closing: The device is being closed due to an error or an unplug event.      */
name|XenbusStateClosing
init|=
literal|5
block|,
name|XenbusStateClosed
init|=
literal|6
block|,
comment|/*      * Reconfiguring: The device is being reconfigured.      */
name|XenbusStateReconfiguring
init|=
literal|7
block|,
name|XenbusStateReconfigured
init|=
literal|8
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|xenbus_state
name|XenbusState
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_PUBLIC_IO_XENBUS_H */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

