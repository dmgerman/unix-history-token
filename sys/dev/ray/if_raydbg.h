begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000  * Dr. Duncan McLennan Barclay, dmlb@ragnet.demon.co.uk.  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY DUNCAN BARCLAY AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL DUNCAN BARCLAY OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Debugging odds and odds  */
end_comment

begin_comment
comment|/*  * RAY_DEBUG settings  *  *	AUTH		Authentication  *	SUBR		Subroutine entry  *	BOOTPARAM	Startup CM dump  *	STARTJOIN	State transitions for start/join  *	CCS		CCS info  *	IOCTL		IOCTL calls  *	MBUF		MBUFs dumped - needs one of TX, RX, MGT, or CTL  *	RX		packet types reported  *	CM		common memory re-mapping  *	COM		new command sleep/wakeup  *	STOP		driver detaching  *	CTL		CTL packets  *	MGT		MGT packets  *	TX		TX routine info  *	DCOM		dump comq entries  */
end_comment

begin_define
define|#
directive|define
name|RAY_DBG_AUTH
value|0x0001
end_define

begin_define
define|#
directive|define
name|RAY_DBG_SUBR
value|0x0002
end_define

begin_define
define|#
directive|define
name|RAY_DBG_BOOTPARAM
value|0x0004
end_define

begin_define
define|#
directive|define
name|RAY_DBG_STARTJOIN
value|0x0008
end_define

begin_define
define|#
directive|define
name|RAY_DBG_CCS
value|0x0010
end_define

begin_define
define|#
directive|define
name|RAY_DBG_IOCTL
value|0x0020
end_define

begin_define
define|#
directive|define
name|RAY_DBG_MBUF
value|0x0080
end_define

begin_define
define|#
directive|define
name|RAY_DBG_RX
value|0x0100
end_define

begin_define
define|#
directive|define
name|RAY_DBG_CM
value|0x0200
end_define

begin_define
define|#
directive|define
name|RAY_DBG_COM
value|0x0400
end_define

begin_define
define|#
directive|define
name|RAY_DBG_STOP
value|0x0800
end_define

begin_define
define|#
directive|define
name|RAY_DBG_CTL
value|0x1000
end_define

begin_define
define|#
directive|define
name|RAY_DBG_MGT
value|0x2000
end_define

begin_define
define|#
directive|define
name|RAY_DBG_TX
value|0x4000
end_define

begin_define
define|#
directive|define
name|RAY_DBG_DCOM
value|0x8000
end_define

begin_comment
comment|/* Cut and paste this into a kernel configuration file */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|RAY_DEBUG
value|(				\
comment|/* RAY_DBG_SUBR		| */
value|\
comment|/* RAY_DBG_BOOTPARAM	| */
value|\
comment|/* RAY_DBG_STARTJOIN	| */
value|\
comment|/* RAY_DBG_CCS		| */
value|\
comment|/* RAY_DBG_IOCTL	| */
value|\
comment|/* RAY_DBG_MBUF		| */
value|\
comment|/* RAY_DBG_RX		| */
value|\
comment|/* RAY_DBG_CM		| */
value|\
comment|/* RAY_DBG_COM		| */
value|\
comment|/* RAY_DBG_STOP		| */
value|\
comment|/* RAY_DBG_CTL		| */
value|\
comment|/* RAY_DBG_MGT		| */
value|\
comment|/* RAY_DBG_TX		| */
value|\
comment|/* RAY_DBG_DCOM		| */
value|\ 			0				\ 			)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|RAY_DEBUG
end_if

begin_define
define|#
directive|define
name|RAY_DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {if (RAY_DEBUG& (mask)) {\     device_printf((sc)->dev, "%s(%d) " fmt "\n",			\     	__FUNCTION__ , __LINE__ , ##args);				\ } } while (0)
end_define

begin_comment
comment|/* This macro assumes that common memory is mapped into kernel space */
end_comment

begin_define
define|#
directive|define
name|RAY_DHEX8
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|,
name|off
parameter_list|,
name|len
parameter_list|,
name|s
parameter_list|)
value|do { if (RAY_DEBUG& (mask)) {	\     int i, j;								\     device_printf((sc)->dev, "%s(%d) %s\n",				\     	__FUNCTION__ , __LINE__ , (s));					\     for (i = (off); i< (off)+(len); i += 8) {				\ 	    printf(".  0x%04x ", i);					\ 	    for (j = 0; j< 8; j++)					\ 		    printf("%02x ", SRAM_READ_1((sc), i+j));		\ 	    printf("\n");						\     }									\ } } while (0)
end_define

begin_define
define|#
directive|define
name|RAY_DCOM
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|,
name|com
parameter_list|,
name|s
parameter_list|)
value|do { if (RAY_DEBUG& (mask)) {	\     device_printf((sc)->dev, "%s(%d) %s com entry 0x%p\n",		\         __FUNCTION__ , __LINE__ , (s) , (com));				\     printf(".  c_mesg %s\n", (com)->c_mesg);				\     printf(".  c_flags 0x%b\n", (com)->c_flags, RAY_COM_FLAGS_PRINTFB);	\     printf(".  c_retval 0x%x\n", (com)->c_retval);			\     printf(".  c_ccs 0x%0x index 0x%02x\n",				\         (com)->c_ccs, RAY_CCS_INDEX((com)->c_ccs));			\ } } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RAY_DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RAY_DHEX8
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|,
name|off
parameter_list|,
name|len
parameter_list|,
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RAY_DCOM
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|,
name|com
parameter_list|,
name|s
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RAY_DEBUG> 0 */
end_comment

begin_comment
comment|/*  * These override macros defined in if_ray.c to turn them into  * debugging ones.  */
end_comment

begin_if
if|#
directive|if
name|RAY_DEBUG
end_if

begin_define
define|#
directive|define
name|RAY_RECERR
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {				\     device_printf((sc)->dev, "%s(%d) " fmt "\n",			\ 	__FUNCTION__ , __LINE__ , ##args);				\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RAY_DEBUG */
end_comment

begin_if
if|#
directive|if
name|RAY_DEBUG
operator|&
name|RAY_DBG_COM
end_if

begin_define
define|#
directive|define
name|RAY_COM_CHECK
parameter_list|(
name|sc
parameter_list|,
name|com
parameter_list|)
value|do { if (RAY_DEBUG& RAY_DBG_COM) {	\     ray_com_ecf_check((sc), (com), __FUNCTION__ );			\ } } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RAY_DEBUG& RAY_DBG_COM */
end_comment

begin_if
if|#
directive|if
name|RAY_DEBUG
operator|&
name|RAY_DBG_MBUF
end_if

begin_define
define|#
directive|define
name|RAY_MBUF_DUMP
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
value|do { if (RAY_DEBUG& (mask)) {	\     ray_dump_mbuf((sc), (m), (s));					\ } } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RAY_DEBUG& RAY_DBG_MBUF */
end_comment

end_unit

