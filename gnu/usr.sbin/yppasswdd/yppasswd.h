begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * yppasswdd  * Copyright 1994 Olaf Kirch,<okir@monad.swb.de>  *  * This program is covered by the GNU General Public License, version 2.  * It is provided in the hope that it is useful. However, the author  * disclaims ALL WARRANTIES, expressed or implied. See the GPL for details.  *   * This file was generated automatically by rpcgen from yppasswd.x, and  * editied manually.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_YPPASSWD_H_
end_ifndef

begin_define
define|#
directive|define
name|_YPPASSWD_H_
end_define

begin_define
define|#
directive|define
name|YPPASSWDPROG
value|((u_long)100009)
end_define

begin_define
define|#
directive|define
name|YPPASSWDVERS
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|YPPASSWDPROC_UPDATE
value|((u_long)1)
end_define

begin_comment
comment|/*  * The password struct passed by the update call. I renamed it to  * xpasswd to avoid a type clash with the one defined in<pwd.h>.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xpasswd
block|{
name|char
modifier|*
name|pw_name
decl_stmt|;
name|char
modifier|*
name|pw_passwd
decl_stmt|;
name|int
name|pw_uid
decl_stmt|;
name|int
name|pw_gid
decl_stmt|;
name|char
modifier|*
name|pw_gecos
decl_stmt|;
name|char
modifier|*
name|pw_dir
decl_stmt|;
name|char
modifier|*
name|pw_shell
decl_stmt|;
block|}
name|xpasswd
typedef|;
end_typedef

begin_comment
comment|/* The updated password information, plus the old password.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|yppasswd
block|{
name|char
modifier|*
name|oldpass
decl_stmt|;
name|xpasswd
name|newpw
decl_stmt|;
block|}
name|yppasswd
typedef|;
end_typedef

begin_comment
comment|/* XDR encoding/decoding routines */
end_comment

begin_function_decl
name|bool_t
name|xdr_xpasswd
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|xpasswd
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_yppasswd
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|yppasswd
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The server procedure invoked by the main loop. */
end_comment

begin_function_decl
name|void
name|yppasswdprog_1
parameter_list|(
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|,
name|SVCXPRT
modifier|*
name|transp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Password update handler. */
end_comment

begin_function_decl
name|int
modifier|*
name|yppasswdproc_pwupdate_1
parameter_list|(
name|yppasswd
modifier|*
name|yppw
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This command is forked to rebuild the NIS maps after a successful  * update. MAP_UPDATE is used as argv[0].  */
end_comment

begin_define
define|#
directive|define
name|MAP_UPDATE
value|"yppwupdate"
end_define

begin_define
define|#
directive|define
name|MAP_UPDATE_PATH
value|YPLIBDIR "/yppwupdate"
end_define

begin_endif
endif|#
directive|endif
endif|_YPPASSWD_H_
end_endif

end_unit

