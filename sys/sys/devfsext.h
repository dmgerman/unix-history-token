begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1997,1998 Julian Elischer.  All rights reserved.  * julian@freebsd.org  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright notice,  *     this list of conditions and the following disclaimer in the documentation  *     and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE HOLDER OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DEVFSEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DEVFSEXT_H_
end_define

begin_warning
warning|#
directive|warning
literal|"Using obsolete<sys/devfsext.h>"
end_warning

begin_comment
comment|/*  * The old DEVFS API is obsolete and should be discontinued ASAP  * Please use the make_dev() function instead.  Plenty of examples  * to look at all over the place, contact phk@FreeBSD.org if in  * doubt.  */
end_comment

begin_comment
comment|/*  * Make a device at a path, and get a cookie for it in return.  * Specify the type, the minor number and the devsw entry to use,  * and the initial default perms/ownerships.  */
end_comment

begin_decl_stmt
name|void
modifier|*
name|devfs_add_devswf
name|__P
argument_list|(
operator|(
name|void
operator|*
name|devsw
operator|,
name|int
name|minor
operator|,
name|int
name|chrblk
operator|,
name|uid_t
name|uid
operator|,
name|gid_t
name|gid
operator|,
name|int
name|perms
operator|,
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|7
argument_list|,
literal|8
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Make a link to a device you already made, and have the cookie for   * We get another cookie, but for now, it can be discarded, as  * at the moment there is nothing you can do with it that you couldn't do  * with the original cookie. ( XXX this might be something I should change )  */
end_comment

begin_decl_stmt
name|void
modifier|*
name|devfs_makelink
name|__P
argument_list|(
operator|(
name|void
operator|*
name|original
operator|,
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Remove all instances of a device you have made. INCLUDING LINKS.  * I.e. either the cookie from the original device or the cookie  * from a link will have the effect of removing both entries.  * Removing with BOTH an original cookie and one from a link is  * likely to cause a panic.  */
end_comment

begin_decl_stmt
name|void
name|devfs_remove_dev
name|__P
argument_list|(
operator|(
name|void
operator|*
name|devnmp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Check if a device exists and is the type you need. Returns NULL or a  * cookie that can be used to try 'open' the device. XXX This is a bit  * of a duplication of devfs_lookup(). I might one day try merge them a bit.  * Used for mountroot under DEVFS. Path is relative to the base of the devfs.  */
end_comment

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|devfs_open_device
name|__P
argument_list|(
operator|(
name|char
operator|*
name|path
operator|,
name|int
name|devtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|devfs_close_device
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|devfs_vntodev
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extract dev_t from devfs vn */
end_comment

begin_define
define|#
directive|define
name|DV_CHR
value|0
end_define

begin_define
define|#
directive|define
name|DV_BLK
value|1
end_define

begin_define
define|#
directive|define
name|DV_DEV
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DEVFSEXT_H_ */
end_comment

end_unit

