begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|NAME
value|__sync_fetch_and_or_8
end_define

begin_define
define|#
directive|define
name|TYPE
value|uint64_t
end_define

begin_define
define|#
directive|define
name|CMPSET
value|atomic_cmpset_64
end_define

begin_define
define|#
directive|define
name|EXPRESSION
value|t | value
end_define

begin_include
include|#
directive|include
file|"__sync_fetch_and_op_n.h"
end_include

end_unit

