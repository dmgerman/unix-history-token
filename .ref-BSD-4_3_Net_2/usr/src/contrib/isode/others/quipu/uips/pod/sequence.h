begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Header: /f/osi/others/quipu/uips/pod/RCS/sequence.h,v 7.1 91/02/22 09:31:54 mrose Interim $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEQ
end_ifndef

begin_define
define|#
directive|define
name|SEQ
end_define

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|QUIPU_MALLOC
end_ifdef

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|smalloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|str_seq
block|{
name|char
modifier|*
name|dname
decl_stmt|;
name|unsigned
name|strlen
decl_stmt|;
name|struct
name|str_seq
modifier|*
name|next
decl_stmt|;
block|}
name|strSeq
operator|,
typedef|*
name|str_seq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLDS
value|((str_seq) 0)
end_define

begin_function_decl
name|char
modifier|*
name|get_from_seq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_seq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_seq
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

