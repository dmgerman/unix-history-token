begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Id: nfs4_idmap.h,v 1.2 2003/11/05 14:58:59 rees Exp $ */
end_comment

begin_comment
comment|/*-  * copyright (c) 2003  * the regents of the university of michigan  * all rights reserved  *   * permission is granted to use, copy, create derivative works and redistribute  * this software and such derivative works for any purpose, so long as the name  * of the university of michigan is not used in any advertising or publicity  * pertaining to the use or distribution of this software without specific,  * written prior authorization.  if the above copyright notice or any other  * identification of the university of michigan is included in any copy of any  * portion of this software, then the disclaimer below must also be included.  *   * this software is provided as is, without representation from the university  * of michigan as to its fitness for any purpose, and without warranty by the  * university of michigan of any kind, either express or implied, including  * without limitation the implied warranties of merchantability and fitness for  * a particular purpose. the regents of the university of michigan shall not be  * liable for any damages, including special, indirect, incidental, or  * consequential damages, with respect to any claim arising out of or in  * connection with the use of the software, even if it has been or is hereafter  * advised of the possibility of such damages.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NFS4_IDMAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__NFS4_IDMAP_H__
end_define

begin_define
define|#
directive|define
name|IDMAP_TYPE_GID
value|1
end_define

begin_define
define|#
directive|define
name|IDMAP_TYPE_UID
value|2
end_define

begin_define
define|#
directive|define
name|IDMAP_MAX_TYPE
value|2
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|uid_t
name|uid
decl_stmt|;
name|gid_t
name|gid
decl_stmt|;
block|}
name|ident_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IDMAP_MAXNAMELEN
value|249
end_define

begin_struct
struct|struct
name|idmap_msg
block|{
name|uint32_t
name|id_type
decl_stmt|;
name|ident_t
name|id_id
decl_stmt|;
name|size_t
name|id_namelen
decl_stmt|;
name|char
name|id_name
index|[
name|IDMAP_MAXNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IDMAP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|idmap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idmap_uninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idmap_gid_to_name
parameter_list|(
name|gid_t
name|id
parameter_list|,
name|char
modifier|*
modifier|*
name|name
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idmap_uid_to_name
parameter_list|(
name|uid_t
name|id
parameter_list|,
name|char
modifier|*
modifier|*
name|name
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idmap_name_to_gid
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
name|len
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idmap_name_to_uid
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NFS4_GSS_H__ */
end_comment

end_unit

