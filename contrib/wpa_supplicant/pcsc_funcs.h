begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / PC/SC smartcard interface for USIM, GSM SIM  * Copyright (c) 2004-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
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

begin_comment
comment|/* GSM files  * File type in first octet:  * 3F = Master File  * 7F = Dedicated File  * 2F = Elementary File under the Master File  * 6F = Elementary File under a Dedicated File  */
end_comment

begin_define
define|#
directive|define
name|SCARD_FILE_MF
value|0x3F00
end_define

begin_define
define|#
directive|define
name|SCARD_FILE_GSM_DF
value|0x7F20
end_define

begin_define
define|#
directive|define
name|SCARD_FILE_UMTS_DF
value|0x7F50
end_define

begin_define
define|#
directive|define
name|SCARD_FILE_GSM_EF_IMSI
value|0x6F07
end_define

begin_define
define|#
directive|define
name|SCARD_FILE_EF_ICCID
value|0x2FE2
end_define

begin_define
define|#
directive|define
name|SCARD_FILE_EF_CK
value|0x6FE1
end_define

begin_define
define|#
directive|define
name|SCARD_FILE_EF_IK
value|0x6FE2
end_define

begin_define
define|#
directive|define
name|SCARD_CHV1_OFFSET
value|13
end_define

begin_define
define|#
directive|define
name|SCARD_CHV1_FLAG
value|0x80
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|SCARD_GSM_SIM_ONLY
block|,
name|SCARD_USIM_ONLY
block|,
name|SCARD_TRY_BOTH
block|}
name|scard_sim_type
typedef|;
end_typedef

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
name|scard_sim_type
name|sim_type
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
name|scard_gsm_auth
parameter_list|(
name|struct
name|scard_data
modifier|*
name|scard
parameter_list|,
name|unsigned
name|char
modifier|*
name|rand
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
name|unsigned
name|char
modifier|*
name|rand
parameter_list|,
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
name|s
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

