begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Apple Computer, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/bsm/audit_uevents.h#7 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSM_AUDIT_UEVENTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSM_AUDIT_UEVENTS_H_
end_define

begin_comment
comment|/*-  * User level audit event numbers  *  * Range of audit event numbers:  * 0			Reserved, invalid  * 1     - 2047		Reserved for kernel events  * 2048  - 32767	Defined by BSM for user events  * 32768 - 36864	Reserved for Mac OS-X applications  * 36865 - 65535	Reserved for applications  *  */
end_comment

begin_define
define|#
directive|define
name|AUE_at_create
value|6144
end_define

begin_define
define|#
directive|define
name|AUE_at_delete
value|6145
end_define

begin_define
define|#
directive|define
name|AUE_at_perm
value|6146
end_define

begin_define
define|#
directive|define
name|AUE_cron_invoke
value|6147
end_define

begin_define
define|#
directive|define
name|AUE_crontab_create
value|6148
end_define

begin_define
define|#
directive|define
name|AUE_crontab_delete
value|6149
end_define

begin_define
define|#
directive|define
name|AUE_crontab_perm
value|6150
end_define

begin_define
define|#
directive|define
name|AUE_inetd_connect
value|6151
end_define

begin_define
define|#
directive|define
name|AUE_login
value|6152
end_define

begin_define
define|#
directive|define
name|AUE_logout
value|6153
end_define

begin_define
define|#
directive|define
name|AUE_telnet
value|6154
end_define

begin_define
define|#
directive|define
name|AUE_rlogin
value|6155
end_define

begin_define
define|#
directive|define
name|AUE_mountd_mount
value|6156
end_define

begin_define
define|#
directive|define
name|AUE_mountd_umount
value|6157
end_define

begin_define
define|#
directive|define
name|AUE_rshd
value|6158
end_define

begin_define
define|#
directive|define
name|AUE_su
value|6159
end_define

begin_define
define|#
directive|define
name|AUE_halt
value|6160
end_define

begin_define
define|#
directive|define
name|AUE_reboot
value|6161
end_define

begin_define
define|#
directive|define
name|AUE_rexecd
value|6162
end_define

begin_define
define|#
directive|define
name|AUE_passwd
value|6163
end_define

begin_define
define|#
directive|define
name|AUE_rexd
value|6164
end_define

begin_define
define|#
directive|define
name|AUE_ftpd
value|6165
end_define

begin_define
define|#
directive|define
name|AUE_init
value|6166
end_define

begin_define
define|#
directive|define
name|AUE_uadmin
value|6167
end_define

begin_define
define|#
directive|define
name|AUE_shutdown
value|6168
end_define

begin_define
define|#
directive|define
name|AUE_poweroff
value|6169
end_define

begin_define
define|#
directive|define
name|AUE_crontab_mod
value|6170
end_define

begin_define
define|#
directive|define
name|AUE_audit_startup
value|6171
end_define

begin_define
define|#
directive|define
name|AUE_audit_shutdown
value|6172
end_define

begin_define
define|#
directive|define
name|AUE_allocate_succ
value|6200
end_define

begin_define
define|#
directive|define
name|AUE_allocate_fail
value|6201
end_define

begin_define
define|#
directive|define
name|AUE_deallocate_succ
value|6202
end_define

begin_define
define|#
directive|define
name|AUE_deallocate_fail
value|6203
end_define

begin_define
define|#
directive|define
name|AUE_listdevice_succ
value|6205
end_define

begin_define
define|#
directive|define
name|AUE_listdevice_fail
value|6206
end_define

begin_define
define|#
directive|define
name|AUE_create_user
value|6207
end_define

begin_define
define|#
directive|define
name|AUE_modify_user
value|6208
end_define

begin_define
define|#
directive|define
name|AUE_delete_user
value|6209
end_define

begin_define
define|#
directive|define
name|AUE_disable_user
value|6210
end_define

begin_define
define|#
directive|define
name|AUE_enable_user
value|6211
end_define

begin_define
define|#
directive|define
name|AUE_sudo
value|6300
end_define

begin_define
define|#
directive|define
name|AUE_modify_password
value|6501
end_define

begin_comment
comment|/* Not assigned by Sun. */
end_comment

begin_define
define|#
directive|define
name|AUE_create_group
value|6511
end_define

begin_comment
comment|/* Not assigned by Sun. */
end_comment

begin_define
define|#
directive|define
name|AUE_delete_group
value|6512
end_define

begin_comment
comment|/* Not assigned by Sun. */
end_comment

begin_define
define|#
directive|define
name|AUE_modify_group
value|6513
end_define

begin_comment
comment|/* Not assigned by Sun. */
end_comment

begin_define
define|#
directive|define
name|AUE_add_to_group
value|6514
end_define

begin_comment
comment|/* Not assigned by Sun. */
end_comment

begin_define
define|#
directive|define
name|AUE_remove_from_group
value|6515
end_define

begin_comment
comment|/* Not assigned by Sun. */
end_comment

begin_define
define|#
directive|define
name|AUE_revoke_obj
value|6521
end_define

begin_comment
comment|/* Not assigned by Sun; not used. */
end_comment

begin_define
define|#
directive|define
name|AUE_lw_login
value|6600
end_define

begin_comment
comment|/* Not assigned by Sun; tentative. */
end_comment

begin_define
define|#
directive|define
name|AUE_lw_logout
value|6601
end_define

begin_comment
comment|/* Not assigned by Sun; tentative. */
end_comment

begin_define
define|#
directive|define
name|AUE_auth_user
value|7000
end_define

begin_comment
comment|/* Not assigned by Sun. */
end_comment

begin_define
define|#
directive|define
name|AUE_ssconn
value|7001
end_define

begin_comment
comment|/* Not assigned by Sun. */
end_comment

begin_define
define|#
directive|define
name|AUE_ssauthorize
value|7002
end_define

begin_comment
comment|/* Not assigned by Sun. */
end_comment

begin_define
define|#
directive|define
name|AUE_ssauthint
value|7003
end_define

begin_comment
comment|/* Not assigned by Sun. */
end_comment

begin_define
define|#
directive|define
name|AUE_openssh
value|32800
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BSM_AUDIT_UEVENTS_H_ */
end_comment

end_unit

