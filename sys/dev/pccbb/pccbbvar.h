begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2001 Jonathan Chen.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Structure definitions for the Cardbus Bridge driver  */
end_comment

begin_struct
struct|struct
name|cbb_intrhand
block|{
name|driver_intr_t
modifier|*
name|intr
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|cbb_intrhand
argument_list|)
name|entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cbb_reslist
block|{
name|SLIST_ENTRY
argument_list|(
argument|cbb_reslist
argument_list|)
name|link
expr_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|rid
decl_stmt|;
comment|/* note: unlike the regular resource list, there can be 		 * duplicate rid's in the same list.  However, the 		 * combination of rid and res->r_dev should be unique. 		 */
name|bus_addr_t
name|cardaddr
decl_stmt|;
comment|/* for 16-bit pccard memory */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CBB_AUTO_OPEN_SMALLHOLE
value|0x100
end_define

begin_struct
struct|struct
name|cbb_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|exca_softc
name|exca
decl_stmt|;
name|struct
name|resource
modifier|*
name|base_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|void
modifier|*
name|intrhand
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|u_int8_t
name|secbus
decl_stmt|;
name|u_int8_t
name|subbus
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|cv
name|cv
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
define|#
directive|define
name|CBB_CARD_OK
value|0x08000000
define|#
directive|define
name|CBB_KLUDGE_ALLOC
value|0x10000000
define|#
directive|define
name|CBB_16BIT_CARD
value|0x20000000
define|#
directive|define
name|CBB_KTHREAD_RUNNING
value|0x40000000
define|#
directive|define
name|CBB_KTHREAD_DONE
value|0x80000000
name|int
name|chipset
decl_stmt|;
comment|/* chipset id */
define|#
directive|define
name|CB_UNKNOWN
value|0
comment|/* NOT Cardbus-PCI bridge */
define|#
directive|define
name|CB_TI113X
value|1
comment|/* TI PCI1130/1131 */
define|#
directive|define
name|CB_TI12XX
value|2
comment|/* TI PCI12xx/14xx/44xx/15xx/45xx */
define|#
directive|define
name|CB_TI125X
value|3
comment|/* TI PCI1250/1251(B)/1450 */
define|#
directive|define
name|CB_RF5C47X
value|4
comment|/* RICOH RF5C475/476/477 */
define|#
directive|define
name|CB_RF5C46X
value|5
comment|/* RICOH RF5C465/466/467 */
define|#
directive|define
name|CB_CIRRUS
value|6
comment|/* Cirrus Logic CLPD683x */
define|#
directive|define
name|CB_TOPIC95
value|7
comment|/* Toshiba ToPIC95 */
define|#
directive|define
name|CB_TOPIC97
value|8
comment|/* Toshiba ToPIC97/100 */
define|#
directive|define
name|CB_O2MICRO
value|9
comment|/* O2Micro chips */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|cbb_reslist
argument_list|)
name|rl
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|cbb_intrhand
argument_list|)
name|intr_handlers
expr_stmt|;
name|device_t
name|cbdev
decl_stmt|;
name|device_t
name|pccarddev
decl_stmt|;
name|struct
name|proc
modifier|*
name|event_thread
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* result of detect_card */
end_comment

begin_define
define|#
directive|define
name|CARD_UKN_CARD
value|0x00
end_define

begin_define
define|#
directive|define
name|CARD_5V_CARD
value|0x01
end_define

begin_define
define|#
directive|define
name|CARD_3V_CARD
value|0x02
end_define

begin_define
define|#
directive|define
name|CARD_XV_CARD
value|0x04
end_define

begin_define
define|#
directive|define
name|CARD_YV_CARD
value|0x08
end_define

begin_comment
comment|/* for power_socket */
end_comment

begin_define
define|#
directive|define
name|CARD_VCC
parameter_list|(
name|X
parameter_list|)
value|(X)
end_define

begin_define
define|#
directive|define
name|CARD_VPP_VCC
value|0xf0
end_define

begin_define
define|#
directive|define
name|CARD_VCCMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|CARD_VCCSHIFT
value|0
end_define

begin_define
define|#
directive|define
name|XV
value|2
end_define

begin_define
define|#
directive|define
name|YV
value|1
end_define

begin_define
define|#
directive|define
name|CARD_OFF
value|(CARD_VCC(0))
end_define

end_unit

