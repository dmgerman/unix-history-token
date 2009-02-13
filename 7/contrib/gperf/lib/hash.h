begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988, 1992, 2000 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_hash_h
end_ifndef

begin_define
define|#
directive|define
name|_hash_h
value|1
end_define

begin_comment
comment|/* a hash function for char[] arrays using the    method described in Aho, Sethi,& Ullman, p 436. */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|hashpjw
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

