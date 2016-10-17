begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_rtwnreg.h,v 1.3 2015/06/14 08:02:47 stsp Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2015 Stefan Sperling<stsp@openbsd.org>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTL8192CE_H
end_ifndef

begin_define
define|#
directive|define
name|RTL8192CE_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c.h>
end_include

begin_comment
comment|/*  * Global definitions.  */
end_comment

begin_define
define|#
directive|define
name|R92CE_PUBQ_NPAGES
value|176
end_define

begin_define
define|#
directive|define
name|R92CE_HPQ_NPAGES
value|41
end_define

begin_define
define|#
directive|define
name|R92CE_LPQ_NPAGES
value|28
end_define

begin_define
define|#
directive|define
name|R92CE_TX_PAGE_COUNT
define|\
value|(R92CE_PUBQ_NPAGES + R92CE_HPQ_NPAGES + R92CE_LPQ_NPAGES)
end_define

begin_comment
comment|/*  * Function declarations.  */
end_comment

begin_comment
comment|/* r92ce_calib.c */
end_comment

begin_function_decl
name|void
name|r92ce_iq_calib
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92ce_fw.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTWN_WITHOUT_UCODE
end_ifndef

begin_function_decl
name|void
name|r92ce_fw_reset
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* r92ce_init.c */
end_comment

begin_function_decl
name|void
name|r92ce_init_intr
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92ce_init_edca
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92ce_init_bb
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r92ce_power_on
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92ce_power_off
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92ce_init_ampdu
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92ce_post_init
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92ce_led.c */
end_comment

begin_function_decl
name|void
name|r92ce_set_led
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92ce_rx.c */
end_comment

begin_function_decl
name|int
name|r92ce_classify_intr
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92ce_enable_intr
parameter_list|(
name|struct
name|rtwn_pci_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92ce_start_xfers
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92ce_tx.c */
end_comment

begin_function_decl
name|void
name|r92ce_setup_tx_desc
parameter_list|(
name|struct
name|rtwn_pci_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92ce_tx_postsetup
parameter_list|(
name|struct
name|rtwn_pci_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bus_dma_segment_t
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92ce_copy_tx_desc
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92ce_dump_tx_desc
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTL8192CE_H */
end_comment

end_unit

