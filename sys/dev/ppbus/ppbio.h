begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPBIO_H
end_ifndef

begin_define
define|#
directive|define
name|__PPBIO_H
end_define

begin_comment
comment|/*  * Set of ppbus i/o routines callable from ppbus device drivers  */
end_comment

begin_define
define|#
directive|define
name|ppb_outsb_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_OUTSB_EPP, buf, cnt, 0))
end_define

begin_define
define|#
directive|define
name|ppb_outsw_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_OUTSW_EPP, buf, cnt, 0))
end_define

begin_define
define|#
directive|define
name|ppb_outsl_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_OUTSL_EPP, buf, cnt, 0))
end_define

begin_define
define|#
directive|define
name|ppb_insb_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_INSB_EPP, buf, cnt, 0))
end_define

begin_define
define|#
directive|define
name|ppb_insw_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_INSW_EPP, buf, cnt, 0))
end_define

begin_define
define|#
directive|define
name|ppb_insl_epp
parameter_list|(
name|dev
parameter_list|,
name|buf
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_INSL_EPP, buf, cnt, 0))
end_define

begin_define
define|#
directive|define
name|ppb_repp_A
parameter_list|(
name|dev
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_REPP_A, 0, 0, 0))
end_define

begin_define
define|#
directive|define
name|ppb_repp_D
parameter_list|(
name|dev
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_REPP_D, 0, 0, 0))
end_define

begin_define
define|#
directive|define
name|ppb_recr
parameter_list|(
name|dev
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_RECR, 0, 0, 0))
end_define

begin_define
define|#
directive|define
name|ppb_rfifo
parameter_list|(
name|dev
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_RFIFO, 0, 0, 0))
end_define

begin_define
define|#
directive|define
name|ppb_wepp_A
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_WEPP_A, 0, 0, byte))
end_define

begin_define
define|#
directive|define
name|ppb_wepp_D
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_WEPP_D, 0, 0, byte))
end_define

begin_define
define|#
directive|define
name|ppb_wecr
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_WECR, 0, 0, byte))
end_define

begin_define
define|#
directive|define
name|ppb_wfifo
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_WFIFO, 0, 0, byte))
end_define

begin_define
define|#
directive|define
name|ppb_rdtr
parameter_list|(
name|dev
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_RDTR, 0, 0, 0))
end_define

begin_define
define|#
directive|define
name|ppb_rstr
parameter_list|(
name|dev
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_RSTR, 0, 0, 0))
end_define

begin_define
define|#
directive|define
name|ppb_rctr
parameter_list|(
name|dev
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_RCTR, 0, 0, 0))
end_define

begin_define
define|#
directive|define
name|ppb_wdtr
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_WDTR, 0, 0, byte))
end_define

begin_define
define|#
directive|define
name|ppb_wstr
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_WSTR, 0, 0, byte))
end_define

begin_define
define|#
directive|define
name|ppb_wctr
parameter_list|(
name|dev
parameter_list|,
name|byte
parameter_list|)
define|\
value|(PPBUS_IO(device_get_parent(dev), PPB_WCTR, 0, 0, byte))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

