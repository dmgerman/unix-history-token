begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Adrian Chadd<adrian@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ATH_CTRL_H__
end_ifndef

begin_define
define|#
directive|define
name|__ATH_CTRL_H__
end_define

begin_struct_decl
struct_decl|struct
name|ath_stats
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ath_diag
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ath_tx_aggr_stats
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ath_rateioctl
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ath_driver_req
block|{
comment|/* Open socket, or -1 */
name|int
name|s
decl_stmt|;
comment|/* The interface name in question */
name|char
modifier|*
name|ifname
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|ath_driver_req_init
parameter_list|(
name|struct
name|ath_driver_req
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_driver_req_open
parameter_list|(
name|struct
name|ath_driver_req
modifier|*
name|req
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_driver_req_close
parameter_list|(
name|struct
name|ath_driver_req
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_driver_req_fetch_diag
parameter_list|(
name|struct
name|ath_driver_req
modifier|*
name|req
parameter_list|,
name|unsigned
name|long
name|cmd
parameter_list|,
name|struct
name|ath_diag
modifier|*
name|ad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_driver_req_zero_stats
parameter_list|(
name|struct
name|ath_driver_req
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_driver_req_fetch_stats
parameter_list|(
name|struct
name|ath_driver_req
modifier|*
name|req
parameter_list|,
name|struct
name|ath_stats
modifier|*
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_drive_req_fetch_aggr_stats
parameter_list|(
name|struct
name|ath_driver_req
modifier|*
name|req
parameter_list|,
name|struct
name|ath_tx_aggr_stats
modifier|*
name|tx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_drive_req_fetch_ratectrl_stats
parameter_list|(
name|struct
name|ath_driver_req
modifier|*
name|req
parameter_list|,
name|struct
name|ath_rateioctl
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

