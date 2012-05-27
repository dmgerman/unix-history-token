begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: version.h,v 1.62 2011/08/02 23:13:01 djm Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VERSION_H_
end_ifndef

begin_define
define|#
directive|define
name|_VERSION_H_
end_define

begin_define
define|#
directive|define
name|SSH_VERSION_BASE
value|"OpenSSH_5.9p1"
end_define

begin_define
define|#
directive|define
name|SSH_VERSION_ADDENDUM
value|"FreeBSD-20111001"
end_define

begin_define
define|#
directive|define
name|SSH_VERSION_HPN
value|"_hpn13v11"
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|ssh_version_get
parameter_list|(
name|int
name|hpn_disabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_version_set_addendum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VERSION_H_ */
end_comment

end_unit

