begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Id: nfs4m_subs.h,v 1.36 2003/11/05 14:59:01 rees Exp $ */
end_comment

begin_comment
comment|/*-  * copyright (c) 2003  * the regents of the university of michigan  * all rights reserved  *   * permission is granted to use, copy, create derivative works and redistribute  * this software and such derivative works for any purpose, so long as the name  * of the university of michigan is not used in any advertising or publicity  * pertaining to the use or distribution of this software without specific,  * written prior authorization.  if the above copyright notice or any other  * identification of the university of michigan is included in any copy of any  * portion of this software, then the disclaimer below must also be included.  *   * this software is provided as is, without representation from the university  * of michigan as to its fitness for any purpose, and without warranty by the  * university of michigan of any kind, either express or implied, including  * without limitation the implied warranties of merchantability and fitness for  * a particular purpose. the regents of the university of michigan shall not be  * liable for any damages, including special, indirect, incidental, or  * consequential damages, with respect to any claim arising out of or in  * connection with the use of the software, even if it has been or is hereafter  * advised of the possibility of such damages.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS4CLIENT_NFSM4_SUBS_H
end_ifndef

begin_define
define|#
directive|define
name|_NFS4CLIENT_NFSM4_SUBS_H
end_define

begin_function_decl
name|void
name|nfsm_v4init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsm_buildf_xx
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
name|mb
parameter_list|,
name|caddr_t
modifier|*
name|bpos
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_dissectf_xx
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
name|md
parameter_list|,
name|caddr_t
modifier|*
name|dpos
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_compound_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_putfh_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_putfh_nv_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_getfh
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_getattr_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_getattr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_finalize_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_getfh_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_getfh
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_lookup_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_lookup
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_setclientid_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_setclientid
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_setclientid_confirm_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_setclientid
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_close_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_fctx
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_access_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_access
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_open_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_open
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_open_confirm_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_open
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_read_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_read
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_write_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_write
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_commit_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_commit
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_readdir_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_readdir
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_renew_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_setattr_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|,
name|struct
name|nfs4_fctx
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_create_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_create
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_rename_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_rename
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_link_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_link
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_remove_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_compound_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_getattr_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_getattr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_getfh_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_getfh
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_setclientid_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_setclientid
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_close_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_fctx
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_access_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_access
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_open_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_open
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_open_confirm_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_open
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_read_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_read
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_write_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_write
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_commit_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_commit
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_setattr_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_create_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|nfs4_oparg_create
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_readlink_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_attrs_xx
parameter_list|(
name|struct
name|nfsv4_fattr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4build_simple_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_v4dissect_simple_xx
parameter_list|(
name|struct
name|nfs4_compound
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|nfsm_v4build_putrootfh_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4build_simple_xx((cp), NFSV4OP_PUTROOTFH, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_lookupp_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4build_simple_xx((cp), NFSV4OP_LOOKUPP, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_savefh_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4build_simple_xx((cp), NFSV4OP_SAVEFH, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_readlink_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4build_simple_xx((cp), NFSV4OP_READLINK, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_putrootfh_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4dissect_simple_xx((cp), NFSV4OP_PUTROOTFH, 0, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_lookup_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4dissect_simple_xx((cp), NFSV4OP_LOOKUP, 0, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_lookupp_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4dissect_simple_xx((cp), NFSV4OP_LOOKUPP, 0, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_putfh_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4dissect_simple_xx((cp), NFSV4OP_PUTFH, 0, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_renew_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4dissect_simple_xx((cp), NFSV4OP_RENEW, 0, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_setclientid_confirm_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4dissect_simple_xx((cp), NFSV4OP_SETCLIENTID_CONFIRM, 0, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_rename_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4dissect_simple_xx((cp), NFSV4OP_RENAME, 0, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_link_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4dissect_simple_xx((cp), NFSV4OP_LINK, 0, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_savefh_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4dissect_simple_xx((cp), NFSV4OP_SAVEFH, 0, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_remove_xx
parameter_list|(
name|cp
parameter_list|,
name|mb
parameter_list|,
name|bpos
parameter_list|)
define|\
value|nfsm_v4dissect_simple_xx((cp), NFSV4OP_REMOVE, 0, (mb), (bpos))
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_compound
parameter_list|(
name|cp
parameter_list|,
name|tag
parameter_list|)
value|do {			\ 	int32_t t1;						\ 	t1 = nfsm_v4build_compound_xx((cp), (tag),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_finalize
parameter_list|(
name|cp
parameter_list|)
value|do {			\ 	int32_t t1;					\ 	t1 = nfsm_v4build_finalize_xx((cp),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_putfh
parameter_list|(
name|cp
parameter_list|,
name|vp
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_putfh_xx((cp), (vp),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_putfh_nv
parameter_list|(
name|cp
parameter_list|,
name|gfh
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_putfh_nv_xx((cp), (gfh),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_putrootfh
parameter_list|(
name|cp
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_putrootfh_xx((cp),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_getattr
parameter_list|(
name|cp
parameter_list|,
name|ga
parameter_list|)
value|do {			\ 	int32_t t1;						\ 	t1 = nfsm_v4build_getattr_xx((cp), (ga),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_setattr
parameter_list|(
name|cp
parameter_list|,
name|vap
parameter_list|,
name|fcp
parameter_list|)
value|do {				\ 	int32_t t1;							\ 	t1 = nfsm_v4build_setattr_xx((cp), (vap), (fcp),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_lookup
parameter_list|(
name|cp
parameter_list|,
name|l
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_lookup_xx((cp), (l),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_lookupp
parameter_list|(
name|cp
parameter_list|)
value|do {			\ 	int32_t t1;					\ 	t1 = nfsm_v4build_lookupp_xx((cp),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_getfh
parameter_list|(
name|cp
parameter_list|,
name|gfh
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_getfh_xx((cp), (gfh),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_close
parameter_list|(
name|cp
parameter_list|,
name|fcp
parameter_list|)
value|do {			\ 	int32_t t1;						\ 	t1 = nfsm_v4build_close_xx((cp), (fcp),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_access
parameter_list|(
name|cp
parameter_list|,
name|acc
parameter_list|)
value|do {			\ 	int32_t t1;						\ 	t1 = nfsm_v4build_access_xx((cp), (acc),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_open
parameter_list|(
name|cp
parameter_list|,
name|o
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_open_xx((cp), (o),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_open_confirm
parameter_list|(
name|cp
parameter_list|,
name|o
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_open_confirm_xx((cp), (o),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_read
parameter_list|(
name|cp
parameter_list|,
name|r
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_read_xx((cp), (r),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_write
parameter_list|(
name|cp
parameter_list|,
name|w
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_write_xx((cp), (w),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_commit
parameter_list|(
name|cp
parameter_list|,
name|c
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_commit_xx((cp), (c),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_readdir
parameter_list|(
name|cp
parameter_list|,
name|r
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_readdir_xx((cp), (r),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_renew
parameter_list|(
name|cp
parameter_list|,
name|cid
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_renew_xx((cp), (cid),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_setclientid
parameter_list|(
name|cp
parameter_list|,
name|cid
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_setclientid_xx((cp), (cid),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_setclientid_confirm
parameter_list|(
name|cp
parameter_list|,
name|cid
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_setclientid_confirm_xx((cp), (cid),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_create
parameter_list|(
name|cp
parameter_list|,
name|c
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_create_xx((cp), (c),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_rename
parameter_list|(
name|cp
parameter_list|,
name|r
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_rename_xx((cp), (r),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_link
parameter_list|(
name|cp
parameter_list|,
name|r
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_link_xx((cp), (r),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_savefh
parameter_list|(
name|cp
parameter_list|)
value|do {			\ 	int32_t t1;					\ 	t1 = nfsm_v4build_savefh_xx((cp),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_readlink
parameter_list|(
name|cp
parameter_list|)
value|do {				\ 	int32_t t1;						\ 	t1 = nfsm_v4build_readlink_xx((cp),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4build_remove
parameter_list|(
name|cp
parameter_list|,
name|name
parameter_list|,
name|namelen
parameter_list|)
value|do {				\ 	int32_t t1;								\ 	t1 = nfsm_v4build_remove_xx((cp), (name), (namelen),&mb,&bpos);	\ 	nfsm_bcheck(t1, mreq);							\ } while (0)
end_define

begin_comment
comment|/* --- */
end_comment

begin_define
define|#
directive|define
name|nfsm_v4dissect_compound
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_compound_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_putfh
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {							\         int32_t t1;					\         t1 = nfsm_v4dissect_putfh_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_putrootfh
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_putrootfh_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_getattr
parameter_list|(
name|cp
parameter_list|,
name|ga
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_getattr_xx((cp), (ga),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_setattr
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_setattr_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_lookup
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_lookup_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_lookupp
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_lookupp_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_getfh
parameter_list|(
name|cp
parameter_list|,
name|gfh
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_getfh_xx((cp), (gfh),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_setclientid
parameter_list|(
name|cp
parameter_list|,
name|sci
parameter_list|)
define|\
value|do {									\         int32_t t1;							\         t1 = nfsm_v4dissect_setclientid_xx((cp), (sci),&md,&dpos);	\         nfsm_dcheck(t1, mrep);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_setclientid_confirm
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {									\         int32_t t1;							\         t1 = nfsm_v4dissect_setclientid_confirm_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_close
parameter_list|(
name|cp
parameter_list|,
name|fcp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_close_xx((cp), (fcp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_access
parameter_list|(
name|cp
parameter_list|,
name|acc
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_access_xx((cp), (acc),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_open
parameter_list|(
name|cp
parameter_list|,
name|openp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_open_xx((cp), (openp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_open_confirm
parameter_list|(
name|cp
parameter_list|,
name|openp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_open_confirm_xx((cp), (openp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_read
parameter_list|(
name|cp
parameter_list|,
name|r
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_read_xx((cp), (r),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_write
parameter_list|(
name|cp
parameter_list|,
name|w
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_write_xx((cp), (w),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_commit
parameter_list|(
name|cp
parameter_list|,
name|c
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_commit_xx((cp), (c),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_attrs
parameter_list|(
name|fattr
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_attrs_xx((fattr),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_renew
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {							\         int32_t t1;					\         t1 = nfsm_v4dissect_renew_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_create
parameter_list|(
name|cp
parameter_list|,
name|c
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_create_xx((cp), (c),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_rename
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_rename_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_link
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_link_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_savefh
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_savefh_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_readlink
parameter_list|(
name|cp
parameter_list|,
name|uiop
parameter_list|)
define|\
value|do {									\         int32_t t1;							\         t1 = nfsm_v4dissect_readlink_xx((cp), (uiop),&md,&dpos);	\         nfsm_dcheck(t1, mrep);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_v4dissect_remove
parameter_list|(
name|cp
parameter_list|)
define|\
value|do {								\         int32_t t1;						\         t1 = nfsm_v4dissect_remove_xx((cp),&md,&dpos);	\         nfsm_dcheck(t1, mrep);					\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS4CLIENT_NFSM4_SUBS_H */
end_comment

end_unit

