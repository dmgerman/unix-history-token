begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tsaperror.c - print out TPKT error codes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/tsap/RCS/tsaperror.c,v 7.3 91/02/22 09:47:26 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/tsap/RCS/tsaperror.c,v 7.3 91/02/22 09:47:26 mrose Interim $  *  *  * $Log:	tsaperror.c,v $  * Revision 7.3  91/02/22  09:47:26  mrose  * Interim 6.8  *   * Revision 7.2  91/01/11  07:09:22  mrose  * jpo  *   * Revision 7.1  90/11/21  11:31:34  mrose  * sun  *   * Revision 7.0  89/11/23  22:30:43  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"tsap.h"
end_include

begin_include
include|#
directive|include
file|"tp4.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SUNLINK_7_0
end_ifdef

begin_include
include|#
directive|include
file|<netosi/osi_layer.h>
end_include

begin_include
include|#
directive|include
file|<netosi/cons_impl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|disc_err0
index|[]
init|=
block|{
literal|"Reason not specified"
block|,
literal|"Congestion at TSAP"
block|,
literal|"Session entity not attached to TSAP"
block|,
literal|"Address unknown"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|disc_err0_cnt
init|=
sizeof|sizeof
name|disc_err0
operator|/
sizeof|sizeof
name|disc_err0
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|disc_err8
index|[]
init|=
block|{
literal|"Normal disconnect initiated by session entity"
block|,
literal|"Remote transport entity congestion at connect time"
block|,
literal|"Connection negotiation failed (proposed class(es) not supported)"
block|,
literal|"Duplicate source reference detected for the same pair of NSAPs"
block|,
literal|"Mismatched references"
block|,
literal|"Protocol error"
block|,
literal|"Not used"
block|,
literal|"Reference overflow"
block|,
literal|"Connect request refused on this network connection"
block|,
literal|"Not used"
block|,
literal|"Header or parameter length invalid"
block|,
literal|"Network disconnect"
block|,
literal|"Invalid parameter"
block|,
literal|"Invalid operation"
block|,
literal|"Timer expired"
block|,
literal|"Indications waiting"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|disc_err8_cnt
init|=
sizeof|sizeof
name|disc_err8
operator|/
sizeof|sizeof
name|disc_err8
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNLINK_7_0
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cons_err0
init|=
literal|"Unspecified (undefined) CONS error"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CONS Error 224 through 255 */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cons_err1
index|[]
init|=
block|{
literal|"CONS provider: undefined"
block|,
comment|/* R_CP_OSI_NETWORK_SERVICE_PROBLEM  */
literal|"CONS provider: disconnection-transient"
block|,
comment|/* R_CP_DIS_TRANS */
literal|"CONS provider: disconnection-permanent"
block|,
comment|/* R_CP_DIS_PERM */
literal|"CONS provider: connection rejection - reason unspecified (transient)"
block|,
comment|/* R_CP_CON_REJ_UNSPEC_TRANS */
literal|"CONS provider: connection rejection - reason unspecified (permanent)"
block|,
comment|/* R_CP_CON_REJ_UNSPEC_PERM */
literal|"CONS provider: connection rejection - QOS not available (transient)"
block|,
comment|/* R_CP_CON_REJ_NO_QOS_TRANS */
literal|"CONS provider: connection rejection - QOS not available (permanent)"
block|,
comment|/* R_CP_CON_REJ_NO_QOS_PERM */
literal|"CONS provider: connection rejection - NSAP unreachable (transient)"
block|,
comment|/* R_CP_CON_REJ_NSAP_UNREACH_TRANS */
literal|"CONS provider: connection rejection - NSAP unreachable (permanent)"
block|,
comment|/* R_CP_CON_REJ_NSAP_UNREACH_PERM */
literal|"CONS provider: RESET - reason unspecified"
block|,
comment|/* R_CP_RESET_UNSPEC */
literal|"CONS provider: RESET - congestion"
block|,
comment|/* R_CP_RESET_CONGESTION */
literal|"CONS provider: connection rejection - NSAP address unknown (permanent)"
block|,
comment|/* R_CP_CON_REJ_NSAP_UNKNOWN_PERM */
literal|"CONS provider: 236"
block|,
comment|/* R_CP_X25_236 */
literal|"CONS provider: 237"
block|,
comment|/* R_CP_X25_237 */
literal|"CONS provider: 238"
block|,
comment|/* R_CP_X25_238 */
literal|"CONS provider: 239"
block|,
comment|/* R_CP_X25_239 */
literal|"CONS user: undefined"
block|,
comment|/* R_CU_HIGHER_LEVEL_INITIATED = 240 */
literal|"CONS user: disconnection - normal"
block|,
comment|/* R_CU_DIS_NORMAL */
literal|"CONS user: disconnection - abnormal"
block|,
comment|/* R_CU_DIS_ABNORMAL */
literal|"CONS user: 243"
block|,
comment|/* R_CU_DIS_INCOMPAT */
literal|"CONS user: connection rejection - transient"
block|,
comment|/* R_CU_CON_REJ_UNSPEC_TRANS */
literal|"CONS user: connection rejection - permanent"
block|,
comment|/* R_CU_CON_REJ_UNSPEC_PERM */
literal|"CONS user: connection rejection - QOS not available (transient)"
block|,
comment|/* R_CU_CON_REJ_NO_QOS_TRANS */
literal|"CONS user: connection rejection - QOS not available (permanent)"
block|,
comment|/* R_CU_CON_REJ_NO_QOS_PERM */
literal|"CONS user: connection rejection - incompatible info in NS-user-data"
block|,
comment|/* R_CU_CON_REJ_INCOMPAT */
literal|"CONS user: 249"
block|,
comment|/* R_CU_CON_UNREC_PROTO */
literal|"CONS user: RESET - user resynchronization"
block|,
comment|/* R_CU_RESET_USER_RESYNCH */
literal|"CONS user: 251"
block|,
comment|/* R_CU_X25_251 */
literal|"CONS user: 252"
block|,
comment|/* R_CU_X25_252 */
literal|"CONS user: 253"
block|,
comment|/* R_CU_X25_253 */
literal|"CONS user: 254"
block|,
comment|/* R_CU_X25_254 */
literal|"CONS user: 255"
block|,
comment|/* R_CU_X25_255 */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|TErrString
parameter_list|(
name|code
parameter_list|)
specifier|register
name|int
name|code
decl_stmt|;
block|{
specifier|register
name|int
name|fcode
decl_stmt|;
specifier|static
name|char
name|buffer
index|[
literal|60
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|SUNLINK_7_0
if|if
condition|(
name|code
operator|>
literal|0xff
condition|)
block|{
comment|/* CONS error code */
name|code
operator|-=
literal|0x100
expr_stmt|;
if|if
condition|(
name|code
operator|==
name|R_CONS_UNDEFINED
condition|)
return|return
name|cons_err0
return|;
if|if
condition|(
name|code
operator|>=
name|R_CP_OSI_NETWORK_SERVICE_PROBLEM
operator|&&
name|code
operator|<=
name|R_CU_X25_255
condition|)
return|return
name|cons_err1
index|[
name|code
operator|-
name|R_CP_OSI_NETWORK_SERVICE_PROBLEM
index|]
return|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"unknown CONS error code 0x%x"
argument_list|,
name|code
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
endif|#
directive|endif
name|code
operator|&=
literal|0xff
expr_stmt|;
if|if
condition|(
name|code
operator|&
name|DR_BASE
condition|)
block|{
if|if
condition|(
operator|(
name|fcode
operator|=
name|code
operator|&
operator|~
name|DR_BASE
operator|)
operator|<
name|disc_err8_cnt
condition|)
return|return
name|disc_err8
index|[
name|fcode
index|]
return|;
block|}
elseif|else
if|if
condition|(
name|code
operator|<
name|disc_err0_cnt
condition|)
return|return
name|disc_err0
index|[
name|code
index|]
return|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"unknown error code 0x%x"
argument_list|,
name|code
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function

end_unit

