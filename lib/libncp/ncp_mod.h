begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Describes all ncp_lib kernel functions  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NCP_MOD_H_
end_ifndef

begin_define
define|#
directive|define
name|_NCP_MOD_H_
end_define

begin_comment
comment|/* order of calls in syscall table relative to offset in system table */
end_comment

begin_define
define|#
directive|define
name|NCP_SE
parameter_list|(
name|callno
parameter_list|)
value|(callno+sysentoffset)
end_define

begin_define
define|#
directive|define
name|NCP_CONNSCAN
value|NCP_SE(0)
end_define

begin_define
define|#
directive|define
name|NCP_CONNECT
value|NCP_SE(1)
end_define

begin_define
define|#
directive|define
name|NCP_INTFN
value|NCP_SE(2)
end_define

begin_define
define|#
directive|define
name|SNCP_REQUEST
value|NCP_SE(3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NCP_MOD_H_ */
end_comment

end_unit

