begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, 2000 Dave Boyce. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *      i4b_iwic - isdn4bsd Winbond W6692 driver  *      ----------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Sun Jan 21 11:08:44 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_IWIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_IWIC_H_
end_define

begin_include
include|#
directive|include
file|<i4b/layer1/iwic/i4b_iwic_ext.h>
end_include

begin_comment
comment|/*---------------------------------------------------------------------------*  *	PCI resources used  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|INFO_IO_BASES
value|2
end_define

begin_struct
struct|struct
name|i4b_info
block|{
name|struct
name|resource
modifier|*
name|io_base
index|[
name|INFO_IO_BASES
index|]
decl_stmt|;
name|int
name|io_rid
index|[
name|INFO_IO_BASES
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
name|int
name|mem_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------------------------------------------------------*  *	state of a B channel   *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|iwic_bchan
block|{
name|int
name|unit
decl_stmt|;
comment|/* unit number		*/
name|int
name|channel
decl_stmt|;
comment|/* channel number	*/
name|int
name|offset
decl_stmt|;
comment|/* offset from iobase	*/
name|int
name|bprot
decl_stmt|;
comment|/* b channel protocol used */
name|int
name|state
decl_stmt|;
comment|/* transceiver state:	*/
define|#
directive|define
name|ST_IDLE
value|0x00
comment|/* channel idle		*/
define|#
directive|define
name|ST_TX_ACTIVE
value|0x01
comment|/* tx running		*/
name|int
name|sc_trace_bcount
decl_stmt|;
comment|/* receive data from ISDN */
name|struct
name|ifqueue
name|rx_queue
decl_stmt|;
comment|/* receiver queue	*/
name|int
name|rxcount
decl_stmt|;
comment|/* rx statistics counter*/
name|struct
name|mbuf
modifier|*
name|in_mbuf
decl_stmt|;
comment|/* rx input buffer	*/
name|u_char
modifier|*
name|in_cbptr
decl_stmt|;
comment|/* curr buffer pointer	*/
name|int
name|in_len
decl_stmt|;
comment|/* rx input buffer len	*/
comment|/* transmit data to ISDN */
name|struct
name|ifqueue
name|tx_queue
decl_stmt|;
comment|/* transmitter queue		*/
name|int
name|txcount
decl_stmt|;
comment|/* tx statistics counter	*/
name|struct
name|mbuf
modifier|*
name|out_mbuf_head
decl_stmt|;
comment|/* first mbuf in possible chain */
name|struct
name|mbuf
modifier|*
name|out_mbuf_cur
decl_stmt|;
comment|/* current mbuf in possbl chain */
name|unsigned
name|char
modifier|*
name|out_mbuf_cur_ptr
decl_stmt|;
comment|/* data pointer into mbuf    */
name|int
name|out_mbuf_cur_len
decl_stmt|;
comment|/* remaining bytes in mbuf    */
comment|/* linktab */
name|isdn_link_t
name|iwic_isdn_linktab
decl_stmt|;
name|drvr_link_t
modifier|*
name|iwic_drvr_linktab
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------------------------------------------------------*  *	state of a D channel  *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|iwic_dchan
block|{
name|int
name|enabled
decl_stmt|;
name|int
name|trace_count
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ibuf
decl_stmt|;
name|u_char
modifier|*
name|ibuf_ptr
decl_stmt|;
comment|/* Input buffer pointer */
name|int
name|ibuf_len
decl_stmt|;
comment|/* Current length of input buffer */
name|int
name|ibuf_max_len
decl_stmt|;
comment|/* Max length in input buffer */
name|int
name|rx_count
decl_stmt|;
name|int
name|tx_ready
decl_stmt|;
comment|/* Can send next 64 bytes of data. */
name|int
name|tx_count
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|obuf
decl_stmt|;
name|int
name|free_obuf
decl_stmt|;
name|u_char
modifier|*
name|obuf_ptr
decl_stmt|;
name|int
name|obuf_len
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|obuf2
decl_stmt|;
name|int
name|free_obuf2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------------------------------------------------------*  *	state of one iwic unit  *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|iwic_softc
block|{
name|int
name|sc_unit
decl_stmt|;
name|u_int32_t
name|sc_iobase
decl_stmt|;
name|int
name|sc_trace
decl_stmt|;
name|int
name|sc_cardtyp
decl_stmt|;
name|int
name|sc_I430state
decl_stmt|;
name|int
name|sc_I430T3
decl_stmt|;
name|int
name|enabled
decl_stmt|;
name|struct
name|iwic_dchan
name|sc_dchan
decl_stmt|;
name|struct
name|iwic_bchan
name|sc_bchan
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|i4b_info
name|sc_resources
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------------------------------------------------------*  *	rd/wr register/fifo macros  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|IWIC_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|(inb   ((sc)->sc_iobase + (u_int32_t)(reg)))
end_define

begin_define
define|#
directive|define
name|IWIC_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|(outb  ((sc)->sc_iobase + (u_int32_t)(reg), (val)))
end_define

begin_define
define|#
directive|define
name|IWIC_WRDFIFO
parameter_list|(
name|sc
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|(outsb ((sc)->sc_iobase + D_XFIFO, (p), (l)))
end_define

begin_define
define|#
directive|define
name|IWIC_RDDFIFO
parameter_list|(
name|sc
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|(insb  ((sc)->sc_iobase + D_RFIFO, (p), (l)))
end_define

begin_define
define|#
directive|define
name|IWIC_WRBFIFO
parameter_list|(
name|sc
parameter_list|,
name|b
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|(outsb (((sc)->sc_iobase + (b)->offset + B_XFIFO), (p), (l)))
end_define

begin_define
define|#
directive|define
name|IWIC_RDBFIFO
parameter_list|(
name|sc
parameter_list|,
name|b
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|(insb  (((sc)->sc_iobase + (b)->offset + B_RFIFO), (p), (l)))
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	possible I.430 states  *---------------------------------------------------------------------------*/
end_comment

begin_enum
enum|enum
name|I430states
block|{
name|ST_F3N
block|,
comment|/* F3 Deactivated, no clock	*/
name|ST_F3
block|,
comment|/* F3 Deactivated		*/
name|ST_F4
block|,
comment|/* F4 Awaiting Signal		*/
name|ST_F5
block|,
comment|/* F5 Identifying Input		*/
name|ST_F6
block|,
comment|/* F6 Synchronized		*/
name|ST_F7
block|,
comment|/* F7 Activated			*/
name|ST_F8
block|,
comment|/* F8 Lost Framing		*/
name|ST_ILL
block|,
comment|/* Illegal State		*/
name|N_STATES
block|}
enum|;
end_enum

begin_comment
comment|/*---------------------------------------------------------------------------*  *	possible I.430 events  *---------------------------------------------------------------------------*/
end_comment

begin_enum
enum|enum
name|I430events
block|{
name|EV_PHAR
block|,
comment|/* PH ACTIVATE REQUEST          */
name|EV_CE
block|,
comment|/* Clock enabled                */
name|EV_T3
block|,
comment|/* Timer 3 expired              */
name|EV_INFO0
block|,
comment|/* receiving INFO0              */
name|EV_RSY
block|,
comment|/* receiving any signal         */
name|EV_INFO2
block|,
comment|/* receiving INFO2              */
name|EV_INFO48
block|,
comment|/* receiving INFO4 pri 8/9      */
name|EV_INFO410
block|,
comment|/* receiving INFO4 pri 10/11    */
name|EV_DR
block|,
comment|/* Deactivate Request           */
name|EV_PU
block|,
comment|/* Power UP                     */
name|EV_DIS
block|,
comment|/* Disconnected (only 2085)     */
name|EV_EI
block|,
comment|/* Error Indication             */
name|EV_ILL
block|,
comment|/* Illegal Event                */
name|N_EVENTS
block|}
enum|;
end_enum

begin_comment
comment|/*---------------------------------------------------------------------------*  *	available commands  *---------------------------------------------------------------------------*/
end_comment

begin_enum
enum|enum
name|I430commands
block|{
name|CMD_ECK
block|,
comment|/* Enable clock			*/
name|CMD_TIM
block|,
comment|/* Timing			*/
name|CMD_RT
block|,
comment|/* Reset			*/
name|CMD_AR8
block|,
comment|/* Activation request pri 8	*/
name|CMD_AR10
block|,
comment|/* Activation request pri 10	*/
name|CMD_DIU
block|,
comment|/* Deactivate Indication Upstream */
name|CMD_ILL
comment|/* Illegal command		*/
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|struct
name|iwic_softc
name|iwic_sc
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|iwic_find_sc
parameter_list|(
name|unit
parameter_list|)
value|(&iwic_sc[(unit)])
end_define

begin_function_decl
specifier|extern
name|void
name|iwic_init
parameter_list|(
name|struct
name|iwic_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iwic_next_state
parameter_list|(
name|struct
name|iwic_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iwic_dchan_init
parameter_list|(
name|struct
name|iwic_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iwic_dchan_xirq
parameter_list|(
name|struct
name|iwic_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iwic_dchan_xfer_irq
parameter_list|(
name|struct
name|iwic_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iwic_dchan_disable
parameter_list|(
name|struct
name|iwic_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iwic_dchan_data_req
parameter_list|(
name|struct
name|iwic_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|freeflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iwic_dchan_transmit
parameter_list|(
name|struct
name|iwic_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|iwic_printstate
parameter_list|(
name|struct
name|iwic_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iwic_init_linktab
parameter_list|(
name|struct
name|iwic_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iwic_bchan_xirq
parameter_list|(
name|struct
name|iwic_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iwic_bchannel_setup
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|h_chan
parameter_list|,
name|int
name|bprot
parameter_list|,
name|int
name|activate
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_IWIC_H_ */
end_comment

end_unit

