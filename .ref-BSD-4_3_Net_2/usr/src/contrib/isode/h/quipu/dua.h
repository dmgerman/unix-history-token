begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dua.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/dua.h,v 7.1 91/02/22 09:25:52 mrose Interim $  *  *  * $Log:	dua.h,v $  * Revision 7.1  91/02/22  09:25:52  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:35  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_define
define|#
directive|define
name|default_common_args
define|\
value|{ \ 		{
comment|/* service controls */
value|\ 			0, \ 			SVC_PRIO_MED, \ 			SVC_NOTIMELIMIT, \ 			SVC_NOSIZELIMIT, \ 			SVC_REFSCOPE_NONE \ 		}, \ 		NULLDN,
comment|/* Common arg - requestor DN */
value|\ 		{
comment|/* op_progress */
value|\ 			OP_PHASE_NOTDEFINED, \ 			OP_PHASE_NOTDEFINED, \ 		}, \ 		CA_NO_ALIASDEREFERENCED, \ 		(struct security_parms *) NULL, \ 		(struct signature *) NULL, \ 		(struct extension *) NULL, \ 	}
end_define

end_unit

