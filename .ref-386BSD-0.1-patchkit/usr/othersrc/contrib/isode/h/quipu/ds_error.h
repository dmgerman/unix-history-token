begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ds_error.h - directory service errors */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/ds_error.h,v 7.1 91/02/22 09:25:44 mrose Interim $  *  *  * $Log:	ds_error.h,v $  * Revision 7.1  91/02/22  09:25:44  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:30  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DSERRORH
end_ifndef

begin_define
define|#
directive|define
name|DSERRORH
end_define

begin_include
include|#
directive|include
file|"quipu/dsp.h"
end_include

begin_struct
struct|struct
name|DSE_abandon_fail
block|{
name|int
name|DSE_ab_problem
decl_stmt|;
define|#
directive|define
name|DSE_AB_NOSUCHOPERATION
value|1
define|#
directive|define
name|DSE_AB_TOOLATE
value|2
define|#
directive|define
name|DSE_AB_CANNOTABANDON
value|3
name|int
name|DSE_ab_invokeid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DSE_at_problem
block|{
name|int
name|DSE_at_what
decl_stmt|;
define|#
directive|define
name|DSE_AT_NOSUCHATTRIBUTE
value|1
define|#
directive|define
name|DSE_AT_INVALIDATTRIBUTESYNTAX
value|2
define|#
directive|define
name|DSE_AT_UNDEFINEDATTRIBUTETYPE
value|3
define|#
directive|define
name|DSE_AT_INAPPROPRIATEMATCHING
value|4
define|#
directive|define
name|DSE_AT_CONSTRAINTVIOLATION
value|5
define|#
directive|define
name|DSE_AT_TYPEORVALUEEXISTS
value|6
name|AttributeType
name|DSE_at_type
decl_stmt|;
name|AttributeValue
name|DSE_at_value
decl_stmt|;
name|struct
name|DSE_at_problem
modifier|*
name|dse_at_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DSE_AT_NOPROBLEM
value|((struct DSE_at_problem*)0)
end_define

begin_struct
struct|struct
name|DSE_attribute
block|{
name|DN
name|DSE_at_name
decl_stmt|;
name|struct
name|DSE_at_problem
name|DSE_at_plist
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DSE_name
block|{
name|int
name|DSE_na_problem
decl_stmt|;
define|#
directive|define
name|DSE_NA_NOSUCHOBJECT
value|1
define|#
directive|define
name|DSE_NA_ALIASPROBLEM
value|2
define|#
directive|define
name|DSE_NA_INVALIDATTRIBUTESYNTAX
value|3
define|#
directive|define
name|DSE_NA_ALIASDEREFERENCE
value|4
name|DN
name|DSE_na_matched
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DSE_referral
block|{
name|ContinuationRef
name|DSE_ref_candidates
decl_stmt|;
name|DN
name|DSE_ref_prefix
decl_stmt|;
comment|/* Context prefix only in DSP           */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DSE_security
block|{
name|int
name|DSE_sc_problem
decl_stmt|;
define|#
directive|define
name|DSE_SC_AUTHENTICATION
value|1
define|#
directive|define
name|DSE_SC_INVALIDCREDENTIALS
value|2
define|#
directive|define
name|DSE_SC_ACCESSRIGHTS
value|3
define|#
directive|define
name|DSE_SC_INVALIDSIGNATURE
value|4
define|#
directive|define
name|DSE_SC_PROTECTIONREQUIRED
value|5
define|#
directive|define
name|DSE_SC_NOINFORMATION
value|6
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DSE_service
block|{
name|int
name|DSE_sv_problem
decl_stmt|;
define|#
directive|define
name|DSE_SV_BUSY
value|1
define|#
directive|define
name|DSE_SV_UNAVAILABLE
value|2
define|#
directive|define
name|DSE_SV_UNWILLINGTOPERFORM
value|3
define|#
directive|define
name|DSE_SV_CHAININGREQUIRED
value|4
define|#
directive|define
name|DSE_SV_UNABLETOPROCEED
value|5
define|#
directive|define
name|DSE_SV_INVALIDREFERENCE
value|6
comment|/* DSP ONLY */
define|#
directive|define
name|DSE_SV_TIMELIMITEXCEEDED
value|7
define|#
directive|define
name|DSE_SV_ADMINLIMITEXCEEDED
value|8
define|#
directive|define
name|DSE_SV_LOOPDETECT
value|9
define|#
directive|define
name|DSE_SV_UNAVAILABLECRITICALEXTENSION
value|10
define|#
directive|define
name|DSE_SV_OUTOFSCOPE
value|11
define|#
directive|define
name|DSE_SV_DITERROR
value|12
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DSE_update
block|{
name|int
name|DSE_up_problem
decl_stmt|;
define|#
directive|define
name|DSE_UP_NAMINGVIOLATION
value|1
define|#
directive|define
name|DSE_UP_OBJECTCLASSVIOLATION
value|2
define|#
directive|define
name|DSE_UP_NOTONNONLEAF
value|3
define|#
directive|define
name|DSE_UP_NOTONRDN
value|4
define|#
directive|define
name|DSE_UP_ALREADYEXISTS
value|5
define|#
directive|define
name|DSE_UP_AFFECTSMULTIPLEDSAS
value|6
define|#
directive|define
name|DSE_UP_NOOBJECTCLASSMODS
value|7
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DSError
block|{
name|int
name|dse_type
decl_stmt|;
define|#
directive|define
name|DSE_INTR_ABANDON_FAILED
value|-5
comment|/* Call interrupted - abandon failed */
define|#
directive|define
name|DSE_INTR_ABANDONED
value|-4
comment|/* Call interrupted - abandoned */
define|#
directive|define
name|DSE_INTRERROR
value|-3
comment|/* Call interrupted */
define|#
directive|define
name|DSE_LOCALERROR
value|-2
comment|/* Error in DUA */
define|#
directive|define
name|DSE_REMOTEERROR
value|-1
comment|/* Problem with DSA */
define|#
directive|define
name|DSE_NOERROR
value|0
define|#
directive|define
name|DSE_ATTRIBUTEERROR
value|1
define|#
directive|define
name|DSE_NAMEERROR
value|2
define|#
directive|define
name|DSE_SERVICEERROR
value|3
define|#
directive|define
name|DSE_REFERRAL
value|4
define|#
directive|define
name|DSE_ABANDONED
value|5
comment|/* Abandoned does not have any parameter and    */
comment|/* so there is no struct for this value         */
define|#
directive|define
name|DSE_SECURITYERROR
value|6
define|#
directive|define
name|DSE_ABANDON_FAILED
value|7
define|#
directive|define
name|DSE_UPDATEERROR
value|8
define|#
directive|define
name|DSE_DSAREFERRAL
value|9
define|#
directive|define
name|ds_recog_err
parameter_list|(
name|a
parameter_list|)
value|((a>= DSE_ATTRIBUTEERROR)&& (a<= DSE_DSAREFERRAL))
union|union
block|{
name|struct
name|DSE_attribute
name|dse_un_attribute
decl_stmt|;
name|struct
name|DSE_name
name|dse_un_name
decl_stmt|;
name|struct
name|DSE_service
name|dse_un_service
decl_stmt|;
name|struct
name|DSE_referral
name|dse_un_referral
decl_stmt|;
name|struct
name|DSE_security
name|dse_un_security
decl_stmt|;
name|struct
name|DSE_abandon_fail
name|dse_un_abandon_fail
decl_stmt|;
name|struct
name|DSE_update
name|dse_un_update
decl_stmt|;
block|}
name|dse_un
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* THIS SECTION DEFINES THE PROCEDURE CALLS */
end_comment

begin_comment
comment|/* All of the DUA calls are SYNCHRONOUS, with no access to referrals    */
end_comment

begin_comment
comment|/* A DUA can access lower level hooks if if needs to be more clever     */
end_comment

begin_comment
comment|/* Each call has a single structure fore each direction, as defined     */
end_comment

begin_comment
comment|/* All routines return integer values with the following possible values */
end_comment

begin_define
define|#
directive|define
name|DS_OK
value|0
end_define

begin_comment
comment|/* Success                              */
end_comment

begin_define
define|#
directive|define
name|DS_ERROR_LOCAL
value|-1
end_define

begin_comment
comment|/* Error within the DUA module          */
end_comment

begin_define
define|#
directive|define
name|DS_ERROR_CONNECT
value|-2
end_define

begin_comment
comment|/* Failed to connect to a remote DSA    */
end_comment

begin_define
define|#
directive|define
name|DS_ERROR_PROVIDER
value|-3
end_define

begin_comment
comment|/* Other OSI provider error             */
end_comment

begin_define
define|#
directive|define
name|DS_X500_ERROR
value|-4
end_define

begin_comment
comment|/* Synonym for remote error */
end_comment

begin_define
define|#
directive|define
name|DS_ERROR_REMOTE
value|-4
end_define

begin_comment
comment|/* Remote error.  Further details will  */
end_comment

begin_comment
comment|/* be in the error parameter            */
end_comment

begin_define
define|#
directive|define
name|DS_CONTINUE
value|-5
end_define

begin_comment
comment|/* operation not finished... continuing */
end_comment

begin_define
define|#
directive|define
name|DS_SUSPEND
value|-6
end_define

begin_comment
comment|/* operation has deliberately suspended */
end_comment

begin_define
define|#
directive|define
name|DS_ERROR_ABANDONED
value|-7
end_define

begin_comment
comment|/* RoIntr caused succesful ds_abandon */
end_comment

begin_define
define|#
directive|define
name|DS_ERROR_ABANDON_FAILED
value|-8
end_define

begin_comment
comment|/* RoIntr caused unsuccesful ds_abandon */
end_comment

begin_define
define|#
directive|define
name|ERR_ABANDON_FAIL
value|dse_un.dse_un_abandon_fail
end_define

begin_define
define|#
directive|define
name|ERR_ATTRIBUTE
value|dse_un.dse_un_attribute
end_define

begin_define
define|#
directive|define
name|ERR_NAME
value|dse_un.dse_un_name
end_define

begin_define
define|#
directive|define
name|ERR_REFERRAL
value|dse_un.dse_un_referral
end_define

begin_define
define|#
directive|define
name|ERR_SECURITY
value|dse_un.dse_un_security
end_define

begin_define
define|#
directive|define
name|ERR_SERVICE
value|dse_un.dse_un_service
end_define

begin_define
define|#
directive|define
name|ERR_UPDATE
value|dse_un.dse_un_update
end_define

begin_define
define|#
directive|define
name|ERR_ALIAS
value|dse_un.dse_un_alias
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

