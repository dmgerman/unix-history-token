begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- forwarding header.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NEW_H__
end_ifndef

begin_define
define|#
directive|define
name|__NEW_H__
end_define

begin_include
include|#
directive|include
file|<new>
end_include

begin_expr_stmt
name|using
name|std
operator|::
name|new_handler
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|set_new_handler
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __NEW_H__
end_comment

end_unit

