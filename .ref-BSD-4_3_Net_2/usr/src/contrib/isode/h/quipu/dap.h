begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dap.h - */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/quipu/RCS/dap.h,v 7.1 91/02/22 09:25:39 mrose Interim $  *  *  * $Log:	dap.h,v $  * Revision 7.1  91/02/22  09:25:39  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:29  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUDAP
end_ifndef

begin_define
define|#
directive|define
name|QUIPUDAP
end_define

begin_decl_stmt
specifier|extern
name|int
name|dsap_ad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Association descriptor in simple DUA mode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dsap_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Invocation identifier in simple DUA mode */
end_comment

begin_define
define|#
directive|define
name|ds_read
parameter_list|(
name|arg
parameter_list|,
name|err
parameter_list|,
name|res
parameter_list|)
value|dap_read(dsap_ad,&(dsap_id),arg,err,res)
end_define

begin_define
define|#
directive|define
name|ds_compare
parameter_list|(
name|arg
parameter_list|,
name|err
parameter_list|,
name|res
parameter_list|)
value|dap_compare(dsap_ad,&(dsap_id),arg,err,res)
end_define

begin_define
define|#
directive|define
name|ds_abandon
parameter_list|(
name|arg
parameter_list|,
name|err
parameter_list|)
value|dap_abandon(dsap_ad,&(dsap_id),arg,err)
end_define

begin_define
define|#
directive|define
name|ds_list
parameter_list|(
name|arg
parameter_list|,
name|err
parameter_list|,
name|res
parameter_list|)
value|dap_list(dsap_ad,&(dsap_id),arg,err,res)
end_define

begin_define
define|#
directive|define
name|ds_search
parameter_list|(
name|arg
parameter_list|,
name|err
parameter_list|,
name|res
parameter_list|)
value|dap_search(dsap_ad,&(dsap_id),arg,err,res)
end_define

begin_define
define|#
directive|define
name|ds_addentry
parameter_list|(
name|arg
parameter_list|,
name|err
parameter_list|)
value|dap_addentry(dsap_ad,&(dsap_id),arg,err)
end_define

begin_define
define|#
directive|define
name|ds_removeentry
parameter_list|(
name|arg
parameter_list|,
name|err
parameter_list|)
value|dap_removeentry(dsap_ad,&(dsap_id),arg,err)
end_define

begin_define
define|#
directive|define
name|ds_modifyentry
parameter_list|(
name|arg
parameter_list|,
name|err
parameter_list|)
value|dap_modifyentry(dsap_ad,&(dsap_id),arg,err)
end_define

begin_define
define|#
directive|define
name|ds_modifyrdn
parameter_list|(
name|arg
parameter_list|,
name|err
parameter_list|)
value|dap_modifyrdn(dsap_ad,&(dsap_id),arg,err)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

