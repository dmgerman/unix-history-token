begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The -*- C++ -*- dynamic memory management header.
end_comment

begin_comment
comment|// Copyright (C) 1994 Free Software Foundation
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NEW__
end_ifndef

begin_define
define|#
directive|define
name|__NEW__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
literal|"std/new.h"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<std/cstddef.h>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
typedef|typedef
name|void
function_decl|(
modifier|*
name|new_handler
function_decl|)
parameter_list|()
function_decl|;
extern|extern
literal|"C"
name|new_handler
name|set_new_handler
parameter_list|(
name|new_handler
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__GNUG__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
comment|// G++ implementation internals
specifier|extern
name|new_handler
name|__new_handler
decl_stmt|;
extern|extern
literal|"C"
name|void
name|__default_new_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// replaceable signatures
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
name|void
modifier|*
name|operator
name|new
function_decl|[]
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
name|operator
name|delete
function_decl|[]
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|// default placement versions of operator new
specifier|inline
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
parameter_list|,
name|void
modifier|*
name|place
parameter_list|)
block|{
return|return
name|place
return|;
block|}
specifier|inline
name|void
modifier|*
name|operator
name|new
function|[]
parameter_list|(
name|size_t
parameter_list|,
name|void
modifier|*
name|place
parameter_list|)
block|{
return|return
name|place
return|;
block|}
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

