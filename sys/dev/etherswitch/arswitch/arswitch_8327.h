begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARSWITCH_8327_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARSWITCH_8327_H__
end_define

begin_enum
enum|enum
name|ar8327_pad_mode
block|{
name|AR8327_PAD_NC
init|=
literal|0
block|,
name|AR8327_PAD_MAC2MAC_MII
block|,
name|AR8327_PAD_MAC2MAC_GMII
block|,
name|AR8327_PAD_MAC_SGMII
block|,
name|AR8327_PAD_MAC2PHY_MII
block|,
name|AR8327_PAD_MAC2PHY_GMII
block|,
name|AR8327_PAD_MAC_RGMII
block|,
name|AR8327_PAD_PHY_GMII
block|,
name|AR8327_PAD_PHY_RGMII
block|,
name|AR8327_PAD_PHY_MII
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ar8327_clk_delay_sel
block|{
name|AR8327_CLK_DELAY_SEL0
init|=
literal|0
block|,
name|AR8327_CLK_DELAY_SEL1
block|,
name|AR8327_CLK_DELAY_SEL2
block|,
name|AR8327_CLK_DELAY_SEL3
block|, }
enum|;
end_enum

begin_comment
comment|/* XXX update the field types */
end_comment

begin_struct
struct|struct
name|ar8327_pad_cfg
block|{
name|uint32_t
name|mode
decl_stmt|;
name|uint32_t
name|rxclk_sel
decl_stmt|;
name|uint32_t
name|txclk_sel
decl_stmt|;
name|uint32_t
name|txclk_delay_sel
decl_stmt|;
name|uint32_t
name|rxclk_delay_sel
decl_stmt|;
name|uint32_t
name|txclk_delay_en
decl_stmt|;
name|uint32_t
name|rxclk_delay_en
decl_stmt|;
name|uint32_t
name|sgmii_delay_en
decl_stmt|;
name|uint32_t
name|pipe_rxclk_sel
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ar8327_sgmii_cfg
block|{
name|uint32_t
name|sgmii_ctrl
decl_stmt|;
name|uint32_t
name|serdes_aen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ar8327_led_cfg
block|{
name|uint32_t
name|led_ctrl0
decl_stmt|;
name|uint32_t
name|led_ctrl1
decl_stmt|;
name|uint32_t
name|led_ctrl2
decl_stmt|;
name|uint32_t
name|led_ctrl3
decl_stmt|;
name|uint32_t
name|open_drain
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ar8327_port_cfg
block|{
define|#
directive|define
name|AR8327_PORT_SPEED_10
value|1
define|#
directive|define
name|AR8327_PORT_SPEED_100
value|2
define|#
directive|define
name|AR8327_PORT_SPEED_1000
value|3
name|uint32_t
name|speed
decl_stmt|;
name|uint32_t
name|force_link
decl_stmt|;
name|uint32_t
name|duplex
decl_stmt|;
name|uint32_t
name|txpause
decl_stmt|;
name|uint32_t
name|rxpause
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|ar8327_attach
parameter_list|(
name|struct
name|arswitch_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ARSWITCH_8327_H__ */
end_comment

end_unit

