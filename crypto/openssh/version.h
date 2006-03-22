begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: version.h,v 1.46 2006/02/01 11:27:22 markus Exp $ */
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
value|"OpenSSH_4.3p1"
end_define

begin_define
define|#
directive|define
name|SSH_VERSION_ADDENDUM
value|"FreeBSD-20060322"
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
name|add
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

