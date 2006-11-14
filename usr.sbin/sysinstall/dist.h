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

begin_define
define|#
directive|define
name|DIST_XORG
value|0x00100
end_define

begin_define
define|#
directive|define
name|DIST_CATPAGES
value|0x00200
end_define

begin_define
define|#
directive|define
name|DIST_PORTS
value|0x00400
end_define

begin_define
define|#
directive|define
name|DIST_LOCAL
value|0x00800
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|DIST_LIB32
value|0x01000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DIST_KERNEL
value|0x02000
end_define

begin_define
define|#
directive|define
name|DIST_ALL
value|0xFFFFF
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
name|DIST_SRC_SCRYPTO
value|0x10000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_SSECURE
value|0x20000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_SKERBEROS5
value|0x40000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_RESCUE
value|0x80000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_ALL
value|0xFFFFF
end_define

begin_comment
comment|/* Subtypes for X.Org packages */
end_comment

begin_define
define|#
directive|define
name|DIST_XORG_CLIENTS
value|0x000001
end_define

begin_define
define|#
directive|define
name|DIST_XORG_LIB
value|0x000002
end_define

begin_define
define|#
directive|define
name|DIST_XORG_MAN
value|0x000004
end_define

begin_define
define|#
directive|define
name|DIST_XORG_DOC
value|0x000008
end_define

begin_define
define|#
directive|define
name|DIST_XORG_IMAKE
value|0x000010
end_define

begin_define
define|#
directive|define
name|DIST_XORG_SERVER
value|0x000100
end_define

begin_define
define|#
directive|define
name|DIST_XORG_NESTSERVER
value|0x000200
end_define

begin_define
define|#
directive|define
name|DIST_XORG_PRINTSERVER
value|0x000400
end_define

begin_define
define|#
directive|define
name|DIST_XORG_VFBSERVER
value|0x000800
end_define

begin_define
define|#
directive|define
name|DIST_XORG_FONTS_MISC
value|0x010000
end_define

begin_define
define|#
directive|define
name|DIST_XORG_FONTS_75
value|0x020000
end_define

begin_define
define|#
directive|define
name|DIST_XORG_FONTS_100
value|0x040000
end_define

begin_define
define|#
directive|define
name|DIST_XORG_FONTS_CYR
value|0x080000
end_define

begin_define
define|#
directive|define
name|DIST_XORG_FONTS_T1
value|0x100000
end_define

begin_define
define|#
directive|define
name|DIST_XORG_FONTS_TT
value|0x200000
end_define

begin_define
define|#
directive|define
name|DIST_XORG_FONTSERVER
value|0x400000
end_define

begin_define
define|#
directive|define
name|DIST_XORG_MISC_ALL
value|0x00001f
end_define

begin_define
define|#
directive|define
name|DIST_XORG_SERVER_ALL
value|0x000f00
end_define

begin_define
define|#
directive|define
name|DIST_XORG_FONTS_ALL
value|0x7f0000
end_define

begin_define
define|#
directive|define
name|DIST_XORG_ALL
define|\
value|(DIST_XORG_MISC_ALL | DIST_XORG_SERVER_ALL | DIST_XORG_FONTS_ALL)
end_define

begin_comment
comment|/* Subtypes for KERNEL distribution */
end_comment

begin_define
define|#
directive|define
name|DIST_KERNEL_GENERIC
value|0x00001
end_define

begin_define
define|#
directive|define
name|DIST_KERNEL_SMP
value|0x00002
end_define

begin_define
define|#
directive|define
name|DIST_KERNEL_ALL
value|0xFFFFF
end_define

begin_comment
comment|/* Canned distribution sets */
end_comment

begin_define
define|#
directive|define
name|_DIST_XORG_FONTS_BASE
define|\
value|(DIST_XORG_FONTS_MISC | DIST_XORG_FONTS_75 | DIST_XORG_FONTS_100 | \ 	 DIST_XORG_FONTS_TT)
end_define

begin_define
define|#
directive|define
name|_DIST_USER
define|\
value|( DIST_BASE | DIST_KERNEL | DIST_DOC | DIST_MANPAGES | DIST_DICT )
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

