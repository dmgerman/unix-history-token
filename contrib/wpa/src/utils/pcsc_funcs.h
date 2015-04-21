begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / PC/SC smartcard interface for USIM, GSM SIM  * Copyright (c) 2004-2006, 2012, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCSC_FUNCS_H
end_ifndef

begin_define
define|#
directive|define
name|PCSC_FUNCS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PCSC_FUNCS
end_ifdef

begin_function_decl
name|struct
name|scard_data
modifier|*
name|scard_init
parameter_list|(
specifier|const
name|char
modifier|*
name|reader
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scard_deinit
parameter_list|(
name|struct
name|scard_data
modifier|*
name|scard
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scard_set_pin
parameter_list|(
name|struct
name|scard_data
modifier|*
name|scard
parameter_list|,
specifier|const
name|char
modifier|*
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scard_get_imsi
parameter_list|(
name|struct
name|scard_data
modifier|*
name|scard
parameter_list|,
name|char
modifier|*
name|imsi
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scard_get_mnc_len
parameter_list|(
name|struct
name|scard_data
modifier|*
name|scard
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scard_gsm_auth
parameter_list|(
name|struct
name|scard_data
modifier|*
name|scard
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|_rand
parameter_list|,
name|unsigned
name|char
modifier|*
name|sres
parameter_list|,
name|unsigned
name|char
modifier|*
name|kc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scard_umts_auth
parameter_list|(
name|struct
name|scard_data
modifier|*
name|scard
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|_rand
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|autn
parameter_list|,
name|unsigned
name|char
modifier|*
name|res
parameter_list|,
name|size_t
modifier|*
name|res_len
parameter_list|,
name|unsigned
name|char
modifier|*
name|ik
parameter_list|,
name|unsigned
name|char
modifier|*
name|ck
parameter_list|,
name|unsigned
name|char
modifier|*
name|auts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scard_get_pin_retry_counter
parameter_list|(
name|struct
name|scard_data
modifier|*
name|scard
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scard_supports_umts
parameter_list|(
name|struct
name|scard_data
modifier|*
name|scard
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PCSC_FUNCS */
end_comment

begin_define
define|#
directive|define
name|scard_init
parameter_list|(
name|r
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|scard_deinit
parameter_list|(
name|s
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|scard_set_pin
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
value|-1
end_define

begin_define
define|#
directive|define
name|scard_get_imsi
parameter_list|(
name|s
parameter_list|,
name|i
parameter_list|,
name|l
parameter_list|)
value|-1
end_define

begin_define
define|#
directive|define
name|scard_get_mnc_len
parameter_list|(
name|s
parameter_list|)
value|-1
end_define

begin_define
define|#
directive|define
name|scard_gsm_auth
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|,
name|s2
parameter_list|,
name|k
parameter_list|)
value|-1
end_define

begin_define
define|#
directive|define
name|scard_umts_auth
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|,
name|a
parameter_list|,
name|r2
parameter_list|,
name|rl
parameter_list|,
name|i
parameter_list|,
name|c
parameter_list|,
name|a2
parameter_list|)
value|-1
end_define

begin_define
define|#
directive|define
name|scard_get_pin_retry_counter
parameter_list|(
name|s
parameter_list|)
value|-1
end_define

begin_define
define|#
directive|define
name|scard_supports_umts
parameter_list|(
name|s
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCSC_FUNCS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCSC_FUNCS_H */
end_comment

end_unit

