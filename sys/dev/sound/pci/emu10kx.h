begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Cameron Grant<gandalf@vilnya.demon.co.uk>  * Copyright (c) 2003-2006 Yuriy Tsibizov<yuriy.tsibizov@gfk.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EMU10KX_H
end_ifndef

begin_define
define|#
directive|define
name|EMU10KX_H
end_define

begin_define
define|#
directive|define
name|SND_EMU10KX_MINVER
value|1
end_define

begin_define
define|#
directive|define
name|SND_EMU10KX_PREFVER
value|1
end_define

begin_define
define|#
directive|define
name|SND_EMU10KX_MAXVER
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|EMUPAGESIZE
value|4096
end_define

begin_define
define|#
directive|define
name|NUM_G
value|64
end_define

begin_define
define|#
directive|define
name|EMU_PLAY_BUFSZ
value|EMUPAGESIZE*16
end_define

begin_comment
comment|/* Recording is limited by EMUPAGESIZE*16=64K buffer */
end_comment

begin_define
define|#
directive|define
name|EMU_REC_BUFSZ
value|EMUPAGESIZE*16
end_define

begin_define
define|#
directive|define
name|EMU_MAX_BUFSZ
value|EMUPAGESIZE*16
end_define

begin_define
define|#
directive|define
name|EMU_MAXPAGES
value|8192
end_define

begin_define
define|#
directive|define
name|EMU_VAR_FUNC
value|0
end_define

begin_define
define|#
directive|define
name|EMU_VAR_ROUTE
value|1
end_define

begin_define
define|#
directive|define
name|EMU_VAR_ISEMU10K1
value|2
end_define

begin_define
define|#
directive|define
name|RT_FRONT
value|0
end_define

begin_define
define|#
directive|define
name|RT_REAR
value|1
end_define

begin_define
define|#
directive|define
name|RT_CENTER
value|2
end_define

begin_define
define|#
directive|define
name|RT_SUB
value|3
end_define

begin_define
define|#
directive|define
name|RT_SIDE
value|4
end_define

begin_define
define|#
directive|define
name|RT_MCHRECORD
value|5
end_define

begin_define
define|#
directive|define
name|RT_COUNT
value|6
end_define

begin_comment
comment|/* mixer controls */
end_comment

begin_comment
comment|/* fx play */
end_comment

begin_define
define|#
directive|define
name|M_FX0_FRONT_L
value|0
end_define

begin_define
define|#
directive|define
name|M_FX1_FRONT_R
value|1
end_define

begin_define
define|#
directive|define
name|M_FX2_REAR_L
value|2
end_define

begin_define
define|#
directive|define
name|M_FX3_REAR_R
value|3
end_define

begin_define
define|#
directive|define
name|M_FX4_CENTER
value|4
end_define

begin_define
define|#
directive|define
name|M_FX5_SUBWOOFER
value|5
end_define

begin_define
define|#
directive|define
name|M_FX6_SIDE_L
value|6
end_define

begin_define
define|#
directive|define
name|M_FX7_SIDE_R
value|7
end_define

begin_comment
comment|/* fx rec */
end_comment

begin_define
define|#
directive|define
name|M_FX0_REC_L
value|8
end_define

begin_define
define|#
directive|define
name|M_FX1_REC_R
value|9
end_define

begin_comment
comment|/* inputs play */
end_comment

begin_define
define|#
directive|define
name|M_IN0_FRONT_L
value|10
end_define

begin_define
define|#
directive|define
name|M_IN0_FRONT_R
value|11
end_define

begin_define
define|#
directive|define
name|M_IN1_FRONT_L
value|12
end_define

begin_define
define|#
directive|define
name|M_IN1_FRONT_R
value|13
end_define

begin_define
define|#
directive|define
name|M_IN2_FRONT_L
value|14
end_define

begin_define
define|#
directive|define
name|M_IN2_FRONT_R
value|15
end_define

begin_define
define|#
directive|define
name|M_IN3_FRONT_L
value|16
end_define

begin_define
define|#
directive|define
name|M_IN3_FRONT_R
value|17
end_define

begin_define
define|#
directive|define
name|M_IN4_FRONT_L
value|18
end_define

begin_define
define|#
directive|define
name|M_IN4_FRONT_R
value|19
end_define

begin_define
define|#
directive|define
name|M_IN5_FRONT_L
value|20
end_define

begin_define
define|#
directive|define
name|M_IN5_FRONT_R
value|21
end_define

begin_define
define|#
directive|define
name|M_IN6_FRONT_L
value|22
end_define

begin_define
define|#
directive|define
name|M_IN6_FRONT_R
value|23
end_define

begin_define
define|#
directive|define
name|M_IN7_FRONT_L
value|24
end_define

begin_define
define|#
directive|define
name|M_IN7_FRONT_R
value|25
end_define

begin_comment
comment|/* inputs rec */
end_comment

begin_define
define|#
directive|define
name|M_IN0_REC_L
value|26
end_define

begin_define
define|#
directive|define
name|M_IN0_REC_R
value|27
end_define

begin_define
define|#
directive|define
name|M_IN1_REC_L
value|28
end_define

begin_define
define|#
directive|define
name|M_IN1_REC_R
value|29
end_define

begin_define
define|#
directive|define
name|M_IN2_REC_L
value|30
end_define

begin_define
define|#
directive|define
name|M_IN2_REC_R
value|31
end_define

begin_define
define|#
directive|define
name|M_IN3_REC_L
value|32
end_define

begin_define
define|#
directive|define
name|M_IN3_REC_R
value|33
end_define

begin_define
define|#
directive|define
name|M_IN4_REC_L
value|34
end_define

begin_define
define|#
directive|define
name|M_IN4_REC_R
value|35
end_define

begin_define
define|#
directive|define
name|M_IN5_REC_L
value|36
end_define

begin_define
define|#
directive|define
name|M_IN5_REC_R
value|37
end_define

begin_define
define|#
directive|define
name|M_IN6_REC_L
value|38
end_define

begin_define
define|#
directive|define
name|M_IN6_REC_R
value|39
end_define

begin_define
define|#
directive|define
name|M_IN7_REC_L
value|40
end_define

begin_define
define|#
directive|define
name|M_IN7_REC_R
value|41
end_define

begin_comment
comment|/* master volume */
end_comment

begin_define
define|#
directive|define
name|M_MASTER_FRONT_L
value|42
end_define

begin_define
define|#
directive|define
name|M_MASTER_FRONT_R
value|43
end_define

begin_define
define|#
directive|define
name|M_MASTER_REAR_L
value|44
end_define

begin_define
define|#
directive|define
name|M_MASTER_REAR_R
value|45
end_define

begin_define
define|#
directive|define
name|M_MASTER_CENTER
value|46
end_define

begin_define
define|#
directive|define
name|M_MASTER_SUBWOOFER
value|47
end_define

begin_define
define|#
directive|define
name|M_MASTER_SIDE_L
value|48
end_define

begin_define
define|#
directive|define
name|M_MASTER_SIDE_R
value|49
end_define

begin_comment
comment|/* master rec volume */
end_comment

begin_define
define|#
directive|define
name|M_MASTER_REC_L
value|50
end_define

begin_define
define|#
directive|define
name|M_MASTER_REC_R
value|51
end_define

begin_define
define|#
directive|define
name|NUM_MIXERS
value|52
end_define

begin_struct_decl
struct_decl|struct
name|emu_sc_info
struct_decl|;
end_struct_decl

begin_comment
comment|/* MIDI device parameters */
end_comment

begin_struct
struct|struct
name|emu_midiinfo
block|{
name|struct
name|emu_sc_info
modifier|*
name|card
decl_stmt|;
name|int
name|port
decl_stmt|;
name|int
name|portnr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* PCM device parameters */
end_comment

begin_struct
struct|struct
name|emu_pcminfo
block|{
name|struct
name|emu_sc_info
modifier|*
name|card
decl_stmt|;
name|int
name|route
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|emu_intr_register
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|inte_mask
parameter_list|,
name|uint32_t
name|intr_mask
parameter_list|,
name|uint32_t
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
name|softc
parameter_list|,
name|uint32_t
name|irq
parameter_list|)
parameter_list|,
name|void
modifier|*
name|isc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|emu_intr_unregister
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|int
name|ihandle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|emu_rd
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|unsigned
name|int
name|regno
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emu_wr
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|unsigned
name|int
name|regno
parameter_list|,
name|uint32_t
name|data
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|emu_rdptr
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|unsigned
name|int
name|chn
parameter_list|,
name|unsigned
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emu_wrptr
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|unsigned
name|int
name|chn
parameter_list|,
name|unsigned
name|int
name|reg
parameter_list|,
name|uint32_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|emu_rd_p16vptr
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|uint16_t
name|chn
parameter_list|,
name|uint16_t
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emu_wr_p16vptr
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|uint16_t
name|chn
parameter_list|,
name|uint16_t
name|reg
parameter_list|,
name|uint32_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|emu_timer_create
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|emu_timer_set
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|int
name|timer
parameter_list|,
name|int
name|delay
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|emu_timer_enable
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|int
name|timer
parameter_list|,
name|int
name|go
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|emu_timer_clear
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|int
name|timer
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|emu_voice
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|emu_route
block|{
name|int
name|routing_left
index|[
literal|8
index|]
decl_stmt|;
name|int
name|amounts_left
index|[
literal|8
index|]
decl_stmt|;
name|int
name|routing_right
index|[
literal|8
index|]
decl_stmt|;
name|int
name|amounts_right
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|emu_voice
modifier|*
name|emu_valloc
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emu_vfree
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|struct
name|emu_voice
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|emu_vinit
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|struct
name|emu_voice
modifier|*
name|m
parameter_list|,
name|struct
name|emu_voice
modifier|*
name|s
parameter_list|,
name|uint32_t
name|sz
parameter_list|,
name|struct
name|snd_dbuf
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emu_vroute
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|struct
name|emu_route
modifier|*
name|rt
parameter_list|,
name|struct
name|emu_voice
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emu_vsetup
parameter_list|(
name|struct
name|emu_voice
modifier|*
name|v
parameter_list|,
name|int
name|fmt
parameter_list|,
name|int
name|spd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emu_vwrite
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|struct
name|emu_voice
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emu_vtrigger
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|struct
name|emu_voice
modifier|*
name|v
parameter_list|,
name|int
name|go
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|emu_vpos
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|struct
name|emu_voice
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_dma_tag_t
name|emu_gettag
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emumix_set_volume
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|int
name|mixer_idx
parameter_list|,
name|int
name|volume
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|emumix_get_volume
parameter_list|(
name|struct
name|emu_sc_info
modifier|*
name|sc
parameter_list|,
name|int
name|mixer_idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emu_enable_ir
parameter_list|(
name|struct
name|emu_sc_info
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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EMU10K1_H */
end_comment

end_unit

