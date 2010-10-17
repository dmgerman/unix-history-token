begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms are freely  * permitted provided that the above copyright notice and this  * paragraph and the following disclaimer are duplicated in all  * such forms.  *  * This software is provided "AS IS" and without any express or  * implied warranties, including, without limitation, the implied  * warranties of merchantability and fitness for a particular  * purpose.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RBX_H_
end_ifndef

begin_define
define|#
directive|define
name|_RBX_H_
end_define

begin_define
define|#
directive|define
name|RBX_ASKNAME
value|0x0
end_define

begin_comment
comment|/* -a */
end_comment

begin_define
define|#
directive|define
name|RBX_SINGLE
value|0x1
end_define

begin_comment
comment|/* -s */
end_comment

begin_comment
comment|/* 0x2 is reserved for log2(RB_NOSYNC). */
end_comment

begin_comment
comment|/* 0x3 is reserved for log2(RB_HALT). */
end_comment

begin_comment
comment|/* 0x4 is reserved for log2(RB_INITNAME). */
end_comment

begin_define
define|#
directive|define
name|RBX_DFLTROOT
value|0x5
end_define

begin_comment
comment|/* -r */
end_comment

begin_define
define|#
directive|define
name|RBX_KDB
value|0x6
end_define

begin_comment
comment|/* -d */
end_comment

begin_comment
comment|/* 0x7 is reserved for log2(RB_RDONLY). */
end_comment

begin_comment
comment|/* 0x8 is reserved for log2(RB_DUMP). */
end_comment

begin_comment
comment|/* 0x9 is reserved for log2(RB_MINIROOT). */
end_comment

begin_define
define|#
directive|define
name|RBX_CONFIG
value|0xa
end_define

begin_comment
comment|/* -c */
end_comment

begin_define
define|#
directive|define
name|RBX_VERBOSE
value|0xb
end_define

begin_comment
comment|/* -v */
end_comment

begin_define
define|#
directive|define
name|RBX_SERIAL
value|0xc
end_define

begin_comment
comment|/* -h */
end_comment

begin_define
define|#
directive|define
name|RBX_CDROM
value|0xd
end_define

begin_comment
comment|/* -C */
end_comment

begin_comment
comment|/* 0xe is reserved for log2(RB_POWEROFF). */
end_comment

begin_define
define|#
directive|define
name|RBX_GDB
value|0xf
end_define

begin_comment
comment|/* -g */
end_comment

begin_define
define|#
directive|define
name|RBX_MUTE
value|0x10
end_define

begin_comment
comment|/* -m */
end_comment

begin_comment
comment|/* 0x11 is reserved for log2(RB_SELFTEST). */
end_comment

begin_comment
comment|/* 0x12 is reserved for boot programs. */
end_comment

begin_comment
comment|/* 0x13 is reserved for boot programs. */
end_comment

begin_define
define|#
directive|define
name|RBX_PAUSE
value|0x14
end_define

begin_comment
comment|/* -p */
end_comment

begin_define
define|#
directive|define
name|RBX_QUIET
value|0x15
end_define

begin_comment
comment|/* -q */
end_comment

begin_define
define|#
directive|define
name|RBX_NOINTR
value|0x1c
end_define

begin_comment
comment|/* -n */
end_comment

begin_comment
comment|/* 0x1d is reserved for log2(RB_MULTIPLE) and is just misnamed here. */
end_comment

begin_define
define|#
directive|define
name|RBX_DUAL
value|0x1d
end_define

begin_comment
comment|/* -D */
end_comment

begin_comment
comment|/* 0x1f is reserved for log2(RB_BOOTINFO). */
end_comment

begin_comment
comment|/* pass: -a, -s, -r, -d, -c, -v, -h, -C, -g, -m, -p, -D */
end_comment

begin_define
define|#
directive|define
name|RBX_MASK
value|(OPT_SET(RBX_ASKNAME) | OPT_SET(RBX_SINGLE) | \ 			OPT_SET(RBX_DFLTROOT) | OPT_SET(RBX_KDB ) | \ 			OPT_SET(RBX_CONFIG) | OPT_SET(RBX_VERBOSE) | \ 			OPT_SET(RBX_SERIAL) | OPT_SET(RBX_CDROM) | \ 			OPT_SET(RBX_GDB ) | OPT_SET(RBX_MUTE) | \ 			OPT_SET(RBX_PAUSE) | OPT_SET(RBX_DUAL))
end_define

begin_define
define|#
directive|define
name|OPT_SET
parameter_list|(
name|opt
parameter_list|)
value|(1<< (opt))
end_define

begin_define
define|#
directive|define
name|OPT_CHECK
parameter_list|(
name|opt
parameter_list|)
value|((opts)& OPT_SET(opt))
end_define

begin_decl_stmt
specifier|extern
name|uint32_t
name|opts
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RBX_H_ */
end_comment

end_unit

