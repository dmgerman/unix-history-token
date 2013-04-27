begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|NAME
value|__sync_fetch_and_sub_4
end_define

begin_define
define|#
directive|define
name|TYPE
value|int32_t
end_define

begin_define
define|#
directive|define
name|FETCHADD
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|atomic_fetchadd_32(x, -(y))
end_define

begin_include
include|#
directive|include
file|"__sync_fetch_and_op_n.h"
end_include

end_unit

