begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dummy K5 routines which are needed to get this to  * compile without having access ti the DCE versions  * of the header files.  * Thiis is very crude, and OSF needs to expose the K5  * API.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_comment
comment|/* Transarc obfascates these routines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DCE_1_1
end_ifdef

begin_define
define|#
directive|define
name|krb5_init_ets
value|_dce_PkjKqOaklP
end_define

begin_define
define|#
directive|define
name|krb5_copy_creds
value|_dce_LuFxPiITzD
end_define

begin_define
define|#
directive|define
name|krb5_unparse_name
value|_dce_LWHtAuNgRV
end_define

begin_define
define|#
directive|define
name|krb5_get_default_realm
value|_dce_vDruhprWGh
end_define

begin_define
define|#
directive|define
name|krb5_build_principal
value|_dce_qwAalSzTtF
end_define

begin_define
define|#
directive|define
name|krb5_build_principal_ext
value|_dce_vhafIQlejW
end_define

begin_define
define|#
directive|define
name|krb5_build_principal_va
value|_dce_alsqToMmuJ
end_define

begin_define
define|#
directive|define
name|krb5_cc_default
value|_dce_KZRshhTXhE
end_define

begin_define
define|#
directive|define
name|krb5_cc_default_name
value|_dce_bzJVAjHXVQ
end_define

begin_define
define|#
directive|define
name|sec_login_krb5_add_cred
value|_dce_ePDtOJTZvU
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DCE 1.0.3a */
end_comment

begin_define
define|#
directive|define
name|krb5_init_ets
value|_dce_BmLRpOVsBo
end_define

begin_define
define|#
directive|define
name|krb5_copy_creds
value|_dce_VGwSEBNwaf
end_define

begin_define
define|#
directive|define
name|krb5_unparse_name
value|_dce_PgAOkJoMXA
end_define

begin_define
define|#
directive|define
name|krb5_get_default_realm
value|_dce_plVOzStKyK
end_define

begin_define
define|#
directive|define
name|krb5_build_principal
value|_dce_uAKSsluIFy
end_define

begin_define
define|#
directive|define
name|krb5_build_principal_ext
value|_dce_tRMpPiRada
end_define

begin_define
define|#
directive|define
name|krb5_build_principal_va
value|_dce_SxnLejZemH
end_define

begin_define
define|#
directive|define
name|krb5_cc_default
value|_dce_SeKosWFnsv
end_define

begin_define
define|#
directive|define
name|krb5_cc_default_name
value|_dce_qJeaphJWVc
end_define

begin_define
define|#
directive|define
name|sec_login_krb5_add_cred
value|_dce_uHwRasumsN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the bare minimum k5 structures which are needed  * by this program. Since the krb5 includes are not supplied  * with DCE, these were based on the MIT Kerberos 5 beta 3  * which should match the DCE as of 1.0.3 at least.  * The tricky one is the krb5_creds, since one is allocated  * by this program, and it needs access to the client principal  * in it.  * Note that there are no function prototypes, so there is no  * compile time checking.  * DEE 07/11/95  */
end_comment

begin_define
define|#
directive|define
name|NPROTOTYPE
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_typedef
typedef|typedef
name|int
name|krb5_int32
typedef|;
end_typedef

begin_comment
comment|/* assuming all DCE systems are 32 bit */
end_comment

begin_typedef
typedef|typedef
name|short
name|krb5short
typedef|;
end_typedef

begin_comment
comment|/* assuming short is 16 bit */
end_comment

begin_typedef
typedef|typedef
name|krb5_int32
name|krb5_error_code
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|krb5_octet
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_octet
name|krb5_boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5short
name|krb5_keytype
typedef|;
end_typedef

begin_comment
comment|/* in k5.2 it's a short */
end_comment

begin_typedef
typedef|typedef
name|krb5_int32
name|krb5_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_int32
name|krb5_timestamp
typedef|;
end_typedef

begin_comment
comment|/* is a time_t in krb5.h */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|krb5_pointer
typedef|;
end_typedef

begin_comment
comment|/* pointer to unexposed data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_krb5_ccache
block|{
name|struct
name|_krb5_cc_ops
modifier|*
name|ops
decl_stmt|;
name|krb5_pointer
name|data
decl_stmt|;
block|}
typedef|*
name|krb5_ccache
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_krb5_cc_ops
block|{
name|char
modifier|*
name|prefix
decl_stmt|;
name|char
operator|*
operator|(
operator|*
name|get_name
operator|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*resolve
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*gen_new
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|*
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*init
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|,
name|krb5_principal
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*destroy
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*close
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*store
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|,
name|krb5_creds
operator|*
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*retrieve
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|,
name|krb5_flags
operator|,
name|krb5_creds
operator|*
operator|,
name|krb5_creds
operator|*
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*get_princ
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|,
name|krb5_principal
operator|*
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*get_first
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|,
name|krb5_cc_cursor
operator|*
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*get_next
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|,
name|krb5_cc_cursor
operator|*
operator|,
name|krb5_creds
operator|*
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*end_get
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|,
name|krb5_cc_cursor
operator|*
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*remove_cred
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|,
name|krb5_flags
operator|,
name|krb5_creds
operator|*
operator|)
argument_list|)
expr_stmt|;
name|krb5_error_code
argument_list|(
argument|*set_flags
argument_list|)
name|NPROTOTYPE
argument_list|(
operator|(
name|krb5_ccache
operator|,
name|krb5_flags
operator|)
argument_list|)
expr_stmt|;
block|}
name|krb5_cc_ops
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_krb5_keyblock
block|{
name|krb5_keytype
name|keytype
decl_stmt|;
name|int
name|length
decl_stmt|;
name|krb5_octet
modifier|*
name|contents
decl_stmt|;
block|}
name|krb5_keyblock
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_krb5_ticket_times
block|{
name|krb5_timestamp
name|authtime
decl_stmt|;
name|krb5_timestamp
name|starttime
decl_stmt|;
name|krb5_timestamp
name|endtime
decl_stmt|;
name|krb5_timestamp
name|renew_till
decl_stmt|;
block|}
name|krb5_ticket_times
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_pointer
name|krb5_cc_cursor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_krb5_data
block|{
name|int
name|length
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|krb5_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_krb5_authdata
block|{
name|int
name|ad_type
decl_stmt|;
name|int
name|length
decl_stmt|;
name|krb5_octet
modifier|*
name|contents
decl_stmt|;
block|}
name|krb5_authdata
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_krb5_creds
block|{
name|krb5_pointer
name|client
decl_stmt|;
name|krb5_pointer
name|server
decl_stmt|;
name|krb5_keyblock
name|keyblock
decl_stmt|;
name|krb5_ticket_times
name|times
decl_stmt|;
name|krb5_boolean
name|is_skey
decl_stmt|;
name|krb5_flags
name|ticket_flags
decl_stmt|;
name|krb5_pointer
modifier|*
modifier|*
name|addresses
decl_stmt|;
name|krb5_data
name|ticket
decl_stmt|;
name|krb5_data
name|second_ticket
decl_stmt|;
name|krb5_pointer
modifier|*
modifier|*
name|authdata
decl_stmt|;
block|}
name|krb5_creds
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_pointer
name|krb5_principal
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_CC_END
value|336760974
end_define

begin_define
define|#
directive|define
name|KRB5_TC_OPENCLOSE
value|0x00000001
end_define

begin_comment
comment|/* Ticket flags */
end_comment

begin_comment
comment|/* flags are 32 bits; each host is responsible to put the 4 bytes    representing these bits into net order before transmission */
end_comment

begin_comment
comment|/* #define  TKT_FLG_RESERVED    0x80000000 */
end_comment

begin_define
define|#
directive|define
name|TKT_FLG_FORWARDABLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_FORWARDED
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_PROXIABLE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_PROXY
value|0x08000000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_MAY_POSTDATE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_POSTDATED
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_INVALID
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_RENEWABLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_INITIAL
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_PRE_AUTH
value|0x00200000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_HW_AUTH
value|0x00100000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PK_INIT
end_ifdef

begin_define
define|#
directive|define
name|TKT_FLG_PUBKEY_PREAUTH
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_DIGSIGN_PREAUTH
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TKT_FLG_PRIVKEY_PREAUTH
value|0x00020000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|krb5_cc_get_principal
parameter_list|(
name|cache
parameter_list|,
name|principal
parameter_list|)
value|(*(cache)->ops->get_princ)(cache, principal)
end_define

begin_define
define|#
directive|define
name|krb5_cc_set_flags
parameter_list|(
name|cache
parameter_list|,
name|flags
parameter_list|)
value|(*(cache)->ops->set_flags)(cache, flags)
end_define

begin_define
define|#
directive|define
name|krb5_cc_get_name
parameter_list|(
name|cache
parameter_list|)
value|(*(cache)->ops->get_name)(cache)
end_define

begin_define
define|#
directive|define
name|krb5_cc_start_seq_get
parameter_list|(
name|cache
parameter_list|,
name|cursor
parameter_list|)
value|(*(cache)->ops->get_first)(cache, cursor)
end_define

begin_define
define|#
directive|define
name|krb5_cc_next_cred
parameter_list|(
name|cache
parameter_list|,
name|cursor
parameter_list|,
name|creds
parameter_list|)
value|(*(cache)->ops->get_next)(cache, cursor, creds)
end_define

begin_define
define|#
directive|define
name|krb5_cc_destroy
parameter_list|(
name|cache
parameter_list|)
value|(*(cache)->ops->destroy)(cache)
end_define

begin_define
define|#
directive|define
name|krb5_cc_end_seq_get
parameter_list|(
name|cache
parameter_list|,
name|cursor
parameter_list|)
value|(*(cache)->ops->end_get)(cache, cursor)
end_define

begin_comment
comment|/* end of k5 dummy typedefs */
end_comment

end_unit

