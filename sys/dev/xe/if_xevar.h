begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Scott Mitchell  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: if_xe.c,v 1.20 1999/06/13 19:17:40 scott Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_XE_IF_XEDEV_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_XE_IF_XEDEV_H
end_define

begin_comment
comment|/*  * One of these structures per allocated device  */
end_comment

begin_struct
struct|struct
name|xe_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
name|struct
name|ifmib_iso_8802_3
name|mibdata
decl_stmt|;
name|struct
name|callout_handle
name|chand
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|ifmedia
modifier|*
name|ifm
decl_stmt|;
name|char
modifier|*
name|card_type
decl_stmt|;
comment|/* Card model name */
name|char
modifier|*
name|vendor
decl_stmt|;
comment|/* Card manufacturer */
name|device_t
name|dev
decl_stmt|;
comment|/* Device */
name|bus_space_tag_t
name|bst
decl_stmt|;
comment|/* Bus space tag for card */
name|bus_space_handle_t
name|bsh
decl_stmt|;
comment|/* Bus space handle for card */
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
name|int
name|srev
decl_stmt|;
comment|/* Silicon revision */
name|int
name|tx_queued
decl_stmt|;
comment|/* Packets currently waiting to transmit */
name|int
name|tx_tpr
decl_stmt|;
comment|/* Last value of TPR reg on card */
name|int
name|tx_collisions
decl_stmt|;
comment|/* Collisions since last successful send */
name|int
name|tx_timeouts
decl_stmt|;
comment|/* Count of transmit timeouts */
name|int
name|autoneg_status
decl_stmt|;
comment|/* Autonegotiation progress state */
name|int
name|media
decl_stmt|;
comment|/* Private media word */
name|u_char
name|version
decl_stmt|;
comment|/* Bonding Version register from card */
name|u_char
name|modem
decl_stmt|;
comment|/* 1 = Card has a modem */
name|u_char
name|ce2
decl_stmt|;
comment|/* 1 = Card has CE2 silicon */
name|u_char
name|mohawk
decl_stmt|;
comment|/* 1 = Card has Mohawk (CE3) silicon */
name|u_char
name|dingo
decl_stmt|;
comment|/* 1 = Card has Dingo (CEM56) silicon */
name|u_char
name|phy_ok
decl_stmt|;
comment|/* 1 = MII-compliant PHY found and initialised */
name|u_char
name|gone
decl_stmt|;
comment|/* 1 = Card bailed out */
block|}
struct|;
end_struct

begin_comment
comment|/*  * For accessing card registers  */
end_comment

begin_define
define|#
directive|define
name|XE_INB
parameter_list|(
name|r
parameter_list|)
value|bus_space_read_1(scp->bst, scp->bsh, (r))
end_define

begin_define
define|#
directive|define
name|XE_INW
parameter_list|(
name|r
parameter_list|)
value|bus_space_read_2(scp->bst, scp->bsh, (r))
end_define

begin_define
define|#
directive|define
name|XE_OUTB
parameter_list|(
name|r
parameter_list|,
name|b
parameter_list|)
value|bus_space_write_1(scp->bst, scp->bsh, (r), (b))
end_define

begin_define
define|#
directive|define
name|XE_OUTW
parameter_list|(
name|r
parameter_list|,
name|w
parameter_list|)
value|bus_space_write_2(scp->bst, scp->bsh, (r), (w))
end_define

begin_define
define|#
directive|define
name|XE_SELECT_PAGE
parameter_list|(
name|p
parameter_list|)
value|XE_OUTB(XE_PR, (p))
end_define

begin_comment
comment|/*  * Horrid stuff for accessing CIS tuples  */
end_comment

begin_define
define|#
directive|define
name|CISTPL_BUFSIZE
value|512
end_define

begin_define
define|#
directive|define
name|CISTPL_TYPE
parameter_list|(
name|tpl
parameter_list|)
value|bus_space_read_1(bst, bsh, tpl + 0)
end_define

begin_define
define|#
directive|define
name|CISTPL_LEN
parameter_list|(
name|tpl
parameter_list|)
value|bus_space_read_1(bst, bsh, tpl + 2)
end_define

begin_define
define|#
directive|define
name|CISTPL_DATA
parameter_list|(
name|tpl
parameter_list|,
name|pos
parameter_list|)
value|bus_space_read_1(bst, bsh, tpl+ 4 + ((pos)<<1))
end_define

begin_function_decl
name|int
name|xe_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xe_activate
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xe_deactivate
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_XE_IF_XEVAR_H */
end_comment

end_unit

