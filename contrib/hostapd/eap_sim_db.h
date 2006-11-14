begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|EAP_SIM_DB_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_SIM_DB_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EAP_SIM
end_ifdef

begin_comment
comment|/* Initialize EAP-SIM database/authentication gateway interface.  * Returns pointer to a private data structure. */
end_comment

begin_function_decl
name|void
modifier|*
name|eap_sim_db_init
parameter_list|(
specifier|const
name|char
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deinitialize EAP-SIM database/authentication gateway interface.  * priv is the pointer from eap_sim_db_init(). */
end_comment

begin_function_decl
name|void
name|eap_sim_db_deinit
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get GSM triplets for user name identity (identity_len bytes). In most cases,  * the user name is '1' | IMSI, i.e., 1 followed by the IMSI in ASCII format.  * priv is the pointer from eap_sim_db_init().  * Returns the number of triplets received (has to be less than or equal to  * max_chal) or -1 on error (e.g., user not found). rand, kc, and sres are  * pointers to data areas for the triplets. */
end_comment

begin_function_decl
name|int
name|eap_sim_db_get_gsm_triplets
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|identity
parameter_list|,
name|size_t
name|identity_len
parameter_list|,
name|int
name|max_chal
parameter_list|,
name|u8
modifier|*
name|rand
parameter_list|,
name|u8
modifier|*
name|kc
parameter_list|,
name|u8
modifier|*
name|sres
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Verify whether the given user identity (identity_len bytes) is known. In  * most cases, the user name is '1' | IMSI, i.e., 1 followed by the IMSI in  * ASCII format.  * priv is the pointer from eap_sim_db_init().  * Returns 0 if the user is found and GSM triplets would be available for it or  * -1 on error (e.g., user not found or no triplets available). */
end_comment

begin_function_decl
name|int
name|eap_sim_db_identity_known
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|identity
parameter_list|,
name|size_t
name|identity_len
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* EAP_SIM */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|eap_sim_db_init
parameter_list|(
specifier|const
name|char
modifier|*
name|config
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eap_sim_db_deinit
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_SIM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_SIM_DB_H */
end_comment

end_unit

