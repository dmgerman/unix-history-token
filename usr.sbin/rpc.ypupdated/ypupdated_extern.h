begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_decl_stmt
specifier|extern
name|void
name|ypu_prog_1
name|__P
argument_list|(
operator|(
expr|struct
name|svc_req
operator|*
operator|,
specifier|register
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|localupdate
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
name|char
operator|*
operator|,
name|u_int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ypmap_update
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
name|char
operator|*
operator|,
name|u_int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yp_del_record
name|__P
argument_list|(
operator|(
name|DB
operator|*
operator|,
name|DBT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

