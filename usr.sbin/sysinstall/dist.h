begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIST_H_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|_DIST_H_INCLUDE
end_define

begin_comment
comment|/* Bitfields for distributions - hope we never have more than 32! :-) */
end_comment

begin_define
define|#
directive|define
name|DIST_BASE
value|0x00001
end_define

begin_define
define|#
directive|define
name|DIST_GAMES
value|0x00002
end_define

begin_define
define|#
directive|define
name|DIST_MANPAGES
value|0x00004
end_define

begin_define
define|#
directive|define
name|DIST_PROFLIBS
value|0x00008
end_define

begin_define
define|#
directive|define
name|DIST_DICT
value|0x00010
end_define

begin_define
define|#
directive|define
name|DIST_SRC
value|0x00020
end_define

begin_define
define|#
directive|define
name|DIST_DOC
value|0x00040
end_define

begin_define
define|#
directive|define
name|DIST_INFO
value|0x00080
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_comment
comment|/* only applicable on x86 */
end_comment

begin_define
define|#
directive|define
name|DIST_COMPAT1X
value|0x00100
end_define

begin_define
define|#
directive|define
name|DIST_COMPAT20
value|0x00200
end_define

begin_define
define|#
directive|define
name|DIST_COMPAT21
value|0x00400
end_define

begin_define
define|#
directive|define
name|DIST_COMPAT22
value|0x00800
end_define

begin_define
define|#
directive|define
name|DIST_COMPAT3X
value|0x01000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DIST_COMPAT4X
value|0x02000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DIST_XF86
value|0x04000
end_define

begin_define
define|#
directive|define
name|DIST_CRYPTO
value|0x08000
end_define

begin_define
define|#
directive|define
name|DIST_CATPAGES
value|0x10000
end_define

begin_define
define|#
directive|define
name|DIST_PORTS
value|0x20000
end_define

begin_define
define|#
directive|define
name|DIST_LOCAL
value|0x40000
end_define

begin_define
define|#
directive|define
name|DIST_PERL
value|0x80000
end_define

begin_define
define|#
directive|define
name|DIST_ALL
value|0xFFFFF
end_define

begin_comment
comment|/* Subtypes for CRYPTO distribution */
end_comment

begin_define
define|#
directive|define
name|DIST_CRYPTO_CRYPTO
value|0x0001
end_define

begin_define
define|#
directive|define
name|DIST_CRYPTO_SCRYPTO
value|0x0002
end_define

begin_define
define|#
directive|define
name|DIST_CRYPTO_SSECURE
value|0x0004
end_define

begin_define
define|#
directive|define
name|DIST_CRYPTO_SKERBEROS5
value|0x0040
end_define

begin_define
define|#
directive|define
name|DIST_CRYPTO_ALL
value|0x007F
end_define

begin_comment
comment|/* Subtypes for SRC distribution */
end_comment

begin_define
define|#
directive|define
name|DIST_SRC_BASE
value|0x00001
end_define

begin_define
define|#
directive|define
name|DIST_SRC_CONTRIB
value|0x00002
end_define

begin_define
define|#
directive|define
name|DIST_SRC_GNU
value|0x00004
end_define

begin_define
define|#
directive|define
name|DIST_SRC_ETC
value|0x00008
end_define

begin_define
define|#
directive|define
name|DIST_SRC_GAMES
value|0x00010
end_define

begin_define
define|#
directive|define
name|DIST_SRC_INCLUDE
value|0x00020
end_define

begin_define
define|#
directive|define
name|DIST_SRC_LIB
value|0x00040
end_define

begin_define
define|#
directive|define
name|DIST_SRC_LIBEXEC
value|0x00080
end_define

begin_define
define|#
directive|define
name|DIST_SRC_TOOLS
value|0x00100
end_define

begin_define
define|#
directive|define
name|DIST_SRC_RELEASE
value|0x00200
end_define

begin_define
define|#
directive|define
name|DIST_SRC_SBIN
value|0x00400
end_define

begin_define
define|#
directive|define
name|DIST_SRC_SHARE
value|0x00800
end_define

begin_define
define|#
directive|define
name|DIST_SRC_SYS
value|0x01000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_UBIN
value|0x02000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_USBIN
value|0x04000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_BIN
value|0x08000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_ALL
value|0x0FFFF
end_define

begin_comment
comment|/* Subtypes for XFree86 packages */
end_comment

begin_define
define|#
directive|define
name|DIST_XF86_CLIENTS
value|0x0001
end_define

begin_define
define|#
directive|define
name|DIST_XF86_DOC
value|0x0002
end_define

begin_define
define|#
directive|define
name|DIST_XF86_LIB
value|0x0004
end_define

begin_define
define|#
directive|define
name|DIST_XF86_MAN
value|0x0008
end_define

begin_define
define|#
directive|define
name|DIST_XF86_PROG
value|0x0010
end_define

begin_define
define|#
directive|define
name|DIST_XF86_MISC_ALL
value|0x001F
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER
value|0x0020
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_FB
value|0x0001
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_NEST
value|0x0002
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_PRINT
value|0x0004
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_VFB
value|0x0008
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_ALL
value|0x000F
end_define

begin_define
define|#
directive|define
name|DIST_XF86_FONTS
value|0x0040
end_define

begin_define
define|#
directive|define
name|DIST_XF86_FONTS_75
value|0x0001
end_define

begin_define
define|#
directive|define
name|DIST_XF86_FONTS_100
value|0x0002
end_define

begin_define
define|#
directive|define
name|DIST_XF86_FONTS_CYR
value|0x0004
end_define

begin_define
define|#
directive|define
name|DIST_XF86_FONTS_SCALE
value|0x0008
end_define

begin_define
define|#
directive|define
name|DIST_XF86_FONTS_BITMAPS
value|0x0010
end_define

begin_define
define|#
directive|define
name|DIST_XF86_FONTS_SERVER
value|0x0020
end_define

begin_define
define|#
directive|define
name|DIST_XF86_FONTS_ALL
value|0x003F
end_define

begin_define
define|#
directive|define
name|DIST_XF86_ALL
value|0x007F
end_define

begin_comment
comment|/* Canned distribution sets */
end_comment

begin_define
define|#
directive|define
name|_DIST_USER
define|\
value|( DIST_BASE | DIST_DOC | DIST_MANPAGES | DIST_DICT | DIST_CRYPTO | DIST_PERL )
end_define

begin_define
define|#
directive|define
name|_DIST_DEVELOPER
define|\
value|( _DIST_USER | DIST_PROFLIBS | DIST_INFO | DIST_SRC )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DIST_H_INCLUDE */
end_comment

end_unit

