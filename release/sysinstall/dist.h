begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|DIST_BIN
value|0x0001
end_define

begin_define
define|#
directive|define
name|DIST_GAMES
value|0x0002
end_define

begin_define
define|#
directive|define
name|DIST_MANPAGES
value|0x0004
end_define

begin_define
define|#
directive|define
name|DIST_PROFLIBS
value|0x0008
end_define

begin_define
define|#
directive|define
name|DIST_DICT
value|0x0010
end_define

begin_define
define|#
directive|define
name|DIST_SRC
value|0x0020
end_define

begin_define
define|#
directive|define
name|DIST_DOC
value|0x0040
end_define

begin_define
define|#
directive|define
name|DIST_INFO
value|0x0080
end_define

begin_define
define|#
directive|define
name|DIST_COMPAT1X
value|0x0100
end_define

begin_define
define|#
directive|define
name|DIST_COMPAT20
value|0x0200
end_define

begin_define
define|#
directive|define
name|DIST_COMPAT21
value|0x0400
end_define

begin_define
define|#
directive|define
name|DIST_XF86
value|0x0800
end_define

begin_define
define|#
directive|define
name|DIST_DES
value|0x1000
end_define

begin_define
define|#
directive|define
name|DIST_CATPAGES
value|0x2000
end_define

begin_define
define|#
directive|define
name|DIST_PORTS
value|0x4000
end_define

begin_define
define|#
directive|define
name|DIST_USR1
value|0x8000
end_define

begin_define
define|#
directive|define
name|DIST_ALL
value|0x7FFF
end_define

begin_comment
comment|/* Canned distribution sets */
end_comment

begin_define
define|#
directive|define
name|_DIST_DEVELOPER
define|\
value|(DIST_BIN | DIST_DOC | DIST_MANPAGES | DIST_DICT | DIST_PROFLIBS | DIST_INFO | DIST_SRC)
end_define

begin_define
define|#
directive|define
name|_DIST_USER
define|\
value|(DIST_BIN | DIST_DOC | DIST_MANPAGES | DIST_DICT)
end_define

begin_comment
comment|/* Subtypes for DES distribution */
end_comment

begin_define
define|#
directive|define
name|DIST_DES_DES
value|0x0001
end_define

begin_define
define|#
directive|define
name|DIST_DES_SCRYPTO
value|0x0002
end_define

begin_define
define|#
directive|define
name|DIST_DES_SSECURE
value|0x0004
end_define

begin_define
define|#
directive|define
name|DIST_DES_KERBEROS
value|0x0008
end_define

begin_define
define|#
directive|define
name|DIST_DES_SKERBEROS
value|0x0010
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
name|DIST_SRC_LKM
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
name|DIST_SRC_SMAILCF
value|0x10000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_ALL
value|0xFFFF
end_define

begin_comment
comment|/* no SMAILCF, it's part of USBIN */
end_comment

begin_comment
comment|/* Subtypes for XFree86 distribution */
end_comment

begin_define
define|#
directive|define
name|DIST_XF86_BIN
value|0x0001
end_define

begin_define
define|#
directive|define
name|DIST_XF86_CFG
value|0x0002
end_define

begin_define
define|#
directive|define
name|DIST_XF86_DOC
value|0x0004
end_define

begin_define
define|#
directive|define
name|DIST_XF86_HTML
value|0x0008
end_define

begin_define
define|#
directive|define
name|DIST_XF86_LIB
value|0x0010
end_define

begin_define
define|#
directive|define
name|DIST_XF86_LKIT98
value|0x0020
end_define

begin_define
define|#
directive|define
name|DIST_XF86_LKIT
value|0x0040
end_define

begin_define
define|#
directive|define
name|DIST_XF86_MAN
value|0x0080
end_define

begin_define
define|#
directive|define
name|DIST_XF86_PROG
value|0x0100
end_define

begin_define
define|#
directive|define
name|DIST_XF86_PS
value|0x0200
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SET
value|0x0400
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SRC
value|0x0800
end_define

begin_define
define|#
directive|define
name|DIST_XF86_CSRC
value|0x1000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_MISC_ALL
value|0x1FFF
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER
value|0x8000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_8514
value|0x0000001
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9480
value|0x0000002
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9EGC
value|0x0000004
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9GA9
value|0x0000008
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9GAN
value|0x0000010
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9LPW
value|0x0000020
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9NKV
value|0x0000040
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9NS3
value|0x0000080
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9SPW
value|0x0000100
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9TGU
value|0x0000200
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9WEP
value|0x0000400
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9WS
value|0x0000800
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_9WSN
value|0x0001000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_AGX
value|0x0002000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_I128
value|0x0004000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_MACH8
value|0x0008000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_MACH32
value|0x0010000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_MACH64
value|0x0020000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_MONO
value|0x0040000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_P9000
value|0x0080000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_S3
value|0x0100000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_S3V
value|0x0200000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_SVGA
value|0x0400000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_VGA16
value|0x0800000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_W32
value|0x1000000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_NEST
value|0x2000000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_VFB
value|0x4000000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_SERVER_ALL
value|0x7FFFFFF
end_define

begin_define
define|#
directive|define
name|DIST_XF86_FONTS
value|0x10000
end_define

begin_define
define|#
directive|define
name|DIST_XF86_FONTS_MISC
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
name|DIST_XF86_FONTS_NON
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
value|0x1FFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DIST_H_INCLUDE */
end_comment

end_unit

