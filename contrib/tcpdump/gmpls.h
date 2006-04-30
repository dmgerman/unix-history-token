begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/gmpls.h,v 1.3.2.1 2005/05/19 06:44:03 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Hannes Gredler (hannes@juniper.net)  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|gmpls_link_prot_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|gmpls_switch_cap_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|gmpls_encoding_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|gmpls_payload_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|diffserv_te_bc_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|lmp_sd_service_config_cpsa_link_type_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|lmp_sd_service_config_cpsa_signal_type_sdh_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|lmp_sd_service_config_cpsa_signal_type_sonet_values
index|[]
decl_stmt|;
end_decl_stmt

end_unit

