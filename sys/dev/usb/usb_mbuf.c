begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USB_GLOBAL_INCLUDE_FILE
end_ifdef

begin_include
include|#
directive|include
include|USB_GLOBAL_INCLUDE_FILE
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdi.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_dev.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_mbuf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USB_GLOBAL_INCLUDE_FILE */
end_comment

begin_comment
comment|/*------------------------------------------------------------------------*  *      usb_alloc_mbufs - allocate mbufs to an usbd interface queue  *  * Returns:  *   A pointer that should be passed to "free()" when the buffer(s)  *   should be released.  *------------------------------------------------------------------------*/
end_comment

begin_function
name|void
modifier|*
name|usb_alloc_mbufs
parameter_list|(
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|,
name|struct
name|usb_ifqueue
modifier|*
name|ifq
parameter_list|,
name|usb_size_t
name|block_size
parameter_list|,
name|uint16_t
name|nblocks
parameter_list|)
block|{
name|struct
name|usb_mbuf
modifier|*
name|m_ptr
decl_stmt|;
name|uint8_t
modifier|*
name|data_ptr
decl_stmt|;
name|void
modifier|*
name|free_ptr
init|=
name|NULL
decl_stmt|;
name|usb_size_t
name|alloc_size
decl_stmt|;
comment|/* align data */
name|block_size
operator|+=
operator|(
operator|(
operator|-
name|block_size
operator|)
operator|&
operator|(
name|USB_HOST_ALIGN
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|nblocks
operator|&&
name|block_size
condition|)
block|{
name|alloc_size
operator|=
operator|(
name|block_size
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|usb_mbuf
argument_list|)
operator|)
operator|*
name|nblocks
expr_stmt|;
name|free_ptr
operator|=
name|malloc
argument_list|(
name|alloc_size
argument_list|,
name|type
argument_list|,
name|M_WAITOK
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
if|if
condition|(
name|free_ptr
operator|==
name|NULL
condition|)
block|{
goto|goto
name|done
goto|;
block|}
name|m_ptr
operator|=
name|free_ptr
expr_stmt|;
name|data_ptr
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|m_ptr
operator|+
name|nblocks
operator|)
expr_stmt|;
while|while
condition|(
name|nblocks
operator|--
condition|)
block|{
name|m_ptr
operator|->
name|cur_data_ptr
operator|=
name|m_ptr
operator|->
name|min_data_ptr
operator|=
name|data_ptr
expr_stmt|;
name|m_ptr
operator|->
name|cur_data_len
operator|=
name|m_ptr
operator|->
name|max_data_len
operator|=
name|block_size
expr_stmt|;
name|USB_IF_ENQUEUE
argument_list|(
name|ifq
argument_list|,
name|m_ptr
argument_list|)
expr_stmt|;
name|m_ptr
operator|++
expr_stmt|;
name|data_ptr
operator|+=
name|block_size
expr_stmt|;
block|}
block|}
name|done
label|:
return|return
operator|(
name|free_ptr
operator|)
return|;
block|}
end_function

end_unit

