begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Hannes Gredler (hannes@juniper.net)  */
end_comment

begin_define
define|#
directive|define
name|GMPLS_PSC1
value|1
end_define

begin_define
define|#
directive|define
name|GMPLS_PSC2
value|2
end_define

begin_define
define|#
directive|define
name|GMPLS_PSC3
value|3
end_define

begin_define
define|#
directive|define
name|GMPLS_PSC4
value|4
end_define

begin_define
define|#
directive|define
name|GMPLS_L2SC
value|51
end_define

begin_define
define|#
directive|define
name|GMPLS_TSC
value|100
end_define

begin_define
define|#
directive|define
name|GMPLS_LSC
value|150
end_define

begin_define
define|#
directive|define
name|GMPLS_FSC
value|200
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|gmpls_link_prot_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|gmpls_switch_cap_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|gmpls_switch_cap_tsc_indication_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|gmpls_encoding_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|gmpls_payload_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|diffserv_te_bc_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|lmp_sd_service_config_cpsa_link_type_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|lmp_sd_service_config_cpsa_signal_type_sdh_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|lmp_sd_service_config_cpsa_signal_type_sonet_values
index|[]
decl_stmt|;
end_decl_stmt

end_unit

