begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002  *	Thomas Skibo<skibo@pacbell.net>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Thomas Skibo.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Thomas Skibo AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Thomas Skibo OR HIS DRINKING PALS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__WI_HOSTAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__WI_HOSTAP_H__
end_define

begin_define
define|#
directive|define
name|WIHAP_MAX_STATIONS
value|1800
end_define

begin_struct
struct|struct
name|hostap_sta
block|{
name|u_int8_t
name|addr
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|asid
decl_stmt|;
name|u_int16_t
name|flags
decl_stmt|;
name|u_int16_t
name|sig_info
decl_stmt|;
comment|/* 15:8 signal, 7:0 noise */
name|u_int16_t
name|capinfo
decl_stmt|;
name|u_int8_t
name|rates
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HOSTAP_FLAGS_AUTHEN
value|0x0001
end_define

begin_define
define|#
directive|define
name|HOSTAP_FLAGS_ASSOC
value|0x0002
end_define

begin_define
define|#
directive|define
name|HOSTAP_FLAGS_PERM
value|0x0004
end_define

begin_define
define|#
directive|define
name|SIOCHOSTAP_GET
value|_IOWR('i', 210, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCHOSTAP_ADD
value|_IOWR('i', 211, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCHOSTAP_DEL
value|_IOWR('i', 212, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCHOSTAP_GETALL
value|_IOWR('i', 213, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCHOSTAP_GFLAGS
value|_IOWR('i', 214, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCHOSTAP_SFLAGS
value|_IOWR('i', 215, struct ifreq)
end_define

begin_comment
comment|/* Flags for SIOCHOSTAP_GFLAGS/SFLAGS */
end_comment

begin_define
define|#
directive|define
name|WIHAPFL_ACTIVE
value|0x0001
end_define

begin_define
define|#
directive|define
name|WIHAPFL_MAC_FILT
value|0x0002
end_define

begin_comment
comment|/* Flags set inernally only: */
end_comment

begin_define
define|#
directive|define
name|WIHAPFL_CANTCHANGE
value|(WIHAPFL_ACTIVE)
end_define

begin_struct
struct|struct
name|hostap_getall
block|{
name|int
name|nstations
decl_stmt|;
name|struct
name|hostap_sta
modifier|*
name|addr
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|wihap_sta_info
block|{
name|LIST_ENTRY
argument_list|(
argument|wihap_sta_info
argument_list|)
name|list
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|wihap_sta_info
argument_list|)
name|hash
expr_stmt|;
name|struct
name|wi_softc
modifier|*
name|sc
decl_stmt|;
name|u_int8_t
name|addr
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|flags
decl_stmt|;
name|int
name|inactivity_timer
decl_stmt|;
name|u_int16_t
name|asid
decl_stmt|;
name|u_int16_t
name|capinfo
decl_stmt|;
name|u_int16_t
name|sig_info
decl_stmt|;
comment|/* 15:8 signal, 7:0 noise */
name|u_int8_t
name|rates
decl_stmt|;
name|u_int8_t
name|tx_curr_rate
decl_stmt|;
name|u_int8_t
name|tx_max_rate
decl_stmt|;
name|struct
name|callout_handle
name|tmo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_SIFLAGS_ASSOC
value|HOSTAP_FLAGS_ASSOC
end_define

begin_define
define|#
directive|define
name|WI_SIFLAGS_AUTHEN
value|HOSTAP_FLAGS_AUTHEN
end_define

begin_define
define|#
directive|define
name|WI_SIFLAGS_PERM
value|HOSTAP_FLAGS_PERM
end_define

begin_define
define|#
directive|define
name|WI_STA_HASH_SIZE
value|113
end_define

begin_if
if|#
directive|if
name|WI_STA_HASH_SIZE
operator|*
literal|16
operator|>=
literal|2007
end_if

begin_comment
comment|/* will generate ASID's too large. */
end_comment

begin_error
error|#
directive|error
literal|"WI_STA_HASH_SIZE too big"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|WI_STA_HASH_SIZE
operator|*
literal|16
operator|<
name|WIHAP_MAX_STATIONS
end_if

begin_error
error|#
directive|error
literal|"WI_STA_HASH_SIZE too small"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|wihap_info
block|{
name|LIST_HEAD
argument_list|(
argument|sta_list
argument_list|,
argument|wihap_sta_info
argument_list|)
name|sta_list
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument|sta_hash
argument_list|,
argument|wihap_sta_info
argument_list|)
name|sta_hash
index|[
name|WI_STA_HASH_SIZE
index|]
expr_stmt|;
name|u_int16_t
name|apflags
decl_stmt|;
name|int
name|n_stations
decl_stmt|;
name|u_int16_t
name|asid_inuse_mask
index|[
name|WI_STA_HASH_SIZE
index|]
decl_stmt|;
name|int
name|inactivity_time
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WIHAP_INTERVAL
value|5
end_define

begin_define
define|#
directive|define
name|WIHAP_DFLT_INACTIVITY_TIME
value|(120/WIHAP_INTERVAL)
end_define

begin_comment
comment|/* 2 minutes */
end_comment

begin_struct_decl
struct_decl|struct
name|wi_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wi_frame
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|wihap_timer
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wihap_mgmt_input
parameter_list|(
name|struct
name|wi_softc
modifier|*
parameter_list|,
name|struct
name|wi_frame
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wihap_data_input
parameter_list|(
name|struct
name|wi_softc
modifier|*
parameter_list|,
name|struct
name|wi_frame
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wihap_check_tx
parameter_list|(
name|struct
name|wihap_info
modifier|*
parameter_list|,
name|u_int8_t
index|[]
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wihap_init
parameter_list|(
name|struct
name|wi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wihap_shutdown
parameter_list|(
name|struct
name|wi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wihap_ioctl
parameter_list|(
name|struct
name|wi_softc
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
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
comment|/* __WI_HOSTAP_H__ */
end_comment

end_unit

