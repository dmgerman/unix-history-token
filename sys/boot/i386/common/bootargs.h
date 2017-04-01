begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Andriy Gapon<avg@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms are freely  * permitted provided that the above copyright notice and this  * paragraph and the following disclaimer are duplicated in all  * such forms.  *  * This software is provided "AS IS" and without any express or  * implied warranties, including, without limitation, the implied  * warranties of merchantability and fitness for a particular  * purpose.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BOOT_I386_ARGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_BOOT_I386_ARGS_H_
end_define

begin_define
define|#
directive|define
name|KARGS_FLAGS_CD
value|0x1
end_define

begin_define
define|#
directive|define
name|KARGS_FLAGS_PXE
value|0x2
end_define

begin_define
define|#
directive|define
name|KARGS_FLAGS_ZFS
value|0x4
end_define

begin_define
define|#
directive|define
name|KARGS_FLAGS_EXTARG
value|0x8
end_define

begin_comment
comment|/* variably sized extended argument */
end_comment

begin_define
define|#
directive|define
name|BOOTARGS_SIZE
value|24
end_define

begin_comment
comment|/* sizeof(struct bootargs) */
end_comment

begin_define
define|#
directive|define
name|BA_BOOTFLAGS
value|8
end_define

begin_comment
comment|/* offsetof(struct bootargs, bootflags) */
end_comment

begin_define
define|#
directive|define
name|BA_BOOTINFO
value|20
end_define

begin_comment
comment|/* offsetof(struct bootargs, bootinfo) */
end_comment

begin_define
define|#
directive|define
name|BI_SIZE
value|48
end_define

begin_comment
comment|/* offsetof(struct bootinfo, bi_size) */
end_comment

begin_comment
comment|/*  * We reserve some space above BTX allocated stack for the arguments  * and certain data that could hang off them.  Currently only struct bootinfo  * is supported in that category.  The bootinfo is placed at the top  * of the arguments area and the actual arguments are placed at ARGOFF offset  * from the top and grow towards the top.  Hopefully we have enough space  * for bootinfo and the arguments to not run into each other.  * Arguments area below ARGOFF is reserved for future use.  */
end_comment

begin_define
define|#
directive|define
name|ARGSPACE
value|0x1000
end_define

begin_comment
comment|/* total size of the BTX args area */
end_comment

begin_define
define|#
directive|define
name|ARGOFF
value|0x800
end_define

begin_comment
comment|/* actual args offset within the args area */
end_comment

begin_define
define|#
directive|define
name|ARGADJ
value|(ARGSPACE - ARGOFF)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

begin_struct
struct|struct
name|bootargs
block|{
name|uint32_t
name|howto
decl_stmt|;
name|uint32_t
name|bootdev
decl_stmt|;
name|uint32_t
name|bootflags
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|pxeinfo
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
name|uint64_t
name|zfspool
decl_stmt|;
block|}
union|;
name|uint32_t
name|bootinfo
decl_stmt|;
comment|/* 	 * If KARGS_FLAGS_EXTARG is set in bootflags, then the above fields 	 * are followed by a uint32_t field that specifies a size of the 	 * extended arguments (including the size field). 	 */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|LOADER_GELI_SUPPORT
end_ifdef

begin_include
include|#
directive|include
file|<crypto/intake.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|geli_boot_args
block|{
name|uint32_t
name|size
decl_stmt|;
union|union
block|{
name|char
name|gelipw
index|[
literal|256
index|]
decl_stmt|;
struct|struct
block|{
name|char
name|notapw
decl_stmt|;
comment|/*  					 * single null byte to stop keybuf 					 * being interpreted as a password 					 */
name|uint32_t
name|keybuf_sentinel
decl_stmt|;
ifdef|#
directive|ifdef
name|LOADER_GELI_SUPPORT
name|struct
name|keybuf
modifier|*
name|keybuf
decl_stmt|;
else|#
directive|else
name|void
modifier|*
name|keybuf
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
block|}
union|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__ASSEMBLER__*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BOOT_I386_ARGS_H_ */
end_comment

end_unit

