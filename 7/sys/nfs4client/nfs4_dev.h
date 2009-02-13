begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Id: nfs4_dev.h,v 1.3 2003/11/05 14:58:59 rees Exp $ */
end_comment

begin_comment
comment|/*-  * copyright (c) 2003  * the regents of the university of michigan  * all rights reserved  *   * permission is granted to use, copy, create derivative works and redistribute  * this software and such derivative works for any purpose, so long as the name  * of the university of michigan is not used in any advertising or publicity  * pertaining to the use or distribution of this software without specific,  * written prior authorization.  if the above copyright notice or any other  * identification of the university of michigan is included in any copy of any  * portion of this software, then the disclaimer below must also be included.  *   * this software is provided as is, without representation from the university  * of michigan as to its fitness for any purpose, and without warranty by the  * university of michigan of any kind, either express or implied, including  * without limitation the implied warranties of merchantability and fitness for  * a particular purpose. the regents of the university of michigan shall not be  * liable for any damages, including special, indirect, incidental, or  * consequential damages, with respect to any claim arising out of or in  * connection with the use of the software, even if it has been or is hereafter  * advised of the possibility of such damages.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS3_DEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS4_DEV_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* type of upcall */
end_comment

begin_define
define|#
directive|define
name|NFS4DEV_TYPE_IDMAP
value|0
end_define

begin_define
define|#
directive|define
name|NFS4DEV_TYPE_GSS
value|1
end_define

begin_define
define|#
directive|define
name|NFS4DEV_MAX_TYPE
value|1
end_define

begin_struct
struct|struct
name|nfs4dev_msg
block|{
name|unsigned
name|int
name|msg_vers
decl_stmt|;
name|unsigned
name|int
name|msg_type
decl_stmt|;
name|unsigned
name|int
name|msg_xid
decl_stmt|;
name|unsigned
name|int
name|msg_error
decl_stmt|;
define|#
directive|define
name|NFS4DEV_MSG_MAX_DATALEN
value|350
name|size_t
name|msg_len
decl_stmt|;
name|uint8_t
name|msg_data
index|[
name|NFS4DEV_MSG_MAX_DATALEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NFS4DEV_VERSION
value|(0x3<< 16 | (int) sizeof(struct nfs4dev_msg))
end_define

begin_comment
comment|/* ioctl commands */
end_comment

begin_define
define|#
directive|define
name|NFS4DEVIOCGET
value|_IOR('A', 0x200, struct nfs4dev_msg)
end_define

begin_define
define|#
directive|define
name|NFS4DEVIOCPUT
value|_IOW('A', 0x201, struct nfs4dev_msg)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|nfs4dev_call
parameter_list|(
name|uint32_t
name|type
parameter_list|,
name|caddr_t
name|req_data
parameter_list|,
name|size_t
name|req_len
parameter_list|,
name|caddr_t
name|rep_datap
parameter_list|,
name|size_t
modifier|*
name|rep_lenp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs4dev_purge
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs4dev_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs4dev_uninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS4_DEV_H_ */
end_comment

end_unit

