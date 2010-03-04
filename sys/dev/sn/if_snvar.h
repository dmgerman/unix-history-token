begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 M. Warner Losh<imp@village.org>   * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_SNVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_SNVAR_H
end_define

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_struct
struct|struct
name|sn_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|callout
name|watchdog
decl_stmt|;
name|int
name|timer
decl_stmt|;
name|int
name|pages_wanted
decl_stmt|;
comment|/* Size of outstanding MMU ALLOC */
name|int
name|intr_mask
decl_stmt|;
comment|/* Most recently set interrupt mask */
name|device_t
name|dev
decl_stmt|;
name|void
modifier|*
name|intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|port_res
decl_stmt|;
name|int
name|port_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|modem_res
decl_stmt|;
comment|/* Extra resource for modem */
name|int
name|modem_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|sn_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sn_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sn_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sn_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sn_activate
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sn_deactivate
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
value|(bus_read_1((sc)->port_res, off))
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
value|(bus_read_2((sc)->port_res, off))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_1((sc)->port_res, off, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_2((sc)->port_res, off, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_MULTI_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_write_multi_1((sc)->port_res, off, addr, count)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_MULTI_2
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_write_multi_2((sc)->port_res, off, addr, count)
end_define

begin_define
define|#
directive|define
name|CSR_READ_MULTI_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_read_multi_1((sc)->port_res, off, addr, count)
end_define

begin_define
define|#
directive|define
name|CSR_READ_MULTI_2
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_read_multi_2((sc)->port_res, off, addr, count)
end_define

begin_define
define|#
directive|define
name|SN_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|SN_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|SN_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&_sc->sc_mtx, device_get_nameunit(_sc->dev), \ 	    MTX_NETWORK_LOCK, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|SN_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&_sc->sc_mtx);
end_define

begin_define
define|#
directive|define
name|SN_ASSERT_LOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&_sc->sc_mtx, MA_OWNED);
end_define

begin_define
define|#
directive|define
name|SN_ASSERT_UNLOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&_sc->sc_mtx, MA_NOTOWNED);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_SNVAR_H */
end_comment

end_unit

