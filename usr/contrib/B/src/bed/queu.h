begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: queu.h,v 2.1 85/08/22 16:07:02 timo Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Definitions for queues of nodes.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|queue
modifier|*
name|queue
typedef|;
end_typedef

begin_struct
struct|struct
name|queue
block|{
name|char
name|type
decl_stmt|;
name|char
name|_unused
decl_stmt|;
name|intlet
name|refcnt
decl_stmt|;
name|intlet
name|len
decl_stmt|;
name|node
name|q_data
decl_stmt|;
name|queue
name|q_link
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|Qnil
value|((queue) NULL)
end_define

begin_define
define|#
directive|define
name|qcopy
parameter_list|(
name|q
parameter_list|)
value|((queue)copy((value)(q)))
end_define

begin_define
define|#
directive|define
name|qrelease
parameter_list|(
name|q
parameter_list|)
value|release((value)(q))
end_define

begin_define
define|#
directive|define
name|emptyqueue
parameter_list|(
name|q
parameter_list|)
value|(!(q))
end_define

begin_function_decl
name|node
name|queuebehead
parameter_list|()
function_decl|;
end_function_decl

end_unit

