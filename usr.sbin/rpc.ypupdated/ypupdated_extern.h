begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_define
define|#
directive|define
name|YPOP_CHANGE
value|1
end_define

begin_comment
comment|/* change, do not add */
end_comment

begin_define
define|#
directive|define
name|YPOP_INSERT
value|2
end_define

begin_comment
comment|/* add, do not change */
end_comment

begin_define
define|#
directive|define
name|YPOP_DELETE
value|3
end_define

begin_comment
comment|/* delete this entry */
end_comment

begin_define
define|#
directive|define
name|YPOP_STORE
value|4
end_define

begin_comment
comment|/* add, or change */
end_comment

begin_define
define|#
directive|define
name|ERR_ACCESS
value|1
end_define

begin_define
define|#
directive|define
name|ERR_MALLOC
value|2
end_define

begin_define
define|#
directive|define
name|ERR_READ
value|3
end_define

begin_define
define|#
directive|define
name|ERR_WRITE
value|4
end_define

begin_define
define|#
directive|define
name|ERR_DBASE
value|5
end_define

begin_define
define|#
directive|define
name|ERR_KEY
value|6
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|YPLIBDIR
end_ifndef

begin_define
define|#
directive|define
name|YPLIBDIR
value|"/usr/libexec/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAP_UPPATE
end_ifndef

begin_define
define|#
directive|define
name|MAP_UPDATE
value|"ypupdate"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAP_UPDATE_PATH
value|YPLIBDIR MAP_UPDATE
end_define

begin_decl_stmt
specifier|extern
name|int
name|children
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|ypu_prog_1
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
specifier|register
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|localupdate
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ypmap_update
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yp_del_record
parameter_list|(
name|DB
modifier|*
parameter_list|,
name|DBT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

