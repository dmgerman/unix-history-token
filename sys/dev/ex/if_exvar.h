begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996, Javier Mart^mn Rueda (jmrueda@diatel.upm.es)  * All rights reserved.  *  * Copyright (c) 2000 Matthew N. Dodd  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_struct
struct|struct
name|ex_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
name|u_char
name|enaddr
index|[
literal|6
index|]
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|ioport
decl_stmt|;
name|int
name|ioport_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|u_short
name|irq_no
decl_stmt|;
comment|/* IRQ number. */
name|char
modifier|*
name|irq2ee
decl_stmt|;
comment|/* irq<-> internal		*/
name|u_char
modifier|*
name|ee2irq
decl_stmt|;
comment|/* representation conversion	*/
name|u_int
name|mem_size
decl_stmt|;
comment|/* Total memory size, in bytes. */
name|u_int
name|rx_mem_size
decl_stmt|;
comment|/* Rx memory size (by default,	*/
comment|/* first 3/4 of total memory).	*/
name|u_int
name|rx_lower_limit
decl_stmt|;
comment|/* Lower and upper limits of	*/
name|u_int
name|rx_upper_limit
decl_stmt|;
comment|/* receive buffer.		*/
name|u_int
name|rx_head
decl_stmt|;
comment|/* Head of receive ring buffer. */
name|u_int
name|tx_mem_size
decl_stmt|;
comment|/* Tx memory size (by default,	*/
comment|/* last quarter of total memory).*/
name|u_int
name|tx_lower_limit
decl_stmt|;
comment|/* Lower and upper limits of	*/
name|u_int
name|tx_upper_limit
decl_stmt|;
comment|/* transmit buffer.		*/
name|u_int
name|tx_head
decl_stmt|;
comment|/* Head and tail of 		*/
name|u_int
name|tx_tail
decl_stmt|;
comment|/* transmit ring buffer.	*/
name|u_int
name|tx_last
decl_stmt|;
comment|/* Pointer to beginning of last	*/
comment|/* frame in the chain.		*/
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|ex_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|irq2eemap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|ee2irqmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|plus_irq2eemap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|plus_ee2irqmap
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ex_alloc_resources
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ex_release_resources
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ex_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ex_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|driver_intr_t
name|ex_intr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|u_int16_t
name|ex_eeprom_read
parameter_list|(
name|struct
name|ex_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ex_get_address
parameter_list|(
name|struct
name|ex_softc
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ex_card_type
parameter_list|(
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ex_stop
parameter_list|(
name|struct
name|ex_softc
modifier|*
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
value|(bus_space_read_1((sc)->bst, (sc)->bsh, off))
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
value|(bus_space_read_2((sc)->bst, (sc)->bsh, off))
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
value|bus_space_write_1((sc)->bst, (sc)->bsh, off, val)
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
value|bus_space_write_2((sc)->bst, (sc)->bsh, off, val)
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
value|bus_space_write_multi_1((sc)->bst, (sc)->bsh, off, addr, count)
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
value|bus_space_write_multi_2((sc)->bst, (sc)->bsh, off, addr, count)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_MULTI_4
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
value|bus_space_write_multi_4((sc)->bst, (sc)->bsh, off, addr, count)
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
value|bus_space_read_multi_1((sc)->bst, (sc)->bsh, off, addr, count)
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
value|bus_space_read_multi_2((sc)->bst, (sc)->bsh, off, addr, count)
end_define

begin_define
define|#
directive|define
name|CSR_READ_MULTI_4
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
value|bus_space_read_multi_4((sc)->bst, (sc)->bsh, off, addr, count)
end_define

begin_define
define|#
directive|define
name|EX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|EX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|EX_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&_sc->sc_mtx, device_get_nameunit(_sc->dev), \ 	    MTX_NETWORK_LOCK, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|EX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&_sc->sc_mtx);
end_define

begin_define
define|#
directive|define
name|EX_ASSERT_LOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&_sc->sc_mtx, MA_OWNED);
end_define

begin_define
define|#
directive|define
name|EX_ASSERT_UNLOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&_sc->sc_mtx, MA_NOTOWNED);
end_define

end_unit

