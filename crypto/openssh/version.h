begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: version.h,v 1.72 2015/03/04 18:53:53 djm Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|SSH_VERSION
value|"OpenSSH_6.8"
end_define

begin_define
define|#
directive|define
name|SSH_PORTABLE
value|"p1"
end_define

begin_define
define|#
directive|define
name|SSH_RELEASE
value|SSH_VERSION SSH_PORTABLE
end_define

begin_define
define|#
directive|define
name|SSH_VERSION_FREEBSD
value|"FreeBSD-20160119"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|OPENSSL_VERSION
value|SSLeay_version(SSLEAY_VERSION)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPENSSL_VERSION
value|"without OpenSSL"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

