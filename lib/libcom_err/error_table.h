begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Student Information Processing Board of the  * Massachusetts Institute of Technology.  *  * For copyright info, see mit-sipb-copyright.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ET_H
end_ifndef

begin_comment
comment|/* Are we using ANSI C? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|error_table
block|{
name|char
specifier|const
modifier|*
specifier|const
modifier|*
name|msgs
decl_stmt|;
name|long
name|base
decl_stmt|;
name|int
name|n_msgs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_list
block|{
name|struct
name|et_list
modifier|*
name|next
decl_stmt|;
specifier|const
name|struct
name|error_table
modifier|*
name|table
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|et_list
modifier|*
name|_et_list
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ERRCODE_RANGE
value|8
end_define

begin_comment
comment|/* # of bits to shift table number */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_CHAR
value|6
end_define

begin_comment
comment|/* # bits to shift per character in name */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|error_table_name
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_ET_H
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

