begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: version.h,v 1.57 2010/03/07 22:01:32 djm Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSH_VERSION
end_ifndef

begin_define
define|#
directive|define
name|SSH_VERSION
value|(ssh_version_get())
end_define

begin_define
define|#
directive|define
name|SSH_RELEASE
value|(ssh_version_get())
end_define

begin_define
define|#
directive|define
name|SSH_VERSION_BASE
value|"OpenSSH_5.4p1"
end_define

begin_define
define|#
directive|define
name|SSH_VERSION_ADDENDUM
value|"FreeBSD-20100308"
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|ssh_version_get
parameter_list|(
name|void
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
comment|/* SSH_VERSION */
end_comment

end_unit

